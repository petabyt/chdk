/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100d_crc32[]={
    { (const char *)0xff810000,   0x285366,  0x953ee36 }, // ROMCODE
    { (const char *)0xffafb86c,    0x11ea8, 0xdfb93c77 }, // RAM data
};

const firmware_crc_block_t firmware_100c_crc32[]={
    { (const char *)0xff810000,   0x285366, 0xe934c5ab }, // ROMCODE
    { (const char *)0xffafb86c,    0x11ea8, 0xdfb93c77 }, // RAM data
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00D", firmware_100d_crc32 },
    { "GM1.00C", firmware_100c_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff868919, // firmware_ver_ptr
    firmware_crc_list,
    2,  // sub_count
    2,  // block_count
};
