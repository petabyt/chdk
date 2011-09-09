#!platform build time optional settings

BUILD_NUMBER := $(BUILD_NUMBER)-Alpha8

# Force EXMEM - not enough Canon heap space!
override OPT_EXMEM_MALLOC=1
override OPT_CHDK_IN_EXMEM=1
