# sx20 - 102c uses 102d source (identical firmware)

TARGET_FW:=$(PLATFORMSUB)

override PLATFORMSUB=102d

include $(camfw)/makefile.inc
