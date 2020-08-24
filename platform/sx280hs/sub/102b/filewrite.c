#include "lolevel.h"
#include "platform.h"

// NOTE: file is based on G16 filewrite.c (including comments), struct offsets appear to match

extern void _LogCameraEvent(int id,const char *fmt,...);

typedef struct {
    unsigned int address;
    unsigned int length;
} cam_ptp_data_chunk; //camera specific structure

#define MAX_CHUNKS_FOR_FWT 7 // filewritetask is prepared for this many chunks
                              // Note : corresponds to filewritetask() jump table entries 0-6
/*
 * fwt_data_struct: defined here as it's camera dependent
 * unneeded members are designated with unkn
 * file_offset, full_size, seek_flag only needs to be defined for cameras with CAM_FILEWRITETASK_SEEK/CAM_FILEWRITETASK_MULTIPASS
 * pdc is always required, name is not currently used
 */
typedef struct
{
    int unkn1;                // 00 message number
    int file_offset;          // 01
    int maybe_full_size;      // 02 TODO doesn't seem to actually be full size for jpeg, instead round number somewhat smaller
    int unkn2, unkn3;         // 03, 04
    cam_ptp_data_chunk pdc[MAX_CHUNKS_FOR_FWT];  // 05 - 18
    int maybe_seek_flag;      // 19 from sub_fc054ea8 0x4C = 74 bytes,  74/4 = 19 words offset in fwt_data_struct
    int unkn5, unkn6;         // 20, 21
    char name[32];            // 22 from sub_fc054ea8  0x58 = 88 bytes,  88/4 = 22 words offset in fwt_data_struct
} fwt_data_struct;

#include "../../../generic/filewrite.c"

#if 0
void log_fwt_msg(fwt_data_struct *fwd)
{
    int m=fwd->unkn1;
    _LogCameraEvent(0x60,"fw m:%d o:0x%08x fs:0x%08x sf:0x%x",m,fwd->file_offset,fwd->maybe_full_size,fwd->maybe_seek_flag);
    _LogCameraEvent(0x60,"fw %s",fwd->name);
    if(m >= 0 && m <=6) {
        _LogCameraEvent(0x60,"fw chunk adr:0x%08x l:0x%08x",fwd->pdc[m].address,fwd->pdc[m].length);
    }
    _LogCameraEvent(0x60,"fw u %08x %08x %08x %08x %08x",fwd->unkn2,fwd->unkn3,fwd->unkn5,fwd->unkn6);
}

void log_fwt_start(void)
{
    _LogCameraEvent(0x60,"fw start");
}
#endif

/*************************************************************/
void __attribute__((naked,noinline)) filewritetask() {
asm volatile (
// -f=chdk -s=task_FileWrite -c=73 -stubs PRIMARY.BIN 0xfc000000
// task_FileWriteTask 0xfc05509d
"    push    {r2, r3, r4, r5, r6, lr}\n"
"    ldr     r5, =0x0001b294\n"
"loc_fc0550a0:\n"
"    movs    r2, #0\n"
"    add     r1, sp, #4\n"
"    ldr     r0, [r5, #0x10]\n"
"    blx     sub_fc251bfc\n" // j_ReceiveMessageQueue
"    cbz     r0, loc_fc0550b8\n"
"    movs    r0, #0\n"
"    movw    r2, #0x3ef\n"
"    ldr     r1, =0xfc05522c\n" //  *"dwFWrite.c"
"    blx     sub_fc251d14\n" // j_DebugAssert
"loc_fc0550b8:\n"
"    ldr     r0, [sp, #4]\n"
"    ldr     r1, [r0]\n"
"    cmp     r1, #0xd\n"
"    bhs     loc_fc0550a0\n"
"    tbb     [pc, r1]\n" // (jumptable r1 13 elements)
"branchtable_fc0550c4:\n"
"    .byte((loc_fc05515e - branchtable_fc0550c4) / 2)\n" // (case 0)
"    .byte((loc_fc05515e - branchtable_fc0550c4) / 2)\n" // (case 1)
"    .byte((loc_fc05515e - branchtable_fc0550c4) / 2)\n" // (case 2)
"    .byte((loc_fc05515e - branchtable_fc0550c4) / 2)\n" // (case 3)
"    .byte((loc_fc05515e - branchtable_fc0550c4) / 2)\n" // (case 4)
"    .byte((loc_fc05515e - branchtable_fc0550c4) / 2)\n" // (case 5)
"    .byte((loc_fc05515e - branchtable_fc0550c4) / 2)\n" // (case 6)
"    .byte((loc_fc055164 - branchtable_fc0550c4) / 2)\n" // (case 7)
"    .byte((loc_fc0550d2 - branchtable_fc0550c4) / 2)\n" // (case 8)
"    .byte((loc_fc0550fc - branchtable_fc0550c4) / 2)\n" // (case 9)
"    .byte((loc_fc05511c - branchtable_fc0550c4) / 2)\n" // (case 10)
"    .byte((loc_fc0550d8 - branchtable_fc0550c4) / 2)\n" // (case 11)
"    .byte((loc_fc0550f6 - branchtable_fc0550c4) / 2)\n" // (case 12)
".align 1\n"
"loc_fc0550d2:\n"
"    bl      sub_fc0552b4\n"
"    b       loc_fc0550a0\n"
"loc_fc0550d8:\n"
"    mov     r4, r0\n"
"    adds    r0, #0x58\n"
"    mov     r6, r0\n"
"    bl      sub_fc2a4df0\n"
"    movs    r1, #0\n"
"    bl      sub_fc05cd5e\n"
"    ldr     r0, [r4, #0xc]\n"
"    bl      sub_fc0a2b32\n"
"    mov     r0, r6\n"
"    bl      sub_fc2a549e\n" // PrepareDirectory_0
"    b       loc_fc055146\n"
"loc_fc0550f6:\n"
"    bl      sub_fc054ea8_my\n" // -> ... fwt_open
"    b       loc_fc0550a0\n"
"loc_fc0550fc:\n"
"    ldr     r1, [r0, #4]\n"
"    movs    r2, #0\n"
"    mov     r4, r0\n"
"    ldr     r0, [r5, #4]\n"
"    bl      sub_fc2a51e0\n" // Lseek_FW
"    adds    r0, r0, #1\n"
"    bne     loc_fc0550a0\n"
"    ldr     r0, =0x09200001\n"
"    mov     r1, r4\n"
"    adds    r0, #0x12\n"
"    str     r0, [r4, #0x10]\n"
"    movs    r0, #7\n"
"    bl      sub_fc054e34\n"
"    b       loc_fc0550a0\n"
"loc_fc05511c:\n"
"    mov     r4, r0\n"
"    ldrsb.w r0, [r0, #0x58]\n"
"    cmp     r0, #0\n"
"    beq     loc_fc0550a0\n"
"    strb.w  r0, [sp]\n"
"    movs    r0, #0\n"
"    strb.w  r0, [sp, #1]\n"
"    add.w   r0, r4, #0x58\n"
"    mov     r6, r0\n"
"    bl      sub_fc2a4df0\n"
"    movs    r1, #0\n"
"    bl      sub_fc05cd5e\n"
"    mov     r0, sp\n"
"    bl      sub_fc0a2b3e\n"
"loc_fc055146:\n"
"    mov     r0, r6\n"
"    bl      sub_fc2a4df0\n"
"    ldr     r1, [r5, #0x18]\n"
"    bl      sub_fc05cdbc\n"
"    ldr     r1, [r5, #0x14]\n"
"    cmp     r1, #0\n"
"    beq     loc_fc0550a0\n"
"    ldr     r0, [r4, #0x10]\n"
"    blx     r1\n"
"    b       loc_fc0550a0\n"
"loc_fc05515e:\n"
"    bl      sub_fc0552f8_my\n" // -> ... fwt_write
"    b       loc_fc0550a0\n"
"loc_fc055164:\n"
"    bl      sub_fc054fa6_my\n" // -> ... fwt_close
"    b       loc_fc0550a0\n"
".ltorg\n"
    );
}

void __attribute__((naked,noinline)) sub_fc054ea8_my() {
asm volatile (
// open stage
// -f=chdk -s=0xfc054ea9 -c=103 -stubs PRIMARY.BIN 0xfc000000
"    push.w  {r4, r5, r6, r7, r8, lr}\n"
"    mov     r4, r0\n"
//"  mov   r0, r4\n"                // + data block start, commented out as R0 is already holding what we need
"    BL      filewrite_main_hook\n" // +
"    mov     r0, r4\n"              // + restore register(s)
"    ldr     r0, [r0, #0x4c]\n"
"    sub     sp, #0x38\n"
"    lsls    r0, r0, #0x1f\n"
"    beq     loc_fc054f82\n"
"    add.w   r0, r4, #0x58\n"
"    mov     r7, r0\n"
"    bl      sub_fc2a4df0\n"
"    movs    r1, #0\n"
"    bl      sub_fc05cd5e\n"
"    ldr     r0, [r4, #0xc]\n"
"    bl      sub_fc0a2b32\n"
"    ldr     r0, [r4, #0x4c]\n"
"    movw    r5, #0x301\n"
"    lsls    r1, r0, #0x1b\n"
"    bpl     loc_fc054eda\n"
"    movs    r5, #9\n"
"    b       loc_fc054ee0\n"
"loc_fc054eda:\n"
"    lsls    r1, r0, #0x19\n"
"    bpl     loc_fc054ee0\n"
"    movs    r5, #1\n"
"loc_fc054ee0:\n"
"    lsls    r0, r0, #0x1a\n"
"    bmi     loc_fc054eea\n"
"    ldr     r0, [r4, #0x54]\n"
"    cmp     r0, #1\n"
"    bne     loc_fc054eee\n"
"loc_fc054eea:\n"
"    orr     r5, r5, #0x8000\n"
"loc_fc054eee:\n"
"    movw    r8, #0x1b6\n"
"    ldr     r6, [r4, #0xc]\n"
"    mov     r2, r8\n"
"    mov     r1, r5\n"
"    mov     r0, r7\n"
//"    bl      sub_fc2a50fa\n"      // - j_Open_FW
"    bl      fwt_open\n"            // +
"    adds    r1, r0, #1\n"
"    bne     loc_fc054f3c\n"
"    mov     r0, r7\n"
"    bl      sub_fc2a549e\n" // PrepareDirectory_0
"    movs    r2, #0xf\n"
"    mov     r1, r7\n"
"    mov     r0, sp\n"
"    blx     sub_fc251d34\n"
"    movs    r0, #0\n"
"    strb.w  r0, [sp, #0xf]\n"
"    movw    r1, #0x41ff\n"
"    str     r1, [sp, #0x20]\n"
"    movs    r1, #0x10\n"
"    str     r6, [sp, #0x30]\n"
"    strd    r0, r6, [sp, #0x28]\n"
"    mov     r0, sp\n"
"    str     r6, [sp, #0x34]\n"
"    str     r1, [sp, #0x24]\n"
"    add     r1, sp, #0x20\n"
"    bl      sub_fc0f2ffe\n"
"    mov     r2, r8\n"
"    mov     r1, r5\n"
"    mov     r0, r7\n"
"    bl      sub_fc2a50fa\n" // j_Open_FW
"loc_fc054f3c:\n"
"    ldr     r5, =0x0001b294\n"
"    mov     r6, r0\n"
"    str     r0, [r5, #4]\n"
"    adds    r0, r0, #1\n"
"    bne     loc_fc054f62\n"
"    mov     r0, r7\n"
"    bl      sub_fc2a4df0\n"
"    ldr     r1, [r5, #0x18]\n"
"    bl      sub_fc05cdbc\n"
"    ldr     r1, [r5, #0x14]\n"
"    cmp     r1, #0\n"
"    beq     loc_fc054fa0\n"
"    add     sp, #0x38\n"
"    ldr     r0, =0x09200001\n"
"    pop.w   {r4, r5, r6, r7, r8, lr}\n"
"    bx      r1\n"
"loc_fc054f62:\n"
"    ldr     r0, =0x0014063c\n"
"    movs    r2, #0x20\n"
"    mov     r1, r7\n"
"    blx     sub_fc251d3c\n" // j_dry_memcpy
//mod start                                 // +
"    ldr     r3, =current_write_ignored\n"  // +
"    ldr     r3, [r3]\n"                    // +
"    cbnz    r3, loc_fwto1\n"               // + jump over the next block
//mod end                                   // +
"    ldr     r0, [r4, #0x4c]\n"
"    lsls    r0, r0, #0x18\n"
"    bpl     loc_fc054f82\n"
"    ldr     r1, [r4, #8]\n"
"    mov     r0, r6\n"
"    bl      sub_fc2a52b4\n"
"    cbnz    r0, loc_fc054f82\n"
"    movs    r0, #7\n"
"    mov     r1, r4\n"
"    b       loc_fc054f98\n"
"loc_fc054f82:\n"
"loc_fwto1:\n"                              // +
"    ldr     r0, [r4, #0x4c]\n"
"    lsls    r0, r0, #0x19\n"
"    bmi     loc_fc054f8c\n"
"    ldr     r0, [r4, #4]\n"
"    cbz     r0, loc_fc054f94\n"
"loc_fc054f8c:\n"
"    movs    r0, #9\n"
"    mov     r1, r4\n"
"    bl      sub_fc054e34\n"
"loc_fc054f94:\n"
"    movs    r0, #0\n"
"    mov     r1, r4\n"
"loc_fc054f98:\n"
"    add     sp, #0x38\n"
"    pop.w   {r4, r5, r6, r7, r8, lr}\n"
//"    b       loc_fc054e34\n"              // -
"    ldr     pc, =0xfc054e34+1\n"           // +
"loc_fc054fa0:\n"
"    add     sp, #0x38\n"
"    pop.w   {r4, r5, r6, r7, r8, pc}\n"
".ltorg\n"
    );
}

void __attribute__((naked,noinline)) sub_fc0552f8_my() {
asm volatile (
// write stage
// -f=chdk -s=0xfc0552f9 -c=64 -stubs PRIMARY.BIN 0xfc000000
"    push.w  {r4, r5, r6, r7, r8, sb, sl, lr}\n"
"    mov     r5, r0\n"
"    ldr     r0, [r0]\n"
"    cmp     r0, #6\n"
"    bhi     loc_fc055310\n"
"    add.w   r0, r5, r0, lsl #3\n"
"    ldrd    r7, r6, [r0, #0x14]\n"
"    cbnz    r6, loc_fc055324\n"
"    b       loc_fc05531e\n"
"loc_fc055310:\n"
"    movw    r2, #0x344\n"
"    ldr     r1, =0xfc05522c\n" //  *"dwFWrite.c"
"    movs    r0, #0\n"
"    blx     sub_fc251d14\n" // j_DebugAssert
"loc_fc05531e:\n"
"    movs    r0, #7\n"
"    mov     r1, r5\n"
"    b       loc_fc055392\n"
"loc_fc055324:\n"
"    ldr.w   sl, =0x0001b294\n"
"    mov.w   sb, #0x1000000\n"
"    mov     r4, r6\n"
"loc_fc05532e:\n"
"    ldr     r0, [r5, #4]\n"
"    cmp     r4, sb\n"
"    mov     r1, sb\n"
"    bhi     loc_fc055338\n"
"    mov     r1, r4\n"
"loc_fc055338:\n"
"    lsls    r2, r0, #8\n"
"    beq     loc_fc05534a\n"
"    bic     r0, r0, #0xff000000\n"
"    rsb.w   r0, r0, #0x1000000\n"
"    cmp     r1, r0\n"
"    bls     loc_fc05534a\n"
"    mov     r1, r0\n"
"loc_fc05534a:\n"
"    ldr.w   r0, [sl, #4]\n"
"    mov     r8, r1\n"
"    mov     r2, r1\n"
"    mov     r1, r7\n"
//"    bl      sub_fc2a51a2\n"  // - j_Write_FW
"    bl      fwt_write\n"       // +
"    ldr     r1, [r5, #4]\n"
"    cmp     r8, r0\n"
"    add     r1, r0\n"
"    str     r1, [r5, #4]\n"
"    beq     loc_fc055372\n"
"    adds    r0, r0, #1\n"
"    bne     loc_fc05536a\n"
"    ldr     r0, =0x09200005\n"
"    b       loc_fc05536e\n"
"loc_fc05536a:\n"
"    ldr     r0, =0x09200005\n"
"    adds    r0, #0x10\n"
"loc_fc05536e:\n"
"    str     r0, [r5, #0x10]\n"
"    b       loc_fc05531e\n"
"loc_fc055372:\n"
"    subs    r4, r4, r0\n"
"    cmp     r4, r6\n"
"    add     r7, r0\n"
"    blo     loc_fc055388\n"
"    movw    r2, #0x36f\n"
"    ldr     r1, =0xfc05522c\n" //  *"dwFWrite.c"
"    movs    r0, #0\n"
"    blx     sub_fc251d14\n" // j_DebugAssert
"loc_fc055388:\n"
"    cmp     r4, #0\n"
"    bne     loc_fc05532e\n"
"    ldr     r0, [r5]\n"
"    mov     r1, r5\n"
"    adds    r0, r0, #1\n"
"loc_fc055392:\n"
"    pop.w   {r4, r5, r6, r7, r8, sb, sl, lr}\n"
//"    b       loc_fc054e34\n"      // -
"    ldr     pc, =0xfc054e34+1\n"   // +
".ltorg\n"
    );
}

void __attribute__((naked,noinline)) sub_fc054fa6_my() {
asm volatile (
// close stage
// -f=chdk -s=0xfc054fa7 -c=104 -stubs PRIMARY.BIN 0xfc000000
"    push    {r4, r5, r6, lr}\n"
"    mov     r4, r0\n"
"    ldr     r0, [r0, #0x4c]\n"
"    ldr     r5, =0x0001b294\n"
"    sub     sp, #0x38\n"
"    lsls    r0, r0, #0x1e\n"
"    bpl     loc_fc05508a\n"
"    ldr     r0, [r5, #4]\n"
"    adds    r1, r0, #1\n"
"    beq     loc_fc054fd8\n"
"    ldr     r6, =0x09200001\n"
"    ldr     r1, [r4, #0x54]\n"
"    adds    r6, r6, #2\n"
"    cmp     r1, #1\n"
"    bne     loc_fc054fca\n"
//mod start                                 // +
"    ldr     r3, =current_write_ignored\n"  // +
"    ldr     r3, [r3]\n"                    // +
"    cbnz    r3, loc_fwtc1\n"               // + jump over the next block
//mod end                                   // +
"    bl      sub_fc2a50fe\n"
"    b       loc_fc054fce\n"
"loc_fc054fca:\n"
"loc_fwtc1:\n"                              // +
//"    bl      sub_fc2a50fc\n"              // - j_Close_FW
"    bl      fwt_close\n"                   // +
"loc_fc054fce:\n"
"    cbz     r0, loc_fc054fd2\n"
"    str     r6, [r4, #0x10]\n"
"loc_fc054fd2:\n"
"    mov.w   r0, #-1\n"
"    str     r0, [r5, #4]\n"
"loc_fc054fd8:\n"
"    add.w   r6, r4, #0x58\n"
"    ldr     r0, [r4, #0x10]\n"
"    lsls    r0, r0, #0x1f\n"
"    bne     loc_fc05507c\n"
"    ldr     r0, [r4, #0x4c]\n"
"    lsls    r1, r0, #0x1f\n"
"    beq     loc_fc055004\n"
"    movw    r0, #0x81ff\n"
"    str     r0, [sp, #0x20]\n"
"    movs    r0, #0x20\n"
"    str     r0, [sp, #0x24]\n"
"    ldr     r0, [r4, #4]\n"
"    str     r0, [sp, #0x28]\n"
"    ldr     r0, [r4, #0xc]\n"
"    str     r0, [sp, #0x2c]\n"
"    ldr     r0, [r4, #0xc]\n"
"    str     r0, [sp, #0x30]\n"
"    ldr     r0, [r4, #0xc]\n"
"    str     r0, [sp, #0x34]\n"
"    b       loc_fc055026\n"
"loc_fc055004:\n"
"    lsls    r0, r0, #0x1b\n"
"    bpl     loc_fc055026\n"
"    add     r1, sp, #0x20\n"
"    mov     r0, r6\n"
"    bl      sub_fc0f2f88\n"
"    cbnz    r0, loc_fc05501e\n"
"    movs    r0, #0\n"
"    movw    r2, #0x3b6\n"
"    ldr     r1, =0xfc05522c\n" //  *"dwFWrite.c"
"    blx     sub_fc251d14\n" // j_DebugAssert
"loc_fc05501e:\n"
"    ldr     r0, [sp, #0x28]\n"
"    ldr     r1, [r4, #4]\n"
"    add     r0, r1\n"
"    str     r0, [sp, #0x28]\n"
"loc_fc055026:\n"
"    ldr     r0, [r4, #0x4c]\n"
"    lsls    r0, r0, #0x19\n"
"    bmi     loc_fc055034\n"
"    add     r1, sp, #0x20\n"
"    mov     r0, r6\n"
"    bl      sub_fc0f2ffe\n"
"loc_fc055034:\n"
"    ldr     r0, [r4, #0x4c]\n"
"    lsls    r0, r0, #0x1a\n"
"    bpl     loc_fc05507c\n"
"    movs    r2, #0x20\n"
"    mov     r1, r6\n"
"    mov     r0, sp\n"
"    blx     sub_fc251d3c\n" // j_dry_memcpy
"    mov     r0, sp\n"
"    bl      sub_fc2b7e28\n" // strlen_FW
"    add     r0, sp, r0\n"
"    movs    r1, #0x54\n"
"    strb    r1, [r0, #-0x3]!\n"
"    movs    r1, #0x4d\n"
"    strb    r1, [r0, #1]\n"
"    movs    r1, #0x50\n"
"    strb    r1, [r0, #2]\n"
"    mov     r1, sp\n"
"    mov     r0, r6\n"
"    bl      sub_fc0a2d0a\n"
"    cbnz    r0, loc_fc055070\n"
"    movs    r0, #0\n"
"    movw    r2, #0x165\n"
"    ldr     r1, =0xfc05522c\n" //  *"dwFWrite.c"
"    blx     sub_fc251d14\n" // j_DebugAssert
"loc_fc055070:\n"
"    mov     r0, sp\n"
"    bl      sub_fc0f32f0\n"
"    mov     r0, r6\n"
"    bl      sub_fc0f32f0\n"
"loc_fc05507c:\n"
"    mov     r0, r6\n"
"    bl      sub_fc2a4df0\n"
"    ldr     r1, [r5, #0x18]\n"
"    bl      sub_fc05cdbc\n"
"    b       loc_fc05508e\n"
"loc_fc05508a:\n"
"    ldr     r0, [r5, #0x18]\n"
"    blx     r0\n"
"loc_fc05508e:\n"
"    ldr     r1, [r5, #0x14]\n"
"    cmp     r1, #0\n"
"    beq     loc_fc055098\n"
"    ldr     r0, [r4, #0x10]\n"
"    blx     r1\n"
"loc_fc055098:\n"
"    add     sp, #0x38\n"
"    pop     {r4, r5, r6, pc}\n"
".ltorg\n"
    );
}
