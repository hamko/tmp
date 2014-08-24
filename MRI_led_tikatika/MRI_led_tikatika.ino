#include <MsTimer2.h>
#include <stdio.h>
#include <hidboot.h>
// Satisfy IDE, which only needs to see the include statment in the ino.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif

#include "printf_wrapper.h"

// 7-13: Disabled by Shield!!
#define LED 13
#define SW 1   // yet
#define DT 100 // ms: control cycle
#define BLINK_TIME 5000

class KbdRptParser : public KeyboardReportParser
{
protected:
  virtual void OnKeyDown(uint8_t mod, uint8_t key);
  virtual void OnKeyUp(uint8_t mod, uint8_t key);
};

int g_trigger_counter = 0;
void KbdRptParser::OnKeyDown(uint8_t mod, uint8_t key)
{
  g_trigger_counter++;
  printf("%c, %d\n", OemToAscii(mod, key), g_trigger_counter);
}
void KbdRptParser::OnKeyUp(uint8_t mod, uint8_t key) {
  printf("test\n");
}


USB     Usb;
HIDBoot<HID_PROTOCOL_KEYBOARD>    HidKeyboard(&Usb);
KbdRptParser Prs;

// Timer Callback Function
long t = 0; // counter for control cycle
void flash() {
  t++; 
  printf("%ld, %d\n", t * DT, (t/10)%2);  
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
}

void loop() {
  Usb.Task();
}
