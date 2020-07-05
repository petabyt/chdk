/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100d_crc32[]={
    { (const char *)0xffc00000,   0x2a6726, 0x913c5b80 }, // ROMCODE
    { (const char *)0xfff16384,     0x9bb8, 0xe6448736 }, // RAM data
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00D", firmware_100d_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xffc6fc65, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
