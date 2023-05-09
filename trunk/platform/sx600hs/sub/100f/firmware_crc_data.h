/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100f_crc32[]={
    { (const char *)0xff010000,   0x5e6904,  0x12ead6b }, // ROMCODE
    { (const char *)0xff83f7cc,    0x43624, 0x5f66fac1 }, // RAM data, RAM code
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00F", firmware_100f_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff0a5101, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
