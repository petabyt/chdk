/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_102b_crc32[]={
    { (const char *)0xff810000,   0x2f47c2, 0x60090b5c },
    { (const char *)0xffb9b3d4,     0xf158,  0x7c0e75c },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.02B", firmware_102b_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff878875, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
