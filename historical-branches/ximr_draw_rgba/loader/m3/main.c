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
    // caching related routine called at fw startup
    "blx     clean_data_cache_line_my\n" // function copied since address varies between 101a (0xc1300b3) and 120f(0xfc13019b)
    "mov     r0, %0\n"
    "add     r0, r0, #1\n"
    "bx      r0\n"
    : : "r"(MEMISOSTART), "r"(((blob_chdk_core_size+3)>>2)<<2) : "memory","r0","r1","r2","r3","r4"
    );
    while(1);
}

void __attribute__((naked,noinline)) clean_data_cache_line_my() {
    asm volatile (
" loc_fc13019a:\n"
"     cmp.w   r1, #0x4000\n"
"     bcs.n   loc_fc1301bc\n"
"     dsb sy\n"
"     add r1, r0\n"
"     bic.w   r0, r0, #0x1f\n"
" loc_fc1301aa:\n"
"     mcr 15, 0, r0, cr7, cr10, 1\n"
"     add.w   r0, r0, #0x20\n"
"     cmp r0, r1\n"
"     bcc.n   loc_fc1301aa\n"
"     dsb sy\n"
"     bx  lr\n"
" loc_fc1301bc:\n"
"     dsb sy\n"
"     mov.w   r1, #0\n"
" loc_fc1301c4:\n"
"     mov.w   r0, #0\n"
" loc_fc1301c8:\n"
"     orr.w   r2, r1, r0\n"
"     mcr 15, 0, r2, cr7, cr10, 2\n"
"     add.w   r0, r0, #0x20\n"
"     cmp.w   r0, #0x1000\n"
"     bne.n   loc_fc1301c8\n"
"     add.w   r1, r1, #0x40000000\n"
"     cmp r1, #0\n"
"     bne.n   loc_fc1301c4\n"
"     dsb sy\n"
"     bx  lr\n"
".ltorg\n"
    );
}	
