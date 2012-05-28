#ifndef __LIVE_VIEW_H
#define __LIVE_VIEW_H

// Live View protocol version
#define LIVE_VIEW_VERSION_MAJOR 2  // increase only with backwards incompatible changes (and reset minor)
#define LIVE_VIEW_VERSION_MINOR 0  // increase with extensions of functionality

// Control flags for determining which data block to transfer
#define LV_TFR_VIEWPORT     0x01
#define LV_TFR_BITMAP       0x04
#define LV_TFR_PALETTE      0x08

enum lv_aspect_rato {
    LV_ASPECT_4_3,
    LV_ASPECT_16_9,
};

typedef struct {
    int data_start; // offset of data from start of live view header
    /*
    buffer width in pixels
    data size is always buffer_width*visible_height*(buffer bpp implied by type)
    */
    int buffer_width;
    /*
    visible size in pixels
    describes data within the buffer which contains image data to be displayed
    any offsets within buffer data are added before sending, so the top left
    pixel is always the first first byte of data.
    width must always be <= buffer_width
    if buffer_width is > width, the additional data should be skipped
    visible_height also defines the number of data rows
    */
    int visible_width;
    int visible_height;

    /*
    margins
    pixels offsets needed to replicate display position on cameras screen
    not used for any buffer offsets
    */
    int margin_left;
    int margin_top;

    int margin_right;
    int margin_bot;
} lv_framebuffer_desc;

typedef struct {
    // TODO not sure we want to put these in every frame
    int version_major;
    int version_minor;
    int lcd_aspect_ratio; // physical aspect ratio of LCD
    int palette_type;
    int palette_data_start;
    lv_framebuffer_desc vp; // viewport
    lv_framebuffer_desc bm; // bitmap
} lv_data_header;

#ifdef CAM_CHDK_PTP
extern int live_view_get_data(ptp_data *data, int flags);
#endif

#endif // __LIVE_VIEW_H
