/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100c_crc32[]={
    { (const char *)0xff010000,   0x5e4eb0, 0xb889b00e },
    { (const char *)0xff84f3c0,    0x2c880, 0x76103c7c },
    { (const char *)0xff838654,    0x16d6c, 0x2e5edbd6 },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00C", firmware_100c_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff0a4c59, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    3,  // block_count
};
