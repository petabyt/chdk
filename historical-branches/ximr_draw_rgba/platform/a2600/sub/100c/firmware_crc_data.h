/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100c_crc32[]={
    { (const char *)0xff810000,   0x338494, 0xc2c02ade }, // ROMCODE
    { (const char *)0xffc4a1b0,    0x1c764, 0xeb99e4af }, // RAM data, RAM code
};

const firmware_crc_block_t firmware_100d_crc32[]={
    { (const char *)0xff810000,   0x338494, 0xb8b53cb4 }, // ROMCODE
    { (const char *)0xffc4a1b0,    0x1c764, 0xeb99e4af }, // RAM data, RAM code
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00C", firmware_100c_crc32 },
    { "GM1.00D", firmware_100d_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff88ebed, // firmware_ver_ptr
    firmware_crc_list,
    2,  // sub_count
    2,  // block_count
};
