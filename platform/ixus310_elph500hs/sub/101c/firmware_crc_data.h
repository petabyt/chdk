/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_101c_crc32[]={
    { (const char *)0xff000000,   0x3cea36, 0xebffc9c5 }, // ROMCODE
    { (const char *)0xff50c010,     0xf758, 0x859f9393 }, // RAM data
};

const firmware_crc_block_t firmware_101b_crc32[]={
    { (const char *)0xff000000,   0x3cea36, 0x5888a7d4 }, // ROMCODE
    { (const char *)0xff50c010,     0xf758, 0x859f9393 }, // RAM data
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.01C", firmware_101c_crc32 },
    { "GM1.01B", firmware_101b_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff086de5, // firmware_ver_ptr
    firmware_crc_list,
    2,  // sub_count
    2,  // block_count
};
