/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100a_crc32[]={
    { (const char *)0xff000000,   0x3a2938, 0x71daec86 },
    { (const char *)0xff4adcd0,     0xf78c, 0x868a07bc },
    { (const char *)0xff49f914,     0xe3bc, 0x9dff0fb2 },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00A", firmware_100a_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff079365, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    3,  // block_count
};
