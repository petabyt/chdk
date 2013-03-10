topdir=../

SKIPBUILDRULES=1
SKIPPLATFORMCHECK=1

include $(topdir)makefile.inc

SUBDIRS=$(topdir)lib/lua $(topdir)lib/ubasic $(topdir)lib/armutil $(topdir)lib/math
SUBDIRS+=$(topdir)lib/lang $(topdir)lib/font $(topdir)lib/core

OBJ_ISDIGIT=
ifeq ($(GCC_VERSION_MAJOR),3)
    OBJ_ISDIGIT+= $(topdir)lib/libc/issmth.o
endif

CFLAGS+=$(CTHUMB) -mlong-calls -DCHDK_MODULE_CODE
# warning: library order matters!
LDLIBS= -lgcc
LDOPTS=-nostdlib -Wl,--allow-shlib-undefined -Wl,-T,$(topdir)tools/link-boot.ld
LDOPTS+=-Wl,-N,-Ttext,0 -r -Wl,-d

# Only build modules files here. Platform indepedant code to be linked to code CHDK should be in libraries (above)
# to avoid 'long_call' overhead
FLTS=fselect.flt edgeovr.flt curves.flt mpopup.flt palette.flt grids.flt mdetect.flt zebra.flt \
     _dng.flt benchm.flt calend.flt 4wins.flt mastmind.flt reversi.flt sokoban.flt _rawop10.flt _rawop12.flt \
     txtread.flt memview.flt modinsp.flt tetris.flt snake.flt sudoku.flt _tbox.flt _osd_le.flt \
     ubasic.flt lua.flt

all: $(FLTS)

%.o: %.c
	@echo $< \-\> $@
	$(CC) $(CFLAGS) -nostdinc -c -o $@ $<

%.o: games/%.c
	@echo $< \-\> $@
	$(CC) $(CFLAGS) -nostdinc -c -o $@ $<

%.elf:
	@echo \-\> $@
	$(CC) $(CFLAGS) -o $@ -Wl,--start-group $^ $(LDLIBS) -Wl,--end-group $(LDFLAGS) $(LDOPTS)

.dep/%.d: %.c .dep
	$(HOSTCC) $(HOSTCFLAGS) -MM $< > $@.$$$$; \
	    sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	    rm -f $@.$$$$

%.flt: %.elf
	@echo \-\> $@
#	arm-elf-objdump$(EXE) -d -r -x $< >$<.dumpobj
#	$(topdir)/tools/elf2flt/elf2flt$(EXE) $< $@ -e -f -h -r -s -iexportlist.inc -!$(topdir)/tools/elf2flt/stoplist.txt >$@.dump
	$(topdir)/tools/elf2flt/elf2flt$(EXE) $< $@ -iexportlist.inc -!$(topdir)/tools/elf2flt/stoplist.txt > $(DEVNULL)

raw_merge10.o: raw_merge.c
	@echo $< \-\> $@
	$(CC) $(CFLAGS) -nostdinc -c -DCAM_MODULE_SENSOR_BITS_PER_PIXEL=10 -o $@ $<

raw_merge12.o: raw_merge.c
	@echo $< \-\> $@
	$(CC) $(CFLAGS) -nostdinc -c -DCAM_MODULE_SENSOR_BITS_PER_PIXEL=12 -o $@ $<

nothumb.o: nothumb.c
	@echo $< \-\> $@
	$(CC) $(CFLAGS) -marm -nostdinc -c -o $@ $<

reversebytes.o: reversebytes.S
	@echo $< \-\> $@
	$(CC) $(CFLAGS) -marm -nostdinc -c -o $@ $<

calend.elf: simple_module.o gui_calendar.o
_tbox.elf: gui_tbox.o
benchm.elf: simple_module.o gui_bench.o
memview.elf: gui_debug.o
palette.elf: gui_palette.o
mpopup.elf: gui_mpopup.o
txtread.elf: gui_read.o
edgeovr.elf: edgeoverlay.o bitvector.o $(OBJ_ISDIGIT)
zebra.elf: zebra.o
curves.elf: curves.o
mdetect.elf: motion_detector.o
grids.elf: gui_grid.o
modinsp.elf: module_inspector.o
_dng.elf: dng.o reversebytes.o
_rawop10.elf: raw_merge10.o
_rawop12.elf: raw_merge12.o
_osd_le.elf: gui_osd_edit.o
fselect.elf: gui_fselect.o nothumb.o

4wins.elf: simple_game.o gui_4wins.o
mastmind.elf: simple_game.o gui_mastermind.o
reversi.elf: simple_game.o gui_reversi.o
tetris.elf: simple_game.o gui_tetris.o
snake.elf: simple_game.o gui_snake.o
sokoban.elf: gui_sokoban.o
sudoku.elf: simple_game.o gui_sudoku.o

ubasic.elf: ubasic.o script_key_funcs.o $(topdir)lib/ubasic/libubasic.a
lua.elf: luascript.o script_key_funcs.o cordic_math.o dbg_dump.o $(topdir)lib/lua/liblua.a

clean:
	rm -f *.o *.elf.syms *.elf *.flt *.dump *.dumpobj

distclean: clean
#	rm -f *.flt

include $(topdir)bottom.inc
