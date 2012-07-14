// Camera - ixus130_sd1400 - platform_camera.h

// This file contains the various settings values specific to the ixus130 camera.
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

    #define CAM_PROPSET                 3
    #define CAM_DRYOS                   1
    #define CAM_DRYOS_2_3_R39           1

    #define CAM_RAW_ROWPIX              4416		// 14 MP 12bpp
    #define CAM_RAW_ROWS                3296		// 

    #undef  CAM_HAS_ERASE_BUTTON
 // #undef  CAM_USE_ZOOM_FOR_MF
    #define CAM_MULTIPART               1
    #undef  CAM_HAS_IRIS_DIAPHRAGM
    #define CAM_HAS_ND_FILTER           1

    #undef CAM_REMOTE
    #undef CAM_SYNCH

    #define CAM_HAS_ZOOM_LEVER          1

 // #define CAM_CAN_SD_OVER_NOT_IN_MF   1			// Camera allows subject distance (focus) override when not in manual focus mode
 // #define CAM_CAN_SD_OVERRIDE         1			// Camera allows to do subject distance override

    #undef  CAM_HAS_MANUAL_FOCUS
    #undef  CAM_HAS_USER_TV_MODES
    #define CAM_SHOW_OSD_IN_SHOOT_MENU            1
    #define CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO  1
    #define CAM_AF_SCAN_DURING_VIDEO_RECORD       1
    #define CAM_CHDK_HAS_EXT_VIDEO_MENU           1

    #define CAM_HAS_IS                  1
    #undef CAM_HAS_JOGDIAL

    #undef  CAM_VIDEO_CONTROL
    #define CAM_VIDEO_QUALITY_ONLY      1
    #define DNG_SUPPORT                 1

    #define CAM_EXT_TV_RANGE            1

    #undef CAM_UNCACHED_BIT
    #define CAM_UNCACHED_BIT            0x40000000

    #define CAM_MAKE                    "Canon"

    #undef CAM_BITMAP_PALETTE
    #define CAM_BITMAP_PALETTE          5

    #undef ZEBRA_HMARGIN0
    #define ZEBRA_HMARGIN0              30			//zebra adjust buffer height: show use at sx200is: needed for save memory space
    #define CAM_ZEBRA_ASPECT_ADJUST 1
    #define CAM_ZEBRA_NOBUF 1

    #define CAM_QUALITY_OVERRIDE 1
    #undef CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL   12
    #undef CAM_WHITE_LEVEL
    #define CAM_WHITE_LEVEL             ((1<<CAM_SENSOR_BITS_PER_PIXEL)-1)
    #undef CAM_BLACK_LEVEL
    #define CAM_BLACK_LEVEL             127

    #define CAM_DNG_LENS_INFO   { 50,10, 200,10, 28,10, 59,10 } // See comments in camera.h

    #define cam_CFAPattern              0x02010100		// Red  Green  Green  Blue

    #define CAM_COLORMATRIX1 510370, 1000000, -68998, 1000000,  -86859, 1000000, \
                            -279980, 1000000, 766686, 1000000,   67944, 1000000, \
                             -14382, 1000000, 113688, 1000000,  239853, 1000000

    #define CAM_ACTIVE_AREA_X1                  48
    #define CAM_ACTIVE_AREA_Y1                  28
    #define CAM_ACTIVE_AREA_X2                  4416-48
    #define CAM_ACTIVE_AREA_Y2                  3296-28

    //nandoide sept-2009
    #undef CAM_USES_ASPECT_CORRECTION   
    #undef CAM_USES_ASPECT_YCORRECTION  
    #define CAM_USES_ASPECT_CORRECTION  1  //camera uses the modified graphics primitives to map screens an viewports to buffers more sized 
    #define CAM_USES_ASPECT_YCORRECTION  0  //only uses mappings on x coordinate

    //grids
    #undef ASPECT_GRID_XCORRECTION
    #define ASPECT_GRID_XCORRECTION(x)  ( (x << 2) / 3 )
    #undef ASPECT_GRID_YCORRECTION
    #define ASPECT_GRID_YCORRECTION(y)  ( (y) )       //y correction for grids  made on a 360x240 As the buffer is 720x240 we have no correction here.
    
    //viewport
    #undef ASPECT_VIEWPORT_XCORRECTION 
    #define ASPECT_VIEWPORT_XCORRECTION(x) ASPECT_GRID_XCORRECTION(x)
    #undef ASPECT_VIEWPORT_YCORRECTION 
    #define ASPECT_VIEWPORT_YCORRECTION(y) ( (y) ) 
    #undef EDGE_HMARGIN 
    #define EDGE_HMARGIN 28
    
    //games mappings
   #undef GAMES_SCREEN_WIDTH
   #undef GAMES_SCREEN_HEIGHT
   #define GAMES_SCREEN_WIDTH 360
   #define GAMES_SCREEN_HEIGHT 240
   #undef ASPECT_GAMES_XCORRECTION
   #define ASPECT_GAMES_XCORRECTION(x)   ( (x) << 1 )  
   #undef ASPECT_GAMES_YCORRECTION
   #define ASPECT_GAMES_YCORRECTION(y)   ( (y) )  //none

    #define cam_CalibrationIlluminant1  17			// Standard Light A

    // cropping
    #define CAM_JPEG_WIDTH              4320
    #define CAM_JPEG_HEIGHT             3240
    // camera name
    #define PARAM_CAMERA_NAME           4			// parameter number for GetParameterData sd990: OK
    #define CAM_CHDK_PTP                1
    #define CAM_DATE_FOLDER_NAMING      1

