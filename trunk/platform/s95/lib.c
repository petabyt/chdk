#include "platform.h"
#include "lolevel.h"


void shutdown()
{
    volatile long *p = (void*)0xc022012C; // from S90

    asm(
         "MRS     R1, CPSR\n"
         "AND     R0, R1, #0x80\n"
         "ORR     R1, R1, #0x80\n"
         "MSR     CPSR_cf, R1\n"
         :::"r1","r0");

    *p = 0x44;

    while(1);
}


#define LED_GREEN 0xc0220130

void debug_led(int state)
{
    if (state)
		*((long*) LED_GREEN) = 0x46;
    else
		*((long*) LED_GREEN) = 0x44;
}


/*
led 0 = green status
led 1 = orange status
led 2 = AF assist lamp
*/
void camera_set_led(int led, int state, __attribute__ ((unused))int bright) {
	static char led_table[4]={0,1,9};

    _LEDDrive(led_table[led%sizeof(led_table)], state<=1 ? !state : state);
}

void JogDial_CW(void){
	_PostLogicalEventToUI(0x86E, 1);  // RotateJogDialRight
}

void JogDial_CCW(void){
	_PostLogicalEventToUI(0x86F, 1);  // RotateJogDialLeft
}

int get_flash_params_count(void){
	return 0x9a;	// found in GetParameterData
}


void vid_bitmap_refresh()
{
	 extern int enabled_refresh_physical_screen; // screen lock counter
	 extern void _ScreenUnlock();

	_ScreenLock();
	enabled_refresh_physical_screen=1;
	_ScreenUnlock();
}


void shutdown_soft()
{
   _PostLogicalEventForNotPowerType(0x1005,0);
}

extern  int     active_raw_buffer;
extern  char*   raw_buffers[];

char *hook_raw_image_addr()
{
    return raw_buffers[active_raw_buffer*3];
}

char *hook_alt_raw_image_addr()
{
    return raw_buffers[(active_raw_buffer^1)*3];
}


// viewport stuff based on g12

// Defined in stubs_min.S
extern char active_viewport_buffer;
extern void* viewport_buffers[];

void *vid_get_viewport_fb()
{
    // Return first viewport buffer - for case when vid_get_viewport_live_fb not defined
    return viewport_buffers[0];
}

void *vid_get_viewport_live_fb()
{
    int b = (active_viewport_buffer-1)&3;
    if ((b == 3) && camera_info.state.mode_video)
        b = 2;  // Video only seems to use the first 3 viewport buffers.

    // Hopefully return the most recently used viewport buffer so that motion detect, histogram, zebra and edge overly are using current image data
    return viewport_buffers[b];
}

void *vid_get_viewport_fb_d()
{
    extern char *viewport_fb_d;
	return viewport_fb_d;
}

// Defined in stubs_min.S
extern int active_bitmap_buffer;
extern char* bitmap_buffer[];

void *vid_get_bitmap_fb()
{
    // Return first bitmap buffer address
    return bitmap_buffer[0];
}

// Y multiplier for cameras with 480 pixel high viewports (CHDK code assumes 240)
int vid_get_viewport_yscale() {
	return 2;               // S95 viewport is 480 pixels high
}

int vid_get_viewport_width()
{
    if (camera_info.state.mode_play)
    {
        return 360;
    }
    extern int _GetVRAMHPixelsSize();
    return _GetVRAMHPixelsSize() >> 1;
}

// viewport width offset table for each image size
// 0 = 4:3, 1 = 16:9, 2 = 3:2, 3 = 1:1, 4 = 4:5
static long vp_xo[5] = { 0, 0, 0, 44, 72 };				// should all be even values for edge overlay

int vid_get_viewport_xoffset()
{
    if (camera_info.state.mode_play)
    {
        return 0;
    }
    else if (camera_info.state.mode_shooting == MODE_STITCH)
    {
        return 0;
    }
    else
    {
	    return vp_xo[shooting_get_prop(PROPCASE_ASPECT_RATIO)];
    }
}

int vid_get_viewport_display_xoffset()
{
    if (camera_info.state.mode_play)
    {
        return 0;
    }
    else if (camera_info.state.mode_shooting == MODE_STITCH)
    {
        if (shooting_get_prop(PROPCASE_STITCH_DIRECTION) == 0)      // Direction check
            if (shooting_get_prop(PROPCASE_STITCH_SEQUENCE) == 0)   // Shot already taken?
                return 40;
            else
                return 140;
        else
            if (shooting_get_prop(PROPCASE_STITCH_SEQUENCE) == 0)   // Shot already taken?
                return 140;
            else
                return 40;
    }
    else
    {
	    return vp_xo[shooting_get_prop(PROPCASE_ASPECT_RATIO)];
    }
}

long vid_get_viewport_height()
{
    if (camera_info.state.mode_play)
    {
        return 240;
    }
    extern int _GetVRAMVPixelsSize();
    return _GetVRAMVPixelsSize() >> 1;
}

static int vp_yoffset(int stitch)
{
    // viewport height offset table for each image size
    // 0 = 4:3, 1 = 16:9, 2 = 3:2, 3 = 1:1, 4 = 4:5
    static long vp_yo[5] = { 0, 30, 13, 0, 0 };

    if (camera_info.state.mode_play)
    {
        return 0;
    }
    else if (camera_info.state.mode_shooting == MODE_STITCH)
    {
        return stitch;
    }
    else if (camera_info.state.mode_video)
    {
        return 30;
    }
    else
    {
	    return vp_yo[shooting_get_prop(PROPCASE_ASPECT_RATIO)];
    }
}

int vid_get_viewport_yoffset()
{
    return vp_yoffset(0);
}

int vid_get_viewport_display_yoffset()
{
    return vp_yoffset(72);
}

// Functions for PTP Live View system
int vid_get_viewport_display_xoffset_proper()   { return vid_get_viewport_display_xoffset() * 2; }
int vid_get_viewport_display_yoffset_proper()   { return vid_get_viewport_display_yoffset() * 2; }
int vid_get_viewport_height_proper()            { return vid_get_viewport_height() * 2; }
int vid_get_viewport_fullscreen_height()        { return 480; }
int vid_get_palette_type()                      { return 3; }
int vid_get_palette_size()                      { return 256 * 4; }

void *vid_get_bitmap_active_buffer()
{
    return bitmap_buffer[active_bitmap_buffer];
}

void *vid_get_bitmap_active_palette()
{
    extern int active_palette_buffer;
    extern char* palette_buffer[];
    return (palette_buffer[active_palette_buffer]+8);
}

char *camera_jpeg_count_str()
{
    extern char jpeg_count_str[];
	return jpeg_count_str;
}
