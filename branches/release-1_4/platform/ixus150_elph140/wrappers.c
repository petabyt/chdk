#include "../generic/wrappers.c"

// Big copy paste, but should be generic
// We do have the SS_MFOn/Off stubs

long lens_get_focus_pos()
{
    return _GetFocusLensSubjectDistance();
}

long lens_get_focus_pos_from_lens()
{
    return _GetFocusLensSubjectDistanceFromLens();
}

 //--------------------------------------------------
 // DoMFLock : use _MFOn/_MFOff  or  _PT_MFOn/_PT_MFOff  or _SS_MFOn/_SS_MFOff if defined in stubs_entry.S
 //            otherwise use PostLogicalEventForNotPowerType(levent_id_for_name(PressSW1andMF),0); (see sx500hs for an example)

int DoMFLock(void)
{
  if (!camera_info.state.mode_play) {
     _SS_MFOn();
     return(1);
  }
  return(0);
}

int UnlockMF(void)
{
  if (!camera_info.state.mode_play) {
     _SS_MFOff();
     return(1);
  }
  return(0);
}

