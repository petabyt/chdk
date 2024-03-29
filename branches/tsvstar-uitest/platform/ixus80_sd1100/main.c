#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "keyboard.h"


extern long link_bss_start;
extern long link_bss_end;
extern void boot();


void startup()
{
    long *bss = &link_bss_start;
    long *ptr;

    // sanity check
    if ((long)&link_bss_end > (MEMISOSTART + MEMISOSIZE)){
	started();
	shutdown();
    }

    // initialize .bss senment
    while (bss<&link_bss_end)
	*bss++ = 0;


    boot();
}


static const int fl_tbl[] = {6200, 7230, 8295, 9681, 11614, 14303, 18600};
#define NUM_FL (sizeof(fl_tbl)/sizeof(fl_tbl[0]))
#define CF_EFL 61291

const int zoom_points = NUM_FL;

int get_effective_focal_length(int zp) {
    return (CF_EFL*get_focal_length(zp))/10000;
}

int get_focal_length(int zp) {
    if (zp<0) return fl_tbl[0];
    else if (zp>NUM_FL-1) return fl_tbl[NUM_FL-1];
    else return fl_tbl[zp];
}

int get_zoom_x(int zp) {
    if (zp<1) return 10;
    else if (zp>NUM_FL-1) return fl_tbl[NUM_FL-1]*10/fl_tbl[0];
    else return fl_tbl[zp]*10/fl_tbl[0];
}

/*
from memory browser physw_status[0-2]:

play:
216e 31c4
d0d8 0fa4  //d0d8 0f84
0000 8fff

rec:
21af 61c4
e0d9 7fa4 // e0d9 7fa4
0000 8fff

*/
#if 0
int rec_switch_state(void) {
//    mode  = (physw_status[1] & 0x10000000)?MODE_PLAY:MODE_REC;
	return !(physw_status[1] & 0x10000000);
}
#endif

long get_vbatt_min()
{
    return 3500;
}

long get_vbatt_max()
{
    return 4100;
}
