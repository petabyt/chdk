"    STMFD   SP!, {R0}\n"
//R3 = Pointer to task function to create

/*** INSTALL init_file_modules_task() hook ***/
"    LDR     R0, =task_InitFileModules\n"
"    CMP     R0, R3\n"
"    LDREQ   R3, =init_file_modules_task\n"

// restore overwritten registers
"    LDMFD   SP!, {R0}\n"
// Execute overwritten instructions from original code, then jump to firmware
