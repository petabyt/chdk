#include "camera_info.h"
#include "stdlib.h"
#include "keyboard.h"
#include "conf.h"
#include "lang.h"
#include "gui.h"
#include "gui_draw.h"
#include "gui_lang.h"
#include "gui_mbox.h"

#include "gui_tbox.h"
#include "module_def.h"

//-------------------------------------------------------------------
int gui_tbox_kbd_process();
void gui_tbox_kbd_process_menu_btn();
void gui_tbox_draw();

gui_handler GUI_MODE_TBOX =
    /*GUI_MODE_TBOX*/ { GUI_MODE_MODULE, gui_tbox_draw, gui_tbox_kbd_process, gui_tbox_kbd_process_menu_btn, 0, 0 };

static gui_handler *gui_tbox_mode_old; // stored previous gui_mode
static int running = 0;

static int gui_tbox_redraw;
static char text_limit_reached;

static const char*  tbox_title;
static const char*  tbox_msg;
static char         cursor_to_draw;

// height of prompt
#define MAX_LINES               6
#define MAX_WIDTH               40
#define MIN_WIDTH               28
#define SPACING_TITLE           4
#define SPACING_BTN             4
#define SPACING_BELOW_TEXT      10
#define BUTTON_SEP              18
#define BUTTON_SIZE             6
#define BUTTON_AREA_WIDTH       (2*BUTTON_SIZE*FONT_WIDTH+BUTTON_SEP)
#define BUTTON_CHAR_WIDTH       ((BUTTON_AREA_WIDTH + BUTTON_SEP) / FONT_WIDTH + 1)

#define MAX_TEXT_WIDTH          (MAX_WIDTH-2)

#define RESET_CHAR              lastKey = '\0'; curchar = -1; curgroup = -1;

#define MAX_MSG_LENGTH          20  //max length of hardcoded messages (>navigate cursor<, text limit reached)

typedef void (*tbox_on_select_t)(const char* newstr);
tbox_on_select_t tbox_on_select = 0;

static coord    tbox_buttons_x, tbox_buttons_y;

typedef char    *cmap[][4];

// Char maps
cmap tbox_chars_default = 
    {
        {"ABCDEF","GHIJKL","MNOPQRS","TUVWXYZ"},
        {"abcdef","ghijkl","mnopqrs","tuvwxyz"},
        {"123","456","789","0+-=/"},
        {".,:;?!","@#$%^&£","()[]{}","<>\"'`~_"},
        {0}
    };

cmap tbox_chars_german = 
    {
        {"ABCDEF","GHIJKL","MNOPQRS","TUVWXYZ"},
        {"abcdef","ghijkl","mnopqrs","tuvwxyz"},
        {"123","456","789","0+-=/"},
        {".,:;?!","@#$%^&£","()[]{}","<>\"'`~_"},
        {"ÄÖÜ","äöüß","€§µ","°²³"},
        {0}
    };

cmap tbox_chars_russian =
    {
        {"ABCDEF","GKLHIJ","MNOPQRS","TUVWXYZ"},
        {"abcdef","ghijkl","mnopqrs","tuvwxyz"},
        {"ÀÁÂÃÄÅÆ","ÇÈÉÊËÌÍ","ÎÏÐÑÒÓÔ","ÕÖ×ØÙÛÜÝÞß"},
        {"àáâãäåæ","çèéêëìí","îïðñòóô","õö÷øùûüýþÿ"},
        {"123","456","789","0+-="},
        {" .:,",";/\\","'\"*","#%&"},
        {0}
    };

cmap *charmaps[] = { &tbox_chars_default, &tbox_chars_german, &tbox_chars_russian };

int lines = 0;                  // num of valid lines in active charmap

int tbox_button_active, line;
int curchar;                    // idx of current entered char in current tmap
int curgroup;
int cursor;
char lastKey;                   // Last pressed key (Left, Right, Up, Down)

#define MODE_KEYBOARD   0
#define MODE_NAVIGATE   1
#define MODE_BUTTON     2
char Mode;                      // K=keyboard, T=textnavigate, B=button

char text_buf[MAX_TEXT_SIZE+1]; // Default buffer if not supplied by caller
char *text = 0;                 // Entered text
int maxlen, offset, fldlen, window_width;
coord text_offset_x, text_offset_y, key_offset_x;
static int tbox_width, tbox_height;     //size of the 'window'

//-------------------------------------------------------
static char *map_chars(int line, int group)
{
    return (*charmaps[conf.tbox_char_map])[line][group];
}

//-------------------------------------------------------
int textbox_init(int title, int msg, const char* defaultstr, unsigned int maxsize, void (*on_select)(const char* newstr), char *input_buffer)
{
    running = 1;

    if (input_buffer)
        text = input_buffer;
    else
    {
        if (maxsize > MAX_TEXT_SIZE) maxsize = MAX_TEXT_SIZE;
        text = text_buf;
    }

    // Count number of entries in selected 'charmap'
    for (lines=0; map_chars(lines,0); lines++) ;

    memset(text, '\0', sizeof(char)*(maxsize+1));

    if ( defaultstr )
        strncpy(text, defaultstr, maxsize);

    tbox_button_active = 0;

    tbox_title = lang_str(title);
    tbox_msg = lang_str(msg);
    tbox_on_select = on_select;

    Mode = MODE_KEYBOARD;
    line = 0;
    RESET_CHAR
    cursor = -1;
    maxlen = maxsize;
    fldlen = (maxlen < MAX_TEXT_WIDTH) ? maxlen : MAX_TEXT_WIDTH; // length of edit field
    offset = 0;

    tbox_width = strlen(tbox_title);
    if (tbox_width < BUTTON_CHAR_WIDTH)
        tbox_width = BUTTON_CHAR_WIDTH;
    if (tbox_width < MIN_WIDTH)
        tbox_width = MIN_WIDTH;         // keyboard length
    if (tbox_width < MAX_MSG_LENGTH)
        tbox_width = MAX_MSG_LENGTH;    // max message length
    if (tbox_width < maxlen)
    {
        if (maxlen < MAX_TEXT_WIDTH)
            tbox_width = maxlen + 2;    // text length
        else if (tbox_width < MAX_WIDTH)
            tbox_width = MAX_WIDTH;
    }

    tbox_height = MAX_LINES;
    tbox_width = text_dimensions(tbox_msg, tbox_width, MAX_WIDTH, &tbox_height) + 2;

    gui_tbox_redraw = 2;
    gui_tbox_mode_old = gui_set_mode( &GUI_MODE_TBOX );

    return 1;
}

static void gui_tbox_draw_buttons()
{
    draw_button(tbox_buttons_x, tbox_buttons_y+FONT_HEIGHT, BUTTON_SIZE, LANG_MBOX_BTN_OK, (tbox_button_active == 0));
    draw_button(tbox_buttons_x + (BUTTON_SIZE*FONT_WIDTH+BUTTON_SEP), tbox_buttons_y+FONT_HEIGHT, BUTTON_SIZE, LANG_MBOX_BTN_CANCEL, (tbox_button_active == 1));
}

void gui_tbox_draw()
{
    if ((gui_tbox_redraw && !text_limit_reached) || gui_tbox_redraw == 2)
    {
        if (gui_tbox_redraw==2)
        {
            text_limit_reached = 0;
            
            key_offset_x = (camera_screen.width - tbox_width*FONT_WIDTH) >> 1;

            coord x = (camera_screen.width - tbox_width * FONT_WIDTH) >> 1;
            coord y = (camera_screen.height - (tbox_height+6) * FONT_HEIGHT-SPACING_BELOW_TEXT) >> 1;
            draw_rectangle(x-4, y-4, x+tbox_width*FONT_WIDTH+4, y+(tbox_height+6)*FONT_HEIGHT+SPACING_BTN+2+SPACING_TITLE+11,
                           MAKE_COLOR(COLOR_GREY, COLOR_WHITE), RECT_BORDER3|DRAW_FILLED|RECT_SHADOW3); // main box
            draw_rectangle(x-2, y-2, x+tbox_width*FONT_WIDTH+2, y+FONT_HEIGHT+2, MAKE_COLOR(COLOR_BLACK, COLOR_WHITE), RECT_BORDER1|DRAW_FILLED); //title

            draw_text_justified(x, y, tbox_title, MAKE_COLOR(COLOR_BLACK, COLOR_WHITE), tbox_width, 1, TEXT_CENTER); //title text
            y += FONT_HEIGHT+2+SPACING_TITLE;

            // draw prompt
            draw_text_justified(x, y, tbox_msg, MAKE_COLOR(COLOR_GREY, COLOR_WHITE), tbox_width, MAX_LINES, TEXT_CENTER);

            text_offset_x = x+((tbox_width-fldlen)>>1)*FONT_WIDTH;
            text_offset_y = y+(tbox_height*FONT_HEIGHT)+SPACING_BELOW_TEXT;

            tbox_buttons_x = x+((tbox_width*FONT_WIDTH-BUTTON_AREA_WIDTH)>>1);
            tbox_buttons_y = text_offset_y+FONT_HEIGHT+SPACING_BELOW_TEXT; // on place of symbol line

            if (Mode == MODE_BUTTON)
                gui_tbox_draw_buttons();
        }

        // draw edit field
        draw_string_justified(text_offset_x, text_offset_y, text+offset, MAKE_COLOR(COLOR_BLACK, COLOR_WHITE), 0, fldlen*FONT_WIDTH, TEXT_LEFT|TEXT_FILL);
        
        // draw long text marker
        draw_char(text_offset_x+fldlen*FONT_WIDTH, text_offset_y, ((strlen(text)-offset)>fldlen) ? '\20' : ' ', MAKE_COLOR(COLOR_GREY, COLOR_RED));
        draw_char(text_offset_x-FONT_WIDTH, text_offset_y, (offset>0) ? '\21' : ' ', MAKE_COLOR(COLOR_GREY, COLOR_RED));

        // symbol line
        if (Mode == MODE_NAVIGATE)
        {
            //rect clears any previous message
            draw_rectangle(key_offset_x+((tbox_width-MAX_MSG_LENGTH)>>1)*FONT_WIDTH, tbox_buttons_y,
                           key_offset_x+((tbox_width+MAX_MSG_LENGTH)>>1)*FONT_WIDTH, tbox_buttons_y+3*FONT_HEIGHT, MAKE_COLOR(COLOR_GREY,COLOR_GREY), RECT_BORDER0|DRAW_FILLED);
            draw_text_justified(key_offset_x, tbox_buttons_y+FONT_HEIGHT, ">navigate cursor<", MAKE_COLOR(COLOR_GREY, COLOR_WHITE), tbox_width, 1, TEXT_CENTER);
        }
        else if (Mode == MODE_KEYBOARD)
        {
            // draw keyboard
            // clean previous symbols line
            draw_rectangle(key_offset_x, tbox_buttons_y, key_offset_x+(tbox_width-1)*FONT_WIDTH, tbox_buttons_y+3*FONT_HEIGHT, MAKE_COLOR(COLOR_GREY, COLOR_GREY), RECT_BORDER0|DRAW_FILLED);

            // draw current symbols line
            int group;
            static int y_offset[4] = { FONT_HEIGHT, 0, FONT_HEIGHT, 2*FONT_HEIGHT };
            static int x_just[4] = { TEXT_LEFT, TEXT_CENTER, TEXT_RIGHT, TEXT_CENTER };

            for (group = 0; group < 4; group++)
            {
                char *tstr = map_chars(line,group);

                int y = tbox_buttons_y + y_offset[group];
                int x = key_offset_x + 4*FONT_WIDTH;

                x = draw_text_justified(x, y, tstr, MAKE_COLOR(COLOR_GREY, COLOR_WHITE), tbox_width-8, 1, x_just[group]);
                if ((group == curgroup) && (curchar >= 0))
                    draw_char(x+(curchar*FONT_WIDTH), y, tstr[curchar], MAKE_COLOR(COLOR_RED, COLOR_WHITE));    // Selected char cursor
            }
        }
        gui_tbox_redraw = 0;
    }

    if (text_limit_reached)
    {
        // clean max_keyboard_length chars long field
        if (text_limit_reached%4 == 0)
            draw_rectangle(key_offset_x+3, tbox_buttons_y,
                           key_offset_x+tbox_width*FONT_WIDTH-3, tbox_buttons_y+3*FONT_HEIGHT, MAKE_COLOR(COLOR_GREY, COLOR_GREY), RECT_BORDER0|DRAW_FILLED);
        draw_text_justified(key_offset_x, tbox_buttons_y+FONT_HEIGHT, "text limit reached", MAKE_COLOR(COLOR_GREY, COLOR_RED), tbox_width, 1, TEXT_CENTER);
        text_limit_reached--;
    }

    // Insertion point cursor
    draw_line(text_offset_x+(1+cursor-offset)*FONT_WIDTH, text_offset_y+1, text_offset_x+(1+cursor-offset)*FONT_WIDTH, text_offset_y+FONT_HEIGHT-3, cursor_to_draw ? COLOR_YELLOW : COLOR_GREY);
    cursor_to_draw = !cursor_to_draw;
}

static void tbox_move_cursor(int direction)
{
    draw_line(text_offset_x+(1+cursor-offset)*FONT_WIDTH, text_offset_y+1, text_offset_x+(1+cursor-offset)*FONT_WIDTH, text_offset_y+FONT_HEIGHT-3, COLOR_BLACK);
    if (direction < 0)
    {
        if (cursor >= 0)
        {
            cursor--;
            if (maxlen>MAX_TEXT_WIDTH && offset != 0 && cursor<offset)
                offset--;
        }
    }
    if (direction > 0)
    {
        if (cursor < (maxlen-1))
        {
            cursor++;
            if (maxlen>MAX_TEXT_WIDTH && (cursor-offset)>=MAX_TEXT_WIDTH)
                offset++;
        }
    }
    gui_tbox_redraw = 1;
}

static void tbox_move_text(int direction)
{
    int i;
    if (direction < 0)
    {
        //This loop moves all characters on the right of the cursor one place left
        for (i=cursor; i<strlen(text); i++)
        {
            text[i] = text[i+1];
        }
    }
    if (direction > 0)
    {
        //This loop moves all characters on the right of the cursor one place right
        for (i=(strlen(text) < maxlen-1)?strlen(text):maxlen-1; i>cursor; i--)
        {
            text[i] = text[i-1];
        }
    }
    gui_tbox_redraw = 1;
}

static void insert_space()
{
    if (strlen(text) < maxlen)
    {
        if (text[cursor+1] != '\0')
            tbox_move_text(1); //check whether cursor is at the end of the string
        tbox_move_cursor(1);
        text[cursor] = ' ';
    }
    else
    {
        text_limit_reached = 8;
    }
    RESET_CHAR
}

static void backspace()
{
    if (cursor >= 0)
    {
        tbox_move_text(-1);
        tbox_move_cursor(-1);
        if ((strlen(text) >= MAX_TEXT_WIDTH) && ((cursor-offset) >= MAX_TEXT_WIDTH-1))
            offset--;
        RESET_CHAR
    }
}

static void tbox_keyboard_key(char curKey, int subgroup)
{
    if (lastKey == curKey)
    {
        curchar++;
        curgroup = subgroup;
        char *tstr = map_chars(line,subgroup);
        if (tstr[curchar] == 0) curchar = 0;
        text[cursor] = tstr[curchar];
    }
    else if (curKey == 'O')
    {
        RESET_CHAR
    }
    else
    {
        if (strlen(text)<maxlen)
        {
            curchar = 0; curgroup = subgroup;
            if (cursor < (maxlen-1))
            {
                if (text[cursor+1] != '\0') tbox_move_text(1); //check whether cursor is at the end of the string
                tbox_move_cursor(1);
            }
            lastKey = curKey;
            char *tstr = map_chars(line,subgroup);
            text[cursor] = tstr[curchar];
        }
        else
        {
            text_limit_reached = 8;
            RESET_CHAR
        }
    }
    gui_tbox_redraw = 1;
}

void gui_tbox_kbd_process_menu_btn()
{
    Mode = (Mode + 1) % 3;
    gui_tbox_redraw=2;
}

int gui_tbox_kbd_process()
{
    if (Mode == MODE_KEYBOARD)
    {
        switch (kbd_get_autoclicked_key() | get_jogdial_direction())
        {
            case KEY_SHOOT_HALF:
                line = (line+1)%lines;
                RESET_CHAR
                gui_tbox_redraw = 1;
                break;
            case KEY_UP:
                tbox_keyboard_key('U',1);
                break;
            case KEY_DOWN:
                tbox_keyboard_key('D',3);
                break;
            case KEY_LEFT:
                tbox_keyboard_key('L',0);
                break;
            case KEY_RIGHT:
                tbox_keyboard_key('R',2);
                break;
            case KEY_SET:
                tbox_keyboard_key('O',0);
                break;
            case KEY_ZOOM_IN:
            case KEY_DISPLAY:
                insert_space();
                break;
            case KEY_ZOOM_OUT:
                backspace();
                break;
            case JOGDIAL_LEFT:
                tbox_move_cursor(-1);
                RESET_CHAR
                break;
            case JOGDIAL_RIGHT:
                if (text[cursor+1] != '\0') tbox_move_cursor(1);
                RESET_CHAR
                break;
        }
    }
    else if (Mode == MODE_NAVIGATE)
    {
        switch (kbd_get_autoclicked_key() | get_jogdial_direction())
        {
            case JOGDIAL_LEFT:
            case KEY_LEFT:
                tbox_move_cursor(-1);
                RESET_CHAR
                break;
            case JOGDIAL_RIGHT:
            case KEY_RIGHT:
                if (text[cursor+1] != '\0') tbox_move_cursor(1);
                RESET_CHAR
                break;
            case KEY_SHOOT_HALF:
                backspace();
                break;
            case KEY_DISPLAY:
                insert_space();
                break;
            case KEY_ZOOM_IN:
                if (offset<(strlen(text)-MAX_TEXT_WIDTH))
                {
                    offset++;
                    if ((cursor+1)<offset) cursor++;
                    gui_tbox_redraw = 1;
                }
                break;
            case KEY_ZOOM_OUT:
                if (offset > 0)
                {
                    offset--;
                    if ((cursor-offset)>=MAX_TEXT_WIDTH) cursor--;
                    gui_tbox_redraw = 1;
                }
                break;
        }
    }
    else { // Mode == MODE_BUTTON
        switch (kbd_get_autoclicked_key() | get_jogdial_direction())
        {
            case JOGDIAL_LEFT:
            case JOGDIAL_RIGHT:
            case KEY_LEFT:
            case KEY_RIGHT:
                tbox_button_active = !tbox_button_active;
                gui_tbox_draw_buttons();
                break;
            case KEY_SET:
                gui_set_mode(gui_tbox_mode_old);
                if (tbox_on_select)
                {
                    if (tbox_button_active == 0)
                        tbox_on_select(text);   // ok
                    else
                        tbox_on_select(0);      // cancel
                    tbox_on_select = 0;         // Prevent unloader from calling this function again
                }
                running = 0;
                break;
        }
    }
    return 0;
}

//==================================================

//---------------------------------------------------------
// PURPOSE: Finalize module operations (close allocs, etc)
// RETURN VALUE: 0-ok, 1-fail
//---------------------------------------------------------
int _module_unloader()
{
    // clean allocated resource
    if (tbox_on_select)
    {
        tbox_on_select(0);      // notify callback about exit as cancel
        tbox_on_select = 0;     // prevent calling twice in the (unlikely) event of the unload called twice
    }

    return 0;
}

int _module_can_unload()
{
    return running == 0;
}

int _module_exit_alt()
{
    running = 0;
    return 0;
}

/******************** Module Information structure ******************/

libtextbox_sym _libtextbox =
{
    {
         0, _module_unloader, _module_can_unload, _module_exit_alt, 0
    },

    textbox_init,
};

ModuleInfo _module_info =
{
    MODULEINFO_V1_MAGICNUM,
    sizeof(ModuleInfo),
    GUI_TBOX_VERSION,           // Module version

    ANY_CHDK_BRANCH, 0, OPT_ARCHITECTURE,         // Requirements of CHDK version
    ANY_PLATFORM_ALLOWED,       // Specify platform dependency

    (int32_t)"Virtual keyboard",
    MTYPE_EXTENSION,

    &_libtextbox.base,

    CONF_VERSION,               // CONF version
    CAM_SCREEN_VERSION,         // CAM SCREEN version
    ANY_VERSION,                // CAM SENSOR version
    ANY_VERSION,                // CAM INFO version
};
