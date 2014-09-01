#ifndef __SETTINGS_H_INCLUDED__
#define __SETTINGS_H_INCLUDED__

#include <gpio.h>
#include "seq.h"
#include "tran.h"

//#define DEBUG_MODE

#define SEC2NSEC (1000000000LL)
#define MS2NS (1000000LL)

#define LED_NUM 15


extern PIN led[LED_NUM];
extern long long t;

#endif
