/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100f_crc32[]={
    { (const char *)0xff000000,   0x5b5a08, 0x9ee2dc92 }, // ROMCODE
    { (const char *)0xff880068,    0x431d8,  0x7a57388 }, // RAM data, RAM code
};

const firmware_crc_block_t firmware_100h_crc32[]={
    { (const char *)0xff000000,   0x5b5a08,   0x7fe256 }, // ROMCODE
    { (const char *)0xff880068,    0x431d8,  0x7a57388 }, // RAM data, RAM code
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00F", firmware_100f_crc32 },
    { "GM1.00H", firmware_100h_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff0c9b41, // firmware_ver_ptr
    firmware_crc_list,
    2,  // sub_count
    2,  // block_count
};
