static void __attribute__((noreturn)) shutdown();
static void __attribute__((noreturn)) panic(int cnt);

extern long *blob_chdk_core;
extern long *blob_copy_and_reset;
extern long blob_chdk_core_size;
extern long blob_copy_and_reset_size;

void __attribute__((noreturn)) my_restart() 
{
    int i;

    void __attribute__((noreturn)) (*copy_and_restart)(char *dst, char *src, long length);

    for (i=0; i<(blob_copy_and_reset_size/sizeof(long)); i++){
	((long*)(RESTARTSTART))[i] = blob_copy_and_reset[i];
    }

    copy_and_restart = (void*)RESTARTSTART;

    copy_and_restart((void*)MEMISOSTART, (char*)blob_chdk_core, blob_chdk_core_size);
}

#define LED_PR 0xC022C30C

static void __attribute__((noreturn)) shutdown()
{
    volatile long *p = (void*)LED_PR;
        
    asm(
         "MRS     R1, CPSR\n"
         "AND     R0, R1, #0x80\n"
         "ORR     R1, R1, #0x80\n"
         "MSR     CPSR_cf, R1\n"
         :::"r1","r0");
        
    *p = *p & 0xFFFFFFCF;  // led off.

    while(1);
}

static void __attribute__((noreturn)) panic(int cnt)
{

	volatile long *p=(void*)LED_PR;
	int i;

	for(;cnt>0;cnt--){
		*p = (*p & 0xFFFFFFCF) | 0x20; // Turn on LED

		for(i=0;i<0x200000;i++){
			asm ("nop\n");
			asm ("nop\n");
		}
		*p = (*p & 0xFFFFFFCF);		 // Turn off LED
		for(i=0;i<0x200000;i++){
			asm ("nop\n");
			asm ("nop\n");
		}
	}
	shutdown();
}
