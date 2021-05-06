/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_101d_crc32[]={
    { (const char *)0xff810000,   0x33dd7a, 0x569b25d2 }, // ROMCODE
    { (const char *)0xffc08418,     0xd570, 0x928b596b }, // RAM data
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.01D", firmware_101d_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff88c819, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
