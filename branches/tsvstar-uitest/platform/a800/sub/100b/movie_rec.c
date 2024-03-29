#include "conf.h"

int *video_quality = &conf.video_quality;
int *video_mode    = &conf.video_mode;

// 0xFFEDB160 A800 1.00B
long def_table[24]={0x2000, 0x38D, 0x788, 0x5800, 0x9C5, 0x14B8, 0x10000, 0x1C6A, 0x3C45, 0x8000, 0xE35, 0x1E23,
           0x1CCD, -0x2E1, -0x579, 0x4F33, -0x7EB, -0xF0C, 0xE666, -0x170A, -0x2BC6, 0x7333, -0xB85, -0x15E3};

long table[24];

void change_video_tables(int a, int b){
 int i;
 for (i=0;i<24;i++) table[i]=(def_table[i]*a)/b; 
}

long CompressionRateTable[]={0x60, 0x5D, 0x5A, 0x57, 0x54, 0x51, 0x4D, 0x48, 0x42, 0x3B, 0x32, 0x29, 0x22, 0x1D, 0x17, 0x14, 0x10, 0xE, 0xB, 9, 7, 6, 5, 4, 3, 2, 1};

//FFD18384
void __attribute__((naked,noinline)) movie_record_task(){ 
asm volatile (
      "    STMFD   SP!, {R2-R8,LR} \n" 
      "    LDR     R4, =0x5680 \n" 
      "    LDR     R7, =0x37F \n" 
      "    LDR     R8, =0x2710 \n" 
      "    MOV     R5, #1 \n" 
      "    MOV     R6, #0 \n" 
"loc_FFD1839C:\n"
      "    LDR     R0, [R4, #0x18] \n" 
      "    MOV     R2, #0 \n" 
      "    ADD     R1, SP, #4 \n" 
      "    BL      sub_FFC2905C \n" 
      "    LDR     R0, [R4, #0x20] \n" 
      "    CMP     R0, #0 \n" 
      "    BNE     loc_FFD1846C \n" 
      "    LDR     R0, [SP, #4] \n" 
      "    LDR     R1, [R0] \n" 
      "    SUB     R1, R1, #2 \n" 
      "    CMP     R1, #0xA \n" 
      "    ADDCC   PC, PC, R1, LSL #2 \n" 
      "    B       loc_FFD1846C \n" 
      "    B       loc_FFD18420 \n" 
      "    B       loc_FFD18440 \n" 
      "    B       loc_FFD18450 \n" 
      "    B       loc_FFD18458 \n" 
      "    B       loc_FFD18428 \n" 
      "    B       loc_FFD18460 \n" 
      "    B       loc_FFD18430 \n" 
      "    B       loc_FFD1846C \n" 
      "    B       loc_FFD18468 \n" 
      "    B       loc_FFD183F8 \n" 
"loc_FFD183F8:\n"
      "    LDR     R0, =0xFFD18098 \n" 
      "    STR     R6, [R4, #0x34] \n" 
      "    STR     R0, [R4, #0xA8] \n" 
      "    LDR     R2, =0xFFD17A2C \n" 
      "    LDR     R1, =0x82B78 \n" 
      "    LDR     R0, =0xFFD17B10 \n" 
      "    STR     R6, [R4, #0x24] \n" 
      "    BL      sub_FFCBF254 \n" 
      "    STR     R5, [R4, #0x38] \n" 
      "    B       loc_FFD1846C \n" 
"loc_FFD18420:\n"
      "    BL      unlock_optical_zoom\n"		//------>
      "    BL      sub_FFD18190 \n" 
      "    B       loc_FFD1846C \n" 
"loc_FFD18428:\n"
      "    BL      sub_FFD17E98_my \n" 		//------------->
      "    B       loc_FFD1846C \n" 
"loc_FFD18430:\n"
      "    LDR     R1, [R0, #0x10] \n" 
      "    LDR     R0, [R0, #4] \n" 
      "    BL      sub_FFE11D78 \n" 
      "    B       loc_FFD1846C \n" 
"loc_FFD18440:\n"
      "    LDR     R0, [R4, #0x38] \n" 
      "    CMP     R0, #5 \n" 
      "    STRNE   R5, [R4, #0x28] \n" 
      "    B       loc_FFD1846C \n" 
"loc_FFD18450:\n"
      "    BL      sub_FFD17C98 \n" 
      "    B       loc_FFD1846C \n" 
"loc_FFD18458:\n"
      "    BL      sub_FFD17B5C \n" 
      "    B       loc_FFD1846C \n" 
"loc_FFD18460:\n"
      "    BL      sub_FFD179B8 \n" 
      "    B       loc_FFD1846C \n" 
"loc_FFD18468:\n"
      "    BL      sub_FFD1866C \n" 
"loc_FFD1846C:\n"
      "    LDR     R1, [SP, #4] \n" 
      "    LDR     R3, =0xFFD1790C \n" 
      "    STR     R6, [R1] \n" 
      "    STR     R7, [SP] \n" 
      "    LDR     R0, [R4, #0x1C] \n" 
      "    MOV     R2, R8 \n" 
      "    BL      sub_FFC0F6A8 \n" 
      "    B       loc_FFD1839C \n" 
	);
}			

void __attribute__((naked,noinline)) sub_FFD17E98_my(){ 
asm volatile (
      "    STMFD   SP!, {R4-R8,LR} \n" 
      "    SUB     SP, SP, #0x40 \n" 
      "    MOV     R6, #0 \n" 
      "    LDR     R5, =0x5680 \n" 
      "    MOV     R4, R0 \n" 
      "    STR     R6, [SP, #0x30] \n" 
      "    STR     R6, [SP, #0x28] \n" 
      "    LDR     R0, [R5, #0x38] \n" 
      "    MOV     R8, #4 \n" 
      "    CMP     R0, #3 \n" 
      "    STREQ   R8, [R5, #0x38] \n" 
      "    LDR     R0, [R5, #0xA8] \n" 
      "    BLX     R0 \n" 
      "    LDR     R0, [R5, #0x38] \n" 
      "    CMP     R0, #4 \n" 
      "    BNE     loc_FFD17F70 \n" 
      "    ADD     R3, SP, #0x28 \n" 
      "    ADD     R2, SP, #0x2C \n" 
      "    ADD     R1, SP, #0x30 \n" 
      "    ADD     R0, SP, #0x34 \n" 
      "    BL      sub_FFE11F0C \n" 
      "    CMP     R0, #0 \n" 
      "    MOV     R7, #1 \n" 
      "    BNE     loc_FFD17F14 \n" 
      "    LDR     R1, [R5, #0x28] \n" 
      "    CMP     R1, #1 \n" 
      "    BNE     loc_FFD17F78 \n" 
      "    LDR     R1, [R5, #0x60] \n" 
      "    LDR     R2, [R5, #0x3C] \n" 
      "    CMP     R1, R2 \n" 
      "    BCC     loc_FFD17F78 \n" 
"loc_FFD17F14:\n"
      "    CMP     R0, #0x80000001 \n" 
      "    STREQ   R8, [R5, #0x64] \n" 
      "    BEQ     loc_FFD17F4C \n" 
      "    CMP     R0, #0x80000003 \n" 
      "    STREQ   R7, [R5, #0x64] \n" 
      "    BEQ     loc_FFD17F4C \n" 
      "    CMP     R0, #0x80000005 \n" 
      "    MOVEQ   R0, #2 \n" 
      "    BEQ     loc_FFD17F48 \n" 
      "    CMP     R0, #0x80000007 \n" 
      "    STRNE   R6, [R5, #0x64] \n" 
      "    BNE     loc_FFD17F4C \n" 
      "    MOV     R0, #3 \n" 
"loc_FFD17F48:\n"
      "    STR     R0, [R5, #0x64] \n" 
"loc_FFD17F4C:\n"
      "    LDR     R0, =0x82BA4 \n" 
      "    LDR     R0, [R0, #8] \n" 
      "    CMP     R0, #0 \n" 
      "    BEQ     loc_FFD17F64 \n" 
      "    BL      sub_FFC44E9C \n" 
      "    B       loc_FFD17F68 \n" 
"loc_FFD17F64:\n"
      "    BL      sub_FFD179B8 \n" 
"loc_FFD17F68:\n"
      "    MOV     R0, #5 \n" 
      "    STR     R0, [R5, #0x38] \n" 
"loc_FFD17F70:\n"
      "    ADD     SP, SP, #0x40 \n" 
      "    LDMFD   SP!, {R4-R8,PC} \n" 
"loc_FFD17F78:\n"
      "    LDR     R12, [SP, #0x30] \n" 
      "    CMP     R12, #0 \n" 
      "    BEQ     loc_FFD18040 \n" 
      "    STR     R7, [R5, #0x2C] \n" 
      "    LDR     R0, [R5, #0x7C] \n" 
      "    LDR     R1, [R4, #0x14] \n" 
      "    LDR     R2, [R4, #0x18] \n" 
      "    LDR     R8, [R4, #0xC] \n" 
      "    ADD     R3, SP, #0x38 \n" 
      "    ADD     LR, SP, #0x14 \n" 
      "    STMIA   LR, {R0-R3} \n" 
      "    LDR     R3, [R5, #0x68] \n" 
      "    LDRD    R0, [SP, #0x28] \n" 
      "    ADD     R2, SP, #0x3C \n" 
      "    ADD     LR, SP, #8 \n" 
      "    STMIA   LR, {R0,R2,R3} \n" 
      "    STR     R1, [SP, #4] \n" 
      "    STR     R12, [SP] \n" 
      "    LDMIB   R4, {R0,R1} \n" 
      "    LDR     R3, [SP, #0x34] \n" 
      "    MOV     R2, R8 \n" 
      "    BL      sub_FFDE46FC \n" 
      "    LDR     R0, [R5, #0x10] \n" 
      "    LDR     R1, [R5, #0x58] \n" 
      "    BL      sub_FFC0F120 \n" 
      "    CMP     R0, #9 \n" 
      "    BNE     loc_FFD17FF4 \n" 
      "    BL      sub_FFE124C4 \n" 
      "    MOV     R0, #0x90000 \n" 
      "    STR     R7, [R5, #0x38] \n" 
      "    B       loc_FFD1800C \n" 
"loc_FFD17FF4:\n"
      "    LDR     R0, [SP, #0x38] \n" 
      "    CMP     R0, #0 \n" 
      "    BEQ     loc_FFD18014 \n" 
      "    BL      sub_FFE124C4 \n" 
      "    MOV     R0, #0xA0000 \n" 
      "    STR     R7, [R5, #0x38] \n" 
"loc_FFD1800C:\n"
      "    BL      sub_FFC70540 \n" 
      "    B       loc_FFD17F70 \n" 
"loc_FFD18014:\n"
      "    BL      sub_FFDE47B4 \n" 
      "    LDR     R0, [SP, #0x34] \n" 
      "    LDR     R1, [SP, #0x3C] \n" 
      "    BL      sub_FFE12284 \n" 
      "    LDR     R0, [R5, #0x5C] \n" 
      "    LDR     R1, =0x56FC \n" 
      "    ADD     R0, R0, #1 \n" 
      "    STR     R0, [R5, #0x5C] \n" 
      "    LDR     R0, [SP, #0x3C] \n" 
      "    MOV     R2, #0 \n" 
      "    BL      sub_FFE10134_my \n"  //----------> patched
"loc_FFD18040:\n"
      "    LDR     R0, [R5, #0x60] \n" 
      "    ADD     R0, R0, #1 \n" 
      "    STR     R0, [R5, #0x60] \n" 
      "    LDR     R1, [R5, #0x4C] \n" 
      "    MUL     R0, R1, R0 \n" 
      "    LDR     R1, [R5, #0x48] \n" 
      "    BL      sub_FFE99D7C \n" 
      "    MOV     R4, R0 \n" 
      "    BL      sub_FFE124FC \n" 
      "    LDR     R1, [R5, #0x80] \n" 
      "    CMP     R1, R4 \n" 
      "    BNE     loc_FFD1807C \n" 
      "    LDR     R0, [R5, #0x30] \n" 
      "    CMP     R0, #1 \n" 
      "    BNE     loc_FFD18090 \n" 
"loc_FFD1807C:\n"
      "    LDR     R1, [R5, #0x8C] \n" 
      "    MOV     R0, R4 \n" 
      "    BLX     R1 \n" 
      "    STR     R4, [R5, #0x80] \n" 
      "    STR     R6, [R5, #0x30] \n" 
"loc_FFD18090:\n"
      "    STR     R6, [R5, #0x2C] \n" 
      "    B       loc_FFD17F70 \n" 
	);
}

void __attribute__((naked,noinline)) sub_FFE10134_my(){ 
asm volatile (
      "    STMFD   SP!, {R4-R9,LR} \n" 
      "    LDR     R5, =0x9194 \n" 
      "    LDR     R4, [R5] \n" 
      "    LDR     R2, [R5, #8] \n" 
      "    CMP     R4, #0 \n" 
      "    LDRNE   R3, [R5, #0xC] \n" 
      "    MOV     R6, R2 \n" 
      "    CMPNE   R3, #1 \n" 
      "    MOVEQ   R2, #0 \n" 
      "    STREQ   R0, [R5] \n" 
      "    STREQ   R2, [R5, #0xC] \n" 
      "    BEQ     loc_FFE10200 \n" 
      "    LDR     R3, [R5, #4] \n" 
      "    LDR     R7, =0xFFEDB160 \n" 
      "    ADD     R12, R3, R3, LSL #1 \n" 
      "    LDR     R3, [R7, R12, LSL #2] \n" 
      "    ADD     R8, R7, #0x30 \n" 
      "    LDR     R9, [R8, R12, LSL #2] \n" 
      "    SUB     R3, R4, R3 \n" 
      "    CMP     R3, #0 \n" 
      "    SUB     R4, R4, R9 \n" 
      "    BLE     loc_FFE101BC \n" 
      "    ADD     R12, R7, R12, LSL #2 \n" 
      "    LDR     R4, [R12, #4] \n" 
      "    CMP     R4, R3 \n" 
      "    ADDGE   R2, R2, #1 \n" 
      "    BGE     loc_FFE101B0 \n" 
      "    LDR     R12, [R12, #8] \n" 
      "    CMP     R12, R3 \n" 
      "    ADDLT   R2, R2, #3 \n" 
      "    ADDGE   R2, R2, #2 \n" 
"loc_FFE101B0:\n"
   //-"    CMP     R2, #0x17 \n" 
   //-"    MOVGE   R2, #0x16 \n" 
      "    CMP     R2, #0x1A\n"   // +
      "    MOVGE   R2, #0x19\n"   // +	
      "    B       loc_FFE101F0 \n" 
"loc_FFE101BC:\n"
      "    CMP     R4, #0 \n" 
      "    BGE     loc_FFE101F0 \n" 
      "    ADD     R3, R8, R12, LSL #2 \n" 
      "    LDR     R12, [R3, #4] \n" 
      "    CMP     R12, R4 \n" 
      "    SUBLE   R2, R2, #1 \n" 
      "    BLE     loc_FFE101E8 \n" 
      "    LDR     R3, [R3, #8] \n" 
      "    CMP     R3, R4 \n" 
      "    SUBGT   R2, R2, #3 \n" 
      "    SUBLE   R2, R2, #2 \n" 
"loc_FFE101E8:\n"
      "    CMP     R2, #0 \n" 
      "    MOVLT   R2, #0 \n" 
"loc_FFE101F0:\n"
      "    CMP     R2, R6 \n" 
      "    STRNE   R2, [R5, #8] \n" 
      "    MOVNE   R2, #1 \n" 
      "    STRNE   R2, [R5, #0xC] \n" 
"loc_FFE10200:\n"
      "    LDR     R2, =CompressionRateTable \n" 
      "    LDR     R3, [R5, #8] \n" 

      "    LDR     R3, =video_mode\n"      // +
      "    LDR     R3, [R3]\n"             // +
      "    LDR     R3, [R3]\n"             // +
      "    CMP     R3, #1\n"               // +
      "    LDREQ   R3, =video_quality\n"   // +     
      "    LDREQ   R3, [R3]\n"             // +     
      "    LDREQ   R2, [R3]\n"             // +  	  
	  
      "    LDR     R2, [R2, R3, LSL #2] \n" 
      "    STR     R2, [R1] \n" 
      "    STR     R0, [R5] \n" 
      "    LDMFD   SP!, {R4-R9,PC} \n" 
	);
}	
