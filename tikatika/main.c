#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sched.h>
#include <sys/mman.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <linux/input.h>
#include <gpio.h>
#include <am335x.h>

#include "settings.h"
#include "data.h"
#include "seq.h"
#include "tran.h"
#include "transit_seq.h"
#include "mri_dt.h"

/* System Global */
long long t;		// task time [nsec]
int mode;		// mode = 0: waiting for command, mode = 0 else: running mode
int fd;			// Keyboard file
data_t data[DATA_NUM];
tran_t tran[TRAN_NUM];
int keyboard_command;
struct input_event keyboard_event;

void clear_led(void) {
	int i;
	for (i = 0; i < LED_NUM; i++)
		digitalWrite(led[i], LOW);
}

static long mri_counter;
static struct timespec rt_base; // rt at mri signal [tv_sec, tv_nsec]
void init_run(void)
{
	mri_counter = 0;
	t = 0;
	rt_base.tv_sec = 0; rt_base.tv_nsec = 0;
	while (read(fd, &keyboard_event, sizeof(keyboard_event)) >= 0); // trash all keyboard input when the mode is command mode
	clear_led();
}

void command(void)
{
	clear_led();
	printf("Ready: type 1-9\n");

	char str[128];
	fgets(str, sizeof(str), stdin);
	if (strlen(str) < 3 && str[0] - '0' > 0 && str[0] - '0' < 10) { // one character and digit
		mode = str[0] - '0';
		init_run();
		printf("Start Mode %d\n", mode);
	} else {
		printf("type 1-9\n");
	}
}

int counter = 0;
void run(void)
{
	// rt: temporary real time, 
	struct timespec rt; // real time [tv_sec, tv_nsec]
	// Time Revise
	clock_gettime(CLOCK_MONOTONIC ,&rt);

	// Read
	read(fd, &keyboard_event, sizeof(keyboard_event));
	if (keyboard_command >= 0 && keyboard_event.type == EV_KEY && keyboard_event.value == 1 && keyboard_event.code == KEY_5) {
		mri_counter++;
		rt_base = rt;
	}
	if (!mri_counter)
		return;

	t = MRI_DT * (mri_counter - 1) + (rt.tv_sec - rt_base.tv_sec) * SEC2NSEC + (rt.tv_nsec - rt_base.tv_nsec);
#ifdef DEBUG_MODE
	if (counter % 1000 == 0)
		printf("t: %lld\n", t);
#endif

	if (transit_seq(tran[mode-1].tran, tran[mode-1].len, t)) {
		printf("Mode %d finished\n", mode);
		mode = 0;
		clear_led();
	}

	counter++; 
}

PIN led[LED_NUM];
void setup() {
	/*
	led[0] = P8_3;
	led[1] = P8_4;
       	led[2] = P8_5; 
	*/
	led[0] = USR1;
	led[1] = USR2;
       	led[2] = USR3; 

	led[3] = P8_6;
       	led[4] = P8_7;
       	led[5] = P8_8;
       	led[6] = P8_9;
       	led[7] = P8_10;
       	led[8] = P8_11;
       	led[9] = P8_12;
       	led[10] = P8_13;
       	led[11] = P8_14;
       	led[12] = P8_15;
       	led[13] = P8_16;
       	led[14] = P8_17;

	int i;
	for (i = 0; i < LED_NUM; i++) 
		pinMode(P8_13, OUTPUT, 7, PULLUP);

	set_data();
	set_tran();
}

int main(int argc, char* argv[])
{
	fd = open("/dev/input/event0", O_NONBLOCK);
	init();
	setup();

	while (1) {
		if (mode == 0)
			command();
		else
			run();
	}

	return 0;
}

