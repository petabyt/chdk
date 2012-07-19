    .text

#define DEF(name,addr) \
    .globl name; name = addr

#define NSTUB(name, addr)\
    .globl _##name ;\
    .weak _##name ;\
    _##name: ;\
	ldr  pc, = ## addr

#define NHSTUB(name, addr)\
    .globl _##name ;\
    _##name: ;\
	ldr  pc, = ## addr

#define STUB(addr)\
    .globl sub_ ## addr ;\
    sub_ ## addr: ;\
	ldr  pc, =0x ## addr
