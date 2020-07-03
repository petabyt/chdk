/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_101b_crc32[]={
    { (const char *)0xff810000,   0x387e0a, 0x530e736f },
    { (const char *)0xffc7ede0,     0xe9c0, 0xeff03ebe },
};

const firmware_crc_block_t firmware_101c_crc32[]={
    { (const char *)0xff810000,   0x387e0a, 0xad85af19 },
    { (const char *)0xffc7ede0,     0xe9c0, 0xeff03ebe },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.01B", firmware_101b_crc32 },
    { "GM1.01C", firmware_101c_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff8938ad, // firmware_ver_ptr
    firmware_crc_list,
    2,  // sub_count
    2,  // block_count
};
