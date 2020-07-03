/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100a_crc32[]={
    { (const char *)0xff010000,   0x62aed0, 0x3bbb5a0c },
    { (const char *)0xff8c92a8,    0x318c4, 0xbf12a5e1 },
    { (const char *)0xff8b1318,    0x17f90, 0xa6367d51 },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00A", firmware_100a_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff0ae9f5, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    3,  // block_count
};
