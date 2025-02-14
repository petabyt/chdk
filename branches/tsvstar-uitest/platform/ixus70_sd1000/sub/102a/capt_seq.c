#include "lolevel.h"
#include "platform.h"
#include "core.h"

static long *nrflag = (long*)0xCDA0;

#include "../../../generic/capt_seq.c"

void __attribute__((naked,noinline)) sub_FFB01EB0_my(long p)
{
    asm volatile (
                "STMFD   SP!, {R4,LR}\n"
                "MOV     R4, R0\n"
                "SUB     SP, SP, #0xC\n"
                "BL      sub_FFB02920\n"
//              "MOVL    R1, 0xFFFFFFFF\n"
                "MVN     R1, #0\n"
                "BL      sub_FFB13090\n" //ClearEventFlag
                "MOV     R0, #0x8A\n"
                "ADD     R1, SP, #4\n"
                "MOV     R2, #4\n"
                "BL      sub_FF81BC98\n"
                "TST     R0, #1\n"
                "BEQ     loc_FFB01EF0\n"
                "MOV     R1, #0x1D0\n"
                "LDR     R0, =0xFFB01D34\n" //aSscaptureseq_c
                "ADD     R1, R1, #2\n"
                "BL      sub_FFB2071C\n" //DebugAssert
"loc_FFB01EF0:\n"                           
                "LDR     R3, =0xBDA80\n"
                "LDR     R2, =0xBDB40\n"
                "LDR     R0, [R3,#0x7C]\n"
                "LDRSH   R1, [R2,#0xE]\n"
                "BL      sub_FFA395F0\n"
                "MOV     R0, R4\n"
                "BL      sub_FFB01CB8\n"
                "BL      wait_until_remote_button_is_released\n"
                "BL      capt_seq_hook_set_nr\n" // +
                "LDR     R3, =0xCDA4\n"
                "LDR     R0, [R3]\n"

                "B       sub_FFB01F14\n"  // ---> jump to end of function in ROM
    );
}

void __attribute__((naked,noinline)) sub_FFAFECD8_my(long p)
{
    asm volatile (
                "STMFD   SP!, {R4,R5,LR}\n"
                "LDR     R3, =0xBDA80\n"
                "LDR     R5, [R0,#0xC]\n"
                "LDR     R1, [R3,#0x24]\n"
                "LDR     R2, [R5,#8]\n"
                "CMP     R1, #0\n"
                "ORR     R2, R2, #1\n"
                "STR     R2, [R5,#8]\n"
                "BNE     loc_FFAFED2C\n"
                "MOV     R0, #0xC\n"
                "BL      sub_FFB09228\n"
                "TST     R0, #1\n"
                "BEQ     loc_FFAFED2C\n"
                "LDR     R3, [R5,#8]\n"
                "MOV     R0, #1\n"
                "ORR     R3, R3, #0x40000000\n"
                "STR     R3, [R5,#8]\n"
"loc_FFAFED1C:\n"                           
                "MOV     R2, R5\n"
                "MOV     R1, #1\n"
                "LDMFD   SP!, {R4,R5,LR}\n"
                "B       sub_FFAFD480\n"
 "loc_FFAFED2C:\n"                           
                "LDR     R4, =0xBDA80\n"
                "BL      sub_FFAFF7D0\n" //Set_CMD25Write_61
                "LDR     R3, [R4,#0x24]\n"
                "CMP     R3, #0\n"
                "BNE     loc_FFAFED74\n"
                "MOV     R0, R5\n"
                "BL      sub_FFB009B4\n"
                "TST     R0, #1\n"
                "BNE     loc_FFAFED1C\n"
                "BL      sub_FF8261B8\n"
                "BL      sub_FF81BE94\n"
                "STR     R0, [R5,#0x14]\n"
                "MOV     R0, R5\n"
                "BL      sub_FFB01D98\n"
                "BL      sub_FFB0278C\n"
                "MOV     R0, R5\n"
                "BL      sub_FFB01EB0_my\n"  //---------->
                "BL      capt_seq_hook_raw_here\n"  // +
                "B       loc_FFAFED88\n"
"loc_FFAFED74:\n"
                "LDR     R3, =0xCD8C\n"
                "LDR     R2, [R3]\n"
                "CMP     R2, #0\n"
                "MOVNE   R0, #0x1D\n"
                "MOVEQ   R0, #0\n"
"loc_FFAFED88:\n"
                "MOV     R1, #1\n"
                "MOV     R2, R5\n"
                "BL      sub_FFAFD480\n"
                "BL      sub_FFB0222C\n"
                "CMP     R0, #0\n"
                "LDRNE   R3, [R5,#8]\n"
                "ORRNE   R3, R3, #0x2000\n"
                "STRNE   R3, [R5,#8]\n"
                "LDMFD   SP!, {R4,R5,PC}\n"
    );
}

void __attribute__((naked,noinline)) capt_seq_task()
{
	asm volatile (
                "STMFD   SP!, {R4,LR}\n"
                "SUB     SP, SP, #4\n"
                "MOV     R4, SP\n"
                "B       loc_FFAFF310\n"
"loc_FFAFF194:\n"                           
                "LDR     R2, [SP]\n"
                "LDR     R3, [R2]\n"
                "MOV     R0, R2\n"
                "CMP     R3, #0x15\n"
                "LDRLS   PC, [PC,R3,LSL#2]\n"
                "B       loc_FFAFF2E4\n"
                ".long loc_FFAFF204\n"
                ".long loc_FFAFF224\n"
                ".long loc_FFAFF238\n"
                ".long loc_FFAFF24C\n"
                ".long loc_FFAFF244\n"
                ".long loc_FFAFF254\n"
                ".long loc_FFAFF25C\n"
                ".long loc_FFAFF268\n"
                ".long loc_FFAFF270\n"
                ".long loc_FFAFF27C\n"
                ".long loc_FFAFF284\n"
                ".long loc_FFAFF28C\n"
                ".long loc_FFAFF294\n"
                ".long loc_FFAFF29C\n"
                ".long loc_FFAFF2A4\n"
                ".long loc_FFAFF2B0\n"
                ".long loc_FFAFF2B8\n"
                ".long loc_FFAFF2C0\n"
                ".long loc_FFAFF2C8\n"
                ".long loc_FFAFF2D4\n"
                ".long loc_FFAFF2DC\n"
                ".long loc_FFAFF2F8\n"
"loc_FFAFF204:\n"                           
                                        
                "BL      sub_FFAFF7F8\n"
                "BL      shooting_expo_param_override\n"   // +
                "BL      sub_FFAFCF08\n"
                "LDR     R3, =0xBDA80\n"
                "LDR     R2, [R3,#0x24]\n"
                "CMP     R2, #0\n"
                "BEQ     loc_FFAFF2F4\n"
                "BL      sub_FFAFEDB4\n"
                "B       loc_FFAFF2F4\n"
"loc_FFAFF224:\n"                           
                                        
                "BL      sub_FFAFECD8_my\n"  //--------->

"loc_FFAFF228:\n"                           
                "LDR     R2, =0xBDA80\n"                       
                "MOV     R3, #0\n"
                "STR     R3, [R2,#0x24]\n"
                "B       loc_FFAFF2F4\n"
"loc_FFAFF238:\n"                           
                "MOV     R0, #1\n"                        
                "BL      sub_FFAFFA18\n" //jumptable case 2
                "B       loc_FFAFF2F4\n"
"loc_FFAFF244:\n"                           
                "BL      sub_FFAFF3F8\n" //jumptable case 4
                "B       loc_FFAFF228\n"
"loc_FFAFF24C:\n"                           
                "BL      sub_FFAFF7B0\n" //BackLightDrv_LcdBackLightOff_15
                "B       loc_FFAFF228\n"
"loc_FFAFF254:\n"                           
                "BL      sub_FFAFF7C0\n" //jumptable case 5
                "B       loc_FFAFF2F4\n"
"loc_FFAFF25C:\n"                           
                "BL      sub_FFAFF910\n" //jumptable case 6                        
                "BL      sub_FFAFCF08\n"
                "B       loc_FFAFF2F4\n"
"loc_FFAFF268:\n"                           
                "BL      sub_FFAFEE90\n" //jumptable case 7
                "B       loc_FFAFF2F4\n"
"loc_FFAFF270:\n"                           
                "BL      sub_FFAFF980\n" //jumptable case 8                        
                "BL      sub_FFAFCF08\n"
                "B       loc_FFAFF2F4\n"
"loc_FFAFF27C:\n"                           
                "BL      sub_FFAFF7B0\n" //BackLightDrv_LcdBackLightOff_15
                "B       loc_FFAFF2F4\n"
"loc_FFAFF284:\n"                           
                "BL      sub_FFB010E8\n" //jumptable case 10
                "B       loc_FFAFF2F4\n"
"loc_FFAFF28C:\n"                           
                "BL      sub_FFB012BC\n" //jumptable case 11
                "B       loc_FFAFF2F4\n"
"loc_FFAFF294:\n"                           
                "BL      sub_FFB01350\n" //jumptable case 12
                "B       loc_FFAFF2F4\n"
"loc_FFAFF29C:\n"                           
                "BL      sub_FFB0144C\n" //jumptable case 13
                "B       loc_FFAFF2F4\n"
"loc_FFAFF2A4:\n"                           
                "MOV     R0, #0\n"                        
                "BL      sub_FFB016B8\n" //jumptable case 14
                "B       loc_FFAFF2F4\n"
"loc_FFAFF2B0:\n"                           
                "BL      sub_FFB0188C\n" //jumptable case 15
                "B       loc_FFAFF2F4\n"
"loc_FFAFF2B8:\n"                           
                "BL      sub_FFB01928\n" //jumptable case 16
                "B       loc_FFAFF2F4\n"
"loc_FFAFF2C0:\n"                           
                "BL      sub_FFB019E8\n" //jumptable case 17
                "B       loc_FFAFF2F4\n"
"loc_FFAFF2C8:\n"                           
                "BL      sub_FFAFFB6C\n" //jumptable case 18                        
                "BL      sub_FFAFEBFC\n"
                "B       loc_FFAFF2F4\n"
"loc_FFAFF2D4:\n"                           
                "BL      sub_FFB0158C\n" //jumptable case 19
                "B       loc_FFAFF2F4\n"
"loc_FFAFF2DC:\n" 
                "BL      sub_FFB015E8\n" //jumptable case 20
                "B       loc_FFAFF2F4\n"
"loc_FFAFF2E4:\n"                         
                "MOV     R1, #0x4C0\n"
                "LDR     R0, =0xFFAFEA58\n" //aSsshoottask_c
                "ADD     R1, R1, #0xE\n"
                "BL      sub_FFB2071C\n" //DebugAssert
"loc_FFAFF2F4:\n"                           
                "LDR     R2, [SP]\n"
"loc_FFAFF2F8:\n"                           
                "LDR     R3, =0x97348\n" //jumptable case 21
                "LDR     R1, [R2,#4]\n"
                "LDR     R0, [R3]\n"
                "BL      sub_FFB12EF4\n" //SetEventFlag
                "LDR     R0, [SP]\n"
                "BL      sub_FFAFEAD8\n"
"loc_FFAFF310:\n"                           
                "LDR     R3, =0x9734C\n"
                "MOV     R1, R4\n"
                "LDR     R0, [R3]\n"
                "MOV     R2, #0\n"
                "BL      sub_FFB1360C\n" //ReceiveMessageQueue
                "TST     R0, #1\n"
                "BEQ     loc_FFAFF194\n"
                "LDR     R0, =0xFFAFEA58\n" //aSsshoottask_c
                "MOV     R1, #0x400\n"
                "BL      sub_FFB2071C\n" //DebugAssert
                "BL      sub_FFB14BD0\n"
                "ADD     SP, SP, #4\n"
                "LDMFD   SP!, {R4,PC}\n"
	);
}


/*************************************************************/
void __attribute__((naked,noinline)) exp_drv_task(){
 asm volatile(
                 "STMFD   SP!, {R4-R8,LR}\n"
                 "SUB     SP, SP, #0x20\n"
                 "ADD     R7, SP, #4\n"
                 "B       loc_FF96AD00\n"
 "loc_FF96A800:\n"
                 "CMP     R2, #0x22\n"
                 "BNE     loc_FF96A818\n"
                 "LDR     R0, [R12,#0x8C]\n"
                 "MOV     LR, PC\n"
                 "LDR     PC, [R12,#0x88]\n"
                 "B       loc_FF96A87C\n"
 "loc_FF96A818:\n"
                 "CMP     R2, #0x1D\n"
                 "BNE     loc_FF96A82C\n"
                 "MOV     R0, R12\n"
                 "BL      sub_FF96A6C0\n"
                 "B       loc_FF96A86C\n"
 "loc_FF96A82C:\n"
                 "CMP     R2, #0x1E\n"
                 "BNE     loc_FF96A840\n"
                 "MOV     R0, R12\n"
                 "BL      sub_FF96A71C\n"
                 "B       loc_FF96A86C\n"
 "loc_FF96A840:\n"
                 "SUB     R3, R2, #0x1F\n"
                 "CMP     R3, #1\n"
                 "BHI     loc_FF96A858\n"
                 "MOV     R0, R12\n"
                 "BL      sub_FF96A778\n"
                 "B       loc_FF96A86C\n"
 "loc_FF96A858:\n"
                 "CMP     R2, #0x21\n"
                 "BNE     loc_FF96A888\n"
                 "BL      sub_FF93087C\n"
                 "BL      sub_FF9339B4\n"
                 "BL      sub_FF932BEC\n"
 "loc_FF96A86C:\n"
                 "LDR     R3, [SP,#4]\n"
                 "LDR     R0, [R3,#0x8C]\n"
                 "MOV     LR, PC\n"
                 "LDR     PC, [R3,#0x88]\n"
 "loc_FF96A87C:\n"
                 "LDR     R0, [SP,#4]\n"
                 "BL      sub_FF9661BC\n"
                 "B       loc_FF96AD00\n"
 "loc_FF96A888:\n"
                 "CMP     R2, #0xD\n"
                 "MOV     R8, #1\n"
                 "BNE     loc_FF96A8F8\n"
                 "LDR     R1, [R12,#0x7C]\n"
                 "ADD     R1, R1, R1,LSL#1\n"
                 "ADD     R1, R12, R1,LSL#2\n"
                 "ADD     R6, SP, #0x14\n"
                 "SUB     R1, R1, #8\n"
                 "MOV     R2, #0xC\n"
                 "MOV     R0, R6\n"
                 "BL      sub_FF9183F4\n" //memcpy
                 "LDR     R0, [SP,#4]\n"
                 "BL      sub_FF968C6C\n"
                 "LDR     R3, [SP,#4]\n"
                 "LDR     R1, [R3,#0x7C]\n"
                 "LDR     R2, [R3,#0x8C]\n"
                 "ADD     R0, R3, #4\n"
                 "MOV     LR, PC\n"
                 "LDR     PC, [R3,#0x88]\n"
                 "LDR     R0, [SP,#4]\n"
                 "BL      sub_FF968F3C\n"
                 "LDR     R3, [SP,#4]\n"
                 "ADD     R0, R3, #4\n"
                 "LDR     R1, [R3,#0x7C]\n"
                 "LDR     R2, [R3,#0x94]\n"
                 "MOV     LR, PC\n"
                 "LDR     PC, [R3,#0x90]\n"
                 "B       loc_FF96AC48\n"
 "loc_FF96A8F8:\n"
                 "SUB     R3, R2, #0xE\n"
                 "CMP     R3, #1\n"
                 "BHI     loc_FF96A9B4\n"
                 "ADD     R6, SP, #0x14\n"
                 "ADD     R5, SP, #8\n"
                 "MOV     R0, R12\n"
                 "MOV     R1, R6\n"
                 "MOV     R2, R5\n"
                 "BL      sub_FF969030\n"
                 "MOV     R4, R0\n"
                 "CMP     R4, #5\n"
                 "CMPNE   R4, #1\n"
                 "BNE     loc_FF96A94C\n"
                 "LDR     R12, [SP,#4]\n"
                 "MOV     R0, R5\n"
                 "LDR     R1, [R12,#0x7C]\n"
                 "MOV     R2, R4\n"
                 "LDR     R3, [R12,#0x8C]\n"
                 "MOV     LR, PC\n"
                 "LDR     PC, [R12,#0x88]\n"
                 "B       loc_FF96A984\n"
 "loc_FF96A94C:\n"
                 "CMP     R4, #6\n"
                 "CMPNE   R4, #2\n"
                 "BNE     loc_FF96A994\n"
                 "LDR     R12, [SP,#4]\n"
                 "MOV     R0, R5\n"
                 "MOV     R1, R8\n"
                 "MOV     R2, R4\n"
                 "LDR     R3, [R12,#0x8C]\n"
                 "MOV     LR, PC\n"
                 "LDR     PC, [R12,#0x88]\n"
                 "MOV     R1, R6\n"
                 "LDR     R0, [SP,#4]\n"
                 "MOV     R2, R5\n"
                 "BL      sub_FF96A2F0\n"
 "loc_FF96A984:\n"
                 "MOV     R1, R4\n"
                 "LDR     R0, [SP,#4]\n"
                 "BL      sub_FF96A654\n"
                 "B       loc_FF96AC48\n"
 "loc_FF96A994:\n"
                 "LDR     R12, [SP,#4]\n"
                 "MOV     R2, R4\n"
                 "ADD     R0, R12, #4\n"
                 "LDR     R1, [R12,#0x7C]\n"
                 "LDR     R3, [R12,#0x8C]\n"
                 "MOV     LR, PC\n"
                 "LDR     PC, [R12,#0x88]\n"
                 "B       loc_FF96AC48\n"
 "loc_FF96A9B4:\n"
                 "SUB     R3, R2, #0x19\n"
                 "CMP     R3, #1\n"
                 "BHI     loc_FF96AA0C\n"
                 "LDR     R1, [R12,#0x7C]\n"
                 "ADD     R1, R1, R1,LSL#1\n"
                 "ADD     R1, R12, R1,LSL#2\n"
                 "ADD     R6, SP, #0x14\n"
                 "SUB     R1, R1, #8\n"
                 "MOV     R2, #0xC\n"
                 "MOV     R0, R6\n"
                 "BL      sub_FF9183F4\n" //memcpy
                 "LDR     R0, [SP,#4]\n"
                 "BL      sub_FF968120\n"
                 "LDR     R3, [SP,#4]\n"
                 "ADD     R0, R3, #4\n"
                 "LDR     R1, [R3,#0x7C]\n"
                 "LDR     R2, [R3,#0x8C]\n"
                 "MOV     LR, PC\n"
                 "LDR     PC, [R3,#0x88]\n"
                 "LDR     R0, [SP,#4]\n"
                 "BL      sub_FF968440\n"
                 "B       loc_FF96AC48\n"
 "loc_FF96AA0C:\n"
                 "ADD     R6, SP, #0x14\n"
                 "ADD     R1, R12, #4\n"
                 "MOV     R2, #0xC\n"
                 "MOV     R0, R6\n"
                 "BL      sub_FF9183F4\n" //memcpy
                 "LDR     R12, [SP,#4]\n"
                 "LDR     R3, [R12]\n"
                 "MOV     R2, R12\n"
                 "CMP     R3, #0x1C\n"
                 "LDRLS   PC, [PC,R3,LSL#2]\n"
                 "B       loc_FF96AC34\n"
                 ".long loc_FF96AAAC\n" //jump table for switch statement
                 ".long loc_FF96AAB8\n"
                 ".long loc_FF96AAC4\n"
                 ".long loc_FF96AAC4\n"
                 ".long loc_FF96AAAC\n"
                 ".long loc_FF96AAB8\n"
                 ".long loc_FF96AAC4\n"
                 ".long loc_FF96AAC4\n"
                 ".long loc_FF96AAE8\n"
                 ".long loc_FF96AAE8\n"
                 ".long loc_FF96AC08\n"
                 ".long loc_FF96AC14\n"
                 ".long loc_FF96AC24\n"
                 ".long loc_FF96AC34\n"
                 ".long loc_FF96AC34\n"
                 ".long loc_FF96AC34\n"
                 ".long loc_FF96AAD0\n"
                 ".long loc_FF96AADC\n"
                 ".long loc_FF96AAF8\n"
                 ".long loc_FF96AB04\n"
                 ".long loc_FF96AB3C\n"
                 ".long loc_FF96AB74\n"
                 ".long loc_FF96ABAC\n"
                 ".long loc_FF96ABE4\n"
                 ".long loc_FF96ABE4\n"
                 ".long loc_FF96AC34\n"
                 ".long loc_FF96AC34\n"
                 ".long loc_FF96ABF0\n"
                 ".long loc_FF96ABFC\n"
 "loc_FF96AAAC:\n"
                 "MOV     R0, R2\n"
                 "BL      sub_FF966B1C\n"
                 "B       loc_FF96AC30\n"
 "loc_FF96AAB8:\n"
                 "MOV     R0, R2\n"
                 "BL      sub_FF966DC0\n"
                 "B       loc_FF96AC30\n"
 "loc_FF96AAC4:\n"
                 "MOV     R0, R2\n"
                 "BL      sub_FF967034\n"
                 "B       loc_FF96AC30\n"
 "loc_FF96AAD0:\n"
                 "MOV     R0, R2\n"
                 "BL      sub_FF967330\n"
                 "B       loc_FF96AC30\n"
 "loc_FF96AADC:\n"
                 "MOV     R0, R2\n"
                 "BL      sub_FF967598\n"
                 "B       loc_FF96AC30\n"
 "loc_FF96AAE8:\n"
                 "MOV     R0, R2\n"
                 "BL      sub_FF967798_my\n"  //------------->
                 "MOV     R8, #0\n"
                 "B       loc_FF96AC30\n"
 "loc_FF96AAF8:\n"
                 "MOV     R0, R2\n"
                 "BL      sub_FF9678F8\n"
                 "B       loc_FF96AC30\n"
 "loc_FF96AB04:\n"
                 "LDRH    R1, [R2,#4]\n"
                 "LDR     R3, =0x2C298\n"
                 "STRH    R1, [SP,#0x14]\n"
                 "LDRH    R1, [R3,#6]\n"
                 "STRH    R1, [SP,#0x1A]\n"
                 "LDRH    R1, [R3,#2]\n"
                 "STRH    R1, [SP,#0x16]\n"
                 "LDRH    R3, [R3,#4]\n"
                 "STRH    R3, [SP,#0x18]\n"
                 "MOV     R0, R2\n"
                 "LDRH    R2, [R2,#0xC]\n"
                 "STRH    R2, [SP,#0x1C]\n"
                 "BL      sub_FF967BF0\n"
                 "B       loc_FF96AC30\n"
 "loc_FF96AB3C:\n"
                 "MOV     R0, R2\n"
                 "LDRH    R2, [R2,#4]\n"
                 "LDR     R3, =0x2C298\n"
                 "STRH    R2, [SP,#0x14]\n"
                 "LDRH    R2, [R3,#8]\n"
                 "STRH    R2, [SP,#0x1C]\n"
                 "LDRH    R1, [R3,#2]\n"
                 "STRH    R1, [SP,#0x16]\n"
                 "LDRH    R2, [R3,#4]\n"
                 "STRH    R2, [SP,#0x18]\n"
                 "LDRH    R3, [R3,#6]\n"
                 "STRH    R3, [SP,#0x1A]\n"
                 "BL      sub_FF967D18\n"
                 "B       loc_FF96AC30\n"
 "loc_FF96AB74:\n"
                 "LDR     R3, =0x2C298\n"
                 "LDRH    R1, [R3]\n"
                 "STRH    R1, [SP,#0x14]\n"
                 "MOV     R0, R2\n"
                 "LDRH    R2, [R2,#6]\n"
                 "STRH    R2, [SP,#0x16]\n"
                 "LDRH    R2, [R3,#8]\n"
                 "STRH    R2, [SP,#0x1C]\n"
                 "LDRH    R1, [R3,#4]\n"
                 "STRH    R1, [SP,#0x18]\n"
                 "LDRH    R3, [R3,#6]\n"
                 "STRH    R3, [SP,#0x1A]\n"
                 "BL      sub_FF967DDC\n"
                 "B       loc_FF96AC30\n"
 "loc_FF96ABAC:\n"
                 "LDR     R3, =0x2C298\n"
                 "LDRH    R1, [R3,#6]\n"
                 "STRH    R1, [SP,#0x1A]\n"
                 "LDRH    R1, [R3]\n"
                 "STRH    R1, [SP,#0x14]\n"
                 "LDRH    R1, [R3,#2]\n"
                 "STRH    R1, [SP,#0x16]\n"
                 "LDRH    R3, [R3,#4]\n"
                 "STRH    R3, [SP,#0x18]\n"
                 "MOV     R0, R2\n"
                 "LDRH    R2, [R2,#0xC]\n"
                 "STRH    R2, [SP,#0x1C]\n"
                 "BL      sub_FF967E94\n"
                 "B       loc_FF96AC30\n"
 "loc_FF96ABE4:\n"
                 "MOV     R0, R2\n"
                 "BL      sub_FF967F44\n"
                 "B       loc_FF96AC30\n"
 "loc_FF96ABF0:\n"
                 "MOV     R0, R2\n"
                 "BL      sub_FF96858C\n"
                 "B       loc_FF96AC30\n"
 "loc_FF96ABFC:\n"
                 "MOV     R0, R2\n"
                 "BL      sub_FF968788\n"
                 "B       loc_FF96AC30\n"
 "loc_FF96AC08:\n"
                 "MOV     R0, R2\n"
                 "BL      sub_FF968944\n"
                 "B       loc_FF96AC30\n"
 "loc_FF96AC14:\n"
                 "MOV     R0, R2\n"
                 "MOV     R1, #0\n"
                 "BL      sub_FF968B2C\n"
                 "B       loc_FF96AC30\n"
 "loc_FF96AC24:\n"
                 "MOV     R0, R2\n"
                 "MOV     R1, #1\n"
                 "BL      sub_FF968B2C\n"
 "loc_FF96AC30:\n"
                 "LDR     R12, [SP,#4]\n"
 "loc_FF96AC34:\n"
                 "ADD     R0, R12, #4\n"
                 "LDR     R1, [R12,#0x7C]\n"
                 "LDR     R2, [R12,#0x8C]\n"
                 "MOV     LR, PC\n"
                 "LDR     PC, [R12,#0x88]\n"
 "loc_FF96AC48:\n"
                 "CMP     R8, #1\n"
                 "BNE     loc_FF96AC70\n"
                 "LDR     R1, [SP,#4]\n"
                 "LDR     R3, [R1,#0x7C]\n"
                 "ADD     R3, R3, R3,LSL#1\n"
                 "ADD     R1, R1, R3,LSL#2\n"
                 "MOV     R0, R6\n"
                 "SUB     R1, R1, #8\n"
                 "BL      sub_FF9667D4\n"
                 "B       loc_FF96ACEC\n"
 "loc_FF96AC70:\n"
                 "LDR     R3, [SP,#4]\n"
                 "LDR     R2, [R3]\n"
                 "CMP     R2, #9\n"
                 "BNE     loc_FF96ACB8\n"
                 "MOV     R4, #0\n"
                 "MOV     R1, #1\n"
                 "MOV     R2, R1\n"
                 "MOV     R3, R1\n"
                 "MOV     R0, R4\n"
                 "STR     R4, [SP]\n"
                 "BL      sub_FF966718\n"
                 "MOV     R1, #1\n"
                 "MOV     R0, R4\n"
                 "MOV     R2, R1\n"
                 "MOV     R3, R1\n"
                 "STR     R4, [SP]\n"
                 "BL      sub_FF966970\n"
                 "B       loc_FF96ACEC\n"
 "loc_FF96ACB8:\n"
                 "MOV     R4, #1\n"
                 "MOV     R0, R4\n"
                 "MOV     R1, R4\n"
                 "MOV     R2, R4\n"
                 "MOV     R3, R4\n"
                 "STR     R4, [SP]\n"
                 "BL      sub_FF966718\n"
                 "MOV     R0, R4\n"
                 "MOV     R1, R0\n"
                 "MOV     R2, R0\n"
                 "MOV     R3, R0\n"
                 "STR     R4, [SP]\n"
                 "BL      sub_FF966970\n"
 "loc_FF96ACEC:\n"
                 "LDR     R2, =0x2C2E4\n"
                 "MOV     R3, #0\n"
                 "LDR     R0, [SP,#4]\n"
                 "STR     R3, [R2]\n"
                 "BL      sub_FF9661BC\n"
 "loc_FF96AD00:\n"
                 "LDR     R3, =0x2C28C\n"
                 "MOV     R2, #0\n"
                 "LDR     R0, [R3]\n"
                 "MOV     R1, R7\n"
                 "BL      sub_FFB1360C\n" //ReceiveMessageQueue
                 "LDR     R12, [SP,#4]\n"
                 "LDR     R2, [R12]\n"
                 "CMP     R2, #0x23\n"
                 "BNE     loc_FF96A800\n"
                 "MOV     R0, R12\n"
                 "BL      sub_FF9661BC\n"
                 "LDR     R3, =0x2C288\n"
                 "MOV     R1, #1\n"
                 "LDR     R0, [R3]\n"
                 "BL      sub_FFB12EF4\n" //SetEventFlag
                 "BL      sub_FFB14BD0\n"
                 "ADD     SP, SP, #0x20\n"
                 "LDMFD   SP!, {R4-R8,PC}\n"
 );
}

void __attribute__((naked,noinline)) sub_FF967798_my(){
 asm volatile(
                 "STMFD   SP!, {R4-R6,LR}\n"
                 "LDR     R3, =0x2C288\n"
                 "MOV     R4, R0\n"
                 "MOV     R1, #0x3E\n"
                 "LDR     R0, [R3]\n"
                 "BL      sub_FFB13090\n" //ClearEventFlag
                 "MOV     R1, #0\n"
                 "LDRSH   R0, [R4,#4]\n"
                 "BL      sub_FF9662F0\n"
                 "MOV     R6, R0\n"
                 "LDRSH   R0, [R4,#6]\n"
                 "BL      sub_FF966458\n"
                 "LDRSH   R0, [R4,#8]\n"
                 "BL      sub_FF9664F4\n"
                 "LDRSH   R0, [R4,#0xA]\n"
                 "BL      sub_FF966590\n"
                 "LDRSH   R0, [R4,#0xC]\n"
                 "BL      sub_FF96662C\n"
                 "LDR     R3, [R4]\n"
                 "CMP     R3, #9\n"
                 "MOV     R5, R0\n"
                 "MOVEQ   R5, #0\n"
                 "MOVEQ   R6, R5\n"
                 "CMP     R6, #1\n"
                 "BNE     loc_FF96781C\n"
                 "MOV     R2, #2\n"
                 "LDRSH   R0, [R4,#4]\n"
                 "LDR     R1, =0xFF966210\n"
                 "BL      sub_FFAD9644\n"
                 "LDR     R2, =0x2C2D8\n"
                 "MOV     R3, #0\n"
                 "STR     R3, [R2]\n"
                 "B       loc_FF967820\n"
 "loc_FF96781C:\n"
                 "BL      sub_FF9666C8\n"
 "loc_FF967820:\n"
                 "STRH    R0, [R4,#4]\n"
                 "CMP     R5, #1\n"
                 "BNE     loc_FF967840\n"
                 "LDRSH   R0, [R4,#0xC]\n"
                 "LDR     R1, =0xFF9662D4\n"
                 "MOV     R2, #0x20\n"
                 "BL      sub_FF966ABC\n"
                 "B       loc_FF967844\n"
 "loc_FF967840:\n"
                 "BL      sub_FF966708\n"
 "loc_FF967844:\n"
                 "STRH    R0, [R4,#0xC]\n"
                 "LDRSH   R0, [R4,#6]\n"
                 "BL      sub_FF9304F8_my\n"  //------------>
                 "LDRSH   R0, [R4,#8]\n"
                 "MOV     R1, #1\n"
                 "BL      sub_FF9327AC\n"
                 "ADD     R0, R4, #8\n"
                 "MOV     R1, #0\n"
                 "BL      sub_FF93286C\n"
                 "LDRSH   R0, [R4,#0xE]\n"
                 "BL      sub_FF954890\n"
                 "CMP     R6, #1\n"
                 "BNE     loc_FF9678A8\n"
                 "LDR     R3, =0x2C288\n"
                 "MOV     R2, #0xBB0\n"
                 "LDR     R0, [R3]\n"
                 "MOV     R1, #2\n"
                 "ADD     R2, R2, #8\n"
                 "BL      sub_FFB12EE4\n"
                 "TST     R0, #1\n"
                 "BEQ     loc_FF9678A8\n"
                 "MOV     R1, #0x4A0\n"
                 "LDR     R0, =0xFF966168\n" //aExpdrv_c
                 "ADD     R1, R1, #3\n"
                 "BL      sub_FFB2071C\n" //DebugAssert
 "loc_FF9678A8:\n"
                 "CMP     R5, #1\n"
                 "LDMNEFD SP!, {R4-R6,PC}\n"
                 "LDR     R3, =0x2C288\n"
                 "MOV     R2, #0xBB0\n"
                 "LDR     R0, [R3]\n"
                 "MOV     R1, #0x20\n"
                 "ADD     R2, R2, #8\n"
                 "BL      sub_FFB12EE4\n"
                 "TST     R0, #1\n"
                 "LDMEQFD SP!, {R4-R6,PC}\n"
                 "MOV     R1, #0x4A0\n"
                 "LDR     R0, =0xFF966168\n" //aExpdrv_c
                 "ADD     R1, R1, #8\n"
                 "LDMFD   SP!, {R4-R6,LR}\n"
                 "B       sub_FFB2071C\n" //DebugAssert
 );
}


void __attribute__((naked,noinline)) sub_FF9304F8_my(){
 asm volatile(
                 "STMFD   SP!, {R4,LR}\n"
                 "LDR     R3, =0x63E4\n"
                 "LDR     R2, [R3]\n"
                 "MOV     R1, #0x168\n"
                 "MOV     R3, R0,LSL#16\n"
                 "CMP     R2, #1\n"
                 "ADD     R1, R1, #3\n"
                 "LDR     R0, =0xFF92FD14\n" //aShutter_c
                 "MOV     R4, R3,ASR#16\n"
                 "BEQ     loc_FF930524\n"
                 "BL      sub_FFB2071C\n" //DebugAssert
 "loc_FF930524:\n"
                 "MOV     R1, #0x170\n"
                 "CMN     R4, #0xC00\n"
                 "LDR     R3, =0x12E16\n"
                 "LDR     R0, =0xFF92FD14\n" //aShutter_c
                 "ADD     R1, R1, #1\n"
                 "LDREQSH R4, [R3]\n"
                 "LDRNE   R3, =0x12E16\n"
                 "CMN     R4, #0xC00\n"
                 "STRH    R4, [R3]\n"
                 "BNE     loc_FF930550\n"
                 "BL      sub_FFB2071C\n" //DebugAssert
 "loc_FF930550:\n"
                 "MOV     R0, R4\n"
             //  "BL      sub_FF931648\n"  // -
                 "BL      apex2us\n"       // +
                 "MOV     R4, R0\n"
                 "BL      sub_FF9BCB6C\n"
                 "MOV     R0, R4\n"
                 "BL      sub_FF9D6534\n"
                 "MOV     R1, #0x174\n"
                 "TST     R0, #1\n"
                 "ADD     R1, R1, #2\n"
                 "LDR     R0, =0xFF92FD14\n" //aShutter_c
                 "LDMEQFD SP!, {R4,PC}\n"
                 "LDMFD   SP!, {R4,LR}\n"
                 "B       sub_FFB2071C\n" //DebugAssert
 );
}
