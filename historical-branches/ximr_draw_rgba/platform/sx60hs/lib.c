#include "platform.h"
#include "lolevel.h"
#include "live_view.h"

extern int displaytype;
extern void _LogCameraEvent(int id, const char *fmt,...);
extern int active_bitmap_buffer;
extern void* bitmap_buffer[];
extern char* raw_buffers_canon_raw[];
extern char* raw_buffers_jpeg[];

void vid_bitmap_refresh() {
    extern void _transfer_src_overlay(int);
    int n = active_bitmap_buffer;
    _transfer_src_overlay(n);
    _transfer_src_overlay(n^1);
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
void camera_set_led(int led, int state, __attribute__ ((unused))int bright) {
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
//     int aspect_ratio=shooting_get_prop(PROPCASE_ASPECT_RATIO);

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

extern int displaytype;
#define hdmi_out ((displaytype == 6) || (displaytype == 7))

// Ximr layer
typedef struct {
    unsigned char   unk1[7];
    unsigned char   scale;
    unsigned int    unk2;
    unsigned short  color_type;
    unsigned short  visibility;
    unsigned short  unk3;
    unsigned short  src_y;
    unsigned short  src_x;
    unsigned short  src_h;
    unsigned short  src_w;
    unsigned short  dst_y;
    unsigned short  dst_x;
    unsigned short  enabled;
    unsigned int    marv_sig;
    unsigned int    bitmap;
    unsigned int    opacity;
    unsigned int    color;
    unsigned int    width;
    unsigned int    height;
    unsigned int    unk4;
} ximr_layer;

// Ximr context
typedef struct {
    unsigned short  unk1;
    unsigned short  width1;
    unsigned short  height1;
    unsigned short  unk2[17];
    unsigned int    output_marv_sig;
    unsigned int    output_buf;
    unsigned int    output_opacitybuf;
    unsigned int    output_color;
    int             buffer_width;
    int             buffer_height;
    unsigned int    unk3[2];
    ximr_layer      layers[8];
    unsigned int    unk4[24];
    unsigned char   denomx;
    unsigned char   numerx;
    unsigned char   denomy;
    unsigned char   numery;
    unsigned int    unk5;
    short           width;
    short           height;
    unsigned int    unk6[27];
} ximr_context;

int display_needs_refresh = 0;

extern unsigned int fw_yuv_layer_buf;
#define FW_YUV_LAYER_SIZE   (960*270*2)

// Max size required
#define CB_W    480
#define CB_H    270

unsigned char* chdk_rgba = NULL;
int chdk_rgba_init = 0;
int bm_w = CB_W;
int bm_h = CB_H;

void vid_bitmap_erase()
{
    extern void _bzero(unsigned char *s, int n);
    _bzero(chdk_rgba, CB_W * bm_h * 4);
}

int last_displaytype;

/*
 * Called when Canon is updating UI, via mzrm_sendmsg log patch.
 * Sets flag for CHDK to update it's UI.
 * Also needed because bitmap buffer resolution changes when using HDMI
 * LCD = 720 x 480
 * HDMI = 960 x 540
 * TODO: This does not reset the OSD positions of things on screen
 *       If user has customised OSD layout how should this be handled?
 */
void update_ui(ximr_context* ximr)
{
    // Init RGBA buffer
    if (chdk_rgba_init == 0)
    {
        chdk_rgba = (unsigned char*)(fw_yuv_layer_buf + FW_YUV_LAYER_SIZE);
        chdk_rgba_init = 1;
        vid_bitmap_erase();
        // Force update
        last_displaytype = -1;
    }

    // Make sure we are updating the correct layer - skip redundant updates for HDMI out
    if (ximr->output_buf != fw_yuv_layer_buf)
    {
        // Update screen dimensions
        if (last_displaytype != displaytype)
        {
            last_displaytype = displaytype;

            if (hdmi_out) {
                bm_w = 480;
                bm_h = 270;
            } else {
                bm_w = 360;
                bm_h = 240;
            }

            camera_screen.width = bm_w;
            camera_screen.height = bm_h;
            camera_screen.buffer_width = CB_W;
            camera_screen.buffer_height = bm_h;

            // Reset OSD offset and width
            camera_screen.disp_right = camera_screen.width - 1;
            camera_screen.disp_width = camera_screen.width;

            // Update other values
            camera_screen.physical_width = camera_screen.width;
            camera_screen.size = camera_screen.width * camera_screen.height;
            camera_screen.buffer_size = camera_screen.buffer_width * camera_screen.buffer_height;

            // Values for chdkptp live view
            camera_screen.yuvbm_width = ximr->width;
            camera_screen.yuvbm_height = ximr->height;
            camera_screen.yuvbm_buffer_width = ximr->buffer_width;
            camera_screen.yuvbm_buffer_size = camera_screen.yuvbm_buffer_width * camera_screen.yuvbm_height;

            // Clear buffer if size changed
            extern void gui_set_need_redraw();
            gui_set_need_redraw();
            vid_bitmap_erase();

            // Tell CHDK UI that display needs update
            display_needs_refresh = 1;
        }

        // g7x uses layer 0 in HDMI and layer 1 in TV out when rendering YUV buffer
        if (ximr->layers[1].bitmap == fw_yuv_layer_buf && ximr->layers[1].enabled) {
            ximr->layers[1].scale = 4;      // x2 scaling vertically for the canon yuv layer
        } else if (ximr->layers[0].bitmap == fw_yuv_layer_buf && ximr->layers[0].enabled) {
            ximr->layers[0].scale = 4;      // x2 scaling vertically for the canon yuv layer
        }

        if (chdk_rgba != 0)
        {
            // Copy canon RGB layer, assumed to be whichever of 0,1 is not the YUV layer
            if(ximr->layers[0].bitmap == fw_yuv_layer_buf && ximr->layers[0].enabled) {
                memcpy(&ximr->layers[3], &ximr->layers[1], sizeof(ximr_layer));
            } else {
                memcpy(&ximr->layers[3], &ximr->layers[0], sizeof(ximr_layer));
            }

            // Remove offset
            ximr->layers[3].scale = 6;      // x2 scaling in both directions
            ximr->layers[3].src_w = bm_w;
            ximr->layers[3].src_h = bm_h;
            ximr->layers[3].dst_x = 0;
            ximr->layers[3].dst_y = 0;

            // Set our buffer
            ximr->layers[3].bitmap = (unsigned int)chdk_rgba;
            ximr->layers[3].width = CB_W;
            ximr->layers[3].height = bm_h;

            // Fix for video recording - https://chdk.setepontos.com/index.php?topic=12788.msg146378#msg146378
            ximr->unk2[0] = 0x500;
        }
    }
    else // rendering to fw_yuv_layer_buf for TV or HDMI out
    {
        // scale and crop to half height to preserve CHDK buffer
        ximr->height = ximr->buffer_height = 270;
        ximr->denomy = 0x6c;
    }
}
