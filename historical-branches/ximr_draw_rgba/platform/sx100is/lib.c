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

#define LED_PR	0xc02200C4
#define LED_RED 0xc02200C8
#define LED_GRN	0xc02200CF
#define LED_PWR	0xc02200D0

void led_on(int led)
{
    volatile long *p=(void*)0;
	switch (led) {
		case 0:
			p = (void*)LED_RED;
			break;
		case 1:
			p = (void*)LED_GRN;
			break;
		case 2:
			p = (void*)LED_PWR;
			break;
		case 3:
			p = (void*)LED_PR;
			break;
	}
	if(p) {
		p[0] = 0x46;
	}
}

void led_off(int led)
{
    volatile long *p=(void*)0;
	switch (led) {
		case 0:
			p = (void*)LED_RED;
			break;
		case 1:
			p = (void*)LED_GRN;
			break;
		case 2:
			p = (void*)LED_PWR;
			break;
		case 3:
			p = (void*)LED_PR;
			break;
	}
	if(p) {
		p[0] = 0x44;
	}
}

void debug_led(int state)
{
    volatile long *p=(void*)LED_PR;
    if (state)
	p[0]=0x46;
    else
	p[0]=0x44;
}

#define LED_AF 0xc02200C0

int get_flash_params_count(void){
 return 114;
}

// PTP display stuff
int vid_get_palette_type() { return 1; }
int vid_get_palette_size() { return 16*4; }

void *vid_get_bitmap_active_palette() 
{
    return (void *)0x422f8;        //Found @ 0xffcd22b4 - Two refs to "BmpDDev"
}

void *vid_get_bitmap_active_buffer() 
{
    return (void*)(*(int*)0x99a8); //Found @ 0xffcd22b4 - Two refs to "BmpDDev"
}
