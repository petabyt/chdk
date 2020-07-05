/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_101a_crc32[]={
    { (const char *)0xfc020000,   0x5c294c, 0x70cfd930 }, // ROMCODE
    { (const char *)0xfc5e2b74,    0x14e74, 0x332470f2 }, // omar_0, omar_1
    { (const char *)0xfc9fefb0,   0x1124b8, 0x3a80b89a }, // zico_0, zico_1, zico_2
    { (const char *)0xfcc637a8,    0x7577d, 0x65520746 }, // RAM data, RAM code, TCM code
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.01A", firmware_101a_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xfc1fcea5, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    4,  // block_count
};
