/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100b_crc32[]={
    { (const char *)0xff810000,   0x2ff440, 0x46d10ef8 }, // ROMCODE
    { (const char *)0xffbf5b08,    0x1ac74, 0xc9b1f873 }, // RAM data, RAM code
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00B", firmware_100b_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff87d84d, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
