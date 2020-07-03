/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100a_crc32[]={
    { (const char *)0xff000000,   0x4f9478,  0x303c6d1 },
    { (const char *)0xff6982d4,    0x2aadc,  0xf6971a7 },
    { (const char *)0xff684650,    0x13c84, 0x48a9980b },
};

const firmware_crc_block_t firmware_100b_crc32[]={
    { (const char *)0xff000000,   0x4f9478, 0x113431cc },
    { (const char *)0xff6982d4,    0x2aadc,  0xf6971a7 },
    { (const char *)0xff684650,    0x13c84, 0x48a9980b },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00A", firmware_100a_crc32 },
    { "GM1.00B", firmware_100b_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff0c164d, // firmware_ver_ptr
    firmware_crc_list,
    2,  // sub_count
    3,  // block_count
};
