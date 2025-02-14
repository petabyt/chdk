#ifndef DNG_TEST_H
#define DNG_TEST_H

// for dng async write testing

typedef struct {
    int write_wait_count;
    int write_chunk_count;
    int finish_wait_count;
    int rev_chunk_count;
    int finit_start;
    int finit_end;
    int save_start;
    int save_end;
    int hdr_create_start;
    int hdr_create_end;
    int thumb_create_start;
    int thumb_create_end;
    int write_hdr_start;
    int write_hdr_end;
    int write_start;
    int write_end;
    int rev_start;
    int rev_end;
    int derev_start;
    int derev_end;
    int close_start;
    int close_end;
} dng_stats_t;

typedef struct {
    int rev_chunk_size;
    int write_end_chunk;
    int use_orig;
} dng_conf_t;

extern dng_stats_t dng_stats;
extern dng_conf_t dng_conf;
#endif
