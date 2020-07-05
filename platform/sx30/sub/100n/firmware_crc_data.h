/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100n_crc32[]={
    { (const char *)0xff810000,   0x3863da, 0x2fe0a6a6 }, // ROMCODE
    { (const char *)0xffc909a0,     0xefb8, 0xaa3b8bda }, // RAM data
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00N", firmware_100n_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff898a45, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
