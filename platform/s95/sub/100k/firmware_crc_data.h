/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100k_crc32[]={
    { (const char *)0xff810000,   0x393b66, 0x41979f2a },
    { (const char *)0xffc9a254,     0xf6e4, 0x469cc93a },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00K", firmware_100k_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff89548d, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
