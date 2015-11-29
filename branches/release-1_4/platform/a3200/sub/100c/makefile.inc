# a3200 - 100c uses 100a source (identical firmware)

TARGET_FW:=$(PLATFORMSUB)

override PLATFORMSUB=100a

include $(camfw)/makefile.inc
