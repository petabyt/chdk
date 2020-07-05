/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100e_crc32[]={
    { (const char *)0xff000000,   0x4524be, 0xc5d9c5d3 }, // ROMCODE
    { (const char *)0xff64be64,    0x12fa8, 0x5ae739ee }, // RAM data
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00E", firmware_100e_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff0908b9, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
