/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_103c_crc32[]={
    { (const char *)0xff810000,   0x2fb3fa, 0xc200c2fe }, // ROMCODE
    { (const char *)0xffbbecd0,     0xc604, 0x2b7183a6 }, // RAM data
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.03C", firmware_103c_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff883abd, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
