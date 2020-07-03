/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100f_crc32[]={
    { (const char *)0xff810000,   0x31f154, 0xf443f1f5 },
    { (const char *)0xffc241c0,     0xf654, 0x25ce016b },
    { (const char *)0xffc180a8,     0xc118, 0x43108708 },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00F", firmware_100f_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff881335, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    3,  // block_count
};
