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

   // sanity check (pointless with automemiso)
    if ((long)&link_bss_end > (MEMISOSTART + MEMISOSIZE)){
	started();
	shutdown();
    }

    // initialize .bss senment
    while (bss<&link_bss_end)
	*bss++ = 0;

    boot();
}

// sd970: Focus length table in firmware @0xfffe2a8c (same address as sd780)
#define NUM_FL      7   // 0 - 6, entries in firmware
#define NUM_DATA    3   // 3 words each entry, first is FL
extern int focus_len_table[NUM_FL*NUM_DATA];

// sd970: Conversion factor lens FL --> 35mm equiv
// lens      35mm     CF
// ----      ----     --
// 6.6       37       ( 37/ 6.6) * 66 = 370  (min FL)
// 33.0      185      (185/33.0) * 66 = 370  (max FL)
#define CF_EFL      370
#define	CF_EFL_DIV  66

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

// sd970: These come from sd990 which has the same battery
long get_vbatt_min()
{
    return 3425; // hnikesch on forum
}
long get_vbatt_max()
{
    return 4000; // fresh off charger slightly greater
}
