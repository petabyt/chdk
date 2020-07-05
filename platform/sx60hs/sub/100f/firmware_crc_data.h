/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100f_crc32[]={
    { (const char *)0xfc020000,   0x55be80, 0xd421297c }, // ROMCODE
    { (const char *)0xfc57c0a8,    0x4fc8c, 0x8b847cf2 }, // omar_0, omar_1
    { (const char *)0xfcad2ac8,   0x112388, 0x568e698c }, // zico_0, zico_1, zico_2
    { (const char *)0xfccec580,    0x570b0, 0x521eef08 }, // RAM data, RAM code
};

const firmware_crc_block_t firmware_100g_crc32[]={
    { (const char *)0xfc020000,   0x55be80, 0xa635b69c }, // ROMCODE
    { (const char *)0xfc57c0a8,    0x4fc8c, 0x8b847cf2 }, // omar_0, omar_1
    { (const char *)0xfcad2ac8,   0x112388, 0x568e698c }, // zico_0, zico_1, zico_2
    { (const char *)0xfccec580,    0x570b0, 0x521eef08 }, // RAM data, RAM code
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00F", firmware_100f_crc32 },
    { "GM1.00G", firmware_100g_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xfc15c1f9, // firmware_ver_ptr
    firmware_crc_list,
    2,  // sub_count
    4,  // block_count
};
