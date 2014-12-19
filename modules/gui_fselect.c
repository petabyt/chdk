#include "camera_info.h"
#include "stdlib.h"
#include "keyboard.h"
#include "modes.h"
#include "sd_card.h"
#include "debug_led.h"
#include "lang.h"
#include "gui.h"
#include "gui_draw.h"
#include "gui_lang.h"
#include "gui_mbox.h"
#include "raw.h"
#include "conf.h"

#include "gui_fselect.h"
#include "raw_merge.h"
#include "dng.h"
#include "gui_mpopup.h"
#include "gui_tbox.h"
#include "gui_read.h"

#include "module_load.h"

/*
    HISTORY:    1.1 - added tbox usage [CHDK 1.1.1 required]
*/

int gui_fselect_kbd_process();
void gui_fselect_kbd_process_menu_btn();
void gui_fselect_draw(int enforce_redraw);

gui_handler GUI_MODE_FSELECT_MODULE =
    /*GUI_MODE_FSELECT*/    { GUI_MODE_FSELECT, gui_fselect_draw, gui_fselect_kbd_process, gui_fselect_kbd_process_menu_btn, 0, 0 };

//-------------------------------------------------------------------
#define HEAD_LINES              1
#define BODY_LINES              10
#define FOOT_LINES              1
#define HEAD_FONT_LINES         HEAD_LINES * FONT_HEIGHT
#define BODY_FONT_LINES         BODY_LINES * FONT_HEIGHT
#define FOOT_FONT_LINES         FOOT_LINES * FONT_HEIGHT

#define NAME_SIZE               camera_screen.fselect_name_size  // "FILENAME.123 "  (8.3 filenames)
#define SIZE_SIZE               camera_screen.fselect_size_size  // "1000 b|M|G"
#define TIME_SIZE               camera_screen.fselect_time_size  // "01.01'70 00:00"

#define NAME_FONT_SIZE          NAME_SIZE * FONT_WIDTH
#define EXTE_FONT_SIZE          EXTE_SIZE * FONT_WIDTH
#define SIZE_FONT_SIZE          SIZE_SIZE * FONT_WIDTH
#define TIME_FONT_SIZE          TIME_SIZE * FONT_WIDTH

#define SPACING                 4
#define TAB_DIVIDER             1
#define BORDER                  2
#define SCROLLBAR               4

#define MARKED_OP_NONE          0
#define MARKED_OP_CUT           1
#define MARKED_OP_COPY          2
#define MARKED_BUF_SIZE         0x10000

//-------------------------------------------------------------------
static int running = 0;
static char current_dir[100];       // Path for title
static char marked_dir[100];        // Path for progress box
static char selected_file[100];     // This full path to current file. So it is return value
static char buf[100];
static gui_handler *gui_fselect_mode_old; // stored previous gui_mode

// basic element of file list
typedef struct _fitem
{
    unsigned int    n;
    unsigned char   attr;
    unsigned long   size;
    unsigned long   mtime;
    unsigned char   marked;
    struct _fitem   *prev, *next;
    char            name[1];    // this structure must dynamically allocated !!!
                                // when allocating add the required length of the name (malloc(sizeof(fitem) + strlen(name))
                                // only one buffer then needs to be allocated and released
} fitem;

// List container
typedef struct
{
    unsigned int    count;
    fitem           *head;
    fitem           *tail;
} flist;

static flist    items;          // head of list<fitem>:  holder of current directory list
static flist    marked_items;   // head of list<fitem>:  holder of selected files list (keep independent filelist). made by Cut/Copy

static fitem    *top;           // ptr to first displayed file (top on the screen)
static fitem    *selected;      // ptr to current file (file on cursor)

static char marked_operation;   // info for paste: MARKED_OP_NONE, MARKED_OP_CUT, MARKED_OP_COPY

static unsigned int max_dir_len;    // just NAME_SIZE+SIZE_SIZE+SPACING

static coord main_x, main_y, main_w, main_h; //main browser window coord (without BORDERs)
static coord head_x, head_y, head_w, head_h; //header window coord
static coord body_x, body_y, body_w, body_h; //main body window coord
static coord foot_x, foot_y, foot_w, foot_h; //footer window coord

static int gui_fselect_redraw;  // flag request fselect redraw: 0-no, 1-only filelist, 2-whole_redraw(incl.border)
static int gui_fselect_readdir; // flag to force re-read of current directory
static char *fselect_title;     // Title of fselect window (could be different: Choose Text, Choose Script, etc)

static void (*fselect_on_select)(const char *fn);
static char raw_operation;      // info for process_raw_files() RAW_OPERATION_AVERAGE, RAW_OPERATION_SUM,

// FSelector POPUP
#define MPOPUP_CUT              0x0001
#define MPOPUP_COPY             0x0002
#define MPOPUP_PASTE            0x0004
#define MPOPUP_DELETE           0x0008
#define MPOPUP_SELINV           0x0010
#define MPOPUP_PURGE            0x0080
#define MPOPUP_EDITOR           0x0800
#define MPOPUP_CHDK_REPLACE     0x1000

#define MPOPUP_RAWOPS           0x0020
#define MPOPUP_MORE             0x0040

static struct mpopup_item popup[]= {
        { MPOPUP_CUT,           LANG_POPUP_CUT    },
        { MPOPUP_COPY,          LANG_POPUP_COPY   },
        { MPOPUP_PASTE,         LANG_POPUP_PASTE  },
        { MPOPUP_DELETE,        LANG_POPUP_DELETE },
        { MPOPUP_SELINV,        LANG_POPUP_SELINV },
        { MPOPUP_PURGE,         LANG_POPUP_PURGE  },
        { MPOPUP_EDITOR,        (int)"Edit" },
        { MPOPUP_CHDK_REPLACE,  (int)"Set this CHDK" },
        { MPOPUP_RAWOPS,        (int)"Raw ops ->" },
        { MPOPUP_MORE,          LANG_POPUP_MORE },
        { 0,                    0 },
};

#define MPOPUP_RAW_ADD          0x0020
#define MPOPUP_RAW_AVERAGE      0x0040
#define MPOPUP_SUBTRACT         0x0100
#define MPOPUP_RAW_DEVELOP      0x0200
#define MPOPUP_DNG_TO_CRW       0x0400

static struct mpopup_item popup_rawop[]= {
        { MPOPUP_RAW_ADD,       LANG_POPUP_RAW_SUM},
        { MPOPUP_RAW_AVERAGE,   LANG_POPUP_RAW_AVERAGE },
        { MPOPUP_RAW_DEVELOP,   LANG_MENU_RAW_DEVELOP },
        { MPOPUP_SUBTRACT,      LANG_POPUP_SUB_FROM_MARKED  },
        { MPOPUP_DNG_TO_CRW,    (int)"DNG -> CHDK RAW"},
        { 0,                    0 },
};

#define MPOPUP_MKDIR  0x0001
#define MPOPUP_RMDIR  0x0002
#define MPOPUP_RENAME 0x0004

static struct mpopup_item popup_more[]= {
        { MPOPUP_MKDIR,         LANG_POPUP_MKDIR },
        { MPOPUP_RMDIR,         LANG_POPUP_RMDIR },
        { MPOPUP_RENAME,        LANG_POPUP_RENAME },
        { 0,                    0 },
};

//-------------------------------------------------------------------
// List helper functions

static void free_list(flist *list)
{
    fitem *ptr = list->head;

    while (ptr)
    {
        fitem *prev = ptr;
        ptr = ptr->next;
        free(prev);
    }

    list->head = list->tail = 0;
    list->count = 0;
}

static void add_item(flist *list, const char *name, unsigned char attr, unsigned long size, unsigned long mtime, unsigned char marked)
{
    fitem *p = malloc(sizeof(fitem) + strlen(name));
    if (p)
    {
        p->n = list->count;
        strcpy(p->name, name);
        p->attr = attr;
        p->size = size;
        p->mtime = mtime;
        p->marked = marked;

        p->next = 0;
        p->prev = list->tail;
        if (list->tail)
            list->tail->next = p;
        list->tail = p;
        if (list->head == 0)
            list->head = p;

        list->count++;
    }
}

int fselect_sort(const void* v1, const void* v2)
{
    fitem *i1 = *((fitem **)v1);
    fitem *i2 = *((fitem **)v2);

    if (i1->attr & DOS_ATTR_DIRECTORY)
    {
        if (i2->attr & DOS_ATTR_DIRECTORY)
        {
            if (i1->name[0]=='.' && i1->name[1]=='.' && i1->name[2]==0)
            {
                return -1;
            }
            else if (i2->name[0]=='.' && i2->name[1]=='.' && i2->name[2]==0)
            {
                return 1;
            }
            else
            {
                return strcmp(i1->name, i2->name);
            }
        }
        else
        {
            return -1;
        }
    }
    else
    {
        if (i2->attr & DOS_ATTR_DIRECTORY)
        {
            return 1;
        }
        else
        {
            return strcmp(i1->name, i2->name);
        }
    }
}

static void sort_list(flist *list)
{
    if (list->count)
    {
        // sort
        fitem **sbuf = malloc(list->count*sizeof(fitem*));
        if (sbuf)
        {
            fitem *ptr = list->head;
            int i = 0;
            while (ptr)
            {
                sbuf[i++] = ptr;
                ptr = ptr->next;
            }

            extern int fselect_sort_nothumb(const void* v1, const void* v2);
            qsort(sbuf, list->count, sizeof(fitem*), fselect_sort_nothumb);

            list->head = sbuf[0];
            list->tail = sbuf[list->count-1];
            for (i=0; i<list->count-1; i++)
            {
                sbuf[i]->n = i;
                sbuf[i]->next = sbuf[i+1];
                sbuf[i+1]->prev = sbuf[i];
            }
            list->head->prev = 0;
            list->tail->next = 0;
            list->tail->n = list->count - 1;

            free(sbuf);
        }
    }
}

//-------------------------------------------------------------------
// File / folder helper functions

static void delete_file(const char *path, const char *name)
{
    sprintf(buf, "%s/%s", path, name);
    remove(buf);
}

static void delete_dir(const char *path)
{
    remove(path);
}

//-------------------------------------------------------------------
// Helper methods to check filenames (case insensitive)

// Match extension
static int chk_ext(const char *ext, const char *tst)
{
    if (ext)
    {
        ext++;
        if (strlen(ext) == strlen(tst))
        {
            int i;
            for (i=0; i<strlen(tst); i++)
                if (toupper(ext[i]) != toupper(tst[i]))
                    return 0;
            return 1;
        }
    }
    return 0;
}

// Match start of filename
static int chk_prefix(const char *name, const char *prefix)
{
    if (name && (strlen(name) >= strlen(prefix)))
    {
        int i;
        for (i=0; i<strlen(prefix); i++)
            if (toupper(prefix[i]) != toupper(name[i]))
                return 0;
        return 1;
    }
    return 0;
}

// Match entire name
static int chk_name(const char *name, const char *tst)
{
    if (name && (strlen(name) == strlen(tst)))
    {
        int i;
        for (i=0; i<strlen(tst); i++)
            if (toupper(tst[i]) != toupper(name[i]))
                return 0;
        return 1;
    }
    return 0;
}

// Check for current or parent directory
static int is_parent(const char *name)  { return (strcmp(name, "..") == 0); }
static int is_current(const char *name)  { return (strcmp(name, ".") == 0); }

// Check if file is a RAW image
static int is_raw(const char *name)
{
    char *ext = strrchr(name, '.');
    return ((chk_prefix(name,"crw_") || (chk_prefix(name,"img_")))) &&
           ((chk_ext(ext,"cr2") || (chk_ext(ext,"crw") || (chk_ext(ext,"dng")))));
}

// Check if file is a JPG
static int is_jpg(const char *name)
{
    char *ext = strrchr(name, '.');
    return (chk_prefix(name,"img_")) && (chk_ext(ext,"jpg"));
}

//-------------------------------------------------------------------
// Structure to hold info about a file or directory
typedef struct
{
    struct dirent   *de;
    unsigned char   attr;
    unsigned long   size;
    unsigned long   mtime;
    short           deleted;        // deleted entry?
    short           isdir;          // directory?
    short           isparent;       // parent directory (..)?
    short           iscurrent;      // current directory (.)?
} fs_dirent;

// Custom readdir - populates extra info about the file or directory
// Uses stat() after calling readdir() - we don't currently get this
// extra data from the firmware function.
static int fs_readdir(DIR *d, fs_dirent *de, const char* path)
{
    de->de = readdir(d);
    de->attr = 0xFF;
    de->size = 0;
    de->mtime = 0;
    de->deleted  = 0;
    de->isparent = 0;
    de->iscurrent = 0;
    de->isdir = 0;

    if (de->de)
    {
        if (de->de->d_name[0] == 0xE5)
        {
            de->deleted = 1;
        }
        else
        {
            de->isparent = is_parent(de->de->d_name);
            de->iscurrent = is_current(de->de->d_name);

            sprintf(buf, "%s/%s", path, de->de->d_name);
            struct stat st;
            if (stat(buf, &st) == 0)
            {
                de->attr  = st.st_attrib;
                de->size  = st.st_size;
                de->mtime = st.st_mtime;
            }
            else
            {
                de->attr = (de->isparent) ? DOS_ATTR_DIRECTORY : 0xFF;
            }

            de->isdir = ((de->attr & DOS_ATTR_DIRECTORY) != 0);
        }

        return 1;
    }

    return 0;
}

// Process contents of named directory
//  - for sub directories, process recursively if required (up to 'nested' levels deep)
//  - for files, call 'file_process' function
// Once file & directory processing done, call 'dir_process' function on input path
static void process_dir(const char *parent, const char *name, int nested, void (*file_process)(const char *path, const char *file), void (*dir_process)(const char *path))
{
    DIR         *d;
    fs_dirent   de;

    // Get full name
    char *path;
    if (name)
    {
        path = malloc(strlen(parent) + strlen(name) + 2);
        sprintf(path, "%s/%s", parent, name);
    }
    else
    {
        path = (char*)parent;
    }

    // Open directory
    d = opendir(path);

    if (d)
    {
        // Process contents
        while (fs_readdir(d, &de, path))
        {
            if (!de.deleted)
            {
                // Sub directory? Process recursively (but only 'nested' level deep)
                if (de.isdir)
                {
                    if (!de.isparent && !de.iscurrent && nested)
                        process_dir(path, de.de->d_name, nested-1, file_process, dir_process);
                }
                else if (file_process)
                {
                    file_process(path, de.de->d_name);
                }
            }
        }
        closedir(d);

        if (dir_process)
            dir_process(path);
    }

    if (name)
        free(path);
}

//-------------------------------------------------------------------
static void fselect_goto_prev(int step)
{
    register int j, i;

    for (j=0; j<step; ++j)
    {
        if (selected->prev==top && top->prev)
            top=top->prev;
        if (selected->prev)
            selected=selected->prev;
        else
        if (step == 1)
        {
            for(; selected->next; selected=selected->next);
            for (i=0, top=selected; i<BODY_LINES-1 && top->prev; ++i, top=top->prev);
        }
    }
}

//-------------------------------------------------------------------
static void fselect_goto_next(int step)
{
    register int j, i;
    fitem  *ptr;

    for (j=0; j<step; ++j)
    {
        for (i=0, ptr=top; i<BODY_LINES-1 && ptr; ++i, ptr=ptr->next);
        if (i==BODY_LINES-1 && ptr && ptr->prev==selected && ptr->next)
            top=top->next;
        if (selected->next)
            selected=selected->next;
        else
        if (step == 1)
        {
            for(; top->prev; top = top->prev);
            selected = top;
        }
    }
}

//-------------------------------------------------------------------
static void gui_fselect_free_data()
{
    free_list(&items);
    top = selected = NULL;
}

//-------------------------------------------------------------------
static void gui_fselect_read_dir(const char* dir)
{
    DIR         *d;
    fs_dirent   de;
    fitem  *ptr, *sbuf;
    int    i;

    gui_fselect_free_data();

    if (dir[0]=='A' && dir[1]==0)
        d = opendir("A/");
    else
        d = opendir(dir);

    if (d)
    {
        while (fs_readdir(d, &de, dir))
            if (!de.deleted && !de.iscurrent)
                add_item(&items, de.de->d_name, de.attr, de.size, de.mtime, 0);
        closedir(d);
    }

    sort_list(&items);

    top = selected = items.head;
}

//-------------------------------------------------------------------
// Attempt to set startup directory (and file) based on input 'dir'
// Note: 'dir' may be a directory name or a file name (including path)
// Returns 1 if valid directory/file found, 0 otherwise
int gui_fselect_find_start_dir(const char* dir)
{
    selected_file[0] = 0;
    strcpy(current_dir, dir);

    // Make sure there is something left to check
    while (strlen(current_dir) > 0)
    {
        struct stat st;
        // check if input 'dir' exists
        if (stat(current_dir,&st) == 0)
        {
            // exists - check if it is a directory or file
            if (st.st_attrib & DOS_ATTR_DIRECTORY)
            {
                // Directory and exists so all good
                return 1;
            }
            else
            {
                // 'dir' is a file, extract filename to 'selected_file' and remove from 'current_dir'
                char *p = strrchr(current_dir,'/');
                strcpy(selected_file, p+1);
                *p = 0;
                return 1;
            }
        }
        else
        {
            // could not find 'dir' - try one level up
            char *p = strrchr(current_dir,'/');
            if (p) *p = 0;
            else return 0;
        }
    }

    return 0;
}

//-------------------------------------------------------------------
void gui_fselect_init(int title, const char* prev_dir, const char* default_dir, void (*on_select)(const char *fn))
{
    running = 1;

    int chars_width = NAME_FONT_SIZE + SIZE_FONT_SIZE + TIME_FONT_SIZE;
    main_w = SPACING/*N*/+SPACING+TAB_DIVIDER+SPACING/*S*/+SPACING+TAB_DIVIDER+SPACING/*T*/+SPACING+SCROLLBAR+chars_width;
    main_h = HEAD_FONT_LINES + TAB_DIVIDER + BODY_FONT_LINES + TAB_DIVIDER + FOOT_FONT_LINES;
    main_x = (camera_screen.width - main_w) >> 1;
    main_y = (camera_screen.height - main_h) >> 1;

    head_x = body_x = foot_x = main_x;
    head_w = body_w = foot_w = main_w;
    head_y = main_y;
    head_h = HEAD_FONT_LINES;
    body_y = head_y + head_h + TAB_DIVIDER;
    body_h = BODY_FONT_LINES;
    foot_y = body_y + body_h + TAB_DIVIDER;
    foot_h = FOOT_FONT_LINES;

    fselect_title = lang_str(title);

    // Try and set start directory, and optionally selected file, from inputs
    if (!gui_fselect_find_start_dir(prev_dir))
        if (!gui_fselect_find_start_dir(default_dir))
            gui_fselect_find_start_dir("A");

    max_dir_len = NAME_SIZE + SIZE_SIZE + SPACING;
    gui_fselect_read_dir(current_dir);

    // Find selected file if it exists in list
    if (selected_file[0])
    {
        fitem *p = items.head;
        while (p)
        {
            if (chk_name(p->name,selected_file))
            {
                break;
            }
            p = p->next;
            fselect_goto_next(1);
        }
        if (!p) selected_file[0] = 0;
    }

    fselect_on_select = on_select;
    marked_operation = MARKED_OP_NONE;
    gui_fselect_redraw = 2;
    gui_fselect_readdir = 0;
    gui_fselect_mode_old = gui_set_mode(&GUI_MODE_FSELECT_MODULE);
}

//-------------------------------------------------------------------
void gui_fselect_draw_initial()
{
    int title_font_size;

    draw_filled_rect(head_x, head_y, head_x+head_w-1, head_y+head_h-1, MAKE_COLOR(COLOR_BLACK, COLOR_BLACK)); //header box
    title_font_size = strlen(fselect_title) * FONT_WIDTH;
    draw_string(head_x+((head_w-title_font_size)>>1), head_y, fselect_title, MAKE_COLOR(COLOR_BLACK, COLOR_WHITE)); //title text

    draw_rect_thick(main_x-BORDER, main_y-BORDER, main_x+main_w+BORDER-1, main_y+main_h+BORDER-1, COLOR_WHITE, BORDER); //border frame
    draw_line(body_x, body_y-1, body_x+body_w-1, body_y-1, COLOR_WHITE); //border head-body
    draw_line(foot_x, foot_y-1, foot_x+foot_w-1, foot_y-1, COLOR_WHITE); //border body-foot
}

//-------------------------------------------------------------------
void gui_fselect_draw(int enforce_redraw)
{
    int i, j, off_name_x, off_size_x, off_time_x, off_body_x, off_body_y;
    fitem  *ptr;
    char buf[100];
    struct tm *time;
    unsigned long sum_size;
    twoColors cl_marked, cl_selected;

    if (gui_fselect_readdir)
    {
        gui_fselect_readdir = 0;
        gui_fselect_read_dir(current_dir);
    }

    if ( enforce_redraw )
        gui_fselect_redraw = 2;

    if (gui_fselect_redraw)
    {
        if (gui_fselect_redraw == 2)
            gui_fselect_draw_initial();

        off_body_y = 0;
        off_name_x = body_x+SPACING;
        off_size_x = off_name_x+NAME_FONT_SIZE+SPACING+TAB_DIVIDER+SPACING;
        off_time_x = off_size_x+SIZE_FONT_SIZE+SPACING+TAB_DIVIDER+SPACING;
        off_body_x = off_time_x+TIME_FONT_SIZE+SPACING;

        sum_size = 0;
        for (i=0, ptr=top; i<BODY_LINES && ptr; ++i, ptr=ptr->next)
        {
            cl_marked = MAKE_COLOR((ptr==selected)?COLOR_RED:COLOR_GREY, (ptr->marked)?COLOR_YELLOW:COLOR_WHITE);
            cl_selected = (ptr==selected)?MAKE_COLOR(COLOR_RED, COLOR_RED):MAKE_COLOR(COLOR_GREY, COLOR_GREY);

            // print name
            for (j=0; j<NAME_SIZE && ptr->name[j]; ++j)
                buf[j] = ptr->name[j];

            if (j==NAME_SIZE && ptr->name[j]) buf[NAME_SIZE-1] = '~'; // too long name

            if (ptr->attr & DOS_ATTR_DIRECTORY && ptr->attr != 0xFF)
            { //?
                if (j<NAME_SIZE)
                {
                    buf[j++]='/';
                }
                else
                {
                    buf[NAME_SIZE-2]='~';
                    buf[NAME_SIZE-1]='/';
                }
            }
            for (; j<NAME_SIZE && (buf[j++]=' ');); //fill upto NAME_SIZE
            buf[NAME_SIZE] = 0; // eos

            off_body_y = body_y+(i*FONT_HEIGHT);
            draw_filled_rect(body_x, off_body_y, off_name_x-1, off_body_y+FONT_HEIGHT-1, cl_selected);
            draw_string(off_name_x, off_body_y, buf, cl_marked);
            draw_filled_rect(off_name_x+NAME_FONT_SIZE, off_body_y, off_name_x+NAME_FONT_SIZE+SPACING-1, off_body_y+FONT_HEIGHT-1, cl_selected);

            // print size or <Dir>
            if (ptr->attr & DOS_ATTR_DIRECTORY)
            {
                if (ptr->attr == 0xFF)
                {
                    sprintf(buf, "  ???  ");
                }
                else if (ptr->name[0] == '.' && ptr->name[1] == '.' && ptr->name[2] == 0)
                {
                    sprintf(buf, "<UpDir>");
                }
                else
                {
                    sprintf(buf, "< Dir >");
                }
            }
            else
            {
                if (ptr->size < 1024)
                    sprintf(buf, "%5d b", ptr->size); // " 1023 b"
                else if (ptr->size < 1024*1024)
                    sprintf(buf, "%3ld.%1d k", ptr->size/1024, (ptr->size%1024*10)/1024); // "999.9 k"
                else if (ptr->size < 1024*1024*1024)
                    sprintf(buf, "%3ld.%ld M", ptr->size/(1024*1024), (ptr->size%(1024*1024)*10)/(1024*1024) ); // "999.9 M"
                else
                    sprintf(buf, "%3ld.%ld G", ptr->size/(1024*1024*1024), (ptr->size%(1024*1024*1024)*10)/(1024*1024*1024)); // "999.9 G"

                if (ptr->marked)
                  sum_size += ptr->size;
            }
            buf[SIZE_SIZE] = 0;
            //tab divider
            draw_line(off_size_x-TAB_DIVIDER-SPACING, off_body_y, off_size_x-TAB_DIVIDER-SPACING, off_body_y+FONT_HEIGHT-1, COLOR_WHITE);
            draw_filled_rect(off_size_x-SPACING, off_body_y, off_size_x-1, off_body_y+FONT_HEIGHT-1, cl_selected);
            draw_string(off_size_x, off_body_y, buf, cl_marked);
            draw_filled_rect(off_size_x+SIZE_FONT_SIZE, off_body_y, off_size_x+SIZE_FONT_SIZE+SPACING-1, off_body_y+FONT_HEIGHT-1, cl_selected);

            // print modification time
            if (ptr->mtime)
            {
                time = localtime(&(ptr->mtime));
                sprintf(buf, "%02u.%02u'%02u %02u:%02u", time->tm_mday, time->tm_mon+1, (time->tm_year<100)?time->tm_year:time->tm_year-100, time->tm_hour, time->tm_min);
            }
            else
            {
                sprintf(buf, "%14s", "");
            }
            buf[TIME_SIZE] = 0;
            //tab divider
            draw_line(off_time_x-TAB_DIVIDER-SPACING, off_body_y, off_time_x-TAB_DIVIDER-SPACING, off_body_y+FONT_HEIGHT-1, COLOR_WHITE);
            draw_filled_rect(off_time_x-SPACING, off_body_y, off_time_x-1, off_body_y+FONT_HEIGHT-1, cl_selected);
            draw_string(off_time_x, off_body_y, buf, cl_marked);
            draw_filled_rect(off_time_x+TIME_FONT_SIZE, off_body_y, off_time_x+TIME_FONT_SIZE+SPACING-1, off_body_y+FONT_HEIGHT-1, cl_selected);
        }

        //fill the rest of body
        off_body_y += FONT_HEIGHT;
        if (i>0 && i<BODY_LINES)
        {
            draw_filled_rect(body_x, off_body_y, body_x+body_w-1, body_y+body_h-1, MAKE_COLOR(COLOR_GREY, COLOR_GREY));
        }

        // scrollbar
        draw_filled_rect(off_body_x, body_y, off_body_x+SCROLLBAR-1, body_y+body_h-1, MAKE_COLOR(COLOR_BLACK, COLOR_BLACK));
        if (items.count>BODY_LINES)
        {
            i = BODY_FONT_LINES - 1;
            j = i*BODY_LINES/items.count;
            if (j<20) j=20;
            i = (i-j)*selected->n/(items.count-1);
            draw_filled_rect(off_body_x, body_y+i, off_body_x+SCROLLBAR-2, body_y+i+j, MAKE_COLOR(COLOR_WHITE, COLOR_WHITE));
        }

        //footer
        i = strlen(current_dir);
        if (i > max_dir_len)
        {
          strncpy(buf, current_dir+i-max_dir_len, max_dir_len);
          buf[0] = '.';
          buf[1] = '.';
        }
        else
        {
          strcpy(buf, current_dir);
        }
        buf[max_dir_len] = 0;
        draw_filled_rect(foot_x, foot_y, foot_x+foot_w-1, foot_y+foot_h-1, MAKE_COLOR(COLOR_GREY, COLOR_GREY)); //footer box
        draw_string(off_name_x, foot_y, buf, MAKE_COLOR(COLOR_GREY, COLOR_WHITE)); //current dir

        if (sum_size)
        {
          sprintf(buf, "%d b", sum_size); //selected size
        }
        else
        {
          unsigned int fr, tot;
          fr = GetFreeCardSpaceKb(); tot = GetTotalCardSpaceKb();
          if (fr < 1024*1024)
            sprintf(buf, "%dM (%d%%)", fr>>10, tot? fr*100/tot: 0);
          else
            sprintf(buf, "%d.%dG (%d%%)", fr>>20, ((fr&0x000FFFFF)*100)>>20, tot? fr*100/tot: 0);
        }
        draw_string(foot_x+foot_w-strlen(buf)*FONT_WIDTH-BORDER, foot_y, buf, MAKE_COLOR(COLOR_GREY, COLOR_WHITE)); // free space
        gui_fselect_redraw = 0;
    }
}

//-------------------------------------------------------------------
static void fselect_delete_file_cb(unsigned int btn)
{
    if (btn==MBOX_BTN_YES)
    {
        started();
        delete_file(current_dir, selected->name);
        finished();
        selected_file[0] = 0;
        gui_fselect_readdir = 1;
    }
    gui_fselect_redraw = 2;
}

// Find a JPG matching a given RAW name. If 'nested' > 0 search recursively in
// child directories of 'folder.
// Returns 1 if found, 0 if not found (or match is not a RAW file)
static int find_jpg(const char *folder, const char *match, int nested)
{
    DIR         *d;
    fs_dirent   de;
    int         rv = 0;

    // Open directory
    d = opendir(folder);

    if (d)
    {
        // Process contents
        while (fs_readdir(d, &de, folder) && !rv)
        {
            if (!de.deleted)
            {
                // Sub directory? Process recursively (but only 'nested' levels deep)
                if (de.isdir)
                {
                    if (!de.isparent && !de.iscurrent && nested)
                    {
                        // Search sub-directory
                        char *path = malloc(strlen(folder) + strlen(de.de->d_name) + 2);
                        sprintf(path, "%s/%s", folder, de.de->d_name);
                        if (find_jpg(path, match, nested-1))
                            rv = 1;
                        free(path);
                    }
                }
                else
                {
                    //If the four digits of the Canon number are the same AND file is JPG
                    if (is_jpg(de.de->d_name) && (strncmp(match+4, de.de->d_name+4, 4) == 0))
                        rv = 1;
                }
            }
        }
        closedir(d);
    }

    return rv;
}

// If 'file' is a RAW file, scan its 'folder' for a JPG with the same
// image number, if not found delete the RAW image file.
static void purge_file(const char *folder, const char *file)
{
    //If no JPG found, delete RAW file
    if (is_raw(file))
        if (!find_jpg(folder, file, 0))
            delete_file(folder, file);
}

// If 'file' is a RAW file, scan its 'folder' and all sibling folders for a JPG with the same
// image number, if not found delete the RAW image file.
// Used when 'Purge RAW' run on the A/DCIM directory. CHDK can store RAW files in a different
// sub-directory of A/DCIM than the corresponding JPG.
static void purge_file_DCIM(const char *folder, const char *file)
{
    //If no JPG found, delete RAW file (search all sub-folders of A/DCIM for JPG)
    if (is_raw(file))
        if (!find_jpg("A/DCIM", file, 1))
            delete_file(folder, file);
}

static void fselect_purge_cb_DCIM(unsigned int btn)
{
    if (btn == MBOX_BTN_YES)
    {
        //If selected folder is A/DCIM or A/RAW (this is to purge all RAW files in any sub-folder)
        process_dir(current_dir, selected->name, 1, purge_file_DCIM, 0);
    }
}

static void fselect_purge_cb_dir(unsigned int btn)
{
    if (btn == MBOX_BTN_YES)
    {
        //If item is a Canon sub-folder of A/DCIM or A/RAW (this is to purge all RAW files inside a single Canon folder)
        process_dir(current_dir, selected->name, 0, purge_file, 0);
    }
}

static void fselect_purge_cb_file(unsigned int btn)
{
    if (btn == MBOX_BTN_YES)
    {
        //Inside a Canon folder (files list)
        fitem *ptr, *ptr2;

        //Loop to find all the RAW files in the list
        for (ptr=items.head; ptr; ptr=ptr->next)
        {
            //If file is RAW (Either CRW/CR2 prefix or file extension) and is not marked
            if (is_raw(ptr->name) && !ptr->marked)
            {
                // Flag for checking if matching JPG exists
                int found = 0;

                //Loop to find a corresponding JPG file in the list
                for (ptr2=items.head; ptr2; ptr2=ptr2->next)
                {
                    //If this is a JPG and the four digits of the Canon number are the same
                    if (is_jpg(ptr2->name) && (strncmp(ptr->name+4, ptr2->name+4, 4) == 0))
                    {
                        found=1;
                        break;
                    }
                }

                //If no JPG found, delete RAW file
                if (found == 0)
                    delete_file(current_dir, ptr->name);
            }
        }
        gui_fselect_readdir = 1;
    }
    gui_fselect_redraw = 2;
}


//-------------------------------------------------------------------
static void fselect_delete_folder_cb(unsigned int btn)
{
    if (btn==MBOX_BTN_YES)
    {
        process_dir(current_dir, selected->name, 999, delete_file, delete_dir);
        selected_file[0] = 0;
        gui_fselect_readdir = 1;
    }
    gui_fselect_redraw = 2;
}

static void confirm_delete_directory()
{
    if (selected->attr & DOS_ATTR_DIRECTORY)
        if (selected->name[0] != '.' || selected->name[1] != '.' || selected->name[2]!=0)
            gui_mbox_init(LANG_BROWSER_ERASE_DIR_TITLE, LANG_BROWSER_ERASE_DIR_TEXT,
                          MBOX_TEXT_CENTER|MBOX_BTN_YES_NO|MBOX_DEF_BTN2, fselect_delete_folder_cb);
}

//-------------------------------------------------------------------
static void fselect_marked_toggle()
{
    if (selected && selected->attr != 0xFF && !(selected->attr & DOS_ATTR_DIRECTORY))
    {
        selected->marked = !selected->marked;
    }
}

//-------------------------------------------------------------------
static void gui_fselect_marked_free_data()
{
    free_list(&marked_items);
    marked_operation = MARKED_OP_NONE;
}

//-------------------------------------------------------------------
static void fselect_marked_copy_list()
{
    gui_fselect_marked_free_data();

    fitem *ptr;

    for (ptr=items.head; ptr; ptr=ptr->next)
        if (ptr->marked)
            add_item(&marked_items, ptr->name, ptr->attr, ptr->size, ptr->mtime, 1);

    if (!marked_items.count)
        if (selected && selected->attr != 0xFF)
            if (!(selected->attr & DOS_ATTR_DIRECTORY))
                add_item(&marked_items, selected->name, selected->attr, selected->size, selected->mtime, 1);

    sprintf(marked_dir, "%s", current_dir);
}

//-------------------------------------------------------------------
static void fselect_marked_paste_cb(unsigned int btn)
{
    fitem  *ptr;
    int ss, sd = 0, fsrc, fdst, i=0;
    register int *buf;
    static struct utimbuf t;

    if (btn != MBOX_BTN_YES) return;

    if (strcmp(marked_dir, current_dir) != 0)
    {
        buf = umalloc(MARKED_BUF_SIZE);
        if (buf)
        {
            for (ptr=marked_items.head; ptr; ptr=ptr->next)
            {
                if (ptr->attr != 0xFF && !(ptr->attr & DOS_ATTR_DIRECTORY))
                {
                    started();
                    ++i;
                    if (marked_items.count)
                        gui_browser_progress_show(lang_str(LANG_FSELECT_PROGRESS_TITLE),i*100/marked_items.count);
                    sprintf(selected_file, "%s/%s", marked_dir, ptr->name);
                    fsrc = open(selected_file, O_RDONLY, 0777);
                    if (fsrc>=0)
                    {
                        sprintf(selected_file, "%s/%s", current_dir, ptr->name);
                        // trying to open for read to check if file exists
                        fdst = open(selected_file, O_RDONLY, 0777);
                        if (fdst<0)
                        {
                            fdst = open(selected_file, O_WRONLY|O_CREAT, 0777);
                            if (fdst>=0)
                            {
                                do
                                {
                                    ss=read(fsrc, buf, MARKED_BUF_SIZE);
                                    if (ss>0) sd=write(fdst, buf, ss);
                                } while (ss>0 && ss==sd);
                                close(fdst);
                                t.actime = t.modtime = ptr->mtime;
                                utime(selected_file, &t);
                                if (marked_operation == MARKED_OP_CUT && ss==0)
                                {
                                    close(fsrc); fsrc = -1;
                                    delete_file(marked_dir, ptr->name);
                                }
                            }
                        }
                        else
                        {
                            close(fdst);
                        }
                        if (fsrc>=0) close(fsrc);
                    }
                    finished();
                    selected_file[0]=0;
                }
            }
            ufree(buf);
            if (marked_operation == MARKED_OP_CUT)
            {
                gui_fselect_marked_free_data();
            }
        }
        gui_fselect_readdir = 1;
    }
    gui_fselect_redraw = 2;
}

//-------------------------------------------------------------------
static inline unsigned int fselect_real_marked_count()
{
    fitem  *ptr;
    register unsigned int cnt=0;

    for (ptr=items.head; ptr; ptr=ptr->next)
    {
        if (ptr->attr != 0xFF && !(ptr->attr & DOS_ATTR_DIRECTORY) && ptr->marked)
            ++cnt;
    }
    return cnt;
}

//-------------------------------------------------------------------
static unsigned int fselect_marked_count()
{
    register unsigned int cnt=fselect_real_marked_count();

    if (!cnt)
    {
        if (selected && selected->attr != 0xFF && !(selected->attr & DOS_ATTR_DIRECTORY))
            ++cnt;
    }

    return cnt;
}

//-------------------------------------------------------------------
static void fselect_marked_delete_cb(unsigned int btn)
{
    fitem  *ptr;
    unsigned int del_cnt=0, cnt;

    if (btn != MBOX_BTN_YES) return;

    cnt = fselect_marked_count();
    for (ptr=items.head; ptr; ptr=ptr->next)
        if (ptr->marked && ptr->attr != 0xFF && !(ptr->attr & DOS_ATTR_DIRECTORY))
        {
            started();
            ++del_cnt;
            if (cnt)
                gui_browser_progress_show(lang_str(LANG_FSELECT_PROGRESS_TITLE),del_cnt*100/cnt);
            delete_file(current_dir, ptr->name);
            finished();
        }

    if (del_cnt == 0 && selected)
    {
        started();
        delete_file(current_dir, selected->name);
        finished();
    }
    selected_file[0] = 0;
    gui_fselect_readdir = 1;
    gui_fselect_redraw = 2;
}

//-------------------------------------------------------------------
static void fselect_chdk_replace_cb(unsigned int btn)
{
    int ss, sd = 0, fsrc, fdst;
    register int *buf;
    static struct utimbuf t;

    if (btn != MBOX_BTN_YES) return;

    buf = umalloc(MARKED_BUF_SIZE);
    sprintf(selected_file, "%s/%s", current_dir, selected->name);
    fsrc = open(selected_file, O_RDONLY, 0777);
    if (fsrc>=0)
    {
        strcpy(selected_file,"A/DISKBOOT.BIN");
            fdst = open(selected_file, O_WRONLY|O_CREAT|O_TRUNC, 0777);
            if (fdst>=0)
            {
                do
                {
                    ss=read(fsrc, buf, MARKED_BUF_SIZE);
                    if (ss>0) sd=write(fdst, buf, ss);
                } while (ss>0 && ss==sd);
                close(fdst);
                t.actime = t.modtime = selected->mtime;
                utime(selected_file, &t);
                gui_browser_progress_show("Please reboot",100);
            }
        if (fsrc>=0) close(fsrc);
    }
    ufree(buf);
}

//-------------------------------------------------------------------
static void fselect_marked_inverse_selection()
{
    fitem  *ptr;

    for (ptr=items.head; ptr; ptr=ptr->next)
        if (ptr->attr != 0xFF && !(ptr->attr & DOS_ATTR_DIRECTORY))
            ptr->marked = !ptr->marked;

    gui_fselect_redraw = 2;
}

//-------------------------------------------------------------------
void process_raw_files(void)
{
    fitem *ptr;

    if ((fselect_marked_count()>1) && librawop->raw_merge_start(raw_operation))
    {
        for (ptr=items.head; ptr; ptr=ptr->next)
            if (ptr->marked && ptr->attr != 0xFF && !(ptr->attr & DOS_ATTR_DIRECTORY))
            {
                sprintf(selected_file, "%s/%s", current_dir, ptr->name);
                librawop->raw_merge_add_file(selected_file);
            }
        librawop->raw_merge_end();
        gui_fselect_readdir = 1;
        gui_fselect_redraw = 2;
    }
}

static void fselect_subtract_cb(unsigned int btn)
{
    fitem *ptr;
    if (btn != MBOX_BTN_YES) return;

    for (ptr=items.head; ptr; ptr=ptr->next)
    {
        if (ptr->marked && ptr->attr != 0xFF &&
            !(ptr->attr & DOS_ATTR_DIRECTORY) &&
            (strcmp(ptr->name,selected->name)) != 0)
        {
            librawop->raw_subtract(ptr->name, current_dir, selected->name, current_dir);
        }
    }
    gui_fselect_readdir = 1;
    gui_fselect_redraw = 2;
}

#define MAX_SUB_NAMES 6
static void setup_batch_subtract(void)
{
    fitem *ptr;
    int i;
    char *p = buf + sprintf(buf,"%s %s\n",selected->name,lang_str(LANG_FSELECT_SUB_FROM));
    for (ptr=items.head, i=0; ptr; ptr=ptr->next)
    {
        if (ptr->marked && ptr->attr != 0xFF && !(ptr->attr & DOS_ATTR_DIRECTORY) && ptr->size >= camera_sensor.raw_size)
        {
            if ( i < MAX_SUB_NAMES )
            {
                sprintf(p, "%s\n",ptr->name);
                // keep a pointer to the one before the end, so we can stick ...and more on
                if (i < MAX_SUB_NAMES - 1)
                {
                    p += strlen(p);
                }
            }
            i++;
        }
    }
    if (i > MAX_SUB_NAMES)
    {
//      "...%d more files"
        sprintf(p,lang_str(LANG_FSELECT_SUB_AND_MORE),i - (MAX_SUB_NAMES - 1));
    }
    gui_mbox_init(LANG_FSELECT_SUBTRACT, (int)buf,
                  MBOX_TEXT_CENTER|MBOX_BTN_YES_NO|MBOX_DEF_BTN2, fselect_subtract_cb);
}
//-------------------------------------------------------------------
void process_dng_to_raw_files(void)
{
    fitem *ptr;
    int i=0;
    started();
    msleep(100);
    finished();

    if (fselect_real_marked_count())
    {
        for (ptr=items.head; ptr; ptr=ptr->next)
            if (ptr->marked && ptr->attr != 0xFF && !(ptr->attr & DOS_ATTR_DIRECTORY))
            {
                sprintf(selected_file, "%s/%s", current_dir, ptr->name);
                gui_browser_progress_show(selected_file, (i++)*100/fselect_real_marked_count()) ;
                libdng->convert_dng_to_chdk_raw(selected_file);
            }
    }
    else
    {
        sprintf(selected_file, "%s/%s", current_dir, selected->name);
        libdng->convert_dng_to_chdk_raw(selected_file);
    }
    gui_fselect_readdir = 1;
}

static void fselect_mpopup_rawop_cb(unsigned int actn)
{
    switch (actn) {
        case MPOPUP_RAW_AVERAGE:
            raw_operation=RAW_OPERATION_AVERAGE;
            process_raw_files();
            break;
        case MPOPUP_RAW_ADD:
            raw_operation=RAW_OPERATION_SUM;
            process_raw_files();
            break;
        case MPOPUP_RAW_DEVELOP:
            sprintf(buf, "%s/%s", current_dir, selected->name);
            raw_prepare_develop(buf, 1);
            break;
        case MPOPUP_SUBTRACT:
            setup_batch_subtract();
            break;
        case MPOPUP_DNG_TO_CRW:
            process_dng_to_raw_files();
            break;
    }
}

static void mkdir_cb(const char* name)
{
    if (name)
    {
        sprintf(selected_file,"%s/%s",current_dir,name);
        mkdir(selected_file);
        gui_fselect_readdir = 1;
        gui_fselect_redraw = 2;
    }
}

static void rename_cb(const char* name)
{
    if (name)
    {
        char newname[100];
        sprintf(selected_file, "%s/%s", current_dir, selected->name);
        sprintf(newname,"%s/%s",current_dir,name);
        rename(selected_file,newname);
        gui_fselect_readdir = 1;
        gui_fselect_redraw = 2;
    }
}

static void fselect_mpopup_more_cb(unsigned int actn)
{
    switch (actn)
    {
        case MPOPUP_MKDIR:
            libtextbox->textbox_init(LANG_POPUP_MKDIR, LANG_PROMPT_MKDIR, "", 15, mkdir_cb, 0);
            break;
        case MPOPUP_RMDIR:
            confirm_delete_directory();
            break;
        case MPOPUP_RENAME:
            libtextbox->textbox_init(LANG_POPUP_RENAME, LANG_PROMPT_RENAME, selected->name, 15, rename_cb, 0);
            break;
    }
    gui_fselect_redraw = 2;
}

static int mpopup_rawop_flag;
static int mpopup_more_flag;

//-------------------------------------------------------------------
static void fselect_mpopup_cb(unsigned int actn)
{
    switch (actn)
    {
        case MPOPUP_CUT:
            fselect_marked_copy_list();
            marked_operation=MARKED_OP_CUT;
            break;
        case MPOPUP_COPY:
            fselect_marked_copy_list();
            marked_operation=MARKED_OP_COPY;
            break;
        case MPOPUP_PASTE:
            if (marked_operation == MARKED_OP_CUT)
            {
                sprintf(buf, lang_str(LANG_FSELECT_CUT_TEXT), marked_items.count, marked_dir);
                gui_mbox_init(LANG_FSELECT_CUT_TITLE, (int)buf,
                              MBOX_TEXT_CENTER|MBOX_BTN_YES_NO|MBOX_DEF_BTN2, fselect_marked_paste_cb);
            }
            else
            {
                sprintf(buf, lang_str(LANG_FSELECT_COPY_TEXT), marked_items.count, marked_dir);
                gui_mbox_init(LANG_FSELECT_COPY_TITLE, (int)buf,
                              MBOX_TEXT_CENTER|MBOX_BTN_YES_NO|MBOX_DEF_BTN2, fselect_marked_paste_cb);
            }
            break;
        case MPOPUP_DELETE:
            sprintf(buf, lang_str(LANG_FSELECT_DELETE_TEXT), fselect_marked_count());
            gui_mbox_init(LANG_FSELECT_DELETE_TITLE, (int)buf,
                          MBOX_TEXT_CENTER|MBOX_BTN_YES_NO|MBOX_DEF_BTN2, fselect_marked_delete_cb);
            break;
         case MPOPUP_PURGE:
           if (chk_name(current_dir, "A") && (chk_name(selected->name, "DCIM") || chk_name(selected->name, "RAW")))
           {
               //If selected folder is A/DCIM or A/RAW (this is to purge all RAW files in any sub-folder)
               gui_mbox_init(LANG_FSELECT_PURGE_TITLE, LANG_FSELECT_PURGE_DCIM_TEXT, MBOX_TEXT_CENTER|MBOX_BTN_YES_NO|MBOX_DEF_BTN2, fselect_purge_cb_DCIM);
           }
           else if ((chk_name(current_dir, "A/DCIM")) || (chk_name(current_dir, "A/RAW")))
           {
               //If selected item is a Canon folder
               gui_mbox_init(LANG_FSELECT_PURGE_TITLE, LANG_FSELECT_PURGE_CANON_FOLDER_TEXT, MBOX_TEXT_CENTER|MBOX_BTN_YES_NO|MBOX_DEF_BTN2, fselect_purge_cb_dir);
           }
           else if (is_raw(selected->name))
           {
               //If selected item is a file produced by the camera
               gui_mbox_init(LANG_FSELECT_PURGE_TITLE, LANG_FSELECT_PURGE_LIST_TEXT, MBOX_TEXT_CENTER|MBOX_BTN_YES_NO|MBOX_DEF_BTN2, fselect_purge_cb_file);
           }
           else
           {
               // Invalid selection
               gui_mbox_init(LANG_FSELECT_PURGE_TITLE, LANG_FSELECT_PURGE_DISABLED_TEXT, MBOX_TEXT_CENTER|MBOX_BTN_OK|MBOX_DEF_BTN1, 0);
           }
           break;
        case MPOPUP_SELINV:
            fselect_marked_inverse_selection();
            break;
        case MPOPUP_CANCEL:
            break;

        case MPOPUP_RAWOPS:
            libmpopup->show_popup( popup_rawop, mpopup_rawop_flag, fselect_mpopup_rawop_cb);
            break;

        case MPOPUP_MORE:
            libmpopup->show_popup( popup_more, mpopup_more_flag, fselect_mpopup_more_cb);
        break;

        case MPOPUP_CHDK_REPLACE:
            gui_mbox_init((int)"Replacing CHDK", (int)"Do you want to replace current CHDK with this file",
                          MBOX_TEXT_CENTER|MBOX_BTN_YES_NO|MBOX_DEF_BTN2, fselect_chdk_replace_cb);
            break;
        case MPOPUP_EDITOR:
            gui_mbox_init((int)"Editor", (int)"edit", MBOX_BTN_OK|MBOX_TEXT_CENTER, NULL);
            break;
    }
    gui_fselect_redraw = 2;
}

//-------------------------------------------------------------------
void finalize_fselect()
{
    gui_fselect_free_data();
    gui_fselect_marked_free_data();
}

static void exit_fselect(char* file)
{
    finalize_fselect();

    gui_set_mode(gui_fselect_mode_old);

    if (fselect_on_select)
    {
        fselect_on_select(file);
        // if called mode will return control to filemanager - we need to redraw it
        gui_fselect_redraw = 2;
    }

    running = 0;
}

//-------------------------------------------------------------------
int gui_fselect_kbd_process()
{
    int i;

    switch (kbd_get_autoclicked_key() | get_jogdial_direction())
    {
        case JOGDIAL_LEFT:
        case KEY_UP:
            if (selected)
            {
                if (camera_info.state.is_shutter_half_press) fselect_goto_prev(4);
                else fselect_goto_prev(1);
                gui_fselect_redraw = 1;
            }
            break;
        case KEY_DOWN:
        case JOGDIAL_RIGHT:
            if (selected)
            {
                if (camera_info.state.is_shutter_half_press) fselect_goto_next(4);
                else fselect_goto_next(1);
                gui_fselect_redraw = 1;
            }
            break;
        case KEY_ZOOM_OUT:
            if (selected)
            {
                fselect_goto_prev(BODY_LINES-1);
                gui_fselect_redraw = 1;
            }
            break;
        case KEY_ZOOM_IN:
            if (selected)
            {
                fselect_goto_next(BODY_LINES-1);
                gui_fselect_redraw = 1;
            }
            break;
        case KEY_RIGHT:
            if (selected)
            {
                fselect_marked_toggle();
                fselect_goto_next(1);
                gui_fselect_redraw = 1;
            }
            break;
        case KEY_LEFT:
            if (selected && selected->attr != 0xFF)
            {
                i=MPOPUP_CUT|MPOPUP_COPY|MPOPUP_SELINV|MPOPUP_MORE;
                mpopup_rawop_flag=0;
                if (fselect_marked_count() > 0)
                {
                    i |= MPOPUP_DELETE;
                    if ( fselect_marked_count()>1 )
                        mpopup_rawop_flag |=MPOPUP_RAW_ADD|MPOPUP_RAW_AVERAGE;
                    // doesn't make sense to subtract from itself!
                    if( selected->marked == 0 && fselect_real_marked_count() > 0)
                        mpopup_rawop_flag |= MPOPUP_SUBTRACT;
                }

                if (marked_operation == MARKED_OP_CUT || marked_operation == MARKED_OP_COPY)
                    i |= MPOPUP_PASTE;
                if (!(selected->attr & DOS_ATTR_DIRECTORY) || !(selected->name[0] == '.' && selected->name[1] == '.' && selected->name[2] == 0) ||//If item is not a folder or UpDir
                    (selected->name[0] == 'D' && selected->name[1] == 'C' && selected->name[2] == 'I' && selected->name[3] == 'M') ||//If item is DCIM folder
                    (selected->name[3] == 'C'))//If item is a DCIM sub folder
                    i |= MPOPUP_PURGE;//Display PURGE RAW function in popup menu
                if (selected->size >= camera_sensor.raw_size)
                    mpopup_rawop_flag |= MPOPUP_RAW_DEVELOP;

                if ((fselect_marked_count()>1)||(selected->size > camera_sensor.raw_size))
                    mpopup_rawop_flag |= MPOPUP_DNG_TO_CRW;

                if (selected->name[9] == 'B' && selected->name[10] == 'I' && selected->name[11] == 'N') //If item is DCIM folder
                    i |= MPOPUP_CHDK_REPLACE;

                if ( mpopup_rawop_flag )
                    i |= MPOPUP_RAWOPS;

                mpopup_more_flag = MPOPUP_MKDIR;
                if (selected->attr & DOS_ATTR_DIRECTORY)
                    mpopup_more_flag |=MPOPUP_RMDIR;
                if ( !(selected->name[0] == '.' && selected->name[1] == '.' && selected->name[2] == 0) ) //If item is not UpDir
                    mpopup_more_flag |=MPOPUP_RENAME;

                libmpopup->show_popup( popup, i, fselect_mpopup_cb);
            }
            break;
        case KEY_SET:
            if (selected && selected->attr != 0xFF && gui_fselect_redraw==0)
            {
                if (selected->attr & DOS_ATTR_DIRECTORY)
                {
                    i=strlen(current_dir);
                    if (selected->name[0]=='.' && selected->name[1]=='.' && selected->name[2]==0)
                    {
                        while (current_dir[--i] != '/');
                        current_dir[i]=0;
                    } else {
                        sprintf(current_dir+i, "/%s", selected->name);
                    }
                    gui_fselect_readdir = 1;
                    gui_fselect_redraw = 1;
                }
                else
                {
                    sprintf(selected_file, "%s/%s", current_dir, selected->name);

                    char *ext = strrchr(selected->name,'.');
                    int do_exit = 1;

                    if (!fselect_on_select)
                    {
                        if (chk_ext(ext,"txt") || chk_ext(ext,"log") || chk_ext(ext,"csv"))
                        {
                            exit_fselect(0);
                            do_exit = 0;
                    		libtxtread->read_file(selected_file);
                        }
                        else if (chk_ext(ext,"flt"))
                        {
                            exit_fselect(0);
                            do_exit = 0;
                    		module_run(selected_file);
                        }
                    }

                    if (do_exit)
                        exit_fselect(selected_file);
                }
            }
            break;
        case KEY_ERASE:
        case KEY_DISPLAY:
            if (selected && selected->attr != 0xFF)
            {
                if (selected->attr & DOS_ATTR_DIRECTORY)
                {
                    confirm_delete_directory();
                } else
                {
                    gui_mbox_init(LANG_BROWSER_DELETE_FILE_TITLE, LANG_BROWSER_DELETE_FILE_TEXT,
                                  MBOX_TEXT_CENTER|MBOX_BTN_YES_NO|MBOX_DEF_BTN2, fselect_delete_file_cb);
                }
            }
            break;
    }
    return 0;
}

void gui_fselect_kbd_process_menu_btn()
{
    // just free resource. callback called with NULL ptr
    exit_fselect(0);
}

// =========  MODULE INIT =================

/***************** BEGIN OF AUXILARY PART *********************
  ATTENTION: DO NOT REMOVE OR CHANGE SIGNATURES IN THIS SECTION
 **************************************************************/

//---------------------------------------------------------
// PURPOSE: Finalize module operations (close allocs, etc)
// RETURN VALUE: 0-ok, 1-fail
//---------------------------------------------------------
int _module_unloader()
{
    finalize_fselect();
    return 0;
}

int _module_can_unload()
{
    return running == 0;
}

int _module_exit_alt()
{
    exit_fselect(0);
    return 0;
}

/******************** Module Information structure ******************/

libfselect_sym _libfselect =
{
    {
        0, _module_unloader, _module_can_unload, _module_exit_alt, 0
    },

    gui_fselect_init
};

ModuleInfo _module_info = {
    MODULEINFO_V1_MAGICNUM,
    sizeof(ModuleInfo),
    GUI_FSELECT_VERSION,        // Module version

    ANY_CHDK_BRANCH, 0, OPT_ARCHITECTURE,         // Requirements of CHDK version
    ANY_PLATFORM_ALLOWED,       // Specify platform dependency

    -LANG_MENU_MISC_FILE_BROWSER,   // Module name
    0,

    &_libfselect.base,

    CONF_VERSION,               // CONF version
    CAM_SCREEN_VERSION,         // CAM SCREEN version
    CAM_SENSOR_VERSION,         // CAM SENSOR version
    CAM_INFO_VERSION,           // CAM INFO version
};

/*************** END OF AUXILARY PART *******************/
