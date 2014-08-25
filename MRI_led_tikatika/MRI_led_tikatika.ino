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

data_t data[DATA_NUM];
tran_t tran[TRAN_NUM];

class KbdRptParser : public KeyboardReportParser
{
protected:
  virtual void OnKeyDown(uint8_t mod, uint8_t key);
};

long g_trigger_counter = 0;
void KbdRptParser::OnKeyDown(uint8_t mod, uint8_t key)
{
  g_trigger_counter++;
}

USB     Usb;
HIDBoot<HID_PROTOCOL_KEYBOARD>    HidKeyboard(&Usb);
KbdRptParser Prs;

// Ready
int ready_num = -1;
boolean start_flag = false;

// Timer Callback Function
long t = 0; // counter for control cycle
void proc_triggered(void) {
  if (ready_num >= 0) {
    printf("Start seq\n");
    start_flag = true;
  } else
    printf("error: Set seq\n");
}
void control(void) {
  if (ready_num >= 0 && start_flag && transit_seq(tran[ready_num].tran, tran[ready_num].len) == -1) {
    ready_num = -1;
    start_flag = false;
    turnoffLED();
    printf("seq done\n");
  }
}

static long pre_counter = g_trigger_counter;
void flash() {
  t++;
  if (t == READY_TIME)
    printf("Ready\n");
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

  // HIDKeyboard callback
  HidKeyboard.SetReportParser(0, (HIDReportParser*)&Prs);
  
  // updown
  init_updown();
  set_data();

  printf("\nBooted\n");
}

void loop() {
  Usb.Task();

  int inputchar = Serial.read();
 
  if(inputchar != -1 ) {
    ready_num = inputchar - '0';
    printf("Set %d\n", ready_num);
  }
}
