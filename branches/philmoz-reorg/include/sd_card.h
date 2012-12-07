#ifndef SD_CARD_H
#define SD_CARD_H

extern unsigned int GetFreeCardSpaceKb(void);
extern unsigned int GetTotalCardSpaceKb(void);

extern unsigned int GetJpgCount(void);
extern unsigned int GetRawCount(void);

extern char * camera_jpeg_count_str();

extern int swap_partitions(int new_partition);
extern unsigned char get_active_partition(void);
extern int get_part_type(void);
extern int get_part_count(void);
extern int is_partition_changed(void);
extern void create_partitions(void);

#endif
