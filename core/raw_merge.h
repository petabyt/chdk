#ifndef RAW_MERGE_H
#define RAW_MERGE_H

#define RAW_OPERATION_SUM 0
#define RAW_OPERATION_AVERAGE 1


struct librawop_sym{
	int version;
	int (*raw_merge_start)(int action);
	void (*raw_merge_add_file)(const char * filename);
	void (*raw_merge_end)(void);
	int (*raw_subtract)(const char *from, const char *sub, const char *dest); 
};

// Defines of exported to chdk symbols
#ifdef THIS_IS_CHDK_CORE
	// This section is for CHDK core
	extern struct librawop_sym* librawop;
#else
	// This section is for module
int raw_merge_start(int action);
void raw_merge_add_file(const char * filename);
void raw_merge_end(void);
int raw_subtract(const char *from, const char *sub, const char *dest); 
#endif

#endif
