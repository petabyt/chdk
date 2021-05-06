# Build rules for camera / firmware specific code - mixed ARM and THUMB code

include $(topdir)makefile_base.inc

# Load camera firmware settings
ifdef PLATFORMSUB
  include $(camfw)/makefile.inc
  
  # Check for valid values
  ifeq ($(PLATFORMOS),dryos)
    ifeq ($(PLATFORMOSVER),)
      $(error PLATFORMOSVER not defined for DryOS cam)
    endif
  endif
  ifndef ROMBASEADDR
    $(error ROMBASEADDR not defined)
  endif

  ifndef MEMBASEADDR
    ifdef THUMB_FW
      MEMBASEADDR=0x8000
    else
      MEMBASEADDR=0x1900
    endif
  endif

  # MAXRAMADDR used in gui_debug.c for controlling memory browser allowed address ranges
  # override in platform/$(PLATFORM)/sub/$(PLATFORMSUB)/makefile.inc to set camera specific value
  ifndef MAXRAMADDR
    MAXRAMADDR=0x1FFFFFF
  endif
endif

ifndef TARGET_CAM
  TARGET_CAM=$(PLATFORM)
endif
ifndef TARGET_FW
  TARGET_FW=$(PLATFORMSUB)
endif
ifndef TARGET_PID
  TARGET_PID=$(PLATFORMID)
endif
ifeq ($(TARGET_PID),)
  override TARGET_PID=$(PLATFORMID)
endif

include $(topdir)arm_rules.inc

ifdef OPT_FI2
  -include $(platform)/fi2.inc
endif

CFLAGS+=-DMEMBASEADDR=$(MEMBASEADDR) -DMEMISOSTART=$(MEMISOSTART) -DMEMISOSIZE=$(MEMISOSIZE) -DMAXRAMADDR=$(MAXRAMADDR) -DROMBASEADDR=$(ROMBASEADDR) -DCAM_DIGIC=$(DIGIC)
CFLAGS+=-mthumb-interwork -DLOW_LEVEL -DPLATFORM=\"$(TARGET_CAM)\" -DPLATFORMSUB=\"$(TARGET_FW)\" -DPLATFORMID=$(TARGET_PID) -DCAMERA_$(PLATFORM)=1
ifeq ($(PLATFORMOS),dryos)
  CFLAGS+=-DCAM_DRYOS_REL=$(PLATFORMOSVER)
endif

include $(topdir)build_rules.inc

# Define empty recipes for source files (including the makefiles)
# to prevent make from trying implicit rules to create them. Speeds up build process
$(topdir)makefile_cam.inc: ;
$(camfw)/makefile.inc: ;
$(platform)/fi2.inc: ;
