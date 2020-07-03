/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100c_crc32[]={
    { (const char *)0xff810000,   0x2fe98c, 0x5f59e2c6 },
    { (const char *)0xffc04d4c,     0xf5d4, 0x555e1674 },
    { (const char *)0xffbf93d0,     0xb97c, 0xa03b5e47 },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00C", firmware_100c_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff87fb5d, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    3,  // block_count
};
