#!build time optional components - comment out the features you dont want to have in your build or copy this file to localbuildconf.inc and override settings there
OPT_GAMES=1
OPT_CURVES=1
OPT_TEXTREADER=1
OPT_CALENDAR=1
OPT_DEBUGGING=1
OPT_EDGEOVERLAY=1

# Old-style user menu
#OPT_USER_MENU=1
# Profiles and Profile Menu
OPT_PROFILES=1

# Scripting components
OPT_UBASIC=1
OPT_LUA=1
OPT_LUA_STRLIB=1
OPT_LUA_IOLIB=1
OPT_LUA_OSLIB=1
# allow Lua to call arbitrary ROM functions and eventprocs
# WARNING: This is DANGEROUS. e.g. call_event_proc("EraseSectorOfRom",...)
# NOTE: the interface for this may change in the future, to support better support buffers etc
#OPT_LUA_CALL_NATIVE=1

# experimental - allocate memory from alternate heap. Default 2MB from EXMEM_RAMDISK
# See exmem_malloc_init in generic/wrappers.c
#OPT_EXMEM_MALLOC=1
# Set OPT_CHDK_IN_EXMEM to build and load CHDK into EXMEM memory 
# Need to define MEMISOSTART and EXMEM values in PLATFORM/PLATFORMSUB/makefile.inc (see G12 or SX30 for example)
# (if setting this must also set OPT_EXMEM_MALLOC !)
#OPT_CHDK_IN_EXMEM=1
# set this to enable exmem corruption testing (see wrappers.c). (Don't set OPT_CHDK_IN_EXMEM with this !)
#OPT_EXMEM_TESTING=1

# experimental PTP/USB interface
OPT_PTP=1
 
# code to dump stack and other debug information, see core/dbg_dump.c
#OPT_DBG_DUMP=1

# record asserts in lua C code with dbg_dump_assert
# requires OPT_DBG_DUMP
#OPT_DBG_LUA_ASSERT=1

#OPT_MD_DEBUG=1
# needs proper fi2.inc in platform/ !!! see http://chdk.setepontos.com/index.php/topic,2995.0.html
#OPT_FI2=1
# if enabled, compiler will produce a lot of warnings, maybe not always correct ones, see http://chdk.setepontos.com/index.php/topic,2509.msg32191.html#msg32191
#OPT_WARNINGS=1
# If enabled (and reference binaries are present in /tools), compiler will generate function signatures
OPT_GEN_SIGS=1
# If enabled (and firmware binaries are present) compiler will update "stubs_entry.S"
OPT_GEN_STUBS=1
# the symbols / not done yet
#!OPT_SYMBOLS=1
# for people who won't use lang files at all / not done yet
#!OPT_LANGUAGEINTERFACE=1
# for CHDK-DE presets without OPT_DEFAULT_LANG
#OPT_DE_VERSION=1

# Override the value below to compile a different default language into
# the core CHDK code. This will save memory by not loading both english and the
# desired language.
# Set the value to the language file name without extension - e.g. OPT_DEFAULT_LANG=russian
#OPT_DEFAULT_LANG=

# Default svn revision. Used when svnversion fail.
DEF_SVN_REF=0
