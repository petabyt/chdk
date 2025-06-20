#include "stubs_asm.h"

NHSTUB(Close,  0xFFE3B614) 
NHSTUB(Read,   0xFFE3B6A8) 
NHSTUB(Write,  0xFFE3B6B4) 
NHSTUB(Remove, 0xFFE3B634) 
NHSTUB(Mount_FileSystem, 0xFFE3A938)
NHSTUB(kbd_read_keys_r2, 0xFFDDD0C0)
NHSTUB(DisplayImagePhysicalScreen, 0xFFDD1AE0)
NHSTUB(kbd_pwr_off, 0xFFDDD708)
NHSTUB(SetPropertyCase, 0xFFC0BB80)
NHSTUB(FreeMemory, 0xFFC08670)
NHSTUB(GetFocusLensSubjectDistance, 0xFFE685A0)
NHSTUB(free, 0xFFCD1704)
NHSTUB(SetZoomActuatorSpeedPercent, 0xFFDD3094) //null stub
NHSTUB(GetDrive_ClusterSize, 0xFFE3AE00)
NHSTUB(GetDrive_TotalClusters, 0xFFE3AE3C)
NHSTUB(GetDrive_FreeClusters, 0xFFE3AE78)
NHSTUB(WriteSDCard, 0xFFE4D9A8)
NHSTUB(TurnOffMic, 0xffdde07c)
NHSTUB(TurnOnMic, 0xffdde040)
NHSTUB(ExpCtrlTool_StopContiAE,  0xFFD15CE8) 
NHSTUB(ExpCtrlTool_StartContiAE, 0xFFD15CB8) 
NHSTUB(MakeAFScan,               0xFFE952B8) 
NHSTUB(GetBatteryTemperature, 0xFFDE0734)
NHSTUB(GetCCDTemperature, 0xFFDE0720)
NHSTUB(GetOpticalTemperature, 0xFFDE070C)
NHSTUB(PT_PlaySound, 0xFFEA01F4)

NHSTUB(EnterToCompensationEVF, 0xffe90258)
NHSTUB(ExitFromCompensationEVF, 0xffe902dc)
