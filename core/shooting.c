#include "platform.h"
#include "core.h"
#include "keyboard.h"
#include "math.h"
#include "stdlib.h"
#include "conf.h"
#include "histogram.h"
#include "usb_remote.h"

// Shooting function that don't need to be ARM code
// ARM code shooting functions are in platform/generic/shooting.c

// This file needs more comments / documentation !!!!

//-------------------------------------------------------------------
// From lolevel.h
extern volatile long focus_busy;
extern long playrec_mode;

// Array & sizes stored in platform/generic/shooting.c
extern const ShutterSpeed shutter_speeds_table[];
extern const unsigned int SS_SIZE;
extern const ApertureSize aperture_sizes_table[];
extern const unsigned int AS_SIZE;
extern const ISOTable iso_table[];
extern const unsigned int ISO_SIZE;
extern const CapturemodeMap modemap[];
extern const unsigned int MODESCNT;

#define AV96_MIN (aperture_sizes_table[0].prop_id)
#define AV96_MAX (aperture_sizes_table[AS_SIZE-1].prop_id)

//-------------------------------------------------------------------
// Local shooting calculation variables
static short iso_market_base=0;
static short sv96_base=0;
static short svm96_base=0;
static short sv96_base_tmp=0;

// Storage for delayed shooting overrides
static PHOTO_PARAM photo_param_put_off;

static short *min_av96_zoom_point_tbl = NULL;

DOF_TYPE dof_values;

void shooting_init()
{
    photo_param_put_off.tv96=PHOTO_PARAM_TV_NONE;
}
//-------------------------------------------------------------------
// Functions to access Canon properties

int shooting_get_prop(int id)
{
    short vv;
    get_property_case(id, &vv, sizeof(vv));
    return vv;
}

static int shooting_get_prop_int(int id)
{
    int vv;
    get_property_case(id, &vv, sizeof(vv));
    return vv;
}

void shooting_set_prop(int id, int v)
{
    short vv = v;
    set_property_case(id, &vv, sizeof(vv));
    return;
}

short shooting_get_is_mode()                    { return shooting_get_prop(PROPCASE_IS_MODE); }
short shooting_get_canon_iso_mode()             { return shooting_get_prop(PROPCASE_ISO_MODE); }
short shooting_get_svm96()                      { return shooting_get_prop(PROPCASE_SV_MARKET); }
short shooting_get_sv96()                       { return shooting_get_prop(PROPCASE_SV); }
short shooting_get_bv96()                       { return shooting_get_prop(PROPCASE_BV); }
short shooting_get_canon_overexposure_value()   { return shooting_get_prop(PROPCASE_OVEREXPOSURE); }
short shooting_get_flash_mode()                 { return shooting_get_prop(PROPCASE_FLASH_MODE); }
short shooting_get_tv96()                       { return shooting_get_prop(PROPCASE_TV); }
short shooting_get_av96()                       { return shooting_get_prop(PROPCASE_AV); }
short shooting_get_focus_mode()                 { return shooting_get_prop(PROPCASE_FOCUS_MODE); }
short shooting_get_ev_correction1()             { return shooting_get_prop(PROPCASE_EV_CORRECTION_1); }
short shooting_get_ev_correction2()             { return shooting_get_prop(PROPCASE_EV_CORRECTION_2); }
short shooting_get_resolution()                 { return shooting_get_prop(PROPCASE_RESOLUTION); }
short shooting_get_display_mode()               { return shooting_get_prop(PROPCASE_DISPLAY_MODE); }

int   shooting_get_exif_subject_dist()          { return shooting_get_prop_int(PROPCASE_SUBJECT_DIST1); }
int   shooting_is_flash()                       { return shooting_get_prop_int(PROPCASE_IS_FLASH_READY); }
int   shooting_in_progress()                    { return shooting_get_prop_int(PROPCASE_SHOOTING); }

short shooting_get_real_focus_mode()
{
    short f = shooting_get_focus_mode();
    short m = shooting_get_prop(PROPCASE_REAL_FOCUS_MODE);
    if (f==0 && m!=0) f=(m==1)?4:m;
    return f;
}

short shooting_get_focus_state()
{
    if (shooting_get_focus_mode()==1) return -1;
    int m = shooting_get_prop_int(PROPCASE_FOCUS_STATE);
    return (short) m;
}
 
short shooting_get_focus_ok()
{
    return ((shooting_get_focus_state()!=0) && shooting_in_progress());
}

short shooting_get_user_tv96()
{
#if CAM_HAS_USER_TV_MODES
    return shooting_get_prop(PROPCASE_USER_TV);
#else
    return 0;
#endif
}

short shooting_get_user_av96()
{
#if CAM_HAS_IRIS_DIAPHRAGM
    return shooting_get_prop(PROPCASE_USER_AV);
#else
    return 0;
#endif
}

short shooting_get_drive_mode()
{
    // these cameras do not set PROPCASE_DRIVE_MODE when in custom timer mode
    // SX 200 IS 0,1,2,3,4=Off, 2 Second, Custom, Face Detection
#if defined (CAM_DRIVE_MODE_FROM_TIMER_MODE)
    short m = shooting_get_prop(PROPCASE_TIMER_MODE);
    // note we return this only in custom mode.
    // Other cameras would return 3 if any timer mode is set (?) even if it doesn't do multiple exposures
    // note that face detect does multiple exposure
    if (m == 3)
        return m;
#endif

    return shooting_get_prop(PROPCASE_DRIVE_MODE);
}

int shooting_get_zoom()
{
    return lens_get_zoom_point();
}

short shooting_get_aperture_sizes_table_size()
{
    return AS_SIZE;
}

short shooting_get_max_aperture_sizes_table_prop_id()
{
    return AV96_MAX;
}

//-------------------------------------------------------------------
// Get file related info

extern const unsigned int param_file_counter;

long get_file_counter()
{
    long v = 0;
    get_parameter_data(param_file_counter, &v, 4);
    return v;
}

long get_exposure_counter()
{
    long v = 0;
    get_parameter_data(param_file_counter, &v, 4);
    v = ((v>>4)&0x3FFF);
    return v;
}

//-------------------------------------------------------------------
// Get time related values

int shooting_get_day_seconds()
{
    struct tm *ttm;
    ttm = get_localtime();
    return ttm->tm_hour * 3600 + ttm->tm_min * 60 + ttm->tm_sec;
}

int shooting_get_tick_count()
{
    return (int)get_tick_count();
}

//-------------------------------------------------------------------
// Convert values to/from APEX 96

static const double sqrt2=1.4142135623731;  //square root from 2
static const double log_2=0.6931471805599;  //natural logarithm of 2
static const double k=12.5;                 //K is the reflected-light meter calibration constant

short shooting_get_sv96_from_iso(short iso)
{
    if (iso > 0)
        return (short)(log(pow(2.0,(-7.0/4.0))*(double)(iso))*96.0/(log_2));
    return 0;
}

short shooting_get_svm96_from_iso(short iso)
{
    if (iso > 0)
        return (short)(log((double)(iso)*32.0/100.0)*96.0/(log_2));
    return 0;
}

short shooting_get_aperture_from_av96(short av96)
{
    if (av96)
        return (short)((pow(sqrt2, ((double)av96)/96.0))*100.0);
    return -1;
}

short shooting_get_iso_from_sv96(short sv96)
{
    return (short)(pow(2, (((double) sv96+168.0)/96.0)));
}

short shooting_get_iso_market_from_svm96(short svm96)
{
    if (svm96 > 0)
        return (short)((double)pow(2, (((double)svm96)/96.0))*100.0/32.0);
    return 0;
}

short shooting_get_tv96_from_shutter_speed(float t)
{
    if (t > 0)
        return (short) (96.0*log(1.0/t)/log_2);
    return -10000;
}

float shooting_get_shutter_speed_from_tv96(short tv)
{
    return pow(2,(float)((-1)*tv)/96.0 );
}

int shooting_get_luminance()// http://en.wikipedia.org/wiki/APEX_system
{
    short bv = shooting_get_bv96();
    int b=(int)(100*k*pow(2.0,((double)(bv-168)/96.0)));
    return b;
}

//-------------------------------------------------------------------
// Get override values

// Define the adjustment factor values for the subject distance override
// Note: also used for ISO overide; but only first five values used
#if MAX_DIST > 1000000      // Superzoom - e.g. SX30, SX40
static const int koef[] = {0,1,10,100,1000,10000,100000,1000000,-1};
#elif MAX_DIST > 100000     // G12, IXUS310
static const int koef[] = {0,1,10,100,1000,10000,100000,-1};
#else                       // Original values (MAX_DIST = 65535)
static const int koef[] = {0,1,10,100,1000};
#endif

static const char * expo_shift[] = { "Off", "1/3Ev","2/3Ev", "1Ev", "1 1/3Ev", "1 2/3Ev", "2Ev", "2 1/3Ev", "2 2/3Ev", "3Ev", "3 1/3Ev", "3 2/3Ev", "4Ev"};

const char* tv_override[]={
#ifdef CAM_EXT_TV_RANGE
    // add very long time exposures as approximately powers of 2, adding 15 exposures
    "2048","1625","1290","1024","812","645","512","406","322","256","203","161","128","101","80",
#endif
    "64","50.8", "40.3", "32", "25.4","20","16", "12.7", "10","8", "6.3","5","4","3.2", "2.5","2", 
    "1.6", "1.3", "1", "0.8", "0.6", "0.5", "0.4", "0.3", "1/4", "1/5", "1/6", "1/8", "1/10", "1/13", 
    "1/15", "1/20", "1/25", "1/30", "1/40", "1/50", "1/60", "1/80", "1/100", "1/125", "1/160", "1/200", 
    "1/250", "1/320", "1/400", "1/500", "1/640","1/800", "1/1000", "1/1250", "1/1600","1/2000","1/2500",
    "1/3200","1/4000", "1/5000", "1/6400", "1/8000", "1/10000", "1/12500", "1/16000", "1/20000", "1/25000", 
    "1/32000", "1/40000", "1/50000", "1/64000","1/80000", "1/100k"
};

// Size of 'tv_override' array
const int tv_override_amount = sizeof(tv_override)/sizeof(tv_override[0]);

// Index of '0' entry in the tv_override array (1 sec)
#if CAM_EXT_TV_RANGE
const int tv_override_zero_shift = 18+15;
#else
const int tv_override_zero_shift = 18;
#endif

float shooting_get_shutter_speed_override_value()
{
    static const float shutter_koef[] = {0, 0.00001, 0.0001, 0.001, 0.01, 0.1, 1, 10, 100, 1000};
	if ( conf.tv_override_value < 0 )
		return 0;
    return (float)conf.tv_override_value*shutter_koef[conf.tv_override_koef];
}

const char * shooting_get_tv_bracket_value()
{
	if (conf.tv_bracket_value<0)
		return expo_shift[0];
    return expo_shift[conf.tv_bracket_value];
}

const char * shooting_get_tv_override_value()
{
    return tv_override[conf.tv_override_value];
}

const char * shooting_get_bracket_type()
{
    static const char * expo_type[] = { "+/-", "-","+"};
    return expo_type[conf.bracket_type];
}

short shooting_get_iso_override_value()
{
    short iso = conf.iso_override_value*koef[conf.iso_override_koef];
	if (conf.iso_override_value<0)
		iso=0;
#ifdef CAM_ISO_LIMIT_IN_HQ_BURST
    // Limit max ISO in HQ burst mode (also done in shooting_set_iso_real; but done here so OSD display value is correct)
    if ((mode_get() & MODE_SHOOTING_MASK) == MODE_SCN_HIGHSPEED_BURST)
        if (iso > CAM_ISO_LIMIT_IN_HQ_BURST) iso = CAM_ISO_LIMIT_IN_HQ_BURST;
#endif
    return iso;
}

short shooting_get_iso_bracket_value()
{
	if ( conf.iso_bracket_value<0)
		return 0;
    return conf.iso_bracket_value*koef[conf.iso_bracket_koef];
}

const char * shooting_get_av_bracket_value()
{
	if ( conf.av_bracket_value<0)
		return expo_shift[0];
    return expo_shift[conf.av_bracket_value];
}

int shooting_get_subject_distance_override_value()
{
    if (conf.subj_dist_override_value != INFINITY_DIST)
        return (conf.subj_dist_override_value < shooting_get_lens_to_focal_plane_width()?0:(conf.subj_dist_override_value - shooting_get_lens_to_focal_plane_width()));
    else
        return INFINITY_DIST;
}

int shooting_get_subject_distance_bracket_value()
{
	if ( conf.subj_dist_bracket_value<0 )
		return 0;
    return conf.subj_dist_bracket_value*koef[conf.subj_dist_bracket_koef];
}

int shooting_get_subject_distance_override_koef()
{
	if (conf.subj_dist_override_value<0)
		return 0;
    return koef[(conf.subj_dist_override_koef)];
}

short shooting_get_av96_override_value()
{
	int av = (conf.av_override_value<0) ? 0 : conf.av_override_value;
    if ( av<=AS_SIZE)
        return (short) aperture_sizes_table[av-1].prop_id;
    return (short) (AV96_MAX+32*(av-AS_SIZE));
}

//-------------------------------------------------------------------
// Get shooting value, with conversion / calculation

int shooting_mode_canon2chdk(int canonmode)
{
	int i;
	for (i=0; i < MODESCNT; i++)
    {
		if (modemap[i].canonmode == canonmode)
			return modemap[i].hackmode;
	}
	return 0;
}

int shooting_mode_chdk2canon(int hackmode)
{
	int i;
	for (i=0; i < MODESCNT; i++)
    {
		if (modemap[i].hackmode == hackmode)
			return modemap[i].canonmode;
	}
	return -1; // 0 is a valid mode on old cameras!
}

int shooting_get_user_tv_id()
{
#if CAM_HAS_USER_TV_MODES
    short tvv;
    long i;
    get_property_case(PROPCASE_USER_TV, &tvv, sizeof(tvv));
    for (i=0;i<SS_SIZE;i++)
    {
	    if (shutter_speeds_table[i].prop_id == tvv)
	        return shutter_speeds_table[i].id;
    }
#endif
    return 0;
}

const ShutterSpeed *shooting_get_tv_line()
{
    short tvv;
    long i;
    get_property_case(PROPCASE_USER_TV, &tvv, sizeof(tvv));
    for (i=0;i<SS_SIZE;i++)
    {
        if (shutter_speeds_table[i].prop_id == tvv)
            return &shutter_speeds_table[i];
    }
    return 0;
}

int shooting_get_user_av_id()
{
#if CAM_HAS_IRIS_DIAPHRAGM
    short avv;
    long i;
    get_property_case(PROPCASE_USER_AV, &avv, sizeof(avv));
    for (i=0;i<AS_SIZE;i++)
    {
        if (aperture_sizes_table[i].prop_id == avv)
            return aperture_sizes_table[i].id;
    }
#endif
    return 0;
}

// Not used
//short shooting_get_aperture_sizes_table_prop_id(short i)
//{
//    return aperture_sizes_table[i].prop_id;
//}

short shooting_get_min_real_aperture()
{
    short av96;
    get_property_case(PROPCASE_MIN_AV, &av96, sizeof(av96));
    if (av96)
        return shooting_get_aperture_from_av96(av96);
    return shooting_get_real_aperture();
}

short shooting_get_real_aperture()
{
    return shooting_get_aperture_from_av96(GetCurrentAvValue());
}

int shooting_get_iso_mode()
{
    short isov;
    long i;
    get_property_case(PROPCASE_ISO_MODE, &isov, sizeof(isov));
    for (i=0;i<ISO_SIZE;i++)
    {
        if (iso_table[i].prop_id == isov)
            return iso_table[i].id;
    }
    return 0;
}

short shooting_get_iso_real()
{
    short sv;
    get_property_case(PROPCASE_SV, &sv, sizeof(sv));
    if (sv == 0)
        return 0;
    return shooting_get_iso_from_sv96(sv);
}

short shooting_get_base_sv96()
{
    short dsv,sv;
    if (shooting_get_canon_iso_mode()<50)
    {
        get_property_case(PROPCASE_DELTA_SV, &dsv, sizeof(dsv));
        get_property_case(PROPCASE_SV, &sv, sizeof(sv));
        sv96_base = (sv-dsv);
    }
    return sv96_base;
}

short shooting_get_iso_base()
{
    sv96_base = shooting_get_base_sv96();
    if (sv96_base != 0)
        return shooting_get_iso_from_sv96(sv96_base);
    return 0;
}

short shooting_get_iso_market_base()
{
    if (iso_market_base==0)
    {
        if (iso_table[1-iso_table[0].id].prop_id == 50) iso_market_base=50;
#if defined(CAMERA_sx40hs) || defined(CAMERA_g1x)
        else iso_market_base=200;
#else
        else iso_market_base=100;
#endif
    }
    return iso_market_base;
}

// AUTOISO:EXIF
short shooting_get_iso_market()
{
    short iso_mode = shooting_get_canon_iso_mode();
    if ((iso_mode < 50) || (conf.iso_override_koef && conf.iso_override_value>0) || (conf.iso_bracket_koef && conf.iso_bracket_value))
    {
        // Original code
        // short iso_b = shooting_get_iso_base();
        // if (iso_b)
        //     return (short)((shooting_get_iso_market_base()*shooting_get_iso_real())/iso_b);

        // Above code translates to:
        //      shooting_get_iso_market_base() * pow(2,((PROPCASE_SV+168)/96)) / pow(2,(((PROPCASE_SV-PROPCASE_DELTA_SV)+168)/96))
        // code has rounding errors due to return values from pow() being cast to short before multiplication and division
        // formula can be simplified to:
        //      shooting_get_iso_market_base() * pow(2,(PROPCASE_DELTA_SV/96))
        short dsv;
        get_property_case(PROPCASE_DELTA_SV, &dsv, sizeof(dsv));
        return (short)((double)shooting_get_iso_market_base() * pow(2, (double)dsv/96.0));
    }
    return iso_mode;
}

short shooting_get_svm96_base()
{
    if (svm96_base == 0)
        svm96_base = shooting_get_svm96_from_iso(shooting_get_iso_market_base());
    return svm96_base;
}

int shooting_get_lens_to_focal_plane_width()
{
    return (int)(lens_get_focus_pos()-lens_get_focus_pos_from_lens());
}

short shooting_get_aperture_from_av96_1e3(short av96) {
	if (av96) return (short)(pow(sqrt2, (((double)av96)/96.0))*1000.0 + 0.5);
	else return -1;
}

int shooting_get_hyperfocal_distance_1e3_f2(int av_1e3, int fl)
{
  if ((av_1e3>0) && (fl>0) && (circle_of_confusion>0)) 
    return (int)(((((double)fl*fl)/(av_1e3*circle_of_confusion)*1000)+fl)+0.5);
  else return (-1);
}

int shooting_get_hyperfocal_distance_1e3_f(int av, int fl)
{
  if ((av>0) && (fl>0) && (circle_of_confusion>0)) 
    return (int)(((((double)fl*fl)/(av*circle_of_confusion)*100)+fl)+0.5);
  else return (-1);
}

int shooting_get_near_limit_f(int s, int av, int fl)
{
  if (shooting_is_infinity_distance()) return (-1);
  int h_1e3 = shooting_get_hyperfocal_distance_1e3_f(av, fl);
  double m = ((double)(h_1e3 - fl)+500)/1000*s;
  int v = ((h_1e3 - 2*fl + 1000*s)+500)/1000;
  if ((m>0) && (v>0)) return (int)((2*m/v+1)/2);
  else return (-1);
}

int shooting_get_far_limit_f(int s, int av, int fl)
{
  if (shooting_is_infinity_distance()) return (-1);
  int h_1e3 = shooting_get_hyperfocal_distance_1e3_f(av, fl);
  double m = ((double)(h_1e3 - fl)+500)/1000*s;
  int v = ((h_1e3 - 1000*s)+500)/1000;
  if ((m>0) && (v>0)) return (int)((2*m/v+1)/2);
  else return (-1); 
}

short shooting_is_infinity_distance()
{
  return (shooting_get_lens_to_focal_plane_width() == 0)?1:0;
}

int shooting_get_canon_subject_distance()
{
	if (conf.dof_use_exif_subj_dist) 
	  return shooting_get_exif_subject_dist();
	else
	  return (lens_get_focus_pos_from_lens());
}

int shooting_get_subject_distance_()
{
   if (!conf.dof_subj_dist_as_near_limit) return shooting_get_canon_subject_distance();
   else return shooting_get_far_limit_f(shooting_get_canon_subject_distance(),
                                         shooting_get_min_real_aperture(), 
                                         get_focal_length(lens_get_zoom_point()));
}

void shooting_update_dof_values()
{
  int hyp, hyp_1e3, av_1e3, v, m;
  int dist = shooting_get_subject_distance_();
  int zoom_point = lens_get_zoom_point();
  int fl = get_focal_length(zoom_point);
  short f_focus_ok = shooting_get_focus_ok();
  short f_hyp_calc = 0, f_dist_calc = 0;
  short min_av96_zoom_point = min_av96_zoom_point_tbl[zoom_point];
  short av96 = shooting_get_user_av96();
  short curr_av96 = GetCurrentAvValue();
  short prop_av96 = shooting_get_av96();
  short min_av96;

  if (!min_av96_zoom_point_tbl) {
    min_av96_zoom_point_tbl = (short *) malloc(zoom_points * sizeof(short));
    if (min_av96_zoom_point_tbl) {
      memset(min_av96_zoom_point_tbl, 0, zoom_points * sizeof(short));
      min_av96_zoom_point = 0;
    }
  } else min_av96_zoom_point = min_av96_zoom_point_tbl[zoom_point]; 

  if (min_av96_zoom_point==0 && shooting_in_progress()) { 
    get_property_case(PROPCASE_MIN_AV, &min_av96, sizeof(min_av96));
    min_av96_zoom_point_tbl[zoom_point] = min_av96;
  }

  m = mode_get()&MODE_SHOOTING_MASK;
  if ((m==MODE_M || m==MODE_AV) && (av96>0) && !f_focus_ok) { 
    if (av96 < min_av96_zoom_point) av96 = min_av96_zoom_point;
  }
  else av96 = (abs(curr_av96-prop_av96)<2)?prop_av96:curr_av96;

  av_1e3 = shooting_get_aperture_from_av96_1e3(av96);
  hyp_1e3 = dof_values.hyperfocal_distance_1e3;
  hyp = dof_values.hyperfocal_distance;
  
  if (dof_values.aperture_value!=av_1e3 || dof_values.focal_length!=fl || (hyp_1e3<0)) { 
    //calc new hyperfocal distance and min stack distance
    f_hyp_calc = 1;
    hyp_1e3 = -1;
    hyp = -1;
    dof_values.aperture_value = av_1e3;
    dof_values.focal_length = fl;
    hyp_1e3 = shooting_get_hyperfocal_distance_1e3_f2(av_1e3, fl);
    if (hyp_1e3>0) {
      hyp = (hyp_1e3+500)/1000;
      dof_values.min_stack_distance = MAX_DIST;
      v = ((hyp_1e3 - fl)/250 + 2 + 1)/2;
      if (v>0) {
        int m = ((fl*((fl - hyp_1e3)/1000 - 1)/500)/v + 1)/2;
        int m2 = (int)((((double)hyp*(2*fl - hyp_1e3)/1000))/v + 0.5);
        dof_values.min_stack_distance = sqrt(m*m - m2) - m;
      }  
    }
  }

  if ((dof_values.subject_distance!=dist || (dof_values.hyperfocal_distance_1e3!=hyp_1e3)) && (hyp_1e3>0)) {
    //calc new NEAR, FAR, DOF values
    f_dist_calc = 1;
    dof_values.subject_distance = dist;
    dof_values.near_limit = -1;
    dof_values.far_limit = -1;
    dof_values.depth_of_field = -1;
    if ((av_1e3>0) && (fl>0) && (dist>0) && (shooting_is_infinity_distance()==0) && (hyp_1e3>0)) {
      double m = ((double)(hyp_1e3 - fl)/1000 * dist) + 0.5;
      if (conf.dof_subj_dist_as_near_limit) { 
         dof_values.near_limit = dist;
      } else {
        int v = ((((hyp_1e3 - 2*fl + 1000*dist)/500) + 1)/2);
   	    if (v>0) dof_values.near_limit = (int)(m/v);
   	  }
      int v = ((((hyp_1e3 - 1000*dist)/500) + 1)/2);
      if (v>0) dof_values.far_limit = (int)(m/v);
      if ((dof_values.near_limit>0) && (dof_values.far_limit>0)) {
        dof_values.depth_of_field = dof_values.far_limit - dof_values.near_limit;
      }
    }
  }
  dof_values.hyperfocal_distance_1e3 = hyp_1e3;
  dof_values.hyperfocal_distance = hyp; 
  f_focus_ok = (f_focus_ok && shooting_get_focus_ok());
  dof_values.hyperfocal_valid = (f_focus_ok || (dof_values.hyperfocal_valid && !f_hyp_calc));
  dof_values.distance_valid = (f_focus_ok || (dof_values.distance_valid && !f_dist_calc)||(dof_values.hyperfocal_valid && shooting_get_focus_mode()));
  return;
}

int shooting_get_subject_distance()
{
  shooting_update_dof_values();
  return dof_values.subject_distance;
}

int shooting_get_hyperfocal_distance()
{
  shooting_update_dof_values();
  return dof_values.hyperfocal_distance;
}

int shooting_get_near_limit_of_acceptable_sharpness()
{
  shooting_update_dof_values();
  return dof_values.near_limit;
}

int shooting_get_far_limit_of_acceptable_sharpness()
{
  shooting_update_dof_values();
  return dof_values.far_limit;
}

int shooting_get_depth_of_field()
{
  shooting_update_dof_values();
  return dof_values.depth_of_field;
}

int shooting_get_min_stack_distance()
{
  shooting_update_dof_values();
  return dof_values.min_stack_distance;
}

short shooting_can_focus()
{
    int m=mode_get()&MODE_SHOOTING_MASK;
#if !CAM_CAN_SD_OVER_NOT_IN_MF && CAM_CAN_SD_OVERRIDE
#if CAM_CAN_SD_OVER_IN_AF_LOCK_ONLY
    if (shooting_get_prop(PROPCASE_AF_LOCK))
        return 1;
    else if (!MODE_IS_VIDEO(m))
        return 0;
#elif CAM_CAN_SD_OVER_IN_AF_LOCK
    if (shooting_get_prop(PROPCASE_AF_LOCK))
        return 1;
#elif CAM_HAS_VIDEO_BUTTON
	return shooting_get_common_focus_mode();
#endif
    return (shooting_get_common_focus_mode() || MODE_IS_VIDEO(m));
#elif !CAM_CAN_SD_OVERRIDE
    return MODE_IS_VIDEO(m);
#elif defined (CAMERA_ixus800_sd700)
    // TODO whats the reason for this ?!?
    return (shooting_get_zoom()<8) && (m!=MODE_AUTO) && (m!=MODE_SCN_UNDERWATER);
#else
    return 1;
#endif
}

short shooting_get_common_focus_mode()
{
#if !CAM_HAS_MANUAL_FOCUS && CAM_CAN_SD_OVERRIDE
    return shooting_get_subject_distance_override_koef();
#elif !CAM_CAN_SD_OVERRIDE
    return 0;
#else
    return shooting_get_focus_mode();
#endif
}

int shooting_is_flash_ready()
{
    int t = shooting_get_flash_mode();
    if ((t != 2) && (shooting_in_progress()))
        if (shooting_is_flash()) 
            return IsStrobeChargeCompleted();
    return 1;
}

// Only needed on VxWorks
#if CAM_DRAW_EXPOSITION

// compare PROPCASE_TV with shutter_speeds_table
char* shooting_get_tv_str()
{
    short int tvv;
    long i;
    get_property_case(PROPCASE_TV, &tvv, sizeof(tvv));
    for(i=0; i<SS_SIZE; i++)
    {
        if(shutter_speeds_table[i].prop_id >= tvv)
            return (char*)shutter_speeds_table[i].name;
    }
    return (void*)"?";
}

// compare PROPCASE_AV with aperture_sizes_table
char* shooting_get_av_str()
{
    short int avv;
    long i;
    get_property_case(PROPCASE_AV, &avv, sizeof(avv));
    for(i=0; i<AS_SIZE; i++)
    {
        if(aperture_sizes_table[i].prop_id == avv)
            return (char*)aperture_sizes_table[i].name;
    }
    return (char*) "?";
}

#endif

//-------------------------------------------------------------------
// Overrides for camera settings

void shooting_set_user_tv_by_id(int v)
{
#if CAM_HAS_USER_TV_MODES
    if ((mode_get()&MODE_MASK) != MODE_PLAY)
    {
        long i;
        for (i=0;i<SS_SIZE;i++)
        {
            if (shutter_speeds_table[i].id == v)
            {
                short vv = shutter_speeds_table[i].prop_id;
                set_property_case(PROPCASE_USER_TV, &vv, sizeof(vv));
                //set_property_case(PROPCASE_TV, &vv, sizeof(vv));
                return;
            }
        }
    }
#endif
}

void shooting_set_user_tv96(short v)
{
#if CAM_HAS_USER_TV_MODES
    if ((mode_get()&MODE_MASK) != MODE_PLAY)
    {
        long i;
        for (i=0;i<SS_SIZE;i++)
        {
            if (shutter_speeds_table[i].prop_id == v)
            {
                set_property_case(PROPCASE_USER_TV, &v, sizeof(v));
                //set_property_case(PROPCASE_TV, &v, sizeof(v));
                return;
            }
        }
    }
#endif
}

void shooting_set_tv96(short v, short is_now)
{
    long i;
    if ((mode_get()&MODE_MASK) != MODE_PLAY)
    {
        for (i=0;i<SS_SIZE;i++)
        {
            if (shutter_speeds_table[i].prop_id == v)
            {
                shooting_set_tv96_direct(v, is_now);
                return;
            }
        }
    }
}

void shooting_set_user_tv_by_id_rel(int v)
{
#if CAM_HAS_USER_TV_MODES
    if ((mode_get()&MODE_MASK) != MODE_PLAY)
    {
        int cv = shooting_get_user_tv_id();
        shooting_set_user_tv_by_id(cv+v);
    }
#endif
}

void shooting_set_shutter_speed(float t, short ev_correction, short is_now)
{
	if (t>0) shooting_set_tv96_direct( ((short) 96.0*log(1/t)/log_2) + ev_correction, is_now);
}

void shooting_set_shutter_speed_ubasic(int t, short is_now)
{
    if ((mode_get()&MODE_MASK) != MODE_PLAY)
    {
        if (t>0)
            shooting_set_tv96_direct((short) (96.0*log(100000.0/(double)t)/log_2), is_now);
    }
}

void shooting_set_av96(short v, short is_now)
{
#if CAM_HAS_IRIS_DIAPHRAGM
    if ((mode_get()&MODE_MASK) != MODE_PLAY)
    {
        long i;
        for (i=0;i<AS_SIZE;i++)
        {
            if (aperture_sizes_table[i].prop_id == v)
            {
                shooting_set_av96_direct(v, is_now);
                return;
            }
        }
    }
#endif
}

void shooting_set_user_av96(short v)
{
#if CAM_HAS_IRIS_DIAPHRAGM
    long i;
    if ((mode_get()&MODE_MASK) != MODE_PLAY)
    {
        for (i=0;i<AS_SIZE;i++)
        {
            if (aperture_sizes_table[i].prop_id == v)
            {
                set_property_case(PROPCASE_USER_AV, &v, sizeof(v));
                //set_property_case(PROPCASE_AV, &v, sizeof(v));
                return;
            }
        }
    }
#endif
}

void shooting_set_user_av_by_id(int v)
{
#if CAM_HAS_IRIS_DIAPHRAGM
    long i;
    if ((mode_get()&MODE_MASK) != MODE_PLAY)
    {
        for (i=0;i<AS_SIZE;i++)
        {
            if (aperture_sizes_table[i].id == v)
            {
                short vv = aperture_sizes_table[i].prop_id;
                set_property_case(PROPCASE_USER_AV, &vv, sizeof(vv));
                //set_property_case(PROPCASE_AV, &vv, sizeof(vv));
                return;
            }
        }
    }
#endif
}

void shooting_set_sv96(short sv96, short is_now)
{
    short dsv96=0, iso_mode=shooting_get_canon_iso_mode();
    if ((mode_get()&MODE_MASK) != MODE_PLAY)
    {
        if (is_now)
        {
            if (iso_mode<50)
                dsv96 =sv96-shooting_get_base_sv96();
            else if (sv96_base)
                dsv96=sv96-sv96_base;
            else if (sv96_base_tmp)
                dsv96=sv96-sv96_base_tmp;
            else
            {
                sv96_base_tmp= (short)((shooting_get_svm96_base()*shooting_get_sv96())/shooting_get_svm96());
                dsv96=sv96-sv96_base_tmp;
            }
            while ((shooting_is_flash_ready()!=1) || (focus_busy));
            short svm96_base =shooting_get_svm96_base();
            if (iso_mode>=50)
                shooting_set_iso_mode(0);
            set_property_case(PROPCASE_SV_MARKET, &svm96_base, sizeof(svm96_base));
            set_property_case(PROPCASE_SV, &sv96, sizeof(sv96));
            set_property_case(PROPCASE_DELTA_SV, &dsv96, sizeof(dsv96));
        }
        else   
            photo_param_put_off.sv96=sv96;
    }
}

void shooting_set_iso_mode(int v)
{
    long i;
    for (i=0;i<ISO_SIZE;i++)
    {
        if (iso_table[i].id == v)
        {
            short vv = iso_table[i].prop_id;
            set_property_case(PROPCASE_ISO_MODE, &vv, sizeof(vv));
            return;
        }
    }
}

void shooting_set_iso_real(short iso, short is_now)
{
    if ((mode_get()&MODE_MASK) != MODE_PLAY)
    {
        if (iso>0)
        {
#ifdef CAM_ISO_LIMIT_IN_HQ_BURST
            // Limit max ISO in HQ burst mode
            if ((mode_get() & MODE_SHOOTING_MASK) == MODE_SCN_HIGHSPEED_BURST)
                if (iso > CAM_ISO_LIMIT_IN_HQ_BURST) iso = CAM_ISO_LIMIT_IN_HQ_BURST;
#endif
            shooting_set_sv96(shooting_get_sv96_from_iso(iso), is_now);
        }
    }
}

void shooting_set_tv96_direct(short v, short is_now)
{
    if ((mode_get()&MODE_MASK) != MODE_PLAY)
    {
        if(is_now)
        {
            set_property_case(PROPCASE_TV, &v, sizeof(v));
#ifdef PROPCASE_TV2
            set_property_case(PROPCASE_TV2, &v, sizeof(v));   // Save override to property that will update JPEG header & Canon OSD
#endif
        }
        else
            photo_param_put_off.tv96=v;
    }
}

void shooting_set_av96_direct(short v, short is_now)
{
#if CAM_HAS_IRIS_DIAPHRAGM
    if ((mode_get()&MODE_MASK) != MODE_PLAY)
    {
        if(is_now)
        {
            set_property_case(PROPCASE_AV, &v, sizeof(v));
#ifdef PROPCASE_AV2
            set_property_case(PROPCASE_AV2, &v, sizeof(v));   // Save override to property that will update JPEG header & Canon OSD
#endif
        }
        else
            photo_param_put_off.av96=v;
    }
#endif
}

void shooting_set_user_av_by_id_rel(int v)
{
#if CAM_HAS_IRIS_DIAPHRAGM
    if ((mode_get()&MODE_MASK) != MODE_PLAY)
    {
        int cv = shooting_get_user_av_id();
        shooting_set_user_av_by_id(cv+v);
    }
#endif
}

#if CAM_QUALITY_OVERRIDE
void shooting_set_image_quality(int imq)
{
    if (imq != 3)
    {
        set_property_case(PROPCASE_QUALITY, &imq, sizeof(imq));
    }
}
#endif

void shooting_set_zoom(int v)
{
    int dist;
    if ((mode_get()&MODE_MASK) != MODE_PLAY)
    {
        dist = shooting_get_subject_distance();
        lens_set_zoom_point(v);
#if defined(CAM_NEED_SET_ZOOM_DELAY)
        msleep(CAM_NEED_SET_ZOOM_DELAY);
#endif
        shooting_set_focus(dist, SET_NOW);
    }
}

void shooting_set_zoom_rel(int v)
{
    int cv = shooting_get_zoom();
    if ((mode_get()&MODE_MASK) != MODE_PLAY)
    {
        shooting_set_zoom(cv+v);
    }
}

void shooting_set_zoom_speed(int v) {
    if ((mode_get()&MODE_MASK) != MODE_PLAY)
    {
        lens_set_zoom_speed(v);
    }
}

void shooting_set_focus(int v, short is_now)
{
    int s=v;
    if ((mode_get()&MODE_MASK) != MODE_PLAY)
    {
        if ((is_now) && shooting_can_focus())
        {
            if (conf.dof_subj_dist_as_near_limit)
            {
                s=shooting_get_near_limit_f(v,shooting_get_min_real_aperture(),get_focal_length(lens_get_zoom_point()));
            }
            if (!conf.dof_use_exif_subj_dist && (s != INFINITY_DIST)) 
                s+=shooting_get_lens_to_focal_plane_width();
            lens_set_focus_pos(s); 
        }
        else
            photo_param_put_off.subj_dist=v;
    }
}

void shooting_video_bitrate_change(int v)
{
#if CAM_CHDK_HAS_EXT_VIDEO_MENU
    int m[]={1,2,3,4,5,6,7,8,10,12};  // m[v]/4 = bitrate*1x
    if (v>=(sizeof(m)/sizeof(m[0])))
        v=(sizeof(m)/sizeof(m[0]))-1;
    change_video_tables(m[v],4);
#endif
}

void shooting_calc_autoiso_coef( int min_shutter )
{
	if ( conf.autoiso2_min_shutter_numerator >= min_shutter ) {
		conf.autoiso2_coef = 0.0;
	}
	else {
		conf.autoiso2_coef = (float)(conf.autoiso2_max_iso_auto_real - conf.autoiso_max_iso_auto_real) / 
				(float)( conf.autoiso2_min_shutter_numerator - min_shutter);
	}
}

void shooting_recalc_conf_autoiso_values()
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
    if ( !iso_m )
    iso_m = iso_m ? iso_m : 1;
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
    if ( !conf.autoiso2_min_shutter_numerator ) {
        conf.autoiso2_max_iso_auto_real = conf.autoiso_max_iso_auto_real;
    }

    // C2=( iso2_max_auto_real - iso_max_auto_real) / ( tv_num[autoiso2_shutter] - tv_numerator[autoiso_shutter])
    shooting_calc_autoiso_coef( conf.autoiso_min_shutter_numerator );
}

void shooting_set_autoiso(int iso_mode)
{
    short max_iso;
	if ( iso_mode<=0 && conf.autoiso_max_iso_auto_real==0) {
		shooting_recalc_conf_autoiso_values();
	}
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
    int m=mode_get()&MODE_SHOOTING_MASK;
    // TODO also long shutter ?
    if (m==MODE_M || m==MODE_TV || m==MODE_STITCH) return; //Only operate outside of M and Tv
	int ev_overexp = 0;
	if ( conf.overexp_ev_enum>0 )
	{
		// No shoot_histogram exist here because no future shot exist yet :)
		live_histogram_process_quick();

		// step 32 is 1/3ev for tv96
		if ( live_histogram_get_range(255-conf.autoiso2_over,255) >= conf.overexp_threshold ) {
			ev_overexp = conf.overexp_ev_enum << 5; 
		}
		live_histogram_end_process();
	}

#ifdef OVEREXP_COMPENSATE_OVERALL
	float current_shutter = shooting_get_shutter_speed_from_tv96( shooting_get_tv96() + ev_overexp );
#else
	float current_shutter = shooting_get_shutter_speed_from_tv96(shooting_get_tv96());
#endif

    short current_iso=shooting_get_iso_real();

	short min_shutter = conf.autoiso_min_shutter_numerator;
	if (min_shutter == 0) {
		short IS_factor = (shooting_get_is_mode()<=1)?conf.autoiso_is_factor:1;
		min_shutter = get_focal_length(lens_get_zoom_point())*conf.autoiso_user_factor / (IS_factor*1000);
		//min_shutter is NOT 1/Xs but optimized for the calculation.
		if ( conf.autoiso2_min_shutter_numerator ) {
			shooting_calc_autoiso_coef( min_shutter );
		}
	}

    short target_iso = current_iso * min_shutter * current_shutter;
	short min_iso = conf.autoiso_min_iso_real;
	
	if (target_iso > max_iso) {
		ev_overexp=0;

		// AutoISO2 if
		// 	it is turned on (C2!=0.0)
		//	and it has valid iso2/shutter2 ( C2<0)
		//       and non-IsoHI mode
		if ( !iso_mode && conf.autoiso2_coef < 0.0 ) {
			target_iso = (max_iso - min_shutter*conf.autoiso2_coef) / ( 1.0 - conf.autoiso2_coef  / (current_shutter * current_iso) );
			if ( target_iso > conf.autoiso2_max_iso_auto_real ) {
				target_iso = conf.autoiso2_max_iso_auto_real;
			}
		} else {
			target_iso = max_iso;
		}
	} else if (target_iso < min_iso) {
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

#if CAM_REAR_CURTAIN
void shooting_set_flash_sync_curtain(int curtain)
{
    set_property_case(PROPCASE_FLASH_SYNC_CURTAIN, &curtain, sizeof(curtain));
}
#endif

// forces manual flash. if set, flash will ALWAYS be triggered (manual)
void shooting_set_flash_video_override(int flash, int power)
{
    int mode = 1;
    if ( (conf.flash_manual_override && power>=0 ) && 
		 ( (conf.flash_video_override && is_video_recording()) || !conf.flash_video_override )
	   )
    {
        set_property_case(PROPCASE_FLASH_ADJUST_MODE, &mode, sizeof(mode));
        set_property_case(PROPCASE_FLASH_FIRE, &flash, sizeof(flash));
        set_property_case(PROPCASE_FLASH_MANUAL_OUTPUT, &power, sizeof(power));
    }
}

void shooting_set_nd_filter_state(short v, short is_now)
{
#if CAM_HAS_ND_FILTER
    if ((mode_get()&MODE_MASK) != MODE_PLAY)
    {
        if (is_now)
        {
            if (v==1)
                PutInNdFilter();
            else if (v==2)
                PutOutNdFilter();
#if defined(CAM_HAS_NATIVE_ND_FILTER) && defined(PROPCASE_ND_FILTER_STATE)
            int n = (v==1) ? 1 : 0;
            set_property_case(PROPCASE_ND_FILTER_STATE, &n, sizeof(n));
#endif
        }
        else
            photo_param_put_off.nd_filter=v;
    }
#endif
}

void unlock_optical_zoom(void)
{
#if CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO
    if (conf.unlock_optical_zoom_for_video) UnsetZoomForMovie();
#endif

#if CAM_EV_IN_VIDEO
    set_ev_video_avail(0);
#endif
}

int shooting_set_mode_canon(int canonmode)
{
    if (canonmode == -1 || !rec_mode_active())
        return 0;
    SetCurrentCaptureModeType(canonmode);
    return 1;
}

int shooting_set_mode_chdk(int mode)
{
    return shooting_set_mode_canon(shooting_mode_chdk2canon(mode));
}

//-------------------------------------------------------------------
// Bracketing functions

EXPO_BRACKETING_VALUES bracketing;

void shooting_tv_bracketing(int when)
{
    short value, is_odd;
    int m=mode_get()&MODE_SHOOTING_MASK;
    if (bracketing.shoot_counter==0)
    { // first shoot
        bracketing.shoot_counter=1;
        // if Tv override is enabled... (this was adapted from function shooting_expo_param_override() )
        if ( ((conf.tv_enum_type) || (conf.tv_override_value)) && (conf.tv_override_koef && conf.tv_override_value>=0) && !(conf.override_disable==1) )
        {
            // ...use Tv override value as seed for bracketing:
            if (conf.tv_enum_type)
                bracketing.tv96 = 32*(conf.tv_override_value-tv_override_zero_shift);
            else
                bracketing.tv96 = shooting_get_tv96_from_shutter_speed(shooting_get_shutter_speed_override_value());
        }
        // Tv override is disabled, use camera's opinion of Tv for bracketing seed value.
        else 
        {
            if (!(m==MODE_M || m==MODE_TV || m==MODE_LONG_SHUTTER)) bracketing.tv96=shooting_get_tv96();
            else bracketing.tv96=shooting_get_user_tv96();
        }
        bracketing.tv96_step=(conf.tv_bracket_value<=0)?0:(32*conf.tv_bracket_value);

    }
    // other shoots
    bracketing.shoot_counter++;
    is_odd=(bracketing.shoot_counter&1);
    if ((!is_odd) || (conf.bracket_type>0))
        bracketing.dtv96+=bracketing.tv96_step;
    if (((!is_odd) && (conf.bracket_type==0)) || (conf.bracket_type==1))
        value=bracketing.tv96-bracketing.dtv96;
    else value=bracketing.tv96+bracketing.dtv96;

    shooting_set_tv96_direct(value, when);
}

void shooting_av_bracketing(int when)
{
    short value,is_odd;

    int m = mode_get()&MODE_SHOOTING_MASK;

    if (bracketing.shoot_counter == 0)
    { // first shoot
        bracketing.shoot_counter = 1;
        //short av_override_value=shooting_get_av96_override_value;
        //if (av_override_value) bracketing.av96=av_override_value;
        if (!(m==MODE_M || m==MODE_AV))
            bracketing.av96 = shooting_get_av96();
        else
            bracketing.av96 = shooting_get_user_av96();
        bracketing.av96_step = (conf.av_bracket_value<=0)?0:(32*conf.av_bracket_value);
    }
    // other shoots
    bracketing.shoot_counter++;
    is_odd = (bracketing.shoot_counter&1);
    value = bracketing.av96;

    if ( !is_odd || (conf.bracket_type > 0) || ( is_odd && (conf.bracket_type == 0) && ((bracketing.av96 - bracketing.dav96) < AV96_MIN) ))
    {
        bracketing.dav96 += bracketing.av96_step;
    }

    if (((!is_odd && (conf.bracket_type == 0)) || (conf.bracket_type == 1)) && ((bracketing.av96 - bracketing.dav96) >= AV96_MIN))
    {
        value -= bracketing.dav96;
    }
    else if ((is_odd && (conf.bracket_type == 0)) 
            || (conf.bracket_type == 2) 
            || ((!is_odd && (conf.bracket_type == 0)) && ((bracketing.av96 - bracketing.dav96) < AV96_MIN)))
    {
        value += bracketing.dav96;
    }

    if (value != bracketing.av96)
    {
        shooting_set_av96_direct(value, when);
#ifdef CAM_AV_OVERRIDE_IRIS_FIX
        MoveIrisWithAv(&value);
#endif
    }
}

void shooting_iso_bracketing(int when){
    short value=0, is_odd;
    if (bracketing.shoot_counter==0)
    { // first shoot
        bracketing.shoot_counter=1;
        bracketing.iso=shooting_get_iso_real();
        bracketing.iso_step=shooting_get_iso_bracket_value();
    }
    // other shoots
    bracketing.shoot_counter++;
    is_odd=(bracketing.shoot_counter&1);

    if (((!is_odd) || (conf.bracket_type>0)) || (((is_odd) && (conf.bracket_type==0)) && (bracketing.iso<=bracketing.diso)))
    {
        bracketing.diso+=bracketing.iso_step;
    }
    if ((((!is_odd) && (conf.bracket_type==0)) || (conf.bracket_type==1)) && (bracketing.iso>bracketing.diso))
    {
        value=bracketing.iso-bracketing.diso;
        shooting_set_iso_real(value, when);
    }
    else if ((((is_odd) && (conf.bracket_type==0)) || (conf.bracket_type==2)) || (((!is_odd) && (conf.bracket_type==0)) && (bracketing.iso<=bracketing.diso)))
    {
        value=bracketing.iso+bracketing.diso;
        shooting_set_iso_real(value, when);
    }
}

void shooting_subject_distance_bracketing(int when){
    short value=0, is_odd;
    if (bracketing.shoot_counter==0)
    { // first shoot
        bracketing.shoot_counter=1;
        bracketing.subj_dist=shooting_get_subject_distance();
        bracketing.subj_dist_step=shooting_get_subject_distance_bracket_value();
    }
    // other shoots
    bracketing.shoot_counter++;
    is_odd=(bracketing.shoot_counter&1);
    if (((!is_odd) || (conf.bracket_type>0)) || (((is_odd) && (conf.bracket_type==0)) && (bracketing.subj_dist<=bracketing.dsubj_dist)))
    {
        bracketing.dsubj_dist+=bracketing.subj_dist_step;
    }
    if ((((!is_odd) && (conf.bracket_type==0)) || (conf.bracket_type==1)) && (bracketing.subj_dist>bracketing.dsubj_dist))
    {
        value=bracketing.subj_dist-bracketing.dsubj_dist;
        shooting_set_focus(value, when);
    }
    else if ((((is_odd) && (conf.bracket_type==0)) || (conf.bracket_type==2)) || (((!is_odd) && (conf.bracket_type==0)) && (bracketing.subj_dist<=bracketing.dsubj_dist)))
    {
        value=bracketing.subj_dist+bracketing.dsubj_dist;
        shooting_set_focus(value, when);
    }
}

void bracketing_reset()
{
    bracketing.shoot_counter=0;
    bracketing.av96=0;
    bracketing.dav96=0;
    bracketing.tv96=0;
    bracketing.dtv96=0;
    bracketing.sv96=0;
    bracketing.dsv96=0;
    bracketing.iso=0;
    bracketing.diso=0;
    bracketing.subj_dist=0;
    bracketing.dsubj_dist=0;
    bracketing.type=0;
}

void bracketing_step(int when)
{
    if (conf.tv_bracket_value>0 && !(conf.override_disable==1 && conf.override_disable_all))
        shooting_tv_bracketing(when);
    else if (conf.av_bracket_value>0 && !(conf.override_disable==1 && conf.override_disable_all))
        shooting_av_bracketing(when);
    else if ((conf.iso_bracket_value>0 && !(conf.override_disable==1 && conf.override_disable_all)) && (conf.iso_bracket_koef))
        shooting_iso_bracketing(when);
    else if ((conf.subj_dist_bracket_value>0 && !(conf.override_disable==1 && conf.override_disable_all)) && (conf.subj_dist_bracket_koef))
        shooting_subject_distance_bracketing(when);   	      
    else if ((conf.subj_dist_bracket_value>0) && (conf.subj_dist_bracket_koef))
        shooting_subject_distance_bracketing(when);
}

void shooting_bracketing(void)
{  
    if (shooting_get_drive_mode()!=0)  
    {
        int m=mode_get()&MODE_SHOOTING_MASK;
        if (m!=MODE_STITCH && m!=MODE_SCN_BEST_IMAGE) 
        {
            if (state_shooting_progress != SHOOTING_PROGRESS_PROCESSING)
                bracketing_reset() ;
            bracketing_step(SET_NOW) ;
        }
    }

}

//-------------------------------------------------------------------
// Other state test functions. 
// Not strictly shooting related; but somehow ended up here.

// TODO sd990 hack for overrides
// caller must save regs
int captseq_hack_override_active()
{
    if (state_kbd_script_run)
        if ( photo_param_put_off.tv96 != PHOTO_PARAM_TV_NONE || photo_param_put_off.sv96 )
            return 1;
    if(conf.override_disable==1)
        return 0;
    if(conf.iso_override_value>0 && conf.iso_override_koef)
        return 1;
    if((conf.tv_enum_type || conf.tv_override_value) && conf.tv_override_koef && conf.tv_override_value>=0)
        return 1;
    return 0;
}

// Return whether video is being recorded
int is_video_recording()
{
#if defined(CAM_HAS_MOVIE_DIGEST_MODE)
    // If camera has movie digest mode then movie_status values are different than previous models
    // 'movie_status' values
    //      0 - after startup
    //      1 - movie recording stopped
    //      4 - movie recording in progress, or in 'movie digest' scene mode
    //      5 - movie recording stopping
    //      6 - in video mode, not recording
    return ((movie_status == VIDEO_RECORD_IN_PROGRESS) && ((mode_get() & MODE_SHOOTING_MASK) != MODE_VIDEO_MOVIE_DIGEST));
#else
    // 'movie_status' values
    //      0 - after startup
    //      1 - movie recording stopped
    //      4 - movie recording in progress
    //      5 - movie recording stopping
    return (movie_status > 1);
#endif
}

// Converted from MODE_IS_VIDEO macro (philmoz July 2011)
int mode_is_video(int m)
{
    m = m & MODE_SHOOTING_MASK;
    return (m==MODE_VIDEO_STD ||
            m==MODE_VIDEO_SPEED ||
            m==MODE_VIDEO_COMPACT ||
            m==MODE_VIDEO_MY_COLORS ||
            m==MODE_VIDEO_COLOR_ACCENT ||
            m==MODE_VIDEO_COLOR_SWAP ||
            m==MODE_VIDEO_MINIATURE ||
            m==MODE_VIDEO_TIME_LAPSE ||
            m==MODE_VIDEO_PORTRAIT ||
            m==MODE_VIDEO_NIGHT ||
            m==MODE_VIDEO_INDOOR ||
            m==MODE_VIDEO_FOLIAGE ||
            m==MODE_VIDEO_SNOW  ||
            m==MODE_VIDEO_BEACH ||
            m==MODE_VIDEO_AQUARIUM ||
            m==MODE_VIDEO_SUPER_MACRO ||
            m==MODE_VIDEO_STITCH ||
            m==MODE_VIDEO_MANUAL ||
            m==MODE_VIDEO_MINIATURE ||
            m==MODE_VIDEO_IFRAME_MOVIE
        // not clear if this should be considered a video mode ?
        //  m==MODE_VIDEO_MOVIE_DIGEST
        );
}

// override in platform/<cam>/main.c if playrec_mode is not found or different
int __attribute__((weak)) rec_mode_active(void)
{
    return (playrec_mode==2 || playrec_mode==4 || playrec_mode==5);
}

int mode_get(void)
{
    int mode, t=0xFF;

    mode = (rec_mode_active())?MODE_REC:MODE_PLAY;

#ifdef CAM_SWIVEL_SCREEN
    mode |= (screen_opened())?MODE_SCREEN_OPENED:0;
    mode |= (screen_rotated())?MODE_SCREEN_ROTATED:0;
#endif

    get_property_case(PROPCASE_SHOOTING_MODE, &t, 4);
    mode |= shooting_mode_canon2chdk(t);

    return (mode);
}

//-------------------------------------------------------------------
// Exposure control in video

#if CAM_EV_IN_VIDEO

int ev_video_avail;
int ev_video;
int save_tv_video;
int tv_min_video;

int get_ev_video_avail(void)
{
    return ev_video_avail;
}

int get_ev_video(void)
{
    return ev_video;
}

void set_ev_video_avail(int x)
{
    if (ev_video_avail==x) return;
    ev_video_avail=x;
    if (x)
    {
        ev_video=0;
        ExpCtrlTool_StopContiAE(0,0);
        get_property_case(PROPCASE_TV,&save_tv_video,2);
        if ((mode_get()&MODE_SHOOTING_MASK)==MODE_VIDEO_SPEED)
            tv_min_video=577;   // 1/60
        else
            tv_min_video=480;   //1/30
    }
    else
        ExpCtrlTool_StartContiAE(0,0);
}

void set_ev_video(int x)
{
    short ev, tv;
    if ((x<-4)||(x>4))
        return;

    ev=48*x;
    tv=save_tv_video-ev;
    if (tv>=tv_min_video)
    {
        ev_video=x;
        SetAE_ShutterSpeed(&tv);
    }
}

#endif

//-------------------------------------------------------------------
// Main exposure override function called from capt_seq_task()

void shooting_expo_param_override_thumb(void)
{
    if ( ((state_kbd_script_run) || (usb_remote_active)) && (photo_param_put_off.tv96 != PHOTO_PARAM_TV_NONE))
    {
        shooting_set_tv96_direct(photo_param_put_off.tv96, SET_NOW);
        photo_param_put_off.tv96=PHOTO_PARAM_TV_NONE;
    }
    else if (((conf.tv_enum_type) || (conf.tv_override_value)) && (conf.tv_override_koef && conf.tv_override_value>=0) && !(conf.override_disable==1))
    {
        if (conf.tv_enum_type)
            shooting_set_tv96_direct(32*(conf.tv_override_value-(tv_override_zero_shift)),SET_NOW);
        else
            shooting_set_tv96_direct(shooting_get_tv96_from_shutter_speed(shooting_get_shutter_speed_override_value()), SET_NOW);
    }

    if (((state_kbd_script_run) || (usb_remote_active)) && (photo_param_put_off.sv96))
    {
        shooting_set_sv96(photo_param_put_off.sv96, SET_NOW);
        photo_param_put_off.sv96=0;
    }
    else if ((conf.iso_override_value>0) && (conf.iso_override_koef) && !(conf.override_disable==1))
        shooting_set_iso_real(shooting_get_iso_override_value(), SET_NOW);
    else if (conf.autoiso_enable && shooting_get_flash_mode()/*NOT FOR FLASH AUTO MODE*/ && !(conf.override_disable==1 && conf.override_disable_all))
        shooting_set_autoiso(shooting_get_iso_mode());

    if (((state_kbd_script_run) || (usb_remote_active)) && (photo_param_put_off.av96))
    {
        shooting_set_av96_direct(photo_param_put_off.av96, SET_NOW);
        photo_param_put_off.av96=0;
    }
    else if (conf.av_override_value>0 && !(conf.override_disable==1))
        shooting_set_av96_direct(shooting_get_av96_override_value(), SET_NOW);

    if (((state_kbd_script_run) || (usb_remote_active)) && (photo_param_put_off.subj_dist))
    {
        shooting_set_focus(photo_param_put_off.subj_dist, SET_NOW);
        photo_param_put_off.subj_dist=0;
    }
    else if ((conf.subj_dist_override_value>0) && (conf.subj_dist_override_koef) && !(conf.override_disable==1))
        shooting_set_focus(shooting_get_subject_distance_override_value(), SET_NOW);

#if CAM_HAS_ND_FILTER
    if ((state_kbd_script_run) && (photo_param_put_off.nd_filter))
    {
        shooting_set_nd_filter_state(photo_param_put_off.nd_filter, SET_NOW);
        photo_param_put_off.nd_filter=0;
    }
    else if (conf.nd_filter_state && !(conf.override_disable==1))
        shooting_set_nd_filter_state(conf.nd_filter_state, SET_NOW);
#endif

#if CAM_REAR_CURTAIN
    shooting_set_flash_sync_curtain(conf.flash_sync_curtain);
#endif

    shooting_set_flash_video_override(conf.flash_manual_override,conf.flash_video_override_power);
#if CAM_QUALITY_OVERRIDE
    // this doesn't really need to be set in the override hook.
    // should only need to be set once if the users doesn't change back, but doing it here ensures it is set
    shooting_set_image_quality(conf.fast_image_quality);
#endif
}

// Override ISO settings only
// need to do this before exposure calc for ISO, as well as after on some cameras
void shooting_expo_iso_override_thumb(void)
{
    if ((state_kbd_script_run) && (photo_param_put_off.sv96))
    {
        shooting_set_sv96(photo_param_put_off.sv96, SET_NOW);
        // photo_param_put_off.sv96 is not reset here, it will be reset in next call to shooting_expo_param_override
    }
    else if ((conf.iso_override_value>0) && (conf.iso_override_koef) && !(conf.override_disable==1))
        shooting_set_iso_real(shooting_get_iso_override_value(), SET_NOW);
    else if (conf.autoiso_enable && shooting_get_flash_mode()/*NOT FOR FLASH AUTO MODE*/ && !(conf.override_disable==1 && conf.override_disable_all))
        shooting_set_autoiso(shooting_get_iso_mode());

#if defined(CAM_HAS_ND_FILTER) && defined(CAM_HAS_NATIVE_ND_FILTER)
    if ((state_kbd_script_run) && (photo_param_put_off.nd_filter))
    {
        shooting_set_nd_filter_state(photo_param_put_off.nd_filter, SET_NOW);
        //photo_param_put_off.nd_filter=0;
    }
    else if (conf.nd_filter_state && !(conf.override_disable==1))
        shooting_set_nd_filter_state(conf.nd_filter_state, SET_NOW);
#endif
}
