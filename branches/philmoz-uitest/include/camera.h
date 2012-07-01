// camera.h

// This file contains the default values for various settings that may change across camera models.
// Setting values specific to each camera model can be found in the platform/XXX/platform_camera.h file for camera.

// If adding a new settings value put a suitable default value in here, along with documentation on
// what the setting does and how to determine the correct value.
// If the setting should not have a default value then add it here using the '#undef' directive
// along with appropriate documentation.

#ifndef CAMERA_H
#define CAMERA_H

//==========================================================
// Camera-dependent settings
//==========================================================

//----------------------------------------------------------
// Default values
//----------------------------------------------------------

    #undef  CAM_DRYOS                           // Camera is DryOS-based
    #undef  CAM_PROPSET                         // Camera's properties group (the generation)
    #undef  CAM_DRYOS_2_3_R31                   // Define for cameras with DryOS release R31 or greater -> G10
    #undef  CAM_DRYOS_2_3_R39                   // Define for cameras with DryOS release R39 or greater
    #undef  CAM_DRYOS_2_3_R47                   // Define for cameras with DryOS release R47 or greater -> Cameras can boot from FAT32

    #undef  CAM_HAS_CMOS                        // Camera has CMOS sensor
    #undef  CAM_SWIVEL_SCREEN                   // Camera has rotated LCD screen
    #define CAM_USE_ZOOM_FOR_MF             1   // Zoom lever can be used for manual focus adjustments
    #undef  CAM_ADJUSTABLE_ALT_BUTTON           // ALT-button can be set from menu
    #define CAM_REMOTE                      1   // Camera supports USB-remote
    #undef  SYNCHABLE_REMOTE_NOT_ENABLED        // Disable support for synchable remote switch (in kbd.c) TODO only used by one camera ???
    #define CAM_SYNCH                       1   // Camera supports SDM precision synch
    #undef  CAM_MULTIPART                       // Camera supports SD-card multipartitioning
    #define CAM_HAS_ZOOM_LEVER              1   // Camera has dedicated zoom buttons
    #undef  CAM_DRAW_EXPOSITION                 // Output expo-pair on screen (for cameras which (sometimes) don't do that)
    #define CAM_HAS_ERASE_BUTTON            1   // Camera has dedicated erase button
    #define CAM_HAS_IRIS_DIAPHRAGM          1   // Camera has real diaphragm mechanism (http://en.wikipedia.org/wiki/Diaphragm_%28optics%29)
    #undef  CAM_HAS_ND_FILTER                   // Camera has build-in ND filter
    #undef  CAM_HAS_NATIVE_ND_FILTER            // Camera has built-in ND filter with Canon menu support for enable/disable
    #define CAM_CAN_SD_OVER_NOT_IN_MF       1   // Camera allows subject distance (focus) override when not in manual focus mode
    #undef  CAM_CAN_SD_OVER_IN_AF_LOCK          // Camera allows subject distance (focus) override when in AF Lock mode
    #define CAM_CAN_SD_OVERRIDE             1   // Camera allows to do subject distance override
    #define CAM_HAS_MANUAL_FOCUS            1   // Camera has manual focus mode
    #define CAM_HAS_USER_TV_MODES           1   // Camera has tv-priority or manual modes with ability to set tv value
    #undef  CAM_SHOW_OSD_IN_SHOOT_MENU          // On some cameras Canon shoot menu has additional functionality and useful in this case to see CHDK OSD in this mode
    #define CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO 1 // Camera can unlock optical zoom in video (if it is locked)
    #undef  CAM_FEATURE_FEATHER                 // Cameras with "feather" or touch wheel.
    #define CAM_HAS_IS                      1   // Camera has image stabilizer
    #undef  CAM_HAS_JOGDIAL                     // Camera has a "jog dial"

    #undef  CAM_CONSOLE_LOG_ENABLED             // Development: internal camera stdout -> A/stdout.txt
    #define CAM_CHDK_HAS_EXT_VIDEO_MENU     1   // In CHDK for this camera realized adjustable video compression
    #undef  CAM_CAN_MUTE_MICROPHONE             // Camera has function to mute microphone

    #define CAM_EMUL_KEYPRESS_DELAY         40  // Delay to interpret <alt>-button press as longpress
    #define CAM_EMUL_KEYPRESS_DURATION      5   // Length of keypress emulation

    #define CAM_MENU_BORDERWIDTH            30  // Defines the width of the border on each side of the CHDK menu. The CHDK menu will have this
                                                // many pixels left blank to the on each side. Should not be less than 10 to allow room for the
                                                // scroll bar on the right.
    #define CAM_DETECT_SCREEN_ERASE         1   // Define this to add 'guard' pixel to the screen bitmap to help detect if the firmware has erase the screen
                                                // If the guard pixel changes the CHDK ALT menu is forced to redraw.
                                                // Take care not to place CHDK OSD elements over the guard pixel.
                                                // The guard pixel is the first pixel of the top row in the screen bitmap.

    #undef  CAM_TOUCHSCREEN_UI                  // Define to enable touch screen U/I (e.g. IXUS 310 HS)
    #define CAM_TS_BUTTON_BORDER            0   // Define this to leave a border on each side of the OSD display for touch screen buttons.
                                                // Used on the IXUS 310 to stop the OSD from overlapping the on screen buttons on each side
    #define CAM_DISP_ALT_TEXT               1   // Display the '<ALT>' message at the bottom of the screen in ALT mode (IXUS 310 changes button color instead)

    #undef  CAM_AF_SCAN_DURING_VIDEO_RECORD     // CHDK can make single AF scan during video record
    #undef  CAM_HAS_VIDEO_BUTTON                // Camera can take stills in video mode, and vice versa
    #undef  CAM_EV_IN_VIDEO                     // CHDK can change exposure in video mode
    #define CAM_VIDEO_CONTROL               1   // pause / unpause video recordings
    #undef  CAM_VIDEO_QUALITY_ONLY              // Override Video Bitrate is not supported
    #undef  CAM_CHDK_HAS_EXT_VIDEO_TIME         // Camera can override time limit of video record -> sx220/230
    #undef  CAM_HAS_MOVIE_DIGEST_MODE           // The values in the 'movie_status' variable change if the camera has this mode (see is_video_recording())

    #define ZOOM_OVERRIDE                   0   // Shall zoom-override be used? default 0 becoz not implemented right now

    #undef  CAM_REAR_CURTAIN                    // Camera do not have front/rear curtain flash sync in menu
    #undef  CAM_BRACKETING                      // Cameras that have bracketing (focus & ev) in original firmware already, most likely s- & g-series (propcase for digic III not found yet!)
    #undef  CAM_EXT_TV_RANGE                    // CHDK can make exposure time longer than 64s
    #define CAM_CHDK_PTP                    1   // include CHDK PTP support

    #define CAM_UNCACHED_BIT                0x10000000 // bit indicating the uncached memory

    #define CAM_MAKE                        "Canon"
    #define CAM_SENSOR_BITS_PER_PIXEL       10  // Bits per pixel. 10 is standard, 12 is supported except for curves
    #define CAM_WHITE_LEVEL                 ((1<<CAM_SENSOR_BITS_PER_PIXEL)-1)      // 10bpp = 1023 ((1<<10)-1), 12bpp = 4095 ((1<<12)-1)
    #define CAM_BLACK_LEVEL                 ((1<<(CAM_SENSOR_BITS_PER_PIXEL-5))-1)  // 10bpp = 31 ((1<<5)-1),    12bpp = 127 ((1<<7)-1)

    #define CAM_BITMAP_PALETTE              1   // which color set is used for this camera

    #undef  CAM_HAS_VARIABLE_ASPECT             // can switch between 16:9 and 4:3

    // Older cameras had a screen/bitmap buffer that was 360 pixels wide (or 480 for wide screen models)
    // CHDK was built around this 360 pixel wide display model
    // Newer cameras have a 720 pixel wide bitmap (960 for wide screen cameras)
    // To accomadate this the CHDK co-ordinate system assumes a 360/480 wide buffer and the
    // pixel drawing routines draw every pixel twice to scale the image up to the actual buffer size
    // Define CAM_USES_ASPECT_CORRECTION with a value of 1 to enable this scaled display
    #define CAM_USES_ASPECT_CORRECTION      0
    #define CAM_SCREEN_WIDTH                360 // Width of bitmap screen in CHDK co-ordinates (360 or 480)
    #define CAM_SCREEN_HEIGHT               240 // Height of bitmap screen in CHDK co-ordinates (always 240 on all cameras so far)
    #define CAM_BITMAP_WIDTH                360 // Actual width of bitmap screen in bytes (may be larger than displayed area)
    #define CAM_BITMAP_HEIGHT               240 // Actual height of bitmap screen in rows (240 or 270)

    #define EDGE_HMARGIN                    0   // define sup and inf screen margins on edge overlay without overlay.  Necessary to save memory buffer space. sx200is needs values other than 0

    #undef CAM_QUALITY_OVERRIDE                 // define this in platform_camera.h to enable 'Super Fine' JPEG compression mode
                                                // used to allow super fine JPEG option on cameras where this has been removed
                                                // from the Canon menu. Note: may not actually work on all cameras.

    #undef  CAM_ZEBRA_ASPECT_ADJUST             // zebra needs to account for real bitmap size being different from what lib.c reports
                                                // also used by some cameras with normal bitmap layouts for memory saving ?
    #undef  CAM_ZEBRA_NOBUF                     // zebra draws directly on bitmap buffer. Requires above as well
    
    #undef  CAM_DATE_FOLDER_NAMING              // set if camera uses date based folder naming (Option "Create Folder" in Canon Menu) and get_target_dir_name is implemented
    
    #undef  CAM_KEY_CLICK_DELAY                 // additional delay between press and release for scripted click
    #define CAM_KEY_PRESS_DELAY             20  // delay after a press - TODO can we combine this with above ?
    #define CAM_KEY_RELEASE_DELAY           20  // delay after a release - TODO do we really need to wait after release ?

    #undef  CAM_STARTUP_CRASH_FILE_OPEN_FIX     // enable fix for camera intermittently crash at startup when opening the conf / font files
                                                // Some cameras throw "ASSERT!! FsIoNotify.c Line xxx    Task name: SpyTask" in ROMLOG
    
    // RAW & DNG related values
    #define DNG_SUPPORT                     1   // Camera supports DNG format for saving of RAW images
    #define DEFAULT_RAW_EXT                 1   // extension to use for raw (see raw_exts in conf.c)
    #define DNG_BADPIXEL_VALUE_LIMIT        0   // Max value of 'bad' pixel - this value or lower is considered a defective pixel on the sensor
    #undef  CAM_RAW_ROWPIX                      // Number of pixels in RAW row (physical size of the sensor Note : as of July 2011, this value can be found in stub_entry.S for dryos cameras)
    #undef  CAM_RAW_ROWS                        // Number of rows in RAW (physical size of the sensor       Note : as of July 2011, this value can be found in stub_entry.S for dryos cameras)
    #undef  CAM_JPEG_WIDTH                      // Default crop size (width) stored in DNG (to match camera JPEG size. From dimensions of the largest size jpeg your camera produces)
    #undef  CAM_JPEG_HEIGHT                     // Default crop size (height) stored in DNG (to match camera JPEG size. From dimensions of the largest size jpeg your camera produces)
    #undef  CAM_ACTIVE_AREA_X1                  // Define usable area of the sensor - needs to be divisible by 4 - calibrate using a CHDK RAW image converted with rawconvert.exe (eg :rawconvert -12to8 -pgm -w=4480 -h=3348 photo.crw photo.pgm)
    #undef  CAM_ACTIVE_AREA_Y1                  // Define usable area of the sensor - needs to be divisible by 2 - "
    #undef  CAM_ACTIVE_AREA_X2                  // Define usable area of the sensor - needs to be divisible by 4 - "
    #undef  CAM_ACTIVE_AREA_Y2                  // Define usable area of the sensor - needs to be divisible by 2 = "
    #undef  cam_CFAPattern                      // Camera Bayer sensor data layout (DNG colors are messed up if not correct)
                                                //   should be 0x01000201 = [Green Blue Red Green], 0x02010100 = [Red Green Green Blue] or 0x01020001 = [Green Red Blue Green]
    #undef  CAM_COLORMATRIX1                    // DNG color profile matrix
    #undef  cam_CalibrationIlluminant1          // DNG color profile illuminant - set it to 17 for standard light A
    #undef  CAM_COLORMATRIX2                    // DNG color profile matrix 2
    #undef  cam_CalibrationIlluminant2          // DNG color profile illuminant 2 - set it to 21 for D65
    #undef  CAM_CAMERACALIBRATION1              // DNG camera calibration matrix 1
    #undef  CAM_CAMERACALIBRATION2              // DNG camera calibration matrix 2
    #undef  CAM_FORWARDMATRIX1                  // DNG camera forward matrix 1
    #undef  CAM_FORWARDMATRIX2                  // DNG camera forward matrix 2
    #undef  CAM_DNG_EXPOSURE_BIAS               // Specify DNG exposure bias value (to override default of -0.5 in the dng.c code)
    #undef  DNG_EXT_FROM                        // Extension in the cameras known extensions to replace with .DNG to allow DNG
                                                // files to be transfered over standard PTP. Only applicable to older cameras

    #undef  CAM_DNG_LENS_INFO                   // Define this to include camera lens information in DNG files
                                                // Value should be an array of 4 DNG 'RATIONAL' values specifying
                                                //   - min focal length in mm
                                                //   - max focal length in mm
                                                //   - max aperture at min focal length
                                                //   - max aperture at max focal length
                                                // E.G - SX30 = { 43,10, 1505,10, 27,10, 58,10 }
                                                //            = 4.3 - 150.5mm, f/2.7 - f.5.8
                                                // Each pair of integers is one 'RATIONAL' value (numerator,denominator)

    #undef  PARAM_CAMERA_NAME                   // parameter number for GetParameterData to get camera name
    #undef  PARAM_OWNER_NAME                    // parameter number for GetParameterData to get owner name
    #undef  PARAM_ARTIST_NAME                   // parameter number for GetParameterData to get artist name
    #undef  PARAM_COPYRIGHT                     // parameter number for GetParameterData to get copyright
    #undef  PARAM_DISPLAY_MODE1                 // param number for LCD display mode when camera in playback
    #undef  PARAM_DISPLAY_MODE2                 // param number for LCD display mode when camera in record view hold mode
    #undef  CAM_FIRMWARE_MEMINFO                // Use 'GetMemInfo' (dryos) or 'memPartInfoGet'/'memPartFindMax' (vxworks)
                                                // function in firmware to get free memory details
                                                // GetMemInfo should be found correctly by the gensig/finsig signature
                                                // finder for all dryos based cameras.

    #undef  CAM_NO_MEMPARTINFO                  // VXWORKS camera does not have memPartInfoGet, fall back to memPartFindMax

    #undef  CAM_DRIVE_MODE_FROM_TIMER_MODE      // use PROPCASE_TIMER_MODE to check for multiple shot custom timer.
                                                // Used to enabled bracketing in custom timer, required on many recent cameras
                                                // see http://chdk.setepontos.com/index.php/topic,3994.405.html

    #undef  CAM_AV_OVERRIDE_IRIS_FIX            // for cameras that require _MoveIrisWithAv function to override Av (for bracketing).

    #undef  CAM_DISABLE_RAW_IN_LOW_LIGHT_MODE   // For cameras with 'low light' mode that does not work with raw define this
    #undef  CAM_DISABLE_RAW_IN_HQ_BURST         // For cameras with 'HQ Burst' mode that does not work with raw define this
    #undef  CAM_DISABLE_RAW_IN_HANDHELD_NIGHT_SCN // For cameras with 'HandHeld Night Scene' mode that does not work with raw define this
    #undef  CAM_ISO_LIMIT_IN_HQ_BURST           // Defines max ISO override value for HQ Burst mode (higher values crash camera)
    
    #undef  CAM_HAS_GPS                         // for cameras with GPS reseiver: includes the GPS coordinates in in DNG file

    #undef  CHDK_COLOR_BASE                     // Start color index for CHDK colors loaded into camera palette.

    #undef  CAM_LOAD_CUSTOM_COLORS              // Define to enable loading CHDK custom colors into the camera color palette
                                                // requires load_chdk_palette() and vid_get_bitmap_active_palette() to be defined
                                                // correctly for the camera along with

    #define CAM_USB_EVENTID         0x902       // Levent ID for USB control. Changed to 0x202 in DryOS R49 so needs to be overridable.

    #undef  CAM_NEED_SET_ZOOM_DELAY             // Define to add a delay after setting the zoom position before resetting the focus position in shooting_set_zoom 

    #undef  USE_REAL_AUTOISO                    // Define this to use real-iso instead of marketing-iso as values of autoiso mechanizm
    #undef  OVEREXP_COMPENSATE_OVERALL          // Define this to make overexposure_compensation work for all scenes, instead of day-light only

    #define CAMERA_MIN_DIST         0           // Define min distance that can be set in _MoveFocusLensToDistance (allow override - e.g. G12 min dist = 1)
    #define CAMERA_MAX_DIST         65535       // Define max distance that can be set in _MoveFocusLensToDistance (allow override for superzooms - SX30/SX40)

	#undef	DRAW_ON_ACTIVE_BITMAP_BUFFER_ONLY	// Draw pixels on active bitmap buffer only. Requires active_bitmap_buffer location in stubs_min.S or stubs_entry.S.
	
    #undef  CAM_ZOOM_ASSIST_BUTTON_CONTROL      // Activate menu option to enable/disable the zoom assist button on the SX30/SX40
                                                // For other cameras, requires additional support code in kbd.c (see the SX30 or SX40 version)

//----------------------------------------------------------
// Overridden values for each camera
//----------------------------------------------------------

// Include the settings file for the camera model currently being compiled.
#include "platform_camera.h"

//==========================================================
// END of Camera-dependent settings
//==========================================================

// For newer cameras where the screen bitmap is double the width we need to scale
// the CHDK horizontal (X) co-ordinates
#if CAM_USES_ASPECT_CORRECTION
    #define ASPECT_XCORRECTION(x)   ((x)<<1)    // See comments for CAM_USES_ASPECT_CORRECTION above
#else
    #define ASPECT_XCORRECTION(x)   (x)         // See comments for CAM_USES_ASPECT_CORRECTION above
#endif

// curves only work in 10bpp for now
#if CAM_SENSOR_BITS_PER_PIXEL != 10
    #undef OPT_CURVES
#endif

#ifndef OPT_PTP
    #undef CAM_CHDK_PTP
#endif

//==========================================================
// Data Structure to store camera specific information
// Used by modules to ensure module code is platform independent

typedef struct {
	int api_version;			// version of this structure

    int bits_per_pixel;
    int black_level;
    int white_level;
    int raw_rows, raw_rowpix, raw_rowlen, raw_size;
    union                       // DNG JPEG info
    {
        struct
        {
            int x, y;           // DNG JPEG top left corner
            int width, height;  // DNG JPEG size
        } jpeg;
        struct
        {
            int origin[2];
            int size[2];
        } crop;
    };
    union                       // DNG active sensor area (Y1, X1, Y2, X2)
    {
        struct
        {
            int y1, x1, y2, x2;
        } active_area;
        int dng_active_area[4];
    };
    int lens_info[8];           // DNG Lens Info
    int exposure_bias[2];       // DNG Exposure Bias
    int cfa_pattern;
    int calibration_illuminant1;
    int color_matrix1[18];      // DNG Color Matrix
    int calibration_illuminant2;
    int color_matrix2[18];      // DNG Color Matrix 2
    int has_calibration1;
    int camera_calibration1[18];// DNG Camera Calibration Matrix 1
    int has_calibration2;
    int camera_calibration2[18];// DNG Camera Calibration Matrix 2
    int has_forwardmatrix1;
    int forward_matrix1[18];    // DNG Camera Forward Matrix 1
    int has_forwardmatrix2;
    int forward_matrix2[18];    // DNG Camera Forward Matrix 1
    int dng_badpixel_value_limit;
} _cam_sensor;

extern _cam_sensor camera_sensor;

// if this struct changed, please change gui_version.common_api 
typedef struct 
{
    int    width, height, size;                        // Size of bitmap screen in CHDK co-ordinates
    int    buffer_width, buffer_height, buffer_size;   // Physical size of bitmap screen
    int    edge_hmargin, ts_button_border;             // margin and touch-screen adjustment values
    int    zebra_nobuf, zebra_aspect_adjust;           // zebra feature settings
    int    has_variable_aspect;                        // zebra feature settings
} _cam_screen;

extern _cam_screen camera_screen;

typedef struct
{
	int api_version;			// version of this structure

    // Canon PARAMS indexes
    struct
    {
        int camera_name;
        int owner_name;
        int artist_name;
        int copyright;
    } params;
    // Canon PROPCASE indexes
    struct
    {
        int gps;
        int orientation_sensor;
        int tv;
        int av;
        int min_av;
        int ev_correction_2;
        int flash_mode;
        int flash_fire;
        int metering_mode;
        int wb_adj;
        int aspect_ratio;
        int shooting;
    } props;
    int rombaseaddr, maxramaddr;
    int tick_count_offset;      // get_tick_count value at which the clock ticks over 1 second
    char* chdk_ver;
    // Miscellaneous variables to record state information
    // Used to control communication between various tasks and modules
    struct
    {
        int edge_state_draw;        // Current state of overlay (Live/Frozen/Pano)
        int is_shutter_half_press;  // State of Shutter Half Press button
    } state;
} _cam_info;

extern _cam_info camera_info;

//==========================================================

#endif /* CAMERA_H */
