/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_102c_crc32[]={
    { (const char *)0xfc020000,   0x461074, 0xd0ebd8f5 }, // ROMCODE
    { (const char *)0xfc48129c,    0x522f4, 0xf7095e2d }, // omar_0, omar_1
    { (const char *)0xfc764824,   0x102ac4, 0x8f5b5b98 }, // zico_0, zico_1
    { (const char *)0xfc932514,    0x40824, 0x4ff345cd }, // RAM data, RAM code
};

const firmware_crc_block_t firmware_102d_crc32[]={
    { (const char *)0xfc020000,   0x461074, 0xe08109a1 }, // ROMCODE
    { (const char *)0xfc48129c,    0x522f4, 0xf7095e2d }, // omar_0, omar_1
    { (const char *)0xfc764824,   0x102ac4, 0x8f5b5b98 }, // zico_0, zico_1
    { (const char *)0xfc932514,    0x40824, 0x4ff345cd }, // RAM data, RAM code
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.02C", firmware_102c_crc32 },
    { "GM1.02D", firmware_102d_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xfc142895, // firmware_ver_ptr
    firmware_crc_list,
    2,  // sub_count
    4,  // block_count
};
