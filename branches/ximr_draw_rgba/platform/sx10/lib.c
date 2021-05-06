#include "platform.h"
#include "lolevel.h"

char *camera_jpeg_count_str()
{
    extern char jpeg_count_str[];
    return jpeg_count_str;
}

void vid_bitmap_refresh()
{
 extern int enabled_refresh_physical_screen;
 enabled_refresh_physical_screen=1;
 _RefreshPhysicalScreen(1);
}


void shutdown()
{
	volatile long *p = (void*)0xC022001C;    
	
	asm(
		"MRS     R1, CPSR\n"
		"AND     R0, R1, #0x80\n"
		"ORR     R1, R1, #0x80\n"
		"MSR     CPSR_cf, R1\n"
		:::"r1","r0");
	
	*p = 0x44;  // power off.
	
	while(1);
}

#define LED_PR 0xC0220060

void debug_led(int state)
{
 *(int*)LED_PR=state ? 0x46 : 0x44;
}

void camera_set_led(int led, int state, __attribute__ ((unused))int bright) {
 static char led_table[5]={4,5,7,8,9};
 _LEDDrive(led_table[led%sizeof(led_table)], state<=1 ? !state : state);
}

int get_flash_params_count(void){
 return 120; 
}

void JogDial_CW(void){
 _PostLogicalEventForNotPowerType(0x874, 1);  // RotateJogDialRight, 1 - rotation count
}

void JogDial_CCW(void){
 _PostLogicalEventForNotPowerType(0x875, 1);  // RotateJogDialLeft, 1 - rotation count
}

void *vid_get_viewport_fb_d()
{
    extern char *viewport_fb_d;
	return viewport_fb_d;
}

long vid_get_viewport_height()
{
	return 240;
}


// PTP display stuff
int vid_get_palette_type() { return 4; }  //Test 1, 2 or 4
int vid_get_palette_size() { return 16*4; }

void *vid_get_bitmap_active_palette() {
    return (void *)*(unsigned int*)(0x8378+0x20);  // sub_ff8f3a08, via sub_ff9d9e1c two refs to "Palette Class."
}
void *vid_get_bitmap_active_buffer()
{
    return (void*)(*(int*)(0x8378+0xC)); //"Add: %p Width : %ld Hight : %ld", 
                                         // 100c: sub_ff8f3acc
                                         // 101a: sub_ff8f3ad4
}
