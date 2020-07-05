/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_102a_crc32[]={
    { (const char *)0xff000000,   0x5a9f48, 0x9cd4faf1 }, // ROMCODE
    { (const char *)0xff86fbdc,    0x45e58, 0x5b997e1e }, // RAM data, RAM code
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.02A", firmware_102a_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff0b5709, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
