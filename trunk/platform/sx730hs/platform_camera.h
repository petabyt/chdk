// Camera - sx730hs - platform_camera.h

// This file contains the various settings values specific to the sx730hs camera.
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

    #define CAM_PROPSET                         12

    // g7x RAW in hybrid auto actually works if you enable "unsafe IO", otherwise hangs
    #define CAM_DISABLE_RAW_IN_HYBRID_AUTO      1
    #define CAM_DISABLE_RAW_IN_HANDHELD_NIGHT_SCN   1 // probably doesn't make sense

    #define CAM_HAS_SPORTS_MODE                 1

    #define CAM_AV_OVERRIDE_IRIS_FIX            1  // for cameras that require _MoveIrisWithAv function to override Av (for bracketing).

    // doesn't seem to needed
//    #undef  CAM_KEY_PRESS_DELAY
//    #define CAM_KEY_PRESS_DELAY                 60          // delay after a press

    #define CAM_ADJUSTABLE_ALT_BUTTON           1

    #define CAM_ALT_BUTTON_NAMES                { "Playback", "Video", "Wifi" }
    #define CAM_ALT_BUTTON_OPTIONS              { KEY_PLAYBACK, KEY_VIDEO, KEY_WIFI}
    #define CAM_DRIVE_MODE_FROM_TIMER_MODE      1

    // default zebra shortcut (left) conflicts with canon AF lock
    #define SHORTCUT_TOGGLE_ZEBRA               KEY_MENU
    // default histo shortcut (up) conflicts with canon AE lock
    #define SHORTCUT_TOGGLE_HISTO               KEY_DUMMY

    #define CAM_DRYOS                           1
    #define CAM_DRYOS_2_3_R39                   1
    #define CAM_DRYOS_2_3_R47                   1

    #define CAM_HAS_CMOS                        1

    // unlocked by default, not needed
    #undef  CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO
    #define CAM_HAS_VIDEO_BUTTON                1

// framing assist = erase
// no dedicated DISP
//    #undef  CAM_HAS_ERASE_BUTTON
    #undef  CAM_USE_ZOOM_FOR_MF

// not implemented
    #undef  CAM_CHDK_HAS_EXT_VIDEO_MENU
    #undef  CAM_VIDEO_CONTROL

// minimal recording or not only
    #define CAM_SIMPLE_MOVIE_STATUS             1

    #define  CAM_IS_VID_REC_WORKS               1 // Define if the 'is_video_recording()' function works

    #define CAM_HAS_JOGDIAL                     1
    #undef  CAM_USE_ZOOM_FOR_MF

    #undef  CAM_UNCACHED_BIT
    #define CAM_UNCACHED_BIT                    0x40000000

// default
//    #define CAM_CIRCLE_OF_CONFUSION             5  // CoC value for camera/sensor (see http://www.dofmaster.com/digital_coc.html)

    #define CAM_DNG_LENS_INFO                   { 43,10,1720,10,33,10,69,10 }
    #define cam_CFAPattern                      0x02010100

// TODO C&P form sx60hs
    #define cam_CalibrationIlluminant1          17

    #define CAM_COLORMATRIX1 \
    15686, 10000, -8326, 10000, -246, 10000, \
    -1888, 10000, 10463, 10000, 1645, 10000, \
      286, 10000,   708, 10000, 6145, 10000

    #define cam_CalibrationIlluminant2          21     // D65 

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

    #define CAM_RAW_ROWPIX                      5344
    #define CAM_RAW_ROWS                        3950

    #define CAM_JPEG_WIDTH                      5184
    #define CAM_JPEG_HEIGHT                     3888

    // sx730 verified identical to sx710
    #define CAM_ACTIVE_AREA_X1                  96 // normal level at 120
    #define CAM_ACTIVE_AREA_Y1                  18 // visible pixels start at 17, 18 to keep even, normal level at 22
    #define CAM_ACTIVE_AREA_X2                  5344 // active area extends to right
    #define CAM_ACTIVE_AREA_Y2                  3950 // active area extends to bottom of image

    #define PARAM_CAMERA_NAME                   3

// same as sx710 value found by calling GetImageFolder with single bits sets
    #define CAM_DATE_FOLDER_NAMING              0x80

    #define CAM_FILE_COUNTER_IS_VAR             1     // file counter is variable file_counter_var in stubs, not a param

    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL           12

    #define CAM_EXT_TV_RANGE                    1   // up to 1024s appears to be supported natively in firmware, exp_drv required for short exposure

    #undef CAM_EXT_AV_RANGE
    // up to APEX 850 F21.5 at max zoom,  640 F 10 at wide
    #define CAM_EXT_AV_RANGE                    9   // Number of 1/3 stop increments to extend the Av range beyond the Canon default smallest aperture

    #define CAM_SHOW_OSD_IN_SHOOT_MENU          1

    #define DRAW_ON_ACTIVE_BITMAP_BUFFER_ONLY   1           // Draw pixels on active bitmap buffer only.
   
    // seems to be 640x480
    #undef  CAM_BITMAP_WIDTH
    #undef  CAM_BITMAP_HEIGHT
    #undef  CAM_SCREEN_WIDTH
    #undef  CAM_SCREEN_HEIGHT
    #define CAM_BITMAP_WIDTH                    640 // Actual width of bitmap screen in <s>bytes</s> pixels
    #define CAM_BITMAP_HEIGHT                   480 // Actual height of bitmap screen in rows
    #define CAM_SCREEN_WIDTH                    640 // Width of bitmap screen in CHDK co-ordinates (360 or 480 pre digic 6, actual width for digic 6)
    #define CAM_SCREEN_HEIGHT                   480 // Height of bitmap screen in CHDK co-ordinates (always 240 pre digic 6, actual height for digic 6)
// TODO
//    #define CAM_SUPPORT_BITMAP_RES_CHANGE       1
    

// TODO
    #undef  EDGE_HMARGIN
    #define EDGE_HMARGIN                        10

// TODO SX730 doesn't have filewrite task
//    #define CAM_HAS_FILEWRITETASK_HOOK          1
    // doesn't appear to use complicated multi pass or seek in normal cases
    //#define CAM_FILEWRITETASK_SEEKS             1

    #undef  CAM_BITMAP_PALETTE
    #define CAM_BITMAP_PALETTE                  100

    #define CAM_ZEBRA_NOBUF                     1

    #undef  CAMERA_MIN_DIST
    #define CAMERA_MIN_DIST                     10         // Override min subject distance, min get_focus() value using MF
    #undef  CAMERA_MAX_DIST
    #define CAMERA_MAX_DIST                     1818088     // Override max subject distance, max get_focus() value at max zoom using MF before it goes to -1

    //#define CAM_CHDK_HAS_EXT_VIDEO_TIME         1

    #undef  CAM_USB_EVENTID
    #define CAM_USB_EVENTID                     0x302       // Levent ID for USB control. 

//    #define CAM_HAS_MOVIE_DIGEST_MODE           1 

// didn't try default default values
    #define CAM_USE_ALT_SET_ZOOM_POINT          1           // Define to use the alternate code in lens_set_zoom_point()
    #define CAM_USE_ALT_PT_MoveOpticalZoomAt    1           // Define to use the PT_MoveOpticalZoomAt() function in lens_set_zoom_point()
// ignored with above
//    #define CAM_NEED_SET_ZOOM_DELAY             300

    #define MKDIR_RETURN_ONE_ON_SUCCESS         1    // mkdir() return 1 on success, 0 on fail.

    #undef  REMOTE_SYNC_STATUS_LED
    // #define REMOTE_SYNC_STATUS_LED              0xC022C30C  // TODO specifies an LED that turns on while camera waits for USB remote to sync
// TODO for sx730
//    #define CAM_REMOTE_HDMI_HPD                 1 // Camera supports using HDMI hotplug detect for remote signal
//    #define CAM_REMOTE_HDMI_POWER_OVERRIDE      1 // Camera requires HDMI power to be forced on in rec mode
//    #define CAM_REMOTE_AtoD_CHANNEL             3 // Camera supports using 3rd battery terminal as well as USB for remote - value = A/D channel to poll
    // sx710 - Open circuit = ~4090, 10k ohm = ~1380?, 3.5k = ~600 (56C as bat temp)
//    #undef CAM_REMOTE_AtoD_THRESHOLD
//    #define CAM_REMOTE_AtoD_THRESHOLD       800 // 3rd battery terminal A/D reading threshold ( lower = 1, higher = 0 )
 
// camera crashes if sd override used in AF
//    #define CAM_SD_OVER_IN_AF                   1
    #define CAM_SD_OVER_IN_AFL                  1
    #define CAM_SD_OVER_IN_MF                   1
 
// AF led, for MD test code
    #undef CAM_AF_LED
    #define CAM_AF_LED                      1

//--------------------------------------------------
