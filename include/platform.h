#ifndef PLATFORM_H
#define PLATFORM_H

#ifdef CHDK_MODULE_CODE
#error platform.h cannot be #included in module code.
#endif

#include "camera.h"
#include "keyboard.h"
#include "clock.h"
#include "modes.h"
#include "backlight.h"
#include "viewport.h"
#include "properties.h"
#include "sd_card.h"
#include "meminfo.h"
#include "debug_led.h"
#include "shooting.h"
#include "file_counter.h"
#include "temperature.h"
#include "battery.h"
#include "lens.h"
#include "shutdown.h"
#include "sound.h"
#include "task.h"

/******************************************************************/
    
#if !CAM_DRYOS
extern void drv_self_hide(void);
extern void drv_self_unhide(void);
#endif

/******************************************************************/

// debug logging function - see generic wrappers.c to adjust destination
// WARNING fixed length buffer
extern void dbg_printf(char *fmt,...);

//#define DEBUG_LOGGING
// debug with timestamp
#ifdef DEBUG_LOGGING
#define DBGPRINTF(fmt,args...) dbg_printf("%08d DBG:" fmt,get_tick_count(), ##args)
#else
#define DBGPRINTF(...)
#endif

/******************************************************************/

// flash hot shoe sense bit override macro, for use in platform kbd.c
#ifdef CAM_HOTSHOE_OVERRIDE
#define HOTSHOE_OVERRIDE \
    if (conf.hotshoe_override == 1) { \
        physw_status[HOTSHOE_IDX] = physw_status[HOTSHOE_IDX] & ~HOTSHOE_FLAG; \
    } \
    else if (conf.hotshoe_override == 2) { \
        physw_status[HOTSHOE_IDX] = physw_status[HOTSHOE_IDX] | HOTSHOE_FLAG; \
    }
#endif

/******************************************************************/

#endif

