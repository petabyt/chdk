#include "platform.h"
#include "leds.h"

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


void debug_led(int state)
{
    volatile long *p=(void*)LED_PR;
    if (state)
	p[0]=0x46;
    else
	p[0]=0x44;
}


void camera_set_led(int led, int state, int bright)
{
    int leds[] = {0xd0,0x134,0x138,0x134,0x130,0xd4,0x3030,0x3030};  // power=3 | green | yellow | (not used) | orange | blue | af beam | timer
    if(led >= 3 && led <= 10 && led != 6)  //  map to valid params;  no extra TIMER LED (is same as AF)
    {
        volatile long *p=(void*)0xc0220000 + leds[(led-3)%sizeof(leds)];
        if (state)
            p[0]=0x46;
        else
            p[0]=0x44;
    }
} 


int get_flash_params_count(void){
 return 114; //???
}
