#ifndef PROPSET3_H
#define PROPSET3_H
/* 
constants for propset 3
WARNING:
 The build uses tools/gen_propset_lua.sed to generate propset3.lua from this file
*/
#define PROPCASE_DRIVE_MODE                 102
#define PROPCASE_FOCUS_MODE                 133     //WIKI|Propcase manual_focus
#define PROPCASE_REAL_FOCUS_MODE            6       //WIKI|Propcase focus_mode
#define PROPCASE_FOCUS_STATE                18
#define PROPCASE_FLASH_MODE                 143
#define PROPCASE_FLASH_FIRE                 122
#define PROPCASE_FLASH_MANUAL_OUTPUT        141
#define PROPCASE_FLASH_ADJUST_MODE          121
#define PROPCASE_USER_TV                    266
#define PROPCASE_TV	                        264
#define PROPCASE_USER_AV                    26
#define PROPCASE_AV                         23
#define PROPCASE_MIN_AV                     25
#define PROPCASE_SV                         249
#define PROPCASE_DELTA_SV                   79
#define PROPCASE_SV_MARKET                  248
#define PROPCASE_BV                         34
#define PROPCASE_SUBJECT_DIST1              247
#define PROPCASE_SUBJECT_DIST2              65
#define PROPCASE_DATE_STAMP                 66         // 0 = Off, 1 = Date, 2 = Date & Time
#define PROPCASE_ISO_MODE                   149
#define PROPCASE_EXPOSURE_LOCK              208     // Old PROPCASE_SHOOTING value - gets set when set_aelock called or AEL button pressed
#define PROPCASE_SHOOTING                   301     // This value appears to work better - gets set to 1 when camera has focused and set exposure, returns to 0 after shot
#define PROPCASE_IS_FLASH_READY             210 
#define PROPCASE_OVEREXPOSURE               103
#define PROPCASE_SHOOTING_MODE              49
#define PROPCASE_IS_MODE                    145
#define PROPCASE_QUALITY                    57
#define PROPCASE_RESOLUTION                 220
#define PROPCASE_EV_CORRECTION_1            107
#define PROPCASE_EV_CORRECTION_2            209
#define PROPCASE_ORIENTATION_SENSOR         221
#define PROPCASE_DIGITAL_ZOOM_MODE          91     // Digital Zoom Mode/State 0 = off/standard, 2 = 1.4x, 3 = 2.3x
#define PROPCASE_DIGITAL_ZOOM_STATE         94
#define PROPCASE_DIGITAL_ZOOM_POSITION      95
#define PROPCASE_DISPLAY_MODE               105
#define PROPCASE_BRACKET_MODE               29
#define PROPCASE_FLASH_SYNC_CURTAIN         64
#define PROPCASE_METERING_MODE              155
#define PROPCASE_WB_MODE                    270     // 0 = Auto, 1 = Daylight, 2 = Cloudy, 3 = Tungsten, 4 = Fluorescent, 5 = Fluorescent H, 7 = Custom
#define PROPCASE_WB_ADJ                     271
#define PROPCASE_ASPECT_RATIO               294
#define PROPCASE_TIMER_MODE                 225
#define PROPCASE_OPTICAL_ZOOM_POSITION      197
#define PROPCASE_VIDEO_RESOLUTION           169
#define PROPCASE_AF_ASSIST_BEAM             5       // 0=disabled,  1=enabled
#define PROPCASE_AF_LOCK                    11      // 0 = AF not locked, 1 = AF locked
#define PROPCASE_CONTINUOUS_AF              12      // 0 = Continuous AF off, 1 = Continuous AF on
#define PROPCASE_SERVO_AF                   297     // 0 = Servo AF off, 1 = Servo AF on
#define PROPCASE_TIMER_SHOTS                336     // Number of shots for TIMER_MODE=Custom
#endif
