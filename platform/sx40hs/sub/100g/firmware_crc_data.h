/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100g_crc32[]={
    { (const char *)0xff000000,   0x43381a, 0x2786129a }, // ROMCODE
    { (const char *)0xff62743c,    0x11e18, 0x201e4249 }, // RAM data
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00G", firmware_100g_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff090055, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
