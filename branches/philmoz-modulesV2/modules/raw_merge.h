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

extern struct librawop_sym* librawop;

extern struct librawop_sym* module_rawop_load();		// 0fail, addr-ok
extern void module_rawop_unload();

#endif
