/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100c_crc32[]={
    { (const char *)0xfc020000,   0x5c2500, 0x75f518b8 },
    { (const char *)0xfcdcd810,    0x1b278, 0xb9816f21 },
    { (const char *)0xfcde8a88,     0x5b3d, 0x5896ef59 },
    { (const char *)0xfcda103c,    0x2c7d4,  0xff66922 },
    { (const char *)0xfcb951dc,     0x7a50, 0x75ada8e7 },
    { (const char *)0xfcb9cc34,     0x4ad0, 0xdb73ca79 },
    { (const char *)0xfcba170c,   0x116788, 0xc73e98e0 },
    { (const char *)0xfc5e2570,      0xf48, 0x847f3285 },
    { (const char *)0xfc5e34b8,    0x506f4, 0x891b64d3 },
};

const firmware_crc_block_t firmware_100b_crc32[]={
    { (const char *)0xfc020000,   0x5c2500, 0x8b873b97 },
    { (const char *)0xfcdcd810,    0x1b278, 0xb9816f21 },
    { (const char *)0xfcde8a88,     0x5b3d, 0x5896ef59 },
    { (const char *)0xfcda103c,    0x2c7d4,  0xff66922 },
    { (const char *)0xfcb951dc,     0x7a50, 0x75ada8e7 },
    { (const char *)0xfcb9cc34,     0x4ad0, 0xdb73ca79 },
    { (const char *)0xfcba170c,   0x116788, 0xc73e98e0 },
    { (const char *)0xfc5e2570,      0xf48, 0x847f3285 },
    { (const char *)0xfc5e34b8,    0x506f4, 0x891b64d3 },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00C", firmware_100c_crc32 },
    { "GM1.00B", firmware_100b_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xfc3b38ad, // firmware_ver_ptr
    firmware_crc_list,
    2,  // sub_count
    9,  // block_count
};
