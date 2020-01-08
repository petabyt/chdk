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
void camera_set_led(int led, int state, int bright) {
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
// only different for HDMI out, playback only, probably pointless
static int vp_full_width = 720;
static int vp_full_buf_width = 736;
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
//
// 0 = 4:3, 1 = 16:9, 2 = 3:2, 3 = 1:1, 4 = 4:5
static long vp_xo[5] = { 40, 0, 0, 120, 168 };				// should all be even values for edge overlay

int vid_get_viewport_display_xoffset() {
    if (camera_info.state.mode_play)
    {
        return 0;
    }
    // video, ignore still res propcase
    if(camera_info.state.mode_video || is_video_recording()) {
        if(shooting_get_prop(PROPCASE_VIDEO_RESOLUTION) == 2) {
            return 40;// 4:3 video
        } else {
            return 0; // 16:9 video, no x offset
        }
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
            return 36; // 16:9 video
        }
    }
    if (shooting_get_prop(PROPCASE_ASPECT_RATIO) == 1)
    {
        return 36;
    }
    return 0;
}

extern char* bitmap_buffer[];

void *vid_get_bitmap_fb() {
    return (void *)0x41441000; // from sub_fc0f7c21, alt 4153e200
}

int vid_get_viewport_byte_width() {
    return (vp_full_width * 2);
}

// Functions for PTP Live View system
int vid_get_viewport_display_xoffset_proper()   { return vid_get_viewport_display_xoffset(); }
int vid_get_viewport_display_yoffset_proper()   { return vid_get_viewport_display_yoffset(); }
int vid_get_viewport_fullscreen_width()         { return vp_full_width; }
int vid_get_viewport_fullscreen_height()        { return vp_full_height; }
int vid_get_viewport_buffer_width_proper()      { return vp_full_buf_width; }
int vid_get_viewport_type()                     { return LV_FB_YUV8B; }
int vid_get_aspect_ratio()                      { return LV_ASPECT_3_2; }
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

#ifdef CAM_SUPPORT_BITMAP_RES_CHANGE
/*
 * needed because bitmap buffer resolutions change when an external display is used
 * an extra screen erase doesn't seem to be needed
 */
void update_screen_dimensions() {
    // see sub_fc0f7aae
    extern int displaytype;
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
            // 640, ? not used
            camera_screen.width = camera_screen.physical_width = camera_screen.buffer_width = 640;
            camera_screen.height = camera_screen.buffer_height = 480;
            camera_screen.size = camera_screen.buffer_size = 640*480;
            break;
        case 1: // TV out NTSC
        case 2: // TV out PAL
        case 8:
        case 9: 
        case 10:// LCD
            camera_screen.width = 720;
            camera_screen.physical_width = camera_screen.buffer_width = 736;
            camera_screen.height = camera_screen.buffer_height = 480;
            camera_screen.size = 720*480;
            camera_screen.buffer_size = 736*480;
            break;
        case 6: // HDMI (playback only) (video standard NTSC)
        case 7: // " (video standard PAL)
            camera_screen.width = camera_screen.physical_width = camera_screen.buffer_width = 960;
            camera_screen.height = camera_screen.buffer_height = 540;
            camera_screen.size = camera_screen.buffer_size = 960*540;
            break;
        case 11:// O_o
            camera_screen.width = 1024;
            camera_screen.physical_width = camera_screen.buffer_width = 1024;
            camera_screen.height = camera_screen.buffer_height = 768;
            camera_screen.size = 1024*768;
            camera_screen.buffer_size = 1024*768;
            break;
    }
    if(displaytype == 6 || displaytype == 7) {
        vp_full_width = 1920;
        vp_full_buf_width = 1920;
        vp_full_height = 1080;
    } else {
        // others are unclear, but unlikely to come up in practice
        vp_full_width = 720;
        vp_full_buf_width = 736;
        vp_full_height = 480;
    }
}
#endif

char *camera_jpeg_count_str()
{
    extern char jpeg_count_str[];
	return jpeg_count_str;
}
