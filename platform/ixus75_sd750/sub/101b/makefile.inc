# ixus75_sd750 - 101b uses 101a source (identical firmware)

TARGET_FW:=$(PLATFORMSUB)

override PLATFORMSUB=101a

include $(camfw)/makefile.inc
