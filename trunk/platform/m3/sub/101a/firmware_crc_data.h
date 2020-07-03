/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_101a_crc32[]={
    { (const char *)0xfc020000,   0x5c294c, 0x70cfd930 },
    { (const char *)0xfccabee8,    0x264ac, 0x4deaf2d0 },
    { (const char *)0xfccd2394,     0x6b91, 0xdfa1bf63 },
    { (const char *)0xfcc637a8,    0x48740, 0xd1d557ab },
    { (const char *)0xfc9fefb0,     0x77b8, 0x55e7705a },
    { (const char *)0xfca06770,     0x4ad0,  0x4cb15aa },
    { (const char *)0xfca0b248,   0x106220, 0xa32a158b },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.01A", firmware_101a_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xfc1fcea5, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    7,  // block_count
};
