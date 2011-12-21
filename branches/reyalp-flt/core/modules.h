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

int module_edgeovr_load();						// 0fail, 1ok

// MODULE "CURVES"
//--------------------------
#include "curves.h"

int module_curves_load();						// 0fail, 1ok

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



//--------------------------
void module_convert_dng_to_chdk_raw(char* fn);


#endif
