#include <stdio.h>
#include "settings.h"

static int onoroff(long* arry, int size, long long target/*ns*/) {
	if (target >= (long long)arry[size-1] * MS2NS)
		return 0;
	if (target < (long long)arry[0] * MS2NS)
		return 0;

	int lowid = 0, highid = size, midid;

	while (highid - lowid > 1) {
		midid = (lowid + highid) / 2;
		if ((long long)arry[midid] * MS2NS <= target)
			lowid = midid;
		else
			highid = midid;
	}

	return !(lowid % 2);
}

void updown(long* seq/*ms*/, int len/*index*/, long seqlen/*ms*/, long long seq_t/*ns*/, int n) {
	if (!len) // no time to blinck
		return;
	if (seq_t / MS2NS > seqlen) { // input error
		printf("input error: seq_t must be below seqlen * MS2NS\n");
		return;
	}

	digitalWrite(led[n], onoroff(seq, len, seq_t));
}
