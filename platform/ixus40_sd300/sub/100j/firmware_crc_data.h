/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100j_crc32[]={
    { (const char *)0xff810000,   0x2c76d0, 0xca106dfd },
    { (const char *)0xffad76d0,     0xeb60, 0xcd7b80a9 },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "1.00J", firmware_100j_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff81e42d, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
