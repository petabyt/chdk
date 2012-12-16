topdir=../

include $(topdir)makefile.inc

CFLAGS+=$(CTHUMB)

# warning: library order matters!
LDLIBS= -lgcc
LDOPTS=-nostdlib -Wl,--allow-shlib-undefined -Wl,-T,$(topdir)tools/link-boot.ld
LDOPTS+=-Wl,-N,-Ttext,$(MEMISOSTART)

all: main.bin

OPT_OBJS=
ifdef OPT_GAMES
CFLAGS+=-DOPT_GAMES
endif
ifdef OPT_CURVES
CFLAGS+=-DOPT_CURVES
endif
ifdef OPT_TEXTREADER
CFLAGS+=-DOPT_TEXTREADER
endif
ifdef OPT_CALENDAR
CFLAGS+=-DOPT_CALENDAR
endif
ifdef OPT_DEBUGGING
# global in root makefile.inc
#CFLAGS+=-DOPT_DEBUGGING
#OPT_OBJS+=gui_debug.o gui_bench.o 
endif
ifdef OPT_EDGEOVERLAY
CFLAGS+=-DOPT_EDGEOVERLAY
#OPT_OBJS+=edgeoverlay.o 
endif
ifdef OPT_MD_DEBUG
CFLAGS+=-DOPT_MD_DEBUG
endif 
ifdef OPT_SCRIPTING
OPT_OBJS+=script.o
endif 
ifdef OPT_PTP
# in top level
#CFLAGS+=-DOPT_PTP
OPT_OBJS+=ptp.o live_view.o
endif
ifdef OPT_DBG_DUMP
OPT_OBJS+=dbg_dump.o
endif

# Build platform dependent code (independent code is built in lib/core/libcore.a)
OBJS=entry.o main.o gui_draw.o gui_menu.o gui_user_menu.o \
     gui.o kbd.o action_stack.o conf.o \
     histogram.o gui_osd.o raw.o \
     modules.o shot_histogram.o shooting.o \
     gps.o camera_info.o $(OPT_OBJS)

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
