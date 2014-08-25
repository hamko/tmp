#ifndef __UPDOWN_H_INCLUDED__
#define __UPDOWN_H_INCLUDED__

extern void init_updown(void);

// seq: Up-Down Sequence, len: Length of seq
extern long updown(long* seq/*ms*/, int len/*index*/, long seqdone/*ms*/, int x, int y); // if done, return -1

#endif
