topdir=../../

# Makefile for platform independent 'libc' library
# Code copied from GCC for linking modules without including GCC library

include $(topdir)makefile_core.inc

OBJS = $Othumb1_case.o

all: $Olibc.a

$Olibc.a: $(OBJS)

clean:
	rm -f $O*.* *.o *.a

distclean: clean
	rm -f $(OBJS:.o=.d)

include $(topdir)bottom.inc
