#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "conf.h"

//static long *nrflag = (long*)0xC910; // FFAB026C

static long *nrflag = (long*)0x5CB4;

#define PAUSE_FOR_FILE_COUNTER 150

#include "../../../generic/capt_seq.c"


int capt_seq_hook_set_nr_my(int orig)
{
 
	camera_info.state.shutter_open_time = _time((void*)0); 
    camera_info.state.shutter_open_tick_count = get_tick_count();

	// Firmware also tests for 3 and 7, meaning unknown, so we don't touch them
	if (orig!=NR_ON && orig!=NR_OFF)
		return orig;

	switch (conf.raw_nr){
	case NOISE_REDUCTION_OFF:
		return NR_OFF;
	case NOISE_REDUCTION_ON:
		return NR_ON;
	case NOISE_REDUCTION_AUTO_CANON: // leave it alone
	default: // shut up compiler 
		return orig;
	};
}

