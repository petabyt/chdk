/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_101b_crc32[]={
    { (const char *)0xff810000,   0x3204a8, 0xf747fc9c },
    { (const char *)0xffc255d8,     0xf654,  0xe4bad3e },
    { (const char *)0xffc194a0,     0xc138, 0x959f08dc },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.01B", firmware_101b_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff881335, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    3,  // block_count
};
