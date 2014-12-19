#include "camera_info.h"
#include "stdlib.h"
#include "conf.h"
#include "gui.h"
#include "gui_lang.h"
#include "gui_menu.h"
#include "fileutil.h"

#include "script_api.h"
#include "gui_fselect.h"

// Forward reference
static void gui_update_script_submenu();

//-------------------------------------------------------------------

#define SCRIPT_DEFAULT_FILENAME     "A/SCRIPT.LUA"
#define SCRIPT_DATA_PATH            "A/CHDK/DATA/"
#define SCRIPT_DEFAULT_DIR          "A/CHDK/SCRIPTS/"

// Requested filename
enum FilenameMakeModeEnum {
    MAKE_PARAMSETNUM_FILENAME,      // "DATA/scriptname.cfg"
    MAKE_PARAM_FILENAME,            // "DATA/scriptname_%d"
    MAKE_PARAM_FILENAME_V2          // "DATA/scriptname.$d"
};

//-------------------------------------------------------------------

const char *script_source_str=NULL;         // ptr to content of script

static const char *lua_script_default =
    "--[[\n"
    "@title Default Script\n"
    "]]\n"
#if defined(VER_CHDK)
    "chdk_def_lang=1\n"
#else
    "chdk_def_lang=2\n"
#endif
    "langs     = {}\n"
    "langs[1]  = {[\"name\"]=\"ENGLISH\", [\"font_cp\"]=0, [\"hint\"]=\"CHDK language changed to english\"}\n"
    "langs[2]  = {[\"name\"]=\"GERMAN\",  [\"font_cp\"]=2, [\"hint\"]=\"CHDK-Sprache auf deutsch geändert\"}\n"
    "langs[13] = {[\"name\"]=\"RUSSIAN\", [\"font_cp\"]=1, [\"hint\"]=\"CHDK language changed to russian\"}\n"
    
    "function get_cam_lang()\n"
        "local l\n"
        "if get_propset()==1 then\n"
            "l=get_prop(196)/256\n"
            "if l>7 then l=l+1 end\n"
            "if l>22 then l=l+1 end\n"
        "else\n"
            "l=get_prop(61)/256\n"
        "end\n"
        "return l+1\n"
    "end\n"
    
    "function get_chdk_lang()\n"
        "local l=0\n"
        "local lf=get_config_value(64)\n"
        "if lf==\"\" then\n"
            "l=chdk_def_lang\n"
        "else\n"
            "for i,v in ipairs(langs) do\n"
                "if string.find(lf, v[\"name\"]..\".LNG\")~=nil then\n"
                    "l=i\n"
                    "break\n"
                "end\n"
            "end\n"
        "end\n"
        "return l\n"
    "end\n"
    
    "function file_exists(name)\n"
         "local f=io.open(name,\"r\")\n"
         "if f~=nil then io.close(f) return true else return false end\n"
    "end\n"
    
    "chdk_lang=get_chdk_lang()\n"
    "cam_lang=get_cam_lang()\n"
    
    "if cam_lang~=chdk_lang then\n"
        "if chdk_lang==0 or cam_lang==chdk_def_lang then\n"
            "set_config_value(64,\"\")\n"
            "set_config_value(65,langs[chdk_def_lang].font_cp)\n"
            "print(langs[chdk_def_lang].hint)\n"
        "elseif langs[cam_lang]~=nil then\n"
            "if file_exists(\"A/CHDK/LANG/\"..langs[cam_lang].name..\".LNG\") then\n"
                "set_config_value(64,\"A/CHDK/LANG/\"..langs[cam_lang].name..\".LNG\")\n"
                "set_config_value(65,langs[cam_lang].font_cp)\n"
                "print(langs[cam_lang].hint)\n"
            "else\n"
                "print(langs[cam_lang].name..\".LNG is missing\")\n"
            "end\n"
        "else\n"
            "print(\"unknown language id (\"..cam_lang..\")\")\n"
        "end\n"
    "else\n"
        "print(\";)\")\n"
    "end\n";

// ================ SCRIPT PARAMETERS ==========

char script_title[36];                          // Title of current script
static int last_script_param_set = -1;          // used to test if script_param_set has changed

#define DEFAULT_PARAM_SET       10              // Value of conf.script_param_set for 'Default' rather than saved parameters
#define MAX_PARAM_NAME_LEN      64              // Max length of a script name or description

sc_param        *script_params = 0;             // Parameters for loaded script (linked list)
static sc_param *tail = 0;
int             script_param_count;             // Number of parameters

//-------------------------------------------------------------------
// Find parameter entry for 'name', return null if not found
sc_param* find_param(char *name)
{
    sc_param *p = script_params;
    while (p)
    {
        if (strcmp(name, p->name) == 0)
            break;
        p = p->next;
    }
    return p;
}

// Create new sc_param structure, and link into list
sc_param* new_param(char *name)
{
    sc_param *p = malloc(sizeof(sc_param));
    memset(p, 0, sizeof(sc_param));
    if (tail)
    {
        tail->next = p;
        tail = p;
    }
    else
    {
        script_params = tail = p;
    }
    script_param_count++;

    p->name = malloc(strlen(name)+1);
    strcpy(p->name, name);

    return p;
}

//-------------------------------------------------------------------

#define IS_SPACE(p)     ((*p == ' ')  || (*p == '\t'))
#define IS_EOL(p)       ((*p == '\n') || (*p == '\r'))

const char* skip_whitespace(const char* p)  { while (IS_SPACE(p)) p++; return p; }                                      // Skip past whitespace
const char* skip_to_token(const char* p)    { while (IS_SPACE(p) || (*p == '=')) p++; return p; }                       // Skip to next token
const char* skip_token(const char* p)       { while (*p && !IS_EOL(p) && !IS_SPACE(p) && (*p != '=')) p++; return p; }  // Skip past current token value
const char* skip_toeol(const char* p)       { while (*p && !IS_EOL(p)) p++; return p; }                                 // Skip to end of line
const char* skip_eol(const char *p)         { p = skip_toeol(p); if (*p == '\r') p++; if (*p == '\n') p++; return p; }  // Skip past end of line

const char* skip_tochar(const char *p, char end)
{
    while (!IS_EOL(p) && (*p != end)) p++;
    return p;
}

// Extract next token into buffer supplied (up to maxlen)
const char* get_token(const char *p, char *buf, int maxlen)
{
    p = skip_whitespace(p);
    int l = skip_token(p) - p;
    int n = (l <= maxlen) ? l : maxlen;
    strncpy(buf, p, n);
    buf[n] = 0;
    return p + l;
}

// Extract name up to maxlen, find or create sc_param based on name
// Return pointer past name.
// Sets *sp to sc_param entry, or 0 if not found
const char* get_name(const char *p, int maxlen, sc_param **sp, int create)
{
    char str[MAX_PARAM_NAME_LEN+1];
    *sp = 0;
    p = skip_whitespace(p);
    if (p[0] && isalpha(p[0]))
    {
        p = get_token(p, str, maxlen);
        *sp = find_param(str);
        if ((*sp == 0) && create)
            *sp = new_param(str);
    }
    return p;
}

// Extract name part of script file from full path
const char* get_script_filename()
{
    const char* name = 0;
    // find name of script
    if (conf.script_file && conf.script_file[0])
    {
        name = strrchr(conf.script_file, '/');
        if (name)
            name++;
        else
            name = conf.script_file;
    }
    return name;
}

//=======================================================
//             PROCESSING "@ACTION" FUNCTIONS
//=======================================================

//-------------------------------------------------------------------
static void process_title(const char *ptr)
{
    ptr = skip_whitespace(ptr);
    int l = skip_toeol(ptr) - ptr;
    if (l >= sizeof(script_title)) l = sizeof(script_title) - 1;
    strncpy(script_title, ptr, l);
    script_title[l] = 0;
}

//-------------------------------------------------------------------
// Process one entry "@param VAR TITLE" to check if it exists
// RETURN VALUE: 0 if not valid, 1 if valid
// Used to ensure that a param loaded from an old saved paramset does
// not overwrite defaults from script
//-------------------------------------------------------------------
static int check_param(const char *ptr)
{
    sc_param *p;
    ptr = get_name(ptr, MAX_PARAM_NAME_LEN, &p, 0);
    if (p)
        return 1;
    return 0;
}

//-------------------------------------------------------------------
// Process one entry "@param VAR TITLE"
// RESULT: params[VAR].desc - parameter title
// RETURN VALUE: 0 if err, 1 if ok
//-------------------------------------------------------------------
static void process_param(const char *ptr)
{
    sc_param *p;
    ptr = get_name(ptr, MAX_PARAM_NAME_LEN, &p, 1);
    if (p)
    {
        ptr = skip_whitespace(ptr);
        int l = skip_toeol(ptr) - ptr;
        if (l > MAX_PARAM_NAME_LEN) l = MAX_PARAM_NAME_LEN;
        p->desc = malloc(l+1);
        strncpy(p->desc, ptr, l);
        p->desc[l] = 0;
    }
}

//-------------------------------------------------------------------
// Process one entry "@default VAR VALUE"
//-------------------------------------------------------------------
static const char* get_default(sc_param *p, const char *ptr, int isScript)
{
    ptr = skip_to_token(ptr);
    if (p)
    {
        p->val = strtol(ptr, NULL, 0);
        p->old_val = p->val;
        if (isScript)   // Loading from script file (rather than saved param set file)
        {
            p->def_val = p->val;
            p->range = 0;
            p->range_type = MENUITEM_INT|MENUITEM_SCRIPT_PARAM;
        }
    }
    return skip_token(ptr);
}

static void process_default(const char *ptr, int isScript)
{
    sc_param *p;
    ptr = get_name(ptr, MAX_PARAM_NAME_LEN, &p, isScript);
    get_default(p, ptr, isScript);
}

//-------------------------------------------------------------------
// Process one entry "@range VAR MIN MAX"
//-------------------------------------------------------------------
static const char* get_range(sc_param *p, const char *ptr, char end)
{
    ptr = skip_whitespace(ptr);
    int min = strtol(ptr,NULL,0);
    ptr = skip_whitespace(skip_token(ptr));
    int max = strtol(ptr,NULL,0);

    if (p)
    {
        p->range = MENU_MINMAX(min,max);
        p->range_type = MENUITEM_INT|MENUITEM_F_MINMAX|MENUITEM_SCRIPT_PARAM;
        if ((p->range == MENU_MINMAX(0,1)) || (p->range == MENU_MINMAX(1,0)))
            p->range_type = MENUITEM_BOOL|MENUITEM_SCRIPT_PARAM;
        else if ((min >= 0) && (max >= 0))
            p->range_type |= MENUITEM_F_UNSIGNED;
    }

    ptr = skip_tochar(ptr, end);
    if (end && (*ptr == end)) ptr++;
    return ptr;
}

static void process_range(const char *ptr)
{
    sc_param *p;
    ptr = get_name(ptr, MAX_PARAM_NAME_LEN, &p, 1);
    get_range(p, ptr, 0);
}

//-------------------------------------------------------------------
// Process one entry "@values VAR A B C D ..."
//-------------------------------------------------------------------
static const char* get_values(sc_param *p, const char *ptr, char end)
{
    ptr = skip_whitespace(ptr);
    int len = skip_tochar(ptr, end) - ptr;

    if (p)
    {
        p->range = 0;
        p->range_type = MENUITEM_ENUM2|MENUITEM_SCRIPT_PARAM;

        p->option_buf = malloc(len+1);
        strncpy(p->option_buf, ptr, len);
        p->option_buf[len] = 0;

        const char *s = p->option_buf;
        int cnt = 0;
        while (*s)
        {
            s = skip_whitespace(skip_token(s));
            cnt++;
        }
        p->option_count = cnt;
        p->options = malloc(cnt * sizeof(char*));

        s = p->option_buf;
        cnt = 0;
        while (*s)
        {
            p->options[cnt] = s;
            s = skip_token(s);
            if (*s)
            {
                *((char*)s) = 0;
                s = skip_whitespace(s+1);
            }
            cnt++;
        }
    }

    ptr += len;
    if (end && (*ptr == end)) ptr++;
    return ptr;
}

static void process_values(const char *ptr)
{
    sc_param *p;
    ptr = get_name(ptr, MAX_PARAM_NAME_LEN, &p, 1);
    get_values(p, ptr, 0);
}

//-------------------------------------------------------------------
// Process short form entry on single line
//      '#VAR=VAL "TITLE" [MIN MAX]'
// or   '#VAR=VAL "TITLE" {A B C D ...}'
//-------------------------------------------------------------------
static int process_single(const char *ptr)
{
    sc_param *p;
    ptr = get_name(ptr, MAX_PARAM_NAME_LEN, &p, 1);
    if (p)
    {
        ptr = get_default(p, ptr, 1);
        ptr = skip_whitespace(ptr);
        if ((*ptr == '"') || (*ptr == '\''))
        {
            const char *s = skip_tochar(ptr+1, *ptr);
            p->desc = malloc(s-ptr);
            strncpy(p->desc, ptr+1, s-ptr-1);
            p->desc[s-ptr-1] = 0;
            if (*s == *ptr) s++;
            ptr = skip_whitespace(s);
        }
        else
        {
            // Error - log to console and abort
            return 0;
        }
        if (*ptr == '[')
        {
            ptr = get_range(p, ptr+1, ']');
        }
        else if (*ptr == '{')
        {
            ptr = get_values(p, ptr+1, '}');
            ptr = skip_whitespace(ptr);
            if (strncmp(ptr,"table",5) == 0)
            {
                p->data_type = DTYPE_TABLE;
            }
        }
        ptr = skip_whitespace(ptr);
        if (strncmp(ptr,"bool",4) == 0)
        {
            p->range = MENU_MINMAX(1,0);
            p->range_type = MENUITEM_BOOL|MENUITEM_SCRIPT_PARAM;
            ptr = skip_token(ptr);
        }
        ptr = skip_whitespace(ptr);
        if (strncmp(ptr,"long",4) == 0)
        {
            p->range = 9999999;
            p->range_type = MENUITEM_INT|MENUITEM_SD_INT;
            ptr = skip_token(ptr);
        }
    }
    return 1;
}

//=======================================================
//                 SCRIPT LOADING FUNCTIONS
//=======================================================

//-------------------------------------------------------------------
// PURPOSE: Parse script (script_source_str) for parameters and title
//-------------------------------------------------------------------
static void script_scan()
{
    register const char *ptr = script_source_str;
    register int i, n;

    if ( !ptr ) { ptr = lua_script_default; }     // sanity check

    // Build title from name (in case no title in script)
    const char *c = get_script_filename();
    strncpy(script_title, c, sizeof(script_title)-1);
    script_title[sizeof(script_title)-1]=0;

    // Reset everything
    sc_param *p = script_params;
    while (p)
    {
        if (p->name)       free(p->name);
        if (p->desc)       free(p->desc);
        if (p->options)    free(p->options);
        if (p->option_buf) free(p->option_buf);
        sc_param *l = p;
        p = p->next;
        free(l);
    }
    script_params = tail = 0;
    script_param_count = 0;

    // Fillup order, defaults
    while (ptr[0])
    {
        ptr = skip_whitespace(ptr);
        if (ptr[0] == '@')
        {
            if (strncmp("@title", ptr, 6)==0)
            {
                process_title(ptr+6);
            }
            else if (strncmp("@param", ptr, 6)==0)
            {
                process_param(ptr+6);
            }
            else if (strncmp("@default", ptr, 8)==0)
            {
                process_default(ptr+8, 1);
            }
            else if (strncmp("@range", ptr, 6)==0)
            {
                process_range(ptr+6);
            }
            else if (strncmp("@values", ptr, 7)==0)
            {
                process_values(ptr+7);
            }
        }
        else if (ptr[0] == '#')
        {
            process_single(ptr+1);
        }
        ptr = skip_eol(ptr);
    }
}

//-------------------------------------------------------------------
// PURPOSE:     Create cfg filename in buffer.
// PARAMETERS:  mode - what exact kind of cfg file name required
// RESULT:  pointer to buffer with full path to config file
//-------------------------------------------------------------------
static char* make_param_filename(enum FilenameMakeModeEnum mode)
{
    // output buffer
    static char tgt_buf[100];
    
    // find name of script
    const char* name = get_script_filename();
    
    // make path
    strcpy(tgt_buf, SCRIPT_DATA_PATH);
    
    // add script filename
    char* s = tgt_buf + strlen(tgt_buf);
    strncpy(s, name, 12);
    s[12] = 0;

    // find where extension start and replace it
    s = strrchr(tgt_buf, '.');
    if (!s) s = tgt_buf + strlen(tgt_buf);

    switch (mode)
    {
        case MAKE_PARAMSETNUM_FILENAME:
            strcpy(s,".cfg");
            break;
        case MAKE_PARAM_FILENAME:
            sprintf(s,"_%d", conf.script_param_set);
            break;
        case MAKE_PARAM_FILENAME_V2:
            sprintf(s,".%d", conf.script_param_set);
            break;
    }

    return tgt_buf;
}

//-------------------------------------------------------------------
// read last paramset num of script "fn" to conf.script_param_set
//-------------------------------------------------------------------
static void get_last_paramset_num()
{
    // skip if internal script used
    if (conf.script_file == NULL || conf.script_file[0] == 0) return;

    char *nm = make_param_filename(MAKE_PARAMSETNUM_FILENAME);
    if ( !load_int_value_file( nm, &conf.script_param_set ) )
    {
        conf.script_param_set = 0;
        last_script_param_set = -1;      // failed to load so force next save
    }
    else
    {
        last_script_param_set = conf.script_param_set;  // save last value loaded from file
    }
    if ((conf.script_param_set < 0) || (conf.script_param_set > 10))
        conf.script_param_set = 0;
}

//-------------------------------------------------------------------
// PURPOSE:     Load parameters from paramset for script
// PARAMETERS:  fn - full path of script
//              paramset - num of loaded paramset (usually conf.script_param_set)
// RETURN:      1-succesfully applied, 0 - something was failed
//-------------------------------------------------------------------
static int load_params_values()
{
    // skip if internal script used
    if (conf.script_file == NULL || conf.script_file[0] == 0) return 0;
    // skip if 'default' parameters requested
    if (conf.script_param_set == DEFAULT_PARAM_SET) return 0;
    
    if ((conf.script_param_set < 0) || (conf.script_param_set > 10))
        conf.script_param_set = 0;

    char *nm = make_param_filename(MAKE_PARAM_FILENAME_V2);

    char* buf = load_file(nm, 0, 1);
    if (buf == 0)
    {
        nm = make_param_filename(MAKE_PARAM_FILENAME);
        buf = load_file(nm, 0, 1);
        if (buf == 0)
            return 0;
    }

    const char* ptr = buf;
    int valid = 1;

    // Initial scan of saved paramset file
    // Ensure all saved params match defaults from script
    // If not assume saved file is invalid and don't load it
    //   may occur if script is changed, or file was saved by a different script with same name
    while (ptr[0] && valid)
    {
        ptr = skip_whitespace(ptr);
        if (ptr[0] == '@')
        {
            if (strncmp("@param", ptr, 6) == 0) 
            {
                if (!check_param(ptr+6))
                    valid = 0;
            }
        }
        else if (ptr[0] == '#')
        {
            if (!check_param(ptr+1))
                valid = 0;
        }
        ptr = skip_eol(ptr);
    }

    if (valid)
    {
        // All ok, reset and process file
        ptr = buf;

        while (ptr[0])
        {
            ptr = skip_whitespace(ptr);
            if (ptr[0]=='@')
            {
                // Already checked file, so only need to load the @default values
                // @param, @range & @values already set from script
                if (strncmp("@default", ptr, 8)==0)
                {
                    process_default(ptr+8, 0);
                }
            }
            else if (ptr[0] == '#')
            {
                process_default(ptr+1, 0);
            }
            ptr = skip_eol(ptr);
        }
    }

    free(buf);

    return valid;
}


//-------------------------------------------------------------------
// PURPOSE:     Auxilary function.
//                Actually save param file
//-------------------------------------------------------------------
static void do_save_param_file()
{
    char buf[100];

    char *fn = make_param_filename(MAKE_PARAM_FILENAME_V2);
    int fd = open(fn, O_WRONLY|O_CREAT|O_TRUNC, 0777);

    if (fd >= 0)
    {
        sc_param *p = script_params;
        while (p)
        {
            // Only need to save name and value - saved as #name=value
            sprintf(buf,"#%s=%d\n",p->name,p->val);
            write(fd, buf, strlen(buf));
            p = p->next;
        }
        close(fd);
    }
}

//-------------------------------------------------------------------
// PURPOSE:     Save parameters to paramset for script
//                  Use: conf.script_file, conf.script_param_set
// PARAMETERS:  enforce = 1 mean save always
//                      = 0 mean save only if any values was changed
//                        (script_params[i].old_val != script_params[i].val)
//
// NOTE:    1. create SCRIPT_DATA_PATH/scriptname.cfg 
//                      which store # of last saved paramset
//          2. create SCRIPT_DATA_PATH/scriptname_PARAMSETNUM 
//                      which param_str
//-------------------------------------------------------------------
void save_params_values( int enforce )
{
    if (conf.script_param_save && (conf.script_param_set != DEFAULT_PARAM_SET))
    {
        // Write paramsetnum file
        if (conf.script_param_set != last_script_param_set)
        {
            char *nm = make_param_filename(MAKE_PARAMSETNUM_FILENAME);
            save_int_value_file( nm, conf.script_param_set );
            last_script_param_set = conf.script_param_set;
        }

        int i, changed=0;

        // Check is anything changed since last time
        sc_param *p = script_params;
        while (p)
        {
            if (p->old_val != p->val)
            {
                changed++;
                p->old_val = p->val;
            }
            p = p->next;
        }

        if (enforce || changed)
        {
            // Write parameters file
            do_save_param_file();
        }
    }
}

//-------------------------------------------------------------------
// PURPOSE: Reset values of variables to default
//-------------------------------------------------------------------
void script_reset_to_default_params_values() 
{
    sc_param *p = script_params;
    while (p)
    {
        p->val = p->def_val;
        p = p->next;
    }
}

//-------------------------------------------------------------------
// PURPOSE: Load script to memory ( and free malloc previous if exists)
// PARAMETERS:  fn - full path of script
//
// RESULTS: conf.script_file
//          script_source_str - loaded script file content
//
// NOTES:  1. Try to load fn, if fn or file is empty - SCRIPT_DEFAULT_FILENAME, 
//                if default not exists - use builtin
//         2. Update conf.script_file, title, submenu
//-------------------------------------------------------------------
void script_load(const char *fn)
{
    char* buf;

    if(script_source_str && script_source_str != lua_script_default)
        free((void *)script_source_str);

    // if filename is empty, try to load default named script.
    // if no such one, lua_script_default will be used
    if ( !fn[0] )
    {
        buf = load_file(SCRIPT_DEFAULT_FILENAME, 0, 1);
        if ( buf )
            fn = SCRIPT_DEFAULT_FILENAME;
    }
    else
    {
        buf = load_file(fn, 0, 1);
    }

    if ( !buf )
    {
        // if failed to load - say "internal" and raise flag need update
        script_source_str = lua_script_default;
        conf.script_file[0] = 0;
    }
    else
    {
        // if ok - set pointers to script
        script_source_str = buf;
        strcpy(conf.script_file, fn);
    }

    get_last_paramset_num();    // update data paths
    script_scan();              // re-fill @title/@names/@range/@value + reset values to @default
    load_params_values();

    gui_update_script_submenu();
}

//-------------------------------------------------------------------

static const char* gui_script_param_set_enum(int change, int arg)
{
    static const char* modes[]={ "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "Default" };

    if (change != 0)
    {
        save_params_values(0);
        gui_enum_value_change(&conf.script_param_set,change,sizeof(modes)/sizeof(modes[0]));

        if ( !load_params_values() )
            script_reset_to_default_params_values();
        gui_update_script_submenu();
    }

    return modes[conf.script_param_set];
}

static const char* gui_script_param_save_enum(int change, int arg)
{
    static const char* modes[]={ "Off", "On" };

    if (conf.script_param_set != DEFAULT_PARAM_SET)
    {
        if (change != 0)
        {
            gui_enum_value_change(&conf.script_param_save,change,sizeof(modes)/sizeof(modes[0]));
            if (conf.script_param_save)
                save_params_values(0);
        }

        return modes[conf.script_param_save];
    }

    return modes[0];
}

static void gui_load_script_selected(const char *fn) {
    if (fn) {
        gui_menu_cancel_redraw();   // Stop menu redraw until after menu rebuilt from script params
        save_params_values(0);
        script_load(fn);
        gui_set_need_restore();
    }
}

static void gui_load_script(int arg) {
    libfselect->file_select(LANG_STR_SELECT_SCRIPT_FILE, conf.script_file, "A/CHDK/SCRIPTS", gui_load_script_selected);
}

static void gui_load_script_default(int arg) {
    script_reset_to_default_params_values();
    gui_update_script_submenu();
    save_params_values(1);
}

static const char* gui_script_autostart_modes[]=            { "Off", "On", "Once", "ALT"};


// Indexes into script_submenu_items array, if you add or remove entries adjust these
#define SCRIPT_SUBMENU_PARAMS_IDX   8       // First adjustable parameter entry
#define SCRIPT_SUBMENU_BOTTOM_IDX   34      // 'Back' entry

static CMenuItem hdr_script_submenu_items[] = {
    MENU_ITEM   (0x35,LANG_MENU_SCRIPT_LOAD,                MENUITEM_PROC,                      gui_load_script,            0 ),
    MENU_ITEM   (0x5f,LANG_MENU_SCRIPT_DELAY,               MENUITEM_INT|MENUITEM_F_UNSIGNED,   &conf.script_shoot_delay,   0 ),
    // remote autostart
    MENU_ENUM2  (0x5f,LANG_MENU_SCRIPT_AUTOSTART,           &conf.script_startup,               gui_script_autostart_modes ),
    MENU_ITEM   (0x5c,LANG_MENU_LUA_RESTART,                MENUITEM_BOOL,                      &conf.debug_lua_restart_on_error,   0 ),
    MENU_ITEM   (0x5d,LANG_MENU_SCRIPT_DEFAULT_VAL,         MENUITEM_PROC,                      gui_load_script_default,    0 ),
    MENU_ITEM   (0x5e,LANG_MENU_SCRIPT_PARAM_SET,           MENUITEM_ENUM,                      gui_script_param_set_enum,  0 ),
    MENU_ITEM   (0x5c,LANG_MENU_SCRIPT_PARAM_SAVE,          MENUITEM_ENUM,                      gui_script_param_save_enum, 0 ),
    MENU_ITEM   (0x0 ,(int)script_title,                    MENUITEM_SEPARATOR,                 0,                          0 ),
};

static CMenuItem *script_submenu_items = 0;
int script_submenu_count = 0;

CMenu script_submenu = {0x27,LANG_MENU_SCRIPT_TITLE, 0 };

static void gui_update_script_submenu() 
{
    int i;
    sc_param *p;

    // Calculate # of header items, and total required for header, parameters, back button and terminator
    int f = sizeof(hdr_script_submenu_items) / sizeof(CMenuItem);
    int n = f + script_param_count + 2;

    // If we need more room, then free up old buffer
    if (script_submenu_items && (script_submenu_count < n))
    {
        free(script_submenu_items);
        script_submenu_items = 0;
        script_submenu_count = 0;
    }

    // If no buffer allocated, allocate one
    if (script_submenu_items == 0)
    {
        script_submenu_items = malloc(n * sizeof(CMenuItem));
        memset(script_submenu_items, 0, n * sizeof(CMenuItem));
        // Update size of buffer if smaller than new size
        if (script_submenu_count < n)
            script_submenu_count = n;
    }

    // Copy header items
    memcpy(script_submenu_items, hdr_script_submenu_items, sizeof(hdr_script_submenu_items));

    // Update menu to point to new submenu buffer
    script_submenu.menu = script_submenu_items;

    // Build parameter menu items
    for (i=f, p=script_params; p; i++, p=p->next)
    {
        script_submenu_items[i].symbol = 0x0;
        script_submenu_items[i].text = (int)p->desc;
        script_submenu_items[i].type = p->range_type;
        script_submenu_items[i].value = &p->val;
        script_submenu_items[i].arg = p->range;

        if (p->option_count != 0)
        {
            script_submenu_items[i].opt_len = p->option_count;
            script_submenu_items[i].arg = (int)p->options;
        }
    }

    // Fill in 'Back' button
    memset(&script_submenu_items[i],0,sizeof(CMenuItem)*2);
    script_submenu_items[i].symbol = 0x51;
    script_submenu_items[i].text = LANG_MENU_BACK;
    script_submenu_items[i].type = MENUITEM_UP;
}

//-------------------------------------------------------------------
