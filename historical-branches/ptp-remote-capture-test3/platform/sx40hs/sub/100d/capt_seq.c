#include "lolevel.h"
#include "platform.h"
#include "core.h"

static long *nrflag = (long*)(0xC3F8+0x0);  // in sub_FF29E004 @ FF29E234 & FF29E2BC
#define NR_AUTO (0)							// have to explictly reset value back to 0 to enable auto
#define PAUSE_FOR_FILE_COUNTER 150          // Enable delay in capt_seq_hook_raw_here to ensure file counter is updated

#include "../../../generic/capt_seq.c"

//void __attribute__((naked,noinline)) hangdebug() {
//	debug_led(1);
//	while(1);
//}

// @ 0xff07c454 in firmware
void __attribute__((naked,noinline)) capt_seq_task() {

asm volatile (

	"STMFD SP!, {R3-R7,LR}\n"
	"LDR	R4, =0x3F64C\n"
	"LDR	R7, =0x30DC\n"
	"MOV	R6, #0\n"

"loc_FF07C464:\n"
	"LDR	R0, [R7,#4]\n"
	"MOV	R2, #0\n"
	"MOV	R1, SP\n"
	"BL		sub_FF02B0F4\n"
	"TST	R0, #1\n"
	"BEQ	loc_FF07C490\n"
	"LDR	R1, =0x491\n"
	"LDR	R0, =0xFF07BDA0\n"		//aSsshoottask_c
	"BL		_DebugAssert\n"
	"BL		_ExitTask\n"
	"LDMFD SP!, {R3-R7,PC}\n"

"loc_FF07C490:\n"
	"LDR	R0, [SP]\n"
	"LDR	R1, [R0]\n"
	"CMP	R1, #0x28\n"
	"ADDLS	PC, PC, R1,LSL#2\n"

	"B       loc_FF07C728\n"
	"B       loc_FF07C544\n"
	"B       loc_FF07C55C\n"
	"B       loc_FF07C568\n"
	"B       loc_FF07C588\n"
	"B       loc_FF07C580\n"
	"B       loc_FF07C594\n"
	"B       loc_FF07C59C\n"
	"B       loc_FF07C5A4\n"
	"B       loc_FF07C5C0\n"
	"B       loc_FF07C600\n"
	"B       loc_FF07C5CC\n"
	"B       loc_FF07C5D8\n"
	"B       loc_FF07C5E0\n"
	"B       loc_FF07C5E8\n"
	"B       loc_FF07C5F0\n"
	"B       loc_FF07C5F8\n"
	"B       loc_FF07C608\n"
	"B       loc_FF07C610\n"
	"B       loc_FF07C618\n"
	"B       loc_FF07C620\n"
	"B       loc_FF07C628\n"
	"B       loc_FF07C630\n"
	"B       loc_FF07C638\n"
	"B       loc_FF07C640\n"
	"B       loc_FF07C648\n"
	"B       loc_FF07C650\n"
	"B       loc_FF07C65C\n"
	"B       loc_FF07C664\n"
	"B       loc_FF07C670\n"
	"B       loc_FF07C678\n"
	"B       loc_FF07C6A8\n"
	"B       loc_FF07C6B0\n"
	"B       loc_FF07C6B8\n"
	"B       loc_FF07C6C0\n"
	"B       loc_FF07C6C8\n"
	"B       loc_FF07C6D0\n"
	"B       loc_FF07C6DC\n"
	"B       loc_FF07C6E4\n"
	"B       loc_FF07C6F0\n"
	"B       loc_FF07C734\n"

// jump table entry 0
"loc_FF07C544:\n"

"		BL	shooting_expo_iso_override\n"  		    // added

"		BL	sub_FF07CD58 \n"

"		BL	shooting_expo_param_override\n"  		// added

"		BL	sub_FF0795A0 \n"

"		MOV     R0, #0\n"							// added
"		STR     R0, [R4,#0x28]\n"					// added, fixes overrides  behavior at short shutter press (from S95)

//"		LDR	R0, [R4,#0x28] \n"						// above two lines make this code redundant
//"		CMP	R0, #0 \n"								// above two lines make this code redundant

//"		BLNE	sub_FF1D5788 \n"					// above two lines make this code redundant
//"		BLNE	sub_FF1D5788_my \n"					// patched (above two lines make this patch redundant)

"		B	loc_FF07C734 \n"

// jump table entry 1
"loc_FF07C55C: \n"

"       BL      wait_until_remote_button_is_released\n"	// +++
"       BL      capt_seq_hook_set_nr\n"           		// +++

"		LDR     R0, [R0,#0x10]\n"
//"       BL      sub_FF07C87C\n"
"		BL      sub_FF07C87C_my\n"                      // Patched

"		B	loc_FF07C734 \n"

// jump table entry 2
"loc_FF07C568: \n"
"		MOV	R0, #1 \n"
"		BL	sub_FF07D0B4 \n"
"		LDR	R0, [R4,#0xC]\n"
"		CMP	R0, #0\n"
"		BLNE	sub_FF07DF6C \n"
"		B	loc_FF07C734 \n"

// jump table entry 4
"loc_FF07C580: \n"
"		BL	sub_FF07C9C4 \n"
"		B	loc_FF07C58C \n"

// jump table entry 3
"loc_FF07C588: \n"
"		BL	sub_FF07CD38 \n"
"loc_FF07C58C: \n"
"		STR	R6, [R4,#0x28] \n"
"		B	loc_FF07C734 \n"

// jump table entry 5
"loc_FF07C594: \n"
"		BL	sub_FF07CD40 \n"
"		B	loc_FF07C734 \n"

// jump table entry 6
"loc_FF07C59C: \n"
"		BL	sub_FF07CF5C \n"
"		B	loc_FF07C5C4 \n"

// jump table entry 7
"loc_FF07C5A4: \n"
"		LDR	R5, [R0,#0x10] \n"
"       MOV R0, R5 \n"
"		BL	sub_FF1D5818 \n"
"       MOV R2, R5 \n"
"       MOV R1, #9 \n"
"		BL	sub_FF07A064 \n"
"		B	loc_FF07C734 \n"

// jump table entry 8
"loc_FF07C5C0: \n"
"		BL	sub_FF07D018 \n"
"loc_FF07C5C4: \n"
"		BL	sub_FF0795A0 \n"
"		B	loc_FF07C734 \n"

// jump table entry 10
"loc_FF07C5CC: \n"
"		LDR	R0, [R4,#0x58] \n"
"		BL	sub_FF07D9D0 \n"
"		B	loc_FF07C734 \n"

// jump table entry 11
"loc_FF07C5D8: \n"
"		BL	sub_FF07DCB4 \n"
"		B	loc_FF07C734 \n"

// jump table entry 12
"loc_FF07C5E0: \n"
"		BL	sub_FF07DD18 \n"
"		B	loc_FF07C734 \n"

// jump table entry 13
"loc_FF07C5E8: \n"
"		BL	sub_FF07E05C \n"
"		B	loc_FF07C734 \n"

// jump table entry 14
"loc_FF07C5F0: \n"
"		BL	sub_FF07E4AC \n"
"		B	loc_FF07C734 \n"

// jump table entry 15
"loc_FF07C5F8: \n"
"		BL	sub_FF07E55C \n"
"		B	loc_FF07C734 \n"

// jump table entry 9
"loc_FF07C600: \n"
"		BL	sub_FF07CD38 \n"
"		B	loc_FF07C734 \n"

// jump table entry 16
"loc_FF07C608: \n"
"		BL	sub_FF1D3364 \n"
"		B	loc_FF07C734 \n"

// jump table entry 17
"loc_FF07C610: \n"
"		BL	sub_FF1D3650 \n"
"		B	loc_FF07C734 \n"

// jump table entry 18
"loc_FF07C618: \n"
"		BL	sub_FF1D3704 \n"
"		B	loc_FF07C734 \n"

// jump table entry 19
"loc_FF07C620: \n"
"		BL	sub_FF1D37EC \n"
"		B	loc_FF07C734 \n"

// jump table entry 20
"loc_FF07C628: \n"
"		BL	sub_FF1D38C0 \n"
"		B	loc_FF07C734 \n"

// jump table entry 21
"loc_FF07C630: \n"
"		MOV	R0, #0 \n"
"		B	loc_FF07C654 \n"

// jump table entry 22
"loc_FF07C638: \n"
"		BL	sub_FF1D3EDC \n"
"		B	loc_FF07C734 \n"

// jump table entry 23
"loc_FF07C640: \n"
"		BL	sub_FF1D3F70 \n"
"		B	loc_FF07C734 \n"

// jump table entry 24
"loc_FF07C648: \n"
"		BL	sub_FF1D402C \n"
"		B	loc_FF07C734 \n"

// jump table entry 25
"loc_FF07C650: \n"
"		MOV	R0, #1 \n"
"loc_FF07C654: \n"
"		BL	sub_FF1D3D6C \n"
"		B	loc_FF07C734 \n"

// jump table entry 26
"loc_FF07C65C: \n"
"		BL	sub_FF07D324 \n"
"		B	loc_FF07C734 \n"

// jump table entry 27
"loc_FF07C664: \n"
"		BL	sub_FF07D3B8 \n"
"		BL	sub_FF1D6420 \n"
"		B	loc_FF07C734 \n"

// jump table entry 28
"loc_FF07C670: \n"
"		BL	sub_FF1D3BAC \n"
"		B	loc_FF07C734 \n"

// jump table entry 29
"loc_FF07C678: \n"
"		MOV     R2, #2 \n"
"		ADD     R1, R4, #0x6C \n"
"		MOV     R0, #0x6F \n"
"		BL      _GetPropertyCase \n"
"		TST     R0, #1 \n"
"		LDRNE   R1, =0x592 \n"
"		LDRNE   R0, =0xFF07BDA0 \n"	//=aSsshoottask_c
"		BLNE    _DebugAssert \n"
"		LDRH    R0, [R4,#0x6C] \n"
"		CMP     R0, #1 \n"
"		BLEQ    sub_FF1D3BA0 \n"
"		B	loc_FF07C734 \n"

// jump table entry 30
"loc_FF07C6A8: \n"
"		BL	sub_FF1D3CCC \n"
"		B	loc_FF07C734 \n"

// jump table entry 31
"loc_FF07C6B0: \n"
"		BL	sub_FF1D64EC \n"
"		B	loc_FF07C734 \n"

// jump table entry 32
"loc_FF07C6B8: \n"
"		BL	sub_FF028484 \n"
"		B	loc_FF07C734 \n"

// jump table entry 33
"loc_FF07C6C0: \n"
"		BL	sub_FF080CD8 \n"
"		B	loc_FF07C734 \n"

// jump table entry 34
"loc_FF07C6C8: \n"
"		BL	sub_FF080D60 \n"
"		B	loc_FF07C734 \n"

// jump table entry 35
"loc_FF07C6D0: \n"
"       LDR R0, [R0,#0xC] \n"
"		BL	sub_FF1D4154 \n"
"		B	loc_FF07C734 \n"

// jump table entry 36
"loc_FF07C6DC: \n"
"		BL	sub_FF1D41C4 \n"
"		B	loc_FF07C734 \n"

// jump table entry 37
"loc_FF07C6E4: \n"
"		BL	sub_FF080DC8 \n"
"		BL	sub_FF080D80 \n"
"		B	loc_FF07C734 \n"

// jump table entry 38
"loc_FF07C6F0: \n"
"		MOV	R0, #1 \n"
"		BL	sub_FF1D5F28 \n"
"		MOV	R0, #1 \n"
"		BL	sub_FF1D605C \n"
"		LDRH	R0, [R4,#0xA8] \n"
"		CMP	R0, #4 \n"
"		LDRNEH	R0, [R4] \n"
"		SUBNE	R1, R0, #0x4200 \n"
"		SUBNES	R1, R1, #0x2B \n"
"		BNE	loc_FF07C734 \n"
"		BL	sub_FF080D60 \n"
"		BL	sub_FF0814DC \n"
"		BL	sub_FF0811F0 \n"
"		B	loc_FF07C734 \n"

// jump table default entry
"loc_FF07C728: \n"
"		LDR	R1, =0x5F2 \n"
"		LDR	R0, =0xFF07BDA0 \n"				// "SsShootTask.c"
"		BL	_DebugAssert \n"

// jump table entry 39
"loc_FF07C734: \n"
"		LDR	R0, [SP] \n"
"		LDR	R1, [R0,#4] \n"
"		LDR	R0, [R7] \n"
"		BL	sub_FF088B4C \n"
"		LDR	R5, [SP] \n"
"		LDR	R0, [R5,#8] \n"
"		CMP	R0, #0 \n"
"		LDREQ	R1, =0x117 \n"
"		LDREQ	R0, =0xFF07BDA0 \n"			// "SsShootTask.c"
"		BLEQ	_DebugAssert \n"
"		STR	R6, [R5,#8] \n"
"		B	loc_FF07C464 \n"
	);
}

void __attribute__((naked,noinline)) sub_FF07C87C_my()
{
 asm volatile(
"                STMFD   SP!, {R4-R6,LR} \n"
"                LDR     R4, =0x3F64C \n"
"                MOV     R5, R0 \n"
"                LDR     R0, [R4,#0x28] \n"
"                CMP     R0, #0 \n"
"                BNE     loc_FF07C8D8 \n"
"                LDRH    R0, [R4] \n"
"                SUB     R1, R0, #0x8200 \n"
"                SUBS    R1, R1, #0x2F \n"
"                SUBNE   R1, R0, #0x4200 \n"
"                SUBNES  R1, R1, #0x2E \n"
"                BLEQ    sub_FF07F044 \n"
"                BL      sub_FF07EC88 \n"
"                MOV     R1, R5 \n"
"                BL      sub_FF07ECE0 \n"
"                LDR     R0, =0x10F \n"
"                MOV     R2, #4 \n"
"                ADD     R1, R5, #0x68 \n"
"                BL      sub_FF090EF4 \n"
"                MOV     R2, #4 \n"
"                ADD     R1, R5, #0x6C \n"
"                MOV     R0, #0x2C \n"
"                BL      sub_FF090EF4 \n"
"loc_FF07C8D8: \n"
"                MOV     R0, R5 \n"
"                BL      sub_FF1D5540 \n"

"       BL      capt_seq_hook_raw_here\n"           	// +++

"                MOV     R6, R0 \n"
"                MOV     R2, R5 \n"
"                MOV     R1, #1 \n"
"                BL      sub_FF07A064 \n"
"                TST     R6, #1 \n"
"                MOVEQ   R0, R5 \n"
"                BLEQ    sub_FF1D474C \n"
"                LDR     R0, [R4,#0xCC] \n"
"                CMP     R0, #2 \n"
"                LDMNEFD SP!, {R4-R6,PC} \n"
"                MOV     R0, R5 \n"
"                LDMFD   SP!, {R4-R6,LR} \n"
"                B       sub_FF07A448 \n"
 );
}

/*************************************************************/
// @ 0xff0cc408
void __attribute__((naked,noinline)) exp_drv_task(){

 asm volatile(
"                STMFD   SP!, {R4-R9,LR} \n"
"                SUB     SP, SP, #0x24 \n"
"                LDR     R6, =0x4BF0 \n"
"                LDR     R7, =0xBB8 \n"
"                LDR     R4, =0x5CDA0 \n"
"                MOV     R0, #0 \n"
"                ADD     R5, SP, #0x14 \n"
"                STR     R0, [SP,#0x10] \n"

"loc_FF0CC428: \n"
"                LDR     R0, [R6,#0x20] \n"
"                MOV     R2, #0 \n"
"                ADD     R1, SP, #0x20 \n"
"                BL      sub_FF02B0F4 \n"
"                LDR     R0, [SP,#0x10] \n"
"                CMP     R0, #1 \n"
"                BNE     loc_FF0CC474 \n"
"                LDR     R0, [SP,#0x20] \n"
"                LDR     R0, [R0] \n"
"                CMP     R0, #0x14 \n"
"                CMPNE   R0, #0x15 \n"
"                CMPNE   R0, #0x16 \n"
"                CMPNE   R0, #0x17 \n"
"                BEQ     loc_FF0CC5D4 \n"
"                CMP     R0, #0x29 \n"
"                BEQ     loc_FF0CC55C \n"
"                ADD     R1, SP, #0x10 \n"
"                MOV     R0, #0 \n"
"                BL      sub_FF0CC3B8 \n"

"loc_FF0CC474: \n"
"                LDR     R0, [SP,#0x20] \n"
"                LDR     R1, [R0] \n"
"                CMP     R1, #0x2F \n"
"                BNE     loc_FF0CC4A0 \n"
"                BL      sub_FF0CD83C \n"
"                LDR     R0, [R6,#0x1C] \n"
"                MOV     R1, #1 \n"
"                BL      sub_FF088B4C \n"
"                BL      _ExitTask \n"
"                ADD     SP, SP, #0x24 \n"
"                LDMFD   SP!, {R4-R9,PC} \n"

"loc_FF0CC4A0: \n"
"                CMP     R1, #0x2E \n"
"                BNE     loc_FF0CC4BC \n"
"                LDR     R2, [R0,#0x8C]! \n"
"                LDR     R1, [R0,#4] \n"
"                MOV     R0, R1 \n"
"                BLX     R2 \n"
"                B       loc_FF0CCA64 \n"

"loc_FF0CC4BC: \n"
"                CMP     R1, #0x27 \n"
"                BNE     loc_FF0CC50C \n"
"                LDR     R0, [R6,#0x1C] \n"
"                MOV     R1, #0x80 \n"
"                BL      sub_FF088B80 \n"
"                LDR     R0, =0xFF0C743C \n"
"                MOV     R1, #0x80 \n"
"                BL      sub_FF1BD7B4 \n"
"                LDR     R0, [R6,#0x1C] \n"
"                MOV     R2, R7 \n"
"                MOV     R1, #0x80 \n"
"                BL      sub_FF088A8C \n"
"                TST     R0, #1 \n"
"                LDRNE   R1, =0x14FE \n"
"                BNE     loc_FF0CC5C8 \n"

"loc_FF0CC4F8: \n"
"                LDR     R1, [SP,#0x20] \n"
"                LDR     R0, [R1,#0x90] \n"
"                LDR     R1, [R1,#0x8C] \n"
"                BLX     R1 \n"
"                B       loc_FF0CCA64 \n"

"loc_FF0CC50C: \n"
"                CMP     R1, #0x28 \n"
"                BNE     loc_FF0CC554 \n"
"                ADD     R1, SP, #0x10 \n"
"                BL      sub_FF0CC3B8 \n"
"                LDR     R0, [R6,#0x1C] \n"
"                MOV     R1, #0x100 \n"
"                BL      sub_FF088B80 \n"
"                LDR     R0, =0xFF0C744C \n"
"                MOV     R1, #0x100 \n"
"                BL      sub_FF1BE59C \n"
"                LDR     R0, [R6,#0x1C] \n"
"                MOV     R2, R7 \n"
"                MOV     R1, #0x100 \n"
"                BL      sub_FF088A8C \n"
"                TST     R0, #1 \n"
"                BEQ     loc_FF0CC4F8 \n"
"                LDR     R1, =0x1508 \n"
"                B       loc_FF0CC5C8 \n"

"loc_FF0CC554: \n"
"                CMP     R1, #0x29 \n"
"                BNE     loc_FF0CC56C \n"

"loc_FF0CC55C: \n"
"                LDR     R0, [SP,#0x20] \n"
"                ADD     R1, SP, #0x10 \n"
"                BL      sub_FF0CC3B8 \n"
"                B       loc_FF0CC4F8 \n"

"loc_FF0CC56C: \n"
"                CMP     R1, #0x2C \n"
"                BNE     loc_FF0CC584 \n"
"                BL      sub_FF0B7938 \n"
"                BL      sub_FF0B8624 \n"
"                BL      sub_FF0B8188 \n"
"                B       loc_FF0CC4F8 \n"

"loc_FF0CC584: \n"
"                CMP     R1, #0x2D \n"
"                BNE     loc_FF0CC5D4 \n"
"                LDR     R0, [R6,#0x1C] \n"
"                MOV     R1, #4 \n"
"                BL      sub_FF088B80 \n"
"                LDR     R1, =0xFF0C746C \n"
"                LDR     R0, =0xFFFFF400 \n"
"                MOV     R2, #4 \n"
"                BL      sub_FF0B7388 \n"
"                BL      sub_FF0B7618 \n"
"                LDR     R0, [R6,#0x1C] \n"
"                MOV     R2, R7 \n"
"                MOV     R1, #4 \n"
"                BL      sub_FF0889A8 \n"
"                TST     R0, #1 \n"
"                BEQ     loc_FF0CC4F8 \n"
"                LDR     R1, =0x1530 \n"

"loc_FF0CC5C8: \n"
"                LDR     R0, =0xFF0C7BFC \n"
"                BL      _DebugAssert \n"
"                B       loc_FF0CC4F8 \n"

"loc_FF0CC5D4: \n"
"                LDR     R0, [SP,#0x20] \n"
"                MOV     R8, #1 \n"
"                LDR     R1, [R0] \n"
"                CMP     R1, #0x12 \n"
"                CMPNE   R1, #0x13 \n"
"                BNE     loc_FF0CC63C \n"
"                LDR     R1, [R0,#0x7C] \n"
"                ADD     R1, R1, R1,LSL#1 \n"
"                ADD     R1, R0, R1,LSL#2 \n"
"                SUB     R1, R1, #8 \n"
"                LDMIA   R1, {R2,R3,R9} \n"
"                STMIA   R5, {R2,R3,R9} \n"
"                BL      sub_FF0CA634 \n"
"                LDR     R0, [SP,#0x20] \n"
"                LDR     R1, [R0,#0x7C] \n"
"                LDR     R3, [R0,#0x8C] \n"
"                LDR     R2, [R0,#0x90] \n"
"                ADD     R0, R0, #4 \n"
"                BLX     R3 \n"
"                LDR     R0, [SP,#0x20] \n"
"                BL      sub_FF0CDC48 \n"
"                LDR     R0, [SP,#0x20] \n"
"                LDR     R1, [R0,#0x7C] \n"
"                LDR     R2, [R0,#0x98] \n"
"                LDR     R3, [R0,#0x94] \n"
"                B       loc_FF0CC950 \n"

"loc_FF0CC63C: \n"
"                CMP     R1, #0x14 \n"
"                CMPNE   R1, #0x15 \n"
"                CMPNE   R1, #0x16 \n"
"                CMPNE   R1, #0x17 \n"
"                BNE     loc_FF0CC6F4 \n"
"                ADD     R3, SP, #0x10 \n"
"                ADD     R2, SP, #0x04 \n"
"                ADD     R1, SP, #0x14 \n"
"                BL      sub_FF0CA89C \n"
"                CMP     R0, #1 \n"
"                MOV     R9, R0 \n"
"                CMPNE   R9, #5 \n"
"                BNE     loc_FF0CC690 \n"
"                LDR     R0, [SP,#0x20] \n"
"                MOV     R2, R9 \n"
"                LDR     R1, [R0,#0x7C]! \n"
"                LDR     R12, [R0,#0x10]! \n"
"                LDR     R3, [R0,#4] \n"
"                ADD     R0, SP, #0x04 \n"
"                BLX     R12 \n"
"                B       loc_FF0CC6C8 \n"

"loc_FF0CC690: \n"
"                LDR     R0, [SP,#0x20] \n"
"                CMP     R9, #2 \n"
"                LDR     R3, [R0,#0x90] \n"
"                CMPNE   R9, #6 \n"
"                BNE     loc_FF0CC6DC \n"
"                LDR     R12, [R0,#0x8C] \n"
"                MOV     R2, R9 \n"
"                MOV     R1, #1 \n"
"                ADD     R0, SP, #0x04 \n"
"                BLX     R12 \n"
"                LDR     R0, [SP,#0x20] \n"
"                ADD     R2, SP, #0x04 \n"
"                ADD     R1, SP, #0x14 \n"
"                BL      sub_FF0CC104 \n"

"loc_FF0CC6C8: \n"
"                LDR     R0, [SP,#0x20] \n"
"                LDR     R2, [SP,#0x10] \n"
"                MOV     R1, R9 \n"
"                BL      sub_FF0CC358 \n"
"                B       loc_FF0CC958 \n"

"loc_FF0CC6DC: \n"
"                LDR     R1, [R0,#0x7C] \n"
"                LDR     R12, [R0,#0x8C] \n"
"                MOV     R2, R9 \n"
"                ADD     R0, R0, #4 \n"
"                BLX     R12 \n"
"                B       loc_FF0CC958 \n"

"loc_FF0CC6F4: \n"
"                CMP     R1, #0x23 \n"
"                CMPNE   R1, #0x24 \n"
"                BNE     loc_FF0CC740 \n"
"                LDR     R1, [R0,#0x7C] \n"
"                ADD     R1, R1, R1,LSL#1 \n"
"                ADD     R1, R0, R1,LSL#2 \n"
"                SUB     R1, R1, #8 \n"
"                LDMIA   R1, {R2,R3,R9} \n"
"                STMIA   R5, {R2,R3,R9} \n"
"                BL      sub_FF0C938C \n"
"                LDR     R0, [SP,#0x20] \n"
"                LDR     R1, [R0,#0x7C] \n"
"                LDR     R3, [R0,#0x8C] \n"
"                LDR     R2, [R0,#0x90] \n"
"                ADD     R0, R0, #4 \n"
"                BLX     R3 \n"
"                LDR     R0, [SP,#0x20] \n"
"                BL      sub_FF0C9880 \n"
"                B       loc_FF0CC958 \n"

"loc_FF0CC740: \n"
"                ADD     R1, R0, #4 \n"
"                LDMIA   R1, {R2,R3,R9} \n"
"                STMIA   R5, {R2,R3,R9} \n"
"                LDR     R1, [R0] \n"
"                CMP     R1, #0x27 \n"
"                ADDCC   PC, PC, R1,LSL#2 \n"
" B       loc_FF0CC940 \n"
" B       loc_FF0CC7F8 \n"
" B       loc_FF0CC7F8 \n"
" B       loc_FF0CC800 \n"
" B       loc_FF0CC808 \n"
" B       loc_FF0CC808 \n"
" B       loc_FF0CC808 \n"
" B       loc_FF0CC7F8 \n"
" B       loc_FF0CC800 \n"
" B       loc_FF0CC808 \n"
" B       loc_FF0CC808 \n"
" B       loc_FF0CC820 \n"
" B       loc_FF0CC820 \n"
" B       loc_FF0CC92C \n"
" B       loc_FF0CC934 \n"
" B       loc_FF0CC934 \n"
" B       loc_FF0CC934 \n"
" B       loc_FF0CC934 \n"
" B       loc_FF0CC93C \n"
" B       loc_FF0CC940 \n"
" B       loc_FF0CC940 \n"
" B       loc_FF0CC940 \n"
" B       loc_FF0CC940 \n"
" B       loc_FF0CC940 \n"
" B       loc_FF0CC940 \n"
" B       loc_FF0CC810 \n"
" B       loc_FF0CC818 \n"
" B       loc_FF0CC818 \n"
" B       loc_FF0CC82C \n"
" B       loc_FF0CC82C \n"
" B       loc_FF0CC834 \n"
" B       loc_FF0CC86C \n"
" B       loc_FF0CC8A4 \n"
" B       loc_FF0CC8DC \n"
" B       loc_FF0CC914 \n"
" B       loc_FF0CC914 \n"
" B       loc_FF0CC940 \n"
" B       loc_FF0CC940 \n"
" B       loc_FF0CC91C \n"
" B       loc_FF0CC924 \n"

"loc_FF0CC7F8: \n"
//"; jumptable FF0CC77C entries 0,1,6
"                BL      sub_FF0C7A30 \n"
"                B       loc_FF0CC940 \n"

"loc_FF0CC800: \n"
//"; jumptable FF0CC77C entries 2,7
"                BL      sub_FF0C7D28 \n"
"                B       loc_FF0CC940 \n"

"loc_FF0CC808: \n"
//"; jumptable FF0CC77C entries 3-5,8,9
"                BL      sub_FF0C7F90 \n"
"                B       loc_FF0CC940 \n"

"loc_FF0CC810: \n"
//"; jumptable FF0CC77C entry 24
"                BL      sub_FF0C8284 \n"
"                B       loc_FF0CC940 \n"

"loc_FF0CC818: \n"
//"; jumptable FF0CC77C entries 25,26
"                BL      sub_FF0C849C \n"
"                B       loc_FF0CC940 \n"

"loc_FF0CC820: \n"
//"; jumptable FF0CC77C entries 10,11
//"                BL      sub_FF0C8958 \n"
"                BL      sub_FF0C8958_my \n"  // patched
"                MOV     R8, #0 \n"
"                B       loc_FF0CC940 \n"

"loc_FF0CC82C: \n"
//"; jumptable FF0CC77C entries 27,28
"                BL      sub_FF0C8B3C \n"
"                B       loc_FF0CC940 \n"

"loc_FF0CC834: \n"
//"; jumptable FF0CC77C entry 29
"                LDRH    R1, [R0,#4] \n"
"                STRH    R1, [SP,#0x14] \n"
"                LDRH    R1, [R4,#2] \n"
"                STRH    R1, [SP,#0x16] \n"
"                LDRH    R1, [R4,#4] \n"
"                STRH    R1, [SP,#0x18] \n"
"                LDRH    R1, [R4,#6] \n"
"                STRH    R1, [SP,#0x1A] \n"
"                LDRH    R1, [R0,#0xC] \n"
"                STRH    R1, [SP,#0x1C] \n"
"                LDRH    R1, [R4,#0xA] \n"
"                STRH    R1, [SP,#0x1E] \n"
"                BL      sub_FF0CD8D0 \n"
"                B       loc_FF0CC940 \n"

"loc_FF0CC86C: \n"
//"; jumptable FF0CC77C entry 30
"                LDRH    R1, [R0,#4] \n"
"                STRH    R1, [SP,#0x14] \n"
"                LDRH    R1, [R4,#2] \n"
"                STRH    R1, [SP,#0x16] \n"
"                LDRH    R1, [R4,#4] \n"
"                STRH    R1, [SP,#0x18] \n"
"                LDRH    R1, [R4,#6] \n"
"                STRH    R1, [SP,#0x1A] \n"
"                LDRH    R1, [R4,#8] \n"
"                STRH    R1, [SP,#0x1C] \n"
"                LDRH    R1, [R4,#0xA] \n"
"                STRH    R1, [SP,#0x1E] \n"
"                BL      sub_FF0CDA48 \n"
"                B       loc_FF0CC940 \n"

"loc_FF0CC8A4: \n"
//"; jumptable FF0CC77C entry 31
"                LDRH    R1, [R4] \n"
"                STRH    R1, [SP,#0x14] \n"
"                LDRH    R1, [R0,#6] \n"
"                STRH    R1, [SP,#0x16] \n"
"                LDRH    R1, [R4,#4] \n"
"                STRH    R1, [SP,#0x18] \n"
"                LDRH    R1, [R4,#6] \n"
"                STRH    R1, [SP,#0x1A] \n"
"                LDRH    R1, [R4,#8] \n"
"                STRH    R1, [SP,#0x1C] \n"
"                LDRH    R1, [R4,#0xA] \n"
"                STRH    R1, [SP,#0x1E] \n"
"                BL      sub_FF0CDAFC \n"
"                B       loc_FF0CC940 \n"

"loc_FF0CC8DC: \n"
//"; jumptable FF0CC77C entry 32
"                LDRH    R1, [R4] \n"
"                STRH    R1, [SP,#0x14] \n"
"                LDRH    R1, [R4,#2] \n"
"                STRH    R1, [SP,#0x16] \n"
"                LDRH    R1, [R4,#4] \n"
"                STRH    R1, [SP,#0x18] \n"
"                LDRH    R1, [R4,#6] \n"
"                STRH    R1, [SP,#0x1A] \n"
"                LDRH    R1, [R0,#0xC] \n"
"                STRH    R1, [SP,#0x1C] \n"
"                LDRH    R1, [R4,#0xA] \n"
"                STRH    R1, [SP,#0x1E] \n"
"                BL      sub_FF0CDBA4 \n"
"                B       loc_FF0CC940 \n"

"loc_FF0CC914: \n"
//"; jumptable FF0CC77C entries 33,34
"                BL      sub_FF0C9124 \n"
"                B       loc_FF0CC940 \n"

"loc_FF0CC91C: \n"
//"; jumptable FF0CC77C entry 37
"                BL      sub_FF0C9984 \n"
"                B       loc_FF0CC940 \n"

"loc_FF0CC924: \n"
//"; jumptable FF0CC77C entry 38
"                BL      sub_FF0C9EDC \n"
"                B       loc_FF0CC940 \n"

"loc_FF0CC92C: \n"
//"; jumptable FF0CC77C entry 12
"                BL      sub_FF0CA100 \n"
"                B       loc_FF0CC940 \n"

"loc_FF0CC934: \n"
//"; jumptable FF0CC77C entries 13-16
"                BL      sub_FF0CA2BC \n"
"                B       loc_FF0CC940 \n"

"loc_FF0CC93C: \n"
//"; jumptable FF0CC77C entry 17
"                BL      sub_FF0CA42C \n"

"loc_FF0CC940: \n"
//"; jumptable FF0CC77C default entry
//"; jumptable FF0CC77C entries 18-23,35,36
"                LDR     R0, [SP,#0x20] \n"
"                LDR     R1, [R0,#0x7C] \n"
"                LDR     R2, [R0,#0x90] \n"
"                LDR     R3, [R0,#0x8C] \n"

"loc_FF0CC950: \n"
"                ADD     R0, R0, #4 \n"
"                BLX     R3 \n"

"loc_FF0CC958: \n"
"                LDR     R1, [SP,#0x20] \n"
"                LDR     R0, [R1] \n"
"                CMP     R0, #0x10 \n"
"                BEQ     loc_FF0CC990 \n"
"                BGT     loc_FF0CC980 \n"
"                CMP     R0, #1 \n"
"                CMPNE   R0, #4 \n"
"                CMPNE   R0, #0xE \n"
"                BNE     loc_FF0CC9A0 \n"
"                B       loc_FF0CC990 \n"

"loc_FF0CC980: \n"
"                CMP     R0, #0x13 \n"
"                CMPNE   R0, #0x17 \n"
"                CMPNE   R0, #0x1A \n"
"                BNE     loc_FF0CC9A0 \n"

"loc_FF0CC990: \n"
"                LDRH    R0, [R4] \n"
"                STRH    R0, [SP,#0x14] \n"
"                LDRH    R0, [R4,#8] \n"
"                STRH    R0, [SP,#0x1C] \n"

"loc_FF0CC9A0: \n"
"                CMP     R8, #1 \n"
"                BNE     loc_FF0CC9EC \n"
"                LDR     R0, [R1,#0x7C] \n"
"                MOV     R2, #0xC \n"
"                ADD     R0, R0, R0,LSL#1 \n"
"                ADD     R0, R1, R0,LSL#2 \n"
"                SUB     R8, R0, #8 \n"
"                LDR     R0, =0x5CDA0 \n"
"                ADD     R1, SP, #0x14 \n"
"                BL      sub_FF42FA58 \n"
"                LDR     R0, =0x5CDAC \n"
"                MOV     R2, #0xC \n"
"                ADD     R1, SP, #0x14 \n"
"                BL      sub_FF42FA58 \n"
"                LDR     R0, =0x5CDB8 \n"
"                MOV     R2, #0xC \n"
"                MOV     R1, R8 \n"
"                BL      sub_FF42FA58 \n"
"                B       loc_FF0CCA64 \n"

"loc_FF0CC9EC: \n"
"                LDR     R0, [R1] \n"
"                MOV     R3, #1 \n"
"                CMP     R0, #0xB \n"
"                BNE     loc_FF0CCA30 \n"
"                MOV     R2, #0 \n"
"                STRD    R2, [SP] \n"
"                MOV     R2, R3 \n"
"                MOV     R1, R3 \n"
"                MOV     R0, #0 \n"
"                BL      sub_FF0C7804 \n"
"                MOV     R3, #1 \n"
"                MOV     R2, #0 \n"
"                STRD    R2, [SP] \n"
"                MOV     R2, R3 \n"
"                MOV     R1, R3 \n"
"                MOV     R0, #0 \n"
"                B       loc_FF0CCA60 \n"

"loc_FF0CCA30: \n"
"                MOV     R2, #1 \n"
"                STRD    R2, [SP] \n"
"                MOV     R3, R2 \n"
"                MOV     R1, R2 \n"
"                MOV     R0, R2 \n"
"                BL      sub_FF0C7804 \n"
"                MOV     R3, #1 \n"
"                MOV     R2, R3 \n"
"                MOV     R1, R3 \n"
"                MOV     R0, R3 \n"
"                STR     R3, [SP] \n"
"                STR     R3, [SP,#0x04] \n"

"loc_FF0CCA60: \n"
"                BL      sub_FF0C797C \n"

"loc_FF0CCA64: \n"
"                LDR     R0, [SP,#0x20] \n"
"                BL      sub_FF0CD83C \n"
"                B       loc_FF0CC428 \n"
 );
}

void __attribute__((naked,noinline)) sub_FF0C8958_my() {
	asm volatile (
"                STMFD   SP!, {R4-R8,LR} \n"
"                LDR     R7, =0x4BF0 \n"
"                MOV     R4, R0 \n"
"                LDR     R0, [R7,#0x1C] \n"
"                MOV     R1, #0x3E \n"
"                BL      sub_FF088B80 \n"
"                MOV     R2, #0 \n"
"                LDRSH   R0, [R4,#4] \n"
"                MOV     R1, R2 \n"
"                BL      sub_FF0C74CC \n"
"                MOV     R5, R0 \n"
"                LDRSH   R0, [R4,#6] \n"
"                BL      sub_FF0C761C \n"
"                LDRSH   R0, [R4,#8] \n"
"                BL      sub_FF0C7674 \n"
"                LDRSH   R0, [R4,#0xA] \n"
"                BL      sub_FF0C76CC \n"
"                LDRSH   R0, [R4,#0xC] \n"
"                MOV     R1, #0 \n"
"                BL      sub_FF0C7724 \n"
"                MOV     R6, R0 \n"
"                LDRSH   R0, [R4,#0xE] \n"
"                BL      sub_FF0CD86C \n"
"                LDR     R0, [R4] \n"
"                LDR     R8, =0x5CDB8 \n"
"                CMP     R0, #0xB \n"
"                MOVEQ   R5, #0 \n"
"                MOVEQ   R6, R5 \n"
"                BEQ     loc_FF0C89F4 \n"
"                CMP     R5, #1 \n"
"                BNE     loc_FF0C89F4 \n"
"                LDRSH   R0, [R4,#4] \n"
"                LDR     R1, =0xFF0C742C \n"
"                MOV     R2, #2 \n"
"                BL      sub_FF1BDB08 \n"
"                STRH    R0, [R4,#4] \n"
"                MOV     R0, #0 \n"
"                STR     R0, [R7,#0x28] \n"
"                B       loc_FF0C89FC \n"

"loc_FF0C89F4: \n"
"                LDRH    R0, [R8] \n"
"                STRH    R0, [R4,#4] \n"

"loc_FF0C89FC: \n"
"                CMP     R6, #1 \n"
"                LDRNEH  R0, [R8,#8] \n"
"                BNE     loc_FF0C8A18 \n"
"                LDRSH   R0, [R4,#0xC] \n"
"                LDR     R1, =0xFF0C74B0 \n"
"                MOV     R2, #0x20 \n"
"                BL      sub_FF0CD88C \n"

"loc_FF0C8A18: \n"
"                STRH    R0, [R4,#0xC] \n"
"                LDRSH   R0, [R4,#6] \n"
//"                BL      sub_FF0B7684 \n"
"                BL      sub_FF0B7684_my \n" // patched
"				 B	     sub_FF0C8A24 \n"	 // continue in firmware
	);
}

void __attribute__((naked,noinline)) sub_FF0B7684_my() {
	asm volatile (
"                STMFD   SP!, {R4-R6,LR} \n"
"                LDR     R5, =0x4898 \n"
"                MOV     R4, R0 \n"
"                LDR     R0, [R5,#4] \n"
"                CMP     R0, #1 \n"
"                LDRNE   R1, =0x14D \n"
"                LDRNE   R0, =0xFF0B74BC \n"	//  ; "Shutter.c"
"                BLNE    _DebugAssert \n"
"                CMN     R4, #0xC00 \n"
"                LDREQSH R4, [R5,#2] \n"
"                CMN     R4, #0xC00 \n"
"                LDREQ   R1, =0x153 \n"
"                LDRNE   R0, =0xFF0B74BC \n"	//  ; "Shutter.c"
"                STRH    R4, [R5,#2] \n"
"                BLEQ    _DebugAssert \n"
"                MOV     R0, R4 \n"
"                BL      apex2us \n"		// patched
"				 B	     sub_FF0B76C8 \n"	// continue in firmware
);
}
