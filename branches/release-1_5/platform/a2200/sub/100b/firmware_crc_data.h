/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100b_crc32[]={
    { (const char *)0xff810000,   0x344b4a, 0xa7c0110e }, // ROMCODE
    { (const char *)0xffc29e94,     0xd3b4, 0x3a089ddd }, // RAM data
};

const firmware_crc_block_t firmware_100c_crc32[]={
    { (const char *)0xff810000,   0x344b4a, 0xb3c416e2 }, // ROMCODE
    { (const char *)0xffc29e94,     0xd3b4, 0x3a089ddd }, // RAM data
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00B", firmware_100b_crc32 },
    { "GM1.00C", firmware_100c_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff889bbd, // firmware_ver_ptr
    firmware_crc_list,
    2,  // sub_count
    2,  // block_count
};
