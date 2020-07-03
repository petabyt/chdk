/* THIS FILE IS GENERATED, DO NOT EDIT! */

const firmware_crc_block_t firmware_100d_crc32[]={
    { (const char *)0xff000000,   0x567b20, 0x71519805 },
    { (const char *)0xff719234,    0x2a5d0, 0x10d42fdb },
    { (const char *)0xff702f8c,    0x162a8,  0xca6d47f },
};

const firmware_crc_block_t firmware_100c_crc32[]={
    { (const char *)0xff000000,   0x567b20, 0x173aa9db },
    { (const char *)0xff719234,    0x2a5d0, 0x10d42fdb },
    { (const char *)0xff702f8c,    0x162a8,  0xca6d47f },
};

const firmware_crc_block_t firmware_100a_crc32[]={
    { (const char *)0xff000000,   0x567b20, 0x4ec04ad6 },
    { (const char *)0xff719234,    0x2a5d0, 0x10d42fdb },
    { (const char *)0xff702f8c,    0x162a8,  0xca6d47f },
};

firmware_crc_sub_t firmware_crc_list[]={
    { "GM1.00D", firmware_100d_crc32 },
    { "GM1.00C", firmware_100c_crc32 },
    { "GM1.00A", firmware_100a_crc32 },
};

const firmware_crc_desc_t firmware_crc_desc={
    (const char *)0xff084569, // firmware_ver_ptr
    firmware_crc_list,
    3,  // sub_count
    3,  // block_count
};
