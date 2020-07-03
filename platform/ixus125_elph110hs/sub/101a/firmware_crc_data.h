/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_101a_crc32[]={
    { (const char *)0xff000000,   0x412730, 0xd88d57af },
    { (const char *)0xff63ce38,     0xf6dc, 0x43d3c33b },
    { (const char *)0xff62ab24,    0x12314, 0x69e8a1bb },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.01A", firmware_101a_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff07a351, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    3,  // block_count
};
