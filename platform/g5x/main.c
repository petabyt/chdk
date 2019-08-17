#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "keyboard.h"

extern long link_bss_start;
extern long link_bss_end;
extern void boot();

void startup() {
    long *bss = &link_bss_start;
    // sanity check
    if ((long)&link_bss_end > (MEMISOSTART + MEMISOSIZE)) {
        started();
        shutdown();
    }
    // initialize .bss senment
    while (bss<&link_bss_end)
        *bss++ = 0;
    boot();
}

#define NUM_FL      101
#define NUM_DATA    2   // 2 words each entry, first is FL
extern int focus_len_table[NUM_FL*NUM_DATA];

// Conversion factor lens FL --> 35mm equiv
// lens      35mm     CF
// ----      ----     --
// 8.8       24       (24.0/8.8  ) * 100 = 273  (min FL)
// 36.8      100      (36.8/100.0) * 100 = 273  (max FL)
#define CF_EFL      273
#define CF_EFL_DIV  100

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

// TODO:
long get_vbatt_min()
{
    return 3000;
}

// TODO:
long get_vbatt_max()
{
    return 3900;
}

// Support swivel screen open/closed flag
int screen_opened(void) {
    return (physw_status[0] & 0x00002000);
}

// Support swivel screen rotated flag - used to flip CHDK UI.
int screen_rotated(void) {
    return !(physw_status[0] & 0x10000000);
}
