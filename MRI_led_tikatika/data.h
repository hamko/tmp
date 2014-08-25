#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

typedef struct {
  long* seq;
  int len;
  long seqlen;
} data_t;

#define DATA_NUM 3
extern data_t data[DATA_NUM];
extern void set_data(void);

#endif
