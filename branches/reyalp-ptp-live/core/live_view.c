#include "platform.h"
#include "conf.h"
#include "stdlib.h"
#include "ptp.h"
#include "core.h"
#include "live_view.h"

#ifdef CAM_CHDK_PTP

int live_view_get_data(ptp_data *data, int flags) {
    lv_data_header lv;
    lv.version_major = LIVE_VIEW_VERSION_MAJOR;
    lv.version_minor = LIVE_VIEW_VERSION_MINOR;

    lv.lcd_aspect_ratio = vid_get_aspect_ratio();

    lv.vp.buffer_width = vid_get_viewport_buffer_width_proper();

    lv.vp.visible_width = vid_get_viewport_width_proper();
    lv.vp.visible_height = vid_get_viewport_height_proper();

    lv.vp.margin_left = vid_get_viewport_display_xoffset_proper();
    lv.vp.margin_top = vid_get_viewport_display_yoffset_proper();

    // TODO returning margins from lib.c might be better
    // can end up with negative if size and offset sources don't update at exactly the same time
    lv.vp.margin_right = vid_get_viewport_fullscreen_width() - lv.vp.visible_width - lv.vp.margin_left;
    lv.vp.margin_bot = vid_get_viewport_fullscreen_height() - lv.vp.visible_height - lv.vp.margin_top;

    lv.bm.buffer_width = camera_screen.buffer_width;

    lv.bm.margin_left = 0;
    lv.bm.margin_top = 0;
    lv.bm.margin_right = 0;
    lv.bm.margin_bot = 0;

    lv.bm.visible_width = ASPECT_XCORRECTION(camera_screen.width);
    lv.bm.visible_height = camera_screen.height;

    lv.palette_type = vid_get_palette_type();

    lv.vp.data_start = 0;
    lv.bm.data_start = 0;
    lv.palette_data_start = 0;

    int total_size = sizeof(lv);
    int vp_size = 0,bm_size = 0,pal_size = 0;

    void *vp = vid_get_viewport_active_buffer();
    // Add viewport details if requested, and not null
    if ( flags & LV_TFR_VIEWPORT && vp) // live buffer
    {
        lv.vp.data_start = total_size;
        vp_size = (lv.vp.buffer_width*lv.vp.visible_height*6)/4;
        total_size += vp_size;
        // offset to start of actual data
        vp += vid_get_viewport_image_offset();
    }

    // Add bitmap details if requested
    if ( flags & LV_TFR_BITMAP ) // bitmap buffer
    {
        lv.bm.data_start = total_size;
        bm_size = lv.bm.buffer_width*lv.bm.visible_height;
        total_size += bm_size;
    }

    // Add palette detals if requested and available
    if ( flags & LV_TFR_PALETTE && vid_get_palette_size() ) // bitmap palette
    {
        lv.palette_data_start = total_size;
        total_size += vid_get_palette_size();
    }

    // Send header structure (along with total size to be sent)
    data->send_data(data->handle,(char*)&lv,sizeof(lv),total_size,0,0,0);

    // Send viewport data if requested
    if ( flags & LV_TFR_VIEWPORT && vp_size)
    {
        data->send_data(data->handle,vp,vp_size,0,0,0,0);
    }

    // Send bitmap data if requested
    if ( flags & LV_TFR_BITMAP )
    {
        data->send_data(data->handle,vid_get_bitmap_active_buffer(),bm_size,0,0,0,0);
    }

    // Send palette data if requested
    // don't try to send zero sized palette data, since palette type is theoretically variable,
    // doesn't make sense for clients to check before requesting
    if ( (flags & LV_TFR_PALETTE) && vid_get_palette_size() )
    {
        data->send_data(data->handle,vid_get_bitmap_active_palette(),vid_get_palette_size(),0,0,0,0);
    }

    return total_size;
}
#endif
