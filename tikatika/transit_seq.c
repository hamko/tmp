#include "transit_seq.h"
#include "settings.h"
#include "updown.h"
#include "data.h"

int transit_seq(int* tran, int tranlen, long long tran_t) {
	int i;

	// Select index
	int index = -1;
	long sum_ms = 0;
	for (i = 0; i < tranlen; i++) {
		long step = data[tran[i]].seqlen[0];
		if ((long long)(sum_ms + step) * MS2NS > tran_t) {
			index = i;
			break;
		}
		sum_ms += step;
	}
	if (index < 0)
		return 1;

	int s = tran[index];
	for (i = 0; i < LED_NUM; i++) 
		updown(data[s].seq[i], data[s].len[i], data[s].seqlen[i], tran_t - (long long)sum_ms * MS2NS, i);

	return 0;
}
