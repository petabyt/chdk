/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100c_crc32[]={
    { (const char *)0xff000000,   0x39d5b8, 0xd3cb59a9 }, // ROMCODE
    { (const char *)0xff4d317c,    0x1d834, 0xdbc91b04 }, // RAM data, RAM code
};

const firmware_crc_block_t firmware_100d_crc32[]={
    { (const char *)0xff000000,   0x39d5b8, 0x32db91a8 }, // ROMCODE
    { (const char *)0xff4d317c,    0x1d834, 0xdbc91b04 }, // RAM data, RAM code
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00C", firmware_100c_crc32 },
    { "GM1.00D", firmware_100d_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff087351, // firmware_ver_ptr
    firmware_crc_list,
    2,  // sub_count
    2,  // block_count
};
