/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_101a_crc32[]={
    { (const char *)0xff810000,   0x2fb20e, 0x9f69b19a }, // ROMCODE
    { (const char *)0xffbbeae8,     0xc604, 0xb4a1ab74 }, // RAM data
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.01A", firmware_101a_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff883a61, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
