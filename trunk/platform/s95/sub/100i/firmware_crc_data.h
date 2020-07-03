/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100i_crc32[]={
    { (const char *)0xff810000,   0x393b3e, 0x65951745 },
    { (const char *)0xffc9a22c,     0xf6e4, 0x17af1913 },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00I", firmware_100i_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff89548d, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
