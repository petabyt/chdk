/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100i_crc32[]={
    { (const char *)0xff810000,   0x2b0b6a, 0xb4a4bb5b }, // ROMCODE
    { (const char *)0xffb2e41c,    0x127e4, 0x1c70e0f9 }, // RAM data
};

const firmware_crc_block_t firmware_100h_crc32[]={
    { (const char *)0xff810000,   0x2b0b6a, 0x967bada6 }, // ROMCODE
    { (const char *)0xffb2e41c,    0x127e4, 0x1c70e0f9 }, // RAM data
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00I", firmware_100i_crc32 },
    { "GM1.00H", firmware_100h_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff86e88d, // firmware_ver_ptr
    firmware_crc_list,
    2,  // sub_count
    2,  // block_count
};
