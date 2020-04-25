# g5x - 110a uses 101d source (identical firmware)

TARGET_FW:=$(PLATFORMSUB)

override PLATFORMSUB=101d

include $(camfw)/makefile.inc
