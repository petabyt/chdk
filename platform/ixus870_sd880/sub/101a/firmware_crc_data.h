/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_101a_crc32[]={
    { (const char *)0xff810000,   0x2c5eda, 0x3d3804e3 }, // ROMCODE
    { (const char *)0xffb53358,     0xe2e8, 0x65ca0a86 }, // RAM data
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.01A", firmware_101a_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff8708a5, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
