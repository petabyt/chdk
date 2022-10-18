/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100d_crc32[]={
    { (const char *)0xff810000,   0x37bd6a, 0x8b9cd944 }, // ROMCODE
    { (const char *)0xffc56cc8,     0xee20, 0x2aeeedb8 }, // RAM data
};

const firmware_crc_block_t firmware_100b_crc32[]={
    { (const char *)0xff810000,   0x37bd6a, 0xd456be6c }, // ROMCODE
    { (const char *)0xffc56cc8,     0xee20, 0xd06f011d }, // RAM data
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00D", firmware_100d_crc32 },
    { "GM1.00B", firmware_100b_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff894e35, // firmware_ver_ptr
    firmware_crc_list,
    2,  // sub_count
    2,  // block_count
};
