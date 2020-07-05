/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100g_crc32[]={
    { (const char *)0xff810000,   0x3193d0, 0x9e80d3c4 }, // ROMCODE, RAM data
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00G", firmware_100g_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff81a491, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    1,  // block_count
};
