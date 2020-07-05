/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_102d_crc32[]={
    { (const char *)0xff810000,   0x37be6e, 0x142d8a5d }, // ROMCODE
    { (const char *)0xffc56de8,     0xee28, 0xa8b0727c }, // RAM data
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.02D", firmware_102d_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff894e61, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
