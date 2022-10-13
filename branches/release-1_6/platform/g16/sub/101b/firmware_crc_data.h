/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_101b_crc32[]={
    { (const char *)0xfc020000,   0x4feaa0, 0x84e375fb }, // ROMCODE
    { (const char *)0xfc51ecc8,    0x522d0, 0x4f7d5014 }, // omar_0, omar_1
    { (const char *)0xfc9c5bcc,   0x107c98, 0xd9b24f6c }, // zico_0, zico_1, zico_2
    { (const char *)0xfcbc22d0,    0x47d88, 0xeb93ff5a }, // RAM data, RAM code
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.01B", firmware_101b_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xfc158a7d, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    4,  // block_count
};
