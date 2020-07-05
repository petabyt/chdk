/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_101a_crc32[]={
    { (const char *)0xfc020000,   0x4fea50, 0x7a1cda25 },
    { (const char *)0xfcbebb18,    0x1e4e8, 0x58bb7f8e },
    { (const char *)0xfcbc2280,    0x29898, 0x39197d58 },
    { (const char *)0xfc9c5b7c,     0x7300, 0x2dc10243 },
    { (const char *)0xfc9cce84,     0x4780, 0x473f703f },
    { (const char *)0xfc9d160c,    0xfc208, 0x842a6aa6 },
    { (const char *)0xfc51ec78,     0x1658, 0xff5be8de },
    { (const char *)0xfc5202d0,    0x50c78, 0xfabde2fb },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.01A", firmware_101a_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xfc158a45, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    8,  // block_count
};
