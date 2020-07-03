/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_110f_crc32[]={
    { (const char *)0xfc020000,   0x5e80b8, 0xec80eab1 },
    { (const char *)0xfceb1908,    0x26d60, 0xdf04d49f },
    { (const char *)0xfced8668,     0x6c1d, 0xa75ff59d },
    { (const char *)0xfce645d4,    0x4d334, 0x181dc70f },
    { (const char *)0xfca32730,     0x7938, 0x4ddee9f5 },
    { (const char *)0xfca3a070,     0x4b30, 0xd577ff45 },
    { (const char *)0xfca3eba8,   0x115060,  0xb4e5b2a },
};

const firmware_crc_block_t firmware_110g_crc32[]={
    { (const char *)0xfc020000,   0x5e80b8,  0x775dedb },
    { (const char *)0xfceb1908,    0x26d60, 0xdf04d49f },
    { (const char *)0xfced8668,     0x6c1d, 0xa75ff59d },
    { (const char *)0xfce645d4,    0x4d334, 0x181dc70f },
    { (const char *)0xfca32730,     0x7938, 0x4ddee9f5 },
    { (const char *)0xfca3a070,     0x4b30, 0xd577ff45 },
    { (const char *)0xfca3eba8,   0x115060,  0xb4e5b2a },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.10F", firmware_110f_crc32 },
    { "GM1.10G", firmware_110g_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xfc1fb049, // firmware_ver_ptr
    firmware_crc_list,
    2,  // sub_count
    7,  // block_count
};
