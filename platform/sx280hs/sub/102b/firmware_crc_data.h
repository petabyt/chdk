/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_102b_crc32[]={
    { (const char *)0xfc020000,   0x460fe0, 0x1d631446 },
    { (const char *)0xfc9538d4,    0x1f3c4, 0xfef03cac },
    { (const char *)0xfc932474,    0x21460, 0x914f819f },
    { (const char *)0xfc764784,     0x57c8, 0x210966a9 },
    { (const char *)0xfc769f60,    0xfd2e8, 0x5e313959 },
    { (const char *)0xfc481208,     0x1610, 0xc2a67ec7 },
    { (const char *)0xfc482818,    0x50ce4, 0xeab13701 },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.02B", firmware_102b_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xfc142895, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    7,  // block_count
};
