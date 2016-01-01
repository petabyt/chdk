topdir=./

tmp:=$(shell echo "BUILD_SVNREV := $(DEF_SVN_REF)" > revision.inc)

# can override on command line or *buildconf.inc for custom subsets
CAMERA_LIST=camera_list.csv

# set date command for ZIP files - override in localbuildconf.inc if needed
#  e.g. OS/X date command does not support -R option, use GNU date (gdate) from coreutils 
ZIPDATE=date -R

include makefile_cam.inc

# skip thumb-2 ports when using old arm-elf toolchains
# used in the batch-zip and batch-zip-complete targets
ifndef OPT_USE_GCC_EABI
    NO_T2=-not2
else
    NO_T2=
endif

BUILD_SVNREV:=$(shell svnversion -cn $(topdir) | $(ESED) 's/[0-9]*:([0-9]+)[MPS]*/\1/')
ifeq ($(BUILD_SVNREV), )
	BUILD_SVNREV:=$(DEF_SVN_REF)
endif
#for CHDK-Shell up to svn revision 1.6
ifeq ($(BUILD_SVNREV), exported)
	BUILD_SVNREV:=$(DEF_SVN_REF)
endif
ifeq ($(BUILD_SVNREV), exportiert)
	BUILD_SVNREV:=$(DEF_SVN_REF)
endif
#for CHDK-Shell svn revision 1.7
ifeq ($(BUILD_SVNREV), Unversioned directory)
	BUILD_SVNREV:=$(DEF_SVN_REF)
endif
tmp:=$(shell echo "BUILD_SVNREV := $(BUILD_SVNREV)" > revision.inc)

SUBDIRS=

# SKIP_TOOLS prevents re-building tools in root level make, to speed up batch builds
ifndef SKIP_TOOLS
SUBDIRS+=tools
endif

# SKIP_MODULES prevents re-building modules in root level make, to speed up batch builds
ifndef SKIP_MODULES
SUBDIRS+=modules
endif

# SKIP_CHDK prevents cleaning CHDK in root level make, to speed up batch clean
ifndef SKIP_CHDK
SUBDIRS+=CHDK
endif

# Build camera, camera firmware & loader code (loader must be last)
SUBDIRS+=$(cam) $(camfw) $(loader)


.PHONY: platformcheck
platformcheck:
ifndef PLATFORM
	$(error PLATFORM has not been defined. Specify the PLATFORM to build on the command line or in localbuildconf.inc)
endif
ifndef PLATFORMSUB
	$(error PLATFORMSUB has not been defined. Specify the PLATFORMSUB to build on the command line or in localbuildconf.inc)
endif

.PHONY: infoline
infoline: platformcheck
	@echo "**** GCC $(GCC_VERSION) : BUILDING CHDK-$(VER), #$(BUILD_NUMBER)-$(BUILD_SVNREV)$(STATE) FOR $(TARGET_CAM)-$(TARGET_FW)"

.PHONY: version
version: FORCE
	echo "**** Build: $(BUILD_NUMBER)"

.PHONY: FORCE
FORCE:


ZIP_SMALL=$(TARGET_CAM)-$(TARGET_FW)-$(BUILD_NUMBER)-$(BUILD_SVNREV)$(STATE).zip
ZIP_FULL=$(TARGET_CAM)-$(TARGET_FW)-$(BUILD_NUMBER)-$(BUILD_SVNREV)-full$(STATE).zip
ZIP_SMALL_BASE=$(PLATFORM)-$(PLATFORMSUB)-$(BUILD_NUMBER)-$(BUILD_SVNREV)$(STATE).zip
ZIP_FULL_BASE=$(PLATFORM)-$(PLATFORMSUB)-$(BUILD_NUMBER)-$(BUILD_SVNREV)-full$(STATE).zip
ifdef PLATFORMOS
    ifeq ($(PLATFORMOS),vxworks)
        FW_UPD_FILE=$(bin)/PS.FIR
    endif
    ifeq ($(PLATFORMOS),dryos)
        ifdef OPT_FI2
            ifdef FI2KEY
                FW_UPD_FILE=$(bin)/PS.FI2
            else
                $(error WARNING OPT_FI2 set but FI2KEY is not! please read platform/fi2.inc.txt)
            endif
        endif
    endif
endif


.PHONY: toolchaincheck
toolchaincheck:
    ifdef THUMB_FW
        ifndef OPT_USE_GCC_EABI
			$(error ERROR Thumb-2 ports require OPT_USE_GCC_EABI and arm-none-eabi toolchain)
        endif
    endif


.PHONY: fir
fir: version firsub


firsub: toolchaincheck platformcheck all
	mkdir -p $(bin)
	cp $(loader)/main.bin $(bin)/main.bin
    ifdef OPT_ZERO100K
        ifeq ($(OSTYPE),Windows)
			zero | dd bs=1k count=100 >> $(bin)/main.bin 2> $(DEVNULL)
        else
			dd if=/dev/zero bs=1k count=100 >> $(bin)/main.bin 2> $(DEVNULL)
        endif
    endif
    ifdef FW_UPD_FILE
		@echo \-\> $(FW_UPD_FILE)
        ifeq ($(PLATFORMOS),vxworks)
			$(PAKWIF) $(FW_UPD_FILE) $(bin)/main.bin $(TARGET_PID) 0x01000101
        endif
        ifeq ($(PLATFORMOS),dryos)
			$(PAKFI2) $(bin)/main.bin -p $(TARGET_PID) -pv $(PLATFORMOSVER) -key $(FI2KEY) -iv $(FI2IV) $(FW_UPD_FILE)
        endif
    endif
    ifdef NEED_ENCODED_DISKBOOT
		@echo dance \-\> DISKBOOT.BIN ver $(NEED_ENCODED_DISKBOOT)
		$(ENCODE_DISKBOOT) $(bin)/main.bin $(bin)/DISKBOOT.BIN $(NEED_ENCODED_DISKBOOT) 
		rm $(bin)/main.bin
    else
		mv $(bin)/main.bin $(bin)/DISKBOOT.BIN
    endif
	@echo "copy modules"
	rm -f $(chdk)/MODULES/*
	cp $(modules)/$O*.flt $(chdk)/MODULES
	@echo "**** Firmware creation completed successfully"


.PHONY: firbatchsub
firbatchsub: infoline clean firsub


.PHONY: firzip
firzip: version firzipsub


firzipsub: infoline clean firsub
	@echo \-\> $(VER)-$(ZIP_SMALL)
	rm -f $(bin)/$(VER)-$(ZIP_SMALL)
	LANG=C echo "CHDK-$(VER) for $(TARGET_CAM) fw:$(TARGET_FW) build:$(BUILD_NUMBER)-$(BUILD_SVNREV) date:`$(ZIPDATE)`" | \
		zip -9jz $(bin)/$(VER)-$(ZIP_SMALL) $(bin)/DISKBOOT.BIN $(FW_UPD_FILE) > $(DEVNULL)
	rm -f $(bin)/DISKBOOT.BIN $(FW_UPD_FILE)
	zip -9 $(bin)/$(VER)-$(ZIP_SMALL) $(chdk)/MODULES/* > $(DEVNULL)


firzipsubcopy: infoline
	@echo \-\> $(VER)-$(ZIP_SMALL) as a copy of $(VER)-$(ZIP_SMALL_BASE)
	rm -f $(bin)/$(VER)-$(ZIP_SMALL)
	cp $(bin)/$(VER)-$(ZIP_SMALL_BASE) $(bin)/$(VER)-$(ZIP_SMALL)


firzipsubcomplete: infoline clean firsub
	cat $(doc)/1_intro.txt $(cam)/notes.txt $(doc)/2_installation.txt $(doc)/3_faq.txt $(doc)/4_urls.txt $(doc)/5_gpl.txt $(doc)/6_ubasic_copyright.txt > $(doc)/readme.txt
	@echo \-\> $(ZIP_SMALL)
	rm -f $(bin)/$(ZIP_SMALL)
	LANG=C echo "CHDK-$(VER) for $(TARGET_CAM) fw:$(TARGET_FW) build:$(BUILD_NUMBER)-$(BUILD_SVNREV)$(STATE) date:`$(ZIPDATE)`" | \
		zip -9jz $(bin)/$(ZIP_SMALL) $(bin)/DISKBOOT.BIN $(FW_UPD_FILE) $(doc)/changelog.txt $(doc)/readme.txt > $(DEVNULL)
	rm -f $(bin)/DISKBOOT.BIN $(FW_UPD_FILE)
	@echo \-\> $(ZIP_FULL)
	cp -f $(bin)/$(ZIP_SMALL) $(bin)/$(ZIP_FULL)
	zip -9 $(bin)/$(ZIP_SMALL) $(chdk)/MODULES/* > $(DEVNULL)
	zip -9j $(bin)/$(ZIP_FULL) $(tools)/vers.req > $(DEVNULL)
	zip -9r $(bin)/$(ZIP_FULL) $(chdk)/* -x CHDK/logo\*.dat \*Makefile \*.svn\* > $(DEVNULL)


firzipsubcompletecopy: infoline
	@echo \-\> $(ZIP_FULL) as a copy of $(ZIP_FULL_BASE)
	@echo \-\> $(ZIP_SMALL) as a copy of $(ZIP_SMALL_BASE)
	rm -f $(bin)/$(ZIP_SMALL)
	rm -f $(bin)/$(ZIP_FULL)
	cp $(bin)/$(ZIP_SMALL_BASE) $(bin)/$(ZIP_SMALL)
	cp $(bin)/$(ZIP_FULL_BASE) $(bin)/$(ZIP_FULL)


print-missing-dump: platformcheck
	if [ ! -s $(TARGET_PRIMARY) ] ; then \
		echo "missing primary for $(PLATFORM) $(PLATFORMSUB)" ; \
	fi

sigfinders:
	$(MAKE) -C tools finsig_dryos$(EXE)
	$(MAKE) -C tools finsig_vxworks$(EXE)
ifeq ($(OPT_CAPSTONE_TOOLS),1)
	$(MAKE) -C tools finsig_thumb2$(EXE)
endif

rebuild-stubs: platformcheck
	if [ -s $(TARGET_PRIMARY) ] ; then \
		if [ "$(THUMB_FW)" == "1" ] ; then \
			if [ "$(OPT_CAPSTONE_TOOLS)" == "1" ] ; then \
				$(MAKE) -C tools finsig_thumb2$(EXE) ;\
				echo "rebuild stubs for $(PLATFORM)-$(PLATFORMSUB)" ;\
				rm -f $(camfw)/stubs_entry.S ;\
				$(MAKE) -C $(camfw) FORCE_GEN_STUBS=1 stubs_entry.S ;\
			else \
				echo "OPT_CAPSTONE_TOOLS not set, skipping $(PLATFORM)-$(PLATFORMSUB)"; \
			fi ;\
		else \
			$(MAKE) -C tools finsig_dryos$(EXE) ;\
			$(MAKE) -C tools finsig_vxworks$(EXE) ;\
			echo "rebuild stubs for $(PLATFORM)-$(PLATFORMSUB)" ;\
			rm -f $(camfw)/stubs_entry.S ;\
			$(MAKE) -C $(camfw) FORCE_GEN_STUBS=1 stubs_entry.S ;\
		fi ;\
	else \
		echo "!!! missing primary for $(PLATFORM)-$(PLATFORMSUB)"; \
	fi

rebuild-stubs_auto: platformcheck
	echo "rebuild stubs_auto for $(PLATFORM)-$(PLATFORMSUB)" ;\
	rm -f $(camfw)/stubs_auto.S ;\
	$(MAKE) -C $(camfw) stubs_auto.S ;\

run-code-gen: platformcheck
	$(MAKE) -C tools code_gen$(EXE)
	$(MAKE) -C $(camfw) run-code-gen

# note assumes PLATFORMOS is always in same case!
os-camera-list-entry: platformcheck
ifeq ($(SRCFW),)
	echo $(TARGET_CAM),$(TARGET_FW),$(subst _,,$(STATE)),,$(SKIP_AUTOBUILD) >> camera_list_$(PLATFORMOS).csv
else
	echo $(TARGET_CAM),$(TARGET_FW),$(subst _,,$(STATE)),$(SRCFW),$(SKIP_AUTOBUILD) >> camera_list_$(PLATFORMOS).csv
endif

compat-table:
	echo "rebuild loader/generic/compat_table.h"
	sh tools/compatbuilder.sh $(CAMERA_LIST)

# for batch builds, build tools for vx and dryos once, instead of once for every firmware
alltools:
	$(MAKE) -C tools clean all

# for batch builds, build modules once, instead of once for every firmware
allmodules:
	$(MAKE) -C modules clean all THUMB_FW=
    ifeq ($(NO_T2), )
		$(MAKE) -C modules clean all THUMB_FW=1
    endif
	$(MAKE) -C CHDK clean all

# define targets to batch build all cameras & firmware versions
# list of cameras/firmware versions is in 'camera_list.csv'
# each row in 'camera_list.csv' has 5 entries:
# - camera (mandatory)         :- name of camera to build
# - firmware (mandatory)       :- firmware version to build
# - beta status (optional)     :- set to BETA for cameras still in beta status
# - source firmware (optional) :- indicates the build for firmware column is copied *from* this firmware
# - skip auto build (optional) :- any value in this column will exclude the camera/firmware from the auto build

batch: version alltools allmodules
	SKIP_TOOLS=1 SKIP_MODULES=1 SKIP_CHDK=1 sh tools/auto_build.sh $(MAKE) firbatchsub $(CAMERA_LIST) -noskip
	@echo "**** Summary of memisosizes"
	cat $(bin)/caminfo.txt
	rm -f $(bin)/caminfo.txt > $(DEVNULL)

batch-zip: version alltools allmodules
	SKIP_TOOLS=1 SKIP_MODULES=1 SKIP_CHDK=1 sh tools/auto_build.sh $(MAKE) firzipsub $(CAMERA_LIST) $(NO_T2)
	@echo "**** Summary of memisosizes"
	cat $(bin)/caminfo.txt
	rm -f $(bin)/caminfo.txt > $(DEVNULL)

batch-zip-complete: version alltools allmodules
	SKIP_TOOLS=1 SKIP_MODULES=1 SKIP_CHDK=1 sh tools/auto_build.sh $(MAKE) firzipsubcomplete $(CAMERA_LIST) $(NO_T2)
	@echo "**** Summary of memisosizes"
	cat $(bin)/caminfo.txt
	rm -f $(bin)/caminfo.txt > $(DEVNULL)

# note, this will include cameras with SKIP_AUTOBUILD set
# doesn't include copied firmwares
os-camera-lists:
	echo 'CAMERA,FIRMWARE,BETA_STATUS,SOURCE_FIRMWARE,SKIP_AUTOBUILD' > camera_list_dryos.csv
	echo 'CAMERA,FIRMWARE,BETA_STATUS,SOURCE_FIRMWARE,SKIP_AUTOBUILD' > camera_list_vxworks.csv
	sh tools/auto_build.sh $(MAKE) os-camera-list-entry $(CAMERA_LIST) -noskip

# make sure each enabled firmware/sub has a PRIMARY.BIN
# Note this will not fail, just prints all the missing ones
batch-print-missing-dumps:
	sh tools/auto_build.sh $(MAKE) print-missing-dump $(CAMERA_LIST) -noskip

# rebuild all the stubs_entry.S files
batch-rebuild-stubs:
	sh tools/auto_build.sh $(MAKE) rebuild-stubs $(CAMERA_LIST) -noskip

# rebuild all the stubs_auto.S files
batch-rebuild-stubs_auto:
	sh tools/auto_build.sh $(MAKE) rebuild-stubs_auto $(CAMERA_LIST) -noskip

# rebuild all the stubs_entry.S files
# parallel version, starts each camera/firmware version build in a seperate session
# Note:- Windows only, this will use all available CPU and a fair amount of memory
#        but will rebuild much faster on a machine with many CPU cores
batch-rebuild-stubs-parallel: sigfinders
	sh tools/auto_build_parallel.sh $(MAKE) rebuild-stubs $(CAMERA_LIST) start -noskip

# *nix version, may work on Windows too
# Note:- needs GNU Parallel, runs one job per CPU core
batch-rebuild-stubs-gnu-parallel: sigfinders
	sh tools/auto_build_parallel.sh $(MAKE) rebuild-stubs $(CAMERA_LIST) echo -noskip | parallel

batch-clean:
	$(MAKE) -C tools clean
	$(MAKE) -C modules clean THUMB_FW=
	$(MAKE) -C modules clean THUMB_FW=1
	$(MAKE) -C CHDK clean
	SKIP_MODULES=1 SKIP_CHDK=1 SKIP_TOOLS=1 sh tools/auto_build.sh $(MAKE) clean $(CAMERA_LIST) -noskip

batch-run-code-gen:
	SKIP_MODULES=1 SKIP_CHDK=1 SKIP_TOOLS=1 sh tools/auto_build.sh $(MAKE) run-code-gen $(CAMERA_LIST) -noskip
