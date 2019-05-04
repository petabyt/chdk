# ixus850_sd800 - 100d uses 100e source (identical firmware)

TARGET_FW:=$(PLATFORMSUB)

override PLATFORMSUB=100e

include $(camfw)/makefile.inc
