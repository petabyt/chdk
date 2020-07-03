/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_101a_crc32[]={
    { (const char *)0xfc020000,   0x54bcc8, 0x1b2f78ef },
    { (const char *)0xfcd4742c,    0x26bd0,  0x7a6abdd },
    { (const char *)0xfcd6dffc,     0x6c19, 0xaac3b10f },
    { (const char *)0xfcd1e5d4,    0x28e58, 0xec19a249 },
    { (const char *)0xfcb2a320,     0x7800, 0x1fb6677c },
    { (const char *)0xfcb31b28,     0x4b20, 0x27dd60a8 },
    { (const char *)0xfcb36650,   0x10d2d0, 0x987d27ea },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.01A", firmware_101a_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xfc4a3495, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    7,  // block_count
};
