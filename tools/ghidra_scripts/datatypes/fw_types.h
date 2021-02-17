/*
types for ghidra
pulled from various parts of the CHDK source

see fw_functions.h for required defines and other details
*/

#ifndef FW_TYPES_H
#define FW_TYPES_H
struct led_control {int led_num; int action; int brightness; int blink_count;};

#if !CAM_DRYOS_REL

struct	__stat  // VxWorks
{
    unsigned long	st_dev;		/* device ID number */
    unsigned long	st_ino;		/* file serial number */
    unsigned short	st_mode;	/* file mode (see below) */
    short		st_nlink;	/* number of links to file */
    short		st_uid;		/* user ID of file's owner */
    short		st_gid;		/* group ID of file's group */
    unsigned long	st_rdev;	/* device ID, only if special file */
    unsigned long	st_size;	/* size of file, in bytes */
    unsigned long	st_atime;	/* time of last access */
    unsigned long	st_mtime;	/* time of last modification */
    unsigned long	st_ctime;	/* time of last change of file status */
    long		st_blksize;
    long		st_blocks;
    unsigned char	st_attrib;	/* file attribute byte (dosFs only) */
    int			reserved1;	/* reserved for future use */
    int			reserved2;	/* reserved for future use */
    int			reserved3;	/* reserved for future use */
    int			reserved4;	/* reserved for future use */
    int			reserved5;	/* reserved for future use */
    int			reserved6;	/* reserved for future use */
};

#elif CAM_DRYOS_REL < 39
struct	__stat  // DryOS pre R39
    {
    unsigned long	st_dev;		//?
    unsigned long	st_ino;		//?
    unsigned short	st_mode;	//?
    short		st_nlink;	//?
    short		st_uid;		//?
    short		st_gid;		//?
    unsigned long	st_atime;	//?
    unsigned long	st_mtime;	//?
    unsigned long	st_ctime;	//?
    unsigned long	st_size;
    long		st_blksize;	//?
    long		st_blocks;	//?
    unsigned char	st_attrib;
    int			reserved1;	//
    int			reserved2;	//
    int			reserved3;	//
    int			reserved4;	//
    int			reserved5;	//
    int			reserved6;	//
};

#elif CAM_DRYOS_REL < 59

struct __stat   // DryOS R39...R58
{
    unsigned long	st_unknown_1;
    unsigned long	st_attrib;
    unsigned long	st_size;
    unsigned long	st_ctime;
    unsigned long	st_mtime;
    unsigned long	st_unknown_2;
};

#else

struct __stat   // DryOS >= R59
{
    unsigned long	st_unknown_1;
    unsigned long	st_attrib;
    unsigned long	st_size;        // fixme: very likely 64bit, upper 32 bit is st_unknown_2
    unsigned long	st_unknown_2;
    unsigned long	st_ctime;
    unsigned long	st_mtime;
    unsigned long	st_unknown_3;
};

#endif//CAM_DRYOS_REL

// from ptp_chdk.h
typedef struct {
    int code;
    int sess_id;
    int trans_id;
    int num_param;
    int param1;
    int param2;
    int param3;
    int param4;
    int param5;
} PTPContainer;

typedef struct {
    int handle;
    int (*send_data)(int handle, const char *buf, int part_size, int total_size, int, int, int); // (0xFF9F525C), total_size should be 0 except for the first call
    int (*recv_data)(int handle, char *buf, int size, int, int); // (0xFF9F5500)
    int (*send_resp)(int handle, PTPContainer *resp, int zero); // (0xFF9F5688), ixus30/40 needs a third argument, which is always 0
    int (*get_data_size)(int handle); // (0xFF9F5830)
    int (*send_err_resp)(int handle, PTPContainer *resp); // (0xFF9F5784)
    int unknown1; // ???
    int (*f2)(); // ??? (0xFF8D5B24)
    int (*f3)(); // ??? (0xFF8D5B5C)
    int more[];
    // more??
} ptp_data;

typedef int (*ptp_handler)(int, ptp_data*, int, int, int, int, int, int, int, int);

// made up, for eventproc table functions
typedef struct {
    const char *name;
    int (*func)();
} eventproc_table_entry;
#endif

