#include "platform.h"
#include "platform_palette.h"
#include "lolevel.h"

#define LED_PR 0xc022d1fc
#define LED_AF 0xc022d200


void debug_led(int state)
{
	*(int*)LED_PR=state ? 0x93d800 : 0x83dc00;
}

void shutdown()
{
    extern void _TurnOffE1(void);
    _TurnOffE1();
    while(1);
}

// TODO
// Power Led = first entry in table (led 0)
// AF Assist Lamp = second entry in table (led 1)
void camera_set_led(int led, int state, int bright) {
    static char led_table[2]={0,4};
    if(state<=1) _LEDDrive(led_table[led%sizeof(led_table)], (!state)&1);
}

void *vid_get_viewport_fb()      { return (void*)0x40866b80; }             // Found @0xffb93e14
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x34d8+0x5c)); } // Found @0xff8853f8 & 0xff885430
char *camera_jpeg_count_str()    { return (char*)0x000d77d4; }             // Found @0xffa13d38
int get_flash_params_count(void) { return 0xF1; }                          // Found @0xff9c3e58 NOT SURE

//void *vid_get_viewport_fb()      { return (void*)0x40846b80; }             // Found @0xffb55d0c

extern int active_bitmap_buffer;
extern char* bitmap_buffer[];

void *vid_get_bitmap_fb()        { return (void*)0x40711000; }             // Found @0xff86689c
/*void *vid_get_bitmap_fb() {
    return bitmap_buffer[0];
}*/

void *vid_get_bitmap_active_buffer() {
    return bitmap_buffer[active_bitmap_buffer&1];
}

// Palette colour tables  found @ 0xffbec15c
void *vid_get_bitmap_active_palette()
{
    extern int active_palette_buffer;
    extern int** palette_buffer_ptr;
    int *p = palette_buffer_ptr[active_palette_buffer];
    if(!p) {
        p = palette_buffer_ptr[0];
    }
    return (p+1);
}

extern int _GetVRAMHPixelsSize();
extern int _GetVRAMVPixelsSize();

//taken from n
int vid_get_viewport_width()
{
    if ((mode_get() & MODE_MASK) == MODE_PLAY)
    {
        return 360;
    }
    return _GetVRAMHPixelsSize() >> 1;
}
// taken from n
long vid_get_viewport_height()
{
  if ((mode_get() & MODE_MASK) == MODE_PLAY)
  {
       return 240;
  }
  return _GetVRAMVPixelsSize();
}

void *vid_get_viewport_fb_d()
{
    extern char *viewport_fb_d;
    return viewport_fb_d;
}

void *vid_get_viewport_live_fb()
{
    extern char active_viewport_buffer;
    extern void* viewport_buffers[];

    // no distinct video mode
    if (get_movie_status() == VIDEO_RECORD_IN_PROGRESS)
        return viewport_buffers[0];     // Video only seems to use the first viewport buffer.
    // Hopefully return the most recently used viewport buffer so that motion detect, histogram, zebra and edge overly are using current image data
    // verified -1 gives best response (50 .. 90 ms)
    return viewport_buffers[(active_viewport_buffer-1)&3];
}

char *hook_raw_image_addr()
{
    return (char*) 0x43727660;  //found by campare "JPEG BUFF" at FFB95894 and compare to ixus 160
}

void vid_bitmap_refresh()
{
    extern int full_screen_refresh;
    extern void _ScreenLock();
    extern void _ScreenUnlock();

    full_screen_refresh |= 3;
    _ScreenLock();
    _ScreenUnlock();
}

//see viewport.h
int vid_get_aspect_ratio()
{
    return 0; // 4:3
}

int vid_get_palette_type()   { return 5; }
int vid_get_palette_size()   { return 256 * 4 ; }

#ifdef CAM_LOAD_CUSTOM_COLORS
// Function to load CHDK custom colors into active Canon palette
void load_chdk_palette()
{
    extern int active_palette_buffer;
	// Only load for the standard record and playback palettes
	if ((active_palette_buffer == 0) || (active_palette_buffer == 5))
    {
        int *pal = (int*)vid_get_bitmap_active_palette();


        if (pal[CHDK_COLOR_BASE+0] != 0x3F3ADF62)
        {
            pal[CHDK_COLOR_BASE+0]  = 0x3F3ADF62;  // Red
            pal[CHDK_COLOR_BASE+1]  = 0x3F26EA40;  // Dark Red
            pal[CHDK_COLOR_BASE+2]  = 0x3F4CD57F;  // Light Red
            pal[CHDK_COLOR_BASE+3]  = 0x3F73BFAE;  // Green
            pal[CHDK_COLOR_BASE+4]  = 0x3F4BD6CA;  // Dark Green
            pal[CHDK_COLOR_BASE+5]  = 0x3F95AB95;  // Light Green
            pal[CHDK_COLOR_BASE+6]  = 0x3F4766F0;  // Blue
            pal[CHDK_COLOR_BASE+7]  = 0x3F1250F3;  // Dark Blue
            pal[CHDK_COLOR_BASE+8]  = 0x3F7F408F;  // Cyan
            pal[CHDK_COLOR_BASE+9]  = 0x3F512D5B;  // Magenta
            pal[CHDK_COLOR_BASE+10] = 0x3FA9A917;  // Yellow
            pal[CHDK_COLOR_BASE+11] = 0x3F819137;  // Dark Yellow
            pal[CHDK_COLOR_BASE+12] = 0x3FDED115;  // Light Yellow
            pal[CHDK_COLOR_BASE+13] = 0x00090000;  // Transparent dark grey

            extern char palette_control;
            palette_control = 1;
            vid_bitmap_refresh();
        }
    }
}
#endif
