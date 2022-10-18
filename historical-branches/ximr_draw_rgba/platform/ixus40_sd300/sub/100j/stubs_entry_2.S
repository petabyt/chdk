#include "stubs_asm.h"
#define NULL_SUB 0xFF81F474

// Override stubs_entry.S
NHSTUB(AllocateMemory,              0xFF81F56C)
NHSTUB(Close,                       0xFF871688)
NHSTUB(CreatePhysicalVram,          0xFF927B0C)
NHSTUB(DisplayImagePhysicalScreen,  0xFF927098)
NHSTUB(EnterToCompensationEVF,      0xff93e1e0)
NHSTUB(ExecuteEventProcedure,       0xFF81756C)
NHSTUB(ExitFromCompensationEVF,     0xff93e220)
NHSTUB(FreeMemory,                  0xFF81F578)
NHSTUB(FreeUncacheableMemory,       0xFF8152BC)
NHSTUB(GetFocusLensSubjectDistance, 0xFFA5FA64)
NHSTUB(GetFocusLensSubjectDistanceFromLens, 0xFFA600D8)
NHSTUB(GetZoomLensCurrentPoint,     0xffa51244)
NHSTUB(MakeAFScan,                  NULL_SUB)
NHSTUB(Mount_FileSystem,            0xFF8702E4)
NHSTUB(Open,                        0xFF87167C)
NHSTUB(PT_PlaySound,                0xff94f2bc)
NHSTUB(PhySw_testgpio,              0xFF82FA8C)
NHSTUB(Read,                        0xFF8716E8)
NHSTUB(Remove,                      0xFF871694)
NHSTUB(Restart,                     0xFF824F58)
NHSTUB(SetCurrentCaptureModeType,   NULL_SUB)
NHSTUB(SetLogicalEventActive,       NULL_SUB)
NHSTUB(UnsetZoomForMovie,           NULL_SUB)
NHSTUB(VbattGet,                    0xFFA5BCC4)
NHSTUB(Write,                       0xFF8716F4)
NHSTUB(WriteSDCard,                 NULL_SUB)
NHSTUB(free,                        0xFFAC58D8)
NHSTUB(iosDevFind,                  0xFFAC3A38)
NHSTUB(kbd_p1_f,                    NULL_SUB)
NHSTUB(kbd_p1_f_cont,               0xFF830AB4)
NHSTUB(kbd_p2_f,                    NULL_SUB)
NHSTUB(kbd_read_keys_r2,            NULL_SUB)
NHSTUB(memPartInfoGet,              NULL_SUB)
NHSTUB(memPartFindMax,              0xffac4598)

// These don't exist
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)

// Additional
NHSTUB(GetCurrentMachineTime,       0xFF81FEFC)
NHSTUB(GetParameterData,            0xFF95A55C)
NHSTUB(SetAFBeamBrightness,         0xFFA62C34)
NHSTUB(SetAFBeamOff,                0xFFA62CB0)
NHSTUB(SetParameterData,            0xFF95A49C)
NHSTUB(SetScriptMode,               0xFF955C24)
NHSTUB(SetTimerWhen,                0xFF815828)
NHSTUB(ShowAllTaskInfo,             0xFFA9E8BC)
NHSTUB(ShowCameraLog,               0xFF81A1A8)
NHSTUB(iosInit,                     0xFFAC3B3C)
NHSTUB(semBCreate,                  0xFFACF158)
NHSTUB(tasktcb,                     0xffad2294)

// New finsig_vxworks differences?
NHSTUB(kbd_pwr_off, 0xffa417b0)
NHSTUB(Feof_Fut, 0xfff17328)

// Custom overrides
NHSTUB(GetPropertyCase_orig,        0xFF82CB54)
NHSTUB(SetPropertyCase_orig,        0xFF82CAD0)
NHSTUB(time_orig, 0xffabdc00)

IGNORE(GetPropertyCase)  // Custom version in lib.c, ignore firmware version
IGNORE(SetPropertyCase)  // Custom version in lib.c, ignore firmware version
IGNORE(time)  // Custom version in lib.c, ignore firmware version
