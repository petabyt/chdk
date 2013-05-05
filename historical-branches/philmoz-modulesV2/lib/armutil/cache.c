/*
Arm cache control functions
TODO
Only valid on processors with cp15 (e.g. not s1)
Makes assumptions about cache size
*/

/*
flush (mark as invalid) entire instruction cache
*/
void __attribute__((naked,noinline)) icache_flush_all(void) {
  asm volatile (
    "MOV    r1, #0\n"
    "MCR    p15, 0, r1,c7,c5\n"
    "BX     LR\n"
  );
}

/*
clean (write all dirty) entire data cache
also drains write buffer (like canon code)
does *not* flush
*/
void __attribute__((naked,noinline)) dcache_clean_all(void) {
  asm volatile (
    "MOV    r1, #0\n"
"2:\n"
    "MOV    r0, #0\n"
"1:\n"
    "ORR    r2,r1,r0\n"
    "MCR    p15, 0, r2, c7, c10, 2\n" // clean line
    "ADD    r0, r0, #0x20\n" // next line
    "CMP    r0,#0x800\n" // segment complete ? TODO assumes 8K cache
    "BNE    1b\n"
    "ADD    r1, r1,#0x40000000\n" // next segment
    "CMP    r1, #0\n"
    "BNE    2b\n"
    "MCR    p15, 0, r1, c7, c10, 4\n" // drain write buffer
    "BX     LR\n"
  );
}
