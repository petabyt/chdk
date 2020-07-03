/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100h_crc32[]={
    { (const char *)0xfc020000,   0x4fe9fc,  0x70bf7ca },
    { (const char *)0xfcbebac8,    0x1e4e8, 0xe661a896 },
    { (const char *)0xfcbc2230,    0x29898,  0x2eabb6a },
    { (const char *)0xfc9c5b2c,     0x7300, 0x2dc10243 },
    { (const char *)0xfc9cce34,     0x4780, 0x473f703f },
    { (const char *)0xfc9d15bc,    0xfc208, 0x842a6aa6 },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00H", firmware_100h_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xfc158a45, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    6,  // block_count
};
