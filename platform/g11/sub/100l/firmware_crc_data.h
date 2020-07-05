/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100l_crc32[]={
    { (const char *)0xff810000,   0x330586, 0x115d88be }, // ROMCODE
    { (const char *)0xffc0c3f8,     0xd00c, 0xec2d7d93 }, // RAM data
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00L", firmware_100l_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff88c7f9, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
