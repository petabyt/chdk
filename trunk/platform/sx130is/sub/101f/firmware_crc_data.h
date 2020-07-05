/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_101f_crc32[]={
    { (const char *)0xff810000,   0x33dd9e, 0x1cc546a1 }, // ROMCODE
    { (const char *)0xffc08438,     0xd570, 0x80a867a3 }, // RAM data
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.01F", firmware_101f_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff88c819, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
