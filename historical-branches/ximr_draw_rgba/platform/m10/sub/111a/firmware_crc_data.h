/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_111a_crc32[]={
    { (const char *)0xfc020000,   0x5e80e8, 0xfe8102fa }, // ROMCODE
    { (const char *)0xfc608310,    0x19538, 0xc054c1f2 }, // omar_0, omar_1
    { (const char *)0xfca32760,   0x1214d8, 0x55193681 }, // zico_0, zico_1, zico_2
    { (const char *)0xfce64604,    0x7acb1, 0x7354a5c9 }, // RAM data, RAM code, TCM code
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.11A", firmware_111a_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xfc1fb051, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    4,  // block_count
};
