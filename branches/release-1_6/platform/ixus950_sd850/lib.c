#include "platform.h"

int get_flash_params_count(void){
 return 111;
}

void shutdown()
{
    volatile long *p = (void*)0xc02200a0;
        
    asm(
         "MRS     R1, CPSR\n"
         "AND     R0, R1, #0x80\n"
         "ORR     R1, R1, #0x80\n"
         "MSR     CPSR_cf, R1\n"
         :::"r1","r0");
        
    *p = 0x44;

    while(1);
}
//LED ports:
//AF:		0xC02200C0
//Print (blue):	0xC02200C4
//Orange:		0xC02200C8
//Gr//een:		0xC02200CC
//Yellow: 	0xC02200D0
//Power (green):	0xC02200D4


#define LED_PR 0xC02200C4

void debug_led(int state)
{
    volatile long *p=(void*)LED_PR;
    if (state)
	p[0]=0x46;
    else
	p[0]=0x44;
}

#define LED_BASE 0xC02200C0

void camera_set_led(int led, int state, __attribute__ ((unused))int bright)

{
  int leds[] = {12,16,-1,8,4,0,20}; // cannot quite figure, in which order they're supposed to be..
  if(led < 4 || led > 10 || led == 6) return;
  volatile long *p=(void*)LED_BASE + leds[led-4];
    if (state)
	p[0]=0x46;
    else
	p[0]=0x44;
}

void *vid_get_bitmap_active_buffer()
{
    return (void*)(*(int*)0xa250);  // in sub_FFA2DE78 for 100c
}

void *vid_get_bitmap_active_palette() {
    return (void *)0x584e8;         // in sub_FFA2DE78 for 100c
}

int vid_get_palette_type() { return 1; }
int vid_get_palette_size() { return 16*4; }
