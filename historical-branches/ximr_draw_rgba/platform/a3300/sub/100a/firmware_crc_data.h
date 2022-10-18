/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100a_crc32[]={
    { (const char *)0xff810000,   0x34c59a, 0x26323038 }, // ROMCODE
    { (const char *)0xffc35320,     0xd7cc, 0x12380338 }, // RAM data
};

const firmware_crc_block_t firmware_100c_crc32[]={
    { (const char *)0xff810000,   0x34c59a, 0x4ea576a4 }, // ROMCODE
    { (const char *)0xffc35320,     0xd7cc, 0x12380338 }, // RAM data
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00A", firmware_100a_crc32 },
    { "GM1.00C", firmware_100c_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff88c049, // firmware_ver_ptr
    firmware_crc_list,
    2,  // sub_count
    2,  // block_count
};
