

#include "lolevel.h"
#include "platform.h"
// all of this copied and adjusted from g7x coding by reyalp
extern void _LogCameraEvent(int id,const char *fmt,...);

typedef struct {
    unsigned int address;
    unsigned int length;
} cam_ptp_data_chunk; //camera specific structure

#define MAX_CHUNKS_FOR_FWT 7 // filewritetask is prepared for this many chunks
                              // corresponds to filewritetask() jump table entries 0-6
/*
 * fwt_data_struct: defined here as it's camera dependent
 * unneeded members are designated with unkn
 * file_offset, full_size, seek_flag only needs to be defined for cameras with CAM_FILEWRITETASK_SEEK/CAM_FILEWRITETASK_MULTIPASS
 * pdc is always required
 * name is not currently used
 */
typedef struct
{
    int unkn1; // message number
    int file_offset;
    int maybe_full_size; // TODO doesn't seem to actually be full size for jpeg, instead round number somewhat smaller
    int unkn2, unkn3;
    int unkn4;
    cam_ptp_data_chunk pdc[MAX_CHUNKS_FOR_FWT];
    int maybe_seek_flag;      // from fc06b0cc 0x50, not clear if ever used to indicate seek. 0x3 raw, 0x83 jpeg, 0x200 CacheFlush, 0x100 create dir
    int unkn5, unkn6;
    char name[32];      //from fc06b0cc offset from start 0x5c = 92 bytes = 23 words
} fwt_data_struct;

/*
g7x observed message sequences
canon raw + jpeg
CR2
12 full_size = 0x010dad6d (actual size), seek_flag = 0x3
 0 chunk 0-0x9aa00
 1 chunk 0x9aa00-0x010dad6d
 2 chunk 0-0
 7 close
JPEG
12 full_size = 32b200 (actual size = 0x35bbae), seek_flag = 0x83
 0 chunk 0-0x35bbae
 1 chunk 0-0
 7 close
10 seek_flag = 0x200, name = A/CacheFlush

single jpeg only, high detail scene
12 full_size = 0x00c41400 (actual size = 0xCD0F69) seek_flag = 0x83
 0 0-0xcd0f69
 1 0-0
 7 close
10 seek_flag = 0x200, name = A/CacheFlush

continuous jpeg
shot 1
12 full_size = 0x369000 (actual 0x39af87) seek_flag = 0x83
 0 chunk 0-0x39af87
 1 chunk 0-0
 7 close
shot 2
12 full_size=0x00369200 (acutal 0x39b022) seek_flag = 0x83
 0 chunk 0-39b022
 1 chunk 0-0
 7 close
10 seek_flag = 0x200, name = A/CacheFlush
10 seek_flag = 0x200, name = A/CacheFlush
(really twice, no obvious difference in params)

canon raw only
12 full_size = 0x010dce4a (actual size) seek_flag 3
 0 chunk 0-0x87200
 1 chunk 0x87200-0x010dce4a
 2 0-0
 7 close
10 seek_flag = 0x200, name = A/CacheFlush

new directory
11 seek_flag = 0x100
before m 12 for shot, after raw hook in capt_seq but before
spytask calls remotecap_raw_available due to sleep loops

bypassing PrepareDirectory_0 seems to cause hang on switch to play mode
*/

#include "../../../generic/filewrite.c"

void log_fwt_msg(fwt_data_struct *fwd)
{
    int m=fwd->unkn1;
    _LogCameraEvent(0x60,"fw m:%d o:0x%08x fs:0x%08x sf:0x%x",m,fwd->file_offset,fwd->maybe_full_size,fwd->maybe_seek_flag);
    _LogCameraEvent(0x60,"fw %s",fwd->name);
    if(m >= 0 && m <=6) {
        _LogCameraEvent(0x60,"fw chunk adr:0x%08x l:0x%08x",fwd->pdc[m].address,fwd->pdc[m].length);
    }
    _LogCameraEvent(0x60,"fw u %08x %08x %08x %08x %08x %08x",fwd->unkn2,fwd->unkn3,fwd->unkn4,fwd->unkn5,fwd->unkn6);
}

void log_fwt_start(void)
{
    _LogCameraEvent(0x60,"fw start");
}
/*************************************************************/
// // task_FileWrite 0xfc065dc7  -s=task_FileWrite -c=43 -f=chdk
void __attribute__((naked,noinline)) filewritetask() {
asm volatile (
// task_FileWrite 0xfc065dc7
"    push    {r3, r4, r5, r6, r7, lr}\n"
"    ldr     r6, =0x09200001\n"
"    movw    r7, #0x428\n"
"    ldr     r5, =0x00024cb8\n"
"    adds    r6, #0x12\n"
"loc_fc065dd2:\n"
"    mov     r1, sp\n"
"    movs    r2, #0\n"
"    ldr     r0, [r5, #0x10]\n"
"    blx     sub_fc2cf370\n" // j_ReceiveMessageQueue
"    cbz     r0, loc_fc065de8\n"
"    movs    r0, #0\n"
"    mov     r2, r7\n"
"    ldr     r1, =0xfc065efc\n" //  *"dwFWrite.c"
"    blx     sub_fc2cf430\n" // j_DebugAssert
"loc_fc065de8:\n"
"    ldr     r0, [sp]\n"
"bl  log_fwt_msg\n"
"    ldr     r0, [sp]\n"
"    ldr     r1, [r0]\n"
"    cmp     r1, #0xd\n"
"    bhs     loc_fc065dd2\n"
"    tbb     [pc, r1]\n" // (jumptable r1 13 elements)
"branchtable_fc065df4:\n"
"    .byte((loc_fc065e36 - branchtable_fc065df4) / 2)\n" // (case 0)
"    .byte((loc_fc065e36 - branchtable_fc065df4) / 2)\n" // (case 1)
"    .byte((loc_fc065e36 - branchtable_fc065df4) / 2)\n" // (case 2)
"    .byte((loc_fc065e36 - branchtable_fc065df4) / 2)\n" // (case 3)
"    .byte((loc_fc065e36 - branchtable_fc065df4) / 2)\n" // (case 4)
"    .byte((loc_fc065e36 - branchtable_fc065df4) / 2)\n" // (case 5)
"    .byte((loc_fc065e36 - branchtable_fc065df4) / 2)\n" // (case 6)
"    .byte((loc_fc065e3c - branchtable_fc065df4) / 2)\n" // (case 7)
"    .byte((loc_fc065e02 - branchtable_fc065df4) / 2)\n" // (case 8)
"    .byte((loc_fc065e14 - branchtable_fc065df4) / 2)\n" // (case 9)
"    .byte((loc_fc065e30 - branchtable_fc065df4) / 2)\n" // (case 10)
"    .byte((loc_fc065e08 - branchtable_fc065df4) / 2)\n" // (case 11)
"    .byte((loc_fc065e0e - branchtable_fc065df4) / 2)\n" // (case 12)
".align 1\n"
"loc_fc065e02:\n"
"    bl      sub_fc065fb6\n"
"    b       loc_fc065dd2\n"
"loc_fc065e08:\n"
"    bl      sub_fc066002\n"
"    b       loc_fc065dd2\n"
"loc_fc065e0e:\n"
"    bl      sub_fc065b7c_my\n"
"    b       loc_fc065dd2\n"
"loc_fc065e14:\n"
"    ldr     r1, [r0, #4]\n"
"    movs    r2, #0\n"
"    mov     r4, r0\n"
"    ldr     r0, [r5, #4]\n"
"    bl      _lseek\n" // -> fwt_lseek ?
"    adds    r0, r0, #1\n"
"    bne     loc_fc065dd2\n"
"    movs    r0, #7\n"
"    mov     r1, r4\n"
"    str     r6, [r4, #0x14]\n"
"    bl      sub_fc065b04\n"
"    b       loc_fc065dd2\n"
"loc_fc065e30:\n"
"    bl      sub_fc066056\n"
"    b       loc_fc065dd2\n"
"loc_fc065e36:\n"
"    bl      sub_fc0660ae_my\n"
"    b       loc_fc065dd2\n"
"loc_fc065e3c:\n"
"    bl      sub_fc065ca2_my\n"
"    b       loc_fc065dd2\n"
".ltorg\n"
    );
}
// -s=0xfc065b7d-c=121 -f=chdk
void __attribute__((naked,noinline)) sub_fc065b7c_my() {
asm volatile (
"    push.w  {r4, r5, r6, r7, r8, sb, lr}\n"
"    mov     r4, r0\n"
//hook placed here to avoid conditional branch a few instructions below (watch out for registers!)
//"  mov   r0, r4\n"      //data block start, commented out as R0 is already holding what we need
"    BL      filewrite_main_hook\n"
"    mov     r0, r4\n" //restore registers
"    ldr     r0, [r0, #0x50]\n"
"    sub     sp, #0x3c\n"
"    lsls    r1, r0, #0x1f\n"
"    bne     loc_fc065b8e\n"
"    lsls    r0, r0, #0x1d\n"
"    bpl     loc_fc065c7e\n"
"loc_fc065b8e:\n"
"    ldr     r7, =0x00024cb8\n"
"    ldr     r0, [r7, #0x18]\n"
"    cbz     r0, loc_fc065b96\n"
"    blx     r0\n"
"loc_fc065b96:\n"
"    add.w   r0, r4, #0x5c\n"
"    mov     r8, r0\n"
"    bl      sub_fc332794\n"
"    movs    r1, #0\n"
"    bl      sub_fc06e672\n"
"    movs    r1, #0\n"
"    movs    r0, #0x47\n"
"    bl      sub_fc3251c0\n"
"    ldr     r0, [r4, #0x50]\n"
"    lsls    r0, r0, #0x1f\n"
"    beq     loc_fc065c7e\n"
"    ldr     r0, [r4, #0x10]\n"
"    bl      sub_fc0cb96e\n"
"    ldr     r0, [r4, #0x50]\n"
"    movw    r5, #0x301\n"
"    lsls    r1, r0, #0x1b\n"
"    bpl     loc_fc065bc8\n"
"    movs    r5, #9\n"
"    b       loc_fc065bce\n"
"loc_fc065bc8:\n"
"    lsls    r1, r0, #0x19\n"
"    bpl     loc_fc065bce\n"
"    movs    r5, #1\n"
"loc_fc065bce:\n"
"    lsls    r0, r0, #0x1a\n"
"    bmi     loc_fc065bd8\n"
"    ldr     r0, [r4, #0x58]\n"
"    cmp     r0, #1\n"
"    bne     loc_fc065bdc\n"
"loc_fc065bd8:\n"
"    orr     r5, r5, #0x8000\n"
"loc_fc065bdc:\n"
"    movw    sb, #0x1b6\n"
"    ldr     r6, [r4, #0x10]\n"
"    mov     r2, sb\n"
"    mov     r1, r5\n"
"    mov     r0, r8\n"
//"    bl      sub_fc332a0a\n" // j_Open_FW
"    bl      fwt_open\n" // +
"    adds    r1, r0, #1\n"
"    bne     loc_fc065c2a\n"
"    mov     r0, r8\n"
"    bl      sub_fc332dae\n" // PrepareDirectory_0
"    movs    r2, #0xf\n"
"    mov     r1, r8\n"
"    add     r0, sp, #4\n"
"    blx     sub_fc2cf450\n"
"    movs    r0, #0\n"
"    strb.w  r0, [sp, #0x13]\n"
"    movw    r1, #0x41ff\n"
"    str     r1, [sp, #0x24]\n"
"    strd    r0, r6, [sp, #0x2c]\n"
"    movs    r1, #0x10\n"
"    str     r6, [sp, #0x34]\n"
"    add     r0, sp, #4\n"
"    str     r6, [sp, #0x38]\n"
"    str     r1, [sp, #0x28]\n"
"    add     r1, sp, #0x24\n"
"    bl      sub_fc0fb9da\n"
"    mov     r2, sb\n"
"    mov     r1, r5\n"
"    mov     r0, r8\n"
"    bl      sub_fc332a0a\n" // j_Open_FW
"loc_fc065c2a:\n"
"    mov     r5, r0\n"
"    str     r0, [r7, #4]\n"
"    adds    r0, r0, #1\n"
"    bne     loc_fc065c56\n"
"    movs    r1, #0\n"
"    movs    r0, #0x48\n"
"    bl      sub_fc3251c0\n"
"    mov     r0, r8\n"
"    bl      sub_fc332794\n"
"    ldr     r1, [r7, #0x1c]\n"
"    bl      sub_fc06e6d0\n"
"    ldr     r1, [r7, #0x14]\n"
"    cmp     r1, #0\n"
"    beq     loc_fc065c9c\n"
"    add     sp, #0x3c\n"
"    ldr     r0, =0x09200001\n"
"    pop.w   {r4, r5, r6, r7, r8, sb, lr}\n"
"    bx      r1\n"
"loc_fc065c56:\n"
"    ldr     r0, =0x002013cc\n"
"    movs    r2, #0x20\n"
"    mov     r1, r8\n"
"    blx     sub_fc2cf458\n" // j_dry_memcpy
// TODO looks equivalent to elph130, not verified that it's required
//mod start
"    LDR R3, =current_write_ignored\n"
"    LDR R3, [R3]\n"
"    cbnz r3,loc_C\n" // jump over the next block
//mod end
"    ldr     r0, [r4, #0x50]\n"
"    lsls    r0, r0, #0x18\n"
"    bpl     loc_fc065c7e\n"
"    ldr     r1, [r4, #0xc]\n"
"    mov     r0, r5\n"
"    bl      sub_fc332bc4\n"
"    cbnz    r0, loc_fc065c7c\n"
"    ldr     r0, =0x09200001\n"
"    mov     r1, r4\n"
"    adds    r0, #0x16\n"
"    str     r0, [r4, #0x14]\n"
"    movs    r0, #7\n"
"    b       loc_fc065c94\n"
"loc_fc065c7c:\n"
"    b       loc_fc065c7e\n"
"loc_fc065c7e:\n"
"loc_C:\n"
"    ldr     r0, [r4, #0x50]\n"
"    lsls    r0, r0, #0x19\n"
"    bmi     loc_fc065c88\n"
"    ldr     r0, [r4, #4]\n"
"    cbz     r0, loc_fc065c90\n"
"loc_fc065c88:\n"
"    movs    r0, #9\n"
"    mov     r1, r4\n"
"    bl      sub_fc065b04\n"
"loc_fc065c90:\n"
"    movs    r0, #0\n"
"    mov     r1, r4\n"
"loc_fc065c94:\n"
"    add     sp, #0x3c\n"
"    pop.w   {r4, r5, r6, r7, r8, sb, lr}\n"
//"    b       loc_fc065b04\n"
"    ldr     pc, =0xfc065b05\n"
"loc_fc065c9c:\n"
"    add     sp, #0x3c\n"
"    pop.w   {r4, r5, r6, r7, r8, sb, pc}\n"
".ltorg\n"
    );
}
// message 0-6 - filewrite chunks
// -s=0xfc0660af -c=65 -f=chdk
void __attribute__((naked,noinline)) sub_fc0660ae_my() {
asm volatile (
"    push.w  {r4, r5, r6, r7, r8, sb, sl, lr}\n"
"    mov     r5, r0\n"
"    ldr     r0, [r0]\n"
"    cmp     r0, #6\n"
"    bhi     loc_fc0660c6\n"
"    add.w   r0, r5, r0, lsl #3\n"
"    ldrd    r7, r6, [r0, #0x18]\n"
"    cbnz    r6, loc_fc0660da\n"
"    b       loc_fc0660d4\n"
"loc_fc0660c6:\n"
"    movw    r2, #0x36d\n"
"    ldr     r1, =0xfc065efc\n" //  *"dwFWrite.c"
"    movs    r0, #0\n"
"    blx     sub_fc2cf430\n" // j_DebugAssert
"loc_fc0660d4:\n"
"    movs    r0, #7\n"
"    mov     r1, r5\n"
"    b       loc_fc06614a\n"
"loc_fc0660da:\n"
"    ldr.w   sl, =0x00024cb8\n"
"    mov.w   sb, #0x1000000\n"
"    mov     r4, r6\n"
"loc_fc0660e4:\n"
"    ldr     r0, [r5, #4]\n"
"    cmp     r4, sb\n"
"    mov     r1, sb\n"
"    bhi     loc_fc0660ee\n"
"    mov     r1, r4\n"
"loc_fc0660ee:\n"
"    lsls    r2, r0, #8\n"
"    beq     loc_fc066100\n"
"    bic     r0, r0, #0xff000000\n"
"    rsb.w   r0, r0, #0x1000000\n"
"    cmp     r1, r0\n"
"    bls     loc_fc066100\n"
"    mov     r1, r0\n"
"loc_fc066100:\n"
"    ldr.w   r0, [sl, #4]\n"
"    mov     r8, r1\n"
"    mov     r2, r1\n"
"    mov     r1, r7\n"
//"    bl      sub_fc332ab2\n" // j_Write_FW
"    bl      fwt_write\n" // +
"    ldr     r1, [r5, #4]\n"
"    cmp     r8, r0\n"
"    add     r1, r0\n"
"    str     r1, [r5, #4]\n"
"    beq     loc_fc06612a\n"
"    adds    r0, r0, #1\n"
"    bne     loc_fc066122\n"
"    ldr     r0, =0x09200006\n"
"    subs    r0, r0, #1\n"
"    b       loc_fc066126\n"
"loc_fc066122:\n"
"    ldr     r0, =0x09200006\n"
"    adds    r0, #0xf\n"
"loc_fc066126:\n"
"    str     r0, [r5, #0x14]\n"
"    b       loc_fc0660d4\n"
"loc_fc06612a:\n"
"    subs    r4, r4, r0\n"
"    cmp     r4, r6\n"
"    add     r7, r0\n"
"    blo     loc_fc066140\n"
"    movw    r2, #0x398\n"
"    ldr     r1, =0xfc065efc\n" //  *"dwFWrite.c"
"    movs    r0, #0\n"
"    blx     sub_fc2cf430\n" // j_DebugAssert
"loc_fc066140:\n"
"    cmp     r4, #0\n"
"    bne     loc_fc0660e4\n"
"    ldr     r0, [r5]\n"
"    mov     r1, r5\n"
"    adds    r0, r0, #1\n"
"loc_fc06614a:\n"
"    pop.w   {r4, r5, r6, r7, r8, sb, sl, lr}\n"
//"    b       loc_fc065b04\n"
"    ldr     pc,=0xfc065b05\n"
".ltorg\n"
    );
}
// message 7 - close
// -s=0xfc065ca3 -c=124 -f=chdk
void __attribute__((naked,noinline)) sub_fc065ca2_my() {
asm volatile (
"    push    {r4, r5, r6, lr}\n"
"    mov     r4, r0\n"
"    ldr     r0, [r0, #0x50]\n"
"    ldr     r5, =0x00024cb8\n"
"    sub     sp, #0x38\n"
"    lsls    r1, r0, #0x1e\n"
"    bmi     loc_fc065cb6\n"
"    lsls    r0, r0, #0x1c\n"
"    bpl     loc_fc065db4\n"
"    b       loc_fc065cf8\n"
"loc_fc065cb6:\n"
"    lsls    r0, r0, #0x18\n"
"    bpl     loc_fc065cd4\n"
"    ldrd    r1, r0, [r4, #8]\n"
"    cmp     r1, r0\n"
"    beq     loc_fc065cd4\n"
"    ldr     r0, [r5, #4]\n"
"    bl      sub_fc332bc4\n"
"    cbnz    r0, loc_fc065cd0\n"
"    ldr     r0, =0x09200001\n"
"    adds    r0, #0x16\n"
"    str     r0, [r4, #0x14]\n"
"loc_fc065cd0:\n"
"    ldr     r0, [r4, #8]\n"
"    str     r0, [sp, #0x28]\n"
"loc_fc065cd4:\n"
"    ldr     r0, [r5, #4]\n"
"    adds    r1, r0, #1\n"
"    beq     loc_fc065cf8\n"
"    ldr     r6, =0x09200001\n"
"    ldr     r1, [r4, #0x58]\n"
"    adds    r6, r6, #2\n"
"    cmp     r1, #1\n"
"    bne     loc_fc065cea\n"
//mod start
"    LDR R3, =current_write_ignored\n"
"    LDR R3, [R3]\n"
"    cbnz R3,loc_D\n" // jump over the next block
//mod end
"    bl      sub_fc332a0e\n"
"    b       loc_fc065cee\n"
"loc_fc065cea:\n"
"loc_D:\n"
//"    bl      sub_fc332a0c\n" // j_Close_FW
"    bl      fwt_close\n" // +
"loc_fc065cee:\n"
"    cbz     r0, loc_fc065cf2\n"
"    str     r6, [r4, #0x14]\n"
"loc_fc065cf2:\n"
"    mov.w   r0, #-1\n"
"    str     r0, [r5, #4]\n"
"loc_fc065cf8:\n"
"    add.w   r6, r4, #0x5c\n"
"    ldr     r0, [r4, #0x14]\n"
"    lsls    r0, r0, #0x1f\n"
"    bne     loc_fc065d9c\n"
"    ldr     r0, [r4, #0x50]\n"
"    lsls    r1, r0, #0x1f\n"
"    beq     loc_fc065d24\n"
"    movw    r0, #0x81ff\n"
"    str     r0, [sp, #0x20]\n"
"    movs    r0, #0x20\n"
"    str     r0, [sp, #0x24]\n"
"    ldr     r0, [r4, #4]\n"
"    str     r0, [sp, #0x28]\n"
"    ldr     r0, [r4, #0x10]\n"
"    str     r0, [sp, #0x2c]\n"
"    ldr     r0, [r4, #0x10]\n"
"    str     r0, [sp, #0x30]\n"
"    ldr     r0, [r4, #0x10]\n"
"    str     r0, [sp, #0x34]\n"
"    b       loc_fc065d46\n"
"loc_fc065d24:\n"
"    lsls    r0, r0, #0x1b\n"
"    bpl     loc_fc065d46\n"
"    add     r1, sp, #0x20\n"
"    mov     r0, r6\n"
"    bl      sub_fc0fb964\n"
"    cbnz    r0, loc_fc065d3e\n"
"    movs    r0, #0\n"
"    movw    r2, #0x3ee\n"
"    ldr     r1, =0xfc065efc\n" //  *"dwFWrite.c"
"    blx     sub_fc2cf430\n" // j_DebugAssert
"loc_fc065d3e:\n"
"    ldr     r0, [sp, #0x28]\n"
"    ldr     r1, [r4, #4]\n"
"    add     r0, r1\n"
"    str     r0, [sp, #0x28]\n"
"loc_fc065d46:\n"
"    ldr     r0, [r4, #0x50]\n"
"    lsls    r0, r0, #0x19\n"
"    bmi     loc_fc065d54\n"
"    add     r1, sp, #0x20\n"
"    mov     r0, r6\n"
"    bl      sub_fc0fb9da\n"
"loc_fc065d54:\n"
"    ldr     r0, [r4, #0x50]\n"
"    lsls    r0, r0, #0x1a\n"
"    bpl     loc_fc065d9c\n"
"    movs    r2, #0x20\n"
"    mov     r1, r6\n"
"    mov     r0, sp\n"
"    blx     sub_fc2cf458\n" // j_dry_memcpy
"    mov     r0, sp\n"
"    bl      _strlen\n"
"    add     r0, sp, r0\n"
"    movs    r1, #0x54\n"
"    strb    r1, [r0, #-0x3]!\n"
"    movs    r1, #0x4d\n"
"    strb    r1, [r0, #1]\n"
"    movs    r1, #0x50\n"
"    strb    r1, [r0, #2]\n"
"    mov     r1, sp\n"
"    mov     r0, r6\n"
"    bl      sub_fc0cbb46\n"
"    cbnz    r0, loc_fc065d90\n"
"    movs    r0, #0\n"
"    movw    r2, #0x179\n"
"    ldr     r1, =0xfc065efc\n" //  *"dwFWrite.c"
"    blx     sub_fc2cf430\n" // j_DebugAssert
"loc_fc065d90:\n"
"    mov     r0, sp\n"
"    bl      sub_fc0fbccc\n"
"    mov     r0, r6\n"
"    bl      sub_fc0fbccc\n"
"loc_fc065d9c:\n"
"    movs    r1, #0\n"
"    movs    r0, #0x48\n"
"    bl      sub_fc3251c0\n"
"    mov     r0, r6\n"
"    bl      sub_fc332794\n"
"    ldr     r1, [r5, #0x1c]\n"
"    bl      sub_fc06e6d0\n"
"    b       loc_fc065db8\n"
"    b       loc_fc065db4\n"
"loc_fc065db4:\n"
"    ldr     r0, [r5, #0x1c]\n"
"    blx     r0\n"
"loc_fc065db8:\n"
"    ldr     r1, [r5, #0x14]\n"
"    cmp     r1, #0\n"
"    beq     loc_fc065dc2\n"
"    ldr     r0, [r4, #0x14]\n"
"    blx     r1\n"
"loc_fc065dc2:\n"
"    add     sp, #0x38\n"
"    pop     {r4, r5, r6, pc}\n"
".ltorg\n"
    );
}

