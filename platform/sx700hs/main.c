#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "keyboard.h"


extern long link_bss_start;
extern long link_bss_end;
extern void boot();

void startup() {
    long *bss = &link_bss_start;
//    *(int*)0xd20b0994 = 0x4d0002;

    // sanity check
    if ((long)&link_bss_end > (MEMISOSTART + MEMISOSIZE)) {
        started();
        shutdown();
    }
    // initialize .bss senment
    while (bss<&link_bss_end)
        *bss++ = 0;
//    *(int*)0xd20b0994 = 0x4d0002;
    boot();
}

/* Screen is not articulated
int screen_opened(void) {
        return (physw_status[2] & 0x00000200);
}

int screen_rotated(void) {
        return !(physw_status[2] & 0x00000100);
}
*/

#define NUM_FL      113 // From physw_status
#define NUM_DATA    2   // 2 words each entry, first is FL
extern int focus_len_table[NUM_FL*NUM_DATA];

// Conversion factor lens FL --> 35mm equiv
// lens      35mm     CF
// ----      ----     --
//  4.5      25       ( 25/  4.5) * 180 = 1000  (min FL)
//135.0     750       (750/135.0) * 180 = 1000  (max FL)

#define CF_EFL      1000
#define CF_EFL_DIV  180

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
    return 3200; //3100 is red in Canon display
}


long get_vbatt_max()
{

    return 4060;  //8300
}
