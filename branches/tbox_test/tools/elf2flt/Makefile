topdir=../../

SKIPBUILDRULES=1

include $(topdir)makefile.inc

OBJS= myio.o elf-arm.o elfflt.o main.o

all: elf2flt$(EXE) fltdump$(EXE)

%.o: %.c
	@echo $< \-\> $@
	$(HOSTCC) $(HOSTCFLAGS) -Wno-format -DPLATFORMOS_$(PLATFORMOS) -c -o $@ $<

.dep/%.d: %.c .dep
	$(HOSTCC) $(HOSTCFLAGS) -MM $< > $@.$$$$; \
	    sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	    rm -f $@.$$$$

elf2flt$(EXE): $(OBJS)
	@echo $< \-\> $@
	$(HOSTCC) $(HOSTCFLAGS) -o $@ $^

fltdump$(EXE): fltdump.o myio.o
	@echo $< \-\> $@
	$(HOSTCC) $(HOSTCFLAGS) -o $@ $^

clean:
	rm -f $(OBJS) fltdump.o

distclean: clean

include $(topdir)bottom.inc

