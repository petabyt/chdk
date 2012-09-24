// Camera - s100 - platform_camera.h

// This file contains the various settings values specific to the s100 camera.
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

    #define CAM_DRYOS         1
    #define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
    #define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
    #define CAM_RAW_ROWPIX    4160 // Found @0xff190f44
    #define CAM_RAW_ROWS      3124 // Found @0xff190f4c
    #undef  CAM_UNCACHED_BIT
    #define CAM_UNCACHED_BIT  0x40000000 // Found @0xff02bd84
    #define CAM_PROPSET                     4
    #define CAM_DRYOS                       1
    #undef  CAM_USE_ZOOM_FOR_MF
    #undef  CAM_MENU_BORDERWIDTH
    #define CAM_MENU_BORDERWIDTH            10
    #define CAM_QUALITY_OVERRIDE            1
    #define CAM_HAS_JOGDIAL                 1
    #define CAM_HAS_ERASE_BUTTON            1
    #define CAM_KEY_CLICK_DELAY             10 // camera requires additional delay for click command

    #define CAM_ADJUSTABLE_ALT_BUTTON       1
    #define CAM_BRACKETING                  1
    #undef  CAM_VIDEO_CONTROL
    #define CAM_VIDEO_QUALITY_ONLY          1
    #define CAM_MULTIPART                   1
    #define CAM_EXT_TV_RANGE                1
    #define CAM_SHOW_OSD_IN_SHOOT_MENU      1

    // camera name
    #define PARAM_CAMERA_NAME               4 // parameter number for GetParameterData
    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL       12

    #undef  CAM_USES_ASPECT_CORRECTION
    #define CAM_USES_ASPECT_CORRECTION      1  //camera uses the modified graphics primitives to map screens an viewports to buffers more sized
    #undef CAM_BITMAP_WIDTH
    #undef CAM_BITMAP_HEIGHT
    #define CAM_BITMAP_WIDTH                960 // Actual width of bitmap screen in bytes
    #define CAM_BITMAP_HEIGHT               270 // Actual height of bitmap screen in rows

    #undef  CAM_BITMAP_PALETTE
    #define CAM_BITMAP_PALETTE              7

    #undef  EDGE_HMARGIN
    #define EDGE_HMARGIN                    28

    #define CAM_DNG_LENS_INFO               { 52,10, 260,10, 20,10, 59,10 }

    #define cam_CFAPattern                  0x01000201 // = [Green Blue Red Green]
    // TODO: find correct values
    #define CAM_COLORMATRIX1                  \
      14134, 1000000, -5576, 1000000, -1527, 1000000, \
      -1991, 1000000, 10719, 1000000,  1273, 1000000, \
      -1158, 1000000,  1929, 1000000,  3581, 1000000
    #define cam_CalibrationIlluminant1      17  // TODO:

    // TODO: check these values
    #define CAM_JPEG_WIDTH                  4000
    #define CAM_JPEG_HEIGHT                 3000
    #define CAM_ACTIVE_AREA_X1              104
    #define CAM_ACTIVE_AREA_Y1              12
    #define CAM_ACTIVE_AREA_X2              (CAM_RAW_ROWPIX-8)
    #define CAM_ACTIVE_AREA_Y2              (CAM_RAW_ROWS-64)

    #define CAM_ZEBRA_ASPECT_ADJUST         1

    #define CAM_STARTUP_CRASH_FILE_OPEN_FIX 1   // enable workaround for camera crash at startup when opening the conf / font files
                                                // see http://chdk.setepontos.com/index.php?topic=6179.0

    // TODO: - we may need this to save memory
    //#define CAM_ZEBRA_NOBUF                 1

    #define CAM_DATE_FOLDER_NAMING                      1    // TODO
    #define CAM_DRIVE_MODE_FROM_TIMER_MODE  1   //  // TODO: use PROPCASE_TIMER_MODE to check for multiple shot custom timer.
                                                // Used to enabled bracketing in custom timer, required on many recent cameras
                                                // see http://chdk.setepontos.com/index.php/topic,3994.405.html
    #undef  CAM_USB_EVENTID
    #define CAM_USB_EVENTID         0x202 // Levent ID for USB control. Changed in DryOS R49 so needs to be overridable.

	#define REMOTE_SYNC_STATUS_LED 	0xC022C30C // specifies an LED that turns on while camera waits for USB remote to sync

    #undef CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO
    #undef CAM_AF_SCAN_DURING_VIDEO_RECORD

//----------------------------------------------------------
