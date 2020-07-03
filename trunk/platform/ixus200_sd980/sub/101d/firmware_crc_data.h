/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_101d_crc32[]={
    { (const char *)0xff810000,   0x32ecfa, 0x43fac5f2 },
    { (const char *)0xffc029e4,    0x1eff0, 0x8d3ae8a7 },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.01D", firmware_101d_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff887c99, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
