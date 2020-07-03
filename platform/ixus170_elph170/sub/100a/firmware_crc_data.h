/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100a_crc32[]={
    { (const char *)0xff810000,   0x39dbc4, 0x9c5178c9 },
    { (const char *)0xffcee1fc,     0xd858, 0x2fd7197a },
    { (const char *)0xffcdfe80,     0xe37c, 0xb99041ed },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00A", firmware_100a_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff89e7ad, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    3,  // block_count
};
