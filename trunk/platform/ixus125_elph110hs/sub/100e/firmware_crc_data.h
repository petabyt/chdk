/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100e_crc32[]={
    { (const char *)0xff000000,   0x4126f8, 0x71e3c414 },
    { (const char *)0xff63cdf8,     0xf6dc, 0x52a5a87f },
    { (const char *)0xff62aaec,    0x1230c, 0x42da59ea },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00E", firmware_100e_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff07a351, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    3,  // block_count
};
