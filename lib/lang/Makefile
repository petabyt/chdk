topdir=../../

include $(topdir)makefile_core.inc

OBJS = $Olang.o $Olang_str.o $Ofileutil.o

all: $Oliblang.a

$Oliblang.a: $(OBJS)

$Olang_str.o: lang_str.c lang_str.h $(core)/gui_lang.h

lang_str.h: $(tools)/makelang$(EXE) $(chdk)/LANG/english.lng $(chdk)/LANG/$(OPT_DEFAULT_LANG).lng
	@echo $< \-\> $@
	$(tools)/makelang$(EXE) $(chdk)/LANG/english.lng $(chdk)/LANG/$(OPT_DEFAULT_LANG).lng > lang_str.h

clean:
	rm -f $O*.* *.o *.a

distclean: clean
	rm -f $(OBJS:.o=.d)

include $(topdir)bottom.inc

