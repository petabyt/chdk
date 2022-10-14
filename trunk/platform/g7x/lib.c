#include "platform.h"
#include "lolevel.h"
#include "live_view.h"

extern int active_bitmap_buffer;

void vid_bitmap_refresh() {
    // clears perfectly but blinks and is asynchronous
//    extern void _displaybusyonscreen();
//    extern void _undisplaybusyonscreen();
//    _displaybusyonscreen();
//    _undisplaybusyonscreen();

    // https://chdk.setepontos.com/index.php?topic=12788.msg133958#msg133958
    extern void _transfer_src_overlay(int);
// works in most cases but can cause "ghosting" in auto mode when canon UI constantly updates
//  _transfer_src_overlay(active_bitmap_buffer);
    int n = active_bitmap_buffer;
    _transfer_src_overlay(n);
    _transfer_src_overlay(n^1);
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
    return 0xde; // @0xfc0afeb8
}

void JogDial_CW(void) {
    _PostLogicalEventToUI(0x872, 1);    //RotateJogDialRight
}

void JogDial_CCW(void) {
    _PostLogicalEventToUI(0x873, 1);    //RotateJogDialLeft
}

// old method, incorrect in many cases
extern  int     active_raw_buffer;
extern  char*   raw_buffers_canon_raw[];
extern  char*   raw_buffers_jpeg[];

// updated by using function in capt_seq, valid between shot start and raw hook end
extern  char*   current_raw_addr;

char *hook_raw_image_addr()
{
    if(current_raw_addr) {
        return current_raw_addr;
    }
    // TODO... fall back to old code.
    // Wron in many cases, but some code like benchmark assumes it get a raw buffer outside of shooting
    // observed values 0-2, 3 would index something that doesn't look like a raw fb in the jpeg case
    int i=active_raw_buffer&3;
    if(i>2) {
        i=0;
    }
    if( camera_info.state.mode_shooting == MODE_AUTO) {
        // AUTO mode (canon raw can't be enabled in AUTO)
        return (char *)0x46f04300; // TODO continuous shooting uses different buffers
    }else if(shooting_get_prop(PROPCASE_IMAGE_FORMAT) == 1) {
    // canon raw disabled - uses up to 3 raw buffers
        return raw_buffers_jpeg[i];
    } else {
        // canon raw enabled - different address, not clear if it ever uses multiple buffers
        return raw_buffers_canon_raw[i];
    }
    // TODO most scene modes seem to use different addresse(s)
}

// TODO
/*
char *hook_alt_raw_image_addr()
{
    return raw_buffers[((active_raw_buffer&1)^1)];
}
*/

void *vid_get_viewport_fb() {
    return (void*)0x43334300; // "first" viewport adr, "VRAM Address  : %p", contains d6 uyvy
// TODO sx280 values
    // Return first viewport buffer - for case when vid_get_viewport_live_fb not defined
    //return (void*)0x43115100; // uyvy buffers with signed(?) chroma components
    // return (void*)0x4b25fc00; // uyvy buffers (more than 4), pixel format compatible with earlier DIGIC uyvy
}
/*
playback viewport
binview uyvy_d6 format
TODO - 3 buffers 0x5e608000 0x5ea08000 0x5ee08000
also 0x5e208000
initially found by RAM dumping
0x5e608000 ref sub_fc1ba3f0 "ImgDDev.c"
0x5ee08000 ref DispCon_ShowColorBar and other DispCon_* functions
*/
void *vid_get_viewport_fb_d()    {
    // alternates between the 5e* buffers, but isn't correct when video selected
    // and doesn't do animated transitions
    /*
    void *p=*(void **)(0xa804);
    if(p) {
        return p;
    }
    return (void*)0x5e608000;
    */
    // based on suggestion from 62ndidiot in https://chdk.setepontos.com/index.php?topic=12532.msg129914#msg129914
    extern void *current_fb_d;
    return current_fb_d;
}

/*
live buffers
binview uyvy_d6 format
0x43334300 (from VRAM Address above)
found by RAM dumping
0x433e2b00 first plus 0xAE800, or 736*480*2=0xAC800 + 0x2000
0x43491300
0x4353fb00
buffer list pointer at 0x398b4 (0x00039878 + 0x3c)->fc612b8, via sub fc13b7f2
active index not found

lower res uyvy_old format
360x240
0x5a3adc00
0x5a3ed080
0x5a42c500
0x5a46b980
0x5a4aae00
0x5a4ea280
0x5a529700
0x5a568b80

640x426
0x5a5a8000
0x5a63e000
0x5a6d4000
0x5a76a000
0x5a800000
0x5a896000
0x5a92c000
0x5a9c2000

*/
extern void* viewport_buffers[];
extern void *current_viewport_buffer;

void *vid_get_viewport_live_fb()
{
// current_viewport_buffer doesn't seem to be most recent
    int i;
    for(i=0;i<4;i++) {
        if(current_viewport_buffer == viewport_buffers[i]) {
            return viewport_buffers[(i+1)&3];
        }
    }
    return 0;
}

// track viewport size changes with display type
static int vp_full_width = 720;
static int vp_full_buf_width = 736;
static int vp_full_height = 480;
static int lv_aspect = LV_ASPECT_3_2; // expected physical aspect ratio depends on output type

// NOTE: digic 6 currently using actual width rather than half width used on pre d6
// pixel format is uyvy (16bpp)
int vid_get_viewport_width() {
    extern int _GetVRAMHPixelsSize();
    if (camera_info.state.mode_play)
    {
        return vp_full_width;
    }
    return _GetVRAMHPixelsSize();
}

long vid_get_viewport_height() {
    extern int _GetVRAMVPixelsSize();
    if (camera_info.state.mode_play)
    {
        return vp_full_height;
    }
    return _GetVRAMVPixelsSize();
}

int vid_get_viewport_yoffset() {
    // this seems to be always 0, buffer always begins with actual display data (widescreen or not)
    return 0;
}

// should all be even values for edge overlay
static long vp_xo[3][5] = {
// 0=4:3, 1=16:9, 2=3:2, 3=1:1, 4=4:5
    {  0,     0,     0,    90,   144 }, // analog out 4:3
    {  0,     0,     0,     0,     0 }, // 16:9 dummy, only applies to playback
    { 40,     0,     0,   120,   168 }, // LCD 3x2
};

int vid_get_viewport_display_xoffset() {
    if (camera_info.state.mode_play)
    {
        return 0;
    }
    // video, ignore still res propcase
    if(camera_info.state.mode_video || is_video_recording()) {
        if(shooting_get_prop(PROPCASE_VIDEO_RESOLUTION) == 2) {
            return vp_xo[lv_aspect][0];// 4:3 video
        } else {
            return 0; // 16:9 video, no x offset
        }
    }
    return vp_xo[lv_aspect][shooting_get_prop(PROPCASE_ASPECT_RATIO)];
}

static long vp_yo[3][5] = {
// 0=4:3, 1=16:9, 2=3:2, 3=1:1, 4=4:5
    {  0,     60,    27,     0,     0 }, // analog out 4:3
    {  0,      0,     0,     0,     0 }, // 16:9 dummy, only applies to playback
    {  0,     36,     0,     0,     0 }, // LCD 3x2 0 = 4:3, 1 = 16:9, 2 = 3:2, 3 = 1:1, 4 = 4:5
};

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
            return vp_yo[lv_aspect][1];// 16:9 video
        }
    }
    return vp_yo[lv_aspect][shooting_get_prop(PROPCASE_ASPECT_RATIO)];
}

extern char* bitmap_buffer[];

void *vid_get_bitmap_fb() {
    return (void *)0x41441000; // from sub_fc0f7c21, alt 4153e200
}

int vid_get_viewport_byte_width() {
    return (vp_full_buf_width * 2);
}

// Functions for PTP Live View system
int vid_get_viewport_display_xoffset_proper()   { return vid_get_viewport_display_xoffset(); }
int vid_get_viewport_display_yoffset_proper()   { return vid_get_viewport_display_yoffset(); }
int vid_get_viewport_fullscreen_width()         { return vp_full_width; }
int vid_get_viewport_fullscreen_height()        { return vp_full_height; }
int vid_get_viewport_buffer_width_proper()      { return vp_full_buf_width; }
int vid_get_viewport_type()                     { return LV_FB_YUV8B; }
int vid_get_aspect_ratio()                      { return lv_aspect; }
void *vid_get_bitmap_active_buffer() {
    return bitmap_buffer[active_bitmap_buffer&1];
}
/*
note RGBA bitmap buffer, 640x480 on 960x480 buffer
0x42541000
0x42703000
doesn't seem to be a simple double buffer, UI shows up in first focus box shows up in second
*/

// the opacity buffer defines opacity for the bitmap overlay's pixels
// found near BmpDDev.c line 215 assert fc0f7b58
volatile char *opacity_buffer[2] = {(char*)0x4163b400, (void*)0x416b9d00};

// 0x10108 also appears to contain the active buffer
void *vid_get_opacity_active_buffer() {
    return (void *)opacity_buffer[active_bitmap_buffer&1];
}

char *camera_jpeg_count_str()
{
    extern char jpeg_count_str[];
	return jpeg_count_str;
}

extern int displaytype;
#define hdmi_out ((displaytype == 6) || (displaytype == 7))
#define hdmi_low_res (displaytype == 8)
#define analog_out ((displaytype == 1) || (displaytype == 2))

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

extern unsigned int fw_yuv_layer_buf;
#define FW_YUV_LAYER_SIZE   (960*270*2)

// Max size required
#define CB_W    480
#define CB_H    270

unsigned char* chdk_rgba = NULL;
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
 * Called when Canon is updating UI, via mzrm_sendmsg log patch.
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
        chdk_rgba = (unsigned char*)(fw_yuv_layer_buf + FW_YUV_LAYER_SIZE);
        chdk_rgba_init = 1;
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
                lv_aspect = LV_ASPECT_16_9;
            } else {
                bm_h = 240;
                // others are unclear, but unlikely to come up in practice
                vp_full_width = 720;
                vp_full_buf_width = 736;
                vp_full_height = 480;
                if(displaytype == 10) { // LCD is 3:2
                    bm_w = 360;
                    lv_aspect = LV_ASPECT_3_2;
                } else { // analog out is 4:3, low res HDMI looks correct at 4:3
                    bm_w = 320; // these modes are scaled 9/8 (640*9/8 = 720) in X direction on final output
                    lv_aspect = LV_ASPECT_4_3;
                }
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

        // g7x uses layer 0 in HDMI and layer 1 in TV out when rendering YUV buffer
        if (ximr->layers[1].bitmap == fw_yuv_layer_buf && ximr->layers[1].enabled) {
            ximr->layers[1].scale = 4;      // x2 scaling vertically for the canon yuv layer
        } else if (ximr->layers[0].bitmap == fw_yuv_layer_buf && ximr->layers[0].enabled) {
            ximr->layers[0].scale = 4;      // x2 scaling vertically for the canon yuv layer
        }

        if (chdk_rgba != 0)
        {
            // Copy canon RGB layer, assumed to be whichever of 0,1 is not the YUV layer
            if(ximr->layers[0].bitmap == fw_yuv_layer_buf && ximr->layers[0].enabled) {
                memcpy(&ximr->layers[3], &ximr->layers[1], sizeof(ximr_layer));
            } else {
                memcpy(&ximr->layers[3], &ximr->layers[0], sizeof(ximr_layer));
            }

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
    else // rendering to fw_yuv_layer_buf for TV or HDMI out
    {
        // scale and crop to half height to preserve CHDK buffer
        if(hdmi_out) {
            ximr->height = ximr->buffer_height = 270;
        } else {
            ximr->height = ximr->buffer_height = 240;
        }
        ximr->denomy = ximr->denomy/2;
    }
}
