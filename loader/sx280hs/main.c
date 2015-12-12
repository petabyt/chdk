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

    // light up green LED
    *(int*)0xd20b0994 = 0x4d0002;
    // LED done

    asm volatile ( // fc095c80 102b/102c
/*    "movs    r0, #0x78\n"
    "mcr     p15, 0, r0, c1, c0\n"
    "movs    r0, #0\n"
    "mcr     p15, 0, r0, c7, c10, 4\n"
    "mcr     p15, 0, r0, c7, c5\n"
    "mcr     p15, 0, r0, c7, c6\n"
    "movw    r0, #0x4006\n"
    "mcr     p15, 0, r0, c9, c1\n"
    "mcr     p15, 0, r0, c9, c1, 1\n"
    "mrc     p15, 0, r0, c1, c0\n"
    "orr.w   r0, r0, #0x50000\n"
    "mcr     p15, 0, r0, c1, c0\n"
    "movw    r1, #0x4ffc\n"
    "ldr     r0, =0x12345678\n"
    "str     r0, [r1, #0]\n"
    //"ldr     r0, =0xfc020000\n"*/
    "mov     r1, %1\n"
    "mov     r0, %0\n"
    "ldr     r2, =0xfc12dd3b\n" // address is OK for 102b and 102c
    "blx     r2\n"              // caching related routine called at fw startup
    "mov     r0, %0\n"
    "add     r0, r0, #1\n"
    "bx      r0\n"
    : : "r"(MEMISOSTART), "r"(((blob_chdk_core_size+3)>>2)<<2) : "memory","r0","r1","r2","r3","r4"
    );
    while(1);
}

