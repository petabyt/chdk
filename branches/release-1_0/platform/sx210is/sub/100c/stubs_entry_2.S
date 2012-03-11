#include "stubs_asm.h"

// not found so - pointed these at nullsub_1 as labelled in IDA -> FF810B1C    (This address is for sx210)

NHSTUB(SetZoomActuatorSpeedPercent, 0xFF810B1C)   //  ???????????????????  
NHSTUB(kbd_pwr_on, 0xFF810B1C)                    //  ???????????????????  

NHSTUB(UnlockAndRefresh, 0xFFA1EDDC)   // In sx20 102 : FFA0498C
NHSTUB(LockAndRefresh, 0xFFA1ED98)    // In sx20 102 : FFA048E8

NHSTUB(MakeAFScan, 0xFF970F5C)    // -> ASM1989 08.21.2010 Looks like, but needs confimation

//Not deteted in Auto and needed

STUB(FFB5FA88)
STUB(FF813404)
STUB(FF810B20)
STUB(FF81A244)
STUB(FF815A94)
STUB(FF815B7C)
STUB(FF872F20)