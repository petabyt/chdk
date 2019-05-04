topdir=../../

include $(topdir)makefile_modules.inc

OBJS = $Ocamera_functions.o $Otokenizer.o $Oubasic.o

all: $Olibubasic.a

$Olibubasic.a: $(OBJS)

UBASIC_TEST_CFLAGS=-g -Wall -DUBASIC_TEST -DCAMERA_$(PLATFORM) -DPLATFORMID=$(PLATFORMID) -I$(cam)
ifdef UBASIC_DEBUG
	UBASIC_TEST_CFLAGS+=-DDEBUG=1
endif

check:
	gcc $(UBASIC_TEST_CFLAGS) -o ubasic_test$(EXE) $(OBJS:.o=.c) run-ubasic.c

clean:
	rm -f $O*.* *.o *.a ubasic_test$(EXE)

distclean: clean
	rm -f $(OBJS:.o=.d)

include $(topdir)bottom.inc
