/*
 * filewrite.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"

typedef struct {
    unsigned int address;
    unsigned int length;
} cam_ptp_data_chunk; //camera specific structure

#define MAX_CHUNKS_FOR_JPEG 7 // filewritetask is prepared for this many chunks
                              // Found in sub_FFABBB58 (1.00a) --> "CMP     R0, #6" and
                              // filewritetask() jump table has 7 calls to loc_FFABB944
/*
 * fwt_data_struct: defined here as it's camera dependent
 * unneeded members are designated with unkn
 * file_offset, full_size, seek_flag only needs to be defined for DryOS>=r50 generation cameras
 * pdc is always required
 * name is not currently used
 */
typedef struct
{
    int unkn1;
    int file_offset;
    int full_size;
    int unkn2, unkn3;
    cam_ptp_data_chunk pdc[MAX_CHUNKS_FOR_JPEG];
    int seek_flag;      // offset from start 0x4c = 76 bytes = 19 words
    int unkn4, unkn5;
    char name[32];      // offset from start 0x58 = 88 bytes = 22 words
} fwt_data_struct;
// seek_flag is different:
// seek state is activated (from state 0xc, open) when
// (word at 0x4c) AND 0x40
// OR
// write offset is not 0
#define FWT_MUSTSEEK    0x40   // value of the masked seek_flag indicating seek is required
#define FWT_SEEKMASK    0x40   // masks out unneeded bits of seek_flag

#include "../../../generic/filewrite.c"

/*************************************************************/
//** filewritetask @ 0xFFAB5B20 - 0xFFAB5CC4, length=106
void __attribute__((naked,noinline)) filewritetask() {
asm volatile (
"    STMFD   SP!, {R1-R7,LR} \n"
"    LDR     R5, =0xBA84 \n"
"    MOV     R6, #0 \n"

"loc_FFAB5B2C:\n"
"    LDR     R0, [R5, #0x10] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #8 \n"
"    BL      sub_003F84B8 \n"
"    CMP     R0, #0 \n"
"    LDRNE   R2, =0x3F5 \n"
"    LDRNE   R1, =0xFFAB5CEC /*'dwFWrite.c'*/ \n"
"    MOVNE   R0, #0 \n"
"    BLNE    _DebugAssert \n"
"    LDR     R0, [SP, #8] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0xD \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_FFAB5B2C \n"
"    B       loc_FFAB5CB8 \n"
"    B       loc_FFAB5CB8 \n"
"    B       loc_FFAB5CB8 \n"
"    B       loc_FFAB5CB8 \n"
"    B       loc_FFAB5CB8 \n"
"    B       loc_FFAB5CB8 \n"
"    B       loc_FFAB5CB8 \n"
"    B       loc_FFAB5CC0 \n"
"    B       loc_FFAB5B98 \n"
"    B       loc_FFAB5C34 \n"
"    B       loc_FFAB5C64 \n"
"    B       loc_FFAB5C00 \n"
"    B       loc_FFAB5C2C \n"

"loc_FFAB5B98:\n"
"    MOV     R4, R5 \n"
"    STR     R6, [SP] \n"

"loc_FFAB5BA0:\n"
"    LDR     R0, [R4, #0x10] \n"
"    MOV     R1, SP \n"
"    BL      sub_003F8710 \n"
"    LDR     R0, [SP] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FFAB5BCC \n"
"    LDR     R0, [R4, #0x10] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #4 \n"
"    BL      sub_003F84B8 \n"
"    B       loc_FFAB5BA0 \n"

"loc_FFAB5BCC:\n"
"    LDR     R0, [R4, #4] \n"
"    CMN     R0, #1 \n"
"    BEQ     fwt_close \n"  // --> Patched. Old value = 0xFFAB5BF4.
"    BL      _Close \n"
"    MVN     R0, #0 \n"
"    STR     R0, [R4, #4] \n"
"    LDR     R0, =0xF1EA8 \n"
"    BL      sub_FF820584 \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF81E400 \n"

"loc_FFAB5BF4:\n"
"    LDR     R0, [R4, #0xC] \n"
"    BL      _GiveSemaphore \n"
"    B       loc_FFAB5B2C \n"

"loc_FFAB5C00:\n"
"    MOV     R4, R0 \n"
"    ADD     R0, R0, #0x58 \n"
"    BL      sub_FF820584 \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF81E2C0 \n"
"    LDR     R0, [R4, #0xC] \n"
"    BL      sub_FF81D180 \n"
"    ADD     R0, R4, #0x58 \n"

//mod start
"    LDR R3, =ignore_current_write\n" // !!
"    LDR R3, [R3]\n"
"    CMP R3, #0\n"
"    BNE loc_A\n" // skip creating directory
//mod end
"    BL      sub_FF8178D0 \n"
"    ADD     R0, R4, #0x58 \n"
"    B       loc_FFAB5C98 \n"

"loc_FFAB5C2C:\n"
"    BL      sub_FFAB5800_my \n"  // --> Patched. Old value = 0xFFAB5800. Open stage
"    B       loc_FFAB5B2C \n"

"loc_FFAB5C34:\n"
"    LDR     R1, [R0, #4] \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R5, #4] \n"
"    MOV     R2, #0 \n"
"    BL      fwt_lseek \n"  // --> Patched. Old value = _lseek.
"    CMN     R0, #1 \n"
"    LDREQ   R0, =0x9200013 \n"
"    MOVEQ   R1, R4 \n"
"    STREQ   R0, [R4, #0x10] \n"
"    MOVEQ   R0, #7 \n"
"    BLEQ    sub_FFAB5740 \n"
"    B       loc_FFAB5B2C \n"

"loc_FFAB5C64:\n"
"    MOV     R4, R0 \n"
"    LDRSB   R0, [R0, #0x58] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FFAB5B2C \n"
"    STRB    R0, [SP, #4] \n"
"    ADD     R0, R4, #0x58 \n"
"    STRB    R6, [SP, #5] \n"
"    BL      sub_FF820584 \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF81E2C0 \n"

//mod start
"    LDR R3, =ignore_current_write\n" // !!
"    LDR R3, [R3]\n"
"    CMP R3, #0\n"
"    BNE loc_B\n" // skip flushing the cache
//mod end

"    ADD     R0, SP, #4 \n"
"    BL      sub_FF81D198 \n"
"loc_B:\n"
"    ADD     R0, R4, #0x58 \n"

"loc_FFAB5C98:\n"
"loc_A:\n"
"    BL      sub_FF820584 \n"
"    LDR     R1, [R5, #0x1C] \n"
"    BL      sub_FF81E400 \n"
"    LDR     R1, [R5, #0x14] \n"
"    CMP     R1, #0 \n"
"    LDRNE   R0, [R4, #0x10] \n"
"    BLXNE   R1 \n"
"    B       loc_FFAB5B2C \n"

"loc_FFAB5CB8:\n"
"    BL      sub_FFAB5EE0_my \n"  // --> Patched. Old value = 0xFFAB5EE0. Write stage
"    B       loc_FFAB5B2C \n"

"loc_FFAB5CC0:\n"
"    BL      sub_FFAB5998_my \n"  // --> Patched. Old value = 0xFFAB5998. Close stage
"    B       loc_FFAB5B2C \n"
);
}

/*************************************************************/
//** sub_FFAB5800_my @ 0xFFAB5800 - 0xFFAB5994, length=102
void __attribute__((naked,noinline)) sub_FFAB5800_my() {
asm volatile (
"    STMFD   SP!, {R4-R9,LR} \n"
"    MOV     R4, R0 \n"
//hook placed here to avoid conditional branch a few instructions below (watch out for registers!)
//"  MOV   R0, R4\n"      //data block start, commented out as R0 is already holding what we need
"    BL filewrite_main_hook\n"
"    MOV     R0, R4\n"      //restore register(s)
//hook end
"    LDR     R0, [R0, #0x4C] \n"
"    SUB     SP, SP, #0x3C \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FFAB5968 \n"
"    LDR     R7, =0xBA84 \n"
"    LDR     R0, [R7, #0x18] \n"
"    CMP     R0, #0 \n"
"    BLXNE   R0 \n"
"    ADD     R0, R4, #0x58 \n"
"    BL      sub_FF820584 \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF81E2C0 \n"
"    LDR     R0, [R4, #0xC] \n"
"    BL      sub_FF81D180 \n"
"    LDR     R0, [R4, #0x4C] \n"
"    LDR     R5, =0x301 \n"
"    TST     R0, #0x10 \n"
"    MOVNE   R5, #9 \n"
"    BNE     loc_FFAB585C \n"
"    TST     R0, #0x40 \n"
"    MOVNE   R5, #1 \n"

"loc_FFAB585C:\n"
"    TST     R0, #0x20 \n"
"    BNE     loc_FFAB5870 \n"
"    LDR     R0, [R4, #0x54] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FFAB5874 \n"

"loc_FFAB5870:\n"
"    ORR     R5, R5, #0x8000 \n"

"loc_FFAB5874:\n"
"    LDR     R9, =0x1B6 \n"
"    ADD     R8, R4, #0x58 \n"
"    LDR     R6, [R4, #0xC] \n"
"    MOV     R2, R9 \n"
"    MOV     R1, R5 \n"
"    MOV     R0, R8 \n"
"    BL      fwt_open \n"  // --> Patched. Old value = _Open.
"    CMN     R0, #1 \n"
"    BNE     loc_FFAB58F4 \n"
"    MOV     R0, R8 \n"
"    BL      sub_FF8178D0 \n"
"    MOV     R2, #0xF \n"
"    MOV     R1, R8 \n"
"    ADD     R0, SP, #4 \n"
"    BL      sub_003FC064 \n"
"    MOV     R0, #0 \n"
"    LDR     R1, =0x41FF \n"
"    STRB    R0, [SP, #0x13] \n"
"    STR     R1, [SP, #0x24] \n"
"    MOV     R1, #0x10 \n"
"    STR     R0, [SP, #0x2C] \n"
"    STR     R1, [SP, #0x28] \n"
"    ADD     R1, SP, #0x24 \n"
"    ADD     R0, SP, #4 \n"
"    STR     R6, [SP, #0x30] \n"
"    STR     R6, [SP, #0x34] \n"
"    STR     R6, [SP, #0x38] \n"
"    BL      sub_FF81DC24 \n"
"    MOV     R2, R9 \n"
"    MOV     R1, R5 \n"
"    MOV     R0, R8 \n"
"    BL      _Open \n"

"loc_FFAB58F4:\n"
"    CMN     R0, #1 \n"
"    MOV     R5, R0 \n"
"    STR     R0, [R7, #4] \n"
"    BNE     loc_FFAB5930 \n"
"    ADD     R0, R4, #0x58 \n"
"    BL      sub_FF820584 \n"
"    LDR     R1, [R7, #0x1C] \n"
"    BL      sub_FF81E400 \n"
"    LDR     R1, [R7, #0x14] \n"
"    CMP     R1, #0 \n"
"    BEQ     loc_FFAB5990 \n"
"    ADD     SP, SP, #0x3C \n"
"    LDMFD   SP!, {R4-R9,LR} \n"
"    LDR     R0, =0x9200001 \n"
"    BX      R1 \n"

"loc_FFAB5930:\n"
"    LDR     R0, =0xF1EA8 \n"
"    MOV     R2, #0x20 \n"
"    ADD     R1, R4, #0x58 \n"
"    BL      sub_003FC24C \n"

//mod start
"    LDR R3, =current_write_ignored\n"
"    LDR R3, [R3]\n"
"    CMP R3, #0\n"
"    BNE loc_C\n" // jump over the next block
//mod end

"    LDR     R0, [R4, #0x4C] \n"
"    TST     R0, #0x80 \n"
"    BEQ     loc_FFAB5968 \n"
"    LDR     R1, [R4, #8] \n"
"    MOV     R0, R5 \n"
"    BL      sub_FF8175A0 \n"
"    CMP     R0, #0 \n"
"    MOVEQ   R1, R4 \n"
"    MOVEQ   R0, #7 \n"
"    BEQ     loc_FFAB598C \n"

"loc_FFAB5968:\n"
"loc_C:\n"
"    LDR     R0, [R4, #0x4C] \n"
"    TST     R0, #0x40 \n"
"    LDREQ   R0, [R4, #4] \n"
"    CMPEQ   R0, #0 \n"
"    MOVNE   R1, R4 \n"
"    MOVNE   R0, #9 \n"
"    BLNE    sub_FFAB5740 \n"
"    MOV     R1, R4 \n"
"    MOV     R0, #0 \n"

"loc_FFAB598C:\n"
"    BL      sub_FFAB5740 \n"

"loc_FFAB5990:\n"
"    ADD     SP, SP, #0x3C \n"
"    LDMFD   SP!, {R4-R9,PC} \n"
);
}

/*************************************************************/
//** sub_FFAB5EE0_my @ 0xFFAB5EE0 - 0xFFAB5FC4, length=58
void __attribute__((naked,noinline)) sub_FFAB5EE0_my() {
asm volatile (
"    STMFD   SP!, {R4-R10,LR} \n"
"    MOV     R5, R0 \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #6 \n"
"    BHI     loc_FFAB5F0C \n"
"    ADD     R0, R5, R0, LSL#3 \n"
"    LDR     R8, [R0, #0x14]! \n"
"    LDR     R7, [R0, #4] \n"
"    CMP     R7, #0 \n"
"    BNE     loc_FFAB5F28 \n"
"    B       loc_FFAB5F1C \n"

"loc_FFAB5F0C:\n"
"    LDR     R2, =0x34A \n"
"    LDR     R1, =0xFFAB5CEC /*'dwFWrite.c'*/ \n"
"    MOV     R0, #0 \n"
"    BL      _DebugAssert \n"

"loc_FFAB5F1C:\n"
"    MOV     R1, R5 \n"
"    MOV     R0, #7 \n"
"    B       loc_FFAB5FC0 \n"

"loc_FFAB5F28:\n"
"    LDR     R9, =0xBA84 \n"
"    MOV     R4, R7 \n"

"loc_FFAB5F30:\n"
"    LDR     R0, [R5, #4] \n"
"    CMP     R4, #0x1000000 \n"
"    MOVLS   R6, R4 \n"
"    MOVHI   R6, #0x1000000 \n"
"    BIC     R1, R0, #0xFF000000 \n"
"    CMP     R1, #0 \n"
"    BICNE   R0, R0, #0xFF000000 \n"
"    RSBNE   R0, R0, #0x1000000 \n"
"    CMPNE   R6, R0 \n"
"    MOVHI   R6, R0 \n"
"    LDR     R0, [R9, #4] \n"
"    MOV     R2, R6 \n"
"    MOV     R1, R8 \n"
"    BL      fwt_write \n"  // --> Patched. Old value = _Write.
"    LDR     R1, [R5, #4] \n"
"    CMP     R6, R0 \n"
"    ADD     R1, R1, R0 \n"
"    STR     R1, [R5, #4] \n"
"    BEQ     loc_FFAB5F90 \n"
"    CMN     R0, #1 \n"
"    LDRNE   R0, =0x9200015 \n"
"    LDREQ   R0, =0x9200005 \n"
"    STR     R0, [R5, #0x10] \n"
"    B       loc_FFAB5F1C \n"

"loc_FFAB5F90:\n"
"    SUB     R4, R4, R0 \n"
"    CMP     R4, R7 \n"
"    LDRCS   R2, =0x375 \n"
"    ADD     R8, R8, R0 \n"
"    LDRCS   R1, =0xFFAB5CEC /*'dwFWrite.c'*/ \n"
"    MOVCS   R0, #0 \n"
"    BLCS    _DebugAssert \n"
"    CMP     R4, #0 \n"
"    BNE     loc_FFAB5F30 \n"
"    LDR     R0, [R5] \n"
"    MOV     R1, R5 \n"
"    ADD     R0, R0, #1 \n"

"loc_FFAB5FC0:\n"
"    LDMFD   SP!, {R4-R10,LR} \n"
"    B       sub_FFAB5740 \n"
"    .ltorg\n" //+
);
}

/*************************************************************/
//** sub_FFAB5998_my @ 0xFFAB5998 - 0xFFAB59D8, length=17
void __attribute__((naked,noinline)) sub_FFAB5998_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R0, #0x4C] \n"
"    LDR     R5, =0xBA84 \n"
"    TST     R0, #2 \n"
"    SUB     SP, SP, #0x38 \n"
"    BEQ     sub_FFAB5B00 \n"
"    LDR     R0, [R5, #4] \n"
"    CMN     R0, #1 \n"
"    BEQ     sub_FFAB59EC \n"
"    LDR     R1, [R4, #0x54] \n"
"    LDR     R6, =0x9200003 \n"
"    CMP     R1, #1 \n"
"    BNE     loc_FFAB59D8 \n"
//mod start
"    LDR R3, =current_write_ignored\n"
"    LDR R3, [R3]\n"
"    CMP R3, #0\n"
"    BNE loc_D\n" // jump over the next block
//mod end

"    BL      sub_FF8172F4 \n"
"    B       sub_FFAB59DC \n"

"loc_FFAB59D8:\n"
"loc_D:\n"
"    BL      fwt_close \n"  // --> Patched. Old value = _Close.
"    LDR     PC, =0xFFAB59DC \n"  // Continue in firmware
);
}
