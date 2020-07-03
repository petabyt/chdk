/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100c_crc32[]={
    { (const char *)0xff000000,   0x49d22c, 0x6e36d10e },
    { (const char *)0xff746ac8,     0xf6b4, 0x48f2afd6 },
    { (const char *)0xff731694,    0x15434, 0xf287287c },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00C", firmware_100c_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff09a199, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    3,  // block_count
};
