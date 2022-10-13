// Camera - ixus125/elph110hs - platform_camera.h

// This file contains the various settings values specific to the ixus125/elph110hs camera.
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

    #define CAM_DRYOS                           1
    #define CAM_PROPSET                         5

    #define CAM_DRYOS_2_3_R39                   1       // Defined for cameras with DryOS version R39 or higher
    #define CAM_DRYOS_2_3_R47                   1       // Defined for cameras with DryOS version R47 or higher

    #undef  CAM_UNCACHED_BIT
    #define CAM_UNCACHED_BIT                    0x40000000 // Found @0xff024684 ixus125 100d

    #define CAM_RAW_ROWPIX                      4784 // Found @0xff15d2f8 ixus125 100d
    #define CAM_RAW_ROWS                        3516 // Found @0xff15d304 ixus125 100d

    #define CAM_JPEG_WIDTH                      4608
    #define CAM_JPEG_HEIGHT                     3456
    #define CAM_ACTIVE_AREA_X1                  96
    #define CAM_ACTIVE_AREA_Y1                  18 // could use 17, but will change effective bayer pattern
    #define CAM_ACTIVE_AREA_X2                  4776
    #define CAM_ACTIVE_AREA_Y2                  3516 // image data goes all the way to the bottom

    #define CAM_DNG_LENS_INFO                   { 43,10, 215,10, 27,10, 59,10 } // See comments in camera.h ixus125

    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL           12

    #define cam_CFAPattern  0x02010100

    #define CAM_COLORMATRIX1    \
    544808, 1000000, -174047, 1000000, -80399, 1000000, \
    -75055, 1000000,  440444, 1000000,  11367, 1000000, \
     -5801, 1000000,   71589, 1000000, 118914, 1000000

    #undef  CAM_USE_ZOOM_FOR_MF
    #define CAM_BRACKETING                      1
    #undef  CAM_VIDEO_CONTROL
    #define CAM_VIDEO_QUALITY_ONLY              1

    #define CAM_HAS_CMOS                        1
    #define CAM_HAS_ND_FILTER                   1
    #undef  CAM_HAS_MANUAL_FOCUS
    #undef  CAM_HAS_IRIS_DIAPHRAGM

    #undef  CAM_HAS_ERASE_BUTTON
    #define CAM_DISABLE_RAW_IN_LOW_LIGHT_MODE   1

    #define CAM_HAS_MOVIE_DIGEST_MODE           1

    #define CAM_HAS_VIDEO_BUTTON                1

    #define CAM_IS_VID_REC_WORKS                1   // is_video_recording() function works

    #define cam_CalibrationIlluminant1          1

    #define PARAM_CAMERA_NAME                   4       // parameter number for GetParameterData

    #undef  CAM_USES_ASPECT_CORRECTION
    #define CAM_USES_ASPECT_CORRECTION          1
    #undef  CAM_BITMAP_WIDTH
    #undef  CAM_BITMAP_HEIGHT
    #define CAM_BITMAP_WIDTH                    960 // Actual width of bitmap screen in bytes
    #define CAM_BITMAP_HEIGHT                   270 // Actual height of bitmap screen in rows

    #define CAM_LOAD_CUSTOM_COLORS              1       // Enable loading CHDK colors into the camera palette memory/hardware

    #undef  EDGE_HMARGIN
    #define EDGE_HMARGIN                        10

    #define CAM_ZEBRA_NOBUF                     1

//    #define CAM_USE_ZOOM_FOR_MF                  1    // Zoom lever can be used for manual focus adjustments
    #define CAM_NEED_SET_ZOOM_DELAY             100  // Define to add a delay after setting the zoom position
    #define CAM_USE_OPTICAL_MAX_ZOOM_STATUS     1    // Use ZOOM_OPTICAL_MAX to reset zoom_status when switching from digital to optical zoo

    #define CAM_QUALITY_OVERRIDE                1
    #define CAM_DATE_FOLDER_NAMING              0x400

    #define CAM_DRIVE_MODE_FROM_TIMER_MODE      1

    #define DRAW_ON_ACTIVE_BITMAP_BUFFER_ONLY   1

    #undef  CAM_USB_EVENTID
    #define CAM_USB_EVENTID                     0x202   // Levent ID for USB control. Changed in DryOS R49, R50 so needs to be overridable.
    #define MKDIR_RETURN_ONE_ON_SUCCESS         1       // mkdir() return 1 on success, 0 on fail.

    #define CAM_HAS_FILEWRITETASK_HOOK      1
    #define CAM_FILEWRITETASK_SEEKS         1

    #define CAM_CHDK_HAS_EXT_VIDEO_TIME     1

//    #define REMOTE_SYNC_STATUS_LED     0xC0220130   // specifies an LED that turns on while camera waits for USB remote to sync

    #define CAM_SD_OVER_IN_AF                   1
    #define CAM_SD_OVER_IN_MF                   1

    #define CAM_ADJUSTABLE_ALT_BUTTON           1
    #define CAM_ALT_BUTTON_NAMES                { "Playback", "Video" }
    #define CAM_ALT_BUTTON_OPTIONS              { KEY_PLAYBACK, KEY_VIDEO }
    #define CAM_DISP_BUTTON_NAME                "Video"
    #define SHORTCUT_TOGGLE_RAW                 KEY_VIDEO

    #define CAM_IS_VID_REC_WORKS                1   // is_video_recording() function works


//--------------------------------------------------
