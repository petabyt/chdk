/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_101a_crc32[]={
    { (const char *)0xff810000,   0x28644e,  0x307b8a6 }, // ROMCODE
    { (const char *)0xffb07fa8,     0xec6c,  0xefb0371 }, // RAM data
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.01A", firmware_101a_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff8739bd, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
