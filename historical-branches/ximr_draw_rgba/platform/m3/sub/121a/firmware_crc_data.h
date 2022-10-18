/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_121a_crc32[]={
    { (const char *)0xfc020000,   0x5c2e94, 0x2941f77a }, // ROMCODE
    { (const char *)0xfc5e30bc,    0x14e94, 0x8e67dbbb }, // omar_0, omar_1
    { (const char *)0xfca003b8,   0x1124b8, 0x3a80b89a }, // zico_0, zico_1, zico_2
    { (const char *)0xfcc50130,    0x757ad, 0x6eb3d8c6 }, // RAM data, RAM code, TCM code
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.21A", firmware_121a_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xfc1fcf1d, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    4,  // block_count
};
