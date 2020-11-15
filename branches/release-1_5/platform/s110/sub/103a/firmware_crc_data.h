/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_103a_crc32[]={
    { (const char *)0xf8000000,   0x648b44, 0x2b77f1cc }, // ROMCODE
    { (const char *)0xf8953540,    0x48d10, 0xca22c1b4 }, // RAM data, RAM code
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.03A", firmware_103a_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xf80d5cfd, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
