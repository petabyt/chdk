/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_102e_crc32[]={
    { (const char *)0xff810000,   0x37bf3a,  0x20c114e }, // ROMCODE
    { (const char *)0xffc56ec8,     0xee30, 0xe914490a }, // RAM data
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.02E", firmware_102e_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff894ed5, // firmware_ver_ptr
    firmware_crc_list,
    1,  // sub_count
    2,  // block_count
};
