#include "stubs_asm.h"

// BEWARE: thumb functions NEED the thumb bit in the below list

#define NULL_SUB	0xfc02041d	// bx lr
#define RET1		0xfc02042b	// mov r0, #1 ; bx lr
#define RET0		0xfc02041f	// mov r0, #0 ; bx lr

NHSTUB(Feof_Fut,	0xfc2d7e91) // sx700v100d from CreateJumptable, after Fgets and Fseek @fc45bdce

NHSTUB(Fflush_Fut,	0xfc2d7eb9) //  sx700v100d Found directly after Feof_Fut in ROM

NHSTUB(SetFileTimeStamp,	0xfc308225) // sx700v100d from ref to 0x12cea600 @0xfc308238, similar to sx280hs search '^; stat '

NHSTUB(SetFileAttributes,	0xfc30826d) // sx700v100d function following SetFileTimeStamp in ROM

NHSTUB(RenameFile_Fut,		0xfc2d7c41) // sx700v100d +0xfc from 100e address

NHSTUB(MakeSDCardBootable,	0xfc307ebb) // sx700v100d in function before ref to "SCRIPT" @0xfc307a4e --  Search for SCRIPT from the end, then search back for b.w


NHSTUB(GetFocusLensSubjectDistanceFromLens,		0xfc2dd03d) // call at 0xfc2bd154 via SetISFocusLensDistance_FW

NHSTUB(GetImageFolder,		0xfc2e08d5) // sx700v100d -- based on ref to fc2e1278 (ref "%s/%3d%s") -> sub_fc3e6a7e, which refs  "___%02d" and "_%02d%02d"

NHSTUB(apex2us,				0xfc31375f) // sx700v100e Shutter.c asserts @ fc1499d0 for line 0x16e, same as 100e fw

NHSTUB(GetDrive_TotalClusters,	0xfc307aad) // sx700v100d found function immediately before GetDrive_FreeClusters in ROM

NHSTUB(LogCameraEvent,		0xfc306c97) // sx700v100d debugging, from func csv 

NHSTUB(CancelHPTimer,		0xfc1361c1) //sx700v100d At fc0e3fa2, following LcdSequence, TakeSemaphoreStrictly calls similar to g7x fc0cd6b0 

NHSTUB(get_dial_hw_position,	0xfc364d11) // sx700v100d kbd_p1_f_cont->fc06e0ce->fc06be36, 4 for jogdial 


// required because DryOS >=54 functions assert on unitialized event flag, sem etc 
// see https://chdk.setepontos.com/index.php?topic=12516.0
NHSTUB(init_focus_eventflag,	0xfc45d5f7) // sx700v100d InitializeAdjustmentSystem->fc40e254->fc45d5f6 event flag matches MoveFocusLensToDistance 

NHSTUB(init_nd_eventflag,	0xfc45d701) //0xfc45d591// sx700v100d InitializeAdjustmentSystem->fc40e254->fc45d700 event flag matches PutInNdFilter 

NHSTUB(CreateBinarySemaphoreStrictly,           0x010c5b6b) // from csv // sx700v100e

// unused
//NHSTUB(captseq_raw_addr_init,			NULL_SUB) //100e was 0xfc12fedf // sx700v100e (via sx60hs) via func fc07b6ba hooked in preshoot case, similar to g7x

NHSTUB(EnterToCompensationEVF,		0xfc25c275) // sx700v100d search for "ExpOn"

NHSTUB(ExitFromCompensationEVF,		0xfc25c2af) // sx700v100d search for "ExpOff"

NHSTUB(ExpCtrlTool_StartContiAE,	0xfc24d425) // sx700v100d search for "ExpCtrl.c" followed by "StartContiAE"

NHSTUB(ExpCtrlTool_StopContiAE,		0xfc24d505) // sx700v100d search for "ExpCtrl.c" followed by "StopContiAE"

NHSTUB(Restart,				0xfc0a6eed) // sx700v100d one of the calls to StopRedirectUART_FW

NHSTUB(SetParameterData,		0xfc0bbe2f) // sx700v100d same as PTM_BackupUIProperty_FW

NHSTUB(WriteSDCard                          ,0xfc0e857d) // sx700v100d above the first occurance of the string "Mounter.c"

NHSTUB(reboot_fw_update                     ,0xfc370cb1) // sx700v100d look for "FirmUpgrade.c"

// *** Not Found 
NHSTUB(RefreshPhysicalScreen,NULL_SUB)

// not implemented
NHSTUB(UnsetZoomForMovie,NULL_SUB)
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)


// From stubs_entry.S

//NHSTUB(RefreshPhysicalScreen                ,0x00000000) //  0            == 0x00000000
//NHSTUB(UnsetZoomForMovie                    ,0x00000000) //  0            == 0x00000000

