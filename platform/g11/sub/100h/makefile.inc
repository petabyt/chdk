# g11 - 100h uses 100j source (identical firmware)

TARGET_FW:=$(PLATFORMSUB)

override PLATFORMSUB=100j

include $(camfw)/makefile.inc
