#0x30F2
PLATFORMID=12530

PLATFORMOS=vxworks

MEMBASEADDR=0x1900
RESTARTSTART=0x50000
MEMISOSTART=0x7C2B0
MEMISOSIZE=0x55000
ROMBASEADDR=0xff810000

TARGET_PRIMARY=$(topdir)platform/$(PLATFORM)/sub/$(PLATFORMSUB)/PRIMARY.BIN

PLFLAGS=-DMEMBASEADDR=$(MEMBASEADDR) -DMEMISOSTART=$(MEMISOSTART) -DMEMISOSIZE=$(MEMISOSIZE)
PLFLAGS+=-DRESTARTSTART=$(RESTARTSTART)
