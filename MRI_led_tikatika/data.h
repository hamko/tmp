#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

#include "settings.h"

typedef struct {
  long* seq[XNUM][YNUM];
  int len[XNUM][YNUM];
  long seqlen[XNUM][YNUM];
} data_t;

typedef struct {
  int* tran;
  int len;
} tran_t;

extern data_t data[DATA_NUM];
extern tran_t tran[DATA_NUM];
extern void set_data(void);

#endif
