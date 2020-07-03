/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_101b_crc32[]={
    { (const char *)0xfc020000,   0x4feaa0, 0x84e375fb },
    { (const char *)0xfcbebb70,    0x1e4e8, 0xdfb42734 },
    { (const char *)0xfcbc22d0,    0x298a0, 0xb7676f4c },
    { (const char *)0xfc9c5bcc,     0x7300, 0x2dc10243 },
    { (const char *)0xfc9cced4,     0x4780, 0x473f703f },
    { (const char *)0xfc9d165c,    0xfc208, 0x842a6aa6 },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.01B", firmware_101b_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xfc158a7d, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    6,  // block_count
};
