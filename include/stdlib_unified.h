#ifndef STDLIB_UNIFIED_H
#define STDLIB_UNIFIED_H

// This is header of unified wrapper platform-dependend io functions

// Stopwords.


// Common values
#define STD_O_TRUNC         0x400
#define STD_O_CREAT         0x200


// Readonly structure. 
// So get simpliest structure
struct	STD_stat
    {
    unsigned long	st_unknown_1;
    unsigned long	st_attrib;
    unsigned long	st_size;
    unsigned long	st_ctime;
    unsigned long	st_mtime;
    unsigned long	st_unknown_2;
};


// Universal struct of directory entry
struct STD_dirent {
    char            d_name[100];
    unsigned long	unk1;
    unsigned char 	attrib;
    unsigned long 	size;
    unsigned long	time1;
    unsigned long	time2;
    unsigned long	time3;
};


// This is directory handler.
typedef struct {
	int magicnum;		// to safe second try to close
	void* dh;
    struct STD_dirent de;
} STD_DIR;




// Unified wrapper for platform-dependent IO functions

extern int 			  				safe_open (const char *name, int flags, int mode );
extern int            				safe_stat (const char *name, struct STD_stat *pStat);

extern STD_DIR*           	safe_opendir (const char* name);
extern struct STD_dirent*	safe_readdir (STD_DIR*);
extern int            		safe_closedir (STD_DIR*);
extern void           		safe_rewinddir (STD_DIR*);


#endif
