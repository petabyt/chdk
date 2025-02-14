#include "conf.h"

//int *video_quality = &conf.video_quality;
//int *video_mode    = &conf.video_mode;

void change_video_tables(int a, int b) {
    //int i;
    //for (i=0;i<24;i++) table[i]=(def_table[i]*a)/b;
}

// like other cameras
void  set_quality(int *x) { // -17 highest; +12 lowest
    if (conf.video_mode) *x=12-((conf.video_quality-1)*(12+17)/(99-1));
}

// ROM:FF96BD30 movie_record_task() aka. task_MovieRecord()
void __attribute__((naked,noinline)) movie_record_task() {
    asm volatile (
        "STMFD   SP!, {R2-R8,LR}\n"
        "LDR     R8, =0x4B2\n"
        "LDR     R7, =0x2710\n"
        "LDR     R4, =0x69D8\n"
        "MOV     R6, #0\n"
        "MOV     R5, #1\n"
        "loc_FF96BD48:\n"
        "LDR     R0, [R4,#0x1C]\n"
        "MOV     R2, #0\n"
        "ADD     R1, SP, #4\n"
        "BL      sub_FF83994C\n"             // LOCATION: KerQueue.c:0
        "LDR     R0, [R4,#0x24]\n"
        "CMP     R0, #0\n"
        "BNE     loc_FF96BE24\n"
        "LDR     R0, [SP,#4]\n"
        "LDR     R1, [R0]\n"
        "SUB     R1, R1, #2\n"
        "CMP     R1, #9\n"
        "ADDLS   PC, PC, R1,LSL#2\n"
        "B       loc_FF96BE24\n"
        "loc_FF96BD7C:\n"
        "B       loc_FF96BDD4\n"
        "loc_FF96BD80:\n"
        "B       loc_FF96BDF8\n"
        "loc_FF96BD84:\n"
        "B       loc_FF96BE08\n"
        "loc_FF96BD88:\n"
        "B       loc_FF96BE10\n"
        "loc_FF96BD8C:\n"
        "B       loc_FF96BDDC\n"
        "loc_FF96BD90:\n"
        "B       loc_FF96BE18\n"
        "loc_FF96BD94:\n"
        "B       loc_FF96BDE8\n"
        "loc_FF96BD98:\n"
        "B       loc_FF96BE24\n"
        "loc_FF96BD9C:\n"
        "B       loc_FF96BE20\n"
        "loc_FF96BDA0:\n"
        "B       loc_FF96BDA4\n"
        "loc_FF96BDA4:\n"                        // jumptable FF96BD74 entry 9
        "LDR     R0, =0xFF96B414\n"
        "STR     R6, [R4,#0x38]\n"
        "STR     R0, [R4,#0xA8]\n"
        //"ADR     R0, =0xFF96BA00\n"
        //"LDR     R0, =0xFF96BA00\n"         // compiler does not like ADR
        "LDR     R0, =sub_FF96BA00_my\n"      // +
        "STR     R0, [R4,#0xAC]\n"
        "LDR     R0, =0xFF96AD2C\n"
        "LDR     R2, =0xFF96AC48\n"
        "LDR     R1, =0x983CC\n"
        "STR     R6, [R4,#0x28]\n"
        "BL      sub_FF8511CC\n"
        "STR     R5, [R4,#0x3C]\n"
        "B       loc_FF96BE24\n"
        "loc_FF96BDD4:\n"                        // jumptable FF96BD74 entry 0
        //"BL      unlock_optical_zoom\n"    // not needed because canon firmware allow zoom
        "BL      sub_FF96B83C\n"             // MovieRecorder.c
        "B       loc_FF96BE24\n"
        "loc_FF96BDDC:\n"                        // jumptable FF96BD74 entry 4
        "LDR     R1, [R4,#0xAC]\n"
        "BLX     R1\n"
        "B       loc_FF96BE24\n"
        "loc_FF96BDE8:\n"                        // jumptable FF96BD74 entry 6
        "LDR     R1, [R0,#0x18]\n"
        "LDR     R0, [R0,#4]\n"
        "BL      sub_FFAB0524\n"             // LOCATION: MovWriter.c:0
        "B       loc_FF96BE24\n"
        "loc_FF96BDF8:\n"                        // jumptable FF96BD74 entry 1
        "LDR     R0, [R4,#0x3C]\n"
        "CMP     R0, #5\n"
        "STRNE   R5, [R4,#0x2C]\n"
        "B       loc_FF96BE24\n"
        "loc_FF96BE08:\n"                        // jumptable FF96BD74 entry 2
        "BL      sub_FF96B0EC\n"             // MovieRecorder.c 1000
        "B       loc_FF96BE24\n"
        "loc_FF96BE10:\n"                        // jumptable FF96BD74 entry 3
        "BL      sub_FF96AD78\n"             // MovieRecorder.c 0\n"
        "B       loc_FF96BE24\n"
        "loc_FF96BE18:\n"                        // jumptable FF96BD74 entry 5
        "BL      sub_FF96ABD4\n"             // MovieRecorder.c 100
        "B       loc_FF96BE24\n"
        "loc_FF96BE20:\n"                        // jumptable FF96BD74 entry 8
        "BL      sub_FF96BF8C\n"             // MovieRecorder.c 100
        "loc_FF96BE24:\n"                        // jumptable FF96BD74 default entry, jumptable FF96BD74 entry 7
        "LDR     R1, [SP,#4]\n"
        "LDR     R3, =0xFF96AA5C\n"          // "MovieRecorder.c"
        "STR     R6, [R1]\n"
        "STR     R8, [SP]\n"
        "LDR     R0, [R4,#0x20]\n"
        "MOV     R2, R7\n"
        "BL      sub_FF83A2A0\n"
        "B       loc_FF96BD48\n"
    );
}

void __attribute__((naked,noinline)) sub_FF96BA00_my() {
    asm volatile (
        "STMFD   SP!, {R4-R8,LR}\n"
        "SUB     SP, SP, #0x40\n"
        "MOV     R7, #0\n"
        "LDR     R6, =0x69D8\n"
        "MOV     R4, R0\n"
        "STR     R7, [SP,#0x30]\n"
        "STR     R7, [SP,#0x28]\n"
        "LDR     R0, [R6,#0x3C]\n"
        "CMP     R0, #3\n"
        "MOVEQ   R0, #4\n"
        "STREQ   R0, [R6,#0x3C]\n"
        "LDR     R0, [R6,#0xA8]\n"
        "BLX     R0\n"
        "LDR     R0, [R6,#0x3C]\n"
        "CMP     R0, #4\n"
        "BNE     loc_FF96BB20\n"
        "ADD     R3, SP, #0x28\n"
        "ADD     R2, SP, #0x2C\n"
        "ADD     R1, SP, #0x30\n"
        "ADD     R0, SP, #0x34\n"
        "BL      sub_FFAB0628\n"             // LOCATION: MovWriter.c:0
        "CMP     R0, #0\n"
        "MOV     R5, #1\n"
        "BNE     loc_FF96BA7C\n"
        "LDR     R1, [R6,#0x2C]\n"
        "CMP     R1, #1\n"
        "BNE     loc_FF96BB28\n"
        "LDR     R1, [R6,#0x60]\n"
        "LDR     R2, [R6,#0x40]\n"
        "CMP     R1, R2\n"
        "BCC     loc_FF96BB28\n"
        "loc_FF96BA7C:\n"
        "BL      sub_FF96B4E8\n"
        "BL      sub_FF96C06C\n"
        "LDR     R0, [R4,#0x1C]\n"
        "ADD     R4, SP, #0x18\n"
        "ADD     R3, SP, #0x38\n"
        "MVN     R2, #1\n"
        "MOV     R1, #0\n"
        "STMIA   R4, {R0-R3}\n"
        "ADD     R1, SP, #0x3C\n"
        "ADD     R4, SP, #8\n"
        "MOV     R0, #0\n"
        "LDRD    R2, [R6,#0x78]\n"
        "STMIA   R4, {R0-R3}\n"
        "MOV     R3, #0\n"
        "MOV     R2, #0x40\n"
        "STRD    R2, [SP]\n"
        "LDR     R3, =0x98418\n"
        "MOV     R2, #0\n"
        "MOV     R1, #0\n"
        "BL      sub_FFA6746C\n"
        "LDR     R0, [R6,#0x14]\n"
        "LDR     R1, [R6,#0x58]\n"
        "BL      sub_FF839D68\n"             // eventproc_export_TakeSemaphore(), LOCATION: KerSem.c:0
        "CMP     R0, #9\n"
        "BNE     loc_FF96BAF0\n"
        "loc_FF96BAE0:\n"
        "BL      sub_FFAB0E48\n"
        "MOV     R0, #1\n"
        "STR     R5, [R6,#0x3C]\n"
        "B       loc_FF96BC48\n"
        "loc_FF96BAF0:\n"
        "LDR     R0, [SP,#0x38]\n"
        "CMP     R0, #0\n"
        "BEQ     loc_FF96BB0C\n"
        "loc_FF96BAFC:\n"
        "BL      sub_FFAB0E48\n"
        "MOV     R0, #1\n"
        "STR     R5, [R6,#0x3C]\n"
        "B       loc_FF96BC78\n"
        "loc_FF96BB0C:\n"
        "MOV     R0, #1\n"
        "BL      sub_FFA67510\n"
        "BL      sub_FFA6756C\n"
        "MOV     R0, #5\n"
        "STR     R0, [R6,#0x3C]\n"
        "loc_FF96BB20:\n"
        "ADD     SP, SP, #0x40\n"
        "LDMFD   SP!, {R4-R8,PC}\n"
        "loc_FF96BB28:\n"
        "LDR     R12, [SP,#0x30]\n"
        "CMP     R12, #0\n"
        "BEQ     loc_FF96BCD8\n"
        "STR     R5, [R6,#0x30]\n"
        "LDR     R0, [R6,#0x60]\n"
        "LDR     R8, [R4,#0xC]\n"
        "CMP     R0, #0\n"
        "LDRNE   LR, [SP,#0x34]\n"
        "BNE     loc_FF96BBD0\n"
        "LDR     R0, [R4,#0x1C]\n"
        "LDR     R1, [R4,#0x20]\n"
        "ADD     R3, SP, #0x38\n"
        "MVN     R2, #0\n"
        "ADD     LR, SP, #0x18\n"
        "STMIA   LR, {R0-R3}\n"
        "LDRD    R2, [R6,#0x78]\n"
        "LDR     R0, [SP,#0x28]\n"
        "ADD     R1, SP, #0x3C\n"
        "ADD     LR, SP, #8\n"
        "STMIA   LR, {R0-R3}\n"
        "LDR     R3, [SP,#0x2C]\n"
        "STR     R12, [SP]\n"
        "STR     R3, [SP,#4]\n"
        "LDMIB   R4, {R0,R1}\n"
        "LDR     R3, [SP,#0x34]\n"
        "MOV     R2, R8\n"
        "BL      sub_FFA6746C\n"
        "LDR     R0, [R6,#0x14]\n"
        "LDR     R1, [R6,#0x58]\n"
        "BL      sub_FF839D68\n"             // eventproc_export_TakeSemaphore(), LOCATION: KerSem.c:0
        "CMP     R0, #9\n"
        "BEQ     loc_FF96BAE0\n"
        "LDR     R0, [SP,#0x38]\n"
        "CMP     R0, #0\n"
        "BNE     loc_FF96BAFC\n"
        "MOV     R0, #1\n"
        "BL      sub_FFA67510\n"
        "LDR     R0, [SP,#0x3C]\n"
        "LDR     R1, [SP,#0x34]\n"
        "ADD     LR, R1, R0\n"
        "LDR     R1, [SP,#0x30]\n"
        "SUB     R12, R1, R0\n"
        "loc_FF96BBD0:\n"
        "LDR     R2, [R6,#0x5C]\n"
        "LDR     R0, [R4,#0x1C]\n"
        "LDR     R1, [R4,#0x20]\n"
        "ADD     R3, SP, #0x38\n"
        "STR     R1, [SP,#0x1C]\n"
        "STR     R3, [SP,#0x24]\n"
        "STR     R2, [SP,#0x20]\n"
        "STR     R0, [SP,#0x18]\n"
        "LDRD    R2, [R6,#0x78]\n"
        "LDR     R0, [SP,#0x28]\n"
        "STR     R3, [SP,#0x14]\n"
        "LDR     R3, [SP,#0x2C]\n"
        "ADD     R1, SP, #0x3C\n"
        "STR     R2, [SP,#0x10]\n"
        "STR     R3, [SP,#4]\n"
        "STR     R1, [SP,#0xC]\n"
        "STR     R12, [SP]\n"
        "STR     R0, [SP,#8]\n"
        "LDMIB   R4, {R0,R1}\n"
        "MOV     R3, LR\n"
        "MOV     R2, R8\n"
        "BL      sub_FFA6746C\n"
        "LDR     R0, [R6,#0x14]\n"
        "LDR     R1, [R6,#0x58]\n"
        "BL      sub_FF839D68\n"             // eventproc_export_TakeSemaphore(), LOCATION: KerSem.c:0
        "CMP     R0, #9\n"
        "BNE     loc_FF96BC60\n"
        "BL      sub_FFAB0E48\n"
        "MOV     R0, #0\n"
        "STR     R5, [R6,#0x3C]\n"
        "loc_FF96BC48:\n"
        "BL      sub_FFA67510\n"
        "BL      sub_FFA6756C\n"
        "MOV     R0, #0xC\n"
        "BL      sub_FF88A11C\n"             // LOCATION: ExMemMan.c:0
        "MOV     R0, #0x90000\n"
        "B       loc_FF96BC8C\n"
        "loc_FF96BC60:\n"
        "LDR     R0, [SP,#0x38]\n"
        "CMP     R0, #0\n"
        "BEQ     loc_FF96BCA0\n"
        "BL      sub_FFAB0E48\n"
        "MOV     R0, #0\n"
        "STR     R5, [R6,#0x3C]\n"
        "loc_FF96BC78:\n"
        "BL      sub_FFA67510\n"
        "BL      sub_FFA6756C\n"
        "MOV     R0, #0xC\n"
        "BL      sub_FF88A11C\n"             // LOCATION: ExMemMan.c:0
        "MOV     R0, #0xA0000\n"
        "loc_FF96BC8C:\n"
        "BL      sub_FF895E1C\n"             // eventproc_export_HardwareDefect()
        "LDR     R1, [R6,#0x98]!\n"
        "LDR     R0, [R6,#0xC]\n"
        "BLX     R1\n"
        "B       loc_FF96BB20\n"
        "loc_FF96BCA0:\n"
        "MOV     R0, #0\n"
        "BL      sub_FFA67510\n"
        "LDR     R0, [SP,#0x34]\n"
        "LDR     R1, [SP,#0x3C]\n"
        "BL      sub_FFAB0854\n"             // LOCATION: MovWriter.c:0
        "LDR     R0, [R6,#0x5C]\n"
        "LDR     R3, =0x6A54\n"              // <---
        "ADD     R1, R0, #1\n"
        "STR     R1, [R6,#0x5C]\n"
        "STR     R3, [SP]\n"
        "LDR     R0, [SP,#0x3C]\n"
        "SUB     R3, R3, #4\n"              // <---
        "MOV     R2, #0xF\n"
        "BL      sub_FFAAE908\n"

        "LDR     R0, =0x6A54-4\n"           // +
        "BL      set_quality\n"             // +

        "loc_FF96BCD8:\n"
        "LDR     R0, [R6,#0x60]\n"
        "ADD     R0, R0, #1\n"
        "STR     R0, [R6,#0x60]\n"
        "LDR     R1, [R6,#0x4C]\n"
        "MUL     R0, R1, R0\n"
        "LDR     R1, [R6,#0x48]\n"
        "BL      sub_FFB5BF88\n"
        "MOV     R4, R0\n"
        "BL      sub_FFAB0E80\n"
        "LDR     R1, [R6,#0x80]\n"
        "CMP     R1, R4\n"
        "BNE     loc_FF96BD14\n"
        "LDR     R0, [R6,#0x34]\n"
        "CMP     R0, #1\n"
        "BNE     loc_FF96BD28\n"
        "loc_FF96BD14:\n"
        "LDR     R1, [R6,#0x8C]\n"
        "MOV     R0, R4\n"
        "BLX     R1\n"
        "STR     R4, [R6,#0x80]\n"
        "STR     R7, [R6,#0x34]\n"
        "loc_FF96BD28:\n"
        "STR     R7, [R6,#0x30]\n"
        "B       loc_FF96BB20\n"
    );
}
