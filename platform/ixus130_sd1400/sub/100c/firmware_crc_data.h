/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100c_crc32[]={
    { (const char *)0xff810000,   0x32d5de, 0x46517dfe }, // ROMCODE
    { (const char *)0xffbf8434,     0xd2d0, 0xb4f76ef6 }, // RAM data
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00C", firmware_100c_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff88b2ad, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
