#ifndef PROFILES_H
#define PROFILES_H

extern void profile_remember();
extern void profile_restore( int do_postprocess );
extern void profile_set_postprocessing();
extern void gui_safe_set_profile(int arg);

#endif
