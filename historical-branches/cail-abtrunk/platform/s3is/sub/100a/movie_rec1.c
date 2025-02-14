#include "conf.h"

long CompressionRateTable[]={0x54, 0x51, 0x4D, 0x48, 0x42, 0x3B, 0x32, 0x29, 0x22, 0x1D, 0x17, 0x14, 0x10, 0xE, 0xB};

int *my_comp=&conf.video_quality;


void __attribute__((naked,noinline)) sub_FF9634C0_my(){
 asm volatile(
                "STMFD   SP!, {R4-R11,LR}\n" 
                "LDR     R3, =0x61188\n"    
                "SUB     SP, SP, #0x38\n"   
                "LDR     LR, [R3]\n"        
                "MOV     R2, #0\n"          
                "LDR     R1, =0x61148\n"    
                "LDR     R0, =0x6114C\n"    
                "LDR     R12, =0x61174\n"   
                "MOV     R11, R2\n"         
                "STR     R11, [R1]\n"       
                "STR     LR, [R12]\n"       
                "STR     R11, [R0]\n"       
                "SUB     R3, LR, #0xA\n"    
                "CMP     R3, #0x32\n"       
                "LDRLS   PC, [PC,R3,LSL#2]\n" 
                "B       loc_FF9635E4\n"    
                ".long loc_FF9635CC\n"
                ".long loc_FF9635E4\n"
                ".long loc_FF9635E4\n"
                ".long loc_FF9635E4\n"
                ".long loc_FF9635E4\n"
                ".long loc_FF9635CC\n"
                ".long loc_FF9635E4\n"
                ".long loc_FF9635E4\n"
                ".long loc_FF9635E4\n"
                ".long loc_FF9635E4\n"
                ".long loc_FF9635D4\n"
                ".long loc_FF9635E4\n"
                ".long loc_FF9635E4\n"
                ".long loc_FF9635E4\n"
                ".long loc_FF9635E4\n"
                ".long loc_FF9635E4\n"
                ".long loc_FF9635E4\n"
                ".long loc_FF9635E4\n"
                ".long loc_FF9635E4\n"
                ".long loc_FF9635E4\n"
                ".long loc_FF9635D4\n"
                ".long loc_FF9635E4\n"
                ".long loc_FF9635E4\n"
                ".long loc_FF9635E4\n"
                ".long loc_FF9635E4\n"
                ".long loc_FF9635E4\n"
                ".long loc_FF9635E4\n"
                ".long loc_FF9635E4\n"
                ".long loc_FF9635E4\n"
                ".long loc_FF9635E4\n"
                ".long loc_FF9635E4\n"
                ".long loc_FF9635E4\n"
                ".long loc_FF9635E4\n"
                ".long loc_FF9635E4\n"
                ".long loc_FF9635E4\n"
                ".long loc_FF9635E4\n"
                ".long loc_FF9635E4\n"
                ".long loc_FF9635E4\n"
                ".long loc_FF9635E4\n"
                ".long loc_FF9635E4\n"
                ".long loc_FF9635E4\n"
                ".long loc_FF9635E4\n"
                ".long loc_FF9635E4\n"
                ".long loc_FF9635E4\n"
                ".long loc_FF9635E4\n"
                ".long loc_FF9635E4\n"
                ".long loc_FF9635E4\n"
                ".long loc_FF9635E4\n"
                ".long loc_FF9635E4\n"
                ".long loc_FF9635E4\n"
                ".long loc_FF9635DC\n"
"loc_FF9635CC:\n"                           
                                        
                "MOV     R11, #2\n"         
                "B       loc_FF9635F0\n"    
"loc_FF9635D4:\n"                           
                                        
                "MOV     R11, #4\n"         
                "B       loc_FF9635F0\n"    
"loc_FF9635DC:\n"                           
                                        
                "MOV     R11, #8\n"         
                "B       loc_FF9635F0\n"    
"loc_FF9635E4:\n"                           
                                        
                                        
                "LDR     R0, =0xFF96256C\n" 
                "MOV     R1, #0x3BC\n"      
                "BL      sub_FF813B80\n"     
"loc_FF9635F0:\n"                           
                                        
                "LDR     R4, =0x61210\n"    
                "MOV     R1, #0\n"          
                "MOV     R2, R4\n"          
                "MOV     R0, #8\n"          
                "BL      sub_FF81282C\n"    
                "LDR     R0, =0xFF96393C\n" 
                "MOV     R1, #0\n"          
                "BL      sub_FF89A344\n" 
                "MOV     R6, #0x1800\n"     
                "LDR     R5, [R4]\n"        
                "LDR     R7, =0x61230\n"    
                "ADD     R6, R6, #0x34\n"   
                "LDR     R12, =0x61234\n"   
                "LDR     R2, =0x6122C\n"    
                "LDR     R1, =0x61164\n"    
                "ADD     R3, R5, R6\n"      
                "STR     R3, [R2]\n"        
                "LDR     R0, [R1]\n"        
                "STR     R5, [R12]\n"       
                "MOV     R1, R7\n"          
                "BL      sub_FF9723E8\n"    
                "LDR     R5, =0x61168\n"    
                "LDR     R3, =0x61170\n"    
                "LDR     R2, [R3]\n"        
                "LDR     R3, [R5]\n"        
                "MUL     R12, R3, R2\n"     
                "LDR     R2, =0x61184\n"    
                "LDR     R2, [R2]\n"        
                "LDR     LR, [R7]\n"        
                "LDMIA   R4, {R0,R1}\n"     
                "LDR     R5, =0x61160\n"    
                "STR     R2, [SP,#0x2C]\n"  
                "LDR     R3, =0x61154\n"    
                "LDR     R9, [R5]\n"        
                "LDR     R4, =0x61188\n"    
                "LDR     R7, =0x61180\n"    
                "RSB     R1, LR, R1\n"      
                "ADD     R0, R0, LR\n"      
                "LDR     R5, =0x61164\n"    
                "LDR     LR, [R3]\n"        
                "LDR     R3, =0x61168\n"    
                "LDR     R2, [R7]\n"        
                "LDR     R7, [R4]\n"        
                "LDR     R4, [R5]\n"        
                "LDRH    R5, [R3]\n"        
                "LDR     R3, =0x61170\n"    
                "LDRH    R8, [R3]\n"        
                "LDR     R3, =0x6116C\n"    
                "MOV     R12, R12,LSL#13\n" 
                "LDR     R10, [R3]\n"       
                "STR     R4, [SP,#8]\n"     
                "STR     R5, [SP,#0x14]\n"  
                "LDR     R4, =0xFF963C28\n" 
                "LDR     R5, =0x61178\n"    
                "LDR     R3, [SP,#0x2C]\n"  
                "MOV     R12, R12,LSR#16\n" 
                "RSB     R1, R6, R1\n"      
                "ADD     R0, R0, R6\n"      
                "STR     R7, [SP]\n"        
                "STR     R12, [SP,#0x10]\n" 
                "STR     R5, [SP,#0x28]\n"  
                "STR     LR, [SP,#4]\n"     
                "STR     R9, [SP,#0xC]\n"   
                "STR     R8, [SP,#0x18]\n"  
                "STR     R11, [SP,#0x1C]\n" 
                "STR     R10, [SP,#0x20]\n" 
                "STR     R4, [SP,#0x24]\n"  
                "LDR     R5, =0x611C8\n"    
                "BL      sub_FF964FB4\n"    
                "LDR     R12, =0x611E8\n"   
                "LDR     R3, =0x611C4\n"    
                "LDMIA   R12, {R1,R2}\n"    
                "LDR     R0, [R3]\n"        
                "LDR     R3, [R5]\n"        
                "BL      sub_FF96529C\n"    
                "LDR     R1, =0x61154\n"    
                "LDR     R7, =0x61180\n"    
                "LDR     R12, [R1]\n"       
                "LDR     R0, [R7]\n"        
                "LDR     R2, =0x611B4\n"    
                "MOV     R3, #0\n"          
                "LDR     R1, =0x611A8\n"    
                "STR     R12, [SP]\n"       
                "BL      sub_FF964AA8_my\n"    //-------------------->
                "LDR     R2, =0x6117C\n"    
                "LDR     R1, =0x611CC\n"    
                "LDR     R3, [R2]\n"        
                "LDR     R0, [R1]\n"        
                "LDR     R2, =0xFF962524\n" 
                "ADD     R3, R3, R3,LSL#1\n" 
                "ADD     R3, R3, R0\n"      
                "LDR     R0, [R2,R3,LSL#2]\n" 
                "MOV     R1, #1\n"          
                "BL      sub_FF898484\n"    
                "LDR     R0, =0xFF96393C\n" 
                "MOV     R1, #0\n"          
                "BL      sub_FF8986AC\n" 
                "MOV     R0, #0\n"          
                "BL      sub_FF830924\n"    
                "TST     R0, #1\n"          
                "BEQ     loc_FF963794\n"    
                "MOV     R1, #0x3EC\n"      
                "LDR     R0, =0xFF96256C\n" 
                "ADD     R1, R1, #3\n"      
                "BL      sub_FF813B80\n"     
"loc_FF963794:\n"                           
                "LDR     R3, =0x65DC\n"     
                "MOV     R4, #1\n"          
                "LDR     R0, =0xFF963D88\n" 
                "MOV     R1, #0\n"          
                "STR     R4, [R3]\n"        
                "BL      sub_FF830958\n"    
                "LDR     R3, =0x61064\n"    
                "MOV     R1, #0x1E\n"       
                "LDR     R0, [R3]\n"        
                "BL      sub_FF821068\n"   
                "CMP     R0, #9\n"          
                "BNE     loc_FF9637D0\n"    
                "LDR     R0, =0xFF96256C\n" 
                "MOV     R1, #0x3F4\n"      
                "BL      sub_FF813B80\n"     
"loc_FF9637D0:\n"                           
                "LDR     R0, [R5]\n"        
                "MOV     R1, #0xE4\n"       
                "ADD     R2, SP, #0x37\n"   
                "MOV     R3, R4\n"          
                "BL      sub_FF824FB8\n"    
                "TST     R0, #1\n"          
                "BEQ     loc_FF9637FC\n"    
                "MOV     R1, #0x3F8\n"      
                "LDR     R0, =0xFF96256C\n" 
                "ADD     R1, R1, #2\n"      
                "BL      sub_FF813B80\n"     
"loc_FF9637FC:\n"                           
                "LDRB    R0, [SP,#0x37]\n"  
                "CMP     R0, #1\n"          
                "MOVNE   R0, #0\n"          
                "MOVEQ   R0, #1\n"          
                "BL      sub_FF831418\n"    
                "LDR     R3, =0x61164\n"    
                "LDR     R7, =0x61168\n"    
                "LDR     R0, [R3]\n"        
                "LDR     R3, =0x61170\n"    
                "LDR     R1, [R7]\n"        
                "LDR     R2, [R3]\n"        
                "BL      sub_FF8310D0\n"    
                "LDR     R0, [R5]\n"        
                "MOV     R3, R4\n"          
                "MOV     R1, #0xE3\n"       
                "ADD     R2, SP, #0x36\n"   
                "BL      sub_FF824FB8\n"    
                "TST     R0, #1\n"          
                "BEQ     loc_FF963858\n"    
                "MOV     R1, #0x400\n"      
                "LDR     R0, =0xFF96256C\n" 
                "ADD     R1, R1, #7\n"      
                "BL      sub_FF813B80\n"     
"loc_FF963858:\n"                           
                "LDRB    R0, [SP,#0x36]\n"  
                "BL      sub_FF831294\n"    
                "ADD     R4, SP, #0x30\n"   
                "MOV     R0, R4\n"          
                "BL      sub_FF9657E4\n"    
                "LDR     R5, =0x6116C\n"    
                "LDR     R0, [SP,#0x30]\n"  
                "LDR     R1, [R5]\n"        
                "BL      sub_FF830E9C\n"    
                "MOV     R0, R4\n"          
                "BL      sub_FF9657E4\n"    
                "LDR     R1, [R5]\n"        
                "LDR     R0, [SP,#0x30]\n"  
                "BL      sub_FF830E9C\n"    
                "LDR     R0, =0x6120C\n"    
                "LDR     R2, =0xFF963D30\n" 
                "LDR     R1, =0x6115C\n"    
                "MOV     R3, #2\n"          
                "STR     R2, [R0]\n"        
                "STR     R3, [R1]\n"        
                "ADD     SP, SP, #0x38\n"   
                "LDMFD   SP!, {R4-R11,PC}\n" 

 );
}

void __attribute__((naked,noinline)) sub_FF964AA8_my(){
 asm volatile(
                "STMFD   SP!, {R4-R8,LR}\n" 
                "LDR     R12, =0x61274\n"   
                "LDR     LR, =0x61280\n"    
                "LDR     R5, =0x6127C\n"    
                "LDR     R7, =0x61278\n"    
                "MOV     R4, #0\n"          
                "CMP     R3, #1\n"          
                "STR     R4, [LR]\n"        
                "MOV     R8, R1\n"          
                "STR     R4, [R12]\n"       
                "MOV     R6, R2\n"          
                "STR     R4, [R5]\n"        
                "STR     R4, [R7]\n"        
                "BNE     loc_FF964AF4\n"    
                "MOV     R0, R8\n"          
                "BL      sub_FF892E6C\n"    
                "MOV     R3, #0x79\n"       
                "STR     R3, [R6]\n"        
                "LDMFD   SP!, {R4-R8,PC}\n" 
"loc_FF964AF4:\n"                           
                "CMP     R0, #0x280\n"      
                "BNE     loc_FF964B20\n"    
                "LDR     R3, [SP,#0x18]\n"  
                "CMP     R3, #1\n"          
                "MOVEQ   R3, #6\n"          
                "MOVEQ   R2, #2\n"          
                "BEQ     loc_FF964B30\n"    
                "LDR     R0, =0xFF964A8C\n" 
                "MOV     R1, #0xBF\n"       
                "BL      sub_FF813B80\n"     
                "B       loc_FF964B48\n"    
"loc_FF964B20:\n"                           
                "CMP     R0, #0x140\n"      
                "BNE     loc_FF964B3C\n"    
                "MOV     R3, #5\n"          
                "MOV     R2, #1\n"          
"loc_FF964B30:\n"                           
                "STR     R3, [R5]\n"        
                "STR     R2, [R7]\n"        
                "B       loc_FF964B48\n"    
"loc_FF964B3C:\n"                           
                "MOV     R3, #2\n"          
                "STR     R3, [R5]\n"        
                "STR     R4, [R7]\n"        
"loc_FF964B48:\n"                           
                                        
                "MOV     R0, R8\n"          
                "BL      sub_FF892E6C\n"    
                "LDR     R3, =0x6127C\n"    
                "LDR     R0, =0x65E0\n"     
                "LDR     R12, [R3]\n"       
                "LDR     R2, =CompressionRateTable\n" 
                "LDR     R3, [R0]\n"        
                "LDR     R1, [R2,R12,LSL#2]\n" 
                "CMP     R3, #1\n"          
                "STR     R1, [R6]\n"        
//                "MOVEQ   R3, #0xB\n"        // original

      "LDREQ   R3, =my_comp\n"                // my 
      "LDREQ   R3, [R3]\n"                    // code
      "LDREQ   R3, [R3]\n"                    // is here

                "STREQ   R3, [R6]\n"        
                "LDMFD   SP!, {R4-R8,PC}\n" 
 );
}

void __attribute__((naked,noinline)) sub_FF964B98_my(){
 asm volatile(
                "CMP     R2, #1\n"          
                "STMFD   SP!, {R4-R8,R10,LR}\n" 
                "MOV     R10, R0\n"         
                "MOV     R8, R1\n"          
                "MOVEQ   R3, #0x79\n"       
                "STREQ   R3, [R8]\n"        
                "LDMEQFD SP!, {R4-R8,R10,PC}\n" 
                "LDR     R1, =0x61274\n"    
                "LDR     R5, [R1]\n"        
                "LDR     R3, =0x6127C\n"    
                "CMP     R5, #0\n"          
                "LDR     R0, [R3]\n"        
                "BEQ     loc_FF964BE0\n"    
                "LDR     R2, =0x61280\n"    
                "LDR     R3, [R2]\n"        
                "CMP     R3, #1\n"          
                "BNE     loc_FF964BF4\n"    
                "B       loc_FF964BE4\n"    
"loc_FF964BE0:\n"                           
                "LDR     R2, =0x61280\n"    
"loc_FF964BE4:\n"                           
                "MOV     R3, #0\n"          
                "STR     R3, [R2]\n"        
                "STR     R10, [R1]\n"       
                "B       loc_FF964CB4\n"    
"loc_FF964BF4:\n"                           
                "LDR     R3, =0x61278\n"    
                "LDR     R2, [R3]\n"        
                "LDR     R7, =0xFF964984\n" 
                "RSB     R3, R2, R2,LSL#3\n" 
                "MOV     R4, R3,LSL#3\n"    
                "LDR     R1, [R7,R4]\n"     
                "ADD     R2, R2, R2,LSL#1\n" 
                "LDR     R6, =0xFF964A2C\n" 
                "MOV     LR, R2,LSL#2\n"    
                "RSB     R12, R1, R5\n"     
                "LDR     R3, [R6,LR]\n"     
                "CMP     R12, #0\n"         
                "RSB     R1, R3, R5\n"      
                "BLE     loc_FF964C60\n"    
                "ADD     R3, R7, #4\n"      
                "LDR     R2, [R3,R4]\n"     
                "CMP     R2, R12\n"         
                "ADDGE   R0, R0, #1\n"      
                "BGE     loc_FF964C54\n"    
                "ADD     R3, R7, #8\n"      
                "LDR     R2, [R3,R4]\n"     
                "CMP     R2, R12\n"         
                "ADDGE   R0, R0, #2\n"      
                "ADDLT   R0, R0, #3\n"      
"loc_FF964C54:\n"                           
                "CMP     R0, #0xE\n"        
                "MOVGE   R0, #0xE\n"        
                "B       loc_FF964C98\n"    
"loc_FF964C60:\n"                           
                "CMP     R1, #0\n"          
                "BGE     loc_FF964C98\n"    
                "ADD     R3, R6, #4\n"      
                "LDR     R2, [R3,LR]\n"     
                "CMP     R2, R1\n"          
                "SUBLE   R0, R0, #1\n"      
                "BLE     loc_FF964C90\n"    
                "ADD     R3, R6, #8\n"      
                "LDR     R2, [R3,LR]\n"     
                "CMP     R2, R1\n"          
                "SUBLE   R0, R0, #2\n"      
                "SUBGT   R0, R0, #3\n"      
"loc_FF964C90:\n"                           
                "CMP     R0, #0\n"          
                "MOVLT   R0, #0\n"          
"loc_FF964C98:\n"                           
                                        
                "LDR     R1, =0x6127C\n"    
                "LDR     R3, [R1]\n"        
                "CMP     R0, R3\n"          
                "LDRNE   R2, =0x61280\n"    
                "MOVNE   R3, #1\n"          
                "STRNE   R0, [R1]\n"        
                "STRNE   R3, [R2]\n"        
"loc_FF964CB4:\n"                           
                "LDR     R3, =0x6127C\n"    
                "LDR     R1, =0x65E0\n"     
                "LDR     R0, [R3]\n"        
                "LDR     R2, =CompressionRateTable\n" 
                "LDR     R12, [R1]\n"       
                "LDR     LR, [R2,R0,LSL#2]\n" 
                "LDR     R3, =0x61274\n"    
                "CMP     R12, #1\n"         
                "STR     R10, [R3]\n"       
                "STR     LR, [R8]\n"        
//                "MOVEQ   R3, #0xB\n"        // original 

      "LDREQ   R3, =my_comp\n"                // my 
      "LDREQ   R3, [R3]\n"                    // code
      "LDREQ   R3, [R3]\n"                    // is here

                "STREQ   R3, [R8]\n"        
                "LDMFD   SP!, {R4-R8,R10,PC}\n" 
 );
}



void __attribute__((naked,noinline)) sub_FF964D08_my(){
 asm volatile(
                "STMFD   SP!, {R4-R8,LR}\n" 
                "LDR     R8, =0x61278\n"    
                "LDR     R3, [R8]\n"        
                "LDR     R7, =0xFF964984\n" 
                "RSB     R6, R3, R3,LSL#3\n" 
                "LDR     R2, [R7,R6,LSL#3]\n" 
                "ADD     R3, R3, R3,LSL#1\n" 
                "LDR     R5, =0xFF964A2C\n" 
                "MOV     LR, R3,LSL#2\n"    
                "RSB     R4, R2, R0\n"      
                "LDR     R12, =0x6127C\n"   
                "LDR     R3, [R5,LR]\n"     
                "CMP     R4, #0\n"          
                "RSB     R0, R3, R0\n"      
                "LDR     R12, [R12]\n"      
                "BLE     loc_FF964D9C\n"    
                "MOV     R0, #1\n"          
                "ORR     R3, R0, R6,LSL R0\n" 
                "LDR     R2, [R7,R3,LSL#2]\n" 
                "CMP     R2, R4\n"          
                "ADD     R12, R12, R0\n"    
                "BGE     loc_FF964D90\n"    
                "MOV     R5, R7\n"          
                "MOV     LR, R8\n"          
"loc_FF964D68:\n"                           
                "ADD     R0, R0, #1\n"      
                "CMP     R0, #0xD\n"        
                "BGT     loc_FF964D90\n"    
                "LDR     R3, [LR]\n"        
                "RSB     R3, R3, R3,LSL#3\n" 
                "ADD     R3, R0, R3,LSL#1\n" 
                "LDR     R2, [R5,R3,LSL#2]\n" 
                "CMP     R2, R4\n"          
                "ADD     R12, R12, #1\n"    
                "BLT     loc_FF964D68\n"    
"loc_FF964D90:\n"                           
                                        
                "CMP     R12, #0xE\n"       
                "MOVGE   R12, #0xE\n"       
                "B       loc_FF964DD4\n"    
"loc_FF964D9C:\n"                           
                "CMP     R0, #0\n"          
                "BGE     loc_FF964DD4\n"    
                "ADD     R3, R5, #4\n"      
                "LDR     R2, [R3,LR]\n"     
                "CMP     R2, R0\n"          
                "SUBLE   R12, R12, #1\n"    
                "BLE     loc_FF964DCC\n"    
                "ADD     R3, R5, #8\n"      
                "LDR     R2, [R3,LR]\n"     
                "CMP     R2, R0\n"          
                "SUBLE   R12, R12, #2\n"    
                "SUBGT   R12, R12, #3\n"    
"loc_FF964DCC:\n"                           
                "CMP     R12, #0\n"         
                "MOVLT   R12, #0\n"         
"loc_FF964DD4:\n"                           
                                        
                "LDR     R3, =CompressionRateTable\n" 
                "LDR     R2, [R3,R12,LSL#2]\n" 
                "STR     R2, [R1]\n"        
                "LDMFD   SP!, {R4-R8,PC}\n" 

 );
}
