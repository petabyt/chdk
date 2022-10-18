#include "platform.h"
#include "lolevel.h"
#include "live_view.h"

extern int active_bitmap_buffer;

void vid_bitmap_refresh()
{
    extern void transfer_src_overlay_my(int);
    int n = active_bitmap_buffer;
    transfer_src_overlay_my(n);
    transfer_src_overlay_my(n^1);
}

void shutdown()
{
    // _PostLogicalEventForNotPowerType(0x1005,0);    // Hack : Press the Off Button and wait
    // while(1) msleep(100) ;
    while(1);    
}

#define LED_PR 0xd20b0994  // G16 green LED on OVF bezel

void debug_led(int state)
{
    volatile long *p = (void*)LED_PR;
    *p = ((state) ? 0x4d0002 : 0x4c0003);
}

void camera_set_led(int led, int state, __attribute__ ((unused))int bright)
{
    static char led_table[4]={0,1,2,4};     // 0=Green OVF, 1=Orange OVF, 2=Power Switch LED, 4=Focus Assist Lamp
    _LEDDrive(led_table[led%sizeof(led_table)], state<=1 ? !state : state);
}

int get_flash_params_count(void)
{
    return 0x9a;         // @0xfc0cce24 - look for compares to #0x4000 in section with PropertyTableManagerCore.c"
}

char *camera_jpeg_count_str()
{
    extern char jpeg_count_str[];
    return jpeg_count_str;
}

void JogDial_CW(void)
{
    _PostLogicalEventToUI(0x872, 1);    //RotateJogDialRight
}

void JogDial_CCW(void) {
    _PostLogicalEventToUI(0x873, 1);    //RotateJogDialLeft
}


// ***  RAW / DNG handling ***

extern  int     active_raw_buffer;
extern  char *  raw_buffers[];
extern  char *  raw_buffers_jpeg[];

char * hook_raw_image_addr()
{
    int i=0 ;                               // AUTO mode uses just 1 buffer
    if(( camera_info.state.mode_shooting != MODE_AUTO ) &&
       ( camera_info.state.mode_shooting != MODE_HYBRID_AUTO ))
    {
        i=active_raw_buffer&3;              // indexes three buffers

        if(shooting_get_prop(PROPCASE_IMAGE_FORMAT) == 1)
        {
            return raw_buffers_jpeg[i];     // canon raw disabled
        }
    }
    return raw_buffers[i];                  // canon raw enabled or AUTO mode

    // **FIXME** scene mode addresses might not be right
}

char *hook_alt_raw_image_addr()
{
    int i=0 ;                               // AUTO mode uses just 1 buffer
    if(( camera_info.state.mode_shooting != MODE_AUTO ) &&
       ( camera_info.state.mode_shooting != MODE_HYBRID_AUTO ))
    {
        int i = (active_raw_buffer&3)-1;    // indexes three buffers
        if (i<0) i=2;

        if(shooting_get_prop(PROPCASE_IMAGE_FORMAT) == 1)
        {
            return raw_buffers_jpeg[i];     // canon raw disabled
        }
    }
    return raw_buffers[i];
}


// ***  Viewport buffer handling ***

extern void* viewport_buffers[];
extern void *current_viewport_buffer;

void *vid_get_viewport_fb_d()
{
    extern void *current_fb_d;
    return current_fb_d;             // same as sx280, sx60, g7x
}

void *vid_get_viewport_fb()          // Return first viewport buffer - for case when vid_get_viewport_live_fb not defined
{
    return viewport_buffers[0];      // ptr in fc571014: (i.e.viewport_buffer[0]) -> 0x43115100
    //return  (void *) 0x43115100;   // "first" viewport adr, found before "VRAM Address  : %p", contains d6 uyvy
}

void *vid_get_viewport_live_fb()
{
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
static int lv_aspect = LV_ASPECT_4_3;

int vid_get_viewport_width()
{
    extern int _GetVRAMHPixelsSize();
    if (camera_info.state.mode_play)
    {
      return vp_full_width;
    }
    return _GetVRAMHPixelsSize();
}

long vid_get_viewport_height()
{
    extern int _GetVRAMVPixelsSize();
    if (camera_info.state.mode_play)
    {
       return vp_full_height;
    }
    return _GetVRAMVPixelsSize();
}

static long vp_xo[5] = { 0, 0,  0,  80, 128 };// should all be even values for edge overlay
static long vp_yo[5] = { 0, 60, 28, 0,  0};

int vid_get_viewport_yoffset()
{
    return 0;       // this seems to be always 0, buffer always begins with actual display data (widescreen or not)
}

int vid_get_viewport_display_xoffset()
{
    if (camera_info.state.mode_play)
    {
        return 0;
    }
    if(camera_info.state.mode_video || is_video_recording())
    {
        return 0;
    }
    return vp_xo[shooting_get_prop(PROPCASE_ASPECT_RATIO)];
}

int vid_get_viewport_display_yoffset()
{
    if (camera_info.state.mode_play)
    {
        return 0;
    }
    if(camera_info.state.mode_video || is_video_recording())
    {
        return 0;
    }
    return (vp_yo[shooting_get_prop(PROPCASE_ASPECT_RATIO)]);
}

extern int active_bitmap_buffer;
extern char* bitmap_buffer[];

void *vid_get_bitmap_fb()
{
    return bitmap_buffer[0];
    //return (void *)0x41421000; // G16 value based on g7x port
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
int vid_get_aspect_ratio()                      { return lv_aspect; }

void *vid_get_bitmap_active_buffer()
{
    return bitmap_buffer[active_bitmap_buffer&1];
}

// the opacity buffer defines opacity for the bitmap overlay's pixels
// G16 routine @ 0xfc1b3e58 - look for vid_get_bitmap_fb value then values at 0xfc1b3e5e and  0xfc1b3e6c
volatile char *opacity_buffer[2] = { (char*)0x41718600, (void*)0x41796f00 };

void *vid_get_opacity_active_buffer()
{
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
    unsigned int    unk4[14];               // Note: different to the other cameras ported so far!
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
 * LCD = 640 x 480
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
                bm_h = 240; // HDMI final output is 540, but canon firmware scales from 480
                vp_full_width = 1920;
                vp_full_buf_width = 1920;
                vp_full_height = 1080;
                lv_aspect = LV_ASPECT_16_9;
            } else {
                bm_w = 360;
                bm_h = 240;
                vp_full_width = 640;
                vp_full_buf_width = 640;
                vp_full_height = 480;
                lv_aspect = LV_ASPECT_4_3;
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

        // g16 uses layer 1 when rendering YUV buffer
        if (ximr->layers[1].bitmap == fw_yuv_layer_buf && ximr->layers[1].enabled) {
            ximr->layers[1].scale = 4;      // x2 scaling vertically for the canon yuv layer
        }

        if (chdk_rgba != 0)
        {
            // Copy canon RGB layer
            memcpy(&ximr->layers[3], &ximr->layers[0], sizeof(ximr_layer));

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
        // scale and crop to half height to preserve CHDK buffer (values from sx710hs port)
        ximr->height = ximr->buffer_height = 240;
        ximr->denomy = 30;
    }
}
