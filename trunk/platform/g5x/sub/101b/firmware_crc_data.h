/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_101b_crc32[]={
    { (const char *)0xfc020000,   0x657514, 0x85fa6b0c }, // ROMCODE
    { (const char *)0xfc67774c,    0x51430, 0xa8ab9a14 }, // omar_0, omar_1
    { (const char *)0xfcc91468,   0x122c58, 0x3d3bd74f }, // zico_0, zico_1, zico_2
    { (const char *)0xfceacaf4,    0x57235, 0x2298dd73 }, // RAM data, RAM code, TCM code
};

const firmware_crc_block_t firmware_101c_crc32[]={
    { (const char *)0xfc020000,   0x657514, 0xabacaede }, // ROMCODE
    { (const char *)0xfc67774c,    0x51430, 0xa8ab9a14 }, // omar_0, omar_1
    { (const char *)0xfcc91468,   0x122c58, 0x3d3bd74f }, // zico_0, zico_1, zico_2
    { (const char *)0xfceacaf4,    0x57235, 0x2298dd73 }, // RAM data, RAM code, TCM code
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.01B", firmware_101b_crc32 },
    { "GM1.01C", firmware_101c_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xfc454711, // firmware_ver_ptr
    firmware_crc_list,
    2,  // sub_count
    4,  // block_count
};
