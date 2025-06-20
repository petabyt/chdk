// G10 loader - entry.S
    .section .entry
// Turn OFF SD Card power
// to support autostart

//ROM:FFC3F634                 LDR     R1, =0xC0220000
//ROM:FFC3F638                 MOV     R0, #0x44
//ROM:FFC3F63C                 STR     R0, [R1,#0x70]


//	LDR     R3, =0xC0220070 	// G10 102a @FF85AA38 & FF85AA40
//	MOV     R2, #0x44
//	STR     R2, [R3]

// looks like idle cycle is required for proper shutdown
	MOV     R3, #0xF0000   		// increased from 8000 to F0000 for extra delay
1:
	SUB R3, R3, #1
	CMP R3, #0
	BNE 1b

// ordinary startup...

	MOV     SP, #0x1900
	MOV     R11, #0
	B	my_restart
