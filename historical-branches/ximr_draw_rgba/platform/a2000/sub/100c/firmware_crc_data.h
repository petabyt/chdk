/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100c_crc32[]={
    { (const char *)0xffc00000,   0x275886, 0xf549d32a }, // ROMCODE
    { (const char *)0xffedac70,     0xc684, 0x4e456de4 }, // RAM data
};

const firmware_crc_block_t firmware_100b_crc32[]={
    { (const char *)0xffc00000,   0x275886, 0xedab8227 }, // ROMCODE
    { (const char *)0xffedac70,     0xc684, 0x4e456de4 }, // RAM data
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00C", firmware_100c_crc32 },
    { "GM1.00B", firmware_100b_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xffc581a9, // firmware_ver_ptr
    firmware_crc_list,
    2,  // sub_count
    2,  // block_count
};
