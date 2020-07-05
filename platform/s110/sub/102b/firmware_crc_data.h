/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_102b_crc32[]={
    { (const char *)0xf8000000,   0x648b60, 0xffd218cb }, // ROMCODE
    { (const char *)0xf8953558,    0x48d10, 0x298bd824 }, // RAM data, RAM code
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.02B", firmware_102b_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xf80d5d19, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
