# g5x - 101c uses 101b source (identical firmware)

TARGET_FW:=$(PLATFORMSUB)

override PLATFORMSUB=101b

include $(camfw)/makefile.inc
