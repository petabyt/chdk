/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100a_crc32[]={
    { (const char *)0xff810000,   0x2e0092, 0x34ad3f14 }, // ROMCODE
    { (const char *)0xffb84e78,     0xc074, 0xe661f405 }, // RAM data
};

const firmware_crc_block_t firmware_100b_crc32[]={
    { (const char *)0xff810000,   0x2e0092, 0x3c76c634 }, // ROMCODE
    { (const char *)0xffb84e78,     0xc074, 0xe661f405 }, // RAM data
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00A", firmware_100a_crc32 },
    { "GM1.00B", firmware_100b_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff86ed9d, // firmware_ver_ptr
    firmware_crc_list,
    2,  // sub_count
    2,  // block_count
};
