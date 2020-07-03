/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_102c_crc32[]={
    { (const char *)0xff810000,   0x37be7e, 0x3b73277c },
    { (const char *)0xffc56df8,     0xee28, 0x451e7e23 },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.02C", firmware_102c_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff894e61, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
