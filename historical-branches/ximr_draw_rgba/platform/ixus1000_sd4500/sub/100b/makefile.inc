# ixus1000_sd4500 - 100b uses 100d source (identical firmware)

TARGET_FW:=$(PLATFORMSUB)

override PLATFORMSUB=100d

include $(camfw)/makefile.inc
