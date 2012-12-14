#ifndef __FLT_H__
#define __FLT_H__

typedef unsigned short uint16_t;
typedef short int16_t;
typedef unsigned int uint32_t;
typedef int int32_t;


//================= CFLT format header =====================

/*
	Structure of CFLAT v6 file:
	- flat_hdr
	- .text		[start from flt_hdr.entry]
    - .rodata	[start from flt_hdr.data_start]
    - .data
	- .bss		[start from flt_hdr.bss_start]
    - reloc_list [start from flt_hdr.reloc_start]
		* this is just array of offsets in flat
    - import_list  [start from flt_hdr.import_start]
		* this is array of import_record_t
    - symbol_list  [start from flt_hdr.symbols_start. till file_size]
        * plain list of zero-terminated strings
		* symbol idx are same as in used exportlist.txt
	    * unused by module symbols are present in list but empty
        * 2 and more continuous empty names could be squeezed to (0x80|num_of_empty_names)
		* This table is not used in module loader now. 
		  No impact to loaded size of module. This extension just for debug purpose and possible future usage
*/


#define	FLAT_VERSION	    0x00000007L
#define FLAT_MAGIC_NUMBER   "CFLAT"


// Structures of relocation and importing
//---------------------------------------

// Rules how relocations works:
//  Relocation:
//  	*(flat_base+reloc[i]) += flat_base;
//  Import:
//    symidx = import[i].importidx
//	  *(flat_base+import[i].offs) += chdk_export_table[sym_idx]


typedef unsigned int reloc_record_t;
typedef struct {
		uint32_t offs;			// offset of changed record from begin of flat
		uint32_t importidx;     // index of symbol in chdk_export_table
	} import_record_t;



//================= FLAT Header structure ==============
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
    uint32_t entry;        // Offset of start .text segment
    uint32_t data_start;   // Offset of data segment from beginning of file
    uint32_t bss_start;    // Offset of bss segment from beginning of file

    /* (It is assumed that data_end through bss_end forms the bss segment.) */

	// v5
	uint32_t _module_info;		// Offset ModuleInfo from beginning file


    uint32_t reloc_start;		// Offset of relocation records from beginning of file
    uint32_t import_start;		// Offset of import section
	uint32_t symbols_start;     // offset of symbol table list

    int32_t _module_loader;       // CFLAT: offsets specific symbols from beginning file 
    int32_t _module_unloader;       
    int32_t _module_run;       
    int32_t _module_exportlist;
    union {       
        char     modulename[12];   // while loaded: module identification
        struct {
				uint32_t file_size;	   // size of file (and this is last byte of symbol table+1)
				uint32_t filler1;  
				uint32_t filler2;  
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

