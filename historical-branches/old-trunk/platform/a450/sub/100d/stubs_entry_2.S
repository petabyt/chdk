#include "stubs_asm.h"

// maybe 0xFFDBA0A8 but it is not used in CHDK at all
NHSTUB(DisplayImagePhysicalScreen, 0xFFDBA0B8)

NHSTUB(Mount_FileSystem, 0xFFE1CB08)
NHSTUB(free, 0xFFCCC768)
NHSTUB(kbd_read_keys_r2, 0xFFDC4AD8) 

NHSTUB(SetZoomActuatorSpeedPercent, 0xFFDC4AD4)  //null stub
       
NHSTUB(kbd_pwr_off, 0xFFDC4AD4)   //null stub
NHSTUB(kbd_pwr_on, 0xFFDC4AD4)    //null stub                                                      

NHSTUB(SetPropertyCase,0xFFC0B664) 

NHSTUB(GetDrive_ClusterSize, 0xFFE1CFD0)
NHSTUB(GetDrive_TotalClusters, 0xFFE1D00C)
NHSTUB(GetDrive_FreeClusters, 0xFFE1D048)
NHSTUB(TurnOffMic, 0xFFDC5854)
NHSTUB(TurnOnMic, 0xFFDC5818)
NHSTUB(ExpCtrlTool_StopContiAE,  0xFFD0DCE0) 
NHSTUB(ExpCtrlTool_StartContiAE, 0xFFD0DCB0) 
NHSTUB(MakeAFScan,               0xFFE7003C) 
NHSTUB(SetAE_ShutterSpeed, 0xFFDE17BC)
