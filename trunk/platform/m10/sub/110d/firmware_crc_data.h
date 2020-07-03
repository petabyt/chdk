/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_110d_crc32[]={
    { (const char *)0xfc020000,   0x5e8084, 0xb7fbc035 },
    { (const char *)0xfceb18d0,    0x26d60, 0xa81014f3 },
    { (const char *)0xfced8630,     0x6c1d, 0xef7cb028 },
    { (const char *)0xfce6459c,    0x4d334, 0x32762c03 },
    { (const char *)0xfca326f8,     0x7938, 0x4ddee9f5 },
    { (const char *)0xfca3a038,     0x4b30, 0xd577ff45 },
    { (const char *)0xfca3eb70,   0x115060,  0xb4e5b2a },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.10D", firmware_110d_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xfc1fb049, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    7,  // block_count
};
