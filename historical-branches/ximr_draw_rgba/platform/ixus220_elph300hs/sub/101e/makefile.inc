# ixus220_elph300hs - 101e uses 101c source (identical firmware)

TARGET_FW:=$(PLATFORMSUB)

override PLATFORMSUB=101c

include $(camfw)/makefile.inc
