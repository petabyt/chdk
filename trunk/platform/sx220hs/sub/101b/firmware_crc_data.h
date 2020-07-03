/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_101b_crc32[]={
    { (const char *)0xff000000,   0x3aff32, 0xa4d72c68 },
    { (const char *)0xff4a9bc4,    0x10220, 0xf885bf01 },
};

const firmware_crc_block_t firmware_101c_crc32[]={
    { (const char *)0xff000000,   0x3aff32, 0x4b8ba51e },
    { (const char *)0xff4a9bc4,    0x10220, 0xf885bf01 },
};

const firmware_crc_block_t firmware_101e_crc32[]={
    { (const char *)0xff000000,   0x3aff32,  0x7505de1 },
    { (const char *)0xff4a9bc4,    0x10220, 0xf885bf01 },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.01B", firmware_101b_crc32 },
    { "GM1.01C", firmware_101c_crc32 },
    { "GM1.01E", firmware_101e_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff0899e1, // firmware_ver_ptr
    firmware_crc_list,
    3,  // sub_count
    2,  // block_count
};
