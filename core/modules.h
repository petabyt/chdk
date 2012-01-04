#ifndef MODULES_H
#define MODULES_H

// MODULE "RAW OPERATIONS"
//--------------------------
#include "raw_merge.h"

struct librawop_sym* module_rawop_load();		// 0fail, addr-ok
void module_rawop_unload();


// MODULE "EDGE OVERLAY"
//--------------------------
#include "edgeoverlay.h"

struct libedgeovr_sym* module_edgeovr_load();	// 0fail, addr-ok

// MODULE "CURVES"
//--------------------------
#include "curves.h"

struct libcurves_sym* module_curves_load();		// 0fail, addr-ok

// MODULE "PALETTE"
//--------------------------
#include "gui_palette.h"
void module_palette_run(int mode, color st_color, void (*on_select)(color clr));

// MODULE "FILE SELECTOR"
//--------------------------
void module_fselect_init(int title, const char* prev_dir, const char* default_dir, void (*on_select)(const char *fn));
void module_fselect_init_w_mode(int title, const char* prev_dir, const char* default_dir, void (*on_select)(const char *fn), unsigned int key_redraw_mode);

// MODULE "MPOPUP"
//--------------------------
#include "gui_mpopup.h"
void module_mpopup_init(struct mpopup_item* popup_actions, const unsigned int flags, void (*on_select)(unsigned int actn), int mode);


// MODULE "DNG"
//--------------------------
#include "dng.h"

// values of semaphore
#define LIBDNG_OWNED_BY_RAW 			0x1
#define LIBDNG_OWNED_BY_CONVERT 		0x2
#define LIBDNG_OWNED_BY_CREATEBADPIXEL	0x4

struct libdng_sym* module_dng_load(int owner);		// 0fail, addr-ok
void module_dng_unload(int owner);

int module_convert_dng_to_chdk_raw(char* fn);		// Return: 0-fail, 1-ok



#endif
