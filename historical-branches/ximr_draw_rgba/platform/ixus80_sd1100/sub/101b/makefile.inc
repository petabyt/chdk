# ixus80_sd1100 - 101b uses 101a source (identical firmware)

TARGET_FW:=$(PLATFORMSUB)

override PLATFORMSUB=101a

include $(camfw)/makefile.inc
