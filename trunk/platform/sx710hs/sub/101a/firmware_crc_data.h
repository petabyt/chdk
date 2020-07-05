/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_101a_crc32[]={
    { (const char *)0xfc020000,   0x54bcc8, 0x1b2f78ef }, // ROMCODE
    { (const char *)0xfc56bef0,    0x50094, 0xf63b1b71 }, // omar_0, omar_1
    { (const char *)0xfcb2a320,   0x119600, 0xfa2f8e20 }, // zico_0, zico_1, zico_2
    { (const char *)0xfcd1e5d4,    0x56641, 0x3c0ccf53 }, // RAM data, RAM code, TCM code
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.01A", firmware_101a_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xfc4a3495, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    4,  // block_count
};
