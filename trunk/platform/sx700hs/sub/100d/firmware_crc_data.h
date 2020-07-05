/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100d_crc32[]={
    { (const char *)0xfc020000,   0x4f4c64, 0xddf00351 },
    { (const char *)0xfcc64f9c,    0x1e808, 0xfcf3db26 },
    { (const char *)0xfcc3dfc0,    0x26fdc, 0xb446d261 },
    { (const char *)0xfca30f2c,     0x7398, 0x4a806932 },
    { (const char *)0xfca382cc,     0x4a70, 0xe397fcd5 },
    { (const char *)0xfca3cd44,   0x109020, 0xb76228af },
    { (const char *)0xfc514e8c,      0xeec, 0x16768e96 },
    { (const char *)0xfc515d78,    0x4fdd8, 0x2d8f3b8a },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00D", firmware_100d_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xfc136795, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    8,  // block_count
};
