# g9 - 100h uses 100i source (identical firmware)

TARGET_FW:=$(PLATFORMSUB)

override PLATFORMSUB=100i

include $(camfw)/makefile.inc
