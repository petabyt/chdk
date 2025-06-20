#include "stubs_asm.h"

NHSTUB(Close, 0xFF877100)
NHSTUB(Remove, 0xFF87710C)
NHSTUB(DisplayImagePhysicalScreen, 0xFF93DA14)
NHSTUB(free, 0xFFAF7318)
NHSTUB(Open, 0xFF8770F4)
NHSTUB(Read, 0xFF877160)
NHSTUB(Write, 0xFF87716C)
NHSTUB(VbattGet, 0xFF82D570)
NHSTUB(Mount_FileSystem, 0xFF875FF0)
NHSTUB(SetParameterData, 0xFF987C70)
NHSTUB(GetPropertyCase, 0xFF825D08)
NHSTUB(SetPropertyCase, 0xFF825C00)
NHSTUB(GetZoomLensCurrentPosition, 0xFFAA85C4)
NHSTUB(GetZoomLensCurrentPoint, 0xFFAA85B0)
NHSTUB(MoveZoomLensWithPoint, 0xFFA87D8C)
NHSTUB(SetZoomActuatorSpeedPercent, 0xFFA87F04)

NHSTUB(kbd_p1_f, 0xFF829470)
NHSTUB(kbd_p1_f_cont, 0xFF829484)
NHSTUB(kbd_read_keys_r2, 0xFF829E58)
NHSTUB(platformsub_kbd_fetch_data, 0xFF829F8C)
NHSTUB(kbd_p2_f, 0xFF829364)

// null stubs
NHSTUB(PhySw_testgpio, 0xFF8118C0)

NHSTUB(UniqueLedOn, 0xFF82EBDC)
NHSTUB(UniqueLedOff, 0xFF82EC54)

NHSTUB(GetDrive_ClusterSize, 0xFF87652C)
NHSTUB(GetDrive_TotalClusters, 0xFF876588)
NHSTUB(GetDrive_FreeClusters, 0xFF8765C4)
