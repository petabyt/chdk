/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_101a_crc32[]={
    { (const char *)0xe0020000,   0x5b81d4, 0xf52081c7 }, // ROMCODE
    { (const char *)0xe0e79d0c,    0xe0e18, 0xf81ac2c9 }, // zico_0, zico_1, zico_2
    { (const char *)0xe0fd3770,    0x519bc, 0x3464921f }, // RAM data, RAM code, TCM code
};

const firmware_crc_block_t firmware_101b_crc32[]={
    { (const char *)0xe0020000,   0x5b81d4, 0x7c4c3d01 }, // ROMCODE
    { (const char *)0xe0e79d0c,    0xe0e18, 0xf81ac2c9 }, // zico_0, zico_1, zico_2
    { (const char *)0xe0fd3770,    0x519bc, 0x3464921f }, // RAM data, RAM code, TCM code
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.01A", firmware_101a_crc32 },
    { "GM1.01B", firmware_101b_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xe0503c4d, // firmware_ver_ptr
    firmware_crc_list,
    2,  // sub_count
    3,  // block_count
};
