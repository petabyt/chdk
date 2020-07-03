/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100c_crc32[]={
    { (const char *)0xfc020000,   0x59d2c8, 0x999f61f1 },
    { (const char *)0xfcd67008,    0x2cc1c, 0xf8c9d003 },
    { (const char *)0xfcd39d50,    0x2d2b8, 0x3ba40e07 },
    { (const char *)0xfcb212bc,     0x77b8, 0x55e7705a },
    { (const char *)0xfcb28a7c,     0x4ad0, 0x85edece7 },
    { (const char *)0xfcb2d554,   0x106100, 0xbbe3bac7 },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00C", firmware_100c_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xfc159205, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    6,  // block_count
};
