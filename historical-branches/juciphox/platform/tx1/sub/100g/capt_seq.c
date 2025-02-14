#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "conf.h"

#define RAWDATA_AVAILABLE (1)
#define RAWDATA_SAVED (2)

#define NR_ON (2)
#define NR_OFF (1)

static long raw_save_stage;

void capt_seq_hook_raw_here()
{
    raw_save_stage = RAWDATA_AVAILABLE;
    core_rawdata_available();
    while (raw_save_stage != RAWDATA_SAVED){
	_SleepTask(10);
    }
}

void hook_raw_save_complete()
{
    raw_save_stage = RAWDATA_SAVED;
}


void capt_seq_hook_set_nr()
{
    long *nrflag = (long*)0xD1B4; 

    switch (core_get_noise_reduction_value()){
    case NOISE_REDUCTION_AUTO_CANON:
	// leave it alone
	break;
    case NOISE_REDUCTION_OFF:
	*nrflag = 1;
	break;
    case NOISE_REDUCTION_ON:
	*nrflag = 2;
	break;
    };
}

void __attribute__((naked,noinline)) sub_FFB2E6FC_my(long p)
{
    asm volatile (
                "STMFD   SP!, {R4,LR}\n"
                "MOV     R4, R0\n"
                "SUB     SP, SP, #0xC\n"
                "BL      sub_FFB2F1C0\n"
                "MVN     R1, #0\n"
                "BL      sub_FFB40348\n" 
                "MOV     R0, #0x8A\n"
                "ADD     R1, SP, #4\n"
                "MOV     R2, #4\n"
                "BL      sub_FF81BD58\n"
                "TST     R0, #1\n"
                "BEQ     loc_FFB2E73C\n"
                "MOV     R1, #0x1D0\n"
                "LDR     R0, =0xFFB2E580\n" 
                "ADD     R1, R1, #2\n"
                "BL      sub_FFB4D970\n" 
"loc_FFB2E73C:\n"
                "LDR     R3, =0xB6FE0\n"
                "LDR     R2, =0xB70A0\n"
                "LDR     R0, [R3,#0x7C]\n"
                "LDRSH   R1, [R2,#0xE]\n"
                "BL      sub_FFA4D7B0\n"
                "MOV     R0, R4\n"
                "BL      sub_FFB2E504\n" 
                "BL      wait_until_remote_button_is_released\n"
                "BL      capt_seq_hook_set_nr\n" // +
                "B       sub_FFB2E758\n"
    );
}

void __attribute__((naked,noinline)) sub_FFB2B0D4_my(long p)
{
    asm volatile (
                "STMFD   SP!, {R4,R5,LR}\n"
                "LDR     R1, =0xB6FE0\n"
                "LDR     R4, [R0,#0xC]\n"
                "LDR     R2, [R1,#0x24]\n"
                "LDR     R3, [R4,#8]\n"
                "CMP     R2, #0\n"
                "ORR     R3, R3, #1\n"
                "STR     R3, [R4,#8]\n"
                "BNE     loc_FFB2B134\n"
                "LDR     R3, [R1,#0xC]\n"
                "CMP     R3, #0\n"
                "BNE     loc_FFB2B134\n"
                "MOV     R0, #0xC\n"
                "BL      sub_FFB36058\n"
                "TST     R0, #1\n"
                "BEQ     loc_FFB2B134\n"
                "LDR     R3, [R4,#8]\n"
                "MOV     R0, #1\n"
                "ORR     R3, R3, #0x40000000\n"
                "STR     R3, [R4,#8]\n"
"loc_FFB2B124:\n"
                "MOV     R2, R4\n"
                "MOV     R1, #1\n"
                "LDMFD   SP!, {R4,R5,LR}\n"
                "B       sub_FFB29294\n"
"loc_FFB2B134:\n"
                "LDR     R1, =0xB6FE0\n"
                "MOV     R3, #0x8200\n"
                "LDRH    R2, [R1]\n"
                "ADD     R3, R3, #0xA\n"
                "CMP     R2, R3\n"
                "BEQ     loc_FFB2B180\n"
                "LDRH    R3, [R1,#0x88]\n"
                "CMP     R3, #3\n"
                "BEQ     loc_FFB2B180\n"
                "LDR     R3, [R4,#0xC]\n"
                "CMP     R3, #1\n"
                "BLS     loc_FFB2B180\n"
                "LDRH    R3, [R1,#0x86]\n"
                "CMP     R3, #0\n"
                "BNE     loc_FFB2B180\n"
                "LDRH    R3, [R1,#0x82]\n"
                "CMP     R3, #2\n"
                "BNE     loc_FFB2B180\n"
                "BL      sub_FFB2C23C\n"
"loc_FFB2B180:\n"
                "LDR     R1, =0xB6FE0\n"
                "MOV     R3, #0x8200\n"
                "LDRH    R2, [R1]\n"
                "ADD     R3, R3, #0xA\n"
                "CMP     R2, R3\n"
                "BEQ     loc_FFB2B1C8\n"
                "LDRH    R3, [R1,#0x88]\n"
                "CMP     R3, #3\n"
                "BEQ     loc_FFB2B1C8\n"
                "LDR     R3, [R4,#0xC]\n"
                "CMP     R3, #1\n"
                "BLS     loc_FFB2B1C8\n"
                "LDRH    R3, [R1,#0x86]\n"
                "CMP     R3, #0\n"
                "BNE     loc_FFB2B1C8\n"
                "LDRH    R3, [R1,#0x82]\n"
                "CMP     R3, #2\n"
                "BEQ     loc_FFB2B230\n"
"loc_FFB2B1C8:\n"
                "LDR     R2, =0xB6FE0\n"
                "LDRH    R3, [R2,#0x88]\n"
                "CMP     R3, #3\n"
                "BEQ     loc_FFB2B248\n"
                "LDRH    R3, [R2,#0x86]\n"
                "CMP     R3, #0\n"
                "BNE     loc_FFB2B248\n"
                "LDRH    R1, [R2,#0x82]\n"
                "CMP     R1, #1\n"
                "BNE     loc_FFB2B248\n"
                "LDRH    R2, [R2]\n"
                "MOV     R3, #0x8200\n"
                "ADD     R3, R3, #0xA\n"
                "CMP     R2, R3\n"
                "BEQ     loc_FFB2B248\n"
                "LDR     R3, [R4,#0xC]\n"
                "CMP     R3, #1\n"
                "BLS     loc_FFB2B248\n"
                "ADD     R3, R1, #0xFF00\n"
                "ADD     R3, R3, #0xFF\n"
                "MOV     R3, R3,LSL#16\n"
                "CMP     R3, #0x10000\n"
                "BHI     loc_FFB2B248\n"
                "LDR     R3, [R4,#0x10]\n"
                "CMP     R3, #1\n"
                "BNE     loc_FFB2B248\n"
"loc_FFB2B230:\n"
                "LDR     R3, =0x920D8\n"
                "MOV     R2, #0xEA00\n"
                "LDR     R0, [R3]\n"
                "MOV     R1, #0x40000000\n"
                "ADD     R2, R2, #0x60\n"
                "BL      sub_FFB3650C\n"
"loc_FFB2B248:\n"
                "LDR     R5, =0xB6FE0\n"
                "BL      sub_FFB2AFB4\n"
                "LDR     R3, [R5,#0x24]\n"
                "CMP     R3, #0\n"
                "BNE     loc_FFB2B264\n"
                "MOV     R0, #2\n"
                "BL      sub_FFB057F8\n"
"loc_FFB2B264:\n"
                "BL      sub_FFB2BD98\n"  
                "LDR     R3, [R4,#0x18]\n"
                "CMP     R3, #0\n"
                "BEQ     loc_FFB2B278\n"
                "BL      sub_FFBAD0D0\n"
"loc_FFB2B278:\n"
                "LDR     R3, [R5,#0x24]\n"
                "CMP     R3, #0\n"
                "BNE     loc_FFB2B2B8\n"
                "MOV     R0, R4\n"
                "BL      sub_FFB2D080\n"
                "TST     R0, #1\n"
                "BNE     loc_FFB2B124\n"
                "BL      sub_FF826F90\n"
                "BL      sub_FF81BF54\n"
                "STR     R0, [R4,#0x14]\n"
                "MOV     R0, R4\n"
                "BL      sub_FFB2E5E4\n"
                "BL      sub_FFB2F02C\n"
                "MOV     R0, R4\n"
                "BL      sub_FFB2E6FC_my\n"         //-------------->
                "BL      capt_seq_hook_raw_here\n"  // +
                "B       loc_FFB2B2CC\n"
"loc_FFB2B2B8:\n"
                "LDR     R3, =0xD19C\n"
                "LDR     R2, [R3]\n"
                "CMP     R2, #0\n"
                "MOVNE   R0, #0x1D\n"
                "MOVEQ   R0, #0\n"
"loc_FFB2B2CC:\n"
                "MOV     R1, #1\n"
                "MOV     R2, R4\n"
                "BL      sub_FFB29294\n"
                "BL      sub_FFB2EACC\n"
                "CMP     R0, #0\n"
                "LDRNE   R3, [R4,#8]\n"
                "ORRNE   R3, R3, #0x2000\n"
                "STRNE   R3, [R4,#8]\n"
                "LDR     R3, [R4,#0x18]\n"
                "CMP     R3, #0\n"
                "BEQ     loc_FFB2B2FC\n"
                "BL      sub_FFBAD0FC\n"
"loc_FFB2B2FC:\n"
                "LDR     R2, =0xB6FE0\n"
                "LDRH    R3, [R2,#0x88]\n"
                "CMP     R3, #3\n"
                "LDMEQFD SP!, {R4,R5,PC}\n"
                "LDRH    R3, [R2,#0x86]\n"
                "CMP     R3, #0\n"
                "LDMNEFD SP!, {R4,R5,PC}\n"
                "LDRH    R3, [R2,#0x82]\n"
                "CMP     R3, #2\n"
                "LDMNEFD SP!, {R4,R5,PC}\n"
                "MOV     R0, R4\n"
                "LDMFD   SP!, {R4,R5,LR}\n"
                "B       sub_FFB2C294\n"
    );
}

void __attribute__((naked,noinline)) capt_seq_task()  // task_CaptSeqTask 0xFFB2B704
{
	asm volatile (
                "STMFD   SP!, {R4,LR}\n"
                "SUB     SP, SP, #4\n"
                "MOV     R4, SP\n"
                "B       loc_FFB2B8A4\n"
"loc_FFB2B714:\n"
                "LDR     R2, [SP]\n"
                "LDR     R3, [R2]\n"
                "MOV     R0, R2\n"
                "CMP     R3, #0x17\n"
                "LDRLS   PC, [PC,R3,LSL#2]\n"
                "B       loc_FFB2B87C\n"
                ".long loc_FFB2B78C\n"
                ".long loc_FFB2B7AC\n"
                ".long loc_FFB2B7C0\n"
                ".long loc_FFB2B7D4\n"
                ".long loc_FFB2B7CC\n"
                ".long loc_FFB2B7DC\n"
                ".long loc_FFB2B7E4\n"
                ".long loc_FFB2B7F0\n"
                ".long loc_FFB2B7F8\n"
                ".long loc_FFB2B804\n"
                ".long loc_FFB2B80C\n"
                ".long loc_FFB2B814\n"
                ".long loc_FFB2B81C\n"
                ".long loc_FFB2B824\n"
                ".long loc_FFB2B82C\n"
                ".long loc_FFB2B838\n"
                ".long loc_FFB2B840\n"
                ".long loc_FFB2B848\n"
                ".long loc_FFB2B850\n"
                ".long loc_FFB2B85C\n"
                ".long loc_FFB2B864\n"
                ".long loc_FFB2B86C\n"
                ".long loc_FFB2B874\n"
                ".long loc_FFB2B88C\n"

"loc_FFB2B78C:\n"
                "BL      sub_FFB2BDC0\n"
                "BL      shooting_expo_param_override\n"  // +
                "BL      sub_FFB28C78\n"
                "LDR     R3, =0xB6FE0\n"
                "LDR     R2, [R3,#0x24]\n"
                "CMP     R2, #0\n"
                "BEQ     loc_FFB2B888\n"
                "BL      sub_FFB2B33C\n"
                "B       loc_FFB2B888\n"
"loc_FFB2B7AC:\n"
                "BL      sub_FFB2B0D4_my\n"   //--------------->
"loc_FFB2B7B0:\n"
                "LDR     R2, =0xB6FE0\n"
                "MOV     R3, #0\n"
                "STR     R3, [R2,#0x24]\n"
                "B       loc_FFB2B888\n"
"loc_FFB2B7C0:\n"
                "MOV     R0, #1\n"
                "BL      sub_FFB2BFE0\n"
                "B       loc_FFB2B888\n"
"loc_FFB2B7CC:\n"
                "BL      sub_FFB2B990\n"
                "B       loc_FFB2B7B0\n"
"loc_FFB2B7D4:\n"
                "BL      sub_FFB2BD78\n"  
                "B       loc_FFB2B7B0\n"
"loc_FFB2B7DC:\n"
                "BL      sub_FFB2BD88\n"
                "B       loc_FFB2B888\n"
"loc_FFB2B7E4:\n"
                "BL      sub_FFB2BED8\n"
                "BL      sub_FFB28C78\n"
                "B       loc_FFB2B888\n"
"loc_FFB2B7F0:\n"
                "BL      sub_FFB2B414\n"
                "B       loc_FFB2B888\n"
"loc_FFB2B7F8:\n"
                "BL      sub_FFB2BF48\n"
                "BL      sub_FFB28C78\n"
                "B       loc_FFB2B888\n"
"loc_FFB2B804:\n"
                "BL      sub_FFB2BD78\n" 
                "B       loc_FFB2B888\n"
"loc_FFB2B80C:\n"
                "BL      sub_FFB2D89C\n"
                "B       loc_FFB2B888\n"
"loc_FFB2B814:\n"
                "BL      sub_FFB2DA70\n"
                "B       loc_FFB2B888\n"
"loc_FFB2B81C:\n"
                "BL      sub_FFB2DB04\n"
                "B       loc_FFB2B888\n"
"loc_FFB2B824:\n"
                "BL      sub_FFB2DC00\n"
                "B       loc_FFB2B888\n"
"loc_FFB2B82C:\n"
                "MOV     R0, #0\n"
                "BL      sub_FFB2DE6C\n"
                "B       loc_FFB2B888\n"
"loc_FFB2B838:\n"
                "BL      sub_FFB2E010\n"
                "B       loc_FFB2B888\n"
"loc_FFB2B840:\n"
                "BL      sub_FFB2E0AC\n"
                "B       loc_FFB2B888\n"
"loc_FFB2B848:\n"
                "BL      sub_FFB2E16C\n"
                "B       loc_FFB2B888\n"
"loc_FFB2B850:\n"
                "BL      sub_FFB2C160\n"
                "BL      sub_FFB2AE94\n"
                "B       loc_FFB2B888\n"
"loc_FFB2B85C:\n"
                "BL      sub_FFB2DD40\n"
                "B       loc_FFB2B888\n"
"loc_FFB2B864:\n"
                "BL      sub_FFB2DD9C\n"
                "B       loc_FFB2B888\n"
"loc_FFB2B86C:\n"
                "BL      sub_FFB2AFB4\n"
                "B       loc_FFB2B888\n"
"loc_FFB2B874:\n"
                "BL      sub_FFB2535C\n"
                "B       loc_FFB2B888\n"
"loc_FFB2B87C:\n"
                "LDR     R0, =0xFFB2ABD8\n"  
                "MOV     R1, #0x4D0\n"
                "BL      sub_FFB4D970\n" 
"loc_FFB2B888:\n"
                "LDR     R2, [SP]\n"
"loc_FFB2B88C:\n"
                "LDR     R3, =0x920D8\n"
                "LDR     R1, [R2,#4]\n"
                "LDR     R0, [R3]\n"
                "BL      sub_FFB401AC\n" 
                "LDR     R0, [SP]\n"
                "BL      sub_FFB2ACC8\n"
"loc_FFB2B8A4:\n"
                "LDR     R3, =0x920DC\n"
                "MOV     R1, R4\n"
                "LDR     R0, [R3]\n"
                "MOV     R2, #0\n"
                "BL      sub_FFB408C4\n" 
                "TST     R0, #1\n"
                "BEQ     loc_FFB2B714\n"
                "MOV     R1, #0x400\n"
                "LDR     R0, =0xFFB2ABD8\n" 
                "ADD     R1, R1, #2\n"
                "BL      sub_FFB4D970\n" 
                "BL      sub_FFB41E88\n"
                "ADD     SP, SP, #4\n"
                "LDMFD   SP!, {R4,PC}\n"
	);
}

