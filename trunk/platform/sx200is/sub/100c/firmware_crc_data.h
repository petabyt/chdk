/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100c_crc32[]={
    { (const char *)0xff810000,   0x2ed12a, 0xc0449559 },
    { (const char *)0xffb91b18,     0xc2cc, 0xedf9fc5d },
};

const firmware_crc_block_t firmware_100d_crc32[]={
    { (const char *)0xff810000,   0x2ed12a, 0xeecadbe9 },
    { (const char *)0xffb91b18,     0xc2cc, 0xedf9fc5d },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00C", firmware_100c_crc32 },
    { "GM1.00D", firmware_100d_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff8733e1, // firmware_ver_ptr
    firmware_crc_list,
    2,  // sub_count
    2,  // block_count
};
