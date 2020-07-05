/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_101b_crc32[]={
    { (const char *)0xfc020000,   0x657514, 0x85fa6b0c },
    { (const char *)0xfcee2168,    0x1ad18, 0xd943729b },
    { (const char *)0xfcefce80,     0x6ea9, 0x891a4295 },
    { (const char *)0xfceacaf4,    0x35674, 0x804bc145 },
    { (const char *)0xfcc91468,     0x7a30, 0xb8d36826 },
    { (const char *)0xfcc98ea0,     0x4ad0, 0xb96a91e0 },
    { (const char *)0xfcc9d978,   0x116748, 0x728940d2 },
    { (const char *)0xfc67774c,      0xe90, 0x47ca7dd9 },
    { (const char *)0xfc6785dc,    0x505a0, 0xb3e2b82a },
};

const firmware_crc_block_t firmware_101c_crc32[]={
    { (const char *)0xfc020000,   0x657514, 0xabacaede },
    { (const char *)0xfcee2168,    0x1ad18, 0xd943729b },
    { (const char *)0xfcefce80,     0x6ea9, 0x891a4295 },
    { (const char *)0xfceacaf4,    0x35674, 0x804bc145 },
    { (const char *)0xfcc91468,     0x7a30, 0xb8d36826 },
    { (const char *)0xfcc98ea0,     0x4ad0, 0xb96a91e0 },
    { (const char *)0xfcc9d978,   0x116748, 0x728940d2 },
    { (const char *)0xfc67774c,      0xe90, 0x47ca7dd9 },
    { (const char *)0xfc6785dc,    0x505a0, 0xb3e2b82a },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.01B", firmware_101b_crc32 },
    { "GM1.01C", firmware_101c_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xfc454711, // firmware_ver_ptr
    firmware_crc_list,
    2,  // sub_count
    9,  // block_count
};
