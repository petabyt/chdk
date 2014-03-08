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

/*
#define RAND_MAX 0x7fffffff

static unsigned int next = 1;
 
int rand_r(unsigned int *seed)
{
	*seed = *seed * 1103515245 + 12345;
	return (*seed % ((unsigned int) RAND_MAX + 1));
}*/

//int _rand(void)
//{
//	return (rand_r(&next));
//}
//
//void* _srand(unsigned int seed)
//{
//	next = seed;
//	return 0;				// unused return value
//}

/*
char *_strrchr(const char *s, int c) {
	// waldo - unable to find strrchr in s95 FW - we use our own fn
    //return _strrchr(s, c);

	char *result = 0;

	c = (char) c;

	do {
		if (c == *s)
			result = (char*) s;
	} while (*s++ != '\0');

	return result;
} 
*/
 
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
