#include "stdlib.h"
#include "keyboard.h"
#include "platform.h"
#include "lang.h"
#include "conf.h"
#include "gui.h"
#include "gui_draw.h"
#include "gui_lang.h"
#include "gui_osd.h"
#ifdef OPT_EDGEOVERLAY
    #include "edgeoverlay.h"
#endif

//-------------------------------------------------------------------
static char osd_buf[64];

DOF_TYPE dof_values;
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

void gui_osd_calc_expo_param()
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

void gui_print_osd_state_string_int(const char * title, int value)
{
    sprintf(osd_buf, "%s%d", title, value);
    gui_print_osd_state_string();
}

void gui_print_osd_state_string_chr(const char *title, const char *value)
{
    sprintf(osd_buf, "%s%s", title, value);
    gui_print_osd_state_string();
}

void gui_print_osd_state_string_float(const char * fmt, int divisor, int value)
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

void gui_print_osd_misc_string_int(const char * title, int value)
{
    sprintf(osd_buf, "%s%d", title, value);
    gui_print_osd_misc_string();
}

void gui_print_osd_misc_string_float(const char * fmt, int divisor, int value)
{
    sprintf(osd_buf, fmt, (int)(value/divisor), (int)(value%divisor));
    gui_print_osd_misc_string();
}

void gui_print_osd_misc_string_canon_values(const char * title, short value)
{
    strcpy(osd_buf, title);
    sprintf_canon_values(osd_buf+strlen(osd_buf), value);
    gui_print_osd_misc_string();
}
    
void gui_print_osd_dof_string_dist(const char * title, int value, short use_good_color, short is_hyp) {
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
    draw_string(conf.values_pos.x+i*FONT_WIDTH, conf.values_pos.y+m, osd_buf, use_good_color?((conf.osd_color & 0xff00) | COLOR_GREEN):conf.osd_color);
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
void gui_osd_draw_state()
{
    int a,  gui_mode=gui_get_mode(), m=(mode_get()&MODE_SHOOTING_MASK); 
    long t; 

    n=0;
    ///////////////////////////
    //sprintf(osd_buf,"%s",get_debug());
    //draw_string(conf.mode_state_pos.x, conf.mode_state_pos.y+6*FONT_HEIGHT, osd_buf, conf.osd_color);
    ////////////////////////////  

    if ((((conf.tv_enum_type) || (conf.tv_override_value)) && (conf.tv_override_koef)  && !(conf.override_disable==1)) || gui_mode==GUI_MODE_OSD)
    {
        if(kbd_is_key_pressed(KEY_SHOOT_HALF)) 
        { 
            t=(int)(shooting_get_shutter_speed_from_tv96(shooting_get_tv96())*100000);	
            gui_print_osd_state_string_float("TV:%d.%05d", 100000, t);
        }
        else 
        {
            if (conf.tv_enum_type) 
                gui_print_osd_state_string_chr("TV:",shooting_get_tv_override_value()); 
            else  
            {
                t=(int)(shooting_get_shutter_speed_override_value()*100000);
                gui_print_osd_state_string_float("TV:%d.%05d", 100000, t);
            }
        }
    }
    if ((conf.av_override_value && !(conf.override_disable==1))|| gui_mode==GUI_MODE_OSD)  
        gui_print_osd_state_string_float("AV:%d.%02d", 100, shooting_get_aperture_from_av96(shooting_get_av96_override_value()));
#if CAM_HAS_ND_FILTER
    if ((conf.nd_filter_state && !(conf.override_disable==1))|| gui_mode==GUI_MODE_OSD) 
        gui_print_osd_state_string_chr("NDFILTER:", ((conf.nd_filter_state==1)?"IN":"OUT"));
#endif    
    if ((conf.autoiso_enable && shooting_get_iso_mode()<=0 && !(m==MODE_M || m==MODE_TV) && shooting_get_flash_mode() && (!(conf.override_disable==1 && conf.override_disable_all))) || gui_mode==GUI_MODE_OSD)  
        gui_print_osd_state_string_chr("AUTOISO:", ((conf.autoiso_enable==1)?"ON":"OFF"));
    if ((conf.subj_dist_override_value && conf.subj_dist_override_koef && shooting_can_focus() && !(conf.override_disable==1)) || ((gui_get_mode()==GUI_MODE_ALT) && shooting_get_common_focus_mode())	|| gui_mode==GUI_MODE_OSD)   {
        extern const char* gui_subj_dist_override_value_enum(int change, int arg);
        extern const char* gui_subj_dist_override_koef_enum(int change, int arg);
        gui_print_osd_state_string_chr("SD:",gui_subj_dist_override_value_enum(0,0));
        if (gui_mode==GUI_MODE_ALT)
            gui_print_osd_state_string_chr("FACTOR:",gui_subj_dist_override_koef_enum(0,0));
    }
    if ((conf.iso_override_value && conf.iso_override_koef && !(conf.override_disable==1))   || gui_mode==GUI_MODE_OSD)
        gui_print_osd_state_string_int("ISO:", shooting_get_iso_override_value());
    if ((gui_mode==GUI_MODE_OSD) || (shooting_get_drive_mode() && m!=MODE_STITCH && m!=MODE_SCN_BEST_IMAGE)) {
    if ((conf.tv_bracket_value && !(conf.override_disable==1 && conf.override_disable_all)) || (conf.av_bracket_value && !(conf.override_disable==1 && conf.override_disable_all))  || (conf.iso_bracket_value && conf.iso_bracket_koef && !(conf.override_disable==1 && conf.override_disable_all)) || ((conf.subj_dist_bracket_value) && (conf.subj_dist_bracket_koef) && (shooting_can_focus() && !(conf.override_disable==1 && conf.override_disable_all))))
        gui_print_osd_state_string_chr("BRACKET:", shooting_get_bracket_type());
      if (conf.tv_bracket_value && !(conf.override_disable==1 && conf.override_disable_all))
        gui_print_osd_state_string_chr("TV:", shooting_get_tv_bracket_value());
      else if  (conf.av_bracket_value && !(conf.override_disable==1 && conf.override_disable_all))
        gui_print_osd_state_string_chr("AV:", shooting_get_av_bracket_value());
      else if  (conf.iso_bracket_value && conf.iso_bracket_koef   && !(conf.override_disable==1 && conf.override_disable_all))
        gui_print_osd_state_string_int("ISO:", shooting_get_iso_bracket_value());
      else if  ((conf.subj_dist_bracket_value  && !(conf.override_disable==1 && conf.override_disable_all)) && (conf.subj_dist_bracket_koef) && (shooting_can_focus()))
        gui_print_osd_state_string_int("SD:",shooting_get_subject_distance_bracket_value());
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
        if (edge_state_draw==0) gui_print_osd_state_string_chr("EDGE:", "LIVE");
        else if (edge_state_draw==1) gui_print_osd_state_string_chr("EDGE:", ((conf.edge_overlay_pano==0)?"FROZEN":"PANO"));
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

void gui_osd_draw_seconds()
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

void gui_osd_draw_movie_time_left()
{
    static int card_used, init_space, elapsed, avg_use, time_left;
    static long init_time;
    static int record_running = 0;
    static int init = 0;
    static unsigned int skipcalls = 1;
    unsigned int hour=0, min=0, sec=0;
    int mode_video = MODE_IS_VIDEO(m); 

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
        // everything else is for stills
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

void gui_osd_draw_ev()
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
