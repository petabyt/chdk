#include "platform.h"
#include "lolevel.h"
#include "live_view.h"

extern int displaytype;
#define hdmi_1080 ((displaytype == 6) || (displaytype == 7))
#define hdmi_480 ((displaytype == 8) || (displaytype == 9))
#define lcd_480 (displaytype == 10)

void vid_bitmap_refresh() {
    if (hdmi_1080 || hdmi_480 || lcd_480) {
        extern void _transfer_src_overlay(int);
        extern int disptype_changing; // fw var set between "DispSw: Start" and "DispSw: Done"
        if (!disptype_changing) {
            _transfer_src_overlay(0);
        }
        if (!disptype_changing) {
            _transfer_src_overlay(1);
        }
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
    while(1)   _SleepTask(500);
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
//	*(int*)0xd20b0810  = 0x4d0002;	 // Orange Led = on

	_PostLogicalEventForNotPowerType(0x1005,0);
}

int get_flash_params_count(void) {
    return 0xe6; // found @ 0xfc27e6fc (101d)
}

void JogDial_CW(void) {
    _PostLogicalEventToUI(0x1134, 1);
    _PostLogicalEventToUI(0x8AF, 1);    //RotateEDialRight
    _PostLogicalEventToUI(0x1135, 1);
}

void JogDial_CCW(void) {
    _PostLogicalEventToUI(0x1134, 1);
    _PostLogicalEventToUI(0x8B0, 1);    //RotateEDialLeft
    _PostLogicalEventToUI(0x1135, 1);
}

extern  int     active_raw_buffer;
extern  char*   raw_buffers[];
extern char* raw_buffers_canon_raw[];
extern char* raw_buffers_jpeg[];

char *hook_raw_image_addr()
{
    // todo: untested
    int i=active_raw_buffer&3;
    if(i>2) i=0;
    return raw_buffers[i];
}

void *vid_get_viewport_fb_d() {
    extern void *current_fb_d;
    return current_fb_d;    // method from the sx60 and g7x ports
}


extern void* viewport_buffers[];
extern void *current_viewport_buffer;
static int vph=480, vpw=720, vpbw=736, vpbh=480;
static int lv_aspect = LV_ASPECT_3_2;

void *vid_get_viewport_fb() {
    // Return first viewport buffer - for case when vid_get_viewport_live_fb not defined
    return viewport_buffers[0]; // 1st of 4 uyvy_d6 buffers
}

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

int vid_get_viewport_width() {
    extern int _GetVRAMHPixelsSize();
    if (camera_info.state.mode_play)
    {
        return vpw;
    }
// TODO: currently using actual width rather than half width used on pre d6
// pixel format is uyvy (16bpp)
    return _GetVRAMHPixelsSize();
}

long vid_get_viewport_height() {
    extern int _GetVRAMVPixelsSize();
    if (camera_info.state.mode_play)
    {
        return vph;
    }
	return _GetVRAMVPixelsSize();
}

int vid_get_viewport_yoffset() {
    // this seems to be always 0, buffer always begins with actual display data (widescreen or not)
    return 0;
}

// 0 = 4:3, 1 = 16:9, 2 = 3:2, 3 = 1:1, 4 = 4:5
static long vp_xo[2][5] = {{ 40, 0, 0, 120, 168 },{ 240, 0, 150, 420, 0/*??*/ }};	// should all be even values for edge overlay

int vid_get_viewport_display_xoffset() {
    unsigned int hires = 0;
    if (camera_info.state.mode_play)
    {
        return 0;
    }
    if (hdmi_1080) {
        hires = 1;
    }
    // video, ignore still res propcase
    if(camera_info.state.mode_video || is_video_recording()) {
        if(shooting_get_prop(PROPCASE_VIDEO_RESOLUTION) == 2) {
            return hires?240:40;// 4:3 video
        } else {
            return 0; // 16:9 video, no x offset
        }
    }
    return vp_xo[hires][shooting_get_prop(PROPCASE_ASPECT_RATIO)];
}

int vid_get_viewport_display_yoffset() {
    if (camera_info.state.mode_play)
    {
        return 0;
    }
    if (hdmi_1080) {
        return 0;
    }
    // video, ignore still res propcase
    if(camera_info.state.mode_video || is_video_recording()) {
        if(shooting_get_prop(PROPCASE_VIDEO_RESOLUTION) == 2) {
            return 0; // 4:3 video, no Y offset
        } else {
            return 36; // 16:9 video
        }
    }
    if (shooting_get_prop(PROPCASE_ASPECT_RATIO) == 1)
    {
        return 36;
    }
    return 0;
}

extern int active_bitmap_buffer;
extern char* bitmap_buffer[];

int vid_get_viewport_type() {
//    if (camera_info.state.mode_play)
        return LV_FB_YUV8B;
//    return LV_FB_YUV8C;
}


void *vid_get_bitmap_fb() {
    // Return first bitmap buffer address
    return bitmap_buffer[0];
}

// Functions for PTP Live View system
int vid_get_viewport_display_xoffset_proper()   { return vid_get_viewport_display_xoffset() ; }
int vid_get_viewport_display_yoffset_proper()   { return vid_get_viewport_display_yoffset() ; }
int vid_get_viewport_buffer_width_proper()      { return vpbw ; }
int vid_get_viewport_fullscreen_width()         { return vpw; }
int vid_get_viewport_byte_width()               { return (vpbw * 2); }

int vid_get_viewport_fullscreen_height()        { return vph; }
int vid_get_aspect_ratio()                      { return lv_aspect; }



// the opacity buffer defines opacity for the bitmap overlay's pixels
volatile char *opacity_buffer[2] = {(char*)0x5FD87300, (void*)0x5FD08A00};

void *vid_get_bitmap_active_buffer() {
    return bitmap_buffer[active_bitmap_buffer&1];
}

void *vid_get_opacity_active_buffer() {
    return (void *)opacity_buffer[active_bitmap_buffer&1];
}


#ifdef CAM_SUPPORT_BITMAP_RES_CHANGE
/*
 * needed because bitmap buffer resolutions change when an external display is used
 * an extra screen erase doesn't seem to be needed
 */
void update_screen_dimensions() {
    // see sub_fc177316 in 110d for the values
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
            // ?
            camera_screen.width = camera_screen.physical_width = camera_screen.buffer_width = 640;
            camera_screen.height = camera_screen.buffer_height = 480;
            camera_screen.size = camera_screen.buffer_size = 640*480;
            break;
        case 1:
        case 2:
        case 8:
        case 9:
            // tv-out (not implemented in hw)
            camera_screen.physical_width = camera_screen.width = 720;
            camera_screen.buffer_width = 736;
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
        case 10:
            // lcd (the real one)
            camera_screen.physical_width = camera_screen.width = 720;
            camera_screen.buffer_width = 736;
            camera_screen.height = camera_screen.buffer_height = 480;
            camera_screen.size = 720*480;
            camera_screen.buffer_size = 736*480;
            break;
        case 11:
            // lcd ? (invalid, buffer would overflow)
            camera_screen.width = camera_screen.physical_width = camera_screen.buffer_width = 1024;
            camera_screen.height = camera_screen.buffer_height = 768;
            camera_screen.size = camera_screen.buffer_size = 1024*768;
            break;
        case 12:
            // lcd ? (invalid, buffer would overflow)
            camera_screen.physical_width = camera_screen.width = 900;
            camera_screen.buffer_width = 928;
            camera_screen.height = camera_screen.buffer_height = 600;
            camera_screen.size = 900*600;
            camera_screen.buffer_size = 928*600;
            break;
    }
}
#endif

char *camera_jpeg_count_str()
{
    extern char jpeg_count_str[];
    return jpeg_count_str;
}

// ximr stuff below

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
    unsigned short  unk5;
    unsigned int    unk6[9];
    unsigned int    output_buf;
    unsigned int    output_opacitybuf;
    unsigned int    output_color;
    int             buffer_width;
    int             buffer_height;
    unsigned int    unk2[2];
    ximr_layer      layers[8];
    unsigned int    unk3[24];
    unsigned char   denomx;
    unsigned char   numerx;
    unsigned char   denomy;
    unsigned char   numery;
    unsigned int    unk7;
    short           width;
    short           height;
    unsigned int    unk4[27];
} ximr_context;

int display_needs_refresh = 0;

#define FW_YUV_LAYER_BUF 0x41141000
#define FW_YUV_LAYER_SIZE (960*270*2)
#define FW_YUV_LAYER_FULLSIZE (960*270*2+960*270)
#define CHDK_LAYER_BUF (((FW_YUV_LAYER_BUF+FW_YUV_LAYER_FULLSIZE)+0xff)&0xffffff00)

unsigned char* chdk_rgba = 0;
int chdk_rgba_init = 0;
int bm_w;
int bm_h;

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
 * LCD = 720 x 480
 * HDMI = 960 x 540
 */
int ximr1, ximr2;
void update_ui(ximr_context* ximr, int msgid)
{
    // Init RGBA buffer
    if (chdk_rgba_init == 0)
    {
        chdk_rgba_init = 1;
        chdk_rgba = (unsigned char*)CHDK_LAYER_BUF;
        last_displaytype = -1;
        ximr1 = ximr2 = 0;
    }
    if (msgid == 0x25) {
        ximr1++;
    }
    else if (msgid == 0x26) {
        ximr2++;
    }

    // Make sure we are updating the correct layer - skip redundant updates for HDMI out
    if (ximr->output_buf != (unsigned int)FW_YUV_LAYER_BUF)
    {
        //_memcpy(0x40000000,ximr,0x300); // debug
        ximr->unk5 = 0x500; // trial to fix movierec overlay glitch - it works
        // Update screen dimensions
        if (last_displaytype != displaytype)
        {
            last_displaytype = displaytype;

            if (ximr->buffer_width == 0x3c0) {
                bm_w = 480;
                bm_h = 270;
            } else if (ximr->width1 == 0x280) {
                bm_w = 320;
                bm_h = 240;
            } else {
                bm_w = 360;
                bm_h = 240;
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

            // Values for chdkptp live view
            camera_screen.yuvbm_width = ximr->width;
            camera_screen.yuvbm_height = ximr->height;
            camera_screen.yuvbm_buffer_width = ximr->buffer_width;
            camera_screen.yuvbm_buffer_size = camera_screen.yuvbm_buffer_width * camera_screen.yuvbm_height;

            switch(displaytype) {
                case 0:
                case 3:
                case 4:
                case 5:
                    // ?
                    vpw = vpbw = 640;
                    vph = vpbh = 480;
                    lv_aspect = LV_ASPECT_4_3;
                    break;
                case 1:
                case 2:
                case 8:
                case 9:
                    // lo-res hdmi
                    vpw = 720;
                    vpbw = 736;
                    vph = vpbh = 480;
                    lv_aspect = LV_ASPECT_4_3;
                    break;
                case 6:
                case 7:
                    // hdmi
                    vpw = vpbw = 1920;
                    vph = vpbh = 1080;
                    lv_aspect = LV_ASPECT_16_9;
                    break;
                case 10:
                    // lcd (the real one)
                    vpw = 720;
                    vpbw = 736;
                    vph = vpbh = 480;
                    lv_aspect = LV_ASPECT_3_2;
                    break;
                case 11:
                    // lcd ? (invalid, buffer would overflow)
                    break;
                case 12:
                    // lcd ? (invalid, buffer would overflow)
                    break;
            }

            // Clear buffer if size changed
            vid_bitmap_erase();

            // Tell CHDK UI that display needs update
            display_needs_refresh = 1;
        }

        unsigned srclay = 1;

        if (ximr->layers[0].bitmap == (unsigned int)FW_YUV_LAYER_BUF) { // hdmi 1080 case
            ximr->layers[0].opacity = (unsigned int)(FW_YUV_LAYER_BUF+FW_YUV_LAYER_SIZE);
            ximr->layers[0].src_h = 270;
            ximr->layers[0].height = 270;
            ximr->layers[0].scale = 4;      // x2 scaling vertically for the canon yuv layer
        }
        else if (ximr->layers[1].bitmap == (unsigned int)FW_YUV_LAYER_BUF) { // hdmi 480 case
            ximr->layers[1].opacity = (unsigned int)(FW_YUV_LAYER_BUF+FW_YUV_LAYER_SIZE);
            ximr->layers[1].src_h = 240;
            ximr->layers[1].height = 240;
            ximr->layers[1].scale = 4;      // x2 scaling vertically for the canon yuv layer
            srclay = 0;
        }

        if (chdk_rgba != 0)
        {
            // Copy canon layer
            memcpy(&ximr->layers[3], &ximr->layers[srclay], sizeof(ximr_layer));

            // Remove offset
            ximr->layers[3].scale = 6;      // x2 scaling
            ximr->layers[3].src_w = bm_w;
            ximr->layers[3].src_h = bm_h;
            ximr->layers[3].dst_x = 0;
            ximr->layers[3].dst_y = 0;

            // Set our buffer
            ximr->layers[3].bitmap = (unsigned int)chdk_rgba;
            ximr->layers[3].width = bm_w;
            ximr->layers[3].height = bm_h;
        }
    }
    else
    {
        // _memcpy(0x40000300,ximr,0x300); // debug
        ximr->output_opacitybuf = (unsigned int)(FW_YUV_LAYER_BUF+FW_YUV_LAYER_SIZE);
        if (ximr->height == 540) {
            ximr->height = ximr->buffer_height = 270;
            ximr->denomy = 0x6c;
        }
        else if (ximr->height == 480) {
            ximr->height = ximr->buffer_height = 240;
            ximr->denomy = 0x2;
        }
    }
}
