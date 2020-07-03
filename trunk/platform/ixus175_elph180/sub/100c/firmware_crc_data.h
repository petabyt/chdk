/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100c_crc32[]={
    { (const char *)0xff810000,   0x3d0e34, 0xca1069b3 },
    { (const char *)0xffd2b31c,    0x10734, 0xf368617e },
    { (const char *)0xffd1d850,     0xdacc, 0xd648824b },
};

const firmware_crc_block_t firmware_100b_crc32[]={
    { (const char *)0xff810000,   0x3d0e34, 0x565653ae },
    { (const char *)0xffd2b31c,    0x10734, 0xf368617e },
    { (const char *)0xffd1d850,     0xdacc, 0xd648824b },
};

const firmware_crc_block_t firmware_100a_crc32[]={
    { (const char *)0xff810000,   0x3d0e34, 0x85e276f6 },
    { (const char *)0xffd2b31c,    0x10734, 0xf368617e },
    { (const char *)0xffd1d850,     0xdacc, 0xd648824b },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00C", firmware_100c_crc32 },
    { "GM1.00B", firmware_100b_crc32 },
    { "GM1.00A", firmware_100a_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff89dbb9, // firmware_ver_ptr
    firmware_crc_list,
    3,  // sub_count
    3,  // block_count
};
