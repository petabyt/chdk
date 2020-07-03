/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100d_crc32[]={
    { (const char *)0xff810000,   0x2a025a, 0xd3793da0 },
    { (const char *)0xffb1cddc,     0xd834, 0xfefa778d },
};

const firmware_crc_block_t firmware_100e_crc32[]={
    { (const char *)0xff810000,   0x2a025a, 0x36e47b4a },
    { (const char *)0xffb1cddc,     0xd834, 0xfefa778d },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00D", firmware_100d_crc32 },
    { "GM1.00E", firmware_100e_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff86c37d, // firmware_ver_ptr
    firmware_crc_list,
    2,  // sub_count
    2,  // block_count
};
