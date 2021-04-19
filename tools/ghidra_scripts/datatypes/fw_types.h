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
#ifdef VX_OLD_PTP
    int (*send_resp)(int handle, PTPContainer *resp, int zero); // (0xFF9F5688), ixus30/40 needs a third argument, which is always 0
#else
    int (*send_resp)(int handle, PTPContainer *resp); // extra param messes up analysis
#endif
    int (*get_data_size)(int handle); // (0xFF9F5830)
    int (*send_err_resp)(int handle, PTPContainer *resp); // (0xFF9F5784)
    int unknown1; // ???
    int (*f2)(); // ??? (0xFF8D5B24)
    int (*f3)(); // ??? (0xFF8D5B5C)
    int more[1];
    // more??
} ptp_data;

typedef int (*ptp_handler)(int, ptp_data*, int, int, int, int, int, int, int, int);

// made up, for eventproc table functions
typedef struct {
    const char *name;
    int (*func)();
} eventproc_table_entry;

// based on include/std/stdio.h
// reverse engineered file struct. Appears to be valid for both vxworks and dryos
// don't use this directly unless you absolutely need to
// don't EVER try to create one yourself, as this isn't the full structure.
typedef struct FILE_S {
    int fd;         // used by Read/Write
    unsigned len;   // +4 verfied in Fseek_FileStream
    int unk0;       // +8
    unsigned pos;   // +0xC verified in Fseek_FileStream
    /* below not used in CHDK */
    int unk1;        // +0x10
    int unk2;        // +0x14
    char * io_buf;      // +0x18 32k uncached allocated in Fopen_FileStream
    int unk3;        // +0x20 related to StartFileAccess_Sem
    char name[127]; // in reality, allocated dynamically but giving length gives better decompilation
} FILE;


// first parameter to mzrm_createmsg / mzrm_sendmsg
typedef struct mzrm_context_s mzrm_context;
typedef struct mzrm_context_s {
    int unk0;
    int sem;
    unsigned alloc_avail;
    int unk1;
    int index1; // probably a circular buffer of some kind?
    int index2;
    int unk2[3];
    void (*maybe_wait_fn)(mzrm_context *ctx);
    int unk3[2]; // possibly more
};

typedef struct mzrm_msg_s {
    int msg_type;
    int unk;
    int payload_size;
    int payload[16]; // actual size varies
} mzrm_msg;

typedef int (*controller_fn)(void *controller_data, int event_id, void *unk1, void *unk2);
typedef struct controller_s controller_t;
struct controller_s {
    controller_fn fn;
    void *data;
    controller_t *next;
#if defined(CAM_DRYOS_REL)
#if CAM_DRYOS_REL <= 52
    int unk[2]; // all <= r52 seem to be 5 words total
#else
    int unk[7]; // actual size varies, g*x and M cams seem to be 10 words total, others mostly 5
#else
    int unk; // vx appears to always be 4 words total
#endif
};
#endif

