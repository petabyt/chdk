/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100d_crc32[]={
    { (const char *)0xff000000,   0x567b20, 0x71519805 }, // ROMCODE
    { (const char *)0xff702f8c,    0x40878,  0xbb83f91 }, // RAM data, RAM code
};

const firmware_crc_block_t firmware_100c_crc32[]={
    { (const char *)0xff000000,   0x567b20, 0x173aa9db }, // ROMCODE
    { (const char *)0xff702f8c,    0x40878,  0xbb83f91 }, // RAM data, RAM code
};

const firmware_crc_block_t firmware_100a_crc32[]={
    { (const char *)0xff000000,   0x567b20, 0x4ec04ad6 }, // ROMCODE
    { (const char *)0xff702f8c,    0x40878,  0xbb83f91 }, // RAM data, RAM code
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00D", firmware_100d_crc32 },
    { "GM1.00C", firmware_100c_crc32 },
    { "GM1.00A", firmware_100a_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff084569, // firmware_ver_ptr
    firmware_crc_list,
    3,  // sub_count
    2,  // block_count
};
