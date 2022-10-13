# a2200 - 100c uses 100b source (identical firmware)

TARGET_FW:=$(PLATFORMSUB)

override PLATFORMSUB=100b

include $(camfw)/makefile.inc
