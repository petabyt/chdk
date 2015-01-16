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

// Focus length table - found by found scanning memory for 1st table entry : 0x88 0x13 0x00 0x00   0x64 0x00 0x00 0x00 ( 5000 100 decimal )
// Conversion factor lens FL --> 35mm equiv
// from Canon specs :  5.0 (W) - 40.0 (T) mm (35mm film equivalent: 28 (W) - 224 (T) mm)
// lens      35mm     CF
// ----      ----     --
//  5.0      28      ( 28/ 5.0) * 50 = 280  (min FL)
// 40.0     224      (224/40.0) * 50 = 280  (max FL)
#define CF_EFL      280
#define CF_EFL_DIV  50
#define NUM_FL      128   // 0 - 63 entries in firmware 
#define NUM_DATA    2     // 2 words each entry, first is FL
extern int focus_len_table[NUM_FL*NUM_DATA];

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
    return 3200;   // powershot N
}

long get_vbatt_max()
{
    return 4000;   // powershot N
}
