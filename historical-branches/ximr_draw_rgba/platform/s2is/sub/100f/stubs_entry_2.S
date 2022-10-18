#include "stubs_asm.h"
#define NULL_SUB 0xFF8118C0

// Override stubs_entry.S
NHSTUB(DisplayImagePhysicalScreen,  0xff93dc88)
NHSTUB(EnterToCompensationEVF,      0xff968128)
NHSTUB(ExitFromCompensationEVF,     0xff96817c)
NHSTUB(GetFocusLensSubjectDistanceFromLens, 0xffa8ef74)
NHSTUB(GetPropertyCase,             0xFF825D08)
NHSTUB(GetZoomLensCurrentPoint,     0xFFAA8824)
NHSTUB(GetZoomLensCurrentPosition,  0xFFAA8838)
NHSTUB(MakeAFScan,                  NULL_SUB)
NHSTUB(Mount_FileSystem,            0xFF876264)
NHSTUB(PhySw_testgpio,              NULL_SUB)
NHSTUB(Remove,                      0xFF877380)
NHSTUB(Restart,                     0xFF823DE8)
NHSTUB(SetParameterData,            0xFF987EE4)
NHSTUB(SetPropertyCase,             0xFF825C00)
NHSTUB(UnsetZoomForMovie,           NULL_SUB)
NHSTUB(WriteSDCard,                 NULL_SUB)
NHSTUB(free,                        0xFFAF758C)
NHSTUB(kbd_p1_f,                    0xFF829470)
NHSTUB(kbd_p1_f_cont,               0xFF829484)
NHSTUB(kbd_p2_f,                    0xFF829364)
NHSTUB(kbd_read_keys_r2,            0xFF829E58)

// Additional
NHSTUB(SetZoomActuatorSpeedPercent, 0xFFA88178)
NHSTUB(UniqueLedOff,                0xFF82EC54)
NHSTUB(UniqueLedOn,                 0xFF82EBDC)
NHSTUB(platformsub_kbd_fetch_data,  0xFF829F8C)

// New finsig_vxworks differences?
NHSTUB(kbd_pwr_off, 0xff82ae84)
