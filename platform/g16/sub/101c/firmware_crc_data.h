/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_101c_crc32[]={
    { (const char *)0xfc020000,   0x4feaac, 0x177a2718 },
    { (const char *)0xfcbebb80,    0x1e4e8, 0x226436f0 },
    { (const char *)0xfcbc22e0,    0x298a0, 0xee8f8bbb },
    { (const char *)0xfc9c5bdc,     0x7300, 0x2dc10243 },
    { (const char *)0xfc9ccee4,     0x4780, 0x473f703f },
    { (const char *)0xfc9d166c,    0xfc208, 0x842a6aa6 },
    { (const char *)0xfc51ecd4,     0x1658, 0xff5be8de },
    { (const char *)0xfc52032c,    0x50c78, 0xfabde2fb },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.01C", firmware_101c_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xfc158a7d, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    8,  // block_count
};
