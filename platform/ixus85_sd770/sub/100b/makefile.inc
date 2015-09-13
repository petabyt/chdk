# ixus85_sd770 - 100b uses 100a source (identical firmware)

TARGET_FW:=$(PLATFORMSUB)

override PLATFORMSUB=100a

include $(camfw)/makefile.inc
