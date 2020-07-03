/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100e_crc32[]={
    { (const char *)0xff000000,   0x49ff98, 0x8fd4ae6c },
    { (const char *)0xff746280,    0x10374, 0xbcba3c8a },
    { (const char *)0xff7310bc,    0x151c4, 0x8b7a5100 },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00E", firmware_100e_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff098729, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    3,  // block_count
};
