topdir=./

tmp:=$(shell echo "BUILD_SVNREV := $(DEF_SVN_REF)" > revision.inc)

# can override on command line or *buildconf.inc for custom subsets
CAMERA_LIST=camera_list.csv

# set date command for ZIP files - override in localbuildconf.inc if needed
#  e.g. OS/X date command does not support -R option, use GNU date (gdate) from coreutils 
ZIPDATE=date -R

include makefile_cam.inc

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

# Must do platform before loader
SUBDIRS+=$(cam) $(camfw)

# Must do this last as it builds the final .bin file
SUBDIRS+=$(loader)


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
	@echo "**** GCC $(GCC_VERSION) : BUILDING CHDK-$(VER), #$(BUILD_NUMBER)-$(BUILD_SVNREV)$(STATE) FOR $(PLATFORM)-$(PLATFORMSUB)"

.PHONY: version
version: FORCE
	echo "**** Build: $(BUILD_NUMBER)"

.PHONY: FORCE
FORCE:


ZIP_SMALL=$(PLATFORM)-$(PLATFORMSUB)-$(BUILD_NUMBER)-$(BUILD_SVNREV)$(STATE).zip
ZIP_FULL=$(PLATFORM)-$(PLATFORMSUB)-$(BUILD_NUMBER)-$(BUILD_SVNREV)-full$(STATE).zip
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


.PHONY: fir
fir: version firsub


firsub: platformcheck all
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
			$(PAKWIF) $(FW_UPD_FILE) $(bin)/main.bin $(PLATFORMID) 0x01000101
        endif
        ifeq ($(PLATFORMOS),dryos)
			$(PAKFI2) $(bin)/main.bin -p $(PLATFORMID) -pv $(PLATFORMOSVER) -key $(FI2KEY) -iv $(FI2IV) $(FW_UPD_FILE)
        endif
    endif
    ifdef NEED_ENCODED_DISKBOOT
		@echo dance \-\> DISKBOOT.BIN ver $(NEED_ENCODED_DISKBOOT)
		$(ENCODE_DISKBOOT) $(bin)/main.bin $(bin)/DISKBOOT.BIN $(NEED_ENCODED_DISKBOOT) 
		rm $(bin)/main.bin
    else
		mv $(bin)/main.bin $(bin)/DISKBOOT.BIN
    endif
	@echo "**** Firmware creation completed successfully"


.PHONY: firzip
firzip: version firzipsub


firzipsub: infoline clean firsub
	@echo \-\> $(VER)-$(ZIP_SMALL)
	rm -f $(bin)/$(VER)-$(ZIP_SMALL)
	LANG=C echo "CHDK-$(VER) for $(PLATFORM) fw:$(PLATFORMSUB) build:$(BUILD_NUMBER)-$(BUILD_SVNREV) date:`$(ZIPDATE)`" | \
		zip -9jz $(bin)/$(VER)-$(ZIP_SMALL) $(bin)/DISKBOOT.BIN $(FW_UPD_FILE) > $(DEVNULL)
	rm -f $(bin)/DISKBOOT.BIN $(FW_UPD_FILE)
	zip -9 $(bin)/$(VER)-$(ZIP_SMALL) $(chdk)/MODULES/* > $(DEVNULL)

    # if COPY_TO is defined then copy this camera/firmware version to the copied firmware version
    # COPY_TO is extracted from camera_list.csv for batch builds.
	# For the case where one CHDK version applies to two or more other Canon firmware version place all the
	# 'copy to' firmware versions together seperated by ':' - e.g. "a2000,100c,BETA,100a:100b,"
    ifdef COPY_TO
		@echo "**** Copying duplicate Firmwares"
		$(foreach COPY_PLATFORMSUB, $(subst :, ,$(COPY_TO)), \
			cp $(bin)/$(VER)-$(ZIP_SMALL) $(bin)/$(VER)-$(PLATFORM)-$(COPY_PLATFORMSUB)-$(BUILD_NUMBER)-$(BUILD_SVNREV)$(STATE).zip ; \
		)
    endif


firzipsubcomplete: infoline clean firsub
	cat $(doc)/1_intro.txt $(cam)/notes.txt $(doc)/2_installation.txt $(doc)/3_faq.txt $(doc)/4_urls.txt $(doc)/5_gpl.txt $(doc)/6_ubasic_copyright.txt > $(doc)/readme.txt
	@echo \-\> $(ZIP_SMALL)
	rm -f $(bin)/$(ZIP_SMALL)
	LANG=C echo "CHDK-$(VER) for $(PLATFORM) fw:$(PLATFORMSUB) build:$(BUILD_NUMBER)-$(BUILD_SVNREV)$(STATE) date:`$(ZIPDATE)`" | \
		zip -9jz $(bin)/$(ZIP_SMALL) $(bin)/DISKBOOT.BIN $(FW_UPD_FILE) $(doc)/changelog.txt $(doc)/readme.txt > $(DEVNULL)
	rm -f $(bin)/DISKBOOT.BIN $(FW_UPD_FILE)
	@echo \-\> $(ZIP_FULL)
	cp -f $(bin)/$(ZIP_SMALL) $(bin)/$(ZIP_FULL)
	zip -9 $(bin)/$(ZIP_SMALL) $(chdk)/MODULES/* > $(DEVNULL)
	zip -9j $(bin)/$(ZIP_FULL) $(tools)/vers.req > $(DEVNULL)
	zip -9r $(bin)/$(ZIP_FULL) $(chdk)/* -x CHDK/logo\*.dat \*Makefile > $(DEVNULL)

    # if COPY_TO is defined then copy this camera/firmware version to the copied firmware version
    # COPY_TO is extracted from camera_list.csv for batch builds.
	# For the case where one CHDK version applies to two or more other Canon firmware version place all the
	# 'copy to' firmware versions together seperated by ':' - e.g. "a2000,100c,BETA,100a:100b,"
    ifdef COPY_TO
		@echo "**** Copying duplicate Firmwares"
		$(foreach COPY_PLATFORMSUB, $(subst :, ,$(COPY_TO)), \
			cp $(bin)/$(ZIP_FULL) $(bin)/$(PLATFORM)-$(COPY_PLATFORMSUB)-$(BUILD_NUMBER)-$(BUILD_SVNREV)-full$(STATE).zip ; \
			cp $(bin)/$(ZIP_SMALL) $(bin)/$(PLATFORM)-$(COPY_PLATFORMSUB)-$(BUILD_NUMBER)-$(BUILD_SVNREV)$(STATE).zip ; \
		)
    endif

print-missing-dump: platformcheck
	if [ ! -s $(TARGET_PRIMARY) ] ; then \
		echo "missing primary for $(PLATFORM) $(PLATFORMSUB)" ; \
	fi

rebuild-stubs: platformcheck
	if [ -s $(TARGET_PRIMARY) ] ; then \
		$(MAKE) -C tools finsig_dryos$(EXE) ;\
		$(MAKE) -C tools finsig_vxworks$(EXE) ;\
		echo "rebuild stubs for $(PLATFORM)-$(PLATFORMSUB)" ;\
		rm -f $(camfw)/stubs_entry.S ;\
		$(MAKE) -C $(camfw) FORCE_GEN_STUBS=1 stubs_entry.S ;\
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
	echo $(PLATFORM),$(PLATFORMSUB),$(subst _,,$(STATE)),$(COPY_TO),$(SKIP_AUTOBUILD) >> camera_list_$(PLATFORMOS).csv

# for batch builds, build tools for vx and dryos once, instead of once for every firmware
alltools:
	$(MAKE) -C tools clean all

# for batch builds, build modules once, instead of once for every firmware
allmodules:
	$(MAKE) -C modules clean all
	$(MAKE) -C CHDK clean all

# define targets to batch build all cameras & firmware versions
# list of cameras/firmware versions is in 'camera_list.csv'
# each row in 'camera_list.csv' has 5 entries:
# - camera (mandatory)         :- name of camera to build
# - firmware (mandatory)       :- firmware version to build
# - beta status (optional)     :- set to BETA for cameras still in beta status
# - copy to (optional)         :- if this firmware version can also be used for another version on the same
#                                 camera define the alternate firmware here. see COPY_TO comments above.
# - skip auto build (optional) :- any value in this column will exclude the camera/firmware from the auto build

batch: version alltools allmodules
	SKIP_TOOLS=1 SKIP_MODULES=1 SKIP_CHDK=1 sh tools/auto_build.sh $(MAKE) firsub $(CAMERA_LIST) -noskip
	@echo "**** Summary of memisosizes"
	cat $(bin)/caminfo.txt
	rm -f $(bin)/caminfo.txt > $(DEVNULL)

batch-zip: version alltools allmodules
	SKIP_TOOLS=1 SKIP_MODULES=1 SKIP_CHDK=1 sh tools/auto_build.sh $(MAKE) firzipsub $(CAMERA_LIST)
	@echo "**** Summary of memisosizes"
	cat $(bin)/caminfo.txt
	rm -f $(bin)/caminfo.txt > $(DEVNULL)

batch-zip-complete: version alltools allmodules
	SKIP_TOOLS=1 SKIP_MODULES=1 SKIP_CHDK=1 sh tools/auto_build.sh $(MAKE) firzipsubcomplete $(CAMERA_LIST)
	@echo "**** Summary of memisosizes"
	cat $(bin)/caminfo.txt
	rm -f $(bin)/caminfo.txt > $(DEVNULL)

# note, this will include cameras with SKIP_AUTOBUILD set
os-camera-lists:
	echo 'CAMERA,FIRMWARE,BETA_STATUS,COPY_TO,SKIP_AUTOBUILD' > camera_list_dryos.csv
	echo 'CAMERA,FIRMWARE,BETA_STATUS,COPY_TO,SKIP_AUTOBUILD' > camera_list_vxworks.csv
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
batch-rebuild-stubs-parallel:
	sh tools/auto_build_parallel.sh $(MAKE) rebuild-stubs $(CAMERA_LIST) -noskip

batch-clean:
	$(MAKE) -C tools clean
	$(MAKE) -C modules clean
	$(MAKE) -C CHDK clean
	SKIP_MODULES=1 SKIP_CHDK=1 SKIP_TOOLS=1 sh tools/auto_build.sh $(MAKE) clean $(CAMERA_LIST) -noskip

batch-run-code-gen:
	SKIP_MODULES=1 SKIP_CHDK=1 SKIP_TOOLS=1 sh tools/auto_build.sh $(MAKE) run-code-gen $(CAMERA_LIST) -noskip
