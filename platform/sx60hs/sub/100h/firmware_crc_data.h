/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100h_crc32[]={
    { (const char *)0xfc020000,   0x55bea8, 0x48b8905b },
    { (const char *)0xfcd16bb4,    0x2caa4, 0xeafffc36 },
    { (const char *)0xfccec5a8,    0x2a60c, 0x4a0c12ab },
    { (const char *)0xfcad2af0,     0x77b8, 0x55e7705a },
    { (const char *)0xfcada2b0,     0x4ad0, 0x3f57c6f7 },
    { (const char *)0xfcaded88,   0x1060f0, 0xc7f13513 },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00H", firmware_100h_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xfc15c1f9, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    6,  // block_count
};
