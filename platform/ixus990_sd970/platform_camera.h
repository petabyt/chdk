// Camera - ixus990_sd970 - platform_camera.h

// This file contains the various settings values specific to the ixus990_sd970 camera.
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

    #define CAM_RAW_ROWPIX                  4080    // sd970: 12 MP 12bpp
    #define CAM_RAW_ROWS                    3048    // sd970: found RAW #s by searching " CrwAddress %lx, CrwSize H %ld V %ld\r"
    #undef  CAM_CIRCLE_OF_CONFUSION
    #define CAM_CIRCLE_OF_CONFUSION         6       // CoC value for camera/sensor (see http://www.dofmaster.com/digital_coc.html)

    #undef  CAM_USE_ZOOM_FOR_MF
    #undef  CAM_HAS_ERASE_BUTTON
    #define CAM_MULTIPART                   1
    #undef  CAM_HAS_IRIS_DIAPHRAGM
    #define CAM_HAS_ND_FILTER               1

    #define CAM_SHOW_OSD_IN_SHOOT_MENU      1

    #undef  CAM_VIDEO_CONTROL
    #define CAM_VIDEO_QUALITY_ONLY          1

    #undef  CAM_UNCACHED_BIT
    #define CAM_UNCACHED_BIT                0x40000000 // sd970: Found @0xff8274e8

    #define CAM_LOAD_CUSTOM_COLORS          1          // Enable loading CHDK colors into the camera palette memory/hardware

    #define CAM_HAS_JOGDIAL                 1
    #define CAM_QUALITY_OVERRIDE            1
    #undef  CAM_SENSOR_BITS_PER_PIXEL
    #define CAM_SENSOR_BITS_PER_PIXEL       12

    #define CAM_DNG_LENS_INFO               { 66,10, 330,10, 32,10, 57,10 } // for sd970, see comments in camera.h
    #define cam_CFAPattern                  0x02010100      // Red  Green  Green  Blue

    // sd970: is is based on actual calibration imagery
	// Computed using methods alike to what Adobe seems to use for Camera Raw/Lightroom today:
	// No longer two sets of matrices but only what used to be CAM_COLORMATRIX2 @D65
    #define cam_CalibrationIlluminant1      21      // D65 can be implemented with continuous spectrum noon sunlight
    #define CAM_COLORMATRIX1                   \
     14100, 10000, -5098, 10000, -1455, 10000, \
     -2254, 10000, 10987, 10000,  1439, 10000, \
     -836,  10000,  1709, 10000,  3904, 10000
    #define CAM_FORWARDMATRIX1                 \
     5545,  10000,  1932, 10000,  2166, 10000, \
     2013,  10000,  7297, 10000,   690, 10000, \
     52,    10000,     3, 10000,  8196, 10000

    // cropping
    #define CAM_JPEG_WIDTH                  4000 //verified for sd970
    #define CAM_JPEG_HEIGHT                 3000 //verified for sd970
    #define CAM_ACTIVE_AREA_X1              24   //verified for sd970
    #define CAM_ACTIVE_AREA_Y1              12   //verified for sd970
    #define CAM_ACTIVE_AREA_X2              4056 //verified for sd970
    #define CAM_ACTIVE_AREA_Y2              3036 //verified for sd970
    // camera name
    #define PARAM_CAMERA_NAME               4    // sd970: Found @0xffb62f78

    #undef CAM_USES_ASPECT_CORRECTION
    #define CAM_USES_ASPECT_CORRECTION      1    //camera uses the modified graphics primitives to map screens an viewports to buffers more sized
    #undef CAM_BITMAP_WIDTH
    #undef CAM_BITMAP_HEIGHT
	
	// ##TODO## SD970
    #define CAM_BITMAP_WIDTH                960 // sd970: Actual width of bitmap screen in bytes
    #define CAM_BITMAP_HEIGHT               270 // sd970: Actual height of bitmap screen in rows
												// 0xff8cee34 on sd970 looked like 270, where does it get used?

    #define CAM_DRIVE_MODE_FROM_TIMER_MODE  1   // use PROPCASE_TIMER_MODE to check for multiple shot custom timer.
                                                // Used to enabled bracketing in custom timer, required on many recent cameras
                                                // see http://chdk.setepontos.com/index.php/topic,3994.405.html
    #define CAM_HAS_FILEWRITETASK_HOOK      1

    #define CAM_SD_OVER_IN_AF               1
    #define CAM_SD_OVER_IN_AFL              1
    #define CAM_SD_OVER_IN_MF               1

    #define CAM_IS_VID_REC_WORKS            1   // is_video_recording() function works
    #define CAM_PTP_USE_NATIVE_BUFFER       1   // use firmware buffers to avoid problems with uncached memory

    #undef CAM_AF_LED
    #define CAM_AF_LED                      4
//--------------------------------------------------
