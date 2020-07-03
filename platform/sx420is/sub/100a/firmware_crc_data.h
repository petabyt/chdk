/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100a_crc32[]={
    { (const char *)0xff010000,   0x5d29e8, 0x89baa4cf },
    { (const char *)0xff7bad88,    0x31d88, 0xbef37f3a },
    { (const char *)0xff7a757c,    0x1380c, 0xb6da303d },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00A", firmware_100a_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff0a80cd, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    3,  // block_count
};
