#ifndef PROPSET5_H
#define PROPSET5_H

/*
constants for propset 5
WARNING:
The build uses tools/gen_propset_lua.sed to generate propset5.lua from this file
*/

#define PROPCASE_AE_LOCK                         3          // 0 = AE not locked, 1 = AE locked
#define PROPCASE_AF_ASSIST_BEAM                  5          // 0=disabled,  1=enabled
#define PROPCASE_REAL_FOCUS_MODE                 6          //??? WIKI|Propcase focus_mode
#define PROPCASE_AF_FRAME                        8          // 1 = FlexiZone, 2 = Face AiAF / Tracking AF
#define PROPCASE_AF_LOCK                         11         // 0 = AF not locked, 1 = AF locked
#define PROPCASE_CONTINUOUS_AF                   12         // 0 = Continuous AF off, 1 = Continuous AF on
#define PROPCASE_FOCUS_STATE                     18         //???
#define PROPCASE_AV2                             22         // (philmoz, May 2011) - this value causes overrides to be saved in JPEG and shown on Canon OSD
#define PROPCASE_AV                              23         // This values causes the actual aperture value to be overriden
#define PROPCASE_MIN_AV                          25
#define PROPCASE_USER_AV                         26
#define PROPCASE_BRACKET_MODE                    29
#define PROPCASE_BV                              34
#define PROPCASE_SHOOTING_MODE                   49
#define PROPCASE_CUSTOM_SATURATION               55         // Canon Menu slide bar values: 255, 254, 0, 1, 2
#define PROPCASE_QUALITY                         57
#define PROPCASE_CUSTOM_CONTRAST                 59         // Canon Menu slide bar values: 255, 254, 0, 1, 2
#define PROPCASE_FLASH_SYNC_CURTAIN              64
#define PROPCASE_SUBJECT_DIST2                   65
#define PROPCASE_DATE_STAMP                      66         // 0 = Off, 1 = Date, 2 = Date & Time
#define PROPCASE_DELTA_SV                        79
#define PROPCASE_DIGITAL_ZOOM_MODE               91         // Digital Zoom Mode/State 0 = off/standard, 2 = 1.5x, 3 = 2.0x
#define PROPCASE_DIGITAL_ZOOM_STATE              94         // Digital Zoom Mode/State 0 = Digital Zoom off, 1 = Digital Zoom on
#define PROPCASE_DIGITAL_ZOOM_POSITION           95
#define PROPCASE_DRIVE_MODE                      102
#define PROPCASE_OVEREXPOSURE                    103
#define PROPCASE_DISPLAY_MODE                    105
#define PROPCASE_EV_CORRECTION_1                 107
#define PROPCASE_FLASH_ADJUST_MODE               121
#define PROPCASE_FLASH_FIRE                      122
#define PROPCASE_FLASH_EXP_COMP                  127    // APEX96 units
#define PROPCASE_FOCUS_MODE                      133
#define PROPCASE_FLASH_MANUAL_OUTPUT             141        // !not sure, but required for compile; from propset4
#define PROPCASE_FLASH_MODE                      143        // 0 = Auto, 1 = ON, 2 = OFF
#define PROPCASE_IS_MODE                         145        // 0 = Continuous, 2 = only Shoot, 4 = OFF
#define PROPCASE_ISO_MODE                        149
#define PROPCASE_METERING_MODE                   157
#define PROPCASE_CUSTOM_BLUE                     177        // Canon Menu slide bar values: 255, 254, 0, 1, 2
#define PROPCASE_CUSTOM_GREEN                    178        // Canon Menu slide bar values: 255, 254, 0, 1, 2
#define PROPCASE_CUSTOM_RED                      179        // Canon Menu slide bar values: 255, 254, 0, 1, 2
#define PROPCASE_CUSTOM_SKIN_TONE                180        // Canon Menu slide bar values: 255, 254, 0, 1, 2
#define PROPCASE_MY_COLORS                       188        // 0 = Off, 1 = Vivid, 2 = Neutral, 3 = B/W, 4 = Sepia, 5 = Positive Film, 6 = Lighter Skin Tone, 7 = Darker Skin Tone, 8 = Vivid Red, 9 = Vivid Green, 10 = Vivid Blue, 11 = Custom Color
#define PROPCASE_ND_FILTER_STATE                 196        // 0 = out, 1 = in
#define PROPCASE_OPTICAL_ZOOM_POSITION           199
#define PROPCASE_EXPOSURE_LOCK                   210     // Old PROPCASE_SHOOTING value - gets set when set_aelock called or AEL button pressed
#define PROPCASE_SHOOTING                        303     // This value appears to work better - gets set to 1 when camera has focused and set exposure, returns to 0 after shot
#define PROPCASE_EV_CORRECTION_2                 211
#define PROPCASE_IS_FLASH_READY                  212
#define PROPCASE_RESOLUTION                      222        // 0 = L, 1 = M1, 2 = M2, 4 = S, 7 = Low Light
#define PROPCASE_ORIENTATION_SENSOR              223
#define PROPCASE_TIMER_MODE                      227        // 0 = OFF, 1 = 2 sec, 2 = 10 sec, 3 = Custom
#define PROPCASE_TIMER_DELAY                     228        // timer delay in msec
#define PROPCASE_CUSTOM_SHARPNESS                229        // Canon Menu slide bar values: 255, 254, 0, 1, 2
#define PROPCASE_STITCH_DIRECTION                237        // 0=left>right, 1=right>left. Some cams have more
#define PROPCASE_STITCH_SEQUENCE                 242        // counts shots in stitch sequence, positive=left>right, negative=right>left
#define PROPCASE_SUBJECT_DIST1                   249
#define PROPCASE_SV_MARKET                       250
#define PROPCASE_TV2                             265        // (philmoz, May 2011) - this value causes overrides to be saved in JPEG and shown on Canon OSD
#define PROPCASE_TV                              266        // Need to set this value for overrides to work correctly
#define PROPCASE_USER_TV                         268
#define PROPCASE_WB_MODE                         272        // 0 = Auto, 1 = Daylight, 2 = Cloudy, 3 = Tungsten, 4 = Fluorescent, 5 = Fluorescent H, 7 = Custom
#define PROPCASE_WB_ADJ                          273
#define PROPCASE_SERVO_AF                        299        // 0 = Servo AF off, 1 = Servo AF on
#define PROPCASE_ASPECT_RATIO                    300        // 0 = 4:3, 1 = 16:9, 2 = 3:2, 3 = 1:1
#define PROPCASE_SV                              347        // (philmoz, May 2011) - this value causes overrides to be saved in JPEG and shown on Canon OSD
#define PROPCASE_GPS                             358        // (CHDKLover, August 2011) - contains a 272 bytes long structure
#define PROPCASE_TIMER_SHOTS                     377        // Number of shots for TIMER_MODE=Custom

// !not sure
//#define PROPCASE_DIGITAL_ZOOM_MODE               91         // Digital Zoom Mode/State 0 = off/standard, 2 = 1.7x, 3 = 2.1x

#endif
