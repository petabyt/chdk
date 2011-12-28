topdir=../../

SKIPBUILDRULES=1

include $(topdir)makefile.inc

OBJ_ISDIGIT=
ifeq ($(GCC_VERSION_MAJOR),3)
    OBJ_ISDIGIT+= $(topdir)lib/libc/issmth.o
endif


CFLAGS+=$(CTHUMB) -mlong-calls
# warning: library order matters!
LDLIBS= -lgcc
LDOPTS=-nostdlib -Wl,--allow-shlib-undefined -Wl,-T,$(topdir)tools/link-boot.ld
LDOPTS+=-Wl,-N,-Ttext,0x0016ee30 -r -Wl,-d

OBJS=../gui_calendar.o ../gui_bench.o ../gui_4wins.o ../gui_mastermind.o ../gui_reversi.o \
	 ../gui_sokoban.o ../gui_read.o ../gui_debug.o  ../gui_tetris.o ../gui_snake.o ../dng.o


CFLAGS+=-DOPT_GENERIC_MODULES
OPT_OBJS= ../gui_fselect.o ../nothumb.o ../gui_mpopup.o ../curves.o ../edgeoverlay.o ../gui_palette.o
OPT_FLT= fselect.flt edgeovr.flt curves.flt mpopup.flt palette.flt


all: exportlist ../flt.h \
		_dng.flt benchm.flt calend.flt 4wins.flt mastmind.flt reversi.flt sokoban.flt _rawop10.flt _rawop12.flt \
		txtread.flt memview.flt modinsp.flt tetris.flt snake.flt modmenu.flt $(OPT_FLT)

%.o: %.c
	@echo $< \-\> $@
	$(CC) $(CFLAGS) -nostdinc -c -o $@ $<

.dep/%.d: %.c .dep
	$(HOSTCC) $(HOSTCFLAGS) -MM $< > $@.$$$$; \
	    sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	    rm -f $@.$$$$

%.flt: %.elf
	@echo \-\> $@
#	arm-elf-objdump.exe -d -r -x $< >$<.dumpobj
#	$(topdir)/tools/elf2flt/elf2flt$(EXE) $< $@ -e -f -h -r -s -iexportlist.txt >$@.dump
	$(topdir)/tools/elf2flt/elf2flt$(EXE) $< $@ -iexportlist.txt > $(DEVNULL)

calend.elf: simple_module.o ../gui_calendar.o
	@echo \-\> $@
	$(CC) $(CFLAGS) -o $@ -Wl,--start-group $^ $(LDLIBS) -Wl,--end-group $(LDFLAGS) $(LDOPTS)

benchm.elf: simple_module.o ../gui_bench.o
	@echo \-\> $@
	$(CC) $(CFLAGS) -o $@ -Wl,--start-group $^ $(LDLIBS) -Wl,--end-group $(LDFLAGS) $(LDOPTS)

4wins.elf: simple_game.o ../gui_4wins.o
	@echo \-\> $@
	$(CC) $(CFLAGS) -o $@ -Wl,--start-group $^ $(LDLIBS) -Wl,--end-group $(LDFLAGS) $(LDOPTS)

mastmind.elf: simple_game.o ../gui_mastermind.o
	@echo \-\> $@
	$(CC) $(CFLAGS) -o $@ -Wl,--start-group $^ $(LDLIBS) -Wl,--end-group $(LDFLAGS) $(LDOPTS)

reversi.elf: simple_game.o ../gui_reversi.o
	@echo \-\> $@
	$(CC) $(CFLAGS) -o $@ -Wl,--start-group $^ $(LDLIBS) -Wl,--end-group $(LDFLAGS) $(LDOPTS)

tetris.elf: ../gui_tetris.o
	@echo \-\> $@
	$(CC) $(CFLAGS) -o $@ -Wl,--start-group $^ $(LDLIBS) -Wl,--end-group $(LDFLAGS) $(LDOPTS)

snake.elf: ../gui_snake.o
	@echo \-\> $@
	$(CC) $(CFLAGS) -o $@ -Wl,--start-group $^ $(LDLIBS) -Wl,--end-group $(LDFLAGS) $(LDOPTS)

sokoban.elf: ../gui_sokoban.o
	@echo \-\> $@
	$(CC) $(CFLAGS) -o $@ -Wl,--start-group $^ $(LDLIBS) -Wl,--end-group $(LDFLAGS) $(LDOPTS)

memview.elf:  ../gui_debug.o
	@echo \-\> $@
	$(CC) $(CFLAGS) -o $@ -Wl,--start-group $^ $(LDLIBS) -Wl,--end-group $(LDFLAGS) $(LDOPTS)

palette.elf:  ../gui_palette.o
	@echo \-\> $@
	$(CC) $(CFLAGS) -o $@ -Wl,--start-group $^ $(LDLIBS) -Wl,--end-group $(LDFLAGS) $(LDOPTS)

mpopup.elf:  ../gui_mpopup.o
	@echo \-\> $@
	$(CC) $(CFLAGS) -o $@ -Wl,--start-group $^ $(LDLIBS) -Wl,--end-group $(LDFLAGS) $(LDOPTS)

txtread.elf: ../gui_read.o
	@echo \-\> $@
	$(CC) $(CFLAGS) -o $@ -Wl,--start-group $^ $(LDLIBS) -Wl,--end-group $(LDFLAGS) $(LDOPTS)

edgeovr.elf: ../edgeoverlay.o $(OBJ_ISDIGIT)
	@echo \-\> $@
	$(CC) $(CFLAGS) -o $@ -Wl,--start-group $^ $(LDLIBS) -Wl,--end-group $(LDFLAGS) $(LDOPTS)

curves.elf: ../curves.o
	@echo \-\> $@
	$(CC) $(CFLAGS) -o $@ -Wl,--start-group $^ $(LDLIBS) -Wl,--end-group $(LDFLAGS) $(LDOPTS)

modinsp.elf: module_inspector.o
	@echo \-\> $@
	$(CC) $(CFLAGS) -o $@ -Wl,--start-group $^ $(LDLIBS) -Wl,--end-group $(LDFLAGS) $(LDOPTS)

modmenu.elf: module_menu.o ../nothumb.o
	@echo \-\> $@
	$(CC) $(CFLAGS) -o $@ -Wl,--start-group $^ $(LDLIBS) -Wl,--end-group $(LDFLAGS) $(LDOPTS)

_dng.elf: ../dng.o $(topdir)/lib/armutil/reversebytes.o
	@echo \-\> $@
	$(CC) $(CFLAGS) -o $@ -Wl,--start-group $^ $(LDLIBS) -Wl,--end-group $(LDFLAGS) $(LDOPTS)

_rawop10.elf: raw_merge10.o
	@echo \-\> $@
	$(CC) $(CFLAGS) -o $@ -Wl,--start-group $^ $(LDLIBS) -Wl,--end-group $(LDFLAGS) $(LDOPTS)

_rawop12.elf: raw_merge12.o
	@echo \-\> $@
	$(CC) $(CFLAGS) -o $@ -Wl,--start-group $^ $(LDLIBS) -Wl,--end-group $(LDFLAGS) $(LDOPTS)

raw_merge10.o: ../raw_merge.c
	@echo $< \-\> $@
	$(CC) $(CFLAGS) -nostdinc -c -DCAM_MODULE_SENSOR_BITS_PER_PIXEL=10 -o $@ $<

raw_merge12.o: ../raw_merge.c
	@echo $< \-\> $@
	$(CC) $(CFLAGS) -nostdinc -c -DCAM_MODULE_SENSOR_BITS_PER_PIXEL=12 -o $@ $<

#lua.elf: lib_edgeoverlay.o ../luascript.o $(topdir)lib/lua/liblua.a
#	@echo \-\> $@
#	$(CC) $(CFLAGS) -o $@ -Wl,--start-group $^ $(LDLIBS) -Wl,--end-group $(LDFLAGS) $(LDOPTS)

fselect.elf: ../gui_fselect.o ../nothumb.o
	@echo \-\> $@
	$(CC) $(CFLAGS) -o $@ -Wl,--start-group $^ $(LDLIBS) -Wl,--end-group $(LDFLAGS) $(LDOPTS)

../nothumb.o: ../nothumb.c
	@echo $< \-\> $@
	$(CC) $(CFLAGS) -marm -nostdinc -c -o $@ $<

clean:
	rm -f *.o *.elf.syms *.elf *.flt $(OBJS) $(OPT_OBJS)

distclean: clean
#	rm -f *.flt

exportlist:  ../module_exportlist.c
	@echo $< \-\> $@
	$(topdir)tools/makeexport$(EXE) ../module_exportlist.c ../module_exportlist.h exportlist.txt

../flt.h: $(topdir)tools/elf2flt/flt.h
	@echo $< \-\> $@
	@echo "//DO NOT EDIT THIS FILE. This is automatic copy of tools/elf2flt/flt.h" > ../flt.h
	cat $(topdir)tools/elf2flt/flt.h >>../flt.h

include $(topdir)bottom.inc
