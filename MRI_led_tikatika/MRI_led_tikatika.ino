#include <MsTimer2.h>
#include <stdio.h>
#include <hidboot.h>
// Satisfy IDE, which only needs to see the include statment in the ino.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif

#include "printf_wrapper.h"
#include "settings.h"

// 7-13: Disabled by Shield!!
#define LED 13
#define SW 1   // yet

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
static long pre_counter = g_trigger_counter;
void proc_triggered(void) {
  printf("%ld\n", t * DT);
}

void flash() {
  t++; 
  if (pre_counter != g_trigger_counter) {
    proc_triggered();  
  }
  pre_counter = g_trigger_counter;
}

void setup() {
  // Pin Settings
  pinMode(LED, OUTPUT);
  pinMode(SW, INPUT);
  
  // Serial Settings
  Serial.begin( 115200 );
  fdev_setup_stream (&uartout, uart_putchar, NULL, _FDEV_SETUP_WRITE);
  stdout = &uartout;
  while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection

  // Timer Interruption  
  MsTimer2::set(DT, flash);
  MsTimer2::start();

  // USB
  if (Usb.Init() == -1)
    Serial.println("OSC did not rt.");
  delay( 200 );

  // HIDKeyboard callback
  HidKeyboard.SetReportParser(0, (HIDReportParser*)&Prs);
  printf("Start\n");
}

void loop() {
  Usb.Task();
}
