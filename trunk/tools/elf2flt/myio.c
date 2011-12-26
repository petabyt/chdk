/*
 * Service library of elf2flt 
 *
 * 	(c)2011	Sergey Taranenko aka tsvstar
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>


#include "myio.h"

static char* filebuf=0;
static int   filesize=0; 
static int   filecuridx=0;

/*---------------------------------------------------------------------------*/
int b_file_preload(char* filename)
{
	int fd;

    filesize=0;
    filecuridx=0;
    
    fd=open(filename, O_RDONLY|O_BINARY);
    if ( fd <=0 ) return 0;
    filesize = lseek(fd,0,SEEK_END);
	if ( FLAG_VERBOSE )
	    printf("File size=%d\n",filesize);
    filebuf=malloc(filesize);    
    if (!filebuf) return 0;

    int now=0, loaded =0; 
    if (lseek(fd, 0, SEEK_SET) != 0) return 0;
    do
    {
       now = read(fd, filebuf+loaded, filesize-loaded);
	   loaded+=now;
	} while (loaded<filesize && now);
         
    if ( loaded == filesize )
    	return loaded;
	return -loaded;
}

/*---------------------------------------------------------------------------*/
int b_read (int fd, void* buf, unsigned int count)
{
    if ( (filecuridx+count)> filesize)
        count = filesize - filecuridx;
    memcpy(buf, filebuf+filecuridx, count);
    filecuridx+=count;
    return count;
}

/*---------------------------------------------------------------------------*/
int b_seek(int fd, long offset, int whence)
{
    filecuridx = offset;
    if ( offset < 0 )
     { filecuridx = 0;}
    else if ( offset > filesize)
     { filecuridx = filesize;}
    return filecuridx;
}

/*---------------------------------------------------------------------------*/
int b_seek_read(unsigned int offset, char *buf, int len)
{
  if (b_seek(1, offset, SEEK_SET) != offset) return -1;
  return b_read(1, buf, len);
}

char* b_get_buf()
{
  return filebuf;
}


static char* import_buf=0;
static int import_counts=0;

int load_import(char* importfile)
{
	int fd;
	int importfilesize;
	static char buf[10];

	import_counts=0;
	import_buf=buf;
	if ( !importfile )
	  return 0;

	fd=open(importfile, O_RDONLY|O_BINARY, 0777);

    if ( fd <=0 ) {
		PRINTERR(stderr,"No import file '%s' found\n",importfile);
		return 0;
	}
    importfilesize = lseek(fd,0,SEEK_END);
	if ( FLAG_VERBOSE )
    	printf("Import file '%s' size=%d\n",importfile, importfilesize);

    import_buf=malloc(importfilesize+1);    
    if (!import_buf) return 0;

    int now=0, loaded =0; 
 	if (lseek(fd, 0, SEEK_SET) != 0) return 0;
	do
	{ 
      now = read(fd, import_buf+loaded, importfilesize-loaded);
      loaded+=now;
    } while (loaded<importfilesize && now);

	import_buf[loaded]=0;
	close(fd);
       
    if ( loaded != importfilesize )
      return -loaded;

	// Parse and check
	char* p=import_buf;
	for (;*p;p++) {
		if (*p==13) {
			PRINTERR(stderr,"Import file should have unix EOL format\n");
			import_counts=0;
			break;
		}

		if (*p==10) {
			import_counts++;
			*p=0;
			continue;
		}
		
		if (!((*p>='A' && *p<='Z') || 
			  (*p>='a' && *p<='z') || 
			  (*p>='0' && *p<='9') || 
			  *p=='_' ))
		{
			PRINTERR(stderr,"Found '%c' sym. Import file should contain only symbol names. No spaces or other sym allowed\n",*p);
			break;
		}

	}
	if ( FLAG_VERBOSE )
		printf("Import file has %d entries\n",import_counts);
	return loaded;
}


// Return: 0=not_found, >=2 - import_sym_idx
int find_import_symbol(char* sym)
{
  static const char prefix[] = "__imported_";
  static int prefixsize = sizeof(prefix);

	if (import_counts<=0)
		return 0;

	if (strlen(sym)==0)
		return 0;

	if ( !strncmp( sym, prefix, prefixsize ) )
	 { sym+=prefixsize; }

	char* cur=import_buf;
	int idx=0;

	for(;idx<import_counts;idx++) {
	  if (!strcmp(sym,cur))
		return (idx+2);

      for (;*cur; cur++);
	  cur++;
	}
	return 0;
}


void raise_error()
{
  static int flag =0;

  if (!flag)
	fprintf(stderr, "In file %s:\n", filename_elf);
  flag=1;
}
