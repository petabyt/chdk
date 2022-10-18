// Camera - SX50HS - platform_camera.h

// This file contains the various settings values specific to the SX40HS camera.
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
// Values below go in 'platform_camera.h':

    #define CAM_PROPSET                         5
    #define CAM_DRYOS                           1
    #define CAM_DRYOS_2_3_R39                   1
    #define CAM_DRYOS_2_3_R47                   1

    #undef  CAM_UNCACHED_BIT
    #define CAM_UNCACHED_BIT  0x40000000 // Found @0xff020984

    #define CAM_SWIVEL_SCREEN                   1
    #define CAM_ADJUSTABLE_ALT_BUTTON           1
    #define CAM_ALT_BUTTON_NAMES                { "Shrtcut", "Flash", "Video" }
    #define CAM_ALT_BUTTON_OPTIONS              { KEY_PRINT, KEY_FLASH, KEY_VIDEO }
    #undef  CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO
    #define CAM_HAS_VIDEO_BUTTON                1
    #define CAM_VIDEO_QUALITY_ONLY              1
    #define CAM_CHDK_HAS_EXT_VIDEO_TIME         1

    #define CAM_HAS_SPORTS_MODE                 1

    #define CAM_BRACKETING                      1
    #undef  CAM_VIDEO_CONTROL
    #define CAM_HAS_JOGDIAL                     1
    #undef  CAM_USE_ZOOM_FOR_MF
    #define CAM_SHOW_OSD_IN_SHOOT_MENU          1

    #undef DEFAULT_RAW_EXT
    #define DEFAULT_RAW_EXT                     2   // use .CR2

/*
  from exif date in Adobe DNG Converted image applied to Canon CR2 file
    Unique Camera Model             : Canon PowerShot SX50 HS
    Color Matrix 1                  : 1.3587 -0.6819 0.06 -0.1159 0.855 0.3112 0.0241 0.0672 0.5343
    Color Matrix 2                  : 1.2432 -0.4753 -0.1247 -0.211 1.0691 0.1629 -0.0412 0.1623 0.4926
    Calibration Illuminant 1        : Standard Light A (17)
    Calibration Illuminant 2        : D65 (21)
    Forward Matrix 1                : 0.5599 0.352 0.0525 0.0388 1.1348 -0.1736 -0.0815 -0.4851 1.3917
    Forward Matrix 2                : 0.5188 0.4576 -0.0121 0.1105 1.1149 -0.2254 0.0039 -0.2338 1.055
*/
    #define cam_CFAPattern                      0x02010100  // Red  Green  Green  Blue
    #define cam_CalibrationIlluminant1          17          // Standard Light A
    #define cam_CalibrationIlluminant2          21          // D65
    #define CAM_COLORMATRIX1    \
      13587, 10000, -6819, 10000,   600, 10000, \
      -1159, 10000,  8550, 10000,  3112, 10000, \
        241, 10000,   672, 10000,  5343, 10000
    #define CAM_COLORMATRIX2    \
      12432, 10000, -4753, 10000, -1247, 10000, \
      -2110, 10000, 10691, 10000,  1629, 10000, \
       -412, 10000,  1623, 10000,  4926, 10000
    #define CAM_FORWARDMATRIX1    \
       5599, 10000,  3520, 10000,   525, 10000, \
        388, 10000, 11348, 10000, -1736, 10000, \
       -815, 10000, -4851, 10000, 13917, 10000
    #define CAM_FORWARDMATRIX2    \
      5188, 10000,  4576, 10000,  -121, 10000, \
      1105, 10000, 11149, 10000, -2254, 10000, \
        39, 10000, -2338, 10000, 10550, 10000
    #define CAM_DNG_EXPOSURE_BIAS               0,1        // Specify DNG exposure bias value to 0 (to override default of -0.5 in the dng.c code)
    #define CAM_DNG_LENS_INFO                   { 43,10, 2150,10, 34,10, 65,10 }

    // Sensor size, DNG image size & cropping
    #define CAM_RAW_ROWPIX    4176 // Found @0xff1ae73c
    #define CAM_RAW_ROWS      3062 // Found @0xff1ae748

    #define CAM_JPEG_WIDTH                      4072
    #define CAM_JPEG_HEIGHT                     3044
    #define CAM_ACTIVE_AREA_X1                  96
    #define CAM_ACTIVE_AREA_Y1                  16
    #define CAM_ACTIVE_AREA_X2                  4168
    #define CAM_ACTIVE_AREA_Y2                  3060

    // camera name
    #define PARAM_CAMERA_NAME                   4       // parameter number for GetParameterData - Camera Model name
    #define PARAM_OWNER_NAME                    7       // parameter number for GetParameterData - Owner name
    #define PARAM_DISPLAY_MODE1                 59      // param number for LCD display mode when camera in playback
    #define PARAM_DISPLAY_MODE2                 62      // param number for LCD display mode when camera in record view hold mode
    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL           12

    #define CAM_QUALITY_OVERRIDE                1

    // copied from the SX200 which has the same video buffer size
    #undef CAM_USES_ASPECT_CORRECTION
    #define CAM_USES_ASPECT_CORRECTION          1       //camera uses the modified graphics primitives to map screens an viewports to buffers more sized
    #undef CAM_BITMAP_WIDTH
    #undef CAM_BITMAP_HEIGHT
    #define CAM_BITMAP_WIDTH                    960 // Actual width of bitmap screen in bytes
    #define CAM_BITMAP_HEIGHT                   270 // Actual height of bitmap screen in rows


    #undef  EDGE_HMARGIN
    #define EDGE_HMARGIN 2

    #define CAM_DATE_FOLDER_NAMING              0x400

    #undef  CAM_KEY_PRESS_DELAY
    #define CAM_KEY_PRESS_DELAY                 60      // delay after a press

    #define CAM_DRIVE_MODE_FROM_TIMER_MODE      1       // use PROPCASE_TIMER_MODE to check for multiple shot custom timer.
                                                        // Used to enabled bracketing in custom timer, required on many recent cameras
                                                        // see http://chdk.setepontos.com/index.php/topic,3994.405.html

    #define CAM_AV_OVERRIDE_IRIS_FIX            1       // for cameras that require _MoveIrisWithAv function to override Av in bracketing.

    #define CAM_DISABLE_RAW_IN_LOW_LIGHT_MODE   1       // For cameras with 'low light' mode that does not work with raw define this
    #define CAM_ISO_LIMIT_IN_HQ_BURST           1420    // Defines max market ISO override value for HQ Burst mode (higher values crash camera)
    #define CAM_HAS_MOVIE_DIGEST_MODE           1       // Changes the values in the 'movie_status' variable if the camera has this mode

    #define CAM_LOAD_CUSTOM_COLORS              1       // Enable loading CHDK colors into the camera palette memory/hardware

    #undef  CAM_USB_EVENTID
    #define CAM_USB_EVENTID                     0x202   // Levent ID for USB control. Changed in DryOS R49 so needs to be overridable.

//  #define REMOTE_SYNC_STATUS_LED  0xC0xxyyyy  // specifies an LED that turns on while camera waits for USB remote to sync

    #define CAM_HAS_CMOS                        1

    #undef  CAMERA_MIN_DIST
    #define CAMERA_MIN_DIST                     95      // Override min subject distance
    #undef  CAMERA_MAX_DIST
    #define CAMERA_MAX_DIST                     9523810 // Override max subject distance

    #define CAM_ZOOM_ASSIST_BUTTON_CONTROL      1       // Activate the menu option to allow disabling the zoom assist button
    #define MKDIR_RETURN_ONE_ON_SUCCESS         1       // mkdir() return 1 on success, 0 on fail.


    #undef  CAM_AF_LED                                  // AF Lamp index for camera_set_led()
    #define CAM_AF_LED                          1       //

    #define CAM_HAS_FILEWRITETASK_HOOK          1
    #define CAM_FILEWRITETASK_SEEKS             1

    #define CAM_HOTSHOE_OVERRIDE                1

    #define CAM_SD_OVER_IN_AFL                  1
    #define CAM_SD_OVER_IN_MF                   1

    #define CAM_IS_VID_REC_WORKS                1   // is_video_recording() function works

    #define CAM_HAS_CANON_RAW                   1   // has native Canon raw

//--------------------------------------------------
