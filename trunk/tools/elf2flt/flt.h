#ifndef __FLT_H__
#define __FLT_H__

typedef unsigned short uint16_t;
typedef short int16_t;
typedef unsigned int uint32_t;
typedef int int32_t;


//================= CFLT format header =====================

#define	FLAT_VERSION	    0x00000005L
#define FLAT_MAGIC_NUMBER   "CFLAT"

/*
 * To make everything easier to port and manage cross platform
 * development,  all fields are in network byte order.
 */

struct flat_hdr {
    char magic[4];          // "CFLA"
    union {
    	uint32_t rev;          			/* version (as above) */
        uint32_t runtime_bind_callback; // while loaded: callback to chdk binder function 
    };
    uint32_t entry;        /* Offset of first executable instruction
                              with text segment from beginning of file */
    uint32_t data_start;   /* Offset of data segment from beginning of
                              file */
    uint32_t data_end;     /* Offset of end of data segment from beginning
                              of file */
    uint32_t bss_end;      /* Offset of end of bss segment from beginning
                              of file */

    /* (It is assumed that data_end through bss_end forms the bss segment.) */

    //uint32_t stack_size;   // BFLAT - Size of stack, in bytes

	// CFLAT_v4
    //uint16_t chdk_min_version;  // @tsv: CFLAT specific
    //uint16_t chdk_req_platfid;	// @tsv: CFLAT specific 0 - if no restriction

	// v5
	uint32_t _module_info;		// Offset ModuleInfo from beginning file


    uint32_t reloc_start;  /* Offset of relocation records from beginning
                              of file */
    uint32_t reloc_count;  // Number of relocation records

    //uint32_t flags;         // BFLAT
    //uint32_t build_date;   // When the program/library was built
    //uint32_t filler[5];    // Reservered, set to zero

    int32_t _module_loader;       // CFLAT: offsets specific symbols from beginning file 
    int32_t _module_unloader;       
    int32_t _module_run;       
    int32_t _module_exportlist;
    union {       
        char     modulename[12];   // while loaded: module identification
        struct {
				uint32_t import_start; // offset of import section and count of records
				uint32_t import_count;
				uint32_t filler;  
			   };
    };
};



//================= Module information structure =====================


#define MODULEINFO_V1_MAGICNUM  0x023703e5

#define ANY_CHDK_BRANCH		0
#define REQUIRE_CHDK_MAIN   1
#define REQUIRE_CHDK_DE		2
#define REQUIRE_CHDK_SDM	3
#define REQUIRE_CHDK_PRIVATEBUILD	4

#define ANY_PLATFORM_ALLOWED	0

// This is system module (hide in Module list)
#define MODULEINFO_FLAG_SYSTEM	1

struct ModuleInfo 
{
	uint32_t magicnum;
	uint32_t sizeof_struct;
	uint16_t chdk_required_branch;
	uint32_t chdk_required_ver;
	uint32_t chdk_required_platfid;
	uint32_t flags;

	int32_t moduleName;			// pointer to string with module name or -LANG_ID
	uint16_t major_ver, minor_ver;
	int32_t description;		// pointer to string with module description
};


#endif /* __FLT_H__ */

