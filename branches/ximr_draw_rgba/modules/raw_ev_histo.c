#include "camera_info.h"
#include "conf.h"
#include "raw_ev_histo.h"
#include "raw.h"
#include "file_counter.h"
#include "gui.h"
#include "gui_draw.h"
#include "math.h"

//-----------------------------------------------------------------------------

int running = 0;

#define EV_MAX14  104   // Max # of slots for 14 bit cameras.

#define BH      31

int ev_max;
unsigned char* r2h = 0;
int last_black_level = -1;

// 1/9 stop histogram buckets + over and under exposed count
unsigned int histo[3][EV_MAX14];
unsigned int over_exposed[3], under_exposed[3];
// Scaled bar heights to fit drawn histogram
unsigned char histo_bar[3][EV_MAX14];
unsigned char under_bar[3], over_bar[3];
unsigned short under_pct[3], over_pct[3];
unsigned char ev_mark[EV_MAX14];
unsigned short ev_mark_cnt;
short ettr_hint[3];
unsigned int sample_count, histo_max;
int over_limit, under_limit;
int histo_ready = 0;
int histo_drawn = 0;

//-----------------------------------------------------------------------------

// enable or disable shot histogram
static void load_raw_ev_histo(int enable)
{
    // If turning histogram off, mark module as unloadable
    if (!enable)
        running = 0;
}

//-----------------------------------------------------------------------------

static void write_row(FILE *fd, char *c, int n)
{
    char fn[64];
    int i;

    sprintf(fn, "%s,%d.%0d,%d,", c, under_pct[n]/10, under_pct[n]%10, under_exposed[n]);
    fwrite(fn, strlen(fn), 1, fd);
    for (i=ev_max-1; i>=0; i--) {
        sprintf(fn, "%d,", histo[n][i]);
        fwrite(fn, strlen(fn), 1, fd);
    }
    sprintf(fn, "%d,%d.%d\n", over_exposed[n], over_pct[n]/10, over_pct[n]%10);
    fwrite(fn, strlen(fn), 1, fd);
}

static void raw_ev_write_to_file()
{
    char fn[64];

    FILE* fd = fopen("A/raw_ev_histo.csv", "a");
    if (fd)
    {
        sprintf(fn, "Image %04d\n", get_target_file_num());
        fwrite(fn, strlen(fn), 1, fd);
        write_row(fd, "R", 0);
        write_row(fd, "G", 1);
        write_row(fd, "B", 2);
        fclose(fd);
    }
}

//-----------------------------------------------------------------------------

int h;

// pow(2, n/9) for 0 <= n < 9
double pow2_inc[9] = {
    1.0,
    1.080059739,
    1.16652904,
    1.25992105,
    1.36079,
    1.469734492,
    1.587401052,
    1.714487966,
    1.851749425
};

static int r2h_ev(int start, int end)
{
    if (start < end)
    {
        memset(r2h+start+camera_sensor.black_level,h,end-start);
        h++;
    }
    return start;
}

static void init_r2h()
{
    if (r2h == 0)
    {
        r2h = malloc(camera_sensor.white_level + 1);
    }

    if (r2h != 0)
    {
        int max = camera_sensor.white_level - camera_sensor.black_level + 1;
        double ev = log2(max);
        h = 0;
        ev_mark[0] = h;
        ev_mark_cnt = 1;
        int s;
        do
        {
            ev = ev - 1.0;
            double d = pow(2, ev);
            s = (int)(d+0.5);
            if (s >= 1)
            {
                int i;
                for (i = 8; i > 0; i--)
                {
                    max = r2h_ev((int)(d*pow2_inc[i]+0.5), max);
                }
                max = r2h_ev(s, max);
            }
            ev_mark[ev_mark_cnt] = h;
            ev_mark_cnt += 1;
        } while (s > 0);
        memset(r2h, h, camera_sensor.black_level+1);
        ev_max = h + 1;
    }
}

static void add_histo(short v, int idx)
{
    if (v > over_limit)
    {
        over_exposed[idx]++;
        if (over_exposed[idx] > histo_max) histo_max = over_exposed[idx];
    }
    else if (v < under_limit)
    {
        under_exposed[idx]++;
        if (under_exposed[idx] > histo_max) histo_max = under_exposed[idx];
    }
    histo[idx][r2h[v]]++;
    if (histo[idx][r2h[v]] > histo_max) histo_max = histo[idx][r2h[v]];
}

void build_raw_ev_histo()
{
    if (running)
    {
        int x, y, x0, x1, y0, y1;

        if ((r2h == 0) || (camera_sensor.black_level != last_black_level))
        {
            last_black_level = camera_sensor.black_level;   // Some cameras can change black level based on ISO and Tv
            init_r2h();
        }

        if (r2h == 0) return; // !! no memory

        memset(histo, 0, 3 * EV_MAX14 * 4);
        memset(over_exposed, 0, 3 * 4);
        memset(under_exposed, 0, 3 * 4);
        histo_max = 0;

        // Use sensor active area only
        int fw = camera_sensor.active_area.x2 - camera_sensor.active_area.x1;
        int fh = camera_sensor.active_area.y2 - camera_sensor.active_area.y1;

        int width = (fw * conf.raw_ev_histo_width) / 100;
        int height = (fh * conf.raw_ev_histo_height) / 100;

        // In future, support definition of a sort of "spot metering"
        x0 = (camera_sensor.active_area.x1 + (fw - width) / 2) & 0xFFFFFFFE;
        x1 = x0 + width;
        y0 = (camera_sensor.active_area.y1 + (fh - height) / 2) & 0xFFFFFFFE;
        y1 = y0 + height;

        sample_count = ((x1 - x0 + conf.raw_ev_histo_xstep - 1) / conf.raw_ev_histo_xstep) * ((y1 - y0 + conf.raw_ev_histo_ystep - 1) / conf.raw_ev_histo_ystep);

        under_limit = camera_sensor.black_level + conf.raw_ev_histo_under_threshold;
        over_limit = camera_sensor.white_level - conf.raw_ev_histo_over_threshold;

        for (y = y0; y < y1; y += conf.raw_ev_histo_ystep)
        {
            for (x = x0; x < x1; x += conf.raw_ev_histo_xstep)
            {
                short r = get_raw_pixel(x+camera_sensor.cfa_offsets[CFA_R][0],y+camera_sensor.cfa_offsets[CFA_R][1]);
                short g1 = get_raw_pixel(x+camera_sensor.cfa_offsets[CFA_G1][0],y+camera_sensor.cfa_offsets[CFA_G1][1]);
                short g2 = get_raw_pixel(x+camera_sensor.cfa_offsets[CFA_G2][0],y+camera_sensor.cfa_offsets[CFA_G2][1]);
                short b = get_raw_pixel(x+camera_sensor.cfa_offsets[CFA_B][0],y+camera_sensor.cfa_offsets[CFA_B][1]);

                add_histo(r, 0);
                add_histo((g1+g2)/2, 1);
                add_histo(b, 2);
            }
        }

        for (x = 0; x < 3; x++)
        {
            under_pct[x] = (under_exposed[x] * 1000) / sample_count;
            over_pct[x] = (over_exposed[x] * 1000) / sample_count;
            
            for (y = 0; y < ev_max; y++)
            {
                histo_bar[x][y] = (histo[x][y] * BH) / histo_max;
            }

            under_bar[x] = (under_exposed[x] * BH) / histo_max;
            over_bar[x] = (over_exposed[x] * BH) / histo_max;

            unsigned int ettr_limit = conf.raw_ev_histo_ettr_pct * sample_count / 1000;
            if (over_exposed[x] > ettr_limit)
            {
                ettr_hint[x] = -1;
            }
            else
            {
                unsigned int sum = 0;
                for (y = 0; y < ev_max; y++)
                {
                    sum += histo[x][y];
                    if (sum >= ettr_limit)
                        break;
                }
                ettr_hint[x] = y * 10 / 9;
            }
        }

        histo_ready = 1;

        if (conf.raw_ev_histo_save_log)
            raw_ev_write_to_file();
    }
}

//-----------------------------------------------------------------------------

static void draw_over_under_pct(int x, int y, int pct, int i)
{
    if (pct > 0)
    {
        char s[10];

        if (pct >= 100)
            sprintf(s, "%3d%%", pct/10);
        else
            sprintf(s, "%d.%d%%", pct/10, pct%10);

        draw_string(x, y+i*BH+i+BH-FONT_HEIGHT, s, MAKE_COLOR(COLOR_BLACK,COLOR_WHITE));
    }
}

static void draw_bar(int x, int y, int val, int i, color col)
{
    if (val > 0)
        draw_vline(x, y+BH+i*BH+i-val+1, val, col);
}

static void draw_raw_ev_histo()
{
    if (running && histo_ready)
    {
        int i, j;

        color rgb[3] = {COLOR_RED, COLOR_GREEN, COLOR_BLUE};

        int hx = conf.raw_ev_histo_pos.x + 4*FONT_WIDTH;
        int hy = conf.raw_ev_histo_pos.y;

        draw_rectangle(hx, hy, hx+ev_max+7, hy+3*BH+3, MAKE_COLOR(COLOR_BLACK,COLOR_GREY_DK),RECT_BORDER1|DRAW_FILLED);
        for (i = 0; i < ev_mark_cnt; i += 1)
            draw_vline(hx+4+(ev_max-1-ev_mark[i]), hy+1, 3*BH+2, COLOR_GREY_DK);
        draw_hline(hx+1, hy+BH+1, ev_max+6, COLOR_GREY_DK);
        draw_hline(hx+1, hy+2*BH+2, ev_max+6, COLOR_GREY_DK);

        for (i=0; i<3; i++)
        {
            for (j = 0; j < ev_max; j++)
                draw_bar(hx+4+(ev_max-1-j), hy, histo_bar[i][j], i, rgb[i]);

            draw_bar(hx+2, hy, under_bar[i], i, COLOR_WHITE);
            draw_bar(hx+5+ev_max, hy, over_bar[i], i, COLOR_WHITE);

            draw_over_under_pct(conf.raw_ev_histo_pos.x, hy, under_pct[i], i);
            draw_over_under_pct(hx+8+ev_max, hy, over_pct[i], i);

            int hint = ettr_hint[i];
            if (hint > 0)
            {
                char s[10];
                if (hint >= 100)
                    strcpy(s, ">10");
                else
                    sprintf(s, ">%d.%d", hint / 10, hint % 10);
                draw_string(hx+8+ev_max, hy+i*BH+i, s, MAKE_COLOR(COLOR_BLACK,COLOR_WHITE));
            }
        }

        histo_drawn = 1;
    }
}

static void erase_raw_ev_histo()
{
    if (histo_drawn)
    {
        histo_drawn = 0;

        int hx = conf.raw_ev_histo_pos.x;
        int hy = conf.raw_ev_histo_pos.y;

        draw_rectangle(hx, hy, hx+ev_max+7+FONT_WIDTH*8, hy+3*BH+3, MAKE_COLOR(COLOR_TRANSPARENT,COLOR_TRANSPARENT), RECT_BORDER0|DRAW_FILLED);
        gui_set_need_restore();
    }
}

//-----------------------------------------------------------------------------

int _module_loader()
{
    running = 1;
    return 0;
}

int _module_unloader()
{
    if (r2h)
    {
        free(r2h);
        r2h = 0;
    }
    return 0;
}

int _module_can_unload()
{
    return !running && !histo_drawn;
}

// =========  MODULE INIT =================

librawevhisto_sym _librawevhisto =
{
    {
         _module_loader, _module_unloader, _module_can_unload, 0, 0
    },

    load_raw_ev_histo,
    build_raw_ev_histo,
    draw_raw_ev_histo,
    erase_raw_ev_histo,
};

ModuleInfo _module_info =
{
    MODULEINFO_V1_MAGICNUM,
    sizeof(ModuleInfo),
    RAW_EV_HISTO_VERSION,       // Module version

    ANY_CHDK_BRANCH, 0, OPT_ARCHITECTURE,        // Requirements of CHDK version
    ANY_PLATFORM_ALLOWED,       // Specify platform dependency

    (int32_t)"RAW EV Histogram",
    MTYPE_EXTENSION,

    &_librawevhisto.base,

    ANY_VERSION,                // CONF version
    ANY_VERSION,                // CAM SCREEN version
    CAM_SENSOR_VERSION,         // CAM SENSOR version
    ANY_VERSION,                // CAM INFO version

    0,
};

//-----------------------------------------------------------------------------
