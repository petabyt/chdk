/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100c_crc32[]={
    { (const char *)0xff010000,   0x62af10, 0xe8eba2a6 },
    { (const char *)0xff8c92e8,    0x318c4, 0x55ac64b9 },
    { (const char *)0xff8b1358,    0x17f90, 0x2bbc9d87 },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00C", firmware_100c_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff0ae9f5, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    3,  // block_count
};
