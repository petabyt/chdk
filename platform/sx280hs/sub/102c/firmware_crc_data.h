/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_102c_crc32[]={
    { (const char *)0xfc020000,   0x461074, 0xd0ebd8f5 },
    { (const char *)0xfc953974,    0x1f3c4, 0x891857e5 },
    { (const char *)0xfc932514,    0x21460, 0x79d64874 },
    { (const char *)0xfc764824,     0x57c8, 0x210966a9 },
    { (const char *)0xfc76a000,    0xfd2e8, 0x5e313959 },
};

const firmware_crc_block_t firmware_102d_crc32[]={
    { (const char *)0xfc020000,   0x461074, 0xe08109a1 },
    { (const char *)0xfc953974,    0x1f3c4, 0x891857e5 },
    { (const char *)0xfc932514,    0x21460, 0x79d64874 },
    { (const char *)0xfc764824,     0x57c8, 0x210966a9 },
    { (const char *)0xfc76a000,    0xfd2e8, 0x5e313959 },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.02C", firmware_102c_crc32 },
    { "GM1.02D", firmware_102d_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xfc142895, // firmware_ver_ptr
    firmware_crc_list,
    2,  // sub_count
    5,  // block_count
};
