topdir=../

include $(topdir)makefile.inc

CFLAGS+=$(CTHUMB)

# warning: library order matters!
LDLIBS= -lgcc
LDOPTS=-nostdlib -Wl,--allow-shlib-undefined -Wl,-T,$(topdir)tools/link-boot.ld
LDOPTS+=-Wl,-N,-Ttext,$(MEMISOSTART)

all: main.bin

# Build platform dependent code (independent code is built in lib/core/libcore.a)
OBJS=entry.o main.o gui_draw.o \
     gui.o kbd.o conf.o gui_osd.o raw.o \
     shot_histogram.o shooting.o camera_info.o

gui.o: FORCE

FORCE:

main.bin: main.elf

main.elf: $(OBJS) $(topdir)platform/$(PLATFORM)/libplatform.a \
          $(topdir)platform/$(PLATFORM)/sub/$(PLATFORMSUB)/libplatformsub.a \
          $(topdir)lib/font/libfont.a $(topdir)lib/math/libmath.a \
          $(topdir)lib/lang/liblang.a $(topdir)lib/armutil/libarmutil.a \
          $(topdir)lib/core/libcore.a
	@echo \-\> $@
	$(CC) $(CFLAGS) -o $@ -Wl,--start-group $^  $(LDLIBS) -Wl,--end-group $(LDFLAGS) $(LDOPTS)
	( $(NM) $@ | grep ' U ' > $@.syms ) && echo "error: unresolved symbols in $@ (see $@.syms)" && exit 1 || exit 0

	$(SIZE) $@ | tee $(topdir)size.txt
	@printf " %s-%s (%s, #%s): MEMISOSIZE used: 0x%s\n" \
      $(PLATFORM) $(PLATFORMSUB) $(PLATFORMOS) $(PLATFORMID) \
      `tail -c16 $(topdir)size.txt | head -c6` >> $(topdir)bin/caminfo.txt
	rm -f $(topdir)size.txt

clean:
	rm -f *.o main.bin main.elf main.bin.dump main.elf.syms

distclean: clean
	rm -f $(OBJS:.o=.d)

include $(topdir)bottom.inc
