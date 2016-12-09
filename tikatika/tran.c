#include "data.h"
#include "tran.h"
#include "settings.h"
int g_tran0[] =   {0,0,0,0,};
int g_tran1[] =   {0,1,0,};
int g_tran2[] =   {1,2,3,4,};
int g_tran3[] =   {0,1,0,};
int g_tran4[] =   {1,2,3,4,};
int g_tran5[] =   {0,1,0,};
int g_tranlen[TRAN_NUM] = {4,3,4,3,4,3,};
void set_tran(void) {
  tran[0].tran = g_tran0;
  tran[1].tran = g_tran1;
  tran[2].tran = g_tran2;
  tran[3].tran = g_tran3;
  tran[4].tran = g_tran4;
  tran[5].tran = g_tran5;
  int i;
  for (i = 0; i < TRAN_NUM; i++) 
    tran[i].len = g_tranlen[i];
}
