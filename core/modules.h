#ifndef MODULES_H
#define MODULES_H

// MODULE "RAW OPERATIONS"
//--------------------------
#include "raw_merge.h"

// MODULE "EDGE OVERLAY"
//--------------------------
#include "edgeoverlay.h"

// MODULE "ZEBRA OVERLAY"
//--------------------------
#include "zebra.h"

// MODULE "CURVES"
//--------------------------
#include "curves.h"

// MODULE "MOTION DETECT"
//--------------------------
#include "motion_detector.h"

// MODULE "GRIDS"
//--------------------------
#include "gui_grid.h"

// MODULE "PALETTE"
//--------------------------
#include "gui_palette.h"

// MODULE "FILE SELECTOR"
//--------------------------
#include "gui_fselect.h"

// MODULE "MPOPUP"
//--------------------------
#include "gui_mpopup.h"

// MODULE "DNG"
//--------------------------
#include "dng.h"

// MODULE "TBOX"
//--------------------------
int module_tbox_get_version();
void module_tbox_run( int title, int msg, char* defaultvalue, unsigned int maxsize, void (*on_select)(char* newstr));

#endif
