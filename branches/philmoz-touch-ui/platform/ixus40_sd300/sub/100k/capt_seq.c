#include "lolevel.h"
#include "platform.h"
#include "core.h"

#define NR_ON (2)
#define NR_OFF (1)
#define NR_AUTO (0)

static long *nrflag = (long*)0x5cdc;

#include "../../../generic/capt_seq.c"

/*
from debug strings:
[0x5cd8]: defect correct setting (0=according to table, 1=off, 2=normal, 3=long)
[0x5cdc]: darksub setting (0=according to table, 1=off, 2=on)
*/

void __attribute__((naked,noinline)) sub_FF941BA0_my(  ) {
asm volatile (
      "    STMFD   SP!, {R4,R5,LR} \n" 
      "    BL      sub_FF98A850 \n" 
      "    LDR     R5, =0x5B94 \n" 
      "    LDR     R3, =0x5B90 \n" 
      "    MOV     R2, #0x1C \n" 
      "    LDR     R1, [R3] \n" 
      "    MOV     R0, R5 \n" 
      "    BL      sub_FFABC2F8 \n" 
      "    BL      sub_FF82CF00 \n" 
      "    LDR     R4, =0x5BB0 \n" 
      "    MOV     R3, R0 \n" 
      "    LDR     R12, [R4] \n" 
      "    MOV     R2, #0x154 \n" 
      "    TST     R3, #1 \n" 
      "    LDR     R1, =0xFF941B94 \n" 
      "    ADD     R2, R2, #3 \n" 
      "    LDR     R0, =0xFF941B5C \n" 
      "    STR     R3, [R12, #4] \n" 
      "    BEQ     loc_FF941BF0 \n" 
      "    BL      sub_FF814C10 \n" 
"loc_FF941BF0:\n"
      "    BL      sub_FFA4872C \n" 
      "    LDR     R2, [R4] \n" 
      "    LDR     R3, =0x5B74 \n" 
      "    STRH    R0, [R2, #0x14] \n" 
      "    LDR     R1, [R3] \n" 
      "    LDRH    R0, [R1, #0x10] \n" 
      "    LDRSH   R1, [R2, #0x14] \n" 
      "    LDRSH   R2, [R5, #8] \n" 
"BL      capt_seq_hook_set_nr\n"        // +
      "    BL      sub_FF946310 \n" 
      "    LDR     R3, =0x5B70 \n" 
      "    LDR     R2, [R3] \n" 
      "    LDR     R1, [R2, #4] \n" 
      "    LDR     R2, =0x5B8C \n" 
      "    CMP     R1, #2 \n" 
      "    STR     R0, [R2] \n" 
      "    MOVEQ   R3, #0 \n" 
      "    STREQ   R3, [R2] \n" 
      "    LDMFD   SP!, {R4,R5,PC} \n" 
    );
}


void __attribute__((naked,noinline)) sub_FF9432B8_my(  ) {
asm volatile (
      "    STMFD   SP!, {R4-R6,LR} \n" 
      "    LDR     R3, =0x5B70 \n" 
      "    LDR     R2, [R3] \n" 
      "    CMP     R2, #0 \n" 
      "    BEQ     loc_FF9432FC \n" 
      "    LDR     R3, =0x5B90 \n" 
      "    LDR     R2, [R3] \n" 
      "    CMP     R2, #0 \n" 
      "    BEQ     loc_FF9432FC \n" 
      "    LDR     R3, =0x5B74 \n" 
      "    LDR     R2, [R3] \n" 
      "    CMP     R2, #0 \n" 
      "    BEQ     loc_FF9432FC \n" 
      "    LDR     R3, =0x5BB0 \n" 
      "    LDR     R2, [R3] \n" 
      "    CMP     R2, #0 \n" 
      "    BNE     loc_FF943310 \n" 
"loc_FF9432FC:\n"
      "    MOV     R2, #0x520 \n" 
      "    LDR     R0, =0xFF9431DC \n" 
      "    LDR     R1, =0xFF941B94 \n" 
      "    ADD     R2, R2, #2 \n" 
      "    BL      sub_FF814C10 \n" 
"loc_FF943310:\n"
      "    BL      sub_FF941A14 \n" 
      "    CMP     R0, #0 \n" 
      "    BNE     loc_FF94334C \n" 
      "    LDR     R3, =0x5B90 \n" 
      "    LDR     R2, [R3] \n" 
      "    LDR     R1, [R2, #4] \n" 
      "    CMP     R1, #0 \n" 
      "    BEQ     loc_FF94334C \n" 
      "    LDR     R0, =0xFF943264 \n" 
      "    BL      sub_FFAC03C4 \n" 
      "    LDR     R0, =0xFF943284 \n" 
      "    BL      sub_FFAC03C4 \n" 
      "    BL      sub_FF941A48 \n" 
      "    LDR     R0, =0xFF9432A8 \n" 
      "    BL      sub_FFAC03C4 \n" 
"loc_FF94334C:\n"
      "    LDR     R3, =0x6763C \n" 
      "    MVN     R4, #0 \n" 
      "    LDR     R0, [R3] \n" 
      "    MOV     R1, R4 \n" 
      "    BL      sub_FF821CB4 \n" 
      "    LDR     R3, =0x67640 \n" 
      "    MOV     R1, R4 \n" 
      "    LDR     R0, [R3] \n" 
      "    BL      sub_FF821CB4 \n" 
    //before take
    "BL      shooting_expo_param_override\n"  // +
      "    LDR     R3, =0x5B80 \n" 
      "    LDR     R3, [R3] \n" 
      "    CMP     R3, #1 \n" 
      "    CMPNE   R3, #3 \n" 
      "    BEQ     loc_FF9433C0 \n" 
      "    CMP     R3, #4 \n" 
      "    BEQ     loc_FF9433C0 \n" 
      "    LDR     R3, =0x5B74 \n" 
      "    LDR     R2, [R3] \n" 
      "    LDRH    R1, [R2, #2] \n" 
      "    CMP     R1, #1 \n" 
      "    BNE     loc_FF9433BC \n" 
      "    LDR     R3, =0x5BB0 \n" 
      "    LDR     R2, [R3] \n" 
      "    LDR     R1, [R2, #8] \n" 
      "    CMP     R1, #1 \n" 
      "    BLS     loc_FF9433BC \n" 
      "    BL      sub_FF942354 \n" 
      "    B       loc_FF9433C0 \n" 
"loc_FF9433BC:\n"
      "    BL      sub_FF942984 \n" 
"loc_FF9433C0:\n"
      "    BL      sub_FF942C6C \n" 
      "    MOV     R4, R0 \n" 
      "    TST     R4, #1 \n" 
      "    BEQ     loc_FF943404 \n" 
      "    LDR     R6, =0x5BC4 \n" 
      "    LDR     R2, [R6] \n" 
      "    CMP     R2, #0 \n" 
      "    BEQ     loc_FF9433F0 \n" 
      "    LDR     R3, =0x5BC8 \n" 
      "    LDR     R1, [R3] \n" 
      "    MOV     LR, PC \n" 
      "    MOV     PC, R2 \n" 
"loc_FF9433F0:\n"
      "    LDR     R5, =0x67638 \n" 
      "    MOV     R1, #2 \n" 
      "    LDR     R0, [R5] \n" 
      "    BL      sub_FF821B20 \n" 
      "    B       loc_FF94340C \n" 
"loc_FF943404:\n"
      "    LDR     R6, =0x5BC4 \n" 
      "    LDR     R5, =0x67638 \n" 
"loc_FF94340C:\n"
      "    BL      sub_FF941BA0_my \n"  // ->
      "    LDR     R3, =0x5BB4 \n" 
      "    LDR     R2, [R3] \n" 
      "    CMP     R2, #0 \n" 
      "    BEQ     loc_FF943434 \n" 
      "    LDR     R3, =0x5BB8 \n" 
      "    MOV     R0, R4 \n" 
      "    LDR     R1, [R3] \n" 
      "    MOV     LR, PC \n" 
      "    MOV     PC, R2 \n" 
"loc_FF943434:\n"
      "    BL      sub_FF942E68 \n" 
      "    BL      sub_FF942F54 \n" 
      "    BL      sub_FF942FFC \n" 
    "BL capt_seq_hook_raw_here\n"       // +
      "    LDR     R2, [R6] \n" 
      "    CMP     R2, #0 \n" 
      "    BEQ     loc_FF94345C \n" 
      "    LDR     R3, =0x5BC8 \n" 
      "    LDR     R1, [R3] \n" 
      "    MOV     LR, PC \n" 
      "    MOV     PC, R2 \n" 
"loc_FF94345C:\n"
      "    LDR     R0, [R5] \n" 
      "    MOV     R1, #2 \n" 
      "    LDMFD   SP!, {R4-R6,LR} \n" 
      "    B       sub_FF821B20 \n" 
    );
}


void __attribute__((naked,noinline)) capt_seq_task() //@ff944b48 in ixus40 100k
{//THE CODE USES STRANGE JUMP TABLE! (starts at 0x5bd0)
/* the table in ROM:
//ROM:FFADB9D0                 DCD loc_FF9427E8 //no idea
//ROM:FFADB9D4                 DCD sub_FF9432B8 //takes the snapshot
//ROM:FFADB9D8                 DCD sub_FF942A40 //also called after releasing half_press
//ROM:FFADB9DC                 DCD sub_FF9426DC //this is called after releasing shoot_half
//ROM:FFADB9E0                 DCD sub_FF943848 
//ROM:FFADB9E4                 DCD sub_FF943B90
//ROM:FFADB9E8                 DCD sub_FF943E2C
//ROM:FFADB9EC                 DCD sub_FF943FD0 //cancel movie capt seq
//ROM:FFADB9F0                 DCD sub_FF944210 
//ROM:FFADB9F4                 DCD sub_FF9443E0
//ROM:FFADB9F8                 DCD sub_FF9444E0
//ROM:FFADB9FC                 DCD sub_FF944564
//ROM:FFADBA00                 DCD sub_FF9447CC
//ROM:FFADBA04                 DCD sub_FF944880
*/
asm volatile (
      "    STMFD   SP!, {R4,R5,LR} \n" 
      "    SUB     SP, SP, #4 \n" 
//patching the jumptable
" LDR R4, =0x5bd0\n" //+
" LDR R5, =sub_FF9432B8_my\n" //+
" STR R5, [R4, #4]\n" //+
//patching finished
      "    MOV     R5, SP \n" 
      "    B       loc_FF944B78 \n" 
"loc_FF944B58:\n"
      "    LDR     R12, [SP] \n" 
      "    CMP     R12, #0xD \n" 
      "    BLS     loc_FF944B6C \n" 
      "    BL      sub_FF814C10 \n" 
      "    LDR     R12, [SP] \n" 
"loc_FF944B6C:\n"
" STMFD   SP!, {R0}\n" //+
" MOV R0, R12\n" //+
" BL set_shooting_status\n" //+ (shooting status hack)
" LDMFD   SP!, {R0}\n" //+
      "    LDR     R3, =0x5BD0 \n" 
      "    MOV     LR, PC \n" 
      "    LDR     PC, [R3, R12, LSL #2] \n" 
"loc_FF944B78:\n"
      "    LDR     R3, =0x67644 \n" 
      "    MOV     R12, #0 \n" 
      "    LDR     R4, =0x5B7C \n" 
      "    MOV     R2, R12 \n" 
      "    MOV     R1, R5 \n" 
      "    LDR     R0, [R3] \n" 
      "    STR     R12, [R4] \n" 
      "    BL      sub_FF822320 \n" 
      "    MOV     R2, #0x7B0 \n" 
      "    TST     R0, #1 \n" 
      "    LDR     R1, =0xFF941B94 \n" 
      "    ADD     R2, R2, #5 \n" 
      "    LDR     R0, =0xFF944B30 \n" 
      "    BEQ     loc_FF944B58 \n" 
      "    BL      sub_FF823B44 \n" 
      "    ADD     SP, SP, #4 \n" 
      "    LDMFD   SP!, {R4,R5,PC} \n" 
    );
}

/*************************************************************/
//** exp_drv_task @ 0xFF8F5CC0 - 0xFF8F5EEC, length=140
void __attribute__((naked,noinline)) exp_drv_task() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    SUB     SP, SP, #0xC \n"
"    MOV     R5, SP \n"
"    B       loc_FF8F5EA8 \n"

"loc_FF8F5CD0:\n"
"    CMP     R3, #0x11 \n"
"    BNE     loc_FF8F5CE8 \n"
"    LDR     R0, [R2, #0x2C] \n"
"    MOV     LR, PC \n"
"    LDR     PC, [R2, #0x28] \n"
"    B       loc_FF8F5D18 \n"

"loc_FF8F5CE8:\n"
"    CMP     R3, #0xF \n"
"    BNE     loc_FF8F5CF8 \n"
"    BL      sub_FFA58A6C \n"
"    B       loc_FF8F5D08 \n"

"loc_FF8F5CF8:\n"
"    CMP     R3, #0x10 \n"
"    BNE     loc_FF8F5D24 \n"
"    BL      sub_FF8A93BC \n"
"    BL      sub_FF8AB6E0 \n"

"loc_FF8F5D08:\n"
"    LDR     R3, [SP] \n"
"    LDR     R0, [R3, #0x2C] \n"
"    MOV     LR, PC \n"
"    LDR     PC, [R3, #0x28] \n"

"loc_FF8F5D18:\n"
"    LDR     R0, [SP] \n"
"    BL      sub_FF8F4B84 \n"
"    B       loc_FF8F5EA8 \n"

"loc_FF8F5D24:\n"
"    CMP     R3, #0xB \n"
"    MOV     R6, #1 \n"
"    BNE     loc_FF8F5D94 \n"
"    LDR     R1, [R2, #0x24] \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R4, SP, #4 \n"
"    ADD     R1, R2, R1, LSL#1 \n"
"    SUB     R1, R1, #2 \n"
"    MOV     R2, #6 \n"
"    MOV     R0, R4 \n"
"    BL      _memcpy \n"
"    LDR     R0, [SP] \n"
"    BL      sub_FF8F56B8 \n"
"    LDR     R3, [SP] \n"
"    LDR     R1, [R3, #0x24] \n"
"    LDR     R2, [R3, #0x2C] \n"
"    ADD     R0, R3, #4 \n"
"    MOV     LR, PC \n"
"    LDR     PC, [R3, #0x28] \n"
"    LDR     R0, [SP] \n"
"    BL      sub_FF8F5838 \n"
"    LDR     R3, [SP] \n"
"    ADD     R0, R3, #4 \n"
"    LDR     R1, [R3, #0x24] \n"
"    LDR     R2, [R3, #0x34] \n"
"    MOV     LR, PC \n"
"    LDR     PC, [R3, #0x30] \n"
"    B       loc_FF8F5E58 \n"

"loc_FF8F5D94:\n"
"    ADD     R4, SP, #4 \n"
"    ADD     R1, R2, #4 \n"
"    MOV     R0, R4 \n"
"    MOV     R2, #6 \n"
"    BL      _memcpy \n"
"    LDR     R12, [SP] \n"
"    LDR     R3, [R12] \n"
"    MOV     R1, R4 \n"
"    MOV     R0, R12 \n"
"    CMP     R3, #0xE \n"
"    LDRLS   PC, [PC, R3, LSL#2] \n"
"    B       loc_FF8F5E44 \n"
"    .long   loc_FF8F5E00 \n"
"    .long   loc_FF8F5E08 \n"
"    .long   loc_FF8F5E10 \n"
"    .long   loc_FF8F5E10 \n"
"    .long   loc_FF8F5E00 \n"
"    .long   loc_FF8F5E08 \n"
"    .long   loc_FF8F5E10 \n"
"    .long   loc_FF8F5E10 \n"
"    .long   loc_FF8F5E28 \n"
"    .long   loc_FF8F5E34 \n"
"    .long   loc_FF8F5E3C \n"
"    .long   loc_FF8F5E44 \n"
"    .long   loc_FF8F5E18 \n"
"    .long   loc_FF8F5E18 \n"
"    .long   loc_FF8F5E20 \n"

"loc_FF8F5E00:\n"
"    BL      sub_FF8F4F68 \n"
"    B       loc_FF8F5E40 \n"

"loc_FF8F5E08:\n"
"    BL      sub_FF8F50A0 \n"
"    B       loc_FF8F5E40 \n"

"loc_FF8F5E10:\n"
"    BL      sub_FF8F51CC \n"
"    B       loc_FF8F5E40 \n"

"loc_FF8F5E18:\n"
"    BL      sub_FF8F58B4 \n"
"    B       loc_FF8F5E40 \n"

"loc_FF8F5E20:\n"
"    BL      sub_FF8F539C \n"
"    B       loc_FF8F5E40 \n"

"loc_FF8F5E28:\n"
"    BL      sub_FF8F54A0_my \n"  // --> Patched. Old value = 0xFF8F54A0.
"    MOV     R6, #0 \n"
"    B       loc_FF8F5E40 \n"

"loc_FF8F5E34:\n"
"    BL      sub_FF8F5550 \n"
"    B       loc_FF8F5E40 \n"

"loc_FF8F5E3C:\n"
"    BL      sub_FF8F5638 \n"

"loc_FF8F5E40:\n"
"    LDR     R12, [SP] \n"

"loc_FF8F5E44:\n"
"    ADD     R0, R12, #4 \n"
"    LDR     R1, [R12, #0x24] \n"
"    LDR     R2, [R12, #0x2C] \n"
"    MOV     LR, PC \n"
"    LDR     PC, [R12, #0x28] \n"

"loc_FF8F5E58:\n"
"    CMP     R6, #1 \n"
"    BNE     loc_FF8F5E80 \n"
"    LDR     R1, [SP] \n"
"    LDR     R3, [R1, #0x24] \n"
"    ADD     R3, R3, R3, LSL#1 \n"
"    ADD     R1, R1, R3, LSL#1 \n"
"    MOV     R0, R4 \n"
"    SUB     R1, R1, #2 \n"
"    BL      sub_FF8F4EB8 \n"
"    B       loc_FF8F5EA0 \n"

"loc_FF8F5E80:\n"
"    MOV     R0, #1 \n"
"    MOV     R1, R0 \n"
"    MOV     R2, R0 \n"
"    BL      sub_FF8F4E5C \n"
"    MOV     R0, #1 \n"
"    MOV     R1, R0 \n"
"    MOV     R2, R0 \n"
"    BL      sub_FF8F4EEC \n"

"loc_FF8F5EA0:\n"
"    LDR     R0, [SP] \n"
"    BL      sub_FF8F4B84 \n"

"loc_FF8F5EA8:\n"
"    LDR     R3, =0x4BD10 \n"
"    MOV     R2, #0 \n"
"    LDR     R0, [R3] \n"
"    MOV     R1, R5 \n"
"    BL      sub_FF822320 /*_ReceiveMessageQueue*/ \n"
"    LDR     R2, [SP] \n"
"    LDR     R3, [R2] \n"
"    CMP     R3, #0x12 \n"
"    BNE     loc_FF8F5CD0 \n"
"    MOV     R0, R2 \n"
"    BL      sub_FF8F4B84 \n"
"    LDR     R3, =0x4BD0C \n"
"    MOV     R1, #1 \n"
"    LDR     R0, [R3] \n"
"    BL      sub_FF821B20 /*_SetEventFlag*/ \n"
"    BL      _ExitTask \n"
"    ADD     SP, SP, #0xC \n"
"    LDMFD   SP!, {R4-R6,PC} \n"
);
}

/*************************************************************/
//** sub_FF8F54A0_my @ 0xFF8F54A0 - 0xFF8F5540, length=41
void __attribute__((naked,noinline)) sub_FF8F54A0_my() {
asm volatile (
"    STMFD   SP!, {R4,R5,LR} \n"
"    LDR     R3, =0x4BD0C \n"
"    MOV     R4, R0 \n"
"    MOV     R1, #0xE \n"
"    LDR     R0, [R3] \n"
"    BL      sub_FF821CB4 /*_ClearEventFlag*/ \n"
"    MOV     R1, #0 \n"
"    LDRSH   R0, [R4, #4] \n"
"    BL      sub_FF8F4C08 \n"
"    MOV     R5, R0 \n"
"    LDRSH   R0, [R4, #6] \n"
"    BL      sub_FF8F4D38 \n"
"    LDRSH   R0, [R4, #8] \n"
"    BL      sub_FF8F4DD4 \n"
"    CMP     R5, #1 \n"
"    LDR     R1, =0xFF8F4BB4 \n"
"    MOV     R2, #2 \n"
"    BNE     loc_FF8F5500 \n"
"    LDRSH   R0, [R4, #4] \n"
"    BL      sub_FFA58750 \n"
"    LDR     R2, =0x4BD34 \n"
"    MOV     R3, #0 \n"
"    STR     R3, [R2] \n"
"    B       loc_FF8F5504 \n"

"loc_FF8F5500:\n"
"    BL      sub_FF8F4E2C \n"

"loc_FF8F5504:\n"
"    STRH    R0, [R4, #4] \n"
"    LDRSH   R0, [R4, #6] \n"
"    BL      sub_FF8A90B0_my \n"  // --> Patched. Old value = 0xFF8A90B0.
"    LDRSH   R0, [R4, #8] \n"
"    BL      sub_FF8AB084 \n"
"    MOV     R1, #0 \n"
"    ADD     R0, R4, #8 \n"
"    BL      sub_FF8AB1D0 \n"
"    CMP     R5, #1 \n"
"    MOV     R1, #2 \n"
"    MOV     R2, #0 \n"
"    LDMNEFD SP!, {R4,R5,PC} \n"
"    LDR     R3, =0x4BD0C \n"
"    LDR     R0, [R3] \n"
"    LDMFD   SP!, {R4,R5,LR} \n"
"    B       sub_FF821B10 /*_WaitForAllEventFlag*/ \n"
);
}

/*************************************************************/
//** sub_FF8A90B0_my @ 0xFF8A90B0 - 0xFF8A910C, length=24
void __attribute__((naked,noinline)) sub_FF8A90B0_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    LDR     R3, =0x3274 \n"
"    LDR     R12, [R3] \n"
"    MOV     R3, R0, LSL#16 \n"
"    CMP     R12, #1 \n"
"    LDR     R1, =0xFF8A8A9C \n"
"    MOV     R2, #0xF5 \n"
"    LDR     R0, =0xFF8A8CC0 \n"
"    MOV     R4, R3, ASR#16 \n"
"    BEQ     loc_FF8A90DC \n"
"    BL      _DebugAssert \n"

"loc_FF8A90DC:\n"
"    CMN     R4, #0xC00 \n"
"    LDR     R3, =0x2F256 \n"
"    LDR     R0, =0xFF8A8CCC \n"
"    LDR     R1, =0xFF8A8A9C \n"
"    MOV     R2, #0xFB \n"
"    LDREQSH R4, [R3] \n"
"    LDRNE   R3, =0x2F256 \n"
"    CMN     R4, #0xC00 \n"
"    STRH    R4, [R3] \n"
"    BNE     loc_FF8A9108 \n"
"    BL      _DebugAssert \n"

"loc_FF8A9108:\n"
"    MOV     R0, R4 \n"
"    BL      apex2us \n"  // --> Patched. Old value = _apex2us.
"    LDR     PC, =0xFF8A9110 \n"  // Continue in firmware
);
}
