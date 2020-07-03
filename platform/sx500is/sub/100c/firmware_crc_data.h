/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100c_crc32[]={
    { (const char *)0xff000000,   0x39d5b8, 0xd3cb59a9 },
    { (const char *)0xff4e1414,     0xf59c, 0xacd2b880 },
    { (const char *)0xff4d317c,     0xe298, 0xb8b3709c },
};

const firmware_crc_block_t firmware_100d_crc32[]={
    { (const char *)0xff000000,   0x39d5b8, 0x32db91a8 },
    { (const char *)0xff4e1414,     0xf59c, 0xacd2b880 },
    { (const char *)0xff4d317c,     0xe298, 0xb8b3709c },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00C", firmware_100c_crc32 },
    { "GM1.00D", firmware_100d_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff087351, // firmware_ver_ptr
    firmware_crc_list,
    2,  // sub_count
    3,  // block_count
};
