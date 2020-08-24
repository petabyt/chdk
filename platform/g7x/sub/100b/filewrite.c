#include "lolevel.h"
#include "platform.h"
// debug
//#define FILEWRITE_DEBUG_LOG 1
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

#ifdef FILEWRITE_DEBUG_LOG
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
#endif

/*************************************************************/
// task_FileWrite 0xfc06b31d  -s=task_FileWrite -c=43 -f=chdk
void __attribute__((naked,noinline)) filewritetask() {
asm volatile (
"    push    {r3, r4, r5, r6, r7, lr}\n"
#ifdef FILEWRITE_DEBUG_LOG
"bl log_fwt_start\n"
#endif
"    ldr     r6, =0x09200001\n"
"    movw    r7, #0x428\n"
"    ldr     r5, =0x00026560\n"
"    adds    r6, #0x12\n"
"loc_fc06b328:\n"
"    mov     r1, sp\n"
"    movs    r2, #0\n"
"    ldr     r0, [r5, #0x10]\n"
"    blx     sub_fc2ef8f8\n" // j_ReceiveMessageQueue
"    cbz     r0, loc_fc06b33e\n"
"    movs    r0, #0\n"
"    mov     r2, r7\n"
"    ldr     r1, =0xfc06b450\n" //  *"dwFWrite.c"
"    blx     sub_fc2ef9f0\n" // j_DebugAssert
"loc_fc06b33e:\n"
#ifdef FILEWRITE_DEBUG_LOG
"ldr     r0, [sp]\n"
"bl log_fwt_msg\n"
#endif
"    ldr     r0, [sp]\n"
"    ldr     r1, [r0]\n"
"    cmp     r1, #0xd\n"
"    bhs     loc_fc06b328\n"
"    tbb     [pc, r1]\n" // (jumptable r1 13 elements)
"branchtable_fc06b34a:\n"
"    .byte((loc_fc06b38c - branchtable_fc06b34a) / 2)\n" // (case 0)
"    .byte((loc_fc06b38c - branchtable_fc06b34a) / 2)\n" // (case 1)
"    .byte((loc_fc06b38c - branchtable_fc06b34a) / 2)\n" // (case 2)
"    .byte((loc_fc06b38c - branchtable_fc06b34a) / 2)\n" // (case 3)
"    .byte((loc_fc06b38c - branchtable_fc06b34a) / 2)\n" // (case 4)
"    .byte((loc_fc06b38c - branchtable_fc06b34a) / 2)\n" // (case 5)
"    .byte((loc_fc06b38c - branchtable_fc06b34a) / 2)\n" // (case 6)
"    .byte((loc_fc06b392 - branchtable_fc06b34a) / 2)\n" // (case 7)
"    .byte((loc_fc06b358 - branchtable_fc06b34a) / 2)\n" // (case 8)
"    .byte((loc_fc06b36a - branchtable_fc06b34a) / 2)\n" // (case 9)
"    .byte((loc_fc06b386 - branchtable_fc06b34a) / 2)\n" // (case 10)
"    .byte((loc_fc06b35e - branchtable_fc06b34a) / 2)\n" // (case 11)
"    .byte((loc_fc06b364 - branchtable_fc06b34a) / 2)\n" // (case 12)
".align 1\n"
"loc_fc06b358:\n"   // case 8 - calls close, not seen in normal shooting
"    bl      sub_fc06b50a\n"
"    b       loc_fc06b328\n"
"loc_fc06b35e:\n"   // case 11 - create dir, TODO not patched
"    bl      sub_fc06b556\n"
"    b       loc_fc06b328\n"
"loc_fc06b364:\n"   // case 12 - patch for open, main hoook
"    bl      sub_fc06b0cc_my\n"
"    b       loc_fc06b328\n"
"loc_fc06b36a:\n"   // case 9 - not seen in normal shooting
"    ldr     r1, [r0, #4]\n"
"    movs    r2, #0\n"
"    mov     r4, r0\n"
"    ldr     r0, [r5, #4]\n"
"    bl      _lseek\n"
"    adds    r0, r0, #1\n"
"    bne     loc_fc06b328\n"
"    movs    r0, #7\n"
"    mov     r1, r4\n"
"    str     r6, [r4, #0x14]\n"
"    bl      sub_fc06b054\n"
"    b       loc_fc06b328\n"
"loc_fc06b386:\n"   // case 10 - cache flush, patch for ignore write (NOT Patched)
"    bl      sub_fc06b5aa\n"
"    b       loc_fc06b328\n"
"loc_fc06b38c:\n"   // case 0-6  - write stage
"    bl      sub_fc06b602_my\n"
"    b       loc_fc06b328\n"
"loc_fc06b392:\n"   // case 7 - close stage
"    bl      sub_fc06b1f2_my\n"
"    b       loc_fc06b328\n"
".ltorg\n"
    );
}

// from 100d, not checked
#if 0
// -s=0xfc06b50b -c=30 -f=chdk
void __attribute__((naked,noinline)) sub_fc06b50a_my() {
asm volatile (
"    push    {r2, r3, r4, lr}\n"
"    ldr     r4, =0x00026560\n"
"    movs    r0, #0\n"
"    str     r0, [sp]\n"
"loc_fc06b512:\n"
"    mov     r1, sp\n"
"    ldr     r0, [r4, #0x10]\n"
"    blx     sub_fc2ef8e4\n" // j_GetNumberOfPostedMessages
"    ldr     r0, [sp]\n"
"    cbz     r0, loc_fc06b52a\n"
"    ldr     r0, [r4, #0x10]\n"
"    movs    r2, #0\n"
"    add     r1, sp, #4\n"
"    blx     sub_fc2ef8ec\n" // j_ReceiveMessageQueue
"    b       loc_fc06b512\n"
"loc_fc06b52a:\n"
"    ldr     r0, [r4, #4]\n"
"    adds    r1, r0, #1\n"
"    beq     loc_fc06b54e\n"
"    bl      sub_fc3580fc\n" // j_Close_FW
"    mov.w   r0, #-1\n"
"    str     r0, [r4, #4]\n"
"    movs    r1, #0\n"
"    movs    r0, #0x48\n"
"    bl      sub_fc351f1c\n"
"    ldr     r0, =0x001c83a0\n"
"    bl      sub_fc357e84\n"
"    movs    r1, #0\n"
"    bl      sub_fc073c34\n"
"loc_fc06b54e:\n"
"    ldr     r0, [r4, #0xc]\n"
"    blx     sub_fc2ef96c\n"
"    pop     {r2, r3, r4, pc}\n"
".ltorg\n"
    );
}
#endif

#if 0
// -s=0xfc06b557 -c=32 -f=chdk
void __attribute__((naked,noinline)) sub_fc06b556_my() {
asm volatile (
"    push    {r4, r5, r6, lr}\n"
"    ldr     r5, =0x00026560\n"
"    mov     r4, r0\n"
"    ldr     r0, [r5, #0x18]\n"
"    cbz     r0, loc_fc06b562\n"
"    blx     r0\n"
"loc_fc06b562:\n"
"    add.w   r0, r4, #0x5c\n"
"    mov     r6, r0\n"
"    bl      sub_fc357e84\n" // mounter.c
"    movs    r1, #0\n"
"    bl      sub_fc073bd6\n" // fileio semaphore
"    movs    r1, #0\n"
"    movs    r0, #0x47\n"
"    bl      sub_fc351f1c\n" // DSIC:0x47,0
"    ldr     r0, [r4, #0x10]\n"
"    bl      sub_fc0cfdae\n"
"    mov     r0, r6\n"
"    bl      sub_fc35849e\n" // PrepareDirectory_0
"    movs    r1, #0\n"
"    movs    r0, #0x48\n"
"    bl      sub_fc351f1c\n" // DSIC:0x48,0
"    mov     r0, r6\n"
"    bl      sub_fc357e84\n"
"    ldr     r1, [r5, #0x1c]\n"
"    bl      sub_fc073c34\n"
"    ldr     r1, [r5, #0x14]\n"
"    cmp     r1, #0\n"
"    beq     loc_fc06b5a8\n"
"    ldr     r0, [r4, #0x14]\n"
"    pop.w   {r4, r5, r6, lr}\n"
"    bx      r1\n"
"loc_fc06b5a8:\n"
"    pop     {r4, r5, r6, pc}\n"
".ltorg\n"
    );
}
#endif

// -s=0xfc06b0cd -c=121 -f=chdk
void __attribute__((naked,noinline)) sub_fc06b0cc_my() {
asm volatile (
"    push.w  {r4, r5, r6, r7, r8, sb, lr}\n"
"    mov     r4, r0\n"
//hook placed here to avoid conditional branch a few instructions below (watch out for registers!)
//"  mov   r0, r4\n"      //data block start, commented out as R0 is already holding what we need
"    bl filewrite_main_hook\n"
"    mov     r0, r4\n"      //restore register(s)
"    ldr     r0, [r0, #0x50]\n"
"    sub     sp, #0x3c\n"
"    lsls    r1, r0, #0x1f\n"
"    bne     loc_fc06b0de\n"
"    lsls    r0, r0, #0x1d\n"
"    bpl     loc_fc06b1ce\n"
"loc_fc06b0de:\n"
"    ldr     r7, =0x00026560\n"
"    ldr     r0, [r7, #0x18]\n"
"    cbz     r0, loc_fc06b0e6\n"
"    blx     r0\n"
"loc_fc06b0e6:\n"
"    add.w   r0, r4, #0x5c\n"
"    mov     r8, r0\n"
"    bl      sub_fc357e90\n"
"    movs    r1, #0\n"
"    bl      sub_fc073bd6\n"
"    movs    r1, #0\n"
"    movs    r0, #0x47\n"
"    bl      sub_fc351f28\n"
"    ldr     r0, [r4, #0x50]\n"
"    lsls    r0, r0, #0x1f\n"
"    beq     loc_fc06b1ce\n"
"    ldr     r0, [r4, #0x10]\n"
"    bl      sub_fc0cfdae\n"
"    ldr     r0, [r4, #0x50]\n"
"    movw    r5, #0x301\n"
"    lsls    r1, r0, #0x1b\n"
"    bpl     loc_fc06b118\n"
"    movs    r5, #9\n"
"    b       loc_fc06b11e\n"
"loc_fc06b118:\n"
"    lsls    r1, r0, #0x19\n"
"    bpl     loc_fc06b11e\n"
"    movs    r5, #1\n"
"loc_fc06b11e:\n"
"    lsls    r0, r0, #0x1a\n"
"    bmi     loc_fc06b128\n"
"    ldr     r0, [r4, #0x58]\n"
"    cmp     r0, #1\n"
"    bne     loc_fc06b12c\n"
"loc_fc06b128:\n"
"    orr     r5, r5, #0x8000\n"
"loc_fc06b12c:\n"
"    movw    sb, #0x1b6\n"
"    ldr     r6, [r4, #0x10]\n"
"    mov     r2, sb\n"
"    mov     r1, r5\n"
"    mov     r0, r8\n"
//"    bl      sub_fc3580fa\n" // j_Open_FW
"    bl      fwt_open\n" // +
"    adds    r1, r0, #1\n"
"    bne     loc_fc06b17a\n"
"    mov     r0, r8\n"
"    bl      sub_fc3584aa\n" // PrepareDirectory_0
"    movs    r2, #0xf\n"
"    mov     r1, r8\n"
"    add     r0, sp, #4\n"
"    blx     sub_fc2efa20\n"
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
"    bl      sub_fc0fc21e\n"
"    mov     r2, sb\n"
"    mov     r1, r5\n"
"    mov     r0, r8\n"
"    bl      _Open\n" // j_Open_FW
"loc_fc06b17a:\n"
"    mov     r5, r0\n"
"    str     r0, [r7, #4]\n"
"    adds    r0, r0, #1\n"
"    bne     loc_fc06b1a6\n"
"    movs    r1, #0\n"
"    movs    r0, #0x48\n"
"    bl      sub_fc351f28\n"
"    mov     r0, r8\n"
"    bl      sub_fc357e90\n"
"    ldr     r1, [r7, #0x1c]\n"
"    bl      sub_fc073c34\n"
"    ldr     r1, [r7, #0x14]\n"
"    cmp     r1, #0\n"
"    beq     loc_fc06b1ec\n"
"    add     sp, #0x3c\n"
"    ldr     r0, =0x09200001\n"
"    pop.w   {r4, r5, r6, r7, r8, sb, lr}\n"
"    bx      r1\n"
"loc_fc06b1a6:\n"
"    ldr     r0, =0x001c83a0\n"
"    movs    r2, #0x20\n"
"    mov     r1, r8\n"
"    blx     sub_fc2efa28\n" // j_dry_memcpy
// TODO looks equivalent to elph130, not verified that it's required
//mod start
"    LDR R3, =current_write_ignored\n"
"    LDR R3, [R3]\n"
"    cbnz r3,loc_C\n" // jump over the next block
//mod end
"    ldr     r0, [r4, #0x50]\n"
"    lsls    r0, r0, #0x18\n"
"    bpl     loc_fc06b1ce\n"
"    ldr     r1, [r4, #0xc]\n"
"    mov     r0, r5\n"
"    bl      sub_fc3582c0\n"
"    cbnz    r0, loc_fc06b1cc\n"
"    ldr     r0, =0x09200001\n"
"    mov     r1, r4\n"
"    adds    r0, #0x16\n"
"    str     r0, [r4, #0x14]\n"
"    movs    r0, #7\n"
"    b       loc_fc06b1e4\n"
"loc_fc06b1cc:\n"
"    b       loc_fc06b1ce\n"
"loc_fc06b1ce:\n"
"loc_C:\n"
"    ldr     r0, [r4, #0x50]\n"
"    lsls    r0, r0, #0x19\n"
"    bmi     loc_fc06b1d8\n"
"    ldr     r0, [r4, #4]\n"
"    cbz     r0, loc_fc06b1e0\n"
"loc_fc06b1d8:\n"
"    movs    r0, #9\n"
"    mov     r1, r4\n"
"    bl      sub_fc06b054\n"
"loc_fc06b1e0:\n"
"    movs    r0, #0\n"
"    mov     r1, r4\n"
"loc_fc06b1e4:\n"
"    add     sp, #0x3c\n"
"    pop.w   {r4, r5, r6, r7, r8, sb, lr}\n"
//"    b       loc_fc06b054\n"
"    ldr     pc,=0xfc06b055\n" // avoid stub
"loc_fc06b1ec:\n"
"    add     sp, #0x3c\n"
"    pop.w   {r4, r5, r6, r7, r8, sb, pc}\n"
".ltorg\n"
    );
}

// from 100d, not checked
#if 0
// -s=0xfc06b5ab -c=35 -f=chdk
void __attribute__((naked,noinline)) sub_fc06b5aa_my() {
asm volatile (
"    push    {r3, r4, r5, r6, r7, lr}\n"
"    ldrsb.w r1, [r0, #0x5c]\n"
"    mov     r4, r0\n"
"    cmp     r1, #0\n"
"    beq     loc_fc06b600\n"
"    ldr     r5, =0x00026560\n"
"    movs    r0, #0\n"
"    strb.w  r1, [sp]\n"
"    strb.w  r0, [sp, #1]\n"
"    ldr     r1, [r5, #0x18]\n"
"    cbz     r1, loc_fc06b5c8\n"
"    blx     r1\n"
"loc_fc06b5c8:\n"
"    add.w   r0, r4, #0x5c\n"
"    mov     r6, r0\n"
"    bl      sub_fc357e84\n"
"    movs    r1, #0\n"
"    bl      sub_fc073bd6\n"
"    mov     r0, sp\n"
"    bl      sub_fc0cfdba\n"
"    mov     r4, r0\n"
"    mov     r0, r6\n"
"    bl      sub_fc357e84\n"
"    ldr     r1, [r5, #0x1c]\n"
"    bl      sub_fc073c34\n"
"    ldr     r1, [r5, #0x14]\n"
"    cmp     r1, #0\n"
"    beq     loc_fc06b600\n"
"    cmp     r4, #1\n"
"    bne     loc_fc06b5fa\n"
"    ldr     r0, =0x09200006\n"
"    b       loc_fc06b5fe\n"
"loc_fc06b5fa:\n"
"    ldr     r0, =0x09200006\n"
"    subs    r0, r0, #1\n"
"loc_fc06b5fe:\n"
"    blx     r1\n"
"loc_fc06b600:\n"
"    pop     {r3, r4, r5, r6, r7, pc}\n"
".ltorg\n"
    );
}
#endif

// message 0-6 - filewrite chunks
// -s=0xfc06b603 -c=65 -f=chdk
void __attribute__((naked,noinline)) sub_fc06b602_my() {
asm volatile (
"    push.w  {r4, r5, r6, r7, r8, sb, sl, lr}\n"
"    mov     r5, r0\n"
"    ldr     r0, [r0]\n"
"    cmp     r0, #6\n"
"    bhi     loc_fc06b61a\n"
"    add.w   r0, r5, r0, lsl #3\n"
"    ldrd    r7, r6, [r0, #0x18]\n"
"    cbnz    r6, loc_fc06b62e\n"
"    b       loc_fc06b628\n"
"loc_fc06b61a:\n"
"    movw    r2, #0x36d\n"
"    ldr     r1, =0xfc06b450\n" //  *"dwFWrite.c"
"    movs    r0, #0\n"
"    blx     sub_fc2ef9f0\n" // j_DebugAssert
"loc_fc06b628:\n"
"    movs    r0, #7\n"
"    mov     r1, r5\n"
"    b       loc_fc06b69e\n"
"loc_fc06b62e:\n"
"    ldr.w   sl, =0x00026560\n"
"    mov.w   sb, #0x1000000\n"
"    mov     r4, r6\n"
"loc_fc06b638:\n"
"    ldr     r0, [r5, #4]\n"
"    cmp     r4, sb\n"
"    mov     r1, sb\n"
"    bhi     loc_fc06b642\n"
"    mov     r1, r4\n"
"loc_fc06b642:\n"
"    lsls    r2, r0, #8\n"
"    beq     loc_fc06b654\n"
"    bic     r0, r0, #0xff000000\n"
"    rsb.w   r0, r0, #0x1000000\n"
"    cmp     r1, r0\n"
"    bls     loc_fc06b654\n"
"    mov     r1, r0\n"
"loc_fc06b654:\n"
"    ldr.w   r0, [sl, #4]\n"
"    mov     r8, r1\n"
"    mov     r2, r1\n"
"    mov     r1, r7\n"
//"    bl      sub_fc3581a2\n" // j_Write_FW
"    bl      fwt_write\n" // +
"    ldr     r1, [r5, #4]\n"
"    cmp     r8, r0\n"
"    add     r1, r0\n"
"    str     r1, [r5, #4]\n"
"    beq     loc_fc06b67e\n"
"    adds    r0, r0, #1\n"
"    bne     loc_fc06b676\n"
"    ldr     r0, =0x09200006\n"
"    subs    r0, r0, #1\n"
"    b       loc_fc06b67a\n"
"loc_fc06b676:\n"
"    ldr     r0, =0x09200006\n"
"    adds    r0, #0xf\n"
"loc_fc06b67a:\n"
"    str     r0, [r5, #0x14]\n"
"    b       loc_fc06b628\n"
"loc_fc06b67e:\n"
"    subs    r4, r4, r0\n"
"    cmp     r4, r6\n"
"    add     r7, r0\n"
"    blo     loc_fc06b694\n"
"    movw    r2, #0x398\n"
"    ldr     r1, =0xfc06b450\n" //  *"dwFWrite.c"
"    movs    r0, #0\n"
"    blx     sub_fc2ef9f0\n" // j_DebugAssert
"loc_fc06b694:\n"
"    cmp     r4, #0\n"
"    bne     loc_fc06b638\n"
"    ldr     r0, [r5]\n"
"    mov     r1, r5\n"
"    adds    r0, r0, #1\n"
"loc_fc06b69e:\n"
"    pop.w   {r4, r5, r6, r7, r8, sb, sl, lr}\n"
//"    b       loc_fc06b054\n"
"    ldr     pc,=0xfc06b055\n"
".ltorg\n"
    );
}

// message 7 - close
// -s=0xfc06b1f3 -c=127 -f=chdk
void __attribute__((naked,noinline)) sub_fc06b1f2_my() {
asm volatile (
"    push    {r4, r5, r6, lr}\n"
"    mov     r4, r0\n"
"    ldr     r0, [r0, #0x50]\n"
"    ldr     r5, =0x00026560\n"
"    sub     sp, #0x38\n"
"    lsls    r1, r0, #0x1e\n"
"    bmi     loc_fc06b206\n"
"    lsls    r0, r0, #0x1c\n"
"    bpl     loc_fc06b302\n"
"    b       loc_fc06b248\n"
"loc_fc06b206:\n"
"    lsls    r0, r0, #0x18\n"
"    bpl     loc_fc06b224\n"
"    ldrd    r1, r0, [r4, #8]\n"
"    cmp     r1, r0\n"
"    beq     loc_fc06b224\n"
"    ldr     r0, [r5, #4]\n"
"    bl      sub_fc3582c0\n"
"    cbnz    r0, loc_fc06b220\n"
"    ldr     r0, =0x09200001\n"
"    adds    r0, #0x16\n"
"    str     r0, [r4, #0x14]\n"
"loc_fc06b220:\n"
"    ldr     r0, [r4, #8]\n"
"    str     r0, [sp, #0x28]\n"
"loc_fc06b224:\n"
"    ldr     r0, [r5, #4]\n"
"    adds    r1, r0, #1\n"
"    beq     loc_fc06b248\n"
"    ldr     r6, =0x09200001\n"
"    ldr     r1, [r4, #0x58]\n"
"    adds    r6, r6, #2\n"
"    cmp     r1, #1\n"
"    bne     loc_fc06b23a\n"
//mod start
"    LDR R3, =current_write_ignored\n"
"    LDR R3, [R3]\n"
"    cbnz R3,loc_D\n" // jump over the next block
//mod end
"    bl      sub_fc35810a\n"
"    b       loc_fc06b23e\n"
"loc_fc06b23a:\n"
"loc_D:\n"
//"    bl      sub_fc3580fc\n" // j_Close_FW
"    bl      fwt_close\n" // +
"loc_fc06b23e:\n"
"    cbz     r0, loc_fc06b242\n"
"    str     r6, [r4, #0x14]\n"
"loc_fc06b242:\n"
"    mov.w   r0, #-1\n"
"    str     r0, [r5, #4]\n"
"loc_fc06b248:\n"
"    add.w   r6, r4, #0x5c\n"
"    ldr     r0, [r4, #0x14]\n"
"    lsls    r0, r0, #0x1f\n"
"    bne     loc_fc06b2f0\n"
"    ldr     r0, [r4, #0x50]\n"
"    lsls    r1, r0, #0x1f\n"
"    beq     loc_fc06b274\n"
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
"    b       loc_fc06b296\n"
"loc_fc06b274:\n"
"    lsls    r0, r0, #0x1b\n"
"    bpl     loc_fc06b296\n"
"    add     r1, sp, #0x20\n"
"    mov     r0, r6\n"
"    bl      sub_fc0fc1a8\n"
"    cbnz    r0, loc_fc06b28e\n"
"    movs    r0, #0\n"
"    movw    r2, #0x3ee\n"
"    ldr     r1, =0xfc06b450\n" //  *"dwFWrite.c"
"    blx     sub_fc2ef9f0\n" // j_DebugAssert
"loc_fc06b28e:\n"
"    ldr     r0, [sp, #0x28]\n"
"    ldr     r1, [r4, #4]\n"
"    add     r0, r1\n"
"    str     r0, [sp, #0x28]\n"
"loc_fc06b296:\n"
"    ldr     r0, [r4, #0x50]\n"
"    lsls    r0, r0, #0x19\n"
"    bmi     loc_fc06b2a4\n"
"    add     r1, sp, #0x20\n"
"    mov     r0, r6\n"
"    bl      sub_fc0fc21e\n"
"loc_fc06b2a4:\n"
"    ldr     r0, [r4, #0x50]\n"
"    lsls    r1, r0, #0x1e\n"
"    bpl     loc_fc06b2f0\n"
"    lsls    r0, r0, #0x1a\n"
"    bpl     loc_fc06b2f0\n"
"    movs    r2, #0x20\n"
"    mov     r1, r6\n"
"    mov     r0, sp\n"
"    blx     sub_fc2efa28\n" // j_dry_memcpy
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
"    bl      sub_fc0cff86\n"
"    cbnz    r0, loc_fc06b2e4\n"
"    movs    r0, #0\n"
"    movw    r2, #0x179\n"
"    ldr     r1, =0xfc06b450\n" //  *"dwFWrite.c"
"    blx     sub_fc2ef9f0\n" // j_DebugAssert
"loc_fc06b2e4:\n"
"    mov     r0, sp\n"
"    bl      sub_fc0fc510\n"
"    mov     r0, r6\n"
"    bl      sub_fc0fc510\n"
"loc_fc06b2f0:\n"
"    movs    r1, #0\n"
"    movs    r0, #0x48\n"
"    bl      sub_fc351f28\n"
"    mov     r0, r6\n"
"    bl      sub_fc357e90\n"
"    ldr     r1, [r5, #0x1c]\n"
"    b       loc_fc06b304\n"
"loc_fc06b302:\n"
"    b       loc_fc06b30a\n"
"loc_fc06b304:\n"
"    bl      sub_fc073c34\n"
"    b       loc_fc06b30e\n"
"loc_fc06b30a:\n"
"    ldr     r0, [r5, #0x1c]\n"
"    blx     r0\n"
"loc_fc06b30e:\n"
"    ldr     r1, [r5, #0x14]\n"
"    cmp     r1, #0\n"
"    beq     loc_fc06b318\n"
"    ldr     r0, [r4, #0x14]\n"
"    blx     r1\n"
"loc_fc06b318:\n"
"    add     sp, #0x38\n"
"    pop     {r4, r5, r6, pc}\n"
".ltorg\n"
    );
}
