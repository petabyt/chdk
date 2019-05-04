// Camera - IXUS300_SD4000 - platform_camera.h

// This file contains the various settings values specific to the IXUS300_SD4000 camera.
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

    #define CAM_PROPSET                     3       
    #define CAM_DRYOS                       1
    #define CAM_DRYOS_2_3_R39               1       // ROM:FFB5E1C0, actually its DRYOS version 2.3, release #0043

    #define CAM_HAS_CMOS                    1

    #undef  CAM_UNCACHED_BIT                             // shut up compiler
    #define CAM_UNCACHED_BIT                0x40000000   // ROM:FF88A248 via ExMem.FreeCacheable()

    #undef  CAM_HAS_ERASE_BUTTON
    
    #define CAM_HAS_ND_FILTER               1

    #undef  CAM_HAS_MANUAL_FOCUS

    #undef  CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO    // canon firmware allow optical zoom while recording movie
    
    #define CAM_VIDEO_QUALITY_ONLY          1        // ToDo: Video Bitrate override cause crash
    #define CAM_HAS_JOGDIAL                 1
    #define CAM_FEATURE_FEATHER             1
    #define CAM_MULTIPART                   1 
    #define CAM_DATE_FOLDER_NAMING          0x100

    #undef CAM_DEFAULT_ALT_BUTTON
    #define CAM_DEFAULT_ALT_BUTTON  KEY_PLAYBACK   // alt button for cameras without adjustable alt
    #undef  CAM_HAS_DISP_BUTTON

    #undef  DNG_BADPIXEL_VALUE_LIMIT
    #define DNG_BADPIXEL_VALUE_LIMIT        16      // Camera sensor apparently has bad pixels with value > 0 & <=16

    #define CAM_DNG_LENS_INFO               { 49,10, 186,10, 20,10, 53,10 } // See comments in camera.h
    #define cam_CFAPattern                  0x02010100            // Red  Green  Green  Blue, OK

    #define CAM_COLORMATRIX1                               \
      640019, 1000000, -220031, 1000000, -96241, 1000000,  \
     -77419,  1000000, 639766,  1000000,  44009, 1000000,  \
      17965,  1000000, 78396,   1000000, 231868, 1000000

    #define cam_CalibrationIlluminant1      1        // Daylight

    #define CAM_RAW_ROWPIX                  3816     // ROM:FFB28EEC
    #define CAM_RAW_ROWS                    2784     // ROM:FFB28EF4

    #define CAM_JPEG_WIDTH                  3648     // JPEG Exif data or ROM:FFB28EFC
    #define CAM_JPEG_HEIGHT                 2736     // JPEG Exif data or ROM:FFB28F04

    #define CAM_ACTIVE_AREA_X1              120      // x offset (right)
    #define CAM_ACTIVE_AREA_Y1              24       // y offset (down)
    #define CAM_ACTIVE_AREA_X2              3784
    #define CAM_ACTIVE_AREA_Y2              2764

    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL       12

    #define PARAM_CAMERA_NAME               4       // parameter number (index) for GetParameterData to get Camera Name

    #define CAM_LOAD_CUSTOM_COLORS          1      // Enable loading CHDK colors into the camera palette memory/hardware
    
    #undef CAM_USES_ASPECT_CORRECTION
    #define CAM_USES_ASPECT_CORRECTION      1       // camera uses the modified graphics primitives to map screens an viewports to buffers more sized
    #undef CAM_SCREEN_WIDTH
    #undef CAM_BITMAP_WIDTH
    #undef CAM_BITMAP_HEIGHT
    #define CAM_SCREEN_WIDTH                480     // Width of bitmap screen in CHDK co-ordinates
    #define CAM_BITMAP_WIDTH                960     // Actual width of bitmap screen in bytes
    #define CAM_BITMAP_HEIGHT               270     // Actual height of bitmap screen in rows

    #define REMOTE_SYNC_STATUS_LED          0xc0220134  // specifies an LED that turns on while camera waits for USB remote to sync

    #define CAM_DRIVE_MODE_FROM_TIMER_MODE  1       // use PROPCASE_TIMER_MODE to check for multiple shot custom timer.

    #define CAM_QUALITY_OVERRIDE            1       // enable 'super fine' override
 
    #undef  CAM_SD_OVER_IN_AF                       // crashes trying to use Subject Distance Overrides if MF or AFL not set
    #define CAM_SD_OVER_IN_AFL              1       // 
    #define CAM_SD_OVER_IN_MF               1       //
    
    #undef  CAM_AF_LED 
    #define CAM_AF_LED                      2       // index of AF led in camera_set_led function

    #define CAM_NEED_SET_ZOOM_DELAY          300    // Define to add a delay after setting the zoom position
    #define CAM_USE_ALT_SET_ZOOM_POINT       1      // Define to use the alternate code in lens_set_zoom_point()
    #define CAM_USE_ALT_PT_MoveOpticalZoomAt 1      // Define to use the PT_MoveOpticalZoomAt() function in lens_set_zoom_point()
 
    #define CAM_MIN_ISO_OVERRIDE            (125+1) // Defines min market (non-zero) ISO override value - lower value may crash if flash used [0 = AUTO, so always allowed] (+1 due to rounding issues)

    #define CAM_HAS_FILEWRITETASK_HOOK      1

//--------------------------------------------------
