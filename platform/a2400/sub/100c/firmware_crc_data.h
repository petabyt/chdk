/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100c_crc32[]={
    { (const char *)0xff810000,   0x2ffaec, 0x21e51440 },
    { (const char *)0xffc022a4,     0xf5d4, 0x67bc7474 },
    { (const char *)0xffbf68e8,     0xb9bc, 0x8ee45105 },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00C", firmware_100c_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff8801ed, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    3,  // block_count
};
