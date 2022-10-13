# ixus110_sd960 - 101g uses 101f source (identical firmware)

TARGET_FW:=$(PLATFORMSUB)

override PLATFORMSUB=101f

include $(camfw)/makefile.inc
