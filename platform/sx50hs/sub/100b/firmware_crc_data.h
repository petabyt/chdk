/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100b_crc32[]={
    { (const char *)0xff000000,   0x49d1d8, 0x35661b05 },
    { (const char *)0xff746a70,     0xf6b4, 0x2c68ed19 },
    { (const char *)0xff73163c,    0x15434, 0x5ce9aab9 },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00B", firmware_100b_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff09a199, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    3,  // block_count
};
