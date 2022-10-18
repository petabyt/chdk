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
    *(volatile int*)0xd20b0994 = 0x4d0002;
    // blinker
    /*
    while(1) {
        int i;
        *(volatile int*)0xd20b0994 = 0x4d0002;
        for(i=0;i<1000000;i++) {
            asm volatile(
            "nop\n"
            );
        }
        *(volatile int*)0xd20b0994 = 0x4c0003;
        for(i=0;i<1000000;i++) {
            asm volatile(
            "nop\n"
            );
        }
    }
    */

    // allows boot on short press without fiddling sub_fc075b56 values or modifying/replacing sub_fc0781f4 (100d addresses)
    // not clear why not set after DISKBOOT.BIN reboot
    *(volatile unsigned *)(0x4ffc)=0x12345678;
// Restart appears to be fc0bd9de (refs to 12345678, fc020001,)
// similar to sx280 fc095c40, but cp15 manipulation does not appear to be the same
// fc157748 called at equivalent location does some, but not equivalent to sx280 code
    asm volatile ( 
    "mov     r1, %1\n"
    "mov     r0, %0\n"
    "ldr     r2, =0xfc133daf\n" // based on sx280, identical in 100b, 100c and 100d. function called in startup after ROM->RAM code copy
    "blx     r2\n"              // doesn't appear to flush/clean instruction cache?
    
    // start execution at MEMISOSTART in thumb mode
    "mov     r0, %0\n"
    "add     r0, r0, #1\n"
    "bx      r0\n"
    : : "r"(MEMISOSTART), "r"(((blob_chdk_core_size+3)>>2)<<2) : "memory","r0","r1","r2","r3","r4"
    );
    while(1);
}

