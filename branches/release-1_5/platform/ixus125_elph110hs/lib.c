#include "platform.h"
#include "platform_palette.h"
#include "lolevel.h"

extern  int     active_raw_buffer;
extern  char*   raw_buffers[];

char *hook_raw_image_addr()
{
    return raw_buffers[active_raw_buffer];
}

char *hook_alt_raw_image_addr()
{
    return raw_buffers[(active_raw_buffer^1)];
}


char *camera_jpeg_count_str()
{
    extern char jpeg_count_str[];
	return jpeg_count_str;
}

int get_flash_params_count(void)
{
    return 0xa6;
}

//To do: find this LED address
//#define LED_PR 0xC0220160

void shutdown()
{
//	volatile long *p = (void*)LED_PR;

	asm(
		"MRS     R1, CPSR\n"
		"AND     R0, R1, #0x80\n"
		"ORR     R1, R1, #0x80\n"
		"MSR     CPSR_cf, R1\n"
		:::"r1","r0");

//	*p = 0x44;  // power off.

	while(1);
}

void debug_led(int state)
{
	// using power LED, which defaults to on
	// for debugging turn LED off if state is 1 and on for state = 0
	// leaves LED on at end of debugging
//     *(int*)LED_PR=state ? 0x46 : 0x44;
}

// To do: fix this.
// IXUS125  has two 'lights'??? - Power LED, and AF assist lamp
// Power Led = first entry in table (led 0) ???
// AF Assist Lamp = second entry in table (led 1) ????
void camera_set_led(int led, int state, int bright) {
	static char led_table[2]={0,4};
    if(state<=1) _LEDDrive(led_table[led%sizeof(led_table)], (!state)&1);
}

// Viewport and Bitmap values that shouldn't change across firmware versions.
// Values that may change are in lib.c for each firmware version.
void *vid_get_viewport_fb_d()
{
    extern char *viewport_fb_d;
    return viewport_fb_d;
}

// Defined in stubs_entry.S
extern char active_viewport_buffer;
extern void* viewport_buffers[];

void *vid_get_viewport_fb()
{
    // Return first viewport buffer - for case when vid_get_viewport_live_fb not defined
    return viewport_buffers[0];
}

void *vid_get_viewport_live_fb()
{
    if (camera_info.state.mode_video || is_video_recording())
        return viewport_buffers[0];     // Video only seems to use the first viewport buffer.

    // Hopefully return the most recently used viewport buffer so that motion detect, histogram, zebra and edge overly are using current image data
    return viewport_buffers[(active_viewport_buffer-1)&3];
}

// Y multiplier for cameras with 480 pixel high viewports (CHDK code assumes 240)
int vid_get_viewport_yscale() {
    return 2;
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

long vid_get_viewport_height()
{
    if (camera_info.state.mode_play)
    {
        return 240;
    }
    extern int _GetVRAMVPixelsSize();
    return _GetVRAMVPixelsSize() >> 1;
}

// 0 = 4:3, 1 = 16:9, 2 = 3:2, 3 = 1:1
static long vp_xo[5] = { 0, 0, 0, 44 };				// should all be even values for edge overlay

// guessed same as elph130
int vid_get_viewport_xoffset()
{
    return 0;
}

int vid_get_viewport_display_xoffset()
{
    if (camera_info.state.mode_play)
    {
        return 0;
    }
    else if (camera_info.state.mode_shooting == MODE_STITCH) // guessed based on elph130
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
    else if (camera_info.state.mode_video || is_video_recording()) {
        return 0;
    }
    else
    {
	    return vp_xo[shooting_get_prop(PROPCASE_ASPECT_RATIO)];
    }
}

// viewport height offset table for each image size
// 0 = 4:3, 1 = 16:9, 2 = 3:2, 3 = 1:1
static long vp_yo[5] = { 0, 30, 13, 0 };

int vid_get_viewport_yoffset()
{
    if (camera_info.state.mode_play)
    {
        return 0;
    }
    else if (camera_info.state.mode_shooting == MODE_STITCH) // guessed based on elph130
    {
        return 0;
    }
    else if (camera_info.state.mode_video || is_video_recording())
    {
        if(shooting_get_prop(PROPCASE_VIDEO_RESOLUTION) == 2) { // 640x480
            return 0;// 4:3 video, no offset
        } else {
            return 30; // 16:9 video
        }
    }
    else
    {
	    return vp_yo[shooting_get_prop(PROPCASE_ASPECT_RATIO)];
    }
}

int vid_get_viewport_display_yoffset()
{
    if (camera_info.state.mode_play)
    {
        return 0;
    }
    else if (camera_info.state.mode_shooting == MODE_STITCH) // guessed based on elph130
    {
        return 72;
    }
    else if (camera_info.state.mode_video || is_video_recording())
    {
        if(shooting_get_prop(PROPCASE_VIDEO_RESOLUTION) == 2) { // 640x480
            return 0;// 4:3 video, no offset
        } else {
            return 30; // 16:9 video
        }
    }
    else
    {
	    return vp_yo[shooting_get_prop(PROPCASE_ASPECT_RATIO)];
    }
}


int vid_get_viewport_display_yoffset_proper()   { return vid_get_viewport_display_yoffset() * 2; }
int vid_get_viewport_height_proper()            { return vid_get_viewport_height() * 2; }
int vid_get_viewport_fullscreen_height()        { return 480; }

void vid_bitmap_refresh() {

    extern int full_screen_refresh;
    extern void _ScreenLock();
    extern void _ScreenUnlock();

    full_screen_refresh |= 3;
    _ScreenLock();
    _ScreenUnlock();
}

void *vid_get_bitmap_active_palette() {
    extern int active_palette_buffer;
    extern char* palette_buffer[];
    void* p = palette_buffer[active_palette_buffer];
    // Don't add offset if value is 0
    if (p) p += 4;
    return p;
}


// Functions for PTP Live View system
// 256 entry palette based on 100b sub_FF926708 ixus115 101a
int vid_get_palette_type()                      { return 3; }
int vid_get_palette_size()                      { return 256 * 4; }

// Defined in stubs_entry.S
extern int active_bitmap_buffer;
extern char* bitmap_buffer[];

void *vid_get_bitmap_fb() {
    // Return first bitmap buffer address
    return bitmap_buffer[0];
}

void *vid_get_bitmap_active_buffer() {
    return bitmap_buffer[active_bitmap_buffer];
}

#ifdef CAM_LOAD_CUSTOM_COLORS
// Function to load CHDK custom colors into active Canon palette
void load_chdk_palette()
{
    extern int active_palette_buffer;
    // Only load for the standard record and playback palettes
    //rec=0, set menu=4, play=5, menu=6
    if ((active_palette_buffer == 0) || (active_palette_buffer == 5))
    {
        int *pal = (int*)vid_get_bitmap_active_palette();
        if (pal && pal[CHDK_COLOR_BASE+0] != 0x33ADF62)
        {
            pal[CHDK_COLOR_BASE+0]  = 0x33ADF62;  // Red
            pal[CHDK_COLOR_BASE+1]  = 0x326EA40;  // Dark Red
            pal[CHDK_COLOR_BASE+2]  = 0x34CD57F;  // Light Red
            pal[CHDK_COLOR_BASE+3]  = 0x373BFAE;  // Green
            pal[CHDK_COLOR_BASE+4]  = 0x34BD6CA;  // Dark Green
            pal[CHDK_COLOR_BASE+5]  = 0x395AB95;  // Light Green
            pal[CHDK_COLOR_BASE+6]  = 0x34766F0;  // Blue
            pal[CHDK_COLOR_BASE+7]  = 0x31250F3;  // Dark Blue
            pal[CHDK_COLOR_BASE+8]  = 0x37F408F;  // Cyan
            pal[CHDK_COLOR_BASE+9]  = 0x3512D5B;  // Magenta
            pal[CHDK_COLOR_BASE+10] = 0x3A9A917;  // Yellow
            pal[CHDK_COLOR_BASE+11] = 0x3819137;  // Dark Yellow
            pal[CHDK_COLOR_BASE+12] = 0x3DED115;  // Light Yellow
            pal[CHDK_COLOR_BASE+13] = 0x0090000;  // Transparent dark grey

            extern char palette_control;
            palette_control = 1;
            vid_bitmap_refresh();
        }
    }
}
#endif
