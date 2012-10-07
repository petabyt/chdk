topdir=../../

include $(topdir)makefile.inc

OBJS = callfunc.o reboot.o cache.o

OBJS_ALL = $(OBJS)
OBJS_ALL += reversebytes.o 

all: libarmutil.a reversebytes.o 

libarmutil.a: $(OBJS)

clean:
	rm -f $(OBJS_ALL) libarmutil.a

distclean: clean
	rm -f $(OBJS_ALL:.o=.d)

include $(topdir)bottom.inc
