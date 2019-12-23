#include "stubs_asm.h"
// NOTE 100d was ported first, comments in that sub are more likely to be helpful
// BEWARE: thumb functions NEED the thumb bit in the below list

#define NULL_SUB	0xfc0200ad	// bx lr
#define RET1		0xfc021f4d	// mov r0, #1 ; bx lr
#define RET0		0xfc0211ed	// mov r0, #0 ; bx lr

NHSTUB(Feof_Fut,								0xfc34c961) // Ghidra exact mne v 100d
NHSTUB(Fflush_Fut,								0xfc34c989) // "
NHSTUB(SetFileTimeStamp,						0xfc3517b3) // "
NHSTUB(SetFileAttributes,						0xfc3517fb) // ", after SetFileTimeStamp in ROM
NHSTUB(RenameFile_Fut,							0xfc34c711) // Ghidra exact
NHSTUB(MakeSDCardBootable,						0xfc3529d5) // "BOOTDISK" string
NHSTUB(GetFocusLensSubjectDistanceFromLens,		0xfc3344bb) // Ghidra exact

NHSTUB(GetImageFolder,							0xfc32f3e7) // match 100d

NHSTUB(LogCameraEvent,							0xfc32c3df) // debugging, from func csv

NHSTUB(GetDrive_TotalClusters,					0xfc35260f) // function immediately before GetDrive_FreeClusters in ROM
NHSTUB(CancelHPTimer,							0xfc3b3591) // Ghidra exact

// required because DryOS >=54 functions assert on unitialized event flag, sem etc 
// see https://chdk.setepontos.com/index.php?topic=12516.0
NHSTUB(init_focus_eventflag,					0xfc52e8f3) // InitializeAdjustmentSystem->fc4415a0->fc52e8f2 event flag matches MoveFocusLensToDistance
NHSTUB(CreateBinarySemaphoreStrictly,         	0xfc34b9f1) // from csv

NHSTUB(_pow,									0x010f8718) // note ARM

// via func fc18e188 hooked in preshoot case, similar to sx710
NHSTUB(captseq_raw_addr_init,					0xfc0f5fab)
NHSTUB(apex2us,									0xfc219833) // Ghidra exact

// SX730 NOT found
NHSTUB(TurnOnBackLight,							NULL_SUB)
NHSTUB(TurnOffBackLight,						NULL_SUB)
NHSTUB(exmem_alloc,								RET0)

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

