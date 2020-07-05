/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100b_crc32[]={
    { (const char *)0xfc020000,   0x55be6c, 0x69b9a1ce },
    { (const char *)0xfcd16b7c,    0x2caa4, 0x1cbbfce3 },
    { (const char *)0xfccec570,    0x2a60c, 0x8ee55799 },
    { (const char *)0xfcad2ab8,     0x77b8, 0x55e7705a },
    { (const char *)0xfcada278,     0x4ad0, 0x3f57c6f7 },
    { (const char *)0xfcaded50,   0x1060f0, 0xc7f13513 },
    { (const char *)0xfc57c094,      0xeec, 0xecb8cfe5 },
    { (const char *)0xfc57cf80,    0x4eda0, 0xd8139245 },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00B", firmware_100b_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xfc15c1f9, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    8,  // block_count
};
