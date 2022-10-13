#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "keyboard.h"


extern long link_bss_start;
extern long link_bss_end;
extern void boot();

void startup() {
    long *bss = &link_bss_start;
//    *(int*)0xd20b0884 = 0x4d0002;

    // sanity check
    if ((long)&link_bss_end > (MEMISOSTART + MEMISOSIZE)) {
        started();
        shutdown();
    }
    // initialize .bss senment
    while (bss<&link_bss_end)
        *bss++ = 0;
//    *(int*)0xd20b0884 = 0x4d0002;
    boot();
}
int screen_opened(void) {
        return (physw_status[2] & 0x00000200);
}

int screen_rotated(void) {
        return !(physw_status[2] & 0x00000100);
}


#define NUM_FL      201
#define NUM_DATA    1   // 1 entry per FL  
extern int focus_len_table[NUM_FL*NUM_DATA];

// Conversion factor lens FL --> 35mm equiv
// lens      35mm     CF
// ----      ----     --
// 3.8	     21.3     (21.3/3.8) * 38 = 213 
// 247       1385.8   (1385.8/247)*38 = 213
//cropfactor 5.61
#define CF_EFL      213
#define CF_EFL_DIV  38

const int zoom_points = NUM_FL;

int get_effective_focal_length(int zp) {
    return (CF_EFL*get_focal_length(zp))/CF_EFL_DIV;
}

int get_focal_length(int zp) {
    if (zp < 0) zp = 0;
    else if (zp >= NUM_FL) zp = NUM_FL-1;
    return focus_len_table[zp*NUM_DATA];
}

int get_zoom_x(int zp) {
    return get_focal_length(zp)*10/focus_len_table[0];
}

long get_vbatt_min()
{
    return 6450; //6700 is red in Canon display
}


long get_vbatt_max()
{

    return 8250;  //8300
}
