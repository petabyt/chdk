/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100e_crc32[]={
    { (const char *)0xfc020000,   0x4f4920, 0xa89e5ab8 },
    { (const char *)0xfcc64c5c,    0x1e808, 0xc45dd68d },
    { (const char *)0xfcc3dc80,    0x26fdc, 0x52cc6ea0 },
    { (const char *)0xfca30bec,     0x7398, 0x4a806932 },
    { (const char *)0xfca37f8c,     0x4a70, 0xe397fcd5 },
    { (const char *)0xfca3ca04,   0x109020, 0xb76228af },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00E", firmware_100e_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xfc1366c9, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    6,  // block_count
};
