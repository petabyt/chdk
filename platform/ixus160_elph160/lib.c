#include "platform.h"
#include "platform_palette.h"
#include "lolevel.h"

#define LED_PR 0xc022f1fc
#define LED_AF 0xc022d200


void debug_led(int state)
{
	*(int*)LED_PR=state ? 0x93d800 : 0x83dc00;
}

// TODO not really complete, last call from task_Bye
void shutdown()
{
    extern void _TurnOffE1(void);
    _TurnOffE1();
    while(1);
}

// IXUS160/ELPH160 has two 'lights' - Power LED, and AF assist lamp
// Power Led = first entry in table (led 0)
// AF Assist Lamp = second entry in table (led 1)
void camera_set_led(int led, int state, int bright) {
    static char led_table[2]={0,4};
    _LEDDrive(led_table[led%sizeof(led_table)], state<=1 ? !state : state);    
}

void *vid_get_viewport_fb()      { return (void*)0x40866b80; }             // Found @0xffb7af7c
char *camera_jpeg_count_str()    { return (char*)0x000d7868; }             // Found @0xff9ff7f0
int get_flash_params_count(void) { return 0xd4; }                          // Found @0xff9af548

extern int active_bitmap_buffer;
extern char* bitmap_buffer[];

void *vid_get_bitmap_fb() {
    return bitmap_buffer[0];
}
//void *vid_get_bitmap_fb()        { return (void*)0x40711000; }             // Found @0xff8662d0

void *vid_get_bitmap_active_buffer() {
    return bitmap_buffer[active_bitmap_buffer];
}

// start palette table FFC062B0?
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
    return 0;
}

char *hook_raw_image_addr()
{
//FFB7C910 (search for CRAW BUFF)
    return (char*) 0x43737E20;
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

