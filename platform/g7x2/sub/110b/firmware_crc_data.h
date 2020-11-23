/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_110b_crc32[]={
    { (const char *)0xe0020000,   0x5b8220, 0xa2bc6204 }, // ROMCODE
    { (const char *)0xe0e79d54,    0xe0e18, 0xf81ac2c9 }, // zico_0, zico_1, zico_2
    { (const char *)0xe0fd37b8,    0x519b4, 0x26b85e07 }, // RAM data, RAM code, TCM code
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.10B", firmware_110b_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xe0503c49, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    3,  // block_count
};
