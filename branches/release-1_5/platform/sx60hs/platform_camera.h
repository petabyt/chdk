// Camera - sx60hs - platform_camera.h

// This file contains the various settings values specific to the SX60HS camera.
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
/*gg
    #define CAM_DISABLE_RAW_IN_LOW_LIGHT_MODE   1
    #define CAM_DISABLE_RAW_IN_HQ_BURST         1
    #define CAM_DISABLE_RAW_IN_HYBRID_AUTO      1 // For cameras that lock up while saving raw in "Hybrid Auto" mode
    #define CAM_DISABLE_RAW_IN_AUTO             1
    #define CAM_DISABLE_RAW_IN_SPORTS           1
*/
// allows CHDK raw exception in sports mode
    #define CAM_HAS_SPORTS_MODE                 1

    #define CAM_AV_OVERRIDE_IRIS_FIX            1

    #undef  CAM_KEY_PRESS_DELAY
    #define CAM_KEY_PRESS_DELAY                 60          // delay after a press

    #define CAM_ADJUSTABLE_ALT_BUTTON           1
    #define CAM_ALT_BUTTON_NAMES                {  "Playback", "Video", "WiFi"}
    #define CAM_ALT_BUTTON_OPTIONS              {  KEY_PLAYBACK,   KEY_VIDEO, KEY_WIFI }
    #define CAM_DRIVE_MODE_FROM_TIMER_MODE      1

    // zebra and histo don't currently work, make shortcuts do nothing
    #define SHORTCUT_TOGGLE_HISTO               KEY_DUMMY
    #define SHORTCUT_TOGGLE_ZEBRA               KEY_DUMMY

    #define CAM_SWIVEL_SCREEN                   1
    #define CAM_DRYOS                           1
    #define CAM_DRYOS_2_3_R39                   1
    #define CAM_DRYOS_2_3_R47                   1
    #define CAM_DRYOS_2_3_R55                   1
    #define CAM_PROPSET                         8

    #define CAM_RAW_ROWPIX                      4768
//4608
    #define CAM_RAW_ROWS                        3516
//3456

    #define CAM_HAS_CMOS                        1

    #undef  CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO
    #define CAM_HAS_VIDEO_BUTTON                  1
//    #define CAM_VIDEO_QUALITY_ONLY                1
    #undef  CAM_HAS_DISP_BUTTON

    #undef  CAM_CHDK_HAS_EXT_VIDEO_MENU
    #undef  CAM_VIDEO_CONTROL

    #define CAM_HAS_JOGDIAL                     1

    #undef  CAM_UNCACHED_BIT
    #define CAM_UNCACHED_BIT                    0x40000000

    #undef  CAM_CIRCLE_OF_CONFUSION
    #define CAM_CIRCLE_OF_CONFUSION             5  // CoC value for camera/sensor (see http://www.dofmaster.com/digital_coc.html)

    
    #define CAM_DNG_LENS_INFO                   { 38,10,2470,10,34,10,65,10 } // 3.8 - 247 mm, f3.4 - f6.5
    #define cam_CFAPattern                      0x02010100

   #define cam_CalibrationIlluminant1          17

    // from CR2 converted to DNG with adobe DNG converter
    #define CAM_COLORMATRIX1 \
    15686, 10000, -8326, 10000, -246, 10000, \
    -1888, 10000, 10463, 10000, 1645, 10000, \
      286, 10000,   708, 10000, 6145, 10000

    #define cam_CalibrationIlluminant2          21     // aDobe 

    #define CAM_COLORMATRIX2 \
    13161, 10000, -5451, 10000, -1344, 10000, \
    -1989, 10000, 10654, 10000,  1531, 10000, \
      -47, 10000,  1271, 10000,  4955, 10000
    #define CAM_FORWARDMATRIX1 \
    3002, 10000, 3390, 10000, 3251, 10000, \
    1080, 10000, 6247, 10000, 2674, 10000, \
     341, 10000,   42, 10000, 7868, 10000

    #define CAM_FORWARDMATRIX2 \
    3678, 10000, 4352, 10000, 1613, 10000, \
    1429, 10000, 8091, 10000,  480, 10000, \
     577, 10000,   26, 10000, 7648, 10000
    #define CAM_JPEG_WIDTH                      4608
    #define CAM_JPEG_HEIGHT                     3456 

    #define CAM_ACTIVE_AREA_X1                  96 //?? 
    #define CAM_ACTIVE_AREA_Y1                  16 //??
    #define CAM_ACTIVE_AREA_X2                  4760
    #define CAM_ACTIVE_AREA_Y2                  3516

    #define PARAM_CAMERA_NAME                   3
    #define CAM_DATE_FOLDER_NAMING              0x80
    #define CAM_FILE_COUNTER_IS_VAR             1     // file counter is variable file_counter_var in stubs, not a param
    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL           12

    #define CAM_EXT_TV_RANGE                    1

    #define  CAM_HAS_ERASE_BUTTON               1
    #define CAM_SHOW_OSD_IN_SHOOT_MENU          1

    #define DRAW_ON_ACTIVE_BITMAP_BUFFER_ONLY   1           // Draw pixels on active bitmap buffer only.
   // #undef  CAM_USES_ASPECT_CORRECTION
    //#define CAM_USES_ASPECT_CORRECTION          1
    #undef  CAM_BITMAP_WIDTH
    #undef  CAM_BITMAP_HEIGHT
    #undef  CAM_SCREEN_WIDTH
    #undef  CAM_SCREEN_HEIGHT
//following widths could be 736 and 720
    #define CAM_BITMAP_WIDTH                    640 // Actual width of bitmap screen in <s>bytes</s> pixels
    #define CAM_BITMAP_HEIGHT                   480 // Actual height of bitmap screen in rows
    #define CAM_SCREEN_WIDTH                    640// Width of bitmap screen in CHDK co-ordinates (360 or 480)
    #define CAM_SCREEN_HEIGHT                   480 // Height of bitmap screen in CHDK co-ordinates (always 240 on all cameras so far)
    #define CAM_SUPPORT_BITMAP_RES_CHANGE         1
//    #undef CAM_SUPPORT_BITMAP_RES_CHANGE      
    

    #undef  EDGE_HMARGIN
    #define EDGE_HMARGIN                        10

    #define CAM_HAS_FILEWRITETASK_HOOK          1
    //#define CAM_FILEWRITETASK_SEEKS             1

    #undef  CAM_BITMAP_PALETTE
    #define CAM_BITMAP_PALETTE                  100

    #define CAM_ZEBRA_NOBUF                     1

    #define CAM_QUALITY_OVERRIDE                1

    #undef  CAMERA_MIN_DIST
    #define CAMERA_MIN_DIST                     100         // Override min subject distance
    #undef  CAMERA_MAX_DIST
    #define CAMERA_MAX_DIST                     1550000     // Override max subject distance; manually checked up to 1550388, with MF max 1369863 (double step)

    #undef CAM_HAS_GPS

    //#define CAM_CHDK_HAS_EXT_VIDEO_TIME         1

    #undef  CAM_USB_EVENTID
    #define CAM_USB_EVENTID                     0x202       // Levent ID for USB control. Changed in DryOS R49, R50 so needs to be overridable.

   // #define CAM_HAS_MOVIE_DIGEST_MODE           1 

    #define CAM_NEED_SET_ZOOM_DELAY             300

    #define MKDIR_RETURN_ONE_ON_SUCCESS         1    // mkdir() return 1 on success, 0 on fail.


    #undef  REMOTE_SYNC_STATUS_LED
    // #define REMOTE_SYNC_STATUS_LED              0xC022C30C  // TODO specifies an LED that turns on while camera waits for USB remote to sync
 
    #define CAM_SD_OVER_IN_AF  1
    #define CAM_SD_OVER_IN_AFL  1
    #define CAM_SD_OVER_IN_MF  1
    #undef  CAM_AF_LED 
    #define CAM_AF_LED     1
    #define CAM_SIMPLE_MOVIE_STATUS 1
    #define CAM_IS_VID_REC_WORKS 1
    #define CAM_HOTSHOE_OVERRIDE 1

    #define CAM_HAS_CANON_RAW                   1   // has native Canon raw
//--------------------------------------------------
