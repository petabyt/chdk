/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_101b_crc32[]={
    { (const char *)0xf8000000,   0x6492d8, 0x2ab4a69e },
    { (const char *)0xf896e790,    0x2e264, 0x829f0f5b },
    { (const char *)0xf8953cd0,    0x1aac0, 0x71136464 },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.01B", firmware_101b_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xf80d5d19, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    3,  // block_count
};
