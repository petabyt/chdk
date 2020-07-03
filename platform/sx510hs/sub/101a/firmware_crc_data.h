/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_101a_crc32[]={
    { (const char *)0xff000000,   0x567b4c, 0x7b0b5352 },
    { (const char *)0xff71925c,    0x2a5d0, 0x11a1f70b },
    { (const char *)0xff702fb4,    0x162a8, 0xb02469e6 },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.01A", firmware_101a_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff084569, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    3,  // block_count
};
