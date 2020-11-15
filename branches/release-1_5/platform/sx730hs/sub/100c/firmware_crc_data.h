/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100c_crc32[]={
    { (const char *)0xfc020000,   0x5c2500, 0x75f518b8 }, // ROMCODE
    { (const char *)0xfc5e2570,    0x5163c, 0xb265a705 }, // omar_0, omar_1
    { (const char *)0xfcb951dc,   0x122cb8, 0xd439f906 }, // zico_0, zico_1, zico_2
    { (const char *)0xfcda103c,    0x4d589, 0xb9052bc5 }, // RAM data, RAM code, TCM code
};

const firmware_crc_block_t firmware_100b_crc32[]={
    { (const char *)0xfc020000,   0x5c2500, 0x8b873b97 }, // ROMCODE
    { (const char *)0xfc5e2570,    0x5163c, 0xb265a705 }, // omar_0, omar_1
    { (const char *)0xfcb951dc,   0x122cb8, 0xd439f906 }, // zico_0, zico_1, zico_2
    { (const char *)0xfcda103c,    0x4d589, 0xb9052bc5 }, // RAM data, RAM code, TCM code
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00C", firmware_100c_crc32 },
    { "GM1.00B", firmware_100b_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xfc3b38ad, // firmware_ver_ptr
    firmware_crc_list,
    2,  // sub_count
    4,  // block_count
};
