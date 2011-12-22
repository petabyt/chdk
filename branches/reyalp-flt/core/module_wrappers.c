#include "stdlib.h"
#include "stdlib_unified.h"

/*******************************************************
// Some of base IO functions are platform dependend. 
//  This file containt wrapper unify them for modules.
//
//  open - different files could be used
//  stat - different "stat" data structure used
//  *dir - different "dirent" data structure used
*******************************************************/


//-------------------------------------------------------
int safe_open (const char *name, int flags, int mode )
{
	int real_flags = flags & ~(STD_O_TRUNC|STD_O_CREAT);
	if ( flags & STD_O_TRUNC ) real_flags |= O_TRUNC;
	if ( flags & STD_O_CREAT ) real_flags |= O_CREAT;
	return open( name, real_flags, mode);
}

//-------------------------------------------------------
int safe_stat (const char *name, struct STD_stat *pStat)
{
  struct stat st;
  int rv;

  if ( pStat==0 ) return 1;
  memset( pStat, 0, sizeof(struct STD_stat));
  rv =  stat( name, &st );
  if  ( rv != 0 ) return rv;

  pStat->st_attrib = st.st_attrib;
  pStat->st_size   = st.st_size;
  pStat->st_ctime =  st.st_ctime;
  pStat->st_mtime =  st.st_mtime;

  return rv;
}


//-------------------------------------------------------
STD_DIR* safe_opendir (const char* name)
{
	DIR* dh = opendir(name);
	STD_DIR* std = 0;

	if ( dh==0 ) return 0;

	std = malloc (sizeof(STD_DIR));
	if ( std == 0 ) {
		closedir(dh);
		return 0;
	}

	memset( std, 0, sizeof(STD_DIR));
	std->dh = dh;

	return std;
}

//-------------------------------------------------------
int safe_closedir (STD_DIR* dir)
{
	int rv;

	if ( dir==0 ) return 0;
	rv = closedir( dir->dh );
	free( dir );
	return rv;
}

/* 
// rewinddir is used used nowhere. so commented for now
//-------------------------------------------------------
void safe_rewinddir (STD_DIR* dir )
{
	if ( dir!=0 ) 
		rewinddir( dir->dh );
}
*/

//-------------------------------------------------------
struct STD_dirent* safe_readdir (STD_DIR* dir) 
{
    struct dirent* de;

	if ( dir==0 ) return 0;
	de = readdir( dir->dh );

	if ( de==0 ) return 0;

#if !CAM_DRYOS
	memset( &(dir->de), 0, sizeof(dir->de));
#else
	dir->de.unk1 = de->unk1;
	dir->de.attrib = de->attrib;
	dir->de.size  = de->size;
	dir->de.time1 = de->time1;
	dir->de.time2 = de->time2;
	dir->de.time3 = de->time3;
#endif
	strncpy( dir->de.d_name, de->d_name, sizeof(dir->de.d_name));
	dir->de.d_name[sizeof(dir->de.d_name)-1]=0;

	return &(dir->de);
}
