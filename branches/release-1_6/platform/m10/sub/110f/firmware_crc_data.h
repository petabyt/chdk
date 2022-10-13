/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_110f_crc32[]={
    { (const char *)0xfc020000,   0x5e80b8, 0xec80eab1 }, // ROMCODE
    { (const char *)0xfc6082e0,    0x19538, 0xc054c1f2 }, // omar_0, omar_1
    { (const char *)0xfca32730,   0x1214d8, 0x55193681 }, // zico_0, zico_1, zico_2
    { (const char *)0xfce645d4,    0x7acb1, 0x9e966d8c }, // RAM data, RAM code, TCM code
};

const firmware_crc_block_t firmware_110g_crc32[]={
    { (const char *)0xfc020000,   0x5e80b8,  0x775dedb }, // ROMCODE
    { (const char *)0xfc6082e0,    0x19538, 0xc054c1f2 }, // omar_0, omar_1
    { (const char *)0xfca32730,   0x1214d8, 0x55193681 }, // zico_0, zico_1, zico_2
    { (const char *)0xfce645d4,    0x7acb1, 0x9e966d8c }, // RAM data, RAM code, TCM code
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.10F", firmware_110f_crc32 },
    { "GM1.10G", firmware_110g_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xfc1fb049, // firmware_ver_ptr
    firmware_crc_list,
    2,  // sub_count
    4,  // block_count
};
