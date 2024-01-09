/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_110a_crc32[]={
    { (const char *)0xff010000,   0x5bfd48, 0x7bfaa308 }, // ROMCODE
    { (const char *)0xff77eb08,    0x40f88, 0x8cc5f9d1 }, // RAM data, RAM code
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.10A", firmware_110a_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff0ac3c9, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
