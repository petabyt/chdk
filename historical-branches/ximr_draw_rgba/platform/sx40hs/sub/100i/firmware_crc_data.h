/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100i_crc32[]={
    { (const char *)0xff000000,   0x43383a, 0xf1c8771d }, // ROMCODE
    { (const char *)0xff62745c,    0x11e18, 0x5b8a5f60 }, // RAM data
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00I", firmware_100i_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff090055, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
