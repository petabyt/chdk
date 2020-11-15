#include "lolevel.h"
#include "platform.h"
// all of this copied and adjusted from g7x coding by reyalp

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
// // task_FileWrite 0xfc065dc7  -s=task_FileWrite -c=43 -f=chdk
void __attribute__((naked,noinline)) filewritetask() {
asm volatile (
// task_FileWrite 0xfc065dc7
"    push    {r3, r4, r5, r6, r7, lr}\n"
"       ldr     r6, =0x09200001\n"
"       movw    r7, #0x477\n"
"       ldr     r5, =0x0003d674\n"
"       adds    r6, #0x12\n"
" loc_fc068b94:\n"
"       mov     r1, sp\n"
"       movs    r2, #0\n"
"       ldr     r0, [r5,#20]\n"
"       blx     sub_FC3022D4\n" // j_ReceiveMessageQueue
"       cbz     r0, loc_fc068baa\n"
"       movs    r0, #0\n"
"       mov     r2, r7\n"
"       ldr     r1, =0xfc068c54\n" //  *"dwFWrite.c"
"       blx     sub_FC302434\n" // j_DebugAssert
" loc_fc068baa:\n"
#ifdef FILEWRITE_DEBUG_LOG
"       ldr     r0, [sp]\n"
"bl log_fwt_msg\n"
#endif
"    ldr     r0, [sp]\n"
"       ldr     r1, [r0]\n"
"       cmp     r1, #0xd\n"
"       bcs     loc_fc068b94\n"
"       tbb.w   [pc,r1]\n"
"branchtable_fc068bb2:\n"
"    .byte((loc_fc068bf8 - branchtable_fc068bb2) / 2)\n" // (case 0)
"    .byte((loc_fc068bf8 - branchtable_fc068bb2) / 2)\n" // (case 1)
"    .byte((loc_fc068bf8 - branchtable_fc068bb2) / 2)\n" // (case 2)
"    .byte((loc_fc068bf8 - branchtable_fc068bb2) / 2)\n" // (case 3)
"    .byte((loc_fc068bf8 - branchtable_fc068bb2) / 2)\n" // (case 4)
"    .byte((loc_fc068bf8 - branchtable_fc068bb2) / 2)\n" // (case 5)
"    .byte((loc_fc068bf8 - branchtable_fc068bb2) / 2)\n" // (case 6)
"    .byte((loc_fc068bfe - branchtable_fc068bb2) / 2)\n" // (case 7)
"    .byte((loc_fc068bc4 - branchtable_fc068bb2) / 2)\n" // (case 8)
"    .byte((loc_fc068bd6 - branchtable_fc068bb2) / 2)\n" // (case 9)
"    .byte((loc_fc068bf2 - branchtable_fc068bb2) / 2)\n" // (case 10)
"    .byte((loc_fc068bca - branchtable_fc068bb2) / 2)\n" // (case 11)
"    .byte((loc_fc068bd0 - branchtable_fc068bb2) / 2)\n" // (case 12)
".align 1\n"
" loc_fc068bc4:\n"   // case 8 - calls close, not seen in normal shooting
"       bl      sub_fc068d76\n"
"       b       loc_fc068b94\n"
" loc_fc068bca:\n"   // case 11 - create dir, TODO not patched
"       bl      sub_fc068dc2\n"
"       b       loc_fc068b94\n"
" loc_fc068bd0:\n"   // case 12 - patch for open, main hook
"       bl      sub_fc068904_my\n"
"       b       loc_fc068b94\n"
" loc_fc068bd6:\n"   // case 9 - not seen in normal shooting
"       ldr     r1, [r0,#4]\n"
"       movs    r2, #0\n"
"       mov     r4, r0\n"
"       ldr     r0, [r5,#8]\n"
"       bl      sub_fc37a9cc\n" // -> fwt_lseek ?
"       adds    r0, r0, #1\n"
"       bne     loc_fc068b94\n"
"       movs    r0, #7\n"
"       mov     r1, r4\n"
"       str     r6, [r4,#0x14]\n"
"       bl      sub_fc06888a\n"
"       b       loc_fc068b94\n"
" loc_fc068bf2:\n"   // case 10 - cache flush, patch for ignore write
"       bl      sub_fc068e20\n"
"       b       loc_fc068b94\n"
" loc_fc068bf8:\n"     // case 0-6  - write stage
"       bl      sub_fc068e92_my\n" //_my ?????
"       b       loc_fc068b94\n"
" loc_fc068bfe:\n"  // case 7 - close stage
"       bl      sub_fc068a36_my\n"
"       b       loc_fc068b94\n"
".ltorg\n"
    );
}
// -s=0xfc068904_my-c=121 -f=chdk
void __attribute__((naked,noinline)) sub_fc068904_my() {
asm volatile (
"    push.w  {r4, r5, r6, r7, r8, r9, lr}\n"
"    mov     r4, r0\n"
//hook placed here to avoid conditional branch a few instructions below (watch out for registers!)
//"  mov   r0, r4\n"      //data block start, commented out as R0 is already holding what we need
"    BL      filewrite_main_hook\n"
"    mov     r0, r4\n"      //restore register(s)
"       ldr     r0, [r0,#0x50]\n"
"       sub     sp, sp, #0x3c\n"
"       lsls    r1, r0, #0x1f\n"
"       bne     loc_fc068916\n"
"       lsls    r0, r0, #0x1d\n"
"       bpl     loc_fc068a12\n"
" loc_fc068916:\n"
"       ldr     r7, =0x0003d674\n"
"       ldr     r0, [r7,#28]\n"
"       cbz     r0, loc_fc06891e\n"
"       blx     r0\n"
" loc_fc06891e:\n"
"       add.w   r0, r4, #0x5c\n"
"       mov     r8, r0\n"
"       bl      sub_FC37A5DC\n"
"       movs    r1, #0\n"
"       bl      sub_fc06e242\n"
"       movs    r1, #0\n"
"       movs    r0, #0x47\n"
"       bl      sub_FC35DEAC\n"
"       ldr     r0, [r4,#0x50]\n"
"       lsls    r0, r0, #0x1f\n"
"       beq     loc_fc068a12\n"
"       ldr     r0, [r4,#0x10]\n"
"       bl      sub_fc0da40e\n"
"       ldr     r0, [r4,#0x50]\n"
"       movw    r5, #0x301\n"
"       lsls    r1, r0, #0x1b\n"
"       bpl     loc_fc068950\n"
"       movs    r5, #9\n"
"       b       loc_fc068956\n"
" loc_fc068950:\n"
"       lsls    r1, r0, #0x19\n"
"       bpl     loc_fc068956\n"
"       movs    r5, #1\n"
" loc_fc068956:\n"
"       lsls    r0, r0, #0x1a\n"
"       bmi     loc_fc068960\n"
"       ldr     r0, [r4,#0x58]\n"
"       cmp     r0, #1\n"
"       bne     loc_fc068964\n"
" loc_fc068960:\n"
"       orr.w   r5, r5, #0x8000\n"
" loc_fc068964:\n"
"       movw    r9, #0x1b6\n"
"       ldr     r6, [r4,#0x10]\n"
"       mov     r2, r9\n"
"       mov     r1, r5\n"
"       mov     r0, r8\n"
//"       bl      sub_fc37a576\n" // j_Open_FW
"    bl      fwt_open\n" // +
"       adds    r1, r0, #1\n"
"       bne     loc_fc0689b2\n"
"       mov     r0, r8\n"
"       bl      sub_FC37AC8A\n" // PrepareDirectory_0
"       movs    r2, #0xf\n"
"       mov     r1, r8\n"
"       add     r0, sp, #4\n"
"       blx     sub_FC30242C\n"
"       movs    r0, #0\n"
"       strb.w  r0, [sp,#19]\n"
"       movw    r1, #0x41ff\n"
"       str     r1, [sp,#36]\n"
"       strd.w  r0, r6, [sp,#0x2c]\n"
"       movs    r1, #0x10\n"
"       str     r6, [sp,#52]\n"
"       add     r0, sp, #4\n"
"       str     r6, [sp,#56]\n"
"       str     r1, [sp,#40]\n"
"       add     r1, sp, #36\n"
"       bl      sub_fc10f10e\n"
"       mov     r2, r9\n"
"       mov     r1, r5\n"
"       mov     r0, r8\n"
"       bl      sub_FC37A8E6\n" // j_Open_FW this is not Open 0xfc3328fd
" loc_fc0689b2:\n"
"       mov     r5, r0\n"
"       str     r0, [r7,#8]\n"
"       adds    r0, r0, #1\n"
"       bne     loc_fc0689ea\n"
"       movs    r1, #0\n"
"       movs    r0, #0x48\n"
"       bl      sub_FC35DEAC\n" // "DSIC:0x48,0"
"       mov     r0, r8\n"
"       bl      sub_FC37A5DC\n"
"       ldr     r1, [r7,#0x20]\n"
"       bl      sub_fc06e2a0\n"
"       ldr     r0, [r7,#0x18]\n"
"       cmp     r0, #0\n"
"       beq     loc_fc068a30\n"
"       ldr     r5, =0x09200001\n"
"       mov     r0, r4\n"
"       mov     r1, r5\n"
"       bl      sub_fc068850\n"
"       ldr     r1, [r7,#0x18]\n"
"       add     sp, sp, #0x3c\n"
"       mov     r0, r5\n"
"       pop.w   {r4, r5, r6, r7, r8, r9,lr}\n"
"       bx      r1\n"
" loc_fc0689ea:\n"
"       ldr     r0, =0x0023BE20\n"
"       movs    r2, #0x20\n"
"       mov     r1, r8\n"
"       blx     sub_FC302414\n" // j_dry_memcpy
// TODO looks equivalent to elph130, not verified that it's required
//mod start
"    LDR R3, =current_write_ignored\n"
"    LDR R3, [R3]\n"
"    cbnz r3,loc_C\n" // jump over the next block
//mod end
"       ldr     r0, [r4,#0x50]\n"
"       lsls    r0, r0, #0x18\n"
"       bpl     loc_fc068a12\n"
"       ldr     r1, [r4,#0xc]\n"
"       mov     r0, r5\n"
"       bl      sub_FC37AAA0\n"
"       cbnz    r0, loc_fc068a10\n"
"       ldr     r0, =0x09200001\n"
"       mov     r1, r4\n"
"       adds    r0, #0x16\n"
"       str     r0, [r4,#0x14]\n"
"       movs    r0, #7\n"
"       b       loc_fc068a28\n"
" loc_fc068a10:\n"
"       b       loc_fc068a12\n"
" loc_fc068a12:\n"
"loc_C:\n"
"       ldr     r0, [r4,#0x50]\n"
"       lsls    r0, r0, #0x19\n"
"       bmi     loc_fc068a1c\n"
"       ldr     r0, [r4,#4]\n"
"       cbz     r0, loc_fc068a24\n"
" loc_fc068a1c:\n"
"       movs    r0, #9\n"
"       mov     r1, r4\n"
"       bl      sub_fc06888a\n"
" loc_fc068a24:\n"
"       movs    r0, #0\n"
"       mov     r1, r4\n"
" loc_fc068a28:\n"
"       add     sp, sp, #0x3c\n"
"       pop.w   {r4, r5, r6, r7, r8, r9,lr}\n"
//"       b       sub_fc06888a\n"
"    	ldr     pc, =0xfc06888b\n"
" loc_fc068a30:\n"
"       add     sp, sp, #0x3c\n"
"       pop.w   {r4, r5, r6, r7, r8,r9,pc}\n"
".ltorg\n"
    );
}
// message 0-6 - filewrite chunks
// -s=0xfc068e92 -c=65 -f=chdk
void __attribute__((naked,noinline)) sub_fc068e92_my() {
asm volatile (
"    push.w  {r4, r5, r6, r7, r8, r9, r10, lr}\n"
"       mov     r5, r0\n"
"       ldr     r0, [r0]\n"
"       cmp     r0, #6\n"
"       bhi     loc_fc068eaa\n"
"       add.w   r0, r5, r0,lsl #3\n"
"       ldrd.w  r7, r6, [r0,#0x18]\n"
"       cbnz    r6, loc_fc068ebe\n"
"       b       loc_fc068eb8\n"
" loc_fc068eaa:\n"
"       movw    r2, #0x3b4\n"
"       ldr     r1, =0xfc068c54\n" //  *"dwFWrite.c"
"       movs    r0, #0\n"
"       blx     sub_fc302410\n" // j_DebugAssert
" loc_fc068eb8:\n"
"       movs    r0, #7\n"
"       mov     r1, r5\n"
"       b       loc_fc068f2e\n"
" loc_fc068ebe:\n"
"       ldr.w   r10, =0x0003d674\n"
"       mov.w   r9, #0x1000000\n"
"       mov     r4, r6\n"
" loc_fc068ec8:\n"
"       ldr     r0, [r5,#4]\n"
"       cmp     r4, r9\n"
"       mov     r1, r9\n"
"       bhi     loc_fc068ed2\n"
"       mov     r1, r4\n"
" loc_fc068ed2:\n"
"       lsls    r2, r0, #8\n"
"       beq     loc_fc068ee4\n"
"       bic.w   r0, r0, #0xff000000\n"
"       rsb.w   r0, r0, #0x1000000\n"
"       cmp     r1, r0\n"
"       bls     loc_fc068ee4\n"
"       mov     r1, r0\n"
" loc_fc068ee4:\n"
"       ldr.w   r0, [r10,#8]\n"
"       mov     r8, r1\n"
"       mov     r2, r1\n"
"       mov     r1, r7\n"
//"       bl      loc_FC37A98E \n"// j_Write_FW
"    	bl      fwt_write\n" // +
"       ldr     r1, [r5,#4]\n"
"       cmp     r8, r0\n"
"       add     r1, r0\n"
"       str     r1, [r5,#4]\n"
"       beq     loc_fc068f0e\n"
"       adds    r0, r0, #1\n"
"       bne     loc_fc068f06\n"
"       ldr     r0, =0x9200006\n"
"       subs    r0, r0, #1\n"
"       b       loc_fc068f0a\n"
" loc_fc068f06:\n"
"       ldr     r0, =0x9200006\n"
"       adds    r0, #0xf\n"
" loc_fc068f0a:\n"
"       str     r0, [r5,#0x14]\n"
"       b       loc_fc068eb8\n"
" loc_fc068f0e:\n"
"       subs    r4, r4, r0\n"
"       cmp     r4, r6\n"
"       add     r7, r0\n"
"       bcc     loc_fc068f24\n"
"       movw    r2, #0x3de\n"
"       ldr	    r1, =0xfc068c54\n" //  *"dwFWrite.c"
"       movs    r0, #0\n"
"       blx     sub_FC302434\n" // j_DebugAssert
" loc_fc068f24:\n"
"       cmp     r4, #0\n"
"       bne     loc_fc068ec8\n"
"       ldr     r0, [r5]\n"
"       mov     r1, r5\n"
"       adds    r0, r0, #1\n"
" loc_fc068f2e:\n"
"    	pop.w   {r4, r5, r6, r7, r8, r9, r10, lr}\n"
//"       b       sub_fc06888a\n"
"    	ldr     pc,=0xfc06888b\n"
".ltorg\n"
    );
}
// message 7 - close
// -s=0xfc068a36 -c=124 -f=chdk
void __attribute__((naked,noinline)) sub_fc068a36_my() {
asm volatile (
"    push    {r4, r5, r6, r7, lr}\n"
"       mov     r4, r0\n"
"       ldr     r0, [r0,#0x50]\n"
"       ldr     r5, =0x0003d674\n"
"       sub     sp, sp, #0x3c\n"
"       add.w   r7, r4, #0x5c\n"
"       lsls    r1, r0, #0x1e\n"
"       bmi     loc_fc068a4e\n"
"       lsls    r0, r0, #0x1c\n"
"       bpl     loc_fc068b4a\n"
"       b       loc_fc068aa2\n"
" loc_fc068a4e:\n"
"       lsls    r0, r0, #0x18\n"
"       bpl     loc_fc068a7e\n"
"       ldrd.w  r1, r0, [r4,#8]\n"
"       cmp     r1, r0\n"
"       beq     loc_fc068a7e\n"
"       ldr     r0, [r5,#8]\n"
"       bl      sub_FC37AAA0\n"
"       cbnz    r0, loc_fc068a6a\n"
"       ldr     r0, =0x09200001\n"
"       adds    r0, #0x16\n"
"       str     r0, [r4,#0x14]\n"
"       b       loc_fc068a7e\n"
" loc_fc068a6a:\n"
"       ldr     r0, [r4,#8]\n"
"       add     r1, sp, #36\n"
"       str     r0, [r4,#4]\n"
"       mov     r0, r7\n"
"       bl      sub_FC10F180\n"
"       cmp     r0, #1\n"
"       bne     loc_fc068a7e\n"
"       ldr     r0, [r4,#4]\n"
"       str     r0, [sp,#44]\n"
" loc_fc068a7e:\n"
"       ldr     r0, [r5,#8]\n"
"       adds    r1, r0, #1\n"
"       beq     loc_fc068aa2\n"
"       ldr     r6, =0x09200001\n"
"       ldr     r1, [r4,#0x58]\n"
"       adds    r6, r6, #2\n"
"       cmp     r1, #1\n"
"       bne     loc_fc068a94\n"
//mod start
"    LDR R3, =current_write_ignored\n"
"    LDR R3, [R3]\n"
"    cbnz R3,loc_D\n" // jump over the next block
//mod end
"       bl      sub_FC37A8EA\n"
"       b       loc_fc068a98\n"
" loc_fc068a94:\n"
"loc_D:\n"
//"       bl      sub_FC37A8E8\n" // j_Close_FW
"    bl      fwt_close\n" // +
" loc_fc068a98:\n"
"       cbz     r0, loc_fc068a9c\n"
"       str     r6, [r4,#0x14]\n"
" loc_fc068a9c:\n"
"       mov.w   r0, #0xffffffff\n"
"       str     r0, [r5,#8]\n"
" loc_fc068aa2:\n"
"       ldr     r0, [r4,#0x14]\n"
"       lsls    r0, r0, #0x1f\n"
"       bne     loc_fc068b56\n"
"       ldr     r0, [r4,#0x50]\n"
"       lsls    r1, r0, #0x1f\n"
"       beq     loc_fc068aca\n"
"       movw    r0, #0x81ff\n"
"       str     r0, [sp,#36]\n"
"       movs    r0, #0x20\n"
"       str     r0, [sp,#40]\n"
"       ldr     r0, [r4,#4]\n"
"       str     r0, [sp,#44]\n"
"       ldr     r0, [r4,#0x10]\n"
"       str     r0, [sp,#48]\n"
"       ldr     r0, [r4,#0x10]\n"
"       str     r0, [sp,#52]\n"
"       ldr     r0, [r4,#0x10]\n"
"       str     r0, [sp,#56]\n"
"       b       loc_fc068aec\n"
" loc_fc068aca:\n"
"       lsls    r0, r0, #0x1b\n"
"       bpl     loc_fc068af2\n"
"       add     r1, sp, #36\n"
"       mov     r0, r7\n"
"       bl      sub_FC10F180\n"
"       cbnz    r0, loc_fc068ae4\n"
"       movs    r0, #0\n"
"       movw    r2, #0x43a\n"
"       ldr     r1, =0xfc068c54\n" //  *"dwFWrite.c"
"       blx     sub_FC302434\n" // j_DebugAssert
" loc_fc068ae4:\n"
"       ldr     r0, [sp,#44]\n"
"       ldr     r1, [r4,#4]\n"
"       add     r0, r1\n"
"       str     r0, [sp,#44]\n"
" loc_fc068aec:\n"
"       ldr     r0, [r4,#0x50]\n"
"       lsls    r0, r0, #0x1f\n"
"       bne     loc_fc068afc\n"
" loc_fc068af2:\n"
"       ldr     r0, [r4,#0x50]\n"
"       lsls    r1, r0, #0x1e\n"
"       bmi     loc_fc068afc\n"
"       lsls    r0, r0, #0x1b\n"
"       bpl     loc_fc068b56\n"
" loc_fc068afc:\n"
"       add     r1, sp, #36\n"
"       mov     r0, r7\n"
"       bl      sub_FC10F1F6\n"
"       ldr     r0, [r4,#0x50]\n"
"       lsls    r1, r0, #0x1e\n"
"       bpl     loc_fc068b56\n"
"       lsls    r0, r0, #0x1a\n"
"       bpl     loc_fc068b56\n"
"       movs    r2, #0x20\n"
"       mov     r1, r7\n"
"       add     r0, sp, #4\n"
"       blx     sub_FC302414\n"
"       add     r0, sp, #4\n"
"       bl      sub_FC3803D2\n"
"       add     r2, sp, #4\n"
"       add     r0, r2\n"
"       movs    r1, #0x54\n"
"       strb.w  r1, [r0,#-3]!\n"
"       movs    r1, #0x4d\n"
"       strb    r1, [r0,#1]\n"
"       movs    r1, #0x50\n"
"       strb    r1, [r0,#2]\n"
"       add     r1, sp, #4\n"
"       mov     r0, r7\n"
"       bl      sub_fc0da5e6\n"
"       cbnz    r0, loc_fc068b46\n"
"       movs    r0, #0\n"
"       movw    r2, #0x1bd\n"
"       ldr     r1, =0xfc068c54\n" //*"dwFWrite.c" 
"       blx     sub_FC302434\n" // j_DebugAssert
" loc_fc068b46:\n"
"       add     r0, sp, #4\n"
"       b       loc_fc068b4c\n"
" loc_fc068b4a:\n"
"       b       loc_fc068b6c\n"
" loc_fc068b4c:\n"
"       bl      sub_FC10F4E8\n"
"       mov     r0, r7\n"
"       bl      sub_FC10F4E8\n"
" loc_fc068b56:\n"
"       movs    r1, #0\n"
"       movs    r0, #0x48\n"
"       bl      sub_FC35DEAC\n"
"       mov     r0, r7\n"
"       bl      sub_FC37A5DC\n"
"       ldr     r1, [r5,#0x20]\n"
"       bl      sub_fc06e2a0\n"
"       b       loc_fc068b70\n"
" loc_fc068b6c:\n"
"       ldr     r0, [r5,#32]\n"
"       blx     r0\n"
" loc_fc068b70:\n"
"       ldr     r0, [r5,#0x18]\n"
"       cmp     r0, #0\n"
"       beq     loc_fc068b84\n"
"       ldr     r1, [r4,#0x14]\n"
"       mov     r0, r4\n"
"       bl      sub_fc068850\n"
"       ldr     r1, [r5,#0x18]\n"
"       ldr     r0, [r4,#0x14]\n"
"       blx     r1\n"
" loc_fc068b84:\n"
"       add     sp, sp, #0x3c\n"
"    pop     {r4, r5, r6, r7, pc}\n"
".ltorg\n"
    );
}

