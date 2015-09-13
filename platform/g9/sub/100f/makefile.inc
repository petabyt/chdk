# g9 - 100f uses 100g source (identical firmware)

TARGET_FW:=$(PLATFORMSUB)

override PLATFORMSUB=100g

include $(camfw)/makefile.inc
