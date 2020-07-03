/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_120f_crc32[]={
    { (const char *)0xfc020000,   0x5c2e64, 0x9d58c83e },
    { (const char *)0xfcc98870,    0x264ac, 0x77e6a425 },
    { (const char *)0xfccbed1c,     0x6b91, 0x8102fe44 },
    { (const char *)0xfcc50100,    0x48770, 0x411c101a },
    { (const char *)0xfca00388,     0x77b8, 0x55e7705a },
    { (const char *)0xfca07b48,     0x4ad0,  0x4cb15aa },
    { (const char *)0xfca0c620,   0x106220, 0xa32a158b },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.20F", firmware_120f_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xfc1fcf15, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    7,  // block_count
};
