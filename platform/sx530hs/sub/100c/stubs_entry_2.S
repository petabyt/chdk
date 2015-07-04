#include "stubs_asm.h"
#define NULLSUB 0xff05ad58

// Override stubs_entry.S
NHSTUB(DebugAssert                          ,0x006b5a04) //107        *** != 0x006b5a58
NHSTUB(DeleteFile_Fut                       ,0xff026928) //  1 90%    *** != 0xff006c18
NHSTUB(GetFocusLensSubjectDistanceFromLens  ,0xff203998) //  3 90%    *** != 0xff1c481c
NHSTUB(MakeDirectory_Fut, 0xff027438)                 //--- ---    *** != 0xff007728 0xff027438 used from mkdir NHSTUB
NHSTUB(MakeSDCardBootable                   ,0xff030e70) //105        *** != 0xff010f3c
NHSTUB(RefreshPhysicalScreen,NULLSUB)              //--- ---    *** != 0x00000000
NHSTUB(Restart                              ,0xff037c88) //122        *** != 0xff01786c
NHSTUB(WriteSDCard,NULLSUB)                        //--- ---    *** != 0xff06506c
NHSTUB(time,NULLSUB)                               //--- ---

// Additional
NHSTUB(TurnOffE1,NULLSUB)
NHSTUB(SetZoomActuatorSpeedPercent,NULLSUB)
NHSTUB(focus_len_table,NULLSUB)
NHSTUB(playrec_mode,NULLSUB)


// Not needed

DEF(focus_len_table                         ,NULLSUB) // copiado da sx510hs jeronymo
DEF(playrec_mode                            ,NULLSUB) // copiado da sx510hs jeronymo


// These don't exist

