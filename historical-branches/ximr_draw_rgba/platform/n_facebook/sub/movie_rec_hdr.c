// Powershot N 
// currently disabled because it likely requires the more complicated code similar to other propset 6 cameras
#include "conf.h"

void change_video_tables(int a, int b){ }

void  set_quality(int *x){ // -17 highest; +12 lowest
 if (conf.video_mode) *x=12-((conf.video_quality-1)*(12+17)/(99-1));
}
