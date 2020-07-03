/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_101a_crc32[]={
    { (const char *)0xe0020000,   0x5b81d4, 0xf52081c7 },
    { (const char *)0xe1017d88,     0x139c, 0xa3c424ea },
    { (const char *)0xe1019124,     0xc008, 0xa2a1854d },
    { (const char *)0xe0fd3770,    0x44618,   0x1ba9db },
    { (const char *)0xe0e79d0c,     0x4ab8, 0x52d0a220 },
    { (const char *)0xe0e7e7cc,     0x8000, 0x17f85c1f },
    { (const char *)0xe0e867d4,    0xd4350, 0xc1b5508b },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.01A", firmware_101a_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xe0503c4d, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    7,  // block_count
};
