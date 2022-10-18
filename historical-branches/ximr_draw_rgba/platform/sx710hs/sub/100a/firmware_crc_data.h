/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100a_crc32[]={
    { (const char *)0xfc020000,   0x54bcc0, 0x72383138 }, // ROMCODE
    { (const char *)0xfc56bee8,    0x50094, 0xf63b1b71 }, // omar_0, omar_1
    { (const char *)0xfcb2a300,   0x119600, 0xfa2f8e20 }, // zico_0, zico_1, zico_2
    { (const char *)0xfcd1e5b4,    0x56641, 0x6a9eda61 }, // RAM data, RAM code, TCM code
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00A", firmware_100a_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xfc4a348d, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    4,  // block_count
};
