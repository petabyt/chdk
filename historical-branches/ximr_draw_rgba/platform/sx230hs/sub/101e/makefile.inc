# sx230hs - 101e uses 101b source (identical firmware)

TARGET_FW:=$(PLATFORMSUB)

override PLATFORMSUB=101b

include $(camfw)/makefile.inc
