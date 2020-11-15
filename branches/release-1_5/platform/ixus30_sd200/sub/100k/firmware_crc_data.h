/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100k_crc32[]={
    { (const char *)0xff810000,   0x2d5f80, 0xc2f86805 }, // ROMCODE, RAM data
};

firmware_crc_sub_t firmware_crc_list[]={
    { "1.00K", firmware_100k_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff81e42d, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    1,  // block_count
};
