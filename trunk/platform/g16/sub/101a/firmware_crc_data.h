/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_101a_crc32[]={
    { (const char *)0xfc020000,   0x4fea50, 0x7a1cda25 }, // ROMCODE
    { (const char *)0xfc51ec78,    0x522d0, 0x4f7d5014 }, // omar_0, omar_1
    { (const char *)0xfc9c5b7c,   0x107c98, 0xd9b24f6c }, // zico_0, zico_1, zico_2
    { (const char *)0xfcbc2280,    0x47d80, 0xd36b20e5 }, // RAM data, RAM code
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.01A", firmware_101a_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xfc158a45, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    4,  // block_count
};
