/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100c_crc32[]={
    { (const char *)0xfc020000,   0x6574d8, 0x8de5b7a5 }, // ROMCODE
    { (const char *)0xfc677710,    0x51430, 0xa8ab9a14 }, // omar_0, omar_1
    { (const char *)0xfcc91428,   0x122c58, 0x3d3bd74f }, // zico_0, zico_1, zico_2
    { (const char *)0xfceacab4,    0x57235, 0x92f7f55e }, // RAM data, RAM code, TCM code
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00C", firmware_100c_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xfc4546d5, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    4,  // block_count
};
