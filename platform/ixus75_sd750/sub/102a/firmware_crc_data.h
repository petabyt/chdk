/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_102a_crc32[]={
    { (const char *)0xff810000,   0x385410, 0xdc7d4b42 },
    { (const char *)0xffb95410,     0xcbf0, 0xa41d4518 },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.02A", firmware_102a_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff818049, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
