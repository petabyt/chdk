/*
 *   Module: "Modules Menu"
 *		Recursively scan argument[0] directory and make submenu binded to argument[1] menuitem
 *
 *   TODO: store results to text cache file .CACHE to avoid module load later (detect by size/timestamp)
 *
 *   (c)2011 Sergey Taranenko aka tsvstar
 */


#include "stdlib.h"
#include "keyboard.h"
#include "platform.h"
#include "core.h"
#include "lang.h"
#include "gui.h"
#include "../gui_draw.h"
#include "../gui_lang.h"
#include "../gui_menu.h"
#include "../module_exportlist.h"

#include "../module_load.h"

//-------------------------------------------------------------------
static char buf[250];

int strlen_basepath;

// module info
char modulename[32];
struct ModuleInfo minfo;

//-------------------------------------------------------------------

void free_modules_submenu( CMenu* menu )
{
	const CMenuItem* cur;

	for ( cur=menu->menu; cur->type; cur++ ) {
		if ( cur->type == MENUITEM_SUBMENU ) {
			free_modules_submenu( (CMenu*) cur->value );
			free( (void*)cur->text );			
		} else if ( cur->type == MENUITEM_PROC ) {
			free( (void*)cur->arg );
		}
	}

	free(menu);
}


//-------------------------------------------------------------------

// Small hack: reuse fileselector nothumb.c
//     Sort first are dirs - then modules
// Return: -1= v1<v2(keep) , 1= v1>v2
//------------------------------------------
extern int fselect_sort_nothumb(const void* v1, const void* v2);
int fselect_sort(const void* v1, const void* v2) {

	const CMenuItem *i1=v1, *i2=v2;

	if (i1->type == MENUITEM_SUBMENU ) {
		if (i2->type != MENUITEM_SUBMENU )
			return -1;
        return strcmp( lang_str(i1->text), lang_str(i2->text) );
	} else {
		if (i2->type == MENUITEM_SUBMENU )
			return 1;
        return strcmp( lang_str(i1->text), lang_str(i2->text) );
	}
}

//-------------------------------------------------------------------
static int parse_module( char* content, int size ) 
{
	struct flat_hdr* flat = (struct flat_hdr*)content;

	memset( &minfo, 0, sizeof(minfo) );
	modulename[0]=0;
	//strncpy ( modulename, "no name", sizeof(modulename) );

	if ( size < sizeof (struct flat_hdr) )
		return 0;
	char b[5];
	memcpy(b,flat->magic,4);
	b[4]=0;

	if ( strncmp( flat->magic, FLAT_MAGIC_NUMBER, sizeof(flat->magic) ) )
		return 0;

	if ( flat->rev != FLAT_VERSION )
		return 0;

	if ( flat->_module_info > (size - sizeof(struct ModuleInfo)) )
		return 0;

	memcpy( &minfo, content+flat->_module_info, sizeof(struct ModuleInfo) );

	if ( minfo.magicnum != MODULEINFO_V1_MAGICNUM ||
		 minfo.sizeof_struct!=sizeof(struct ModuleInfo) )
		return 0;

	if ( minfo.moduleName < 0 )
	  { strncpy( modulename, lang_str(-minfo.moduleName), sizeof(modulename)); }
	else if ( minfo.moduleName >= flat->entry )
	  { strncpy( modulename, (content+minfo.moduleName), sizeof(modulename)); }

	return 1;
}


// Load info from module "fn" to minfo 
// Return: 0-fail, 1-ok
static int load_module_info(char* fn)
{
	return load_from_file(fn, parse_module);
}


//---------------------------------------------------------
CMenu* scan_directory(const char* dir) {

    STD_DIR           *d;
    struct STD_dirent *de;
    static struct STD_stat   st;

	char curdir[100];
	strcpy( curdir, dir);

    int iter, count, len;
	CMenu* mmenu = 0;
	CMenuItem* mitems = 0;
	CMenuItem* curitem;

	// Two iterations:
	//		first for draft count possible elements. then allocate
	//		second exact check and filling each elements
	for ( iter=1; iter<=2; iter++ )
	{
	    d = safe_opendir(curdir);
    	if (!d) return 0;

		count = 0;
	    for( de = safe_readdir(d); de; de = safe_readdir(d) ) {

            if (de->d_name[0] == 0xE5 /* deleted entry */ )
				continue;

            if (de->d_name[0] == '.' && de->d_name[1]==0) 
				continue;

            if (de->d_name[0] == '.' && de->d_name[1]=='.' && de->d_name[2] == 0 )
				continue;

           	sprintf(buf, "%s/%s", curdir, de->d_name);
	        if (safe_stat(buf, &st)!=0) 
				continue;
			
			if ( st.st_attrib != DOS_ATTR_DIRECTORY &&
				 st.st_size <= (sizeof(struct flat_hdr)+sizeof(struct ModuleInfo)) ) 
				continue;

			if ( iter==2 ) {

				curitem=mitems+count;

				if ( st.st_attrib == DOS_ATTR_DIRECTORY ) {
					void* submenu = 0;
					submenu = scan_directory( buf );

					if ( submenu==0 )
						continue;

					curitem->text = (int)malloc( strlen(de->d_name)+1 );
					if ( curitem->text==0 ) continue;
					curitem->type = MENUITEM_SUBMENU;
					curitem->value = submenu;
					strcpy( (char*)curitem->text, de->d_name);
				} else {

					char *ext = strchr(de->d_name,'.');
        		    if ( !ext || (ext[1]|0x20)!='f' || (ext[2]|0x20)!='l' || (ext[3]|0x20)!='t' )
						continue;

					if ( !load_module_info(buf) )
						continue;

					if (minfo.flags & MODULEINFO_FLAG_SYSTEM )
						continue;

					len = ( minfo.moduleName < 0 ) ? 0 : strlen(modulename);

					curitem->arg = (int)malloc( len+1 + strlen(buf)-strlen_basepath );
					if ( curitem->arg==0 ) continue;

					curitem->type = MENUITEM_PROC;
					curitem->value = (void*)gui_menu_run_fltmodule;
					strcpy( (void*)curitem->arg, buf+strlen_basepath+1 );

					if ( minfo.moduleName < 0 )
						curitem->text= -minfo.moduleName;
					else {
						curitem->text = curitem->arg + strlen((char*)curitem->arg)+1;
						strcpy( (char*)curitem->text, modulename );
					}
				}

				curitem->symbol=0x5c;
			}

			count++;
		}

		safe_closedir(d);

		// Iteration#1 final: allocate menuitems
		if (iter==1) {

			if ( count==0 )	{ safe_closedir(d); return 0;}

			len = sizeof(CMenu) + sizeof(CMenuItem)*(count+2);
			mmenu=malloc( len );
			if ( mmenu==0 ) return 0;
			mitems = (CMenuItem*) ((char*)mmenu + sizeof(CMenu) );
			memset( mmenu, 0, len );
		}
	}

	// Iteration#2 final

	if ( count == 0 ) {
		free( mmenu );
		return 0;
	}

	// .. fill Cmenu
	mmenu->symbol = 0x29;
	mmenu->on_change = 0;
	mmenu->menu = mitems;
	if ( strlen(curdir)==strlen_basepath )
		strcpy( buf, "Modules");
	else
		sprintf( buf, "Modules %s", curdir+strlen_basepath+1);

	mmenu->title = (int)malloc( strlen(buf)+1 );
	if ( mmenu->title==0 )
	{
		free( mmenu );
		return 0;
	}

	strcpy( (void*)mmenu->title, buf );


	// sort item
    qsort(mitems, count, sizeof(CMenuItem), fselect_sort_nothumb);


	// Add "Back" item
	curitem=mitems+count;
	curitem->text = LANG_MENU_BACK;
	curitem->symbol=0x51;
    curitem->type = MENUITEM_UP;

	return mmenu;
}



// =========  MODULE INIT =================
int module_idx=-1;

/***************** BEGIN OF AUXILARY PART *********************
  ATTENTION: DO NOT REMOVE OR CHANGE SIGNATURES IN THIS SECTION
 **************************************************************/

void* MODULE_EXPORT_LIST[] = {
	/* 0 */	(void*)EXPORTLIST_MAGIC_NUMBER,
	/* 1 */	(void*)0
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

	// If "gui_menu_run_fltmodule" is 0, then menu system is changed
	if ( module_find_symbol_address(MODULESYM_GUI_MENU_RUN_FLTMODULE) == 0)
		return 1;

    if ( !API_VERSION_MATCH_REQUIREMENT( gui_version.menu_api, 1, 0 ) )
	  return 1;

	return 0;
}



//---------------------------------------------------------
// PURPOSE: Finalize module operations (close allocs, etc)
// RETURN VALUE: 0-ok, 1-fail
//---------------------------------------------------------
int _module_unloader()
{
    return 0;
}


//---------------------------------------------------------
// PURPOSE: Default action 
// NOTE: Please comment this function if no default action and this library module
//---------------------------------------------------------
int _module_run(int moduleidx, int argn, int* arguments)
{
	module_idx=moduleidx;

    if ( argn!=2 ) {
		module_async_unload(moduleidx);		// fail to init - "unload me"
		return 1;
	}

	CMenu* menu;
	CMenuItem* item = (void*) arguments[1];
	switch ( item->type ) 
	{
		case MENUITEM_SUBMENU:
			free_modules_submenu( (CMenu*) item->value );
		case MENUITEM_PROC:
		case MENUITEM_TEXT:
			item->type = MENUITEM_TEXT;
			break;
		default:
			// should never be other types
			module_async_unload(moduleidx);
			return 1;
	}

	strlen_basepath = strlen( (char*) arguments[0] );
	menu = scan_directory( (char*) arguments[0] );
	if ( menu!=0 ) {
		item->type = MENUITEM_SUBMENU;
		item->value = (int*)menu;
	}

	module_async_unload(moduleidx);		// processing finished - "unload me"
	return 0;
}


/******************** Module Information structure ******************/

struct ModuleInfo _module_info = {	MODULEINFO_V1_MAGICNUM,
									sizeof(struct ModuleInfo),

									ANY_CHDK_BRANCH, 0,			// Requirements of CHDK version
									ANY_PLATFORM_ALLOWED,		// Specify platform dependency
									MODULEINFO_FLAG_SYSTEM,		// flag
									(int32_t)"Module Menu",		// Module name
									1, 0,						// Module version
									(int32_t)"Scan directory for modules and create submenu hierarchy"
								 };

/*************** END OF AUXILARY PART *******************/
