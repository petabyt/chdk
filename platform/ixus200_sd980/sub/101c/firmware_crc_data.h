/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_101c_crc32[]={
    { (const char *)0xff810000,   0x32eb3e, 0xa77e9c6b },
    { (const char *)0xffc0282c,    0x1eff0, 0x18583e8a },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.01C", firmware_101c_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff887c49, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
