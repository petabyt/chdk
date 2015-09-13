# SX270HS - uses SX280HS as source camera

TARGET_PID=12896
TARGET_CAM:=$(PLATFORM)
TARGET_FW=$(PLATFORMSUB)

override PLATFORM=sx280hs

include $(camfw)/makefile.inc
