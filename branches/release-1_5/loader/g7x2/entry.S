.section .entry
// ordinary startup...
.code 16
.align 2
.syntax unified
    LDR     SP, =0x2000
    B       my_restart
