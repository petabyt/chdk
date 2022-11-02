#include "platform.h"
#include "lolevel.h"
#include "live_view.h"

void vid_bitmap_refresh() {
    extern void _transfer_src_overlay(int);
    extern int disptype_changing; // fw var set between "DispSw: Start" and "DispSw: Done"
    if (!disptype_changing) {
        _transfer_src_overlay(0);
    }
    if (!disptype_changing) {
        _transfer_src_overlay(1);
    }
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
    _PostLogicalEventForNotPowerType(0x1005,0);
}

int get_flash_params_count(void) {
    return 0x91;
}

void JogDial_CW(void) {
    _PostLogicalEventToUI(0x872, 1);    //RotateJogDialRight
}

void JogDial_CCW(void) {
    _PostLogicalEventToUI(0x873, 1);    //RotateJogDialLeft
}

extern  int     active_raw_buffer;
extern  char*   raw_buffers[];

char *hook_raw_image_addr()
{
    return raw_buffers[(active_raw_buffer&1)];
}

char *hook_alt_raw_image_addr()
{
    return raw_buffers[((active_raw_buffer&1)^1)];
}

static int vph=480, vpw=640, vpbw=640, vpbh=480;
static int lv_aspect = LV_ASPECT_4_3;

/*
    Playback mode framebuffers (uyvy_d6)
    resolution according to output device (HDMI case unknown, there's space for full HD)
    0x4eb68000, 0x4ef68000, 0x4f368000
    @ 0xfc937e04 (0080364F 01000000 00000000 0080F64E 01000000 00000000 0080B64E 01000000 00000000)
    aka 0xd990 in RAM (102b)
*/
void *vid_get_viewport_fb_d() {
    extern void *current_fb_d;
    return current_fb_d;    // method from the sx60 and g7x ports
}

extern void* viewport_buffers[];
extern void *current_viewport_buffer;

void *vid_get_viewport_fb() {
    // Return first viewport buffer - for case when vid_get_viewport_live_fb not defined
    return viewport_buffers[0]; // 1st of 4 uyvy_d6 buffers
    //return (void*)0x4b25fc00; // uyvy buffers (more than 4), pixel format compatible with earlier DIGIC uyvy
}

void *vid_get_viewport_live_fb() {
    /*
    1)  4 live buffers starting @ 0x43115100, change dimensions when changing output device, uyvy_d6
        size of 1 buffer is 0xae800 bytes (not enough for HDMI 960x540, but there's no live view through HDMI anyway)
        address list @ 0xfc4d3568 (102b)
    2)  8 live buffers starting @ 0x4B25FC00, fixed 640x480, old uyvy
        size of 1 buffer is 0x96000 bytes (640*480*2)
        address list @ 0xfc4d3578, listed in reverse order (102b)
    3)  3 live buffers (probably only active when half shooting) starting @ 0x4B70FC00, 1280x960, old uyvy
        size of 1 buffer is 0x26ac00 bytes (1280x990)
        address list @ 0xfc4d35d8, listed in reverse order (102b)
    */

    // implementation is from the g7x port, including the comment

    // current_viewport_buffer doesn't seem to be most recent
    int i;
    for(i=0;i<4;i++) {
        if(current_viewport_buffer == viewport_buffers[i]) {
            return viewport_buffers[(i+1)&3];
        }
    }
    return 0;
}

int vid_get_viewport_width() {
/*
loc_fc134980: ; 4 refs (GetVRAMHPixelsSize)
fc134980:   487d        ldr r0, [pc, #500]  ; 0xfc134b78: (0002ca18) 
fc134982:   f8d0 00ac   ldr.w   r0, [r0, #172]  ; 0xac
fc134986:   4770        bx  lr
*/
    extern int _GetVRAMHPixelsSize();
// TODO: this is the actual width, pixel format is uyvy (16bpp)
    if (camera_info.state.mode_play)
        return vpbw;
    return _GetVRAMHPixelsSize();
}

long vid_get_viewport_height() {
/*
loc_fc134988: ; 3 refs (GetVRAMVPixelsSize)
fc134988:   487b        ldr r0, [pc, #492]  ; 0xfc134b78: (0002ca18) 
fc13498a:   f8d0 00b0   ldr.w   r0, [r0, #176]  ; 0xb0
fc13498e:   4770        bx  lr
*/
    extern int _GetVRAMVPixelsSize();
// return half height
    if (camera_info.state.mode_play)
        return vpbh;
    return _GetVRAMVPixelsSize();
}

static long vp_xo[5] = { 0, 0,  0,  80, 128 };// should all be even values for edge overlay
static long vp_yo[5] = { 0, 60, 28, 0,  0};

int vid_get_viewport_yoffset() {
    // this seems to be always 0, buffer always begins with actual display data (widescreen or not)
    return 0;
}

int vid_get_viewport_display_xoffset() {
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

extern int active_bitmap_buffer;
extern char* bitmap_buffer[];

void *vid_get_bitmap_fb() {
    // Return first bitmap buffer address
    return bitmap_buffer[0];
}

// Functions for PTP Live View system
int vid_get_viewport_display_xoffset_proper()   { return vid_get_viewport_display_xoffset(); }
int vid_get_viewport_display_yoffset_proper()   { return vid_get_viewport_display_yoffset(); }
int vid_get_viewport_fullscreen_height()        { return vph; } // may not be always ok
int vid_get_viewport_buffer_width_proper()      { return vpbw; } // may not be always ok
int vid_get_viewport_byte_width()               { return vpbw * 2; } // may not be always ok
int vid_get_aspect_ratio()                      { return lv_aspect; }

int vid_get_viewport_type() {
    /*
    // no longer needed, other viewports are used instead
    if (camera_info.state.mode_play)
        return LV_FB_YUV8B;
    */
    return LV_FB_YUV8B;
}

void *vid_get_bitmap_active_buffer() {
    return bitmap_buffer[active_bitmap_buffer&1];
}

// the opacity buffer defines opacity for the bitmap overlay's pixels
volatile char *opacity_buffer[2] = {(char*)0x41718600, (char*)0x41796f00};

void *vid_get_opacity_active_buffer() {
    return (void *)opacity_buffer[active_bitmap_buffer&1];
}

extern int displaytype;

#ifdef CAM_SUPPORT_BITMAP_RES_CHANGE
/*
 * needed because bitmap buffer resolutions change when an external display is used
 * an extra screen erase doesn't seem to be needed
 */
void update_screen_dimensions() {
    // see sub_fc18618a in 102b and 102c for the values
    static int old_displaytype = -1;

    if (old_displaytype == displaytype) {
        return;
    }
    old_displaytype = displaytype;

    switch(displaytype) {
        case 0:
        case 3:
        case 4:
        case 5:
            // lcd
            camera_screen.width = camera_screen.physical_width = camera_screen.buffer_width = 640;
            camera_screen.height = camera_screen.buffer_height = 480;
            camera_screen.size = camera_screen.buffer_size = 640*480;
            break;
        case 1:
        case 2:
        case 8:
        case 9:
            // tv-out
            camera_screen.width = 720;
            camera_screen.physical_width = camera_screen.buffer_width = 736;
            camera_screen.height = camera_screen.buffer_height = 480;
            camera_screen.size = 720*480;
            camera_screen.buffer_size = 736*480;
            break;
        case 6:
        case 7:
            // hdmi
            camera_screen.width = camera_screen.physical_width = camera_screen.buffer_width = 960;
            camera_screen.height = camera_screen.buffer_height = 540;
            camera_screen.size = camera_screen.buffer_size = 960*540;
            break;
    }
}
#endif


// ximr stuff below

// Ximr layer
typedef struct {
    unsigned char   unk1[8];
    unsigned char   scale;      // 1: vertical flip, 4,8: 2x hor magn, 0x10: 2x vert magn
    unsigned char   unk2[3];
    unsigned char   scale2;     // 4,8: hor flip
    unsigned char   unk3[3];
    unsigned int    unk4;
    unsigned char   shift_left;
    unsigned char   unk5;
    unsigned short  src_h;
    unsigned short  src_w;
    unsigned char   unk6;
    unsigned char   unk7;
    unsigned char   shift_right;
    unsigned char   unk8[3];
    unsigned short  enabled;
    unsigned short  unk9;
    unsigned int    marv_sig;
    unsigned int    bitmap;
    unsigned int    opacity;
    unsigned int    color;
    unsigned int    width;
    unsigned int    height;
    unsigned int    unk10;
    // those below are not needed and remain unidentified
    //unsigned short  color_type;
    //unsigned short  visibility;
    //unsigned short  src_y;
    //unsigned short  src_x;
    //unsigned short  dst_y;
    //unsigned short  dst_x;
} ximr_layer;

// Ximr context
typedef struct {
    unsigned int    unk1;
    unsigned short  width1;
    unsigned short  unk2;
    unsigned short  height1;
    unsigned short  unk3;
    unsigned int    unk4;
    unsigned int    unk5[10];
    unsigned int    marv_sig;
    unsigned int    output_buf;
    unsigned int    output_opacitybuf;
    unsigned int    output_color;
    int             buffer_width;
    int             buffer_height;
    unsigned int    unk6;
    unsigned int    unk7;
    ximr_layer      layers[8];
    unsigned int    unk8[36];
    unsigned char   denomx;
    unsigned char   unk9[3];
    unsigned char   numerx;
    unsigned char   unk10[3];
    unsigned char   denomy;
    unsigned char   unk11[3];
    unsigned char   numery;
    unsigned char   unk12[3];
    unsigned int    unk13[2];
    short           width;
    unsigned short  unk14;
    short           height;
    unsigned short  unk15;
    unsigned int    unk16[28];
} ximr_context;

int display_needs_refresh = 0;

#define FW_YUV_LAYER_BUF 0x41815800
#define FW_YUV_LAYER_SIZE (960*480*2)
#define FW_YUV_LAYER_FULLSIZE (960*480*2) // there's space between yuv buf and its opacity buf at 0x41991300 (size 633600 bytes)
#define CHDK_LAYER_BUF (((FW_YUV_LAYER_BUF+FW_YUV_LAYER_FULLSIZE)+0xff)&0xffffff00)

unsigned char* chdk_rgba = 0;
int chdk_rgba_init = 0;
int bm_w = 360;
int bm_h = 240;

void vid_bitmap_erase()
{
    extern void _memset32(unsigned char *s, int n, unsigned int pattern);
    _memset32(chdk_rgba, bm_w * bm_h * 4, 0);
}

int last_displaytype;

/*
 * Called when Canon is updating UI, via mzrm_sendmsg custom logging function.
 * Sets flag for CHDK to update its UI.
 * Also needed because bitmap buffer resolution changes when using HDMI
 * LCD = 640 x 480
 * HDMI 1080 = 960 x 480
 * TVout, HDMI 480 = 720 x 480
 */
//int ximr1;
void update_ui(ximr_context* ximr, __attribute__ ((unused))int msgid)
{
    // Init RGBA buffer
    if (chdk_rgba_init == 0)
    {
        chdk_rgba_init = 1;
        chdk_rgba = (unsigned char*)CHDK_LAYER_BUF;
        last_displaytype = -1;
//        ximr1 = 0;
    }
//    ximr1++;

    // Make sure we are updating the correct layer - skip redundant updates for firmware YUV layer
    if (ximr->output_buf != (unsigned int)FW_YUV_LAYER_BUF)
    {
//        _memcpy(0x40000000,ximr,0x378); // debug
//        int myof = *(int*)0x40001000;           // helper for ximr struct discovery
//        int myva = *(int*)0x40001004;           // helper for ximr struct discovery
//        if (myof>=0 && myof<0x378) {            // helper for ximr struct discovery
//            *((int*)ximr+(myof>>2)) |= myva;    // helper for ximr struct discovery
//        }
        ximr->unk4 = 0x500; // trial to fix movierec overlay glitch
        // Update screen dimensions
        if (last_displaytype != displaytype)
        {
            last_displaytype = displaytype;

            if (ximr->buffer_width == 960) {
                bm_w = 480;
                bm_h = 240;
                lv_aspect = LV_ASPECT_16_9;
            } else {
                bm_w = 360;
                bm_h = 240;
                lv_aspect = LV_ASPECT_4_3;
            }

            camera_screen.width = bm_w;
            camera_screen.height = bm_h;
            camera_screen.buffer_width = bm_w;
            camera_screen.buffer_height = bm_h;

            // Reset OSD offset and width
            camera_screen.disp_right = camera_screen.width - 1;
            camera_screen.disp_width = camera_screen.width;

            // Update other values
            camera_screen.physical_width = camera_screen.width;
            camera_screen.size = camera_screen.width * camera_screen.height;
            camera_screen.buffer_size = camera_screen.buffer_width * camera_screen.buffer_height;

            switch(displaytype) {
                case 0:
                case 3:
                case 4:
                case 5:
                    // lcd
                    vpw = vpbw = 640;
                    vph = vpbh = 480;
                    break;
                case 1:
                case 2:
                case 8:
                case 9:
                    // tv-out
                    vpw = 720;
                    vpbw = 736;
                    vph = vpbh = 480;
                    break;
                case 6:
                case 7:
                    // hdmi
                    vpw = vpbw = 960;
                    vph = vpbh = 540;
                    break;
            }

            // Values for chdkptp live view
            camera_screen.yuvbm_width = ximr->width;
            camera_screen.yuvbm_height = ximr->height;
            camera_screen.yuvbm_buffer_width = ximr->buffer_width;
            camera_screen.yuvbm_buffer_size = camera_screen.yuvbm_buffer_width * camera_screen.yuvbm_height;

            // Clear buffer if size changed
            vid_bitmap_erase();

            // Tell CHDK UI that display needs update
            display_needs_refresh = 1;
        }

        if (chdk_rgba != 0)
        {
            // Copy canon layer
            memcpy(&ximr->layers[3], &ximr->layers[0], sizeof(ximr_layer));

            // Remove offset
            ximr->layers[3].scale = 0x18;      // x2 scaling
            ximr->layers[3].src_w = bm_w;
            ximr->layers[3].src_h = bm_h;

            // Set our buffer
            ximr->layers[3].bitmap = (unsigned int)chdk_rgba;
            ximr->layers[3].width = bm_w;
            ximr->layers[3].height = bm_h;
        }
    }
    else
    {
//         _memcpy(0x40000400,ximr,0x378); // debug
    }
}

