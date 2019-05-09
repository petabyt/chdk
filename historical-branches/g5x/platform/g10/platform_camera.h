// Camera - G10 - platform_camera.h

// This file contains the various settings values specific to the G10 camera.
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

    #define CAM_DRYOS                       1

    #undef  CAM_CIRCLE_OF_CONFUSION
    #define CAM_CIRCLE_OF_CONFUSION         7   // CoC value for camera/sensor (see http://www.dofmaster.com/digital_coc.html)

    #define CAM_PROPSET                     2

    #undef  CAM_USE_ZOOM_FOR_MF
    #define CAM_HAS_ND_FILTER               1
    #define CAM_HAS_NATIVE_ND_FILTER        1   // Camera has built-in ND filter with Canon menu support for enable/disable

    #define CAM_HAS_HI_ISO_AUTO_MODE        1

    #undef  CAM_EMUL_KEYPRESS_DURATION
    #define CAM_EMUL_KEYPRESS_DURATION      10

    #define CAM_ADJUSTABLE_ALT_BUTTON       1
    #define CAM_ALT_BUTTON_NAMES            { "Print", "Disp",  "AE Lock", "Jump" }
    #define CAM_ALT_BUTTON_OPTIONS          { KEY_PRINT, KEY_DISPLAY, KEY_AE_LOCK, KEY_METERING}

    #define CAM_RAW_ROWPIX                  4480    // G10 auto found @0xffacde38
    #define CAM_RAW_ROWS                    3348    // G10 auto found @0xffacde3c

    #define CAM_JPEG_WIDTH                  4416    // taken from G10 jpg header info
    #define CAM_JPEG_HEIGHT                 3312    // "

    #define CAM_ACTIVE_AREA_X1              12      // calibrated with G10 RAW picture converted with rawconvert.exe (rawconvert -12to8 -pgm -w=4480 -h=3348 g10.crw g10.pgm)
    #define CAM_ACTIVE_AREA_Y1              12      // "
    #define CAM_ACTIVE_AREA_X2              4440    // "
    #define CAM_ACTIVE_AREA_Y2              3334    // "

    #define CAM_QUALITY_OVERRIDE            1
    #define CAM_AF_SCAN_DURING_VIDEO_RECORD 1
    #define CAM_RESET_AEL_AFTER_VIDEO_AF    1   // Cam needs AE Lock state reset after AF in video recording
    #define CAM_HAS_JOGDIAL                 1

    #define CAM_BRACKETING                  1
    #define CAM_MULTIPART                   1
    #undef  CAM_UNCACHED_BIT
    #define CAM_UNCACHED_BIT                0x40000000  // G10 auto found @0xff828844

    #define CAM_SHOW_OSD_IN_SHOOT_MENU      1

    #define PARAM_CAMERA_NAME               4       // parameter number for GetParameterData
    #define PARAM_DISPLAY_MODE1             57      // param number for LCD display mode when camera in playback
    #define PARAM_DISPLAY_MODE2             58      // param number for LCD display mode when camera in record view hold mode

    #define CAM_LOAD_CUSTOM_COLORS          1      // Enable loading CHDK colors into the camera palette memory/hardware

    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL       12

    #undef  CAM_USES_ASPECT_CORRECTION
    #define CAM_USES_ASPECT_CORRECTION      1       //camera uses the modified graphics primitives to map screens an viewports to buffers more sized
    #undef  CAM_BITMAP_WIDTH
    #define CAM_BITMAP_WIDTH                720 // Actual width of bitmap screen in bytes

    #undef  EDGE_HMARGIN
    #define EDGE_HMARGIN 28


/*
  from exif date in Adobe DNG Converted image applied to Canon CR2 file
    Unique Camera Model             : Canon PowerShot G10
    Color Matrix 1                  : 1.3591 -0.6592 0.0324 -0.344 1.0533 0.3374 -0.0169 0.1008 0.5612
    Color Matrix 2                  : 1.1093 -0.3906 -0.1028 -0.5047 1.2492 0.2879 -0.1003 0.175 0.5561
    Calibration Illuminant 1        : Standard Light A (17)
    Calibration Illuminant 2        : D65 (21)
    Forward Matrix 1                : 0.6117 0.4074 -0.0548 0.2413 1.0772 -0.3185 0.0231 -0.1931 0.995
    Forward Matrix 2                : 0.6117 0.4074 -0.0548 0.2413 1.0772 -0.3185 0.0231 -0.1931 0.995
*/
    #define cam_CFAPattern                  0x01000201   // 0x01000201 = Green Blue Red Green
    #define cam_CalibrationIlluminant1      17           // Standard Light A
    #define cam_CalibrationIlluminant2      21           // D65
    #define CAM_COLORMATRIX1    \
      13591, 10000, -6592, 10000,   324, 10000, \
      -3440, 10000, 10533, 10000,  3374, 10000, \
        169, 10000,  1008, 10000,  5612, 10000
    #define CAM_COLORMATRIX2    \
      11093, 10000, -3906, 10000, -1028, 10000, \
      -5047, 10000, 12492, 10000,  2879, 10000, \
      -1003, 10000,  1750, 10000,  5561, 10000
    #define CAM_FORWARDMATRIX1    \
       6117, 10000,  4074, 10000,  -548, 10000, \
       2413, 10000, 10772, 10000, -3185, 10000, \
        231, 10000, -1931, 10000,  9950, 10000
    #define CAM_FORWARDMATRIX2    \
       6117, 10000,  4074, 10000,  -548, 10000, \
       2413, 10000, 10772, 10000, -3185, 10000, \
        231, 10000, -1931, 10000,  9950, 10000
    #define CAM_DNG_EXPOSURE_BIAS           0,1          // Specify DNG exposure bias value to 0 (to override default of -0.5 in the dng.c code)
    #define CAM_DNG_LENS_INFO               { 61,10, 305,10, 28,10, 45,10 }

    // zebra
    #define CAM_ZEBRA_NOBUF                 1

    #define CAM_USE_ALT_SET_ZOOM_POINT      1   // Define to use the alternate code in lens_set_zoom_point()

    #define CAM_DRIVE_MODE_FROM_TIMER_MODE  1       // use PROPCASE_TIMER_MODE to check for multiple shot custom timer.
                                                    // Used to enabled bracketing in custom timer, required on many recent cameras
                                                    // see http://chdk.setepontos.com/index.php/topic,3994.405.html

    #define REMOTE_SYNC_STATUS_LED          0xC02200DC  // specifies an LED that turns on while camera waits for USB remote to sync

    #undef  CAM_AF_LED
    #define CAM_AF_LED                      5       // Index of AF led in camera_set_led function

    #define CAM_HOTSHOE_OVERRIDE            1

    #define CAM_SD_OVER_IN_AF               1
    #define CAM_SD_OVER_IN_AFL              1
    #define CAM_SD_OVER_IN_MF               1

    #define CAM_HAS_FILEWRITETASK_HOOK      1

    #define CAM_HAS_CANON_RAW                   1   // has native Canon raw

//--------------------------------------------------
