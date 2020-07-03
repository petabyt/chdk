/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_101b_crc32[]={
    { (const char *)0xff810000,   0x2ffce0, 0x534cee96 },
    { (const char *)0xffc06164,     0xf5d4, 0x15770a8b },
    { (const char *)0xffbfa7c8,     0xb99c, 0xeed35642 },
};

const firmware_crc_block_t firmware_102a_crc32[]={
    { (const char *)0xff810000,   0x2ffce0, 0x8465629b },
    { (const char *)0xffc06164,     0xf5d4, 0x15770a8b },
    { (const char *)0xffbfa7c8,     0xb99c, 0xeed35642 },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.01B", firmware_101b_crc32 },
    { "GM1.02A", firmware_102a_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff87fb5d, // firmware_ver_ptr
    firmware_crc_list,
    2,  // sub_count
    3,  // block_count
};
