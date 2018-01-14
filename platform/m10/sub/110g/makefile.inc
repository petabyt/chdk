# m10 - 110g uses 110f source (identical firmware)

TARGET_FW:=$(PLATFORMSUB)

override PLATFORMSUB=110f

include $(camfw)/makefile.inc
