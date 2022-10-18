/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_103a_crc32[]={
    { (const char *)0xff810000,   0x2f47d6, 0x35a9d9e4 }, // ROMCODE
    { (const char *)0xffb9b3ec,     0xf158, 0x7c5469e7 }, // RAM data
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.03A", firmware_103a_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff878875, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
