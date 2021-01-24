#include "stubs_asm.h"

// BEWARE: thumb functions NEED the thumb bit in the below list

#define NULL_SUB	0xfc0212a5	// bx lr
#define RET1		0xfc001eeb	// mov r0, #1 ; bx lr
#define RET0		0xfc000981	// mov r0, #0 ; bx lr

NHSTUB(Feof_Fut,								0xfc325d21) // from CreateJumptable, after Fseek
NHSTUB(Fflush_Fut,								0xfc325d49) // directly after Feof_Fut in ROM
// unused with current display method
//NHSTUB(displaybusyonscreen,                   	0xfc34586d) // 0xfc356638 ref _PBBusyScrn
//NHSTUB(undisplaybusyonscreen,                 	0xfc345905) // near display* above
NHSTUB(SetFileTimeStamp,						0xfc3582d1) // from ref to 0x12cea600 @0xfc3582e4, similar to sx280hs
NHSTUB(SetFileAttributes,						0xfc358319) // function following SetFileTimeStamp in ROM
NHSTUB(RenameFile_Fut,							0xfc325ad1) // from ref to ".RPC" @0xfc11019a, similar to sx280hs
NHSTUB(MakeSDCardBootable,						0xfc357f65) // in function before ref to "SCRIPT" @0xfc357b78
NHSTUB(GetFocusLensSubjectDistanceFromLens,		0xfc31fdfd) // call at 0xfc305ef0 similar to sx280 0xfc26ea22, from earlier ISDriver.c assert
// based on ref to fc32190b -> sub_fc469ee2, which refs  "___%02d" and "_%02d%02d"
NHSTUB(GetImageFolder,							0xfc320ebf)
NHSTUB(apex2us,									0xfc382687) // Shutter.c asserts in sub_fc16e57e, similar to sx280 sub_fc2a63d6
NHSTUB(GetDrive_TotalClusters,					0xfc357bd7) // function immediately before GetDrive_FreeClusters in ROM
NHSTUB(LogCameraEvent,							0xfc36000b) // debugging, from func csv
NHSTUB(CancelHPTimer,							0xfc158e25) // At 0xfc0cd6b0, following LcdSequence, TakeSemaphoreStrictly calls similar to sx280

NHSTUB(get_dial_hw_position,					0xfc491e7d) // kbd_p1_f_cont->fc075c1c->fc077438->func 4=rear dial, 5=front dial

// required because DryOS >=54 functions assert on unitialized event flag, sem etc
// see https://chdk.setepontos.com/index.php?topic=12516.0
NHSTUB(init_focus_eventflag,	0xfc4f3bd7) // InitializeAdjustmentSystem->fc3d31c4->fc4f3bd6 event flag matches MoveFocusLensToDistance
NHSTUB(init_nd_eventflag,		0xfc4f3ce9) // InitializeAdjustmentSystem->fc3d31c4->fc4f3ce8 event flag matches PutInNdFilter
NHSTUB(CreateBinarySemaphoreStrictly,0x010e5bb7) // for av_override_semaphore

// gets raw address and other stuff for next shot, stores in structure pointed to by r1
// via sub_fc1e58d8, sub_fc1e56a6 called from capt_seq_task. Calls sub_fc184310 to get raw address
NHSTUB(captseq_raw_addr_init,0xfc152773)

// TODO temp for compile
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

IGNORE(GetDrive_FreeClusters) // replaced in lib.c
