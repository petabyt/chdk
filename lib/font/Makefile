topdir=../../

SKIPPLATFORMCHECK=1

include $(topdir)makefile.inc

CFLAGS+=$(CTHUMB) -DCHDK_MODULE_CODE

OBJS = $Ofont_8x16.o $Orbf_font.o

all: $Olibfont.a

$Olibfont.a: $(OBJS)

$Ofont_8x16.o: font_8x16.c font_8x16_uni_packed.h

font_8x16_uni_packed.h: font_8x16_uni.h codepages.h $(topdir)tools/font_8x16_pack$(EXE)
	$(topdir)tools/font_8x16_pack$(EXE) > font_8x16_uni_packed.h

clean:
	rm -f $O*.* *.o *.a

distclean: clean
	rm -f $(OBJS:.o=.d)

include $(topdir)bottom.inc
