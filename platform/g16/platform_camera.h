// Camera - g16 - platform_camera.h

// This file contains the various settings values specific to the G16 camera.
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

    #define CAM_DISABLE_RAW_IN_HYBRID_AUTO      1 // For cameras that lock up while saving raw in "Hybrid Auto" mode
    #define CAM_DISABLE_RAW_IN_HANDHELD_NIGHT_SCN   1 // raw would make absolutely no sense in this mode
    #define CAM_DISABLE_RAW_IN_HDR              1 // raw hook not currently called, probably doesn't make sense

    #define CAM_AV_OVERRIDE_IRIS_FIX            1
    #define CAM_HAS_ND_FILTER                   1           // Camera has built-in ND filter (in addition to iris)
    #undef  CAM_KEY_PRESS_DELAY
    #define CAM_KEY_PRESS_DELAY                 60          // delay after a press
    
    #define CAM_ADJUSTABLE_ALT_BUTTON           1
    #define CAM_ALT_BUTTON_NAMES                {  "Video",   "Playback",   "Shortcut" }
    #define CAM_ALT_BUTTON_OPTIONS              {  KEY_VIDEO, KEY_PLAYBACK, KEY_PRINT }
    
    #define CAM_DRIVE_MODE_FROM_TIMER_MODE      1

    // zebra and histo don't currently work, and default zebra shortcut conflicts with canon AF lock
    #define SHORTCUT_TOGGLE_HISTO               KEY_DUMMY
    #define SHORTCUT_TOGGLE_ZEBRA               KEY_DUMMY

    #define CAM_DRYOS                           1
    #define CAM_DRYOS_2_3_R39                   1
    #define CAM_DRYOS_2_3_R47                   1
    #define CAM_PROPSET                         6

    #define CAM_HAS_CMOS                        1

    #define CAM_HAS_NATIVE_ND_FILTER            1   // Camera has built-in ND filter with Canon menu support for enable/disable

    #undef  CAM_CHDK_HAS_EXT_VIDEO_MENU
    #undef  CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO
    #define CAM_HAS_VIDEO_BUTTON                1
    #undef  CAM_VIDEO_CONTROL

    #define CAM_HAS_JOGDIAL                     1
    #undef  CAM_USE_ZOOM_FOR_MF

    #undef  CAM_UNCACHED_BIT
    #define CAM_UNCACHED_BIT                    0x40000000

/*

  From Canon CR2 image converted to DNG by Adobe DNG Converter

   Calibration Illuminant 1        : Standard Light A  ( = 17)
   Calibration Illuminant 2        : D65               ( = 21)

   Color Matrix 1 : 0.9249 -0.4361  0.0549 -0.2474 0.9924 0.2983 -0.0142 0.0935 0.6104
   Color Matrix 2 : 0.8020 -0.2687 -0.0682 -0.3704 1.1879 0.2052 -0.0965 0.1921 0.5556

*/

    #define CAM_DNG_LENS_INFO                { 61,10,305,10,18,10,28,10 }
    #define cam_CFAPattern                   0x02010100
    #define CAM_DNG_EXPOSURE_BIAS           0,1          // Specify DNG exposure bias value to 0 (to override default of -0.5 in the dng.c codei

    #define cam_CalibrationIlluminant1        17
    #define CAM_COLORMATRIX1                  \
      9249, 10000, -4361, 10000 ,  549, 10000, \
     -2474, 10000,  9924, 10000,  2983, 10000, \
      -142, 10000,   935, 10000,  6104, 10000

    #define cam_CalibrationIlluminant2         21
    # define CAM_COLORMATRIX2                  \
      8020, 10000,  -2687, 10000,  -682, 10000, \
     -3704, 10000,  11879, 10000,  2052, 10000, \
      -965, 10000,   1921, 10000,  5556, 10000

/*
  From exif info in Canon CR2 image

    Cropped Image Width             : 4000
    Cropped Image Height            : 3000
    Sensor Width                    : 4192
    Sensor Height                   : 3062
    Sensor Left Border              : 132
    Sensor Top Border               : 40
    Sensor Right Border             : 4131
    Sensor Bottom Border            : 3039
    Black Mask Left Border          : 120
    Black Mask Top Border           : 2
    Black Mask Right Border         : 4143
    Black Mask Bottom Border        : 15
*/

    #define CAM_RAW_ROWPIX                      4192
    #define CAM_RAW_ROWS                        3062

    #define CAM_JPEG_WIDTH                      4000
    #define CAM_JPEG_HEIGHT                     3000

    #define CAM_ACTIVE_AREA_X1                  96
    #define CAM_ACTIVE_AREA_Y1                  18
    #define CAM_ACTIVE_AREA_X2                  4168
    #define CAM_ACTIVE_AREA_Y2                  3062

    #define PARAM_CAMERA_NAME                   3
    #define CAM_DATE_FOLDER_NAMING              0x80
    #define CAM_FILE_COUNTER_IS_VAR             1     // file counter is variable file_counter_var in stubs, not a param
    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL           12

    #define CAM_EXT_TV_RANGE                    1

    #undef  CAM_HAS_ERASE_BUTTON
    #define CAM_SHOW_OSD_IN_SHOOT_MENU          1

    #define DRAW_ON_ACTIVE_BITMAP_BUFFER_ONLY   1           // Draw pixels on active bitmap buffer only.
    //#undef  CAM_USES_ASPECT_CORRECTION
    //#define CAM_USES_ASPECT_CORRECTION          1
    #define DRAW_ON_YUV_OVERLAY                 1
    #undef  CAM_BITMAP_WIDTH
    #undef  CAM_BITMAP_HEIGHT
    #undef  CAM_SCREEN_WIDTH
    #undef  CAM_SCREEN_HEIGHT
    #define CAM_BITMAP_WIDTH                    640 // Actual width of bitmap screen in <s>bytes</s> pixels
    #define CAM_BITMAP_HEIGHT                   480 // Actual height of bitmap screen in rows
    #define CAM_SCREEN_WIDTH                    640 // Width of bitmap screen in CHDK co-ordinates (360 or 480)
    #define CAM_SCREEN_HEIGHT                   480 // Height of bitmap screen in CHDK co-ordinates (always 240 on all cameras so far)
    //#define CAM_SUPPORT_BITMAP_RES_CHANGE       1

    #undef  EDGE_HMARGIN
    #define EDGE_HMARGIN                        10

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
    
    #define CAM_HOTSHOE_OVERRIDE            1
    
    //#define CAM_CHDK_HAS_EXT_VIDEO_TIME         1
    #define CAM_SIMPLE_MOVIE_STATUS             1

    #undef  CAM_USB_EVENTID
    #define CAM_USB_EVENTID                     0x202       // Levent ID for USB control. Changed in DryOS R49, R50 so needs to be overridable.

    #define CAM_HAS_MOVIE_DIGEST_MODE           1

    #define CAM_USE_ALT_SET_ZOOM_POINT          1           // Define to use the alternate code in lens_set_zoom_point()
    #define CAM_NEED_SET_ZOOM_DELAY             300

    #define MKDIR_RETURN_ONE_ON_SUCCESS         1    // mkdir() return 1 on success, 0 on fail.

    #undef  REMOTE_SYNC_STATUS_LED
    // #define REMOTE_SYNC_STATUS_LED              0xC022C30C  // TODO specifies an LED that turns on while camera waits for USB remote to sync

// AF led, for MD test code
    #undef CAM_AF_LED
    #define CAM_AF_LED                          1

    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_MF  1

    #define CAM_HAS_CANON_RAW                   1   // has native Canon raw

