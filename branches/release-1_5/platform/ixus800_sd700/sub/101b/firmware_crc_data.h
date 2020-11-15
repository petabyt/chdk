/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_101b_crc32[]={
    { (const char *)0xff810000,   0x31edf0, 0x65218e34 }, // ROMCODE, RAM data
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.01B", firmware_101b_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff81a5d5, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    1,  // block_count
};
