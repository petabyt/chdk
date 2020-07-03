/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100g_crc32[]={
    { (const char *)0xff810000,   0x3ae510, 0x8dba9737 },
    { (const char *)0xffbbe510,     0xcea0, 0xefe928c5 },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00G", firmware_100g_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff8180b9, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
