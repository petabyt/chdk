#include "platform.h"
#include "lolevel.h"
#include "live_view.h"

void vid_bitmap_refresh()
{
 // Method 1:
 //   extern void _displaybusyonscreen();
 //   extern void _undisplaybusyonscreen();
 //   _displaybusyonscreen();                 // clears perfectly but blinks and is asynchronous - see SX280hs for more code options
 //   _undisplaybusyonscreen();
 
 // Method 2:
 // extern int active_bitmap_buffer;
 // extern void _transfer_src_overlay(int);
 //   _transfer_src_overlay(active_bitmap_buffer);    
    
 // Method 3:
 // https://chdk.setepontos.com/index.php?topic=12788.msg133958#msg133958
 // works in most cases but can cause "ghosting" in auto mode when canon UI constantly updates;
    extern void _transfer_src_overlay(int);
    _transfer_src_overlay(0);
    _transfer_src_overlay(1);    
    
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

void camera_set_led(int led, int state, int bright)
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

int vid_get_viewport_width()
{
    extern int _GetVRAMHPixelsSize();
    if (camera_info.state.mode_play)
    {
      return camera_screen.physical_width;
    }
    return _GetVRAMHPixelsSize();
}

long vid_get_viewport_height()
{
    extern int _GetVRAMVPixelsSize();
    if (camera_info.state.mode_play)
    {
       return camera_screen.buffer_height;
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

// Functions for PTP Live View system
int vid_get_viewport_display_xoffset_proper()   { return vid_get_viewport_display_xoffset(); }
int vid_get_viewport_display_yoffset_proper()   { return vid_get_viewport_display_yoffset(); }
int vid_get_viewport_byte_width()               { return (640 * 2); }
int vid_get_viewport_fullscreen_height()        { return camera_screen.height; }
int vid_get_viewport_buffer_width_proper()      { return camera_screen.buffer_width; }
int vid_get_viewport_type()                     { return LV_FB_YUV8B; }

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
