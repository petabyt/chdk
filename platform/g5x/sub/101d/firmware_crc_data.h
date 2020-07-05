/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_101d_crc32[]={
    { (const char *)0xfc020000,   0x65753c, 0x604f6356 },
    { (const char *)0xfcee2190,    0x1ad18, 0x73cff6d1 },
    { (const char *)0xfcefcea8,     0x6ea9, 0x97c71c43 },
    { (const char *)0xfceacb1c,    0x35674, 0x90fa8bca },
    { (const char *)0xfcc91490,     0x7a30, 0xb8d36826 },
    { (const char *)0xfcc98ec8,     0x4ad0, 0xb96a91e0 },
    { (const char *)0xfcc9d9a0,   0x116748, 0x728940d2 },
    { (const char *)0xfc677774,      0xe90, 0x47ca7dd9 },
    { (const char *)0xfc678604,    0x505a0, 0xb3e2b82a },
};

const firmware_crc_block_t firmware_101e_crc32[]={
    { (const char *)0xfc020000,   0x65753c, 0x5c58725a },
    { (const char *)0xfcee2190,    0x1ad18, 0x73cff6d1 },
    { (const char *)0xfcefcea8,     0x6ea9, 0x97c71c43 },
    { (const char *)0xfceacb1c,    0x35674, 0x90fa8bca },
    { (const char *)0xfcc91490,     0x7a30, 0xb8d36826 },
    { (const char *)0xfcc98ec8,     0x4ad0, 0xb96a91e0 },
    { (const char *)0xfcc9d9a0,   0x116748, 0x728940d2 },
    { (const char *)0xfc677774,      0xe90, 0x47ca7dd9 },
    { (const char *)0xfc678604,    0x505a0, 0xb3e2b82a },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.01D", firmware_101d_crc32 },
    { "GM1.01E", firmware_101e_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xfc454739, // firmware_ver_ptr
    firmware_crc_list,
    2,  // sub_count
    9,  // block_count
};
