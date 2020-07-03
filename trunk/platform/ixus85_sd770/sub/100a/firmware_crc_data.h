/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100a_crc32[]={
    { (const char *)0xff810000,   0x29a7ae, 0x5c76b089 },
    { (const char *)0xffb15aa4,     0xd6e4, 0xc6560f3d },
};

const firmware_crc_block_t firmware_100b_crc32[]={
    { (const char *)0xff810000,   0x29a7ae, 0xcd6c12b5 },
    { (const char *)0xffb15aa4,     0xd6e4, 0xc6560f3d },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00A", firmware_100a_crc32 },
    { "GM1.00B", firmware_100b_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff86befd, // firmware_ver_ptr
    firmware_crc_list,
    2,  // sub_count
    2,  // block_count
};
