/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100c_crc32[]={
    { (const char *)0xff010000,   0x62af10, 0xe8eba2a6 }, // ROMCODE
    { (const char *)0xff8b1358,    0x49854, 0x7dae91df }, // RAM data, RAM code
};

const firmware_crc_block_t firmware_110a_crc32[]={
    { (const char *)0xff010000,   0x62af10, 0x9467859c }, // ROMCODE
    { (const char *)0xff8b1358,    0x49854, 0x7dae91df }, // RAM data, RAM code
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00C", firmware_100c_crc32 },
    { "GM1.10A", firmware_110a_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff0ae9f5, // firmware_ver_ptr
    firmware_crc_list,
    2,  // sub_count
    2,  // block_count
};
