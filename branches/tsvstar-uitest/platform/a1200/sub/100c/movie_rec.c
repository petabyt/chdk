#include "conf.h"

void change_video_tables(int a, int b) {}

void  set_quality(int *x) { // -17 highest; +12 lowest
    if (conf.video_mode)
        *x=12-((conf.video_quality-1)*(12+17)/(99-1));
}

void __attribute__((naked,noinline)) movie_record_task(  ) {
    // FF9645BC
asm volatile (
     "    STMFD   SP!, {R2-R10,LR} \n"
      "    LDR     R6, =0xFF963AEC \n"
//    "    LDR     R7, =0xFF963FE4 \n"
      "    LDR     R7, =sub_FF963FE4_my \n" // patched
      "    LDR     R4, =0x6570 \n"
      "    LDR     R9, =0x67F \n"
      "    LDR     R10, =0x2710 \n"
      "    MOV     R8, #1 \n"
      "    MOV     R5, #0 \n"
"loc_FF9645DC:\n"
      "    LDR     R0, [R4, #0x24] \n"
      "    MOV     R2, #0 \n"
      "    ADD     R1, SP, #4 \n"
      "    BL      sub_FF8397A4 \n"
      "    LDR     R0, [R4, #0x2C] \n"
      "    CMP     R0, #0 \n"
      "    LDRNE   R0, [R4, #0xC] \n"
      "    CMPNE   R0, #2 \n"
      "    LDRNE   R0, [R4, #0x44] \n"
      "    CMPNE   R0, #6 \n"
      "    BNE     loc_FF964700 \n"
      "    LDR     R0, [SP, #4] \n"
      "    LDR     R1, [R0] \n"
      "    SUB     R1, R1, #2 \n"
      "    CMP     R1, #0xB \n"
      "    ADDCC   PC, PC, R1, LSL #2 \n"
      "    B       loc_FF964700 \n"
      "    B       loc_FF9646B0 \n"
      "    B       loc_FF9646D4 \n"
      "    B       loc_FF9646E4 \n"
      "    B       loc_FF9646EC \n"
      "    B       loc_FF9646B8 \n"
      "    B       loc_FF9646F4 \n"
      "    B       loc_FF9646C4 \n"
      "    B       loc_FF964700 \n"
      "    B       loc_FF9646FC \n"
      "    B       loc_FF96467C \n"
      "    B       loc_FF96464C \n"
"loc_FF96464C:\n"
      "    STR     R5, [R4, #0x40] \n"
      "    STR     R5, [R4, #0x30] \n"
      "    STR     R5, [R4, #0x34] \n"
      "    STRH    R5, [R4, #6] \n"
      "    STR     R6, [R4, #0xB4] \n"
      "    STR     R7, [R4, #0xCC] \n"
      "    LDR     R0, [R4, #0xC] \n"
      "    ADD     R0, R0, #1 \n"
      "    STR     R0, [R4, #0xC] \n"
      "    MOV     R0, #6 \n"
      "    STR     R0, [R4, #0x44] \n"
      "    B       loc_FF96469C \n"
"loc_FF96467C:\n"
      "    STR     R5, [R4, #0x40] \n"
      "    STR     R5, [R4, #0x30] \n"
      "    STR     R6, [R4, #0xB4] \n"
      "    STR     R7, [R4, #0xCC] \n"
      "    LDR     R0, [R4, #0xC] \n"
      "    ADD     R0, R0, #1 \n"
      "    STR     R0, [R4, #0xC] \n"
      "    STR     R8, [R4, #0x44] \n"
"loc_FF96469C:\n"
      "    LDR     R2, =0xFF963308 \n"
      "    LDR     R1, =0xAC448 \n"
      "    LDR     R0, =0xFF96341C \n"
      "    BL      sub_FF852804 \n"
      "    B       loc_FF964700 \n"
"loc_FF9646B0:\n"
      "    BL      unlock_optical_zoom \n"      // added
      "    BL      sub_FF963C44 \n"
      "    B       loc_FF964700 \n"
"loc_FF9646B8:\n"
      "    LDR     R1, [R4, #0xCC] \n"
      "    BLX     R1 \n"
      "    B       loc_FF964700 \n"
"loc_FF9646C4:\n"
      "    LDR     R1, [R0, #0x18] \n"
      "    LDR     R0, [R0, #4] \n"
      "    BL      sub_FFAA7204 \n"         // 1.00c
      "    B       loc_FF964700 \n"
"loc_FF9646D4:\n"
      "    LDR     R0, [R4, #0x44] \n"
      "    CMP     R0, #5 \n"
      "    STRNE   R8, [R4, #0x34] \n"
      "    B       loc_FF964700 \n"
"loc_FF9646E4:\n"
      "    BL      sub_FF9637AC \n"
      "    B       loc_FF964700 \n"
"loc_FF9646EC:\n"
      "    BL      sub_FF963468 \n"
      "    B       loc_FF964700 \n"
"loc_FF9646F4:\n"
      "    BL      sub_FF963294 \n"
      "    B       loc_FF964700 \n"
"loc_FF9646FC:\n"
      "    BL      sub_FF964B40 \n"
"loc_FF964700:\n"
      "    LDR     R1, [SP, #4] \n"
      "    LDR     R3, =0xFF9630DC \n"
      "    STR     R5, [R1] \n"
      "    STR     R9, [SP] \n"
      "    LDR     R0, [R4, #0x28] \n"
      "    MOV     R2, R10 \n"
      "    BL      sub_FF83A11C \n"
      "    B       loc_FF9645DC \n"
    );
}

void __attribute__((naked,noinline)) sub_FF963FE4_my(  ) {
    // FF963FE4
asm volatile (
      "    STMFD   SP!, {R4-R11,LR} \n"
      "    SUB     SP, SP, #0x64 \n"
      "    MOV     R9, #0 \n"
      "    LDR     R6, =0x6570 \n"
      "    STR     R9, [SP, #0x54] \n"
      "    STR     R9, [SP, #0x4C] \n"
      "    STR     R9, [R6, #0xB8] \n"
      "    STR     R9, [R6, #0xBC] \n"
      "    STR     R9, [R6, #0xC0] \n"
      "    MOV     R4, R0 \n"
      "    STR     R9, [R6, #0xC4] \n"
      "    LDR     R0, [R6, #0x44] \n"
      "    MOV     R11, #4 \n"
      "    CMP     R0, #3 \n"
      "    STREQ   R11, [R6, #0x44] \n"
      "    LDR     R0, [R6, #0xB4] \n"
      "    MOV     R8, R9 \n"
      "    MOV     R5, #1 \n"
      "    MOV     R7, R9 \n"
      "    BLX     R0 \n"
      "    LDR     R0, [R6, #0x44] \n"
      "    CMP     R0, #6 \n"
      "    BEQ     loc_FF964054 \n"
      "    LDR     R1, [R6, #0xC] \n"
      "    CMP     R1, #2 \n"
      "    BNE     loc_FF96407C \n"
      "    CMP     R0, #5 \n"
      "    BEQ     loc_FF96408C \n"
"loc_FF964054:\n"
      "    LDR     R2, =0xFF963EB8 \n"
      "    LDR     R1, =0xFF963F1C \n"
      "    LDR     R0, =0xFF963F80 \n"
      "    MOV     R7, #1 \n"
      "    ADD     R3, SP, #0x34 \n"
      "    BL      sub_FF853624 \n"
      "    LDR     R0, [R6, #0x44] \n"
      "    CMP     R0, #4 \n"
      "    MOVNE   R5, #0 \n"
      "    B       loc_FF96409C \n"
"loc_FF96407C:\n"
      "    CMP     R0, #4 \n"
      "    BEQ     loc_FF96409C \n"
      "    CMP     R1, #2 \n"
      "    BNE     loc_FF964094 \n"
"loc_FF96408C:\n"
      "    MOV     R0, #0 \n"
      "    BL      sub_FF853630 \n"
"loc_FF964094:\n"
      "    ADD     SP, SP, #0x64 \n"
      "    LDMFD   SP!, {R4-R11,PC} \n"
"loc_FF96409C:\n"
      "    LDRH    R0, [R6, #6] \n"
      "    CMP     R0, #3 \n"
      "    BNE     loc_FF9640BC \n"
      "    LDR     R0, [R6, #0x6C] \n"
      "    LDR     R1, [R6, #0xC8] \n"
      "    BL      sub_FFB52AD0 \n"         // 1.00c
      "    CMP     R1, #0 \n"
      "    MOVNE   R5, #0 \n"
"loc_FF9640BC:\n"
      "    LDR     R0, [R6, #0x44] \n"
      "    CMP     R0, #6 \n"
      "    CMPNE   R0, #1 \n"
      "    CMPNE   R0, #3 \n"
      "    BNE     loc_FF964100 \n"
      "    CMP     R7, #1 \n"
      "    CMPEQ   R5, #0 \n"
      "    BNE     loc_FF964100 \n"
      "    BL      sub_FF853628 \n"
      "    LDR     R0, [R6, #0x18] \n"
      "    MOV     R1, #0x3E8 \n"
      "    BL      sub_FF839BC0 \n"
      "    CMP     R0, #9 \n"
      "    BNE     loc_FF964538 \n"
      "    MOV     R0, #0x90000 \n"
      "    BL      sub_FF88F0F4 \n"
      "    B       loc_FF964094 \n"
"loc_FF964100:\n"
      "    CMP     R5, #1 \n"
      "    MOV     R10, #1 \n"
      "    BNE     loc_FF964128 \n"
      "    ADD     R3, SP, #0x4C \n"
      "    ADD     R2, SP, #0x50 \n"
      "    ADD     R1, SP, #0x54 \n"
      "    ADD     R0, SP, #0x58 \n"
      "    BL      sub_FFAA72C4 \n"     // 1.00c
      "    MOVS    R9, R0 \n"
      "    BNE     loc_FF964144 \n"
"loc_FF964128:\n"
      "    LDR     R0, [R6, #0x34] \n"
      "    CMP     R0, #1 \n"
      "    BNE     loc_FF9642B4 \n"
      "    LDR     R0, [R6, #0x6C] \n"
      "    LDR     R1, [R6, #0x48] \n"
      "    CMP     R0, R1 \n"
      "    BCC     loc_FF9642B4 \n"
"loc_FF964144:\n"
      "    CMP     R9, #0x80000001 \n"
      "    STREQ   R11, [R6, #0x70] \n"
      "    BEQ     loc_FF96417C \n"
      "    CMP     R9, #0x80000003 \n"
      "    STREQ   R10, [R6, #0x70] \n"
      "    BEQ     loc_FF96417C \n"
      "    CMP     R9, #0x80000005 \n"
      "    MOVEQ   R0, #2 \n"
      "    BEQ     loc_FF964178 \n"
      "    CMP     R9, #0x80000007 \n"
      "    STRNE   R8, [R6, #0x70] \n"
      "    BNE     loc_FF96417C \n"
      "    MOV     R0, #3 \n"
"loc_FF964178:\n"
      "    STR     R0, [R6, #0x70] \n"
"loc_FF96417C:\n"
      "    LDR     R0, [R6, #0xC] \n"
      "    CMP     R0, #2 \n"
      "    BNE     loc_FF9641E4 \n"
      "    LDR     R0, =0xFF963EAC \n"
      "    MOV     R1, #0 \n"
      "    BL      sub_FFA63C28 \n"
      "    LDR     R2, [R6, #0x64] \n"
      "    ADD     R3, SP, #0x5C \n"
      "    STRD    R2, [SP, #0x28] \n"
      "    MOV     R2, #0x18 \n"
      "    ADD     R1, SP, #0x34 \n"
      "    ADD     R0, SP, #0x10 \n"
      "    BL      sub_FFB527B4 \n"     // 1.00c
      "    LDR     R1, [R6, #0x84] \n"
      "    LDR     R2, [R6, #0x88] \n"
      "    MVN     R3, #1 \n"
      "    ADD     R0, SP, #0x60 \n"
      "    STMEA   SP, {R0-R3} \n"
      "    MOV     R3, #0 \n"
      "    LDR     R0, =0xAC494 \n"
      "    MOV     R2, R3 \n"
      "    MOV     R1, #0x40 \n"
      "    BL      sub_FFA63B74 \n"
      "    B       loc_FF96423C \n"
"loc_FF9641DC:\n"
      "    MOV     R1, #1 \n"
      "    B       loc_FF9644C8 \n"
"loc_FF9641E4:\n"
      "    BL      sub_FF964C10 \n"
      "    LDR     R2, [R6, #0x64] \n"
      "    ADD     R3, SP, #0x5C \n"
      "    MVN     R1, #1 \n"
      "    MOV     R0, #0 \n"
      "    ADD     R5, SP, #0x1C \n"
      "    STMIA   R5, {R0-R3} \n"
      "    LDR     R3, [R4, #0x1C] \n"
      "    LDR     R1, [R6, #0x84] \n"
      "    LDR     R2, [R6, #0x88] \n"
      "    ADD     R0, SP, #0x60 \n"
      "    ADD     R4, SP, #0xC \n"
      "    STMIA   R4, {R0-R3} \n"
      "    MOV     R3, #0 \n"
      "    MOV     R1, #0x40 \n"
      "    STMEA   SP, {R1,R3} \n"
      "    MOV     R2, #0 \n"
      "    STR     R3, [SP, #8] \n"
      "    LDR     R3, =0xAC494 \n"
      "    MOV     R1, R2 \n"
      "    MOV     R0, R2 \n"
      "    BL      sub_FFA62880 \n"
"loc_FF96423C:\n"
      "    LDR     R0, [R6, #0x18] \n"
      "    LDR     R1, [R6, #0x60] \n"
      "    BL      sub_FF839BC0 \n"
      "    CMP     R0, #9 \n"
      "    BEQ     loc_FF9641DC \n"
      "    LDR     R0, [SP, #0x5C] \n"
      "    CMP     R0, #0 \n"
      "    BEQ     loc_FF964264 \n"
"loc_FF96425C:\n"
      "    MOV     R1, #1 \n"
      "    B       loc_FF9644E0 \n"
"loc_FF964264:\n"
      "    LDR     R0, [R6, #0xC] \n"
      "    MOV     R4, #5 \n"
      "    CMP     R0, #2 \n"
      "    MOV     R0, #1 \n"
      "    BNE     loc_FF9642A0 \n"
      "    BL      sub_FFA63BE8 \n"
      "    BL      sub_FFA63C10 \n"
      "    MOV     R0, #0 \n"
      "    BL      sub_FF853630 \n"
      "    BL      sub_FF853640 \n"
      "    STR     R4, [R6, #0x44] \n"
      "    BL      sub_FF964C10 \n"
      "    BL      sub_FF85369C \n"
      "    STR     R10, [R6, #0x44] \n"
      "    B       loc_FF9642AC \n"
"loc_FF9642A0:\n"
      "    BL      sub_FFA62930 \n"
      "    BL      sub_FFA6297C \n"
      "    STR     R4, [R6, #0x44] \n"
"loc_FF9642AC:\n"
      "    STR     R8, [R6, #0x34] \n"
      "    B       loc_FF964094 \n"
"loc_FF9642B4:\n"
      "    CMP     R5, #1 \n"
      "    BNE     loc_FF964530 \n"
      "    STR     R10, [R6, #0x38] \n"
      "    LDR     R0, [R6, #0x6C] \n"
      "    LDR     R11, [R4, #0xC] \n"
      "    CMP     R0, #0 \n"
      "    LDRNE   R9, [SP, #0x58] \n"
      "    LDRNE   R10, [SP, #0x54] \n"
      "    BNE     loc_FF964400 \n"
      "    LDR     R0, [R6, #0xC] \n"
      "    CMP     R0, #2 \n"
      "    BNE     loc_FF964358 \n"
      "    LDR     R0, =0xFF963EAC \n"
      "    MOV     R1, #0 \n"
      "    BL      sub_FFA63C28 \n"
      "    LDR     R2, [R6, #0x64] \n"
      "    ADD     R3, SP, #0x5C \n"
      "    STRD    R2, [SP, #0x28] \n"
      "    MOV     R2, #0x18 \n"
      "    ADD     R1, SP, #0x34 \n"
      "    ADD     R0, SP, #0x10 \n"
      "    BL      sub_FFB527B4 \n"         // 1.00c
      "    LDR     R1, [R6, #0x84] \n"
      "    LDR     R2, [R6, #0x88] \n"
      "    MVN     R3, #0 \n"
      "    ADD     R0, SP, #0x60 \n"
      "    STMEA   SP, {R0-R3} \n"
      "    LDR     R0, [SP, #0x58] \n"
      "    LDR     R1, [SP, #0x54] \n"
      "    LDR     R2, [SP, #0x50] \n"
      "    LDR     R3, [SP, #0x4C] \n"
      "    BL      sub_FFA63B74 \n"
      "    LDR     R0, [R6, #0x18] \n"
      "    LDR     R1, [R6, #0x60] \n"
      "    BL      sub_FF839BC0 \n"
      "    CMP     R0, #9 \n"
      "    BEQ     loc_FF9641DC \n"
      "    LDR     R0, =0xFF963BC8 \n"
      "    MOV     R1, #0 \n"
      "    BL      sub_FFA63C28 \n"
      "    B       loc_FF9643C0 \n"
"loc_FF964358:\n"
      "    LDR     R0, [R4, #0x20] \n"
      "    LDR     R2, [R6, #0x64] \n"
      "    ADD     R3, SP, #0x5C \n"
      "    MVN     R1, #0 \n"
      "    ADD     R9, SP, #0x1C \n"
      "    STMIA   R9, {R0-R3} \n"
      "    LDR     R3, [R4, #0x1C] \n"
      "    LDR     R1, [R6, #0x84] \n"
      "    LDR     R2, [R6, #0x88] \n"
      "    ADD     R0, SP, #0x60 \n"
      "    ADD     R9, SP, #0xC \n"
      "    STMIA   R9, {R0-R3} \n"
      "    LDR     R1, [SP, #0x50] \n"
      "    LDR     R2, [SP, #0x54] \n"
      "    LDR     R3, [SP, #0x4C] \n"
      "    STMFA   SP, {R1,R3} \n"
      "    STR     R2, [SP] \n"
      "    LDMIB   R4, {R0,R1} \n"
      "    LDR     R3, [SP, #0x58] \n"
      "    MOV     R2, R11 \n"
      "    BL      sub_FFA62880 \n"
      "    LDR     R0, [R6, #0x18] \n"
      "    LDR     R1, [R6, #0x60] \n"
      "    BL      sub_FF839BC0 \n"
      "    CMP     R0, #9 \n"
      "    BEQ     loc_FF9641DC \n"
"loc_FF9643C0:\n"
      "    LDR     R0, [SP, #0x5C] \n"
      "    CMP     R0, #0 \n"
      "    BNE     loc_FF96425C \n"
      "    LDR     R0, [R6, #0xC] \n"
      "    CMP     R0, #2 \n"
      "    MOV     R0, #1 \n"
      "    BNE     loc_FF9643E4 \n"
      "    BL      sub_FFA63BE8 \n"
      "    B       loc_FF9643E8 \n"
"loc_FF9643E4:\n"
      "    BL      sub_FFA62930 \n"
"loc_FF9643E8:\n"
      "    STR     R8, [R6, #0xC4] \n"
      "    LDR     R0, [SP, #0x60] \n"
      "    LDR     R1, [SP, #0x58] \n"
      "    ADD     R9, R1, R0 \n"
      "    LDR     R1, [SP, #0x54] \n"
      "    SUB     R10, R1, R0 \n"
"loc_FF964400:\n"
      "    LDR     R0, [R6, #0xC] \n"
      "    LDR     R2, [R6, #0x64] \n"
      "    CMP     R0, #2 \n"
      "    ADD     R3, SP, #0x5C \n"
      "    BNE     loc_FF964458 \n"
      "    STRD    R2, [SP, #0x28] \n"
      "    MOV     R2, #0x18 \n"
      "    ADD     R1, SP, #0x34 \n"
      "    ADD     R0, SP, #0x10 \n"
      "    BL      sub_FFB527B4 \n"         // 1.00c
      "    LDR     R1, [R6, #0x84] \n"
      "    LDR     R2, [R6, #0x88] \n"
      "    LDR     R3, [R6, #0x68] \n"
      "    ADD     R0, SP, #0x60 \n"
      "    STMEA   SP, {R0-R3} \n"
      "    LDR     R2, [SP, #0x50] \n"
      "    LDR     R3, [SP, #0x4C] \n"
      "    MOV     R1, R10 \n"
      "    MOV     R0, R9 \n"
      "    BL      sub_FFA63B74 \n"
      "    BL      sub_FF853628 \n"
      "    B       loc_FF9644B0 \n"
"loc_FF964458:\n"
      "    LDR     R1, [R6, #0x68] \n"
      "    LDR     R0, [R4, #0x20] \n"
      "    STR     R1, [SP, #0x20] \n"
      "    STR     R0, [SP, #0x1C] \n"
      "    STR     R2, [SP, #0x24] \n"
      "    STR     R3, [SP, #0x28] \n"
      "    LDR     R3, [R4, #0x1C] \n"
      "    LDR     R1, [R6, #0x84] \n"
      "    LDR     R2, [R6, #0x88] \n"
      "    ADD     R0, SP, #0x60 \n"
      "    STR     R2, [SP, #0x14] \n"
      "    LDR     R2, [SP, #0x50] \n"
      "    STR     R1, [SP, #0x10] \n"
      "    STR     R3, [SP, #0x18] \n"
      "    LDR     R3, [SP, #0x4C] \n"
      "    STR     R0, [SP, #0xC] \n"
      "    STMFA   SP, {R2,R3} \n"
      "    STR     R10, [SP] \n"
      "    LDMIB   R4, {R0,R1} \n"
      "    MOV     R3, R9 \n"
      "    MOV     R2, R11 \n"
      "    BL      sub_FFA62880 \n"
"loc_FF9644B0:\n"
      "    LDR     R0, [R6, #0x18] \n"
      "    LDR     R1, [R6, #0x60] \n"
      "    BL      sub_FF839BC0 \n"
      "    CMP     R0, #9 \n"
      "    BNE     loc_FF9644D0 \n"
      "    MOV     R1, #0 \n"
"loc_FF9644C8:\n"
      "    MOV     R0, #0x90000 \n"
      "    B       loc_FF9644E4 \n"
"loc_FF9644D0:\n"
      "    LDR     R0, [SP, #0x5C] \n"
      "    CMP     R0, #0 \n"
      "    BEQ     loc_FF9644EC \n"
      "    MOV     R1, #0 \n"
"loc_FF9644E0:\n"
      "    MOV     R0, #0xA0000 \n"
"loc_FF9644E4:\n"
      "    BL      sub_FF963E4C \n"
      "    B       loc_FF964094 \n"
"loc_FF9644EC:\n"
      "    LDR     R0, [R6, #0xC] \n"
      "    CMP     R0, #2 \n"
      "    MOV     R0, #0 \n"
      "    BNE     loc_FF964504 \n"
      "    BL      sub_FFA63BE8 \n"
      "    B       loc_FF964508 \n"
"loc_FF964504:\n"
      "    BL      sub_FFA62930 \n"
"loc_FF964508:\n"
      "    LDR     R0, [SP, #0x58] \n"
      "    LDR     R1, [SP, #0x60] \n"
      "    BL      sub_FFAA74E8 \n"         // 1.00c
      "    LDR     R0, [R6, #0x68] \n"
      "    LDR     R3, =0x65F8 \n"          // <- 65F8
      "    ADD     R1, R0, #1 \n"
      "    STR     R1, [R6, #0x68] \n"
      "    LDR     R0, [SP, #0x60] \n"
      "    SUB     R2, R3, #4 \n"           // <-  -4
      "    BL      sub_FFAA52BC \n"         // 1.00c
      "    LDR     R0, =0x65F4 \n"          // added, 65F8 - 4
      "    BL      set_quality \n"          // added
"loc_FF964530:\n"
      "    CMP     R7, #1 \n"
      "    BNE     loc_FF964544 \n"
"loc_FF964538:\n"
      "    BL      sub_FF85362C \n"
      "    MOV     R0, #1 \n"
      "    BL      sub_FF853630 \n"
"loc_FF964544:\n"
      "    CMP     R5, #1 \n"
      "    LDRNEH  R0, [R6, #6] \n"
      "    CMPNE   R0, #3 \n"
      "    BNE     loc_FF964094 \n"
      "    LDR     R0, [R6, #0x6C] \n"
      "    ADD     R0, R0, #1 \n"
      "    STR     R0, [R6, #0x6C] \n"
      "    LDRH    R1, [R6, #6] \n"
      "    CMP     R1, #3 \n"
      "    LDRNE   R1, [R6, #0x54] \n"
      "    LDREQ   R1, =0x3E9 \n"
      "    MUL     R0, R1, R0 \n"
      "    LDRNE   R1, [R6, #0x50] \n"
      "    LDREQ   R1, =0x1770 \n"
      "    BL      sub_FFB52AD0 \n"         // 1.00c
      "    MOV     R4, R0 \n"
      "    BL      sub_FFAA7870 \n"         // 1.00c
      "    LDR     R0, [R6, #0x8C] \n"
      "    CMP     R0, R4 \n"
      "    BNE     loc_FF9645A0 \n"
      "    LDR     R0, [R6, #0x3C] \n"
      "    CMP     R0, #1 \n"
      "    BNE     loc_FF9645B4 \n"
"loc_FF9645A0:\n"
      "    LDR     R1, [R6, #0x98] \n"
      "    MOV     R0, R4 \n"
      "    BLX     R1 \n"
      "    STR     R4, [R6, #0x8C] \n"
      "    STR     R8, [R6, #0x3C] \n"
"loc_FF9645B4:\n"
      "    STR     R8, [R6, #0x38] \n"
      "    B       loc_FF964094 \n"
    );
}
