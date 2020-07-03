/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_103b_crc32[]={
    { (const char *)0xff810000,   0x2fb23e, 0xf66d40fd },
    { (const char *)0xffbbeb18,     0xc604, 0x586e04a0 },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.03B", firmware_103b_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff883a6d, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
