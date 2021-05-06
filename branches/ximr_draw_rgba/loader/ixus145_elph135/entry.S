    .section .entry

    LDR     SP, =MEMBASEADDR
    BL      check_compat

// SD card off stuff does not seem to be needed

	MOV     SP, #0x1900
	MOV     R11, #0
	B	my_restart
