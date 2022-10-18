# g5x - 101e uses 101d source (identical firmware)

TARGET_FW:=$(PLATFORMSUB)

override PLATFORMSUB=101d

include $(camfw)/makefile.inc
