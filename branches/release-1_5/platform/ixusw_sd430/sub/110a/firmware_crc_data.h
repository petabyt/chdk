/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_110a_crc32[]={
    { (const char *)0xff810000,   0x43a390, 0xc2f897ca }, // ROMCODE, RAM data
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.10A", firmware_110a_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff81ccc9, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    1,  // block_count
};
