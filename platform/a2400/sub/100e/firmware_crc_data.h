/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100e_crc32[]={
    { (const char *)0xff810000,   0x300e40, 0x618dbe99 },
    { (const char *)0xffc036bc,     0xf5d4, 0xcd332d12 },
    { (const char *)0xffbf7ce0,     0xb9dc, 0x28e1e654 },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00E", firmware_100e_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff8801ed, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    3,  // block_count
};
