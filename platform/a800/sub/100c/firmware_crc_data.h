/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100c_crc32[]={
    { (const char *)0xffc00000,   0x29d276,  0x2a39200 }, // ROMCODE
    { (const char *)0xfff0e280,     0x9ac8, 0x6ce1064a }, // RAM data
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00C", firmware_100c_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xffc6ab1d, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
