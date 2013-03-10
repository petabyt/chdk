#include "platform.h"
#include "stdlib.h"
#include "keyboard.h"
#include "lang.h"
#include "conf.h"
#include "gui.h"
#include "gui_menu.h"
#include "gui_draw.h"
#include "gui_lang.h"
#include "gui_osd.h"
#include "gui_batt.h"
#include "gui_usb.h"
#include "gui_space.h"
#include "histogram.h"
#ifdef CAM_HAS_GPS
#include "gps.h"
#endif
#include "modules.h"

//-------------------------------------------------------------------

// Values for conf.show_histo
#define SHOW_ALWAYS    1
#define SHOW_HALF      2

//-------------------------------------------------------------------

extern const char* gui_video_bitrate_enum(int change, int arg);

//-------------------------------------------------------------------
static char osd_buf[64];

typedef struct {
    short av96;
    short tv96;
    short sv96;
    short iso;
    short sv96_market;
    short iso_market;
    short bv96_measured;
    short bv96_seted;       //Ev96_internal-Sv96
    short ev96_seted;       //Tv96+Av96
    short ev96_measured;    //Bv96+Sv96
    short dev96;            // Ev96_external-Ev96_internal
    short dev96_canon;      // Canon OverExposure
    int b;                  //average scene luminance 
} EXPO_TYPE;

static EXPO_TYPE expo;

//-------------------------------------------------------------------
static void print_dist(char *buf, float dist, short is_hyp) {
// length of printed string is always 4
    if (dist<=0 || (!(is_hyp) && shooting_is_infinity_distance())) {
        sprintf(buf, " inf");
    } else if (dist<1000) {
        sprintf(buf, ".%03d", (int)dist);
    } else if (dist<10000) {
        sprintf(buf, "%d.%02d", (int)(dist/1000), (int)(dist/10)%100);
    } else if (dist<100000) {
        sprintf(buf, "%02d.%d", (int)(dist/1000), (int)(dist/100)%10);
    } else {
        sprintf(buf, "%4d", (int)(dist/1000));
    }
}

// Append scaled value display of 'dist' to 'osd_buf'
static void sprintf_dist(char *buf, float dist)
{
    print_dist(buf, dist, 0);
}

// Append scaled value display of 'dist' to 'osd_buf'
static void sprintf_dist_hyp(char *buf, float dist)
{
    print_dist(buf, dist, 1);
}

static void sprintf_canon_values(char *buf, short dist) 
{
    short v=((dist<0)?-dist:dist);	
    sprintf(buf, "%s%d.%02d", ((dist<0)?"-":""), v/96, v%96);
}


//-------------------------------------------------------------------
void gui_osd_calc_dof()
{
    shooting_update_dof_values();
}

static void gui_osd_calc_expo_param()
{
    expo.av96=shooting_get_av96();
    expo.tv96=shooting_get_tv96();
    expo.sv96=shooting_get_sv96();
    expo.iso=shooting_get_iso_real();
    expo.sv96_market=shooting_get_svm96();
    expo.iso_market=shooting_get_iso_market();
    expo.bv96_measured=shooting_get_bv96();
    expo.ev96_seted=expo.tv96+expo.av96; //Tv96+Av96
    expo.ev96_measured=expo.bv96_measured+expo.sv96;//Bv96+Sv96
    expo.dev96=expo.ev96_measured-expo.ev96_seted;// Ev96_external-Ev96_internal
    expo.bv96_seted=expo.ev96_seted-expo.sv96;
    expo.dev96_canon=shooting_get_canon_overexposure_value();
    expo.b=shooting_get_luminance();
}

void gui_osd_draw_dof() 
{
    color valid_col = (conf.osd_color & 0xff00) | COLOR_HISTO_G;
    int i=8;
    short f_ex = (conf.show_dof==DOF_SHOW_IN_DOF_EX);
    draw_string(conf.dof_pos.x, conf.dof_pos.y, "S/NL/FL:", conf.osd_color);
    sprintf_dist(osd_buf, (float)dof_values.subject_distance);
    int j=strlen(osd_buf);
    draw_string(conf.dof_pos.x+i*FONT_WIDTH, conf.dof_pos.y, osd_buf,
      (f_ex && (dof_values.distance_valid || shooting_get_focus_mode()))?valid_col:conf.osd_color);
    i=i+j;
    draw_string(conf.dof_pos.x+i*FONT_WIDTH, conf.dof_pos.y, "/", conf.osd_color);
    sprintf_dist(osd_buf, (float)dof_values.near_limit);
    j=strlen(osd_buf);
    draw_string(conf.dof_pos.x+(++i)*FONT_WIDTH, conf.dof_pos.y, osd_buf,
      (f_ex && dof_values.distance_valid)?valid_col:conf.osd_color);
    i=i+j;
    draw_string(conf.dof_pos.x+i*FONT_WIDTH, conf.dof_pos.y, "/", conf.osd_color);
    sprintf_dist(osd_buf, (float)dof_values.far_limit);
    draw_string(conf.dof_pos.x+(++i)*FONT_WIDTH, conf.dof_pos.y, osd_buf,
      (f_ex && dof_values.distance_valid)?valid_col:conf.osd_color);
    i=8;
      draw_string(conf.dof_pos.x, conf.dof_pos.y+FONT_HEIGHT, "DOF/HYP:", conf.osd_color);
    sprintf_dist(osd_buf, (float)dof_values.depth_of_field);
    j=strlen(osd_buf);
    draw_string(conf.dof_pos.x+i*FONT_WIDTH, conf.dof_pos.y+FONT_HEIGHT, osd_buf,
      (f_ex && dof_values.distance_valid)?valid_col:conf.osd_color);
    i=i+j;
    draw_string(conf.dof_pos.x+i*FONT_WIDTH, conf.dof_pos.y+FONT_HEIGHT, "/", conf.osd_color);
    sprintf_dist_hyp(osd_buf, (float)dof_values.hyperfocal_distance);
    draw_string(conf.dof_pos.x+(++i)*FONT_WIDTH, conf.dof_pos.y+FONT_HEIGHT, osd_buf,
      (f_ex && dof_values.hyperfocal_valid)?valid_col:conf.osd_color);
}

//-------------------------------------------------------------------
static short n, m; //string number

static void gui_print_osd_state_string()
{
    sprintf(osd_buf+strlen(osd_buf), "%12s", "");
    osd_buf[12]=0;  // limit length to 12 max
    draw_string(conf.mode_state_pos.x, conf.mode_state_pos.y+n, osd_buf, conf.osd_color_override);
    n+=FONT_HEIGHT;
}

static void gui_print_osd_state_string_int(const char * title, int value)
{
    sprintf(osd_buf, "%s%d", title, value);
    gui_print_osd_state_string();
}

static void gui_print_osd_state_string_chr(const char *title, const char *value)
{
    sprintf(osd_buf, "%s%s", title, value);
    gui_print_osd_state_string();
}

static void gui_print_osd_state_string_float(const char * fmt, int divisor, int value)
{
    sprintf(osd_buf, fmt, (int)(value/divisor), (int)(value%divisor));
    gui_print_osd_state_string();
}

static void gui_print_osd_misc_string()
{
    sprintf(osd_buf+strlen(osd_buf), "%9s", "");
    osd_buf[9]=0;  // limit length to 9 max
    draw_string(conf.values_pos.x, conf.values_pos.y+m, osd_buf, conf.osd_color);
    m+=FONT_HEIGHT;
}

static void gui_print_osd_misc_string_int(const char * title, int value)
{
    sprintf(osd_buf, "%s%d", title, value);
    gui_print_osd_misc_string();
}

static void gui_print_osd_misc_string_float(const char * fmt, int divisor, int value)
{
    sprintf(osd_buf, fmt, (int)(value/divisor), (int)(value%divisor));
    gui_print_osd_misc_string();
}

static void gui_print_osd_misc_string_canon_values(const char * title, short value)
{
    strcpy(osd_buf, title);
    sprintf_canon_values(osd_buf+strlen(osd_buf), value);
    gui_print_osd_misc_string();
}
    
static void gui_print_osd_dof_string_dist(const char * title, int value, short use_good_color, short is_hyp) {
  strcpy(osd_buf, title);
  int i=strlen(osd_buf);
  if (i<8) {
    draw_string(conf.values_pos.x, conf.values_pos.y+m, osd_buf, conf.osd_color);
    if (is_hyp) {
        sprintf_dist_hyp(osd_buf, (float)value);
    } else {
        sprintf_dist(osd_buf, (float)value);
    }
    sprintf(osd_buf+strlen(osd_buf), "%9s", "");
    osd_buf[9-i]=0;
    draw_string(conf.values_pos.x+i*FONT_WIDTH, conf.values_pos.y+m, osd_buf, use_good_color?((conf.osd_color & 0xff00) | COLOR_HISTO_G):conf.osd_color);
  } else {
    osd_buf[9]=0;
    draw_string(conf.values_pos.x, conf.values_pos.y+m, osd_buf, conf.osd_color);
  }
  m+=FONT_HEIGHT;
}

//-------------------------------------------------------------------
void gui_osd_draw_raw_info() 
{
    static int b;
    if (is_raw_enabled())
    { 
        if (conf.show_remaining_raw) 
        {
            int raw_count = GetRawCount();  
            sprintf(osd_buf, "%s:%3d", (conf.dng_raw)?"DNG":"RAW", raw_count);
            draw_string(conf.mode_raw_pos.x, conf.mode_raw_pos.y, osd_buf, ((raw_count > conf.remaining_raw_treshold) || (b <= 6)) ? conf.osd_color : conf.osd_color_warn);
            if (++b > 12) b = 0;
        }
        else
            draw_string(conf.mode_raw_pos.x, conf.mode_raw_pos.y, (conf.dng_raw)?"DNG":"RAW", conf.osd_color); 
    }   
    else if (conf.raw_exceptions_warn)
    {
        gui_print_osd_state_string_chr((conf.dng_raw)?"DNG Disabled":"RAW Disabled",""); 
    }
}

//-------------------------------------------------------------------

static const char * shooting_get_bracket_type()
{
    static const char * expo_type[] = { "+/-", "-","+"};
    return expo_type[conf.bracket_type];
}

static const char * expo_shift[] = { "Off", "1/3Ev","2/3Ev", "1Ev", "1 1/3Ev", "1 2/3Ev", "2Ev", "2 1/3Ev", "2 2/3Ev", "3Ev", "3 1/3Ev", "3 2/3Ev", "4Ev"};

static const char * shooting_get_tv_bracket_value()
{
    return expo_shift[conf.tv_bracket_value];
}

static const char * shooting_get_av_bracket_value()
{
    return expo_shift[conf.av_bracket_value];
}

void gui_osd_draw_state()
{
    int gui_mode=gui_get_mode();
    long t; 

    n=0;
    ///////////////////////////
    //sprintf(osd_buf,"%s",get_debug());
    //draw_string(conf.mode_state_pos.x, conf.mode_state_pos.y+6*FONT_HEIGHT, osd_buf, conf.osd_color);
    ////////////////////////////  

    if (is_tv_override_enabled || gui_mode==GUI_MODE_OSD)
    {
        if(camera_info.state.is_shutter_half_press) 
        { 
            t=(int)(shooting_get_shutter_speed_from_tv96(shooting_get_tv96())*100000);	
            gui_print_osd_state_string_float("TV:%d.%05d", 100000, t);
        }
        else 
        {
            if (conf.tv_enum_type==TV_OVERRIDE_EV_STEP)
                gui_print_osd_state_string_chr("TV:",gui_tv_override_value_enum(0,0)); 
            else if (conf.tv_enum_type==TV_OVERRIDE_SHORT_EXP)
                gui_print_osd_state_string_float("TV:%d.%05d", 100000, conf.tv_override_short_exp);
            else
                gui_print_osd_state_string_chr("TV:",gui_hhmss_enum(0,(int)(&conf.tv_override_long_exp))); 
        }
    }
    if (is_av_override_enabled || gui_mode==GUI_MODE_OSD)  
        gui_print_osd_state_string_float("AV:%d.%02d", 100, shooting_get_aperture_from_av96(shooting_get_av96_override_value()));
    if (camera_info.cam_has_nd_filter)
        if ((conf.nd_filter_state && !(conf.override_disable==1))|| gui_mode==GUI_MODE_OSD) 
            gui_print_osd_state_string_chr("NDFILTER:", ((conf.nd_filter_state==1)?"IN":"OUT"));
    if ((conf.autoiso_enable && shooting_get_iso_mode()<=0 && !(m==MODE_M || m==MODE_TV) && shooting_get_flash_mode() && (autoiso_and_bracketing_overrides_are_enabled)) || gui_mode==GUI_MODE_OSD)  
        gui_print_osd_state_string_chr("AUTOISO:", ((conf.autoiso_enable==1)?"ON":"OFF"));
    if ((is_sd_override_enabled && shooting_can_focus()) || ((gui_get_mode()==GUI_MODE_ALT) && shooting_get_common_focus_mode()) || gui_mode==GUI_MODE_OSD)
    {
        gui_print_osd_state_string_chr("SD:",gui_subj_dist_override_value_enum(0,0));
        if (gui_mode==GUI_MODE_ALT)
        {
            if (conf.subj_dist_override_koef == SD_OVERRIDE_ON)
            {
                gui_print_osd_state_string_chr("Adj:",menu_increment_factor_string());
            }
            else
                gui_print_osd_state_string_chr("Adj:",gui_subj_dist_override_koef_enum(0,0));
        }
    }
    if (is_iso_override_enabled || gui_mode==GUI_MODE_OSD)
        gui_print_osd_state_string_int("ISO:", shooting_get_iso_override_value());
    if ((gui_mode==GUI_MODE_OSD) || (shooting_get_drive_mode() && m!=MODE_STITCH && m!=MODE_SCN_BEST_IMAGE))
    {
      if (is_tv_bracketing_enabled || is_av_bracketing_enabled || is_iso_bracketing_enabled || is_sd_bracketing_enabled)
        gui_print_osd_state_string_chr("BRACKET:", shooting_get_bracket_type());
      if (is_tv_bracketing_enabled)
        gui_print_osd_state_string_chr("TV:", shooting_get_tv_bracket_value());
      else if (is_av_bracketing_enabled)
        gui_print_osd_state_string_chr("AV:", shooting_get_av_bracket_value());
      else if (is_iso_bracketing_enabled)
        gui_print_osd_state_string_int("ISO:", conf.iso_bracket_value);
      else if (is_sd_bracketing_enabled)
        gui_print_osd_state_string_int("SD:", conf.subj_dist_bracket_value);
    }
#ifdef OPT_CURVES
    if (conf.curve_enable || gui_mode==GUI_MODE_OSD) {
        if (conf.curve_enable==1) gui_print_osd_state_string_chr("CURVES:", "CSTM");
        else if (conf.curve_enable==4) gui_print_osd_state_string_chr("CURVES:", "AUTO");
        else if (conf.curve_enable==3) gui_print_osd_state_string_chr("CURVES:", "+2EV");
        else if (conf.curve_enable==2) gui_print_osd_state_string_chr("CURVES:", "+1EV");
    }
#endif
    if (conf.override_disable == 1) gui_print_osd_state_string_chr("NO ", "OVERRIDES");
    if (conf.flash_manual_override) gui_print_osd_state_string_chr("Flash:", "Manual Override");
#ifdef OPT_EDGEOVERLAY
    // edgeoverlay state
    if (conf.edge_overlay_enable || gui_mode==GUI_MODE_OSD) {
        if (camera_info.state.edge_state_draw==0) gui_print_osd_state_string_chr("EDGE:", "LIVE");
        else if (camera_info.state.edge_state_draw==1) gui_print_osd_state_string_chr("EDGE:", ((conf.edge_overlay_pano==0)?"FROZEN":"PANO"));
    }
#endif
#ifdef CAM_QUALITY_OVERRIDE
    // displaying the overriding picture quality if active
    if (!(conf.fast_image_quality==3) || gui_mode==GUI_MODE_OSD) {
        if (conf.fast_image_quality==0) gui_print_osd_state_string_chr("QUALI:", "super");
        else if (conf.fast_image_quality==1) gui_print_osd_state_string_chr("QUALI:", "fine");
        else if (conf.fast_image_quality==2) gui_print_osd_state_string_chr("QUALI:", "normal");
    }
#endif

/*
 draw_string(conf.mode_state_pos.x, conf.mode_state_pos.y+n, get_debug(), conf.osd_color);
        n+=FONT_HEIGHT;*/
}

//-------------------------------------------------------------------
void gui_osd_draw_values(int showtype)
{
    int iso_mode=shooting_get_iso_mode();

    m=0;

    //gui_osd_calc_expo_param();

    if (conf.values_show_zoom)
    {
        int fl, zp=shooting_get_zoom(), fl1=get_focal_length(zp);     
        switch (conf.zoom_value)
        {
         case ZOOM_SHOW_FL:
             sprintf(osd_buf, "Z:%d.%dmm%8s", fl1/1000, fl1%1000/100, "");
             break;
         case ZOOM_SHOW_EFL:
             fl=get_effective_focal_length(zp);
             // scale by users adapter lens eg. Canon Wide .42 or Canon Tele 1.75
             fl = fl * conf.zoom_scale / 100;
             sprintf(osd_buf, "Z:%3dmm%8s", fl/1000, "");
             break;
         case ZOOM_SHOW_X:
         default:
             fl=get_zoom_x(zp);
             sprintf(osd_buf, "Z:%d/%d.%dx%8s", zp, fl/10, fl%10, "");
             break;
        }
        gui_print_osd_misc_string();
    }

    if ((conf.values_show_real_aperture) && (showtype==1))
         gui_print_osd_misc_string_float("Av :%d.%02d ", 100, shooting_get_real_aperture());
    short f_ex = (conf.show_dof==DOF_SHOW_IN_MISC_EX);
    if (((conf.show_dof==DOF_SHOW_IN_MISC) && (showtype)) || f_ex) {
      if (f_ex) gui_osd_calc_dof();
      if (conf.dof_subj_dist_in_misc) gui_print_osd_dof_string_dist("SD :", dof_values.subject_distance,
         f_ex && (dof_values.distance_valid || shooting_get_focus_mode()), 0);
      if (conf.dof_near_limit_in_misc) gui_print_osd_dof_string_dist("NL :", dof_values.near_limit,
         f_ex && dof_values.distance_valid, 0);
      if (conf.dof_far_limit_in_misc) gui_print_osd_dof_string_dist("FL :", dof_values.far_limit,
         f_ex && dof_values.distance_valid, 0);
      if (conf.dof_depth_in_misc) gui_print_osd_dof_string_dist("DOF:", dof_values.depth_of_field,
         f_ex && dof_values.distance_valid, 0);
      if (conf.dof_hyperfocal_in_misc) gui_print_osd_dof_string_dist("HYP:", dof_values.hyperfocal_distance,
         f_ex && dof_values.hyperfocal_valid, 1);
    }
    if (showtype==1)
    {
        if ((iso_mode <= 0) || !(conf.values_show_iso_only_in_autoiso_mode))
        {
            if (conf.values_show_real_iso) gui_print_osd_misc_string_int("I-R:", expo.iso);
            if (conf.values_show_market_iso) gui_print_osd_misc_string_int("I-M:", expo.iso_market);
        }
        if (conf.values_show_bv_measured) gui_print_osd_misc_string_canon_values("Bvm:", expo.bv96_measured	);
        if (conf.values_show_bv_seted) gui_print_osd_misc_string_canon_values("Bvs:", expo.bv96_seted	);
        if (conf.values_show_ev_measured) gui_print_osd_misc_string_canon_values("Evm:", expo.ev96_measured);
        if (conf.values_show_ev_seted	) gui_print_osd_misc_string_canon_values("Evs:", expo.ev96_seted	);
        if (conf.values_show_overexposure) gui_print_osd_misc_string_canon_values("dE :", expo.dev96);
        if (conf.values_show_canon_overexposure	) gui_print_osd_misc_string_canon_values("dEc:", expo.dev96_canon);
        if (conf.values_show_luminance) gui_print_osd_misc_string_float("B  :%d.%02d", 100, expo.b);
    }
}

//-------------------------------------------------------------------
#define CLOCK_FORMAT_24 0
#define CLOCK_FORMAT_12 1
#define CLOCK_WITHOUT_SEC 1
#define CLOCK_WITH_SEC 2

void gui_osd_draw_clock(int x, int y, color cl)
{
    static char *ampm[2][3] = { { " AM", "A", " "}, { " PM", "P", "." } };
    struct tm *ttm;
    int w;
    char *ampm_ind;

    ttm = get_localtime();
    unsigned int hour=(ttm->tm_hour);

    ampm_ind = "";  // AM / PM indicator
    w = 0;          // Extra with from AM/PM indicator and seconds (if displayed)

    if (conf.clock_format == CLOCK_FORMAT_12)
    {
        ampm_ind = ampm[hour/12][conf.clock_indicator]; //(hour >= 12) ? pm : am; 
        w = strlen(ampm_ind);
        if (hour == 0)
            hour = 12;
        else if (hour > 12)
            hour =hour - 12;
    }

    switch(conf.show_clock)
    {
    case CLOCK_WITHOUT_SEC:
        sprintf(osd_buf, "%2u:%02u%s", hour, ttm->tm_min, ampm_ind);
        break;  
    case CLOCK_WITH_SEC:
    default:
        sprintf(osd_buf, "%2u:%02u:%02u%s", hour, ttm->tm_min, ttm->tm_sec, ampm_ind);
        w += 3;
        break;  
    }

    draw_string(((x)?x:conf.clock_pos.x)-w*FONT_WIDTH, (y)?y:conf.clock_pos.y, osd_buf, (cl)?cl:conf.osd_color);
}

static void gui_osd_draw_seconds()
{
    static struct tm *ttm;

    ttm = get_localtime();
    sprintf(osd_buf, "%02u", ttm->tm_sec);
    if (conf.clock_pos.x<4*FONT_WIDTH)
    {
        draw_string(conf.clock_pos.x, conf.clock_pos.y, osd_buf, conf.osd_color);
    }
    else
    {
        draw_string(conf.clock_pos.x+(3*FONT_WIDTH), conf.clock_pos.y, osd_buf, conf.osd_color);
    }
}

static unsigned int movie_reset;

static void gui_osd_draw_movie_time_left()
{
    static int card_used, init_space, elapsed, avg_use, time_left;
    static long init_time;
    static int record_running = 0;
    static int init = 0;
    static unsigned int skipcalls = 1;
    unsigned int hour=0, min=0, sec=0;
    int mode = mode_get();
    int mode_video = MODE_IS_VIDEO(mode); 

    if ((mode & MODE_MASK) == MODE_PLAY) return;

#if CAM_CHDK_HAS_EXT_VIDEO_MENU
    if (mode_video || is_video_recording())
    {
        // if manual adjust, show the field item to be adjusted
        // if any value overriden, show the override value
#if !CAM_VIDEO_QUALITY_ONLY
        if ((conf.video_mode == 0 && conf.fast_movie_quality_control==1) || conf.video_bitrate != VIDEO_DEFAULT_BITRATE)
        {
            // gui_print_osd_state_string_chr("Bitrate: ",video_bitrate_strings[conf.video_bitrate]);
            sprintf(osd_buf, "Bit:%5s",gui_video_bitrate_enum(0,0));
            draw_string( conf.mode_video_pos.x, conf.mode_video_pos.y+2*FONT_HEIGHT, osd_buf, conf.osd_color);
        }
#endif
        if ((conf.video_mode == 1 && conf.fast_movie_quality_control==1) || conf.video_quality != VIDEO_DEFAULT_QUALITY)
        {
            // gui_print_osd_state_string_int("Quality: ",conf.video_quality);
            sprintf(osd_buf, "Qual:%2i",conf.video_quality);
            draw_string( conf.mode_video_pos.x, conf.mode_video_pos.y+3*FONT_HEIGHT, osd_buf, conf.osd_color);
        }
        // everything else is for when recording
        if (mode_video)
            return;
    }
#endif

    if (movie_reset == 1)
    {
        init = 0;
        movie_reset = 0;
    }

    if (is_video_recording())
        record_running = 1;
    else
    {
        record_running = 0;
        init = 0;
    }

    if (record_running == 1 && init == 0)
    {
        init = 1;
        init_space = GetFreeCardSpaceKb();
        init_time  = get_tick_count();
    }

    if (init == 1)
    {
        card_used = init_space - GetFreeCardSpaceKb();
        elapsed = (int) ( get_tick_count() - init_time ) / 1000;
        avg_use = card_used / elapsed;  // running average Kb/sec
        time_left = (GetFreeCardSpaceKb() / avg_use);
        hour = time_left / 3600;
        min = (time_left % 3600) / 60;
        sec = (time_left % 3600) % 60;

        if (elapsed < 1)
        {
            sprintf(osd_buf, "Calc...");
            draw_string( conf.mode_video_pos.x, conf.mode_video_pos.y, osd_buf, conf.osd_color);
        }

        if (--skipcalls ==0)
        {
            if (elapsed > 1)
            {
                int time_yofst = 0;
                if (conf.show_movie_time == 3)
                {
                    // Both lines displayed so offset time value below bit rate
                    time_yofst = FONT_HEIGHT;
                }
                if (conf.show_movie_time & 2)
                {
                    sprintf(osd_buf, "%04d KB/s", avg_use);
                    draw_string( conf.mode_video_pos.x, conf.mode_video_pos.y, osd_buf, conf.osd_color);
                }
                if (conf.show_movie_time & 1)
                {
                    sprintf(osd_buf, "-%02d:%02d:%02d", hour, min, sec);
                    draw_string( conf.mode_video_pos.x, conf.mode_video_pos.y+time_yofst, osd_buf, conf.osd_color);
                }
#if CAM_CHDK_HAS_EXT_VIDEO_TIME
                if( (int)conf.ext_video_time == 1 )
                {
                    draw_txt_string(0, 13, lang_str(LANG_WARN_VIDEO_EXT_TIME), conf.osd_color_warn);
                }		
#endif
            }

            skipcalls = conf.show_movie_refresh*5;
        }
    }
}

static void gui_osd_draw_ev()
{
    static char *s[6]={"   ", "1/6", "1/3", "1/2", "2/3", "5/6"};
    short ev=shooting_get_ev_correction1();
    if (ev/96 || (ev==0)) sprintf(osd_buf, "EV:  %d %s", abs(ev/96), s[abs(ev/16%6)]);
    else sprintf(osd_buf, "EV:  %s   ", s[abs(ev/16%6)]);
    if (ev>0) osd_buf[4]='+'; else if (ev<0) osd_buf[4]='-';
    draw_string(conf.mode_ev_pos.x, conf.mode_ev_pos.y, osd_buf, conf.osd_color);
}

//-------------------------------------------------------------------
static void draw_temp(char *lbl, int val, int yofst)
{
    if (conf.temperature_unit != 0)
        val = (val*18+320)/10;
    sprintf(osd_buf,"%s: %i°",lbl, val);
    draw_string(conf.temp_pos.x, conf.temp_pos.y+yofst*FONT_HEIGHT, osd_buf, conf.osd_color);
}

void gui_osd_draw_temp() {
    switch (conf.show_temp)
    {
    case 2:
#ifdef CAM_HAS_CMOS
        draw_temp("CMOS", get_ccd_temp(), 0);
#else
        draw_temp("CCD", get_ccd_temp(), 0);
#endif
        break;
    case 3:
        draw_temp("bat", get_battery_temp(), 0);
        break;
    case 4:
        draw_temp("bat", get_battery_temp(), 2);
#ifdef CAM_HAS_CMOS
        draw_temp("CMOS", get_ccd_temp(), 1);
#else
        draw_temp("CCD", get_ccd_temp(), 1);
#endif
    case 1:
        draw_temp("opt", get_optical_temp(), 0);
        break;
    }
}

//-------------------------------------------------------------------
void gui_osd_draw_ev_video(int visible)
{
#if CAM_EV_IN_VIDEO
    int x0=conf.ev_video_pos.x, y0=conf.ev_video_pos.y;
    int i, deltax;

    draw_filled_rect(x0,y0,x0+70,y0+24, visible? MAKE_COLOR(BG_COLOR(conf.osd_color),BG_COLOR(conf.osd_color)): COLOR_TRANSPARENT);

    if (!visible) { return; }

    for (i=0;i<9;i++) draw_line(x0+2+i*8,   y0+12, x0+2+i*8,   y0+12-(i&1 ? 5 : 10), conf.osd_color);
    for (i=0;i<9;i++) draw_line(x0+2+i*8+1, y0+12, x0+2+i*8+1, y0+12-(i&1 ? 5 : 10), conf.osd_color);

    deltax=8*get_ev_video();

    x0+=deltax;

    draw_line(x0+34,y0+16,x0+34,y0+22,conf.osd_color);
    draw_line(x0+35,y0+16,x0+35,y0+22,conf.osd_color);

    draw_line(x0+32,y0+19,x0+32,y0+22,conf.osd_color);
    draw_line(x0+33,y0+18,x0+33,y0+22,conf.osd_color);
    draw_line(x0+36,y0+18,x0+36,y0+22,conf.osd_color);
    draw_line(x0+37,y0+19,x0+37,y0+22,conf.osd_color);
#endif
}

//------------------------------------------------------------------- 
// Process up/down/left/right/jogdial shortcuts when control options enabled
static int kbd_use_up_down_left_right_as_fast_switch()
{
    static long key_pressed = 0;
    int m = mode_get(); 
    int mode_video = (MODE_IS_VIDEO(m) || is_video_recording());
    int ev_video = 0;
    int jogdial;

#if CAM_EV_IN_VIDEO
    ev_video = get_ev_video_avail(); 
#endif

    // One of the control options must be enabled or don't do anything
    if (!conf.fast_ev && !conf.fast_movie_control && !conf.fast_movie_quality_control) return 0;

    // Clear state variable is neither UP or DOWN is pressed
    if (!kbd_is_key_pressed(KEY_UP) && !kbd_is_key_pressed(KEY_DOWN)) key_pressed = 0;

    // Must be in record mode and not have Canon menu open
    if (canon_shoot_menu_active!=0 || (m&MODE_MASK) != MODE_REC) return 0;

    // Adjust exposure if 'Enable Fast EV switch?' option is set
    if (conf.fast_ev && (key_pressed == 0) && ((m&MODE_SHOOTING_MASK) != MODE_M))
    {
#if !CAM_HAS_JOGDIAL
        if (kbd_is_key_pressed(KEY_UP))
        {
            shooting_set_prop(PROPCASE_EV_CORRECTION_1,shooting_get_ev_correction1()+(conf.fast_ev_step+1)*16);
            shooting_set_prop(PROPCASE_EV_CORRECTION_2,shooting_get_ev_correction2()+(conf.fast_ev_step+1)*16);
            EnterToCompensationEVF();
            key_pressed = KEY_UP;
                    
            return 1;
        } 

        if (kbd_is_key_pressed(KEY_DOWN))
        {
            shooting_set_prop(PROPCASE_EV_CORRECTION_1,shooting_get_ev_correction1()-(conf.fast_ev_step+1)*16);
            shooting_set_prop(PROPCASE_EV_CORRECTION_2,shooting_get_ev_correction2()-(conf.fast_ev_step+1)*16);
            EnterToCompensationEVF();
            key_pressed = KEY_DOWN;

            return 1;
        }
#else
        jogdial=get_jogdial_direction();

        if (camera_info.state.is_shutter_half_press && (jogdial==JOGDIAL_RIGHT))
        {
            shooting_set_prop(PROPCASE_EV_CORRECTION_1,shooting_get_ev_correction1()+(conf.fast_ev_step+1)*16);
            shooting_set_prop(PROPCASE_EV_CORRECTION_2,shooting_get_ev_correction2()+(conf.fast_ev_step+1)*16);
            EnterToCompensationEVF();
        }

        if (camera_info.state.is_shutter_half_press && (jogdial==JOGDIAL_LEFT))
        {
            shooting_set_prop(PROPCASE_EV_CORRECTION_1,shooting_get_ev_correction1()-(conf.fast_ev_step+1)*16);
            shooting_set_prop(PROPCASE_EV_CORRECTION_2,shooting_get_ev_correction2()-(conf.fast_ev_step+1)*16);
            EnterToCompensationEVF();
        }
#endif
    } 

    // Adjust video quality/bitrate if 'Video Quality Control?' option is set
    if (conf.fast_movie_quality_control && key_pressed == 0 && mode_video && is_video_recording())
    {
        if (kbd_is_key_pressed(KEY_UP))
        {
            if (conf.video_mode==0)
            {
#if !CAM_VIDEO_QUALITY_ONLY
                gui_video_bitrate_enum(1,0);
                movie_reset = 1;
#endif
            }    
            else if (conf.video_mode==1)
            {
                conf.video_quality+=1;
                if (conf.video_quality>VIDEO_MAX_QUALITY)
                    conf.video_quality=VIDEO_MAX_QUALITY;
                movie_reset = 1;
            }              
            key_pressed = KEY_UP;
            return 1;
        }
    
        if (kbd_is_key_pressed(KEY_DOWN))
        {
            if (conf.video_mode==0)
            {
#if !CAM_VIDEO_QUALITY_ONLY
                conf.video_bitrate-=1;
                if (conf.video_bitrate<0)
                    conf.video_bitrate=0;

                shooting_video_bitrate_change(conf.video_bitrate);
                movie_reset = 1;
#endif
            }
            else if (conf.video_mode==1)
            {
                conf.video_quality-=1;
                if (conf.video_quality<1)
                    conf.video_quality=1;
                movie_reset = 1;
            }          
            key_pressed = KEY_DOWN;
            return 1;
        }
    } 
    
#if CAM_VIDEO_CONTROL
    // Pause / unpause video if 'Fast Movie Control' option is set
    if (conf.fast_movie_control && key_pressed == 0 && !ev_video
#ifndef CAM_HAS_VIDEO_BUTTON 
        && mode_video
#endif
        )
    {
        if (kbd_is_key_pressed(KEY_LEFT) && is_video_recording())
        {
            movie_status = VIDEO_RECORD_STOPPED;
            key_pressed = KEY_LEFT;
            return 1;
        }

    	// reyalp - HACK for cams that can do video in any mode
	    // note that this means this will probably run whenever you press right
        // BUG this doesn't know whether recording was stopped or paused.
        if (kbd_is_key_pressed(KEY_RIGHT) && (movie_status == VIDEO_RECORD_STOPPED))
        {
            movie_status = VIDEO_RECORD_IN_PROGRESS;
            movie_reset = 1;
            key_pressed = KEY_RIGHT;
            return 1;
        }
    } 
#endif

    return key_pressed;
}

//------------------------------------------------------------------- 
// Process Shutter Half Press + BUTTON shortcuts
static int half_disp_press = 0;

static void kbd_shortcut(int button, int *var, int max_value)
{
    if (kbd_is_key_clicked(button))
    {
        (*var)++;
        if (*var > max_value)
        {
            *var = 0;
            gui_set_need_restore();
        }
    }
}

void gui_kbd_shortcuts()
{
    unsigned int m, mode_photo, mode_video;
    static int half_disp_press_old=0;
    
    if (camera_info.state.is_shutter_half_press)
    {
        kbd_shortcut(SHORTCUT_TOGGLE_ZEBRA, &conf.zebra_draw, 1);
        kbd_shortcut(SHORTCUT_TOGGLE_HISTO, &conf.show_histo, SHOW_HALF);
        kbd_shortcut(SHORTCUT_TOGGLE_OSD, &conf.show_osd, 1);
        kbd_shortcut(SHORTCUT_DISABLE_OVERRIDES, &conf.override_disable, 1);
#if !CAM_HAS_MANUAL_FOCUS && CAM_HAS_ZOOM_LEVER && CAM_CAN_SD_OVERRIDE
        // Todo, check for AF and if its running, don't override
        if (kbd_is_key_pressed(SHORTCUT_SD_SUB)) {
            if (!(conf.override_disable==1) && shooting_can_focus() && shooting_get_common_focus_mode()) {
                gui_subj_dist_override_value_enum(-1,0);
                shooting_set_focus(shooting_get_subject_distance_override_value(),SET_NOW);
            }
        } else if (kbd_is_key_pressed(SHORTCUT_SD_ADD)) {
            if (!(conf.override_disable==1) && shooting_can_focus() && shooting_get_common_focus_mode()) {
                gui_subj_dist_override_value_enum(1,0);
                shooting_set_focus(shooting_get_subject_distance_override_value(),SET_NOW);
            }
        }
#endif
    }

    m = mode_get();

    mode_video = MODE_IS_VIDEO(m);
    mode_photo = (m&MODE_MASK) == MODE_PLAY || !(mode_video || (m&MODE_SHOOTING_MASK)==MODE_STITCH);

    half_disp_press = mode_photo && camera_info.state.is_shutter_half_press && kbd_is_key_pressed(KEY_DISPLAY);
    if (half_disp_press && !half_disp_press_old)
        gui_set_need_restore();
#ifdef CAM_DISP_ALT_TEXT
    if (half_disp_press)
    {
        extern void gui_reset_alt_helper();
        gui_reset_alt_helper();
    }
#endif
    half_disp_press_old = half_disp_press;
}

//------------------------------------------------------------------- 
// Handler for button presses in normal camera shooting or playback modes
static int gui_std_kbd_process()
{
#ifdef CAM_USE_ZOOM_FOR_MF
    if (conf.use_zoom_mf && kbd_use_zoom_as_mf())
        return 1;
#endif 

    if (kbd_use_up_down_left_right_as_fast_switch())
        return 1;

    // Process Shutter Half Press + BUTTON shortcuts
    gui_kbd_shortcuts();

    // process other keys in not <alt> mode

#if CAM_AF_SCAN_DURING_VIDEO_RECORD 
    if (is_video_recording())
        if (kbd_is_key_clicked(conf.video_af_key)) MakeAFScan(); 
#endif 

#if CAM_CAN_UNLOCK_OPTICAL_ZOOM_IN_VIDEO
    // return from digital to optical zoom in video
#if CAM_HAS_ZOOM_LEVER
    if (conf.unlock_optical_zoom_for_video && is_video_recording() &&  kbd_is_key_clicked(KEY_ZOOM_OUT))
#else
    if (conf.unlock_optical_zoom_for_video && is_video_recording() &&  kbd_is_key_clicked(KEY_DOWN))
#endif
    {
        short x;
        get_property_case(PROPCASE_DIGITAL_ZOOM_STATE, &x, sizeof(x));
        if (x)
        {
            get_property_case(PROPCASE_DIGITAL_ZOOM_POSITION, &x, sizeof(x));
#if defined(CAM_USE_OPTICAL_MAX_ZOOM_STATUS)
	        if (x==0) zoom_status=ZOOM_OPTICAL_MAX; //ERR99: No zoom back from digital to optical zoom possible if set to medium
#else
	        if (x==0) zoom_status=ZOOM_OPTICAL_MEDIUM;
#endif
        }
    }
#endif

#if CAM_EV_IN_VIDEO
    if (is_video_recording() && !camera_info.state.is_shutter_half_press)
    {
#if CAM_HAS_ERASE_BUTTON
        if (kbd_is_key_clicked(KEY_ERASE))
#elif CAM_HAS_DISP_BUTTON
        if (kbd_is_key_clicked(KEY_DISPLAY))
#else
        if (kbd_is_key_clicked(KEY_MENU))
#endif
        {
            set_ev_video_avail(!get_ev_video_avail());
#ifdef CAM_TOUCHSCREEN_UI
            redraw_buttons = 1;
#endif
        }
        if (get_ev_video_avail())
        {
            if (kbd_is_key_clicked(KEY_LEFT))
            {
                set_ev_video(get_ev_video()-1);
            }
            if (kbd_is_key_clicked(KEY_RIGHT))
            {
                set_ev_video(get_ev_video()+1);
            }
        }
    }
#endif

    return 0;
}

//-------------------------------------------------------------------
// int osd_visible( uint playmode )         // playmode = m&MODE_MASK from gui_draw_osd()
//                                          // hide_osd =  0=Don't, 1=In Playback, 2=On Disp Press, 3=Both
//-------------------------------------------------------------------
int osd_visible(unsigned int playmode)
{
    if ( conf.hide_osd == 0 ) return(1) ;

    if( !camera_info.state.is_shutter_half_press)
    {
        if (playmode == MODE_REC)
        {
            if ( conf.hide_osd < 2 ) return( 1 ) ;

#if defined(PARAM_DISPLAY_MODE1) && defined(PARAM_DISPLAY_MODE2)

			short disp_key_mode ;
			if (recreview_hold==0)
			{	
				if ( shooting_get_display_mode() == 0) return( 1 );			
			}
			else
			{
				if (conf.show_osd_in_review )
				{
					get_parameter_data(PARAM_DISPLAY_MODE2, &disp_key_mode, 2);		
					if (disp_key_mode == 0 ) return( 1 ) ;
				}
			}
		}
		else
		{
			if (conf.hide_osd == 2 ) 
			{	
				short disp_key_mode ;

                get_parameter_data(PARAM_DISPLAY_MODE1, &disp_key_mode, 2);
                if (disp_key_mode == 1 ) return( 1 ) ;
            }
        }
    }
#else
			if ( shooting_get_display_mode() == 0) return 1;
		}
	}
#endif		

    return 0;

}

//-------------------------------------------------------------------

#ifdef OPT_DEBUGGING

extern int debug_display_direction;

#ifndef CAM_DRYOS
extern int debug_tasklist_start;
#endif

#define TASKLIST_MAX_LINES 12 // probably as much as will fit on screen
#define TASKLIST_NUM_TASKS 64 // should be enough ?

#ifndef CAM_DRYOS
static void gui_debug_draw_tasklist(void)
{
    int tasklist[TASKLIST_NUM_TASKS]; // max number of tasks we will look at
    int n_tasks,n_show_tasks,show_start;
    const char *name;
    int i;
    n_tasks = task_id_list_get(tasklist,sizeof(tasklist)/sizeof(tasklist[0]));
    show_start = debug_tasklist_start;
    n_show_tasks = n_tasks - show_start;
    // auto adjust to show the last N tasks
    if(n_show_tasks < TASKLIST_MAX_LINES) {
        show_start = n_tasks - TASKLIST_MAX_LINES;
        if(show_start<0)
            show_start = 0;
        n_show_tasks = n_tasks - show_start;
    }
    else if( n_show_tasks > TASKLIST_MAX_LINES ) {
        n_show_tasks = TASKLIST_MAX_LINES;
    }
    sprintf(osd_buf,"%d-%d of %d tasks %c",show_start,show_start+n_show_tasks,n_tasks,debug_display_direction > 0?'+':'-');
    draw_string(64,0,osd_buf, conf.osd_color);
    for( i = 0;  i < n_show_tasks; i++ ) {
        // TODO get full task info
        name = task_name(tasklist[show_start+i]);
        if ( !name || !*name ) {
            name = "(unknown)";
        }
        sprintf(osd_buf,"%10s %8X",name,tasklist[show_start+i]);
        draw_string(64,16+16*i,osd_buf, conf.osd_color);
    }
}
#endif //CAM_DRYOS

#endif

//------------------------------------------------------------------- 
void gui_draw_debug_vals_osd()
{
#ifdef OPT_DEBUGGING

#if defined(OPT_EXMEM_TESTING)
    // Only do memory corruption testing if not recording video
    if (!MODE_IS_VIDEO(mode_get()))
    {
        // If defined the exmem memory is allocated; but not used for CHDK.
        // It is filled with a guard value (see wrappers.c) which is checked here
        // Any corruption is reported, otherwise 'OK' is displayed on screen (along with the exmem memory start address).
        extern void *exmem_start, *exmem_end;
        // check exmem allocated memory for corruption
        unsigned long* p = (unsigned long*)exmem_start;
        unsigned long *f = 0, *l = 0;
        long cnt = 0;
        while (p < (unsigned long*)exmem_end)
        {
            if (p[0] != 0xDEADBEEF)
            {
                l = p;
                if (f == 0) f = p;
                cnt++;
            }
            p++;
        }
        if (cnt != 0)
        {
            sprintf(osd_buf, "s:%8x e:%8x", exmem_start, exmem_end);
            draw_txt_string(2, 12, osd_buf, conf.osd_color);
            sprintf(osd_buf, "f:%8x l:%8x c:%d", f, l, cnt);
        }
        else
        {
            sprintf(osd_buf, "OK 0x%x", exmem_start);
        }
        draw_txt_string(2, 13, osd_buf, conf.osd_color);
        // end of check	
    }
#endif

    // DEBUG: "Show misc. values"
    // change ROW to fit values on screen in draw_txt_string(COLUMN, ROW, ...)
    // uncomment call to gui_draw_debug_vals_osd() in gui_redraw() if you want debug values always on top
    if (conf.debug_misc_vals_show) {
        // show value of Memory Address selected with Memory Browser
        sprintf(osd_buf, "MEM: %#8x", (void*) (*(int*)conf.mem_view_addr_init));    // show value in Hexadecimal integer
        //sprintf(osd_buf, "MEM: %8u", (void*) (*(int*)conf.mem_view_addr_init));    // show value in Decimal integer
        draw_txt_string(28,  9, osd_buf, conf.osd_color);

        // show Autofocus status (if AF is working)
        extern volatile long focus_busy;
        sprintf(osd_buf, "FB:  %8u", focus_busy);
        draw_txt_string(28, 10, osd_buf, conf.osd_color);

        // show Zoom status (if Lens is moving)
        extern volatile long zoom_busy;
        sprintf(osd_buf, "ZB:  %8u", zoom_busy);
        draw_txt_string(28, 11, osd_buf, conf.osd_color);

        // show USB-Power status to debug remote / sync
        sprintf(osd_buf, "USB: %8u", get_usb_power(1));
        draw_txt_string(28, 12, osd_buf, conf.osd_color);

        /*
        // some cameras missing zoom_status
        sprintf(osd_buf, "ZS:  %#8x", zoom_status);
        draw_txt_string(28, 13, osd_buf, conf.osd_color);
        */

        /*
        sprintf(osd_buf, "VP:  %#8x", vid_get_viewport_fb_d());
        draw_txt_string(28, 14, osd_buf, conf.osd_color);
        */

        /*
        // debug keymap, KEYS_MASKx, SD_READONLY_FLAG, USB_MASK
        extern long physw_status[3];
        sprintf(osd_buf, "PS1: %#8x", physw_status[0]);
        draw_txt_string(28, 10, osd_buf, conf.osd_color);

        sprintf(osd_buf, "PS2: %#8x", physw_status[1]);
        draw_txt_string(28, 11, osd_buf, conf.osd_color);

        sprintf(osd_buf, "PS3: %#8x", physw_status[2]);
        draw_txt_string(28, 12, osd_buf, conf.osd_color);
        */

        /*
        long v=get_file_counter();
        sprintf(osd_buf, "1:%03d-%04d", (v>>18)&0x3FF, (v>>4)&0x3FFF);
        sprintf(osd_buf, "1:%d, %08X", xxxx, eeee);
        */
    }
    {
        int r,i, p, len;
        if (conf.debug_display == DEBUG_DISPLAY_PROPS){

            for (i=0;i<10;i++){
                r = 0;
                p = conf.debug_propcase_page*10+i;
                get_property_case(p, &r, 4);
                sprintf(osd_buf, "%3d: %d              ", p, r);
                osd_buf[20]=0;
                draw_string(64,16+16*i,osd_buf, conf.osd_color);
            }
        }

        if (conf.debug_display == DEBUG_DISPLAY_PARAMS){
            char s[30];
            int count;

            for (i=0;i<10;i++){
                r = 0;
                p = conf.debug_propcase_page*10+i;
                if (p>=get_flash_params_count()) {
                    sprintf(osd_buf, "%3d: This parameter does not exists", p);
                } else  {
                    len = get_parameter_size(p);
                    if ((len==1)||(len==2)||(len==4)){
                        get_parameter_data(p, &r, len); 
                        sprintf(osd_buf, "%3d: %30d :%2d ", p, r,len);
                    }
                    else {
                        if (len>=sizeof(s)) count=sizeof(s)-1; else count=len;
                        get_parameter_data(p, &s, count);
                        s[count]=0;
                        sprintf(osd_buf, "%3d: %30s :%2d ", p, s,len);
                    }
                }
                draw_string(16,16+16*i,osd_buf, conf.osd_color);
            }
        }
    }

#ifndef CAM_DRYOS
    if(conf.debug_display == DEBUG_DISPLAY_TASKS)
            gui_debug_draw_tasklist();
#endif
#endif
}

// Update displayed debug page for tasks/props/params
#ifdef OPT_DEBUGGING
void gui_update_debug_page()
{
#ifndef CAM_DRYOS
    if(conf.debug_display == DEBUG_DISPLAY_TASKS)
    {
        debug_tasklist_start += debug_display_direction*(TASKLIST_MAX_LINES-2); // a little intentional overlap
        if(debug_tasklist_start >= TASKLIST_NUM_TASKS || debug_tasklist_start < 0)
            debug_tasklist_start = 0;
    }
    else 
#endif
    if (conf.debug_display == DEBUG_DISPLAY_PROPS || conf.debug_display == DEBUG_DISPLAY_PARAMS)
    {
        conf.debug_propcase_page += debug_display_direction*1;
        if(conf.debug_propcase_page > 128 || conf.debug_propcase_page < 0) 
            conf.debug_propcase_page = 0;
    }
}
#endif

//-------------------------------------------------------------------
// void gui_draw_osd()
//      Common OSD display code
//-------------------------------------------------------------------
void gui_draw_osd()
{
    unsigned int m, mode_photo, mode_video;
    m = mode_get();

    if (half_disp_press) 
        return;
    
    mode_video = MODE_IS_VIDEO(m);
    mode_photo = ((m&MODE_MASK) == MODE_PLAY) || !(mode_video || (m&MODE_SHOOTING_MASK)==MODE_STITCH);
    
    if (((camera_info.state.is_shutter_half_press && (conf.show_histo==SHOW_HALF)) || 
         ((conf.show_histo==SHOW_ALWAYS) && (recreview_hold==0))) && 
        (mode_photo || (m&MODE_SHOOTING_MASK)==MODE_STITCH))
    {
        gui_osd_draw_histo();
    }

    if ((m&MODE_MASK) == MODE_REC && (recreview_hold==0 || conf.show_osd_in_review))
    {
        if (conf.show_grid_lines)
            if (module_grids_load())
                libgrids->gui_grid_draw_osd(1);

        if ((((camera_info.state.is_shutter_half_press || camera_info.state.state_kbd_script_run || shooting_get_common_focus_mode()) &&
              (mode_photo || (m&MODE_SHOOTING_MASK)==MODE_STITCH)) ||
             ((mode_video || is_video_recording()) && conf.show_values_in_video)))
        {
           if (conf.show_dof!=DOF_DONT_SHOW)
               gui_osd_calc_dof();
           if ((conf.show_dof==DOF_SHOW_IN_DOF) || (conf.show_dof==DOF_SHOW_IN_DOF_EX))
               gui_osd_draw_dof();  
           if (conf.values_show_real_iso || conf.values_show_market_iso || conf.values_show_ev_seted || conf.values_show_ev_measured || 
               conf.values_show_bv_measured || conf.values_show_bv_seted || conf.values_show_overexposure || conf.values_show_canon_overexposure || conf.values_show_luminance)
               gui_osd_calc_expo_param();           	           
        }

        if (conf.show_state)
            gui_osd_draw_state();

        if (conf.save_raw && conf.show_raw_state && !mode_video && (!camera_info.state.is_shutter_half_press))
            gui_osd_draw_raw_info();
        
        if ((conf.show_values==SHOW_ALWAYS && mode_photo) || 
            ((mode_video || is_video_recording()) && conf.show_values_in_video) || 
            ((camera_info.state.is_shutter_half_press || (recreview_hold==1)) && (conf.show_values==SHOW_HALF)))
            gui_osd_draw_values(1);
        else if (shooting_get_common_focus_mode() && mode_photo && conf.show_values && !((conf.show_dof==DOF_SHOW_IN_DOF) || (conf.show_dof==DOF_SHOW_IN_DOF_EX)))   
            gui_osd_draw_values(2);
        else if (conf.show_values==SHOW_HALF)
            gui_osd_draw_values(0);   
    }

    if ( osd_visible(m&MODE_MASK) )  
    {
        gui_batt_draw_osd();
        gui_space_draw_osd();
        gui_usb_draw_osd();
        if (conf.show_temp>0)
            gui_osd_draw_temp();
#ifdef CAM_HAS_GPS
        gps_startup();
#endif
        if (conf.fast_ev && !mode_video && (m&MODE_MASK) == MODE_REC )
            gui_osd_draw_ev();
    }

    if ( conf.show_clock )
    {
        if ( osd_visible(m&MODE_MASK) || ( camera_info.state.is_shutter_half_press && conf.clock_halfpress==0) ) gui_osd_draw_clock(0,0,0);
        else if ( camera_info.state.is_shutter_half_press && conf.clock_halfpress==1 ) gui_osd_draw_seconds();
    }

    if ( conf.show_movie_time > 0 && (mode_video || is_video_recording()))
        gui_osd_draw_movie_time_left();

#if CAM_EV_IN_VIDEO
    if (is_video_recording()) gui_osd_draw_ev_video(get_ev_video_avail());
#endif

    gui_draw_debug_vals_osd();
}

// GUI handler for normal shooting / playback modes
static void gui_default_draw()
{
    unsigned int m, mode_photo, mode_video;

    m = mode_get();

#if CAM_SWIVEL_SCREEN
    static int flashlight = 0;

    if (conf.flashlight && (m&MODE_SCREEN_OPENED) && (m&MODE_SCREEN_ROTATED))
    {
        flashlight = 1;
        draw_filled_rect(0, 0, camera_screen.width-1, camera_screen.height-1, MAKE_COLOR(COLOR_WHITE, COLOR_WHITE));
        return;
    }
    else if (flashlight)
    {
        flashlight = 0;
        gui_set_need_restore();
        return;
    }
#endif

    if (half_disp_press) 
        return;

    mode_video = MODE_IS_VIDEO(m);
    mode_photo = ((m&MODE_MASK) == MODE_PLAY) || !(mode_video || (m&MODE_SHOOTING_MASK)==MODE_STITCH);

    if (conf.zebra_draw)
        if (module_zebra_load())
	        if (libzebra->gui_osd_draw_zebra(conf.zebra_draw && camera_info.state.is_shutter_half_press && mode_photo))
		        return; // if zebra drawn, we're done

#if !CAM_SHOW_OSD_IN_SHOOT_MENU
    if (!(conf.show_osd && (canon_menu_active==(int)&canon_menu_active-4) && (canon_shoot_menu_active==0))) return;
#else
    if (!(conf.show_osd && (canon_menu_active==(int)&canon_menu_active-4) /*&& (canon_shoot_menu_active==0)*/ )) return;
#endif  

    gui_draw_osd();

#if CAM_DRAW_EXPOSITION
    if (camera_info.state.is_shutter_half_press && ((m&MODE_MASK)==MODE_REC) && ((m&MODE_SHOOTING_MASK))!=MODE_VIDEO_STD && (m&MODE_SHOOTING_MASK)!=MODE_VIDEO_COMPACT)
    {
        extern char* shooting_get_tv_str();
        extern char* shooting_get_av_str();

        strcpy(osd_buf,shooting_get_tv_str());
        strcat(osd_buf,"\"  F");
        strcat(osd_buf,shooting_get_av_str());
        draw_txt_string(22-strlen(osd_buf)/2, 14, osd_buf, conf.osd_color);
    }
#endif
}

//-------------------------------------------------------------------
// GUI/KBD handlers - Canon modes (not in CHDK <ALT> mode, menu etc)
gui_handler defaultGuiHandler = { GUI_MODE_NONE, gui_default_draw, gui_std_kbd_process, 0, 0, GUI_MODE_MAGICNUM };
//-------------------------------------------------------------------
