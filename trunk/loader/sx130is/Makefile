topdir=../../

include $(topdir)makefile_cam.inc
SUBDIRS=resetcode

CFLAGS+=-DRESTARTSTART=$(RESTARTSTART)

LDOPTS=-nostdlib -Wl,--allow-shlib-undefined -Wl,-EL,-T,$(tools)/link-boot.ld -Wl,-N,-Ttext,$(MEMBASEADDR)

CORE_FILE=$(camfw)/main.bin
RESET_FILE=resetcode/main.bin

CFLAGS+=-I. -DCORE_FILE=\"$(CORE_FILE)\" -DRESET_FILE=\"$(RESET_FILE)\"

all: all-recursive main.bin

OBJS=entry.o main.o blobs.o

main.bin: main.elf
main.elf: $(OBJS)

clean: clean-recursive
	rm -f *.o *.bin *.elf *.dump *.elf.syms

distclean: distclean-recursive
	rm -f *.o *.bin *.elf *.dump *.elf.syms
	rm -f reboot_core.h copy_and_reset.h

blobs.o: $(RESET_FILE) $(CORE_FILE)

include $(topdir)bottom.inc
