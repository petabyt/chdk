#include "stubs_asm.h"
#define NULL_SUB 0xFF8118C0

// Override stubs_entry.S
NHSTUB(DisplayImagePhysicalScreen,  0xFF93C9EC)
NHSTUB(EnterToCompensationEVF,      0xff9590c8)
NHSTUB(ExitFromCompensationEVF,     0xff95911c)
NHSTUB(GetCurrentAvValue,           0xFFA516E0)
NHSTUB(GetFocusLensSubjectDistance, 0xFFA66F80)
NHSTUB(GetPropertyCase,             0xFF825AA8)
NHSTUB(MakeAFScan,                  NULL_SUB)
NHSTUB(Mount_FileSystem,            0xFF873F40)
NHSTUB(PhySw_testgpio,              NULL_SUB)
NHSTUB(Remove,                      0xFF874BA8)
NHSTUB(Restart,                     0xFF823B90)
NHSTUB(SetPropertyCase,             0xFF8259A0)
NHSTUB(UnsetZoomForMovie,           0xFF9A4D1C)
NHSTUB(VbattGet,                    0xFFA62D84)
NHSTUB(WriteSDCard,                 NULL_SUB)
NHSTUB(free,                        0xFFABEC40)
NHSTUB(kbd_p1_f,                    NULL_SUB)
NHSTUB(kbd_p1_f_cont,               0xFF828DE0)
NHSTUB(kbd_p2_f,                    NULL_SUB)
NHSTUB(kbd_read_keys_r2,            NULL_SUB)

// These don't exist
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)

// Additional
NHSTUB(UniqueLedOff,                0xFF82E024)
NHSTUB(UniqueLedOn,                 0xFF82DFC8)
NHSTUB(kbd_p1_1,                    0xFF8291F0)
NHSTUB(kbd_p1_2,                    0xFF829258)
NHSTUB(kbd_p1_3,                    0xFF82963C)
NHSTUB(platformsub_kbd_fetch_data,  0xFF8297A8)

// New finsig_vxworks differences?
NHSTUB(kbd_pwr_off, 0xff82a120)
