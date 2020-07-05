/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100c_crc32[]={
    { (const char *)0xff810000,   0x3a7b42, 0x44e051fd }, // ROMCODE
    { (const char *)0xffcb1c20,     0xee98, 0xc3134e2f }, // RAM data
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00C", firmware_100c_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff894561, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
