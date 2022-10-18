#include "platform.h"
#include "platform_palette.h"
#include "lolevel.h"

void vid_bitmap_refresh()
{
	_ScreenLock();
    _RefreshPhysicalScreen(1);
}

void shutdown()
{
    volatile long *p = (void*)0xc022001C; // from task_by (not really complete)

    asm(
         "MRS     R1, CPSR\n"
         "AND     R0, R1, #0x80\n"
         "ORR     R1, R1, #0x80\n"
         "MSR     CPSR_cf, R1\n"
         :::"r1","r0");

    *p = 0x44;

    while(1);
}

// found at 0xff8d03f0 for sd970 which matched 0xff8cab9c on sd780 which referenced to 0xc0220128 originally
#define LED_PR 0xC0220134

void debug_led(int state)
{
    volatile long *p=(void*)LED_PR;
    if (state)
	p[0]=0x46;
    else
	p[0]=0x44;
}

int get_flash_params_count(void) { return 0x7a; }  // sd970: Found @0xff94ce88
// values for sd970 found by experiment in CHDKPTP
// using "=set_led(0,1)"  first parameter: LED number, second: state of the LED: 1 on, 0 off, others blink
void camera_set_led(int led, int state, __attribute__ ((unused))int bright) {
 static char led_table[]={0, // green
                          1, // orange, right
                          2, // yellow, left
                          // 3,4,5,6,7,
                          8, // blue
                          9 // af
                          };
 if((unsigned)led < sizeof(led_table))
  _LEDDrive(led_table[led], state<=1 ? !state : state);
// _LEDDrive(led_table[led%sizeof(led_table)], state<=1 ? !state : state);
}

// 0x874 and 0x875 values may be camera model dependent, search them in firmware (in pair with RotateJogDialRight(Left)) strings.
// sd970: table "PrintMenu" @ ffb8060e, fw 1.00A
void JogDial_CW(void){
 _PostLogicalEventForNotPowerType(0x874, 1);  // sd970: RotateJogDialRight (in table "PrintMenu" @ ffb81b5a, fw 1.00A)
}
void JogDial_CCW(void){
 _PostLogicalEventForNotPowerType(0x875, 1);  // sd970: RotateJogDialLeft (in table "PrintMenu" @ ffb81ad3, fw 1.00A)
}

// sd970: The palette replaces the hues of blue used for gradients on menu buttons
// that works consistently though Rec / Func, Play and Canon Menu have no CHDK Palette
void load_chdk_palette()
{
    extern int active_palette_buffer;

    if ((active_palette_buffer == 0) || (active_palette_buffer == 1)) 
    {
        int *pal = (int*)vid_get_bitmap_active_palette();
        if (pal[CHDK_COLOR_BASE+0] != 0x33ADF62)
        {
            pal[CHDK_COLOR_BASE+0]  = 0x33ADF62;  // Red
            pal[CHDK_COLOR_BASE+1]  = 0x326EA40;  // Dark Red
            pal[CHDK_COLOR_BASE+2]  = 0x34CD57F;  // Light Red
            pal[CHDK_COLOR_BASE+3]  = 0x373BFAE;  // Green
            pal[CHDK_COLOR_BASE+4]  = 0x34BD6CA;  // Dark Green
            pal[CHDK_COLOR_BASE+5]  = 0x395AB95;  // Light Green
            pal[CHDK_COLOR_BASE+6]  = 0x34766F0;  // Blue
            pal[CHDK_COLOR_BASE+7]  = 0x31250F3;  // Dark Blue
            pal[CHDK_COLOR_BASE+8]  = 0x37F408F;  // Cyan
            pal[CHDK_COLOR_BASE+9]  = 0x3512D5B;  // Magenta
            pal[CHDK_COLOR_BASE+10] = 0x3A9A917;  // Yellow
            pal[CHDK_COLOR_BASE+11] = 0x3819137;  // Dark Yellow
            pal[CHDK_COLOR_BASE+12] = 0x3DED115;  // Light Yellow
            pal[CHDK_COLOR_BASE+13] = 0x0090000;  // Transparent dark grey

            vid_bitmap_refresh();
        }
    }
}

// Viewport and Bitmap values that shouldn't change across firmware versions.
// Values that may change are in lib.c for each firmware version.
extern int _GetVRAMHPixelsSize();
extern int _GetVRAMVPixelsSize();

// Fixes 320 Video for CHDKPTP, maybe more?
int vid_get_viewport_width_proper() {
    return ((mode_get()&MODE_MASK) == MODE_PLAY)?720:_GetVRAMHPixelsSize();
}
int vid_get_viewport_height_proper() {
    return ((mode_get()&MODE_MASK) == MODE_PLAY)?480:_GetVRAMVPixelsSize();
}

int vid_get_viewport_width() { return vid_get_viewport_width_proper(); }
long vid_get_viewport_height() { return vid_get_viewport_height_proper(); }
//I don't know if these get used
int vid_get_viewport_fullscreen_width() { return vid_get_viewport_width_proper(); }
int vid_get_viewport_fullscreen_height() { return vid_get_viewport_height_proper(); }


// sd970: PTP display stuff
int vid_get_palette_type() { return 3; }
int vid_get_palette_size() { return 256 * 4; }

void *vid_get_bitmap_active_palette()
{
    extern int active_palette_buffer;
    extern char** palette_buffer_ptr;
    return palette_buffer_ptr[active_palette_buffer]+12;
}
