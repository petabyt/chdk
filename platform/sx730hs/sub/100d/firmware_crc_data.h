/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100d_crc32[]={
    { (const char *)0xfc020000,   0x5c2528, 0xdbd7ffad },
    { (const char *)0xfcdcd810,    0x1b278,  0x71bf3ff },
    { (const char *)0xfcde8a88,     0x5b3d, 0xbadb95b3 },
    { (const char *)0xfcda103c,    0x2c7d4, 0x4759a102 },
    { (const char *)0xfcb95204,     0x7a50, 0x75ada8e7 },
    { (const char *)0xfcb9cc5c,     0x4ad0, 0xdb73ca79 },
    { (const char *)0xfcba1734,   0x116788, 0xc73e98e0 },
    { (const char *)0xfc5e2598,      0xf48, 0x847f3285 },
    { (const char *)0xfc5e34e0,    0x506f4, 0x891b64d3 },
};

const firmware_crc_block_t firmware_100e_crc32[]={
    { (const char *)0xfc020000,   0x5c2528, 0x1e79cc57 },
    { (const char *)0xfcdcd810,    0x1b278,  0x71bf3ff },
    { (const char *)0xfcde8a88,     0x5b3d, 0xbadb95b3 },
    { (const char *)0xfcda103c,    0x2c7d4, 0x4759a102 },
    { (const char *)0xfcb95204,     0x7a50, 0x75ada8e7 },
    { (const char *)0xfcb9cc5c,     0x4ad0, 0xdb73ca79 },
    { (const char *)0xfcba1734,   0x116788, 0xc73e98e0 },
    { (const char *)0xfc5e2598,      0xf48, 0x847f3285 },
    { (const char *)0xfc5e34e0,    0x506f4, 0x891b64d3 },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00D", firmware_100d_crc32 },
    { "GM1.00E", firmware_100e_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xfc3b38d5, // firmware_ver_ptr
    firmware_crc_list,
    2,  // sub_count
    9,  // block_count
};
