#include "platform.h"
#include "lolevel.h"

static char* frame_buffer[2];

  extern int displaytype;//for test
extern void _LogCameraEvent(int id, const char *fmt,...);
extern int active_bitmap_buffer;
extern void* bitmap_buffer[];
extern char* raw_buffers_canon_raw[];
extern char* raw_buffers_jpeg[];

void vid_bitmap_refresh() {
    extern int full_screen_refresh;
    extern void _ScreenUnlock();
    extern void _ScreenLock();
    extern void _displaybusyonscreen();
    extern void _undisplaybusyonscreen();

    
    // clears perfectly but blinks and is asynchronous
    _displaybusyonscreen();
    _undisplaybusyonscreen();
/*    _LogCameraEvent(0x20,"lc  avb:%d gdt:%d ",
                   active_bitmap_buffer,
                   displaytype 
                   );
*/     
    // stuff commented on sx280
    /*
    // completely ineffective
    extern void _refresh_bitmap_buf_from(int, int);
    _refresh_bitmap_buf_from(0,0);
    */

    /*
    // flips the active buffer but doesn't erase areas not occupied by the canon osd
    _ScreenLock();
    full_screen_refresh |= 3;
    _ScreenUnlock();
    */

    /*
    //ineffective, like screenlock/unlock, crashed movie rec once
    extern void _RefreshPhysicalScreen();
    int saved_abdcplus4c = *(int*)(0xabdc+0x4c);
    *(int*)(0xabdc+0x4c) = 0;
    _RefreshPhysicalScreen(0);
    *(int*)(0xabdc+0x4c) = saved_abdcplus4c;
    */

    //DisplayPhysicalScreenCBR NG
    //Window_EmergencyRefresh NG crash
}

void shutdown() {
/*
    volatile long *p = (void*)0xC022001C;

    asm(
        "MRS     R1, CPSR\n"
        "AND     R0, R1, #0x80\n"
        "ORR     R1, R1, #0x80\n"
        "MSR     CPSR_cf, R1\n"
        :::"r1","r0"
    );

    *p = 0x44;  // power off.
*/
    while(1);
}

#define LED_PR 0xd20b0994 // green LED on the back

void debug_led(int state) {
    volatile long *p = (void*)LED_PR;
    *p = ((state) ? 0x4d0002 : 0x4c0003);
}

// Power Led = first entry in table (led 0)
// AF Assist Lamp = second entry in table (led 1)
void camera_set_led(int led, int state, int bright) {
    static char led_table[2]={0,4};
    _LEDDrive(led_table[led%sizeof(led_table)], state<=1 ? !state : state);
}

void shutdown_soft() {
    _PostLogicalEventForNotPowerType(0x1005,0); // PressOffButton
}

int get_flash_params_count(void) {
    return 0xde; // @0xfc0afeb8
}

void JogDial_CW(void) {
    _PostLogicalEventToUI(0x8ad, 1);    //RotateJogDialRight 
}

void JogDial_CCW(void) {
    _PostLogicalEventToUI(0x8ae, 1);    //RotateJogDialLeft
}

extern  int     active_raw_buffer;
//extern  char*   raw_buffers[];
char *hook_raw_image_addr()
{
    // observed values 0-2, 3 would index something that doesn't look like a raw fb in the jpeg case
    int i=active_raw_buffer&3;
/*    _LogCameraEvent(0x20,"lc: hria: %i %i %08x %i",i, camera_info.state.mode_shooting,
                                              camera_info.state.mode_shooting,
                                              shooting_get_prop(PROPCASE_IMAGE_FORMAT));
*/
    if(i>2) {
        i=0;
    }
    if( camera_info.state.mode_shooting == MODE_AUTO) {
        // AUTO mode (canon raw can't be enabled in AUTO)
        return (char *)0x435ee300; // TODO unclear if this is only buffer, or if used in all AUTO sub modes
    }else if(shooting_get_prop(PROPCASE_IMAGE_FORMAT) == 1) {
    // canon raw disabled - uses up to 3 raw buffers
        return raw_buffers_jpeg[i];
    } else {
        // canon raw enabled - different address, not clear if it ever uses multiple buffers
        return raw_buffers_canon_raw[i];
    }
    // TODO most scene modes seem to use different addresse(s)
}

/*
char *hook_raw_image_addr()
{
      return raw_buffers[(active_raw_buffer&1)];
}


char *hook_alt_raw_image_addr()
{
    return raw_buffers[((active_raw_buffer&1)^1)];
}
*/


void *vid_get_viewport_fb() {
    return (void*)0x43334300; // same as g7x "first" viewport adr, "VRAM Address  : %p", contains d6 uyvy
// TODO sx280 values
    // Return first viewport buffer - for case when vid_get_viewport_live_fb not defined
    //return (void*)0x43115100; // uyvy buffers with signed(?) chroma components
    // return (void*)0x4b25fc00; // uyvy buffers (more than 4), pixel format compatible with earlier DIGIC uyvy
}

void *vid_get_viewport_fb_d()    { return (void*)0x43334300; } 

void *vid_get_viewport_live_fb() {
    return bitmap_buffer[(active_bitmap_buffer -1 )&3];
}

int vid_get_viewport_width() {
/*
loc_fc134980: ; 4 refs (GetVRAMHPixelsSize)
fc134980:   487d        ldr r0, [pc, #500]  ; 0xfc134b78: (0002ca18) 
fc134982:   f8d0 00ac   ldr.w   r0, [r0, #172]  ; 0xac
fc134986:   4770        bx  lr
*/
   if (camera_info.state.mode_play)
   { 
      return 360; //todo
   }
    extern int _GetVRAMHPixelsSize();
    return _GetVRAMHPixelsSize();
}

long vid_get_viewport_height() {
/*
loc_fc134988: ; 3 refs (GetVRAMVPixelsSize)
fc134988:   487b        ldr r0, [pc, #492]  ; 0xfc134b78: (0002ca18) 
fc13498a:   f8d0 00b0   ldr.w   r0, [r0, #176]  ; 0xb0
fc13498e:   4770        bx  lr
*/

    int m = mode_get();
    int aspect_ratio=shooting_get_prop(PROPCASE_ASPECT_RATIO);

    if (MODE_IS_VIDEO(m) || is_video_recording())
        return 480;

    if ((m & MODE_MASK) != MODE_PLAY)
    {
        // 0 = 4:3, 1 = 16:9, 2 = 3:2, 3 = 1:1
        if (aspect_ratio==1 || aspect_ratio==2)
            return 480;
    }
    extern int _GetVRAMVPixelsSize();
    return ((m & MODE_MASK) == MODE_PLAY)?480:_GetVRAMVPixelsSize();
}


// Y multiplier for cameras with 480 pixel high viewports (CHDK code assumes 240)
int vid_get_viewport_yscale() {
    return 2;
}
// viewport width offset table for each aspect ratio
// 0 = 4:3, 1 = 16:9, 2 = 3:2, 3 = 1:1
static long vp_xo[4] = { 0, 0, 0, 44 };        // should all be even values for edge overlay

int vid_get_viewport_yoffset() {
/*    int m = mode_get();
    int aspect_ratio=shooting_get_prop(PROPCASE_ASPECT_RATIO);

    if ((m & MODE_MASK) != MODE_PLAY) {
        return (vp_xo[aspect_ratio]);
    }
    else
        return 0;
*/
return 0;
}


int vid_get_viewport_display_xoffset() {
/*
    int m = mode_get();
    int aspect_ratio=shooting_get_prop(PROPCASE_ASPECT_RATIO);

    if ((m & MODE_MASK) != MODE_PLAY) {
        return (vp_xo[aspect_ratio]);
    }
    else
        return 0;
*/
    return 0;
}

int vid_get_viewport_display_yoffset() {
    return 0;
}


//extern int active_bitmap_buffer;
//int active_bitmap_buffer = 0;
//extern char* bitmap_buffer[];

void *vid_get_bitmap_fb() {
    return (void *)0x41441000; //  from sub_fc0f8804, alt 4153e200
}

// TODO
// Functions for PTP Live View system
int vid_get_viewport_display_xoffset_proper()   { return vid_get_viewport_display_xoffset() * 2; }
int vid_get_viewport_display_yoffset_proper()   { return vid_get_viewport_display_yoffset() * 2; }
//int vid_get_viewport_width_proper()             { return 1280; }
//int vid_get_viewport_height_proper()            { return 640; }
int vid_get_viewport_width_proper()             { return vid_get_viewport_width() * 2; }
int vid_get_viewport_height_proper()            { return vid_get_viewport_height() * 2; }
int vid_get_viewport_fullscreen_height()        { return 480; }
int vid_get_palette_type()                      { return 3; }
int vid_get_palette_size()                      { return 256 * 4; }
/*
void *vid_get_bitmap_active_buffer() {
    return bitmap_buffer[active_bitmap_buffer&1];
}
*/
// the opacity buffer defines opacity for the bitmap overlay's pixels
// found near BmpDDev.c line 215 assert fc0f7b58
volatile char *opacity_buffer[2] = {(char*)0x4163b400, (void*)0x416b9d00};
//volatile char *opacity_buffer[2] = {(char *)0xDEADBEEF, (void*)0xDEADBEEF};

void *vid_get_bitmap_active_palette() {
    return (void*)0x8000; // just to return something valid, no palette needed on this cam
}
char *camera_jpeg_count_str()
{
    extern char jpeg_count_str[];
        return jpeg_count_str;
}

