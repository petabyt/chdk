/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_101d_crc32[]={
    { (const char *)0xfc020000,   0x65753c, 0x604f6356 }, // ROMCODE
    { (const char *)0xfc677774,    0x51430, 0xa8ab9a14 }, // omar_0, omar_1
    { (const char *)0xfcc91490,   0x122c58, 0x3d3bd74f }, // zico_0, zico_1, zico_2
    { (const char *)0xfceacb1c,    0x57235, 0x8816c760 }, // RAM data, RAM code, TCM code
};

const firmware_crc_block_t firmware_101e_crc32[]={
    { (const char *)0xfc020000,   0x65753c, 0x5c58725a }, // ROMCODE
    { (const char *)0xfc677774,    0x51430, 0xa8ab9a14 }, // omar_0, omar_1
    { (const char *)0xfcc91490,   0x122c58, 0x3d3bd74f }, // zico_0, zico_1, zico_2
    { (const char *)0xfceacb1c,    0x57235, 0x8816c760 }, // RAM data, RAM code, TCM code
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.01D", firmware_101d_crc32 },
    { "GM1.01E", firmware_101e_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xfc454739, // firmware_ver_ptr
    firmware_crc_list,
    2,  // sub_count
    4,  // block_count
};
