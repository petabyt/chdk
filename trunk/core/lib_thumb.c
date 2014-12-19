// routines compiled as thumb
#include "platform.h"
#include "conf.h"

#if defined(CAM_DRYOS)
#include "chdk-dir.c"
#endif

//---------------------------------------------------------------------

// CHDK dir functions

extern int   fw_closedir(void *d);
extern void *fw_opendir(const char* name);

DIR *opendir(const char* name)
{
    // Create CHDK DIR structure
    DIR *dir = malloc(sizeof(DIR));
    // If malloc failed return failure
    if (dir == 0) return NULL;

#if defined(CAM_DRYOS)
    extern int get_fstype(void);
    // try built-in routine first, but only on FAT
    if ((get_fstype() < 4) && (!conf.disable_lfn_parser))
    {
        dir->fw_dir = 0;
        dir->cam_DIR = CHDKOpenDir(name);
    }
    else
    {
        dir->cam_DIR = NULL;
    }
    if (!dir->cam_DIR)
    {
        // try firmware routine if built-in failed
        dir->fw_dir = 1;
        dir->cam_DIR = fw_opendir(name);
    }
#else
    dir->cam_DIR = fw_opendir(name);
#endif

    // Init readdir return value
    dir->dir.d_name[0] = 0;

    // If failed clean up and return failure
    if (!dir->cam_DIR)
    {
        free(dir);
        return NULL;
    }

    return dir;
}

#ifndef CAM_DRYOS

// Internal VxWorks dirent structure returned by readdir
struct __dirent
{
    char            d_name[100];
};

struct dirent* readdir(DIR *d)
{
    if (d && d->cam_DIR)
    {
        // Get next entry from firmware function
        extern void *fw_readdir(void *d);
        struct __dirent *de = fw_readdir(d->cam_DIR);
        // Return next directory name if present, else return 0 (end of list)
        if (de)
        {
            strcpy(d->dir.d_name,de->d_name);
            return &d->dir;
        }
        else
        {
            d->dir.d_name[0] = 0;
        }
    }
    return NULL;
}

#else // dryos

struct dirent * readdir(DIR *d)
{
    if (d && d->cam_DIR)
    {
        if (d->fw_dir == 0)
        {
            CHDKReadDir(d->cam_DIR, d->dir.d_name);
        }
        else
        {
            extern int fw_readdir(void *d, void* dd); // DRYOS
            fw_readdir(d->cam_DIR, d->dir.d_name);
        }
        return d->dir.d_name[0]? &d->dir : NULL;
    }
    return NULL;
}

#endif // dryos dir functions

int closedir(DIR *d)
{
    int rv = -1;
    if (d && d->cam_DIR)
    {
#if defined(CAM_DRYOS)
        if (d->fw_dir == 0)
        {
            rv = CHDKCloseDir(d->cam_DIR);
        }
        else
#endif
        rv = fw_closedir(d->cam_DIR);

        // Mark closed (just in case)
        d->cam_DIR = 0;
        // Free allocated memory
        free(d);    
    }
    return rv;
}
