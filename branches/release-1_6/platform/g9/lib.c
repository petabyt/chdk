#include "platform.h"

void shutdown()
{
    volatile long *p = (void*)0xc022006C;
        
    asm(
         "MRS     R1, CPSR\n"
         "AND     R0, R1, #0x80\n"
         "ORR     R1, R1, #0x80\n"
         "MSR     CPSR_cf, R1\n"
         :::"r1","r0");
        
    *p = 0x44;

    while(1);
}

char *camera_jpeg_count_str()
{
    return (char*)0x60354;
}

#define LED_PR 0xC022006C //used iso blue, was 0xc02200C4  //a650- 0xc02200C4


void debug_led(int state)
{
    volatile long *p=(void*)LED_PR;
    if (state)
	p[0]=0x46;
    else
	p[0]=0x44;
}

#define LED_BASE 0xc0220080
#define LED_AF 0xC0220094//was 0xc0220080 //a650- 0xc0220080//from g7

void camera_set_led1(int led, int state, __attribute__ ((unused))int bright)//?
{
  int leds[] = {12,16,4,8,4,0,4};
  if(led < 4 || led > 10 || led == 6) return;
  volatile long *p=(void*)LED_BASE + leds[led-4];
    if (state)
	p[0]=0x46;
    else
	p[0]=0x44;
}


int get_flash_params_count(void){
 return 114;	//++  FF956AEC
}

void *vid_get_viewport_live_fb() //By comparison to A720 - UNTESTED
{
    void **fb=(void **)0x228C;
    unsigned char buff = *((unsigned char*)0x2124);
    if (buff == 0) {
        buff = 2;
    }
    else {
        buff--;
    }
    return fb[buff];
}

void *vid_get_bitmap_fb()
{ 
    return (void*)0x10361000; 
}

void *vid_get_viewport_fb()
{ 
    return (void*)0x1067b540; 
}

long vid_get_viewport_height()
{
    return 240;
}

// PTP display stuff
int vid_get_palette_type() { return 1; } //UNTESTED
int vid_get_palette_size() { return 16*4; } //UNTESTED

void *vid_get_bitmap_active_palette() 
{
    return (void *)0x47ce8;        //Found @ 0xff8f5e4c - Two refs to "BmpDDev"
}

void *vid_get_bitmap_active_buffer() 
{
    return (void*)(*(int*)0xd548); //Found @ 0xff8f5e50 - Two refs to "BmpDDev"
}
