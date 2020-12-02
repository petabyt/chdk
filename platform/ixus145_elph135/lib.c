#include "platform.h"
#include "platform_palette.h"
#include "lolevel.h"

void vid_bitmap_refresh()
{
    extern int full_screen_refresh;
    extern void _ScreenLock();
    extern void _ScreenUnlock();

    full_screen_refresh |= 3;
    _ScreenLock();
    _ScreenUnlock();
}

//TODO: not really complete, last call from task_Bye
void shutdown()
{
    extern void _TurnOffE1(void);
    _TurnOffE1();
    while(1);
}

#define LED_PR 0xC022D1FC  // green LED
#define LED_AF 0xC022D200  // orange AF LED

void debug_led(int state)
{
    // using power LED, which defaults to on
    // for debugging turn LED off if state is 1 and on for state = 0
     *(int*)LED_PR=state ? 0x46 : 0x44;
}

// IXUS145_ELPH135 has two 'lights' - Power LED, and AF assist lamp
// Power Led = first entry in table (led 0)
// AF Assist Lamp = second entry in table (led 1)
void camera_set_led(int led, int state, __attribute__ ((unused))int bright) {
    static char led_table[2]={0,4}; // green, AF
    _LEDDrive(led_table[led%sizeof(led_table)], state<=1 ? !state : state);
}

char *camera_jpeg_count_str()
{
    extern char jpeg_count_str[];
    return jpeg_count_str;
}

int get_flash_params_count(void) { return 0xa6; }               // Found @0xff9a7ef4 ixus145 100c
char *hook_raw_image_addr()      {return (char*) 0x42f95130;}

extern int _GetVRAMHPixelsSize();
extern int _GetVRAMVPixelsSize();

int vid_get_viewport_width()
{
    if ((mode_get() & MODE_MASK) == MODE_PLAY)
    {
        return 360;
    }
    return _GetVRAMHPixelsSize() >> 1;
}

long vid_get_viewport_height()
{
  if ((mode_get() & MODE_MASK) == MODE_PLAY)
  {
       return 240;
  }
  return _GetVRAMVPixelsSize();
}


// Viewport and Bitmap values that shouldn't change across firmware versions.
// Values that may change are in lib.c for each firmware version.
//void *vid_get_bitmap_fb()        { return (void*)0x40431000; } // Found @0xff85cf34
// OSD buffer
/*
void *vid_get_bitmap_fb()
{
	return (void*)0x40730480;//0x406F1000; // "BmpDDev.c", 0xFF93DAE4	// ixus145
}*/
void *vid_get_bitmap_fb() { return (void*)0x406f1000; }

//void *vid_get_viewport_fb()      { return (void*)0x40586b80; } // Found @0xffb17000
// Live picture buffer (shoot half-pressed)
/*
void *vid_get_viewport_fb()
{
	return (void*)0x40846B80;  // "VRAM Address" sub_FFB66A8C // ixus145
}*/
void *vid_get_viewport_fb() { return (void*)0x40846b80; }

void *vid_get_viewport_fb_d()
{
    extern char *viewport_fb_d;
    return viewport_fb_d;
}

//To do
void *vid_get_viewport_live_fb()
{
    extern char active_viewport_buffer;
    extern void* viewport_buffers[];

    if (MODE_IS_VIDEO(mode_get()) || is_video_recording())
        return viewport_buffers[0];     // Video only seems to use the first viewport buffer.

    // Hopefully return the most recently used viewport buffer so that motion detect, histogram, zebra and edge overly are using current image data
    return viewport_buffers[(active_viewport_buffer-1)&3]; //After a while MD Last 190 / Min 70 / Max 198 / Avg 179
}

int vid_get_palette_type()                      { return 3; }
int vid_get_palette_size()                      { return 256 * 4; }

void *vid_get_bitmap_active_buffer()
{
    return vid_get_bitmap_fb();
}

void *vid_get_bitmap_active_palette() // from ixus140_elph130
{
    extern int active_palette_buffer;
    extern int** palette_buffer_ptr;
    int *p = palette_buffer_ptr[active_palette_buffer];
    // active_palette_buffer can point at null when
    // func and menu are opened for the first time
    if(!p) {
        p = palette_buffer_ptr[0]; // rec mode buffer appears to always be initialized
    }
    return (p+1);
}

// Function to load CHDK custom colors into active Canon palette

void load_chdk_palette() {

    extern int active_palette_buffer;
    // Only load for the standard record(0) and playback palettes(5)
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
            pal[CHDK_COLOR_BASE+13] = 0x1F0A0000;  // Transparent dark grey

            extern char palette_control;
            palette_control = 1;
            vid_bitmap_refresh();
        }
    }
}

