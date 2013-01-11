/*
 *   CHDK-FLAT Module System.  
 *
 *   (c)2011 Sergey Taranenko aka tsvstar
 *
 *   This is main file of module processing system. Module load/unload/service functions
 */

#include "stdlib.h"
#include "console.h"
#include "keyboard.h"
#include "cache.h"
#include "conf.h"

#include "module_load.h"
#include "module_exportlist.h"

//********************************************************/

typedef int (*_module_loader_t)( unsigned int* chdk_export_list );
typedef int (*_module_unloader_t)();
typedef int (*_module_run_t)(int moduleidx, int argn, int* arguments);

// Hashed Symbol table for exported symbols
extern sym_hash symbol_hash_table[];

//********************************************************/
//**    TEMPORARY FROM .H FILES   **
//********************************************************/

#define MAX_NUM_LOADED_MODULES 10
#define BUFFER_FOR_READ_SIZE   4096

//********************************************************/
//**    Small library for safe io to cacheable memory   **
//**  use smaller buffer then fopen so bigger could     **
//**  be loaded										    **
//********************************************************/

static char* buf_load=0;

int b_read(int fd, char* buf, int len)
{
  if (buf_load==0) {
    buf_load = umalloc( BUFFER_FOR_READ_SIZE );
    if (buf_load==0)
       return 0;
  }
  int loaded=0, now=1;

  while (now && loaded<len)
  {
     now = len-loaded;
     if ( now > BUFFER_FOR_READ_SIZE )
       now = BUFFER_FOR_READ_SIZE;

     now = read(fd,buf_load,now);
     
     memcpy(buf+loaded, buf_load, now);
     loaded+=now;
  }
  return loaded;
}

void b_close(int fd)
{
  if (fd >=0 )
  close(fd);

  if (buf_load)
   ufree(buf_load);
  buf_load=0;
}



//********************************************************/
//**       Auxilary module system functions             **
//********************************************************/

// array of pointer to loaded modules (NULL - slot is empty)
static struct flat_hdr* modules[MAX_NUM_LOADED_MODULES];

// >0- if correspondend module require to unload it
static unsigned char module_unload_request[MAX_NUM_LOADED_MODULES]; 

// =1- if correspondend module ask to unload it on exit from main menu
static unsigned char module_flags[MAX_NUM_LOADED_MODULES]; 

//-----------------------------------------------
// Cut module name to 11 sym + make it uppercase
//-----------------------------------------------
static void flat_module_name_make( char* tgt, char* name )
{
	char *p=tgt;

	for (; *name; name++ ){
		if ( *name=='/') {
			p=tgt;
		} else if ( (p-tgt) < 11 ) {
			*p=*name; p++;
		}
    }
    *p=0;
}

//-----------------------------------------------
// Do path to module
//-----------------------------------------------
static void flat_module_path_make( char* tgt, char* name )
{
	// check is name absolute path
	if ( name[0]=='A' && name[1]=='/')
   		strcpy(tgt,name);
	else
   sprintf(tgt,"%s/%s",MODULES_PATH,name);
}

//-----------------------------------------------
// PURPOSE: Find idx_loaded by module name or by module idx
// RETURN: -1 if module not loaded yet, otherwise idx in modules[]
//-----------------------------------------------
int module_find(char * name )
{
   char namebuf[12];
   int i = (uint32_t)name;

   // Check if given parameter is idx
   if (i < MAX_NUM_LOADED_MODULES)
    return (modules[i] ? i : -1);

   flat_module_name_make(namebuf,name);

   for ( i=0; i<MAX_NUM_LOADED_MODULES; i++ ) 
   {
    if ( modules[i] &&  !strcmp(namebuf, modules[i]->modulename) ) {
        return i;
    }
   }
   return -1;
}


//-----------------------------------------------

typedef int (*module_action_t)( struct flat_hdr* flat, void* relocbuf, uint32_t count );

static int module_do_relocations( struct flat_hdr* flat, void* relocbuf, uint32_t reloc_count )
{
   int i;
   unsigned int offs;
   unsigned char* buf = (unsigned char*)flat;

   for ( i=0; i < reloc_count; i++ )
   {
      offs = *(uint32_t*)relocbuf;
      relocbuf = ((uint32_t*)relocbuf)+1;
	  //@tsv todo: if (offs>=flat->reloc_start) error_out_of_bound
      *(uint32_t*)(buf+offs) += (uint32_t)buf;
   }  
   return 1;
}

// Find symbol address in array from hash id
const void* module_find_symbol_address(uint32_t importid)
{
    // binary search (first entry is magic number & entry count)
    int min = 1, max = EXPORTLIST_LAST_IDX;
    do
    {
        int mid = (min + max) >> 1;
        if (importid == symbol_hash_table[mid].hash)
            return symbol_hash_table[mid].address;
        else if (importid > symbol_hash_table[mid].hash)
            min = mid + 1;
        else
            max = mid - 1;
    } while (min <= max);
    return 0;
}

static int module_do_imports( struct flat_hdr* flat, void* relocbuf, uint32_t import_count )
{
	int i;
	const void* importaddress;
	uint32_t* ptr;
	unsigned char* buf = (unsigned char*)flat;
   

	for ( i=0; i < import_count; i++ )
	{
		ptr = (uint32_t*)( buf + ((import_record_t*)relocbuf)->offs );
		importaddress = module_find_symbol_address(((import_record_t*)relocbuf)->importidx);

        if (importaddress == 0) return 0;

		*ptr += (int)importaddress;  //(uint32_t)CHDK_EXPORT_LIST[importidx];
        relocbuf = ((import_record_t*)relocbuf)+1;
	}  
    return 1;
}

// variables to quick error
static char* module_filename;
static int module_fd;
static char* flat_buf;
static char* reloc_buf;

//-----------------------------------------------
static int moduleload_error(char* text, int value)
{
  if ( module_fd >=0 )
    b_close( module_fd);

  if ( flat_buf )
      free(flat_buf);
  if ( reloc_buf )
      ufree(reloc_buf);   

  //extern int console_is_inited();
  extern volatile int chdk_started_flag;
  if ( chdk_started_flag ) {
  char fmt[50];
  strcpy(fmt,"Fail to load %s: ");
  strcpy(fmt+17,text);

  char buf[100];
  sprintf(buf, fmt, module_filename, value);

  console_clear();
  console_add_line(buf);
	  msleep(1000);
  }

  return -1;
}


//-----------------------------------------------
// return: 0 if error, otherwise ok
static int module_do_action( char* actionname, uint32_t offset, uint32_t count, uint32_t segment_size, module_action_t func )
{
   if ( !count ) 
		return 1;

   reloc_buf = umalloc( segment_size );
   if ( !reloc_buf )
       	return (int)moduleload_error("malloc",0);   

   if ( offset != lseek(module_fd, offset, SEEK_SET) )
       	return (int)moduleload_error("action %s",(int)actionname);
   if ( segment_size != read(module_fd, reloc_buf, segment_size) )
       	return (int)moduleload_error("action %s", (int)actionname);

   // make relocations
   if ( !func( (struct flat_hdr*) flat_buf, (uint32_t*)reloc_buf, count ) )  
       	return (int)moduleload_error("bad import symbol",0);

   ufree(reloc_buf); reloc_buf=0;
   return 1;
}

//********************************************************/
//**           Main module system functions             **
//********************************************************/

//-----------------------------------------------
// PARAMETER:  name - filename of module
//             callback - function which bind/unbind chdk 
//         local pointers with module symbols.
//         Optional ( NULL - do not bind )
// RETURN:    -1 - failed, >=0 =idx of module
//-----------------------------------------------
int module_load(char* name, _module_bind_t callback)
{
   int idx;

   module_fd = -1;
   module_filename = name;
   flat_buf = 0;
   reloc_buf = 0;

/* possible to have idx=0. so no checks
   if (!name)		
      return -1;
*/

   //moduleload_error("Loading module %s", (uint32_t)name);

   // Check if module loaded
   idx = module_find(name);
   if ( idx>=0 ) {
	  // reset possible unload request
	  module_unload_request[idx]=0;
      if ( callback )
          callback( (void**) modules[idx]->_module_exportlist );
      return idx;
   }

   // Find empty slot   
   for ( idx=0; idx<MAX_NUM_LOADED_MODULES && modules[idx]; idx++ );

   if  ( idx == MAX_NUM_LOADED_MODULES )
      return moduleload_error("%d already loaded",MAX_NUM_LOADED_MODULES);

   module_unload_request[idx]=0;
   module_flags[idx]=0;

   char path[60];
   struct flat_hdr flat;
   int size_flat;

   flat_module_path_make(path,name);

   module_fd = open( path, O_RDONLY, 0777 );
   if ( module_fd <=0 )
      return moduleload_error("file not found",0);

   // @tsv TODO - compare loaded with requested
   b_read( module_fd, (char*)&flat, sizeof(flat) );

   if  ( flat.rev!=FLAT_VERSION || memcmp( flat.magic, FLAT_MAGIC_NUMBER, 4) )
      return moduleload_error("bad magicnum", 0);

   size_flat = flat.reloc_start;

   flat_buf = malloc( size_flat );
   if ( !flat_buf ) 
      return moduleload_error("malloc",0);
    
   if ( 0!= lseek(module_fd, 0, SEEK_SET) )
        return moduleload_error("read",0);
   if ( size_flat != b_read(module_fd, flat_buf, size_flat) )
        return moduleload_error("read",0);

   b_close(-1);	// filebuf not needed below


   // Module info checks

   struct ModuleInfo* _module_info = 0;
   if ( flat._module_info )    
   { 
	 _module_info = (struct ModuleInfo* ) ((unsigned int)flat_buf+flat._module_info);

	 if  ( _module_info->magicnum != MODULEINFO_V1_MAGICNUM ||
		   _module_info->sizeof_struct != sizeof(struct ModuleInfo) )
       return moduleload_error("Malformed module info", 0 );

	 if  ( _module_info->chdk_required_branch &&
		   _module_info->chdk_required_branch != CURRENT_CHDK_BRANCH )
       return moduleload_error("require different CHDK branch",0 );

	 if  ( _module_info->chdk_required_ver > CHDK_BUILD_NUM)
       return moduleload_error("require CHDK%05d", _module_info->chdk_required_ver);

     if  ( _module_info->chdk_required_platfid && 
		   _module_info->chdk_required_platfid != conf.platformid )
       return moduleload_error("require platfid %d", _module_info->chdk_required_platfid);
   }

   // Make relocations

   int reloc_size = flat.import_start - flat.reloc_start;
   int reloc_count = reloc_size/sizeof(reloc_record_t);
   if ( !module_do_action( "reloc", flat.reloc_start, reloc_count, reloc_size, module_do_relocations ) )
	  return -1;

   int import_size = flat.file_size - flat.import_start;
   int import_count = import_size/sizeof(import_record_t);
   if ( !module_do_action( "export", flat.import_start, import_count, import_size, module_do_imports ) )
	  return -1;

   b_close( module_fd );
   module_fd = -1;

   // Module is valid. Finalize binding

   modules[idx] = (struct flat_hdr* )flat_buf;

   modules[idx]->_module_info = (uint32_t) _module_info;
   if ( flat._module_loader )    { modules[idx]->_module_loader += (unsigned int)flat_buf; }
   if ( flat._module_unloader )  { modules[idx]->_module_unloader += (unsigned int)flat_buf; }
   if ( flat._module_run )       { modules[idx]->_module_run += (unsigned int)flat_buf; }

   // store runtime params
   flat_module_name_make(modules[idx]->modulename, name);
   modules[idx]->runtime_bind_callback = (uint32_t) callback;     //@tsv reuse unneeded entry to store valuable

   // TODO these could be changed to operate on affected address ranges only
   // after relocating but before attempting to execute loaded code
   // clean data cache to ensure code is in main memory
   dcache_clean_all();
   // then flush instruction cache to ensure no addresses containing new code are cached
   icache_flush_all();
   
   int bind_err=0;
   if ( flat._module_exportlist ) { 
        modules[idx]->_module_exportlist += (unsigned int)flat_buf; 
        if ( * ((uint32_t*)modules[idx]->_module_exportlist) != EXPORTLIST_MAGIC_NUMBER )
            return moduleload_error("wrong import magic",0);

        if ( callback )
            bind_err = callback( (void**) modules[idx]->_module_exportlist );
   }

   if ( modules[idx]->_module_loader ) {
		uint32_t x = ((_module_loader_t) modules[idx]->_module_loader )((unsigned int*)&symbol_hash_table[0]);
        bind_err = bind_err || x;
   }

   if ( bind_err )
   {
        module_unload(name); flat_buf=0;
        return moduleload_error("chdk mismatch",0);
   }

   return idx;
}

//-----------------------------------------------
// PURPOSE: 	run module "name" with argn/argv arguments. 
//				callback = chdk-bind/unbind exported by module symbols.
//				unload_after = 0 - do not unload
//							   1 - unload if load and no run handler
//							   2 - unload always
// RETURN VALUE: passed from module. -1 if something was failed
//-----------------------------------------------
int module_run(char* name, _module_bind_t callback, int argn, void* args, enum ModuleUnloadMode unload_after)
{
   int rv = -1;
   int loadflag=0;

   int moduleidx = module_find(name);
	if ( moduleidx<0 )
	{
		loadflag=1;
	
		moduleidx = module_load( name, callback );
   		if ( moduleidx<0 )
      		return -1;
	}

   if ( modules[moduleidx]->_module_run ) {
      kbd_key_release_all();
	  module_unload_request[moduleidx]=0;	// sanity stability clean
      rv = ( (_module_run_t) modules[moduleidx]->_module_run )(moduleidx, argn, args);
	}
	else if ( unload_after==UNLOAD_IF_ERR && loadflag)
		unload_after=UNLOAD_ALWAYS;

   if ( unload_after==UNLOAD_ALWAYS )
      module_unload(name);
   return rv;
}


//-----------------------------------------------
void module_unload_idx(int idx)
{
   _module_loader_t callback;

   if ( idx>=0 ) {
        // Make finalization module
        if ( modules[idx]->_module_unloader )
           ((_module_unloader_t) modules[idx]->_module_unloader )();
        // Unbind pointers to module (chdk core callback)
        if ( modules[idx]->runtime_bind_callback ) {
           callback = (_module_loader_t)modules[idx]->runtime_bind_callback;
           callback(0);
        }
       
        // Free slot
        free ( modules[idx] );
        modules[idx]=0;
        module_unload_request[idx]=0;
        module_flags[idx]=0;
   }
}

void module_unload(char* name)
{
    module_unload_idx(module_find(name));
}

//-----------------------------------------------
// Return: 0 no such module exist, !=0 found
//-----------------------------------------------
int module_check_is_exist(char* name)
{
    char path[60];
    flat_module_path_make(path, name);

    struct stat st;
    if (stat(path,&st) != 0) return 0;  // file does not exist

    return 1;
}

//-----------------------------------------------
void module_async_unload(unsigned int idx)
{
  if (idx <MAX_NUM_LOADED_MODULES)
     module_unload_request[idx]=2;
}

void module_set_flags(unsigned int idx, char value)
{
  if (idx <MAX_NUM_LOADED_MODULES)
     module_flags[idx]=value;
}

//-----------------------------------------------
// Close all runned modules
//   1. Called when goto GUI_MODE_NONE
//   2. Close in 0.1sec to finalize possible in-module flow
//	 3. Close only modules which are raised flag autounload
//-----------------------------------------------
void module_async_unload_allrunned(int enforce)
{
	int idx;

    for( idx=0; idx<MAX_NUM_LOADED_MODULES; idx++) {
		if ( modules[idx] &&
				( enforce ||
				 (module_flags[idx]&MODULE_FLAG_DISABLE_AUTOUNLOAD)==0 ) )
			module_unload_request[idx]=10;
	}     	  
}



//-----------------------------------------------
// Called on each tick to safe asynchronous unload module by its requests 
//-----------------------------------------------
void module_tick_unloader()
{
  int idx;

  for( idx=0; idx<MAX_NUM_LOADED_MODULES; idx++) {
    if ( module_unload_request[idx] >0 ) {
        module_unload_request[idx]--;
        //do unload on second tick to give module time to finish
            // (even if we set it right before return from function tick could happen at same moment)
        if ( module_unload_request[idx] == 0 )
            module_unload_idx(idx);
    }
  }
}

void* module_get_adr(unsigned int idx)
{
	if (idx < MAX_NUM_LOADED_MODULES)
		return modules[idx];
	return 0;
}
