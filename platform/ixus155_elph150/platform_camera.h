// Camera - IXUS155_ELPH150 - platform_camera.h

// This file contains the various settings values specific to the IXUS155_ELPH150 camera.
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
    #define CAM_PROPSET                         6
    #define CAM_DRYOS_2_3_R39                   1       // Defined for cameras with DryOS version R39 or higher
    #define CAM_DRYOS_2_3_R47                   1       // Defined for cameras with DryOS version R47 or higher

    #undef  CAM_CIRCLE_OF_CONFUSION
    #define CAM_CIRCLE_OF_CONFUSION             5

    #define CAM_RAW_ROWPIX    5248 // Found @0xff9640d4
    #define CAM_RAW_ROWS      3920 // Found @0xff9640dc


    #define CAM_JPEG_WIDTH                      5152
    #define CAM_JPEG_HEIGHT                     3864

    #define CAM_ACTIVE_AREA_X1                  8
    #define CAM_ACTIVE_AREA_Y1                  16
    #define CAM_ACTIVE_AREA_X2                  5192
    #define CAM_ACTIVE_AREA_Y2                  3904

    #undef  CAM_UNCACHED_BIT
    #define CAM_UNCACHED_BIT  0x40000000 // Found @0xff825e30

    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL           12

    #define CAM_DNG_LENS_INFO                   { 43,10, 430,10, 30,10, 69,10 } // See comments in camera.h

    #define cam_CFAPattern                  0x02010100 // Red  Green  Green  Blue

    //TODO
    #define CAM_COLORMATRIX1                             \
    827547, 1000000, -290458, 1000000, -126086, 1000000, \
    -12829, 1000000,  530507, 1000000,   50537, 1000000, \
      5181, 1000000,   48183, 1000000,  245014, 1000000
    #define cam_CalibrationIlluminant1          1       // Daylight

    // no separate erase button
    #undef  CAM_HAS_ERASE_BUTTON
    #undef  CAM_HAS_DISP_BUTTON

    #define CAM_HAS_VIDEO_BUTTON                1
    #undef  CAM_VIDEO_CONTROL
    #undef  CAM_CHDK_HAS_EXT_VIDEO_MENU

    #define CAM_IS_VID_REC_WORKS                1   // is_video_recording() function works

    #define CAM_ZEBRA_NOBUF                     1

    #undef  CAM_HAS_IRIS_DIAPHRAGM
    #define CAM_HAS_ND_FILTER                   1


    #define DNG_VERT_RLE_BADPIXELS              1

    #define CAM_DATE_FOLDER_NAMING 0x080 // Found @0xffa946a4 (pass as 3rd param to GetImageFolder)
    #define PARAM_CAMERA_NAME 3 // Found @0xffc841ec

    #undef  CAM_HAS_MANUAL_FOCUS
    #undef  CAM_USE_ZOOM_FOR_MF
    #define CAM_HAS_IS                      1   // Camera has image stabilizer

    #define CAM_LOAD_CUSTOM_COLORS              1       // Enable loading CHDK colors into the camera palette memory/hardware
    //#undef CAM_LOAD_CUSTOM_COLORS

    //To do
    #undef  CAM_USES_ASPECT_CORRECTION
    #define CAM_USES_ASPECT_CORRECTION          1
    #undef  CAM_BITMAP_WIDTH
    #define CAM_BITMAP_WIDTH                    720     // Actual width of bitmap screen in bytes (may be larger than displayed area)
    #undef  CAM_BITMAP_HEIGHT
    #define CAM_BITMAP_HEIGHT                   360     // http://chdk.setepontos.com/index.php?topic=12144.msg119748#msg119748

    #define CAM_ADJUSTABLE_ALT_BUTTON           1   // ALT-button can be set from menu
    #define CAM_ALT_BUTTON_NAMES                { "Playback", "Help" }
    #define CAM_ALT_BUTTON_OPTIONS              { KEY_PLAYBACK, KEY_HELP }

    #define CAM_HAS_FILEWRITETASK_HOOK          1
    #define CAM_FILEWRITETASK_SEEKS             1

    #undef  CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO
    #define CAM_HAS_ZOOM_LEVER                  1      // Camera has dedicated zoom buttons

    #define CAM_FILE_COUNTER_IS_VAR             1       // file counter is variable file_counter_var in stubs, not a param

    #define CAM_QUALITY_OVERRIDE                1

    #undef  CAM_MARKET_ISO_BASE
    #define CAM_MARKET_ISO_BASE                 200 // Override base 'market' ISO value, from isobase.lua

    #undef  CAM_USB_EVENTID
    #define CAM_USB_EVENTID                     0x202   // Levent ID for USB control. Changed in DryOS R49, R50 so needs to be overridable.

    #define MKDIR_RETURN_ONE_ON_SUCCESS         1       // mkdir() return 1 on success, 0 on fail.

    #undef  CAM_AF_LED
    #define CAM_AF_LED                          1   // Index of AF led in camera_set_led function

    #define CAM_SD_OVER_IN_AF                   1
    #define CAM_SD_OVER_IN_AFL                  1
    #define CAM_SD_OVER_IN_MF                   1

    #define CAM_3ARG_DebugAssert                1   // DebugAssert takes 3 arguments

//--------------------------------------------------
