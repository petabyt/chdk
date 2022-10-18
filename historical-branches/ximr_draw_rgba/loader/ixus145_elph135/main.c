#include "../generic/check_compat.c"

extern long *blob_chdk_core;
extern long blob_chdk_core_size;

void __attribute__((noreturn)) my_restart() 
{
    // DEBUG: blink led
    /*
    int counter;

    while(1) {
    counter = DELAY; *DEBUG_LED = 0x46;  while (counter--) { asm("nop\n nop\n"); };
    counter = DELAY; *DEBUG_LED = 0x44;  while (counter--) { asm("nop\n nop\n"); };
    }
    */

    long *dst = (long*)MEMISOSTART;
    const long *src = blob_chdk_core;
    long length = (blob_chdk_core_size + 3) >> 2;

  core_copy(src, dst, length);

    // ROM:FF826C68 resetcode here:
    // search for "0x12345678"
    // [sx170]	
  asm volatile (
		//"    BL	   sub_FF863224 \n" 
		//"    BL	   sub_003F79A4 \n" 
		//"    BL	   sub_003F6884 \n" 
		//"    BL	   sub_FF88DC4C \n" 
		//"    CMP	   R4, #7 \n" 
		//"    LDMEQFD SP!, {R4,PC} \n" 
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
"    LDR     R0, =0x12345678 \n"
"    MOV     R1, #0x80000000 \n"
"    STR     R0, [R1, #0xFFC] \n"
		//"    LDR	   R0, =0xFF820000 \n" 
		"MOV     R0, %0\n"              // new jump-vector				
		"    LDMFD   SP!, {R4,LR} \n" 
"    BX      R0 \n"
		: : "r"(MEMISOSTART) : "memory","r0","r1","r2","r3","r4"
	);
  while(1);
}