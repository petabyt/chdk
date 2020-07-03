/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_101a_crc32[]={
    { (const char *)0xff000000,   0x5a9f14, 0x9885459b },
    { (const char *)0xff887958,    0x2e09c, 0xe96964a7 },
    { (const char *)0xff86fba4,    0x17db4, 0x26a216da },
};

const firmware_crc_block_t firmware_100d_crc32[]={
    { (const char *)0xff000000,   0x5a9f14, 0xe729d0a6 },
    { (const char *)0xff887958,    0x2e09c, 0xe96964a7 },
    { (const char *)0xff86fba4,    0x17db4, 0x26a216da },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.01A", firmware_101a_crc32 },
    { "GM1.00D", firmware_100d_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff0b5709, // firmware_ver_ptr
    firmware_crc_list,
    2,  // sub_count
    3,  // block_count
};
