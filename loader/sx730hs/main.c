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

    // light up green LED - verified
/*
    *(volatile int*)0xd20b0994 = 0x4d0002;
    // blinker
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
// 
    // on G7X allows boot on short press without fiddling variables in startup code
    // not tried on sx730
//    *(volatile unsigned *)(0x4ffc)=0x12345678;
    asm volatile ( 
    "mov     r1, %1\n"
    "mov     r0, %0\n"
//    "ldr     r2, =0xfc0db23f\n" // function called in startup after ROM->RAM code copy, sx730 100d
//    "blx     r2\n"
    "bl cache_func_my\n" // different address on 100c, copied inline
    // start execution at MEMISOSTART in thumb mode
    "mov     r0, %0\n"
    "add     r0, r0, #1\n"
    "bx      r0\n"
    : : "r"(MEMISOSTART), "r"(((blob_chdk_core_size+3)>>2)<<2) : "memory","r0","r1","r2","r3","r4"
    );
    while(1);
}
// 100d -f=chdk -s=0xfc0db23f -eret=2
void __attribute__((naked,noinline)) cache_func_my() {
    asm volatile (
"    cmp.w   r1, #0x4000\n"
"    bhs     loc_fc0db260\n"
"    dsb     sy\n"
"    add     r1, r0\n"
"    bic     r0, r0, #0x1f\n"
"loc_fc0db24e:\n"
"    mcr     p15, #0, r0, c7, c10, #1\n"
"    add.w   r0, r0, #0x20\n"
"    cmp     r0, r1\n"
"    blo     loc_fc0db24e\n"
"    dsb     sy\n"
"    bx      lr\n"
"loc_fc0db260:\n"
"    dsb     sy\n"
"    mov.w   r1, #0\n"
"loc_fc0db268:\n"
"    mov.w   r0, #0\n"
"loc_fc0db26c:\n"
"    orr.w   r2, r1, r0\n"
"    mcr     p15, #0, r2, c7, c10, #2\n"
"    add.w   r0, r0, #0x20\n"
"    cmp.w   r0, #0x1000\n"
"    bne     loc_fc0db26c\n"
"    add.w   r1, r1, #0x40000000\n"
"    cmp     r1, #0\n"
"    bne     loc_fc0db268\n"
"    dsb     sy\n"
"    bx      lr\n"
".ltorg\n"
    );
}
