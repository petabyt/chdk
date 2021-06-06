#include "platform.h"
#include "lolevel.h"
#include "live_view.h"

extern int active_bitmap_buffer;

void vid_bitmap_refresh() {
    // https://chdk.setepontos.com/index.php?topic=12788.msg133958#msg133958
    extern void _transfer_src_overlay(int);
// works in most cases but can cause "ghosting" in auto mode when canon UI constantly updates
//  _transfer_src_overlay(active_bitmap_buffer);
    _transfer_src_overlay(0);
    _transfer_src_overlay(1);
}

void shutdown() {
//***TODO***
/*
    volatile long *p = (void*)0xC022001C;

    asm(
        "MRS     R1, CPSR\n"
        "AND     R0, R1, #0x80\n"
        "ORR     R1, R1, #0x80\n"
        "MSR     CPSR_cf, R1\n"
        :::"r1","r0"
    );

    *p = 0x44;  // power off.
*/
    while(1);
}

#define LED_PR 0xd20b0994 // green LED on the back

void debug_led(int state) {
    volatile long *p = (void*)LED_PR;
    *p = ((state) ? 0x4d0002 : 0x4c0003);
}

// Power Led = first entry in table (led 0)
// AF Assist Lamp = second entry in table (led 1)
void camera_set_led(int led, int state, __attribute__ ((unused))int bright) {
    static char led_table[2]={0,4};
    _LEDDrive(led_table[led%sizeof(led_table)], state<=1 ? !state : state);
}

void shutdown_soft() {
    _PostLogicalEventForNotPowerType(0x1005,0); // PressOffButton
}

int get_flash_params_count(void) {
    return 0xe5; // @fc066f98 GetParameterData
}

void JogDial_CW(void) {
    _PostLogicalEventToUI(0x872, 1);    //RotateJogDialRight
}

void JogDial_CCW(void) {
    _PostLogicalEventToUI(0x873, 1);    //RotateJogDialLeft
}

// updated by using function in capt_seq, valid between shot start and raw hook end
extern  char*   current_raw_addr;
char *hook_raw_image_addr()
{
    if(current_raw_addr) {
        return current_raw_addr;
    }
    // TODO fallback if current_raw_addr not set. Would be better to fail, but calling code doesn't check
    return  (char *)0x41574352; // CRAW BUF = *fc56898c
}

// TODO - camera has at least 3 raw buffers
/*
0x42f69e00
0x44da0100
0x46bd6400
*/
/*
char *hook_alt_raw_image_addr()
{
    return raw_buffers[((active_raw_buffer&1)^1)];
}
*/

void *vid_get_viewport_fb() {
    return (void*)0x42cafe00; // "first" viewport adr, "VRAM Address  : %p", contains d6 uyvy
}
/*
playback viewport
*/
void *vid_get_viewport_fb_d()    {
    // based on suggestion from 62ndidiot in https://chdk.setepontos.com/index.php?topic=12532.msg129914#msg129914
    extern void *current_fb_d;
    return current_fb_d;
}

extern void* viewport_buffers[];
/*
four viewport buffers @0xfc5befd8
0x42cafe00
0x42d5e600
0x42e0ce00
0x42ebb600
*/

extern void *current_viewport_buffer;
void *vid_get_viewport_live_fb()
{
// current_viewport_buffer assummed not most recent, like g7x
    int i;
    for(i=0;i<4;i++) {
        if(current_viewport_buffer == viewport_buffers[i]) {
            return viewport_buffers[(i+1)&3];
        }
    }
    return 0;
}

// track viewport size changes with display type
// only different from bitmap for HDMI out, playback only, probably pointless
static int vp_full_width = 640;
static int vp_full_buf_width = 640;
static int vp_full_height = 480;

int vid_get_viewport_width() {
    extern int _GetVRAMHPixelsSize();
    if (camera_info.state.mode_play)
    {
        return vp_full_width;
    }
// TODO: currently using actual width rather than half width used on pre d6
// pixel format is uyvy (16bpp)
    return _GetVRAMHPixelsSize();
}

long vid_get_viewport_height() {
    extern int _GetVRAMVPixelsSize();
    if (camera_info.state.mode_play)
    {
        return vp_full_height;
    }
// TODO: currently using actual height rather than 240 used on pre d6
    return _GetVRAMVPixelsSize();
}

int vid_get_viewport_yoffset() {
    // this seems to be always 0, buffer always begins with actual display data (widescreen or not)
    return 0;
}
// TODO
// 0 = 4:3, 1 = 16:9, 2 = 3:2, 3 = 1:1
static long vp_xo[4] = { 0, 0, 0, 80 };				// should all be even values for edge overlay

int vid_get_viewport_display_xoffset() {
    if (camera_info.state.mode_play)
    {
        return 0;
    }
    // video, ignore still res propcase
    if(camera_info.state.mode_video || is_video_recording()) {
        return 0; //neither 4:3 nor 16:9 video have x offset
    }
    return vp_xo[shooting_get_prop(PROPCASE_ASPECT_RATIO)];
}

// 0 = 4:3, 1 = 16:9, 2 = 3:2, 3 = 1:1
static long vp_yo[4] = { 0, 60, 28, 0 };

int vid_get_viewport_display_yoffset() {
    if (camera_info.state.mode_play)
    {
        return 0;
    }
    // video, ignore still res propcase
    if(camera_info.state.mode_video || is_video_recording()) {
        if(shooting_get_prop(PROPCASE_VIDEO_RESOLUTION) == 2) {
            return 0; // 4:3 video, no Y offset
        } else {
            return 60; // 16:9 video
        }
    }
    return vp_yo[shooting_get_prop(PROPCASE_ASPECT_RATIO)];
}

extern char* bitmap_buffer[];

void *vid_get_bitmap_fb() {
    return (void *)0x5ff02e00; // from sub_fc1632ba, alt 5fe05c00, based on searching for "BmpDDev.c" similar to g7x
}

int vid_get_viewport_byte_width() {
    return vp_full_buf_width*2;
}

// Functions for PTP Live View system
int vid_get_viewport_display_xoffset_proper()   { return vid_get_viewport_display_xoffset(); }
int vid_get_viewport_display_yoffset_proper()   { return vid_get_viewport_display_yoffset(); }
int vid_get_viewport_fullscreen_width()         { return vp_full_width; }
int vid_get_viewport_fullscreen_height()        { return vp_full_height; }
int vid_get_viewport_buffer_width_proper()      { return vp_full_buf_width; }
int vid_get_viewport_type()                     { return LV_FB_YUV8B; }

void *vid_get_bitmap_active_buffer() {
    return bitmap_buffer[active_bitmap_buffer&1];
}

// the opacity buffer defines opacity for the bitmap overlay's pixels
// fc1631ee, similar to g7x fc0f7b52, BmpDDev.c assert + switch
volatile char *opacity_buffer[2] = {(char*)0x5fd87300, (void*)0x5fd08a00};

// 0x10108 also appears to contain the active buffer
void *vid_get_opacity_active_buffer() {
    return (void *)opacity_buffer[active_bitmap_buffer&1];
}

extern int displaytype;
#define hdmi_out ((displaytype == 6) || (displaytype == 7))

// Ximr layer
typedef struct {
    unsigned char   unk1[7];
    unsigned char   scale;
    unsigned int    unk2;
    unsigned short  color_type;
    unsigned short  visibility;
    unsigned short  unk3;
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
    unsigned int    unk4;
} ximr_layer;

// Ximr context
typedef struct {
    unsigned short  unk1;
    unsigned short  width1;
    unsigned short  height1;
    unsigned short  unk2[17];
    unsigned int    output_marv_sig;
    unsigned int    output_buf;
    unsigned int    output_opacitybuf;
    unsigned int    output_color;
    int             buffer_width;
    int             buffer_height;
    unsigned int    unk3[2];
    ximr_layer      layers[8];
    unsigned int    unk4[24];
    unsigned char   denomx;
    unsigned char   numerx;
    unsigned char   denomy;
    unsigned char   numery;
    unsigned int    unk5;
    short           width;
    short           height;
    unsigned int    unk6[27];
} ximr_context;

int display_needs_refresh = 0;

// To find FW_YUV_LAYER_BUF
//   Start at the transfer_src_overlay function, then go to the last function called
//   Now find the function call just after the "MakeOsdVram.c" DebugAssert call.
//   The value is the second parameter to this function.
extern const unsigned fw_yuv_layer_buf;

#define FW_YUV_LAYER_SIZE   (960*270*2)

// Max size required
#define CB_W    480
#define CB_H    270

unsigned char* chdk_rgba;
int chdk_rgba_init = 0;
int bm_w = CB_W;
int bm_h = CB_H;

void vid_bitmap_erase()
{
    extern void _bzero(unsigned char *s, int n);
    _bzero(chdk_rgba, CB_W * bm_h * 4);
}

int last_displaytype;

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
    // Init RGBA buffer
    if (chdk_rgba_init == 0)
    {
        chdk_rgba_init = 1;
        chdk_rgba = (unsigned char*)(fw_yuv_layer_buf+FW_YUV_LAYER_SIZE);
        vid_bitmap_erase();
        // Force update
        last_displaytype = -1;
    }

    // Make sure we are updating the correct layer - skip redundant updates for HDMI out
    if (ximr->output_buf != fw_yuv_layer_buf)
    {
        // Update screen dimensions
        if (last_displaytype != displaytype)
        {
            last_displaytype = displaytype;

            if (hdmi_out) {
                bm_w = 480;
                bm_h = 270;
                vp_full_width = 1920;
                vp_full_buf_width = 1920;
                vp_full_height = 1080;
                /*lv_aspect = LV_ASPECT_16_9;*/ // TODO
            } else {
                bm_w = 360;
                bm_h = 240;
                vp_full_width = 640;
                vp_full_buf_width = 640;
                vp_full_height = 480;
            }

            camera_screen.width = bm_w;
            camera_screen.height = bm_h;
            camera_screen.buffer_width = CB_W;
            camera_screen.buffer_height = bm_h;

            // Reset OSD offset and width
            camera_screen.disp_right = camera_screen.width - 1;
            camera_screen.disp_width = camera_screen.width;

            // Update other values
            camera_screen.physical_width = camera_screen.width;
            camera_screen.size = camera_screen.width * camera_screen.height;
            camera_screen.buffer_size = camera_screen.buffer_width * camera_screen.buffer_height;

            // Values for chdkptp live view
            camera_screen.yuvbm_width = ximr->width;
            camera_screen.yuvbm_height = ximr->height;
            camera_screen.yuvbm_buffer_width = ximr->buffer_width;
            camera_screen.yuvbm_buffer_size = camera_screen.yuvbm_buffer_width * camera_screen.yuvbm_height;

            // Clear buffer if size changed
            extern void gui_set_need_redraw();
            gui_set_need_redraw();
            vid_bitmap_erase();

            // Tell CHDK UI that display needs update
            display_needs_refresh = 1;
        }

        if (ximr->layers[0].bitmap == fw_yuv_layer_buf) {
            // HDMI out sets width to 1024 - reset to 960 so our RGBA buffer is not overwritten
            ximr->layers[0].src_w = ximr->layers[0].width = 960;
            ximr->layers[0].src_h = ximr->layers[0].height = 270;
            ximr->layers[0].scale = 4;      // x2 scaling vertically for the canon yuv layer
        }

        if (chdk_rgba != 0)
        {
            // Copy canon layer
            memcpy(&ximr->layers[3], &ximr->layers[1], sizeof(ximr_layer));

            // Remove offset
            ximr->layers[3].scale = 6;      // x2 scaling in both directions
            ximr->layers[3].src_w = bm_w;
            ximr->layers[3].src_h = bm_h;
            ximr->layers[3].dst_x = 0;
            ximr->layers[3].dst_y = 0;

            // Set our buffer
            ximr->layers[3].bitmap = (unsigned int)chdk_rgba;
            ximr->layers[3].width = CB_W;
            ximr->layers[3].height = bm_h;

            // Fix for video recording - https://chdk.setepontos.com/index.php?topic=12788.msg146378#msg146378
            ximr->unk2[0] = 0x500;
        }
    }
    else
    {
        // HDMI out sets width to 1024 - reset to 960 so our RGBA buffer is not overwritten
        ximr->width = ximr->buffer_width = 960;
        ximr->height = ximr->buffer_height = 270;
        ximr->denomy = 0x6c;
    }
}

#ifdef CAM_SUPPORT_BITMAP_RES_CHANGE
/*
 * needed because bitmap buffer resolutions change when an external display is used
 * an extra screen erase doesn't seem to be needed
 */
void update_screen_dimensions() {
    // see sub_fc163142 in 101a for values
    extern int displaytype;
    static int old_displaytype = -1;

    if (old_displaytype == displaytype) {
        return;
    }
    old_displaytype = displaytype;

    switch(displaytype) {
        case 0:
        case 3:
        case 4: // normal screen
        case 5:
            // lcd
            camera_screen.width = camera_screen.physical_width = camera_screen.buffer_width = 640;
            camera_screen.height = camera_screen.buffer_height = 480;
            camera_screen.size = camera_screen.buffer_size = 640*480;
            break;
            // tv-out
        case 1: // NTSC
        case 2: // PAL
        case 8: // HDMI to non-HD display, (both NTSC and PAL)
        case 9:
        case 10:
            camera_screen.physical_width = camera_screen.width = 720;
            camera_screen.buffer_width = 736;
            camera_screen.height = camera_screen.buffer_height = 480;
            camera_screen.size = 720*480;
            camera_screen.buffer_size = 736*480;
            break;
            // hdmi, playback only
        case 6: // NTSC
        case 7: // PAL
            camera_screen.width = camera_screen.physical_width = camera_screen.buffer_width = 960;
            camera_screen.height = camera_screen.buffer_height = 540;
            camera_screen.size = camera_screen.buffer_size = 960*540;
            break;
// unknown / invalid, but in canon code. Can be set with sub_fc0f0dfa but display is garbled, unstable
        case 11:// O_o
            camera_screen.width = camera_screen.physical_width = camera_screen.buffer_width = 1024;
            camera_screen.height = camera_screen.buffer_height = 768;
            camera_screen.size = 1024*768;
            camera_screen.buffer_size = 1024*768;
            break;
        case 12:// O_o
            camera_screen.width = 900;
            camera_screen.physical_width = camera_screen.buffer_width = 928;
            camera_screen.height = camera_screen.buffer_height = 600;
            camera_screen.size = 900*600;
            camera_screen.buffer_size = 928*600;
            break;

    }
    if(hdmi_out) {
        vp_full_width = 1920;
        vp_full_buf_width = 1920;
        vp_full_height = 1080;
    } else {
        // others non LCD/TV out are unclear, but unlikely to come up in practice
        vp_full_width = camera_screen.width;
        vp_full_buf_width = camera_screen.buffer_width;
        vp_full_height = camera_screen.height;
    }
}
#endif

char *camera_jpeg_count_str()
{
    extern char jpeg_count_str[];
	return jpeg_count_str;
}
