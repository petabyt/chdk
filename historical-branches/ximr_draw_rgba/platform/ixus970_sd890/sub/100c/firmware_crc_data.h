/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100c_crc32[]={
    { (const char *)0xff810000,   0x2a11d2, 0x3c749e38 }, // ROMCODE
    { (const char *)0xffb1e480,     0xd864, 0x41e1380b }, // RAM data
};

const firmware_crc_block_t firmware_100d_crc32[]={
    { (const char *)0xff810000,   0x2a11d2, 0x6b166d1e }, // ROMCODE
    { (const char *)0xffb1e480,     0xd864, 0x41e1380b }, // RAM data
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00C", firmware_100c_crc32 },
    { "GM1.00D", firmware_100d_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff86c129, // firmware_ver_ptr
    firmware_crc_list,
    2,  // sub_count
    2,  // block_count
};
