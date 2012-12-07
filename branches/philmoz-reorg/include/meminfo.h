#ifndef MEMINFO_H
#define MEMINFO_H

// Data returned from GetMemInfo & GetExMemInfo functions stored in this data structure
typedef struct {
    int start_address;
    int end_address;
    int total_size;
    int allocated_size;
    int allocated_peak;
    int allocated_count;
    int free_size;
    int free_block_max_size;
    int free_block_count;
} cam_meminfo;

// Always included for module_inspector
extern void GetMemInfo(cam_meminfo*);
extern int GetExMemInfo(cam_meminfo*);

#endif
