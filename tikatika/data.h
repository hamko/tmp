#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

#include "settings.h"

typedef struct {
  long* seq[LED_NUM];
  int len[LED_NUM];
  long seqlen[LED_NUM];
} data_t;

typedef struct {
  int* tran;
  int len;
} tran_t;

extern data_t data[DATA_NUM];
extern tran_t tran[TRAN_NUM];
extern void set_data(void);

#endif
