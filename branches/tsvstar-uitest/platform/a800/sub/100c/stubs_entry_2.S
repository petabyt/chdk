#include "stubs_asm.h"
#define NULL_SUB 0xffc00b28

// Override stubs_entry.S
NSTUB(GetBatteryTemperature,            NULL_SUB)   // Does not work in SX130 - A800 (included dummy in sub/100c/lib.c)
NHSTUB(kbd_pwr_on,                      NULL_SUB)   // endere�o dummy com uma instru��o bx lr (um ret, creio)
NHSTUB(mkdir,                           0xffc267fc) // 53% corrigido
NHSTUB(rand,                            NULL_SUB)   // N�o encontrei manualmente
NHSTUB(srand,                           NULL_SUB)   // idem acima

// These don't exist
NHSTUB(SetZoomActuatorSpeedPercent,     NULL_SUB)

// Additional
NHSTUB(MakeAFScan,                      0xffd1b2e0) // verifiquei a rotina e as refer�ncias a ela e s�o bastante similares FFD0F2AC) // Ok
NHSTUB(TurnOffMic,                      0xffc444ec) // rotina em posi��o similar a de a495 -logo provavelmente doesn't work tamb�m -  FFC43C28) // Doesn't work
NHSTUB(TurnOnMic,                       0xffc44518) // idem acima FFC43C54) // Doesn't work
