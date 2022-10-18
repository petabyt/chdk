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
    int maybe_seek_flag;      // 0x2083 jpeg, 0x100 create dir, 0x200 CacheFlush
    int unkn5, unkn6;
    char name[32];
} fwt_data_struct;

/*
sx710 observed message sequences
JPEG
12 maybe_full_size = 0x0058181d (=actual size), seek_flag = 0x2083
 0 chunk 0-0x0058181d
 1 chunk 0-0
 7 close

new directory
11 seek_flag = 0x100
before m 12 for shot, after raw hook in capt_seq

playback switch
10 A/CacheFlush seek_flag 0x200
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
// -s=task_FileWrite -c=43 -f=chdk
void __attribute__((naked,noinline)) filewritetask() {
asm volatile (
// task_FileWrite 0xfc3f7c91
"    push    {r3, r4, r5, r6, r7, lr}\n"
#ifdef FILEWRITE_DEBUG_LOG
"bl log_fwt_start\n"
#endif
"    ldr     r6, =0x09200001\n"
"    movw    r7, #0x477\n"
"    ldr     r5, =0x0002008c\n"
"    adds    r6, #0x12\n"
"loc_fc3f7c9c:\n"
"    mov     r1, sp\n"
"    movs    r2, #0\n"
"    ldr     r0, [r5, #0x14]\n"
"    blx     sub_fc2c7ca0\n" // j_ReceiveMessageQueue
"    cbz     r0, loc_fc3f7cb2\n"
"    movs    r0, #0\n"
"    mov     r2, r7\n"
"    ldr     r1, =0xfc3f7d5c\n" //  *"dwFWrite.c"
"    blx     sub_fc2c7de0\n" // j_DebugAssert
"loc_fc3f7cb2:\n"
#ifdef FILEWRITE_DEBUG_LOG
"ldr     r0, [sp]\n"
"bl log_fwt_msg\n"
#endif
"    ldr     r0, [sp]\n"
"    ldr     r1, [r0]\n"
"    cmp     r1, #0xd\n"
"    bhs     loc_fc3f7c9c\n"
"    tbb     [pc, r1]\n" // (jumptable r1 13 elements)
"branchtable_fc3f7cbe:\n"
"    .byte((loc_fc3f7d00 - branchtable_fc3f7cbe) / 2)\n" // (case 0)
"    .byte((loc_fc3f7d00 - branchtable_fc3f7cbe) / 2)\n" // (case 1)
"    .byte((loc_fc3f7d00 - branchtable_fc3f7cbe) / 2)\n" // (case 2)
"    .byte((loc_fc3f7d00 - branchtable_fc3f7cbe) / 2)\n" // (case 3)
"    .byte((loc_fc3f7d00 - branchtable_fc3f7cbe) / 2)\n" // (case 4)
"    .byte((loc_fc3f7d00 - branchtable_fc3f7cbe) / 2)\n" // (case 5)
"    .byte((loc_fc3f7d00 - branchtable_fc3f7cbe) / 2)\n" // (case 6)
"    .byte((loc_fc3f7d06 - branchtable_fc3f7cbe) / 2)\n" // (case 7)
"    .byte((loc_fc3f7ccc - branchtable_fc3f7cbe) / 2)\n" // (case 8)
"    .byte((loc_fc3f7cde - branchtable_fc3f7cbe) / 2)\n" // (case 9)
"    .byte((loc_fc3f7cfa - branchtable_fc3f7cbe) / 2)\n" // (case 10)
"    .byte((loc_fc3f7cd2 - branchtable_fc3f7cbe) / 2)\n" // (case 11)
"    .byte((loc_fc3f7cd8 - branchtable_fc3f7cbe) / 2)\n" // (case 12)
".align 1\n"
"loc_fc3f7ccc:\n"   // case 8 - calls close, not seen in normal shooting (g7x)
"    bl      sub_fc3f7e7e\n"
"    b       loc_fc3f7c9c\n"
"loc_fc3f7cd2:\n"    // case 11 - create dir, TODO not patched
"    bl      sub_fc3f7eca\n"
"    b       loc_fc3f7c9c\n"
"loc_fc3f7cd8:\n"  // case 12 - patch for open, main hook
"    bl      sub_fc3f7a0c_my\n"
"    b       loc_fc3f7c9c\n"
"loc_fc3f7cde:\n"  // case 9 - not seen in normal shooting (g7x)
"    ldr     r1, [r0, #4]\n"
"    movs    r2, #0\n"
"    mov     r4, r0\n"
"    ldr     r0, [r5, #8]\n"
"    bl      _lseek\n"
"    adds    r0, r0, #1\n"
"    bne     loc_fc3f7c9c\n"
"    movs    r0, #7\n"
"    mov     r1, r4\n"
"    str     r6, [r4, #0x14]\n"
"    bl      sub_fc3f7992\n"
"    b       loc_fc3f7c9c\n"
"loc_fc3f7cfa:\n"     // case 10 - cache flush
"    bl      sub_fc3f7f28\n"
"    b       loc_fc3f7c9c\n"
"loc_fc3f7d00:\n"    // case 0-6  - write stage
"    bl      sub_fc3f7f9a_my\n"
"    b       loc_fc3f7c9c\n"
"loc_fc3f7d06:\n"   // case 7 - close stage
"    bl      sub_fc3f7b3e_my\n"
"    b       loc_fc3f7c9c\n"
".ltorg\n"
    );
}


// -f=chdk -s=0xfc3f7a0d -c=126
void __attribute__((naked,noinline)) sub_fc3f7a0c_my() {
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
"    bne     loc_fc3f7a1e\n"
"    lsls    r0, r0, #0x1d\n"
"    bpl     loc_fc3f7b1a\n"
"loc_fc3f7a1e:\n"
"    ldr     r7, =0x0002008c\n"
"    ldr     r0, [r7, #0x1c]\n"
"    cbz     r0, loc_fc3f7a26\n"
"    blx     r0\n"
"loc_fc3f7a26:\n"
"    add.w   r0, r4, #0x5c\n"
"    mov     r8, r0\n"
"    bl      sub_fc316ffc\n"
"    movs    r1, #0\n"
"    bl      sub_fc0710aa\n"
"    movs    r1, #0\n"
"    movs    r0, #0x47\n"
"    bl      sub_fc305b50\n"
"    ldr     r0, [r4, #0x50]\n"
"    lsls    r0, r0, #0x1f\n"
"    beq     loc_fc3f7b1a\n"
"    ldr     r0, [r4, #0x10]\n"
"    bl      sub_fc16fd22\n"
"    ldr     r0, [r4, #0x50]\n"
"    movw    r5, #0x301\n"
"    lsls    r1, r0, #0x1b\n"
"    bpl     loc_fc3f7a58\n"
"    movs    r5, #9\n"
"    b       loc_fc3f7a5e\n"
"loc_fc3f7a58:\n"
"    lsls    r1, r0, #0x19\n"
"    bpl     loc_fc3f7a5e\n"
"    movs    r5, #1\n"
"loc_fc3f7a5e:\n"
"    lsls    r0, r0, #0x1a\n"
"    bmi     loc_fc3f7a68\n"
"    ldr     r0, [r4, #0x58]\n"
"    cmp     r0, #1\n"
"    bne     loc_fc3f7a6c\n"
"loc_fc3f7a68:\n"
"    orr     r5, r5, #0x8000\n"
"loc_fc3f7a6c:\n"
"    movw    sb, #0x1b6\n"
"    ldr     r6, [r4, #0x10]\n"
"    mov     r2, sb\n"
"    mov     r1, r5\n"
"    mov     r0, r8\n"
//"    bl      sub_fc317272\n" // j_Open_FW
"    bl      fwt_open\n" // +
"    adds    r1, r0, #1\n"
"    bne     loc_fc3f7aba\n"
"    mov     r0, r8\n"
"    bl      sub_fc317616\n" // PrepareDirectory_0
"    movs    r2, #0xf\n"
"    mov     r1, r8\n"
"    add     r0, sp, #4\n"
"    blx     sub_fc2c7d80\n"
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
"    bl      sub_fc1702ca\n"
"    mov     r2, sb\n"
"    mov     r1, r5\n"
"    mov     r0, r8\n"
"    bl      _Open\n" // j_Open_FW
"loc_fc3f7aba:\n"
"    mov     r5, r0\n"
"    str     r0, [r7, #8]\n"
"    adds    r0, r0, #1\n"
"    bne     loc_fc3f7af2\n"
"    movs    r1, #0\n"
"    movs    r0, #0x48\n"
"    bl      sub_fc305b50\n"
"    mov     r0, r8\n"
"    bl      sub_fc316ffc\n"
"    ldr     r1, [r7, #0x20]\n"
"    bl      sub_fc071108\n"
"    ldr     r0, [r7, #0x18]\n"
"    cmp     r0, #0\n"
"    beq     loc_fc3f7b38\n"
"    ldr     r5, =0x09200001\n"
"    mov     r0, r4\n"
"    mov     r1, r5\n"
"    bl      sub_fc3f7958\n"
"    ldr     r1, [r7, #0x18]\n"
"    add     sp, #0x3c\n"
"    mov     r0, r5\n"
"    pop.w   {r4, r5, r6, r7, r8, sb, lr}\n"
"    bx      r1\n"
"loc_fc3f7af2:\n"
"    ldr     r0, =0x001c7acc\n"
"    movs    r2, #0x20\n"
"    mov     r1, r8\n"
"    blx     sub_fc2c7d78\n" // j_dry_memcpy
// TODO looks equivalent to elph130, not verified that it's required
//mod start
"    LDR R3, =current_write_ignored\n"
"    LDR R3, [R3]\n"
"    cbnz r3,loc_C\n" // jump over the next block
//mod end
"    ldr     r0, [r4, #0x50]\n"
"    lsls    r0, r0, #0x18\n"
"    bpl     loc_fc3f7b1a\n"
"    ldr     r1, [r4, #0xc]\n"
"    mov     r0, r5\n"
"    bl      sub_fc31742c\n"
"    cbnz    r0, loc_fc3f7b18\n"
"    ldr     r0, =0x09200001\n"
"    mov     r1, r4\n"
"    adds    r0, #0x16\n"
"    str     r0, [r4, #0x14]\n"
"    movs    r0, #7\n"
"    b       loc_fc3f7b30\n"
"loc_fc3f7b18:\n"
"    b       loc_fc3f7b1a\n"
"loc_fc3f7b1a:\n"
"loc_C:\n"
"    ldr     r0, [r4, #0x50]\n"
"    lsls    r0, r0, #0x19\n"
"    bmi     loc_fc3f7b24\n"
"    ldr     r0, [r4, #4]\n"
"    cbz     r0, loc_fc3f7b2c\n"
"loc_fc3f7b24:\n"
"    movs    r0, #9\n"
"    mov     r1, r4\n"
"    bl      sub_fc3f7992\n"
"loc_fc3f7b2c:\n"
"    movs    r0, #0\n"
"    mov     r1, r4\n"
"loc_fc3f7b30:\n"
"    add     sp, #0x3c\n"
"    pop.w   {r4, r5, r6, r7, r8, sb, lr}\n"
//"    b       loc_fc3f7992\n"
"    ldr     pc,=0xfc3f7993\n" // avoid stub
"loc_fc3f7b38:\n"
"    add     sp, #0x3c\n"
"    pop.w   {r4, r5, r6, r7, r8, sb, pc}\n"
".ltorg\n"
    );
}


// message 0-6 - filewrite chunks
// -f=chdk -s=0xfc3f7f9b -c=65
void __attribute__((naked,noinline)) sub_fc3f7f9a_my() {
asm volatile (
"    push.w  {r4, r5, r6, r7, r8, sb, sl, lr}\n"
"    mov     r5, r0\n"
"    ldr     r0, [r0]\n"
"    cmp     r0, #6\n"
"    bhi     loc_fc3f7fb2\n"
"    add.w   r0, r5, r0, lsl #3\n"
"    ldrd    r7, r6, [r0, #0x18]\n"
"    cbnz    r6, loc_fc3f7fc6\n"
"    b       loc_fc3f7fc0\n"
"loc_fc3f7fb2:\n"
"    movw    r2, #0x3b4\n"
"    ldr     r1, =0xfc3f7d5c\n" //  *"dwFWrite.c"
"    movs    r0, #0\n"
"    blx     sub_fc2c7de0\n" // j_DebugAssert
"loc_fc3f7fc0:\n"
"    movs    r0, #7\n"
"    mov     r1, r5\n"
"    b       loc_fc3f8036\n"
"loc_fc3f7fc6:\n"
"    ldr.w   sl, =0x0002008c\n"
"    mov.w   sb, #0x1000000\n"
"    mov     r4, r6\n"
"loc_fc3f7fd0:\n"
"    ldr     r0, [r5, #4]\n"
"    cmp     r4, sb\n"
"    mov     r1, sb\n"
"    bhi     loc_fc3f7fda\n"
"    mov     r1, r4\n"
"loc_fc3f7fda:\n"
"    lsls    r2, r0, #8\n"
"    beq     loc_fc3f7fec\n"
"    bic     r0, r0, #0xff000000\n"
"    rsb.w   r0, r0, #0x1000000\n"
"    cmp     r1, r0\n"
"    bls     loc_fc3f7fec\n"
"    mov     r1, r0\n"
"loc_fc3f7fec:\n"
"    ldr.w   r0, [sl, #8]\n"
"    mov     r8, r1\n"
"    mov     r2, r1\n"
"    mov     r1, r7\n"
//"    bl      sub_fc31731a\n" // j_Write_FW
"    bl      fwt_write\n" // +
"    ldr     r1, [r5, #4]\n"
"    cmp     r8, r0\n"
"    add     r1, r0\n"
"    str     r1, [r5, #4]\n"
"    beq     loc_fc3f8016\n"
"    adds    r0, r0, #1\n"
"    bne     loc_fc3f800e\n"
"    ldr     r0, =0x09200006\n"
"    subs    r0, r0, #1\n"
"    b       loc_fc3f8012\n"
"loc_fc3f800e:\n"
"    ldr     r0, =0x09200006\n"
"    adds    r0, #0xf\n"
"loc_fc3f8012:\n"
"    str     r0, [r5, #0x14]\n"
"    b       loc_fc3f7fc0\n"
"loc_fc3f8016:\n"
"    subs    r4, r4, r0\n"
"    cmp     r4, r6\n"
"    add     r7, r0\n"
"    blo     loc_fc3f802c\n"
"    movw    r2, #0x3de\n"
"    ldr     r1, =0xfc3f7d5c\n" //  *"dwFWrite.c"
"    movs    r0, #0\n"
"    blx     sub_fc2c7de0\n" // j_DebugAssert
"loc_fc3f802c:\n"
"    cmp     r4, #0\n"
"    bne     loc_fc3f7fd0\n"
"    ldr     r0, [r5]\n"
"    mov     r1, r5\n"
"    adds    r0, r0, #1\n"
"loc_fc3f8036:\n"
"    pop.w   {r4, r5, r6, r7, r8, sb, sl, lr}\n"
//"    b       loc_fc3f7992\n"
"    ldr     pc,=0xfc3f7993\n"
".ltorg\n"
    );
}

// message 7 - close
// -f=chdk -s=0xfc3f7b3f -c=145
void __attribute__((naked,noinline)) sub_fc3f7b3e_my() {
asm volatile (
"    push    {r4, r5, r6, r7, lr}\n"
"    mov     r4, r0\n"
"    ldr     r0, [r0, #0x50]\n"
"    ldr     r5, =0x0002008c\n"
"    sub     sp, #0x3c\n"
"    add.w   r7, r4, #0x5c\n"
"    lsls    r1, r0, #0x1e\n"
"    bmi     loc_fc3f7b56\n"
"    lsls    r0, r0, #0x1c\n"
"    bpl     loc_fc3f7c52\n"
"    b       loc_fc3f7baa\n"
"loc_fc3f7b56:\n"
"    lsls    r0, r0, #0x18\n"
"    bpl     loc_fc3f7b86\n"
"    ldrd    r1, r0, [r4, #8]\n"
"    cmp     r1, r0\n"
"    beq     loc_fc3f7b86\n"
"    ldr     r0, [r5, #8]\n"
"    bl      sub_fc31742c\n"
"    cbnz    r0, loc_fc3f7b72\n"
"    ldr     r0, =0x09200001\n"
"    adds    r0, #0x16\n"
"    str     r0, [r4, #0x14]\n"
"    b       loc_fc3f7b86\n"
"loc_fc3f7b72:\n"
"    ldr     r0, [r4, #8]\n"
"    add     r1, sp, #0x24\n"
"    str     r0, [r4, #4]\n"
"    mov     r0, r7\n"
"    bl      sub_fc170254\n"
"    cmp     r0, #1\n"
"    bne     loc_fc3f7b86\n"
"    ldr     r0, [r4, #4]\n"
"    str     r0, [sp, #0x2c]\n"
"loc_fc3f7b86:\n"
"    ldr     r0, [r5, #8]\n"
"    adds    r1, r0, #1\n"
"    beq     loc_fc3f7baa\n"
"    ldr     r6, =0x09200001\n"
"    ldr     r1, [r4, #0x58]\n"
"    adds    r6, r6, #2\n"
"    cmp     r1, #1\n"
"    bne     loc_fc3f7b9c\n"
//mod start
"    LDR R3, =current_write_ignored\n"
"    LDR R3, [R3]\n"
"    cbnz R3,loc_D\n" // jump over the next block
//mod end
"    bl      sub_fc317276\n"
"    b       loc_fc3f7ba0\n"
"loc_fc3f7b9c:\n"
"loc_D:\n"
//"    bl      sub_fc317274\n" // j_Close_FW
"    bl      fwt_close\n" // +
"loc_fc3f7ba0:\n"
"    cbz     r0, loc_fc3f7ba4\n"
"    str     r6, [r4, #0x14]\n"
"loc_fc3f7ba4:\n"
"    mov.w   r0, #-1\n"
"    str     r0, [r5, #8]\n"
"loc_fc3f7baa:\n"
"    ldr     r0, [r4, #0x14]\n"
"    lsls    r0, r0, #0x1f\n"
"    bne     loc_fc3f7c5e\n"
"    ldr     r0, [r4, #0x50]\n"
"    lsls    r1, r0, #0x1f\n"
"    beq     loc_fc3f7bd2\n"
"    movw    r0, #0x81ff\n"
"    str     r0, [sp, #0x24]\n"
"    movs    r0, #0x20\n"
"    str     r0, [sp, #0x28]\n"
"    ldr     r0, [r4, #4]\n"
"    str     r0, [sp, #0x2c]\n"
"    ldr     r0, [r4, #0x10]\n"
"    str     r0, [sp, #0x30]\n"
"    ldr     r0, [r4, #0x10]\n"
"    str     r0, [sp, #0x34]\n"
"    ldr     r0, [r4, #0x10]\n"
"    str     r0, [sp, #0x38]\n"
"    b       loc_fc3f7bf4\n"
"loc_fc3f7bd2:\n"
"    lsls    r0, r0, #0x1b\n"
"    bpl     loc_fc3f7bfa\n"
"    add     r1, sp, #0x24\n"
"    mov     r0, r7\n"
"    bl      sub_fc170254\n"
"    cbnz    r0, loc_fc3f7bec\n"
"    movs    r0, #0\n"
"    movw    r2, #0x43a\n"
"    ldr     r1, =0xfc3f7d5c\n" //  *"dwFWrite.c"
"    blx     sub_fc2c7de0\n" // j_DebugAssert
"loc_fc3f7bec:\n"
"    ldr     r0, [sp, #0x2c]\n"
"    ldr     r1, [r4, #4]\n"
"    add     r0, r1\n"
"    str     r0, [sp, #0x2c]\n"
"loc_fc3f7bf4:\n"
"    ldr     r0, [r4, #0x50]\n"
"    lsls    r0, r0, #0x1f\n"
"    bne     loc_fc3f7c04\n"
"loc_fc3f7bfa:\n"
"    ldr     r0, [r4, #0x50]\n"
"    lsls    r1, r0, #0x1e\n"
"    bmi     loc_fc3f7c04\n"
"    lsls    r0, r0, #0x1b\n"
"    bpl     loc_fc3f7c5e\n"
"loc_fc3f7c04:\n"
"    add     r1, sp, #0x24\n"
"    mov     r0, r7\n"
"    bl      sub_fc1702ca\n"
"    ldr     r0, [r4, #0x50]\n"
"    lsls    r1, r0, #0x1e\n"
"    bpl     loc_fc3f7c5e\n"
"    lsls    r0, r0, #0x1a\n"
"    bpl     loc_fc3f7c5e\n"
"    movs    r2, #0x20\n"
"    mov     r1, r7\n"
"    add     r0, sp, #4\n"
"    blx     sub_fc2c7d78\n" // j_dry_memcpy
"    add     r0, sp, #4\n"
"    bl      _strlen\n"
"    add     r2, sp, #4\n"
"    add     r0, r2\n"
"    movs    r1, #0x54\n"
"    strb    r1, [r0, #-0x3]!\n"
"    movs    r1, #0x4d\n"
"    strb    r1, [r0, #1]\n"
"    movs    r1, #0x50\n"
"    strb    r1, [r0, #2]\n"
"    add     r1, sp, #4\n"
"    mov     r0, r7\n"
"    bl      sub_fc16fefa\n"
"    cbnz    r0, loc_fc3f7c4e\n"
"    movs    r0, #0\n"
"    movw    r2, #0x1bd\n"
"    ldr     r1, =0xfc3f7d5c\n" //  *"dwFWrite.c"
"    blx     sub_fc2c7de0\n" // j_DebugAssert
"loc_fc3f7c4e:\n"
"    add     r0, sp, #4\n"
"    b       loc_fc3f7c54\n"
"loc_fc3f7c52:\n"
"    b       loc_fc3f7c74\n"
"loc_fc3f7c54:\n"
"    bl      sub_fc1705bc\n"
"    mov     r0, r7\n"
"    bl      sub_fc1705bc\n"
"loc_fc3f7c5e:\n"
"    movs    r1, #0\n"
"    movs    r0, #0x48\n"
"    bl      sub_fc305b50\n"
"    mov     r0, r7\n"
"    bl      sub_fc316ffc\n"
"    ldr     r1, [r5, #0x20]\n"
"    bl      sub_fc071108\n"
"    b       loc_fc3f7c78\n"
"loc_fc3f7c74:\n"
"    ldr     r0, [r5, #0x20]\n"
"    blx     r0\n"
"loc_fc3f7c78:\n"
"    ldr     r0, [r5, #0x18]\n"
"    cmp     r0, #0\n"
"    beq     loc_fc3f7c8c\n"
"    ldr     r1, [r4, #0x14]\n"
"    mov     r0, r4\n"
"    bl      sub_fc3f7958\n"
"    ldr     r1, [r5, #0x18]\n"
"    ldr     r0, [r4, #0x14]\n"
"    blx     r1\n"
"loc_fc3f7c8c:\n"
"    add     sp, #0x3c\n"
"    pop     {r4, r5, r6, r7, pc}\n"
".ltorg\n"
    );
}
