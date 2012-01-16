#include "stdlib.h"
#include "keyboard.h"
#include "platform.h"
#include "core.h"
#include "conf.h"
#include "lang.h"
#include "gui.h"
#include "gui_draw.h"
#include "gui_lang.h"
#include "gui_mbox.h"

#include "module_load.h"

extern void gui_tbox_kbd_process();
extern void gui_tbox_draw(int enforce_redraw);

gui_handler GUI_MODE_TBOX =
    /*GUI_MODE_TBOX*/       { GUI_MODE_MODULE,   gui_tbox_draw,    gui_tbox_kbd_process,   gui_tbox_kbd_process, 0, GUI_MODE_MAGICNUM };

static gui_handler *gui_tbox_mode_old; // stored previous gui_mode
static int module_idx = -1;

static int gui_tbox_redraw;
static char text_limit_reached;
static int vkbd_txtfield_width=200;
static int vkbd_txtfield_height=75;

extern int module_idx;

static const char*  tbox_title;
static const char*  tbox_msg;
static char         cursor_to_draw;
static int          cl_greygrey;
static int          max_keyboard_lenght;
// height of prompt
#define MAX_LINES              6
#define MAX_WIDTH              40
#define SPACING_TITLE          4
#define SPACING_BTN            4
#define SPACING_BELOW_TEXT     10
#define BUTTON_SEP             18
#define BUTTON_SIZE            6

// max possible charsets
#define MAX_CHARSET            10
#define SUBGROUP_SEPARATOR     '|'

#define MAX_TEXT_WIDTH         (MAX_WIDTH-2)

#define RESET_CHAR             lastKey = '\0'; \
                               curchar = -1;

#define MAX_MSG_LENGH           20  //max length of hardcoded messages (>navigate cursor<, text limit reached)

typedef void (*tbox_on_select_t)(char* newstr);
tbox_on_select_t tbox_on_select = 0;

static coord    tbox_buttons_x, tbox_buttons_y;

//
const char *tbox_chars_default[] = {"ABCDEF|GHIJKL|MNOPQRS|TUVWXYZ",
                            "abcdef|ghijkl|mnopqrs|tuvwxyz",
                            "123|456|789|0+-=/",
                            ".,:;?!|@#$%^&|()[]{}|<>\"'`~",
                            0 };

const char *tbox_chars[MAX_CHARSET+1]; // current char map (array of string. separator of groups is '|')
int lines = 0;                         // num of valid lines in tbox_chars
int subgroup_offs[4];                  // offsets of subgroups in currently selected line of tbox_chars


int tbox_button_active, line;
int curchar;     // idx of current entered char in current tmap
int cursor;
char lastKey;    // Last pressed key (Left, Right, Up, Down)
char Mode;       // K=keyboard, T=textnavigate, B=button

char *text = 0;  // Entered text
int maxlen, offset;
coord text_offset_x, text_offset_y, key_offset_x;

//-------------------------------------------------------
static void tbox_charmap_init( char* buffer, int buffer_size)
{
  int i, size;

  lines=0;
  memset( tbox_chars, 0, sizeof(tbox_chars) );

  lines = 0;
  for ( i=0; i<buffer_size && lines<MAX_CHARSET;)
  {
     size = strlen(buffer+i);
     if ( size > 0 )
        tbox_chars[lines++]=(buffer+i);
        if (max_keyboard_lenght<size) max_keyboard_lenght=size;
     i+=size+1;
  }

  if ( lines>0 )
    return;


  for (lines=0;lines<MAX_CHARSET;lines++) {
    tbox_chars[lines] = tbox_chars_default[lines];
    if ( tbox_chars[lines]==0 )
      break;
    if (max_keyboard_lenght<strlen(tbox_chars[lines])) max_keyboard_lenght=strlen(tbox_chars[lines]);
  }
}

//-------------------------------------------------------
static void tbox_split_to_subgroups()
{
    int idx,i;

    memset(subgroup_offs, 0, sizeof(subgroup_offs));

    idx=1;
    for (i=0; tbox_chars[line][i] && idx<4; i++ ) {
        if (tbox_chars[line][i]==SUBGROUP_SEPARATOR)
          subgroup_offs[idx++]=i+1;
    }
}



void gui_tbox_init(int title, int msg, char* defaultstr, unsigned int maxsize, void (*on_select)(char* newstr)) {
    text = malloc(sizeof(char)*(maxsize+1));
    if ( text==0 ) {
        // fatal failure
        if (tbox_on_select)
            tbox_on_select(0);    // notify callback about exit as cancel
        module_async_unload(module_idx);
        return;
    }

    memset(text, '\0', sizeof(char)*(maxsize+1));

    if ( defaultstr )
        strncpy(text, defaultstr, maxsize);

    tbox_button_active = 0;

    tbox_title = lang_str(title);
    tbox_msg = lang_str(msg);
    tbox_on_select = on_select;
    gui_tbox_mode_old = gui_set_mode( &GUI_MODE_TBOX );

    Mode = 'K';
    line = 0;
    RESET_CHAR
    cursor = -1;
    maxlen = maxsize;
    offset = 0;
    tbox_split_to_subgroups();

    gui_tbox_redraw = 2;
}


static void gui_tbox_draw_buttons() {
    coord x = tbox_buttons_x;
    color cl;

    cl = MAKE_COLOR((tbox_button_active==0)?COLOR_RED:COLOR_BLACK, COLOR_WHITE);
    draw_rect(x-1, tbox_buttons_y-1, x+BUTTON_SIZE*FONT_WIDTH+3, tbox_buttons_y+FONT_HEIGHT+3, COLOR_BLACK); //shadow
    draw_filled_rect(x-2, tbox_buttons_y-2, x+BUTTON_SIZE*FONT_WIDTH+2, tbox_buttons_y+FONT_HEIGHT+2, cl);
    draw_string(x+(((BUTTON_SIZE-strlen(lang_str(LANG_MBOX_BTN_OK)))*FONT_WIDTH)>>1), tbox_buttons_y, lang_str(LANG_MBOX_BTN_OK), cl);
    x+=BUTTON_SIZE*FONT_WIDTH+BUTTON_SEP;

    cl = MAKE_COLOR((tbox_button_active==1)?COLOR_RED:COLOR_BLACK, COLOR_WHITE);
    draw_rect(x-1, tbox_buttons_y-1, x+BUTTON_SIZE*FONT_WIDTH+3, tbox_buttons_y+FONT_HEIGHT+3, COLOR_BLACK); //shadow
    draw_filled_rect(x-2, tbox_buttons_y-2, x+BUTTON_SIZE*FONT_WIDTH+2, tbox_buttons_y+FONT_HEIGHT+2, cl);
    draw_string(x+(((BUTTON_SIZE-strlen(lang_str(LANG_MBOX_BTN_CANCEL)))*FONT_WIDTH)>>1), tbox_buttons_y, lang_str(LANG_MBOX_BTN_CANCEL), cl);
    x+=BUTTON_SIZE*FONT_WIDTH+BUTTON_SEP;
}

void gui_tbox_draw(int enforce_redraw)
{
    if ((gui_tbox_redraw && !text_limit_reached) || gui_tbox_redraw == 2) {
        if (gui_tbox_redraw==2) {
            text_limit_reached = 0;
            char c[MAX_LINES][MAX_WIDTH+1];        // PROMPT PARSED
            const char *p=tbox_msg;
            coord x=0, y=0;
            unsigned int w, h=0, l=0, bw=(2*BUTTON_SIZE*FONT_WIDTH+BUTTON_SEP);

            memset(c,0,sizeof(c));

            w =strlen(tbox_title);
            if (w > MAX_WIDTH) w = MAX_WIDTH;
            while (*p) {
                if (*p == '\n') {
                    c[h++][l] = 0;
                    l=0;
                    if (h == MAX_LINES) break;
                } else {
                    if (l < MAX_WIDTH) {
                        c[h][l++]=*p;
                        if (l > w) w = l;
                    }
                }
                ++p;
            }
            w+=2;
            if (h<MAX_LINES)
                c[h++][l] = 0;
            if (bw+BUTTON_SEP>w*FONT_WIDTH)
                w=(bw+BUTTON_SEP)/FONT_WIDTH+1;
            if (w<max_keyboard_lenght)
                w=max_keyboard_lenght; // keyboard length
            if (w<MAX_MSG_LENGH)
                w=MAX_MSG_LENGH; // max message length
            if (w<maxlen) {
                if (maxlen < MAX_TEXT_WIDTH)
                    w=maxlen+2; // text length
                else
					w=((MAX_TEXT_WIDTH+2)>w)?MAX_TEXT_WIDTH+2:w;
            }
            h += 2;

            x = (camera_screen.width - w * FONT_WIDTH) >> 1;
            y = (camera_screen.height - (h+2) * FONT_HEIGHT-SPACING_BELOW_TEXT) >> 1;
            draw_rect_shadow(x-3, y-3, x+w*FONT_WIDTH+5, y+(h+2)*FONT_HEIGHT+SPACING_BTN+2+SPACING_TITLE+12, COLOR_BLACK, 3); //shadow
            draw_filled_rect_thick(x-4, y-4, x+w*FONT_WIDTH+4, y+(h+2)*FONT_HEIGHT+SPACING_BTN+2+SPACING_TITLE+11, MAKE_COLOR(COLOR_GREY, COLOR_WHITE), 3); // main box
            draw_filled_rect(x-2, y-2, x+w*FONT_WIDTH+2, y+FONT_HEIGHT+2, MAKE_COLOR(COLOR_BLACK, COLOR_WHITE)); //title

            l = strlen(tbox_title);
            draw_string(x+((w-l)>>1)*FONT_WIDTH, y, tbox_title, MAKE_COLOR(COLOR_BLACK, COLOR_WHITE)); //title text
            y+=FONT_HEIGHT+2+SPACING_TITLE;

            tbox_buttons_x = x+((w*FONT_WIDTH-bw)>>1);
            //tbox_buttons_y = y+h*FONT_HEIGHT+SPACING_BTN;

            text_offset_x = x+((w-((maxlen<MAX_TEXT_WIDTH)?maxlen:MAX_TEXT_WIDTH))>>1)*FONT_WIDTH;
            text_offset_y = y+(h-2)*FONT_HEIGHT+SPACING_BELOW_TEXT;
            key_offset_x = x+((w-strlen(tbox_chars[0]))>>1)*FONT_WIDTH;

            tbox_buttons_y = text_offset_y+FONT_HEIGHT+SPACING_BELOW_TEXT; // on place of symbol line

            // draw prompt
            while (h) {
                l = strlen(c[--h]);
                draw_string(x+(((w-l)>>1)*FONT_WIDTH), y+h*FONT_HEIGHT, c[h], MAKE_COLOR(COLOR_GREY, COLOR_WHITE));
            }

            if ( Mode == 'B' )
                gui_tbox_draw_buttons();
        }

        // draw edit field
        int i;
        for (i=offset; (i-offset)<((maxlen<MAX_TEXT_WIDTH)?maxlen:MAX_TEXT_WIDTH); i++) {
            draw_char(text_offset_x+(i-offset)*FONT_WIDTH, text_offset_y, (i<strlen(text))?text[i]:' ', MAKE_COLOR(COLOR_BLACK, COLOR_WHITE));
        }
        
        // draw long text marker
        if ((strlen(text)-offset)>MAX_TEXT_WIDTH) draw_char(text_offset_x+MAX_TEXT_WIDTH*FONT_WIDTH, text_offset_y, '\20', MAKE_COLOR(COLOR_GREY, COLOR_RED));
        else draw_char(text_offset_x+MAX_TEXT_WIDTH*FONT_WIDTH, text_offset_y, ' ', MAKE_COLOR(COLOR_GREY, COLOR_GREY));
        if (offset>0) draw_char(text_offset_x-FONT_WIDTH, text_offset_y, '\21', MAKE_COLOR(COLOR_GREY, COLOR_RED));
        else draw_char(text_offset_x-FONT_WIDTH, text_offset_y, ' ', MAKE_COLOR(COLOR_GREY, COLOR_GREY));

        // symbol line
        if ( Mode== 'T' )
        {
            //rect clears any previous message
            draw_filled_rect(key_offset_x+((strlen(tbox_chars[0])-MAX_MSG_LENGH)>>1)*FONT_WIDTH, tbox_buttons_y, 
                             key_offset_x+((strlen(tbox_chars[0])+MAX_MSG_LENGH)>>1)*FONT_WIDTH, tbox_buttons_y+FONT_HEIGHT, MAKE_COLOR(COLOR_GREY,COLOR_GREY));
            draw_string(key_offset_x+((strlen(tbox_chars[0])-17)>>1)*FONT_WIDTH, tbox_buttons_y, ">navigate cursor<", MAKE_COLOR(COLOR_GREY, COLOR_WHITE));
        }
        else if ( Mode == 'K' )
        {
            // draw keyboard
            char ch;
            color cl;
            int offs;

            // clean previous symbols line

            int pline = (line == 0)?lines:line-1;
            offs=(camera_screen.width - strlen(tbox_chars[pline])*FONT_WIDTH)>>1;
            //Don't try to do this as below. Just doesn't work properly!
            //offs = ((strlen(tbox_chars[0])-strlen(tbox_chars[pline]))*FONT_WIDTH)>>1;
            for(i = 0; (tbox_chars[pline][i] != '\0'); i++)
                draw_char(offs+i*FONT_WIDTH, tbox_buttons_y, tbox_chars[pline][i], cl_greygrey);

            // draw current symbols line

            offs=(camera_screen.width - strlen(tbox_chars[line])*FONT_WIDTH)>>1;
            //offs = ((strlen(tbox_chars[0])-strlen(tbox_chars[line]))*FONT_WIDTH)>>1;
            for(i = 0; (tbox_chars[line][i] != '\0'); i++) {
                ch = tbox_chars[line][i];

                if ( i!=curchar )
                    cl = MAKE_COLOR(COLOR_GREY, COLOR_WHITE);
                else if ( tbox_chars[line][i]!=' ' )
                    cl = MAKE_COLOR(COLOR_GREY, COLOR_RED);
                else
                    cl = MAKE_COLOR(COLOR_RED,COLOR_GREY);    // "space" is special color case (inverted)

                if ( ch==SUBGROUP_SEPARATOR )    // replace separator to more visual obvious
                    ch=6;

                draw_char(offs+i*FONT_WIDTH, tbox_buttons_y, ch, cl);
            }
        }
        gui_tbox_redraw = 0;
    }
    if (text_limit_reached) {
        // clean max_keyboard_lengt chars long field
        if (text_limit_reached%4 == 0)
            draw_filled_rect(key_offset_x+((strlen(tbox_chars[0])-max_keyboard_lenght)>>1)*FONT_WIDTH, tbox_buttons_y, 
                             key_offset_x+max_keyboard_lenght*FONT_WIDTH, tbox_buttons_y+FONT_HEIGHT, MAKE_COLOR(COLOR_GREY, COLOR_GREY));
        draw_string(key_offset_x+((strlen(tbox_chars[0])-18)>>1)*FONT_WIDTH, tbox_buttons_y, "text limit reached", MAKE_COLOR(COLOR_GREY, COLOR_RED));
        text_limit_reached--;
    }
    if (cursor_to_draw) {
        draw_line(text_offset_x+(1+cursor-offset)*FONT_WIDTH, text_offset_y+1, text_offset_x+(1+cursor-offset)*FONT_WIDTH, text_offset_y+FONT_HEIGHT-3, MAKE_COLOR(COLOR_GREY, COLOR_YELLOW));
        cursor_to_draw = 0;
    }
    else {
        draw_line(text_offset_x+(1+cursor-offset)*FONT_WIDTH, text_offset_y+1, text_offset_x+(1+cursor-offset)*FONT_WIDTH, text_offset_y+FONT_HEIGHT-3, cl_greygrey);
        cursor_to_draw = 1;
    }
}

static void tbox_move_cursor(int direction)
{
    if (direction<0) {
        if (cursor >= 0) {
            cursor--;
            if (maxlen>MAX_TEXT_WIDTH && offset != 0 && cursor<offset)
                offset--;
        }
    }

    if (direction>0) {
        if (cursor < (maxlen-1)) {
            cursor++;
            if (maxlen>MAX_TEXT_WIDTH && (cursor-offset)>=MAX_TEXT_WIDTH)
                offset++;
        }
    }
    gui_tbox_redraw = 1;
}

static void tbox_move_text(int direction) {
    int i;
    if (direction<0) {
        //This loop moves all characters on the right of the cursor one place left
        for (i=cursor; i<strlen(text); i++) {
            text[i]=text[i+1];
        }
    }

    if (direction>0) {
        //This loop moves all characters on the right of the cursor one place right
        for (i=(strlen(text) < maxlen-1)?strlen(text):maxlen-1; i>cursor; i--) {
            text[i]=text[i-1];
        }
    }
    gui_tbox_redraw = 1;
}

static void tbox_keyboard_key(char curKey, int subgroup)
{
    if (curKey == 'b') {
        if (cursor >= 0) {
            tbox_move_text(-1);
            if (strlen(text)>=MAX_TEXT_WIDTH && (cursor-offset)>=MAX_TEXT_WIDTH-1) offset--;
            tbox_move_cursor(-1);
            RESET_CHAR
        }
    }
    else if (lastKey == curKey) {
        curchar++;
        if (tbox_chars[line][curchar] == SUBGROUP_SEPARATOR || tbox_chars[line][curchar]==0) {
            curchar=subgroup_offs[subgroup];
        }
        text[cursor] = tbox_chars[line][curchar];
    }
    else if (curKey == 's') {
        if (strlen(text)<maxlen) {
            if (text[cursor+1] != '\0') tbox_move_text(1); //check wheter cursor is at the end of the string
            tbox_move_cursor(1);
            text[cursor] = ' ';
            RESET_CHAR
        }
        else {
            text_limit_reached = 8;
            RESET_CHAR
        }
    }
    else if (curKey == 'O') {
        RESET_CHAR
    }
    else {
        if (strlen(text)<maxlen) {
            curchar = subgroup_offs[subgroup];
            if (cursor < (maxlen-1)) {
                if (text[cursor+1] != '\0') tbox_move_text(1); //check wheter cursor is at the end of the string
                tbox_move_cursor(1);
            }
            lastKey = curKey;
            text[cursor] = tbox_chars[line][curchar];
        }
        else { 
            text_limit_reached = 8;
            RESET_CHAR
        }
    }
    gui_tbox_redraw = 1;
}

void gui_tbox_kbd_process()
{
    if (Mode == 'K') {
        switch (kbd_get_autoclicked_key() | get_jogdial_direction()) {
            case KEY_SHOOT_HALF:
                line = (line+1)%lines;
                RESET_CHAR
                tbox_split_to_subgroups();
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
                tbox_keyboard_key('s',0); //space
                break;
            case KEY_ZOOM_OUT:
                tbox_keyboard_key('b',0); //backspace
                break;
            case JOGDIAL_LEFT:
                tbox_move_cursor(-1);
                RESET_CHAR
                break;
            case JOGDIAL_RIGHT:
                if (text[cursor+1] != '\0') tbox_move_cursor(1);
                RESET_CHAR
                break;
            case KEY_MENU:
                Mode = 'T';
                gui_tbox_redraw=2;
                break;
        }
    }
    else if (Mode == 'T') {
        switch (kbd_get_autoclicked_key() | get_jogdial_direction()) {
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
                tbox_keyboard_key('b',0);   //backspace - for non-zoom cameras?
                break;
            case KEY_DISPLAY:
                tbox_keyboard_key('s',0);   //space            -,,-
                break;
            case KEY_ZOOM_IN:
                if (offset<(strlen(text)-MAX_TEXT_WIDTH)) {
                    offset++;
                    if ((cursor+1)<offset) cursor++;
                    gui_tbox_redraw = 1;
                }
                break;
            case KEY_ZOOM_OUT:
                if (offset > 0) {
                    offset--;
                    if ((cursor-offset)>=MAX_TEXT_WIDTH) cursor--;
                    gui_tbox_redraw = 1;
                }
                break;
            case KEY_MENU:
                Mode = 'B';
                gui_tbox_redraw=2;
                break;
        }
    }
    else { // Mode == 'B'
        switch (kbd_get_autoclicked_key() | get_jogdial_direction()) {
            case JOGDIAL_LEFT:
            case KEY_LEFT:
                if (tbox_button_active > 0) tbox_button_active = 0;
                else tbox_button_active = 1;
                gui_tbox_draw_buttons();
                break;
            case JOGDIAL_RIGHT:
            case KEY_RIGHT:
                if (tbox_button_active <= 0) tbox_button_active = 1;
                else tbox_button_active = 0;
                gui_tbox_draw_buttons();
                break;
            case KEY_SET:
                kbd_reset_autoclicked_key();
                gui_set_mode(gui_tbox_mode_old);
                draw_restore();
                if (tbox_on_select) {
                    if (tbox_button_active == 0)
                         tbox_on_select(text); // ok
                    else {
                        free(text);
                        tbox_on_select(0); // cancel
                    }
                    text=0;
                }
                  module_async_unload(module_idx);
                break;
            case KEY_MENU:
                Mode = 'K';
                gui_tbox_redraw=2;
                break;
        }
    }
}


// DEBUG TEST CALLBACK
void test_callback(char* txt )
{
    if ( txt==0 )    // cancel
    {
        gui_mbox_init(139, 139, MBOX_BTN_OK|MBOX_TEXT_CENTER, NULL);
    }
    else        //ok
    {
        gui_mbox_init(138, (int)txt, MBOX_BTN_OK|MBOX_TEXT_CENTER, NULL);
        // should be free in real callback but here should be kept to correct mbox
    }
}


//==================================================


//---------------------------------------------------------
// PURPOSE:   Bind module symbols with chdk.
//        Required function
// PARAMETERS: pointer to chdk list of export
// RETURN VALUE: 1 error, 0 ok
//---------------------------------------------------------
int _module_loader( void** chdk_export_list )
{
  if ( (unsigned int)chdk_export_list[0] != EXPORTLIST_MAGIC_NUMBER )
     return 1;

  if ( !API_VERSION_MATCH_REQUIREMENT( gui_version.common_api, 1, 0 ) )
      return 1;

  cl_greygrey = MAKE_COLOR(COLOR_GREY, COLOR_GREY);

  return 0;
}



//---------------------------------------------------------
// PURPOSE: Finalize module operations (close allocs, etc)
// RETURN VALUE: 0-ok, 1-fail
//---------------------------------------------------------
int _module_unloader()
{
    // clean allocated resource
    if ( text!=0 ) {
        free(text);
        if (tbox_on_select)
            tbox_on_select(0);    // notify callback about exit as cancel
    }


    //sanity clean to prevent accidentaly assign/restore guimode to unloaded module
    GUI_MODE_TBOX.magicnum = 0;

    return 0;
}


//---------------------------------------------------------
// PURPOSE: Default action for simple modules (direct run)
// NOTE: Please comment this function if no default action and this library module
//---------------------------------------------------------
int _module_run(int moduleidx, int argn, int* arguments)
{
  module_idx=moduleidx;


  // DEBUG CASE
  if ( argn==0 ) {
      tbox_charmap_init( 0,0 );

        gui_tbox_init( 137 /*title*/, 137 /*msg*/, (char*)NULL /*defaultstr*/,
                 50 /*maxsize*/, test_callback /* on_select */);
    return 0;

  }

  // "Run scenario #1" - no arguments request for keyboard API version
  if ( argn!=7 || arguments==0 || arguments[6]==0)
  {
    module_async_unload(moduleidx);
    return MAKE_API_VERSION(1,0);
  }

  // Autounloading is unsafe because it should exists to catch finalization of mpopup
  //module_set_flags(module_idx, MODULE_FLAG_DISABLE_AUTOUNLOAD);

  tbox_charmap_init( (char*)arguments[0] /*charmap_buffer*/, arguments[1] /*charmap_size*/);

  gui_tbox_init( arguments[2] /*title*/, arguments[3] /*msg*/, (char*)arguments[4] /*defaultstr*/,
                 arguments[5] /*maxsize*/, (tbox_on_select_t) arguments[6] /* on_select */);

  return 0;
}


/******************** Module Information structure ******************/

struct ModuleInfo _module_info = {    MODULEINFO_V1_MAGICNUM,
                                    sizeof(struct ModuleInfo),

                                    ANY_CHDK_BRANCH, 0,            // Requirements of CHDK version
                                    ANY_PLATFORM_ALLOWED,        // Specify platform dependency
                                    0,    // MODULEINFO_FLAG_SYSTEM,            // flag
                                    (int32_t)"Virtual keyboard",    // Module name
                                    1, 0,                        // Module version
                                    0
                                 };
