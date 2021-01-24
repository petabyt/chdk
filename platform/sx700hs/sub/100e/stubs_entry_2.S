#include "stubs_asm.h"

// BEWARE: thumb functions NEED the thumb bit in the below list
// Found for sx700v100e

#define NULL_SUB	0xfc02041d	// bx lr
#define RET1		0xfc02042b	// mov r0, #1 ; bx lr
#define RET0		0xfc02041f	// mov r0, #0 ; bx lr

// *** FOUND for sx700v100e ***
NHSTUB(Feof_Fut,	0xfc2d7d95) // sx700v100e from CreateJumptable, after Fgets and Fseek @ fc45bc5c

NHSTUB(Fflush_Fut,	0xfc2d7dbd) // sx700v100e Found directly after Feof_Fut in ROM

NHSTUB(SetFileTimeStamp,	0xfc3080fd) // sx700v100e from ref to 0x12cea600 @0xfc308110, similar to sx280hs search '^; stat '

NHSTUB(SetFileAttributes,	0xfc308145) // sx700v100e MakeDirectoryFUT function following SetFileTimeStamp in ROM

NHSTUB(RenameFile_Fut,		0xfc2d7b45) // sx700v100e Via fc3505e2 similar to g7x fc41fef8, just after ref to DeleteFile_Fut, LDR --  Search for RedEyeController from the end, then search forward for DeleteFile_Fut

NHSTUB(MakeSDCardBootable,	0xfc307d93) // sx700v100e in function before ref to "SCRIPT" @0xfc316cf8 --  Search for SCRIPT from the end, then search back for b.w


NHSTUB(GetFocusLensSubjectDistanceFromLens,		0xfc2dcf41) // call at 0xfc2bd058 via SetISFocusLensDistance_FW -> 0xfc2bd056 //sx700v100e found

NHSTUB(GetImageFolder,		0xfc2e07d9) // sx700v100e -- based on ref to fc2e117c (ref "%s/%3d%s") -> sub_fc3e690e, which refs  "___%02d" and "_%02d%02d"

NHSTUB(apex2us,		0xfc313637) // sx700v100e Shutter.c asserts @ fc1495ca -> fc149620 instructions similar to g7x fc3826c4

NHSTUB(GetDrive_TotalClusters,	0xfc307985) // sx700v100e found function immediately before GetDrive_FreeClusters in ROM

NHSTUB(LogCameraEvent,		0xfc306b6f) // sx700v100e found debugging, from func csv

NHSTUB(CancelHPTimer,		0xfc1360f5) // sx700v100e At fc0e3f42, following LcdSequence, TakeSemaphoreStrictly calls similar to g7x fc0cd6b0

NHSTUB(get_dial_hw_position,	0xfc364be9) // sx700v100e kbd_p1_f_cont->fc06e0ce->fc06be36, 4 for jogdial


// required because DryOS >=54 functions assert on unitialized event flag, sem etc
// see https://chdk.setepontos.com/index.php?topic=12516.0
NHSTUB(init_focus_eventflag,	0xfc45d487) // sx700v100e InitializeAdjustmentSystem->fc40e0e4->fc45d486 event flag matches MoveFocusLensToDistance

NHSTUB(init_nd_eventflag,	0xfc45d591) // sx700v100e InitializeAdjustmentSystem->fc542300->fc45d590 event flag matches PutInNdFilter

NHSTUB(CreateBinarySemaphoreStrictly,           0x010c5b6b) // from csv // sx700v100e

NHSTUB(captseq_raw_addr_init,			0xfc12fedf) // sx700v100e (via sx60hs) via func fc07b6ba hooked in preshoot case, similar to g7x

NHSTUB(EnterToCompensationEVF,		0xfc25c1a9) // sx700v100e search for "ExpOn"

NHSTUB(ExitFromCompensationEVF,		0xfc254ce9) // sx700v100e search for "ExpOff"

NHSTUB(ExpCtrlTool_StartContiAE,	0xfc24d359) //  sx700v100e search for "ExpCtrl.c" followed by "StartContiAE"

NHSTUB(ExpCtrlTool_StopContiAE,		0xfc24d439) //  sx700v100e search for "ExpCtrl.c" followed by "StopContiAE"

NHSTUB(Restart,				0xfc0a6e95) //  sx700v100e one of the calls to StopRedirectUART_FW

NHSTUB(SetParameterData,		0xfc0bbdd7) //  sx700v100e same as PTM_BackupUIProperty_FW

NHSTUB(WriteSDCard                          ,0xfc0e851d) //  sx700v100e above the first occurance of the string "Mounter.c"

NHSTUB(reboot_fw_update                     ,0xfc370b89) //  sx700v100e look for "FirmUpgrade.c"

// not implemented
NHSTUB(UnsetZoomForMovie,NULL_SUB)
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)


// From stubs_entry.S

//NHSTUB(RefreshPhysicalScreen                ,0x00000000) //  0            == 0x00000000
//NHSTUB(UnsetZoomForMovie                    ,0x00000000) //  0            == 0x00000000

IGNORE(GetDrive_FreeClusters) // replaced in lib.c
