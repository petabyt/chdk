#include "platform.h"
#include "lolevel.h"
#include "live_view.h"

static char* frame_buffer[2];

void vid_bitmap_refresh() {
    // extern int full_screen_refresh;
    // extern void _ScreenUnlock();
    // extern void _ScreenLock();
    // extern void _displaybusyonscreen();
    // extern void _undisplaybusyonscreen();

    
    // clears perfectly but blinks and is asynchronous
    // _displaybusyonscreen();
    // _undisplaybusyonscreen();
    
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
    while(1)   _SleepTask(500);
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
        return 720;
    }
// TODO: currently using actual width rather than half width used on pre d6
// pixel format is uyvy (16bpp)
    return _GetVRAMHPixelsSize();
}

long vid_get_viewport_height() {
    extern int _GetVRAMVPixelsSize();
    if (camera_info.state.mode_play)
    {
        return 480;
    }
	return _GetVRAMVPixelsSize();
}

int vid_get_viewport_yoffset() {
    // this seems to be always 0, buffer always begins with actual display data (widescreen or not)
    return 0;
}

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
int vid_get_viewport_buffer_width_proper()		{ return camera_screen.buffer_width ; } //(*(int*)(0x00053CBC) );
int vid_get_viewport_fullscreen_width()			{ return camera_screen.width; }
int vid_get_viewport_byte_width() 				{ return (camera_screen.buffer_width * 2); }

int vid_get_viewport_fullscreen_height()        { return 480; }
int vid_get_aspect_ratio()                      { return LV_ASPECT_3_2; }



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

#ifdef CAM_SUPPORT_BITMAP_RES_CHANGE
/*
 * needed because bitmap buffer resolutions change when an external display is used
 * an extra screen erase doesn't seem to be needed
 */
void update_screen_dimensions() {
    // see sub_fc18618a in 102b and 102c for the values
    extern int displaytype;
    static int old_displaytype = -1;

   /*  if (old_displaytype == displaytype) {
        return;
    }
    old_displaytype = displaytype; */
//*(int*)0xd20b0810  = 0x4d0002;	 // Orange Led = on
    switch(displaytype) {
        case 0:
        case 3:
        case 4:
        case 5:
		case 10:
            // lcd
			
            camera_screen.physical_width = camera_screen.width = 720;
			camera_screen.buffer_width = 736;
            camera_screen.height = camera_screen.buffer_height = 480;
            camera_screen.size = camera_screen.buffer_size = 736*480;
            break;
        case 1:
        case 2:
        case 8:
        case 9:
            // tv-out
            camera_screen.width = 736;
            camera_screen.physical_width = camera_screen.buffer_width = 736;
            camera_screen.height = camera_screen.buffer_height = 480;
            camera_screen.size = 736*480;
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

