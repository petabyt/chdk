#include "../generic/check_compat.c"

extern long *blob_chdk_core;
extern long blob_chdk_core_size;

void __attribute__((noreturn)) my_restart()
{
//    check_compat();

    long *dst = (long*)MEMISOSTART;
    const long *src = blob_chdk_core;
    long length = (blob_chdk_core_size + 3) >> 2;

    core_copy(src, dst, length);

    // GPIO base = 0xD2080000
    // 0xD20801E4   - SD led
    // 0xD20801E8   - AF led

    // light up green LED
    volatile int* p = (int*)0xD20801E4;
    *p = 0x24D0002;

//    // blinker
//    int i;
//    while (1)
//    {
//        *p = 0x24D0002;
//        for(i=0;i<10000000;i++) {
//            asm volatile(
//            "nop\n"
//            );
//        }
//        *p = 0x24C0003;
//        for(i=0;i<10000000;i++) {
//            asm volatile(
//            "nop\n"
//            );
//        }
//    }

    asm volatile (
            "mov     r1, %1\n"
            "mov     r0, %0\n"
            "ldr     r2, =0xe042eb75\n" // address is OK for 101a
            "blx     r2\n"              // caching related routine called at fw startup
            "mov     r1, %1\n"
            "mov     r0, %0\n"
            "ldr     r2, =0xe042ec4d\n" // address is OK for 101a
            "blx     r2\n"              // caching related routine called at fw startup
            "mov     r0, %0\n"
            "add     r0, r0, #1\n"
            "bx      r0\n"
            : : "r"(MEMISOSTART), "r"(((blob_chdk_core_size+3)>>2)<<2) : "memory","r0","r1","r2","r3","r4"
    );
    while(1);
}

