#include "platform.h"
#include "lolevel.h"

#define LED_IO_G 0xC0220130
#define LED_IO_R 0xC0220134
#define LED_IO_Y 0xC0220134
#define LED_AF   0xC0223030


// Force Screen to refresh like original Firmware
// from SX210, thanks asm1989
void vid_bitmap_refresh() {
    extern int enabled_refresh_physical_screen;
    extern int full_screen_refresh;
 
    // asm1989: i've tried refreshphysical screen (screen unlock) and that caused the canon and
    // function menu to not display at all. This seems to work and is called in a similar
    // way in other places where original OSD should be refreshed.
    extern void _ScreenLock();
    extern void _ScreenUnlock();

    _ScreenLock();
 
    enabled_refresh_physical_screen=1;
    full_screen_refresh=3;   // found in ScreenUnlock underneath a CameraLog.c call
 
    _ScreenUnlock();
}

void shutdown() {
  volatile long *p = (void*)0xc022001C; // from task_by (not really complete)

  asm(
    "MRS     R1, CPSR\n"
    "AND     R0, R1, #0x80\n"
    "ORR     R1, R1, #0x80\n"
    "MSR     CPSR_cf, R1\n"
    :::"r1","r0");

  *p = 0x44;

  while (1) {
    asm volatile ("nop\n");
  }
}

int get_flash_params_count(void) { return 0x94; }                          // Found @0xff986190

// based on SX10, values found by experiment
void camera_set_led(int led, int state, __attribute__ ((unused))int bright) {
  return; // doesn't seem to work
  static char led_table[]={0, // green
                           1, // orange, right
                           2, // yellow, left
                           3, // power
                           // 4,5,6,7,
                           8, // blue
                           9 // af
  };
  if ((unsigned)led < sizeof(led_table)) {
    _LEDDrive(led_table[led], state<=1 ? !state : state);
  }
}

#define DEBUG_LED LED_IO_Y
void debug_led(int state)
{
    * (int *) DEBUG_LED = state ? 0x46 : 0x44;
}

// from sx10
void JogDial_CW(void){
  //_PostLogicalEventForNotPowerType(0x874, 2);  // RotateJogDialRight
}

void JogDial_CCW(void){
  //_PostLogicalEventForNotPowerType(0x875, 2);  // RotateJogDialLeft
}

// Viewport and Bitmap values that shouldn't change across firmware versions.
// Values that may change are in lib.c for each firmware version.

// Defined in stubs_min.S
extern char active_viewport_buffer;
extern void* viewport_buffers[];

void *vid_get_viewport_fb()
{
    // Return first viewport buffer - for case when vid_get_viewport_live_fb not defined
    return viewport_buffers[0];
}

void *vid_get_viewport_live_fb()
{
    if (camera_info.state.mode_video)
        return viewport_buffers[0];     // Video only seems to use the first viewport buffer.

    // Hopefully return the most recently used viewport buffer so that motion detect, histogram, zebra and edge overly are using current image data
    return viewport_buffers[(active_viewport_buffer)&3];
}

void *vid_get_viewport_fb_d()
{
    extern char *viewport_fb_d;
	return viewport_fb_d;
}

void *vid_get_bitmap_fb()
{
    return (void*)0x40431000;               // Found @0xff859828
}


// Functions for PTP Live View system
// 256 entry palette based on 100a
// sub_ff90ce84  <- Called for a function with 2 ref to **"Palette Class.
int vid_get_palette_type()                      { return 3; }
int vid_get_palette_size()                      { return 256 * 4; }

void *vid_get_bitmap_active_buffer()
{   //found @loc_ff90cf28 ixus130 100a ->Called before *"..<GetBmpVramInfo> Add
    return (void*)(*(int*)(0x556C+0x18)); 
}

void *vid_get_bitmap_active_palette() {
        return (void*)(*(int*)(0x556C+0x2C));  //Found @ 0xff90ce84 ixus130 100a
}
