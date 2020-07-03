/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_102a_crc32[]={
    { (const char *)0xff810000,   0x2f964a, 0xc123aea8 },
    { (const char *)0xffba09dc,     0xef34, 0x99d01504 },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.02A", firmware_102a_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff8768c9, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
