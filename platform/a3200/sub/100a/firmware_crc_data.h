/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100a_crc32[]={
    { (const char *)0xff810000,   0x34be42, 0xa69ebb16 }, // ROMCODE
    { (const char *)0xffc33798,     0xd7ac,  0xd787a5e }, // RAM data
};

const firmware_crc_block_t firmware_100c_crc32[]={
    { (const char *)0xff810000,   0x34be42, 0x28016307 }, // ROMCODE
    { (const char *)0xffc33798,     0xd7ac,  0xd787a5e }, // RAM data
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00A", firmware_100a_crc32 },
    { "GM1.00C", firmware_100c_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff88bf95, // firmware_ver_ptr
    firmware_crc_list,
    2,  // sub_count
    2,  // block_count
};
