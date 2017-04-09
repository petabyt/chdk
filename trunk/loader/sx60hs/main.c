#include "../generic/check_compat.c"

extern long *blob_chdk_core;
extern long blob_chdk_core_size;

void __attribute__((noreturn)) my_restart()
{
    check_compat();

    long *dst = (long*)MEMISOSTART;
    const long *src = blob_chdk_core;
    long length = (blob_chdk_core_size + 3) >> 2;

    core_copy(src, dst, length);


     *(volatile unsigned *)(0x4ffc)=0x12345678;

    asm volatile ( // fc095c80 102b/102c
    "mov     r1, %1\n"
    "mov     r0, %0\n"
    "ldr     r2, =0xfc1361cf\n" // address is for 100b, 100c, 100f
    "blx     r2\n"              // caching related routine called at fw startup
    "mov     r0, %0\n"
    "add     r0, r0, #1\n"
    "bx      r0\n"
    : : "r"(MEMISOSTART), "r"(((blob_chdk_core_size+3)>>2)<<2) : "memory","r0","r1","r2","r3","r4"
   );

    while(1);
}

