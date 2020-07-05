/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100d_crc32[]={
    { (const char *)0xff810000,   0x34e23a, 0x2a9840d9 }, // ROMCODE
    { (const char *)0xffc206d4,     0xd944, 0x99a0adf5 }, // RAM data
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00D", firmware_100d_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff88e6c9, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
