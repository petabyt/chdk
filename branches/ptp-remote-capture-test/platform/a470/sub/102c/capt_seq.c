#include "lolevel.h"
#include "platform.h"
#include "core.h"

static long *nrflag = (long*)0x88d8; //found in sub_ffd0d528

typedef struct {
    unsigned int address;
    unsigned int length;
} cam_ptp_data_chunk; //camera specific structure

#define MAX_CHUNKS_FOR_JPEG 3 //can be model specific (it's either for JPEG or native RAW)

#include "../../../generic/capt_seq.c"

void __attribute__((naked,noinline)) sub_FFD0D528_my(){ 
 asm volatile(
                 "STMFD   SP!, {R0-R10,LR}\n"
                 "MOV     R6, #0\n"
                 "MOV     R4, R0\n"
                 "BL      sub_FFD0E028\n"
                 "MVN     R1, #0\n"
                 "BL      sub_FFC173EC\n"
                 "MOV     R2, #4\n"
                 "ADD     R1, SP, #8\n"
                 "MOV     R0, #0x8A\n"
                 "BL      sub_FFC57424\n"
                 "TST     R0, #1\n"
                 "LDRNE   R1, =0x218\n"
                 "LDRNE   R0, =0xFFD0D73C\n"
                 "BLNE    sub_FFC0BDB8\n"
                 "LDR     R8, =0x1977C\n"
                 "LDR     R5, =0x196D0\n"
                 "LDRSH   R1, [R8,#0xE]\n"
                 "LDR     R0, [R5,#0x74]\n"
                 "BL      sub_FFCCBC30\n"
                 "BL      sub_FFC3302C\n"
                 "LDR     R2, =0x88DC\n"
                 "ADD     R3, R4, #0x8C\n"
                 "STRH    R0, [R4,#0x88]\n"
                 "STR     R2, [SP]\n"  //Was "STRD    R2, [SP,#0x30-0x30]\n"
                 "STR     R3, [SP,#4]\n" //
                 "MOV     R1, R0\n"
                 "LDRH    R0, [R5,#0x4C]\n"
                 "LDRSH   R2, [R8,#0xC]\n"
                 "LDR     R3, =0x88D8\n"
				 "BL      sub_FFD0E514\n"
                 "BL      wait_until_remote_button_is_released\n"
                 "BL      capt_seq_hook_set_nr\n"
                 "B       sub_FFD0D59C\n"
 );
}

void __attribute__((naked,noinline)) task_CaptSeqTask_my() //#fs
{
	asm volatile (
                "STMFD   SP!, {R3-R7,LR}\n"
                "LDR     R6, =0x52F8\n"

"loc_FFC48DC8:\n"
                "LDR     R0, [R6,#8]\n"
                "MOV     R2, #0\n"
                "MOV     R1, SP\n"
                "BL      sub_FFC1763C\n"
                "TST     R0, #1\n"
                "BEQ     loc_FFC48DF4\n"
                "LDR     R1, =0x48E\n"
                "LDR     R0, =0xFFC48AE8\n" // aSsshoottask_c ; SsShootTask.c
                "BL      sub_FFC0BDB8\n"    // Assert
                "BL      sub_FFC0BB70\n"    // ExitTask
                "LDMFD   SP!, {R3-R7,PC}\n"

"loc_FFC48DF4:\n"
                //LDR     R0, [SP,#0x18+var_18]
                "LDR     R0, [SP]\n"
                "LDR     R1, [R0]\n"

                "CMP     R1, #0x19\n"
                "ADDLS   PC, PC, R1,LSL#2\n"
                "B       loc_FFC49008\n"        // 0: error handler (invalid jump offset) (also when shutter half-pressed?)

                "B       loc_FFC48E70\n"        // 1: immediately after shutter release, !modify this one!
                "B       loc_FFC48E78\n"
                "B       loc_FFC48EF8\n"        // 3: default if shutter not pressed
                "B       loc_FFC48F0C\n"        // 4: after shutter release, when timed image preview active
                "B       loc_FFC48F04\n"        // 5: after shutter release, in detailed image review
                "B       loc_FFC48F14\n"
                "B       loc_FFC48F1C\n"
                "B       loc_FFC48F28\n"
                "B       loc_FFC48F80\n"        // 9: also ends with continuation of #1
                "B       loc_FFC48F0C\n"        // 10:
                "B       loc_FFC48F88\n"        // 11:
                "B       loc_FFC48F90\n"        // 12:
                "B       loc_FFC48F98\n"        // 13:
                "B       loc_FFC48FA0\n"        // 14:
                "B       loc_FFC48FA8\n"        // 15: in image-viewer
                "B       loc_FFC48FB4\n"
                "B       loc_FFC48FBC\n"
                "B       loc_FFC48FC4\n"
                "B       loc_FFC48FCC\n"
                "B       loc_FFC48FD8\n"
                "B       loc_FFC48FE0\n"
                "B       loc_FFC48FE8\n"
                "B       loc_FFC48FF0\n"
                "B       loc_FFC48FF8\n"
                "B       loc_FFC49000\n"
                "B       loc_FFC49014\n"
"loc_FFC48E70:\n"                               // #1
                "BL      sub_FFD0C090\n"        
                "BL      shooting_expo_param_override\n"  // +
                "B       loc_FFC48F20\n"
"loc_FFC48E78:\n"                               // #2
                "LDR     R4, [R0,#0xC]\n"
                "LDR     R0, [R4,#8]\n"
                "ORR     R0, R0, #1\n"
                "STR     R0, [R4,#8]\n"
				"BL      sub_FFD0C080\n"
                "MOV     R0, R4\n"
                "BL      sub_FFD0C468\n"
                "TST     R0, #1\n"
                "MOVNE   R2, R4\n"
                "MOVNE   R1, #1\n"
                "BNE     loc_FFC48F78\n"
                "BL      sub_FFD2ABAC\n"
                "BL      sub_FFC575B4\n"
                "STR     R0, [R4,#0x14]\n"
                "MOV     R0, R4\n"
                "BL      sub_FFD0D460\n"
                "BL      sub_FFD0DEC4\n"
                "MOV     R0, R4\n"
                "BL      sub_FFD0D528_my\n"         //--------------> 
                "BL      capt_seq_hook_raw_here\n"  //-------------->
				"MOV     R5, R0\n"
				"BL		 sub_FFD0EEA4\n"
				"BL      sub_FFD0EEE0\n"
                "MOV     R2, R4\n"
                "MOV     R1, #1\n"
				"MOV     R0, R5\n"
                "BL      sub_FFC4759C\n"
                "BL      sub_FFD0D8D8\n"
                "CMP     R0, #0\n"
                "LDRNE   R0, [R4,#8]\n"
                "ORRNE   R0, R0, #0x2000\n"
                "STRNE   R0, [R4,#8]\n"
                "B       loc_FFC49014\n"
"loc_FFC48EF8:\n"
                "MOV     R0, #1\n"
                "BL      sub_FFD0C224\n"
                "B       loc_FFC49014\n"
"loc_FFC48F04:\n"
                "BL      sub_FFD0BCF0\n"
                "B       loc_FFC49014\n"
"loc_FFC48F0C:\n"
                "BL      sub_FFD0C070\n"
                "B       loc_FFC49014\n"
"loc_FFC48F14:\n"
                "BL      sub_FFD0C078\n"
                "B       loc_FFC49014\n"
"loc_FFC48F1C:\n"
                "BL      sub_FFD0C144\n"
"loc_FFC48F20:\n"
                "BL      sub_FFC4721C\n"
                "B       loc_FFC49014\n"
"loc_FFC48F28:\n"
                "LDR     R4, [R0,#0xC]\n"
                "BL      sub_FFD0C080\n"
                "MOV     R0, R4\n"
                "BL      sub_FFD0C7E8\n"
                "TST     R0, #1\n"
                "MOV     R5, R0\n"
                "BNE     loc_FFC48F68\n"
                "BL      sub_FFC575B4\n"
                "STR     R0, [R4,#0x14]\n"
                "MOV     R0, R4\n"
                "BL      sub_FFD0D460\n"
                "MOV     R0, R4\n"
                "BL      sub_FFD0D938\n"
                "MOV     R5, R0\n"
                "LDR     R0, [R4,#0x14]\n"
                "BL      sub_FFC577C0\n"
"loc_FFC48F68:\n"
                "BL      sub_FFD0C070\n"
                "MOV     R2, R4\n"
                "MOV     R1, #9\n"
                "MOV     R0, R5\n"
"loc_FFC48F78:\n"
                "BL      sub_FFC4759C\n"
                "B       loc_FFC49014\n"
"loc_FFC48F80:\n"
                "BL      sub_FFD0C1A4\n"
                "B       loc_FFC48F20\n"
"loc_FFC48F88:\n"
                "BL      sub_FFD0CA64\n"
                "B       loc_FFC49014\n"
"loc_FFC48F90:\n"
                "BL      sub_FFD0CC4C\n"
                "B       loc_FFC49014\n"
"loc_FFC48F98:\n"
                "BL      sub_FFD0CCDC\n"
                "B       loc_FFC49014\n"
"loc_FFC48FA0:\n"
                "BL      sub_FFD0CD90\n"
                "B       loc_FFC49014\n"
"loc_FFC48FA8:\n"
                "MOV     R0, #0\n"
				"BL      sub_FFD0CF34\n"
                "B       loc_FFC49014\n"
"loc_FFC48FB4:\n"
                "BL      sub_FFD0D084\n"
                "B       loc_FFC49014\n"
"loc_FFC48FBC:\n"
                "BL      sub_FFD0D118\n"
                "B       loc_FFC49014\n"
"loc_FFC48FC4:\n"
                "BL      sub_FFD0D1E0\n"
                "B       loc_FFC49014\n"
"loc_FFC48FCC:\n"
				"BL      sub_FFD0C340\n"
				"BL      sub_FFC149A0\n"
				"B       loc_FFC49014\n"
"loc_FFC48FD8:\n"
				"BL      sub_FFD0CE4C\n"
				"B       loc_FFC49014\n"
"loc_FFC48FE0:\n"
                "BL      sub_FFD0CE90\n"
				"B       loc_FFC49014\n"
"loc_FFC48FE8:\n"
                "BL      sub_FFD0EE88\n"
                "B       loc_FFC49014\n"
"loc_FFC48FF0:\n"
                "BL      sub_FFD0EEA4\n"
                "B       loc_FFC49014\n"
"loc_FFC48FF8:\n"
                "BL      sub_FFD0EEB4\n"
                "B       loc_FFC49014\n"
"loc_FFC49000:\n"
                "BL      sub_FFD0EEE0\n"
                "B       loc_FFC49014\n"
"loc_FFC49008:\n"
                "LDR     R1, =0x58E\n"
                "LDR     R0, =0xFFC48AE8\n" // aSsshoottask_c ; SsShootTask.c
                "BL      sub_FFC0BDB8\n"    // Assert
"loc_FFC49014:\n"
                //"LDR     R0, [SP,#0x18+var_18]\n"
                "LDR     R0, [SP]\n"
                "LDR     R1, [R0,#4]\n"
                "LDR     R0, [R6,#4]\n"
                "BL      sub_FFC173B8\n"
                //"LDR     R4, [SP,#0x18+var_18]\n"
                "LDR     R4, [SP]\n"
                "LDR     R0, [R4,#8]\n"
                "CMP     R0, #0\n"
                "LDREQ   R1, =0x10D\n"
                "LDREQ   R0, =0xFFC48AE8\n" // aSsshoottask_c ; SsShootTask.c
                "BLEQ    sub_FFC0BDB8\n"    // Assert
                "MOV     R0, #0\n"
                "STR     R0, [R4,#8]\n"
                "B       loc_FFC48DC8\n"
    );
} //#fe


void __attribute__((naked,noinline)) exp_drv_task()
{
        asm volatile (
"       STMFD   SP!, {R4-R8,LR}\n"
"       SUB     SP, SP, #0x20\n"
"       LDR     R8, =0xBB8\n"
"       LDR     R7, =0x64FC\n"
"       LDR     R5, =0x3D41C\n"
"       MOV     R0, #0\n"
"       ADD     R6, SP, #0x10\n"
"       STR     R0, [SP,#0xC]\n"
"loc_FFC905F4:\n"
"       LDR     R0, [R7,#0x20]\n"
"       MOV     R2, #0\n"
"       ADD     R1, SP, #0x1C\n"
"       BL      sub_FFC1763C\n"
"       LDR     R0, [SP,#0xC]\n"
"       CMP     R0, #1\n"
"       BNE     loc_FFC9063C\n"
"       LDR     R0, [SP,#0x1C]\n"
"       LDR     R0, [R0]\n"
"       CMP     R0, #0x13\n"
"       CMPNE   R0, #0x14\n"
"       CMPNE   R0, #0x15\n"
"       BEQ     loc_FFC90758\n"
"       CMP     R0, #0x27\n"
"       BEQ     loc_FFC90730\n"
"       ADD     R1, SP, #0xC\n"
"       MOV     R0, #0\n"
"       BL      sub_FFC90584\n"
"loc_FFC9063C:\n"
"       LDR     R0, [SP,#0x1C]\n"
"       LDR     R1, [R0]\n"
"       CMP     R1, #0x2C\n"
"       BNE     loc_FFC9066C\n"
"       LDR     R0, [SP,#0x1C]\n"
"       BL      sub_FFC91838\n"
"       LDR     R0, [R7,#0x1C]\n"
"       MOV     R1, #1\n"
"       BL      sub_FFC173B8\n"
"       BL      sub_FFC0BB70\n"
"       ADD     SP, SP, #0x20\n"
"       LDMFD   SP!, {R4-R8,PC}\n"
"loc_FFC9066C:\n"
"       CMP     R1, #0x2B\n"
"       BNE     loc_FFC90688\n"
"       LDR     R2, [R0,#0x88]!\n"
"       LDR     R1, [R0,#4]\n"
"       MOV     R0, R1\n"
"       BLX     R2\n"
"       B       loc_FFC90BBC\n"
"loc_FFC90688:\n"
"       CMP     R1, #0x25\n"
"       BNE     loc_FFC906D8\n"
"       LDR     R0, [R7,#0x1C]\n"
"       MOV     R1, #0x80\n"
"       BL      sub_FFC173EC\n"
"       LDR     R0, =0xFFC8D078\n"
"       MOV     R1, #0x80\n"
"       BL      sub_FFD03A20\n"
"       LDR     R0, [R7,#0x1C]\n"
"       MOV     R2, R8\n"
"       MOV     R1, #0x80\n"
"       BL      sub_FFC172F0\n"
"       TST     R0, #1\n"
"       LDRNE   R1, =0xD1B\n"
"       BNE     loc_FFC9071C\n"
"loc_FFC906C4:\n"
"       LDR     R1, [SP,#0x1C]\n"
"       LDR     R0, [R1,#0x8C]\n"
"       LDR     R1, [R1,#0x88]\n"
"       BLX     R1\n"
"       B       loc_FFC90BBC\n"
"loc_FFC906D8:\n"
"       CMP     R1, #0x26\n"
"       BNE     loc_FFC90728\n"
"       ADD     R1, SP, #0xC\n"
"       BL      sub_FFC90584\n"
"       LDR     R0, [R7,#0x1C]\n"
"       MOV     R1, #0x100\n"
"       BL      sub_FFC173EC\n"
"       LDR     R0, =0xFFC8D088\n"
"       MOV     R1, #0x100\n"
"       BL      sub_FFD03CA8\n"
"       LDR     R0, [R7,#0x1C]\n"
"       MOV     R2, R8\n"
"       MOV     R1, #0x100\n"
"       BL      sub_FFC172F0\n"
"       TST     R0, #1\n"
"       BEQ     loc_FFC906C4\n"
"       LDR     R1, =0xD25\n"
"loc_FFC9071C:\n"
"       LDR     R0, =0xffc8d778\n" // "ExpDrv.c"
"       BL      sub_FFC0BDB8\n"
"       B       loc_FFC906C4\n"
"loc_FFC90728:\n"
"       CMP     R1, #0x27\n"
"       BNE     loc_FFC90740\n"
"loc_FFC90730:\n"
"       LDR     R0, [SP,#0x1C]\n"
"       ADD     R1, SP, #0xC\n"
"       BL      sub_FFC90584\n"
"       B       loc_FFC906C4\n"
"loc_FFC90740:\n"
"       CMP     R1, #0x2A\n"
"       BNE     loc_FFC90758\n"
"       BL      sub_FFC7042C\n"
"       BL      sub_FFC711F8\n"
"       BL      sub_FFC70C7C\n"
"       B       loc_FFC906C4\n"
"loc_FFC90758:\n"
"       LDR     R0, [SP,#0x1C]\n"
"       MOV     R4, #1\n"
"       LDR     R1, [R0]\n"
"       CMP     R1, #0x11\n"
"       CMPNE   R1, #0x12\n"
"       BNE     loc_FFC907C8\n"
"       LDR     R1, [R0,#0x7C]\n"
"       ADD     R1, R1, R1,LSL#1\n"
"       ADD     R1, R0, R1,LSL#2\n"
"       SUB     R1, R1, #8\n"
"       LDMIA   R1, {R2-R4}\n"
"       STMIA   R6, {R2-R4}\n"
"       BL      sub_FFC8F104\n"
"       LDR     R0, [SP,#0x1C]\n"
"       LDR     R1, [R0,#0x7C]\n"
"       LDR     R3, [R0,#0x88]\n"
"       LDR     R2, [R0,#0x8C]\n"
"       ADD     R0, R0, #4\n"
"       BLX     R3\n"
"       LDR     R0, [SP,#0x1C]\n"
"       BL      sub_FFC91C10\n"
"       LDR     R0, [SP,#0x1C]\n"
"       LDR     R1, [R0,#0x7C]\n"
"       LDR     R3, [R0,#0x90]\n"
"       LDR     R2, [R0,#0x94]\n"
"       ADD     R0, R0, #4\n"
"       BLX     R3\n"
"       B       loc_FFC90AFC\n"
"loc_FFC907C8:\n"
"       CMP     R1, #0x13\n"
"       CMPNE   R1, #0x14\n"
"       CMPNE   R1, #0x15\n"
"       BNE     loc_FFC9087C\n"
"       ADD     R3, SP, #0xC\n"
"       MOV     R2, SP\n"
"       ADD     R1, SP, #0x10\n"
"       BL      sub_FFC8F34C\n"
"       CMP     R0, #1\n"
"       MOV     R4, R0\n"
"       CMPNE   R4, #5\n"
"       BNE     loc_FFC90818\n"
"       LDR     R0, [SP,#0x1C]\n"
"       MOV     R2, R4\n"
"       LDR     R1, [R0,#0x7C]!\n"
"       LDR     R12, [R0,#0xC]!\n"
"       LDR     R3, [R0,#4]\n"
"       MOV     R0, SP\n"
"       BLX     R12\n"
"       B       loc_FFC90850\n"
"loc_FFC90818:\n"
"       LDR     R0, [SP,#0x1C]\n"
"       CMP     R4, #2\n"
"       LDR     R3, [R0,#0x8C]\n"
"       CMPNE   R4, #6\n"
"       BNE     loc_FFC90864\n"
"       LDR     R12, [R0,#0x88]\n"
"       MOV     R0, SP\n"
"       MOV     R2, R4\n"
"       MOV     R1, #1\n"
"       BLX     R12\n"
"       LDR     R0, [SP,#0x1C]\n"
"       MOV     R2, SP\n"
"       ADD     R1, SP, #0x10\n"
"       BL      sub_FFC902D0\n"
"loc_FFC90850:\n"
"       LDR     R0, [SP,#0x1C]\n"
"       LDR     R2, [SP,#0xC]\n"
"       MOV     R1, R4\n"
"       BL      sub_FFC90524\n"
"       B       loc_FFC90AFC\n"
"loc_FFC90864:\n"
"       LDR     R1, [R0,#0x7C]\n"
"       LDR     R12, [R0,#0x88]\n"
"       ADD     R0, R0, #4\n"
"       MOV     R2, R4\n"
"       BLX     R12\n"
"       B       loc_FFC90AFC\n"
"loc_FFC9087C:\n"
"       CMP     R1, #0x21\n"
"       CMPNE   R1, #0x22\n"
"       BNE     loc_FFC908C8\n"
"       LDR     R1, [R0,#0x7C]\n"
"       ADD     R1, R1, R1,LSL#1\n"
"       ADD     R1, R0, R1,LSL#2\n"
"       SUB     R1, R1, #8\n"
"       LDMIA   R1, {R2-R4}\n"
"       STMIA   R6, {R2-R4}\n"
"       BL      sub_FFC8E690\n"
"       LDR     R0, [SP,#0x1C]\n"
"       LDR     R1, [R0,#0x7C]\n"
"       LDR     R3, [R0,#0x88]\n"
"       LDR     R2, [R0,#0x8C]\n"
"       ADD     R0, R0, #4\n"
"       BLX     R3\n"
"       LDR     R0, [SP,#0x1C]\n"
"       BL      sub_FFC8E980\n"
"       B       loc_FFC90AFC\n"
"loc_FFC908C8:\n"
"       ADD     R1, R0, #4\n"
"       LDMIA   R1, {R2,R3,R12}\n"
"       STMIA   R6, {R2,R3,R12}\n"
"       LDR     R1, [R0]\n"
"       CMP     R1, #0x24\n"
"       ADDLS   PC, PC, R1,LSL#2\n"
"       B       loc_FFC90ADC\n" //default case
"loc_FFC908E4:\n"
"       B       loc_FFC90978\n"
"loc_FFC908E8:\n"
"       B       loc_FFC90978\n"
"loc_FFC908EC:\n"
"       B       loc_FFC90980\n"
"loc_FFC908F0:\n"
"       B       loc_FFC90988\n"
"loc_FFC908F4:\n"
"       B       loc_FFC90988\n"
"loc_FFC908F8:\n"
"       B       loc_FFC90988\n"
"loc_FFC908FC:\n"
"       B       loc_FFC90978\n"
"loc_FFC90900:\n"
"       B       loc_FFC90980\n"
"loc_FFC90904:\n"
"       B       loc_FFC90988\n"
"loc_FFC90908:\n"
"       B       loc_FFC90988\n"
"loc_FFC9090C:\n"
"       B       loc_FFC909E4\n"
"loc_FFC90910:\n"
"       B       loc_FFC909E4\n"
"loc_FFC90914:\n"
"       B       loc_FFC90AD0\n"
"loc_FFC90918:\n"
"       B       loc_FFC90AD8\n"
"loc_FFC9091C:\n"
"       B       loc_FFC90AD8\n"
"loc_FFC90920:\n"
"       B       loc_FFC90AD8\n"
"loc_FFC90924:\n"
"       B       loc_FFC90AD8\n"
"loc_FFC90928:\n"
"       B       loc_FFC90ADC\n"
"loc_FFC9092C:\n"
"       B       loc_FFC90ADC\n"
"loc_FFC90930:\n"
"       B       loc_FFC90ADC\n"
"loc_FFC90934:\n"
"       B       loc_FFC90ADC\n"
"loc_FFC90938:\n"
"       B       loc_FFC90ADC\n"
"loc_FFC9093C:\n"
"       B       loc_FFC90990\n"
"loc_FFC90940:\n"
"       B       loc_FFC90998\n"
"loc_FFC90944:\n"
"       B       loc_FFC90998\n"
"loc_FFC90948:\n"
"       B       loc_FFC909F0\n"
"loc_FFC9094C:\n"
"       B       loc_FFC909F0\n"
"loc_FFC90950:\n"
"       B       loc_FFC909F8\n"
"loc_FFC90954:\n"
"       B       loc_FFC90A28\n"
"loc_FFC90958:\n"
"       B       loc_FFC90A58\n"
"loc_FFC9095C:\n"
"       B       loc_FFC90A88\n"
"loc_FFC90960:\n"
"       B       loc_FFC90AB8\n"
"loc_FFC90964:\n"
"       B       loc_FFC90AB8\n"
"loc_FFC90968:\n"
"       B       loc_FFC90ADC\n"
"loc_FFC9096C:\n"
"       B       loc_FFC90ADC\n"
"loc_FFC90970:\n"
"       B       loc_FFC90AC0\n"
"loc_FFC90974:\n"
"       B       loc_FFC90AC8\n"
"loc_FFC90978:\n"
"       BL      sub_FFC8D560\n" //cases 0,1,6
"       B       loc_FFC90ADC\n" //default case
"loc_FFC90980:\n"
"       BL      sub_FFC8D7F0\n" //cases 2,7
"       B       loc_FFC90ADC\n" //default case
"loc_FFC90988:\n"
"       BL      sub_FFC8D9F4\n" //cases 3-5,8,9
"       B       loc_FFC90ADC\n" //default case
"loc_FFC90990:\n"
"       BL      sub_FFC8DC5C\n" //case 22
"       B       loc_FFC90ADC\n" //default case
"loc_FFC90998:\n"
"       BL      sub_FFC8DE50\n" //cases 23,24
"       B       loc_FFC90ADC\n" //default case
"loc_FFC909E4:\n"
"       BL      sub_FFC8E0B8_my\n" //cases 10,11 ->
"       MOV     R4, #0\n"
"       B       loc_FFC90ADC\n" //default case
"loc_FFC909F0:\n"
"       BL      sub_FFC8E1F4\n" //cases 25,26
"       B       loc_FFC90ADC\n" //default case
"loc_FFC909F8:\n"
"       LDRH    R1, [R0,#4]\n" //case 27
"       STRH    R1, [SP,#0x10]\n"
"       LDRH    R1, [R5,#2]\n"
"       STRH    R1, [SP,#0x12]\n"
"       LDRH    R1, [R5,#4]\n"
"       STRH    R1, [SP,#0x14]\n"
"       LDRH    R1, [R5,#6]\n"
"       STRH    R1, [SP,#0x16]\n"
"       LDRH    R1, [R0,#0xC]\n"
"       STRH    R1, [SP,#0x18]\n"
"       BL      sub_FFC918AC\n"
"       B       loc_FFC90ADC\n" //default case
"loc_FFC90A28:\n"
"       LDRH    R1, [R0,#4]\n" //case 28
"       STRH    R1, [SP,#0x10]\n"
"       LDRH    R1, [R5,#2]\n"
"       STRH    R1, [SP,#0x12]\n"
"       LDRH    R1, [R5,#4]\n"
"       STRH    R1, [SP,#0x14]\n"
"       LDRH    R1, [R5,#6]\n"
"       STRH    R1, [SP,#0x16]\n"
"       LDRH    R1, [R5,#8]\n"
"       STRH    R1, [SP,#0x18]\n"
"       BL      sub_FFC91A2C\n"
"       B       loc_FFC90ADC\n" //default case
"loc_FFC90A58:\n"
"       LDRH    R1, [R5]\n" //case 29
"       STRH    R1, [SP,#0x10]\n"
"       LDRH    R1, [R0,#6]\n"
"       STRH    R1, [SP,#0x12]\n"
"       LDRH    R1, [R5,#4]\n"
"       STRH    R1, [SP,#0x14]\n"
"       LDRH    R1, [R5,#6]\n"
"       STRH    R1, [SP,#0x16]\n"
"       LDRH    R1, [R5,#8]\n"
"       STRH    R1, [SP,#0x18]\n"
"       BL      sub_FFC91AD8\n"
"       B       loc_FFC90ADC\n" //default case
"loc_FFC90A88:\n"
"       LDRH    R1, [R5]\n" //case 30
"       STRH    R1, [SP,#0x10]\n"
"       LDRH    R1, [R5,#2]\n"
"       STRH    R1, [SP,#0x12]\n"
"       LDRH    R1, [R5,#4]\n"
"       STRH    R1, [SP,#0x14]\n"
"       LDRH    R1, [R5,#6]\n"
"       STRH    R1, [SP,#0x16]\n"
"       LDRH    R1, [R0,#0xC]\n"
"       STRH    R1, [SP,#0x18]\n"
"       BL      sub_FFC91B78\n"
"       B       loc_FFC90ADC\n" //default case
"loc_FFC90AB8:\n"
"       BL      sub_FFC8E468\n" //cases 31,32
"       B       loc_FFC90ADC\n" //default case
"loc_FFC90AC0:\n"
"       BL      sub_FFC8EA84\n" //case 35
"       B       loc_FFC90ADC\n" //default case
"loc_FFC90AC8:\n"
"       BL      sub_FFC8ECBC\n" //case 36
"       B       loc_FFC90ADC\n" //default case
"loc_FFC90AD0:\n"
"       BL      sub_FFC8EE34\n" //case 12
"       B       loc_FFC90ADC\n" //default case
"loc_FFC90AD8:\n"
"       BL      sub_FFC8EFCC\n" //cases 13-16
"loc_FFC90ADC:\n"
"       LDR     R0, [SP,#0x1C]\n" //default case
"       LDR     R1, [R0,#0x7C]\n"
"       LDR     R3, [R0,#0x88]\n"
"       LDR     R2, [R0,#0x8C]\n"
"       ADD     R0, R0, #4\n"
"       BLX     R3\n"
"       CMP     R4, #1\n"
"       BNE     loc_FFC90B44\n"
"loc_FFC90AFC:\n"
"       LDR     R0, [SP,#0x1C]\n"
"       MOV     R2, #0xC\n"
"       LDR     R1, [R0,#0x7C]\n"
"       ADD     R1, R1, R1,LSL#1\n"
"       ADD     R0, R0, R1,LSL#2\n"
"       SUB     R4, R0, #8\n"
"       LDR     R0, =0x3D41C\n"
"       ADD     R1, SP, #0x10\n"
"       BL      sub_FFE4EA44\n"
"       LDR     R0, =0x3D428\n"
"       MOV     R2, #0xC\n"
"       ADD     R1, SP, #0x10\n"
"       BL      sub_FFE4EA44\n"
"       LDR     R0, =0x3D434\n"
"       MOV     R2, #0xC\n"
"       MOV     R1, R4\n"
"       BL      sub_FFE4EA44\n"
"       B       loc_FFC90BBC\n"
"loc_FFC90B44:\n"
"       LDR     R0, [SP,#0x1C]\n"
"       LDR     R0, [R0]\n"
"       CMP     R0, #0xB\n"
"       BNE     loc_FFC90B8C\n"
"       MOV     R3, #0\n"
"       STR     R3, [SP]\n"
"       MOV     R3, #1\n"
"       MOV     R2, #1\n"
"       MOV     R1, #1\n"
"       MOV     R0, #0\n"
"       BL      sub_FFC8D368\n"
"       MOV     R3, #0\n"
"       STR     R3, [SP]\n"
"       MOV     R3, #1\n"
"       MOV     R2, #1\n"
"       MOV     R1, #1\n"
"       MOV     R0, #0\n"
"       B       loc_FFC90BB8\n"
"loc_FFC90B8C:\n"
"       MOV     R3, #1\n"
"       MOV     R2, #1\n"
"       MOV     R1, #1\n"
"       MOV     R0, #1\n"
"       STR     R3, [SP]\n"
"       BL      sub_FFC8D368\n"
"       MOV     R3, #1\n"
"       MOV     R2, #1\n"
"       MOV     R1, #1\n"
"       MOV     R0, #1\n"
"       STR     R3, [SP]\n"
"loc_FFC90BB8:\n"
"       BL      sub_FFC8D4A8\n"
"loc_FFC90BBC:\n"
"       LDR     R0, [SP,#0x1C]\n"
"       BL      sub_FFC91838\n"
"       B       loc_FFC905F4\n"
        );
}


void __attribute__((naked,noinline)) sub_FFC8E0B8_my()
{
        asm volatile (
"       STMFD   SP!, {R4-R8,LR}\n"
"       LDR     R7, =0x64FC\n"
"       MOV     R4, R0\n"
"       LDR     R0, [R7,#0x1C]\n"
"       MOV     R1, #0x3E\n"
"       BL      sub_FFC173EC\n"
"       LDRSH   R0, [R4,#4]\n"
"       MOV     R2, #0\n"
"       MOV     R1, #0\n"
"       BL      sub_FFC8D0FC\n"
"       MOV     R6, R0\n"
"       LDRSH   R0, [R4,#6]\n"
"       BL      sub_FFC8D208\n"
"       LDRSH   R0, [R4,#8]\n"
"       BL      sub_FFC8D260\n"
"       LDRSH   R0, [R4,#0xA]\n"
"       BL      sub_FFC8D2B8\n"
"       LDRSH   R0, [R4,#0xC]\n"
"       BL      sub_FFC8D310\n"
"       MOV     R5, R0\n"
"       LDR     R0, [R4]\n"
"       LDR     R8, =0x3D434\n"
"       CMP     R0, #0xB\n"
"       MOVEQ   R6, #0\n"
"       MOVEQ   R5, #0\n"
"       BEQ     loc_FFC8E148\n"
"       CMP     R6, #1\n"
"       BNE     loc_FFC8E148\n"
"       LDRSH   R0, [R4,#4]\n"
"       LDR     R1, =0xFFC8D068\n"
"       MOV     R2, #2\n"
"       BL      sub_FFD03B74\n"
"       STRH    R0, [R4,#4]\n"
"       MOV     R0, #0\n"
"       STR     R0, [R7,#0x28]\n"
"       B       loc_FFC8E150\n"
"loc_FFC8E148:\n"
"       LDRH    R0, [R8]\n"
"       STRH    R0, [R4,#4]\n"
"loc_FFC8E150:\n"
"       CMP     R5, #1\n"
"       LDRNEH  R0, [R8,#8]\n"
"       BNE     loc_FFC8E16C\n"
"       LDRSH   R0, [R4,#0xC]\n"
"       MOV     R2, #0x20\n"
"       LDR     R1, =0xFFC8D0EC\n"
"       BL      sub_FFC91868\n"
"loc_FFC8E16C:\n"
"       STRH    R0, [R4,#0xC]\n"
"       LDRSH   R0, [R4,#6]\n"
"       BL      sub_FFC70178_my\n" // ->
"       LDR     PC, =0xFFC8E178\n" // + continue in ROM
/* removed to spare some bytes -
"       LDRSH   R0, [R4,#8]\n"
"       MOV     R1, #1\n"
"       BL      sub_FFC70974\n"
"       MOV     R1, #0\n"
"       ADD     R0, R4, #8\n"
"       BL      sub_FFC709FC\n"
"       LDRSH   R0, [R4,#0xE]\n"
"       BL      sub_FFC84038\n"
"       LDR     R4, =0xBB8\n"
"       CMP     R6, #1\n"
"       BNE     loc_FFC8E1C4\n"
"       LDR     R0, [R7,#0x1C]\n"
"       MOV     R2, R4\n"
"       MOV     R1, #2\n"
"       BL      sub_FFC172F0\n"
"       TST     R0, #1\n"
"       LDRNE   R1, =0x532\n"
"       LDRNE   R0, =0xffc8d778\n" // "ExpDrv.c"
"       BLNE    sub_FFC0BDB8\n"
"loc_FFC8E1C4:\n"
"       CMP     R5, #1\n"
"       LDMNEFD SP!, {R4-R8,PC}\n"
"       LDR     R0, [R7,#0x1C]\n"
"       MOV     R2, R4\n"
"       MOV     R1, #0x20\n"
"       BL      sub_FFC172F0\n"
"       TST     R0, #1\n"
"       LDRNE   R1, =0x537\n"
"       LDRNE   R0, =0xffc8d778\n" // "ExpDrv.c"
"       LDMNEFD SP!, {R4-R8,LR}\n"
"       BNE     sub_FFC0BDB8\n"
"       LDMFD   SP!, {R4-R8,PC}\n"
*/
        );
}


void __attribute__((naked,noinline)) sub_FFC70178_my()
{
        asm volatile (
"       STMFD   SP!, {R4-R6,LR}\n"
"       LDR     R5, =0x5FD4\n"
"       MOV     R4, R0\n"
"       LDR     R0, [R5,#4]\n"
"       CMP     R0, #1\n"
"       LDRNE   R1, =0x16D\n"
"       LDRNE   R0, =0xffc6ff10\n" // "Shutter.c"
"       BLNE    sub_FFC0BDB8\n"
"       CMN     R4, #0xC00\n"
"       LDREQSH R4, [R5,#2]\n"
"       CMN     R4, #0xC00\n"
"       LDREQ   R1, =0x173\n"
"       LDREQ   R0, =0xffc6ff10\n" // "Shutter.c"
"       STRH    R4, [R5,#2]\n"
"       BLEQ    sub_FFC0BDB8\n"
"       MOV     R0, R4\n"
//"       BL      sub_FFD68DD8\n" //-
"       BL      apex2us\n" //+
"       MOV     R4, R0\n"
//"       BL      nullsub\n" //-
//"       MOV     R0, R4\n" //-
"       BL      sub_FFCA2AF8\n"
"       TST     R0, #1\n"
"       LDMNEFD SP!, {R4-R6,LR}\n"
"       MOVNE   R1, #0x178\n"
"       LDRNE   R0, =0xffc6ff10\n" // "Shutter.c"
"       BNE     sub_FFC0BDB8\n"
"       LDMFD   SP!, {R4-R6,PC}\n"
        );
}

//parts of filewritetask follow

void __attribute__((naked,noinline)) filewritetask(  ) { //sub_FFDC18E4
asm volatile (
      "    STMFD   SP!, {R1-R5,LR} \n" 
      "    LDR     R4, =0xC0C8 \n" 
"loc_FFDC18EC:\n"
      "    LDR     R0, [R4, #0x10] \n" 
      "    MOV     R2, #0 \n" 
      "    ADD     R1, SP, #8 \n" 
      "    BL      sub_FFC1763C \n" //ReceiveMessageQueue
      "    CMP     R0, #0 \n" 
      "    BNE     loc_FFDC191C \n" 
      "    LDR     R0, [SP, #8] \n" 
      "    LDR     R1, [R0] \n" 
      "    CMP     R1, #1 \n" 
      "    BNE     loc_FFDC1924 \n" 
      "    LDR     R0, [R4, #8] \n" 
      "    BL      sub_FFC0B844 \n" //GiveSemaphore
"loc_FFDC191C:\n"
      "    BL      sub_FFC0BB70 \n" //ExitTask
      "    LDMFD   SP!, {R1-R5,PC} \n" 
"loc_FFDC1924:\n"
      "    SUB     R1, R1, #2 \n" 
      "    CMP     R1, #5 \n" 
      "    ADDLS   PC, PC, R1, LSL #2 \n" //switch
      "    B       loc_FFDC18EC \n" 
      "    B       loc_FFDC194C \n" 
      "    B       loc_FFDC19B0 \n" 
      "    B       loc_FFDC19B8 \n" 
      "    B       loc_FFDC19B8 \n" 
      "    B       loc_FFDC19B8 \n" 
      "    B       loc_FFDC19C0 \n" 
"loc_FFDC194C:\n" //case 0
      "    MOV     R0, #0 \n" 
      "    STR     R0, [SP] \n" 
"loc_FFDC1954:\n"
      "    LDR     R0, [R4, #0x10] \n" 
      "    MOV     R1, SP \n" 
      "    BL      sub_FFC17840 \n" 
      "    LDR     R0, [SP] \n" 
      "    CMP     R0, #0 \n" 
      "    BEQ     loc_FFDC1980 \n" 
      "    LDR     R0, [R4, #0x10] \n" 
      "    MOV     R2, #0 \n" 
      "    ADD     R1, SP, #4 \n" 
      "    BL      sub_FFC1763C \n" //ReceiveMessageQueue
      "    B       loc_FFDC1954 \n" 
"loc_FFDC1980:\n"
      "    LDR     R0, [R4] \n" 
      "    CMN     R0, #1 \n" 
      "    BEQ     loc_FFDC19A4 \n" 
      "    BL      sub_FFC13B5C \n" //Close
      "    MVN     R0, #0 \n" 
      "    STR     R0, [R4] \n" 
      "    LDR     R0, =0x7BA94 \n" 
      "    BL      sub_FFC3CEF0 \n" 
      "    BL      sub_FFC3E7A4 \n" 
"loc_FFDC19A4:\n"
      "    LDR     R0, [R4, #0xC] \n" 
      "    BL      sub_FFC0B844 \n" //GiveSemaphore
      "    B       loc_FFDC18EC \n" 
"loc_FFDC19B0:\n" //case 1
      "    BL      sub_FFDC1B84_my \n" //-> open file
      "    B       loc_FFDC18EC \n" 
"loc_FFDC19B8:\n" //case 2,3,4
      "    BL      sub_FFDC1CC4_my \n" //-> write file
      "    B       loc_FFDC18EC \n" 
"loc_FFDC19C0:\n" //case 5
      "    BL      sub_FFDC1DC0_my \n" //-> close file
      "    B       loc_FFDC18EC \n"
    );
}

void __attribute__((naked,noinline)) sub_FFDC1B84_my(  ) {
asm volatile (
      "    STMFD   SP!, {R4-R8,LR} \n" 
      "    MOV     R4, R0 \n" 
      "    ADD     R0, R0, #0x2C \n" 
      "    SUB     SP, SP, #0x38 \n" 
      "    BL      sub_FFC3CEF0 \n" 
      "    MOV     R1, #0 \n" 
      "    BL      sub_FFC3E754 \n" 
      "    LDR     R0, [R4, #0xC] \n" 
      "    BL      sub_FFC3F044 \n" 
      "    LDR     R7, [R4, #8] \n" 
      "    LDR     R8, =0x1B6 \n" 
      "    ADD     R6, R4, #0x2C \n" 
      "    LDR     R5, [R4, #0xC] \n" 
//place hook here
//the task's data block is at [r4] at this point, filename starts at [r4+0x2c]
//the block can be captured here for a (new) camera with unknown data block structure
//for ptp remote capture, return fake file handle (255) when done and jump to 0xFFDC1C28
//if writing does not need to be prevented, just continue
      "STMFD SP!, {R4-R12,LR}\n"
      "ADD R1, R4, #0x14\n" //data chunk definitions start here
      "ADD R0, R4, #0x2c\n" //name starts here
      "BL filewrite_main_hook\n"
      "LDMFD SP!, {R4-R12,LR}\n"
      "LDR R0, =ignore_current_write\n"
      "LDR R0, [R0]\n"
      "CMP R0, #0\n"
      "MOVNE R0, #0xff\n"
      "LDRNE PC, =0xffdc1c28\n" //adapt this to the current routine
//hook end
      "    MOV     R0, R6 \n" 
      "    MOV     R1, R7 \n" 
      "    MOV     R2, R8 \n" 
      "    BL      sub_FFC13B34 \n" //Open
//
      "LDR PC, =0xffdc1bc8\n" //continue in ROM
//      "    CMN     R0, #1 \n" // rom:ffdc1bc8 (check for failure in Open)
//      "    BNE     loc_FFDC1C28 \n" // jump here when exiting the hook above
    );
}

void __attribute__((naked,noinline)) sub_FFDC1CC4_my(  ) {
asm volatile (
      "    STMFD   SP!, {R4-R10,LR} \n"             // rom:ffdc1cc4  0xE92D47F0 
      "    MOV     R4, R0 \n" //pointer to the data block
      "    LDR     R0, [R0] \n"                     // rom:ffdc1ccc  0xE5900000 
      "    CMP     R0, #4 \n" //stage "4"?
      "    LDREQ   R6, [R4, #0x18] \n" //1st chunk length
      "    LDREQ   R7, [R4, #0x14] \n" //1st chunk address (exif)
      "    BEQ     loc_FFDC1D00 \n"                 // rom:ffdc1cdc  0x0A000007 
      "    CMP     R0, #5 \n" //stage "5"?
      "    LDREQ   R6, [R4, #0x20] \n" //2nd chunk length
      "    LDREQ   R7, [R4, #0x1C] \n" //2nd chunk address (jpeg)
      "    BEQ     loc_FFDC1D00 \n"                 // rom:ffdc1cec  0x0A000003 
      "    CMP     R0, #6 \n" //stage "6"?
      "    BNE     loc_FFDC1D14 \n"                 // rom:ffdc1cf4  0x1A000006 
      "    LDR     R6, [R4, #0x28] \n" //3rd chunk length (seems to always be zero)
      "    LDR     R7, [R4, #0x24] \n" //3rd chunk address
"loc_FFDC1D00:\n"
      "    CMP     R6, #0 \n"                       // rom:ffdc1d00  0xE3560000 
      "    BNE     loc_FFDC1D24 \n"                 // rom:ffdc1d04  0x1A000006 
"loc_FFDC1D08:\n"
      "    MOV     R1, R4 \n"                       // rom:ffdc1d08  0xE1A01004 
      "    MOV     R0, #7 \n"                       // rom:ffdc1d0c  0xE3A00007 
      "    B       loc_FFDC1DB8 \n"                 // rom:ffdc1d10  0xEA000028 
"loc_FFDC1D14:\n"
      "    LDR     R1, =0x1E2 \n"                   // rom:ffdc1d14  0xE59F1144 
      "    LDR     R0, =0xFFDC1CA4 \n"              // rom:ffdc1d18  0xE24F007C 
      "    BL      sub_FFC0BDB8 \n"                 // rom:ffdc1d1c  0xEBF92825 
      "    B       loc_FFDC1D08 \n"                 // rom:ffdc1d20  0xEAFFFFF8 
"loc_FFDC1D24:\n"
      "    LDR     R9, =0xC0C8 \n"                  // rom:ffdc1d24  0xE51F90A8 
      "    MOV     R5, R6 \n"                       // rom:ffdc1d28  0xE1A05006 
"loc_FFDC1D2C:\n"
      "    LDR     R0, [R4, #4] \n"                 // rom:ffdc1d2c  0xE5940004 
      "    CMP     R5, #0x1000000 \n"               // rom:ffdc1d30  0xE3550401 
      "    MOVLS   R8, R5 \n"                       // rom:ffdc1d34  0x91A08005 
      "    MOVHI   R8, #0x1000000 \n"               // rom:ffdc1d38  0x83A08401 
      "    BIC     R1, R0, #0xFF000000 \n"          // rom:ffdc1d3c  0xE3C014FF 
      "    CMP     R1, #0 \n"                       // rom:ffdc1d40  0xE3510000 
      "    BICNE   R0, R0, #0xFF000000 \n"          // rom:ffdc1d44  0x13C004FF 
      "    RSBNE   R0, R0, #0x1000000 \n"           // rom:ffdc1d48  0x12600401 
      "    CMPNE   R8, R0 \n"                       // rom:ffdc1d4c  0x11580000 
      "    MOVHI   R8, R0 \n"                       // rom:ffdc1d50  0x81A08000 
//mod start
      "LDR R0, =ignore_current_write\n"
      "LDR R0, [R0]\n"
      "CMP R0, #0\n"
      "MOVNE R0, R8\n" //"everything's written"
      "BNE loc_ffdc1d64\n" //jump past Write (in RAM, because there are jump targets before this location)
//mod end
      "    LDR     R0, [R9] \n"                     // rom:ffdc1d54  0xE5990000 
      "    MOV     R2, R8 \n" //nr of bytes to be written
      "    MOV     R1, R7 \n"                       // rom:ffdc1d5c  0xE1A01007 
      "    BL      sub_FFC13C08 \n" //Write
"loc_ffdc1d64:\n" //+
      "    LDR     R1, [R4, #4] \n"                 // rom:ffdc1d64  0xE5941004 
      "    CMP     R8, R0 \n"                       // rom:ffdc1d68  0xE1580000 
      "    ADD     R1, R1, R0 \n"                   // rom:ffdc1d6c  0xE0811000 
      "    STR     R1, [R4, #4] \n"                 // rom:ffdc1d70  0xE5841004 
      "    BEQ     loc_FFDC1D8C \n"                 // rom:ffdc1d74  0x0A000004 
      "    LDR     R0, =0x10B1 \n"                  // rom:ffdc1d78  0xE59F00E4 
      "    BL      sub_FFC5B7B0 \n"                 // rom:ffdc1d7c  0xEBFA668B 
      "    LDR     R1, =0x9200005 \n"               // rom:ffdc1d80  0xE59F10E0 
      "    STR     R1, [R4, #0x10] \n"              // rom:ffdc1d84  0xE5841010 
      "    B       loc_FFDC1D08 \n"                 // rom:ffdc1d88  0xEAFFFFDE 
"loc_FFDC1D8C:\n"
      "    SUB     R5, R5, R0 \n"                   // rom:ffdc1d8c  0xE0455000 
      "    CMP     R5, R6 \n"                       // rom:ffdc1d90  0xE1550006 
      "    ADD     R7, R7, R0 \n"                   // rom:ffdc1d94  0xE0877000 
      "    LDRCS   R1, =0x211 \n"                   // rom:ffdc1d98  0x259F10CC 
      "    LDRCS   R0, =0xFFDC1CA4 \n"              // rom:ffdc1d9c  0x224F0C01 
      "    BLCS    sub_FFC0BDB8 \n"                 // rom:ffdc1da0  0x2BF92804 
      "    CMP     R5, #0 \n"                       // rom:ffdc1da4  0xE3550000 
      "    BNE     loc_FFDC1D2C \n"                 // rom:ffdc1da8  0x1AFFFFDF 
      "    LDR     R0, [R4] \n"                     // rom:ffdc1dac  0xE5940000 
      "    MOV     R1, R4 \n"                       // rom:ffdc1db0  0xE1A01004 
      "    ADD     R0, R0, #1 \n"                   // rom:ffdc1db4  0xE2800001 
"loc_FFDC1DB8:\n"
      "    LDMFD   SP!, {R4-R10,LR} \n"             // rom:ffdc1db8  0xE8BD47F0 
      "    B       sub_FFDC183C \n"                 // rom:ffdc1dbc  0xEAFFFE9E
    );
}

void __attribute__((naked,noinline)) sub_FFDC1DC0_my(  ) {
asm volatile (
      "    STMFD   SP!, {R4,R5,LR} \n"              // rom:ffdc1dc0  0xE92D4030 
      "    LDR     R5, =0xC0C8 \n"                  // rom:ffdc1dc4  0xE51F5148 
      "    MOV     R4, R0 \n"                       // rom:ffdc1dc8  0xE1A04000 
      "    LDR     R0, [R5] \n"                     // rom:ffdc1dcc  0xE5950000 
      "    SUB     SP, SP, #0x1C \n"                // rom:ffdc1dd0  0xE24DD01C 
      "    CMN     R0, #1 \n"                       // rom:ffdc1dd4  0xE3700001 
      "    BEQ     loc_FFDC1DF4 \n"                 // rom:ffdc1dd8  0x0A000005 
//mod start
      "LDR R1, =ignore_current_write\n"
      "LDR R1, [R1]\n"
      "CMP R1, #0\n"
      "MOVNE R0, #0\n" //"close OK"
      "LDRNE R1, =ignore_current_write\n"
      "STRNE R0, [R1]\n" //also disarm flag
      "LDRNE PC, =0xffdc1de0\n" //jump past Close (in ROM)
//mod end
      "    BL      sub_FFC13B5C \n" //Close, has only one param (R0)
      "    CMP     R0, #0 \n" // rom:ffdc1de0
      "    LDRNE   R0, =0x9200003 \n"               // rom:ffdc1de4  0x159F0084 
      "    STRNE   R0, [R4, #0x10] \n"              // rom:ffdc1de8  0x15840010 
      "    MVN     R0, #0 \n"                       // rom:ffdc1dec  0xE3E00000 
      "    STR     R0, [R5] \n"                     // rom:ffdc1df0  0xE5850000 
"loc_FFDC1DF4:\n"
      "    LDR     R0, [R4, #0x10] \n"              // rom:ffdc1df4  0xE5940010 
      "LDR PC, =0xffdc1df8\n" //+ continue in ROM
/*      "    TST     R0, #1 \n"                       // rom:ffdc1df8  0xE3100001 
      "    BNE     loc_FFDC1E3C \n"                 // rom:ffdc1dfc  0x1A00000E 
      "    LDR     R0, =0x81FF \n"                  // rom:ffdc1e00  0xE59F006C 
      "    ADD     R1, SP, #4 \n"                   // rom:ffdc1e04  0xE28D1004 
      "    STR     R0, [SP, #4] \n"                 // rom:ffdc1e08  0xE58D0004 
      "    MOV     R0, #0x20 \n"                    // rom:ffdc1e0c  0xE3A00020 
      "    STR     R0, [SP, #8] \n"                 // rom:ffdc1e10  0xE58D0008 
      "    LDR     R0, [R4, #4] \n"                 // rom:ffdc1e14  0xE5940004 
      "    STR     R0, [SP, #0xC] \n"               // rom:ffdc1e18  0xE58D000C 
      "    LDR     R0, [R4, #0xC] \n"               // rom:ffdc1e1c  0xE594000C 
      "    STR     R0, [SP, #0x10] \n"              // rom:ffdc1e20  0xE58D0010 
      "    LDR     R0, [R4, #0xC] \n"               // rom:ffdc1e24  0xE594000C 
      "    STR     R0, [SP, #0x14] \n"              // rom:ffdc1e28  0xE58D0014 
      "    LDR     R0, [R4, #0xC] \n"               // rom:ffdc1e2c  0xE594000C 
      "    STR     R0, [SP, #0x18] \n"              // rom:ffdc1e30  0xE58D0018 
      "    ADD     R0, R4, #0x2C \n"                // rom:ffdc1e34  0xE284002C 
      "    BL      sub_FFC3E068 \n"                 // rom:ffdc1e38  0xEBF9F08A 
"loc_FFDC1E3C:\n"
      "    ADD     R0, R4, #0x2C \n"                // rom:ffdc1e3c  0xE284002C 
      "    BL      sub_FFC3CEF0 \n"                 // rom:ffdc1e40  0xEBF9EC2A 
      "    BL      sub_FFC3E7A4 \n"                 // rom:ffdc1e44  0xEBF9F256 
      "    LDR     R1, [R5, #0x14] \n"              // rom:ffdc1e48  0xE5951014 
      "    CMP     R1, #0 \n"                       // rom:ffdc1e4c  0xE3510000 
      "    LDRNE   R0, [R4, #0x10] \n"              // rom:ffdc1e50  0x15940010 
      "    BLXNE   R1 \n"                           // rom:ffdc1e54  0x112FFF31 
      "    ADD     SP, SP, #0x1C \n"                // rom:ffdc1e58  0xE28DD01C 
      "    LDMFD   SP!, {R4,R5,PC} \n"              // rom:ffdc1e5c  0xE8BD8030
*/
    );
}
