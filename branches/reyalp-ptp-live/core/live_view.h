#ifndef __LIVE_VIEW_H
#define __LIVE_VIEW_H

// Live View protocol version
#define LIVE_VIEW_VERSION_MAJOR 1  // increase only with backwards incompatible changes (and reset minor)
#define LIVE_VIEW_VERSION_MINOR 0  // increase with extensions of functionality

// Control flags for determining which data block to transfer
#define LV_TFR_CORE_DETAILS 0x80
#define LV_TFR_VIEWPORT     0x01
#define LV_TFR_BITMAP       0x04
#define LV_TFR_PALETTE      0x08

// Structure to populate with live view base info
// These details are static and only need to be retrieved once
typedef struct {
    int version_major;          // Major version number
    int version_minor;          // Minor version number
    int vp_max_width;           // Maximum viewport width (in pixels)
    int vp_max_height;          // Maximum viewport height (in pixels)
    int vp_buffer_width;        // Viewport buffer width in case buffer is wider than visible viewport (in pixels)
    int bm_max_width;           // Maximum width of bitmap (in pixels)
    int bm_max_height;          // Maximum height of bitmap (in pixels)
    int bm_buffer_width;        // Bitmap buffer width in case buffer is wider than visible bitmap (in pixels)
    int lcd_aspect_ratio;       // 0 = 4:3, 1 = 16:9
} lv_base_info;

// Structure containing the info for the current live view frame
// This information may change across calls
typedef struct {
    int vp_xoffset;             // Viewport X offset in pixels (for cameras with variable image size)
    int vp_yoffset;             // Viewport Y offset in pixels (for cameras with variable image size)
    int vp_width;               // Actual viewport width in pixels (for cameras with variable image size)
    int vp_height;              // Actual viewport height in pixels (for cameras with variable image size)
    int vp_buffer_start;        // Offset in data transferred where the viewport data starts
    int vp_buffer_size;         // Size of viewport data sent (in bytes)
    int bm_buffer_start;        // Offset in data transferred where the bitmap data starts
    int bm_buffer_size;         // Size of bitmap data sent (in bytes)
    int palette_type;           // Camera palette type 
                                // (0 = no palette, 1 = 16 x 4 byte AYUV values, 2 = 16 x 4 byte AYUV values with A = 0..3, 3 = 256 x 4 byte AYUV values with A = 0..3)
    int palette_buffer_start;   // Offset in data transferred where the palette data starts
    int palette_buffer_size;    // Size of palette data sent (in bytes)
} lv_vid_info;

enum lv_aspect_rato {
    LV_ASPECT_4_3,
    LV_ASPECT_16_9,
};

typedef struct {
    /*
    logical screen
    descibes how big the buffer would be in pixels, if it exactly filled the physical screen
    may be larger or smaller than the buffer data, due to letter boxing or unused data
    using lcd_aspect_ratio, you can create a correct representation of the screen
    */
    int logical_width;  
    int logical_height;
    /*
    buffer - describes the actual data sent
    data size is always buffer_width*buffer_height*(buffer bpp implied by type)
    offsets represent the position of the data on the logical screen,
       > 0 for sub images (16:9 on a 4:3 screen, stitch window, etc)
    */
    int buffer_width;
    // TODO will go away
    int buffer_height;

    int buffer_logical_xoffset;
    int buffer_logical_yoffset;

    /*
    visible - describes data within the buffer which contains image data to be displayed
    offsets are relative to buffer
    width must be <= logical_width - buffer_logical_xoffset and width + xoffset must be <= buffer_width 
    */
    int visible_width;
    int visible_height;

    int data_start;    // offset of data
} lv_framebuffer_desc;

typedef struct {
    int lcd_aspect_ratio; // physical aspect ratio of LCD
    int palette_type;
    int palette_data_start;
    lv_framebuffer_desc vp; // viewport
    lv_framebuffer_desc bm; // bitmap
} lv_data_header;

#ifdef CAM_CHDK_PTP
extern int live_view_data_handler(ptp_data *data, int flags, int arg2);
extern int live_view_get_data(ptp_data *data, int flags);
#endif

#endif // __LIVE_VIEW_H
