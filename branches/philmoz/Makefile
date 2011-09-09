topdir=./
srcdir=./

include makefile.inc

#ifndef NO_INC_BUILD
#BUILD_NUMBER := $(shell expr $(BUILD_NUMBER) + 1)
#endif

SUBDIRS=tools lib platform core loader CHDK

all: all-recursive

clean: clean-recursive

distclean: distclean-recursive

.PHONY: fir
fir: version firsub

firsub: all
	mkdir -p  $(topdir)bin
	cp $(topdir)loader/$(PLATFORM)/main.bin  $(topdir)bin/main.bin
ifndef NOZERO100K
ifeq ($(OSTYPE),Windows)
	zero | dd bs=1k count=100 >>  $(topdir)bin/main.bin 2> $(DEVNULL)
else
	dd if=/dev/zero bs=1k count=100 >>  $(topdir)bin/main.bin 2> $(DEVNULL)
endif
endif
ifdef PLATFORMOS
  ifeq ($(PLATFORMOS),vxworks)
	@echo \-\> PS.FIR
	$(PAKWIF) $(topdir)bin/PS.FIR $(topdir)bin/main.bin $(PLATFORMID) 0x01000101
  endif
  ifeq ($(PLATFORMOS),dryos)
ifdef OPT_FI2
  ifdef FI2KEY
		@echo \-\> PS.FI2
		$(PAKFI2)  $(topdir)bin/main.bin -p $(PLATFORMID) -key $(FI2KEY) -iv $(FI2IV)  $(topdir)bin/PS.FI2
  else
		@echo WARNING OPT_FI2 set but FI2KEY is not! please read platform/fi2.inc.txt
  endif
endif
  endif
endif
ifdef NEED_ENCODED_DISKBOOT
	@echo dance \-\> DISKBOOT.BIN ver $(NEED_ENCODED_DISKBOOT)
	$(ENCODE_DISKBOOT) $(topdir)bin/main.bin  $(topdir)bin/DISKBOOT.BIN $(NEED_ENCODED_DISKBOOT)
	rm  $(topdir)bin/main.bin
else
	mv  $(topdir)bin/main.bin  $(topdir)bin/DISKBOOT.BIN
endif
	@echo "**** Firmware creation completed successfully"

.PHONY: upload
upload: fir
	@echo Uploading...
	cp $(topdir)bin/$(PLATFORM)-$(PLATFORMSUB).FIR $(topdir)bin/PS.FIR
	/home/vitalyb/Projects/ch/libptp2-1.1.0/src/ptpcam -u -m 0xbf01 --filename $(topdir)bin/PS.FIR

infoline:
	@echo "**** GCC $(GCC_VERSION) : BUILDING CHDK-$(VER), #$(BUILD_NUMBER)$(STATE) FOR $(PLATFORM)-$(PLATFORMSUB)"

version: FORCE
	echo "**** Build: $(BUILD_NUMBER)"
#	echo "BUILD_NUMBER := $(BUILD_NUMBER)" > version.inc

FORCE:

firzip: version firzipsub

firzipsub: infoline clean firsub
	@echo \-\> $(VER)-$(PLATFORM)-$(PLATFORMSUB)-$(BUILD_NUMBER)$(STATE).zip
	rm -f $(topdir)bin/$(VER)-$(PLATFORM)-$(PLATFORMSUB)-$(BUILD_NUMBER)$(STATE).zip
	LANG=C echo -e "CHDK-$(VER) for $(PLATFORM) fw:$(PLATFORMSUB) build:$(BUILD_NUMBER) date:`date -R`" | \
	    zip -9jz $(topdir)bin/$(VER)-$(PLATFORM)-$(PLATFORMSUB)-$(BUILD_NUMBER)$(STATE).zip $(topdir)bin/DISKBOOT.BIN > $(DEVNULL)
ifdef PLATFORMOS
  ifeq ($(PLATFORMOS),vxworks)
	zip -9j $(topdir)bin/$(VER)-$(PLATFORM)-$(PLATFORMSUB)-$(BUILD_NUMBER)$(STATE).zip $(topdir)bin/PS.FIR > $(DEVNULL)
	rm -f $(topdir)bin/PS.FIR
  endif
  ifeq ($(PLATFORMOS),dryos)
    ifdef OPT_FI2
      ifdef FI2KEY
	    zip -9j $(topdir)bin/$(VER)-$(PLATFORM)-$(PLATFORMSUB)-$(BUILD_NUMBER)$(STATE).zip $(topdir)bin/PS.FI2 > $(DEVNULL)
	    rm -f $(topdir)bin/PS.FI2
      endif
    endif
  endif
endif
# if COPY_TO is defined the copy this camera/firmware version to the copied firmware version
ifdef COPY_TO
	cp $(topdir)bin/$(VER)-$(PLATFORM)-$(PLATFORMSUB)-$(BUILD_NUMBER)$(STATE).zip $(topdir)bin/$(VER)-$(PLATFORM)-$(COPY_TO)-$(BUILD_NUMBER)$(STATE).zip
endif
	rm -f $(topdir)bin/DISKBOOT.BIN


firzipsubcomplete: infoline clean firsub
	@echo \-\> $(PLATFORM)-$(PLATFORMSUB)-$(BUILD_NUMBER)-full$(STATE).zip
	rm -f $(topdir)bin/$(PLATFORM)-$(PLATFORMSUB)-$(BUILD_NUMBER)-full$(STATE).zip
	@echo \-\> $(PLATFORM)-$(PLATFORMSUB)-$(BUILD_NUMBER)$(STATE).zip
	rm -f $(topdir)bin/$(PLATFORM)-$(PLATFORMSUB)-$(BUILD_NUMBER)$(STATE).zip
	LANG=C echo -e "CHDK-$(VER) for $(PLATFORM) fw:$(PLATFORMSUB) build:$(BUILD_NUMBER)$(STATE) date:`date -R`" | \
	zip -9jz $(topdir)bin/$(PLATFORM)-$(PLATFORMSUB)-$(BUILD_NUMBER)-full$(STATE).zip $(topdir)bin/DISKBOOT.BIN > $(DEVNULL)
	LANG=C echo -e "CHDK-$(VER) for $(PLATFORM) fw:$(PLATFORMSUB) build:$(BUILD_NUMBER)$(STATE) date:`date -R`" | \
	zip -9jz $(topdir)bin/$(PLATFORM)-$(PLATFORMSUB)-$(BUILD_NUMBER)$(STATE).zip $(topdir)bin/DISKBOOT.BIN > $(DEVNULL)
	zip -9 $(topdir)bin/$(PLATFORM)-$(PLATFORMSUB)-$(BUILD_NUMBER)-full$(STATE).zip $(topdir)CHDK/SYMBOLS/*  > $(DEVNULL)
	zip -9 $(topdir)bin/$(PLATFORM)-$(PLATFORMSUB)-$(BUILD_NUMBER)-full$(STATE).zip $(topdir)CHDK/BOOKS/*  > $(DEVNULL)
	zip -9 $(topdir)bin/$(PLATFORM)-$(PLATFORMSUB)-$(BUILD_NUMBER)-full$(STATE).zip $(topdir)CHDK/CURVES/*  > $(DEVNULL)
	zip -9 $(topdir)bin/$(PLATFORM)-$(PLATFORMSUB)-$(BUILD_NUMBER)-full$(STATE).zip $(topdir)CHDK/DATA/*  > $(DEVNULL)
	zip -9 $(topdir)bin/$(PLATFORM)-$(PLATFORMSUB)-$(BUILD_NUMBER)-full$(STATE).zip $(topdir)CHDK/FONTS/*  > $(DEVNULL)
	zip -9 $(topdir)bin/$(PLATFORM)-$(PLATFORMSUB)-$(BUILD_NUMBER)-full$(STATE).zip $(topdir)CHDK/GAMES/*   > $(DEVNULL)
	zip -9 $(topdir)bin/$(PLATFORM)-$(PLATFORMSUB)-$(BUILD_NUMBER)-full$(STATE).zip $(topdir)CHDK/GRIDS/* > $(DEVNULL)
	zip -9 $(topdir)bin/$(PLATFORM)-$(PLATFORMSUB)-$(BUILD_NUMBER)-full$(STATE).zip $(topdir)CHDK/LANG/*   > $(DEVNULL)
	zip -9 $(topdir)bin/$(PLATFORM)-$(PLATFORMSUB)-$(BUILD_NUMBER)-full$(STATE).zip $(topdir)CHDK/LUALIB/*   > $(DEVNULL)
	zip -9 $(topdir)bin/$(PLATFORM)-$(PLATFORMSUB)-$(BUILD_NUMBER)-full$(STATE).zip $(topdir)CHDK/LUALIB/GEN/*   > $(DEVNULL)
	zip -9 $(topdir)bin/$(PLATFORM)-$(PLATFORMSUB)-$(BUILD_NUMBER)-full$(STATE).zip $(topdir)CHDK/SCRIPTS/*  > $(DEVNULL)
	zip -9 $(topdir)bin/$(PLATFORM)-$(PLATFORMSUB)-$(BUILD_NUMBER)-full$(STATE).zip $(topdir)CHDK/SCRIPTS/EXAM/* 	 > $(DEVNULL)
	zip -9 $(topdir)bin/$(PLATFORM)-$(PLATFORMSUB)-$(BUILD_NUMBER)-full$(STATE).zip $(topdir)CHDK/SCRIPTS/TEST/* 	 > $(DEVNULL)
	zip -9 $(topdir)bin/$(PLATFORM)-$(PLATFORMSUB)-$(BUILD_NUMBER)-full$(STATE).zip $(topdir)CHDK/syscurves.CVF 	 > $(DEVNULL)
	zip -9j $(topdir)bin/$(PLATFORM)-$(PLATFORMSUB)-$(BUILD_NUMBER)-full$(STATE).zip $(topdir)doc/changelog.txt  > $(DEVNULL)
	zip -9j $(topdir)bin/$(PLATFORM)-$(PLATFORMSUB)-$(BUILD_NUMBER)$(STATE).zip $(topdir)doc/changelog.txt  > $(DEVNULL)
	zip -9j $(topdir)bin/$(PLATFORM)-$(PLATFORMSUB)-$(BUILD_NUMBER)-full$(STATE).zip $(topdir)tools/vers.req  > $(DEVNULL)
	cat $(topdir)doc/1_intro.txt  $(topdir)platform/$(PLATFORM)/notes.txt $(topdir)doc/2_installation.txt $(topdir)doc/3_faq.txt $(topdir)doc/4_urls.txt $(topdir)doc/5_gpl.txt $(topdir)doc/6_ubasic_copyright.txt > $(topdir)doc/readme.txt
	zip -9j $(topdir)bin/$(PLATFORM)-$(PLATFORMSUB)-$(BUILD_NUMBER)-full$(STATE).zip $(topdir)doc/readme.txt  > $(DEVNULL)
	zip -9j $(topdir)bin/$(PLATFORM)-$(PLATFORMSUB)-$(BUILD_NUMBER)$(STATE).zip $(topdir)doc/readme.txt  > $(DEVNULL)

ifdef PLATFORMOS
  ifeq ($(PLATFORMOS),vxworks)
	zip -9j $(topdir)bin/$(PLATFORM)-$(PLATFORMSUB)-$(BUILD_NUMBER)-full$(STATE).zip $(topdir)bin/PS.FIR > $(DEVNULL)
	zip -9j $(topdir)bin/$(PLATFORM)-$(PLATFORMSUB)-$(BUILD_NUMBER)$(STATE).zip $(topdir)bin/PS.FIR > $(DEVNULL)
	rm -f $(topdir)bin/PS.FIR
  endif
  ifeq ($(PLATFORMOS),dryos)
#	zip -9j $(topdir)bin/$(PLATFORM)-$(PLATFORMSUB)-$(BUILD_NUMBER)-full$(STATE).zip $(topdir)doc/readme.txt  > $(DEVNULL)
#	zip -9j $(topdir)bin/$(PLATFORM)-$(PLATFORMSUB)-$(BUILD_NUMBER)$(STATE).zip $(topdir)doc/readme.txt  > $(DEVNULL)
ifdef OPT_FI2
  ifdef FI2KEY
	zip -9j $(topdir)bin/$(PLATFORM)-$(PLATFORMSUB)-$(BUILD_NUMBER)-full$(STATE).zip $(topdir)bin/PS.FI2 > $(DEVNULL)
	zip -9j $(topdir)bin/$(PLATFORM)-$(PLATFORMSUB)-$(BUILD_NUMBER)$(STATE).zip $(topdir)bin/PS.FI2 > $(DEVNULL)
	rm -f $(topdir)bin/PS.FI2
  endif
endif
  endif
endif
# if COPY_TO is defined the copy this camera/firmware version to the copied firmware version
ifdef COPY_TO
	cp $(topdir)bin/$(PLATFORM)-$(PLATFORMSUB)-$(BUILD_NUMBER)-full$(STATE).zip $(topdir)bin/$(PLATFORM)-$(COPY_TO)-$(BUILD_NUMBER)-full$(STATE).zip
	cp $(topdir)bin/$(PLATFORM)-$(PLATFORMSUB)-$(BUILD_NUMBER)$(STATE).zip $(topdir)bin/$(PLATFORM)-$(COPY_TO)-$(BUILD_NUMBER)$(STATE).zip
endif
	rm -f $(topdir)bin/DISKBOOT.BIN


batch-zip: version
	$(MAKE) -f makefile.cam VER=$(VER) ACTION=firzipsub batch
	@echo "**** Summary of memisosizes"
	cat $(topdir)bin/caminfo.txt
	rm -f $(topdir)bin/caminfo.txt   > $(DEVNULL)


batch-zip-complete: version
	$(MAKE) -f makefile.cam VER=$(VER) ACTION=firzipsubcomplete batch
	@echo "**** Summary of memisosizes"
	cat $(topdir)bin/caminfo.txt
	rm -f $(topdir)bin/caminfo.txt   > $(DEVNULL)


batch-clean:
	$(MAKE) -f makefile.cam VER=$(VER) ACTION=clean batch
