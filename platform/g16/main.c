#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "keyboard.h"

extern long link_bss_start;
extern long link_bss_end;
extern void boot();

void startup()
{

    long *bss = &link_bss_start;

    // sanity check
    if ((long)&link_bss_end > (MEMISOSTART + MEMISOSIZE)) {      
        //started();
            #define LED_PR     0xd20b0994       // G16 green LED on OVF bezel   
            #define LED_PWR    0xd20b0884       // G16 green LED on power button
            #define LED_ORANGE 0xd20b0888       // G16 orange LED on OVF bezel   
            #define XDELAY 4000000         
            int j = 1000 ;
            while(j-- > 0) {
                int i;
                *(volatile int*)LED_PR = 0x4d0002;
                *(volatile int*)LED_PWR = 0x4d0002;
                *(volatile int*)LED_ORANGE = 0x4d0002;
                for(i=0;i<XDELAY/10;i++) {
                    asm volatile(
                    "nop\n"
                    );
                }
                *(volatile int*)LED_PR = 0x4c0003;
                *(volatile int*)LED_PWR = 0x4c0003;
                *(volatile int*)LED_ORANGE = 0x4c0003;                                
                for(i=0;i<XDELAY;i++) {
                    asm volatile(
                    "nop\n"
                    );
                }
            }  
        shutdown();
    }
  
    // initialize .bss senment
    while (bss<&link_bss_end)
        *bss++ = 0;
    boot();
}

// Conversion factor lens FL --> 35mm equiv G16
// lens      35mm     CF
// ----      ----     --
// 6.1       28       ( 28/ 6.1) * 61 = 280  (min FL)
// 30.5      140      (140/30.5) * 61 = 280  (max FL)

#define CF_EFL      280
#define CF_EFL_DIV  61
#define NUM_FL      122 // G16 1.01c 0xfdf2bd38 to 0xdf2c108
#define NUM_DATA    2   // 2 x 32 bit words each entry, first is FL, second is multiplier (x100)

extern int focus_len_table[NUM_FL*NUM_DATA];
const int zoom_points = NUM_FL;

int get_effective_focal_length(int zp)
{
    return (CF_EFL*get_focal_length(zp))/CF_EFL_DIV;
}

int get_focal_length(int zp)
{
    if (zp < 0) zp = 0;
    else if (zp >= NUM_FL) zp = NUM_FL-1;
    return focus_len_table[zp*NUM_DATA];
}

int get_zoom_x(int zp)
{
    return get_focal_length(zp)*10/focus_len_table[0];
}

// Battery voltage thresholds

long get_vbatt_min() { return 6450; }
long get_vbatt_max() { return 8250; }
