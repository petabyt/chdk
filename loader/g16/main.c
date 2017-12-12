#include "../generic/check_compat.c"

extern long *blob_chdk_core;
extern long blob_chdk_core_size;

#define LED_PR     0xd20b0994       // G16 green LED on OVF bezel                                                                              
#define LED_PWR    0xd20b0884       // G16 green LED on power button
#define LED_ORANGE 0xd20b0888       // G16 orange LED on OVF bezel


#if 0
void xblinker(int j) 
{
    while(j-- > 0) {
        int i;
        *(volatile int*)LED_ORANGE = 0x4d0002;
        for(i=0;i<3000000;i++) {
            asm volatile(
            "nop\n"
            );
        }
        *(volatile int*)LED_ORANGE = 0x4c0003;
        for(i=0;i<2000000;i++) {
            asm volatile(
            "nop\n"
            );
        }
    }

    j=30 ;
    while(--j>0) {
        int i;
        for(i=0;i<2000000;i++) {
            asm volatile(
            "nop\n"
            );
        }
    }
}
#endif

      
void __attribute__((noreturn)) my_restart()
{
    
    //xblinker(3) ;
    
    check_compat();

    long *dst = (long*)MEMISOSTART;
    const long *src = blob_chdk_core;
    long length = (blob_chdk_core_size + 3) >> 2;

    core_copy(src, dst, length);

    // light up green LED
    //*(int*)0xd20b0994 = 0x4d0002;
    
    // light up orange LED
    //*(int*)0xd20b0888 = 0x4d0002;
    
    // allows boot on short press without fiddling elsewhere
    *(volatile unsigned *)(0x4ffc)=0x12345678;  // @ 0xfc0b59ee for g16 100h 101a 101c
    
    //xblinker(2) ;

    asm volatile ( 
    
    "mov     r1, %1\n"
    "mov     r0, %0\n"
    
    //"ldr     r2, =0xfc13c4d7\n" // caching related routine called at fw startup after ROM->RAM code copy
    //"blx     r2\n"              // G16 1.00h 0xfc13c4d6   1.01a  0xfc13c4d6  1.01c 0xfc13c50e   
    
            "    cmp.w   r1, #0x4000\n"
            "    bhs     L2\n"
            "    dsb     sy\n"
            "    add     r1, r0\n"
            "    bic     r0, r0, #0x1f\n"
            "L1:\n"
            "    mcr     p15, #0, r0, c7, c10, #1\n"
            "    add.w   r0, r0, #0x20\n"
            "    cmp     r0, r1\n"
            "    blo     L1\n"
            "    dsb     sy\n"
            "    b L5\n"
            "L2:\n"
            "    dsb     sy\n"
            "    mov.w   r1, #0\n"
            "L3:\n"
            "    mov.w   r0, #0\n"
            "L4:\n"
            "    orr.w   r2, r1, r0\n"
            "    mcr     p15, #0, r2, c7, c10, #2\n"
            "    add.w   r0, r0, #0x20\n"
            "    cmp.w   r0, #0x1000\n"
            "    bne     L4\n"
            "    add.w   r1, r1, #0x40000000\n"
            "    cmp     r1, #0\n"
            "    bne     L3\n"
            "    dsb     sy\n"
            "L5:\n"

    // start execution at MEMISOSTART in thumb mode    
    "mov     r0, %0\n"
    "add     r0, r0, #1\n"
    "bx      r0\n"
    : : "r"(MEMISOSTART), "r"(((blob_chdk_core_size+3)>>2)<<2) : "memory","r0","r1","r2","r3","r4"
    );
    while(1);
}

