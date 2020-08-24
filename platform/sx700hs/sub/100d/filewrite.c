#include "lolevel.h"
#include "platform.h"

//#define FILEWRITE_DEBUG_LOG 1

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
    int maybe_seek_flag;      // 19 from sx700v100e sub_fc063eac 0x4C = 74 bytes,  74/4 = 19 words offset in fwt_data_struct
    int unkn5, unkn6;         // 20, 21
    char name[32];            // 22 from sx700hsv100e sub_fc063eac  0x58 = 88 bytes,  88/4 = 22 words offset in fwt_data_struct
} fwt_data_struct;

#include "../../../generic/filewrite.c"


#ifdef FILEWRITE_DEBUG_LOG
extern void _LogCameraEvent(int id,const char *fmt,...);
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
// sx700v100e   -f=chdk -s=task_FileWrite -c=73
// task_FileWrite 0xfc0640ad
void __attribute__((naked,noinline)) filewritetask() {
asm volatile (
"    push    {r2, r3, r4, r5, r6, lr}\n"
"    ldr     r5, =0x00021500\n"
"loc_fc0640b0:\n"
"    movs    r2, #0\n"
"    add     r1, sp, #4\n"
"    ldr     r0, [r5, #0x10]\n"
"    blx     sub_fc29b440\n" // j_ReceiveMessageQueue
"    cbz     r0, loc_fc0640c8\n"
"    movs    r0, #0\n"
"    movw    r2, #0x3f6\n"
"    ldr     r1, =0xfc064230\n" //  *"dwFWrite.c"
"    blx     sub_fc29b538\n" // j_DebugAssert
"loc_fc0640c8:\n"
"    ldr     r0, [sp, #4]\n"
"    ldr     r1, [r0]\n"
"    cmp     r1, #0xd\n"
"    bhs     loc_fc0640b0\n"
"    tbb     [pc, r1]\n" // (jumptable r1 13 elements)
"branchtable_fc0640d4:\n"
"    .byte((loc_fc06416e - branchtable_fc0640d4) / 2)\n" // (case 0)
"    .byte((loc_fc06416e - branchtable_fc0640d4) / 2)\n" // (case 1)
"    .byte((loc_fc06416e - branchtable_fc0640d4) / 2)\n" // (case 2)
"    .byte((loc_fc06416e - branchtable_fc0640d4) / 2)\n" // (case 3)
"    .byte((loc_fc06416e - branchtable_fc0640d4) / 2)\n" // (case 4)
"    .byte((loc_fc06416e - branchtable_fc0640d4) / 2)\n" // (case 5)
"    .byte((loc_fc06416e - branchtable_fc0640d4) / 2)\n" // (case 6)
"    .byte((loc_fc064174 - branchtable_fc0640d4) / 2)\n" // (case 7)
"    .byte((loc_fc0640e2 - branchtable_fc0640d4) / 2)\n" // (case 8)
"    .byte((loc_fc06410c - branchtable_fc0640d4) / 2)\n" // (case 9)
"    .byte((loc_fc06412c - branchtable_fc0640d4) / 2)\n" // (case 10)
"    .byte((loc_fc0640e8 - branchtable_fc0640d4) / 2)\n" // (case 11)
"    .byte((loc_fc064106 - branchtable_fc0640d4) / 2)\n" // (case 12)
".align 1\n"
"loc_fc0640e2:\n"   // case 8 -  calls close, not seen in normal shooting
"    bl      sub_fc0642d0\n"
"    b       loc_fc0640b0\n"
"loc_fc0640e8:\n"   // case 11 - create dir, TODO not patched
"    mov     r4, r0\n"
"    adds    r0, #0x58\n"
"    mov     r6, r0\n"
"    bl      sub_fc307d3a\n"
"    movs    r1, #0\n"
"    bl      sub_fc06c0c6\n"
"    ldr     r0, [r4, #0xc]\n"
"    bl      sub_fc0ba11e\n"
"    mov     r0, r6\n"
"    bl      sub_fc3083f2\n" // PrepareDirectory_0
"    b       loc_fc064156\n"
"loc_fc064106:\n"    // case 12 - patch for open, main hook
//"    bl      sub_fc063eac\n"
"    bl      sub_fc063eac_my\n"         // --->>
"    b       loc_fc0640b0\n"
"loc_fc06410c:\n"        // case 9 - not seen in normal shooting?
"    ldr     r1, [r0, #4]\n"
"    movs    r2, #0\n"
"    mov     r4, r0\n"
"    ldr     r0, [r5, #4]\n"
"    bl      _lseek\n"
"    adds    r0, r0, #1\n"
"    bne     loc_fc0640b0\n"
"    ldr     r0, =0x09200001\n"
"    mov     r1, r4\n"
"    adds    r0, #0x12\n"
"    str     r0, [r4, #0x10]\n"
"    movs    r0, #7\n"
"    bl      sub_fc063e38\n"
"    b       loc_fc0640b0\n"
"loc_fc06412c:\n"           // case 10 - cache flush, patch for ignore write
"    mov     r4, r0\n"
"    ldrsb.w r0, [r0, #0x58]\n"
"    cmp     r0, #0\n"
"    beq     loc_fc0640b0\n"
"    strb.w  r0, [sp]\n"
"    movs    r0, #0\n"
"    strb.w  r0, [sp, #1]\n"
"    add.w   r0, r4, #0x58\n"
"    mov     r6, r0\n"
"    bl      sub_fc307d3a\n"
"    movs    r1, #0\n"
"    bl      sub_fc06c0c6\n"
"    mov     r0, sp\n"
"    bl      sub_fc0ba12a\n"
"loc_fc064156:\n"
"    mov     r0, r6\n"
"    bl      sub_fc307d3a\n"
"    ldr     r1, [r5, #0x1c]\n"
"    bl      sub_fc06c124\n"
"    ldr     r1, [r5, #0x14]\n"
"    cmp     r1, #0\n"
"    beq     loc_fc0640b0\n"
"    ldr     r0, [r4, #0x10]\n"
"    blx     r1\n"
"    b       loc_fc0640b0\n"
"loc_fc06416e:\n"     // case 0-6  - write stage
//"    bl      sub_fc064314\n"
"    bl      sub_fc064314_my\n"          // --->>
"    b       loc_fc0640b0\n"
"loc_fc064174:\n"                // case 7 - close stage
//"    bl      sub_fc063fb6\n"
"    bl      sub_fc063fb6_my\n"            // --->>
"    b       loc_fc0640b0\n"
".ltorg\n"
    );
}


// message 12 - open
// sx700v100d -f=chdk -s=fc063ead -c=109
void __attribute__((naked,noinline)) sub_fc063eac_my() {
asm volatile (
"    push.w  {r4, r5, r6, r7, r8, sb, lr}\n"
"    mov     r4, r0\n"
                                    //hook placed here to avoid conditional branch a few instructions below (watch out for registers!)
//"  mov   r0, r4\n"                // data block start, commented out as R0 is already holding what we need
"    BL      filewrite_main_hook\n" //
"    mov     r0, r4\n"              // restore register(s)

"    ldr     r0, [r0, #0x4c]\n"     // offset of maybe_seek_flag in fwt_data_struct ?
"    sub     sp, #0x3c\n"
"    lsls    r0, r0, #0x1f\n"
"    beq     loc_fc063f92\n"
"    ldr     r7, =0x00021500\n"
"    ldr     r0, [r7, #0x18]\n"
"    cbz     r0, loc_fc063ec2\n"
"    blx     r0\n"
"loc_fc063ec2:\n"
"    add.w   r0, r4, #0x58\n"
"    mov     r8, r0\n"
"    bl      sub_fc307d3a\n"
"    movs    r1, #0\n"
"    bl      sub_fc06c0c6\n"
"    ldr     r0, [r4, #0xc]\n"
"    bl      sub_fc0ba11e\n"
"    ldr     r0, [r4, #0x4c]\n"
"    movw    r5, #0x301\n"
"    lsls    r1, r0, #0x1b\n"
"    bpl     loc_fc063ee6\n"
"    movs    r5, #9\n"
"    b       loc_fc063eec\n"
"loc_fc063ee6:\n"
"    lsls    r1, r0, #0x19\n"
"    bpl     loc_fc063eec\n"
"    movs    r5, #1\n"
"loc_fc063eec:\n"
"    lsls    r0, r0, #0x1a\n"
"    bmi     loc_fc063ef6\n"
"    ldr     r0, [r4, #0x54]\n"
"    cmp     r0, #1\n"
"    bne     loc_fc063efa\n"
"loc_fc063ef6:\n"
"    orr     r5, r5, #0x8000\n"
"loc_fc063efa:\n"
"    movw    sb, #0x1b6\n"
"    ldr     r6, [r4, #0xc]\n"
"    mov     r2, sb\n"
"    mov     r1, r5\n"
"    mov     r0, r8\n"
//"    bl      sub_fc30804e\n" // j_Open_FW
"    bl      fwt_open\n"   // +
"    adds    r1, r0, #1\n"
"    bne     loc_fc063f48\n"
"    mov     r0, r8\n"
"    bl      sub_fc3083f2\n" // PrepareDirectory_0
"    movs    r2, #0xf\n"
"    mov     r1, r8\n"
"    add     r0, sp, #4\n"
"    blx     sub_fc29b558\n"
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
"    bl      sub_fc0e7e4a\n"
"    mov     r2, sb\n"
"    mov     r1, r5\n"
"    mov     r0, r8\n"
//"    bl      sub_fc30804e\n" // j_Open_FW
"    bl      _Open\n" // j_Open_FW
"loc_fc063f48:\n"
"    mov     r5, r0\n"
"    str     r0, [r7, #4]\n"
"    adds    r0, r0, #1\n"
"    bne     loc_fc063f6c\n"
"    mov     r0, r8\n"
"    bl      sub_fc307d3a\n"
"    ldr     r1, [r7, #0x1c]\n"
"    bl      sub_fc06c124\n"
"    ldr     r1, [r7, #0x14]\n"
"    cmp     r1, #0\n"
"    beq     loc_fc063fb0\n"
"    add     sp, #0x3c\n"
"    ldr     r0, =0x09200001\n"
"    pop.w   {r4, r5, r6, r7, r8, sb, lr}\n"
"    bx      r1\n"
"loc_fc063f6c:\n"
"    ldr     r0, =0x001ba8d4\n"
"    movs    r2, #0x20\n"
"    mov     r1, r8\n"
"    blx     sub_fc29b560\n" // j_dry_memcpy
//mod start
"    LDR R3, =current_write_ignored\n"
"    LDR R3, [R3]\n"
"    cbnz r3,loc_C\n" // jump over the next block
//mod end
"    ldr     r0, [r4, #0x4c]\n"
"    lsls    r0, r0, #0x18\n"
"    bpl     loc_fc063f92\n"
"    ldr     r1, [r4, #8]\n"
"    mov     r0, r5\n"
"    bl      sub_fc308208\n"
"    cbnz    r0, loc_fc063f92\n"
"    ldr     r0, =0x09200001\n"
"    mov     r1, r4\n"
"    adds    r0, #0x16\n"
"    str     r0, [r4, #0x10]\n"
"    movs    r0, #7\n"
"    b       loc_fc063fa8\n"
"loc_fc063f92:\n"
"loc_C:\n"
"    ldr     r0, [r4, #0x4c]\n"
"    lsls    r0, r0, #0x19\n"
"    bmi     loc_fc063f9c\n"
"    ldr     r0, [r4, #4]\n"
"    cbz     r0, loc_fc063fa4\n"
"loc_fc063f9c:\n"
"    movs    r0, #9\n"
"    mov     r1, r4\n"
"    bl      sub_fc063e38\n"
"loc_fc063fa4:\n"
"    movs    r0, #0\n"
"    mov     r1, r4\n"
"loc_fc063fa8:\n"
"    add     sp, #0x3c\n"
"    pop.w   {r4, r5, r6, r7, r8, sb, lr}\n"
//"    b       loc_fc063e38\n"
"    ldr     pc,=0xfc063e39\n"
"loc_fc063fb0:\n"
"    add     sp, #0x3c\n"
"    pop.w   {r4, r5, r6, r7, r8, sb, pc}\n"
".ltorg\n"
    );
}


// message 0-6 - filewrite chunks
// sx700v100d  -s=0xfc064315 -c=64
void __attribute__((naked,noinline)) sub_fc064314_my() {
asm volatile (
"    push.w  {r4, r5, r6, r7, r8, sb, sl, lr}\n"
"    mov     r5, r0\n"
"    ldr     r0, [r0]\n"
"    cmp     r0, #6\n"
"    bhi     loc_fc06432c\n"
"    add.w   r0, r5, r0, lsl #3\n"
"    ldrd    r7, r6, [r0, #0x14]\n"
"    cbnz    r6, loc_fc064340\n"
"    b       loc_fc06433a\n"
"loc_fc06432c:\n"
"    movw    r2, #0x34b\n"
"    ldr     r1, =0xfc064230\n" //  *"dwFWrite.c"
"    movs    r0, #0\n"
"    blx     sub_fc29b538\n" // j_DebugAssert
"loc_fc06433a:\n"
"    movs    r0, #7\n"
"    mov     r1, r5\n"
"    b       loc_fc0643ae\n"
"loc_fc064340:\n"
"    ldr.w   sl, =0x00021500\n"
"    mov.w   sb, #0x1000000\n"
"    mov     r4, r6\n"
"loc_fc06434a:\n"
"    ldr     r0, [r5, #4]\n"
"    cmp     r4, sb\n"
"    mov     r1, sb\n"
"    bhi     loc_fc064354\n"
"    mov     r1, r4\n"
"loc_fc064354:\n"
"    lsls    r2, r0, #8\n"
"    beq     loc_fc064366\n"
"    bic     r0, r0, #0xff000000\n"
"    rsb.w   r0, r0, #0x1000000\n"
"    cmp     r1, r0\n"
"    bls     loc_fc064366\n"
"    mov     r1, r0\n"
"loc_fc064366:\n"
"    ldr.w   r0, [sl, #4]\n"
"    mov     r8, r1\n"
"    mov     r2, r1\n"
"    mov     r1, r7\n"
//"    bl      sub_fc3080f6\n" // j_Write_FW
"    bl      fwt_write\n" // +
"    ldr     r1, [r5, #4]\n"
"    cmp     r8, r0\n"
"    add     r1, r0\n"
"    str     r1, [r5, #4]\n"
"    beq     loc_fc06438e\n"
"    adds    r0, r0, #1\n"
"    bne     loc_fc064386\n"
"    ldr     r0, =0x09200005\n"
"    b       loc_fc06438a\n"
"loc_fc064386:\n"
"    ldr     r0, =0x09200005\n"
"    adds    r0, #0x10\n"
"loc_fc06438a:\n"
"    str     r0, [r5, #0x10]\n"
"    b       loc_fc06433a\n"
"loc_fc06438e:\n"
"    subs    r4, r4, r0\n"
"    cmp     r4, r6\n"
"    add     r7, r0\n"
"    blo     loc_fc0643a4\n"
"    movw    r2, #0x376\n"
"    ldr     r1, =0xfc064230\n" //  *"dwFWrite.c"
"    movs    r0, #0\n"
"    blx     sub_fc29b538\n" // j_DebugAssert
"loc_fc0643a4:\n"
"    cmp     r4, #0\n"
"    bne     loc_fc06434a\n"
"    ldr     r0, [r5]\n"
"    mov     r1, r5\n"
"    adds    r0, r0, #1\n"
"loc_fc0643ae:\n"
"    pop.w   {r4, r5, r6, r7, r8, sb, sl, lr}\n"
//"    b       loc_fc063e38\n"
"    ldr     pc,=0xfc063e39\n"
".ltorg\n"
    );
}

// message 7 - close
// sx700hsv100d   -f=chdk -s=0xfc063fb7 -c=104
void __attribute__((naked,noinline)) sub_fc063fb6_my() {
asm volatile (
"    push    {r4, r5, r6, lr}\n"
"    mov     r4, r0\n"
"    ldr     r0, [r0, #0x4c]\n"
"    ldr     r5, =0x00021500\n"
"    sub     sp, #0x38\n"
"    lsls    r0, r0, #0x1e\n"
"    bpl     loc_fc06409a\n"
"    ldr     r0, [r5, #4]\n"
"    adds    r1, r0, #1\n"
"    beq     loc_fc063fe8\n"
"    ldr     r6, =0x09200001\n"
"    ldr     r1, [r4, #0x54]\n"
"    adds    r6, r6, #2\n"
"    cmp     r1, #1\n"
"    bne     loc_fc063fda\n"
//mod start
"    LDR R3, =current_write_ignored\n"
"    LDR R3, [R3]\n"
"    cbnz R3,loc_D\n" // jump over the next block
//mod end
"    bl      sub_fc308052\n"
"    b       loc_fc063fde\n"
"loc_fc063fda:\n"
"loc_D:\n"
//"    bl      sub_fc308050\n" // j_Close_FW
"    bl      fwt_close\n" // +
"loc_fc063fde:\n"
"    cbz     r0, loc_fc063fe2\n"
"    str     r6, [r4, #0x10]\n"
"loc_fc063fe2:\n"
"    mov.w   r0, #-1\n"
"    str     r0, [r5, #4]\n"
"loc_fc063fe8:\n"
"    add.w   r6, r4, #0x58\n"
"    ldr     r0, [r4, #0x10]\n"
"    lsls    r0, r0, #0x1f\n"
"    bne     loc_fc06408c\n"
"    ldr     r0, [r4, #0x4c]\n"
"    lsls    r1, r0, #0x1f\n"
"    beq     loc_fc064014\n"
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
"    b       loc_fc064036\n"
"loc_fc064014:\n"
"    lsls    r0, r0, #0x1b\n"
"    bpl     loc_fc064036\n"
"    add     r1, sp, #0x20\n"
"    mov     r0, r6\n"
"    bl      sub_fc0e7dd4\n"
"    cbnz    r0, loc_fc06402e\n"
"    movs    r0, #0\n"
"    movw    r2, #0x3bd\n"
"    ldr     r1, =0xfc064230\n" //  *"dwFWrite.c"
"    blx     sub_fc29b538\n" // j_DebugAssert
"loc_fc06402e:\n"
"    ldr     r0, [sp, #0x28]\n"
"    ldr     r1, [r4, #4]\n"
"    add     r0, r1\n"
"    str     r0, [sp, #0x28]\n"
"loc_fc064036:\n"
"    ldr     r0, [r4, #0x4c]\n"
"    lsls    r0, r0, #0x19\n"
"    bmi     loc_fc064044\n"
"    add     r1, sp, #0x20\n"
"    mov     r0, r6\n"
"    bl      sub_fc0e7e4a\n"
"loc_fc064044:\n"
"    ldr     r0, [r4, #0x4c]\n"
"    lsls    r0, r0, #0x1a\n"
"    bpl     loc_fc06408c\n"
"    movs    r2, #0x20\n"
"    mov     r1, r6\n"
"    mov     r0, sp\n"
"    blx     sub_fc29b560\n" // j_dry_memcpy
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
"    bl      sub_fc0ba2f6\n"
"    cbnz    r0, loc_fc064080\n"
"    movs    r0, #0\n"
"    movw    r2, #0x167\n"
"    ldr     r1, =0xfc064230\n" //  *"dwFWrite.c"
"    blx     sub_fc29b538\n" // j_DebugAssert
"loc_fc064080:\n"
"    mov     r0, sp\n"
"    bl      sub_fc0e813c\n"
"    mov     r0, r6\n"
"    bl      sub_fc0e813c\n"
"loc_fc06408c:\n"
"    mov     r0, r6\n"
"    bl      sub_fc307d3a\n"
"    ldr     r1, [r5, #0x1c]\n"
"    bl      sub_fc06c124\n"
"    b       loc_fc06409e\n"
"loc_fc06409a:\n"
"    ldr     r0, [r5, #0x1c]\n"
"    blx     r0\n"
"loc_fc06409e:\n"
"    ldr     r1, [r5, #0x14]\n"
"    cmp     r1, #0\n"
"    beq     loc_fc0640a8\n"
"    ldr     r0, [r4, #0x10]\n"
"    blx     r1\n"
"loc_fc0640a8:\n"
"    add     sp, #0x38\n"
"    pop     {r4, r5, r6, pc}\n"
".ltorg\n"
    );
}
