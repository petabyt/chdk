/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_102b_crc32[]={
    { (const char *)0xff810000,   0x2c5f0a, 0xb45be68c }, // ROMCODE
    { (const char *)0xffb53388,     0xe2e8, 0xd16df0b8 }, // RAM data
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.02B", firmware_102b_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff8708a5, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
