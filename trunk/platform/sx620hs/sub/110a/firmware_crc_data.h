/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_110a_crc32[]={
    { (const char *)0xff010000,   0x69f868, 0xb9dc4fd7 }, // ROMCODE
    { (const char *)0xff915438,    0x4ab28, 0xb9dc17a4 }, // RAM data, RAM code
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.10A", firmware_110a_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff0ae1dd, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
