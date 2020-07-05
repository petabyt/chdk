/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_101b_crc32[]={
    { (const char *)0xff810000,   0x2ffce0, 0x534cee96 }, // ROMCODE
    { (const char *)0xffbfa7c8,    0x1af70, 0xa1db1a1c }, // RAM data, RAM code
};

const firmware_crc_block_t firmware_102a_crc32[]={
    { (const char *)0xff810000,   0x2ffce0, 0x8465629b }, // ROMCODE
    { (const char *)0xffbfa7c8,    0x1af70, 0xa1db1a1c }, // RAM data, RAM code
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.01B", firmware_101b_crc32 },
    { "GM1.02A", firmware_102a_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff87fb5d, // firmware_ver_ptr
    firmware_crc_list,
    2,  // sub_count
    2,  // block_count
};
