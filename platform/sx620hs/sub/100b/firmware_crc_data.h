/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100b_crc32[]={
    { (const char *)0xff010000,   0x6879d4, 0xcf26e20c },
    { (const char *)0xff912534,    0x32f28, 0xc5d77a46 },
    { (const char *)0xff8fa98c,    0x17ba8, 0xed5a9166 },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00B", firmware_100b_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff0aec8d, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    3,  // block_count
};
