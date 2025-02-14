#include "lolevel.h"
#include "platform.h"
#include "core.h"

static long *nrflag = (long*)0x9F90;

#include "../../../generic/capt_seq.c"

void __attribute__((naked,noinline)) sub_FFD0A3CC_my(){ 
 asm volatile(
                 "STMFD   SP!, {R0-R10,LR}\n"
                 "MOV     R6, #0\n"
                 "MOV     R4, R0\n"
                 "BL      sub_FFD0AEB4\n"
                 "MVN     R1, #0\n"
                 "BL      sub_FFC18E20\n"
                 "MOV     R2, #4\n"
                 "ADD     R1, SP, #8\n"
                 "MOV     R0, #0x8A\n"
                 "BL      sub_FFC59C2C\n"
                 "TST     R0, #1\n"
                 "LDRNE   R1, =0x20A\n"
                 "LDRNE   R0, =0xFFD0A5A0\n"
                 "BLNE    sub_FFC0C098\n"
                 "LDR     R8, =0x1933C\n"
                 "LDR     R5, =0x19290\n"
                 "LDRSH   R1, [R8,#0xE]\n"
                 "LDR     R0, [R5,#0x74]\n"
                 "BL      sub_FFCD0C9C\n"
                 "BL      sub_FFC39108\n"
                 "LDR     R2, =0x9F94\n"
                 "ADD     R3, R4, #0x8C\n"
                 "STRH    R0, [R4,#0x88]\n"
                 "STR     R2, [SP]\n"
                 "STR     R3, [SP,#4]\n"
                 "MOV     R1, R0\n"
                 "LDRH    R0, [R5,#0x4C]\n"
                 "LDRSH   R2, [R8,#0xC]\n"
                 "LDR     R3, =0x9F90\n"
		 "BL      sub_FFD0B3A0\n"
                 "BL      wait_until_remote_button_is_released\n"
                 "BL      capt_seq_hook_set_nr\n"
                 "B       sub_FFD0A440\n"
 );
}


void __attribute__((naked,noinline)) task_CaptSeqTask_my() //#fs
{
	asm volatile (
                "STMFD   SP!, {R3-R7,LR}\n"
                "LDR     R6, =0x5680\n"

"loc_FFC4CB6C:\n"
                "LDR     R0, [R6,#8]\n"
                "MOV     R2, #0\n"
                "MOV     R1, SP\n"
                "BL      sub_FFC19070\n"
                "TST     R0, #1\n"
                "BEQ     loc_FFC4CB98\n"
                "LDR     R1, =0x43F\n"
                "LDR     R0, =0xFFC4C924\n" // aSsshoottask_c ; SsShootTask.c
                "BL      sub_FFC0C098\n"    // Assert
                "BL      sub_FFC0BE50\n"    // ExitTask
                "LDMFD   SP!, {R3-R7,PC}\n"

"loc_FFC4CB98:\n"
                //LDR     R0, [SP,#0x18+var_18]
                "LDR     R0, [SP]\n"
                "LDR     R1, [R0]\n"

                "LDR     R2, =0x1850\n"         // DEBUG: Save jumptable-target ...
                "STR     R1, [R2]\n"            // ...to some unused space. Read and displayed in GUI in core/gui.c

                "CMP     R1, #0x16\n"
                "ADDLS   PC, PC, R1,LSL#2\n"
                "B       loc_FFC4CD80\n"        // 0: error handler (invalid jump offset) (also when shutter half-pressed?)

                "B       loc_FFC4CC08\n"        // 1: immediately after shutter release, !modify this one!
                "B       loc_FFC4CC10\n"
                "B       loc_FFC4CC88\n"        // 3: default if shutter not pressed
                "B       loc_FFC4CC9C\n"        // 4: after shutter release, when timed image preview active
                "B       loc_FFC4CC94\n"        // 5: after shutter release, in detailed image review
                "B       loc_FFC4CCA4\n"
                "B       loc_FFC4CCAC\n"
                "B       loc_FFC4CCB8\n"
                "B       loc_FFC4CD10\n"        // 9: also ends with continuation of #1
                "B       loc_FFC4CC9C\n"        // 10:
                "B       loc_FFC4CD18\n"        // 11:
                "B       loc_FFC4CD20\n"        // 12:
                "B       loc_FFC4CD28\n"        // 13:
                "B       loc_FFC4CD30\n"        // 14:
                "B       loc_FFC4CD38\n"        // 15: in image-viewer
                "B       loc_FFC4CD40\n"
                "B       loc_FFC4CD48\n"
                "B       loc_FFC4CD50\n"
                "B       loc_FFC4CD58\n"
                "B       loc_FFC4CD64\n"
                "B       loc_FFC4CD70\n"
                "B       loc_FFC4CD78\n"
                "B       loc_FFC4CD8C\n"
"loc_FFC4CC08:\n"                               // #1
                "BL      sub_FFD08E6C\n"        
                "BL      shooting_expo_param_override\n"  // +
                "B       loc_FFC4CCB0\n"
"loc_FFC4CC10:\n"                               // #2
                "LDR     R4, [R0,#0xC]\n"
                "LDR     R0, [R4,#8]\n"
                "ORR     R0, R0, #1\n"
                "STR     R0, [R4,#8]\n"
                "MOV     R0, #2\n"
                "BL      sub_FFC48200\n"
                "BL      sub_FFD08E5C\n"
                "MOV     R0, R4\n"
                "BL      sub_FFD092AC\n"
                "TST     R0, #1\n"
                "MOVNE   R2, R4\n"
                "MOVNE   R1, #1\n"
                "BNE     loc_FFC4CD08\n"
                "BL      sub_FFD1D7E0\n"
                "BL      sub_FFC59DBC\n"
                "STR     R0, [R4,#0x14]\n"
                "MOV     R0, R4\n"
                "BL      sub_FFD0A2E4\n"
                "BL      sub_FFD0AD48\n"
                "MOV     R0, R4\n"
                "BL      sub_FFD0A3CC_my\n"         //--------------> 
                "BL      capt_seq_hook_raw_here\n"  //-------------->
                "MOV     R2, R4\n"
                "MOV     R1, #1\n"
                "BL      sub_FFC4B2F8\n"
                "BL      sub_FFD0A798\n"
                "CMP     R0, #0\n"
                "LDRNE   R0, [R4,#8]\n"
                "ORRNE   R0, R0, #0x2000\n"
                "STRNE   R0, [R4,#8]\n"
                "B       loc_FFC4CD8C\n"
"loc_FFC4CC88:\n"
                "MOV     R0, #1\n"
                "BL      sub_FFD08FFC\n"
                "B       loc_FFC4CD8C\n"
"loc_FFC4CC94:\n"
                "BL      sub_FFD08A88\n"
                "B       loc_FFC4CD8C\n"
"loc_FFC4CC9C:\n"
                "BL      sub_FFD08E4C\n"
                "B       loc_FFC4CD8C\n"
"loc_FFC4CCA4:\n"
                "BL      sub_FFD08E54\n"
                "B       loc_FFC4CD8C\n"
"loc_FFC4CCAC:\n"
                "BL      sub_FFD08F1C\n"
"loc_FFC4CCB0:\n"
                "BL      sub_FFC4AF60\n"
                "B       loc_FFC4CD8C\n"
"loc_FFC4CCB8:\n"
                "LDR     R4, [R0,#0xC]\n"
                "BL      sub_FFD08E5C\n"
                "MOV     R0, R4\n"
                "BL      sub_FFD0962C\n"
                "TST     R0, #1\n"
                "MOV     R5, R0\n"
                "BNE     loc_FFC4CCF8\n"
                "BL      sub_FFC59DBC\n"
                "STR     R0, [R4,#0x14]\n"
                "MOV     R0, R4\n"
                "BL      sub_FFD0A2E4\n"
                "MOV     R0, R4\n"
                "BL      sub_FFD0A7F8\n"
                "MOV     R5, R0\n"
                "LDR     R0, [R4,#0x14]\n"
                "BL      sub_FFC59FD0\n"
"loc_FFC4CCF8:\n"
                "BL      sub_FFD08E4C\n"
                "MOV     R2, R4\n"
                "MOV     R1, #8\n"
                "MOV     R0, R5\n"
"loc_FFC4CD08:\n"
                "BL      sub_FFC4B2F8\n"
                "B       loc_FFC4CD8C\n"
"loc_FFC4CD10:\n"
                "BL      sub_FFD08F78\n"
                "B       loc_FFC4CCB0\n"
"loc_FFC4CD18:\n"
                "BL      sub_FFD09898\n"
                "B       loc_FFC4CD8C\n"
"loc_FFC4CD20:\n"
                "BL      sub_FFD09A50\n"
                "B       loc_FFC4CD8C\n"
"loc_FFC4CD28:\n"
                "BL      sub_FFD09AE0\n"
                "B       loc_FFC4CD8C\n"
"loc_FFC4CD30:\n"
                "BL      sub_FFD09B94\n"
                "B       loc_FFC4CD8C\n"
"loc_FFC4CD38:\n"
                "MOV     R0, #0\n"
                "B       loc_FFC4CD5C\n"
"loc_FFC4CD40:\n"
                "BL      sub_FFD09EC8\n"
                "B       loc_FFC4CD8C\n"
"loc_FFC4CD48:\n"
                "BL      sub_FFD09F5C\n"
                "B       loc_FFC4CD8C\n"
"loc_FFC4CD50:\n"
                "BL      sub_FFD0A01C\n"
                "B       loc_FFC4CD8C\n"
"loc_FFC4CD58:\n"
                "MOV     R0, #1\n"
"loc_FFC4CD5C:\n"
                "BL      sub_FFD09D88\n"
                "B       loc_FFC4CD8C\n"
"loc_FFC4CD64:\n"
                "BL      sub_FFD09128\n"
                "BL      sub_FFC15B44\n"
                "B       loc_FFC4CD8C\n"
"loc_FFC4CD70:\n"
                "BL      sub_FFD09C50\n"
                "B       loc_FFC4CD8C\n"
"loc_FFC4CD78:\n"
                "BL      sub_FFD09CBC\n"
                "B       loc_FFC4CD8C\n"
"loc_FFC4CD80:\n"
                "LDR     R1, =0x523\n"
                "LDR     R0, =0xFFC4C924\n" // aSsshoottask_c ; SsShootTask.c
                "BL      sub_FFC0C098\n"    // Assert
"loc_FFC4CD8C:\n"
                //"LDR     R0, [SP,#0x18+var_18]\n"
                "LDR     R0, [SP]\n"
                "LDR     R1, [R0,#4]\n"
                "LDR     R0, [R6,#4]\n"
                "BL      sub_FFC18DEC\n"
                //"LDR     R4, [SP,#0x18+var_18]\n"
                "LDR     R4, [SP]\n"
                "LDR     R0, [R4,#8]\n"
                "CMP     R0, #0\n"
                "MOVEQ   R1, #0xFC\n"
                "LDREQ   R0, =0xFFC4C924\n" // aSsshoottask_c ; SsShootTask.c
                "BLEQ    sub_FFC0C098\n"    // Assert
                "MOV     R0, #0\n"
                "STR     R0, [R4,#8]\n"
                "B       loc_FFC4CB6C\n"
    );
} //#fe

/*
void __attribute__((naked,noinline)) exp_drv_task(){
 asm volatile(
                "STMFD   SP!, {R4-R8,LR}\n"
                "SUB     SP, SP, #0x20\n"
                "LDR     R8, =0xBB8\n"
                "LDR     R7, =0x6818\n"
                "LDR     R5, =0x40A68\n"
                "MOV     R0, #0\n"
                "ADD     R6, SP, #0x10\n"
                "STR     R0, [SP,#0xC]\n"
"loc_FFC91474:\n"
                "LDR     R0, [R7,#0x20]\n"
                "MOV     R2, #0\n"
                "ADD     R1, SP, #0x1C\n"
                "BL      sub_FFC19070\n"
                "LDR     R0, [SP,#0xC]\n"
                "CMP     R0, #1\n"
                "BNE     loc_FFC914BC\n"
                "LDR     R0, [SP,#0x1C]\n"
                "LDR     R0, [R0]\n"
                "CMP     R0, #0x13\n"
                "CMPNE   R0, #0x14\n"
                "CMPNE   R0, #0x15\n"
                "BEQ     loc_FFC9163C\n"
                "CMP     R0, #0x26\n"
                "BEQ     loc_FFC915A8\n"
                "ADD     R1, SP, #0xC\n"
                "MOV     R0, #0\n"
                "BL      sub_FFC91404\n"
"loc_FFC914BC:\n"
                "LDR     R0, [SP,#0x1C]\n"
                "LDR     R1, [R0]\n"
                "CMP     R1, #0x2B\n"
                "BNE     loc_FFC914EC\n"
                "LDR     R0, [SP,#0x1C]\n"
                "BL      sub_FFC92734\n"
                "LDR     R0, [R7,#0x1C]\n"
                "MOV     R1, #1\n"
                "BL      sub_FFC18DEC\n"
                "BL      _ExitTask\n"
                "ADD     SP, SP, #0x20\n"
                "LDMFD   SP!, {R4-R8,PC}\n"
"loc_FFC914EC:\n"
                "CMP     R1, #0x2A\n"
                "BNE     loc_FFC91508\n"
                "LDR     R2, [R0,#0x88]\n"
                "LDR     R1, [R0,#4]\n"
                "MOV     R0, R1\n"
                "BLX     R2\n"
                "B       loc_FFC91AA0\n"
"loc_FFC91508:\n"
                "CMP     R1, #0x24\n"
                "BNE     loc_FFC91558\n"
                "LDR     R0, [R7,#0x1C]\n"
                "MOV     R1, #0x80\n"
                "BL      sub_FFC18E20\n"
                "LDR     R0, =0xFFC8DEF0\n"
                "MOV     R1, #0x80\n"
                "BL      sub_FFCFF1BC\n"
                "LDR     R0, [R7,#0x1C]\n"
                "MOV     R2, R8\n"
                "MOV     R1, #0x80\n"
                "BL      sub_FFC18D24\n"
                "TST     R0, #1\n"
                "LDRNE   R1, =0xD07\n"
                "BNE     loc_FFC91618\n"
"loc_FFC91544:\n"
                "LDR     R1, [SP,#0x1C]\n"
                "LDR     R0, [R1,#0x8C]\n"
                "LDR     R1, [R1,#0x88]\n"
                "BLX     R1\n"
                "B       loc_FFC91AA0\n"
"loc_FFC91558:\n"
                "CMP     R1, #0x25\n"
                "BNE     loc_FFC915A0\n"
                "ADD     R1, SP, #0xC\n"
                "BL      sub_FFC91404\n"
                "LDR     R0, [R7,#0x1C]\n"
                "MOV     R1, #0x100\n"
                "BL      sub_FFC18E20\n"
                "MOV     R1, #0x100\n"
                "LDR     R0, =0xFFC8DF00\n"
                "BL      sub_FFCFF97C\n"
                "LDR     R0, [R7,#0x1C]\n"
                "MOV     R2, R8\n"
                "MOV     R1, #0x100\n"
                "BL      sub_FFC18D24\n"
                "TST     R0, #1\n"
                "BEQ     loc_FFC91544\n"
                "LDR     R1, =0xD11\n"
                "B       loc_FFC91618\n"
"loc_FFC915A0:\n"
                "CMP     R1, #0x26\n"
                "BNE     loc_FFC915B8\n"
"loc_FFC915A8:\n"
                "LDR     R0, [SP,#0x1C]\n"
                "ADD     R1, SP, #0xC\n"
                "BL      sub_FFC91404\n"
                "B       loc_FFC91544\n"
"loc_FFC915B8:\n"
                "CMP     R1, #0x27\n"
                "CMPNE   R1, #0x28\n"
                "BNE     loc_FFC91624\n"
                "ADD     R1, SP, #0xC\n"
                "BL      sub_FFC91404\n"
                "LDR     R4, [SP,#0x1C]\n"
                "LDR     R0, [R7,#0x1C]\n"
                "MOV     R1, #0x40\n"
                "BL      sub_FFC18E20\n"
                "LDR     R0, [R4]\n"
                "MOV     R1, #0x40\n"
                "CMP     R0, #0x27\n"
                "LDR     R0, =0xFFC8DF64\n"
                "BNE     loc_FFC915F8\n"
                "BL      sub_FFCFF25C\n"
                "B       loc_FFC915FC\n"
"loc_FFC915F8:\n"
                "BL      sub_FFCFF2E8\n"
"loc_FFC915FC:\n"
                "LDR     R0, [R7,#0x1C]\n"
                "MOV     R2, R8\n"
                "MOV     R1, #0x40\n"
                "BL      sub_FFC18D24\n"
                "TST     R0, #1\n"
                "BEQ     loc_FFC91544\n"
                "LDR     R1, =0xD1F\n"
"loc_FFC91618:\n"
                "LDR     R0, =0xFFC8E600\n" //aExpdrv_c
                "BL      sub_FFC0C098\n"    //DebugAssert
                "B       loc_FFC91544\n"
"loc_FFC91624:\n"
                "CMP     R1, #0x29\n"
                "BNE     loc_FFC9163C\n"
                "BL      sub_FFC73568\n"
                "BL      sub_FFC742E8\n"
                "BL      sub_FFC73DA8\n"
                "B       loc_FFC91544\n"
"loc_FFC9163C:\n"
                "LDR     R0, [SP,#0x1C]\n"
                "MOV     R4, #1\n"
                "LDR     R1, [R0]\n"
                "CMP     R1, #0x11\n"
                "CMPNE   R1, #0x12\n"
                "BNE     loc_FFC916AC\n"
                "LDR     R1, [R0,#0x7C]\n"
                "ADD     R1, R1, R1,LSL#1\n"
                "ADD     R1, R0, R1,LSL#2\n"
                "SUB     R1, R1, #8\n"
                "LDMIA   R1, {R2-R4}\n"
                "STMIA   R6, {R2-R4}\n"
                "BL      sub_FFC8FF80\n"
                "LDR     R0, [SP,#0x1C]\n"
                "LDR     R1, [R0,#0x7C]\n"
                "LDR     R3, [R0,#0x88]\n"
                "LDR     R2, [R0,#0x8C]\n"
                "ADD     R0, R0, #4\n"
                "BLX     R3\n"
                "LDR     R0, [SP,#0x1C]\n"
                "BL      sub_FFC92B08\n"
                "LDR     R0, [SP,#0x1C]\n"
                "LDR     R1, [R0,#0x7C]\n"
                "LDR     R3, [R0,#0x90]\n"
                "LDR     R2, [R0,#0x94]\n"
                "ADD     R0, R0, #4\n"
                "BLX     R3\n"
                "B       loc_FFC919E0\n"
"loc_FFC916AC:\n"
                "CMP     R1, #0x13\n"
                "CMPNE   R1, #0x14\n"
                "CMPNE   R1, #0x15\n"
                "BNE     loc_FFC91760\n"
                "ADD     R3, SP, #0xC\n"
                "MOV     R2, SP\n"
                "ADD     R1, SP, #0x10\n"
                "BL      sub_FFC901C8\n"
                "CMP     R0, #1\n"
                "MOV     R4, R0\n"
                "CMPNE   R4, #5\n"
                "BNE     loc_FFC916FC\n"
                "LDR     R0, [SP,#0x1C]\n"
                "MOV     R2, R4\n"
                "LDR     R1, [R0,#0x7C]\n"
                "LDR     R12, [R0,#0xC]\n"
                "LDR     R3, [R0,#4]\n"
                "MOV     R0, SP\n"
                "BLX     R12\n"
                "B       loc_FFC91734\n"
"loc_FFC916FC:\n"
                "LDR     R0, [SP,#0x1C]\n"
                "CMP     R4, #2\n"
                "LDR     R3, [R0,#0x8C]\n"
                "CMPNE   R4, #6\n"
                "BNE     loc_FFC91748\n"
                "LDR     R12, [R0,#0x88]\n"
                "MOV     R0, SP\n"
                "MOV     R2, R4\n"
                "MOV     R1, #1\n"
                "BLX     R12\n"
                "LDR     R0, [SP,#0x1C]\n"
                "MOV     R2, SP\n"
                "ADD     R1, SP, #0x10\n"
                "BL      sub_FFC91150\n"
"loc_FFC91734:\n"
                "LDR     R0, [SP,#0x1C]\n"
                "LDR     R2, [SP,#0xC]\n"
                "MOV     R1, R4\n"
                "BL      sub_FFC913A4\n"
                "B       loc_FFC919E0\n"
"loc_FFC91748:\n"
                "LDR     R1, [R0,#0x7C]\n"
                "LDR     R12, [R0,#0x88]\n"
                "ADD     R0, R0, #4\n"
                "MOV     R2, R4\n"
                "BLX     R12\n"
                "B       loc_FFC919E0\n"
"loc_FFC91760:\n"
                "CMP     R1, #0x20\n"
                "CMPNE   R1, #0x21\n"
                "BNE     loc_FFC917AC\n"
                "LDR     R1, [R0,#0x7C]\n"
                "ADD     R1, R1, R1,LSL#1\n"
                "ADD     R1, R0, R1,LSL#2\n"
                "SUB     R1, R1, #8\n"
                "LDMIA   R1, {R2-R4}\n"
                "STMIA   R6, {R2-R4}\n"
                "BL      sub_FFC8F504\n"
                "LDR     R0, [SP,#0x1C]\n"
                "LDR     R1, [R0,#0x7C]\n"
                "LDR     R3, [R0,#0x88]\n"
                "LDR     R2, [R0,#0x8C]\n"
                "ADD     R0, R0, #4\n"
                "BLX     R3\n"
                "LDR     R0, [SP,#0x1C]\n"
                "BL      sub_FFC8F800\n"
                "B       loc_FFC919E0\n"
"loc_FFC917AC:\n"
                "ADD     R1, R0, #4\n"
                "LDMIA   R1, {R2,R3,R12}\n"
                "STMIA   R6, {R2,R3,R12}\n"
                "LDR     R1, [R0]\n"
                "CMP     R1, #0x23\n"
                "ADDLS   PC, PC, R1,LSL#2\n"
                "B       loc_FFC919C0\n"
"loc_FFC917C8:\n"
                "B       loc_FFC91858\n"
"loc_FFC917CC:\n"
                "B       loc_FFC91858\n"
"loc_FFC917D0:\n"
                "B       loc_FFC918A8\n"
"loc_FFC917D4:\n"
                "B       loc_FFC918B0\n"
"loc_FFC917D8:\n"
                "B       loc_FFC918B0\n"
"loc_FFC917DC:\n"
                "B       loc_FFC918B0\n"
"loc_FFC917E0:\n"
                "B       loc_FFC91858\n"
"loc_FFC917E4:\n"
                "B       loc_FFC918A8\n"
"loc_FFC917E8:\n"
                "B       loc_FFC918B0\n"
"loc_FFC917EC:\n"
                "B       loc_FFC918B0\n"
"loc_FFC917F0:\n"
                "B       loc_FFC918C8\n"
"loc_FFC917F4:\n"
                "B       loc_FFC918C8\n"
"loc_FFC917F8:\n"
                "B       loc_FFC919B4\n"
"loc_FFC917FC:\n"
                "B       loc_FFC919BC\n"
"loc_FFC91800:\n"
                "B       loc_FFC919BC\n"
"loc_FFC91804:\n"
                "B       loc_FFC919BC\n"
"loc_FFC91808:\n"
                "B       loc_FFC919BC\n"
"loc_FFC9180C:\n"
                "B       loc_FFC919C0\n"
"loc_FFC91810:\n"
                "B       loc_FFC919C0\n"
"loc_FFC91814:\n"
                "B       loc_FFC919C0\n"
"loc_FFC91818:\n"
                "B       loc_FFC919C0\n"
"loc_FFC9181C:\n"
                "B       loc_FFC919C0\n"
"loc_FFC91820:\n"
                "B       loc_FFC918B8\n"
"loc_FFC91824:\n"
                "B       loc_FFC918C0\n"
"loc_FFC91828:\n"
                "B       loc_FFC918C0\n"
"loc_FFC9182C:\n"
                "B       loc_FFC918D4\n"
"loc_FFC91830:\n"
                "B       loc_FFC918DC\n"
"loc_FFC91834:\n"
                "B       loc_FFC9190C\n"
"loc_FFC91838:\n"
                "B       loc_FFC9193C\n"
"loc_FFC9183C:\n"
                "B       loc_FFC9196C\n"
"loc_FFC91840:\n"
                "B       loc_FFC9199C\n"
"loc_FFC91844:\n"
                "B       loc_FFC9199C\n"
"loc_FFC91848:\n"
                "B       loc_FFC919C0\n"
"loc_FFC9184C:\n"
                "B       loc_FFC919C0\n"
"loc_FFC91850:\n"
                "B       loc_FFC919A4\n"
"loc_FFC91854:\n"
                "B       loc_FFC919AC\n"
"loc_FFC91858:\n"
                "BL      sub_FFC8E3E8\n"
                "B       loc_FFC919C0\n"
//"dword_FFC91860  DCD 0xB09\n"
//"dword_FFC91864  DCD 0xB1C\n"
//"dword_FFC91868  DCD 0xB99\n"
//"dword_FFC9186C  DCD 0xC1E\n"
//"dword_FFC91870  DCD 0xC67\n"
//"dword_FFC91874  DCD 0xC6C\n"
//"dword_FFC91878  DCD 0xC7A\n"
//"dword_FFC9187C  DCD 0xCD4\n"
//"dword_FFC91880  DCD 0xCFA\n"
//"dword_FFC91884  DCD 0xCFD\n"
//"off_FFC91888    DCD 0xFFC8DF10\n"
//"dword_FFC9188C  DCD 0xD2C\n"
//"dword_FFC91890  DCD 0x40A68\n"
//"dword_FFC91894  DCD 0xD07\n"
//"dword_FFC91898  DCD 0xD11\n"
//"off_FFC9189C    DCD 0xFFC8DF64\n"
//"dword_FFC918A0  DCD 0xD1F\n"
//"off_FFC918A4    DCD 0xFFC8E600\n"        //aExpdrv_c
"loc_FFC918A8:\n"
                "BL      sub_FFC8E670\n"
                "B       loc_FFC919C0\n"
"loc_FFC918B0:\n"
                "BL      sub_FFC8E874\n"
                "B       loc_FFC919C0\n"
"loc_FFC918B8:\n"
                "BL      sub_FFC8EADC\n"
                "B       loc_FFC919C0\n"
"loc_FFC918C0:\n"
                "BL      sub_FFC8ECD0\n"
                "B       loc_FFC919C0\n"
"loc_FFC918C8:\n"
                "BL      sub_FFC8EF34_my\n" //------------>
                "MOV     R4, #0\n"
                "B       loc_FFC919C0\n"
"loc_FFC918D4:\n"
                "BL      sub_FFC8F070\n"
                "B       loc_FFC919C0\n"
"loc_FFC918DC:\n"
                "LDRH    R1, [R0,#4]\n"
                "STRH    R1, [SP,#0x10]\n"
                "LDRH    R1, [R5,#2]\n"
                "STRH    R1, [SP,#0x12]\n"
                "LDRH    R1, [R5,#4]\n"
                "STRH    R1, [SP,#0x14]\n"
                "LDRH    R1, [R5,#6]\n"
                "STRH    R1, [SP,#0x16]\n"
                "LDRH    R1, [R0,#0xC]\n"
                "STRH    R1, [SP,#0x18]\n"
                "BL      sub_FFC927A8\n"
                "B       loc_FFC919C0\n"
"loc_FFC9190C:\n"
                "LDRH    R1, [R0,#4]\n"
                "STRH    R1, [SP,#0x10]\n"
                "LDRH    R1, [R5,#2]\n"
                "STRH    R1, [SP,#0x12]\n"
                "LDRH    R1, [R5,#4]\n"
                "STRH    R1, [SP,#0x14]\n"
                "LDRH    R1, [R5,#6]\n"
                "STRH    R1, [SP,#0x16]\n"
                "LDRH    R1, [R5,#8]\n"
                "STRH    R1, [SP,#0x18]\n"
                "BL      sub_FFC92924\n"
                "B       loc_FFC919C0\n"
"loc_FFC9193C:\n"
                "LDRH    R1, [R5]\n"
                "STRH    R1, [SP,#0x10]\n"
                "LDRH    R1, [R0,#6]\n"
                "STRH    R1, [SP,#0x12]\n"
                "LDRH    R1, [R5,#4]\n"
                "STRH    R1, [SP,#0x14]\n"
                "LDRH    R1, [R5,#6]\n"
                "STRH    R1, [SP,#0x16]\n"
                "LDRH    R1, [R5,#8]\n"
                "STRH    R1, [SP,#0x18]\n"
                "BL      sub_FFC929D0\n"
                "B       loc_FFC919C0\n"
"loc_FFC9196C:\n"
                "LDRH    R1, [R5]\n"
                "STRH    R1, [SP,#0x10]\n"
                "LDRH    R1, [R5,#2]\n"
                "STRH    R1, [SP,#0x12]\n"
                "LDRH    R1, [R5,#4]\n"
                "STRH    R1, [SP,#0x14]\n"
                "LDRH    R1, [R5,#6]\n"
                "STRH    R1, [SP,#0x16]\n"
                "LDRH    R1, [R0,#0xC]\n"
                "STRH    R1, [SP,#0x18]\n"
                "BL      sub_FFC92A70\n"
                "B       loc_FFC919C0\n"
"loc_FFC9199C:\n"
                "BL      sub_FFC8F2C8\n"
                "B       loc_FFC919C0\n"
"loc_FFC919A4:\n"
                "BL      sub_FFC8F904\n"
                "B       loc_FFC919C0\n"
"loc_FFC919AC:\n"
                "BL      sub_FFC8FB38\n"
                "B       loc_FFC919C0\n"
"loc_FFC919B4:\n"
                "BL      sub_FFC8FCB0\n"
                "B       loc_FFC919C0\n"
"loc_FFC919BC:\n"
                "BL      sub_FFC8FE48\n"
"loc_FFC919C0:\n"
                "LDR     R0, [SP,#0x1C]\n"
                "LDR     R1, [R0,#0x7C]\n"
                "LDR     R3, [R0,#0x88]\n"
                "LDR     R2, [R0,#0x8C]\n"
                "ADD     R0, R0, #4\n"
                "BLX     R3\n"
                "CMP     R4, #1\n"
                "BNE     loc_FFC91A28\n"
"loc_FFC919E0:\n"
                "LDR     R0, [SP,#0x1C]\n"
                "MOV     R2, #0xC\n"
                "LDR     R1, [R0,#0x7C]\n"
                "ADD     R1, R1, R1,LSL#1\n"
                "ADD     R0, R0, R1,LSL#2\n"
                "SUB     R4, R0, #8\n"
                "LDR     R0, =0x40A68\n"
                "ADD     R1, SP, #0x10\n"
                "BL      sub_FFE3B3C4\n"
                "LDR     R0, =0x40A74\n"
                "MOV     R2, #0xC\n"
                "ADD     R1, SP, #0x10\n"
                "BL      sub_FFE3B3C4\n"
                "LDR     R0, =0x40A80\n"
                "MOV     R2, #0xC\n"
                "MOV     R1, R4\n"
                "BL      sub_FFE3B3C4\n"
                "B       loc_FFC91AA0\n"
"loc_FFC91A28:\n"
                "LDR     R0, [SP,#0x1C]\n"
                "LDR     R0, [R0]\n"
                "CMP     R0, #0xB\n"
                "BNE     loc_FFC91A70\n"
                "MOV     R3, #0\n"
                "STR     R3, [SP]\n"
                "MOV     R3, #1\n"
                "MOV     R2, #1\n"
                "MOV     R1, #1\n"
                "MOV     R0, #0\n"
                "BL      sub_FFC8E1F0\n"
                "MOV     R3, #0\n"
                "STR     R3, [SP]\n"
                "MOV     R3, #1\n"
                "MOV     R2, #1\n"
                "MOV     R1, #1\n"
                "MOV     R0, #0\n"
                "B       loc_FFC91A9C\n"
"loc_FFC91A70:\n"
                "MOV     R3, #1\n"
                "MOV     R2, #1\n"
                "MOV     R1, #1\n"
                "MOV     R0, #1\n"
                "STR     R3, [SP]\n"
                "BL      sub_FFC8E1F0\n"
                "MOV     R3, #1\n"
                "MOV     R2, #1\n"
                "MOV     R1, #1\n"
                "MOV     R0, #1\n"
                "STR     R3, [SP]\n"
"loc_FFC91A9C:\n"
                "BL      sub_FFC8E330\n"
"loc_FFC91AA0:\n"
                "LDR     R0, [SP,#0x1C]\n"
                "BL      sub_FFC92734\n"
                "B       loc_FFC91474\n"
	 );
}

void __attribute__((naked,noinline)) sub_FFC8EF34_my(){
 asm volatile(
                "STMFD   SP!, {R4-R8,LR}\n"
                "LDR     R7, =0x6818\n"
                "MOV     R4, R0\n"
                "LDR     R0, [R7,#0x1C]\n"
                "MOV     R1, #0x3E\n"
                "BL      sub_FFC18E20\n"
                "LDRSH   R0, [R4,#4]\n"
                "MOV     R2, #0\n"
                "MOV     R1, #0\n"
                "BL      sub_FFC8DF84\n"
                "MOV     R6, R0\n"
                "LDRSH   R0, [R4,#6]\n"
                "BL      sub_FFC8E090\n"
                "LDRSH   R0, [R4,#8]\n"
                "BL      sub_FFC8E0E8\n"
                "LDRSH   R0, [R4,#0xA]\n"
                "BL      sub_FFC8E140\n"
                "LDRSH   R0, [R4,#0xC]\n"
                "BL      sub_FFC8E198\n"
                "MOV     R5, R0\n"
                "LDR     R0, [R4]\n"
                "LDR     R8, =0x40A80\n"
                "CMP     R0, #0xB\n"
                "MOVEQ   R6, #0\n"
                "MOVEQ   R5, #0\n"
                "BEQ     loc_FFC8EFC4\n"
                "CMP     R6, #1\n"
                "BNE     loc_FFC8EFC4\n"
                "LDRSH   R0, [R4,#4]\n"
                "LDR     R1, =0xFFC8DEE0\n"
                "MOV     R2, #2\n"
                "BL      sub_FFCFF430\n"
                "STRH    R0, [R4,#4]\n"
                "MOV     R0, #0\n"
                "STR     R0, [R7,#0x28]\n"
                "B       loc_FFC8EFCC\n"
"loc_FFC8EFC4:\n"
                "LDRH    R0, [R8]\n"
                "STRH    R0, [R4,#4]\n"
"loc_FFC8EFCC:\n"
                "CMP     R5, #1\n"
                "LDRNEH  R0, [R8,#8]\n"
                "BNE     loc_FFC8EFE8\n"
                "LDRSH   R0, [R4,#0xC]\n"
                "LDR     R1, =0xFFC8DF74\n"
                "MOV     R2, #0x20\n"
                "BL      sub_FFC92764\n"
"loc_FFC8EFE8:\n"
                "STRH    R0, [R4,#0xC]\n"
                "LDRSH   R0, [R4,#6]\n"
                "BL      sub_FFC7330C_my\n" //------------>
                "LDRSH   R0, [R4,#8]\n"
                "MOV     R1, #1\n"
                "BL      sub_FFC73AA0\n"
                "MOV     R1, #0\n"
                "ADD     R0, R4, #8\n"
                "BL      sub_FFC73B28\n"
                "LDRSH   R0, [R4,#0xE]\n"
                "BL      sub_FFC853B0\n"
                "LDR     R4, =0xBB8\n"
                "CMP     R6, #1\n"
                "BNE     loc_FFC8F040\n"
                "LDR     R0, [R7,#0x1C]\n"
                "MOV     R2, R4\n"
                "MOV     R1, #2\n"
                "BL      sub_FFC18D24\n"
                "TST     R0, #1\n"
                "LDRNE   R1, =0x527\n"
                "LDRNE   R0, =0xFFC8E600\n" //ADRNE->LDRNE, aExpdrv_c
                "BLNE    sub_FFC0C098\n"    //DebugAssert
"loc_FFC8F040:\n"
                "CMP     R5, #1\n"
                "LDMNEFD SP!, {R4-R8,PC}\n"
                "LDR     R0, [R7,#0x1C]\n"
                "MOV     R2, R4\n"
                "MOV     R1, #0x20\n"
                "BL      sub_FFC18D24\n"
                "TST     R0, #1\n"
                "LDRNE   R1, =0x52C\n"
                "LDRNE   R0, =0xFFC8E600\n" //aExpdrv_c
                "LDMNEFD SP!, {R4-R8,LR}\n"
                "BNE     sub_FFC0C098\n"    //DebugAssert
                "LDMFD   SP!, {R4-R8,PC}\n"
	 );
}

void __attribute__((naked,noinline)) sub_FFC7330C_my(){
 asm volatile(
                "STMFD   SP!, {R4-R6,LR}\n"
                "LDR     R5, =0x62D4\n"
                "MOV     R4, R0\n"
                "LDR     R0, [R5,#4]\n"
                "CMP     R0, #1\n"
                "MOVNE   R1, #0x16C\n"
                "LDRNE   R0, =0xFFC730A4\n" //aShutter_c
                "BLNE    sub_FFC0C098\n"    //DebugAssert
                "CMN     R4, #0xC00\n"
                "LDREQSH R4, [R5,#2]\n"
                "CMN     R4, #0xC00\n"
                "LDREQ   R1, =0x172\n"
                "LDREQ   R0, =0xFFC730A4\n" //aShutter_c
                "STRH    R4, [R5,#2]\n"
                "BLEQ    sub_FFC0C098\n"    //DebugAssert
                "MOV     R0, R4\n"
//                "BL      sub_FFD6363C\n"  //-
                "BL      apex2us\n"         //+
                "MOV     R4, R0\n"
//                "BL      nullsub_20\n"
                "MOV     R0, R4\n"
                "BL      sub_FFCA493C\n"
                "TST     R0, #1\n"
                "LDRNE   R1, =0x177\n"
                "LDMNEFD SP!, {R4-R6,LR}\n"
                "LDRNE   R0, =0xFFC730A4\n" //aShutter_c
                "BNE     sub_FFC0C098\n"    //DebugAssert
                "LDMFD   SP!, {R4-R6,PC}\n"
	 );
}
*/