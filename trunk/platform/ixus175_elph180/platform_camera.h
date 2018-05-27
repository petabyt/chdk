// Camera - ixus175_elph180 - platform_camera.h

// This file contains the various settings values specific to the A2500 camera.
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
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    5248 // Found @0xff97c21c
//#define CAM_RAW_ROWS      3920 // Found @0xff97c224
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff825d74
//#define CAM_DATE_FOLDER_NAMING 0x080 // Found @0xffaba86c (pass as 3rd param to GetImageFolder)
//#define PARAM_CAMERA_NAME 3 // Found @0xffce41a8

    #define CAM_PROPSET                     10
    #define CAM_DRYOS                       1
    #define CAM_DRYOS_2_3_R39               1       // Defined for cameras with DryOS version R39 or higher
    #define CAM_DRYOS_2_3_R47               1       // Defined for cameras with DryOS version R47 or higher

#define CAM_RAW_ROWPIX    5248 // Found @0xff97c21c
#define CAM_RAW_ROWS      3920 // Found @0xff97c224

    #define CAM_JPEG_WIDTH                  5152
    #define CAM_JPEG_HEIGHT                 3864
    
    #define CAM_ACTIVE_AREA_X1              0
    #define CAM_ACTIVE_AREA_Y1              0
    #define CAM_ACTIVE_AREA_X2              5192
    #define CAM_ACTIVE_AREA_Y2              3900

    #undef  CAM_UNCACHED_BIT
    #define CAM_UNCACHED_BIT                0x40000000 // Found @0xff825d74

    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL       12
    
    #define CAM_DNG_LENS_INFO               { 50,10, 400,10, 32,10, 69,10 } // See comments in camera.h
    
    #define cam_CFAPattern                  0x02010100 // Red  Green  Green  Blue ixus160
    
    //TODO
    #define CAM_COLORMATRIX1                             \
    827547, 1000000, -290458, 1000000, -126086, 1000000, \
    -12829, 1000000,  530507, 1000000,   50537, 1000000, \
      5181, 1000000,   48183, 1000000,  245014, 1000000

    #define cam_CalibrationIlluminant1      1       // Daylight

#define CAM_DATE_FOLDER_NAMING 0x080 // Found @0xffaba86c (pass as 3rd param to GetImageFolder)
#define PARAM_CAMERA_NAME 3 // Found @0xffce41a8

    // MakeDirectory_Fut not found, using mkdir
    #define MKDIR_RETURN_ONE_ON_SUCCESS     1

    #define CAM_HAS_FILEWRITETASK_HOOK      1       // FileWriteTask hook is available (local file write can be prevented)
    #define CAM_FILEWRITETASK_SEEKS         1       // Camera's FileWriteTask can do Lseek() - DryOS r50 or higher, the define could also be CAM_DRYOS_2_3_R50

    #define CAM_FILE_COUNTER_IS_VAR         1       // file counter is variable file_counter_var in stubs, not a param

    #undef  CAM_HAS_IRIS_DIAPHRAGM
    #define CAM_HAS_ND_FILTER               1
    #define CAM_EXT_TV_RANGE                1       // CHDK can make exposure time longer than 64s

    #define CAM_QUALITY_OVERRIDE            1       // enable JPEG quality override

    #undef  CAM_USES_ASPECT_CORRECTION
    #define CAM_USES_ASPECT_CORRECTION      1       // camera uses the modified graphics primitives to map screens an viewports to buffers more sized
    #undef  CAM_BITMAP_WIDTH
    #define CAM_BITMAP_WIDTH                720     // Actual width of bitmap screen in bytes
    #undef  CAM_BITMAP_HEIGHT
    #define CAM_BITMAP_HEIGHT               360

 //   #define CAM_ZEBRA_NOBUF                 1

    #define CAM_LOAD_CUSTOM_COLORS          1       // Enable loading CHDK colors into the camera palette memory/hardware

    #define CAM_ADJUSTABLE_ALT_BUTTON       1

    #define CAM_ALT_BUTTON_NAMES            { "Playback", "Help" }
    #define CAM_ALT_BUTTON_OPTIONS          { KEY_PLAYBACK, KEY_HELP }

    #define DRAW_ON_ACTIVE_BITMAP_BUFFER_ONLY   1

    #define CAM_DISABLE_RAW_IN_LOW_LIGHT_MODE   1   // For cameras with 'low light' mode that does not work with raw define this

    #define CAM_USE_ALT_SET_ZOOM_POINT          1   // Define to use the alternate code in lens_set_zoom_point()
    #define CAM_USE_ALT_PT_MoveOpticalZoomAt    1   // Define to use the PT_MoveOpticalZoomAt() function in lens_set_zoom_point()
    #define CAM_NEED_SET_ZOOM_DELAY             100 // Define to add a delay after setting the zoom position
    
    #undef  CAM_HAS_ERASE_BUTTON
    #undef  CAM_HAS_DISP_BUTTON
    #undef  CAM_DEFAULT_ALT_BUTTON
    #define CAM_DEFAULT_ALT_BUTTON          KEY_PLAYBACK
    #define SHORTCUT_TOGGLE_RAW             KEY_VIDEO
    #define CAM_HAS_VIDEO_BUTTON            1

   	#define CAM_SD_OVER_IN_AF               1
    #define CAM_SD_OVER_IN_AFL              1
    #define CAM_SD_OVER_IN_MF               1

	#undef  CAM_USB_EVENTID
    #define CAM_USB_EVENTID                 0x302   // Levent ID for USB control. Changed in DryOS R49 so needs to be overridable.
	
	#undef CAM_AF_LED
    #define CAM_AF_LED                      1
    //#define CAM_VIDEO_QUALITY_ONLY          1
//    #undef  CAM_VIDEO_CONTROL
//    #undef  CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO    // it's unlocked by default
//    #define CAM_IS_VID_REC_WORKS            1       // TODO
    
   

    //#define CAM_DRIVE_MODE_FROM_TIMER_MODE  1

   
//----------------------------------------------------------