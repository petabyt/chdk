# ixus140_elph130 - 100b uses 100a source (identical firmware)

TARGET_FW:=$(PLATFORMSUB)

override PLATFORMSUB=100a

include $(camfw)/makefile.inc
