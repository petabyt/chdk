# ixus310_elph500hs - 101b uses 101c source (identical firmware)

TARGET_FW:=$(PLATFORMSUB)

override PLATFORMSUB=101c

include $(camfw)/makefile.inc
