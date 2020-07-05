/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100a_crc32[]={
    { (const char *)0xff810000,   0x393d5c, 0x8c64df6d }, // ROMCODE
    { (const char *)0xffccaaec,    0x1d5c8,  0x6cad803 }, // RAM data, RAM code
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00A", firmware_100a_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff8941d5, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
