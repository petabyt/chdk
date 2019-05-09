topdir=../../

include $(topdir)makefile_core.inc

OBJS = $Od2d.o $Owrapper.o

all: $Olibmath.a

$Olibmath.a: $(OBJS)

$Od2d.o: d2d.c fdlibm.h

clean:
	rm -f $O*.* *.o *.a

distclean: clean
	rm -f $(OBJS:.o=.d)

include $(topdir)bottom.inc


# Define empty recipes for source files (including the makefiles)
# to prevent make from trying implicit rules to create them. Speeds up build process
fdlibm.h: ;
