// Camera - EOS M10 - platform_camera.h

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

    #define CAM_DISABLE_RAW_IN_LOW_LIGHT_MODE   1
    #define CAM_DISABLE_RAW_IN_HANDHELD_NIGHT_SCN   1
    #define CAM_DISABLE_RAW_IN_HQ_BURST         1
    #define CAM_DISABLE_RAW_IN_HYBRID_AUTO      1
    #define CAM_DISABLE_RAW_IN_SPORTS           1
    #define CAM_AV_OVERRIDE_IRIS_FIX            1
    #undef CAM_HAS_ND_FILTER                             // Camera does not have built-in ND filter, obviously
    #undef  CAM_KEY_PRESS_DELAY
    #define CAM_KEY_PRESS_DELAY                 60          // delay after a press
    #define CAM_ADJUSTABLE_ALT_BUTTON           1
    #define CAM_ALT_BUTTON_NAMES                { "Playback", "Video", "Wifi" }
    #define CAM_ALT_BUTTON_OPTIONS              { KEY_PLAYBACK, KEY_VIDEO, KEY_WIFI }
    #undef  CAM_HAS_ERASE_BUTTON
    #undef  CAM_HAS_DISP_BUTTON
    #undef  CAM_DEFAULT_ALT_BUTTON
    #define CAM_DEFAULT_ALT_BUTTON              KEY_PLAYBACK
    #define SHORTCUT_TOGGLE_RAW                 KEY_VIDEO
    #define CAM_HAS_VIDEO_BUTTON                1
    #define CAM_DRIVE_MODE_FROM_TIMER_MODE      1

    // half press shortcuts (zebra assigned to a non-conflicting button, CHDK histogram makes no sense)
    #define SHORTCUT_TOGGLE_HISTO               KEY_DUMMY
    #define SHORTCUT_TOGGLE_ZEBRA               KEY_UP

    #define CAM_DRYOS                           1
    #define CAM_DRYOS_2_3_R39                   1
    #define CAM_DRYOS_2_3_R47                   1
    #define CAM_PROPSET                         10

    #define CAM_RAW_ROWPIX                      5280
    #define CAM_RAW_ROWS                        3528

    #define CAM_HAS_CMOS                        1

    #undef  CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO

    //#undef  CAM_CHDK_HAS_EXT_VIDEO_MENU
    #define CAM_MOVIEREC_NEWSTYLE               1
    #undef  CAM_VIDEO_CONTROL
    #define CAM_SIMPLE_MOVIE_STATUS             1

    #define CAM_HAS_JOGDIAL                     1
    #undef  CAM_USE_ZOOM_FOR_MF

    #undef  CAM_UNCACHED_BIT
    #define CAM_UNCACHED_BIT                    0x40000000

    #define CAM_DNG_LENS_INFO                   { 150,10,450,10,35,10,63,10 } // kit lens for now...

    #define cam_CFAPattern                      0x02010100

    // values from dcraw for M10 Canon RAW files
    #define CAM_COLORMATRIX1 \
         6400,  1000000,     -480,  1000000,     -888,  1000000, \
        -5294,  1000000,    13416,  1000000,     2047,  1000000, \
        -1296,  1000000,     2203,  1000000,     6137,  1000000

    #define cam_CalibrationIlluminant1          17      // standard light A

    //#define CAM_CALC_BLACK_LEVEL                1
    #undef CAM_BLACK_LEVEL
    #define CAM_BLACK_LEVEL                     2047    // not tested under all conditions

    #define CAM_JPEG_WIDTH                      5184
    #define CAM_JPEG_HEIGHT                     3456

//Exiftool:
//Sensor Width                    : 5280
//Sensor Height                   : 3528
//Sensor Left Border              : 84
//Sensor Top Border               : 62
//Sensor Right Border             : 5267
//Sensor Bottom Border            : 3517

    // below is more relaxed than the values reported by Exiftool, but still cuts off a few usable pixels
    #define CAM_ACTIVE_AREA_X1                  76
    #define CAM_ACTIVE_AREA_Y1                  52
    #define CAM_ACTIVE_AREA_X2                  5272
    #define CAM_ACTIVE_AREA_Y2                  3522

    #define PARAM_CAMERA_NAME                   3
    #define CAM_DATE_FOLDER_NAMING              0x80
    #define CAM_FILE_COUNTER_IS_VAR             1     // file counter is variable file_counter_var in stubs, not a param
    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL           14

    // "real" to "market" conversion definitions, market seems to be close enough to real
    #define SV96_MARKET_OFFSET                  0
    #define ISO_MARKET_TO_REAL_MULT             1
    #define ISO_MARKET_TO_REAL_SHIFT            0
    #define ISO_MARKET_TO_REAL_ROUND            0
    #define ISO_REAL_TO_MARKET_MULT             1
    #define ISO_REAL_TO_MARKET_SHIFT            0
    #define ISO_REAL_TO_MARKET_ROUND            0

    #define CAM_EXT_TV_RANGE                    1 // note: exp_drv_task not implemented

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

    #undef  CAM_BITMAP_PALETTE
    #define CAM_BITMAP_PALETTE                  100

    #define CAM_ZEBRA_NOBUF                     1

    //#define CAM_QUALITY_OVERRIDE                1

    #undef  CAMERA_MIN_DIST
    #define CAMERA_MIN_DIST                     1           // ?
    #undef  CAMERA_MAX_DIST
    #define CAMERA_MAX_DIST                     1550000     // ?

    //#define CAM_CHDK_HAS_EXT_VIDEO_TIME         1

    #undef  CAM_USB_EVENTID
    #define CAM_USB_EVENTID                     0x202       // Levent ID for USB control. Changed in DryOS R49, R50 so needs to be overridable.

    #define CAM_HAS_MOVIE_DIGEST_MODE           1

    #define MKDIR_RETURN_ONE_ON_SUCCESS         1    // mkdir() return 1 on success, 0 on fail.

    #undef  REMOTE_SYNC_STATUS_LED

    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_MF  1

    #define CAM_HAS_CANON_RAW                   1   // has native Canon raw

