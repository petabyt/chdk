#include "stdlib.h"
#include "stdlib_unified.h"
#include "lang.h"

// PURPOSE:
// Universal file loader: alloc space and load file
// RETURN:
//  pointer to loaded file (0 if fail) and loaded size 
//			into rv_size (-1 if file not exists)
//-------------------------------------------------------------------
char* load_file( const char* name, int* rv_size )
{
	int fd;
	int size = -1;
	char* buf;

	// get size of file
	struct STD_stat st;
    if ( safe_stat(name,&st) == 0 )
		size = st.st_size;

	if ( rv_size )
		*rv_size = size;

	if ( size<=0 )
    	return 0;

	fd = open( name, O_RDONLY, 0777 );
	if ( fd <=0 )
    	return 0;

	buf = umalloc(size+1);
	if ( buf==0 ) {
		close(fd);
		return 0;
	}
    
    size = read(fd, buf, size );
 	buf[size]=0;
	close(fd);

	if ( rv_size )
  		*rv_size = size;
	return buf;
}


// Completely same as load_file but place result to cached memory
//-------------------------------------------------------------------
char* load_file_to_cached( const char* name, int* rv_size )
{
	int size;

	char* buf = load_file( name, &size );
	if ( rv_size ) *rv_size = size;

	if ( !buf )
		return 0;

	char* buf_cached = malloc( size+1 );
	if ( !buf_cached )
	{
		if (rv_size) *rv_size=-1;
		ufree(buf);
		return 0;
	}

	memcpy( buf_cached, buf, size+1 );
	ufree(buf);

	return buf_cached;
}

// PURPOSE:
// Universal file processor
// Load file, process by callback, unalloc/close file
// RETURN:
//	 Transfer return value from callback
// NOTE:
//	 Call callback even if fail to load/malloc (size=-1 if no file, size=0 if empty) 
//-------------------------------------------------------------------
int load_from_file(const char *filename, callback_process_file callback)
{
    int size;

    char *buf = load_file( filename, &size);

	size = callback( buf, size );

	if ( buf )
		ufree(buf);

	return size;
}

//-------------------------------------------------------------------

// PURPOSE: Load content to *value_p if file exist and contain number
// RETURN: 0-file_not_exist_or_failed (value is not changed), 1-ok

int load_int_value_file( const char* filename, int* value_p )
{
	int tmp;
	char *buf;

	buf=load_file( filename, &tmp );
	if ( !buf )
	   return 0;
	
	if ( value_p )	
		*value_p = strtol(buf, NULL, 10 /*dec*/);
	ufree(buf);

	return 1;
}


// PURPOSE: Save integer "value" to text file with name "filename"

void save_int_value_file( const char* filename, int value )
{
	char* buf = umalloc(20);
	if ( !buf )
		return;

	sprintf(buf,"%d", value);

	int fd = open( filename, O_WRONLY|O_CREAT|O_TRUNC, 0777);
	if (fd>=0) 
	{
		write(fd, buf, strlen(buf));
		close(fd);
	} 
	ufree(buf);
}

//-------------------------------------------------------------------

// PURPOSE: check_file_status
// result: 0=not_exists, -1=exist_but_empty, 1=exist_and_nonempty
int is_file_exists(const char* fn)		
{
	struct STD_stat st; 
	if ( safe_stat(fn,&st) )
	  return 0;
	return ( st.st_size==0)?-1:1;
}
