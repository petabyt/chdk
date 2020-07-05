/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100h_crc32[]={
    { (const char *)0xfc020000,   0x55bea8, 0x48b8905b }, // ROMCODE
    { (const char *)0xfc57c0d0,    0x4fc8c, 0x8b847cf2 }, // omar_0, omar_1
    { (const char *)0xfcad2af0,   0x112388, 0x568e698c }, // zico_0, zico_1, zico_2
    { (const char *)0xfccec5a8,    0x570b0, 0x91e51fd1 }, // RAM data, RAM code
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00H", firmware_100h_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xfc15c1f9, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    4,  // block_count
};
