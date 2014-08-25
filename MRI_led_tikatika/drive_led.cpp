#include <Arduino.h>
#include "settings.h"
#include "printf_wrapper.h"

static boolean led_state[XNUM][YNUM];
void setLED(int x, int y, boolean out) {
  led_state[x][y] = out;
}

static long counter = 0;
void driveLED(void){
  boolean x = (counter++) % 2;
  
  digitalWrite(2, x);
  digitalWrite(3, !x);

  digitalWrite(4, led_state[x][0]);
  digitalWrite(5, led_state[x][1]);
  digitalWrite(6, led_state[x][2]);
  digitalWrite(14, led_state[x][3]);
  digitalWrite(15, led_state[x][4]);
  digitalWrite(16, led_state[x][5]);
  digitalWrite(17, led_state[x][6]);
  digitalWrite(18, led_state[x][7]);
} 
