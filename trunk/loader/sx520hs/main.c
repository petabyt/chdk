#include "../generic/check_compat.c"

extern long *blob_chdk_core;
extern long blob_chdk_core_size;

void debug_pisca_led(int n)
{
  	volatile long *p = (void*)0xC022D1FC;

	int cnt=0, i=0;
	for(;cnt<n;cnt++)
	{
		*p = 0x93d800;
 
		for(i=0; i<0x100000; i++)
		{
			asm ("nop\n");
			asm ("nop\n");
		}
		*p = 0x83dc00;

		for(i=0; i<0x100000; i++)
		{
			asm ("nop\n");
			asm ("nop\n");
		}
	}  	
}

void __attribute__((noreturn)) my_restart() 
{
	{
        long *dst = (long*)MEMISOSTART;
        const long *src = blob_chdk_core;
        long length = (blob_chdk_core_size + 3) >> 2;

  core_copy(src, dst, length);

}

    // restart function
    // from sub_FF83846C via 0x12345678    
	asm volatile (
		"    MOV     R0, #0x78 \n"
		"    MCR     p15, 0, R0,c1,c0 \n"
		"    MOV     R0, #0 \n"
		"    MCR     p15, 0, R0,c7,c10, 4 \n"
		"    MCR     p15, 0, R0,c7,c5 \n"
		"    MCR     p15, 0, R0,c7,c6 \n"
		"    MOV     R0, #0x80000006 \n"
		"    MCR     p15, 0, R0,c9,c1 \n"
		"    MCR     p15, 0, R0,c9,c1, 1 \n"
		"    MRC     p15, 0, R0,c1,c0 \n"
		"    ORR     R0, R0, #0x50000 \n"
		"    MCR     p15, 0, R0,c1,c0 \n"
		"    LDR     R0, =0x12345678 \n"
		"    MOV     R1, #0x80000000 \n"
		"    STR     R0, [R1,#0xFFC] \n"
//		"    LDR     R0, =0xFF020000 \n"
		"MOV     R0, %0\n"              // new jump-vector				
		"    LDMFD   SP!, {R4,LR} \n" 
		"    BX	   R0 \n" 
		: : "r"(MEMISOSTART) : "memory","r0","r1","r2","r3","r4"
	);
	while(1);
}

