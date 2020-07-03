/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100b_crc32[]={
    { (const char *)0xfc020000,   0x59d2e0, 0xcc64e1dd },
    { (const char *)0xfcd67020,    0x2cc1c, 0x3682bc35 },
    { (const char *)0xfcd39d68,    0x2d2b8, 0x199295aa },
    { (const char *)0xfcb212d4,     0x77b8, 0x55e7705a },
    { (const char *)0xfcb28a94,     0x4ad0, 0x85edece7 },
    { (const char *)0xfcb2d56c,   0x106100, 0xbbe3bac7 },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00B", firmware_100b_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xfc159205, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    6,  // block_count
};
