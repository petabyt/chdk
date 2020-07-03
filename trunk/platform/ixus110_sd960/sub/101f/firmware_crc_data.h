/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_101f_crc32[]={
    { (const char *)0xff810000,   0x2dd9ce, 0xc9fae20b },
    { (const char *)0xffb7e0d4,     0xbeec, 0x773df45f },
};

const firmware_crc_block_t firmware_101g_crc32[]={
    { (const char *)0xff810000,   0x2dd9ce, 0xe9b729ec },
    { (const char *)0xffb7e0d4,     0xbeec, 0x773df45f },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.01F", firmware_101f_crc32 },
    { "GM1.01G", firmware_101g_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff86e6e9, // firmware_ver_ptr
    firmware_crc_list,
    2,  // sub_count
    2,  // block_count
};
