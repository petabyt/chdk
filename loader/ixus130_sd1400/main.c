// static void __attribute__((noreturn)) shutdown();
// static void __attribute__((noreturn)) panic(int cnt);

extern long *blob_chdk_core;
// extern long *blob_copy_and_reset;
extern long blob_chdk_core_size;
// extern long blob_copy_and_reset_size;



void __attribute__((noreturn)) my_restart() 
{
  {
  // char *dst = dst_void;
  // const char *src = src_void;
  long *dst = (long*)MEMISOSTART;
  const long *src = blob_chdk_core;
  long length = (blob_chdk_core_size + 3) >> 2;

  if (src < dst && dst < src + length)
    {
    /* Have to copy backwards */
    src += length;
    dst += length;
    while (length--)  *--dst = *--src;
    }
  else
    while (length--)  *dst++ = *src++;
  }

  // found at address 0xff83b9c0
  asm volatile (
        "mrs    r0, CPSR\n"
        "bic    r0, r0, #63\n"  // 0x3f
        "orr    r0, r0, #211\n" // 0xd3
        "msr    CPSR, r0\n"
        "ldr    r1, =0xc0200000\n" // was: "[pc, #164]  ; ff83ba7c" 
        "mvn    r0, #0\n"       // 0x0
        "str    r0, [r1, #268]\n"
        "str    r0, [r1, #12]\n"
        "str    r0, [r1, #28]\n"
        "str    r0, [r1, #44]\n"
        "str    r0, [r1, #60]\n"
        "str    r0, [r1, #76]\n"
        "str    r0, [r1, #92]\n"
        "str    r0, [r1, #108]\n"
        "str    r0, [r1, #124]\n"
        "str    r0, [r1, #140]\n"
        "str    r0, [r1, #156]\n"
        "str    r0, [r1, #172]\n"
        "str    r0, [r1, #188]\n"
        "str    r0, [r1, #204]\n"
        "str    r0, [r1, #220]\n"
        "str    r0, [r1, #236]\n"
        "cmp    r4, #7\n"       // 0x7
        "str    r0, [r1, #252]\n"
        "popeq  {r4, pc}\n"
        "ldr    r0, =0x78\n" // was: "mov ..., #120"
        "mcr    15, 0, r0, cr1, cr0, 0\n"
        "ldr    r0, =0x0\n" // was: "mov ..., #0"
        "mcr    15, 0, r0, cr7, cr10, 4\n"
        "mcr    15, 0, r0, cr7, cr5, 0\n"
        "mcr    15, 0, r0, cr7, cr6, 0\n"
        "ldr    r0, =0x80000006\n" // was: "mov ..., #-2147483642"
        "mcr    15, 0, r0, cr9, cr1, 0\n"
        "mcr    15, 0, r0, cr9, cr1, 1\n"
        "mrc    15, 0, r0, cr1, cr0, 0\n"
        "orr    r0, r0, #327680\n"      // 0x50000
        "mcr    15, 0, r0, cr1, cr0, 0\n"
        "ldr    r0, =0x12345678\n" // was: "[pc, #36]   ; ff83ba80" 
        "ldr    r1, =0x80000000\n" // was: "mov ..., #-2147483648"
        "str    r0, [r1, #4092]\n"
        //"ldr    r0, =0xff810000\n" // changed to:
        "mov    r0, %0\n"
        "pop    {r4, lr}\n"
        "bx     r0\n"
        : : "r"(MEMISOSTART) : "memory","r0","r1","r2","r3","r4");

  while(1);
}


// static void __attribute__((noreturn)) shutdown()
// {
//     volatile long *p = (void*)0xC022001C;       // from task_Bye (not really complete)
//         
//     asm(
//          "MRS     R1, CPSR\n"
//          "AND     R0, R1, #0x80\n"
//          "ORR     R1, R1, #0x80\n"
//          "MSR     CPSR_cf, R1\n"
//          :::"r1","r0");
//         
//     *p = 0x44;
// 
//     while(1);
// }
// 
// #define LED_PR 0xC0220134
// static void __attribute__((noreturn)) panic(int cnt)
// {
// 	volatile long *p=(void*)LED_PR;
// 	int i;
// 
// 	for(;cnt>0;cnt--){
// 		p[0]=0x46;
// 
// 		for(i=0;i<0x200000;i++){
// 			asm ("nop\n");
// 			asm ("nop\n");
// 		}
// 		p[0]=0x44;
// 		for(i=0;i<0x200000;i++){
// 			asm ("nop\n");
// 			asm ("nop\n");
// 		}
// 	}
// 	shutdown();
// }
