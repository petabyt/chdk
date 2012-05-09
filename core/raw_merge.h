#ifndef RAW_MERGE_H
#define RAW_MERGE_H

#define RAW_OPERATION_SUM 0
#define RAW_OPERATION_AVERAGE 1


struct librawop_sym{
	int version;
	int (*raw_merge_start)(int action);
	int (*raw_merge_add_file)(const char * filename);
	void (*raw_merge_end)(void);
	int (*raw_subtract)(const char *from, const char *sub, const char *dest); 
};

// Defines of exported to chdk symbols
#ifdef THIS_IS_CHDK_CORE
	// This section is for CHDK core
	extern struct librawop_sym* librawop;
#else
	// This section is for module
    extern int raw_merge_start(int action);
    extern int raw_merge_add_file(const char * filename);
    extern void raw_merge_end(void);
    extern int raw_subtract(const char *from, const char *sub, const char *dest); 
#endif

extern struct librawop_sym* module_rawop_load();		// 0fail, addr-ok
extern void module_rawop_unload();

#endif
