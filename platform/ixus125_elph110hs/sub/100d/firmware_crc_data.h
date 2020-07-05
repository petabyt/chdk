/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100d_crc32[]={
    { (const char *)0xff000000,   0x412608, 0xf4aeb5fc }, // ROMCODE
    { (const char *)0xff62a9fc,    0x219e8, 0x1d52a10b }, // RAM data, RAM code
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00D", firmware_100d_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff07a351, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
