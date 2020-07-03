/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100k_crc32[]={
    { (const char *)0xff810000,   0x2c7700, 0x77389f21 },
    { (const char *)0xffad7700,     0xeb60, 0xe312461e },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "1.00K", firmware_100k_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff81e42d, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
