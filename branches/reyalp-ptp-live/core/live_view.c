#include "platform.h"
#include "conf.h"
#include "stdlib.h"
#include "ptp.h"
#include "core.h"
#include "live_view.h"

#ifdef CAM_CHDK_PTP

// PTP Live View functions

// Function used to send core live view info back to client
// this is data that does not change (including version info)
static int live_view_core_info(ptp_data *data)
{
    int total_size;             // Calculated total size of data to transfer to client

    // Structure to populate with live view info
    lv_base_info details;

    // Populate structure info
    details.version_major       = LIVE_VIEW_VERSION_MAJOR;
    details.version_minor       = LIVE_VIEW_VERSION_MINOR;
    details.vp_max_width        = vid_get_viewport_max_width();
    details.vp_max_height       = vid_get_viewport_max_height();
    details.vp_buffer_width     = vid_get_viewport_buffer_width_proper();
    /*
    details.bm_max_width        = ASPECT_XCORRECTION(vid_get_bitmap_screen_width());
    details.bm_max_height       = vid_get_bitmap_screen_height();
    details.bm_buffer_width     = vid_get_bitmap_buffer_width();
    */
    details.bm_max_width        = ASPECT_XCORRECTION(camera_screen.width);
    details.bm_max_height       = camera_screen.height;
    details.bm_buffer_width     = camera_screen.buffer_width;
    details.lcd_aspect_ratio    = vid_get_aspect_ratio();

    total_size = sizeof(details);

    // Send header structure (along with total size to be sent)
    data->send_data(data->handle,(char*)&details,sizeof(details),total_size,0,0,0);

    return total_size;
}

// Function used to get viewport, bitmap and palette data via PTP
// Address of this function sent back to client program which then
// calls this with options to determine what to transfer
int live_view_data_handler(ptp_data *data, int flags, int arg2)
{
    int total_size;             // Calculated total size of data to transfer to client

    if (flags & LV_TFR_CORE_DETAILS)
    {
        // Send base info including version
        return live_view_core_info(data);
    }

    // Structure containing the info for the current live view frame
    lv_vid_info vid_info;

    // Populate the above structure with the current default details
    vid_info.vp_xoffset = vid_get_viewport_xoffset_proper();
    vid_info.vp_yoffset = vid_get_viewport_yoffset_proper();
    vid_info.vp_width = vid_get_viewport_width_proper();
    vid_info.vp_height = vid_get_viewport_height_proper();
    vid_info.vp_buffer_start = 0;
    vid_info.vp_buffer_size = 0;
    vid_info.bm_buffer_start = 0;
    vid_info.bm_buffer_size = 0;
    vid_info.palette_type = vid_get_palette_type();
    vid_info.palette_buffer_start = 0;
    vid_info.palette_buffer_size = 0;

    total_size = sizeof(vid_info);

    void *vp = vid_get_viewport_active_buffer();
    // Add viewport details if requested, and not null
    if ( flags & LV_TFR_VIEWPORT && vp) // live buffer
    {
        vid_info.vp_buffer_start = total_size;
        // TODO viewport buffer height can vary, e.g. a540 in 640x480 video=528, normal 240
        // but shouldn't send max size when not in use
        vid_info.vp_buffer_size = (vid_get_viewport_buffer_width_proper()*vid_get_viewport_max_height()*6)/4;
        total_size += vid_info.vp_buffer_size;
    }

    // Add bitmap details if requested
    if ( flags & LV_TFR_BITMAP ) // bitmap buffer
    {
        vid_info.bm_buffer_start = total_size;
        //vid_info.bm_buffer_size = vid_get_bitmap_buffer_width()*vid_get_bitmap_screen_height();
        vid_info.bm_buffer_size = camera_screen.buffer_width*camera_screen.buffer_height;
        total_size += vid_info.bm_buffer_size;
    }

    // Add palette detals if requested and available
    if ( flags & LV_TFR_PALETTE  && vid_get_palette_size() ) // bitmap palette
    {
        vid_info.palette_buffer_start = total_size;
        vid_info.palette_buffer_size = vid_get_palette_size();
        total_size += vid_info.palette_buffer_size;
    }

    // Send header structure (along with total size to be sent)
    data->send_data(data->handle,(char*)&vid_info,sizeof(vid_info),total_size,0,0,0);

    // Send viewport data if requested
    if ( flags & LV_TFR_VIEWPORT && vp)
    {
        data->send_data(data->handle,vp,vid_info.vp_buffer_size,0,0,0,0);
    }

    // Send bitmap data if requested
    if ( flags & LV_TFR_BITMAP )
    {
        data->send_data(data->handle,vid_get_bitmap_active_buffer(),vid_info.bm_buffer_size,0,0,0,0);
    }

    // Send palette data if requested
    // don't try to send zero sized palette data, since palette type is theoretically variable,
    // doesn't make sense for clients to check before requesting
    if ( (flags & LV_TFR_PALETTE) && vid_get_palette_size() )
    {
        data->send_data(data->handle,vid_get_bitmap_active_palette(),vid_info.palette_buffer_size,0,0,0,0);
    }

    return total_size;
}

int live_view_get_data(ptp_data *data, int flags) {
    lv_data_header lv;
    lv.lcd_aspect_ratio    = vid_get_aspect_ratio();

    lv.vp.logical_width = vid_get_viewport_logical_width();
    lv.vp.logical_height = vid_get_viewport_logical_height();

    lv.vp.buffer_width = vid_get_viewport_buffer_width_proper();
    // TODO will go away, always the same as visible
    lv.vp.buffer_height = vid_get_viewport_height_proper();

    // TODO
    lv.vp.buffer_logical_xoffset = vid_get_viewport_display_xoffset_proper();
    lv.vp.buffer_logical_yoffset = vid_get_viewport_display_yoffset_proper();

    lv.vp.visible_width = vid_get_viewport_width_proper();
    lv.vp.visible_height = vid_get_viewport_height_proper();

    lv.bm.logical_width = ASPECT_XCORRECTION(camera_screen.width);
    lv.bm.logical_height = camera_screen.height;

    lv.bm.buffer_width = camera_screen.buffer_width;
    // TODO will go away
    lv.bm.buffer_height = camera_screen.height;

    lv.bm.buffer_logical_xoffset = 0;
    lv.bm.buffer_logical_yoffset = 0;

    lv.bm.visible_width = lv.bm.logical_width;
    lv.bm.visible_height = lv.bm.logical_height;

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
        bm_size = camera_screen.buffer_width*camera_screen.buffer_height;
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
