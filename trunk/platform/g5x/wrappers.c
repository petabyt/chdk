#include "../generic/wrappers.c"

long lens_get_focus_pos()
{
	return _GetFocusLensSubjectDistance();
}

long lens_get_focus_pos_from_lens()
{
	return _GetFocusLensSubjectDistanceFromLens(); 
}

long lens_get_target_distance()
{
	return _GetCurrentTargetDistance();
}
 
 //--------------------------------------------------
 // DoMFLock : use _MFOn/_MFOff  or  _PT_MFOn/_PT_MFOff  or _SS_MFOn/_SS_MFOff if defined in stubs_entry.S
 //            otherwise use PostLogicalEventForNotPowerType(levent_id_for_name(PressSW1andMF),0); (see sx500hs for an example)
 
int DoMFLock(void)
{
  if (!camera_info.state.mode_play) {
     _PT_MFOn();
     return(1);
  }
  return(0);
}
 
int UnlockMF(void)
{
  if (!camera_info.state.mode_play) {
     _PT_MFOff();
     return(1);
  }
  return(0);
}

// Wrappers to call inner functions of event procs for ND filter

static void null_func() { }

void _PutInNdFilter()
{
    extern void _PutInNdFilter_FW(void*, int);
    _PutInNdFilter_FW(null_func, 0);
}

void _PutOutNdFilter()
{
    extern void _PutOutNdFilter_FW(void*, int);
    _PutOutNdFilter_FW(null_func, 0);
}

void _MoveFocusLensToDistance(short *dist)
{
    // Crashes unless camera is set to manual focus in Canon GUI
    extern void _MoveFocusLensToDistance_FW(short*, void*, int);
    _MoveFocusLensToDistance_FW(dist, null_func, 0);
}
