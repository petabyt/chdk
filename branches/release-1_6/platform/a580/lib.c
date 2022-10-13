#include "platform.h"

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


#define LED_PR 0xc02200C4

void debug_led(int state)
{
    volatile long *p=(void*)LED_PR;
    if (state)
	p[0]=0x46;
    else
	p[0]=0x44;
}

#define LED_AF 0xc0220080

int get_flash_params_count(void){
 return 115; //Corrected! from 114 (x73 = 115 form Stubs_Entry.S)
}

// PTP display stuff
int vid_get_palette_type() { return 1; }
int vid_get_palette_size() { return 16*4; }

void *vid_get_bitmap_active_palette() 
{
    return (void *)0x3CEC0;        //Found @ 0xffcc4b7c - Two refs to "BmpDDev"
}

void *vid_get_bitmap_active_buffer() 
{
    return (void*)(*(int*)0x752c); //Found @ 0xffcc4b7c - Two refs to "BmpDDev"
}
