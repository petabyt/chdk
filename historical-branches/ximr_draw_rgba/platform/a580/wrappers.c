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

void camera_set_led(int led, int state, __attribute__ ((unused))int bright)
{
        // 0 gr
        // 1 orange
        // 2 yel
        // 8 dp
        // 9 af

  int leds[] = {0,2,8,1,8,9};
  if(led < 4 || led > 9 || led == 6) return;
  _LEDDrive(leds[led-4], state<=1 ? !state : state);
}
 
 //--------------------------------------------------
 // DoMFLock : use _MFOn/_MFOff  or  _PT_MFOn/_PT_MFOff  or _SS_MFOn/_SS_MFOff if defined in stubs_entry.S
 //            otherwise use PostLogicalEventForNotPowerType(levent_id_for_name(PressSW1andMF),0); (see sx500hs for an example)
 
int DoMFLock(void)
{
  if (!camera_info.state.mode_play) {
     int mf_lock;
     get_property_case(PROPCASE_FOCUS_MODE,&mf_lock,sizeof(mf_lock));
     if( mf_lock == 0 ) PostLogicalEventForNotPowerType(levent_id_for_name("PressSw1AndMF"),0);
     return(1);
  }
  return(0);
}
 
int UnlockMF(void)
{
  if (!camera_info.state.mode_play) {
     int mf_lock;
     get_property_case(PROPCASE_FOCUS_MODE,&mf_lock,sizeof(mf_lock));
     if( mf_lock == 1 ) PostLogicalEventForNotPowerType(levent_id_for_name("PressSw1AndMF"),0);
     return(1);
  }
  return(0);
}
