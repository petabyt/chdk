#include "platform.h"
#include "lolevel.h"
#include "live_view.h"

extern int active_bitmap_buffer;
extern char* bitmap_buffer[];

extern int displaytype;
#define evf_out     (displaytype == 11)
#define hdmi_out ((displaytype == 6) || (displaytype == 7))

void vid_bitmap_refresh() {
    extern void _transfer_src_overlay(int);
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
extern char* raw_buffers_canon_raw[];
extern char* raw_buffers_jpeg[];

char *hook_raw_image_addr()
{
//    return raw_buffers[(active_raw_buffer&3)];
    // observed values 0-2, 3 would index something that doesn't look like a raw fb in the jpeg case
    int i=active_raw_buffer&3;
    if(i>2) i=0;
    return raw_buffers[i];
        // TODO most scene modes seem to use different addresse(s)
}

/* char *hook_alt_raw_image_addr()
{
    return raw_buffers[((active_raw_buffer&1)^1)];
} */

extern char active_viewport_buffer;
extern void* viewport_buffers[];

void *vid_get_viewport_fb() {
    // Return first viewport buffer - for case when vid_get_viewport_live_fb not defined
    //return (void*)0x43115100; // uyvy buffers with signed(?) chroma components
    return (void*)0x4367AF00; // 0x43A6F700 0x4b25fc00; uyvy buffers (more than 4), pixel format compatible with earlier DIGIC uyvy
}

void *vid_get_viewport_fb_d()    {
    // based on suggestion from 62ndidiot in https://chdk.setepontos.com/index.php?topic=12532.msg129914#msg129914
    extern void *current_fb_d;
    return current_fb_d;
} 

extern void* viewport_buffers[];
extern void *current_viewport_buffer;

int vid_get_aspect_ratio(){
	if (hdmi_out) {
		return LV_ASPECT_16_9;
	} else if (evf_out) {
		return LV_ASPECT_4_3;
	} else {
		return LV_ASPECT_3_2;
	}
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
//	return (void*)0x4367AF00;  	
}

int vid_get_viewport_width() {
    extern int _GetVRAMHPixelsSize();
    if (camera_info.state.mode_play)
    {
	if (hdmi_out) {
		return 1920;
	} else if (evf_out) {
		return 1024;
	} else {
		return 736;
	}

    }
// TODO: currently using actual width rather than half width used on pre d6
// pixel format is uyvy (16bpp)
    return _GetVRAMHPixelsSize();
}

long vid_get_viewport_height() {
    extern int _GetVRAMVPixelsSize();
    if (camera_info.state.mode_play)
    {
	if (hdmi_out) {
		return 1080;
	} else if (evf_out) {
		return 768;
	} else {
		return 480;
	};
    }
	return _GetVRAMVPixelsSize();
}

int vid_get_viewport_yoffset() {
    // this seems to be always 0, buffer always begins with actual display data (widescreen or not)
    return 0;
}

static long vp_xo[3][5] = {
// 0=4:3, 1=16:9, 2=3:2, 3=1:1, 4=4:5
    {  0,     0,     0,   128,     0 }, // EVF 4:3
    {240,     0,   150,   420,     0 }, // HDMI 16:9
    { 40,     0,     0,   120,     0 }, // LCD 3x2
};

int vid_get_viewport_display_xoffset() {
    if (camera_info.state.mode_play)
    {
        return 0;
    }
    // video, ignore still res propcase
    if(camera_info.state.mode_video || is_video_recording()) {
        if(shooting_get_prop(PROPCASE_VIDEO_RESOLUTION) == 2) {
			if (hdmi_out) { // 4:3 video,
				return 240;
			} else if (evf_out) {
				return 0;
			} else {
				return 40;
			};			
        } else {
            return 0; // 16:9 video, no x offset
        }
    }
    return vp_xo[vid_get_aspect_ratio()][shooting_get_prop(PROPCASE_ASPECT_RATIO)];
}

static long vp_yo[3][5] = {
// 0=4:3, 1=16:9, 2=3:2, 3=1:1, 4=4:5
    {  0,     96,    42,     0,     0 }, // EVF 4:3
    {  0,      0,     0,     0,     0 }, // HDMI 16:9
    {  0,     36,     0,     0,     0 }, // LCD 3:2
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
			if (hdmi_out) { // 16:9 video,
				return 0;
			} else if (evf_out) {
				return 96;
			} else {
				return 36;
			};            
        }
    }
    return vp_yo[vid_get_aspect_ratio()][shooting_get_prop(PROPCASE_ASPECT_RATIO)];
}

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

int vid_get_viewport_buffer_width_proper(){
	if (hdmi_out) {
		return 1920;
	} else if (evf_out) {
		return 1024;
	} else {
		return 736;
	}
}

int vid_get_viewport_fullscreen_width(){
	if (hdmi_out) {
		return 1920;
	} else if (evf_out) {
		return 1024;
	} else {
		return 720;
	}
}
int vid_get_viewport_byte_width() 		{ return (vid_get_viewport_buffer_width_proper() * 2); }

int vid_get_viewport_fullscreen_height(){
	if (hdmi_out) {
		return 1080;
	} else if (evf_out) {
		return 768;
	} else {
		return 480;
	}
}


// the opacity buffer defines opacity for the bitmap overlay's pixels
//volatile char *opacity_buffer[2] = {(char*)0x41718600, (void*)0x41796f00};
volatile char *opacity_buffer[2] = {(char*)0x41741000, (void*)0x41801000};

void *vid_get_bitmap_active_buffer() {
    return bitmap_buffer[active_bitmap_buffer&1];
}

void *vid_get_opacity_active_buffer() {
    return (void *)opacity_buffer[active_bitmap_buffer&1];
}


void *vid_get_bitmap_active_palette() {
    return (void*)0x8000; // just to return something valid, no palette needed on this cam
}


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

#define FW_YUV_LAYER_SIZE   (960*270*2)
extern unsigned int fw_yuv_layer_buf;

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
            } else if (evf_out) {
                bm_w = 360;
                bm_h = 270;
            } else {
                bm_w = 360;
                bm_h = 240;
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
            ximr->layers[0].src_h = 270;
            ximr->layers[0].height = 270;
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
        ximr->height = ximr->buffer_height = 270;
        ximr->denomy = 0x6c;
    }
}
