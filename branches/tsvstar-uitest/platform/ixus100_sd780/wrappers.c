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

// VERIFY_SD780 Only one arg? - unknown
// I dared to comment it out, because it produced
// a warning, but is not called anywhere - ultimA
//long OpLog_Get(long i)
//{
//  extern int _OpLog_Get(int);
//	return _OpLog_Get(i);
//}
