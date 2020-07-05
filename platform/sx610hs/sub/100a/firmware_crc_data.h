/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100a_crc32[]={
    { (const char *)0xff010000,   0x622c90, 0x2bc824ab }, // ROMCODE
    { (const char *)0xff84de10,    0x48f0c, 0x79a25d68 }, // RAM data, RAM code
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00A", firmware_100a_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff0aaf95, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
