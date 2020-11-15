/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100e_crc32[]={
    { (const char *)0xfc020000,   0x4f4920, 0xa89e5ab8 }, // ROMCODE
    { (const char *)0xfc514b48,    0x50cc4, 0x19d96165 }, // omar_0, omar_1
    { (const char *)0xfca30bec,   0x114e38, 0xbb6f5900 }, // zico_0, zico_1, zico_2
    { (const char *)0xfcc3dc80,    0x457e4, 0x2cfcd642 }, // RAM data, RAM code
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00E", firmware_100e_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xfc1366c9, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    4,  // block_count
};
