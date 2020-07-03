/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100f_crc32[]={
    { (const char *)0xffc00000,   0x28a3c0, 0xec63d77a },
    { (const char *)0xffe8a3c0,     0xf710, 0xadce3bea },
};

const firmware_crc_block_t firmware_100e_crc32[]={
    { (const char *)0xffc00000,   0x28a3c0, 0xb2916d06 },
    { (const char *)0xffe8a3c0,     0xf710, 0xadce3bea },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00F", firmware_100f_crc32 },
    { "GM1.00E", firmware_100e_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xffc0ad35, // firmware_ver_ptr
    firmware_crc_list,
    2,  // sub_count
    2,  // block_count
};
