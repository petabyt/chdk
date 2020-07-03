/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100j_crc32[]={
    { (const char *)0xff810000,   0x3a1b50, 0x46d8b0fe },
    { (const char *)0xffbb1b50,     0xd610, 0x566c2ccf },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00J", firmware_100j_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff81a745, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
