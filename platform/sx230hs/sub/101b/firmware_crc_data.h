/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_101b_crc32[]={
    { (const char *)0xff000000,   0x3ba71a, 0x1de9afb0 },
    { (const char *)0xff4b506c,    0x10318, 0xb6dcf6ce },
};

const firmware_crc_block_t firmware_101c_crc32[]={
    { (const char *)0xff000000,   0x3ba71a, 0xa71b6d33 },
    { (const char *)0xff4b506c,    0x10318, 0xb6dcf6ce },
};

const firmware_crc_block_t firmware_101e_crc32[]={
    { (const char *)0xff000000,   0x3ba71a, 0x7591f864 },
    { (const char *)0xff4b506c,    0x10318, 0xb6dcf6ce },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.01B", firmware_101b_crc32 },
    { "GM1.01C", firmware_101c_crc32 },
    { "GM1.01E", firmware_101e_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff08afad, // firmware_ver_ptr
    firmware_crc_list,
    3,  // sub_count
    2,  // block_count
};
