#include "stubs_asm.h"

#define NULL_SUB 0xffc00b28

NHSTUB(mkdir                                   ,0xffc267fc) //  53% corrigido
NHSTUB(kbd_pwr_off, 0xffc43e84)//igual aixus220 e a495  60% confirmado


// --- Não encontrados ou mesmo não existem - Those aren't used or don't exist in DryOS (like A720 and other)
NHSTUB(kbd_pwr_on, NULL_SUB)//endereço dummy com uma instrução bx lr (um ret, creio)
NHSTUB(rand, NULL_SUB)   //Não encontrei manualmente
NHSTUB(srand, NULL_SUB)  // idem acima
NHSTUB(SetZoomActuatorSpeedPercent, NULL_SUB)
NSTUB(GetBatteryTemperature, NULL_SUB)        // Does not work in SX130 - A800 (included dummy in sub/100c/lib.c)
NHSTUB(SetFileAttributes,				NULL_SUB)


//Decalcado de stubs_entry_2.S de a495 - por agora retirado
// video buffer stuff
//NHSTUB(UnlockAndRefresh, 0xFFD7C5EC)			// "Window.c"
//NHSTUB(LockAndRefresh, 0xFFD7C5A8)				// "Window.c"

NHSTUB(MakeAFScan, 0xffd1b2e0)					// verifiquei a rotina e as referências a ela e são bastante similares FFD0F2AC)					// Ok
NHSTUB(TurnOffMic, 0xffc444ec)				// rotina em posição similar a de a495 -logo provavelmente doesn't work também -  FFC43C28)					// Doesn't work
NHSTUB(TurnOnMic, 0xffc44518)					// idem acima 	FFC43C54)					// Doesn't work
