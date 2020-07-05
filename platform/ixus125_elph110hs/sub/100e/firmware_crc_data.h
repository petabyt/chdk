/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100e_crc32[]={
    { (const char *)0xff000000,   0x4126f8, 0x71e3c414 }, // ROMCODE
    { (const char *)0xff62aaec,    0x219e8, 0x2c429713 }, // RAM data, RAM code
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00E", firmware_100e_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff07a351, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
