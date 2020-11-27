/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_101c_crc32[]={
    { (const char *)0xff810000,   0x390112, 0x82d40b72 }, // ROMCODE
    { (const char *)0xffc8ab50,     0xeb9c, 0x603110a7 }, // RAM data
};

const firmware_crc_block_t firmware_101d_crc32[]={
    { (const char *)0xff810000,   0x390112, 0xea387165 }, // ROMCODE
    { (const char *)0xffc8ab50,     0xeb9c, 0x603110a7 }, // RAM data
};

const firmware_crc_block_t firmware_101e_crc32[]={
    { (const char *)0xff810000,   0x390112, 0x1726021c }, // ROMCODE
    { (const char *)0xffc8ab50,     0xeb9c, 0x603110a7 }, // RAM data
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.01C", firmware_101c_crc32 },
    { "GM1.01D", firmware_101d_crc32 },
    { "GM1.01E", firmware_101e_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff894efd, // firmware_ver_ptr
    firmware_crc_list,
    3,  // sub_count
    2,  // block_count
};
