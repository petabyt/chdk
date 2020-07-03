/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100g_crc32[]={
    { (const char *)0xff810000,   0x2d7ee0, 0x75f0e7d8 },
    { (const char *)0xffae7ee0,     0xe7d0, 0xfdd7a7c5 },
};

const firmware_crc_block_t firmware_100f_crc32[]={
    { (const char *)0xff810000,   0x2d7ee0, 0x30865f90 },
    { (const char *)0xffae7ee0,     0xe7d0, 0xfdd7a7c5 },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00G", firmware_100g_crc32 },
    { "GM1.00F", firmware_100f_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff81b27d, // firmware_ver_ptr
    firmware_crc_list,
    2,  // sub_count
    2,  // block_count
};
