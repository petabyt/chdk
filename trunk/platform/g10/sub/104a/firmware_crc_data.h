/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_104a_crc32[]={
    { (const char *)0xff810000,   0x2f968a, 0x99dba80d },
    { (const char *)0xffba0a1c,     0xef34, 0x310aacac },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.04A", firmware_104a_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff8768c9, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
