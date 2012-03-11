#include "stdlib.h"
#include "keyboard.h"
#include "platform.h"
#include "core.h"
#include "gui.h"
#include "gui_draw.h"
#include "conf.h"
#include "script.h"
#include "console.h"
#include "action_stack.h"
#include "modules.h"
#include "shot_histogram.h"
#include "lang.h"
#include "gui_lang.h"
#include "kbd.h"

#ifdef OPT_LUA
#include "lauxlib.h"
#endif

//-------------------------------------------------------------------

const char *script_source_str=NULL; // ptr to content of script
char cfg_name[100] = "\0";          // buffer to make string "DATAPATH/scriptname.cfg"
char cfg_set_name[100] = "\0";      // buffer to make string "DATAPATH/scriptname_PARAMSET"

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
    "langs[1]  = {[\"name\"]=\"ENGLISH\",  [\"font_cp\"]=0,  [\"hint\"]=\"CHDK language changed to english\"}\n"
    "langs[2]  = {[\"name\"]=\"GERMAN\",   [\"font_cp\"]=2,  [\"hint\"]=\"CHDK Sprache auf deutsch geäert\"}\n"
    "langs[13] = {[\"name\"]=\"RUSSIAN\",  [\"font_cp\"]=1,  [\"hint\"]=\"CHDK language changed to russian\"}\n"
    
    "function get_cam_language()\n"
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
    
    "function get_chdk_language()\n"
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
    
    
    "chdk_lang=get_chdk_language()\n"
    "cam_lang=get_cam_language()\n"
    
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
char script_title[36];                                      // Title of current script

//
// 1. Values of script parameters are stored in conf.script_vars
// 2. Encoding scheme is: array[VAR-'a'] = value

char script_params[SCRIPT_NUM_PARAMS][28];                  // Parameter title
int script_param_order[SCRIPT_NUM_PARAMS];                  // Ordered as_in_script list of variables ( [idx] = id_of_var )
                                                            // to display in same order in script
static char script_params_update[SCRIPT_NUM_PARAMS];        // Flag is such parameter exist
static int script_loaded_params[SCRIPT_NUM_PARAMS];         // Copy of original values of parameters 
                                                            // (detect are they changed or not)

static long running_script_stack_name = -1;                 // ID of action_stack, which used to control script processing

//-------------------------------------------------------------------
static void process_title(const char *title) {
    register const char *ptr = title;
    register int i=0;

    while (ptr[0]==' ' || ptr[0]=='\t') ++ptr; // whitespaces
    while (i<(sizeof(script_title)-1) && ptr[i] && ptr[i]!='\r' && ptr[i]!='\n') {
        script_title[i]=ptr[i];
        ++i;
    }
    script_title[i]=0;
}

//-------------------------------------------------------------------
// Process one entry "@param VAR TITLE"
//      param = ptr right after descriptor (should point to var)
//      update = 0 - get
//               1 - check is such parameter exists in loaded script
// RESULT: script_params[VAR] - parameter title
//         script_params_update[VAR] 
// RETURN VALUE: 0 if err, 1..26 = id of var
//-------------------------------------------------------------------
static int process_param(const char *param, int update) {
    register const char *ptr = param;
    register int n, i=0;

    while (ptr[0]==' ' || ptr[0]=='\t') ++ptr; // whitespaces
    if (ptr[0] && (ptr[0]>='a' && ptr[0]<='a'+SCRIPT_NUM_PARAMS) && (ptr[1]==' ' || ptr[1]=='\t')) {
        n=ptr[0]-'a';
        ptr+=2;
        while (ptr[0]==' ' || ptr[0]=='\t') ++ptr; // whitespaces
        script_params_update[n] = 1;
        while (i<(sizeof(script_params[0])-1) && ptr[i] && ptr[i]!='\r' && ptr[i]!='\n') {
            if (update) { 
                if (script_params[n][i]!=ptr[i]) 
                    { script_params_update[n] = 0; break; }
            } 
            else 
                script_params[n][i]=ptr[i];
            ++i;
        }
        if (!update) script_params[n][i]=0;
        n++;
    } else n=0; // ??? else produce error message    
    return n; // n=1 if '@param a' was processed, n=2 for 'b' ... n=26 for 'z'. n=0 if failed.
}

//-------------------------------------------------------------------
// Process one entry "@default VAR VALUE"
//      param = ptr right after descriptor (should point to var)
//      update = 0 - get
//               1 - only if updated
//-------------------------------------------------------------------
static void process_default(const char *param, char update) {
    register const char *ptr = param;
    register int n;

    while (ptr[0]==' ' || ptr[0]=='\t') ++ptr; // whitespaces
    if (ptr[0] && (ptr[0]>='a' && ptr[0]<='a'+SCRIPT_NUM_PARAMS) && (ptr[1]==' ' || ptr[1]=='\t')) {
        n=ptr[0]-'a';
        ptr+=2;
        if (!update || script_params_update[n])
        {
            conf.script_vars[n] = strtol(ptr, NULL, 0);
            script_loaded_params[n] = conf.script_vars[n];
        }
    } // ??? else produce error message
}

//-------------------------------------------------------------------
// PURPOSE: Parse script for @xxx
// PARAMETERS:  fn - full path of script
//              update_vars - 1 process "@defaults", 0 do not
// RESULTS:  script_title
//           script_params
//           script_params_order
//           script_loaded_params, conf.script_vars
//-------------------------------------------------------------------
static void script_scan(const char *fn, int update_vars) {
    register const char *ptr = script_source_str;
    register int i, j=0, n;
    char *c;

    c=strrchr(fn, '/');
    strncpy(script_title, (c)?c+1:fn, sizeof(script_title));
    script_title[sizeof(script_title)-1]=0;
    for (i=0; i<SCRIPT_NUM_PARAMS; ++i) {
        script_params[i][0]=0;
        script_param_order[i]=0;
    }

    while (ptr[0]) {
        while (ptr[0]==' ' || ptr[0]=='\t') ++ptr; // whitespaces
        if (ptr[0]=='@') {
            if (strncmp("@title", ptr, 6)==0) {
                ptr+=6;
                process_title(ptr);
            } else if (strncmp("@param", ptr, 6)==0) {
                ptr+=6;
                n=process_param(ptr, 0); // n=1 if '@param a' was processed, n=2 for 'b' ... n=26 for 'z'. n=0 if failed.
                if (n>0 && n<=SCRIPT_NUM_PARAMS) {
                  script_param_order[j]=n;
                  j++;
                }
            } else if (update_vars && strncmp("@default", ptr, 8)==0) {
                ptr+=8;
                process_default(ptr, 0);
            }
        }
        while (ptr[0] && ptr[0]!='\n') ++ptr; // unless end of line
        if (ptr[0]) ++ptr;
    }

    /*for (i=0; i<SCRIPT_NUM_PARAMS; ++i) {
        if (script_params[i][0]) break;
    }
    if (i==SCRIPT_NUM_PARAMS) { // there was no @param in script
        for (i=0; i<3; ++i) {
            strcpy(script_params[i], "Var. ? value");
            script_params[i][5]='a'+i;
        }
    }*/
}

//-------------------------------------------------------------------
// PURPOSE:     Create filename of paramset
// PARAMETERS:  fn - full path of script
//              param_set - >=0 = num of paramset, <0 = made .cfg
// RESULT:  name at cfg_set_name or cfg_name (depending on param_set)
//-------------------------------------------------------------------
void set_params_values_name(const char *fn, int param_set)
{
    int shift;
    register char *ptr = (param_set >= 0 ? cfg_set_name : cfg_name);
    const char *name;
    
    if (fn == NULL || fn[0] == 0) { ptr[0] = 0; return; }
    
    strncpy(ptr, SCRIPT_DATA_PATH, 100); ptr[99]=0;
    shift = strlen(SCRIPT_DATA_PATH);
    name = strrchr(fn, '/'); 
    if (name) name++; else name=fn;
    strncpy(ptr+shift, name, 100-shift); ptr[99]=0;
    shift = strlen(ptr); if (shift >= 100) shift=99;

    if (param_set >= 0) 
        sprintf(ptr+shift-4, "_%d\0", param_set);
    else
        strcpy(ptr+shift-3, "cfg\0");
}

//-------------------------------------------------------------------
//-------------------------------------------------------------------
// PURPOSE:     Load parameters from paramset for script
// PARAMETERS:  fn - full path of script
//              update_vars - if true load parameters,
//                                  otherwise do not
//              read_param_set - if true load required paramset to conf.script_param_set 
//                                  from .cfg, otherwise use paramset 0
// NOTES:       touched conf.script_param_set
//-------------------------------------------------------------------
int load_params_values(const char *fn, int update_vars, int read_param_set)
{
    int i, fd=-1, rcnt;
    register const char *ptr;   
    struct stat st;
    char *buf;
    
    if (fn == NULL || fn[0] == 0) return 0;
    if (read_param_set)
    {
        set_params_values_name(fn, -1);
        // find param set
        fd = open(cfg_name, O_RDONLY, 0777);
        if (fd >= 0)
        {
            buf=umalloc(16);
            rcnt = read(fd, buf, 15);
            buf[rcnt] = 0;
            close(fd);
            conf.script_param_set = strtol(buf, NULL, 0);
            ufree(buf);
        } else conf.script_param_set = 0;
    }
    set_params_values_name(fn, conf.script_param_set);
    if (!update_vars) return 0;
    
    // open and read file
    if (stat(cfg_set_name,&st) != 0)
        return 0;
    buf=umalloc(st.st_size+1);
    if(!buf)
        return 0;
    fd = open(cfg_set_name, O_RDONLY, 0777);
    if (fd < 0) {
        ufree(buf);
        return 0;
    }
    rcnt = read(fd, buf, st.st_size);
    buf[rcnt] = 0;
    close(fd);

    for(i = 0; i < SCRIPT_NUM_PARAMS; ++i) script_params_update[i]=0;
    ptr = buf;

    while (ptr[0]) 
    {
        while (ptr[0]==' ' || ptr[0]=='\t') ++ptr; // whitespaces
        if (ptr[0]=='@')
        {
            if (strncmp("@param", ptr, 6) == 0) 
            {
                ptr+=6;
                process_param(ptr, 1);
            } else if (strncmp("@default", ptr, 8)==0) {
                ptr+=8;
                process_default(ptr, 1);
            }
        }
        while (ptr[0] && ptr[0]!='\n') ++ptr; // unless end of line
        if (ptr[0]) ++ptr;
    }
    ufree(buf);
    return 1;
}

//-------------------------------------------------------------------
// PURPOSE:     Save parameters to paramset for script
//                  Use: conf.script_file, conf.script_param_set
// PARAMETERS:  unconditional - if 0 then save only if values are changed
//                                  (script_loaded_params[i] != conf.script_vars[i])
//                              otherwise mean "save always"
//
// NOTE:    1. create SCRIPT_DATA_PATH/scriptname.cfg 
//                      which store # of last saved paramset
//          2. create SCRIPT_DATA_PATH/scriptname_PARAMSETNUM 
//                      which contain @param/@defaults pair with values
//-------------------------------------------------------------------
void save_params_values(int unconditional)
{
    int i, n, fd, changed=0;
    char *buf,*p;
    for(i = 0; i < SCRIPT_NUM_PARAMS; i++)
    {
        if (script_loaded_params[i] != conf.script_vars[i]) changed++;
        script_loaded_params[i] = conf.script_vars[i];
    }
    if (!unconditional && !changed) return;

    if (cfg_name[0] == 0) set_params_values_name(conf.script_file, -1);
    fd = open(cfg_name, O_WRONLY|O_CREAT, 0777);
    if (fd >= 0)
    {
        char s[20];
        sprintf(s, " %d\n", conf.script_param_set);
        write(fd, s, strlen(s));
        close(fd);
    }
    
    // open and read file
    set_params_values_name(conf.script_file, conf.script_param_set);

    // max possible params * (param description + some extra for @default etc)
    buf=umalloc(SCRIPT_NUM_PARAMS*(28 + 20));
    if(!buf)
        return;

    fd = open(cfg_set_name, O_WRONLY|O_CREAT, 0777);
    if (fd < 0) {
        ufree(buf);
        return;
    }
    buf[0] = 0;
    p=buf;
    for(n = 0; n < SCRIPT_NUM_PARAMS; ++n)
    {
        if (script_params[n][0] != 0)
        {
            p+=sprintf(p,"@param %c %s\n@default %c %d\n",'a'+n,script_params[n],'a'+n,conf.script_vars[n]);
        }
    }
    write(fd, buf, strlen(buf));
    close(fd);
    ufree(buf);
}



//-------------------------------------------------------------------
// PURPOSE: Load script to memory ( and free malloc previous if exists)
// PARAMETERS:  fn - full path of script
//              saved_params -  0= reset all parameters to defaults
//                              1= load last stored paramset, if script was switched
//                              2= load paramset #0
//
// RESULTS: conf.script_file
//          script_source_str - loaded script file content
//
// NOTES:  1. Try to load fn, if fn or file is empty - SCRIPT_DEFAULT_FILENAME, 
//                if default not exists - use builtin
//         2. Update conf.script_file, title, submenu
//-------------------------------------------------------------------
void script_load(const char *fn, int saved_params) {
    int i, update_vars;
    FILE *fd = NULL;
    struct stat st;
    
//    save_params_values(0);

    if(script_source_str && script_source_str != lua_script_default)
        free((void *)script_source_str);

    script_source_str = lua_script_default;
    update_vars = (strcmp(fn, conf.script_file) != 0) || !saved_params || (saved_params == 2);  // update if new file

    if (!fn[0]) { // load internal script
        if (!conf.script_file[0]) { // internal script was used last time
            fd = fopen(SCRIPT_DEFAULT_FILENAME, "rb");
            if (fd) {
                fn = SCRIPT_DEFAULT_FILENAME;
                update_vars = 1; 
            }
        }
    } else {
        fd = fopen(fn, "rb");
        if (!fd) {
            conf.script_file[0]=0;
            update_vars = 1; 
        }
    }

    // zero size = default script
    if(stat(fn,&st) != 0 || st.st_size == 0) {
        conf.script_file[0]=0;
        update_vars = 1; 
        if(fd) {
            fclose(fd);
            fd=0;
        }
    }


    if (fd){
        int rcnt;
        char *buf;

        buf = malloc(st.st_size+2);
        if(!buf) {
            fclose(fd);
            return;
        }

        // TODO we could process the script here to reduce size
        // or compile for lua
        rcnt = fread(buf, 1, st.st_size,fd);
        if (rcnt > 0){
            buf[rcnt] = '\n';
            buf[rcnt+1] = 0;
            script_source_str = buf;
            strcpy(conf.script_file, fn);
        }
        else {
            free(buf);
        }
        fclose(fd);
    }

    if (update_vars) {
        for (i=0; i<SCRIPT_NUM_PARAMS; ++i) {
            conf.script_vars[i] = 0;
            script_loaded_params[i] = 0;
        }
    }
    script_scan(conf.script_file, update_vars);
    if (saved_params)
        load_params_values(conf.script_file, update_vars, (saved_params!=2));
    gui_update_script_submenu();
}

//-------------------------------------------------------------------
static int  print_screen_p;             // print_screen predicate: 0-off 1-on.
static int  print_screen_d = -1;        // print_screen file descriptor.
char print_screen_file[25];

void script_print_screen_init()
{
    print_screen_p = 0;
    if (print_screen_d >= 0) {
        close(print_screen_d);
        print_screen_d = -1;
    }
}

void script_print_screen_end()
{
    if (print_screen_d >= 0) {
        close(print_screen_d);
        print_screen_d = -1;
        print_screen_p = 0;
    }
}

void script_print_screen_statement(int val)
{
  // Negative values for 'val' parameter will append to log file,
  // positive values will truncate the log file
  int flag_trunc = O_TRUNC;

  print_screen_p = val;
  if (val) {
    if (print_screen_d>=0) close(print_screen_d);
    if (val<0) {
       flag_trunc = 0;
       val = -val;
    }
    while (val > 9999) val -= 10000;
    sprintf(print_screen_file, "A/CHDK/LOGS/LOG_%04d.TXT", val);
    print_screen_d = open(print_screen_file, O_WRONLY|O_CREAT|flag_trunc, 0777);
    if (print_screen_d>=0) lseek(print_screen_d,0,SEEK_END);
  }
}

void script_console_add_line(const char *str)
{
    console_add_line(str);

    if (print_screen_p && (print_screen_d >= 0)) {
        char nl = '\n';
        // TODO this should be uncached memory
        write(print_screen_d, str, strlen(str) );
        write(print_screen_d, &nl, 1);
    }
}

static int is_lua( const char* script_file)
{
  int len;
  char const* s;
  
  s = script_file;
  len = strlen( s );
  return !s[0] || (len >= 4 && ( s[len-1] == 'a' || s[len-1] == 'A' )
    && ( s[len-2] == 'u' || s[len-2] == 'U' )
    && ( s[len-3] == 'l' || s[len-3] == 'L' )
    && s[len-4] == '.');
}

void script_wait_and_end(void)
{
    script_console_add_line("PRESS SHUTTER TO CLOSE");

    // We're not running any more, but we have scheduled stuff that
    // needs to finish. So keep the script marked as running, but don't
    // call any more scripting functions.
    state_kbd_script_run = 3;
}

static void process_script()
{   // Note: This function is called from an action stack for AS_SCRIPT_RUN.

    if (state_kbd_script_run != 3) {
#ifdef OPT_LUA
        if( L ) {
            lua_script_run();
        } else
#endif
        {
#ifdef OPT_UBASIC
            ubasic_run();
            if (ubasic_finished()) {
                script_console_add_line(lang_str(LANG_CONSOLE_TEXT_FINISHED));
                action_pop();
                script_end();
            }    
#endif
        }
    }
}

static int script_action_stack(long p)
{
    // process stack operations
    switch (p) {
        case AS_SCRIPT_RUN:
            if (state_kbd_script_run)
                process_script();
            else
                action_pop();
            break;
        case AS_TEXTBOX:
        case AS_FILE_BROWSER:
            // state_kbd_script_run is set to 0 when the file browser is started from a Lua script
            // it is reset back to 1 when the file browser exits and control is returned back to
            // the script
            if (state_kbd_script_run)
            {
                action_pop();
            }
            break;
        case AS_MOTION_DETECTOR:
            if (module_mdetect_load())
            {
                if (libmotiondetect->md_detect_motion()==0)
                {
                    action_pop();
#ifdef OPT_LUA
                    if (L)
                    {
                        // We need to recover the motion detector's
                        // result and push
                        // it onto the thread's stack.
                        lua_pushnumber( Lt, libmotiondetect->md_get_result() );
                    } else
#endif
                    {
#ifdef OPT_UBASIC
                        ubasic_set_md_ret(libmotiondetect->md_get_result());
#endif
                    }
                }
            }
            else
            {
                action_pop();
#ifdef OPT_LUA
                if (L)
                {
                    lua_pushnumber( Lt, 0 );
                } else
#endif
                {
#ifdef OPT_UBASIC
                    ubasic_set_md_ret(0);
#endif
                }
            }
            break;
#if defined(OPT_LUA) && defined(CAM_CHDK_PTP)
        case AS_SCRIPT_READ_USB_MSG:
            if(L) { // only lua supported for now
                ptp_script_msg *msg = ptp_script_read_msg();
                if(action_process_delay(2) || msg) {
                    if(msg) {
                        lua_pushlstring( Lt,msg->data,msg->size);
                    } else {
                        lua_pushnil(Lt);
                    }
                    action_clear_delay();
                    action_pop();
                    action_pop();
                }
            }
            break;
        case AS_SCRIPT_WRITE_USB_MSG:
            if(L) { // only lua supported for now
                ptp_script_msg *msg = (ptp_script_msg *)action_get_prev(2);
                int r = ptp_script_write_msg(msg);
                if(action_process_delay(3) || r) {
                    action_clear_delay();
                    action_pop();
                    action_pop();
                    action_pop();
                    lua_pushboolean(Lt,r);
                }
            }
            break;
#endif
        default:
            if (!action_stack_standard(p) && !state_kbd_script_run)
            {
                /*finished();*/
                action_pop();
                script_end();
            }
            break;
    }
    
    return 1;
}

long script_stack_start()
{
    running_script_stack_name = action_stack_create(&script_action_stack, AS_SCRIPT_RUN);
    return running_script_stack_name;
}

int script_is_running()
{
    return !action_stack_is_finished(running_script_stack_name);
}

void script_end()
{
    script_print_screen_end();
#ifdef OPT_LUA
    if( L ) {
      lua_script_reset();
    } else
#endif
    {
#ifdef OPT_UBASIC
      ubasic_end();
#endif
    }
    // If motion detect library loaded then shut down motion detector
    // Don't call 'module_mdetect_load' here as we don't want to load
    // the module, just see if it was already loaded.
    if (libmotiondetect)
        libmotiondetect->md_close_motion_detector();
	shot_histogram_set(0);
    kbd_key_release_all();
    state_kbd_script_run = 0;

    conf_update_prevent_shutdown();

    vid_bitmap_refresh();
}

long script_start_gui( int autostart )
{
    int i;

    shot_histogram_set(0);
    if (autostart)
        auto_started = 1;
    else
        auto_started = 0;

    kbd_last_clicked = 0;

    /*if (!autostart)*/ kbd_key_release_all();

    console_clear();
    script_print_screen_init();

    if (conf.script_param_save) {
        save_params_values(0);
    }
    if( autostart )
        script_console_add_line("***Autostart***");
    else
        script_console_add_line(lang_str(LANG_CONSOLE_TEXT_STARTED));

    if( is_lua( conf.script_file ) ) {
#ifdef OPT_LUA
        if( !lua_script_start(script_source_str,0) ) {
            return -1;
        }
        for (i=0; i<SCRIPT_NUM_PARAMS; ++i) {
            if( script_params[i][0] ) {
                char var = 'a'+i;
                lua_pushlstring( L, &var, 1 );
                lua_pushnumber( L, conf.script_vars[i] );
                lua_settable( L, LUA_GLOBALSINDEX );
            }
        }
#else
        char msg[64];
        sprintf(msg,lang_str(LANG_CONSOLE_SCRIPT_DISABLED_IN_BUILD),"Lua");
        console_add_line(msg);
        return -1;
#endif
    } else
    { // ubasic
#ifdef OPT_UBASIC
        ubasic_init(script_source_str);

        for (i=0; i<SCRIPT_NUM_PARAMS; ++i) {
            ubasic_set_variable(i, conf.script_vars[i]);
        }
#else
        char msg[64];
        sprintf(msg,lang_str(LANG_CONSOLE_SCRIPT_DISABLED_IN_BUILD),"UBASIC");
        console_add_line(msg);
        return -1;
#endif
    }

    state_kbd_script_run = 1;

    conf_update_prevent_shutdown();

    return script_stack_start();
}

#if defined(OPT_LUA) && defined(CAM_CHDK_PTP)
long script_start_ptp( char *script )
{
  if (!lua_script_start(script,1)) return -1;
  state_kbd_script_run = 1;
  kbd_set_block(1);
  auto_started = 0;
  return script_stack_start();
}
#endif

int script_key_is_pressed(int k)
{
    if (k==0xFF)
        return get_usb_power(1);
    if (k > 0)
        return kbd_is_key_pressed(k);
    return 0;
}

int script_key_is_clicked(int k)
{
    if (k==0xFF)
        return get_usb_power(1);
    if (k > 0)
        return (kbd_last_clicked == k);
    return 0;
}

static const struct Keynames {
    int keyid;
    char *keyname;
} keynames[] = {
    { KEY_UP,           "up"         },
    { KEY_DOWN,         "down"       },
    { KEY_LEFT,         "left"       },
    { KEY_RIGHT,        "right"      },
    { KEY_SET,          "set"        },
    { KEY_SHOOT_HALF,   "shoot_half" },
    { KEY_SHOOT_FULL,   "shoot_full" },
    { KEY_SHOOT_FULL_ONLY,   "shoot_full_only" },
    { KEY_ZOOM_IN,      "zoom_in"    },
    { KEY_ZOOM_OUT,     "zoom_out"   },
    { KEY_MENU,         "menu"       },
    { KEY_DISPLAY,      "display"    },
    { KEY_PRINT,        "print"      },
    { KEY_ERASE,        "erase"      },
    { KEY_ISO,          "iso"        },
    { KEY_FLASH,        "flash"      },
    { KEY_MF,           "mf"         },
    { KEY_MACRO,        "macro"      },
    { KEY_VIDEO,        "video"      },
    { KEY_TIMER,        "timer"      },
    { KEY_EXPO_CORR,    "expo_corr"  },
    { KEY_MICROPHONE,   "fe"         },
    { KEY_ZOOM_ASSIST,  "zoom_assist"},
    { KEY_AE_LOCK,      "ae_lock"    },
    { KEY_METERING,     "metering_mode"},
    { 0xFF,             "remote"     },
    { 0xFFFF,           "no_key"     },
};

int script_keyid_by_name (const char *n)
{
    int i;
    for (i=0;i<sizeof(keynames)/sizeof(keynames[0]);i++)
    if (strcmp(keynames[i].keyname,n) == 0)
        return keynames[i].keyid;
    return 0;
}
