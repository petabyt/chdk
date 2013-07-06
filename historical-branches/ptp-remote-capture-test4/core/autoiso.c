#include "platform.h"
#include "stdlib.h"
#include "math.h"
#include "conf.h"

//-------------------------------------------------------------------
// AUTO ISO

//////////////////////////////////////////////////////////////////////////////////////////////
// @tsv
// Module below calculate live histogram in same way as OSD histogram
// Difference from shot_histogram family is that live_histogram give answer before shot
// Regular histogram_process cannot be used, because raw non-summarized 0.255 values required
// This module is used in AutoISO2 mechanizm.
//////////////////////////////////////////////////////////////////////////////////////////////

// Define how many viewport blocks to step in each loop iteration. Each block is 6 bytes (UYVYYY) or 4 image pixels
#define	HISTO_STEP_SIZE	6

static unsigned short live_histogram_proc[256]; // Buffer for histogram
static int live_histogram_overall;		        // Total num of pixels in histogram

/*
build histogram of viewport Y values (downsampled by HISTO_STEP_SIZE)
*/
int live_histogram_read_y()
{
    int i;

    int vp_width = vid_get_viewport_width();
    int vp_offset = vid_get_viewport_row_offset();
    int viewport_size = vid_get_viewport_height() * vid_get_viewport_byte_width() * vid_get_viewport_yscale();

    unsigned char *img = vid_get_viewport_active_buffer();
    // can be NULL in playback mode (if a movie is selected)
    // _fb will give us an address, although it may not contain the data we want!
    // TODO should probably just return all zeros, but need to make sure auto-iso stuff will handle it
    if (img == NULL)
        img = vid_get_viewport_fb();

    img += vid_get_viewport_image_offset();

    live_histogram_overall = 0;
    memset(live_histogram_proc, 0, sizeof(unsigned short)*256);

    int x = 0;	// count how many blocks we have done on the current row (to skip unused buffer space at end of each row)

    for (i=1; i<viewport_size; i+=HISTO_STEP_SIZE*6)
    {
        ++live_histogram_proc[img[i]];
        ++live_histogram_overall; // TODO - would be better to just calculate this from dimensions and step

        // Handle case where viewport memory buffer is wider than the actual buffer.
        x += HISTO_STEP_SIZE * 2;	// viewport width is measured in blocks of three bytes each even though the data is stored in six byte chunks !
        if (x == vp_width)
        {
            i += vp_offset;
            x = 0;
        }
    }

    return live_histogram_overall;
}

static int live_histogram_get_range(int from, int to)
{
    if (from < 0) from = 0;
    if (to > 255) to = 255;

    int rv = 0;
    for(; from<=to; from++)
        rv += live_histogram_proc[from];

    return (rv * 100) / live_histogram_overall;
}

//-------------------------------------------------------------------

static const int shutter1_values[] = { 0, 8, 15, 30, 60, 125, 250, 500, 1000 };
static const int shutter2_values[] = { 0, 4, 6, 8, 12, 15, 20, 25, 30, 40, 50, 60, 80, 100, 125, 160, 200, 250, 500, 1000 };

static void shooting_calc_autoiso_coef( int min_shutter )
{
    if (shutter2_values[conf.autoiso2_shutter_enum] >= min_shutter)
    {
        conf.autoiso2_coef = 0.0;
    }
    else
    {
        conf.autoiso2_coef = (float)(conf.autoiso2_max_iso_auto_real - conf.autoiso_max_iso_auto_real) / 
            (float)( shutter2_values[conf.autoiso2_shutter_enum] - min_shutter);
    }
}

static void shooting_recalc_conf_autoiso_values()
{
#ifndef USE_REAL_AUTOISO
    // Initialize only once
    static int iso_b = 0;   // real base iso
    static int iso_m = 0;   // marketing base iso

    // @tsv - marketing to real iso correspondance is quite linear so just got multiplier
    // Base values are correct only when shoot is prepared, so calc multiplier right before first shoot
    if ( !iso_m || !iso_b )
    {
        iso_b = 10 * shooting_get_iso_base();	// 10 - is additional multiplier from user_entered_value
        iso_m = shooting_get_iso_market_base();
    }

    // check zero in to_market convertion numerator
    if (iso_m == 0)
        iso_m = 1;
#else
    // If real ISO in GUI, then just multiply by 10
    static int iso_b = 10;
    static int iso_m = 1;
#endif

    // Calculate realISO (real = market * iso_b / iso_m)
    conf.autoiso_max_iso_hi_real    = conf.autoiso_max_iso_hi    * iso_b / iso_m;
    conf.autoiso_max_iso_auto_real  = conf.autoiso_max_iso_auto  * iso_b / iso_m; 
    conf.autoiso_min_iso_real	    = conf.autoiso_min_iso       * iso_b / iso_m;      
    conf.autoiso2_max_iso_auto_real = conf.autoiso2_max_iso_auto * iso_b / iso_m;

    // There are two exceptional situation: 
    // 1. shutter_numerator2 should be < shutter_numerator1, otherwise exceptional situation 
    // 2. autoiso2 <= autoiso1
    if ( !shutter2_values[conf.autoiso2_shutter_enum] )
        conf.autoiso2_max_iso_auto_real = conf.autoiso_max_iso_auto_real;

    // C2=( iso2_max_auto_real - iso_max_auto_real) / ( tv_num[autoiso2_shutter] - tv_numerator[autoiso_shutter])
    shooting_calc_autoiso_coef( shutter1_values[conf.autoiso_shutter_enum] );
}

void shooting_set_autoiso(int iso_mode)
{
    short max_iso;

    if (iso_mode<=0)
        shooting_recalc_conf_autoiso_values();

    switch (iso_mode)
    {
    case -1: // ISO HI
        //max_iso = conf.autoiso_max_iso_hi*10;
        max_iso = conf.autoiso_max_iso_hi_real;
        break;
    case 0: // ISO AUTO
        //max_iso = conf.autoiso_max_iso_auto*10;
        max_iso = conf.autoiso_max_iso_auto_real;
        break;
    default:
        return;
    }

    int m = mode_get()&MODE_SHOOTING_MASK;

    // TODO also long shutter ?
    if (m==MODE_M || m==MODE_TV || m==MODE_STITCH) return; //Only operate outside of M and Tv

    int ev_overexp = 0;
    if (conf.overexp_ev_enum)
    {
        // No shoot_histogram exist here because no future shot exist yet :)
        live_histogram_read_y();

        // step 32 is 1/3ev for tv96
        if (live_histogram_get_range(255-conf.autoiso2_over,255) >= conf.overexp_threshold)
            ev_overexp = conf.overexp_ev_enum << 5; 
    }

#ifdef OVEREXP_COMPENSATE_OVERALL
    float current_shutter = shooting_get_shutter_speed_from_tv96(shooting_get_tv96() + ev_overexp);
#else
    float current_shutter = shooting_get_shutter_speed_from_tv96(shooting_get_tv96());
#endif

    short current_iso = shooting_get_iso_real();

    short min_shutter = shutter1_values[conf.autoiso_shutter_enum];
    if (min_shutter == 0)
    {
        short IS_factor = (shooting_get_is_mode()<=1)?conf.autoiso_is_factor:1;
        min_shutter = get_focal_length(lens_get_zoom_point())*conf.autoiso_user_factor / (IS_factor*1000);
        //min_shutter is NOT 1/Xs but optimized for the calculation.
        if (shutter2_values[conf.autoiso2_shutter_enum])
            shooting_calc_autoiso_coef( min_shutter );
    }

    short target_iso = current_iso * min_shutter * current_shutter;
    short min_iso = conf.autoiso_min_iso_real;

    if (target_iso > max_iso)
    {
        ev_overexp=0;

        // AutoISO2 if
        // 	it is turned on (C2!=0.0)
        //	and it has valid iso2/shutter2 ( C2<0)
        //       and non-IsoHI mode
        if ( !iso_mode && conf.autoiso2_coef < 0.0 )
        {
            target_iso = (max_iso - min_shutter*conf.autoiso2_coef) / ( 1.0 - conf.autoiso2_coef  / (current_shutter * current_iso) );
            if ( target_iso > conf.autoiso2_max_iso_auto_real )
                target_iso = conf.autoiso2_max_iso_auto_real;
        }
        else
        {
            target_iso = max_iso;
        }
    }
    else if (target_iso < min_iso)
    {
        target_iso = min_iso;
    }

    float target_shutter = current_shutter *  current_iso / target_iso;

#ifdef OVEREXP_COMPENSATE_OVERALL
    shooting_set_shutter_speed(target_shutter, 0, SET_NOW);
#else
    // Daylight only (below autoiso_max) overexp compensation
    shooting_set_shutter_speed(target_shutter, ev_overexp, SET_NOW);
#endif

    shooting_set_iso_real(target_iso, SET_NOW);
}

//-------------------------------------------------------------------
