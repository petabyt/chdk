#include "platform.h"
#include "lolevel.h"

static char* frame_buffer[2];

void vid_bitmap_refresh() {
    extern int full_screen_refresh;
    extern void _ScreenUnlock();
    extern void _ScreenLock();
    extern void _displaybusyonscreen();
    extern void _undisplaybusyonscreen();

    
    // clears perfectly but blinks and is asynchronous
    _displaybusyonscreen();
    _undisplaybusyonscreen();
    
    // stuff commented on sx280
    /*
    // completely ineffective
    extern void _refresh_bitmap_buf_from(int, int);
    _refresh_bitmap_buf_from(0,0);
    */

    /*
    // flips the active buffer but doesn't erase areas not occupied by the canon osd
    _ScreenLock();
    full_screen_refresh |= 3;
    _ScreenUnlock();
    */

    /*
    //ineffective, like screenlock/unlock, crashed movie rec once
    extern void _RefreshPhysicalScreen();
    int saved_abdcplus4c = *(int*)(0xabdc+0x4c);
    *(int*)(0xabdc+0x4c) = 0;
    _RefreshPhysicalScreen(0);
    *(int*)(0xabdc+0x4c) = saved_abdcplus4c;
    */

    //DisplayPhysicalScreenCBR NG
    //Window_EmergencyRefresh NG crash
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

extern  int     active_raw_buffer;
extern  char*   raw_buffers_canon_raw[];
extern  char*   raw_buffers_jpeg[];

char *hook_raw_image_addr()
{
    // observed values 0-2, 3 would index something that doesn't look like a raw fb in the jpeg case
    int i=active_raw_buffer&3;
    if(i>2) {
        i=0;
    }
    if( camera_info.state.mode_shooting == MODE_AUTO) {
        // AUTO mode (canon raw can't be enabled in AUTO)
        return (char *)0x46f04300; // TODO unclear if this is only buffer, or if used in all AUTO sub modes
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

extern char active_viewport_buffer;
extern void* viewport_buffers[];

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
initially found by RAM dumping
0x5e608000 ref sub_fc1ba3f0 "ImgDDev.c" 
0x5ee08000 ref DispCon_ShowColorBar and other DispCon_* functions
*/
void *vid_get_viewport_fb_d()    {
    return (void*)0x5e608000;
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
void *vid_get_viewport_live_fb() {
    return 0; //TODO
}

int vid_get_viewport_width() {
    extern int _GetVRAMHPixelsSize();
    if (camera_info.state.mode_play)
    {
        return 720;
    }
// TODO: this is the actual width, pixel format is uyvy (16bpp)
    return _GetVRAMHPixelsSize();
}

long vid_get_viewport_height() {
    extern int _GetVRAMVPixelsSize();
    if (camera_info.state.mode_play)
    {
        return 480;
    }
// TODO return half height?
    return _GetVRAMVPixelsSize();
}

// Y multiplier for cameras with 480 pixel high viewports (CHDK code assumes 240)
int vid_get_viewport_yscale() {
    return 2;
}

int vid_get_viewport_yoffset() {
    // this seems to be always 0, buffer always begins with actual display data (widescreen or not)
    return 0;
}

int vid_get_viewport_display_xoffset() {
    return 0;
}

int vid_get_viewport_display_yoffset() {
    return 0;
}

extern int active_bitmap_buffer;
extern char* bitmap_buffer[];

void *vid_get_bitmap_fb() {
    return (void *)0x41441000; // from sub_fc0f7c21, alt 4153e200
}

// TODO
// Functions for PTP Live View system
int vid_get_viewport_display_xoffset_proper()   { return vid_get_viewport_display_xoffset() * 2; }
int vid_get_viewport_display_yoffset_proper()   { return vid_get_viewport_display_yoffset() * 2; }
int vid_get_viewport_width_proper()             { return vid_get_viewport_width(); }
int vid_get_viewport_height_proper()            { return vid_get_viewport_height() * 2; }
int vid_get_viewport_fullscreen_height()        { return 480; }
int vid_get_palette_type()                      { return 3; }
int vid_get_palette_size()                      { return 256 * 4; }

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

void *vid_get_bitmap_active_palette() {
    return (void*)0x8000; // just to return something valid, no palette needed on this cam
}

#if 0
#ifdef CAM_SUPPORT_BITMAP_RES_CHANGE
/*
 * needed because bitmap buffer resolutions change when an external display is used
 * an extra screen erase doesn't seem to be needed
 */
void update_screen_dimensions() {
    // see sub_fc18618a in 102b and 102c for the values
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
#endif

char *camera_jpeg_count_str()
{
    extern char jpeg_count_str[];
	return jpeg_count_str;
}
