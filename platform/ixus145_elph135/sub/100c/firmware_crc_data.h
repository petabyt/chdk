/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100c_crc32[]={
    { (const char *)0xff810000,   0x3965d4, 0xa8bd7447 },
    { (const char *)0xffcde91c,    0x10480, 0x8ad7f001 },
    { (const char *)0xffcd0d7c,     0xdba0, 0xd851d3cd },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00C", firmware_100c_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff897d55, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    3,  // block_count
};
