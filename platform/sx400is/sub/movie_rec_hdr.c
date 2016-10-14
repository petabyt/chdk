#include "conf.h"

static int bitrate_multiplier = 4; // unit: factory rate / 4
static int bitrate_changed = 0;
extern int video_target_framesize;
extern int video_target_framesize2;


static int orig_bitrate[2]; // original bitrates, saved at beginning of recording

void change_video_tables(int a, int b) {
    bitrate_multiplier = (a<<2)/b;
    bitrate_changed = 1;
}

// firmware: -12 (best) ... +20 (worst)
void  set_quality(int *x){ // -17 highest; +12 lowest
 if (conf.video_mode) *x=12-((conf.video_quality-1)*(12+17)/(99-1));
}

void save_original_bitrates() {
    orig_bitrate[0] = video_target_framesize;
    orig_bitrate[1] = video_target_framesize2;
    bitrate_changed = 1;
}

void modify_bitrate() {
    if (bitrate_changed) {
        bitrate_changed = 0;
        video_target_framesize = (orig_bitrate[0] * bitrate_multiplier) >> 2;
        video_target_framesize2 = (orig_bitrate[1] * bitrate_multiplier) >> 2;
    }
}

