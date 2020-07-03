/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100c_crc32[]={
    { (const char *)0xff000000,   0x440480, 0x42eb0382 },
    { (const char *)0xff680a14,    0x1044c, 0x703175a5 },
    { (const char *)0xff66db9c,    0x12e78, 0xac4acb9d },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00C", firmware_100c_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff07f44d, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    3,  // block_count
};
