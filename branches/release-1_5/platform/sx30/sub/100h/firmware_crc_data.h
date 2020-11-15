/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100h_crc32[]={
    { (const char *)0xff810000,   0x3861be, 0x5d7ca96f }, // ROMCODE
    { (const char *)0xffc90780,     0xefb8, 0x848e4152 }, // RAM data
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00H", firmware_100h_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff898a41, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
