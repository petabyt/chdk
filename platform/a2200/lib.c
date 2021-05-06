#include "platform.h"
#include "platform_palette.h"
#include "lolevel.h"

#define LED_AC     0xC0220130
#define LED_AF     0xC02200AC

void shutdown() {
	
	volatile long *p = (void*)LED_AF;

	asm(
		"MRS     R1, CPSR\n"
		"AND     R0, R1, #0x80\n"
		"ORR     R1, R1, #0x80\n"
		"MSR     CPSR_cf, R1\n"
		:::"r1","r0");

	*p = 0x44;  // power off.

	while(1);
}

void debug_led(int state) {
	
	*(int*)LED_AC=state ? 0x46 : 0x44;
}

void camera_set_led(int led, int state, __attribute__ ((unused))int bright) {
	
	static char led_table[2]={0,9};
	_LEDDrive(led_table[led%sizeof(led_table)], state<=1 ? !state : state);
}

int vid_get_viewport_width()
{
    return 360;
}

long vid_get_viewport_height()
{
    return 240;
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
    if (MODE_IS_VIDEO(mode_get()))
        return viewport_buffers[0];     // Video only seems to use the first viewport buffer.

    // Hopefully return the most recently used viewport buffer so that motion detect, histogram, zebra and edge overly are using current image data
    return viewport_buffers[(active_viewport_buffer-1)&3];
}

void *vid_get_viewport_fb_d()
{
    extern char *viewport_fb_d;
	return viewport_fb_d;
}

void vid_bitmap_refresh() {

    extern int full_screen_refresh;
    extern void _ScreenLock();
    extern void _ScreenUnlock();

    full_screen_refresh |= 3;
    _ScreenLock();
    _ScreenUnlock();
}

//// viewport image offset - used when image size != viewport size (zebra, histogram, motion detect & edge overlay)
//// returns the byte offset into the viewport buffer where the image pixels start (to skip any black borders)
//int vid_get_viewport_image_offset() {
//	
//	return (vid_get_viewport_yoffset() * vid_get_viewport_buffer_width() + vid_get_viewport_xoffset()) * 3;
//}
//
//// viewport row offset - used when image size != viewport size (zebra, histogram, motion detect & edge overlay)
//// returns the byte offset to skip at the end of a viewport buffer row to get to the next row.
//int vid_get_viewport_row_offset() {
//	
//	return (vid_get_viewport_buffer_width() - vid_get_viewport_width()) * 3;
//}

void *vid_get_bitmap_active_palette() {
    extern int active_palette_buffer;
    extern char* palette_buffer[];
    void* p = palette_buffer[active_palette_buffer];
    // Don't add offset if value is 0
    if (p) p += 8;
    return p;
}

// Function to load CHDK custom colors into active Canon palette
void load_chdk_palette() {
	
	extern int active_palette_buffer;
	// Only load for the standard record and playback palettes
	if ((active_palette_buffer == 0) || (active_palette_buffer == 4))
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
			
			extern char palette_control;
			palette_control = 1;
			vid_bitmap_refresh();
        }
    }
}

int vid_get_palette_type() {
	
	return 3;
}

int vid_get_palette_size() {
	
	return 256 * 4;
}

void *vid_get_bitmap_active_buffer()
{

	return (void*)(*(int*)(0x560C+0x18)); // found @ FF912D5C: A2200 100b & 100d
}
