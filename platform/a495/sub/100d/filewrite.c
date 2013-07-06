#include "lolevel.h"
#include "platform.h"

typedef struct {
    unsigned int address;
    unsigned int length;
} cam_ptp_data_chunk; //camera specific structure

#define MAX_CHUNKS_FOR_JPEG 4 // filewritetask is prepared for this many chunks
/*
 * fwt_data_struct: defined here as it's camera dependent
 * unneeded members are designated with unkn
 * file_offset, full_size, seek_flag only needs to be defined for DryOS>=r50 generation cameras
 * pdc is always required
 * name is not currently used
 */
typedef struct
{
    int unkn1, unkn2, unkn3, unkn4, unkn5;
    cam_ptp_data_chunk pdc[MAX_CHUNKS_FOR_JPEG];
	int unkn6;
    char name[32];
} fwt_data_struct;

#include "../../../generic/filewrite.c"

//** filewritetask  @ 0xFFDE66CC 

void __attribute__((naked,noinline)) filewritetask(  ) { 
asm volatile (
    "STMFD   SP!, {R1-R5,LR}\n"
    "LDR     R4, =0x8428\n"
"loc_FFDE66D4:\n"
    "LDR     R0, [R4, #0x10]\n"
    "MOV     R2, #0\n"
    "ADD     R1, SP, #8\n"
    "BL      sub_FFC28AA0\n"
    "CMP     R0, #0\n"
    "BNE     loc_FFDE6704\n"
    "LDR     R0, [SP, #8]\n"
    "LDR     R1, [R0]\n"
    "CMP     R1, #1\n"
    "BNE     loc_FFDE670C\n"
    "LDR     R0, [R4, #8]\n"
    "BL      _GiveSemaphore \n"
"loc_FFDE6704:\n"
    "BL      _ExitTask \n"
    "LDMFD   SP!, {R1-R5,PC}\n"
"loc_FFDE670C:\n"
    "SUB     R1, R1, #2\n"
    "CMP     R1, #6\n"
    "ADDLS   PC, PC, R1, LSL #2\n"
    "B       loc_FFDE66D4\n"
    "B       loc_FFDE6738\n" //(0)
    "B       loc_FFDE679C\n" //(1)
    "B       loc_FFDE67A4\n" //(2)
    "B       loc_FFDE67A4\n" //(3)
    "B       loc_FFDE67A4\n" //(4)
    "B       loc_FFDE67A4\n" //(5)
    "B       loc_FFDE67AC\n" //(6)
"loc_FFDE6738:\n"            //(state 0)
    "MOV     R0, #0\n"
    "STR     R0, [SP]\n"
"loc_FFDE6740:\n"
    "LDR     R0, [R4, #0x10]\n"
    "MOV     R1, SP\n"
    "BL      sub_FFC28CE4\n"
    "LDR     R0, [SP]\n"
    "CMP     R0, #0\n"
    "BEQ     loc_FFDE676C\n"
    "LDR     R0, [R4, #0x10]\n"
    "MOV     R2, #0\n"
    "ADD     R1, SP, #4\n"
    "BL      sub_FFC28AA0\n"
    "B       loc_FFDE6740\n"
"loc_FFDE676C:\n"
    "LDR     R0, [R4]\n"
    "CMN     R0, #1\n"
    "BEQ     loc_FFDE6790\n"
//    "BL      _Close \n"       //original
    "BL      fwt_close\n" 		//patch
    "MVN     R0, #0\n"
    "STR     R0, [R4]\n"
    "LDR     R0, =0xBF334\n"
    "BL      sub_FFC514AC\n"
    "BL      sub_FFC4F748\n"
"loc_FFDE6790:\n"
    "LDR     R0, [R4, #0xC]\n"
    "BL      _GiveSemaphore \n"
    "B       loc_FFDE66D4\n"
"loc_FFDE679C:\n"               //-> open (state 1)
//    "BL      sub_FFDE69BC\n"  //original
    "BL      sub_FFDE69BC_my\n" //patch
    "B       loc_FFDE66D4\n"
"loc_FFDE67A4:\n"			 	// -> write stage (states 2..5)
//    "BL      sub_FFDE6AF0\n"  //original
    "BL      sub_FFDE6AF0_my\n" //patch
    "B       loc_FFDE66D4\n"
"loc_FFDE67AC:\n"               // -> close stage (state 6)
//    "BL      sub_FFDE6558\n"  //original
    "BL      sub_FFDE6558_my\n" //patch
    "B       loc_FFDE66D4\n"
	);
}


//** sub_FFDE69BC_my  @ 0xFFDE69BC

void __attribute__((naked,noinline)) sub_FFDE69BC_my(  ) { //open
asm volatile (
    "STMFD   SP!, {R4-R8,LR}\n"
    "MOV     R4, R0\n"
    "ADD     R0, R0, #0x38\n"
    "SUB     SP, SP, #0x38\n"
    "BL      sub_FFC514AC\n"
    "MOV     R1, #0\n"
    "BL      sub_FFC4F6F8\n"
    "LDR     R0, [R4, #0xC]\n"
    "BL      sub_FFC4E55C\n"
    "LDR     R7, [R4, #8]\n"
    "LDR     R8, =0x1B6\n"
    "ADD     R6, R4, #0x38\n"
    "LDR     R5, [R4, #0xC]\n"
//hook start
      "STMFD SP!, {R4-R12,LR}\n"
      "MOV R0, R4\n"
      "BL filewrite_main_hook\n"
      "LDMFD SP!, {R4-R12,LR}\n"
//hook end
    "MOV     R0, R6\n"
    "MOV     R1, R7\n"
    "MOV     R2, R8\n"
//    "BL      _Open \n"        //original
	"BL      fwt_open\n"        //patch
    "LDR PC, =0xFFDE6A00\n"     //+ jump back to ROM
/*    "CMN     R0, #1\n"        //@sub_FFDE69BC+0x44
    "BNE     loc_FFDE6A60\n"
    "MOV     R0, R6\n"
    "BL      sub_FFC2649C\n"
    "MOV     R2, #0xF\n"
    "MOV     R1, R6\n"
    "MOV     R0, SP\n"
    "BL      sub_FFE80E10\n"
    "LDR     R0, =0x41FF\n"
    "MOV     R1, #0\n"
    "STRB    R1, [SP, #0xF]\n"
    "STR     R0, [SP, #0x20]\n"
    "MOV     R0, #0x10\n"
    "ADD     R2, SP, #0x24\n"
    "STMIA   R2, {R0,R1,R5}\n"
    "ADD     R1, SP, #0x20\n"
    "MOV     R0, SP\n"
    "STR     R5, [SP, #0x30]\n"
    "STR     R5, [SP, #0x34]\n"
    "BL      sub_FFC4F068\n"
    "MOV     R2, R8\n"
    "MOV     R1, R7\n"
    "MOV     R0, R6\n"
    "BL      _Open \n"
"loc_FFDE6A60:\n"
    "LDR     R5, =0x8428\n"
    "CMN     R0, #1\n"
    "STR     R0, [R5]\n"
    "BNE     loc_FFDE6AA8\n"
    "LDR     R0, [R5, #0x18]\n"
    "CMP     R0, #0\n"
    "BLXNE   R0\n"
    "ADD     R0, R4, #0x38\n"
    "BL      sub_FFC514AC\n"
    "BL      sub_FFC4F748\n"
    "LDR     R1, [R5, #0x14]\n"
    "CMP     R1, #0\n"
    "ADDNE   SP, SP, #0x38\n"
    "LDMNEFD SP!, {R4-R8,LR}\n"
    "LDRNE   R0, =0x9200001\n"
    "BXNE    R1\n"
"loc_FFDE6AA0:\n"
    "ADD     SP, SP, #0x38\n"
    "LDMFD   SP!, {R4-R8,PC}\n"
"loc_FFDE6AA8:\n"
    "LDR     R0, =0xBF334\n"
    "MOV     R2, #0x20\n"
    "ADD     R1, R4, #0x38\n"
    "BL      sub_FFE80F78\n"
    "MOV     R1, R4\n"
    "MOV     R0, #4\n"
    "BL      sub_FFDE6498\n"
    "B       loc_FFDE6AA0\n"*/
	);
}


//** sub_FFDE6AF0_my  @ 0xFFDE6AF0 

void __attribute__((naked,noinline)) sub_FFDE6AF0_my(  ) { //write
asm volatile (
    "STMFD   SP!, {R4-R10,LR}\n"
    "MOV     R4, R0\n"
    "LDR     R0, [R0]\n"
    "CMP     R0, #4\n"
    "LDREQ   R6, [R4, #0x18]\n"
    "LDREQ   R7, [R4, #0x14]\n"
    "BEQ     loc_FFDE6B3C\n"
    "CMP     R0, #5\n"
    "LDREQ   R6, [R4, #0x20]\n"
    "LDREQ   R7, [R4, #0x1C]\n"
    "BEQ     loc_FFDE6B3C\n"
    "CMP     R0, #6\n"
    "LDREQ   R6, [R4, #0x28]\n"
    "LDREQ   R7, [R4, #0x24]\n"
    "BEQ     loc_FFDE6B3C\n"
    "CMP     R0, #7\n"
    "BNE     loc_FFDE6B50\n"
    "LDR     R6, [R4, #0x30]\n"
    "LDR     R7, [R4, #0x2C]\n"
"loc_FFDE6B3C:\n"
    "CMP     R6, #0\n"
    "BNE     loc_FFDE6B60\n"
"loc_FFDE6B44:\n"
    "MOV     R1, R4\n"
    "MOV     R0, #8\n"
    "B       loc_FFDE6BF4\n"
"loc_FFDE6B50:\n"
    "LDR     R1, =0x29F\n"
    "LDR     R0, =0xFFDE67C4\n"
    "BL      _DebugAssert \n"
    "B       loc_FFDE6B44\n"
"loc_FFDE6B60:\n"
    "LDR     R9, =0x8428\n"
    "MOV     R5, R6\n"
"loc_FFDE6B68:\n"
    "LDR     R0, [R4, #4]\n"
    "CMP     R5, #0x1000000\n"
    "MOVLS   R8, R5\n"
    "MOVHI   R8, #0x1000000\n"
    "BIC     R1, R0, #0xFF000000\n"
    "CMP     R1, #0\n"
    "BICNE   R0, R0, #0xFF000000\n"
    "RSBNE   R0, R0, #0x1000000\n"
    "CMPNE   R8, R0\n"
    "MOVHI   R8, R0\n"
    "LDR     R0, [R9]\n"
    "MOV     R2, R8\n"
    "MOV     R1, R7\n"
//    "BL      _write \n"       //original
    "BL      fwt_write\n"       //patch
    "LDR     R1, [R4, #4]\n"
    "CMP     R8, R0\n"
    "ADD     R1, R1, R0\n"
    "STR     R1, [R4, #4]\n"
    "BEQ     loc_FFDE6BC8\n"
    "CMN     R0, #1\n"
    "LDRNE   R0, =0x9200015\n"
    "LDREQ   R0, =0x9200005\n"
    "STR     R0, [R4, #0x10]\n"
    "B       loc_FFDE6B44\n"
"loc_FFDE6BC8:\n"
    "SUB     R5, R5, R0\n"
    "CMP     R5, R6\n"
    "ADD     R7, R7, R0\n"
    "LDRCS   R0, =0xFFDE67C4\n"
    "LDRCS   R1, =0x2CA\n"
    "BLCS    _DebugAssert \n"
    "CMP     R5, #0\n"
    "BNE     loc_FFDE6B68\n"
    "LDR     R0, [R4]\n"
    "MOV     R1, R4\n"
    "ADD     R0, R0, #1\n"
"loc_FFDE6BF4:\n"
    "LDMFD   SP!, {R4-R10,LR}\n"
    "B       sub_FFDE6498\n"
	);
}


//** sub_FFDE6558_my  @ 0xFFDE6558

void __attribute__((naked,noinline)) sub_FFDE6558_my(  ) { 
asm volatile (
    "STMFD   SP!, {R4-R6,LR}\n"
    "LDR     R5, =0x8428\n"
    "MOV     R4, R0\n"
    "LDR     R0, [R5]\n"
    "SUB     SP, SP, #0x38\n"
    "CMN     R0, #1\n"
//    "BEQ     loc_FFDE65A0\n"  //original
    "LDREQ PC, =0xFFDE65A0\n"   //patch
    "LDR     R1, [R4, #8]\n"
    "LDR     R6, =0x9200003\n"
    "TST     R1, #0x8000\n"
    "BEQ     loc_FFDE658C\n"
    "BL      sub_FFC4E7A4\n"
    "B       loc_FFDE6590\n"
"loc_FFDE658C:\n"
//    "BL      _Close \n"       //original
    "BL      fwt_close\n"       //patch
"loc_FFDE6590:\n"
    "LDR PC, =0xFFDE6590\n"     //+ jump back to ROM
/*    "CMP     R0, #0\n"
    "MVN     R0, #0\n"
    "STRNE   R6, [R4, #0x10]\n"
    "STR     R0, [R5]\n"
"loc_FFDE65A0:\n"
    "LDR     R0, [R4, #0x10]\n"
    "TST     R0, #1\n"
    "BNE     loc_FFDE669C\n"
    "LDR     R0, [R4, #8]\n"
    "TST     R0, #8\n"
    "BEQ     loc_FFDE65E8\n"
    "ADD     R1, SP, #0x20\n"
    "ADD     R0, R4, #0x38\n"
    "BL      sub_FFC4EEB4\n"
    "CMP     R0, #0\n"
    "LDREQ   R1, =0x305\n"
    "LDREQ   R0, =0xFFDE67C4\n"
    "BLEQ    _DebugAssert \n"
    "LDR     R0, [SP, #0x28]\n"
    "LDR     R1, [R4, #4]\n"
    "ADD     R0, R0, R1\n"
    "STR     R0, [SP, #0x28]\n"
    "B       loc_FFDE6618\n"
"loc_FFDE65E8:\n"
    "LDR     R0, =0x81FF\n"
    "STR     R0, [SP, #0x20]\n"
    "MOV     R0, #0x20\n"
    "STR     R0, [SP, #0x24]\n"
    "LDR     R0, [R4, #4]\n"
    "STR     R0, [SP, #0x28]\n"
    "LDR     R0, [R4, #0xC]\n"
    "STR     R0, [SP, #0x2C]\n"
    "LDR     R0, [R4, #0xC]\n"
    "STR     R0, [SP, #0x30]\n"
    "LDR     R0, [R4, #0xC]\n"
    "STR     R0, [SP, #0x34]\n"
"loc_FFDE6618:\n"
    "LDR     R0, [R4, #0x34]\n"
    "CMP     R0, #2\n"
    "BEQ     loc_FFDE669C\n"
    "ADD     R1, SP, #0x20\n"
    "ADD     R0, R4, #0x38\n"
    "BL      sub_FFC4F068\n"
    "LDR     R0, [R4, #0x34]\n"
    "CMP     R0, #1\n"
    "BNE     loc_FFDE669C\n"
    "MOV     R2, #0x20\n"
    "ADD     R1, R4, #0x38\n"
    "MOV     R0, SP\n"
    "BL      sub_FFE80F78\n"
    "MOV     R0, SP\n"
    "BL      _strlen \n"
    "MOV     R2, #0x54\n"
    "ADD     R0, SP, R0\n"
    "MOV     R1, #0x4D\n"
    "STRB    R2, [R0, #-3]\n"
    "STRB    R1, [R0, #-2]\n"
    "MOV     R1, #0x50\n"
    "STRB    R1, [R0, #-1]\n"
    "MOV     R1, SP\n"
    "ADD     R0, R4, #0x38\n"
    "BL      sub_FFC4E7C4\n"
    "CMP     R0, #0\n"
    "LDREQ   R1, =0x159\n"
    "LDREQ   R0, =0xFFDE67C4\n"
    "BLEQ    _DebugAssert \n"
    "MOV     R0, SP\n"
    "BL      sub_FFC4F4C4\n"
    "ADD     R0, R4, #0x38\n"
    "BL      sub_FFC4F4C4\n"
"loc_FFDE669C:\n"
    "LDR     R0, [R5, #0x18]\n"
    "CMP     R0, #0\n"
    "BLXNE   R0\n"
    "ADD     R0, R4, #0x38\n"
    "BL      sub_FFC514AC\n"
    "BL      sub_FFC4F748\n"
    "LDR     R1, [R5, #0x14]\n"
    "CMP     R1, #0\n"
    "LDRNE   R0, [R4, #0x10]\n"
    "BLXNE   R1\n"
    "ADD     SP, SP, #0x38\n"
    "LDMFD   SP!, {R4-R6,PC}\n"*/
	);
}
