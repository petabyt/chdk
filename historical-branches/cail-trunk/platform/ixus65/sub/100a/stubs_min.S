#include "stubs_asm.h"

DEF(physw_run, 0x1FAC)
DEF(physw_status, 0xE758)

// The names below could be found automanically
// by looking up the strings with the same names as these variables
// and function 'ShowPhySwStatus' which is also symbolic
DEF(NotifyMask, 0x0000E728)
DEF(SwitchMask, 0x0000E738)
DEF(InvertData, 0x0000E748)
// This is the real name for 'physw_status'
DEF(GpioStatus, 0x0000E758)
DEF(SwitchStatus, 0x0000E768)


// Key values for 'Feather' on joystic
// Could be retrieved from 'PhySW' Task
DEF(touch_keys_angle, 0x0000E8C8)
// Semaphore address to disable Feather processing
DEF(touch_keys_sema, 0x0000E874)



// INVALID!!!!!!!!
DEF(zoom_busy, 0x801C4)
DEF(focus_busy, 0x80574)
DEF(movie_compression, 0x6CBC)
