/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100b_crc32[]={
    { (const char *)0xfc020000,   0x59d2e0, 0xcc64e1dd }, // ROMCODE
    { (const char *)0xfc5bd508,    0x50cec, 0xd1c92372 }, // omar_0, omar_1
    { (const char *)0xfcb212d4,   0x112398, 0xa563c933 }, // zico_0, zico_1, zico_2
    { (const char *)0xfcd39d68,    0x59ed4, 0x9f65e3cd }, // RAM data, RAM code
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00B", firmware_100b_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xfc159205, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    4,  // block_count
};
