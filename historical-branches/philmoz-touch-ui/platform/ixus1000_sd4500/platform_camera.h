// Camera - IXUS1000_SD4500 - platform_camera.h

// This file contains the various settings values specific to the IXUS1000_SD4500 camera.
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

    #define CAM_PROPSET                     4
    #define CAM_DRYOS                       1
    #define CAM_DRYOS_2_3_R39               1

    #define CAM_DATE_FOLDER_NAMING          0x400

    #define CAM_RAW_ROWPIX                  3816 // from calcs see 100C lib.c   //ASM1989
    #define CAM_RAW_ROWS                    2784 //  "     "    "    "    "  //ASM1989
    #undef  CAM_EMUL_KEYPRESS_DURATION
    #define CAM_EMUL_KEYPRESS_DURATION      100
    #define EXMEM_HEAP_SKIP                 (0x08000000-0x07D08A00)     // G12 & SX30 uses movie memory buffers at the top of the memory allocated by exmem_alloc
    #define EXMEM_BUFFER_SIZE (1024*1024*2)        // desired amount of exmem memory to allocate

    #undef  CAM_HAS_IRIS_DIAPHRAGM
    #define CAM_HAS_ND_FILTER               1

    #define CAM_ADJUSTABLE_ALT_BUTTON        1    // ALT-button can be set from menu
    #define CAM_ALT_BUTTON_NAMES             { "Video", "Playback"  }
    #define CAM_ALT_BUTTON_OPTIONS           { KEY_VIDEO, KEY_PLAYBACK }
    #undef  CAM_HAS_DISP_BUTTON

    //ASM1989 TESTING VIDEO HANG
    #undef  CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO
    //#define CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO 1

    #define CAM_HAS_VIDEO_BUTTON            1
    #define CAM_VIDEO_QUALITY_ONLY          1
    #undef  CAM_VIDEO_CONTROL
    #define CAM_MULTIPART                   1
    #define CAM_HAS_JOGDIAL                 1
    #undef  CAM_USE_ZOOM_FOR_MF

    #undef  CAM_UNCACHED_BIT
    #define CAM_UNCACHED_BIT                0x40000000

    #define CAM_DNG_LENS_INFO               { 63,10, 630,10, 34,10, 56,10 } // See comments in camera.h

    #define cam_CFAPattern                  0x01020001 // Green Red Blue Green (http://chdk.setepontos.com/index.php?board=29.0)

   #define CAM_COLORMATRIX1                     \
      12194, 10000, -3534, 10000, -1846, 10000, \
       -117, 10000,  5518, 10000,   374, 10000, \
        997, 10000,  1261, 10000,  3258, 10000

    #define cam_CalibrationIlluminant1      1        // Daylight

    #define CAM_JPEG_WIDTH                  3648
    #define CAM_JPEG_HEIGHT                 2736

    // The pixels just outside this area are working but dim. The pixels
    // outside (4, 4, 3816-92, 2784-0) are black.
    #define CAM_ACTIVE_AREA_X1              32
    #define CAM_ACTIVE_AREA_Y1              24
    #define CAM_ACTIVE_AREA_X2              3816-120
    #define CAM_ACTIVE_AREA_Y2              2784-20

    // camera name
    #define PARAM_CAMERA_NAME               4 // parameter number for GetParameterData
    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL       12

    #undef  CAM_HAS_ERASE_BUTTON
    #define CAM_SHOW_OSD_IN_SHOOT_MENU      1

    #undef  CAM_SCREEN_WIDTH
    #undef  CAM_BITMAP_WIDTH
    #undef  CAM_BITMAP_HEIGHT
    #define CAM_SCREEN_WIDTH                480 // Width of bitmap screen in CHDK co-ordinates
    #define CAM_BITMAP_WIDTH                960 // Actual width of bitmap screen in bytes
    #define CAM_BITMAP_HEIGHT               270 // Actual height of bitmap screen in rows

    #undef  CAM_USES_ASPECT_CORRECTION
    #define CAM_USES_ASPECT_CORRECTION      1   //camera uses the modified graphics primitives to map screens an viewports to buffers more sized

    #undef  EDGE_HMARGIN
    #define EDGE_HMARGIN                    10  //10 fits video mode of sx210

   //zebra letterbox for saving memory
    #define CAM_ZEBRA_NOBUF                 1

    #define CAM_QUALITY_OVERRIDE            1
    #define CAM_AF_SCAN_DURING_VIDEO_RECORD 1

    #define CAM_HAS_CMOS                    1

    #define DRAW_ON_ACTIVE_BITMAP_BUFFER_ONLY 1   // Draw pixels on active bitmap buffer only.
    #define CAM_HAS_FILEWRITETASK_HOOK      1

// FOR TESTING PURPOSE
// push all regs except SP and PC
// push CPSR via R0
// restore value for R0 from stack
#define ASM_SAFE_ENTER \
    "STMFD SP!, {R0-R12,LR}\n" \
    "MRS R0, CPSR\n" \
    "STR R0,[SP,#-4]!\n" \
    "LDR R0,[SP,#4]\n"

// pop CPSR via R0
// pop all regs except SP and PC
#define ASM_SAFE_LEAVE \
    "LDR R0,[SP],#4\n" \
    "MSR CPSR_cxsf,R0\n" \
    "LDMFD SP!, {R0-R12,LR}\n"

#define ASM_SAFE(asmcode) \
    ASM_SAFE_ENTER \
    asmcode \
    ASM_SAFE_LEAVE

//    #define REMOTE_SYNC_STATUS_LED     0xC0xxyyyy        // specifies an LED that turns on while camera waits for USB remote to sync

    #define CAM_SD_OVER_IN_AFL              1
    #define CAM_SD_OVER_IN_MF               1

//--------------------------------------------------
