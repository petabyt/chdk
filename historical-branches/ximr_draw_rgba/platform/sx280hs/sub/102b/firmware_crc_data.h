/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_102b_crc32[]={
    { (const char *)0xfc020000,   0x460fe0, 0x1d631446 }, // ROMCODE
    { (const char *)0xfc481208,    0x522f4, 0xf7095e2d }, // omar_0, omar_1
    { (const char *)0xfc764784,   0x102ac4, 0x8f5b5b98 }, // zico_0, zico_1
    { (const char *)0xfc932474,    0x40824, 0x387657b3 }, // RAM data, RAM code
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.02B", firmware_102b_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xfc142895, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    4,  // block_count
};
