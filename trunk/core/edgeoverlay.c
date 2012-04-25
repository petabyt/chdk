#include "platform.h"

#include "edgeoverlay.h"
#include "conf.h"
#include "keyboard.h"
#include "stdlib.h"
#include "gui_draw.h"
#include "gui_menu.h"
#include "gui_lang.h"
#include "bitvector.h"

#include "modules.h"
#include "module_exportlist.h"

//-------------------------------------------------------------------

typedef struct
{
    color edge_overlay_color;
    int edge_overlay_filter;
    int edge_overlay_zoom;    // shall zoom be set when *edg file is loaded?
    //int edge_overlay_pano;    // whether a full press changes back to live mode
    int edge_overlay_pano_overlap;    // overlap in % in pano mode
    int edge_overlay_show;    // whether to show overlay even when no button is pressed
    int edge_overlay_play;    // whether edge overlay is switched on also for play mode
} EdgeConf;

EdgeConf econf;

static ConfInfo conf_info[] = {
    CONF_INFO( 1, econf.edge_overlay_color,         CONF_DEF_VALUE, cl:0, NULL),
    CONF_INFO( 2, econf.edge_overlay_play,          CONF_DEF_VALUE, i:0, NULL),
    //CONF_INFO( 3, econf.edge_overlay_pano,           CONF_DEF_VALUE, i:0, NULL),
    CONF_INFO( 4, econf.edge_overlay_zoom,          CONF_DEF_VALUE, i:1, NULL),
	CONF_INFO( 5, econf.edge_overlay_filter,        CONF_DEF_VALUE, i:0, NULL),
	CONF_INFO( 6, econf.edge_overlay_show,          CONF_DEF_VALUE, i:0, NULL),
    CONF_INFO( 7, econf.edge_overlay_pano_overlap,  CONF_DEF_VALUE, i:30, NULL),
};

//-------------------------------------------------------------------

// the way we save edge overlays on their own...
#define EDGE_FILE_PREFIX "EDG_"
#define EDGE_FILE_FORMAT EDGE_FILE_PREFIX "%04d.edg"
#define EDGE_SLICES     2

typedef enum _edge_fsm_state
{
    EDGE_LIVE = 0,
    EDGE_FROZEN
} edge_fsm_state_t;

static edge_fsm_state_t fsm_state = EDGE_LIVE;
static bit_vector_t* edgebuf = NULL;
static int xoffset = 0, yoffset = 0;
static unsigned char* smbuf = NULL;

static int slice = 0;           // the current slice of the frame we are calculating/drawing
static int slice_height;        // the height of a single slice

static int viewport_byte_width; // width in bytes of one viewport line ??
static int viewport_yscale;     // Y multiplier (for cameras with 480 pixel high viewports)
static int viewport_height;     // height of visible / used area of viewport
static int viewport_width;      // width of visible / used area of viewport (in 3 byte units)
static int viewport_xoffset;	// used when image size != viewport size (e.g. wide screen image on 4:3 LCD)
static int viewport_yoffset;	// used when image size != viewport size (e.g. wide screen image on 4:3 LCD)

static void get_viewport_size()
{
    viewport_height = vid_get_viewport_height()-camera_screen.edge_hmargin*2; //don't trace bottom lines
    viewport_width = vid_get_viewport_width();
    viewport_byte_width = vid_get_viewport_byte_width();
    viewport_yscale = vid_get_viewport_yscale();

	viewport_xoffset = vid_get_viewport_display_xoffset();
	viewport_yoffset = vid_get_viewport_display_yoffset();

    slice_height = viewport_height / EDGE_SLICES;
}

static void ensure_allocate_imagebuffer()
{
    if (edgebuf == NULL)
    {
        edgebuf = bv_create(viewport_height * viewport_width, 1);
        if (edgebuf != NULL)
            memset(edgebuf->ptr, 0, edgebuf->ptrLen);
    }
    if (econf.edge_overlay_filter && (smbuf == NULL))
    {
        smbuf = (unsigned char*)malloc(viewport_byte_width*3);
        if (smbuf != NULL)
            memset(smbuf, 0, viewport_byte_width*3);
        else
        {
            // Disable filtering if we do not have enough memory for it
            econf.edge_overlay_filter = 0;
        }
    }
}

static void reset_edge_overlay()
{
    if (smbuf != NULL)
    {
        free(smbuf);
        smbuf = NULL;
    }

    if (edgebuf != NULL)
    {
        draw_restore();     // Refresh display to restore Canon OSD
        bv_free(edgebuf);
        edgebuf = NULL;
    }

    fsm_state = EDGE_LIVE;
    slice = 0;

    // Clean up state saved in core CHDK
    module_save_edge(edgebuf, fsm_state);
}

static int is_buffer_ready()
{
    if (edgebuf == NULL) return 0;
    if (edgebuf->ptr == NULL) return 0; // this should never happen, but it does not hurt to check
    return 1;
}

// scans a filename for the number of the edge detection file it contains
static int get_edge_file_num(const char* fn)
{
    int num = 0;
    if( strncmp(fn,EDGE_FILE_PREFIX,sizeof(EDGE_FILE_PREFIX)-1) == 0 )
    {
        // has the correct beginning at least, now try to read as a number...
        fn += sizeof(EDGE_FILE_PREFIX);
        while( *fn == '0' ) // skip leading 0s
        {
            ++fn;
        }
        while( isdigit(*fn) )
        {
            num *= 10;
            num += *fn - '0';
            ++fn;
        }
        // ignore anything else after it, that is like the ending etc.
    }
    return num;
}

// saves the actual active overlay data to a file.
void save_edge_overlay(void)
{

    char fn[64];
    char msg[64];
    FILE *fd;
    STD_DIR* d;
    int fnum = 0;
    int fr = 0;
    int zoom = 0;
    struct STD_dirent* de;
    static struct utimbuf t;
    // nothing to save? then dont save

    if( !is_buffer_ready() )
    {
        draw_string(0, 0, "No overlay to save.", conf.osd_color);
        return;
    }

    zoom = shooting_get_zoom();

    // first figure out the most appropriate filename to use
    d = safe_opendir(EDGE_SAVE_DIR);
    if( ! d )
    {
        return;
    }

    while( (de = safe_readdir(d)) )
    {
        fr = get_edge_file_num(de->d_name);
        if( fr > fnum )
        {
            fnum = fr;
        }
    }
    ++fnum; // the highest is set, we use the next one
    get_viewport_size();
    // open the right file
    sprintf(fn, EDGE_SAVE_DIR "/" EDGE_FILE_FORMAT, fnum );
    fd = fopen(fn, "wb");
    if(fd !=NULL)
    {
        // write the data
        fwrite(edgebuf->ptr,edgebuf->ptrLen,1,fd);
        fwrite(&zoom,sizeof(zoom),1,fd);
        fclose(fd);
        t.actime = t.modtime = time(NULL);
        utime(fn, &t);
        sprintf(msg, "Saved as %s",fn);
        draw_string(0, 0, msg, conf.osd_color);
    }
    safe_closedir(d);
}

// load the edge overlay from a file
void load_edge_overlay(const char* fn)
{
    FILE *fd;
    int zoom;

    get_viewport_size();
    ensure_allocate_imagebuffer( );
    fd = fopen(fn,"rb");
    if( fd != NULL )
    {
        int ret = fread(edgebuf->ptr,edgebuf->ptrLen,1,fd);
        int ret2 = fread (&zoom,sizeof(zoom),1,fd);
        fclose(fd);
        if( (ret == 1) && (ret2 == 1) )
        {
            fsm_state = EDGE_FROZEN;    // switch to "edge overlay frozen"-mode
            if (econf.edge_overlay_zoom)
            {
                shooting_set_zoom(zoom);
            }
        }
    }
}

static void average_filter_row(const unsigned char* ptrh1,  // previous row
                               unsigned char* smptr,        // write results here
                               int x, int x_max)
{
    const unsigned char* ptrh2 = ptrh1 + viewport_byte_width*viewport_yscale;  // current row
    const unsigned char* ptrh3 = ptrh2 + viewport_byte_width*viewport_yscale;  // next row

    for (; x<x_max; x+=6)
    {
        *(smptr + x + 1) = (*(ptrh1 + x - 1) +
                            *(ptrh1 + x + 1) +
                            *(ptrh1 + x + 3) +

                            *(ptrh2 + x - 1) +
                            *(ptrh2 + x + 1) +
                            *(ptrh2 + x + 3) +

                            *(ptrh3 + x - 1) +
                            *(ptrh3 + x + 1) +
                            *(ptrh3 + x + 3)) / 9u;

        *(smptr + x + 3) = (*(ptrh1 + x + 1) +
                            *(ptrh1 + x + 3) +
                            *(ptrh1 + x + 4) +

                            *(ptrh2 + x + 1) +
                            *(ptrh2 + x + 3) +
                            *(ptrh2 + x + 4) +

                            *(ptrh3 + x + 1) +
                            *(ptrh3 + x + 3) +
                            *(ptrh3 + x + 4)) / 9u;

        *(smptr + x + 4) = (*(ptrh1 + x + 3) +
                            *(ptrh1 + x + 4) +
                            *(ptrh1 + x + 5) +

                            *(ptrh2 + x + 3) +
                            *(ptrh2 + x + 4) +
                            *(ptrh2 + x + 5) +

                            *(ptrh3 + x + 3) +
                            *(ptrh3 + x + 4) +
                            *(ptrh3 + x + 5)) / 9u;

        *(smptr + x + 5) = (*(ptrh1 + x + 4) +
                            *(ptrh1 + x + 5) +
                            *(ptrh1 + x + 7) +

                            *(ptrh2 + x + 4) +
                            *(ptrh2 + x + 5) +
                            *(ptrh2 + x + 7) +

                            *(ptrh3 + x + 4) +
                            *(ptrh3 + x + 5) +
                            *(ptrh3 + x + 7)) / 9u;
    }

    // copy 2nd last column to last column to prevent vertical stripe artifact.
    smptr[x+1] = smptr[x-5];
    smptr[x+3] = smptr[x-3];
    smptr[x+4] = smptr[x-2];
    smptr[x+5] = smptr[x-1];
}

// Sobel edge detector
static int calc_edge_overlay()
{
    int shutter_fullpress = kbd_is_key_pressed(KEY_SHOOT_FULL);

    const int bPlayMode = (mode_get() & MODE_MASK) == MODE_PLAY;
    const unsigned char* img = bPlayMode ? vid_get_viewport_fb_d() :  vid_get_viewport_fb();
    const unsigned char*  ptrh1 = NULL;    // previous pixel line
    const unsigned char*  ptrh2 = NULL;    // current pixel line
    const unsigned char*  ptrh3 = NULL;    // next pixel line
    unsigned char*  smptr = NULL;    // pointer to line in smbuf
    int x, y, xdiv3;
    int conv1, conv2;

    const int y_min = camera_screen.edge_hmargin+ slice   *slice_height;
    const int y_max = camera_screen.edge_hmargin+(slice+1)*slice_height;
    const int x_min = 6;
    const int x_max = (viewport_width - 2) * 3;

    img += vid_get_viewport_image_offset();		// offset into viewport for when image size != viewport size (e.g. 16:9 image on 4:3 LCD)

    xoffset = 0;
    yoffset = 0;

    // Reserve buffers
    ensure_allocate_imagebuffer();
    if( !is_buffer_ready() ) return 0;

    // In every 6 bytes the Y of four pixels are described in the
    // viewport (UYVYYY format). For edge detection we only
    // consider the second in the current and the first
    // in the next pixel.

    // Clear all edges in the current slice
    int compressed_slice = edgebuf->ptrLen / EDGE_SLICES;
    memset(edgebuf->ptr + slice*compressed_slice, 0, compressed_slice);

    if (econf.edge_overlay_filter)
    {
        // Prefill smbuf with three lines of avergae-filtered data.
        // This looks much more complex then it actually is.
        // We really are just summing up nine pixels in a 3x3 box
        // and averaging the current pixel based on them. And
        // we do it 4 bytes at a time because of the UYVYYY format.
        for (y = -1; y <= 1; ++y)
        {
            shutter_fullpress |= kbd_is_key_pressed(KEY_SHOOT_FULL);

            ptrh1 = img + (y_min+y-1) * viewport_byte_width*viewport_yscale;
            smptr = smbuf + (y+1) * viewport_byte_width;

            average_filter_row(ptrh1, smptr, x_min, x_max);
        }
    }

    for (y = y_min; y < y_max; ++y)
    {
        shutter_fullpress |= kbd_is_key_pressed(KEY_SHOOT_FULL);

        if (econf.edge_overlay_filter)
        {
            // We need to shift up our smbuf one line,
            // and fill in the last line (which now empty)
            // with average-filtered data from img.
            // By storing only three lines of smoothed picture
            // in memory, we save memory.

            // Shift
            memcpy(smbuf, smbuf+viewport_byte_width, viewport_byte_width*2);

            // Filter new line
            ptrh1 = img + y * viewport_byte_width*viewport_yscale;
            smptr = smbuf + 2 * viewport_byte_width;
            average_filter_row(ptrh1, smptr, x_min, x_max);

            ptrh1 = smbuf;
        }
        else
        {
            ptrh1 = img + (y-1) * viewport_byte_width*viewport_yscale;
        }
        ptrh2 = ptrh1 + viewport_byte_width*viewport_yscale;
        ptrh3 = ptrh2 + viewport_byte_width*viewport_yscale;

        // Now we do sobel on the current line

        for (x = x_min, xdiv3 = x_min/3; x < x_max; x += 6, xdiv3 += 2)
        {
            // convolve vert (second Y)
            conv1 = *(ptrh1 + x + 1) * ( 1) +
                    *(ptrh1 + x + 4) * (-1) +

                    *(ptrh2 + x + 1) * ( 2) +
                    *(ptrh2 + x + 4) * (-2) +

                    *(ptrh3 + x + 1) * ( 1) +
                    *(ptrh3 + x + 4) * (-1);
            if  (conv1 < 0)     // abs()
                conv1 = -conv1;

            // convolve vert (first Y of next pixel)
            conv2 = *(ptrh1 + x + 1) * ( 1) +
                    *(ptrh1 + x + 3) * ( 2) +
                    *(ptrh1 + x + 4) * ( 1) +

                    *(ptrh3 + x + 1) * (-1) +
                    *(ptrh3 + x + 3) * (-2) +
                    *(ptrh3 + x + 4) * (-1);
            if  (conv2 < 0)     // abs()
                conv2 = -conv2;

            if (conv1 + conv2 > conf.edge_overlay_thresh)
            {
                bv_set(edgebuf, (y-camera_screen.edge_hmargin)*viewport_width + xdiv3, 1);
            }

            // Do it once again for the next 'pixel'

            // convolve vert (second Y)
            conv1 = *(ptrh1 + x + 5) * ( 1) +
                    *(ptrh1 + x + 9) * (-1) +

                    *(ptrh2 + x + 5) * ( 2) +
                    *(ptrh2 + x + 9) * (-2) +

                    *(ptrh3 + x + 5) * ( 1) +
                    *(ptrh3 + x + 9) * (-1);
            if  (conv1 < 0)     // abs()
                conv1 = -conv1;

            // convolve vert (first Y of next pixel)
            conv2 = *(ptrh1 + x + 5) * ( 1) +
                    *(ptrh1 + x + 7) * ( 2) +
                    *(ptrh1 + x + 9) * ( 1) +

                    *(ptrh3 + x + 5) * (-1) +
                    *(ptrh3 + x + 7) * (-2) +
                    *(ptrh3 + x + 9) * (-1);
            if  (conv2 < 0)     // abs()
                conv2 = -conv2;

            if (conv1 + conv2 > conf.edge_overlay_thresh)
            {
                bv_set(edgebuf, (y-camera_screen.edge_hmargin)*viewport_width + xdiv3+1, 1);
            }
        }   // for x
    }   // for y


//  For an even more improved edge overlay, enabling the following lines will
//  post-filter the results of the edge detection, removing false edge 'dots'
//  from the display. However, the speed hit is large. In the developer's opinion
//  this code is not needed, but if you want that additional quality and do not
//  care so much about performance, you can enable it.
//
//    if (econf.edge_overlay_filter)
//    {
//        // Here we do basic filtering on the detected edges.
//        // If a pixel is marked as edge but just a few of its
//        // neighbors are also edges, then we assume that the
//        // current pixel is just noise and delete the mark.
//
//        bit_vector_t* bv_tmp = bv_create(edgebuf->nElem, edgebuf->nBits);
//        if (bv_tmp != NULL)
//        {
//            memset(bv_tmp->ptr, 0, bv_tmp->ptrLen);
//
//            for (y = 1; y < viewport_height-1; ++y)
//            {
//                shutter_fullpress |= kbd_is_key_pressed(KEY_SHOOT_FULL);
//
//                for (x=12; x<(viewport_width - 4); ++x)
//                {
//                    int bEdge = bv_get(edgebuf, y*viewport_width + x);
//                    if (bEdge)
//                    {
//                        // Count the number of neighbor edges
//                        int sum =
//                            bv_get(edgebuf, (y-1)*viewport_width + (x-1)) +
//                            bv_get(edgebuf, (y-1)*viewport_width + (x)) +
//                            bv_get(edgebuf, (y-1)*viewport_width + (x+1)) +
//
//                            bv_get(edgebuf, (y)*viewport_width + (x-1)) +
////              bv_get(&edgebuf, (y)*viewport_width + (x)) + //  we only inspect the neighbors
//                            bv_get(edgebuf, (y)*viewport_width + (x+1)) +
//
//                            bv_get(edgebuf, (y+1)*viewport_width + (x-1)) +
//                            bv_get(edgebuf, (y+1)*viewport_width + (x)) +
//                            bv_get(edgebuf, (y+1)*viewport_width + (x+1));
//
//                        if (!econf.edge_overlay_show)
//                        {
//                            if (sum >= 5)    // if we have at least 5 neighboring edges
//                                bv_set(bv_tmp, y*viewport_width + x, 1);   // keep the edge
//                            // else
//                            // there is no need to delete because the buffer is already zeroed
//                        }
//                    }
//                }   // for x
//            }   // for y
//
//            // Swap the filtered edge buffer for the real one
//            bit_vector_t* swap_tmp = edgebuf;
//            edgebuf = bv_tmp;
//            bv_free(swap_tmp);
//        }   // NULL-check
//    }   // if filtering

    return shutter_fullpress;
}

static int draw_edge_overlay()
{
    int shutter_fullpress = kbd_is_key_pressed(KEY_SHOOT_FULL);

    int x, y;
    int x_off, y_off;

    const color cl = econf.edge_overlay_color;
    const int y_slice_min = camera_screen.edge_hmargin+ slice   *slice_height;
    const int y_slice_max = camera_screen.edge_hmargin+(slice+1)*slice_height;
    const int y_min = camera_screen.edge_hmargin;
    const int y_max = camera_screen.edge_hmargin+viewport_height;
    const int x_min = 2;
    const int x_max = (viewport_width - 2);

    if( !is_buffer_ready() ) return 0;

    for (y = y_slice_min; y < y_slice_max; ++y)
    {
        y_off = y + yoffset;
        
        shutter_fullpress |= kbd_is_key_pressed(KEY_SHOOT_FULL);

        if ((unsigned)(y_off-y_min) < (y_max-y_min)) // is the same as ((y_off > y_min) && (y_off < y_max)) // do not draw outside of allowed area
        {
            const int y_edgebuf = (y-y_min) * viewport_width;

            for (x = x_min; x < x_max; ++x)
            {
                x_off = x + xoffset;

                if ((unsigned)(x_off-x_min) < (x_max-x_min)) // is the same as  ((x_off > x_min) && (x_off < x_max)) // do not draw outside of allowed area
                {
                    // Draw a pixel to the screen wherever we detected an edge.
                    // If there is no edge based on the newest data, but there is one painted on the screen
                    // from previous calls, delete it from the screen.
                    const int bEdge = bv_get(edgebuf, y_edgebuf + x);
                    const int bDraw = bEdge || (draw_get_pixel(x_off+viewport_xoffset, y_off+viewport_yoffset) == econf.edge_overlay_color);
                    const color cl = bEdge ? econf.edge_overlay_color : 0;
                    if (bEdge || bDraw)
                        draw_pixel(x_off+viewport_xoffset, y_off+viewport_yoffset, cl);
                    
                }
            }   // for x
        }
    }   // for y


    // Drawing the overlay is over.
    // But as a finishing touch we clear up garbage on the screen
    // by clearing those parts that the overlay has left.

    if (xoffset != 0)
    {
        // Cleans up leftover from horizontal motion

        const int x_min_c = (xoffset < 0) ? x_max + xoffset : x_min;
        const int x_max_c = (xoffset > 0) ? x_min + xoffset : x_max;

        for (y = y_min; y < y_max; ++y)
        {
            for (x = x_min_c; x < x_max_c; ++x)
            {
                // if there is an edge drawn on the screen but there is no edge there based on the newest data, delete it from the screen
                if (draw_get_pixel(x+viewport_xoffset, y+viewport_yoffset) == cl)
                    draw_pixel(x+viewport_xoffset, y+viewport_yoffset, 0 );
            }
        }
    }

    if (yoffset != 0)
    {
        // Cleans up leftover from vertical motion

        const int y_min_c = (yoffset < 0) ? y_max + yoffset : y_min;
        const int y_max_c = (yoffset > 0) ? y_min + yoffset : y_max;

        for (y = y_min_c; y < y_max_c; ++y)
        {
            for (x = x_min; x < x_max; ++x)
            {
                // if there is an edge drawn on the screen but there is no edge there based on the newest data, delete it from the screen
                if (draw_get_pixel(x+viewport_xoffset, y+viewport_yoffset) == cl)
                    draw_pixel(x+viewport_xoffset, y+viewport_yoffset, 0 );
            }
        }
    }

    return shutter_fullpress;
}

static void set_offset_from_overlap()
{
    const int y_max = viewport_height;
    const int x_max = (viewport_width - 2);

    switch(conf.edge_overlay_pano)
    {
    case 0:     // pano off
        xoffset = 0;
        yoffset = 0;
        break;
    case 1:     // pano from left to right
        xoffset = -x_max*(100-econf.edge_overlay_pano_overlap)/100;
        break;
    case 2:     // pano from top to bottom
        yoffset = -y_max*(100-econf.edge_overlay_pano_overlap)/100;
        break;
    case 3:     // pano from right to left
        xoffset = x_max*(100-econf.edge_overlay_pano_overlap)/100;
        break;
    case 4:     // pano from bottom to top
        yoffset = y_max*(100-econf.edge_overlay_pano_overlap)/100;
        break;
    case 5:     // free mode
    default:
        // free mode: change position with "ALT" and cursor
        // nothing to do here.
        break;
    }
}


// Main edge overlay function.
// It works by detecting edges using the Sobel operator
// (calc_edgeoverlay()), the detected edges are then stored into an
// array of 1-bit elements. A set bit indicates that there is an
// edge and that it should be drawn onto the overlay.
// When needed, the 1-bit edge buffer is drawn onto the screen
// (dynamically decompressing it) using draw_edge_overlay().
void edge_overlay()
{
    // Was the shutter fully pressed the last time we ran?
    // We use this to make sure that the user has released
    // the button before processing the next FullPress event.
    // This prevents switching FSM states more than once
    // per press.
    static int bFullPress_prev = 0;

    // Have we already started taking pictures in panorama mode?
    // We use this variable to be able to detect if panorama
    // mode has been turned off.
    static int bPanoInProgress = 0;

    // Precalculate some values to make the rest of the
    // code easier to read.
    int bFullPress = kbd_is_key_pressed(KEY_SHOOT_FULL);
    const int bHalfPress = kbd_is_key_pressed(KEY_SHOOT_HALF);
    const int bPlayMode = (mode_get() & MODE_MASK) == MODE_PLAY;
    const int bPanoramaMode = (conf.edge_overlay_pano != 0);
    const int bNeedHalfPress = (econf.edge_overlay_show != 1);
    const int bDisplayInPlay = (econf.edge_overlay_play == 1);
    const int bGuiModeNone = (gui_get_mode() == GUI_MODE_NONE);
    const int bGuiModeAlt = (gui_get_mode() == GUI_MODE_ALT);
    const int bCanDisplay = (
                                (!bPlayMode && (bHalfPress || !bNeedHalfPress)) ||   // we have a HalfPress in rec-mode
                                ( bPlayMode && bDisplayInPlay)  // or we are in play-mode with the right settings
                            );

    if (bPanoInProgress && !bPanoramaMode)
    {
        // This means panorama mode has been recently
        // turned off in the menu. So let's release
        // Frozen mode for the user.
        reset_edge_overlay();
        bPanoInProgress = 0;
    }

    get_viewport_size();

    // For just two states a state machine is not actually needed.
    // But it is scalable in the future in case anybody
    // wants to extend the functionality of edge overlay.
    switch (fsm_state)
    {
    case EDGE_LIVE:
    {
        edge_state_draw=0;
        // In this state we assume no edge overlay in memory,
        // but we are ready to create one if the user presses wishes so.

        int bRealtimeUpdate = bCanDisplay && (bGuiModeAlt || bGuiModeNone);
        if (bRealtimeUpdate)
        {
            // We try to detect button presses during the lengthy
            // calculations.
            bFullPress |= calc_edge_overlay();
            bFullPress |= draw_edge_overlay();
        }

        int bSwitch2Frozen = bFullPress && !bFullPress_prev && bGuiModeNone;
        if (bSwitch2Frozen)
        {
            // Switch to Frozen mode

            // Make sure we have one whole consistent frame
            for (slice = 0; slice < EDGE_SLICES; ++slice)
                calc_edge_overlay();

            set_offset_from_overlap();
            fsm_state = EDGE_FROZEN;
            bPanoInProgress = bPanoramaMode;
        }

        if (!bRealtimeUpdate && !bSwitch2Frozen)
        {
            // Nothing happens. So do nothing.
            // Or rather, we could clean up if we are that bored.
            reset_edge_overlay();
        }
        break;
    }
    case EDGE_FROZEN:
    {
        edge_state_draw=1;
        // We have a stored edge overlay in memory and we display
        // it on screen in 'frozen' mode.

        // Move edge overlay around.
        if (gui_get_mode() == GUI_MODE_ALT)
        {
            if (kbd_is_key_pressed(KEY_RIGHT))
                xoffset +=XINC;
            if (kbd_is_key_pressed(KEY_LEFT))
                xoffset -=XINC;
            if (kbd_is_key_pressed(KEY_DOWN))
                yoffset +=YINC;
            if (kbd_is_key_pressed(KEY_UP))
                yoffset -=YINC;
        }

        if (bCanDisplay && (bGuiModeAlt || bGuiModeNone))
        {
            // We try to detect button presses during the lengthy
            // calculations.
            bFullPress |= draw_edge_overlay();
            //draw_string(0, 0, "Frozen", conf.osd_color);
        }

        // In event of a FullPress, we either capture a new
        // overlay and stay frozen, OR we go back to live mode.
        if (bFullPress && !bFullPress_prev && bGuiModeNone)
        {
            // Possible mode switch
            if (bPanoramaMode)
            {
                // Make sure we have one whole consistent frame
                for (slice = 0; slice < EDGE_SLICES; ++slice)
                    calc_edge_overlay();

                set_offset_from_overlap();
                bPanoInProgress = 1;
            }
            else
                fsm_state = EDGE_LIVE;
        }

        break;
    }   // case
    }   // switch


    bFullPress_prev = bFullPress;

    if (++slice >= EDGE_SLICES)
        slice = 0;

}   // function


//-------------------------------------------------------------------
static void gui_load_edge_selected( const char* fn ) {
    if (fn)
		load_edge_overlay(fn);
}

void gui_menuproc_edge_save(int arg) {
    save_edge_overlay();
}

void gui_menuproc_edge_load(int arg) {
    module_fselect_init(LANG_MENU_EDGE_LOAD, EDGE_SAVE_DIR, EDGE_SAVE_DIR, gui_load_edge_selected);
}

static const char* gui_edge_pano_modes[] = { "Off", "Right", "Down", "Left", "Up", "Free"};
static CMenuItem edge_overlay_submenu_items[] = {
    MENU_ITEM(0x5c,LANG_MENU_EDGE_OVERLAY_ENABLE,   MENUITEM_BOOL,              &conf.edge_overlay_enable, 0 ),
    MENU_ITEM(0x5c,LANG_MENU_EDGE_FILTER,           MENUITEM_BOOL,              &econf.edge_overlay_filter, 0 ),
    MENU_ENUM2(0x5f,LANG_MENU_EDGE_PANO,            &conf.edge_overlay_pano,    gui_edge_pano_modes ),
    MENU_ITEM(0x5e,LANG_MENU_EDGE_PANO_OVERLAP,     MENUITEM_INT|MENUITEM_F_UNSIGNED|MENUITEM_F_MINMAX, &econf.edge_overlay_pano_overlap, MENU_MINMAX(0, 100) ),
    MENU_ITEM(0x5c,LANG_MENU_EDGE_SHOW,             MENUITEM_BOOL,              &econf.edge_overlay_show, 0 ),
    MENU_ITEM(0x5e,LANG_MENU_EDGE_OVERLAY_TRESH,    MENUITEM_INT|MENUITEM_F_UNSIGNED|MENUITEM_F_MINMAX, &conf.edge_overlay_thresh, MENU_MINMAX(0, 255) ),
    MENU_ITEM(0x65,LANG_MENU_EDGE_OVERLAY_COLOR,    MENUITEM_COLOR_FG,          &econf.edge_overlay_color, 0 ),
    MENU_ITEM(0x5c,LANG_MENU_EDGE_PLAY,			    MENUITEM_BOOL,		        &econf.edge_overlay_play, 0 ), //does not work on cams like s-series, which dont have a real "hardware" play/rec switch, need a workaround, probably another button
    MENU_ITEM(0x33,LANG_MENU_EDGE_SAVE,			    MENUITEM_PROC,		        gui_menuproc_edge_save, 0 ),
    MENU_ITEM(0x5c,LANG_MENU_EDGE_ZOOM,             MENUITEM_BOOL,              &econf.edge_overlay_zoom, 0 ),
    MENU_ITEM(0x33,LANG_MENU_EDGE_LOAD,			    MENUITEM_PROC,		        gui_menuproc_edge_load, 0 ),
    MENU_ITEM(0x51,LANG_MENU_BACK,                  MENUITEM_UP, 0, 0 ),
    {0}
};
static CMenu edge_overlay_submenu = {0x7f,LANG_MENU_EDGE_OVERLAY_TITLE, NULL, edge_overlay_submenu_items };


// =========  MODULE INIT =================

#include "module_load.h"
int module_idx=-1;

/***************** BEGIN OF AUXILARY PART *********************
  ATTENTION: DO NOT REMOVE OR CHANGE SIGNATURES IN THIS SECTION
 **************************************************************/

struct libedgeovr_sym libedgeovr = {
			MAKE_API_VERSION(1,0),		// apiver: increase major if incompatible changes made in module, 
										// increase minor if compatible changes made(including extending this struct)

			edge_overlay,
		};


void* MODULE_EXPORT_LIST[] = {
	/* 0 */	(void*)EXPORTLIST_MAGIC_NUMBER,
	/* 1 */	(void*)1,

			&libedgeovr
		};


//---------------------------------------------------------
// PURPOSE:   Bind module symbols with chdk. 
//		Required function
// PARAMETERS: pointer to chdk list of export
// RETURN VALUE: 1 error, 0 ok
//---------------------------------------------------------
int _module_loader( unsigned int* chdk_export_list )
{
  if ( chdk_export_list[0] != EXPORTLIST_MAGIC_NUMBER )
     return 1;

  if ( !API_VERSION_MATCH_REQUIREMENT( camera_sensor.api_version, 1, 0 ) )
	 return 1;
  if ( !API_VERSION_MATCH_REQUIREMENT( conf.api_version, 2, 0 ) )
	 return 1;

  conf_info[0].cl = MAKE_COLOR(0, COLOR_BLUE);
  config_restore(&conf_info[0], "A/CHDK/MODULES/CFG/edgeovr.cfg", sizeof(conf_info)/sizeof(conf_info[0]), 0);

  module_restore_edge((void**)&edgebuf, (int*)&fsm_state);

  return 0;
}


//---------------------------------------------------------
// PURPOSE: Finalize module operations (close allocs, etc)
// RETURN VALUE: 0-ok, 1-fail
//---------------------------------------------------------
int _module_unloader()
{
    // Save state info
    module_save_edge(edgebuf, fsm_state);

    // Module can be unloaded when menu exits
    // Edge overlay state is store in core CHDK and will
    // be restored when module reloads
    config_save(&conf_info[0], "A/CHDK/MODULES/CFG/edgeovr.cfg", sizeof(conf_info)/sizeof(conf_info[0]));

    // Free filter buffer
    if (smbuf != NULL)
    {
        free(smbuf);
        smbuf = NULL;
    }

    return 0;
}


//---------------------------------------------------------
// PURPOSE: Default action for simple modules (direct run)
// NOTE: Please comment this function if no default action and this library module
//---------------------------------------------------------
int _module_run(int moduleidx, int argn, int* arguments)
{
  module_idx=moduleidx;

  gui_activate_sub_menu(&edge_overlay_submenu, module_idx);

  return 0;
}

/******************** Module Information structure ******************/

struct ModuleInfo _module_info = {	MODULEINFO_V1_MAGICNUM,
									sizeof(struct ModuleInfo),

									ANY_CHDK_BRANCH, 0,			// Requirements of CHDK version
									ANY_PLATFORM_ALLOWED,		// Specify platform dependency
									MODULEINFO_FLAG_SYSTEM,		// flag
									(int32_t)"Edge Overlay (dll)",// Module name
									1, 0,						// Module version
									(int32_t)"Implementation one of core modes"
								 };


/*************** END OF AUXILARY PART *******************/

