# sx510hs - 100a uses 100d source (identical firmware)

TARGET_FW:=$(PLATFORMSUB)

override PLATFORMSUB=100d

include $(camfw)/makefile.inc
