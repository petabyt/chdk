/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100b_crc32[]={
    { (const char *)0xff810000,   0x34634a, 0xd803743e },
    { (const char *)0xffc2b8d4,     0xd3d8, 0x958dbd93 },
};

const firmware_crc_block_t firmware_100a_crc32[]={
    { (const char *)0xff810000,   0x34634a, 0x6ef7dd55 },
    { (const char *)0xffc2b8d4,     0xd3d8, 0x958dbd93 },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00B", firmware_100b_crc32 },
    { "GM1.00A", firmware_100a_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff889029, // firmware_ver_ptr
    firmware_crc_list,
    2,  // sub_count
    2,  // block_count
};
