// Camera - g9 - platform_camera.h

// This file contains the various settings values specific to the g9 camera.
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

    #define CAM_PROPSET                     2
    #define CAM_DRYOS                       1

    #define CAM_RAW_ROWPIX                  4104   // for 12 MP
    #define CAM_RAW_ROWS                    3048   // for 12 MP

    #undef  CAM_CIRCLE_OF_CONFUSION
    #define CAM_CIRCLE_OF_CONFUSION         6   // CoC value for camera/sensor (see http://www.dofmaster.com/digital_coc.html)

    #define CAM_HAS_ND_FILTER               1
    #define CAM_HAS_NATIVE_ND_FILTER        1   // Camera has built-in ND filter with Canon menu support for enable/disable
    #define CAM_HAS_HI_ISO_AUTO_MODE        1
    #define CAM_ADJUSTABLE_ALT_BUTTON       1
    #define CAM_ALT_BUTTON_NAMES            { "Print", "FE" }
    #define CAM_ALT_BUTTON_OPTIONS          { KEY_PRINT, KEY_MICROPHONE }
    #undef  CAM_EMUL_KEYPRESS_DURATION
    #define CAM_EMUL_KEYPRESS_DURATION  10
    #define CAM_AF_SCAN_DURING_VIDEO_RECORD 1
    #define CAM_HAS_JOGDIAL                 1
    #define CAM_BRACKETING                  1
    #define CAM_MULTIPART                   1

    // camera name
    #define PARAM_CAMERA_NAME               4       // parameter number for GetParameterData

    #define CAM_DNG_LENS_INFO               { 74,10, 444,10, 28,10, 48,10 } // See comments in camera.h
    // pattern
    #define cam_CFAPattern                  0x02010100 // Red  Green  Green  Blue

    // From Adobe DNG converter
    #define cam_CalibrationIlluminant1      17  // Standard Light A
    #define CAM_COLORMATRIX1 \
       8796, 10000,  -3770, 10000,   311, 10000, \
      -4148, 10000,  11362, 10000,  3197, 10000, \
       -598, 10000,    982, 10000,  5880, 10000
    #define cam_CalibrationIlluminant2      21  // D65
    #define CAM_COLORMATRIX2 \
       7368, 10000,  -2141, 10000,  -598, 10000, \
      -5621, 10000,  13254, 10000,  2625, 10000, \
      -1418, 10000,   1696, 10000,  5743, 10000
    #define CAM_FORWARDMATRIX1 \
       6878, 10000,  2225, 10000,   540, 10000, \
       2229, 10000,  8950, 10000, -1179, 10000, \
        989, 10000, -3091, 10000, 10353, 10000
    #define CAM_FORWARDMATRIX2 \
       6872, 10000,  3093, 10000,  -322, 10000, \
       2761, 10000,  9704, 10000, -2465, 10000, \
        614, 10000, -1539, 10000,  9176, 10000

    // cropping
    #define CAM_JPEG_WIDTH                  4000
    #define CAM_JPEG_HEIGHT                 3000
    #define CAM_ACTIVE_AREA_X1              48
    #define CAM_ACTIVE_AREA_Y1              12
    #define CAM_ACTIVE_AREA_X2              4080
    #define CAM_ACTIVE_AREA_Y2              3036

    #define CAM_HAS_FILEWRITETASK_HOOK      1

    #define REMOTE_SYNC_STATUS_LED          0xC022006C  // specifies an LED that turns on while camera waits for USB remote to sync

    #define CAM_SD_OVER_IN_AF               1
    #define CAM_SD_OVER_IN_AFL              1
    #define CAM_SD_OVER_IN_MF               1

    #define CAM_HAS_CANON_RAW               1   // has native Canon raw

//--------------------------------------------------

    #undef  CAM_DEFAULT_MENU_CURSOR_BG
    #undef  CAM_DEFAULT_MENU_CURSOR_FG
    #define CAM_DEFAULT_MENU_CURSOR_BG  IDX_COLOR_RED      // Override menu cursor colors
    #define CAM_DEFAULT_MENU_CURSOR_FG  IDX_COLOR_WHITE    // Override menu cursor colors
