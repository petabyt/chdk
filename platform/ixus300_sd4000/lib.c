#include "platform.h"
#include "platform_palette.h"
#include "lolevel.h"

void shutdown() {
    volatile long *p = (void*)0xC0223030;    // Red AF Led (front)

    asm(
        "MRS     R1, CPSR\n"
        "AND     R0, R1, #0x80\n"
        "ORR     R1, R1, #0x80\n"
        "MSR     CPSR_cf, R1\n"
        :::"r1","r0"
    );

    *p = 0x44;

    while(1);
}

#define LED_DEBUG1 0xC0220130      // Green Led (backside)
#define LED_DEBUG2 0xc0220134      // Red Led (backside)
#define LED_DEBUG3 0xC0223030      // Red AF Led (front)
#define LED_AF 0xC0223030
#define DEBUG_LED_DELAY 2500000    // use beforce change CPU speed in boot.c


void debug_led(int state) {

    volatile long *p=(void*)LED_DEBUG2;

    if (state)
        p[0]=0x46;
    else
        p[0]=0x44;

    // delay loop
    int i;
    for (i=0; i<DEBUG_LED_DELAY; i++)
        asm("nop\n nop\n");
}

void camera_set_led(int led, int state, __attribute__ ((unused))int bright) {  // camera has three LED's (focus assist lamp & and a green/orange combo LED)
    static char led_table[3]={0,1,9};
    _LEDDrive(led_table[led%sizeof(led_table)], state<=1 ? !state : state);
}

int get_flash_params_count(void) {
    return 148;     // 0x94 = 148
}


void JogDial_CW(void) {
    _PostLogicalEventForNotPowerType(0x876, 1);  // RotateJogDialRight at levent_table
}

void JogDial_CCW(void) {
    _PostLogicalEventForNotPowerType(0x877, 1);  // RotateJogDialLeft at levent_table
}

void vid_bitmap_refresh() {
    extern int enabled_refresh_physical_screen;
    extern int full_screen_refresh;
    extern void _LockAndRefresh();   // wrapper function for screen lock
    extern void _UnlockAndRefresh();   // wrapper function for screen unlock

    _LockAndRefresh();

    enabled_refresh_physical_screen=1;
    full_screen_refresh=3;   // found in ScreenUnlock underneath a CameraLog.c call

    _UnlockAndRefresh();
}


// Canon UI Buffers for LiveView

    extern int   active_bitmap_buffer;   // in stub_min.S for ixus300
    extern char* bitmap_buffer[];        // in stub_min.S for ixus300

    void *vid_get_bitmap_fb()
    {
        // Return first bitmap buffer address
        return bitmap_buffer[0];
    }

// Canon Viewport buffers for LiveView, histogram, edgeoverlay, zebra , motion detect

    extern char  active_viewport_buffer; // in stub_entry.S for ixus300
    extern void* viewport_buffers[];     // in stub_entry.S for ixus300

    void *vid_get_viewport_live_fb()
    {
        char vp ;
        if (camera_info.state.mode_video || (get_movie_status()==VIDEO_RECORD_IN_PROGRESS))
            return viewport_buffers[0];     // Video only seems to use the first viewport buffer.

        // Hopefully return the most recently used viewport buffer so that motion detect, histogram, zebra and edge overly are using current image data
        // Note that this camera only seems to use 3 buffers (vs 4 on other models). 
        // Tests with MD_tune.bas show that returning one buffer back from the current value of active_viewport_buffer works best for motion detect

        vp = active_viewport_buffer ;
        return viewport_buffers[ (vp == 0) ? 2 : vp-1 ];
    }

    void *vid_get_viewport_fb()   /* redefined */
    {
        // Return first viewport buffer - for case when vid_get_viewport_live_fb not defined
        // Offset the return value because the viewport is left justified instead of centered on this camera
        return viewport_buffers[0];
    }

    void *vid_get_viewport_fb_d() /* redefined */
    {
        extern char *viewport_fb_d;
        return viewport_fb_d;
    }

    // Physical width of viewport row in bytes
    int vid_get_viewport_byte_width() {
        return 960 * 6 / 4;     // IXUS 300 - wide screen LCD is 960 pixels wide, each group of 4 pixels uses 6 bytes (UYVYYY)
    }

    int vid_get_viewport_width()
    {
        if (camera_info.state.mode_play)
        {
            return 480 ;
        }
        extern int _GetVRAMHPixelsSize();
        return _GetVRAMHPixelsSize() >> 1;
    }

    int vid_get_viewport_display_xoffset()
    {
        if (camera_info.state.mode_play)
        {
            return 0;
        }
        else
        {
            // viewport width offset table for each image size 
            // ixus300 has six sizes :  3648x2736 (4:3)   2816x2112 (4:3)    2272x1702 (4:3)  1600x1200  (4:3)  640x480  (4:3)  3648x2048 (16:9)
            //   PROPCASE_RESOLUTION :  0                 1                  2                3                 4                8
            if (shooting_get_prop(PROPCASE_RESOLUTION ) ==  8 ) return 0 ;      // wide screen mode
            return 60 ;                                                         // all other modes
        }
    }

   long vid_get_viewport_height(){ return 240; } 


// Additional Functions for PTP Live View system

    int vid_get_viewport_display_xoffset_proper()   { return vid_get_viewport_display_xoffset() * 2 ; }
    int vid_get_viewport_height_proper()            { return 240; }
    int vid_get_viewport_buffer_width_proper()      { return 960; }
    int vid_get_viewport_fullscreen_height()        { return 240; }
    int vid_get_palette_type()                      { return 3; }
    int vid_get_palette_size()                      { return 256 * 4; }
    int vid_get_aspect_ratio()                      { return 1; }


// ** Custom Color Palette **

extern char** palette_buffer_ptr;
extern int active_palette_buffer;

void* vid_get_bitmap_active_palette()
{
    return palette_buffer_ptr[active_palette_buffer]+8;
}

void load_chdk_palette()
{
    if ((active_palette_buffer == 0) || (active_palette_buffer == 4) || (active_palette_buffer == 7))  //00=rec  04=play  07=menu  03=setmenu (don't override in setmenu as it has no non-overlapping blank palette areas)
    {
        int *pal = (int *)vid_get_bitmap_active_palette();
        if (pal[CHDK_COLOR_BASE+0] != 0x33ADF62)
        {
            pal[CHDK_COLOR_BASE+0]  = 0x033ADF62;  // Red
            pal[CHDK_COLOR_BASE+1]  = 0x0326EA40;  // Dark Red
            pal[CHDK_COLOR_BASE+2]  = 0x034CD57F;  // Light Red
            pal[CHDK_COLOR_BASE+3]  = 0x0373BFAE;  // Green
            pal[CHDK_COLOR_BASE+4]  = 0x034BD6CA;  // Dark Green
            pal[CHDK_COLOR_BASE+5]  = 0x0395AB95;  // Light Green
            pal[CHDK_COLOR_BASE+6]  = 0x034766F0;  // Blue
            pal[CHDK_COLOR_BASE+7]  = 0x031250F3;  // Dark Blue
            pal[CHDK_COLOR_BASE+8]  = 0x037F408F;  // Cyan
            pal[CHDK_COLOR_BASE+9]  = 0x03512D5B;  // Magenta
            pal[CHDK_COLOR_BASE+10] = 0x03A9A917;  // Yellow
            pal[CHDK_COLOR_BASE+11] = 0x03819137;  // Dark Yellow
            pal[CHDK_COLOR_BASE+12] = 0x03DED115;  // Light Yellow
            pal[CHDK_COLOR_BASE+13] = 0x00090000;  // Transparent dark grey

            vid_bitmap_refresh();
        }
    }
}

