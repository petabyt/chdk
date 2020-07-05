/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100d_crc32[]={
    { (const char *)0xfc020000,   0x5c2528, 0xdbd7ffad }, // ROMCODE
    { (const char *)0xfc5e2598,    0x5163c, 0xb265a705 }, // omar_0, omar_1
    { (const char *)0xfcb95204,   0x122cb8, 0xd439f906 }, // zico_0, zico_1, zico_2
    { (const char *)0xfcda103c,    0x4d589, 0xb17d824a }, // RAM data, RAM code, TCM code
};

const firmware_crc_block_t firmware_100e_crc32[]={
    { (const char *)0xfc020000,   0x5c2528, 0x1e79cc57 }, // ROMCODE
    { (const char *)0xfc5e2598,    0x5163c, 0xb265a705 }, // omar_0, omar_1
    { (const char *)0xfcb95204,   0x122cb8, 0xd439f906 }, // zico_0, zico_1, zico_2
    { (const char *)0xfcda103c,    0x4d589, 0xb17d824a }, // RAM data, RAM code, TCM code
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00D", firmware_100d_crc32 },
    { "GM1.00E", firmware_100e_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xfc3b38d5, // firmware_ver_ptr
    firmware_crc_list,
    2,  // sub_count
    4,  // block_count
};
