#ifndef PROPSET1_H
#define PROPSET1_H
/* 
constants for propset 1, most digic2 camera
WARNING:
 The build uses tools/gen_propset_lua.sed to generate propset1.lua from this file
*/
#define PROPCASE_DRIVE_MODE                 6
#define PROPCASE_FOCUS_MODE                 12      //WIKI|Propcase manual_focus
#define PROPCASE_REAL_FOCUS_MODE            11      //WIKI|Propcase focus_mode
#define PROPCASE_FOCUS_STATE                67
#define PROPCASE_FLASH_MODE                 16
#define PROPCASE_FLASH_FIRE                 79
// need corresponding values for propset2!!!
#define PROPCASE_FLASH_ADJUST_MODE          15
// #define PROPCASE_FLASH_CORRECTION               28      
#define PROPCASE_FLASH_MANUAL_OUTPUT        29
#define PROPCASE_USER_TV                    40
#define PROPCASE_TV	                        69
#define PROPCASE_USER_AV                    39
#define PROPCASE_AV                         68
#define PROPCASE_MIN_AV                     77
#define PROPCASE_SV                         73
#define PROPCASE_DELTA_SV                   70
#define PROPCASE_SV_MARKET                  72
#define PROPCASE_BV                         71
#define PROPCASE_ISO_MODE                   21
#define PROPCASE_SUBJECT_DIST1              65
#define PROPCASE_SUBJECT_DIST2              66
#define PROPCASE_SHOOTING                   205
#define PROPCASE_IS_FLASH_READY             221
#define PROPCASE_OVEREXPOSURE               76
#define PROPCASE_SHOOTING_MODE              0
#define PROPCASE_IS_MODE                    229
#define PROPCASE_QUALITY                    23
#define PROPCASE_RESOLUTION                 24
#define PROPCASE_EV_CORRECTION_1            25
#define PROPCASE_EV_CORRECTION_2            26
#define PROPCASE_ORIENTATION_SENSOR         37
#define PROPCASE_DIGITAL_ZOOM_STATE         58
#define PROPCASE_DIGITAL_ZOOM_POSITION      57
#define PROPCASE_DISPLAY_MODE               181
#define PROPCASE_BRACKET_MODE               36 //missing for dryos!
#define PROPCASE_FLASH_SYNC_CURTAIN         20
#define PROPCASE_METERING_MODE              9
#define PROPCASE_WB_ADJ                     100
#define PROPCASE_OPTICAL_ZOOM_POSITION      99 //untested !
#define PROPCASE_STITCH_DIRECTION           52 // 0=left>right, 1=right>left. Some cams have more
#define PROPCASE_STITCH_SEQUENCE            48 // counts shots in stitch sequence, positive for left-right, negative for right-left
#endif
