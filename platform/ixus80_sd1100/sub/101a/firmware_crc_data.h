/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_101a_crc32[]={
    { (const char *)0xff810000,   0x29858a, 0xba8f6014 }, // ROMCODE
    { (const char *)0xffb126f4,     0xd58c, 0xb60ff35c }, // RAM data
};

const firmware_crc_block_t firmware_101b_crc32[]={
    { (const char *)0xff810000,   0x29858a, 0x4ead84e9 }, // ROMCODE
    { (const char *)0xffb126f4,     0xd58c, 0xb60ff35c }, // RAM data
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.01A", firmware_101a_crc32 },
    { "GM1.01B", firmware_101b_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff86bea1, // firmware_ver_ptr
    firmware_crc_list,
    2,  // sub_count
    2,  // block_count
};
