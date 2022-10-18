/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100c_crc32[]={
    { (const char *)0xff810000,   0x3e5da4, 0x5badfd34 }, // ROMCODE
    { (const char *)0xffd42fe0,    0x1d430, 0x3ff42edb }, // RAM data, RAM code
};

const firmware_crc_block_t firmware_100b_crc32[]={
    { (const char *)0xff810000,   0x3e5da4, 0x6c90340b }, // ROMCODE
    { (const char *)0xffd42fe0,    0x1d430, 0x3ff42edb }, // RAM data, RAM code
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00C", firmware_100c_crc32 },
    { "GM1.00B", firmware_100b_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff89fca5, // firmware_ver_ptr
    firmware_crc_list,
    2,  // sub_count
    2,  // block_count
};
