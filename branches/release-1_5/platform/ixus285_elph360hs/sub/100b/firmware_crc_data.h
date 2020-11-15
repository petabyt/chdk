/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100b_crc32[]={
    { (const char *)0xff010000,   0x681584, 0x59ad5438 }, // ROMCODE
    { (const char *)0xff8f42e0,    0x4a8c8, 0x9c453fde }, // RAM data, RAM code
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00B", firmware_100b_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff0aac81, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
