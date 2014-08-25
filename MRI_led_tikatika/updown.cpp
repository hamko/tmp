#include <Arduino.h>
#include "drive_led.h"
#include "settings.h"

static long counter[XNUM][YNUM]; // [ms/DT] (if Non-active -1)
static long index[XNUM][YNUM];
static boolean out[XNUM][YNUM];

void init_updown(void) {
  for (int x = 0; x < XNUM; x++) {
    for (int y = 0; y < YNUM; y++) {
      counter[x][y] = -1;
      index[x][y] = 0;
      out[x][y] = LOW;
    }
  }
}

long updown(long* seq/*ms*/, int len/*index*/, long seqlen/*ms*/, int x, int y) {
    counter[x][y]++;
    
    if (index[x][y] < len && counter[x][y] * DT == seq[index[x][y]]) {
      out[x][y] = !out[x][y]; index[x][y]++;
    }
    
    setLED(x, y, out[x][y]);
    
    if (counter[x][y] * DT >= seqlen - 1) {
      index[x][y] = 0; counter[x][y] = -1; out[x][y] = LOW;
    }
    
    return counter[x][y]; // if done, -1
}
