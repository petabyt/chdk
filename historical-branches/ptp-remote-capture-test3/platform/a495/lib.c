#include "platform.h"
#include "lolevel.h"

// only two LEDs in A495:
#define LED_PR 0xC0220088  // green LED
#define LED_AF 0xC0220080  // orange AF LED


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

// A495 has 2 led values
// 0/7 - Power LED Green
// 1/9 - AF LED Orange
void camera_set_led(int led, int state, int bright) {
    static char led_table[2]={7,9};
//    if(state<=1) _LEDDrive(led_table[led%2], (!state)&1);
    if(state<=1) _LEDDrive(led_table[led%sizeof(led_table)], (!state)&1);
}

void vid_bitmap_refresh() {
    extern int enabled_refresh_physical_screen;
    extern int full_screen_refresh;

    // asm1989: i've tried refreshphysical screen (screen unlock) and that caused the canon and
    // function menu to not display at all. This seems to work and is called in a similar
    // way in other places where original OSD should be refreshed.
    extern void _ScreenLock();
    extern void _ScreenUnlock();

    _ScreenLock();

    enabled_refresh_physical_screen=1;
    full_screen_refresh=3;   // found in ScreenUnlock underneath a CameraLog.c call

    _ScreenUnlock();
}

// Near "PropertyTableManagerCore.c" ROM:FFD2ED94
int get_flash_params_count(void){
    return 0x74; 
}


/*void vid_turn_off_updates()
{
    extern void _LockAndRefresh();   // wrapper function for screen lock

    _LockAndRefresh();
}

void vid_turn_on_updates()
{
    extern void _UnlockAndRefresh();   // wrapper function for screen unlock

    //_RefreshPhysicalScreen(1);
    _UnlockAndRefresh();
}*/

// Functions for PTP Live View system

void *vid_get_bitmap_active_palette() {
        return (void*)(*(int*)(0x4970+0x20));  //Found @ 0xffcd1e80 a495 100f
}


// 64 entry palette based on 100f 0xffcd1e80
int vid_get_palette_type()                      { return 4; }
int vid_get_palette_size()                      { return 16*4; }

void *vid_get_bitmap_active_buffer()
{
    return (void*)(*(int*)(0x4970+0xC)); //found @ 0xffcd1f3c a495 100f
}
