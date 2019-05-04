# sx30 - 100m uses 100l source (identical firmware)

TARGET_FW:=$(PLATFORMSUB)

override PLATFORMSUB=100l

include $(camfw)/makefile.inc
