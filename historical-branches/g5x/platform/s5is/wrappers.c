#include "../generic/wrappers.c"

long lens_get_focus_pos()
{
    static long v=CAMERA_MAX_DIST;
    return (kbd_is_key_pressed(KEY_SHOOT_HALF) || camera_info.state.state_kbd_script_run  || shooting_get_focus_mode())?v=_GetFocusLensSubjectDistance():v;
//	return _GetFocusLensSubjectDistance();
}

long lens_get_focus_pos_from_lens()
{
    static long v=CAMERA_MAX_DIST;
    return (kbd_is_key_pressed(KEY_SHOOT_HALF) || camera_info.state.state_kbd_script_run  || shooting_get_focus_mode())?v=_GetFocusLensSubjectDistanceFromLens():v;
//	return _GetFocusLensSubjectDistanceFromLens(); 
}

long lens_get_target_distance()
{
    static long v=CAMERA_MAX_DIST;
    return (kbd_is_key_pressed(KEY_SHOOT_HALF) || camera_info.state.state_kbd_script_run  || shooting_get_focus_mode())?v=_GetCurrentTargetDistance():v;
//	return _GetCurrentTargetDistance();
}
 
 //--------------------------------------------------
 // DoMFLock : use _MFOn/_MFOff  or  _PT_MFOn/_PT_MFOff  or _SS_MFOn/_SS_MFOff if defined in stubs_entry.S
 //            otherwise use PostLogicalEventForNotPowerType(levent_id_for_name(PressSW1andMF),0); (see sx500hs for an example)
 
int DoMFLock(void)
{
  if (!camera_info.state.mode_play) {
     _MFOn();
     return(1);
  }
  return(0);
}
 
int UnlockMF(void)
{
  if (!camera_info.state.mode_play) {
     _MFOff();
     return(1);
  }
  return(0);
}
