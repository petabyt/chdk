/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100f_crc32[]={
    { (const char *)0xfc020000,   0x55be80, 0xd421297c },
    { (const char *)0xfcd16b8c,    0x2caa4, 0xf051a6b0 },
    { (const char *)0xfccec580,    0x2a60c, 0x5129c3d0 },
    { (const char *)0xfcad2ac8,     0x77b8, 0x55e7705a },
    { (const char *)0xfcada288,     0x4ad0, 0x3f57c6f7 },
    { (const char *)0xfcaded60,   0x1060f0, 0xc7f13513 },
    { (const char *)0xfc57c0a8,      0xeec, 0xecb8cfe5 },
    { (const char *)0xfc57cf94,    0x4eda0, 0xd8139245 },
};

const firmware_crc_block_t firmware_100g_crc32[]={
    { (const char *)0xfc020000,   0x55be80, 0xa635b69c },
    { (const char *)0xfcd16b8c,    0x2caa4, 0xf051a6b0 },
    { (const char *)0xfccec580,    0x2a60c, 0x5129c3d0 },
    { (const char *)0xfcad2ac8,     0x77b8, 0x55e7705a },
    { (const char *)0xfcada288,     0x4ad0, 0x3f57c6f7 },
    { (const char *)0xfcaded60,   0x1060f0, 0xc7f13513 },
    { (const char *)0xfc57c0a8,      0xeec, 0xecb8cfe5 },
    { (const char *)0xfc57cf94,    0x4eda0, 0xd8139245 },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00F", firmware_100f_crc32 },
    { "GM1.00G", firmware_100g_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xfc15c1f9, // firmware_ver_ptr
    firmware_crc_list,
    2,  // sub_count
    8,  // block_count
};
