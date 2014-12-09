# This file is included from platform/*/Makefile

include $(topdir)makefile.inc

CFLAGS+=-DLOW_LEVEL

# Change CPU architecture to ARM V4 if building with GCC EABI
# Otherwise incorrect wrapper calls to firmware functions are generated
ifdef OPT_USE_GCC_EABI
    CFLAGS+=-march=armv4
endif

OBJS=main.o lib.o wrappers.o kbd.o shooting.o

libplatform.a: $(OBJS)

all: libplatform.a

kbd.o: kbd.c
lib.o: lib.c
main.o: main.c
shooting.o: shooting.c ../generic/shooting.c
wrappers.o: wrappers.c ../generic/wrappers.c

clean:
	rm -f $(OBJS) libplatform.a

distclean: clean
	rm -f $(OBJS:.o=.d)

include $(topdir)bottom.inc


# Define empty recipes for source files (including the makefiles)
# to prevent make from trying implicit rules to create them. Speeds up build process
$(topdir)platform/makefile_platform.inc: ;
