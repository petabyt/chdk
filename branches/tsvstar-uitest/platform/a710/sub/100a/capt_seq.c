#include "lolevel.h"
#include "platform.h"
#include "core.h"

static long *nrflag = (long*)0x621C;

#include "../../../generic/capt_seq.c"

void __attribute__((naked,noinline)) sub_FFD5F178_my(long p)
{
    asm volatile (
                "STMFD   SP!, {R4,LR}\n"
                "MOV     R4, R0\n"
                "SUB     SP, SP, #0xC\n"
                "BL      sub_FFD5FB34\n"
                "LDR     R1, =0xFFFFFFFF\n"
                "BL      sub_FFC103A4\n"
                "LDR     R0, =0x122\n"
                "ADD     R1, SP, #0x14-0x10\n"
                "MOV     R2, #4\n"
                "BL      sub_FFC14DEC\n"
                "TST     R0, #1\n"
                "BEQ     loc_FFD5F1B8\n"
                "LDR     R0, =0xFFD5EFF4\n"
                "MOV     R1, #0x1BC\n"
                "BL      sub_FFC03CF8\n"
"loc_FFD5F1B8:\n"
                "LDR     R3, =0x9CB20\n"
                "LDR     R2, =0x9CBE0\n"
                "LDR     R0, [R3,#0x78]\n"
                "LDRSH   R1, [R2,#0xE]\n"
                "BL      sub_FFC90768\n"
                "MOV     R0, R4\n"
                "BL      sub_FFD5EF78\n"
            "BL      wait_until_remote_button_is_released\n"
	    	"BL      capt_seq_hook_set_nr\n"
                "LDR     R3, =0x6220\n"
                "LDR     R0, [R3]\n"

		"B       sub_FFD5F1DC\n"
    );
}

void __attribute__((naked,noinline)) sub_FFD5C2C4_my(long p)
{
    asm volatile (
                "STMFD   SP!, {R4,LR}\n"
                "LDR     R4, [R0,#0xC]\n"
                "LDR     R3, [R4,#8]\n"
                "ORR     R3, R3, #1\n"
                "STR     R3, [R4,#8]\n"
                "MOV     R0, #0xC\n"
                "BL      sub_FFD6581C\n"
                "TST     R0, #1\n"
                "MOV     R2, R4\n"
                "MOV     R0, #2\n"
                "BEQ     loc_FFD5C30C\n"
                "LDR     R3, [R4,#8]\n"
                "SUB     R0, R0, #1\n"
                "ORR     R3, R3, #0x40000000\n"
                "MOV     R1, R0\n"
                "STR     R3, [R4,#8]\n"
                "LDMFD   SP!, {R4,LR}\n"
                "B       sub_FFD5AA1C\n"
"loc_FFD5C30C:\n"
                "BL      sub_FFEA6BEC\n"
                "BL      sub_FFD5CD8C\n"
                "MOV     R0, R4\n"
                "BL      sub_FFD5DD50\n"
                "TST     R0, #1\n"
                "MOV     R2, R4\n"
                "MOV     R1, #1\n"
                "BEQ     loc_FFD5C334\n"
                "LDMFD   SP!, {R4,LR}\n"
                "B       sub_FFD5AA1C\n"
"loc_FFD5C334:\n"
                "BL      sub_FFD9ADF8\n"
                "BL      sub_FFC14FE8\n"
                "STR     R0, [R4,#0x14]\n"
                "MOV     R0, R4\n"
                "BL      sub_FFD5F060\n"
                "BL      sub_FFD5F9C0\n"
                "MOV     R0, R4\n"
                "BL      sub_FFD5F178_my\n"
		"BL      capt_seq_hook_raw_here\n"
                "MOV     R1, #1\n"
                "MOV     R2, R4\n"
                "BL      sub_FFD5AA1C\n"
                "BL      sub_FFD5F4AC\n"
                "CMP     R0, #0\n"
                "LDRNE   R3, [R4,#8]\n"
                "ORRNE   R3, R3, #0x2000\n"
                "STRNE   R3, [R4,#8]\n"
                "LDMFD   SP!, {R4,PC}\n"
    );
}

void __attribute__((naked,noinline)) capt_seq_task()
{
	asm volatile (
                "STMFD   SP!, {R4,LR}\n"
                "SUB     SP, SP, #4\n"
                "MOV     R4, SP\n"
                "B       loc_FFD5C878\n"
"loc_FFD5C70C:\n"
                "LDR     R2, [SP,#0xC-0xC]\n"
                "LDR     R3, [R2]\n"
                "MOV     R0, R2\n"
                "CMP     R3, #0x16\n"
                "LDRLS   PC, [PC,R3,LSL#2]\n"
                "B       loc_FFD5C84C\n"
                ".long loc_FFD5C780\n"
                ".long loc_FFD5C78C\n"
                ".long loc_FFD5C794\n"
                ".long loc_FFD5C7A8\n"
                ".long loc_FFD5C7A0\n"
                ".long loc_FFD5C7B0\n"
                ".long loc_FFD5C7B8\n"
                ".long loc_FFD5C7C4\n"
                ".long loc_FFD5C7CC\n"
                ".long loc_FFD5C7D8\n"
                ".long loc_FFD5C7E0\n"
                ".long loc_FFD5C7E8\n"
                ".long loc_FFD5C7F0\n"
                ".long loc_FFD5C7F8\n"
                ".long loc_FFD5C800\n"
                ".long loc_FFD5C80C\n"
                ".long loc_FFD5C814\n"
                ".long loc_FFD5C81C\n"
                ".long loc_FFD5C824\n"
                ".long loc_FFD5C830\n"
                ".long loc_FFD5C83C\n"
                ".long loc_FFD5C844\n"
                ".long loc_FFD5C860\n"
"loc_FFD5C780:\n"
                "BL      sub_FFD5CDA0\n"
                "BL      shooting_expo_param_override\n"  // +
                "BL      sub_FFD5A518\n"
                "B       loc_FFD5C85C\n"
"loc_FFD5C78C:\n"
                "BL      sub_FFD5C2C4_my\n"
                "B       loc_FFD5C85C\n"
"loc_FFD5C794:\n"
                "MOV     R0, #1\n"
                "BL      sub_FFD5CF94\n"
                "B       loc_FFD5C85C\n"
"loc_FFD5C7A0:\n"
                "BL      sub_FFD5C96C\n"
                "B       loc_FFD5C85C\n"
"loc_FFD5C7A8:\n"
                "BL      sub_FFD5CD6C\n"
                "B       loc_FFD5C85C\n"
"loc_FFD5C7B0:\n"
                "BL      sub_FFD5CD7C\n"
                "B       loc_FFD5C85C\n"
"loc_FFD5C7B8:\n"
                "BL      sub_FFD5CE8C\n"
                "BL      sub_FFD5A518\n"
                "B       loc_FFD5C85C\n"
"loc_FFD5C7C4:\n"
                "BL      sub_FFD5C3D8\n"
                "B       loc_FFD5C85C\n"
"loc_FFD5C7CC:\n"
                "BL      sub_FFD5CEF4\n"
                "BL      sub_FFD5A518\n"
                "B       loc_FFD5C85C\n"
"loc_FFD5C7D8:\n"
                "BL      sub_FFD5CD6C\n"
                "B       loc_FFD5C85C\n"
"loc_FFD5C7E0:\n"
                "BL      sub_FFD5E444\n"
                "B       loc_FFD5C85C\n"
"loc_FFD5C7E8:\n"
                "BL      sub_FFD5E610\n"
                "B       loc_FFD5C85C\n"
"loc_FFD5C7F0:\n"
                "BL      sub_FFD5E6A4\n"
                "B       loc_FFD5C85C\n"
"loc_FFD5C7F8:\n"
                "BL      sub_FFD5E740\n"
                "B       loc_FFD5C85C\n"
"loc_FFD5C800:\n"
                "MOV     R0, #0\n"
                "BL      sub_FFD5E9AC\n"
                "B       loc_FFD5C85C\n"
"loc_FFD5C80C:\n"
                "BL      sub_FFD5EB64\n"
                "B       loc_FFD5C85C\n"
"loc_FFD5C814:\n"
                "BL      sub_FFD5EBF4\n"
                "B       loc_FFD5C85C\n"
"loc_FFD5C81C:\n"
                "BL      sub_FFD5ECAC\n"
                "B       loc_FFD5C85C\n"
"loc_FFD5C824:\n"
                "MOV     R0, #1\n"
                "BL      sub_FFD5E9AC\n"
                "B       loc_FFD5C85C\n"
"loc_FFD5C830:\n"
                "BL      sub_FFD5D0D0\n"
                "BL      sub_FFD5C1EC\n"
                "B       loc_FFD5C85C\n"
"loc_FFD5C83C:\n"
                "BL      sub_FFD5E880\n"
                "B       loc_FFD5C85C\n"
"loc_FFD5C844:\n"
                "BL      sub_FFD5E8D8\n"
                "B       loc_FFD5C85C\n"
"loc_FFD5C84C:\n"
                "MOV     R1, #0x4E0\n"
                "LDR     R0, =0xFFD5C048\n"
                "ADD     R1, R1, #9\n"
                "BL      sub_FFC03CF8\n"
"loc_FFD5C85C:\n"
                "LDR     R2, [SP,#0xC-0xC]\n"
"loc_FFD5C860:\n"
                "LDR     R3, =0x71C94\n"
                "LDR     R1, [R2,#4]\n"
                "LDR     R0, [R3]\n"
                "BL      sub_FFC10208\n"
                "LDR     R0, [SP,#0xC-0xC]\n"
                "BL      sub_FFD5C0C4\n"
"loc_FFD5C878:\n"
                "LDR     R3, =0x71C98\n"
                "MOV     R1, R4\n"
                "LDR     R0, [R3]\n"
                "MOV     R2, #0\n"
                "BL      sub_FFC10920\n"
                "TST     R0, #1\n"
                "BEQ     loc_FFD5C70C\n"
                "MOV     R1, #0x410\n"
                "LDR     R0, =0xFFD5C048\n"
                "ADD     R1, R1, #0xB\n"
                "BL      sub_FFC03CF8\n"
                "BL      sub_FFC11E7C\n"
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
                 "B       loc_FFD05950\n"
 "loc_FFD054A4:\n"
                 "CMP     R2, #0x22\n"
                 "BNE     loc_FFD054BC\n"
                 "LDR     R0, [R12,#0x8C]\n"
                 "MOV     LR, PC\n"
                 "LDR     PC, [R12,#0x88]\n"
                 "B       loc_FFD05520\n"
 "loc_FFD054BC:\n"
                 "CMP     R2, #0x1D\n"
                 "BNE     loc_FFD054D0\n"
                 "MOV     R0, R12\n"
                 "BL      sub_FFD05364\n"
                 "B       loc_FFD05510\n"
 "loc_FFD054D0:\n"
                 "CMP     R2, #0x1E\n"
                 "BNE     loc_FFD054E4\n"
                 "MOV     R0, R12\n"
                 "BL      sub_FFD053C0\n"
                 "B       loc_FFD05510\n"
 "loc_FFD054E4:\n"
                 "SUB     R3, R2, #0x1F\n"
                 "CMP     R3, #1\n"
                 "BHI     loc_FFD054FC\n"
                 "MOV     R0, R12\n"
                 "BL      sub_FFD0541C\n"
                 "B       loc_FFD05510\n"
 "loc_FFD054FC:\n"
                 "CMP     R2, #0x21\n"
                 "BNE     loc_FFD0552C\n"
                 "BL      sub_FFCA4380\n"
                 "BL      sub_FFCA7474\n"
                 "BL      sub_FFCA66AC\n"
 "loc_FFD05510:\n"
                 "LDR     R3, [SP,#4]\n"
                 "LDR     R0, [R3,#0x8C]\n"
                 "MOV     LR, PC\n"
                 "LDR     PC, [R3,#0x88]\n"
 "loc_FFD05520:\n"
                 "LDR     R0, [SP,#4]\n"
                 "BL      sub_FFD00F00\n"
                 "B       loc_FFD05950\n"
 "loc_FFD0552C:\n"
                 "CMP     R2, #0xD\n"
                 "MOV     R8, #1\n"
                 "BNE     loc_FFD0559C\n"
                 "LDR     R1, [R12,#0x7C]\n"
                 "ADD     R1, R1, R1,LSL#1\n"
                 "ADD     R1, R12, R1,LSL#2\n"
                 "ADD     R6, SP, #0x14\n"
                 "SUB     R1, R1, #8\n"
                 "MOV     R2, #0xC\n"
                 "MOV     R0, R6\n"
                 "BL      _memcpy\n"
                 "LDR     R0, [SP,#4]\n"
                 "BL      sub_FFD039DC\n"
                 "LDR     R3, [SP,#4]\n"
                 "LDR     R1, [R3,#0x7C]\n"
                 "LDR     R2, [R3,#0x8C]\n"
                 "ADD     R0, R3, #4\n"
                 "MOV     LR, PC\n"
                 "LDR     PC, [R3,#0x88]\n"
                 "LDR     R0, [SP,#4]\n"
                 "BL      sub_FFD03CAC\n"
                 "LDR     R3, [SP,#4]\n"
                 "ADD     R0, R3, #4\n"
                 "LDR     R1, [R3,#0x7C]\n"
                 "LDR     R2, [R3,#0x94]\n"
                 "MOV     LR, PC\n"
                 "LDR     PC, [R3,#0x90]\n"
                 "B       loc_FFD058EC\n"
 "loc_FFD0559C:\n"
                 "SUB     R3, R2, #0xE\n"
                 "CMP     R3, #1\n"
                 "BHI     loc_FFD05658\n"
                 "ADD     R6, SP, #0x14\n"
                 "ADD     R5, SP, #8\n"
                 "MOV     R0, R12\n"
                 "MOV     R1, R6\n"
                 "MOV     R2, R5\n"
                 "BL      sub_FFD03DA0\n"
                 "MOV     R4, R0\n"
                 "CMP     R4, #5\n"
                 "CMPNE   R4, #1\n"
                 "BNE     loc_FFD055F0\n"
                 "LDR     R12, [SP,#4]\n"
                 "MOV     R0, R5\n"
                 "LDR     R1, [R12,#0x7C]\n"
                 "MOV     R2, R4\n"
                 "LDR     R3, [R12,#0x8C]\n"
                 "MOV     LR, PC\n"
                 "LDR     PC, [R12,#0x88]\n"
                 "B       loc_FFD05628\n"
 "loc_FFD055F0:\n"
                 "CMP     R4, #6\n"
                 "CMPNE   R4, #2\n"
                 "BNE     loc_FFD05638\n"
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
                 "BL      sub_FFD04FD0\n"
 "loc_FFD05628:\n"
                 "MOV     R1, R4\n"
                 "LDR     R0, [SP,#4]\n"
                 "BL      sub_FFD052F8\n"
                 "B       loc_FFD058EC\n"
 "loc_FFD05638:\n"
                 "LDR     R12, [SP,#4]\n"
                 "MOV     R2, R4\n"
                 "ADD     R0, R12, #4\n"
                 "LDR     R1, [R12,#0x7C]\n"
                 "LDR     R3, [R12,#0x8C]\n"
                 "MOV     LR, PC\n"
                 "LDR     PC, [R12,#0x88]\n"
                 "B       loc_FFD058EC\n"
 "loc_FFD05658:\n"
                 "SUB     R3, R2, #0x19\n"
                 "CMP     R3, #1\n"
                 "BHI     loc_FFD056B0\n"
                 "LDR     R1, [R12,#0x7C]\n"
                 "ADD     R1, R1, R1,LSL#1\n"
                 "ADD     R1, R12, R1,LSL#2\n"
                 "ADD     R6, SP, #0x14\n"
                 "SUB     R1, R1, #8\n"
                 "MOV     R2, #0xC\n"
                 "MOV     R0, R6\n"
                 "BL      _memcpy\n"
                 "LDR     R0, [SP,#4]\n"
                 "BL      sub_FFD02DD4\n"
                 "LDR     R3, [SP,#4]\n"
                 "ADD     R0, R3, #4\n"
                 "LDR     R1, [R3,#0x7C]\n"
                 "LDR     R2, [R3,#0x8C]\n"
                 "MOV     LR, PC\n"
                 "LDR     PC, [R3,#0x88]\n"
                 "LDR     R0, [SP,#4]\n"
                 "BL      sub_FFD031B0\n"
                 "B       loc_FFD058EC\n"
 "loc_FFD056B0:\n"
                 "ADD     R6, SP, #0x14\n"
                 "ADD     R1, R12, #4\n"
                 "MOV     R2, #0xC\n"
                 "MOV     R0, R6\n"
                 "BL      memcpy\n"
                 "LDR     R12, [SP,#4]\n"
                 "LDR     R3, [R12]\n"
                 "MOV     R2, R12\n"
                 "CMP     R3, #0x1C\n"
                 "LDRLS   PC, [PC,R3,LSL#2]\n"
                 "B       loc_FFD058D8\n"
                 ".long loc_FFD05750\n"
                 ".long loc_FFD0575C\n"
                 ".long loc_FFD05768\n"
                 ".long loc_FFD05768\n"
                 ".long loc_FFD05750\n"
                 ".long loc_FFD0575C\n"
                 ".long loc_FFD05768\n"
                 ".long loc_FFD05768\n"
                 ".long loc_FFD0578C\n"
                 ".long loc_FFD0578C\n"
                 ".long loc_FFD058AC\n"
                 ".long loc_FFD058B8\n"
                 ".long loc_FFD058C8\n"
                 ".long loc_FFD058D8\n"
                 ".long loc_FFD058D8\n"
                 ".long loc_FFD058D8\n"
                 ".long loc_FFD05774\n"
                 ".long loc_FFD05780\n"
                 ".long loc_FFD0579C\n"
                 ".long loc_FFD057A8\n"
                 ".long loc_FFD057E0\n"
                 ".long loc_FFD05818\n"
                 ".long loc_FFD05850\n"
                 ".long loc_FFD05888\n"
                 ".long loc_FFD05888\n"
                 ".long loc_FFD058D8\n"
                 ".long loc_FFD058D8\n"
                 ".long loc_FFD05894\n"
                 ".long loc_FFD058A0\n"
 "loc_FFD05750:\n"
                 "MOV     R0, R2\n"
                 "BL      sub_FFD017B0\n"
                 "B       loc_FFD058D4\n"
 "loc_FFD0575C:\n"
                 "MOV     R0, R2\n"
                 "BL      sub_FFD01A54\n"
                 "B       loc_FFD058D4\n"
 "loc_FFD05768:\n"
                 "MOV     R0, R2\n"
                 "BL      sub_FFD01CC8\n"
                 "B       loc_FFD058D4\n"
 "loc_FFD05774:\n"
                 "MOV     R0, R2\n"
                 "BL      sub_FFD01FC4\n"
                 "B       loc_FFD058D4\n"
 "loc_FFD05780:\n"
                 "MOV     R0, R2\n"
                 "BL      sub_FFD02228\n"
                 "B       loc_FFD058D4\n"
 "loc_FFD0578C:\n"
                 "MOV     R0, R2\n"
                 "BL      sub_FFD02424_my\n"  //---------->
                 "MOV     R8, #0\n"
                 "B       loc_FFD058D4\n"
 "loc_FFD0579C:\n"
                 "MOV     R0, R2\n"
                 "BL      sub_FFD02580\n"
                 "B       loc_FFD058D4\n"
 "loc_FFD057A8:\n"
                 "LDRH    R1, [R2,#4]\n"
                 "LDR     R3, =0x4D750\n"
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
                 "BL      sub_FFD0287C\n"
                 "B       loc_FFD058D4\n"
 "loc_FFD057E0:\n"
                 "MOV     R0, R2\n"
                 "LDRH    R2, [R2,#4]\n"
                 "LDR     R3, =0x4D750\n"
                 "STRH    R2, [SP,#0x14]\n"
                 "LDRH    R2, [R3,#8]\n"
                 "STRH    R2, [SP,#0x1C]\n"
                 "LDRH    R1, [R3,#2]\n"
                 "STRH    R1, [SP,#0x16]\n"
                 "LDRH    R2, [R3,#4]\n"
                 "STRH    R2, [SP,#0x18]\n"
                 "LDRH    R3, [R3,#6]\n"
                 "STRH    R3, [SP,#0x1A]\n"
                 "BL      sub_FFD029A4\n"
                 "B       loc_FFD058D4\n"
 "loc_FFD05818:\n"
                 "LDR     R3, =0x4D750\n"
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
                 "BL      sub_FFD02A68\n"
                 "B       loc_FFD058D4\n"
 "loc_FFD05850:\n"
                 "LDR     R3, =0x4D750\n"
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
                 "BL      sub_FFD02B20\n"
                 "B       loc_FFD058D4\n"
 "loc_FFD05888:\n"
                 "MOV     R0, R2\n"
                 "BL      sub_FFD02BD0\n"
                 "B       loc_FFD058D4\n"
 "loc_FFD05894:\n"
                 "MOV     R0, R2\n"
                 "BL      sub_FFD03300\n"
                 "B       loc_FFD058D4\n"
 "loc_FFD058A0:\n"
                 "MOV     R0, R2\n"
                 "BL      sub_FFD034FC\n"
                 "B       loc_FFD058D4\n"
 "loc_FFD058AC:\n"
                 "MOV     R0, R2\n"
                 "BL      sub_FFD036B8\n"
                 "B       loc_FFD058D4\n"
 "loc_FFD058B8:\n"
                 "MOV     R0, R2\n"
                 "MOV     R1, #0\n"
                 "BL      sub_FFD0389C\n"
                 "B       loc_FFD058D4\n"
 "loc_FFD058C8:\n"
                 "MOV     R0, R2\n"
                 "MOV     R1, #1\n"
                 "BL      sub_FFD0389C\n"
 "loc_FFD058D4:\n"
                 "LDR     R12, [SP,#4]\n"
 "loc_FFD058D8:\n"
                 "ADD     R0, R12, #4\n"
                 "LDR     R1, [R12,#0x7C]\n"
                 "LDR     R2, [R12,#0x8C]\n"
                 "MOV     LR, PC\n"
                 "LDR     PC, [R12,#0x88]\n"
 "loc_FFD058EC:\n"
                 "CMP     R8, #1\n"
                 "BNE     loc_FFD05914\n"
                 "LDR     R1, [SP,#4]\n"
                 "LDR     R3, [R1,#0x7C]\n"
                 "ADD     R3, R3, R3,LSL#1\n"
                 "ADD     R1, R1, R3,LSL#2\n"
                 "MOV     R0, R6\n"
                 "SUB     R1, R1, #8\n"
                 "BL      sub_FFD01514\n"
                 "B       loc_FFD05948\n"
 "loc_FFD05914:\n"
                 "MOV     R4, #1\n"
                 "MOV     R0, R4\n"
                 "MOV     R1, R4\n"
                 "MOV     R2, R4\n"
                 "MOV     R3, R4\n"
                 "STR     R4, [SP]\n"
                 "BL      sub_FFD01468\n"
                 "MOV     R0, R4\n"
                 "MOV     R1, R0\n"
                 "MOV     R2, R0\n"
                 "MOV     R3, R0\n"
                 "STR     R4, [SP]\n"
                 "BL      sub_FFD015EC\n"
 "loc_FFD05948:\n"
                 "LDR     R0, [SP,#4]\n"
                 "BL      sub_FFD00F00\n"
 "loc_FFD05950:\n"
                 "LDR     R3, =0x4D748\n"
                 "MOV     R2, #0\n"
                 "LDR     R0, [R3]\n"
                 "MOV     R1, R7\n"
                 "BL      sub_FFC10920\n"
                 "LDR     R12, [SP,#4]\n"
                 "LDR     R2, [R12]\n"
                 "CMP     R2, #0x23\n"
                 "BNE     loc_FFD054A4\n"
                 "MOV     R0, R12\n"
                 "BL      sub_FFD00F00\n"
                 "LDR     R3, =0x4D744\n"
                 "MOV     R1, #1\n"
                 "LDR     R0, [R3]\n"
                 "BL      sub_FFC10208\n"
                 "BL      _ExitTask\n"
                 "ADD     SP, SP, #0x20\n"
                 "LDMFD   SP!, {R4-R8,PC}\n"
 );
}

                                        		
void __attribute__((naked,noinline)) sub_FFD02424_my(){
 asm volatile(
                 "STMFD   SP!, {R4-R6,LR}\n"
                 "LDR     R3, =0x4D744\n"
                 "MOV     R4, R0\n"
                 "MOV     R1, #0x3E\n"
                 "LDR     R0, [R3]\n"
                 "BL      sub_FFC103A4\n"
                 "MOV     R1, #0\n"
                 "LDRSH   R0, [R4,#4]\n"
                 "BL      sub_FFD01034\n"
                 "MOV     R6, R0\n"
                 "LDRSH   R0, [R4,#6]\n"
                 "BL      sub_FFD011A8\n"
                 "LDRSH   R0, [R4,#8]\n"
                 "BL      sub_FFD01244\n"
                 "LDRSH   R0, [R4,#0xA]\n"
                 "BL      sub_FFD012E0\n"
                 "LDRSH   R0, [R4,#0xC]\n"
                 "BL      sub_FFD0137C\n"
                 "LDR     R3, [R4]\n"
                 "CMP     R3, #9\n"
                 "MOV     R5, R0\n"
                 "MOVEQ   R5, #0\n"
                 "MOVEQ   R6, R5\n"
                 "CMP     R6, #1\n"
                 "BNE     loc_FFD024A8\n"
                 "MOV     R2, #2\n"
                 "LDRSH   R0, [R4,#4]\n"
                 "LDR     R1, =0xFFD00F54\n"
                 "BL      sub_FFE993F8\n"
                 "LDR     R2, =0x4D784\n"
                 "MOV     R3, #0\n"
                 "STR     R3, [R2]\n"
                 "B       loc_FFD024AC\n"
 "loc_FFD024A8:\n"
                 "BL      sub_FFD01418\n"
 "loc_FFD024AC:\n"
                 "STRH    R0, [R4,#4]\n"
                 "CMP     R5, #1\n"
                 "BNE     loc_FFD024CC\n"
                 "LDRSH   R0, [R4,#0xC]\n"
                 "LDR     R1, =0xFFD01018\n"
                 "MOV     R2, #0x20\n"
                 "BL      sub_FFD01750\n"
                 "B       loc_FFD024D0\n"
 "loc_FFD024CC:\n"
                 "BL      sub_FFD01458\n"
 "loc_FFD024D0:\n"
                 "STRH    R0, [R4,#0xC]\n"
                 "LDRSH   R0, [R4,#6]\n"
                 "BL      sub_FFCA4008_my\n"  // ------------->
                 "LDRSH   R0, [R4,#8]\n"
                 "MOV     R1, #1\n"
                 "BL      sub_FFCA626C\n"
                 "ADD     R0, R4, #8\n"
                 "MOV     R1, #0\n"
                 "BL      sub_FFCA632C\n"
                 "LDRSH   R0, [R4,#0xE]\n"
                 "BL      sub_FFCEEF80\n"
                 "CMP     R6, #1\n"
                 "BNE     loc_FFD02534\n"
                 "LDR     R3, =0x4D744\n"
                 "MOV     R2, #0xBB0\n"
                 "LDR     R0, [R3]\n"
                 "MOV     R1, #2\n"
                 "ADD     R2, R2, #8\n"
                 "BL      sub_FFC101F8\n"
                 "TST     R0, #1\n"
                 "BEQ     loc_FFD02534\n"
                 "MOV     R1, #0x440\n"
                 "LDR     R0, =0xFFD00EAC\n"
                 "ADD     R1, R1, #0xB\n"
                 "BL      sub_FFC03CF8\n"
 "loc_FFD02534:\n"
                 "CMP     R5, #1\n"
                 "LDMNEFD SP!, {R4-R6,PC}\n"
                 "LDR     R3, =0x4D744\n"
                 "MOV     R2, #0xBB0\n"
                 "LDR     R0, [R3]\n"
                 "MOV     R1, #0x20\n"
                 "ADD     R2, R2, #8\n"
                 "BL      sub_FFC101F8\n"
                 "TST     R0, #1\n"
                 "LDMEQFD SP!, {R4-R6,PC}\n"
                 "LDR     R0, =0xFFD00EAC\n"
                 "MOV     R1, #0x450\n"
                 "LDMFD   SP!, {R4-R6,LR}\n"
                 "B       sub_FFC03CF8\n"
 );
}

void __attribute__((naked,noinline)) sub_FFCA4008_my(){
 asm volatile(
                 "STMFD   SP!, {R4,LR}\n"
                 "LDR     R3, =0x52E0\n"
                 "LDR     R2, [R3]\n"
                 "MOV     R1, #0x150\n"
                 "MOV     R3, R0,LSL#16\n"
                 "CMP     R2, #1\n"
                 "ADD     R1, R1, #1\n"
                 "LDR     R0, =0xFFCA3844\n"
                 "MOV     R4, R3,ASR#16\n"
                 "BEQ     loc_FFCA4034\n"
                 "BL      sub_FFC03CF8\n"
 "loc_FFCA4034:\n"
                 "MOV     R1, #0x154\n"
                 "CMN     R4, #0xC00\n"
                 "LDR     R3, =0x3F066\n"
                 "LDR     R0, =0xFFCA3844\n"
                 "ADD     R1, R1, #3\n"
                 "LDREQSH R4, [R3]\n"
                 "LDRNE   R3, =0x3F066\n"
                 "CMN     R4, #0xC00\n"
                 "STRH    R4, [R3]\n"
                 "BNE     loc_FFCA4060\n"
                 "BL      sub_FFC03CF8\n"
 "loc_FFCA4060:\n"
                 "MOV     R0, R4\n"
                 "BL      apex2us\n"  //---------->
                 "MOV     R4, R0\n"
                 "BL      sub_FFCD020C\n"
                 "MOV     R0, R4\n"
                 "BL      sub_FFCA33D0\n"
                 "TST     R0, #1\n"
                 "MOV     R1, #0x15C\n"
                 "LDR     R0, =0xFFCA3844\n"
                 "LDMEQFD SP!, {R4,PC}\n"
                 "LDMFD   SP!, {R4,LR}\n"
                 "B       sub_FFC03CF8\n"
 );
}
