#include <MsTimer2.h>
#include <stdio.h>
#include <hidboot.h>
// Satisfy IDE, which only needs to see the include statment in the ino.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif

#include "printf_wrapper.h"
#include "settings.h"
#include "drive_led.h"
#include "updown.h"
#include "transit_seq.h"
#include "data.h"

class KbdRptParser : public KeyboardReportParser
{
protected:
  virtual void OnKeyDown(uint8_t mod, uint8_t key);
};

long g_trigger_counter = 0;
void KbdRptParser::OnKeyDown(uint8_t mod, uint8_t key)
{
  g_trigger_counter++;
//  printf("%c, %d\n", OemToAscii(mod, key), g_trigger_counter);
}

USB     Usb;
HIDBoot<HID_PROTOCOL_KEYBOARD>    HidKeyboard(&Usb);
KbdRptParser Prs;

// Timer Callback Function
long t = 0; // counter for control cycle
void proc_triggered(void) {
  printf("%ld\n", t * DT);
}
void control(void) {
  if (g_trigger_counter == 3) {
    int seq[] = {0, 1, 2, 0};
    if (transit_seq(seq, sizeof(seq)/sizeof(seq[0])) == -1) {
      printf("seq done\n");
    }
    /*
    if (updown(data[0].seq, data[0].len, data[0].seqdone, 0, 0) == -1) {
      printf("seq done\n");
    }
    */
  }
  /*
  if (g_trigger_counter % 2) 
    setLED(0, 0, HIGH);
  else 
    setLED(0, 0, LOW);
  */
}

static long pre_counter = g_trigger_counter;
void flash() {
  t++; 
  if (pre_counter != g_trigger_counter) {
    proc_triggered();  
  }
  control();
  pre_counter = g_trigger_counter;
  driveLED();
}

void setup() {
  // Pin Settings
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(18, OUTPUT);
  
  // Serial Settings
  Serial.begin( 115200 );
  fdev_setup_stream (&uartout, uart_putchar, NULL, _FDEV_SETUP_WRITE);
  stdout = &uartout;
  while (!Serial);

  // Timer Interruption  
  MsTimer2::set(DT, flash);
  MsTimer2::start();

  // USB
  if (Usb.Init() == -1)
    Serial.println("OSC did not rt.");
  delay( 200 );

  // HIDKeyboard callback
  HidKeyboard.SetReportParser(0, (HIDReportParser*)&Prs);
  
  // updown
  init_updown();
  set_data();
  
  printf("Start\n");
}

void loop() {
  Usb.Task();
}
