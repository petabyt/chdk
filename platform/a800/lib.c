#include "platform.h"
#include "lolevel.h"

// only two LEDs in A495 - the same in a800
#define LED_PR 0xC0220088  // green LED
#define LED_AF 0xC0220080  // orange AF LED - não sei


void shutdown()
{
    volatile long *p = (void*)LED_PR;    // Green LED

    asm(
        "MRS     R1, CPSR\n"
        "AND     R0, R1, #0x80\n"
        "ORR     R1, R1, #0x80\n"
        "MSR     CPSR_cf, R1\n"
        :::"r1","r0");

    *p = 0x44;  // power off.

    while(1);
}


void debug_led(int state)
{
    *(int*)LED_PR=state ? 0x46 : 0x44;
}

void camera_set_led(int led, int state, __attribute__ ((unused))int bright) {
    static char led_table[2]={7,9};
    if(state<=1) _LEDDrive(led_table[led%sizeof(led_table)], (!state)&1);
}

void vid_bitmap_refresh()
{
 	extern int full_screen_refresh;
	extern void _ScreenLock();
	extern void _ScreenUnlock();

	full_screen_refresh |= 3; //found in ScreenUnlock
	_ScreenLock();	
	_ScreenUnlock();
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
    return viewport_buffers[(active_viewport_buffer)&3];
}

// Near "PropertyTableManagerCore.c" ROM:FFD2ED94
int get_flash_params_count(void) {
 return 0xa0; 
 }


// PTP display stuff
// 64 entry palette based on 100b 0xffcd86d4
int vid_get_palette_type() { return 4; }
int vid_get_palette_size() { return 16*4; }

void *vid_get_bitmap_active_palette() {
    return (void *)*(unsigned int*)(0x49e8+0x20);  // sub_ffcd86d4, via sub_ffe51bf0 two refs to "Palette Class."
}
void *vid_get_bitmap_active_buffer()
{
    return (void*)(*(int*)(0x49e8+0x0c)); //sub_ffcd8790, via sub_ffe70e04 "Add: %p Width : %ld Hight : %ld", 
}
