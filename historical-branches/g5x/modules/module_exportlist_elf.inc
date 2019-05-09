// This file is parsed by the makeexport.c program to generate the
// symbol hash table loaded later (from module_hashlist.h)
// Symbols to be exported should be on separate lines. Blank lines and '//' style comments are allowed

// This file contains only symbols to be exported from the GCC library, and is dependant on the ABI version (this is the ELF file)
// For linking modules without including a copy of the GCC library in each module
    __modsi3
    __umodsi3
    __divsi3
    __udivsi3
    __divsf3
    __mulsf3
    __divdf3
    __muldf3
    __floatunsisf
    __fixunssfsi
    __extendsfdf2
    __truncdfsf2
    __floatsidf
    __floatsisf
    __fixdfsi
    __adddf3
    __subdf3
    __ltdf2
    __gtdf2
    __bswapsi2
    __floatunsidf
    __fixunsdfsi
