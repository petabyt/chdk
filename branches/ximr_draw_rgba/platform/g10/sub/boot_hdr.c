#include "lolevel.h"
#include "platform.h"
#include "core.h"

// run blinker task
//#define BLINKER 1
#ifdef BLINKER
#include "gui.h"
#include "../../../../core/gui_draw.h"
#endif

const char * const new_sa = &_end;

#define LED_ISO  (void*) 0xC02200D0 // G10 ISO select dial LED
#define LED_DP   (void*) 0xC02200D4 // G10 direct print button LED
#define LED_ECL  (void*) 0xC02200D8 // G10 exposure compensation dial LED
#define LED_PWR  (void*) 0xC02200DC // G10 power LED

extern void task_CaptSeq();
extern void task_InitFileModules();
extern void task_RotaryEncoder();
extern void task_MovieRecord();
extern void task_ExpDrv();
extern void task_FileWrite();

// Forward declarations
void CreateTask_PhySw();
void CreateTask_spytask();
extern volatile int jogdial_stopped;
void JogDial_task_my(void);

#ifdef BLINKER
void __attribute__((naked,noinline)) task_blinker() {

int pwr_led_count = 0 ;
int blue_led_count = 0 ;
int gui_mode, gui_mode_flag = GUI_MODE_NONE ;

volatile long *pwr_LED = (void*)LED_PWR;
volatile long *blue_LED = (void*)LED_DP;

        _SleepTask(2000);

        while(1){

            gui_mode = camera_info.state.gui_mode;

            if(( (gui_mode == GUI_MODE_ALT)  && (gui_mode_flag != GUI_MODE_ALT) ) || ( (gui_mode == GUI_MODE_NONE)  && (gui_mode_flag != GUI_MODE_NONE) ) )
            {
                gui_mode_flag = gui_mode ;
                blue_led_count = 10 ;
                *blue_LED = 0x46;
            }
            if ( blue_led_count > 0 )
            {
                if ( --blue_led_count == 0 )
                {
                    *blue_LED = 0x44;
                }
            }

            if ( pwr_led_count == 2 )
            {
                *pwr_LED = 0x44;
            }
            if ( --pwr_led_count <= 0 )
            {
                pwr_led_count = 20 ;
                *pwr_LED = 0x46;
            }

            _SleepTask(100);
        }
};

void CreateTask_Blinker() {
        _CreateTask("Blinker", 0x1, 0x200, task_blinker, 0);
};
#endif

void taskCreateHook(int *p) {
    p-=17;

    if (p[0]==(int)task_InitFileModules) p[0]=(int)init_file_modules_task;
    if (p[0]==(int)task_MovieRecord)     p[0]=(int)movie_record_task;
    if (p[0]==(int)task_CaptSeq)         p[0]=(int)capt_seq_task;
    if (p[0]==(int)task_ExpDrv)          p[0]=(int)exp_drv_task;
    if (p[0]==(int)task_RotaryEncoder)   p[0]=(int)JogDial_task_my;
    if (p[0]==(int)task_FileWrite)       p[0]=(int)filewritetask;
}

void taskCreateHook2(int *p) {
    p-=17;
    if (p[0]==(int)task_InitFileModules) p[0]=(int)init_file_modules_task;
    if (p[0]==(int)task_ExpDrv)          p[0]=(int)exp_drv_task;
    if (p[0]==(int)task_FileWrite)       p[0]=(int)filewritetask;
}

/*----------------------------------------------------------------------
    boot()

    Main entry point for the CHDK code
-----------------------------------------------------------------------*/
