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
	
	// sanity check
	if ((long)&link_bss_end > (MEMISOSTART + MEMISOSIZE))
	{
		started();
		shutdown();
	}

	// initialize .bss senment
	while (bss<&link_bss_end)
		*bss++ = 0;

	boot();
}

// same number of zoom steps as in ixus160
#define NUM_FL      101
#define NUM_DATA    2

extern int focus_len_table[NUM_FL*NUM_DATA];

// Conversion factor lens FL --> 35mm equiv
// lens      35mm     CF
// ----      ----     --
//  4.5       25      (25/4.5) * 18 = 100  (min FL)
// 54        300      (300/54) * 18 = 100  (max FL)
#define CF_EFL      100
#define CF_EFL_DIV  18

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

    return 3250; // tested
}

long get_vbatt_max()
{
    return 4000; // tested
}

