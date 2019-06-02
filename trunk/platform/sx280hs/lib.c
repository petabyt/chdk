#include "platform.h"
#include "lolevel.h"
#include "live_view.h"

void vid_bitmap_refresh() {
    extern void _transfer_src_overlay(int);
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
        return camera_screen.physical_width;
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
        return camera_screen.buffer_height;
    return _GetVRAMVPixelsSize();
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
    // Return first bitmap buffer address
    return bitmap_buffer[0];
}

// Functions for PTP Live View system
int vid_get_viewport_display_xoffset_proper()   { return vid_get_viewport_display_xoffset(); }
int vid_get_viewport_display_yoffset_proper()   { return vid_get_viewport_display_yoffset(); }
int vid_get_viewport_fullscreen_height()        { return camera_screen.height; } // may not be always ok
int vid_get_viewport_buffer_width_proper()      { return camera_screen.buffer_width; } // may not be always ok
int vid_get_viewport_byte_width()               { return camera_screen.buffer_width * 2; } // may not be always ok

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

