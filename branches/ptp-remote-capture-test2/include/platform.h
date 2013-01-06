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

#ifdef CAM_LOAD_CUSTOM_COLORS
// Color palette function
extern void load_chdk_palette();
#endif
/******************************************************************/

#if defined(CAM_DRAW_EXPOSITION)
    char* shooting_get_tv_str();
    char* shooting_get_av_str();
#endif
/******************************************************************/

// not used. Right now this is just to preserve code from earlier version of mode_get()
// in case we want to check play/rec switch state in the future.
// WARNING: it isn't known if all variants of this check the switch state or some other bit.
// should return 0 is switch is in play position, non-zero otherwise
//int rec_switch_state(void);

// swivel screen state.
#ifdef CAM_SWIVEL_SCREEN
// 0 not open, non-zero open
int screen_opened(void);
// 0 not rotated, non-zero rotated
int screen_rotated(void);
#endif

/******************************************************************/

#if CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO
extern void UnsetZoomForMovie();
#endif
#ifdef CAM_AV_OVERRIDE_IRIS_FIX
extern int MoveIrisWithAv(short*);
#endif
#if CAM_EV_IN_VIDEO
extern void ExpCtrlTool_StartContiAE(int, int);
extern void ExpCtrlTool_StopContiAE(int, int);
extern short SetAE_ShutterSpeed(short* tv);
#endif

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

#endif

