/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_110d_crc32[]={
    { (const char *)0xfc020000,   0x5e8084, 0xb7fbc035 }, // ROMCODE
    { (const char *)0xfc6082ac,    0x19538, 0xc054c1f2 }, // omar_0, omar_1
    { (const char *)0xfca326f8,   0x1214d8, 0x55193681 }, // zico_0, zico_1, zico_2
    { (const char *)0xfce6459c,    0x7acb1, 0xcb90802d }, // RAM data, RAM code, TCM code
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.10D", firmware_110d_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xfc1fb049, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    4,  // block_count
};
