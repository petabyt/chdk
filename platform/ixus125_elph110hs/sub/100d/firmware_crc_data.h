/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100d_crc32[]={
    { (const char *)0xff000000,   0x412608, 0xf4aeb5fc },
    { (const char *)0xff63cd08,     0xf6dc, 0x52a5a87f },
    { (const char *)0xff62a9fc,    0x1230c, 0xc7a0d93b },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00D", firmware_100d_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff07a351, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    3,  // block_count
};
