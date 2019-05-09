# ixus960_sd950 - 100c uses 100d source (identical firmware)

TARGET_FW:=$(PLATFORMSUB)

override PLATFORMSUB=100d

include $(camfw)/makefile.inc
