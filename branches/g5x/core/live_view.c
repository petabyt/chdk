#include "camera_info.h"
#include "stdlib.h"
#include "conf.h"
#include "viewport.h"
#include "ptp_chdk.h"
#include "live_view.h"

// Live View implementation for all cameras using YUV or 8bpp palette based bitmap buffer
// Viewport = YUV buffer
// Bitmap = 8bpp buffer or YUV buffer (Digic6)
// Palette = Color table (Non Digic 6)

typedef struct
{
    lv_data_header      lv;
    lv_framebuffer_desc vp;
    lv_framebuffer_desc bm;
#ifdef THUMB_FW
    lv_framebuffer_desc bmo;
#endif
} lv_hdr;

/*
send selected data for live view
returns 0 on error, total size on success
should only be called from ptp handler
*/
int live_view_get_data(ptp_data *data, int flags)
{
    int buf_size = sizeof(lv_hdr);

    lv_hdr lv;
    memset(&lv, 0, buf_size);

    // Header
    lv.lv.version_major = LIVE_VIEW_VERSION_MAJOR;
    lv.lv.version_minor = LIVE_VIEW_VERSION_MINOR;

    lv.lv.lcd_aspect_ratio = vid_get_aspect_ratio();

    lv.lv.vp_desc_start = sizeof(lv_data_header);
    lv.lv.bm_desc_start = lv.lv.vp_desc_start+sizeof(lv_framebuffer_desc);
#ifdef THUMB_FW
    lv.lv.bmo_desc_start = lv.lv.bm_desc_start+sizeof(lv_framebuffer_desc);
#endif

    // Viewport
    lv.vp.fb_type = vid_get_viewport_type();

    lv.vp.buffer_width = vid_get_viewport_buffer_width_proper();

    lv.vp.visible_width = vid_get_viewport_width_proper();
    lv.vp.visible_height = vid_get_viewport_height_proper();

    lv.vp.margin_left = vid_get_viewport_display_xoffset_proper();
    lv.vp.margin_top = vid_get_viewport_display_yoffset_proper();

    // TODO returning margins from lib.c might be better
    // can end up with negative if size and offset sources don't update at exactly the same time
    lv.vp.margin_right = vid_get_viewport_fullscreen_width() - lv.vp.visible_width - lv.vp.margin_left;
    lv.vp.margin_bot = vid_get_viewport_fullscreen_height() - lv.vp.visible_height - lv.vp.margin_top;

    // Bitmap
    // TODO maybe should be function like viewport
#ifdef THUMB_FW
    lv.bm.fb_type = LV_FB_YUV8B;
#else
    lv.bm.fb_type = LV_FB_PAL8;
#endif
    lv.bm.buffer_width = camera_screen.buffer_width;

    lv.bm.visible_width = camera_screen.physical_width;
    lv.bm.visible_height = camera_screen.height;

#ifdef THUMB_FW
    // Bitmap opacity
    lv.bmo.fb_type = LV_FB_OPACITY8;
    lv.bmo.buffer_width = lv.bm.buffer_width;

    lv.bmo.visible_width = lv.bm.visible_width;
    lv.bmo.visible_height = lv.bm.visible_height;
#endif

    // Calc sizes and get buffer pointers
    int total_size = buf_size;

#ifndef THUMB_FW
    int pal_size = 0;
    // determine if we will send palette so it can go in one send
    if ( flags & LV_TFR_PALETTE ) // bitmap palette
    {
        // if no palette, will be set to zero
        pal_size = vid_get_palette_size();
        if (pal_size)
        {
            lv.lv.palette_type = vid_get_palette_type();
            lv.lv.palette_data_start = total_size;
            total_size += pal_size;
        }
    }
#endif

    int vp_size = 0;
    void *vp_fb = vid_get_viewport_active_buffer();
    // Add viewport details if requested, and not null
    if ( (flags & LV_TFR_VIEWPORT) && vp_fb) // live buffer
    {
        lv.vp.data_start = total_size;
        vp_size = (lv.vp.buffer_width*lv.vp.visible_height*6)/4;
        total_size += vp_size;
        // offset to start of actual data
        vp_fb += vid_get_viewport_image_offset();
    }

    int bm_size = 0;
    // Add bitmap details if requested
    if ( flags & LV_TFR_BITMAP ) // bitmap buffer
    {
        lv.bm.data_start = total_size;
        bm_size = lv.bm.buffer_width*lv.bm.visible_height;
        total_size += bm_size;
    }

#ifdef THUMB_FW
    int bmo_size = 0;
    // Add bitmap opacity if thumb2 and request
    if ( flags & LV_TFR_BITMAP_OPACITY ) // bitmap opacity buffer
    {
        lv.bmo.data_start = total_size;
        bmo_size = lv.bmo.buffer_width*lv.bmo.visible_height;
        total_size += bmo_size;
    }
#endif

    // Send header structure (along with total size to be sent)
    data->send_data(data->handle,(char*)&lv,buf_size,total_size,0,0,0);

#ifndef THUMB_FW
    // Send palette data if requested
    if (pal_size)
    {
        data->send_data(data->handle,vid_get_bitmap_active_palette(),pal_size,0,0,0,0);
    }
#endif

    // Send viewport data if requested
    if ( vp_size )
    {
        data->send_data(data->handle,vp_fb,vp_size,0,0,0,0);
    }

    // Send bitmap data if requested
    if ( bm_size )
    {
        data->send_data(data->handle,vid_get_bitmap_active_buffer(),bm_size,0,0,0,0);
    }

#ifdef THUMB_FW
    // Send bitmap opacity data if requested
    if ( bmo_size )
    {
        data->send_data(data->handle,vid_get_opacity_active_buffer(),bmo_size,0,0,0,0);
    }
#endif

    return total_size;
}
