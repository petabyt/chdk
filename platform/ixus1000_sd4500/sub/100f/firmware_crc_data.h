/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100f_crc32[]={
    { (const char *)0xff810000,   0x37bd6e, 0x921e56f7 }, // ROMCODE
    { (const char *)0xffc56cd0,     0xee28, 0xad44ecec }, // RAM data
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00F", firmware_100f_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff894e35, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
