// Powershot N Facebook

#include "platform.h"
#include "platform_palette.h"
#include "lolevel.h"

extern  int     active_raw_buffer;
extern  char*   raw_buffers[];

char *camera_jpeg_count_str()    { return (char*)0x00220be0; }             // Found @0xff2c14cc
int get_flash_params_count(void) { return 0x91; }                          // Found @0xff250098


char *hook_raw_image_addr()
{
    return raw_buffers[active_raw_buffer];
}

char *hook_alt_raw_image_addr()
{
    return raw_buffers[(active_raw_buffer^1)];
}

void vid_bitmap_refresh()
{
    extern int full_screen_refresh;
    extern void _ScreenUnlock();
    extern void _ScreenLock();

    full_screen_refresh |= 3;
    _ScreenLock();
    _ScreenUnlock();
}

void shutdown()
{
    extern void _TurnOffE1(void);
    _TurnOffE1();
    while(1);
}

// powershot N has only one LED - on the power button
void debug_led(int state) 
{
    if ( state == 1 ) *(int*)0xc022c30c = ( (*(int*)0xc022c30c) & 0xffffffcf ) | 0x20 ;
    else              *(int*)0xc022c30c = ( (*(int*)0xc022c30c) & 0xffffffcf )        ;
}

// powershot N has one LED - on the power button - and a focus assist / camera lamp on the front of the camera
void camera_set_led(int led, int state, __attribute__ ((unused))int bright)
{
    static char led_table[3]={0,6,11};  // 0=green power button LED, 6=focus assist lamp (dim), 11=flash LED (bright)
    _LEDDrive(led_table[led%sizeof(led_table)], state<=1 ? !state : state);
}

// Bitmap values 
void *vid_get_bitmap_fb()   { return (void*)0x406c5000; }        // Found @0xff08d5d8
void *vid_get_viewport_fb() { return (void*)0x4081ab80; }        // Found @0xff4b7678

void *vid_get_viewport_fb_d()                                    // buffer used in playback mode & fallback if vid_get_viewport_live_fb returns null
{
    extern char *viewport_fb_d;
    return viewport_fb_d;
}

void *vid_get_viewport_live_fb()                                 // live buffer used in record mode
{ 
    extern char active_viewport_buffer;
    extern void* viewport_buffers[];

    if (MODE_IS_VIDEO(mode_get()) || (get_movie_status()==VIDEO_RECORD_IN_PROGRESS))
        return viewport_buffers[0];     // Video only seems to use the first viewport buffer.
   
    // Hopefully return the most recently used viewport buffer so that motion detect, histogram, zebra and edge overly are using current image data
    // -1 used for best MD response - TODO verify this
    return viewport_buffers[(active_viewport_buffer-7)&7];  // -7 tested best with fudgey's HTML motion detector
}



// Y multiplier for cameras with 480 pixel high viewports (CHDK code assumes 240)
int vid_get_viewport_yscale() {
        return 2;              
}

int vid_get_viewport_width()
{
    if ((mode_get() & MODE_MASK) == MODE_PLAY)
    {
        return 360;
    }
    extern int _GetVRAMHPixelsSize();
    return _GetVRAMHPixelsSize() >> 1;    
}

long vid_get_viewport_height()
{
  if ((mode_get() & MODE_MASK) == MODE_PLAY)
  {
       return 240;
  }
  extern int _GetVRAMVPixelsSize();
  return _GetVRAMVPixelsSize() >> 1;

}

// Functions for PTP Live View system & Cuatom Palette Colors

extern int active_palette_buffer;
extern int** palette_buffer_ptr;
extern char palette_control;

int vid_get_viewport_display_xoffset_proper()   { return vid_get_viewport_display_xoffset() * 2; }
int vid_get_palette_type()                      { return 3; }
int vid_get_palette_size()                      { return 256 * 4; }
int vid_get_aspect_ratio()                      { return 1; }

void *vid_get_bitmap_active_palette() {
    unsigned char theme;
    get_parameter_data(20, &theme, 1);
    return  palette_buffer_ptr[active_palette_buffer+theme] + 1;
}

void * vid_get_bitmap_active_buffer()
{
    return (void*)(*(int*)(0x7510+0x18)); //found Powershot N FB @ loc_ff1be034 (from A1400 example)
}

#ifdef CAM_LOAD_CUSTOM_COLORS

// Function to load CHDK custom colors into active Canon palette

void load_chdk_palette()
{
    unsigned char theme;
 
    // active_palette_buffer values
    //  0x00:shooting, 0x04:camera modes menu, 0x0C:func menu, 0x10:playback, 0x14:shooting setup menu, 0x18:wifi menu
    
    if (    (active_palette_buffer == 0x00) 
         || (active_palette_buffer == 0x10))
    {
        get_parameter_data(20, &theme, 1);   
        if (palette_buffer_ptr[active_palette_buffer+theme] !=0)
        {
            int* pal = palette_buffer_ptr[active_palette_buffer+theme] + 1; 
            // check that palette_buffer != null and palette transparent & black colors are correct before overwriting palette)
            if (    (pal!=0) 
                 && (pal[CHDK_COLOR_BASE+0] != 0x3F3ADF62) 
                 && (pal[0x00]==0x00FF0000) 
                 && (pal[0xFF]==0x3F000000) )
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

                palette_control = 1; // note appears to be a bitmask, 2nd bit is also used for something ?
                
                vid_bitmap_refresh();
            }
        }
    }
}
#endif
