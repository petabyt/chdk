#include "stubs_asm.h"

NHSTUB(free, 0xFFB1551C)

NSTUB(realloc, 0xFFB1475C)
NSTUB(memmove, 0xFFB0D584)
NSTUB(calloc,  0xFFB1472C)
NSTUB(printf,  0xFFB11634)


NHSTUB(kbd_pwr_off, 0xFF827FF8)
NHSTUB(kbd_pwr_on, 0xFF827FDC)


// Function reads Gpio Status into physw_status variable
// call located at start of the 'kbd_p1_f' => 'PhySWTask'
NHSTUB(kbd_read_keys, 0xFF826DB8)


NHSTUB(VbattGet, 0xFF82D154)
NHSTUB(SetZoomActuatorSpeedPercent, 0xFF8117EC)

NHSTUB(ZZZ, 0x0)


NSTUB(taskName, 0xFFB22A50)
NSTUB(taskIdListGet, 0xFFB22B58)
NSTUB(taskResume, 0xFFB22E34)
NSTUB(taskSuspend, 0xFFB22C60)
NSTUB(taskNameToId, 0xFFB22A74)

// These two are indistinguishable!!!!
// ????
NSTUB(feof, 0xffb09d18)
NSTUB(ferror, 0xffb09d84)


STUB_DIR(vsprintf,0xFFB11278)

NHSTUB(UnsetZoomForMovie ,0xFF9B1680)

NHSTUB(GetDrive_ClusterSize, 0xFF86FD58)
NHSTUB(GetDrive_TotalClusters, 0xFF86FD94)
NHSTUB(GetDrive_FreeClusters, 0xFF868AD4)
