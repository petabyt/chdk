# Build rules for camera / firmware specific code - mixed ARM and THUMB code

include $(topdir)makefile_base.inc

# Load camera firmware settings
ifdef PLATFORMSUB
  include $(camfw)/makefile.inc
  ifndef MEMBASEADDR
    MEMBASEADDR=0x1900
  endif
  PLFLAGS=-DMEMBASEADDR=$(MEMBASEADDR) -DMEMISOSTART=$(MEMISOSTART) -DMEMISOSIZE=$(MEMISOSIZE)
  ifdef RESTARTSTART
    PLFLAGS+=-DRESTARTSTART=$(RESTARTSTART)
  endif
  ifeq ($(PLATFORMOS),dryos)
    ifeq ($(PLATFORMOSVER),)
      $(error PLATFORMOSVER not defined for DryOS cam)
    endif
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

# Used in gui_debug.c for controlling memory browser allowed address ranges
# override in platform/$(PLATFORM)/sub/$(PLATFORMSUB)/makefile.inc to set camera specific value
ifdef MAXRAMADDR
PLFLAGS+=-DMAXRAMADDR=$(MAXRAMADDR)
else
PLFLAGS+=-DMAXRAMADDR=0x1FFFFFF
endif
ifdef ROMBASEADDR
PLFLAGS+=-DROMBASEADDR=$(ROMBASEADDR)
else
PLFLAGS+=-DROMBASEADDR=0xFFC00000
endif

include $(topdir)arm_rules.inc

ifdef OPT_FI2
-include $(platform)/fi2.inc
endif

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
