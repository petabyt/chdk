/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_101a_crc32[]={
    { (const char *)0xfc020000,   0x6574f0, 0x79fbb338 },
    { (const char *)0xfcee2140,    0x1ad18, 0x60918a86 },
    { (const char *)0xfcefce58,     0x6ea9, 0x42d4b749 },
    { (const char *)0xfceacacc,    0x35674, 0xe0f28887 },
    { (const char *)0xfcc91440,     0x7a30, 0xb8d36826 },
    { (const char *)0xfcc98e78,     0x4ad0, 0xb96a91e0 },
    { (const char *)0xfcc9d950,   0x116748, 0x728940d2 },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.01A", firmware_101a_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xfc4546ed, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    7,  // block_count
};
