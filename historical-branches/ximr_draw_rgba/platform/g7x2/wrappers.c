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

// Override to handle high-speed continuous drive mode so code and scripts detect camera is in continuous shooting mode
long _GetPropertyCase(long opt_id, void *buf, long bufsize)
{
    extern long _GetPropertyCase_FW(long opt_id, void *buf, long bufsize);
    long rv = _GetPropertyCase_FW(opt_id, buf, bufsize);
    // Fake drive mode 1 if camera set to high speed mode
    if (opt_id == PROPCASE_DRIVE_MODE)
        if (*((short*)buf) == 4)
            *((short*)buf) = 1;
    return rv;
}
