// Camera - EOS M3 - platform_camera.h

// This file contains the various settings values specific to the SX260HS camera.
// This file is referenced via the 'include/camera.h' file and should not be loaded directly.

// If adding a new settings value put a suitable default in 'include/camera.h',
// along with documentation on what the setting does and how to determine the correct value.
// If the setting should not have a default value then add it in 'include/camera.h'
// using the '#undef' directive along with appropriate documentation.

// Override any default values with your camera specific values in this file. Try and avoid
// having override values that are the same as the default value.

// When overriding a setting value there are two cases:
// 1. If removing the value, because it does not apply to your camera, use the '#undef' directive.
// 2. If changing the value it is best to use an '#undef' directive to remove the default value
//    followed by a '#define' to set the new value.

// When porting CHDK to a new camera, check the documentation in 'include/camera.h'
// for information on each setting. If the default values are correct for your camera then
// don't override them again in here.
    #define CAM_ILC                             1 // Camera uses interchangable lenses (EOS M series)

    #define CAM_DISABLE_RAW_IN_LOW_LIGHT_MODE   1 // there's no low light mode, so just in case
    #define CAM_AV_OVERRIDE_IRIS_FIX            1
    #undef CAM_HAS_ND_FILTER                             // Camera does not have built-in ND filter
    #undef  CAM_KEY_PRESS_DELAY
    #define CAM_KEY_PRESS_DELAY                 60          // delay after a press
    #define CAM_ADJUSTABLE_ALT_BUTTON           1
    #define CAM_ALT_BUTTON_NAMES                { "M-Fn", "Video", "Display" }
    #define CAM_ALT_BUTTON_OPTIONS              { KEY_PRINT, KEY_VIDEO, KEY_DISPLAY }
    #define CAM_DRIVE_MODE_FROM_TIMER_MODE      1

    #define CAM_DRYOS                           1
    #define CAM_DRYOS_2_3_R39                   1
    #define CAM_DRYOS_2_3_R47                   1
    #define CAM_PROPSET                         9

    #define CAM_RAW_ROWPIX                      6112 //6096
    #define CAM_RAW_ROWS                        4060 //4056

    #define CAM_HAS_CMOS                        1

    #undef  CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO
    #define CAM_HAS_VIDEO_BUTTON                1

    //#undef  CAM_CHDK_HAS_EXT_VIDEO_MENU
    #define CAM_MOVIEREC_NEWSTYLE               1
    #undef  CAM_VIDEO_CONTROL

    #undef  CAM_HAS_JOGDIAL                     // jogdial support not implemented
    #undef  CAM_USE_ZOOM_FOR_MF

    #undef  CAM_UNCACHED_BIT
    #define CAM_UNCACHED_BIT                    0x40000000

    #define CAM_DNG_LENS_INFO                   { 180,10,550,10,35,10,56,10 }
    #define cam_CFAPattern                      0x02010100

    #define CAM_COLORMATRIX1                            \
	6362, 10000, -823, 10000, -847, 10000, \
	-4426, 10000, 12109, 10000, 2616, 10000, \
	-743, 10000, 1857, 10000, 5635, 10000
 
    #define cam_CalibrationIlluminant1          17
    #undef CAM_BLACK_LEVEL
    #define CAM_BLACK_LEVEL                     2047    // not tested under all conditions	

    #define CAM_JPEG_WIDTH                      6000
    #define CAM_JPEG_HEIGHT                     4000

    #define CAM_ACTIVE_AREA_X1                  84
    #define CAM_ACTIVE_AREA_Y1                  46
    #define CAM_ACTIVE_AREA_X2                  6084
    #define CAM_ACTIVE_AREA_Y2                  4046

    #define PARAM_CAMERA_NAME                   3
    #define CAM_DATE_FOLDER_NAMING              0x80
    #define CAM_FILE_COUNTER_IS_VAR             1     // file counter is variable file_counter_var in stubs, not a param
    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL           14

    #define CAM_EXT_TV_RANGE                    1

    #undef  CAM_HAS_ERASE_BUTTON
    #define CAM_SHOW_OSD_IN_SHOOT_MENU          1

    #define DRAW_ON_ACTIVE_BITMAP_BUFFER_ONLY   1           // Draw pixels on active bitmap buffer only.
    //#undef  CAM_USES_ASPECT_CORRECTION
    //#define CAM_USES_ASPECT_CORRECTION          1
    #undef  CAM_BITMAP_WIDTH
    #undef  CAM_BITMAP_HEIGHT
    #undef  CAM_SCREEN_WIDTH
    #undef  CAM_SCREEN_HEIGHT
    #define CAM_BITMAP_WIDTH                    736 // Actual width of bitmap screen in <s>bytes</s> pixels
    #define CAM_BITMAP_HEIGHT                   480 // Actual height of bitmap screen in rows
    #define CAM_SCREEN_WIDTH                    720 // Width of bitmap screen in CHDK co-ordinates (360 or 480)
    #define CAM_SCREEN_HEIGHT                   480 // Height of bitmap screen in CHDK co-ordinates (always 240 on all cameras so far)
    #define CAM_SUPPORT_BITMAP_RES_CHANGE       1
    

    #undef  EDGE_HMARGIN
    #define EDGE_HMARGIN                        16

    #define CAM_HAS_FILEWRITETASK_HOOK          1
    //#define CAM_FILEWRITETASK_SEEKS             1

    #undef  CAM_BITMAP_PALETTE
    #define CAM_BITMAP_PALETTE                  100

    #define CAM_ZEBRA_NOBUF                     1

    //#define CAM_QUALITY_OVERRIDE                1

    #undef  CAMERA_MIN_DIST
    #define CAMERA_MIN_DIST                     100         // Override min subject distance
    #undef  CAMERA_MAX_DIST
    #define CAMERA_MAX_DIST                     1550000     // Override max subject distance; manually checked up to 1550388, with MF max 1369863 (double step)

    //#define CAM_HAS_GPS                         1

    //#define CAM_CHDK_HAS_EXT_VIDEO_TIME         1

    #undef  CAM_USB_EVENTID
    #define CAM_USB_EVENTID                     0x202       // Levent ID for USB control. Changed in DryOS R49, R50 so needs to be overridable.

    #define CAM_HAS_MOVIE_DIGEST_MODE           1 

    #define MKDIR_RETURN_ONE_ON_SUCCESS         1    // mkdir() return 1 on success, 0 on fail.

    #undef  REMOTE_SYNC_STATUS_LED
    // #define REMOTE_SYNC_STATUS_LED              0xC022C30C  // TODO specifies an LED that turns on while camera waits for USB remote to sync
 
    // subject distance override currently not available
    #undef CAM_SD_OVER_IN_AFL
    #undef CAM_SD_OVER_IN_AF
    #undef CAM_SD_OVER_IN_MF

    #define CAM_HOTSHOE_OVERRIDE                1

// ------- MY -----------
//    #define CAM_TOUCHSCREEN_UI	1
//    #undef CAM_CHDK_PTP
//	#define DEBUG_PRINT_TO_LCD
// #define OPT_RUN_WITH_BATT_COVER_OPEN 1
#undef CAM_AF_LED
#define CAM_AF_LED 							1
//#define OPT_DEBUGGING						1
//--------------------------------------------------
// "real" to "market" conversion definitions
#define SV96_MARKET_OFFSET                  0
#define ISO_MARKET_TO_REAL_MULT             1
#define ISO_MARKET_TO_REAL_SHIFT            0
#define ISO_MARKET_TO_REAL_ROUND            0
#define ISO_REAL_TO_MARKET_MULT             1
#define ISO_REAL_TO_MARKET_SHIFT            0
#define ISO_REAL_TO_MARKET_ROUND            0

    #define CAM_SIMPLE_MOVIE_STATUS             1

    #define CAM_HAS_CANON_RAW                   1   // has native Canon raw

    #define CAM_CLEAN_OVERLAY                   1

    #define CAM_HAS_WIFI                        1   // Camera has wifi support

