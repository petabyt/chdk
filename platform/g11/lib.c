#include "platform.h"
#include "lolevel.h"

void shutdown()
{
    volatile long *p = (void*)0xC0220240; // G11
    
    asm(
         "MRS     R1, CPSR\n"
         "AND     R0, R1, #0x80\n"
         "ORR     R1, R1, #0x80\n"
         "MSR     CPSR_cf, R1\n"
         :::"r1","r0");
        
    *p = 0x44;

    while(1);
}


#define LED_PR 0xC0220128 //EV LED

void debug_led(int state)
{
    volatile long *p=(void*)LED_PR;
    if (state)
	p[0]=0x46;
    else
	p[0]=0x44;
}

/*
0 Upper LED near EVF in Green
1 Upper LED near EVF in Orange
2 Lower LED near EVF
3 LED in power button
4 AF assist LED
5 LED next to ISO Dial
6 LED next EV +/- Dial 
*/
void camera_set_led(int led, int state, __attribute__ ((unused))int bright) {
	static char led_table[7]={0,1,2,3,10,14,15};
    _LEDDrive(led_table[led%sizeof(led_table)], state<=1 ? !state : state);
}

int get_flash_params_count(void) { return 0x84; }                          // Found @0xff9968bc

void JogDial_CW(void){
 _PostLogicalEventForNotPowerType(0x874, 1);  // RotateJogDialRight
}

void JogDial_CCW(void){
 _PostLogicalEventForNotPowerType(0x875, 1);  // RotateJogDialLeft
}


char *camera_jpeg_count_str()
{
    extern char jpeg_count_str[];
	return jpeg_count_str;
}

char *hook_raw_image_addr()
{
    return (char*)0x41C0F460;  // G11 search for aCrwaddressLxCr " CrwAddress %lx, CrwSize H %ld V %ld\r" 0x41c0f460 0xEA0 0xAE0
							   // or for aCrawBuffP      DCB "CRAW BUFF       %p",0
}

void vid_bitmap_refresh()
{
	 extern int enabled_refresh_physical_screen; // screen lock counter
	 extern void _ScreenUnlock();

	 _ScreenLock();
	  enabled_refresh_physical_screen = 1;
	 _ScreenUnlock();
}

void *vid_get_bitmap_fb()       
{
	return (void*)0x40471000; // G11 OK 100j loc_FF85A4BC ir 0xFF85A4C0 (at end of function DispCon_ShowBlackChart
}

void *vid_get_viewport_fb()
{
	
		return (void*)0x40587700;
/*
100j
ROM:FFB067B0 28 12 9F E5                             LDR     R1, =0x40587700 ; Load from Memory
ROM:FFB067B4 20 02 9F E5                             LDR     R0, =0x7E900    ; Load from Memory
ROM:FFB067B8 00 10 84 E5                             STR     R1, [R4]        ; Store to Memory
ROM:FFB067BC 04 00 84 E5                             STR     R0, [R4,#4]     ; Store to Memory
ROM:FFB067C0 95 0F 8F E2                             ADR     R0, aVramAddressP ; "VRAM Address  : %p\r"
*/

}

// Viewport and Bitmap values that shouldn't change across firmware versions.
// Values that may change are in lib.c for each firmware version.

int vid_get_viewport_width()
{
	return 360;
}

long vid_get_viewport_height()
{
   return 240;
}

// Y multiplier for cameras with 480 pixel high viewports (CHDK code assumes 240)
int vid_get_viewport_yscale() {
	return 2;               // G11 viewport is 480 pixels high
}

void *vid_get_viewport_fb_d()
{
    extern char *viewport_fb_d;
	return viewport_fb_d;
}

void *vid_get_viewport_live_fb()
{
    extern char active_viewport_buffer;
    extern void* viewport_buffers[];

    int buf = active_viewport_buffer-1;
    if(buf < 0) {
        buf = 2;
    }
    // Hopefully return the most recently used viewport buffer so that motion detect, histogram, zebra and edge overly are using current image data
    return viewport_buffers[buf];
}

// Functions for PTP Live View system
int vid_get_palette_type()                      { return 3 ; }          // 1,2,3,4,or 5
int vid_get_palette_size()                      { return 256 * 4 ; }    // 16*4 or 256*4

void *vid_get_bitmap_active_palette()
{
    extern int active_palette_buffer;
    extern char** palette_buffer_ptr;
    return palette_buffer_ptr[active_palette_buffer]+8;
}
