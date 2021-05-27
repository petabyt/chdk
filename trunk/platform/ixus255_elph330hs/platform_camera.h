// Camera - ixus255_elph330hs - platform_camera.h

// This file contains the various settings values specific to the elph130 camera.
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

    #define CAM_PROPSET                     6
    #define CAM_DRYOS                       1
    #define CAM_DRYOS_2_3_R39               1 // Defined for cameras with DryOS version R39 or higher
    #define CAM_DRYOS_2_3_R47               1 // Defined for cameras with DryOS version R47 or higher

    #define CAM_RAW_ROWPIX                  4176 // Found @0xff1f7824
    #define CAM_RAW_ROWS                    3062 // Found @0xff1f7830

    #define CAM_JPEG_WIDTH                  4000
    #define CAM_JPEG_HEIGHT                 3000

    // defined to pixels containing any data
    #define CAM_ACTIVE_AREA_X1              96
    #define CAM_ACTIVE_AREA_Y1              18
    #define CAM_ACTIVE_AREA_X2              4168
    #define CAM_ACTIVE_AREA_Y2              3062

    #undef  CAM_UNCACHED_BIT
    #define CAM_UNCACHED_BIT                0x40000000 // Found @0xff03a200

    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL       12

    #define CAM_DNG_LENS_INFO               { 43,10, 430,10, 30,10, 69,10 } // See comments in camera.h

    // verified
    #define cam_CFAPattern                  0x02010100 // Red Green Green Blue

    // Generated using X-Rite ColorChecker Camera Calibration software, v1.0.2
    // with photos taken of a GretagMacbeth ColorChecker
    // Matricies extracted with dcpTool: http://dcptool.sourceforge.net/
    #define cam_CalibrationIlluminant1      17      // Standard Light A
    #define cam_CalibrationIlluminant2      21      // D65
    #define CAM_COLORMATRIX1 \
       798, 1000,   -562, 1000,   1580, 1000, \
       158, 1000,     66, 1000,   1375, 1000, \
       528, 1000,  -1063, 1000,  12790, 1000
    #define CAM_COLORMATRIX2 \
     15311, 1000,  -6044, 1000,  -1478, 1000, \
      -435, 1000,   9280, 1000,   1381, 1000, \
       172, 1000,   1362, 1000,   3978, 1000

    // no separate erase button
    #undef  CAM_HAS_ERASE_BUTTON
    #undef  CAM_HAS_DISP_BUTTON
    #define CAM_HAS_VIDEO_BUTTON            1
    #undef  CAM_USE_ZOOM_FOR_MF
    #undef  CAM_HAS_IRIS_DIAPHRAGM
    #define CAM_HAS_ND_FILTER               1

    // long shutter is actually user TV, may work ?
    #undef  CAM_HAS_USER_TV_MODES

    #undef  CAM_VIDEO_CONTROL
// not working
    #undef  CAM_CHDK_HAS_EXT_VIDEO_MENU
//    #define CAM_VIDEO_QUALITY_ONLY          1
//    #define CAM_CHDK_HAS_EXT_VIDEO_MENU     1

    // TODO
//    #define CAM_AF_SCAN_DURING_VIDEO_RECORD 1

    #undef  CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO  // unlocked in canon firmware by default

    #undef  CAM_HAS_MANUAL_FOCUS

    // MakeDirectory_Fut not found, using mkdir
    #define MKDIR_RETURN_ONE_ON_SUCCESS

    //aspect correction
    #undef  CAM_USES_ASPECT_CORRECTION
    #define CAM_USES_ASPECT_CORRECTION      1       //camera uses the modified graphics primitives to map screens an viewports to buffers more sized
    #undef CAM_BITMAP_WIDTH
    #define CAM_BITMAP_WIDTH                960 // Actual width of bitmap screen in bytes
    #undef  CAM_BITMAP_HEIGHT
    #define CAM_BITMAP_HEIGHT               270 // Actual height of bitmap screen in rows

    #define DRAW_ON_ACTIVE_BITMAP_BUFFER_ONLY 1   // Draw pixels on active bitmap buffer only.

    #define CAM_LOAD_CUSTOM_COLORS          1   // Enable loading CHDK colors into the camera palette memory/hardware
    // doesn't seem to conflict badly with anything

    #define CAM_DRIVE_MODE_FROM_TIMER_MODE  1   // use PROPCASE_TIMER_MODE to check for multiple shot custom timer.
                                                // Used to enabled bracketing in custom timer, required on many recent cameras
                                                // see http://chdk.setepontos.com/index.php/topic,3994.405.html

    #define CAM_ADJUSTABLE_ALT_BUTTON       1

    #define CAM_ALT_BUTTON_NAMES            { "Playback", "Video" }
    #define CAM_ALT_BUTTON_OPTIONS          { KEY_PLAYBACK, KEY_VIDEO }

    #undef  CAM_USB_EVENTID
    #define CAM_USB_EVENTID                         0x202 // Levent ID for USB control. Changed in DryOS R49 so needs to be overridable.

    #undef  CAMERA_MIN_DIST
    #define CAMERA_MIN_DIST                 47      // Override min subject distance in macro mode
    #undef  CAMERA_MAX_DIST
    #define CAMERA_MAX_DIST                 564972       // Define max distance that can be set in _MoveFocusLensToDistance (allow override for superzooms - SX30/SX40)

    #define CAM_SD_OVER_IN_AFL              1
    #define CAM_SD_OVER_IN_MF               1

    // Seems to work
    #define CAM_DATE_FOLDER_NAMING          0x80

    #define PARAM_CAMERA_NAME               3       // parameter number for GetParameterData

    #define CAM_FILE_COUNTER_IS_VAR         1       // file counter is variable file_counter_var in stubs, not a param

    #define CAM_HAS_FILEWRITETASK_HOOK      1 // FileWriteTask hook is available (local file write can be prevented)
    #define CAM_FILEWRITETASK_SEEKS         1 // Camera's FileWriteTask can do Lseek() - DryOS r50 or higher, the define could also be CAM_DRYOS_2_3_R50

//    only non-AF led available
    #define REMOTE_SYNC_STATUS_LED          0xC022C020  // specifies an LED that turns on while camera waits for USB remote to sync

    #undef  CAM_AF_LED
    #define CAM_AF_LED                      1

    #define CAM_HAS_CMOS                    1          // Camera has CMOS sensor

    #define CAM_NEED_SET_ZOOM_DELAY          150    // Define to add a delay after setting the zoom position

    #define CAM_HAS_WIFI                    1       // Camera has wifi support

//----------------------------------------------------------
