.section .entry
// ordinary startup...
.code 16
.align 2
.syntax unified
    LDR     SP, =MEMBASEADDR
    B       my_restart
