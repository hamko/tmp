#ifndef __UPDOWN_H_INCLUDED__
#define __UPDOWN_H_INCLUDED__

extern void init_updown(void);

// seq: Up-Down Sequence, len: Length of seq
extern void updown(long* seq/*ms*/, int len/*index*/, long seqlen/*ms*/, long long seq_t/*ns*/, int n);

#endif
