/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100e_crc32[]={
    { (const char *)0xff810000,   0x3008d4, 0xae71887e }, // ROMCODE
    { (const char *)0xffbf7050,    0x1ac94,  0xe86efe0 }, // RAM data, RAM code
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00E", firmware_100e_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff87d84d, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
