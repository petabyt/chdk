/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100j_crc32[]={
    { (const char *)0xff810000,   0x2d6230, 0x8a1253e5 }, // ROMCODE, RAM data
};

firmware_crc_sub_t firmware_crc_list[]={
    { "1.00J", firmware_100j_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff81e42d, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    1,  // block_count
};
