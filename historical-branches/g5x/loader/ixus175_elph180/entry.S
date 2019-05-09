.section .entry

    LDR     SP, =MEMBASEADDR
    BL      check_compat


// ordinary startup...

    MOV     SP, #0x1900
    MOV     R11, #0
    B       my_restart
