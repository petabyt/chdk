/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_102c_crc32[]={
    { (const char *)0xff810000,   0x2fb232, 0x539ae0e1 }, // ROMCODE
    { (const char *)0xffbbeb08,     0xc604, 0x3391e6b9 }, // RAM data
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.02C", firmware_102c_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff883a61, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
