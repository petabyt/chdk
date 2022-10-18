#include "../generic/check_compat.c"

extern long *blob_chdk_core;
extern long blob_chdk_core_size;

void __attribute__((noreturn)) my_restart()
{
     check_compat();

    // light up green LED
    *(int*)0xd20b0994 = 0x4d0002;
    // LED done
    long *dst = (long*)MEMISOSTART;
    const long *src = blob_chdk_core;
    long length = (blob_chdk_core_size + 3) >> 2;

    core_copy(src, dst, length);

    asm volatile (
    "mov     r1, %1\n"
    "mov     r0, %0\n"
    "ldr     r2, =0xfc1267cb\n" // address is OK for 110d, 110f, 111a
    "blx     r2\n"              // clean data cache
    "mov     r0, %0\n"
    "add     r0, r0, #1\n"
    "bx      r0\n"
    : : "r"(MEMISOSTART), "r"(((blob_chdk_core_size+3)>>2)<<2) : "memory","r0","r1","r2","r3","r4"
    );
    while(1);
}

