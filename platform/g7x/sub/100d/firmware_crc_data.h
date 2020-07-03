/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100d_crc32[]={
    { (const char *)0xfc020000,   0x59d2f4, 0x7ead9dca },
    { (const char *)0xfcd67030,    0x2cc1c, 0xfb622e0e },
    { (const char *)0xfcd39d78,    0x2d2b8, 0xf5966fa8 },
    { (const char *)0xfcb212e4,     0x77b8, 0x55e7705a },
    { (const char *)0xfcb28aa4,     0x4ad0, 0x85edece7 },
    { (const char *)0xfcb2d57c,   0x106100, 0xbbe3bac7 },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00D", firmware_100d_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xfc159205, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    6,  // block_count
};
