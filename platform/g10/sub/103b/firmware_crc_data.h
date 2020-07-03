/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_103b_crc32[]={
    { (const char *)0xff810000,   0x2f9676, 0xa0696075 },
    { (const char *)0xffba0a04,     0xef34, 0x71c3f371 },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.03B", firmware_103b_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff8768c9, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
