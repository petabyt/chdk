/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_101c_crc32[]={
    { (const char *)0xff810000,   0x329582,  0x93393a8 }, // ROMCODE
    { (const char *)0xffc14e98,     0xdb70, 0x54eb3a4d }, // RAM data
};

const firmware_crc_block_t firmware_101b_crc32[]={
    { (const char *)0xff810000,   0x329582, 0xb719441e }, // ROMCODE
    { (const char *)0xffc14e98,     0xdb70, 0x54eb3a4d }, // RAM data
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.01C", firmware_101c_crc32 },
    { "GM1.01B", firmware_101b_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff88bbe1, // firmware_ver_ptr
    firmware_crc_list,
    2,  // sub_count
    2,  // block_count
};
