/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100c_crc32[]={
    { (const char *)0xfc020000,   0x59d2c8, 0x999f61f1 }, // ROMCODE
    { (const char *)0xfc5bd4f0,    0x50cec, 0xd1c92372 }, // omar_0, omar_1
    { (const char *)0xfcb212bc,   0x112398, 0xa563c933 }, // zico_0, zico_1, zico_2
    { (const char *)0xfcd39d50,    0x59ed4, 0x290a310e }, // RAM data, RAM code
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00C", firmware_100c_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xfc159205, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    4,  // block_count
};
