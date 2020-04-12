#include "stubs_asm.h"
// BEWARE: thumb functions NEED the thumb bit in the below list

#define NULL_SUB	0xfc0200ad	// bx lr
#define RET1		0xfc021f4d	// mov r0, #1 ; bx lr
#define RET0		0xfc0211ed	// mov r0, #0 ; bx lr

NHSTUB(Feof_Fut,								0xfc34c989) // Ghidra exact mne v sx710
NHSTUB(Fflush_Fut,								0xfc34c9b1) // "
NHSTUB(SetFileTimeStamp,						0xfc3517db) // "
NHSTUB(SetFileAttributes,						0xfc351823) // after SetFileTimeStamp in ROM
NHSTUB(RenameFile_Fut,							0xfc34c739) // Ghidra exact
NHSTUB(MakeSDCardBootable,						0xfc3529fd) // Ghidra implied, "BOOTDISK" string
NHSTUB(GetFocusLensSubjectDistanceFromLens,		0xfc3344e3) // Ghidra implied, fc131dbe like sx710 fc141b0c 

NHSTUB(GetImageFolder,							0xfc32f40f) // based on ref to fc3344e2 (ref "%s/%3d%s"), exact match sx710 fc31152e

NHSTUB(LogCameraEvent,							0xfc32c407) // debugging, from func csv

NHSTUB(GetDrive_TotalClusters,					0xfc352637) // function immediately before GetDrive_FreeClusters in ROM
NHSTUB(CancelHPTimer,							0xfc3b35b9) // fc368cf4 ref to UITimer, similar to sx710 fc301a54

// required because DryOS >=54 functions assert on unitialized event flag, sem etc 
// see https://chdk.setepontos.com/index.php?topic=12516.0
NHSTUB(init_focus_eventflag,					0xfc52e91b) // InitializeAdjustmentSystem->fc4415c8->fc52e91a event flag matches MoveFocusLensToDistance
NHSTUB(CreateBinarySemaphoreStrictly,         	0xfc34ba19) // from csv

NHSTUB(_pow,									0x010f8718) // note ARM

// via func fc18e1b0 hooked in preshoot case, similar to sx710
NHSTUB(captseq_raw_addr_init,					0xfc0f5fd3)
NHSTUB(apex2us,									0xfc21985b) // Ghidra exact

NHSTUB(exmem_alloc,								0xFC3B2E05)
NHSTUB(exmem_free,								0xFC3B2E3D)

// SX730 NOT found
NHSTUB(TurnOnBackLight,							NULL_SUB)
NHSTUB(TurnOffBackLight,						NULL_SUB)

// not implemented
NHSTUB(EnterToCompensationEVF,NULL_SUB)
NHSTUB(ExitFromCompensationEVF,NULL_SUB)
NHSTUB(ExpCtrlTool_StartContiAE,NULL_SUB)
NHSTUB(ExpCtrlTool_StopContiAE,NULL_SUB)
NHSTUB(Restart,NULL_SUB)
NHSTUB(SetParameterData,NULL_SUB)
NHSTUB(WriteSDCard,NULL_SUB)
NHSTUB(reboot_fw_update,NULL_SUB)

// from sx280 These don't exist
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)
NHSTUB(UnsetZoomForMovie,           NULL_SUB)

