#315B
PLATFORMID=12635

PLATFORMOS=dryos

MEMBASEADDR=0x1900
RESTARTSTART=0x50000
MEMISOSTART=0xA3F20
MEMISOSIZE=0x55000
ROMBASEADDR=0xffc00000

TARGET_PRIMARY=$(topdir)platform/$(PLATFORM)/sub/$(PLATFORMSUB)/PRIMARY.BIN

PLFLAGS=-DMEMBASEADDR=$(MEMBASEADDR) -DMEMISOSTART=$(MEMISOSTART) -DMEMISOSIZE=$(MEMISOSIZE)
PLFLAGS+=-DRESTARTSTART=$(RESTARTSTART)
