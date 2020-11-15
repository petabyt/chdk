/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_201a_crc32[]={
    { (const char *)0xff810000,   0x31b0da, 0x6145d0c1 }, // ROMCODE
    { (const char *)0xffbe2c7c,    0x10034, 0x875ea413 }, // RAM data
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM2.01A", firmware_201a_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff87ccc1, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
