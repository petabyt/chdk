/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100a_crc32[]={
    { (const char *)0xff810000,   0x3ad7a0, 0x79a556a2 }, // ROMCODE
    { (const char *)0xffce7fc8,    0x1b9c4, 0xc39f2700 }, // RAM data, RAM code
};

const firmware_crc_block_t firmware_100b_crc32[]={
    { (const char *)0xff810000,   0x3ad7a0, 0x52f39ff6 }, // ROMCODE
    { (const char *)0xffce7fc8,    0x1b9c4, 0xc39f2700 }, // RAM data, RAM code
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00A", firmware_100a_crc32 },
    { "GM1.00B", firmware_100b_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff89b601, // firmware_ver_ptr
    firmware_crc_list,
    2,  // sub_count
    2,  // block_count
};
