/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100g_crc32[]={
    { (const char *)0xff810000,   0x2e66b0, 0x6e2432e4 }, // ROMCODE, RAM data
};

const firmware_crc_block_t firmware_100e_crc32[]={
    { (const char *)0xff810000,   0x2e66b0, 0x120dcdb8 }, // ROMCODE, RAM data
};

const firmware_crc_block_t firmware_100f_crc32[]={
    { (const char *)0xff810000,   0x2e66b0, 0x9598b6f0 }, // ROMCODE, RAM data
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00G", firmware_100g_crc32 },
    { "GM1.00E", firmware_100e_crc32 },
    { "GM1.00F", firmware_100f_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff81b27d, // firmware_ver_ptr
    firmware_crc_list,
    3,  // sub_count
    1,  // block_count
};
