
#include "platform.h"
#include "lolevel.h"
#include "live_view.h"
#include "levent.h"

// Dummy variable - actual zoom_status not found
int zoom_status;

extern int active_bitmap_buffer;
extern char* bitmap_buffer[];

void vid_bitmap_refresh()
{
    extern void _transfer_src_overlay(int);
    extern void _VTMLock();
    extern void _VTMUnlock();
    _VTMLock();
    int n = active_bitmap_buffer;
    _transfer_src_overlay(n^1);
    _transfer_src_overlay(n);
    _VTMUnlock();
}

void *vid_get_bitmap_fb()
{
    // For live view send YUV instead of RGBA
    return bitmap_buffer[0];
}

// the opacity buffer defines opacity for the bitmap overlay's pixels
// found near BmpDDev.c
void *opacity_buffer[2] = { (void*)0x7FC40000, (void*)0x7FB80000 };

void *vid_get_opacity_active_buffer()
{
    return opacity_buffer[active_bitmap_buffer&1];
}

char *camera_jpeg_count_str()
{
    extern char jpeg_count_str[];
    return jpeg_count_str;
}

void shutdown()
{
    debug_led(1);
    PostLogicalEventForNotPowerType(levent_id_for_name("PressPowerButton"),0);
    while(1) msleep(100);
}

#define LED_PR 0xD20801E4   // green LED on the back

void debug_led(int state)
{
    volatile long *p = (void*) LED_PR;
    *p = ((state) ? 0x24D0002 : 0x24C0003);
}

// Power Led = first entry in table (led 0)
// AF Assist Lamp = second entry in table (led 1)
void camera_set_led(int led, int state, __attribute__ ((unused))int bright) {
    static char led_table[2] = { 0, 4 };
    _LEDDrive(led_table[led % sizeof(led_table)], state <= 1 ? !state : state);
}

void shutdown_soft()
{
    _PostLogicalEventForNotPowerType(0x1005, 0);
}

int get_flash_params_count(void)
{
    return 241;
}

void JogDial_CW(void)
{
    _PostLogicalEventToUI(0x872, 1);    //RotateJogDialRight
}

void JogDial_CCW(void)
{
    _PostLogicalEventToUI(0x873, 1);    //RotateJogDialLeft
}

// updated by using function in capt_seq, valid between shot start and raw hook end
char *hook_raw_image_addr()
{
    extern char* current_raw_addr;
    return current_raw_addr;
}

char *hook_alt_raw_image_addr()
{
    extern char* current_raw_alt_addr;
    return current_raw_alt_addr;
}

extern void* _GetActiveViewportBuffer();

void *vid_get_viewport_fb_d()
{
    return _GetActiveViewportBuffer();
}

void *vid_get_viewport_fb()
{
    return _GetActiveViewportBuffer();
}

void *vid_get_viewport_live_fb()
{
    return _GetActiveViewportBuffer();
}

extern int displaytype;
#define hdmi_out ((displaytype == 6) || (displaytype == 7))

int vid_get_viewport_width() {
    if (camera_info.state.mode_play)
    {
        if (hdmi_out) return 1920;
        return 720;
    }
    extern int _GetVRAMHPixelsSize();
    return _GetVRAMHPixelsSize();
}

long vid_get_viewport_height() {
    if (camera_info.state.mode_play)
    {
        if (hdmi_out) return 1080;
        return 480;
    }
    extern int _GetVRAMVPixelsSize();
    return _GetVRAMVPixelsSize();
}

int vid_get_viewport_byte_width()
{
    return vid_get_viewport_buffer_width_proper()*2;
}

int vid_get_viewport_display_xoffset()
{
    // viewport width offset table for each image size
    // 0 = 4:3, 1 = 16:9, 2 = 3:2, 3 = 1:1
    static long vp_xo[5] = { 40, 0, 0, 120};        // should all be even values for edge overlay
    static long vp_xo_hdmi[5] = { 240, 0, 150, 420};   // should all be even values for edge overlay

    if (camera_info.state.mode_play)
    {
        return 0;
    }
    else if (camera_info.state.mode_video)
    {
        if (shooting_get_prop(PROPCASE_VIDEO_RESOLUTION) == 2)  // VGA
        {
            if (hdmi_out) return 240;
            return 40;
        }
        return 0;
    }
    else
    {
        if (hdmi_out)
            return vp_xo_hdmi[shooting_get_prop(PROPCASE_ASPECT_RATIO)];
        return vp_xo[shooting_get_prop(PROPCASE_ASPECT_RATIO)];
    }
}

int vid_get_viewport_display_yoffset()
{
    // viewport height offset table for each image size
    // 0 = 4:3, 1 = 16:9, 2 = 3:2, 3 = 1:1
    static long vp_yo[5] = { 0, 38, 0, 0 };

    if (camera_info.state.mode_play)
    {
        return 0;
    }
    else if (camera_info.state.mode_video)
    {
        if (shooting_get_prop(PROPCASE_VIDEO_RESOLUTION) == 2) // VGA
            return 0;
        return 38;
    }
    else
    {
        if (hdmi_out)
            return 0;
        return vp_yo[shooting_get_prop(PROPCASE_ASPECT_RATIO)];
    }
}

// Functions for PTP Live View system
int vid_get_viewport_display_xoffset_proper()   { return vid_get_viewport_display_xoffset(); }
int vid_get_viewport_display_yoffset_proper()   { return vid_get_viewport_display_yoffset(); }
int vid_get_viewport_fullscreen_width()         { if (hdmi_out) return 1920; else return 720; }
int vid_get_viewport_fullscreen_height()        { if (hdmi_out) return 1080; else return 480; }
int vid_get_viewport_buffer_width_proper()      { if (hdmi_out) return 1920; else return 736; }
int vid_get_viewport_type()                     { return LV_FB_YUV8B; }
int vid_get_aspect_ratio()                      { if (hdmi_out) return LV_ASPECT_16_9; else return LV_ASPECT_3_2; }

int display_needs_refresh = 0;

// Ximr layer
typedef struct {
    unsigned short  unk1[6];
    unsigned short  color_type;
    unsigned short  visibility;
    unsigned short  unk2;
    unsigned short  src_y;
    unsigned short  src_x;
    unsigned short  src_h;
    unsigned short  src_w;
    unsigned short  dst_y;
    unsigned short  dst_x;
    unsigned short  enabled;
    unsigned int    marv_sig;
    unsigned int    bitmap;
    unsigned int    opacity;
    unsigned int    color;
    unsigned int    width;
    unsigned int    height;
    unsigned int    unk3;
} ximr_layer;

// Ximr context
typedef struct {
    unsigned int    unk1[14];
    int             buffer_width;
    int             buffer_height;
    unsigned int    unk2[2];
    ximr_layer      layers[8];
    unsigned int    unk3[26];
    short           width;
    short           height;
    unsigned int    unk4[27];
} ximr_context;

/*
 * Called when Canon is updating UI, via dry_memcpy patch.
 * Sets flag for CHDK to update it's UI.
 * Also needed because bitmap buffer resolution changes when using HDMI
 * LCD = 720 x 480
 * HDMI = 960 x 540
 * TODO: This does not reset the OSD positions of things on screen
 *       If user has customised OSD layout how should this be handled?
 */
void update_ui(ximr_context* ximr)
{
    // Update screen dimensions
    if (camera_screen.buffer_width != ximr->buffer_width)
    {
        camera_screen.width = ximr->width;
        camera_screen.height = ximr->height;
        camera_screen.buffer_width = ximr->buffer_width;
        camera_screen.buffer_height = ximr->buffer_height;

        // Reset OSD offset and width
        camera_screen.disp_right = camera_screen.width - 1;
        camera_screen.disp_width = camera_screen.width;

        // Update other values
        camera_screen.physical_width = camera_screen.width;
        camera_screen.size = camera_screen.width * camera_screen.height;
        camera_screen.buffer_size = camera_screen.buffer_width * camera_screen.buffer_height;
    }

    // Tell CHDK UI that display needs update
    display_needs_refresh = 1;
}
