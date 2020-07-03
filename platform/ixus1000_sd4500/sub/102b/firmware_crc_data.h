/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_102b_crc32[]={
    { (const char *)0xff810000,   0x37be66,  0x2b5f510 },
    { (const char *)0xffc56de0,     0xee28, 0xd5c2e7bc },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.02B", firmware_102b_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff894e61, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
