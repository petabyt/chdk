/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100c_crc32[]={
    { (const char *)0xff010000,   0x5e4eb0, 0xb889b00e }, // ROMCODE
    { (const char *)0xff838654,    0x435ec, 0x3cb3baab }, // RAM data, RAM code
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00C", firmware_100c_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff0a4c59, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
