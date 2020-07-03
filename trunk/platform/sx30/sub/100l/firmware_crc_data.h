/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100l_crc32[]={
    { (const char *)0xff810000,   0x386366, 0xd17bd4f6 },
    { (const char *)0xffc90928,     0xefb8, 0xc168808c },
};

const firmware_crc_block_t firmware_100m_crc32[]={
    { (const char *)0xff810000,   0x386366, 0x98388d15 },
    { (const char *)0xffc90928,     0xefb8, 0xc168808c },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00L", firmware_100l_crc32 },
    { "GM1.00M", firmware_100m_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff898a45, // firmware_ver_ptr
    firmware_crc_list,
    2,  // sub_count
    2,  // block_count
};
