#include "data.h"
#include "printf_wrapper.h"

data_t data[DATA_NUM];

// NEVER ACCESS DIRECTORY
long g_seq0[] = {1000, 2000, 3000, 4000, 5000, 6000};
long g_seqlen0 = 6000;
long g_seq1[] = {100, 200, 300, 400, 500, 600};
long g_seqlen1 = 3000;
long g_seq2[] = {0, 3000};
long g_seqlen2 = 4000;

void set_data(void) {
  data[0].seq = g_seq0;
  data[0].seqlen = g_seqlen0;
  data[0].len = sizeof(g_seq0)/sizeof(g_seq0[0]);

  data[1].seq = g_seq1;
  data[1].seqlen = g_seqlen1;
  data[1].len = sizeof(g_seq1)/sizeof(g_seq1[0]);

  data[2].seq = g_seq2;
  data[2].seqlen = g_seqlen2;
  data[2].len = sizeof(g_seq2)/sizeof(g_seq2[0]);
}
