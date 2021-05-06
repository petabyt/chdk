/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_101a_crc32[]={
    { (const char *)0xfc020000,   0x6574f0, 0x79fbb338 }, // ROMCODE
    { (const char *)0xfc677728,    0x51430, 0xa8ab9a14 }, // omar_0, omar_1
    { (const char *)0xfcc91440,   0x122c58, 0x3d3bd74f }, // zico_0, zico_1, zico_2
    { (const char *)0xfceacacc,    0x57235,  0xc36205f }, // RAM data, RAM code, TCM code
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.01A", firmware_101a_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xfc4546ed, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    4,  // block_count
};
