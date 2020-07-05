/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100a_crc32[]={
    { (const char *)0xff000000,   0x5bac84, 0x7d75fce2 }, // ROMCODE
    { (const char *)0xff8d0134,    0x45584, 0x790c2325 }, // RAM data, RAM code
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00A", firmware_100a_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff0cb595, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
