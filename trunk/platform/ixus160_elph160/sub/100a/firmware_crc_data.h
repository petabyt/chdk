/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100a_crc32[]={
    { (const char *)0xff810000,   0x3ad7a0, 0x79a556a2 },
    { (const char *)0xffcf60b4,     0xd8d8, 0x83ff6211 },
    { (const char *)0xffce7fc8,     0xe0ec, 0xb5b1fb1b },
};

const firmware_crc_block_t firmware_100b_crc32[]={
    { (const char *)0xff810000,   0x3ad7a0, 0x52f39ff6 },
    { (const char *)0xffcf60b4,     0xd8d8, 0x83ff6211 },
    { (const char *)0xffce7fc8,     0xe0ec, 0xb5b1fb1b },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00A", firmware_100a_crc32 },
    { "GM1.00B", firmware_100b_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff89b601, // firmware_ver_ptr
    firmware_crc_list,
    2,  // sub_count
    3,  // block_count
};
