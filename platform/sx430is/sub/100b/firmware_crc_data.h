/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100b_crc32[]={
    { (const char *)0xff010000,   0x5e45d8,  0x9b947f3 },
    { (const char *)0xff7cf0a8,    0x2f1c4, 0xac8e3f09 },
    { (const char *)0xff7bba78,    0x13630, 0xf127d2f6 },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00B", firmware_100b_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff0acde9, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    3,  // block_count
};
