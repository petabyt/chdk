topdir=../../

# Makefile for platform independent 'core' library
# builds code from core and modules that only needs to be compiled once across all camera/firmware versions

SKIPPLATFORMCHECK=1

include $(topdir)makefile.inc

CFLAGS+=$(CTHUMB) -DCHDK_MODULE_CODE

OBJS = $Ogui_batt.o $Ogui_space.o $Ogui_usb.o $Ogui_mbox.o $Ogps.o $Ogui_script.o $Ogui_menu.o $Ogui_user_menu.o
OBJS+= $Osuba.o $Olevent.o $Oconsole.o $Ogps_math.o $Olive_view.o $Optp.o $Oaction_stack.o $Oscript.o
OBJS+= $Ousb_input.o $Ousb_module.o $Ousb_remote.o $Oautoiso.o
OBJS+= $Omodule_hashlist.o $Omodule_load.o $Omodules.o $Oversions.o

all: $Olibcore.a

$Olibcore.a: $(OBJS)

$Omodule_load.o: $(topdir)modules/module_load.c $(topdir)modules/module_load.h $(topdir)modules/module_exportlist.h
$Omodule_hashlist.o: $(topdir)modules/module_hashlist.c
	@echo $< \-\> $@
	$(CC) $(CFLAGS) -nostdinc -fno-builtin -c -o $@ $<

$(topdir)modules/module_hashlist.c: $(topdir)modules/module_exportlist.c $(topdir)modules/module_exportlist$(ABI).inc $(topdir)/tools/makeexport$(EXE)
	@echo $< \-\> $@
	$(topdir)tools/makeexport$(EXE) $(topdir)modules/module_exportlist.h $(topdir)/modules/exportlist.inc $(topdir)modules/module_hashlist.c $(topdir)modules/module_exportlist.c $(topdir)modules/module_exportlist$(ABI).inc

clean:
	rm -f $O*.* *.o *.a

distclean: clean
	rm -f $(OBJS:.o=.d)

include $(topdir)bottom.inc
