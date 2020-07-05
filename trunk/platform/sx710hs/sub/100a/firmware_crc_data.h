/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100a_crc32[]={
    { (const char *)0xfc020000,   0x54bcc0, 0x72383138 },
    { (const char *)0xfcd4740c,    0x26bd0, 0x47cce707 },
    { (const char *)0xfcd6dfdc,     0x6c19, 0xc641ee31 },
    { (const char *)0xfcd1e5b4,    0x28e58, 0x834bcbab },
    { (const char *)0xfcb2a300,     0x7800, 0x1fb6677c },
    { (const char *)0xfcb31b08,     0x4b20, 0x27dd60a8 },
    { (const char *)0xfcb36630,   0x10d2d0, 0x987d27ea },
    { (const char *)0xfc56bee8,      0xed0, 0x182c0800 },
    { (const char *)0xfc56cdb8,    0x4f1c4, 0xd7cf6f42 },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00A", firmware_100a_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xfc4a348d, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    9,  // block_count
};
