/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_102d_crc32[]={
    { (const char *)0xff810000,   0x32a416, 0xa2e17fb4 },
    { (const char *)0xffc0f184,     0xcefc, 0x5b0bd9fb },
};

const firmware_crc_block_t firmware_102c_crc32[]={
    { (const char *)0xff810000,   0x32a416, 0x3571a11f },
    { (const char *)0xffc0f184,     0xcefc, 0x5b0bd9fb },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.02D", firmware_102d_crc32 },
    { "GM1.02C", firmware_102c_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff88e43d, // firmware_ver_ptr
    firmware_crc_list,
    2,  // sub_count
    2,  // block_count
};
