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

// return whether video is actually being recorded
extern int is_video_recording();

#define MIN_DIST                    CAMERA_MIN_DIST     // Defined in camera.h (can be overridden in platform_camera.h)
#define MAX_DIST                    CAMERA_MAX_DIST     // Defined in camera.h (can be overridden in platform_camera.h)
#define INFINITY_DIST               0xFFFFFFFF          // Value to send to firmware to select 'infinity' focus

//********************
//char * get_debug();
//********************

#define MODE_SCREEN_MASK            0x0C00
#define MODE_SCREEN_OPENED          0x0400
#define MODE_SCREEN_ROTATED         0x0800

/* Keyboard repeat and initial delays */
#define KBD_REPEAT_DELAY  140
#define KBD_INITIAL_DELAY 300

// Video recording current status constants, see movie_status variable 
#define VIDEO_RECORD_NEVER_STARTED  0  
#define VIDEO_RECORD_STOPPED        1  
#define VIDEO_RECORD_IN_PROGRESS    4

//Optical & digital zoom status constants, see zoom_status variable 
#define ZOOM_OPTICAL_MIN            1
#define ZOOM_OPTICAL_MAX            2
#define ZOOM_OPTICAL_MEDIUM         3
#define ZOOM_OPTICAL_IN             4
#define ZOOM_OPTICAL_OUT            5
#define ZOOM_OPTICAL_REACHED_MIN    7

#define ZOOM_DIGITAL_MAX            9
#define ZOOM_DIGITAL_MEDIUM         10
#define ZOOM_DIGITAL_IN             11
#define ZOOM_DIGITAL_OUT            12
#define ZOOM_DIGITAL_REACHED_MAX    13

typedef struct {
    unsigned short hackmode;   // platform independent mode values from MODE_xxx enum
    unsigned short canonmode;  // PROPCASE_SHOOTING_MODE value
} CapturemodeMap;

#define SHOW_ALWAYS    1
#define SHOW_HALF      2

#define PHOTO_PARAM_TV_NONE 32767 // ~ 1/(2^341) seconds, safe marker for "no value"

typedef struct {
    short av96;
    short tv96;
    short sv96;
    short subj_dist;
    short nd_filter;
} PHOTO_PARAM;

typedef struct {
    short av96;
    short tv96;
    short sv96;
    short iso;
    short sv96_market;
    short iso_market;
    short bv96_measured;
    short bv96_seted;       //Ev96_internal-Sv96
    short ev96_seted;       //Tv96+Av96
    short ev96_measured;    //Bv96+Sv96
    short dev96;            // Ev96_external-Ev96_internal
    short dev96_canon;      // Canon OverExposure
    int b;                  //average scene luminance 
} EXPO_TYPE;

typedef struct {
    float value;
    char fraction[10];
} shutter_speed;


/******************************************************************/

void remount_filesystem();
void mark_filesystem_bootable();

/******************************************************************/

#ifdef CAM_LOAD_CUSTOM_COLORS
// Color palette function
extern void load_chdk_palette();
#endif
/******************************************************************/

void hook_raw_save_complete();

/******************************************************************/
extern void shooting_init(); // startup initialization

#if defined(CAM_DRAW_EXPOSITION)
    char* shooting_get_tv_str();
    char* shooting_get_av_str();
#endif
/******************************************************************/

// returns 0 if in play, nonzero if rec
int rec_mode_active(void); 

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
void clear_values();
/******************************************************************/

void change_video_tables(int a, int b);

/******************************************************************/
extern int canon_menu_active;
extern char canon_shoot_menu_active;
extern int recreview_hold;

void MakeAFScan(void);
extern int zoom_status;
void EnterToCompensationEVF(void);
void ExitFromCompensationEVF(void);

extern void PutInNdFilter();
extern void PutOutNdFilter();
extern long GetCurrentAvValue();
extern long IsStrobeChargeCompleted();
extern void SetCurrentCaptureModeType();
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

void wait_until_remote_button_is_released(void);

//image_quality_override
void shooting_set_image_quality(int imq);

int get_ev_video_avail(void);
void set_ev_video_avail(int);
int get_ev_video(void);
void set_ev_video(int);
void save_ext_for_dng(void);
void change_ext_to_dng(void);
void change_ext_to_default(void);

void drv_self_hide(void);
void drv_self_unhide(void);

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

