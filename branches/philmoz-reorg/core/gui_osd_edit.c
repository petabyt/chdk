#include "stdlib.h"
#include "keyboard.h"
#include "platform.h"
#include "histogram.h"
#include "lang.h"
#include "conf.h"
#include "gui_draw.h"
#include "gui_lang.h"
#include "gui_batt.h"
#include "gui_usb.h"
#include "gui_space.h"
#include "gui_osd.h"

#include "module_load.h"
#include "module_exportlist.h"

//-------------------------------------------------------------------
typedef struct {
    int     title;
    OSD_pos *pos;
    OSD_pos size;
} OSD_elem;

static OSD_elem osd[]={
    {LANG_OSD_LAYOUT_EDITOR_HISTO,      &conf.histo_pos,        {HISTO_WIDTH+2, HISTO_HEIGHT}   },
    {LANG_OSD_LAYOUT_EDITOR_DOF_CALC,   &conf.dof_pos,          {23*FONT_WIDTH, 2*FONT_HEIGHT}  },
    {LANG_OSD_LAYOUT_EDITOR_STATES,     &conf.mode_state_pos,   {12*FONT_WIDTH, 4*FONT_HEIGHT}  },
    {LANG_OSD_LAYOUT_EDITOR_RAW,        &conf.mode_raw_pos,     {7*FONT_WIDTH, FONT_HEIGHT}     },
    {LANG_OSD_LAYOUT_EDITOR_MISC,       &conf.values_pos,       {9*FONT_WIDTH, 9*FONT_HEIGHT}   },
    {LANG_OSD_LAYOUT_EDITOR_BAT_ICON,   &conf.batt_icon_pos,    {28, 12}                        },
    {LANG_OSD_LAYOUT_EDITOR_SPACE_ICON, &conf.space_icon_pos,   {23, 15}                        },
    {LANG_OSD_LAYOUT_EDITOR_SPACE_ICON, &conf.space_ver_pos,    {3, 50}                         },
    {LANG_OSD_LAYOUT_EDITOR_SPACE_ICON, &conf.space_hor_pos,    {50, 3}                         },
    {LANG_OSD_LAYOUT_EDITOR_BAT_TEXT,   &conf.batt_txt_pos,     {5*FONT_WIDTH, FONT_HEIGHT}     },
    {LANG_OSD_LAYOUT_EDITOR_SPACE_TEXT, &conf.space_txt_pos,    {5*FONT_WIDTH, FONT_HEIGHT}     },
    {LANG_OSD_LAYOUT_EDITOR_CLOCK,      &conf.clock_pos,        {5*FONT_WIDTH, FONT_HEIGHT}     },
    {LANG_OSD_LAYOUT_EDITOR_TEMP,       &conf.temp_pos,         {9*FONT_WIDTH, FONT_HEIGHT}     },
    {LANG_OSD_LAYOUT_EDITOR_VIDEO,      &conf.mode_video_pos,   {9*FONT_WIDTH, 4*FONT_HEIGHT}   },
    {LANG_OSD_LAYOUT_EDITOR_EV,         &conf.mode_ev_pos,      {12*FONT_WIDTH, FONT_HEIGHT}    },
    {LANG_OSD_LAYOUT_EDITOR_EV_VIDEO,   &conf.ev_video_pos,     {70, 24}},
    {LANG_OSD_LAYOUT_EDITOR_USB_INFO,   &conf.usb_info_pos,     {31, 14}},  
    {0}
};

static int osd_to_draw;
static int curr_item;
static int step;

//-------------------------------------------------------------------
void gui_osd_draw(int enforce_redraw)
{
    char osd_buf[64];

    if (osd_to_draw)
    {
        int i;
        draw_restore();
        gui_osd_draw_histo();
        gui_osd_draw_dof();
        gui_batt_draw_osd();
        gui_space_draw_osd();
        gui_osd_draw_state();
        gui_osd_draw_raw_info();
        gui_osd_draw_values(2);
        gui_osd_draw_clock(0,0,0);
        gui_osd_draw_temp();
        gui_osd_draw_ev_video(1);
        gui_usb_draw_osd();
        for (i=1; i<=2; ++i)
        {
            draw_rect((osd[curr_item].pos->x>=i)?osd[curr_item].pos->x-i:0, (osd[curr_item].pos->y>=i)?osd[curr_item].pos->y-i:0, 
                      osd[curr_item].pos->x+osd[curr_item].size.x+i-1, osd[curr_item].pos->y+osd[curr_item].size.y+i-1,
                      COLOR_GREEN);
        }
        sprintf(osd_buf, " %s:  x:%d y:%d s:%d ", lang_str(osd[curr_item].title), osd[curr_item].pos->x, osd[curr_item].pos->y, step);
        draw_string(0, (osd[curr_item].pos->x<strlen(osd_buf)*FONT_WIDTH+4 && osd[curr_item].pos->y<FONT_HEIGHT+4)?camera_screen.height-FONT_HEIGHT:0,
                    osd_buf, MAKE_COLOR(COLOR_RED, COLOR_WHITE));
        osd_to_draw = 0;
    }
}

//-------------------------------------------------------------------
int gui_osd_kbd_process()
{
    switch (kbd_get_autoclicked_key())
    {
    case KEY_LEFT:
        if (osd[curr_item].pos->x > 0)
        {
            osd[curr_item].pos->x-=(osd[curr_item].pos->x>=step)?step:osd[curr_item].pos->x;
            osd_to_draw = 1;
        }
        break;
    case KEY_RIGHT:
        if (osd[curr_item].pos->x < camera_screen.width-osd[curr_item].size.x)
        {
            osd[curr_item].pos->x+=(camera_screen.width-osd[curr_item].size.x-osd[curr_item].pos->x>step)?step:camera_screen.width-osd[curr_item].size.x-osd[curr_item].pos->x;
            osd_to_draw = 1;
        } else
            osd[curr_item].pos->x = camera_screen.width-osd[curr_item].size.x;
        break;
    case KEY_UP:
        if (osd[curr_item].pos->y > 0)
        {
            osd[curr_item].pos->y-=(osd[curr_item].pos->y>=step)?step:osd[curr_item].pos->y;
            osd_to_draw = 1;
        }
        break;
    case KEY_DOWN:
        if (osd[curr_item].pos->y < camera_screen.height-osd[curr_item].size.y)
        {
            osd[curr_item].pos->y+=(camera_screen.height-osd[curr_item].size.y-osd[curr_item].pos->y>step)?step:camera_screen.height-osd[curr_item].size.y-osd[curr_item].pos->y;
            osd_to_draw = 1;
        } else
            osd[curr_item].pos->y = camera_screen.height-osd[curr_item].size.y;
        break;
    case KEY_SET:
        ++curr_item;
        if ((osd[curr_item].title == LANG_OSD_LAYOUT_EDITOR_EV_VIDEO) && !camera_info.cam_ev_in_video) curr_item++;
        if (!osd[curr_item].pos) 
            curr_item = 0;
        osd_to_draw = 1;
        break;
    case KEY_DISPLAY:
        step=(step==1)?10:1;
        osd_to_draw = 1;
        break;
    }
    return 0;
}

static int module_idx=-1;

void gui_osd_menu_kbd_process()
{
	gui_default_kbd_process_menu_btn();
  	module_async_unload(module_idx);
}

//-------------------------------------------------------------------

gui_handler layoutGuiHandler =
{
    // THIS IS OSD LAYOUT EDITOR
    GUI_MODE_OSD, gui_osd_draw, gui_osd_kbd_process, gui_osd_menu_kbd_process, GUI_MODE_FLAG_NODRAWRESTORE, GUI_MODE_MAGICNUM
};

// =========  MODULE INIT =================
#include "module_load.h"

/***************** BEGIN OF AUXILARY PART *********************
  ATTENTION: DO NOT REMOVE OR CHANGE SIGNATURES IN THIS SECTION
 **************************************************************/

void* MODULE_EXPORT_LIST[] = {
	/* 0 */	(void*)EXPORTLIST_MAGIC_NUMBER,
	/* 1 */	(void*)0
		};


//---------------------------------------------------------
// PURPOSE:   Bind module symbols with chdk. 
//		Required function
// PARAMETERS: pointer to chdk list of export
// RETURN VALUE: 1 error, 0 ok
//---------------------------------------------------------
int _module_loader( unsigned int* chdk_export_list )
{
  if ( chdk_export_list[0] != EXPORTLIST_MAGIC_NUMBER )
     return 1;
  if ( !API_VERSION_MATCH_REQUIREMENT( gui_version.common_api, 1, 0 ) )
	  return 1;

  return 0;
}


//---------------------------------------------------------
// PURPOSE: Finalize module operations (close allocs, etc)
// RETURN VALUE: 0-ok, 1-fail
//---------------------------------------------------------
int _module_unloader()
{
  //sanity clean to prevent accidentaly assign/restore guimode to unloaded module 
  layoutGuiHandler.magicnum = 0;

  return 0;
}


//---------------------------------------------------------
// PURPOSE: Default action for simple modules (direct run)
// NOTE: Please comment this function if no default action and this library module
//---------------------------------------------------------
int _module_run(int moduleidx, int argn, int* arguments)
{
    module_idx=moduleidx;

    osd_to_draw = 1;
    curr_item = 0;
    step = 10;

    gui_set_mode(&layoutGuiHandler);

    return 0;
}

/******************** Module Information structure ******************/

struct ModuleInfo _module_info = {	MODULEINFO_V1_MAGICNUM,
									sizeof(struct ModuleInfo),

									ANY_CHDK_BRANCH, 0,			// Requirements of CHDK version
									ANY_PLATFORM_ALLOWED,		// Specify platform dependency
									MODULEINFO_FLAG_SYSTEM,     // flag
									(int32_t)"OSD Editor",		// Module name
									1, 0,						// Module version
									0
								 };

/*************** END OF AUXILARY PART *******************/
