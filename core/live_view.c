#include "camera_info.h"
#include "stdlib.h"
#include "conf.h"
#include "viewport.h"
#include "ptp_chdk.h"
#include "live_view.h"

/*
send selected data for live view
returns 0 on error, total size on success
should only be called from ptp handler
*/
int live_view_get_data(ptp_data *data, int flags) {
    int vp_size = 0,bm_size = 0,bmo_size = 0,pal_size = 0;
    lv_data_header *lv;
    lv_framebuffer_desc *vp;
    lv_framebuffer_desc *bm;
    lv_framebuffer_desc *bmo;

    // determine if we will send palette so it can go in one send
    if ( flags & LV_TFR_PALETTE ) // bitmap palette
    {
        // if no palette, will be set to zero
        pal_size = vid_get_palette_size();
    }
    
    // one contiguous buffer to allow a single send call
    int buf_size = sizeof(lv_data_header) + sizeof(lv_framebuffer_desc)*3 + pal_size;
    void *buf = malloc(buf_size);
    if(!buf) {
        return 0;
    }
    lv = buf;

    lv->vp_desc_start = sizeof(lv_data_header);
    lv->bm_desc_start = lv->vp_desc_start+sizeof(lv_framebuffer_desc);
    lv->bmo_desc_start = lv->bm_desc_start+sizeof(lv_framebuffer_desc);

    vp = buf + lv->vp_desc_start;
    bm = buf + lv->bm_desc_start;
    bmo = buf + lv->bmo_desc_start;

    lv->version_major = LIVE_VIEW_VERSION_MAJOR;
    lv->version_minor = LIVE_VIEW_VERSION_MINOR;

    lv->lcd_aspect_ratio = vid_get_aspect_ratio();

    lv->palette_type = vid_get_palette_type();
    lv->palette_data_start = 0;

    vp->fb_type = vid_get_viewport_type();

    vp->buffer_width = vid_get_viewport_buffer_width_proper();

    vp->visible_width = vid_get_viewport_width_proper();
    vp->visible_height = vid_get_viewport_height_proper();

    vp->margin_left = vid_get_viewport_display_xoffset_proper();
    vp->margin_top = vid_get_viewport_display_yoffset_proper();

    // TODO returning margins from lib.c might be better
    // can end up with negative if size and offset sources don't update at exactly the same time
    vp->margin_right = vid_get_viewport_fullscreen_width() - vp->visible_width - vp->margin_left;
    vp->margin_bot = vid_get_viewport_fullscreen_height() - vp->visible_height - vp->margin_top;

// TODO maybe should be function like viewport
#ifndef THUMB_FW
    bm->fb_type = LV_FB_PAL8;
#else
    bm->fb_type = LV_FB_YUV8B;
#endif
    bm->buffer_width = camera_screen.buffer_width;

    bm->margin_left = 0;
    bm->margin_top = 0;
    bm->margin_right = 0;
    bm->margin_bot = 0;

    bm->visible_width = camera_screen.physical_width;
    bm->visible_height = camera_screen.height;

// type is always set to OPACITY8 even if camera doesn't have, we won't have a "none" define.
    bmo->fb_type = LV_FB_OPACITY8;
// for pre-d6, all values set to 0
#ifndef THUMB_FW
    bmo->buffer_width = 0;

    bmo->margin_left = 0;
    bmo->margin_top = 0;
    bmo->margin_right = 0;
    bmo->margin_bot = 0;

    bmo->visible_width = 0;
    bmo->visible_height = 0;
#else
// TODO for now assume opacity buffer is same size as bm
    bmo->buffer_width = camera_screen.buffer_width;

    bmo->margin_left = 0;
    bmo->margin_top = 0;
    bmo->margin_right = 0;
    bmo->margin_bot = 0;

    bmo->visible_width = camera_screen.physical_width;
    bmo->visible_height = camera_screen.height;
#endif

    vp->data_start = 0;
    bm->data_start = 0;
    bmo->data_start = 0;

    int total_size = buf_size;

    void *vp_fb = vid_get_viewport_active_buffer();
    // Add viewport details if requested, and not null
    if ( flags & LV_TFR_VIEWPORT && vp_fb) // live buffer
    {
        vp->data_start = total_size;
#ifndef THUMB_FW
        vp_size = (vp->buffer_width*vp->visible_height*6)/4;
#else
        vp_size = (vp->buffer_width*vp->visible_height*4)/2;
#endif
        total_size += vp_size;
        // offset to start of actual data
        vp_fb += vid_get_viewport_image_offset();
    }

    // Add bitmap details if requested
    if ( flags & LV_TFR_BITMAP ) // bitmap buffer
    {
        bm->data_start = total_size;
#ifndef THUMB_FW
        bm_size = bm->buffer_width*bm->visible_height;
#else
        bm_size = (bm->buffer_width*bm->visible_height*4)/2;
#endif
        total_size += bm_size;
    }
 
    // Add bitmap opacity if thumb2 and request
#ifdef THUMB_FW
    if ( flags & LV_TFR_BITMAP_OPACITY ) // bitmap opacity buffer
    {
        bmo->data_start = total_size;
        bmo_size = bmo->buffer_width*bmo->visible_height;
        total_size += bmo_size;
    }
#endif

    // Add palette detals if requested and available
    if ( pal_size ) // bitmap palette
    {
        lv->palette_data_start = buf_size - pal_size;
        memcpy(buf + lv->palette_data_start,vid_get_bitmap_active_palette(),pal_size);
    }

    // Send header structure (along with total size to be sent)
    data->send_data(data->handle,(char*)buf,buf_size,total_size,0,0,0);

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

    // Send bitmap opacity data if requested
#ifdef THUMB_FW
    if ( bmo_size )
    {
        data->send_data(data->handle,vid_get_opacity_active_buffer(),bmo_size,0,0,0,0);
    }
#endif

    free(buf);
    return total_size;
}
