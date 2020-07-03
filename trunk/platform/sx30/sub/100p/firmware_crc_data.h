/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100p_crc32[]={
    { (const char *)0xff810000,   0x3863ba, 0x8b791dea },
    { (const char *)0xffc90980,     0xefb8,   0x3a494c },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00P", firmware_100p_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff898a45, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
