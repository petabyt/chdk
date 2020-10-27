// Camera - g5x - platform_camera.h

// This file contains the various settings values specific to the G5X camera.
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

    #define CAM_PROPSET                         13

    #define CAM_HAS_NATIVE_ND_FILTER            1   // Camera has built-in ND filter with Canon menu support for enable/disable
    #define CAM_HAS_ND_FILTER                   1   // Camera has built-in ND filter (in addition to iris)

    #define CAM_ADJUSTABLE_ALT_BUTTON           1
    #define CAM_ALT_BUTTON_NAMES                { "WiFi", "Video", "Playback" }
    #define CAM_ALT_BUTTON_OPTIONS              { KEY_WIFI, KEY_VIDEO, KEY_PLAYBACK }

    #define CAM_DRYOS                           1
    #define CAM_DRYOS_2_3_R39                   1
    #define CAM_DRYOS_2_3_R47                   1

    #define CAM_HAS_CMOS                        1

// not implemented
    #undef  CAM_CHDK_HAS_EXT_VIDEO_MENU
    #undef  CAM_VIDEO_CONTROL

// minimal recording or not only
    #define CAM_SIMPLE_MOVIE_STATUS             1

    #define CAM_IS_VID_REC_WORKS                1 // Define if the 'is_video_recording()' function works

    #define CAM_HAS_VIDEO_BUTTON                1

    #undef  CAM_UNCACHED_BIT
    #define CAM_UNCACHED_BIT                    0x40000000

    #define CAM_DNG_LENS_INFO                   { 88,10, 368,10, 18,10, 28,10 }
    #define cam_CFAPattern                      0x02010100

    #define CAM_RAW_ROWPIX                      5632
    #define CAM_RAW_ROWS                        3710

    #define CAM_JPEG_WIDTH                      5472
    #define CAM_JPEG_HEIGHT                     3648

    #define CAM_ACTIVE_AREA_X1                  96
    #define CAM_ACTIVE_AREA_Y1                  18
    #define CAM_ACTIVE_AREA_X2                  5632
    #define CAM_ACTIVE_AREA_Y2                  3710

    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL           14

    #undef CAM_BLACK_LEVEL
    #define CAM_BLACK_LEVEL                     2047

    #define PARAM_CAMERA_NAME                   3
    #define CAM_DATE_FOLDER_NAMING              0x80
    #define CAM_FILE_COUNTER_IS_VAR             1     // file counter is variable file_counter_var in stubs, not a param

    #undef  CAM_HAS_ERASE_BUTTON
    #define CAM_SHOW_OSD_IN_SHOOT_MENU          1

    #define DRAW_ON_ACTIVE_BITMAP_BUFFER_ONLY   1           // Draw pixels on active bitmap buffer only.
    #define CAM_SUPPORT_BITMAP_RES_CHANGE       1   // Bitmap resolution changes when switching to HDMI output
    #define CAM_DETECT_BITMAP_UPDATE            1   // camera can detect if CHDK needs to be redrawn
    #undef  CAM_BITMAP_WIDTH
    #undef  CAM_BITMAP_HEIGHT
    #undef  CAM_SCREEN_WIDTH
    #undef  CAM_SCREEN_HEIGHT
    #define CAM_BITMAP_WIDTH                    736 // Actual width of bitmap screen in <s>bytes</s> pixels (YUV buffer)
    #define CAM_BITMAP_HEIGHT                   480 // Actual height of bitmap screen in rows
    #define CAM_SCREEN_WIDTH                    720 // Width of bitmap screen in CHDK co-ordinates (360 or 480)
    #define CAM_SCREEN_HEIGHT                   480 // Height of bitmap screen in CHDK co-ordinates (always 240 on all cameras so far)

    #define MKDIR_RETURN_ONE_ON_SUCCESS         1    // mkdir() return 1 on success, 0 on fail.

    #undef  CAM_CIRCLE_OF_CONFUSION
    #define CAM_CIRCLE_OF_CONFUSION             11  // CoC value for camera/sensor (see http://www.dofmaster.com/digital_coc.html)

    #define cam_CalibrationIlluminant1          17
    #define cam_CalibrationIlluminant2          21      // D65

    // from CR2 converted to DNG with adobe DNG converter
    #define CAM_COLORMATRIX1 \
    11125, 10000, -5937, 10000,  355, 10000, \
    -2979, 10000, 10926, 10000, 2360, 10000, \
     -116, 10000,   835, 10000, 6064, 10000

    #define CAM_COLORMATRIX2 \
     9602, 10000, -3823, 10000, -937, 10000, \
    -2984, 10000, 11495, 10000, 1675, 10000, \
     -407, 10000,  1415, 10000, 5049, 10000,

    #define CAM_FORWARDMATRIX1 \
     4264, 10000, 4193, 10000, 1187, 10000, \
     1832, 10000, 7811, 10000,  357, 10000, \
      854, 10000,   16, 10000, 7381, 10000

    #define CAM_FORWARDMATRIX2 \
     4036, 10000, 4056, 10000, 1551, 10000, \
     1780, 10000, 7757, 10000,  463, 10000, \
      764, 10000,    1, 10000, 7487, 10000

    // "real" to "market" conversion definitions
    #define SV96_MARKET_OFFSET                  0   // market and real appear to be identical on this cam
    #define ISO_MARKET_TO_REAL_MULT             1
    #define ISO_MARKET_TO_REAL_SHIFT            0
    #define ISO_MARKET_TO_REAL_ROUND            0
    #define ISO_REAL_TO_MARKET_MULT             1
    #define ISO_REAL_TO_MARKET_SHIFT            0
    #define ISO_REAL_TO_MARKET_ROUND            0

    #define CAM_HAS_CANON_RAW                   1   // has native Canon raw

    // AF led, for MD test code
    #undef CAM_AF_LED
    #define CAM_AF_LED                          1

    #define CAM_ZEBRA_NOBUF                     1

    #undef  EDGE_HMARGIN
    #define EDGE_HMARGIN                        10

    #define CAM_EXT_TV_RANGE                    1

    #define CAM_HAS_FILEWRITETASK_HOOK          1

    #define CAM_PTP_USE_NATIVE_BUFFER           1   // use firmware buffers to avoid problems with uncached memory

    #define CAM_HAS_HIGH_SPEED_CONT             4   // Camera has high speed continuous shooting mode. DRIVE_MODE propcase = 4 in this mode

    // TODO: Below needs tp be checked

    #define CAM_DISABLE_RAW_IN_LOW_LIGHT_MODE   1 // there's no low light mode, so just in case
    #define CAM_DISABLE_RAW_IN_HANDHELD_NIGHT_SCN   1 // raw would make absolutely no sense in this mode
    #define CAM_DISABLE_RAW_IN_HQ_BURST         1 // raw wouldn't make any sense in this mode either
    #define CAM_DISABLE_RAW_IN_HYBRID_AUTO      1 // For cameras that lock up while saving raw in "Hybrid Auto" mode
    #define CAM_DISABLE_RAW_IN_AUTO             1 // disabled due to wrong raw buffer selection at quick shutter press
    #define CAM_DISABLE_RAW_IN_SPORTS           1 // sports mode seems to use a no-yet-found code path and corrupts JPEG/DNG

    #define CAM_AV_OVERRIDE_IRIS_FIX            1

    #define CAM_DRIVE_MODE_FROM_TIMER_MODE      1

    #undef  CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO
    #define CAM_VIDEO_QUALITY_ONLY              1
    #undef  CAM_VIDEO_CONTROL
    #undef  CAM_USE_ZOOM_FOR_MF

    //#define CAM_QUALITY_OVERRIDE                1

    #undef  CAMERA_MIN_DIST
    #define CAMERA_MIN_DIST                     100         // Override min subject distance
    #undef  CAMERA_MAX_DIST
    #define CAMERA_MAX_DIST                     1550000     // Override max subject distance; manually checked up to 1550388, with MF max 1369863 (double step)

    //#define CAM_CHDK_HAS_EXT_VIDEO_TIME         1

    #undef  CAM_USB_EVENTID
    #define CAM_USB_EVENTID                     0x302       // Levent ID for USB control. Changed in DryOS R49, R50 so needs to be overridable.

    #define CAM_HAS_MOVIE_DIGEST_MODE           1 

    #define CAM_NEED_SET_ZOOM_DELAY             300

    #undef  REMOTE_SYNC_STATUS_LED
    // #define REMOTE_SYNC_STATUS_LED              0xC022C30C  // TODO specifies an LED that turns on while camera waits for USB remote to sync
 
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_MF  1

//--------------------------------------------------
