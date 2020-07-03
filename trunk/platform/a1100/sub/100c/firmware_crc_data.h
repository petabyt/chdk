/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100c_crc32[]={
    { (const char *)0xffc00000,   0x26fa66, 0x5229b57f },
    { (const char *)0xffed53a0,     0x98b0, 0xe46011cc },
};

const firmware_crc_block_t firmware_100b_crc32[]={
    { (const char *)0xffc00000,   0x26fa66, 0x3613c327 },
    { (const char *)0xffed53a0,     0x98b0, 0xe46011cc },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00C", firmware_100c_crc32 },
    { "GM1.00B", firmware_100b_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xffc584fd, // firmware_ver_ptr
    firmware_crc_list,
    2,  // sub_count
    2,  // block_count
};
