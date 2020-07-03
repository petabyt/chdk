/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100d_crc32[]={
    { (const char *)0xff810000,   0x2ffaf4,  0x45d9370 },
    { (const char *)0xffc022ac,     0xf5d4, 0x67bc7474 },
    { (const char *)0xffbf68f0,     0xb9bc, 0x75e5a2e1 },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00D", firmware_100d_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff8801ed, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    3,  // block_count
};
