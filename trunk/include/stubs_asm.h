// Common definitions for stubs_entry.S and stubs_entry_2.S macros

    .text

#define DEF(n,a) \
    .globl n; n = a

#if defined(OPT_FIRMWARE_PC24_CALL)

#define NHSTUB(name, addr)\
    .globl _##name ;\
    .weak _##name ;\
    _##name = ## addr

#define STUB(addr)\
    .globl sub_ ## addr ;\
    sub_ ## addr = 0x ## addr

#else

#define NHSTUB(name, addr)\
    .globl _##name ;\
    .weak _##name ;\
    _##name: ;\
	ldr  pc, = ## addr

#define STUB(addr)\
    .globl sub_ ## addr ;\
    sub_ ## addr: ;\
	ldr  pc, =0x ## addr

#endif
