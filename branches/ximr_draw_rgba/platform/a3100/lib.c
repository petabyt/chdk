#include "platform.h"
#include "lolevel.h"

void shutdown()
{
    volatile long *p = (void*)0xC0220010;
    
    asm(
         "MRS     R1, CPSR\n"
         "AND     R0, R1, #0x80\n"
         "ORR     R1, R1, #0x80\n"
         "MSR     CPSR_cf, R1\n"
         :::"r1","r0");
        
    *p = 0x44;

    while(1);
}


#define LED_PR 0xC0220010

void debug_led(int state)
{
    volatile long *p=(void*)LED_PR;
    if (state)
	p[0]=0x46;
    else
	p[0]=0x44;
}

/*
M:FFC24CDC sub_FFC24CDC                            ; CODE XREF: sub_FFC24E54+48
ROM:FFC24CDC                                         ; DATA XREF: sub_FFC24E54+34
ROM:FFC24CDC                 STMFD   SP!, {R4,LR}
ROM:FFC24CE0                 MOV     R1, #0
ROM:FFC24CE4                 MOV     R0, #4
ROM:FFC24CE8                 BL      LEDDrive
ROM:FFC24CEC                 MOV     R1, #0
ROM:FFC24CF0                 MOV     R0, #2
ROM:FFC24CF4                 BL      LEDDrive
ROM:FFC24CF8                 MOV     R1, #0
ROM:FFC24CFC                 MOV     R0, #0
ROM:FFC24D00                 BL      LEDDrive
ROM:FFC24D04                 MOV     R1, #0
ROM:FFC24D08                 MOV     R0, #7
ROM:FFC24D0C                 BL      LEDDrive
ROM:FFC24D10                 LDMFD   SP!, {R4,LR}
ROM:FFC24D14                 MOV     R1, #0
ROM:FFC24D18                 MOV     R0, #8
ROM:FFC24D1C                 B       LEDDrive
ROM:FFC24D1C ; End of function sub_FFC24CDC

*/
#define LED_BASE 0xc0220000

void camera_set_led(int led, int state, __attribute__ ((unused))int bright)

{
  int leds[] = {16,0,5,4,0,9,0}; // power, backlight bright, backlight normal, af assist
  if(led < 4 || led > 10) return;
  led -= 4;
  if (leds[led])
  {
    volatile long *p=(void*)LED_BASE + leds[led];
    if (state)
	p[0]=0x46;
    else
	p[0]=0x44;
  }
}


/*void camera_set_led(int led, int state, int bright) {
	
	static char led_table[10]={0,9};
	_LEDDrive(led_table[led%sizeof(led_table)], state<=1 ? !state : state);
}*/


int get_flash_params_count(void){
/*
ROM:FFD36E08                 BIC     R4, R4, #0x4000
ROM:FFD36E0C                 CMP     R4, #0x94
ROM:FFD36E10                 LDRCS   R0, =aPropertytablem ; "PropertyTableManagerCore.c"
*/
 return 0x94;
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

// Defined in stubs_min.S
extern char active_viewport_buffer;
extern void* viewport_buffers[];

// Live picture buffer (shoot not pressed)
void *vid_get_viewport_live_fb()
{
    unsigned char buff = (unsigned char) active_viewport_buffer;
    if (buff == 0) buff = 2;  else buff--;
    return viewport_buffers[buff];
}

// Functions for PTP Live View system

void *vid_get_bitmap_active_palette() {
        return (void*)(*(int*)(0x4c18+0x20));  //Found @ 0xff8ebce8 a3100 100a
}

// 64 entry palette based on 100a 0xff8ebce8
int vid_get_palette_type()                      { return 4; }
int vid_get_palette_size()                      { return 16*4; }

void *vid_get_bitmap_active_buffer()
{
    return (void*)(*(int*)(0x4c18+0xC)); //found @ 0xff8ebda4 a3100 100a
}
