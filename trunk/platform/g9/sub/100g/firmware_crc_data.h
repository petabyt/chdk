/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100g_crc32[]={
    { (const char *)0xff810000,   0x2b0b42, 0xf66dc3f6 },
    { (const char *)0xffb2e3f4,    0x127e4, 0x8c44ceaf },
};

const firmware_crc_block_t firmware_100f_crc32[]={
    { (const char *)0xff810000,   0x2b0b42, 0xad465cf2 },
    { (const char *)0xffb2e3f4,    0x127e4, 0x8c44ceaf },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00G", firmware_100g_crc32 },
    { "GM1.00F", firmware_100f_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff86e88d, // firmware_ver_ptr
    firmware_crc_list,
    2,  // sub_count
    2,  // block_count
};
