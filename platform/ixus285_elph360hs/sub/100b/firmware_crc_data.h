/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100b_crc32[]={
    { (const char *)0xff010000,   0x681584, 0x59ad5438 },
    { (const char *)0xff90bc80,    0x32f28, 0xd4dc135c },
    { (const char *)0xff8f42e0,    0x179a0, 0x99c0794b },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00B", firmware_100b_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff0aac81, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    3,  // block_count
};
