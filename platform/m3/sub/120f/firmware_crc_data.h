/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_120f_crc32[]={
    { (const char *)0xfc020000,   0x5c2e64, 0x9d58c83e }, // ROMCODE
    { (const char *)0xfc5e308c,    0x14e94, 0x8e67dbbb }, // omar_0, omar_1
    { (const char *)0xfca00388,   0x1124b8, 0x3a80b89a }, // zico_0, zico_1, zico_2
    { (const char *)0xfcc50100,    0x757ad, 0x3ee7dbb2 }, // RAM data, RAM code, TCM code
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.20F", firmware_120f_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xfc1fcf15, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    4,  // block_count
};
