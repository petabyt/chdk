/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100c_crc32[]={
    { (const char *)0xfc020000,   0x55be58, 0x295eaab6 }, // ROMCODE
    { (const char *)0xfc57c080,    0x4fc8c, 0x8b847cf2 }, // omar_0, omar_1
    { (const char *)0xfcad2aa0,   0x112388, 0x568e698c }, // zico_0, zico_1, zico_2
    { (const char *)0xfccec558,    0x570b0, 0xd2b0e5da }, // RAM data, RAM code
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00C", firmware_100c_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xfc15c1f9, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    4,  // block_count
};
