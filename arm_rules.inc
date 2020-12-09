# ARM GCC rules

CROSS_COMPILE=arm-none-eabi-

CC=$(CROSS_COMPILE)gcc
OBJCOPY=$(CROSS_COMPILE)objcopy
OBJDUMP=$(CROSS_COMPILE)objdump
STRIP=$(CROSS_COMPILE)strip
NM=$(CROSS_COMPILE)nm
AR=$(CROSS_COMPILE)ar
RANLIB=$(CROSS_COMPILE)ranlib
SIZE=$(CROSS_COMPILE)size

GCC_VERSION=$(shell $(CC) -dumpversion)
GCC_VERSION_MAJOR=$(firstword $(subst ., ,$(GCC_VERSION)))

# check for valid GCC version.
# Add DISABLE_GCC_VERSION_CHECK=1 to localbuildconf.inc if you know what you are doing
ifndef DISABLE_GCC_VERSION_CHECK
    ifneq ($(GCC_VERSION_MAJOR),$(filter $(GCC_VERSION_MAJOR),4 5 8 9 10))
        $(error Invalid GCC version. CHDK build is supported on GCC 4, 5, 8 or 9. GCC 10 support is experimental.)
    endif
    ifeq ($(GCC_VERSION_MAJOR),$(filter $(GCC_VERSION_MAJOR),10))
        $(warning Unsupported GCC version. CHDK build is supported on GCC 4, 5, 8 or 9. GCC 10 support is experimental.)
    endif
endif

# -fno-schedule-insns2 for this gcc bug http://gcc.gnu.org/bugzilla/show_bug.cgi?id=38644
# technically not required for gcc >= 4.6.3, and probably not required for vxworks cams
# see http://chdk.setepontos.com/index.php?topic=8273.msg100205#msg100205
CFLAGS=-fno-inline -Os -fno-strict-aliasing -fno-schedule-insns2
# for gcc >= v4, we want to allow use of strd etc
# Also set architecture version for modules (to prevent loading on wrong build)
ifndef THUMB_FW
    CFLAGS+=-mtune=arm946e-s -march=armv5te -DOPT_ARCHITECTURE=GCC_EABI_THUMB
else
    ifdef DIGIC7
        CFLAGS+=-march=armv7-a -mthumb -DTHUMB_FW -DOPT_ARCHITECTURE=GCC_EABI_THUMB2A
    else
        CFLAGS+=-march=armv7-r -mthumb -DTHUMB_FW -DOPT_ARCHITECTURE=GCC_EABI_THUMB2
    endif
endif

CFLAGS+=-I$(include) -I$(core) -I$(modules) -I$(cam) $(PLFLAGS)
CFLAGS+=-DVER_$(VER) -DHDK_VERSION=\"$(VER)\" -DBUILD_NUMBER=\"$(BUILD_NUMBER)\" -DBUILD_SVNREV=\"$(BUILD_SVNREV)\"
CFLAGS+=-Wall -Wno-unused -Wno-format

ifdef OPT_CURVES
CFLAGS+=-DOPT_CURVES
endif

ifdef OPT_MD_DEBUG
CFLAGS+=-DOPT_MD_DEBUG
endif 

ifdef OPT_VIEWPORT_DEBUG
CFLAGS+=-DOPT_VIEWPORT_DEBUG
endif

ifdef OPT_DEBUGGING
CFLAGS+=-DOPT_DEBUGGING
endif

ifdef OPT_PTP
CFLAGS+=-DOPT_PTP
endif

ifdef OPT_FORCE_LUA_CALL_NATIVE
CFLAGS+=-DOPT_FORCE_LUA_CALL_NATIVE
endif

ifdef OPT_ARAM_MALLOC
CFLAGS+=-DOPT_ARAM_MALLOC -DARAM_HEAP_START=$(ARAM_HEAP_START) -DARAM_HEAP_SIZE=$(ARAM_HEAP_SIZE)
# Only allow OPT_CHDK_IN_ARAM when OPT_ARAM_MALLOC is also defined
ifdef OPT_CHDK_IN_ARAM
CFLAGS+=-DOPT_CHDK_IN_ARAM -DCHDK_NOT_IN_CANON_HEAP
endif
endif   # OPT_ARAM_MALLOC

ifdef OPT_ARAM_TESTING
CFLAGS+=-DOPT_ARAM_TESTING
endif

ifdef OPT_EXMEM_MALLOC
CFLAGS+=-DOPT_EXMEM_MALLOC
# Only allow OPT_CHDK_IN_EXMEM when OPT_EXMEM_MALLOC is also defined
ifdef OPT_CHDK_IN_EXMEM
CFLAGS+=-DOPT_CHDK_IN_EXMEM -DCHDK_NOT_IN_CANON_HEAP
override OPT_FIRMWARE_PC24_CALL=
endif
endif   # OPT_EXMEM_MALLOC

ifdef OPT_EXMEM_TESTING
CFLAGS+=-DOPT_EXMEM_TESTING
endif

ifdef EXMEM_HEAP_SKIP
CFLAGS+=-DEXMEM_HEAP_SKIP=$(EXMEM_HEAP_SKIP)
endif

ifdef EXMEM_BUFFER_SIZE
CFLAGS+=-DEXMEM_BUFFER_SIZE=$(EXMEM_BUFFER_SIZE)
endif

ifdef OPT_FIRMWARE_PC24_CALL
CFLAGS+=-DOPT_FIRMWARE_PC24_CALL
endif

ifdef OPT_RUN_WITH_BATT_COVER_OPEN
CFLAGS+=-DOPT_RUN_WITH_BATT_COVER_OPEN
endif

ifdef OPT_DBG_LUA_ASSERT
CFLAGS+=-DOPT_DBG_LUA_ASSERT
endif

# make sure this is either 0 or 1
ifdef OPT_DISABLE_CAM_ERROR
CFLAGS+=-DOPT_DISABLE_CAM_ERROR=1
else
CFLAGS+=-DOPT_DISABLE_CAM_ERROR=0
endif

ifdef OPT_WARNINGS
    CFLAGS+=-Wextra -Wunused
    ifeq ($(GCC_VERSION_MAJOR),$(filter $(GCC_VERSION_MAJOR),8 9 10))
        CFLAGS+=-Wno-builtin-declaration-mismatch -Wno-implicit-fallthrough -Wno-cast-function-type
    endif
endif

ifdef OPT_EXPIRE_TEST
# convert +n days to unix-ish timestamp
EXPIRE_TIME:=$(shell expr `date +%s` + $(OPT_EXPIRE_TEST) '*' 86400)
CFLAGS+= -DOPT_EXPIRE_TEST=$(EXPIRE_TIME)
endif

ifdef OPT_FILEIO_STATS
CFLAGS+=-DOPT_FILEIO_STATS
endif


# Define empty recipes for source files (including the makefiles)
# to prevent make from trying implicit rules to create them. Speeds up build process
$(topdir)arm_rules.inc: ;
