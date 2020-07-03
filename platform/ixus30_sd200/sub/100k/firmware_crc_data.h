/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100k_crc32[]={
    { (const char *)0xff810000,   0x2c74a0, 0x741cb4b1 },
    { (const char *)0xffad74a0,     0xeae0, 0x3e908c51 },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "1.00K", firmware_100k_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff81e42d, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
