#include "../generic/check_compat.c"

extern long *blob_chdk_core;
extern long blob_chdk_core_size;

// DEBUG: blink led
//#define LED_AF 0xc022d200
//#define DELAY 5000000

void __attribute__((noreturn)) my_restart()
{
// DEBUG: blink led
  //  volatile long *p1 = (void*)LED_AF;
    //int counter;
    //counter = DELAY; *p1 = 0x93d800;  while (counter--) { asm("nop\n nop\n"); };
    //counter = DELAY; *p1 = 0x83dc00;  while (counter--) { asm("nop\n nop\n"); };
    {
        long *dst = (long*)MEMISOSTART;
        const long *src = blob_chdk_core;
        long length = (blob_chdk_core_size + 3) >> 2;

  core_copy(src, dst, length);
    }

    // restart function
    // from sub_FF038ADC via 0x23456789  ixus190_elph200 
    asm volatile (
		"    MOV     R0, #0x78 \n" 
		"    MCR     p15, 0, R0, c1, c0 \n" 
		"    MOV     R0, #0 \n" 
		"    MCR     p15, 0, R0, c7, c10, 4 \n" 
		"    MCR     p15, 0, R0, c7, c5 \n" 
		"    MCR     p15, 0, R0, c7, c6 \n" 
		"    MOV     R0, #0x80000006 \n" 
		"    MCR     p15, 0, R0, c9, c1 \n" 
		"    MCR     p15, 0, R0, c9, c1, 1 \n" 
		"    MRC     p15, 0, R0, c1, c0 \n" 
		"    ORR     R0, R0, #0x50000 \n" 
		"    MCR     p15, 0, R0, c1, c0 \n" 
		"    LDR     R0, =0x23456789 \n" 
		"    MOV     R1, #0x80000000 \n" 
		//"    STR     R0, [R1, #0xFFC] \n" 
		//"    LDR     R0, =sub_FF020000 \n" 
		"    MOV     R0, %0\n"              // new jump-vector
		"    BLX     R0 \n"
		"    MOV     R0, #1 \n"		
		//"    LDMFD   SP!, {R4,PC} \n"  
         : : "r"(MEMISOSTART) : "memory","r0","r1","r2","r3","r4"
        );

        while(1);
}

