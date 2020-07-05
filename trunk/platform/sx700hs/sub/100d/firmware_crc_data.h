/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100d_crc32[]={
    { (const char *)0xfc020000,   0x4f4c64, 0xddf00351 }, // ROMCODE
    { (const char *)0xfc514e8c,    0x50cc4, 0x19d96165 }, // omar_0, omar_1
    { (const char *)0xfca30f2c,   0x114e38, 0xbb6f5900 }, // zico_0, zico_1, zico_2
    { (const char *)0xfcc3dfc0,    0x457e4, 0xe9ede447 }, // RAM data, RAM code
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00D", firmware_100d_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xfc136795, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    4,  // block_count
};
