/*
 * movie_rec.c
 *
 *  Standard CHDK movie functions not implemented.
 *
 */
#include "conf.h"

void change_video_tables(int a, int b)
{
    return ;
}

void  set_quality(int *x)
{ 
 if (conf.video_mode) *x=12-((conf.video_quality-1)*(12+17)/(99-1));  // -17 highest; +12 lowest
 return ;
}
