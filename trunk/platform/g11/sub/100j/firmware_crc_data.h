/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100j_crc32[]={
    { (const char *)0xff810000,   0x3303ca, 0xd2e2443f },
    { (const char *)0xffc0c238,     0xd00c, 0x244e2ad1 },
};

const firmware_crc_block_t firmware_100k_crc32[]={
    { (const char *)0xff810000,   0x3303ca, 0x75a397bc },
    { (const char *)0xffc0c238,     0xd00c, 0x244e2ad1 },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00J", firmware_100j_crc32 },
    { "GM1.00K", firmware_100k_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff88c7a9, // firmware_ver_ptr
    firmware_crc_list,
    2,  // sub_count
    2,  // block_count
};
