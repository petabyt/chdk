
// Camera - Powershot N - platform_camera.h

// This file contains the various settings values specific to the PowerShot N camera.
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
    #define CAM_DRYOS_2_3_R39               1               // Defined for cameras with DryOS version R39 or higher
    #define CAM_DRYOS_2_3_R47               1               // Defined for cameras with DryOS version R47 or higher

    #define CAM_RAW_ROWPIX                  4176            // Found @0xff20165c
    #define CAM_RAW_ROWS                    3062            // Found @0xff201668
    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL       12

    #undef  CAM_UNCACHED_BIT
    #define CAM_UNCACHED_BIT                0x40000000      // Found @0xff03a120

    #define CAM_JPEG_WIDTH                  4000            // from jpeg exif info
    #define CAM_JPEG_HEIGHT                 3000            //

    #define CAM_FILE_COUNTER_IS_VAR         1               // file counter is variable file_counter_var in stubs, not a param
    #define CAM_DATE_FOLDER_NAMING          0x080           // Found @0xff3a8cd4 (pass as 3rd param to GetImageFolder)

    #undef  CAM_HAS_ERASE_BUTTON                            // No erase button
    #undef  CAM_HAS_MANUAL_FOCUS                            // No manual focus mode
    #define CAM_HAS_CMOS                    1
    #define CAM_HAS_ND_FILTER               1
    #undef  CAM_HAS_IRIS_DIAPHRAGM

    #undef  CAM_USES_ASPECT_CORRECTION
    #define CAM_USES_ASPECT_CORRECTION      1               // camera uses the modified graphics primitives to map screens and viewports to buffers more sized
    #define CAM_LOAD_CUSTOM_COLORS          1               // Enable loading CHDK colors into the camera palette memory/hardware

    #undef  CAM_BITMAP_WIDTH
    #define CAM_BITMAP_WIDTH                720             // Actual width of bitmap screen in bytes (may be larger than displayed area)
    #undef  EDGE_HMARGIN
    #define EDGE_HMARGIN                    1               // edge overlay margin
    #undef  CAM_MENU_BORDERWIDTH
    #define CAM_MENU_BORDERWIDTH            -3              // Need to leave this much border to avoid overlap with on screen buttons (added to CAM_TS_BUTTON_BORDER).
    #undef  CAM_TS_BUTTON_BORDER
    #define CAM_TS_BUTTON_BORDER            50              // 60  = Define this to leave a border on each side of the palette display.
    #undef  CAM_DISP_ALT_TEXT                               // Turn off <ALT> at bottom of screen in Alt mode - changes button color instead
    #define CAM_TOUCHSCREEN_UI              1               // Enable touch screen U/I

    #undef  CAM_EMUL_KEYPRESS_DELAY         
    #define CAM_EMUL_KEYPRESS_DELAY         80              // Delay to interpret <alt>-button press as longpress
    #undef  CAM_EMUL_KEYPRESS_DURATION
    #define CAM_EMUL_KEYPRESS_DURATION      10

    #undef  MKDIR_RETURN_ONE_ON_SUCCESS                     // mkdir() return 1 on success, 0 on fail.

    #define PARAM_CAMERA_NAME               3               // parameter number for GetParameterData - Camera Model name

    #define CAM_HAS_FILEWRITETASK_HOOK      1
    #define CAM_FILEWRITETASK_SEEKS         1
    #define CAM_SHOW_OSD_IN_SHOOT_MENU      1

    #define CAM_ACTIVE_AREA_X1              92              // DNG stuff
    #define CAM_ACTIVE_AREA_Y1              14
    #define CAM_ACTIVE_AREA_X2              4160
    #define CAM_ACTIVE_AREA_Y2              3050
    #define cam_CFAPattern                  0x02010100      // bayer sensor pattern Red  Green  Green  Blue
    #define CAM_DNG_EXPOSURE_BIAS           0,1             // DNG exposure bias value to 0 (to override default of -0.5 in the dng.c code)
    #define CAM_DNG_LENS_INFO               { 28,10, 2240,10, 30,10, 59,10 } // See comments in camera.h
    #define cam_CalibrationIlluminant1      1
    #define CAM_COLORMATRIX1    \
    544808, 1000000, -174047, 1000000, -80399, 1000000, \
    -75055, 1000000, 440444, 1000000, 11367, 1000000, \
    -5801, 1000000, 71589, 1000000, 118914, 1000000

    #undef  CAM_USB_EVENTID
    #define CAM_USB_EVENTID                 0x202           // Levent ID for USB control. Changed in DryOS R49, R50 so needs to be overridable.

    #define CAM_SD_OVER_IN_AFL              1               // probably not going to work well
    #define CAM_SD_OVER_IN_MF               1               //

    #undef  CAM_GUI_FSELECT_SIZE      
    #define CAM_GUI_FSELECT_SIZE            15, 6, 8       // use narrow columns in file select window gui

    #define CAM_IS_VID_REC_WORKS            1   // is_video_recording() function works

//------ Powershot N - fence for values checked as okay - stuff below here not checked yet ---------------

    #undef  CAM_USE_ZOOM_FOR_MF                             // not useful if cam does not have Canon MF mode - just changes focus mode
    #define CAM_NEED_SET_ZOOM_DELAY         300             // add a delay after setting the zoom position

    #define CAM_BRACKETING                  1               // allow disable of RAW saving in native Ev bracketing
    #define CAM_DRIVE_MODE_FROM_TIMER_MODE  1               // use PROPCASE_TIMER_MODE to check for multiple shot custom timer.

    #undef  CAM_VIDEO_CONTROL
    #define CAM_HAS_VIDEO_BUTTON            1
    #undef  CAM_CHDK_HAS_EXT_VIDEO_MENU
//    #define CAM_VIDEO_QUALITY_ONLY          1
    #define CAM_HAS_MOVIE_DIGEST_MODE       1
    #undef  CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO
    #undef  CAM_CHDK_HAS_EXT_VIDEO_TIME

//--------------------------------------------------
