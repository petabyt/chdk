// Camera - sx30 - platform_camera.h

// This file contains the various settings values specific to the sx30 camera.
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

    #define CAM_PROPSET                     4
    #define CAM_DRYOS                       1
    #define CAM_DRYOS_2_3_R39               1

    #define CAM_SWIVEL_SCREEN               1
    #define CAM_ADJUSTABLE_ALT_BUTTON       1
    #undef  CAM_CAN_SD_OVER_NOT_IN_MF
    #undef  CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO
    #define CAM_HAS_VIDEO_BUTTON            1
    #define CAM_VIDEO_QUALITY_ONLY          1
    #define CAM_BRACKETING                  1
    #undef  CAM_VIDEO_CONTROL
    #define CAM_MULTIPART                   1
    #define CAM_HAS_JOGDIAL                 1
    #undef  CAM_USE_ZOOM_FOR_MF
    #undef  CAM_UNCACHED_BIT                    // shut up compiler
    #define CAM_UNCACHED_BIT                0x40000000
    #define CAM_SHOW_OSD_IN_SHOOT_MENU      1

    #undef DEFAULT_RAW_EXT
    #define DEFAULT_RAW_EXT                 2   // use .CR2 

    #undef CAM_MENU_BORDERWIDTH
    #define CAM_MENU_BORDERWIDTH            10

    // bayer sensor pattern
    #define cam_CFAPattern                  0x01000201  // Green  Blue  Red  Green

    #define CAM_DNG_EXPOSURE_BIAS           0,1         // Specify DNG exposure bias value to 0 (to override default of -0.5 in the dng.c code)

    #define CAM_DNG_LENS_INFO               { 43,10, 1505,10, 27,10, 58,10 }    // See comments in camera.h

    // color

    // TODO - Still needs work
    #define cam_CalibrationIlluminant1      1   // Daylight

    #define CAM_COLORMATRIX1                                \
     1301431, 1000000,  -469837, 1000000, -102652, 1000000, \
     -200195, 1000000,   961551, 1000000,  238645, 1000000, \
      -16441, 1000000,   142319, 1000000,  375979, 1000000

    // Sensor size, DNG image size & cropping
    #define CAM_RAW_ROWPIX                  4464
    #define CAM_RAW_ROWS                    3276
    #define CAM_JPEG_WIDTH                  4368
    #define CAM_JPEG_HEIGHT                 3254
    #define CAM_ACTIVE_AREA_X1              24
    #define CAM_ACTIVE_AREA_Y1              10
    #define CAM_ACTIVE_AREA_X2              (CAM_RAW_ROWPIX-72)
    #define CAM_ACTIVE_AREA_Y2              (CAM_RAW_ROWS-12)
    // camera name
    #define PARAM_CAMERA_NAME               4   // parameter number for GetParameterData
    #define PARAM_DISPLAY_MODE1             59  // param number for LCD display mode when camera in playback
    #define PARAM_DISPLAY_MODE2             62  // param number for LCD display mode when camera in record view hold mode
    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL       12

    #define CAM_EXT_TV_RANGE                1
    #define CAM_QUALITY_OVERRIDE            1

    // copied from the SX200 which has the same video buffer size
    #undef  CAM_USES_ASPECT_CORRECTION
    #define CAM_USES_ASPECT_CORRECTION      1       //camera uses the modified graphics primitives to map screens an viewports to buffers more sized
    #undef CAM_BITMAP_WIDTH
    #undef CAM_BITMAP_HEIGHT
    #define CAM_BITMAP_WIDTH                960 // Actual width of bitmap screen in bytes
    #define CAM_BITMAP_HEIGHT               270 // Actual height of bitmap screen in rows

    #define CAM_ZEBRA_ASPECT_ADJUST         1

    #undef  CAM_BITMAP_PALETTE
    #define CAM_BITMAP_PALETTE              13


    #undef  EDGE_HMARGIN
    #define EDGE_HMARGIN                    2

    #define CAM_DATE_FOLDER_NAMING          0x400 //Value found in the last function, which is called in GetImageFolder. (first compare)

    #define CAM_STARTUP_CRASH_FILE_OPEN_FIX 1   // enable fix for camera crash at startup when opening the conf / font files see http://chdk.setepontos.com/index.php?topic=6179.0

    #define CAM_KEY_CLICK_DELAY             150 // SX30 appears to need extra delay for clicks

    #define CAM_DRIVE_MODE_FROM_TIMER_MODE  1   // use PROPCASE_TIMER_MODE to check for multiple shot custom timer.
                                                // Used to enabled bracketing in custom timer, required on many recent cameras
                                                // see http://chdk.setepontos.com/index.php/topic,3994.405.html

    #define CAM_FIRMWARE_MEMINFO            1   // Use 'GetMemInfo' to get free memory size.

    #define CAM_AV_OVERRIDE_IRIS_FIX        1   // for cameras that require _MoveIrisWithAv function to override Av.

    #define CAM_DISABLE_RAW_IN_LOW_LIGHT_MODE   1   // For cameras with 'low light' mode that does now work with raw define this

    #define CAM_LOAD_CUSTOM_COLORS          1   // Enable loading CHDK colors into the camera palette memory/hardware
    #define CHDK_COLOR_BASE                 0xB3// Start color index for CHDK colors loaded into camera palette.
    #define CAM_USE_COLORED_ICONS           1       // Enable using the CHDK-DE colored icons.

//	#define REMOTE_SYNC_STATUS_LED 	0xC0xxyyyy		// specifies an LED that turns on while camera waits for USB remote to sync

    #define CAM_NEED_SET_ZOOM_DELAY         300 // SX30 needs a short delay after setting the zoom before resetting focus in shooting_set_zoom()

    #undef  CAMERA_MIN_DIST
    #define CAMERA_MIN_DIST                 95      // Override min subject distance
    #undef  CAMERA_MAX_DIST
    #define CAMERA_MAX_DIST                 9090910 // Override max subject distance

//----------------------------------------------------------

