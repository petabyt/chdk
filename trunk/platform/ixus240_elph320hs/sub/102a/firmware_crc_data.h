/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_102a_crc32[]={
    { (const char *)0xff000000,   0x5a9f48, 0x9cd4faf1 },
    { (const char *)0xff887998,    0x2e09c, 0xec6614ba },
    { (const char *)0xff86fbdc,    0x17dbc, 0x61f3db35 },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.02A", firmware_102a_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff0b5709, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    3,  // block_count
};
