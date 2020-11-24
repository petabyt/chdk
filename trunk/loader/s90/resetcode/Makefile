topdir=../../../

include $(topdir)makefile_cam.inc

LDOPTS=-nostdlib -Wl,--allow-shlib-undefined -Wl,-EL,-T,$(tools)/link-boot.ld -Wl,-N,-Ttext,$(RESTARTSTART)

all: main.bin

OBJS=entry.o main.o

main.bin: main.elf
main.elf: $(OBJS)

clean: clean-recursive
	rm -f *.o *.bin *.elf *.dump *.elf.syms

distclean: distclean-recursive
	rm -f *.o *.bin *.elf *.dump *.elf.syms

include $(topdir)bottom.inc
