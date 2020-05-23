// Camera - sx530hs - platform_camera.h

// This file contains the various settings values specific to the sx530hs camera.
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


// propset 8, new for this camera. See development thread https://chdk.setepontos.com/index.php?topic=12418.msg127109#msg127109
    #define CAM_PROPSET                     8
    #define CAM_DRYOS                       1
    #define CAM_DRYOS_2_3_R39               1 // Defined for cameras with DryOS version R39 or higher
    #define CAM_DRYOS_2_3_R47               1 // Defined for cameras with DryOS version R47 or higher

    #undef  CAM_CIRCLE_OF_CONFUSION
    #define CAM_CIRCLE_OF_CONFUSION         6   // CoC value for camera/sensor (see http://www.dofmaster.com/digital_coc.html)

    #define CAM_RAW_ROWPIX                  4768 // Found @0xff196e7c
    #define CAM_RAW_ROWS                    3516 // Found @0xff196e88


    #define CAM_JPEG_WIDTH                  4608 // from canon specs
    #define CAM_JPEG_HEIGHT                 3456

    #define CAM_ACTIVE_AREA_X1              96
    #define CAM_ACTIVE_AREA_Y1              16
    #define CAM_ACTIVE_AREA_X2              4768 // active all the way to the edge
    #define CAM_ACTIVE_AREA_Y2              3516 // active all the way to the bottom

    #undef CAM_UNCACHED_BIT
    #define CAM_UNCACHED_BIT                0x40000000 // Found @0xff025c5c

    #undef CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL       12

    #define CAM_DNG_LENS_INFO               { 43,10, 1806,10, 34,10, 60,10 } // See comments in camera.h

    #define cam_CFAPattern                  0x02010100 // Red Green Green Blue

    // TODO C&P from D10
    #define CAM_COLORMATRIX1                        \
      14052, 10000,   -5229, 10000,   -1156, 10000, \
      -1325, 10000,    9420, 10000,    2252, 10000, \
       -498, 10000,    1957, 10000,    4116, 10000
    #define cam_CalibrationIlluminant1      21      // D65

    #undef  CAM_HAS_CMOS
    #define CAM_HAS_CMOS                    1

    #undef  CAM_USE_ZOOM_FOR_MF

    #define CAM_HAS_VIDEO_BUTTON            1

    #undef  CAM_HAS_DISP_BUTTON

    // long shutter is actually user TV, may work ?
    #undef  CAM_HAS_USER_TV_MODES
    #define CAM_SHOW_OSD_IN_SHOOT_MENU      1

    #undef  CAM_VIDEO_CONTROL

//    #define CAM_VIDEO_QUALITY_ONLY            1
    #define CAM_HAS_MOVIE_DIGEST_MODE       1   //Camera doesn't actually have MOVIE_DIGEST_MOVIE, but this is required by is_video_recording.
                                                //See http://chdk.setepontos.com/index.php?topic=9986.msg118892#msg118892
    //#define CAM_IS_VID_REC_WORKS            1   // is_video_recording() function works
    #undef CAM_IS_VID_REC_WORKS

    // TODO
//    #define CAM_AF_SCAN_DURING_VIDEO_RECORD   1
    #undef CAM_AF_SCAN_DURING_VIDEO_RECORD

    #undef CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO  // unlocked in canon firmware by default

    #define CAM_DRIVE_MODE_FROM_TIMER_MODE  1

    // MakeDirectory_Fut not found, using mkdir
    #define MKDIR_RETURN_ONE_ON_SUCCESS

    //aspect correction
    #undef  CAM_USES_ASPECT_CORRECTION
    #define CAM_USES_ASPECT_CORRECTION      1
    #undef  CAM_BITMAP_WIDTH
    #define CAM_BITMAP_WIDTH                960 // Actual width of bitmap screen in bytes (may be larger than displayed area)
    #undef  CAM_BITMAP_HEIGHT
    #define CAM_BITMAP_HEIGHT               270 // Actual height of bitmap screen in rows (240 or 270)


    #define CAM_HAS_JOGDIAL                 1
    #define CAM_ADJUSTABLE_ALT_BUTTON       1
    #define CAM_ALT_BUTTON_NAMES            { "Playback", "Video", "DriveMode" }
    #define CAM_ALT_BUTTON_OPTIONS          { KEY_PLAYBACK, KEY_VIDEO, KEY_DRIVE_MODE }

    // TODO
    #undef  CAM_USB_EVENTID
    #define CAM_USB_EVENTID                 0x202 // Levent ID for USB control. Changed in DryOS R49 so needs to be overridable.

    #define CAM_DATE_FOLDER_NAMING          0x080

    #define PARAM_CAMERA_NAME               3 // parameter number for GetParameterData

    #undef CAM_FILE_COUNTER_IS_VAR
    #define CAM_FILE_COUNTER_IS_VAR         1 // file counter is variable file_counter_var in stubs, not a param

    //#define  CAM_HAS_FILEWRITETASK_HOOK     1 // FileWriteTask hook is available (local file write can be prevented)
    #undef CAM_HAS_FILEWRITETASK_HOOK
    //#define  CAM_FILEWRITETASK_SEEKS        1 // Camera's FileWriteTask can do Lseek() - DryOS r50 or higher, the define could also be CAM_DRYOS_2_3_R50
    #undef  CAM_FILEWRITETASK_SEEKS

    #define CAM_NEED_SET_ZOOM_DELAY            300

//  only non-AF led available
//  CHDK doesn't currently (April 2016) support REMOTE_SYNC_STATUS_LED on DIGIC 4+ / 5 / 6 cameras
//    #define REMOTE_SYNC_STATUS_LED          0xC022D1FC  // specifies an LED that turns on while camera waits for USB remote to sync

    #undef CAM_AF_LED
    #define CAM_AF_LED                      1

    #undef  CAM_KEY_PRESS_DELAY
    #define CAM_KEY_PRESS_DELAY             120  // delay after a press - Required by zoom_in/zoom_out buttons

    #define SHORTCUT_TOGGLE_ZEBRA           KEY_MENU

    #define CAM_SD_OVER_IN_AF               1
    #define CAM_SD_OVER_IN_AFL              1
    #define CAM_SD_OVER_IN_MF               1

    #define CAM_MIN_ISO_OVERRIDE            100     // https://chdk.setepontos.com/index.php?topic=12314.msg128518#msg128518
    #define CAM_MAX_ISO_OVERRIDE            3200    // https://chdk.setepontos.com/index.php?topic=12314.msg128683#msg128683


    #undef DRAW_ON_ACTIVE_BITMAP_BUFFER_ONLY  //jeronymo
    #define DRAW_ON_ACTIVE_BITMAP_BUFFER_ONLY 1

    #define CAM_3ARG_DebugAssert                1   // DebugAssert takes 3 arguments

//----------------------------------------------------------
    #undef  CAM_DEFAULT_MENU_CURSOR_BG
    #undef  CAM_DEFAULT_MENU_CURSOR_FG
    #define CAM_DEFAULT_MENU_CURSOR_BG  IDX_COLOR_RED      // Override menu cursor colors
    #define CAM_DEFAULT_MENU_CURSOR_FG  IDX_COLOR_WHITE    // Override menu cursor colors


