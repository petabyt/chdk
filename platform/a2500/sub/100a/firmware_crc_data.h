/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100a_crc32[]={
    { (const char *)0xff810000,   0x338634, 0x44cb0938 }, // ROMCODE
    { (const char *)0xffc4a350,    0x1c764,  0x89da49d }, // RAM data, RAM code
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00A", firmware_100a_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff88ebed, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
