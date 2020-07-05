/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_101d_crc32[]={
    { (const char *)0xff810000,   0x2dd8de, 0xbb1d6a66 }, // ROMCODE
    { (const char *)0xffb7dfe4,     0xbeec, 0xb3921de6 }, // RAM data
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.01D", firmware_101d_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff86e6e9, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
