#include "data.h"
#include "printf_wrapper.h"
#include "settings.h"

// NEVER ACCESS DIRECTORY
// Seq
long g_seq0[] = {1000, 2000, 3000, 4000, 5000, 6000};
long g_seqlen0 = 6000;
long g_seq1[] = {100, 200, 300, 400, 500, 600};
long g_seqlen1 = 3000;
long g_seq2[] = {0, 3000};
long g_seqlen2 = 4000;
// Tran
int g_tran0[] = {0, 1, 2, 0};
int g_tran1[] = {1, 1, 1, 1};
int g_tran2[] = {2, 2, 2, 2};

void set_data(void) {
  // Seq
  // All data is the same for now
  for (int x = 0; x < XNUM; x++) {
  for (int y = 0; y < YNUM; y++) {
  data[0].seq[x][y] = g_seq0;
  data[0].seqlen[x][y] = g_seqlen0;
  data[0].len[x][y] = sizeof(g_seq0)/sizeof(g_seq0[0]);

  data[1].seq[x][y] = g_seq1;
  data[1].seqlen[x][y] = g_seqlen1;
  data[1].len[x][y] = sizeof(g_seq1)/sizeof(g_seq1[0]);

  data[2].seq[x][y] = g_seq2;
  data[2].seqlen[x][y] = g_seqlen2;
  data[2].len[x][y] = sizeof(g_seq2)/sizeof(g_seq2[0]);
  }
  }
  // Tran
  tran[0].tran = g_tran0;
  tran[0].len = sizeof(g_tran0)/sizeof(g_tran0[0]);
  tran[1].tran = g_tran1;
  tran[1].len = sizeof(g_tran1)/sizeof(g_tran0[1]);
  tran[2].tran = g_tran2;
  tran[2].len = sizeof(g_tran2)/sizeof(g_tran0[2]);
}
