/*

Motion detection module

Author: mx3 (Max Sagaydachny) . win1251 ( Максим Сагайдачный )
Email: win.drivers@gmail.com
Skype: max_dtc
ICQ#: 125-985-663
Country: Ukraine
Sity: Kharkiv

20070912 mx3: first version

20070918 mx3: speed optimization,

20101201 CHDKLover: speed optimization

*/

#ifdef OPT_MD_DEBUG
#define MD_REC_CALLS_CNT 2048
#define MD_INFO_BUF_SIZE 4096
#endif

#include "camera_info.h"
#include "motion_detector.h"
#include "action_stack.h"
#include "console.h"
#include "keyboard.h"
#include "clock.h"
#include "viewport.h"
#include "debug_led.h"
#include "gui.h"
#include "gui_draw.h"
#include "script_api.h"

// Forward references
static int md_detect_motion(void);

#define MD_XY2IDX(x,y) ((y)*motion_detector.columns+(x))

enum
{
    MD_MEASURE_MODE_U=0,
    MD_MEASURE_MODE_Y=1,
    MD_MEASURE_MODE_V=2,
    MD_MEASURE_MODE_R=3,
    MD_MEASURE_MODE_G=4,
    MD_MEASURE_MODE_B=5
};

enum
{
    MD_DO_IMMEDIATE_SHOOT=1,
    MD_MAKE_DEBUG_LOG_FILE=2,
    MD_MAKE_RAM_DUMP_FILE=4,
    MD_NO_SHUTTER_RELEASE_ON_SHOOT=8
};

enum
{
    MD_REGION_NONE=0,
    MD_REGION_INCLUDE=1,
    MD_REGION_EXCLUDE=2
};

#define MOTION_DETECTOR_CELLS 1024

struct motion_detector_s
{
    int prev[MOTION_DETECTOR_CELLS];
    unsigned char diff[MOTION_DETECTOR_CELLS];

    int columns;
    int rows;
    int threshold;
    int pixel_measure_mode;
    int timeout;
    int measure_interval;

    int last_measure_time;
    int start_time;

    int running;
    int detected_cells;

    int draw_grid;
    int clipping_region_mode;
    int clipping_region_row1;
    int clipping_region_column1;
    int clipping_region_row2;
    int clipping_region_column2;

    int previous_picture_is_ready;

    int return_value;
    int parameters;
    int pixels_step;
    int msecs_before_trigger;

// debug
#ifdef OPT_MD_DEBUG
    int comp_calls_cnt;
    int comp_calls[MD_REC_CALLS_CNT];
#endif
};

static struct motion_detector_s motion_detector;

// Stack process function for running MD logic
static int action_stack_AS_MOTION_DETECTOR()
{
    if (md_detect_motion() == 0)
    {
        if (libscriptapi)
        {
            // We need to recover the motion detector's
            // result and push
            // it onto the thread's stack.
            libscriptapi->set_as_ret(motion_detector.return_value);
        }
        action_pop_func(0);
        return 1;
    }
    return 0;
}

static void md_kbd_sched_immediate_shoot(int no_release)
{
    action_pop_func(0);// REMOVE MD ITEM

    // stack operations are reversed!
    if (!no_release)  // only release shutter if allowed
    {
        action_push_release(KEY_SHOOT_FULL);
        action_push_delay(camera_info.cam_key_press_delay);
    }
    action_push_func(action_stack_AS_MOTION_DETECTOR); // it will removed right after exit from this function
    kbd_key_press(KEY_SHOOT_FULL); // not a stack operation... pressing right now
}

static int clip(int v)
{
    if (v<0) v=0;
    else if (v>255) v=255;
    return v;
}

// TODO add script interface, currently done when script ends
void md_close_motion_detector()
{
}

int md_init_motion_detector
(
 int columns,
 int rows,
 int pixel_measure_mode,
 int detection_timeout,
 int measure_interval,
 int threshold,
 int draw_grid,
 int clipping_region_mode,
 int clipping_region_column1,
 int clipping_region_row1,
 int clipping_region_column2,
 int clipping_region_row2,
 int parameters,
 int pixels_step,
 int msecs_before_trigger
)
{
#ifdef OPT_MD_DEBUG
    motion_detector.comp_calls_cnt=0;
#endif

    if(     pixel_measure_mode != MD_MEASURE_MODE_Y
        &&  pixel_measure_mode != MD_MEASURE_MODE_U
        &&  pixel_measure_mode != MD_MEASURE_MODE_V
        &&  pixel_measure_mode != MD_MEASURE_MODE_R
        &&  pixel_measure_mode != MD_MEASURE_MODE_G
        &&  pixel_measure_mode != MD_MEASURE_MODE_B
        )
    {
        pixel_measure_mode = MD_MEASURE_MODE_Y;
    }

    // Sanity check on grid size
    if (columns < 1) columns = 3;
    if (rows < 1) rows = 3;
    // If too many grid cells, reduce larger of columns and rows until it fits
    while ((columns * rows) > MOTION_DETECTOR_CELLS)
    {
        if (columns > rows) columns--;
        else rows--;
    }

    if(msecs_before_trigger<0)
    {
        msecs_before_trigger=0;
    }

    if (pixels_step<1)
    {
        pixels_step=1;
    }

    if(detection_timeout<0)
    {
        detection_timeout=0;
    }

    if(measure_interval<0)
    {
        measure_interval=0;
    }

    if(threshold<0)
    {
        threshold=0;
    }

    motion_detector.msecs_before_trigger = msecs_before_trigger;
    motion_detector.parameters = parameters;
    motion_detector.pixels_step = pixels_step;
    motion_detector.columns = columns;
    motion_detector.rows = rows;
    motion_detector.return_value = 0;

    motion_detector.pixel_measure_mode = pixel_measure_mode;
    motion_detector.timeout = detection_timeout;
    motion_detector.measure_interval = measure_interval;
    motion_detector.threshold = threshold;
    motion_detector.draw_grid = draw_grid;

    if (clipping_region_column1>clipping_region_column2)
    {
        motion_detector.clipping_region_column2 = clipping_region_column1;
        motion_detector.clipping_region_column1 = clipping_region_column2;
    }
    else
    {
        motion_detector.clipping_region_column2 = clipping_region_column2;
        motion_detector.clipping_region_column1 = clipping_region_column1;
    }

    if (clipping_region_row1>clipping_region_row2)
    {
        motion_detector.clipping_region_row2 = clipping_region_row1;
        motion_detector.clipping_region_row1 = clipping_region_row2;
    }
    else
    {
        motion_detector.clipping_region_row2 = clipping_region_row2;
        motion_detector.clipping_region_row1 = clipping_region_row1;
    }

    if (clipping_region_mode!=MD_REGION_NONE && clipping_region_mode!=MD_REGION_INCLUDE && clipping_region_mode!=MD_REGION_EXCLUDE)
    {
        clipping_region_mode=MD_REGION_NONE;
    }
    motion_detector.clipping_region_mode = clipping_region_mode;

    motion_detector.detected_cells = 0;
    motion_detector.previous_picture_is_ready = 0;
    motion_detector.start_time=get_tick_count();

    motion_detector.last_measure_time = motion_detector.start_time - motion_detector.measure_interval;

    motion_detector.running = 1;

    action_push_func(action_stack_AS_MOTION_DETECTOR);
    gui_set_need_restore();

    return 1;
}

#ifdef OPT_MD_DEBUG
static void md_save_calls_history(){
    char buf[200], fn[30];
    char big[MD_INFO_BUF_SIZE];
    int big_ln;
    int calls,i, ln, fd;
    static struct utimbuf t;
    static struct tm *ttm;


    if( (motion_detector.parameters & MD_MAKE_DEBUG_LOG_FILE) == 0 ){
        return;
    }


    strcpy(fn,"A/MD_INFO.TXT");//,BUILD_NUMBER,motion_detector.pixels_step);
    fd = open(fn, O_WRONLY|O_CREAT, 0777);
    if( fd>=0) {
        console_add_line("Writing info file...");
        lseek(fd,0,SEEK_END);
	    ttm = get_localtime();
        big_ln=sprintf(big, 
				"\r\n--- %04u-%02u-%02u  %02u:%02u:%02u\r\n"
				"CHDK Ver: %s [ #%s ]\r\nBuild Date: %s %s\r\nCamera:  %s [ %s ]\r\n"
				"[%dx%d], threshold: %d, interval: %d, pixels step: %d\r\n"
				"region: [%d,%d-%d,%d], region type: %d\r\n"
				"wait interval: %d, parameters: %d, calls: %d, detected cells: %d\r\n", 
				1900+ttm->tm_year, ttm->tm_mon+1, ttm->tm_mday, ttm->tm_hour, ttm->tm_min, ttm->tm_sec,
				camera_info.chdk_ver, camera_info.build_number, camera_info.build_date, camera_info.build_time, camera_info.platform, camera_info.platformsub,
				motion_detector.columns, motion_detector.rows, motion_detector.threshold, motion_detector.measure_interval, motion_detector.pixels_step,
				motion_detector.clipping_region_column1, motion_detector.clipping_region_row1, motion_detector.clipping_region_column2, motion_detector.clipping_region_row2, motion_detector.clipping_region_mode,
				motion_detector.msecs_before_trigger, motion_detector.parameters, motion_detector.comp_calls_cnt,
				motion_detector.detected_cells
		);

        calls = ( motion_detector.comp_calls_cnt < MD_REC_CALLS_CNT) ?motion_detector.comp_calls_cnt: MD_REC_CALLS_CNT;

        for(i=0;i<calls;i++){
            ln=sprintf(buf,"[%d] - %d\r\n",i,motion_detector.comp_calls[i]);
            if(big_ln+ln>MD_INFO_BUF_SIZE){
          write(fd,big,big_ln);
                big_ln=0;
            }
            memcpy(big+big_ln,buf,ln+1);
            big_ln+=ln;
        }
    write(fd,big,big_ln);
        close(fd);
      t.actime = t.modtime = time(NULL);
    utime(fn, &t);
    }
}

static void mx_dump_memory(void *img){
    char fn[36];
    int fd, i;
    static int cnt=0;

    started();
    mkdir("A/MD");

        do {
            cnt++;
            sprintf(fn, "A/MD/%04d.FB", cnt);
            fd = open(fn, O_RDONLY, 0777);

            if(fd>=0){
                close(fd);
            }
        } while(fd>=0);


		sprintf(fn, "A/MD/%04d.FB", cnt );
		fd = open(fn, O_WRONLY|O_CREAT, 0777);
		if (fd) {
	    write(fd, img, camera_screen.width*vid_get_viewport_height()*3);
	    close(fd);
		}
  vid_bitmap_refresh();
  finished();

}
#else
#define md_save_calls_history()
#define mx_dump_memory(x)
#endif


static int md_running()
{
	return motion_detector.running;
}


static int md_detect_motion(void)
{
    int idx, tick;
    int val, cy, cv, cu;

    register int col, row, x, y;

    if(!md_running())
    {
        return 0;
    }

    tick=get_tick_count();
#ifdef OPT_MD_DEBUG
    if(motion_detector.comp_calls_cnt < MD_REC_CALLS_CNT)
    {
        motion_detector.comp_calls[motion_detector.comp_calls_cnt]=tick;
    }
    motion_detector.comp_calls_cnt++;
#endif

    if(motion_detector.start_time + motion_detector.timeout < tick )
    {
        md_save_calls_history();
        motion_detector.running = 0;
        return 0;
    }

    if(motion_detector.last_measure_time + motion_detector.measure_interval > tick)
    {
        // wait for the next time
        return 1;
    }

    motion_detector.last_measure_time = tick;

    unsigned char* img = vid_get_viewport_live_fb();
    if(img==NULL)
    {
        img = vid_get_viewport_fb();
    }

#ifdef OPT_MD_DEBUG
    if(motion_detector.comp_calls_cnt==50 && (motion_detector.parameters & MD_MAKE_RAM_DUMP_FILE) != 0 )
    {
        mx_dump_memory((char*)img);
    }
#endif

	img += vid_get_viewport_image_offset();		// offset into viewport for when image size != viewport size (e.g. 16:9 image on 4:3 LCD)

	int vp_h = vid_get_viewport_height();
    int vp_w = vid_get_viewport_width();
	int vp_bw = vid_get_viewport_byte_width() * vid_get_viewport_yscale();

	int x_step = motion_detector.pixels_step * 3;
	int y_step = motion_detector.pixels_step * vp_bw;

    for (idx=0, row=0; row < motion_detector.rows; row++)
    {
        // Calc img y start and end offsets
        int y_start = ((row * vp_h) / motion_detector.rows) * vp_bw;
        int y_end = (((row + 1) * vp_h) / motion_detector.rows) * vp_bw;

        for (col=0; col < motion_detector.columns; col++, idx++)
        {
            int in_clipping_region=0;

            if (col+1 >= motion_detector.clipping_region_column1 &&
                col+1 <= motion_detector.clipping_region_column2 &&
                row+1 >= motion_detector.clipping_region_row1 &&
                row+1 <= motion_detector.clipping_region_row2)
            {
                in_clipping_region=1;
            }

            int curr = 0;
            int diff = 0;

            if (
                (motion_detector.clipping_region_mode==MD_REGION_NONE) ||
                (motion_detector.clipping_region_mode==MD_REGION_EXCLUDE && in_clipping_region==0) ||
                (motion_detector.clipping_region_mode==MD_REGION_INCLUDE && in_clipping_region==1)
               )
            {
                // Calc img x start and end offsets
                int x_start = ((col * vp_w) / motion_detector.columns) * 3;
                int x_end = (((col + 1) * vp_w) / motion_detector.columns) * 3;

                int points = 0;

                for (y=y_start; y<y_end; y+=y_step)
                {
                    for (x=x_start; x<x_end; x+=x_step)
                    {
                        // ARRAY of UYVYYY values
                        // 6 bytes - 4 pixels

                        if (motion_detector.pixel_measure_mode == MD_MEASURE_MODE_Y)
                        {
                            val = img[y + x + 1];				                        //Y
                        }
                        else
                        {
                            // Calc offset to UYV component
                            int uvx = x;
                            if (uvx & 1) uvx -= 3;

                            switch(motion_detector.pixel_measure_mode)
                            {
                            case MD_MEASURE_MODE_U:
                                val = (signed char)img[y + uvx];		                //U
                                break;

                            case MD_MEASURE_MODE_V:
                                val = (signed char)img[y + uvx + 2];	                //V
                                break;

                            case MD_MEASURE_MODE_R:
                                cy = img[y + x + 1];
                                cv = (signed char)img[y + uvx + 2];
                                val = clip(((cy<<12)           + cv*5743 + 2048)>>12); // R
                                break;

                            case MD_MEASURE_MODE_G:
                                cy = img[y + x + 1];
                                cu = (signed char)img[y + uvx];
                                cv = (signed char)img[y + uvx + 2];
                                val = clip(((cy<<12) - cu*1411 - cv*2925 + 2048)>>12); // G
                                break;

                            case MD_MEASURE_MODE_B:
                                cy = img[y + x + 1];
                                cu = (signed char)img[y + uvx];
                                val = clip(((cy<<12) + cu*7258           + 2048)>>12); // B
                                break;

                            default:
                                val = 0;    // Stop compiler warning
                                break;
                            }
                        }

                        curr += val;
                        points++;
                    }
                }

                diff = (curr - motion_detector.prev[idx]) / points;
                if (diff < 0) diff = -diff;
                if ((diff > motion_detector.threshold) &&
                    (motion_detector.start_time+motion_detector.msecs_before_trigger < tick))
                {
                    motion_detector.detected_cells++;
                }
            }

            motion_detector.diff[idx] = diff;
            motion_detector.prev[idx] = curr;
        }
    }

    if (motion_detector.previous_picture_is_ready == 0)
    {
        motion_detector.previous_picture_is_ready = 1;
        motion_detector.start_time = get_tick_count();
        motion_detector.last_measure_time = motion_detector.start_time - motion_detector.measure_interval;
        return 1;
    }

    if ( motion_detector.detected_cells > 0 )
    {
//      sprintf(buf,"-cells: %d", motion_detector.detected_cells);
//      script_console_add_line(buf);

        if (motion_detector.start_time+motion_detector.msecs_before_trigger < tick)
        {
            motion_detector.running=0;
            motion_detector.return_value = motion_detector.detected_cells;

//          md_save_calls_history();
            if ((motion_detector.parameters&MD_DO_IMMEDIATE_SHOOT) != 0)
            {
                //make shoot
                md_kbd_sched_immediate_shoot(motion_detector.parameters&MD_NO_SHUTTER_RELEASE_ON_SHOOT);
            }
            return 0;
        }
    }

    return 1;
}

int md_get_cell_diff(int column, int row)
{
    if ((column<1 || column > motion_detector.columns) ||
        (row<1 || row > motion_detector.rows))
    {
        return 0;
    }

    return motion_detector.diff[ MD_XY2IDX(column-1,row-1) ];
}

void md_draw_grid()
{
    int col, row;
    int i;
    char mdbuff[8];

    if (!md_running() || motion_detector.draw_grid==0 || camera_info.state.state_kbd_script_run==0)
    {
        return;
	}

	int xoffset = vid_get_viewport_display_xoffset();	// used when image size != viewport size
	int yoffset = vid_get_viewport_display_yoffset();	// used when image size != viewport size

    // display area size
	int x_size = camera_screen.width-xoffset * 2;
	int y_size = camera_screen.height-yoffset * 2;

    // initial display offsets
    int y_start, y_end = yoffset;
    int x_start, x_end;

    for (i=0, row=0; row < motion_detector.rows; row++)
    {
        // Calc display start and end offsets
        y_start = y_end;    // reuse last end value as new start value
        y_end = yoffset + ((row + 1) * y_size) / motion_detector.rows;

        x_end = xoffset;

        for (col=0; col < motion_detector.columns; col++, i++)
        {
            // Calc display x start and end offsets
            x_start = x_end;    // reuse last end value as new start value
            x_end = xoffset + ((col + 1) * x_size) / motion_detector.columns;

            int in_clipping_region = 0;
            if ( col+1>=motion_detector.clipping_region_column1
                && col+1<=motion_detector.clipping_region_column2
                && row+1>=motion_detector.clipping_region_row1
                && row+1<=motion_detector.clipping_region_row2
                )
            {
                in_clipping_region = 1;
            }

            if ((motion_detector.clipping_region_mode==MD_REGION_EXCLUDE && in_clipping_region==0) ||
                (motion_detector.clipping_region_mode==MD_REGION_INCLUDE && in_clipping_region==1) ||
                (motion_detector.clipping_region_mode==MD_REGION_NONE))
            {
                int diff = motion_detector.diff[i];

                color c = MAKE_COLOR(COLOR_TRANSPARENT, COLOR_HISTO_G);
                if (diff > motion_detector.threshold)
                {
                    c = MAKE_COLOR(COLOR_TRANSPARENT, COLOR_RED);
                }

                if (motion_detector.draw_grid & 2)
                {
                    sprintf(mdbuff,"%-3d", diff);
                    draw_string(x_start+4, y_start+2, mdbuff, c);
                }

                if (motion_detector.draw_grid & 1)
                {
                    draw_rect(x_start+2, y_start+2, x_end-2, y_end-2, c);
                }
            }
        }
    }
}


// =========  MODULE INIT =================

#include "module_def.h"
int module_idx=-1;

/***************** BEGIN OF AUXILARY PART *********************
  ATTENTION: DO NOT REMOVE OR CHANGE SIGNATURES IN THIS SECTION
 **************************************************************/

struct libmotiondetect_sym _libmotiondetect = {
			MAKE_API_VERSION(1,0),		// apiver: increase major if incompatible changes made in module, 
										// increase minor if compatible changes made(including extending this struct)

        md_close_motion_detector,
        md_init_motion_detector,
        md_get_cell_diff,
        md_draw_grid,
	};


void* MODULE_EXPORT_LIST[] = {
	/* 0 */	(void*)EXPORTLIST_MAGIC_NUMBER,
	/* 1 */	(void*)1,

			&_libmotiondetect
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

  if ( !API_VERSION_MATCH_REQUIREMENT( camera_sensor.api_version, 1, 0 ) )
	 return 1;

  return 0;
}


//---------------------------------------------------------
// PURPOSE: Finalize module operations (close allocs, etc)
// RETURN VALUE: 0-ok, 1-fail
//---------------------------------------------------------
int _module_unloader()
{
    md_close_motion_detector();
    return 0;
}


//---------------------------------------------------------
// PURPOSE: Default action for simple modules (direct run)
// NOTE: Please comment this function if no default action and this library module
//---------------------------------------------------------
int _module_run(int moduleidx, int argn, int* arguments)
{
  module_idx=moduleidx;

  return 0;
}

/******************** Module Information structure ******************/

struct ModuleInfo _module_info = {	MODULEINFO_V1_MAGICNUM,
									sizeof(struct ModuleInfo),

									ANY_CHDK_BRANCH, 0,			// Requirements of CHDK version
									ANY_PLATFORM_ALLOWED,		// Specify platform dependency
									MODULEINFO_FLAG_SYSTEM,		// flag
									(int32_t)"Motion Detect",   // Module name
									1, 0,						// Module version
									(int32_t)"Motion Detect"
								 };


/*************** END OF AUXILARY PART *******************/

