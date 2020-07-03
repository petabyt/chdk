/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_103a_crc32[]={
    { (const char *)0xf8000000,   0x648b44, 0x2b77f1cc },
    { (const char *)0xf896dfec,    0x2e264, 0xe8be69f5 },
    { (const char *)0xf8953540,    0x1aaac, 0x22e61a3d },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.03A", firmware_103a_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xf80d5cfd, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    3,  // block_count
};
