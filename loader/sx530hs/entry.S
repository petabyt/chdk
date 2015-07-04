    .section .entry

// looks like idle cycle is required for proper shutdown
	MOV     R3, #0xFF000
1:
	SUB	    R3, R3, #1
	CMP	    R3, #0
	BNE	    1b

/* 	This code is crashing
	STMFD	SP!, {R0,R1}
	LDR		R1, =0xC022D1FC	// Green LED
	MOVW	R0, #0xd800	// Power on LED, the value I want is 0x0093d800
	MOVT	R0, #0x0093	// It need 2 steps
	STR		R0, [R1]
*/

// ordinary startup...
	MOV     SP, #0x1900
	MOV     R11, #0
	B	    my_restart
	//BL 0xFF010000
