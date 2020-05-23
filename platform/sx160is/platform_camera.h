// Camera - SX160IS - platform_camera.h

// This file contains the various settings values specific to the SX160IS camera.
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

    #define CAM_PROPSET                                 5
    #define CAM_DRYOS                                   1
    #define CAM_DRYOS_2_3_R39                           1
    #define CAM_DRYOS_2_3_R47                           1 // Defined for cameras with DryOS version R47 or higher

    #undef  CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO
    #define CAM_BRACKETING                              1
    #define CAM_HAS_JOGDIAL                             1

    #define CAM_ADJUSTABLE_ALT_BUTTON                   1
    #define CAM_ALT_BUTTON_NAMES                        { "Playback", "Video", "Display" }
    #define CAM_ALT_BUTTON_OPTIONS                      { KEY_PLAYBACK, KEY_VIDEO, KEY_DISPLAY }

    // pattern
    #define cam_CFAPattern                              0x01000201 // Green  Blue  Red  Green
    // color
    #define CAM_COLORMATRIX1                               \
      1301431, 1000000,  -469837, 1000000, -102652, 1000000, \
      -200195, 1000000,   961551, 1000000,  238645, 1000000, \
       -16441, 1000000,   142319, 1000000,  375979, 1000000
    #define cam_CalibrationIlluminant1                  1 // Daylight
 
    // Sensor size, DNG image size & cropping
    #define CAM_RAW_ROWPIX                            4704 // Found @0xff95b0b8 sx160is 100a
    #define CAM_RAW_ROWS                              3504 // Found @0xff95b0c4 sx160is 100a

    #undef  CAM_UNCACHED_BIT
    #define CAM_UNCACHED_BIT                    0x40000000 // Found @0xff82ec94 sx160is 100a

    #define CAM_JPEG_WIDTH                            4608
    #define CAM_JPEG_HEIGHT                           3456
    #define CAM_ACTIVE_AREA_X1                          12
    #define CAM_ACTIVE_AREA_Y1                          10
    #define CAM_ACTIVE_AREA_X2                        4668
    #define CAM_ACTIVE_AREA_Y2                        3490

    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL                   12

    #define CAM_DNG_LENS_INFO                           { 50,10, 800,10, 35,10, 59,10 } // See comments in camera.h

    #define CAM_QUALITY_OVERRIDE                        1

    #define CAM_HAS_VIDEO_BUTTON                        1
    #define CAM_VIDEO_QUALITY_ONLY                      1
    #undef  CAM_VIDEO_CONTROL
    #define CAM_HAS_MOVIE_DIGEST_MODE                   1   //Camera doesn't actually have MOVIE_DIGEST_MOVIE, but this is required by is_video_recording.
                                                            //See http://chdk.setepontos.com/index.php?topic=9986.msg118892#msg118892
    #define CAM_DISABLE_RAW_IN_LOW_LIGHT_MODE           1   // Binned mode, no valid raw data

    #define CAM_AV_OVERRIDE_IRIS_FIX            1  // for cameras that require _MoveIrisWithAv function to override Av (for bracketing).

    #undef  CAM_USES_ASPECT_CORRECTION
    #define CAM_USES_ASPECT_CORRECTION                  1
    #undef  CAM_BITMAP_WIDTH
    #define CAM_BITMAP_WIDTH                          960 // Actual width of bitmap screen in bytes (may be larger than displayed area)
    #undef  CAM_BITMAP_HEIGHT
    #define CAM_BITMAP_HEIGHT                         270 // Actual height of bitmap screen in rows (240 or 270)
    #define DRAW_ON_ACTIVE_BITMAP_BUFFER_ONLY           1   // Draw pixels on active bitmap buffer only.

    #define CAM_HAS_FILEWRITETASK_HOOK                  1
    #define CAM_FILEWRITETASK_SEEKS                     1

    #define CAM_ZEBRA_NOBUF                             1

    #define PARAM_CAMERA_NAME                           4 // parameter number for GetParameterData

    #define CAM_LOAD_CUSTOM_COLORS                      1 // Enable loading CHDK colors into the camera palette memory/hardware

    #define CAM_DATE_FOLDER_NAMING                  0x400

    #define CAM_DRIVE_MODE_FROM_TIMER_MODE              1 // use PROPCASE_TIMER_MODE to check for multiple shot custom timer.
                                                          // Used to enabled bracketing in custom timer, required on many recent cameras
                                                          // see http://chdk.setepontos.com/index.php/topic,3994.405.html

    #undef  CAM_USE_ZOOM_FOR_MF
    #define CAM_NEED_SET_ZOOM_DELAY                   300 // Define to add a delay after setting the zoom position

    #undef  CAM_USB_EVENTID
    #define CAM_USB_EVENTID                         0x202 // Levent ID for USB control. Changed in DryOS R49 so needs to be overridable.

//  define REMOTE_SYNC_STATUS_LED              0xC0220120 // specifies an LED that turns on while camera waits for USB remote to sync
    #define CAM_REMOTE_HDMI_HPD                 1 // Camera supports using HDMI hotplug detect for remote signal
    #define CAM_REMOTE_HDMI_POWER_OVERRIDE      1 // Camera requires HDMI power to be forced on in rec mode
    #define CAM_REMOTE_ANALOG_AV                1 // Camera supports analog AV detect for remote signal

    #undef CAM_AF_LED
    #define CAM_AF_LED                                  1

    #define MKDIR_RETURN_ONE_ON_SUCCESS                 1 // mkdir() return 1 on success, 0 on fail.

    #define CAM_SD_OVER_IN_AF                           1
    #define CAM_SD_OVER_IN_MF                           1

    #define CAM_IS_VID_REC_WORKS                        1   // is_video_recording() function works    

//--------------------------------------------------
