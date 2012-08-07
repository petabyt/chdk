#include "stdlib.h"
#include "keyboard.h"
#include "platform.h"
#include "core.h"
#include "gui.h"
#include "gui_osd.h"
#include "gui_draw.h"
#include "gui_menu.h"
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

// Requested filename
enum FilenameMakeModeEnum 
	{ 	MAKE_PARAMSETNUM_FILENAME,		// "DATA/scriptname.cfg" -> cfg_name
		MAKE_PARAMSET_NAMES_FILENAME,	// "CFG/scriptname.cfg"  -> cfg_name
		MAKE_PARAM_FILENAME };			// "DATA/scriptname_%d" -> cfg_param_name

//-------------------------------------------------------------------

long kbd_last_clicked;
const char *script_source_str=NULL; // ptr to content of script
char cfg_name[100] = "\0";          // buffer to make cfg files name (paramsetnum, param_names)
char cfg_param_name[100] = "\0";    // buffer to make cfg param files name (params, state_before_tmprun)

const char* paramset_names[10];		// pointer of names of paramsets

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
    "langs[2]  = {[\"name\"]=\"GERMAN\",   [\"font_cp\"]=2,  [\"hint\"]=\"CHDK-Sprache auf deutsch geändert\"}\n"
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
short script_param_order[SCRIPT_NUM_PARAMS];                // Ordered as_in_script list of variables ( [idx] = id_of_var )
                                                            // to display in same order in script
int script_range_values[SCRIPT_NUM_PARAMS];                 // Min/Max values for param validation
short script_range_types[SCRIPT_NUM_PARAMS];                // Specifies if range values is signed (-9999-32767) or unsigned (0-65535)
                                                            // Note: -9999 limit on negative values is due to current gui_menu code (and because menu only displays chars)
const char **script_named_values[SCRIPT_NUM_PARAMS];        // Array of list values for named parameters
int script_named_counts[SCRIPT_NUM_PARAMS];                 // Count of # of entries in each script_list_values array
char *script_named_strings[SCRIPT_NUM_PARAMS];              // Base storage for named value string data
static char script_params_update[SCRIPT_NUM_PARAMS];        // Flag is such parameter exist
static int script_loaded_params[SCRIPT_NUM_PARAMS];         // Copy of original values of parameters 
                                                            // (detect are they changed or not)

const char* paramset_names[10];			// pointer of names of paramsets


static long running_script_stack_name = -1;                 // ID of action_stack, which used to control script processing

//-------------------------------------------------------------------

const char* skip_whitespace(const char* p)  { while (*p==' ' || *p=='\t') p++; return p; }  // Skip past whitespace
const char* skip_token(const char* p)       { while (*p && *p!='\r' && *p!='\n' && *p!=' ' && *p!='\t') p++; return p; }  // Skip past current token value
const char* skip_toeol(const char* p)       { while (*p && *p!='\r' && *p!='\n') p++; return p; } // Skip to end of line

//=======================================================
//             PROCESSING "@ACTION" FUNCTIONS
//=======================================================


//-------------------------------------------------------------------
static void process_title(const char *title) {
    register const char *ptr = title;
    register int i=0;

    ptr = skip_whitespace(ptr);
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
static int process_param(const char *param, int update)
{
    register const char *ptr = param;
    register int n, i=0;

    ptr = skip_whitespace(ptr);
    if (ptr[0] && (ptr[0]>='a' && ptr[0]<='a'+SCRIPT_NUM_PARAMS) && (ptr[1]==' ' || ptr[1]=='\t')) {
        n=ptr[0]-'a';
        ptr = skip_whitespace(ptr+2);
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
static void process_default(const char *param, char update)
{
    register const char *ptr = param;
    register int n;

    ptr = skip_whitespace(ptr);
    if (ptr[0] && (ptr[0]>='a' && ptr[0]<='a'+SCRIPT_NUM_PARAMS) && (ptr[1]==' ' || ptr[1]=='\t')) {
        n=ptr[0]-'a';
        ptr = skip_whitespace(ptr+2);
        if (!update || script_params_update[n])
        {
            conf.script_vars[n] = strtol(ptr, NULL, 0);
            script_loaded_params[n] = conf.script_vars[n];
        }
    } // ??? else produce error message
}

//-------------------------------------------------------------------
// Process one entry "@range VAR MIN MAX"
//      param = ptr right after descriptor (should point to var)
//      update = 0 - get
//               1 - only if updated
//-------------------------------------------------------------------
static void process_range(const char *param, char update)
{
    register const char *ptr = param;
    register int n;

    ptr = skip_whitespace(ptr);
    if (ptr[0] && (ptr[0]>='a' && ptr[0]<='a'+SCRIPT_NUM_PARAMS) && (ptr[1]==' ' || ptr[1]=='\t'))
    {
        n=ptr[0]-'a';
        ptr = skip_whitespace(ptr+2);
        if (!update || script_params_update[n])
        {
            int min = strtol(ptr,NULL,0);
            ptr = skip_whitespace(skip_token(ptr));
            int max = strtol(ptr,NULL,0);
            script_range_values[n] = MENU_MINMAX(min,max);
            if ((min == 0) && (max == 1))
                script_range_types[n] = MENUITEM_BOOL;
            else if ((min >= 0) && (max >= 0)) 
                script_range_types[n] = MENUITEM_INT|MENUITEM_F_MINMAX|MENUITEM_F_UNSIGNED;
            else
                script_range_types[n] = MENUITEM_INT|MENUITEM_F_MINMAX;
        }
    } // ??? else produce error message
}

//-------------------------------------------------------------------
// Process one entry "@values VAR A B C D ..."
//      param = ptr right after descriptor (should point to var)
//      update = 0 - get
//               1 - only if updated
//-------------------------------------------------------------------
static void process_values(const char *param, char update)
{
    register const char *ptr = param;
    register int n;

    ptr = skip_whitespace(ptr);
    if (ptr[0] && (ptr[0]>='a' && ptr[0]<='a'+SCRIPT_NUM_PARAMS) && (ptr[1]==' ' || ptr[1]=='\t'))
    {
        n=ptr[0]-'a';
        ptr = skip_whitespace(ptr+2);
        if (!update || script_params_update[n])
        {
            int len = skip_toeol(ptr) - ptr;
            script_named_strings[n] = malloc(len+1);
            strncpy(script_named_strings[n], ptr, len);
            script_named_strings[n][len] = 0;

            const char *p = script_named_strings[n];
            int cnt = 0;
            while (*p)
            {
                p = skip_whitespace(skip_token(p));
                cnt++;
            }
            script_named_counts[n] = cnt;
            script_named_values[n] = malloc(cnt * sizeof(char*));

            p = script_named_strings[n];
            cnt = 0;
            while (*p)
            {
                script_named_values[n][cnt] = p;
                p = skip_token(p);
                if (*p)
                {
                    *((char*)p) = 0;
                    p = skip_whitespace(p+1);
                }
                cnt++;
            }
        }
    } // ??? else produce error message
}

//=======================================================
//                 SCRIPT LOADING FUNCTIONS
//=======================================================

//-------------------------------------------------------------------
// PURPOSE: Parse script (script_source_str) for @xxx
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

	if ( !ptr ) { ptr = lua_script_default; } 	// sanity check

	// Build title

    c=strrchr(fn, '/');
    strncpy(script_title, (c)?c+1:fn, sizeof(script_title));
    script_title[sizeof(script_title)-1]=0;

	// Reset everything

    for (i=0; i<SCRIPT_NUM_PARAMS; ++i) {
    	if (update_vars) {
            conf.script_vars[i] = 0;
            script_loaded_params[i] = 0;
	    }
        script_params[i][0]=0;
        script_param_order[i]=0;
        script_range_values[i] = 0;
        if (script_named_values[i]) free(script_named_values[i]);
        script_named_values[i] = 0;
        if (script_named_strings[i]) free(script_named_strings[i]);
        script_named_strings[i] = 0;
        script_named_counts[i] = 0;
    }

	// Fillup order, defaults

    while (ptr[0]) {
        ptr = skip_whitespace(ptr);
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
            } else if (update_vars && strncmp("@range", ptr, 6)==0) {
                ptr+=6;
                process_range(ptr, 0);
            } else if (update_vars && strncmp("@values", ptr, 7)==0) {
                ptr+=7;
                process_values(ptr, 0);
            }
        }
        while (ptr[0] && ptr[0]!='\n') ++ptr; // unless end of line
        if (ptr[0]) ++ptr;
    }
}

//-------------------------------------------------------------------
// PURPOSE:     Create cfg filename in buffer.
// PARAMETERS:  mode - what exact kind of cfg file name required
//				fn - full path of script  (optional. have no matter for some modes)
//				paramset - target paramset (optional)
// RESULT:  name at cfg_param_name or cfg_name (depending on mode)
//-------------------------------------------------------------------
void make_param_filename( enum FilenameMakeModeEnum mode, const char* fn, int paramset )
{
	char extbuf[5];
	char* tgt_buf;
	char* base_path;
	char* name = 0;
	
	// find name of script
    if (fn && fn[0] ) 
{
	    name = strrchr( fn, '/' ); 
    	if (name) name++; else name=(char*)fn;
	}

	// prepare base data to make
	switch ( mode ) {
		case MAKE_PARAMSETNUM_FILENAME:
			tgt_buf = cfg_name;
			base_path = SCRIPT_DATA_PATH;
			strcpy(extbuf,".cfg");
			break;			
		case MAKE_PARAMSET_NAMES_FILENAME:
			tgt_buf = cfg_name;
			base_path = CFG_BASE_PATH;
			strcpy(extbuf,".cfg");
			break;
		case MAKE_PARAM_FILENAME:
			tgt_buf   = cfg_param_name;
			base_path = SCRIPT_DATA_PATH;
			sprintf(extbuf,"_%d",paramset);
			break;			
		default:		// unknown mode
			return;
	}
    
	// make path
	strcpy(tgt_buf, base_path);
    
	// add script filename
	char* tgt_name=tgt_buf+strlen(tgt_buf);
	strncpy( tgt_name, name, 12 );
	tgt_name[12] = 0;

	// find where extension start and replace it
	char* ext = strrchr(tgt_name, '.');
	if (!ext) ext=tgt_name+strlen(tgt_name);
	strcpy ( ext, extbuf );
}

//-------------------------------------------------------------------
// read last paramset num of script "fn" to conf.script_param_set
//-------------------------------------------------------------------
void get_last_paramset_num(const char *fn)
{
	// skip if internal script used
    if (fn == NULL || fn[0] == 0) return;

    make_param_filename( MAKE_PARAMSETNUM_FILENAME, fn, 0);
	if ( !load_int_value_file( cfg_name, &conf.script_param_set ) )
	   conf.script_param_set = 0;
	make_param_filename( MAKE_PARAM_FILENAME, fn, conf.script_param_set);
}

//-------------------------------------------------------------------
// PURPOSE:     Load parameters from paramset for script
// PARAMETERS:  fn - full path of script
//              paramset - num of loaded paramset (usually conf.script_param_set)
//                   -1=names are ready, nothing need to do
// RETURN:      1-succesfully applied, 0 - something was failed
//-------------------------------------------------------------------
int load_params_values(const char *fn, int paramset)
{
	if ( paramset>=0 ) {
	// skip if internal script used
    if (fn == NULL || fn[0] == 0) return 0;
    
		conf.script_param_set = paramset;
		make_param_filename( MAKE_PARAM_FILENAME, fn, paramset );
	}

	int size;
	char* buf = load_file( cfg_param_name, &size);
    if(!buf)
        return 0;

	int i;
	char *ptr;
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
            } else if (strncmp("@range", ptr, 6)==0) {
                ptr+=6;
                process_range(ptr, 1);
            } else if (strncmp("@values", ptr, 7)==0) {
                ptr+=7;
                process_values(ptr, 0);
            }
			/* 	// this will reqruired to temporary scripts infrastructure
				// only in data files (never in script)
				// not implemented yet
				else if (strncmp("@load_script", ptr, 12)==0) { 1;}
				else if (strncmp("@load_paramset", ptr, 14)==0) { 1;}
			*/
        }
        while (ptr[0] && ptr[0]!='\n') ++ptr; // unless end of line
        if (ptr[0]) ++ptr;
    }

    ufree(buf);

    return 1;
}


//-------------------------------------------------------------------
// PURPOSE:     Auxilary function.
//				Actually save param file
// PARAMETERS:  fn = name of target file (actually always cfg_param_name)
//				script_file = name if need to restore path
//				paramset = num of paramset, if it should be restored
//-------------------------------------------------------------------
static void do_save_param_file( char* fn, char* script_file, int paramset )
{
    int i,n, fd;
    char *buf;

    buf=umalloc(250);
    if( buf )
	{
    	fd = open(fn, O_WRONLY|O_CREAT, 0777);
    	if (fd >=0)
		{
			///// OLD FORMAT OF DATA FILE////

			// store filename and current paramset
			if (script_file) {
				sprintf( buf, "@script_file %s\n", script_file );
				write( fd, buf, strlen(buf) );
			}
			if ( paramset >0 ) {
				sprintf( buf, "@load_paramset %d\n", paramset );
				write( fd, buf, strlen(buf) );
			}

    		for(n = 0; n < SCRIPT_NUM_PARAMS; ++n)
    		{
    		    if (script_params[n][0] != 0)
    		    {
    		        sprintf(buf,"@param %c %s\n@default %c %d\n",'a'+n,script_params[n],'a'+n,conf.script_vars[n]);
    		        if (script_range_values[n] != 0)
    		            sprintf(buf+strlen(buf),"@range %c %d %d\n",'a'+n,(short)(script_range_values[n]&0xFFFF),(short)(script_range_values[n]>>16));
    		        if (script_named_counts[n] != 0)
    		        {
    		            sprintf(buf+strlen(buf),"@values %c",'a'+n);
    		            for (i=0; i<script_named_counts[n]; i++)
    		                sprintf(buf+strlen(buf)," %s",script_named_values[n][i]);
    		            strcat(buf,"\n");
    		        }
    				write(fd, buf, strlen(buf));
				}
    		}
    		
    		close(fd);
		}
			
  		ufree(buf);
	}
}

//-------------------------------------------------------------------
// PURPOSE:     Save parameters to paramset for script
//                  Use: conf.script_file, conf.script_param_set
// PARAMETERS:  enforce = 1 mean save always
//                      = 0 mean save only if any values was changed
//                        (script_loaded_params[i] != conf.script_vars[i])
//
// NOTE:    1. create SCRIPT_DATA_PATH/scriptname.cfg 
//                      which store # of last saved paramset
//          2. create SCRIPT_DATA_PATH/scriptname_PARAMSETNUM 
//                      which param_str
//-------------------------------------------------------------------
void save_params_values( int enforce )
{
    int i, changed=0;

	// Check is anything changed since last time

    for(i = 0; i < SCRIPT_NUM_PARAMS; i++)
    {
        if (script_loaded_params[i] != conf.script_vars[i]) changed++;
        script_loaded_params[i] = conf.script_vars[i];
    }
    if (!enforce && !changed) return;

	// Write paramsetnum file
    if (cfg_name[0] == 0)
	    make_param_filename( MAKE_PARAMSETNUM_FILENAME, conf.script_file, 0);
    save_int_value_file( cfg_name, conf.script_param_set );
    
    // Write parameters file
    
	make_param_filename( MAKE_PARAM_FILENAME, conf.script_file, conf.script_param_set);
	do_save_param_file( cfg_param_name, 0, -1);
}


//--------------------------------------------------------------------------
// Apply param_string 
// PARAMETERS: 
//     param_str = encoded to string list of script variable values
//                 Format: "#paramset_num,varname1=value1,varname2=value2,..." (#paramset is optional)
//                 Example: "#3,a=15,e=210"
//     allow_paramset_load = 1-apply paramset load if exists, 0-ignore it
//--------------------------------------------------------------------------
void script_apply_paramstr( char* param_str, int allow_load_paramset )
{
	int n;
	int value;
	char* e;
	char* ptr = param_str;

	if ( allow_load_paramset && *ptr=='#') {
		ptr++;
		if (*ptr>='0' && *ptr<='9' ) {
			load_params_values( conf.script_file, (*ptr-'0') );
			make_param_filename( MAKE_PARAM_FILENAME, conf.script_file, conf.script_param_set);
		}
	}

	// main list parsing
	for( ; *ptr; ptr++ ) {

		if ( *ptr<'a' || *ptr>=('a'+SCRIPT_NUM_PARAMS) ) continue;
		n=(*ptr-'a');
		ptr++;

		while ( *ptr && *ptr!='=' ) ptr++;
		if ( !*ptr ) break;

		ptr++;
		value = strtol(ptr,&e, 10);
		if (ptr!=e) {
			ptr=e;
			conf.script_vars[n]=value;
		}
	}
}

//-------------------------------------------------------------------
// PURPOSE: Reset values of variables to default
//-------------------------------------------------------------------
void script_reset_to_default_params_values() 
{
	script_scan( conf.script_file, 1 );			// load all values from script
    gui_update_script_submenu();
}

//-------------------------------------------------------------------
// PURPOSE: Load script to memory ( and free malloc previous if exists)
// PARAMETERS:  fn - full path of script
//              saved_params -  0= reset all parameters to defaults
//                              1= load last stored paramset, if script was switched
//                              2= load current paramset
//
// RESULTS: conf.script_file
//          script_source_str - loaded script file content
//
// NOTES:  1. Try to load fn, if fn or file is empty - SCRIPT_DEFAULT_FILENAME, 
//                if default not exists - use builtin
//         2. Update conf.script_file, title, submenu
//-------------------------------------------------------------------
void script_load(const char *fn, enum ScriptLoad_Mode_ saved_params) {
    
	int size;
	char* buf;

//    save_params_values(0);

    if(script_source_str && script_source_str != lua_script_default)
        free((void *)script_source_str);

    int update_vars = (strcmp(fn, conf.script_file) != 0);  // is file was switched

    // if filename is empty, try to load default named script.
	// if no such one, lua_script_default will be used
    if ( !fn[0] ) {
		update_vars = 1; 
		buf = load_file_to_cached( SCRIPT_DEFAULT_FILENAME, &size );
		if ( buf )
                fn = SCRIPT_DEFAULT_FILENAME;
    } else {
		buf = load_file_to_cached( fn, &size );
	}

	if ( !buf ) {
		// if failed to load - say "internal" and raise flag need update
	    script_source_str = lua_script_default;
        conf.script_file[0]=0;
        update_vars = 1; 
	}
	else {

		// if ok - set pointers to script
		script_source_str = buf;
		strcpy(conf.script_file, fn);
    }

	fn = conf.script_file;

	switch ( saved_params )
	{
		case SCRIPT_LOAD_DEFAULT_VALUES:
			// reset to default
		    script_scan( fn, 1 );
			break;

		case SCRIPT_LOAD_LAST_PARAMSET:		// load last paramset ( if script was changed )
	        get_last_paramset_num( fn );			// update data paths
		    script_scan( fn, update_vars );      	// re-fill @title/@names/@order/@range/@value + reset values to @default if update_vars=1
			if ( update_vars )
				load_params_values( fn, -1 );
			break;

		case SCRIPT_UPDATE_PARAMS: 			// update current
		    script_scan( fn, 1 );            		// reset values from script's default
			load_params_values( conf.script_file, conf.script_param_set );	// update values from current paramset
			break;
	}

    gui_update_script_submenu();
}

//=======================================================
//             PROCESSING PARAMS_NAME FUNCTIONS
//=======================================================

void load_params_names_cfg()
{
	int num;
	char* e;
	char* ptr;

	static char* file_buf = 0;
	static char* default_names[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

	if ( file_buf )
		ufree( file_buf );


	make_param_filename( MAKE_PARAMSET_NAMES_FILENAME, conf.script_file, conf.script_param_set);
	file_buf = load_file( cfg_name, 0 );

	for ( num=0; num<=9; num++ ) paramset_names[num] = default_names[num];


	if ( !file_buf )
		return;

	for ( ptr=file_buf; *ptr; ) {

		while ( *ptr=='\r' || *ptr=='\n') ptr++;
        ptr = (char*)skip_whitespace(ptr);

		if ( *ptr>='0' && *ptr<='9' && ptr[1]==':') {
			num = *ptr-'0';

			ptr+=2;
			e=(char*)skip_toeol(ptr);

			if (e!=ptr) {
	
				// if value exists copy it
				paramset_names[num]=ptr;

				// and limit to 7 chars length
				if ( (e-ptr)>7 ) ptr[7]=0;
			}

			ptr=e;
			if (*ptr)
				{ *ptr=0; ptr++;}

			continue;
		}

        ptr = (char*)skip_toeol(ptr);
	}

}


//=======================================================
//                 SCRIPT CONSOLE FUNCTIONS
//=======================================================

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

//=======================================================
//                 SCRIPT FUNCTIONS
//=======================================================

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
    state_kbd_script_run = SCRIPT_STATE_PENDING;
}

static void process_script()
{   // Note: This function is called from an action stack for AS_SCRIPT_RUN.

    if (state_kbd_script_run != SCRIPT_STATE_PENDING) {
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
            // If motion detect module loaded then run the MD code
            // Don't call module_mdetect_load here as it may cause the
            // module to be re-loaded after the script is interrupted
            if (libmotiondetect)
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
            if (!action_stack_standard(p) && state_kbd_script_run==SCRIPT_STATE_INACTIVE )
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

//-------------------------------------------------------------------

#ifdef OPT_SCRIPTING
static void interrupt_script()
{
    script_console_add_line(lang_str(LANG_CONSOLE_TEXT_INTERRUPTED));
    script_end();
}
#endif

// Main button processing for CHDK Script mode
static int gui_script_kbd_process()
{
#ifdef OPT_SCRIPTING
    // Stop a script if the shutter button pressed in Script mode
    if (kbd_is_key_clicked(KEY_SHOOT_FULL))
    {
        if (state_kbd_script_run == SCRIPT_STATE_INTERRUPTED || state_kbd_script_run == SCRIPT_STATE_PENDING )
            interrupt_script();
#ifdef OPT_LUA
        else if (L)
        {
            state_kbd_script_run = SCRIPT_STATE_INTERRUPTED;
            lua_run_restore();
            interrupt_script();
        }
#endif
#ifdef OPT_UBASIC
        else
        {
            state_kbd_script_run = SCRIPT_STATE_INTERRUPTED;
            if (jump_label("restore") == 0)
                interrupt_script();
        }
#endif
    }
#endif

    return 0;
}

//-------------------------------------------------------------------
void gui_script_draw()
{
    extern void gui_chdk_draw();
    gui_chdk_draw();

    if ((mode_get()&MODE_MASK) == MODE_REC || (mode_get()&MODE_MASK) == MODE_PLAY)
    {
        static int show_md_grid=0;
        if (state_kbd_script_run) show_md_grid=5;
        if (show_md_grid)
        {
            --show_md_grid;
            // If motion detect library loaded then display the MD grid
            // Don't call 'module_mdetect_load' here as we don't want to load
            // the module, just see if it was already loaded.
            if (libmotiondetect)
                libmotiondetect->md_draw_grid();
        }
    }
}

// GUI handler for Script mode
gui_handler scriptGuiHandler = { GUI_MODE_SCRIPT, gui_script_draw, gui_script_kbd_process, 0, GUI_MODE_FLAG_NODRAWRESTORE|GUI_MODE_FLAG_NORESTORE_ON_SWITCH, GUI_MODE_MAGICNUM };      

static gui_handler *old_gui_handler = 0;

//-------------------------------------------------------------------

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
    module_mdetect_unload();

	shot_histogram_set(0);
    kbd_key_release_all();
    state_kbd_script_run = SCRIPT_STATE_INACTIVE;

    conf_update_prevent_shutdown();

    vid_bitmap_refresh();

    if (old_gui_handler)
    {
        gui_set_mode(old_gui_handler);
        old_gui_handler = 0;
    }
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

    state_kbd_script_run = SCRIPT_STATE_RAN;

    conf_update_prevent_shutdown();

    old_gui_handler = gui_set_mode(&scriptGuiHandler);

    return script_stack_start();
}

#if defined(OPT_LUA) && defined(CAM_CHDK_PTP)
long script_start_ptp( char *script )
{
  if (!lua_script_start(script,1)) return -1;
  state_kbd_script_run = SCRIPT_STATE_RAN;
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
