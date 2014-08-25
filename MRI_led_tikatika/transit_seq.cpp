#include "transit_seq.h"
#include <Arduino.h>
#include "settings.h"
#include "updown.h"
#include "data.h"

static int index = -1;
int transit_seq(int* tran, int tranlen) {
  if (index < 0)
    index = 0;

  int s = tran[index];
  boolean done = 0;
  for (int x = 0; x < XNUM; x++) {
    for (int y = 0; y < YNUM; y++) {
      if (updown(data[s].seq, data[s].len, data[s].seqlen, x, y) == -1) { // TODO seq, lenにx, yの情報がない．全部同じ時系列になってる
        done = 1;
      }
    }
  }

  if (done)
    index++;
  
  if (index >= tranlen)
    index = -1;
  
  return index;
}
