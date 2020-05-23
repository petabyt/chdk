// Camera - sx610hs - platform_camera.h

// This file contains the various settings values specific to the sx610hs camera.
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

    #define CAM_PROPSET                     7
    #define CAM_DRYOS                       1
    #define CAM_DRYOS_2_3_R39               1 // Defined for cameras with DryOS version R39 or higher
    #define CAM_DRYOS_2_3_R47               1 // Defined for cameras with DryOS version R47 or higher


    #define CAM_RAW_ROWPIX                  5344 
    #define CAM_RAW_ROWS                    3950 

    #define CAM_JPEG_WIDTH                  5184 //Canon spec.   
    #define CAM_JPEG_HEIGHT                 3888    

    #define CAM_ACTIVE_AREA_X1              120     
    #define CAM_ACTIVE_AREA_Y1              16      
    #define CAM_ACTIVE_AREA_X2              5344 // active all the way to the edge
    #define CAM_ACTIVE_AREA_Y2              3950 // active all the way to the bottom

    #undef  CAM_UNCACHED_BIT
    #define CAM_UNCACHED_BIT                0x40000000     

    #undef CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL       12
	
	#undef  CAM_HAS_CMOS
	#define CAM_HAS_CMOS                    1

    #define CAM_DNG_LENS_INFO               { 45,10, 810, 10, 38,10, 69, 10 } // See comments in camera.h

    #define cam_CFAPattern                  0x02010100 // Red  Green  Green  Blue


    // TODO C&P from D10
    #define CAM_COLORMATRIX1                        \
      14052, 10000,   -5229, 10000,   -1156, 10000, \
      -1325, 10000,    9420, 10000,    2252, 10000, \
       -498, 10000,    1957, 10000,    4116, 10000
    #define cam_CalibrationIlluminant1      21      // D65
	
    #undef  CAM_HAS_IRIS_DIAPHRAGM
	#undef  CAM_HAS_DISP_BUTTON
    #undef  CAM_USE_ZOOM_FOR_MF
    #undef  CAM_HAS_MANUAL_FOCUS
	#undef  CAM_HAS_ERASE_BUTTON
	
	#define CAM_HAS_ND_FILTER                   1

    #define CAM_HAS_VIDEO_BUTTON                1
    #define CAM_HAS_MOVIE_DIGEST_MODE           1   // camera doesn't actually have digest mode, this is needed by is_video_recording
//    #define CAM_IS_VID_REC_WORKS                1	// is_video_recording() function works
    #undef CAM_IS_VID_REC_WORKS
	
    #undef  CAM_VIDEO_CONTROL
	#undef  CAM_CHDK_HAS_EXT_VIDEO_MENU

//    #define CAM_AF_SCAN_DURING_VIDEO_RECORD   1

    #undef CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO  // unlocked in canon firmware by default

    // MakeDirectory_Fut not found, using mkdir
    #define MKDIR_RETURN_ONE_ON_SUCCESS

    //aspect correction
    #undef  CAM_USES_ASPECT_CORRECTION
    #define CAM_USES_ASPECT_CORRECTION          1
    #undef  CAM_BITMAP_WIDTH
    #define CAM_BITMAP_WIDTH                    960   // Actual width of bitmap screen in bytes
    #undef  CAM_BITMAP_HEIGHT
    #define CAM_BITMAP_HEIGHT                   270   

    #define CAM_ADJUSTABLE_ALT_BUTTON           1

    #define CAM_ALT_BUTTON_NAMES            { "Playback", "Video", "Wifi" }
    #define CAM_ALT_BUTTON_OPTIONS          { KEY_PLAYBACK, KEY_VIDEO, KEY_WIFI }

    #undef  CAM_USB_EVENTID
    #define CAM_USB_EVENTID                     0x202 // Levent ID for USB control. Changed in DryOS R49 so needs to be overridable.

    
    #define CAM_DATE_FOLDER_NAMING              0x080    

    #define PARAM_CAMERA_NAME                   3 

    #define CAM_FILE_COUNTER_IS_VAR             1 // file counter is variable file_counter_var in stubs, not a param

    #define  CAM_HAS_FILEWRITETASK_HOOK         1 // FileWriteTask hook is available (local file write can be prevented)
    // doesn't appear to use complicated multi pass or seek in normal cases (based on similarity to elph180)
//    #define  CAM_FILEWRITETASK_SEEKS            1 // Camera's FileWriteTask can do Lseek() - DryOS r50 or higher, the define could also be CAM_DRYOS_2_3_R50

    #define CAM_NEED_SET_ZOOM_DELAY             500     // Define to add a delay after setting the zoom position

//  only non-AF led available
//    #define REMOTE_SYNC_STATUS_LED          0xC022302C  // specifies an LED that turns on while camera waits for USB remote to sync

    #undef CAM_AF_LED
    #define CAM_AF_LED                          1

    #undef  CAM_KEY_PRESS_DELAY
    #define CAM_KEY_PRESS_DELAY                 60  // delay after a press - Required by zoom_in/zoom_out buttons


    #define CAM_SD_OVER_IN_AF                   1
    #define CAM_SD_OVER_IN_AFL                  1
    #define CAM_SD_OVER_IN_MF                   1

    #define DRAW_ON_ACTIVE_BITMAP_BUFFER_ONLY   1
	
	#define CAM_3ARG_DebugAssert                1
    
//----------------------------------------------------------
    #undef  CAM_DEFAULT_MENU_CURSOR_BG
    #undef  CAM_DEFAULT_MENU_CURSOR_FG
    #define CAM_DEFAULT_MENU_CURSOR_BG  IDX_COLOR_RED      // Override menu cursor colors
    #define CAM_DEFAULT_MENU_CURSOR_FG  IDX_COLOR_WHITE    // Override menu cursor colors
