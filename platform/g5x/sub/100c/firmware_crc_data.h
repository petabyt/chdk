/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100c_crc32[]={
    { (const char *)0xfc020000,   0x6574d8, 0x8de5b7a5 },
    { (const char *)0xfcee2128,    0x1ad18, 0x58d78cc8 },
    { (const char *)0xfcefce40,     0x6ea9, 0x4b3f494e },
    { (const char *)0xfceacab4,    0x35674, 0x2a0bb9e6 },
    { (const char *)0xfcc91428,     0x7a30, 0xb8d36826 },
    { (const char *)0xfcc98e60,     0x4ad0, 0xb96a91e0 },
    { (const char *)0xfcc9d938,   0x116748, 0x728940d2 },
    { (const char *)0xfc677710,      0xe90, 0x47ca7dd9 },
    { (const char *)0xfc6785a0,    0x505a0, 0xb3e2b82a },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00C", firmware_100c_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xfc4546d5, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    9,  // block_count
};
