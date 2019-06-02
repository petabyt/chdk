#include "platform.h"
#include "lolevel.h"
#include "live_view.h"

static char* frame_buffer[2];

extern int displaytype;
extern void _LogCameraEvent(int id, const char *fmt,...);
extern int active_bitmap_buffer;
extern void* bitmap_buffer[];
extern char* raw_buffers_canon_raw[];
extern char* raw_buffers_jpeg[];

void vid_bitmap_refresh() {

    extern int active_bitmap_buffer;
    extern void _transfer_src_overlay(int);
    _transfer_src_overlay(0);
    _transfer_src_overlay(1);
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
extern  char*   current_raw_addr;
//extern  char*   raw_buffers[];
char *hook_raw_image_addr()
{
    if (current_raw_addr) {
         return current_raw_addr;
    }
// fall back to old code which will be wrong in many cases.....
    // observed values 0-2, 3 would index something that doesn't look like a raw fb in the jpeg case
    int i=active_raw_buffer&3;
/*
    _LogCameraEvent(0x20,"lc: hria: %i %i %08x %i",i, camera_info.state.mode_shooting,
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
      return raw_buffers_jpeg[(active_raw_buffer&1)];
}

char *hook_alt_raw_image_addr()
{
    return raw_buffers_jpeg[((active_raw_buffer&1)^1)];
}
*/





void *vid_get_viewport_fb() {
    return (void*)0x43334300; // same as g7x "first" viewport adr, "VRAM Address  : %p", contains d6 uyvy
// TODO sx280 values
    // Return first viewport buffer - for case when vid_get_viewport_live_fb not defined
    //return (void*)0x43115100; // uyvy buffers with signed(?) chroma components
    // return (void*)0x4b25fc00; // uyvy buffers (more than 4), pixel format compatible with earlier DIGIC uyvy
}

//void *vid_get_viewport_fb_d()    { return (void*)0x5e878000; } //by comparison with g7x
void *vid_get_viewport_fb_d()    { 
  extern void *current_fb_d;
  return current_fb_d;
 } 
//void *vid_get_viewport_fb_d()    { return (void*)0x43334300; } 
//void *vid_get_viewport_fb_d()    { return (void*)0x465ebb40; } 
/* live buffers the list is found at 0xfc5cf054 on 100f and at 0xfc5cf040 on 100b
  first at 0x43334000 
strangely these increment like the g7x (by 0xae800)  case which has higher rez
  640*2*480 = 0x96000 + 0x18800 ae800
 0x43334300
 0x433e2b00
 0x43491300
 0x4353fb00
*/
extern void* viewport_buffers[];
extern void *current_viewport_buffer;

void *vid_get_viewport_live_fb()
{
// current_viewport_buffer doesn't seem to be most recent
    int i;
    for(i=0;i<4;i++) {
        if(current_viewport_buffer == viewport_buffers[i]) {
            return viewport_buffers[(i+1)&3];
        }
    }
    return 0;
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
       return camera_screen.physical_width; 
//     return 360; //todo
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
/*
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
*/
       extern int _GetVRAMVPixelsSize();
// return half height
    if (camera_info.state.mode_play)
        return camera_screen.buffer_height;
    return _GetVRAMVPixelsSize();
}

// viewport width offset table for each aspect ratio
// 0 = 4:3, 1 = 16:9, 2 = 3:2, 3 = 1:1 4 = 4:5
static long vp_xo[5] = { 0, 0, 0, 80, 128 };// should all be even values for edge overlay
static long vp_yo[5] = {0, 60, 28, 0, 0};

int vid_get_viewport_yoffset() {
    int aspect_ratio=shooting_get_prop(PROPCASE_ASPECT_RATIO);

        return 0;
}


int vid_get_viewport_display_xoffset() {

    if (camera_info.state.mode_play) {
        return 0;
    }
    // video, ignore still res propcase
    if(camera_info.state.mode_video || is_video_recording()) {
            return 0; //all video modes for now
    }
    return vp_xo[shooting_get_prop(PROPCASE_ASPECT_RATIO)];

}

int vid_get_viewport_display_yoffset() {
    if (camera_info.state.mode_play) {
        return 0;
    }
    else {
        if(camera_info.state.mode_video || is_video_recording()) {
                return 0; //all video modes
        }
    } 
    return (vp_yo[shooting_get_prop(PROPCASE_ASPECT_RATIO)]);

}


//extern int active_bitmap_buffer;
//int active_bitmap_buffer = 0;
//extern char* bitmap_buffer[];

void *vid_get_bitmap_fb() {
//    return (void *)0x41441000; //  from sub_fc0f8804, alt 4153e200
      return bitmap_buffer[0];
}

// TODO
// Functions for PTP Live View system
int vid_get_viewport_display_xoffset_proper()   { return vid_get_viewport_display_xoffset() ; }
int vid_get_viewport_display_yoffset_proper()   { return vid_get_viewport_display_yoffset() ; }
int vid_get_viewport_byte_width() {
// digic 6 uYvY    2 pixels per 4 bytes
  return (640 * 2);
}
int vid_get_viewport_fullscreen_width()         { return camera_screen.width; }
int vid_get_viewport_fullscreen_height()        { return camera_screen.height; }
int vid_get_viewport_buffer_width_proper()      { return camera_screen.buffer_width; } // may not be always ok
int vid_get_viewport_type()                     { return LV_FB_YUV8B; }

void *vid_get_bitmap_active_buffer() {
    return bitmap_buffer[active_bitmap_buffer&1];
}

// the opacity buffer defines opacity for the bitmap overlay's pixels
// found near BmpDDev.c line 215 assert fc0f873c
volatile char *opacity_buffer[2] = {(char*)0x4163b400, (void*)0x416b9d00};
void *vid_get_opacity_active_buffer() {
    return (void *)opacity_buffer[active_bitmap_buffer&1];
}
// now in platform_palette.c
//void *vid_get_bitmap_active_palette() {
//    return (void*)0x8000; // just to return something valid, no palette needed on this cam
//}
char *camera_jpeg_count_str()
{
    extern char jpeg_count_str[];
        return jpeg_count_str;
}
#ifdef CAM_SUPPORT_BITMAP_RES_CHANGE
/*
 * needed because bitmap buffer resolutions change when an external display is used
 * an extra screen erase doesn't seem to be needed
 */
void update_screen_dimensions() {
    extern int displaytype;
    static int old_displaytype = -1;

    if (old_displaytype == displaytype) {
        return;
    }
 
    _LogCameraEvent(0x60,"lc: odt: %d dt: %d csw: %d csh: %d css: %d",
                old_displaytype, displaytype, camera_screen.width,
                 camera_screen.height, camera_screen.size);
    camera_screen.width = camera_screen.physical_width = camera_screen.buffer_width = 640;
    camera_screen.height = camera_screen.buffer_height = 480;
    camera_screen.size = camera_screen.buffer_size = 640*480;
    old_displaytype = displaytype;
    switch(displaytype) {
        case 0:
        case 3:
        case 4:
            // lcd
            camera_screen.width = camera_screen.physical_width = camera_screen.buffer_width = 640;
            camera_screen.height = camera_screen.buffer_height = 480;
            camera_screen.size = camera_screen.buffer_size = 640*480;
            break;
        case 5:
        case 1:
        case 2:
        case 8:
        case 9:
            // tv-out
            camera_screen.width = 720;
            camera_screen.physical_width = camera_screen.buffer_width = 736;
            camera_screen.height = camera_screen.buffer_height = 480;
            camera_screen.size = 720*480;
            camera_screen.buffer_size = 736*480;
            break;
        case 6:
            // hdmi
            camera_screen.width = camera_screen.physical_width = camera_screen.buffer_width = 960;
            camera_screen.height = camera_screen.buffer_height = 540;
            camera_screen.size = camera_screen.buffer_size = 960*540;
            break;
    }
}
#endif

