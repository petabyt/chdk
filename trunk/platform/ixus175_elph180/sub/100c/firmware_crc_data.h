/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100c_crc32[]={
    { (const char *)0xff810000,   0x3d0e34, 0xca1069b3 }, // ROMCODE
    { (const char *)0xffd1d850,    0x1e200, 0xa28ec33a }, // RAM data, RAM code
};

const firmware_crc_block_t firmware_100b_crc32[]={
    { (const char *)0xff810000,   0x3d0e34, 0x565653ae }, // ROMCODE
    { (const char *)0xffd1d850,    0x1e200, 0xa28ec33a }, // RAM data, RAM code
};

const firmware_crc_block_t firmware_100a_crc32[]={
    { (const char *)0xff810000,   0x3d0e34, 0x85e276f6 }, // ROMCODE
    { (const char *)0xffd1d850,    0x1e200, 0xa28ec33a }, // RAM data, RAM code
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00C", firmware_100c_crc32 },
    { "GM1.00B", firmware_100b_crc32 },
    { "GM1.00A", firmware_100a_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff89dbb9, // firmware_ver_ptr
    firmware_crc_list,
    3,  // sub_count
    2,  // block_count
};
