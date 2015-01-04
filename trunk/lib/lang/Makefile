topdir=../../

SKIPPLATFORMCHECK=1

include $(topdir)makefile.inc

CFLAGS+=$(CTHUMB) -DCHDK_MODULE_CODE

OBJS = $Olang.o $Olang_str.o $Ofileutil.o

all: $Oliblang.a

$Oliblang.a: $(OBJS)

$Olang_str.o: lang_str.c lang_str.h $(topdir)core/gui_lang.h

lang_str.h: $(topdir)tools/makelang$(EXE) $(topdir)CHDK/LANG/english.lng $(topdir)CHDK/LANG/$(OPT_DEFAULT_LANG).lng
	@echo $< \-\> $@
	$(topdir)tools/makelang$(EXE) $(topdir)CHDK/LANG/english.lng $(topdir)CHDK/LANG/$(OPT_DEFAULT_LANG).lng > lang_str.h

clean:
	rm -f $O*.* *.o *.a

distclean: clean
	rm -f $(OBJS:.o=.d)

include $(topdir)bottom.inc

