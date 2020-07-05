/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_102a_crc32[]={
    { (const char *)0xff810000,   0x384a20, 0xd328a717 }, // ROMCODE, RAM data
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.02A", firmware_102a_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff818035, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    1,  // block_count
};
