
static FuncSig func_sig_SleepTask_1[] = {
	{   1, 0xe1a04000, 0xfdffffff }, // mov:6:0xE1A04000
	{   2, 0xe59f0038, 0xfdffffff }, // ldr:4:0xE59F0038
	{   3, 0xe5900000, 0xfdffffff }, // ldr:4:0xE5900000
	{   4, 0xe5900000, 0xfdffffff }, // ldr:4:0xE5900000
	{   5, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{   6, 0xc59f1048, 0xfdffffff }, // ldr:4:0xC59F1048
	{   7, 0xc08f002c, 0xfdffffff }, // add:6:0xC28F002C
	{   8, 0xcb000000, 0xff000000 }, // b, bl:3:0xCBFFCA68
	{   9, 0xe1540000, 0xfdffffff }, // cmp:7:0xE3540000
	{  10, 0x1a000000, 0xff000000 }, // b, bl:3:0x1A000001
	{  11, 0xe1a00000, 0xfdffffff }, // mov:6:0xE3A00000
	{  13, 0xe1a01004, 0xfdffffff }, // mov:6:0xE1A01004
	{  14, 0xe1a0000d, 0xfdffffff }, // mov:6:0xE1A0000D
	{  15, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFFDE5
	{  16, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFA207
	{  17, 0xea000000, 0xff000000 }, // b, bl:3:0xEAFFFFF8
	{  19, 0x000001f9, 0xfdffffff }, // and:6:0x000001F9
	{  22, 0x00000000, 0xfdffffff }, // and:6:0x00000000
	{  23, 0x00001cc4, 0xfdffffff }, // and:6:0x00001CC4
	{  24, 0x00001cc8, 0xfdffffff }, // and:6:0x00001CC8
	{  25, 0x3b000000, 0xff000000 }, // b, bl:3:0x3B9ACA00
	{  26, 0x000001ca, 0xfdffffff }, // and:6:0x000001CA
	{  27, 0xe51f002c, 0xfdffffff }, // ldr:4:0xE51F002C
	{  29, 0xe5900000, 0xfdffffff }, // ldr:4:0xE5900000
	{  30, 0xe5900000, 0xfdffffff }, // ldr:4:0xE5900000
	{  31, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{ -1, -1, -1 },
	/* 26/32 */
};

static FuncSig func_sig_CreateTask_1[] = {
	{   1, 0xe1a04000, 0xfdffffff }, // mov:6:0xE1A04000
	{   2, 0xe59f0218, 0xfdffffff }, // ldr:4:0xE59F0218
	{   3, 0xe1a06001, 0xfdffffff }, // mov:6:0xE1A06001
	{   4, 0xe5900000, 0xfdffffff }, // ldr:4:0xE5900000
	{   5, 0xe59d8028, 0xfdffffff }, // ldr:4:0xE59D8028
	{   6, 0xe5900000, 0xfdffffff }, // ldr:4:0xE5900000
	{   7, 0xe1a07003, 0xfdffffff }, // mov:6:0xE1A07003
	{   8, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{   9, 0xc1a010a3, 0xfdffffff }, // mov:6:0xC3A010A3
	{  10, 0xc08f0f7f, 0xfdffffff }, // add:6:0xC28F0F7F
	{  11, 0xe1a05002, 0xfdffffff }, // mov:6:0xE1A05002
	{  12, 0xcb000000, 0xff000000 }, // b, bl:3:0xCB000128
	{  13, 0xe59f11fc, 0xfdffffff }, // ldr:4:0xE59F11FC
	{  14, 0xe1540000, 0xfdffffff }, // cmp:7:0xE3540000
	{  15, 0x05914000, 0xfdffffff }, // ldr:4:0x05914000
	{  16, 0xe0460001, 0xfdffffff }, // sub:6:0xE2460001
	{  17, 0xe1500020, 0xfdffffff }, // cmp:7:0xE3500020
	{  18, 0x2a000000, 0xff000000 }, // b, bl:3:0x2A000001
	{  19, 0xe1570000, 0xfdffffff }, // cmp:7:0xE3570000
	{  20, 0x1a000000, 0xff000000 }, // b, bl:3:0x1A000001
	{  21, 0xe1a00003, 0xfdffffff }, // mov:6:0xE3A00003
	{  23, 0xe1550000, 0xfdffffff }, // cmp:7:0xE3550000
	{  24, 0x05915004, 0xfdffffff }, // ldr:4:0x05915004
	{  25, 0xe1a02000, 0xfdffffff }, // mov:6:0xE3A02000
	{  27, 0xe1a01008, 0xfdffffff }, // mov:6:0xE1A01008
	{  28, 0xe1a00007, 0xfdffffff }, // mov:6:0xE1A00007
	{  29, 0xe1a03005, 0xfdffffff }, // mov:6:0xE1A03005
	{  30, 0xe58d6000, 0xfdffffff }, // str:4:0xE58D6000
	{  31, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFD7C9
	{ -1, -1, -1 },
	/* 29/32 */
};

static FuncSig func_sig_ExitTask_1[] = {
	{   0, 0xe51f0070, 0xfdffffff }, // ldr:4:0xE51F0070
	{   2, 0xe5900000, 0xfdffffff }, // ldr:4:0xE5900000
	{   3, 0xe5900000, 0xfdffffff }, // ldr:4:0xE5900000
	{   4, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{   5, 0xc59f1028, 0xfdffffff }, // ldr:4:0xC59F1028
	{   6, 0xc04f0084, 0xfdffffff }, // sub:6:0xC24F0084
	{   7, 0xcb000000, 0xff000000 }, // b, bl:3:0xCB000089
	{   8, 0xe51f007c, 0xfdffffff }, // ldr:4:0xE51F007C
	{   9, 0xe5900000, 0xfdffffff }, // ldr:4:0xE5900000
	{  10, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{  11, 0xc1a01f87, 0xfdffffff }, // mov:6:0xC3A01F87
	{  12, 0xc04f009c, 0xfdffffff }, // sub:6:0xC24F009C
	{  13, 0xcb000000, 0xff000000 }, // b, bl:3:0xCB000083
	{  16, 0xea000000, 0xff000000 }, // b, bl:3:0xEAFFD76C
	{  17, 0x00000219, 0xfdffffff }, // and:6:0x00000219
	{  18, 0xe1a0c003, 0xfdffffff }, // mov:6:0xE1A0C003
	{  20, 0xe59d3010, 0xfdffffff }, // ldr:4:0xE59D3010
	{  21, 0xe58d3000, 0xfdffffff }, // str:4:0xE58D3000
	{  22, 0xe1a0300c, 0xfdffffff }, // mov:6:0xE1A0300C
	{  23, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFFF43
	{  24, 0xe1500005, 0xfdffffff }, // cmp:7:0xE3500005
	{  25, 0xe1a04000, 0xfdffffff }, // mov:6:0xE1A04000
	{  26, 0x008f0f72, 0xfdffffff }, // add:6:0x028F0F72
	{  27, 0x01a01013, 0xfdffffff }, // mov:6:0x03A01013
	{  28, 0x0b000000, 0xff000000 }, // b, bl:3:0x0B000074
	{  29, 0xe1a00004, 0xfdffffff }, // mov:6:0xE1A00004
	{ -1, -1, -1 },
	/* 26/32 */
};

static FuncSig func_sig_AllocateMemory_1[] = {
	{   0, 0xe5900000, 0xfdffffff }, // ldr:4:0xE5900000
	{   1, 0xea000000, 0xff000000 }, // b, bl:3:0xEAF90666
	{   3, 0xe5900000, 0xfdffffff }, // ldr:4:0xE5900000
	{   4, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBF90631
	{   5, 0xe1a00000, 0xfdffffff }, // mov:6:0xE3A00000
	{   7, 0xe0800004, 0xfdffffff }, // add:6:0xE2800004
	{   8, 0xe5101004, 0xfdffffff }, // ldr:4:0xE5101004
	{   9, 0xe5900000, 0xfdffffff }, // ldr:4:0xE5900000
	{  10, 0xe5810000, 0xfdffffff }, // str:4:0xE5810000
	{  11, 0xe1a00000, 0xfdffffff }, // mov:6:0xE3A00000
	{  13, 0x0000d71c, 0xfdffffff }, // and:6:0x0000D71C
	{  14, 0x0000000a, 0xfdffffff }, // and:6:0x0000000A
	{  16, 0x000a5838, 0xfdffffff }, // and:6:0x000A5838
	{  17, 0x00000a0d, 0xfdffffff }, // and:6:0x00000A0D
	{  22, 0x00000020, 0xfdffffff }, // and:6:0x00000020
	{  25, 0x00000020, 0xfdffffff }, // and:6:0x00000020
	{  27, 0x00000020, 0xfdffffff }, // and:6:0x00000020
	{  29, 0x00000020, 0xfdffffff }, // and:6:0x00000020
	{  31, 0x00000020, 0xfdffffff }, // and:6:0x00000020
	{ -1, -1, -1 },
	/* 19/32 */
};

static FuncSig func_sig_ExecuteEventProcedure_1[] = {
	{   2, 0xe59f00f8, 0xfdffffff }, // ldr:4:0xE59F00F8
	{   3, 0xe59d1010, 0xfdffffff }, // ldr:4:0xE59D1010
	{   4, 0xe0404014, 0xfdffffff }, // sub:6:0xE2404014
	{   5, 0xe58d0000, 0xfdffffff }, // str:4:0xE58D0000
	{   6, 0xe5940008, 0xfdffffff }, // ldr:4:0xE5940008
	{   7, 0xe08d5014, 0xfdffffff }, // add:6:0xE28D5014
	{   8, 0xe1a0200d, 0xfdffffff }, // mov:6:0xE1A0200D
	{   9, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB003810
	{  10, 0xe1500019, 0xfdffffff }, // cmp:7:0xE3500019
	{  11, 0x1a000000, 0xff000000 }, // b, bl:3:0x1A000007
	{  12, 0xe59f00a0, 0xfdffffff }, // ldr:4:0xE59F00A0
	{  13, 0xe59d3010, 0xfdffffff }, // ldr:4:0xE59D3010
	{  14, 0xe08f20cc, 0xfdffffff }, // add:6:0xE28F20CC
	{  15, 0xe08f10bc, 0xfdffffff }, // add:6:0xE28F10BC
	{  16, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB00092C
	{  17, 0xe5941004, 0xfdffffff }, // ldr:4:0xE5941004
	{  18, 0xe59f0088, 0xfdffffff }, // ldr:4:0xE59F0088
	{  20, 0xe5942000, 0xfdffffff }, // ldr:4:0xE5942000
	{  21, 0xe59d1010, 0xfdffffff }, // ldr:4:0xE59D1010
	{  22, 0xe5940010, 0xfdffffff }, // ldr:4:0xE5940010
	{  24, 0xe59d0000, 0xfdffffff }, // ldr:4:0xE59D0000
	{  26, 0xe1a00005, 0xfdffffff }, // mov:6:0xE1A00005
	{  29, 0xe49df014, 0xfdffffff }, // ldr:4:0xE49DF014
	{  30, 0x00001b0c, 0xfdffffff }, // and:6:0x00001B0C
	{ -1, -1, -1 },
	/* 24/32 */
};

static FuncSig func_sig_FreeMemory_1[] = {
	{   1, 0xe5900000, 0xfdffffff }, // ldr:4:0xE5900000
	{   2, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBF9066B
	{   3, 0xe1a00000, 0xfdffffff }, // mov:6:0xE3A00000
	{   5, 0xe5900000, 0xfdffffff }, // ldr:4:0xE5900000
	{   6, 0xea000000, 0xff000000 }, // b, bl:3:0xEAF90666
	{   8, 0xe5900000, 0xfdffffff }, // ldr:4:0xE5900000
	{   9, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBF90631
	{  10, 0xe1a00000, 0xfdffffff }, // mov:6:0xE3A00000
	{  12, 0xe0800004, 0xfdffffff }, // add:6:0xE2800004
	{  13, 0xe5101004, 0xfdffffff }, // ldr:4:0xE5101004
	{  14, 0xe5900000, 0xfdffffff }, // ldr:4:0xE5900000
	{  15, 0xe5810000, 0xfdffffff }, // str:4:0xE5810000
	{  16, 0xe1a00000, 0xfdffffff }, // mov:6:0xE3A00000
	{  18, 0x0000d71c, 0xfdffffff }, // and:6:0x0000D71C
	{  19, 0x0000000a, 0xfdffffff }, // and:6:0x0000000A
	{  21, 0x000a5838, 0xfdffffff }, // and:6:0x000A5838
	{  22, 0x00000a0d, 0xfdffffff }, // and:6:0x00000A0D
	{  27, 0x00000020, 0xfdffffff }, // and:6:0x00000020
	{  30, 0x00000020, 0xfdffffff }, // and:6:0x00000020
	{ -1, -1, -1 },
	/* 19/32 */
};

static FuncSig func_sig_GetCurrentTargetDistance_1[] = {
	{   0, 0xe51f0a94, 0xfdffffff }, // ldr:4:0xE51F0A94
	{   2, 0xe5900000, 0xfdffffff }, // ldr:4:0xE5900000
	{   3, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{   4, 0x059f0388, 0xfdffffff }, // ldr:4:0x059F0388
	{   5, 0x01a01fdb, 0xfdffffff }, // mov:6:0x03A01FDB
	{   6, 0x0b000000, 0xff000000 }, // b, bl:3:0x0BFC394F
	{   7, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB0331BC
	{   9, 0xea000000, 0xff000000 }, // b, bl:3:0xEAFFFFDC
	{  10, 0xe51f0abc, 0xfdffffff }, // ldr:4:0xE51F0ABC
	{  12, 0xe5900000, 0xfdffffff }, // ldr:4:0xE5900000
	{  13, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{  14, 0x059f13d4, 0xfdffffff }, // ldr:4:0x059F13D4
	{  15, 0x059f035c, 0xfdffffff }, // ldr:4:0x059F035C
	{  16, 0x0b000000, 0xff000000 }, // b, bl:3:0x0BFC3945
	{  17, 0xe1a02000, 0xfdffffff }, // mov:6:0xE3A02000
	{  18, 0xe1a0100d, 0xfdffffff }, // mov:6:0xE1A0100D
	{  19, 0xe08d0004, 0xfdffffff }, // add:6:0xE28D0004
	{  20, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB001685
	{  21, 0xe1a01000, 0xfdffffff }, // mov:6:0xE1A01000
	{  24, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB032FE0
	{  26, 0xe51f0afc, 0xfdffffff }, // ldr:4:0xE51F0AFC
	{  28, 0xe5900000, 0xfdffffff }, // ldr:4:0xE5900000
	{  29, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{  30, 0x059f1398, 0xfdffffff }, // ldr:4:0x059F1398
	{  31, 0x059f031c, 0xfdffffff }, // ldr:4:0x059F031C
	{ -1, -1, -1 },
	/* 25/32 */
};

static FuncSig func_sig_GetSystemTime_1[] = {
	{   1, 0xe1a0000d, 0xfdffffff }, // mov:6:0xE1A0000D
	{   2, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBF906F7
	{   3, 0xe59d0000, 0xfdffffff }, // ldr:4:0xE59D0000
	{   6, 0xe1a0e001, 0xfdffffff }, // mov:6:0xE1A0E001
	{   7, 0xe59f139c, 0xfdffffff }, // ldr:4:0xE59F139C
	{   8, 0xe1a0400d, 0xfdffffff }, // mov:6:0xE1A0400D
	{  10, 0xe1500004, 0xfdffffff }, // cmp:7:0xE3500004
	{  11, 0x315e0050, 0xfdffffff }, // cmp:7:0x335E0050
	{  12, 0x21a00001, 0xfdffffff }, // mov:6:0x23A00001
	{  14, 0x2a000000, 0xff000000 }, // b, bl:3:0x2A00000D
	{  15, 0xe51f1118, 0xfdffffff }, // ldr:4:0xE51F1118
	{  16, 0xe59f337c, 0xfdffffff }, // ldr:4:0xE59F337C
	{  18, 0xe1520000, 0xfdffffff }, // cmp:7:0xE3520000
	{  19, 0x1583e108, 0xfdffffff }, // str:4:0x1583E108
	{  20, 0x11a02e1a, 0xfdffffff }, // mov:6:0x13A02E1A
	{  21, 0x0583e104, 0xfdffffff }, // str:4:0x0583E104
	{  22, 0xe5940100, 0xfdffffff }, // ldr:4:0xE7940100
	{  23, 0x01a02e19, 0xfdffffff }, // mov:6:0x03A02E19
	{  24, 0xe5802000, 0xfdffffff }, // str:4:0xE5802000
	{  25, 0x11a00000, 0xfdffffff }, // mov:6:0x13A00000
	{  26, 0x01a00001, 0xfdffffff }, // mov:6:0x03A00001
	{  28, 0xe1a00000, 0xfdffffff }, // mov:6:0xE3A00000
	{  29, 0xe08dd010, 0xfdffffff }, // add:6:0xE28DD010
	{  31, 0xe0801004, 0xfdffffff }, // add:6:0xE2801004
	{ -1, -1, -1 },
	/* 24/32 */
};

static FuncSig func_sig_memcmp_1[] = {
	{   0, 0xe1520018, 0xfdffffff }, // cmp:7:0xE3520018
	{   1, 0x3a000000, 0xff000000 }, // b, bl:3:0x3A000029
	{   2, 0xea000000, 0xff000000 }, // b, bl:3:0xEA00000A
	{   5, 0xe153000c, 0xfdffffff }, // cmp:7:0xE153000C
	{   6, 0x00800001, 0xfdffffff }, // add:6:0x02800001
	{   7, 0x00811001, 0xfdffffff }, // add:6:0x02811001
	{   8, 0x00422001, 0xfdffffff }, // sub:6:0x02422001
	{   9, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A000003
	{  12, 0xe0400001, 0xfdffffff }, // sub:6:0xE0400001
	{  14, 0xe1100003, 0xfdffffff }, // tst:7:0xE3100003
	{  15, 0x1a000000, 0xff000000 }, // b, bl:3:0x1AFFFFF2
	{  16, 0xe0113003, 0xfdffffff }, // and:6:0xE2113003
	{  17, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A00000D
	{  18, 0xe1530001, 0xfdffffff }, // cmp:7:0xE3530001
	{  19, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A00001A
	{  20, 0xe1530002, 0xfdffffff }, // cmp:7:0xE3530002
	{  21, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A000013
	{  22, 0xe1530003, 0xfdffffff }, // cmp:7:0xE3530003
	{  23, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A000016
	{  24, 0xea000000, 0xff000000 }, // b, bl:3:0xEA000012
	{  25, 0xe5903000, 0xfdffffff }, // ldr:4:0xE5903000
	{  26, 0xe591c000, 0xfdffffff }, // ldr:4:0xE591C000
	{  27, 0xe153000c, 0xfdffffff }, // cmp:7:0xE153000C
	{  28, 0x1a000000, 0xff000000 }, // b, bl:3:0x1A000011
	{  29, 0xe0800004, 0xfdffffff }, // add:6:0xE2800004
	{  30, 0xe0811004, 0xfdffffff }, // add:6:0xE2811004
	{  31, 0xe0422004, 0xfdffffff }, // sub:6:0xE2422004
	{ -1, -1, -1 },
	/* 27/32 */
};

static FuncSig func_sig_memcpy_1[] = {
	{   0, 0xe1520010, 0xfdffffff }, // cmp:7:0xE3520010
	{   1, 0xe1a03000, 0xfdffffff }, // mov:6:0xE1A03000
	{   2, 0x3a000000, 0xff000000 }, // b, bl:3:0x3A000032
	{   3, 0xe1130003, 0xfdffffff }, // tst:7:0xE3130003
	{   5, 0x10422001, 0xfdffffff }, // sub:6:0x12422001
	{   7, 0x1a000000, 0xff000000 }, // b, bl:3:0x1AFFFFFA
	{   8, 0xe011c003, 0xfdffffff }, // and:6:0xE211C003
	{   9, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A00000D
	{  10, 0xe15c0001, 0xfdffffff }, // cmp:7:0xE35C0001
	{  11, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A000029
	{  12, 0xe15c0002, 0xfdffffff }, // cmp:7:0xE35C0002
	{  13, 0x1a000000, 0xff000000 }, // b, bl:3:0x1A000027
	{  14, 0xea000000, 0xff000000 }, // b, bl:3:0xEA00001A
	{  15, 0xe491c004, 0xfdffffff }, // ldr:4:0xE491C004
	{  16, 0xe0422010, 0xfdffffff }, // sub:6:0xE2422010
	{  17, 0xe483c004, 0xfdffffff }, // str:4:0xE483C004
	{  18, 0xe491c004, 0xfdffffff }, // ldr:4:0xE491C004
	{  19, 0xe483c004, 0xfdffffff }, // str:4:0xE483C004
	{  20, 0xe491c004, 0xfdffffff }, // ldr:4:0xE491C004
	{  21, 0xe483c004, 0xfdffffff }, // str:4:0xE483C004
	{  22, 0xe491c004, 0xfdffffff }, // ldr:4:0xE491C004
	{  23, 0xe483c004, 0xfdffffff }, // str:4:0xE483C004
	{  24, 0xe1520010, 0xfdffffff }, // cmp:7:0xE3520010
	{  25, 0x2a000000, 0xff000000 }, // b, bl:3:0x2AFFFFF4
	{  26, 0xea000000, 0xff000000 }, // b, bl:3:0xEA000002
	{  27, 0xe491c004, 0xfdffffff }, // ldr:4:0xE491C004
	{  28, 0xe0422004, 0xfdffffff }, // sub:6:0xE2422004
	{  29, 0xe483c004, 0xfdffffff }, // str:4:0xE483C004
	{  30, 0xe1520004, 0xfdffffff }, // cmp:7:0xE3520004
	{  31, 0x2a000000, 0xff000000 }, // b, bl:3:0x2AFFFFFA
	{ -1, -1, -1 },
	/* 30/32 */
};

static FuncSig func_sig_memset_1[] = {
	{   0, 0xe1a03001, 0xfdffffff }, // mov:6:0xE1A03001
	{   1, 0xe1520010, 0xfdffffff }, // cmp:7:0xE3520010
	{   2, 0xe003c0ff, 0xfdffffff }, // and:6:0xE203C0FF
	{   3, 0xe1a01000, 0xfdffffff }, // mov:6:0xE1A01000
	{   4, 0x3a000000, 0xff000000 }, // b, bl:3:0x3A000016
	{   5, 0xe1110003, 0xfdffffff }, // tst:7:0xE3110003
	{   6, 0x10422001, 0xfdffffff }, // sub:6:0x12422001
	{   8, 0x1a000000, 0xff000000 }, // b, bl:3:0x1AFFFFFB
	{   9, 0xe1a03c0c, 0xfdffffff }, // mov:6:0xE1A03C0C
	{  13, 0xe1520010, 0xfdffffff }, // cmp:7:0xE3520010
	{  14, 0x3a000000, 0xff000000 }, // b, bl:3:0x3A000007
	{  15, 0xe4813004, 0xfdffffff }, // str:4:0xE4813004
	{  16, 0xe4813004, 0xfdffffff }, // str:4:0xE4813004
	{  17, 0xe4813004, 0xfdffffff }, // str:4:0xE4813004
	{  18, 0xe0422010, 0xfdffffff }, // sub:6:0xE2422010
	{  19, 0xe4813004, 0xfdffffff }, // str:4:0xE4813004
	{  20, 0xea000000, 0xff000000 }, // b, bl:3:0xEAFFFFF7
	{  21, 0xe0422004, 0xfdffffff }, // sub:6:0xE2422004
	{  22, 0xe4813004, 0xfdffffff }, // str:4:0xE4813004
	{  23, 0xe1520004, 0xfdffffff }, // cmp:7:0xE3520004
	{  24, 0x2a000000, 0xff000000 }, // b, bl:3:0x2AFFFFFB
	{  25, 0xea000000, 0xff000000 }, // b, bl:3:0xEA000001
	{  26, 0xe0422001, 0xfdffffff }, // sub:6:0xE2422001
	{  28, 0xe1520000, 0xfdffffff }, // cmp:7:0xE3520000
	{  29, 0x1a000000, 0xff000000 }, // b, bl:3:0x1AFFFFFB
	{ -1, -1, -1 },
	/* 25/32 */
};

static FuncSig func_sig_Close_1[] = {
	{   1, 0xe1a05000, 0xfdffffff }, // mov:6:0xE1A05000
	{   2, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFD489
	{   3, 0xe1a04000, 0xfdffffff }, // mov:6:0xE1A04000
	{   4, 0xe1a00005, 0xfdffffff }, // mov:6:0xE1A00005
	{   5, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB00AAC1
	{   6, 0xe1a00004, 0xfdffffff }, // mov:6:0xE1A00004
	{   9, 0xe1a0200d, 0xfdffffff }, // mov:6:0xE1A0200D
	{  10, 0xe08d1004, 0xfdffffff }, // add:6:0xE28D1004
	{  11, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFD41F
	{  12, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{  14, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A000001
	{  15, 0xe59d1004, 0xfdffffff }, // ldr:4:0xE59D1004
	{  16, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB00B3FE
	{  19, 0xe1a05000, 0xfdffffff }, // mov:6:0xE1A05000
	{  20, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFFFF2
	{  21, 0xe1b04000, 0xfdffffff }, // mov:6:0xE1B04000
	{  22, 0x1a000000, 0xff000000 }, // b, bl:3:0x1A000008
	{  23, 0xe1a00005, 0xfdffffff }, // mov:6:0xE1A00005
	{  24, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB00AADC
	{  25, 0xe1a01005, 0xfdffffff }, // mov:6:0xE1A01005
	{  26, 0xe1a0000d, 0xfdffffff }, // mov:6:0xE1A0000D
	{  27, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB000176
	{  28, 0xe1a0000d, 0xfdffffff }, // mov:6:0xE1A0000D
	{  29, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB000185
	{  30, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{ -1, -1, -1 },
	/* 25/32 */
};

static FuncSig func_sig_Open_1[] = {
	{   1, 0xe1a06001, 0xfdffffff }, // mov:6:0xE1A06001
	{   2, 0xe1a05000, 0xfdffffff }, // mov:6:0xE1A05000
	{   3, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFD466
	{   4, 0xe1a04000, 0xfdffffff }, // mov:6:0xE1A04000
	{   5, 0xe1a02006, 0xfdffffff }, // mov:6:0xE1A02006
	{   6, 0xe1a01005, 0xfdffffff }, // mov:6:0xE1A01005
	{   7, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB00AA8D
	{   8, 0xe1a00004, 0xfdffffff }, // mov:6:0xE1A00004
	{  11, 0xe1a05000, 0xfdffffff }, // mov:6:0xE1A05000
	{  12, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFD489
	{  13, 0xe1a04000, 0xfdffffff }, // mov:6:0xE1A04000
	{  14, 0xe1a00005, 0xfdffffff }, // mov:6:0xE1A00005
	{  15, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB00AAC1
	{  16, 0xe1a00004, 0xfdffffff }, // mov:6:0xE1A00004
	{  19, 0xe1a0200d, 0xfdffffff }, // mov:6:0xE1A0200D
	{  20, 0xe08d1004, 0xfdffffff }, // add:6:0xE28D1004
	{  21, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFD41F
	{  22, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{  24, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A000001
	{  25, 0xe59d1004, 0xfdffffff }, // ldr:4:0xE59D1004
	{  26, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB00B3FE
	{  29, 0xe1a05000, 0xfdffffff }, // mov:6:0xE1A05000
	{  30, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFFFF2
	{  31, 0xe1b04000, 0xfdffffff }, // mov:6:0xE1B04000
	{ -1, -1, -1 },
	/* 24/32 */
};

static FuncSig func_sig_Read_1[] = {
	{   1, 0xe1b04002, 0xfdffffff }, // mov:6:0xE1B04002
	{   2, 0x01a00000, 0xfdffffff }, // mov:6:0x03A00000
	{   3, 0xe1a05001, 0xfdffffff }, // mov:6:0xE1A05001
	{   4, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A000008
	{   5, 0xe1a0200d, 0xfdffffff }, // mov:6:0xE1A0200D
	{   6, 0xe08d1004, 0xfdffffff }, // add:6:0xE28D1004
	{   7, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFFE27
	{   8, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{   9, 0xaa000000, 0xff000000 }, // b, bl:3:0xAA000004
	{  10, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFE4CD
	{  11, 0xe1a01009, 0xfdffffff }, // mov:6:0xE3A01009
	{  12, 0xe5801000, 0xfdffffff }, // str:4:0xE5801000
	{  15, 0xe59f01a4, 0xfdffffff }, // ldr:4:0xE59F01A4
	{  16, 0xe59d1004, 0xfdffffff }, // ldr:4:0xE59D1004
	{  17, 0xe1a02004, 0xfdffffff }, // mov:6:0xE1A02004
	{  18, 0xe5900101, 0xfdffffff }, // ldr:4:0xE7900101
	{  19, 0xe1a01005, 0xfdffffff }, // mov:6:0xE1A01005
	{  20, 0xe590300c, 0xfdffffff }, // ldr:4:0xE590300C
	{  21, 0xe59d0000, 0xfdffffff }, // ldr:4:0xE59D0000
	{  25, 0xe1b04002, 0xfdffffff }, // mov:6:0xE1B04002
	{  26, 0x01a00000, 0xfdffffff }, // mov:6:0x03A00000
	{  27, 0xe1a05001, 0xfdffffff }, // mov:6:0xE1A05001
	{  28, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A000008
	{  29, 0xe1a0200d, 0xfdffffff }, // mov:6:0xE1A0200D
	{  30, 0xe08d1004, 0xfdffffff }, // add:6:0xE28D1004
	{  31, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFFE0F
	{ -1, -1, -1 },
	/* 26/32 */
};

static FuncSig func_sig_Write_1[] = {
	{   1, 0xe1a06000, 0xfdffffff }, // mov:6:0xE1A06000
	{   2, 0xe1a05002, 0xfdffffff }, // mov:6:0xE1A05002
	{   3, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFD4EF
	{   4, 0xe1500005, 0xfdffffff }, // cmp:7:0xE1500005
	{   5, 0xe1a04000, 0xfdffffff }, // mov:6:0xE1A04000
	{   6, 0x11a00006, 0xfdffffff }, // mov:6:0x11A00006
	{   7, 0x1b000000, 0xff000000 }, // b, bl:3:0x1B00AA87
	{   8, 0xe1a00004, 0xfdffffff }, // mov:6:0xE1A00004
	{  11, 0xe1a05001, 0xfdffffff }, // mov:6:0xE1A05001
	{  12, 0xe1a01000, 0xfdffffff }, // mov:6:0xE3A01000
	{  13, 0xe1a02000, 0xfdffffff }, // mov:6:0xE3A02000
	{  14, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFD426
	{  15, 0xe0504000, 0xfdffffff }, // sub:6:0xE2504000
	{  18, 0xe1a02005, 0xfdffffff }, // mov:6:0xE1A02005
	{  19, 0xe1a0100b, 0xfdffffff }, // mov:6:0xE3A0100B
	{  20, 0xe1a00004, 0xfdffffff }, // mov:6:0xE1A00004
	{  21, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFD529
	{  22, 0xe1a05000, 0xfdffffff }, // mov:6:0xE1A05000
	{  23, 0xe1a00004, 0xfdffffff }, // mov:6:0xE1A00004
	{  24, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFD448
	{  25, 0xe1a00005, 0xfdffffff }, // mov:6:0xE1A00005
	{  28, 0xe1a06001, 0xfdffffff }, // mov:6:0xE1A06001
	{  29, 0xe1a05000, 0xfdffffff }, // mov:6:0xE1A05000
	{  30, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFFFEA
	{  31, 0xe1b04000, 0xfdffffff }, // mov:6:0xE1B04000
	{ -1, -1, -1 },
	/* 25/32 */
};

static FuncSig func_sig_Lseek_1[] = {
	{   1, 0xe1520000, 0xfdffffff }, // cmp:7:0xE3520000
	{   2, 0xe04dd034, 0xfdffffff }, // sub:6:0xE24DD034
	{   3, 0xe1a05000, 0xfdffffff }, // mov:6:0xE1A05000
	{   4, 0xe1a04001, 0xfdffffff }, // mov:6:0xE1A04001
	{   5, 0x1a000000, 0xff000000 }, // b, bl:3:0x1A00000B
	{   6, 0xe1a02004, 0xfdffffff }, // mov:6:0xE1A02004
	{   7, 0xe1a01010, 0xfdffffff }, // mov:6:0xE3A01010
	{   8, 0xe1a00005, 0xfdffffff }, // mov:6:0xE1A00005
	{   9, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFD510
	{  10, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{  11, 0xba000000, 0xff000000 }, // b, bl:3:0xBA000023
	{  12, 0xe1a02000, 0xfdffffff }, // mov:6:0xE3A02000
	{  13, 0xe1a0100f, 0xfdffffff }, // mov:6:0xE3A0100F
	{  14, 0xe1a00005, 0xfdffffff }, // mov:6:0xE1A00005
	{  15, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFD50A
	{  16, 0xe08dd034, 0xfdffffff }, // add:6:0xE28DD034
	{  18, 0xe1520001, 0xfdffffff }, // cmp:7:0xE3520001
	{  19, 0x1a000000, 0xff000000 }, // b, bl:3:0x1A00000F
	{  20, 0xe1a02000, 0xfdffffff }, // mov:6:0xE3A02000
	{  21, 0xe1a0100f, 0xfdffffff }, // mov:6:0xE3A0100F
	{  22, 0xe1a00005, 0xfdffffff }, // mov:6:0xE1A00005
	{  23, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFD502
	{  24, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{  25, 0xba000000, 0xff000000 }, // b, bl:3:0xBA000015
	{  26, 0xe0844000, 0xfdffffff }, // add:6:0xE0844000
	{  27, 0xea000000, 0xff000000 }, // b, bl:3:0xEA000011
	{  28, 0xe1a02004, 0xfdffffff }, // mov:6:0xE1A02004
	{  29, 0xe1a01010, 0xfdffffff }, // mov:6:0xE3A01010
	{  30, 0xe1a00005, 0xfdffffff }, // mov:6:0xE1A00005
	{  31, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFD4FA
	{ -1, -1, -1 },
	/* 30/32 */
};

static FuncSig func_sig_strcmp_1[] = {
	{   0, 0xea000000, 0xff000000 }, // b, bl:3:0xEA000008
	{   2, 0xe1520003, 0xfdffffff }, // cmp:7:0xE1520003
	{   3, 0x00800001, 0xfdffffff }, // add:6:0x02800001
	{   4, 0x00811001, 0xfdffffff }, // add:6:0x02811001
	{   5, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A000003
	{   8, 0xe0400001, 0xfdffffff }, // sub:6:0xE0400001
	{  11, 0xe1520000, 0xfdffffff }, // cmp:7:0xE3520000
	{  13, 0x01530000, 0xfdffffff }, // cmp:7:0x03530000
	{  14, 0x1a000000, 0xff000000 }, // b, bl:3:0x1AFFFFF1
	{  15, 0xe1a00000, 0xfdffffff }, // mov:6:0xE3A00000
	{  17, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{  19, 0xe1a01000, 0xfdffffff }, // mov:6:0xE1A01000
	{  21, 0xe1520000, 0xfdffffff }, // cmp:7:0xE3520000
	{  22, 0x10811001, 0xfdffffff }, // add:6:0x12811001
	{  23, 0x1a000000, 0xff000000 }, // b, bl:3:0x1AFFFFFB
	{  24, 0xe0410000, 0xfdffffff }, // sub:6:0xE0410000
	{  26, 0xe1520018, 0xfdffffff }, // cmp:7:0xE3520018
	{  27, 0x3a000000, 0xff000000 }, // b, bl:3:0x3A000029
	{  28, 0xea000000, 0xff000000 }, // b, bl:3:0xEA00000A
	{  31, 0xe153000c, 0xfdffffff }, // cmp:7:0xE153000C
	{ -1, -1, -1 },
	/* 20/32 */
};

static FuncSig func_sig_strcpy_1[] = {
	{   0, 0xe1a02000, 0xfdffffff }, // mov:6:0xE1A02000
	{   2, 0xe1530000, 0xfdffffff }, // cmp:7:0xE3530000
	{   4, 0x1a000000, 0xff000000 }, // b, bl:3:0x1AFFFFFB
	{   6, 0xe1a03000, 0xfdffffff }, // mov:6:0xE1A03000
	{   7, 0xea000000, 0xff000000 }, // b, bl:3:0xEA000009
	{   9, 0xe15c0000, 0xfdffffff }, // cmp:7:0xE35C0000
	{  11, 0x1a000000, 0xff000000 }, // b, bl:3:0x1A000005
	{  12, 0xe1a01000, 0xfdffffff }, // mov:6:0xE3A01000
	{  13, 0xe0422001, 0xfdffffff }, // sub:6:0xE2422001
	{  16, 0x1a000000, 0xff000000 }, // b, bl:3:0x1AFFFFFB
	{  18, 0xe0522001, 0xfdffffff }, // sub:6:0xE2522001
	{  19, 0x2a000000, 0xff000000 }, // b, bl:3:0x2AFFFFF3
	{  21, 0xea000000, 0xff000000 }, // b, bl:3:0xEA000008
	{  23, 0xe1520003, 0xfdffffff }, // cmp:7:0xE1520003
	{  24, 0x00800001, 0xfdffffff }, // add:6:0x02800001
	{  25, 0x00811001, 0xfdffffff }, // add:6:0x02811001
	{  26, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A000003
	{  29, 0xe0400001, 0xfdffffff }, // sub:6:0xE0400001
	{ -1, -1, -1 },
	/* 18/32 */
};

static FuncSig func_sig_strlen_1[] = {
	{   0, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{   2, 0xe1a01000, 0xfdffffff }, // mov:6:0xE1A01000
	{   4, 0xe1520000, 0xfdffffff }, // cmp:7:0xE3520000
	{   5, 0x10811001, 0xfdffffff }, // add:6:0x12811001
	{   6, 0x1a000000, 0xff000000 }, // b, bl:3:0x1AFFFFFB
	{   7, 0xe0410000, 0xfdffffff }, // sub:6:0xE0410000
	{   9, 0xe1520018, 0xfdffffff }, // cmp:7:0xE3520018
	{  10, 0x3a000000, 0xff000000 }, // b, bl:3:0x3A000029
	{  11, 0xea000000, 0xff000000 }, // b, bl:3:0xEA00000A
	{  14, 0xe153000c, 0xfdffffff }, // cmp:7:0xE153000C
	{  15, 0x00800001, 0xfdffffff }, // add:6:0x02800001
	{  16, 0x00811001, 0xfdffffff }, // add:6:0x02811001
	{  17, 0x00422001, 0xfdffffff }, // sub:6:0x02422001
	{  18, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A000003
	{  21, 0xe0400001, 0xfdffffff }, // sub:6:0xE0400001
	{  23, 0xe1100003, 0xfdffffff }, // tst:7:0xE3100003
	{  24, 0x1a000000, 0xff000000 }, // b, bl:3:0x1AFFFFF2
	{  25, 0xe0113003, 0xfdffffff }, // and:6:0xE2113003
	{  26, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A00000D
	{  27, 0xe1530001, 0xfdffffff }, // cmp:7:0xE3530001
	{  28, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A00001A
	{  29, 0xe1530002, 0xfdffffff }, // cmp:7:0xE3530002
	{  30, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A000013
	{  31, 0xe1530003, 0xfdffffff }, // cmp:7:0xE3530003
	{ -1, -1, -1 },
	/* 24/32 */
};

static FuncSig func_sig_TakeSemaphore_1[] = {
	{   1, 0xe1a04000, 0xfdffffff }, // mov:6:0xE1A04000
	{   2, 0xe59f009c, 0xfdffffff }, // ldr:4:0xE59F009C
	{   3, 0xe1a05001, 0xfdffffff }, // mov:6:0xE1A05001
	{   4, 0xe5900000, 0xfdffffff }, // ldr:4:0xE5900000
	{   5, 0xe5900000, 0xfdffffff }, // ldr:4:0xE5900000
	{   6, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{   7, 0xc59f109c, 0xfdffffff }, // ldr:4:0xC59F109C
	{   8, 0xc08f0088, 0xfdffffff }, // add:6:0xC28F0088
	{   9, 0xcb000000, 0xff000000 }, // b, bl:3:0xCB000184
	{  10, 0xe59f0094, 0xfdffffff }, // ldr:4:0xE59F0094
	{  11, 0xe5900000, 0xfdffffff }, // ldr:4:0xE5900000
	{  12, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{  13, 0xc59f108c, 0xfdffffff }, // ldr:4:0xC59F108C
	{  14, 0xc08f0070, 0xfdffffff }, // add:6:0xC28F0070
	{  15, 0xcb000000, 0xff000000 }, // b, bl:3:0xCB00017E
	{  16, 0xe0040001, 0xfdffffff }, // and:6:0xE2040001
	{  17, 0xe0400001, 0xfdffffff }, // sub:6:0xE2400001
	{  18, 0xe1100004, 0xfdffffff }, // tst:7:0xE1100004
	{  19, 0x01a00007, 0xfdffffff }, // mov:6:0x03A00007
	{  20, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A000014
	{  21, 0xe1550000, 0xfdffffff }, // cmp:7:0xE3550000
	{  22, 0x01a00000, 0xfdffffff }, // mov:6:0x03A00000
	{  23, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A000002
	{  24, 0xe1a01005, 0xfdffffff }, // mov:6:0xE1A01005
	{  25, 0xe1a0000d, 0xfdffffff }, // mov:6:0xE1A0000D
	{  26, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB0034F7
	{  27, 0xe1a01000, 0xfdffffff }, // mov:6:0xE1A01000
	{  28, 0xe1a000a4, 0xfdffffff }, // mov:6:0xE1A000A4
	{  29, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFDA36
	{  31, 0x01a00009, 0xfdffffff }, // mov:6:0x03A00009
	{ -1, -1, -1 },
	/* 30/32 */
};

static FuncSig func_sig_vsprintf_1[] = {
	{   0, 0xe52de004, 0xfdffffff }, // str:4:0xE52DE004
	{   1, 0xe04dd01c, 0xfdffffff }, // sub:6:0xE24DD01C
	{   2, 0xe58d0008, 0xfdffffff }, // str:4:0xE58D0008
	{   3, 0xe1a00002, 0xfdffffff }, // mov:6:0xE3A00002
	{   4, 0xe1a03002, 0xfdffffff }, // mov:6:0xE1A03002
	{   5, 0xe1a02001, 0xfdffffff }, // mov:6:0xE1A02001
	{   7, 0xe04f004c, 0xfdffffff }, // sub:6:0xE24F004C
	{   8, 0xe08d1004, 0xfdffffff }, // add:6:0xE28D1004
	{   9, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFE9A3
	{  10, 0xe59d2008, 0xfdffffff }, // ldr:4:0xE59D2008
	{  11, 0xe1a01000, 0xfdffffff }, // mov:6:0xE3A01000
	{  13, 0xe08dd01c, 0xfdffffff }, // add:6:0xE28DD01C
	{  14, 0xe49df004, 0xfdffffff }, // ldr:4:0xE49DF004
	{  17, 0xe04dd054, 0xfdffffff }, // sub:6:0xE24DD054
	{  18, 0xe1a05001, 0xfdffffff }, // mov:6:0xE1A05001
	{  19, 0xe1a04000, 0xfdffffff }, // mov:6:0xE1A04000
	{  20, 0xe59d2068, 0xfdffffff }, // ldr:4:0xE59D2068
	{  21, 0xe08d0004, 0xfdffffff }, // add:6:0xE28D0004
	{  22, 0xe1a01050, 0xfdffffff }, // mov:6:0xE3A01050
	{  23, 0xe08d306c, 0xfdffffff }, // add:6:0xE28D306C
	{  24, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB004457
	{  25, 0xe08d2004, 0xfdffffff }, // add:6:0xE28D2004
	{  26, 0xe1a01005, 0xfdffffff }, // mov:6:0xE1A01005
	{  27, 0xe1a00004, 0xfdffffff }, // mov:6:0xE1A00004
	{  28, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFCA11
	{  29, 0xe08dd054, 0xfdffffff }, // add:6:0xE28DD054
	{  31, 0xe49df014, 0xfdffffff }, // ldr:4:0xE49DF014
	{ -1, -1, -1 },
	/* 27/32 */
};

static FuncSig func_sig_GetFocusLensSubjectDistance_1[] = {
	{   1, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFFAE5
	{   2, 0xe1a01000, 0xfdffffff }, // mov:6:0xE1A01000
	{   3, 0xe08f006c, 0xfdffffff }, // add:6:0xE28F006C
	{   4, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFC0987
	{   5, 0xe1a00000, 0xfdffffff }, // mov:6:0xE3A00000
	{   7, 0xe1a0001e, 0xfdffffff }, // mov:6:0xE3A0001E
	{   9, 0xe1a00010, 0xfdffffff }, // mov:6:0xE3A00010
	{  12, 0xe5904000, 0xfdffffff }, // ldr:4:0xE5904000
	{  13, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFCF2D3
	{  14, 0xe1a0100d, 0xfdffffff }, // mov:6:0xE1A0100D
	{  15, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFCF065
	{  16, 0xe59d0000, 0xfdffffff }, // ldr:4:0xE59D0000
	{  17, 0xe0800084, 0xfdffffff }, // add:6:0xE0800084
	{  23, 0x00006425, 0xfdffffff }, // and:6:0x00006425
	{  27, 0x00642520, 0xfdffffff }, // rsb:6:0x00642520
	{  31, 0x00642520, 0xfdffffff }, // rsb:6:0x00642520
	{ -1, -1, -1 },
	/* 16/32 */
};

static FuncSig func_sig_GetZoomLensCurrentPoint_1[] = {
	{   1, 0xe51f41bc, 0xfdffffff }, // ldr:4:0xE51F41BC
	{   2, 0xe5940000, 0xfdffffff }, // ldr:4:0xE5940000
	{   3, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{   4, 0x059f1bf0, 0xfdffffff }, // ldr:4:0x059F1BF0
	{   5, 0x004f0f6f, 0xfdffffff }, // sub:6:0x024F0F6F
	{   6, 0x0b000000, 0xff000000 }, // b, bl:3:0x0BFC2427
	{   7, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB03340F
	{   8, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{  10, 0x1a000000, 0xff000000 }, // b, bl:3:0x1AFFFFEB
	{  11, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB03340C
	{  12, 0xe5941004, 0xfdffffff }, // ldr:4:0xE5941004
	{  14, 0xea000000, 0xff000000 }, // b, bl:3:0xEA033197
	{  16, 0xe1a09002, 0xfdffffff }, // mov:6:0xE1A09002
	{  17, 0xe1a07000, 0xfdffffff }, // mov:6:0xE1A07000
	{  18, 0xe1a05001, 0xfdffffff }, // mov:6:0xE1A05001
	{  19, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFFFEB
	{  20, 0xe51f6208, 0xfdffffff }, // ldr:4:0xE51F6208
	{  21, 0xe1a04000, 0xfdffffff }, // mov:6:0xE1A04000
	{  22, 0xe5960000, 0xfdffffff }, // ldr:4:0xE5960000
	{  23, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{  24, 0x01a010c6, 0xfdffffff }, // mov:6:0x03A010C6
	{  25, 0x004f0f83, 0xfdffffff }, // sub:6:0x024F0F83
	{  26, 0x0b000000, 0xff000000 }, // b, bl:3:0x0BFC2413
	{  27, 0xe5960008, 0xfdffffff }, // ldr:4:0xE5960008
	{  28, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{  30, 0xe5960010, 0xfdffffff }, // ldr:4:0xE5960010
	{  31, 0xe51f8208, 0xfdffffff }, // ldr:4:0xE51F8208
	{ -1, -1, -1 },
	/* 27/32 */
};

static FuncSig func_sig_GetZoomLensCurrentPosition_1[] = {
	{   0, 0xea000000, 0xff000000 }, // b, bl:3:0xEA033137
	{   1, 0xea000000, 0xff000000 }, // b, bl:3:0xEAFFFE0C
	{   2, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{   3, 0x059f0100, 0xfdffffff }, // ldr:4:0x059F0100
	{   4, 0xe51f2d48, 0xfdffffff }, // ldr:4:0xE51F2D48
	{   5, 0xe5820028, 0xfdffffff }, // str:4:0xE5820028
	{   6, 0x01a00000, 0xfdffffff }, // mov:6:0x03A00000
	{   7, 0x1582102c, 0xfdffffff }, // str:4:0x1582102C
	{   8, 0x0582002c, 0xfdffffff }, // str:4:0x0582002C
	{  10, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{  11, 0x059f00e4, 0xfdffffff }, // ldr:4:0x059F00E4
	{  12, 0xe51f2d68, 0xfdffffff }, // ldr:4:0xE51F2D68
	{  13, 0xe5820018, 0xfdffffff }, // str:4:0xE5820018
	{  14, 0x01a00000, 0xfdffffff }, // mov:6:0x03A00000
	{  15, 0x1582101c, 0xfdffffff }, // str:4:0x1582101C
	{  16, 0x0582001c, 0xfdffffff }, // str:4:0x0582001C
	{  19, 0xe59f00c8, 0xfdffffff }, // ldr:4:0xE59F00C8
	{  20, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB033528
	{  21, 0xe59f00c4, 0xfdffffff }, // ldr:4:0xE59F00C4
	{  23, 0xea000000, 0xff000000 }, // b, bl:3:0xEA032DF1
	{  24, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{  25, 0x059f00a8, 0xfdffffff }, // ldr:4:0x059F00A8
	{  26, 0xe51f2da0, 0xfdffffff }, // ldr:4:0xE51F2DA0
	{  27, 0xe5820020, 0xfdffffff }, // str:4:0xE5820020
	{  28, 0x01a00000, 0xfdffffff }, // mov:6:0x03A00000
	{  29, 0x15821024, 0xfdffffff }, // str:4:0x15821024
	{  30, 0x05820024, 0xfdffffff }, // str:4:0x05820024
	{ -1, -1, -1 },
	/* 27/32 */
};

static FuncSig func_sig_RefreshPhysicalScreen_1[] = {
	{   1, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB0000A4
	{   2, 0xe1100001, 0xfdffffff }, // tst:7:0xE3100001
	{   3, 0x1a000000, 0xff000000 }, // b, bl:3:0x1A000017
	{   4, 0xe51f44d0, 0xfdffffff }, // ldr:4:0xE51F44D0
	{   5, 0xe5940030, 0xfdffffff }, // ldr:4:0xE5940030
	{   6, 0xe1500001, 0xfdffffff }, // cmp:7:0xE3500001
	{   7, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A000011
	{   8, 0xe08f1f7b, 0xfdffffff }, // add:6:0xE28F1F7B
	{   9, 0xe1a00020, 0xfdffffff }, // mov:6:0xE3A00020
	{  10, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFBD744
	{  11, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFF1A8
	{  13, 0xe1a01000, 0xfdffffff }, // mov:6:0xE3A01000
	{  14, 0xe58d1000, 0xfdffffff }, // str:4:0xE58D1000
	{  16, 0xe594c028, 0xfdffffff }, // ldr:4:0xE594C028
	{  17, 0xe594100c, 0xfdffffff }, // ldr:4:0xE594100C
	{  18, 0xe5943000, 0xfdffffff }, // ldr:4:0xE5943000
	{  19, 0xe1a02000, 0xfdffffff }, // mov:6:0xE3A02000
	{  21, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFF19D
	{  22, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFF084
	{  23, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFF242
	{  24, 0xe1a00000, 0xfdffffff }, // mov:6:0xE3A00000
	{  25, 0xe584002c, 0xfdffffff }, // str:4:0xE584002C
	{  26, 0xe5940018, 0xfdffffff }, // ldr:4:0xE5940018
	{  27, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFAA64D
	{  29, 0xe51f1534, 0xfdffffff }, // ldr:4:0xE51F1534
	{  30, 0xe1a00000, 0xfdffffff }, // mov:6:0xE3A00000
	{  31, 0xe5810030, 0xfdffffff }, // str:4:0xE5810030
	{ -1, -1, -1 },
	/* 27/32 */
};

static FuncSig func_sig_GetPropertyCase_1[] = {
	{   1, 0xe51f4130, 0xfdffffff }, // ldr:4:0xE51F4130
	{   2, 0xe1a05000, 0xfdffffff }, // mov:6:0xE1A05000
	{   3, 0xe5940000, 0xfdffffff }, // ldr:4:0xE5940000
	{   4, 0xe1a06001, 0xfdffffff }, // mov:6:0xE1A06001
	{   5, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{   6, 0x059f1820, 0xfdffffff }, // ldr:4:0x059F1820
	{   7, 0x004f0f51, 0xfdffffff }, // sub:6:0x024F0F51
	{   8, 0xe1a07002, 0xfdffffff }, // mov:6:0xE1A07002
	{   9, 0x0b000000, 0xff000000 }, // b, bl:3:0x0BFEC910
	{  10, 0xe5940008, 0xfdffffff }, // ldr:4:0xE5940008
	{  11, 0xe59f3810, 0xfdffffff }, // ldr:4:0xE59F3810
	{  12, 0xe59f1800, 0xfdffffff }, // ldr:4:0xE59F1800
	{  13, 0xe5900000, 0xfdffffff }, // ldr:4:0xE5900000
	{  14, 0xe04f2e16, 0xfdffffff }, // sub:6:0xE24F2E16
	{  15, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFEC8C4
	{  16, 0xe5940008, 0xfdffffff }, // ldr:4:0xE5940008
	{  17, 0xe1a03007, 0xfdffffff }, // mov:6:0xE1A03007
	{  18, 0xe1a02006, 0xfdffffff }, // mov:6:0xE1A02006
	{  19, 0xe1a01005, 0xfdffffff }, // mov:6:0xE1A01005
	{  20, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFFFC5
	{  21, 0xe1a05000, 0xfdffffff }, // mov:6:0xE1A05000
	{  22, 0xe5940008, 0xfdffffff }, // ldr:4:0xE5940008
	{  23, 0xe5900000, 0xfdffffff }, // ldr:4:0xE5900000
	{  24, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFEC7A6
	{  25, 0xe1a00005, 0xfdffffff }, // mov:6:0xE1A00005
	{  28, 0xe51f419c, 0xfdffffff }, // ldr:4:0xE51F419C
	{  29, 0xe5940000, 0xfdffffff }, // ldr:4:0xE5940000
	{  30, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{  31, 0x059f17c4, 0xfdffffff }, // ldr:4:0x059F17C4
	{ -1, -1, -1 },
	/* 29/32 */
};

static FuncSig func_sig_SetPropertyCase_1[] = {
	{   0, 0xea000000, 0xff000000 }, // b, bl:3:0xEA002395
	{   2, 0xe08d1004, 0xfdffffff }, // add:6:0xE28D1004
	{   3, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB002392
	{   5, 0xea000000, 0xff000000 }, // b, bl:3:0xEA0023D2
	{   7, 0xe1a02000, 0xfdffffff }, // mov:6:0xE3A02000
	{   8, 0xe1510001, 0xfdffffff }, // cmp:7:0xE3510001
	{   9, 0xe58d2008, 0xfdffffff }, // str:4:0xE58D2008
	{  10, 0xe58d2004, 0xfdffffff }, // str:4:0xE58D2004
	{  11, 0xe58d2000, 0xfdffffff }, // str:4:0xE58D2000
	{  12, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A000009
	{  13, 0xe1510002, 0xfdffffff }, // cmp:7:0xE3510002
	{  14, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A00000C
	{  15, 0xe1510004, 0xfdffffff }, // cmp:7:0xE3510004
	{  16, 0x11a00002, 0xfdffffff }, // mov:6:0x11A00002
	{  17, 0x1a000000, 0xff000000 }, // b, bl:3:0x1A000003
	{  18, 0xe1a02004, 0xfdffffff }, // mov:6:0xE3A02004
	{  19, 0xe08d1008, 0xfdffffff }, // add:6:0xE28D1008
	{  20, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB0023C3
	{  21, 0xe59d0008, 0xfdffffff }, // ldr:4:0xE59D0008
	{  23, 0xe1a02001, 0xfdffffff }, // mov:6:0xE3A02001
	{  24, 0xe1a0100d, 0xfdffffff }, // mov:6:0xE1A0100D
	{  25, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB0023BE
	{  28, 0xe1a02004, 0xfdffffff }, // mov:6:0xE3A02004
	{  29, 0xe08d1004, 0xfdffffff }, // add:6:0xE28D1004
	{  30, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB0023B9
	{ -1, -1, -1 },
	/* 25/32 */
};

static FuncSig func_sig_VbattGet_1[] = {
	{   1, 0xe1a00002, 0xfdffffff }, // mov:6:0xE3A00002
	{   2, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB008AF0
	{   3, 0xe51f183c, 0xfdffffff }, // ldr:4:0xE51F183C
	{   6, 0xe0400001, 0xfdffffff }, // sub:6:0xE0400001
	{   7, 0xe1a00800, 0xfdffffff }, // mov:6:0xE1A00800
	{   8, 0xe1a00840, 0xfdffffff }, // mov:6:0xE1A00840
	{   9, 0xea000000, 0xff000000 }, // b, bl:3:0xEAFFFD64
	{  11, 0xe1a00002, 0xfdffffff }, // mov:6:0xE3A00002
	{  12, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB008A94
	{  13, 0xe1a00000, 0xfdffffff }, // mov:6:0xE3A00000
	{  14, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB008A92
	{  15, 0xe1a00001, 0xfdffffff }, // mov:6:0xE3A00001
	{  16, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB008A90
	{  17, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFFFED
	{  18, 0xe1a05000, 0xfdffffff }, // mov:6:0xE1A05000
	{  19, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFE7BB
	{  20, 0xe59f657c, 0xfdffffff }, // ldr:4:0xE59F657C
	{  21, 0xe59640e4, 0xfdffffff }, // ldr:4:0xE59640E4
	{  22, 0xe1a00002, 0xfdffffff }, // mov:6:0xE3A00002
	{  23, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB008A75
	{  24, 0xe1a00000, 0xfdffffff }, // mov:6:0xE3A00000
	{  25, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB008A73
	{  26, 0xe1a00001, 0xfdffffff }, // mov:6:0xE3A00001
	{  27, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB008A71
	{  28, 0xe51fc8f4, 0xfdffffff }, // ldr:4:0xE51FC8F4
	{  29, 0xe59c3028, 0xfdffffff }, // ldr:4:0xE59C3028
	{  30, 0xe1530001, 0xfdffffff }, // cmp:7:0xE3530001
	{  31, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A000047
	{ -1, -1, -1 },
	/* 28/32 */
};

static FuncSig func_sig_kbd_read_keys_1[] = {
	{   0, 0xe51f214c, 0xfdffffff }, // ldr:4:0xE51F214C
	{   2, 0xe1a00002, 0xfdffffff }, // mov:6:0xE3A00002
	{   3, 0xe1a01000, 0xfdffffff }, // mov:6:0xE3A01000
	{   4, 0xe5821100, 0xfdffffff }, // str:4:0xE7821100
	{   5, 0xe0500001, 0xfdffffff }, // sub:6:0xE2500001
	{   6, 0x5a000000, 0xff000000 }, // b, bl:3:0x5AFFFFFC
	{   7, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB008FDE
	{   8, 0xe51f016c, 0xfdffffff }, // ldr:4:0xE51F016C
	{   9, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB008FCF
	{  10, 0xe51f0174, 0xfdffffff }, // ldr:4:0xE51F0174
	{  11, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB008E85
	{  13, 0xea000000, 0xff000000 }, // b, bl:3:0xEA008FEE
	{  15, 0xe51f5190, 0xfdffffff }, // ldr:4:0xE51F5190
	{  16, 0xe1a04000, 0xfdffffff }, // mov:6:0xE1A04000
	{  17, 0xe5950008, 0xfdffffff }, // ldr:4:0xE5950008
	{  18, 0xe1500001, 0xfdffffff }, // cmp:7:0xE3500001
	{  19, 0x1a000000, 0xff000000 }, // b, bl:3:0x1A000003
	{  20, 0xe59f0150, 0xfdffffff }, // ldr:4:0xE59F0150
	{  21, 0xe1540000, 0xfdffffff }, // cmp:7:0xE1540000
	{  22, 0x11540c09, 0xfdffffff }, // cmp:7:0x13540C09
	{  24, 0xe1a00004, 0xfdffffff }, // mov:6:0xE1A00004
	{  25, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB0122C7
	{  26, 0xe5950000, 0xfdffffff }, // ldr:4:0xE5950000
	{  27, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{  28, 0x11a01004, 0xfdffffff }, // mov:6:0x11A01004
	{  30, 0x108f0f4b, 0xfdffffff }, // add:6:0x128F0F4B
	{  31, 0x1a000000, 0xff000000 }, // b, bl:3:0x1AFFB920
	{ -1, -1, -1 },
	/* 27/32 */
};

static FuncSig func_sig_kbd_p1_f_1[] = {
	{   1, 0xe1a04000, 0xfdffffff }, // mov:6:0xE3A04000
	{   2, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFFFBB
	{   3, 0xe51f1260, 0xfdffffff }, // ldr:4:0xE51F1260
	{   4, 0xe1a00002, 0xfdffffff }, // mov:6:0xE3A00002
	{   5, 0xe041200c, 0xfdffffff }, // sub:6:0xE241200C
	{   6, 0xe0823018, 0xfdffffff }, // add:6:0xE2823018
	{   7, 0xe1a0500d, 0xfdffffff }, // mov:6:0xE1A0500D
	{   8, 0xe593c100, 0xfdffffff }, // ldr:4:0xE793C100
	{   9, 0xe592e100, 0xfdffffff }, // ldr:4:0xE792E100
	{  10, 0xe00cc00e, 0xfdffffff }, // and:6:0xE00CC00E
	{  11, 0xe591e100, 0xfdffffff }, // ldr:4:0xE791E100
	{  13, 0xe585c100, 0xfdffffff }, // str:4:0xE785C100
	{  14, 0xe0500001, 0xfdffffff }, // sub:6:0xE2500001
	{  15, 0x5a000000, 0xff000000 }, // b, bl:3:0x5AFFFFF7
	{  16, 0xe51f2280, 0xfdffffff }, // ldr:4:0xE51F2280
	{  17, 0xe1a0000d, 0xfdffffff }, // mov:6:0xE1A0000D
	{  18, 0xe042100c, 0xfdffffff }, // sub:6:0xE242100C
	{  19, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFFE53
	{  20, 0xe51f029c, 0xfdffffff }, // ldr:4:0xE51F029C
	{  21, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB008E30
	{  22, 0xe51f12a4, 0xfdffffff }, // ldr:4:0xE51F12A4
	{  23, 0xe1500001, 0xfdffffff }, // cmp:7:0xE3500001
	{  24, 0x01a04001, 0xfdffffff }, // mov:6:0x03A04001
	{  25, 0xe1a00002, 0xfdffffff }, // mov:6:0xE3A00002
	{  26, 0xe081200c, 0xfdffffff }, // add:6:0xE281200C
	{  27, 0xe5923100, 0xfdffffff }, // ldr:4:0xE7923100
	{  28, 0xe1530000, 0xfdffffff }, // cmp:7:0xE3530000
	{  29, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A000006
	{  30, 0xe591c100, 0xfdffffff }, // ldr:4:0xE791C100
	{  31, 0xe595e100, 0xfdffffff }, // ldr:4:0xE795E100
	{ -1, -1, -1 },
	/* 30/32 */
};

static FuncSig func_sig_kbd_p1_f_cont_1[] = {
	{   0, 0xe51f1260, 0xfdffffff }, // ldr:4:0xE51F1260
	{   1, 0xe1a00002, 0xfdffffff }, // mov:6:0xE3A00002
	{   2, 0xe041200c, 0xfdffffff }, // sub:6:0xE241200C
	{   3, 0xe0823018, 0xfdffffff }, // add:6:0xE2823018
	{   4, 0xe1a0500d, 0xfdffffff }, // mov:6:0xE1A0500D
	{   5, 0xe593c100, 0xfdffffff }, // ldr:4:0xE793C100
	{   6, 0xe592e100, 0xfdffffff }, // ldr:4:0xE792E100
	{   7, 0xe00cc00e, 0xfdffffff }, // and:6:0xE00CC00E
	{   8, 0xe591e100, 0xfdffffff }, // ldr:4:0xE791E100
	{  10, 0xe585c100, 0xfdffffff }, // str:4:0xE785C100
	{  11, 0xe0500001, 0xfdffffff }, // sub:6:0xE2500001
	{  12, 0x5a000000, 0xff000000 }, // b, bl:3:0x5AFFFFF7
	{  13, 0xe51f2280, 0xfdffffff }, // ldr:4:0xE51F2280
	{  14, 0xe1a0000d, 0xfdffffff }, // mov:6:0xE1A0000D
	{  15, 0xe042100c, 0xfdffffff }, // sub:6:0xE242100C
	{  16, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFFE53
	{  17, 0xe51f029c, 0xfdffffff }, // ldr:4:0xE51F029C
	{  18, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB008E30
	{  19, 0xe51f12a4, 0xfdffffff }, // ldr:4:0xE51F12A4
	{  20, 0xe1500001, 0xfdffffff }, // cmp:7:0xE3500001
	{  21, 0x01a04001, 0xfdffffff }, // mov:6:0x03A04001
	{  22, 0xe1a00002, 0xfdffffff }, // mov:6:0xE3A00002
	{  23, 0xe081200c, 0xfdffffff }, // add:6:0xE281200C
	{  24, 0xe5923100, 0xfdffffff }, // ldr:4:0xE7923100
	{  25, 0xe1530000, 0xfdffffff }, // cmp:7:0xE3530000
	{  26, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A000006
	{  27, 0xe591c100, 0xfdffffff }, // ldr:4:0xE791C100
	{  28, 0xe595e100, 0xfdffffff }, // ldr:4:0xE795E100
	{  30, 0xe003300e, 0xfdffffff }, // and:6:0xE003300E
	{ -1, -1, -1 },
	/* 29/32 */
};

static FuncSig func_sig_kbd_p2_f_1[] = {
	{   1, 0xe04dd018, 0xfdffffff }, // sub:6:0xE24DD018
	{   2, 0xe59f656c, 0xfdffffff }, // ldr:4:0xE59F656C
	{   3, 0xe08d7008, 0xfdffffff }, // add:6:0xE28D7008
	{   4, 0xea000000, 0xff000000 }, // b, bl:3:0xEA00001D
	{   5, 0xe59f1554, 0xfdffffff }, // ldr:4:0xE59F1554
	{   7, 0xe08d3008, 0xfdffffff }, // add:6:0xE28D3008
	{   8, 0xe08d2014, 0xfdffffff }, // add:6:0xE28D2014
	{   9, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB0090FA
	{  10, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{  11, 0x1a000000, 0xff000000 }, // b, bl:3:0x1A00000C
	{  12, 0xe59d0014, 0xfdffffff }, // ldr:4:0xE59D0014
	{  13, 0xe1500102, 0xfdffffff }, // cmp:7:0xE3500102
	{  14, 0x11500000, 0xfdffffff }, // cmp:7:0x13500000
	{  15, 0x11500106, 0xfdffffff }, // cmp:7:0x13500106
	{  16, 0x11500001, 0xfdffffff }, // cmp:7:0x13500001
	{  17, 0x1a000000, 0xff000000 }, // b, bl:3:0x1A000005
	{  18, 0xe59f1514, 0xfdffffff }, // ldr:4:0xE59F1514
	{  19, 0xe5911004, 0xfdffffff }, // ldr:4:0xE5911004
	{  20, 0xe1510000, 0xfdffffff }, // cmp:7:0xE3510000
	{  21, 0x1a000000, 0xff000000 }, // b, bl:3:0x1A000001
	{  22, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB0001B5
	{  23, 0xea000000, 0xff000000 }, // b, bl:3:0xEA000000
	{  24, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB0001A0
	{  25, 0xe1a00002, 0xfdffffff }, // mov:6:0xE3A00002
	{  26, 0xe5971100, 0xfdffffff }, // ldr:4:0xE7971100
	{  27, 0xe1510000, 0xfdffffff }, // cmp:7:0xE3510000
	{  28, 0x15962100, 0xfdffffff }, // ldr:4:0x17962100
	{  30, 0x15861100, 0xfdffffff }, // str:4:0x17861100
	{  31, 0xe0400001, 0xfdffffff }, // sub:6:0xE2400001
	{ -1, -1, -1 },
	/* 29/32 */
};

static FuncSig func_sig_kbd_pwr_on_1[] = {
	{   0, 0xe59f00f8, 0xfdffffff }, // ldr:4:0xE59F00F8
	{   2, 0xe59010e0, 0xfdffffff }, // ldr:4:0xE59010E0
	{   4, 0xe58010e0, 0xfdffffff }, // str:4:0xE58010E0
	{   5, 0xe04f2028, 0xfdffffff }, // sub:6:0xE24F2028
	{   6, 0xe0821000, 0xfdffffff }, // add:6:0xE2821000
	{   7, 0xe1a03000, 0xfdffffff }, // mov:6:0xE3A03000
	{   8, 0xe1a00032, 0xfdffffff }, // mov:6:0xE3A00032
	{   9, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB0081BD
	{  10, 0xe1100001, 0xfdffffff }, // tst:7:0xE3100001
	{  11, 0x11500015, 0xfdffffff }, // cmp:7:0x13500015
	{  12, 0x11a010ec, 0xfdffffff }, // mov:6:0x13A010EC
	{  13, 0x108f00c8, 0xfdffffff }, // add:6:0x128F00C8
	{  14, 0x1b000000, 0xff000000 }, // b, bl:3:0x1BFF53FC
	{  15, 0xe59f00b8, 0xfdffffff }, // ldr:4:0xE59F00B8
	{  16, 0xe59f10c8, 0xfdffffff }, // ldr:4:0xE59F10C8
	{  17, 0xe5900004, 0xfdffffff }, // ldr:4:0xE5900004
	{  19, 0xe1a030ed, 0xfdffffff }, // mov:6:0xE3A030ED
	{  20, 0xe08f20ac, 0xfdffffff }, // add:6:0xE28F20AC
	{  21, 0xea000000, 0xff000000 }, // b, bl:3:0xEAFF53AF
	{  22, 0xe59f00a0, 0xfdffffff }, // ldr:4:0xE59F00A0
	{  23, 0xe59010e0, 0xfdffffff }, // ldr:4:0xE59010E0
	{  25, 0xe58010e0, 0xfdffffff }, // str:4:0xE58010E0
	{  27, 0xe5900000, 0xfdffffff }, // ldr:4:0xE5900000
	{  28, 0xe0000001, 0xfdffffff }, // and:6:0xE2000001
	{  30, 0xe5801000, 0xfdffffff }, // str:4:0xE5801000
	{ -1, -1, -1 },
	/* 25/32 */
};

static FuncSig func_sig_kbd_pwr_off_1[] = {
	{   0, 0xe59f00a0, 0xfdffffff }, // ldr:4:0xE59F00A0
	{   1, 0xe59010e0, 0xfdffffff }, // ldr:4:0xE59010E0
	{   3, 0xe58010e0, 0xfdffffff }, // str:4:0xE58010E0
	{   5, 0xe5900000, 0xfdffffff }, // ldr:4:0xE5900000
	{   6, 0xe0000001, 0xfdffffff }, // and:6:0xE2000001
	{   8, 0xe5801000, 0xfdffffff }, // str:4:0xE5801000
	{  10, 0xe59f0078, 0xfdffffff }, // ldr:4:0xE59F0078
	{  11, 0xe59010e0, 0xfdffffff }, // ldr:4:0xE59010E0
	{  13, 0xe58010e0, 0xfdffffff }, // str:4:0xE58010E0
	{  15, 0xe59f0064, 0xfdffffff }, // ldr:4:0xE59F0064
	{  16, 0xe59010e0, 0xfdffffff }, // ldr:4:0xE59010E0
	{  18, 0xe58010e0, 0xfdffffff }, // str:4:0xE58010E0
	{  21, 0xe1a05000, 0xfdffffff }, // mov:6:0xE1A05000
	{  22, 0xe59f0044, 0xfdffffff }, // ldr:4:0xE59F0044
	{  23, 0xe1a04000, 0xfdffffff }, // mov:6:0xE3A04000
	{  24, 0xe5900000, 0xfdffffff }, // ldr:4:0xE5900000
	{  25, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{  26, 0x11a010c7, 0xfdffffff }, // mov:6:0x13A010C7
	{  27, 0x108f0038, 0xfdffffff }, // add:6:0x128F0038
	{  28, 0x1b000000, 0xff000000 }, // b, bl:3:0x1BFF53D8
	{  29, 0xe59f0040, 0xfdffffff }, // ldr:4:0xE59F0040
	{  30, 0xe1550000, 0xfdffffff }, // cmp:7:0xE3550000
	{  31, 0x0590401c, 0xfdffffff }, // ldr:4:0x0590401C
	{ -1, -1, -1 },
	/* 23/32 */
};

static FuncSig func_sig_kbd_read_keys_r2_1[] = {
	{   1, 0xe1a04000, 0xfdffffff }, // mov:6:0xE1A04000
	{   2, 0xe59f04bc, 0xfdffffff }, // ldr:4:0xE59F04BC
	{   3, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB00016B
	{   4, 0xe51f608c, 0xfdffffff }, // ldr:4:0xE51F608C
	{   5, 0xe1a01000, 0xfdffffff }, // mov:6:0xE1A01000
	{   8, 0xe1a002a0, 0xfdffffff }, // mov:6:0xE1A002A0
	{   9, 0xe5942100, 0xfdffffff }, // ldr:4:0xE7942100
	{  10, 0xe003301f, 0xfdffffff }, // and:6:0xE203301F
	{  12, 0xe5841100, 0xfdffffff }, // str:4:0xE7841100
	{  13, 0xe59f0494, 0xfdffffff }, // ldr:4:0xE59F0494
	{  14, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB000160
	{  15, 0xe1a01000, 0xfdffffff }, // mov:6:0xE1A01000
	{  18, 0xe1a002a0, 0xfdffffff }, // mov:6:0xE1A002A0
	{  19, 0xe5942100, 0xfdffffff }, // ldr:4:0xE7942100
	{  20, 0xe003301f, 0xfdffffff }, // and:6:0xE203301F
	{  22, 0xe5841100, 0xfdffffff }, // str:4:0xE7841100
	{  24, 0xe1a052a0, 0xfdffffff }, // mov:6:0xE1A052A0
	{  25, 0xe1a0000b, 0xfdffffff }, // mov:6:0xE3A0000B
	{  26, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFF67D
	{  28, 0xe050cc01, 0xfdffffff }, // sub:6:0xE250CC01
	{  29, 0x205cc05b, 0xfdffffff }, // sub:6:0x225CC05B
	{  30, 0xe5941105, 0xfdffffff }, // ldr:4:0xE7941105
	{  31, 0x31a00000, 0xfdffffff }, // mov:6:0x33A00000
	{ -1, -1, -1 },
	/* 23/32 */
};

static FuncSig func_sig_mkdir_1[] = {
	{   1, 0xe1a07000, 0xfdffffff }, // mov:6:0xE1A07000
	{   2, 0xe1a01000, 0xfdffffff }, // mov:6:0xE1A01000
	{   3, 0xe1a0000d, 0xfdffffff }, // mov:6:0xE1A0000D
	{   4, 0xe1a06000, 0xfdffffff }, // mov:6:0xE3A06000
	{   5, 0xe1a05000, 0xfdffffff }, // mov:6:0xE3A05000
	{   6, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB0000A2
	{   7, 0xe1a00007, 0xfdffffff }, // mov:6:0xE1A00007
	{   8, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB0000AD
	{   9, 0xe1a08000, 0xfdffffff }, // mov:6:0xE1A08000
	{  10, 0xe1a0000d, 0xfdffffff }, // mov:6:0xE1A0000D
	{  11, 0xe1a02000, 0xfdffffff }, // mov:6:0xE3A02000
	{  12, 0xe1a01001, 0xfdffffff }, // mov:6:0xE3A01001
	{  13, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFD369
	{  14, 0xe0504000, 0xfdffffff }, // sub:6:0xE2504000
	{  15, 0xda000000, 0xff000000 }, // b, bl:3:0xDA000007
	{  16, 0xe1a02008, 0xfdffffff }, // mov:6:0xE1A02008
	{  17, 0xe1a01004, 0xfdffffff }, // mov:6:0xE3A01004
	{  18, 0xe1a00004, 0xfdffffff }, // mov:6:0xE1A00004
	{  19, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFD46D
	{  20, 0xe1a05000, 0xfdffffff }, // mov:6:0xE1A05000
	{  21, 0xe1a00004, 0xfdffffff }, // mov:6:0xE1A00004
	{  22, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFD38C
	{  23, 0xe1a06000, 0xfdffffff }, // mov:6:0xE1A06000
	{  24, 0xe1a0000d, 0xfdffffff }, // mov:6:0xE1A0000D
	{  25, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB0000A0
	{  26, 0xe1540000, 0xfdffffff }, // cmp:7:0xE3540000
	{  27, 0xda000000, 0xff000000 }, // b, bl:3:0xDA000008
	{  28, 0xe1550000, 0xfdffffff }, // cmp:7:0xE3550000
	{  29, 0x01560000, 0xfdffffff }, // cmp:7:0x03560000
	{  30, 0x1a000000, 0xff000000 }, // b, bl:3:0x1A000005
	{  31, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{ -1, -1, -1 },
	/* 31/32 */
};

static FuncSig func_sig_GetParameterData_1[] = {
	{   1, 0xe51f5cfc, 0xfdffffff }, // ldr:4:0xE51F5CFC
	{   2, 0xe1a04000, 0xfdffffff }, // mov:6:0xE1A04000
	{   3, 0xe5950000, 0xfdffffff }, // ldr:4:0xE5950000
	{   4, 0xe59f6260, 0xfdffffff }, // ldr:4:0xE59F6260
	{   5, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{   6, 0xe1a07001, 0xfdffffff }, // mov:6:0xE1A07001
	{   7, 0x059f01e4, 0xfdffffff }, // ldr:4:0x059F01E4
	{   8, 0x01a01006, 0xfdffffff }, // mov:6:0x01A01006
	{   9, 0xe1a08002, 0xfdffffff }, // mov:6:0xE1A08002
	{  10, 0x0b000000, 0xff000000 }, // b, bl:3:0x0BFBBEAC
	{  11, 0xe1140901, 0xfdffffff }, // tst:7:0xE3140901
	{  12, 0x059f01d0, 0xfdffffff }, // ldr:4:0x059F01D0
	{  13, 0x01a01006, 0xfdffffff }, // mov:6:0x01A01006
	{  14, 0x0b000000, 0xff000000 }, // b, bl:3:0x0BFBBEA8
	{  16, 0xe1540072, 0xfdffffff }, // cmp:7:0xE3540072
	{  17, 0x259f01bc, 0xfdffffff }, // ldr:4:0x259F01BC
	{  18, 0x21a01006, 0xfdffffff }, // mov:6:0x21A01006
	{  19, 0x2b000000, 0xff000000 }, // b, bl:3:0x2BFBBEA3
	{  20, 0xe59f3224, 0xfdffffff }, // ldr:4:0xE59F3224
	{  21, 0xe59f21ac, 0xfdffffff }, // ldr:4:0xE59F21AC
	{  22, 0xe51f1d24, 0xfdffffff }, // ldr:4:0xE51F1D24
	{  23, 0xe5950008, 0xfdffffff }, // ldr:4:0xE5950008
	{  24, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFBBE8F
	{  25, 0xe51f0d3c, 0xfdffffff }, // ldr:4:0xE51F0D3C
	{  26, 0xe1a03008, 0xfdffffff }, // mov:6:0xE1A03008
	{  27, 0xe5901004, 0xfdffffff }, // ldr:4:0xE5901004
	{  28, 0xe1a00004, 0xfdffffff }, // mov:6:0xE1A00004
	{  29, 0xe1a02007, 0xfdffffff }, // mov:6:0xE1A02007
	{  30, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB030271
	{  31, 0xe5950008, 0xfdffffff }, // ldr:4:0xE5950008
	{ -1, -1, -1 },
	/* 30/32 */
};

static FuncSig func_sig_SetParameterData_1[] = {
	{   1, 0xe51f5c6c, 0xfdffffff }, // ldr:4:0xE51F5C6C
	{   2, 0xe1a04000, 0xfdffffff }, // mov:6:0xE1A04000
	{   3, 0xe5950000, 0xfdffffff }, // ldr:4:0xE5950000
	{   4, 0xe1a06001, 0xfdffffff }, // mov:6:0xE1A06001
	{   5, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{   6, 0x059f0278, 0xfdffffff }, // ldr:4:0x059F0278
	{   7, 0x01a01ff7, 0xfdffffff }, // mov:6:0x03A01FF7
	{   8, 0xe1a07002, 0xfdffffff }, // mov:6:0xE1A07002
	{   9, 0x0b000000, 0xff000000 }, // b, bl:3:0x0BFBBED1
	{  10, 0xe1140901, 0xfdffffff }, // tst:7:0xE3140901
	{  11, 0x059f0264, 0xfdffffff }, // ldr:4:0x059F0264
	{  12, 0x01a01ff7, 0xfdffffff }, // mov:6:0x03A01FF7
	{  13, 0x0b000000, 0xff000000 }, // b, bl:3:0x0BFBBECD
	{  15, 0xe1540072, 0xfdffffff }, // cmp:7:0xE3540072
	{  16, 0x259f0250, 0xfdffffff }, // ldr:4:0x259F0250
	{  17, 0x21a01ff7, 0xfdffffff }, // mov:6:0x23A01FF7
	{  18, 0x2b000000, 0xff000000 }, // b, bl:3:0x2BFBBEC8
	{  19, 0xe59f32b0, 0xfdffffff }, // ldr:4:0xE59F32B0
	{  20, 0xe59f2240, 0xfdffffff }, // ldr:4:0xE59F2240
	{  21, 0xe51f1c90, 0xfdffffff }, // ldr:4:0xE51F1C90
	{  22, 0xe5950008, 0xfdffffff }, // ldr:4:0xE5950008
	{  23, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFBBEB4
	{  24, 0xe1a03000, 0xfdffffff }, // mov:6:0xE3A03000
	{  25, 0xe1a02001, 0xfdffffff }, // mov:6:0xE3A02001
	{  27, 0xe51f0cb4, 0xfdffffff }, // ldr:4:0xE51F0CB4
	{  28, 0xe1a03007, 0xfdffffff }, // mov:6:0xE1A03007
	{  29, 0xe5901004, 0xfdffffff }, // ldr:4:0xE5901004
	{  30, 0xe1a00004, 0xfdffffff }, // mov:6:0xE1A00004
	{  31, 0xe1a02006, 0xfdffffff }, // mov:6:0xE1A02006
	{ -1, -1, -1 },
	/* 29/32 */
};

static FuncSig func_sig_IsStrobeChargeCompleted_1[] = {
	{   1, 0xe59f33f0, 0xfdffffff }, // ldr:4:0xE59F33F0
	{   2, 0xe51f60cc, 0xfdffffff }, // ldr:4:0xE51F60CC
	{   3, 0xe51f50e4, 0xfdffffff }, // ldr:4:0xE51F50E4
	{   4, 0xe58d3000, 0xfdffffff }, // str:4:0xE58D3000
	{   5, 0xe5950004, 0xfdffffff }, // ldr:4:0xE5950004
	{   6, 0xe04f30ec, 0xfdffffff }, // sub:6:0xE24F30EC
	{   7, 0xe1a04000, 0xfdffffff }, // mov:6:0xE3A04000
	{   8, 0xe1a01004, 0xfdffffff }, // mov:6:0xE3A01004
	{   9, 0xe1a02006, 0xfdffffff }, // mov:6:0xE1A02006
	{  10, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFDD2B1
	{  11, 0xe59f73cc, 0xfdffffff }, // ldr:4:0xE59F73CC
	{  12, 0xe04f3f41, 0xfdffffff }, // sub:6:0xE24F3F41
	{  13, 0xe58d7000, 0xfdffffff }, // str:4:0xE58D7000
	{  14, 0xe5950008, 0xfdffffff }, // ldr:4:0xE5950008
	{  15, 0xe1a02006, 0xfdffffff }, // mov:6:0xE1A02006
	{  16, 0xe1a01003, 0xfdffffff }, // mov:6:0xE3A01003
	{  17, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFDD2B5
	{  18, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{  19, 0x11a01007, 0xfdffffff }, // mov:6:0x11A01007
	{  20, 0x104f0f49, 0xfdffffff }, // sub:6:0x124F0F49
	{  21, 0x1b000000, 0xff000000 }, // b, bl:3:0x1BFDD2D6
	{  22, 0xe5950008, 0xfdffffff }, // ldr:4:0xE5950008
	{  23, 0xe08d1004, 0xfdffffff }, // add:6:0xE28D1004
	{  24, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFE0643
	{  25, 0xe5950008, 0xfdffffff }, // ldr:4:0xE5950008
	{  26, 0xe1a01003, 0xfdffffff }, // mov:6:0xE3A01003
	{  27, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFE0632
	{  28, 0xe59d0004, 0xfdffffff }, // ldr:4:0xE59D0004
	{  29, 0xe1100001, 0xfdffffff }, // tst:7:0xE3100001
	{  30, 0x11a04001, 0xfdffffff }, // mov:6:0x13A04001
	{  31, 0xe1a00004, 0xfdffffff }, // mov:6:0xE1A00004
	{ -1, -1, -1 },
	/* 31/32 */
};

static FuncSig func_sig_open_1[] = {
	{   1, 0xe1a07002, 0xfdffffff }, // mov:6:0xE1A07002
	{   2, 0xe1a06001, 0xfdffffff }, // mov:6:0xE1A06001
	{   3, 0xe1a04000, 0xfdffffff }, // mov:6:0xE1A04000
	{   4, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFFE9C
	{   5, 0xe0505000, 0xfdffffff }, // sub:6:0xE2505000
	{   6, 0xaa000000, 0xff000000 }, // b, bl:3:0xAA000002
	{   7, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFE576
	{   8, 0xe1a01017, 0xfdffffff }, // mov:6:0xE3A01017
	{   9, 0xea000000, 0xff000000 }, // b, bl:3:0xEA000009
	{  10, 0xe08d2008, 0xfdffffff }, // add:6:0xE28D2008
	{  11, 0xe08d1004, 0xfdffffff }, // add:6:0xE28D1004
	{  12, 0xe1a00004, 0xfdffffff }, // mov:6:0xE1A00004
	{  13, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFFFBC
	{  14, 0xe1b04000, 0xfdffffff }, // mov:6:0xE1B04000
	{  15, 0x1a000000, 0xff000000 }, // b, bl:3:0x1A000005
	{  16, 0xe1a00005, 0xfdffffff }, // mov:6:0xE1A00005
	{  17, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFFEB1
	{  18, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFE56B
	{  19, 0xe1a01002, 0xfdffffff }, // mov:6:0xE3A01002
	{  20, 0xe5801000, 0xfdffffff }, // str:4:0xE5801000
	{  21, 0xea000000, 0xff000000 }, // b, bl:3:0xEA00000D
	{  22, 0xe59f0420, 0xfdffffff }, // ldr:4:0xE59F0420
	{  23, 0xe59d1008, 0xfdffffff }, // ldr:4:0xE59D1008
	{  24, 0xe58d5000, 0xfdffffff }, // str:4:0xE58D5000
	{  25, 0xe5900101, 0xfdffffff }, // ldr:4:0xE7900101
	{  26, 0xe59d1004, 0xfdffffff }, // ldr:4:0xE59D1004
	{  27, 0xe590c000, 0xfdffffff }, // ldr:4:0xE590C000
	{  28, 0xe1a00004, 0xfdffffff }, // mov:6:0xE1A00004
	{  29, 0xe1a03007, 0xfdffffff }, // mov:6:0xE1A03007
	{  30, 0xe1a02006, 0xfdffffff }, // mov:6:0xE1A02006
	{ -1, -1, -1 },
	/* 30/32 */
};

static FuncSig func_sig_write_1[] = {
	{   1, 0xe1b04002, 0xfdffffff }, // mov:6:0xE1B04002
	{   2, 0x01a00000, 0xfdffffff }, // mov:6:0x03A00000
	{   3, 0xe1a05001, 0xfdffffff }, // mov:6:0xE1A05001
	{   4, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A000008
	{   5, 0xe1a0200d, 0xfdffffff }, // mov:6:0xE1A0200D
	{   6, 0xe08d1004, 0xfdffffff }, // add:6:0xE28D1004
	{   7, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFFE0F
	{   8, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{   9, 0xaa000000, 0xff000000 }, // b, bl:3:0xAA000004
	{  10, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFE4B5
	{  11, 0xe1a01009, 0xfdffffff }, // mov:6:0xE3A01009
	{  12, 0xe5801000, 0xfdffffff }, // str:4:0xE5801000
	{  15, 0xe59f0144, 0xfdffffff }, // ldr:4:0xE59F0144
	{  16, 0xe59d1004, 0xfdffffff }, // ldr:4:0xE59D1004
	{  17, 0xe1a02004, 0xfdffffff }, // mov:6:0xE1A02004
	{  18, 0xe5900101, 0xfdffffff }, // ldr:4:0xE7900101
	{  19, 0xe1a01005, 0xfdffffff }, // mov:6:0xE1A01005
	{  20, 0xe5903010, 0xfdffffff }, // ldr:4:0xE5903010
	{  21, 0xe59d0000, 0xfdffffff }, // ldr:4:0xE59D0000
	{  25, 0xe1b04003, 0xfdffffff }, // mov:6:0xE1B04003
	{  26, 0x01a00000, 0xfdffffff }, // mov:6:0x03A00000
	{  27, 0xe1a06002, 0xfdffffff }, // mov:6:0xE1A06002
	{  28, 0xe1a05001, 0xfdffffff }, // mov:6:0xE1A05001
	{  29, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A000008
	{  30, 0xe1a0200d, 0xfdffffff }, // mov:6:0xE1A0200D
	{  31, 0xe08d1004, 0xfdffffff }, // add:6:0xE28D1004
	{ -1, -1, -1 },
	/* 26/32 */
};

static FuncSig func_sig_close_1[] = {
	{   1, 0xe1a0200d, 0xfdffffff }, // mov:6:0xE1A0200D
	{   2, 0xe08d1004, 0xfdffffff }, // add:6:0xE28D1004
	{   3, 0xe1a04000, 0xfdffffff }, // mov:6:0xE1A04000
	{   4, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFFEA4
	{   5, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{   6, 0xaa000000, 0xff000000 }, // b, bl:3:0xAA000004
	{   7, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFE54A
	{   8, 0xe1a01009, 0xfdffffff }, // mov:6:0xE3A01009
	{   9, 0xe5801000, 0xfdffffff }, // str:4:0xE5801000
	{  12, 0xe1a00004, 0xfdffffff }, // mov:6:0xE1A00004
	{  13, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFFE89
	{  14, 0xe59f0390, 0xfdffffff }, // ldr:4:0xE59F0390
	{  15, 0xe59d1004, 0xfdffffff }, // ldr:4:0xE59D1004
	{  16, 0xe5900101, 0xfdffffff }, // ldr:4:0xE7900101
	{  17, 0xe1a01004, 0xfdffffff }, // mov:6:0xE1A01004
	{  18, 0xe5902004, 0xfdffffff }, // ldr:4:0xE5902004
	{  19, 0xe59d0000, 0xfdffffff }, // ldr:4:0xE59D0000
	{  23, 0xe1a0200d, 0xfdffffff }, // mov:6:0xE1A0200D
	{  24, 0xe08d1004, 0xfdffffff }, // add:6:0xE28D1004
	{  25, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFFE8F
	{  26, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{  27, 0xaa000000, 0xff000000 }, // b, bl:3:0xAA000003
	{  28, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFE535
	{  29, 0xe1a01009, 0xfdffffff }, // mov:6:0xE3A01009
	{  30, 0xe5801000, 0xfdffffff }, // str:4:0xE5801000
	{  31, 0xea000000, 0xff000000 }, // b, bl:3:0xEA000005
	{ -1, -1, -1 },
	/* 26/32 */
};

static FuncSig func_sig_lseek_1[] = {
	{   1, 0xe1520000, 0xfdffffff }, // cmp:7:0xE3520000
	{   2, 0xe04dd034, 0xfdffffff }, // sub:6:0xE24DD034
	{   3, 0xe1a05000, 0xfdffffff }, // mov:6:0xE1A05000
	{   4, 0xe1a04001, 0xfdffffff }, // mov:6:0xE1A04001
	{   5, 0x1a000000, 0xff000000 }, // b, bl:3:0x1A00000B
	{   6, 0xe1a02004, 0xfdffffff }, // mov:6:0xE1A02004
	{   7, 0xe1a01010, 0xfdffffff }, // mov:6:0xE3A01010
	{   8, 0xe1a00005, 0xfdffffff }, // mov:6:0xE1A00005
	{   9, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFD510
	{  10, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{  11, 0xba000000, 0xff000000 }, // b, bl:3:0xBA000023
	{  12, 0xe1a02000, 0xfdffffff }, // mov:6:0xE3A02000
	{  13, 0xe1a0100f, 0xfdffffff }, // mov:6:0xE3A0100F
	{  14, 0xe1a00005, 0xfdffffff }, // mov:6:0xE1A00005
	{  15, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFD50A
	{  16, 0xe08dd034, 0xfdffffff }, // add:6:0xE28DD034
	{  18, 0xe1520001, 0xfdffffff }, // cmp:7:0xE3520001
	{  19, 0x1a000000, 0xff000000 }, // b, bl:3:0x1A00000F
	{  20, 0xe1a02000, 0xfdffffff }, // mov:6:0xE3A02000
	{  21, 0xe1a0100f, 0xfdffffff }, // mov:6:0xE3A0100F
	{  22, 0xe1a00005, 0xfdffffff }, // mov:6:0xE1A00005
	{  23, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFD502
	{  24, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{  25, 0xba000000, 0xff000000 }, // b, bl:3:0xBA000015
	{  26, 0xe0844000, 0xfdffffff }, // add:6:0xE0844000
	{  27, 0xea000000, 0xff000000 }, // b, bl:3:0xEA000011
	{  28, 0xe1a02004, 0xfdffffff }, // mov:6:0xE1A02004
	{  29, 0xe1a01010, 0xfdffffff }, // mov:6:0xE3A01010
	{  30, 0xe1a00005, 0xfdffffff }, // mov:6:0xE1A00005
	{  31, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFD4FA
	{ -1, -1, -1 },
	/* 30/32 */
};

static FuncSig func_sig_read_1[] = {
	{   1, 0xe1b04002, 0xfdffffff }, // mov:6:0xE1B04002
	{   2, 0x01a00000, 0xfdffffff }, // mov:6:0x03A00000
	{   3, 0xe1a05001, 0xfdffffff }, // mov:6:0xE1A05001
	{   4, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A000008
	{   5, 0xe1a0200d, 0xfdffffff }, // mov:6:0xE1A0200D
	{   6, 0xe08d1004, 0xfdffffff }, // add:6:0xE28D1004
	{   7, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFFE27
	{   8, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{   9, 0xaa000000, 0xff000000 }, // b, bl:3:0xAA000004
	{  10, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFE4CD
	{  11, 0xe1a01009, 0xfdffffff }, // mov:6:0xE3A01009
	{  12, 0xe5801000, 0xfdffffff }, // str:4:0xE5801000
	{  15, 0xe59f01a4, 0xfdffffff }, // ldr:4:0xE59F01A4
	{  16, 0xe59d1004, 0xfdffffff }, // ldr:4:0xE59D1004
	{  17, 0xe1a02004, 0xfdffffff }, // mov:6:0xE1A02004
	{  18, 0xe5900101, 0xfdffffff }, // ldr:4:0xE7900101
	{  19, 0xe1a01005, 0xfdffffff }, // mov:6:0xE1A01005
	{  20, 0xe590300c, 0xfdffffff }, // ldr:4:0xE590300C
	{  21, 0xe59d0000, 0xfdffffff }, // ldr:4:0xE59D0000
	{  25, 0xe1b04002, 0xfdffffff }, // mov:6:0xE1B04002
	{  26, 0x01a00000, 0xfdffffff }, // mov:6:0x03A00000
	{  27, 0xe1a05001, 0xfdffffff }, // mov:6:0xE1A05001
	{  28, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A000008
	{  29, 0xe1a0200d, 0xfdffffff }, // mov:6:0xE1A0200D
	{  30, 0xe08d1004, 0xfdffffff }, // add:6:0xE28D1004
	{  31, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFFE0F
	{ -1, -1, -1 },
	/* 26/32 */
};

static FuncSig func_sig_Fopen_Fut_1[] = {
	{   1, 0xe1a06001, 0xfdffffff }, // mov:6:0xE1A06001
	{   2, 0xe1a01001, 0xfdffffff }, // mov:6:0xE3A01001
	{   3, 0xe1a05000, 0xfdffffff }, // mov:6:0xE1A05000
	{   4, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB0000B3
	{   5, 0xe1a04000, 0xfdffffff }, // mov:6:0xE1A04000
	{   6, 0xe1a00005, 0xfdffffff }, // mov:6:0xE1A00005
	{   7, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB0000D1
	{   8, 0xe1a01006, 0xfdffffff }, // mov:6:0xE1A01006
	{   9, 0xe1a00005, 0xfdffffff }, // mov:6:0xE1A00005
	{  10, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB00B190
	{  11, 0xe1a05000, 0xfdffffff }, // mov:6:0xE1A05000
	{  12, 0xe1a00004, 0xfdffffff }, // mov:6:0xE1A00004
	{  13, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB0000B4
	{  14, 0xe1a00005, 0xfdffffff }, // mov:6:0xE1A00005
	{  17, 0xe1b04000, 0xfdffffff }, // mov:6:0xE1B04000
	{  19, 0xe04dd03c, 0xfdffffff }, // sub:6:0xE24DD03C
	{  20, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A000023
	{  21, 0xe0840020, 0xfdffffff }, // add:6:0xE2840020
	{  22, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFE7A7
	{  23, 0xe1500020, 0xfdffffff }, // cmp:7:0xE3500020
	{  24, 0xd08d5018, 0xfdffffff }, // add:6:0xD28D5018
	{  25, 0xda000000, 0xff000000 }, // b, bl:3:0xDA000002
	{  26, 0xe0800001, 0xfdffffff }, // add:6:0xE2800001
	{  27, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB001355
	{  28, 0xe1a05000, 0xfdffffff }, // mov:6:0xE1A05000
	{  29, 0xe0841020, 0xfdffffff }, // add:6:0xE2841020
	{  30, 0xe1a00005, 0xfdffffff }, // mov:6:0xE1A00005
	{  31, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFE778
	{ -1, -1, -1 },
	/* 28/32 */
};

static FuncSig func_sig_Fwrite_Fut_1[] = {
	{   1, 0xe1b04003, 0xfdffffff }, // mov:6:0xE1B04003
	{   2, 0xe1a06000, 0xfdffffff }, // mov:6:0xE1A06000
	{   4, 0xe1a08002, 0xfdffffff }, // mov:6:0xE1A08002
	{   5, 0xe1a07001, 0xfdffffff }, // mov:6:0xE1A07001
	{   7, 0xe1a01001, 0xfdffffff }, // mov:6:0xE3A01001
	{   8, 0xe0840020, 0xfdffffff }, // add:6:0xE2840020
	{   9, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB00005E
	{  10, 0xe1a05000, 0xfdffffff }, // mov:6:0xE1A05000
	{  11, 0xe1a00006, 0xfdffffff }, // mov:6:0xE1A00006
	{  12, 0xe1a03004, 0xfdffffff }, // mov:6:0xE1A03004
	{  13, 0xe1a02008, 0xfdffffff }, // mov:6:0xE1A02008
	{  14, 0xe1a01007, 0xfdffffff }, // mov:6:0xE1A01007
	{  15, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB00B1DB
	{  16, 0xe1a04000, 0xfdffffff }, // mov:6:0xE1A04000
	{  17, 0xe1a00005, 0xfdffffff }, // mov:6:0xE1A00005
	{  18, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB00005F
	{  19, 0xe1a00004, 0xfdffffff }, // mov:6:0xE1A00004
	{  22, 0xe1b04002, 0xfdffffff }, // mov:6:0xE1B04002
	{  23, 0xe1a06000, 0xfdffffff }, // mov:6:0xE1A06000
	{  24, 0x01a00000, 0xfdffffff }, // mov:6:0x03A00000
	{  25, 0xe1a07001, 0xfdffffff }, // mov:6:0xE1A07001
	{  27, 0xe1a01001, 0xfdffffff }, // mov:6:0xE3A01001
	{  28, 0xe0840020, 0xfdffffff }, // add:6:0xE2840020
	{  29, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB00004A
	{  30, 0xe1a05000, 0xfdffffff }, // mov:6:0xE1A05000
	{  31, 0xe1a00006, 0xfdffffff }, // mov:6:0xE1A00006
	{ -1, -1, -1 },
	/* 26/32 */
};

static FuncSig func_sig_Fclose_Fut_1[] = {
	{   1, 0xe1b04000, 0xfdffffff }, // mov:6:0xE1B04000
	{   3, 0xe04dd03c, 0xfdffffff }, // sub:6:0xE24DD03C
	{   4, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A000023
	{   5, 0xe0840020, 0xfdffffff }, // add:6:0xE2840020
	{   6, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFE7A7
	{   7, 0xe1500020, 0xfdffffff }, // cmp:7:0xE3500020
	{   8, 0xd08d5018, 0xfdffffff }, // add:6:0xD28D5018
	{   9, 0xda000000, 0xff000000 }, // b, bl:3:0xDA000002
	{  10, 0xe0800001, 0xfdffffff }, // add:6:0xE2800001
	{  11, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB001355
	{  12, 0xe1a05000, 0xfdffffff }, // mov:6:0xE1A05000
	{  13, 0xe0841020, 0xfdffffff }, // add:6:0xE2841020
	{  14, 0xe1a00005, 0xfdffffff }, // mov:6:0xE1A00005
	{  15, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFE778
	{  16, 0xe5946008, 0xfdffffff }, // ldr:4:0xE5946008
	{  17, 0xe1a01001, 0xfdffffff }, // mov:6:0xE3A01001
	{  18, 0xe1a00005, 0xfdffffff }, // mov:6:0xE1A00005
	{  19, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB000094
	{  20, 0xe1a07000, 0xfdffffff }, // mov:6:0xE1A07000
	{  21, 0xe1a00005, 0xfdffffff }, // mov:6:0xE1A00005
	{  22, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB0000B2
	{  23, 0xe1a00004, 0xfdffffff }, // mov:6:0xE1A00004
	{  24, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB00B1B4
	{  25, 0xe1560000, 0xfdffffff }, // cmp:7:0xE3560000
	{  26, 0xe1a04000, 0xfdffffff }, // mov:6:0xE1A04000
	{  27, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A000002
	{  28, 0xe1a00005, 0xfdffffff }, // mov:6:0xE1A00005
	{  29, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFFD9F
	{  30, 0xea000000, 0xff000000 }, // b, bl:3:0xEA000002
	{  31, 0xe1a0100d, 0xfdffffff }, // mov:6:0xE1A0100D
	{ -1, -1, -1 },
	/* 30/32 */
};

static FuncSig func_sig_Fread_Fut_1[] = {
	{   1, 0xe1b04003, 0xfdffffff }, // mov:6:0xE1B04003
	{   2, 0xe1a06000, 0xfdffffff }, // mov:6:0xE1A06000
	{   4, 0xe1a08002, 0xfdffffff }, // mov:6:0xE1A08002
	{   5, 0xe1a07001, 0xfdffffff }, // mov:6:0xE1A07001
	{   7, 0xe1a01001, 0xfdffffff }, // mov:6:0xE3A01001
	{   8, 0xe0840020, 0xfdffffff }, // add:6:0xE2840020
	{   9, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB000073
	{  10, 0xe1a05000, 0xfdffffff }, // mov:6:0xE1A05000
	{  11, 0xe1a00006, 0xfdffffff }, // mov:6:0xE1A00006
	{  12, 0xe1a03004, 0xfdffffff }, // mov:6:0xE1A03004
	{  13, 0xe1a02008, 0xfdffffff }, // mov:6:0xE1A02008
	{  14, 0xe1a01007, 0xfdffffff }, // mov:6:0xE1A01007
	{  15, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB00B1A9
	{  16, 0xe1a04000, 0xfdffffff }, // mov:6:0xE1A04000
	{  17, 0xe1a00005, 0xfdffffff }, // mov:6:0xE1A00005
	{  18, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB000074
	{  19, 0xe1a00004, 0xfdffffff }, // mov:6:0xE1A00004
	{  22, 0xe1b04003, 0xfdffffff }, // mov:6:0xE1B04003
	{  23, 0xe1a06000, 0xfdffffff }, // mov:6:0xE1A06000
	{  25, 0xe1a08002, 0xfdffffff }, // mov:6:0xE1A08002
	{  26, 0xe1a07001, 0xfdffffff }, // mov:6:0xE1A07001
	{  28, 0xe1a01001, 0xfdffffff }, // mov:6:0xE3A01001
	{  29, 0xe0840020, 0xfdffffff }, // add:6:0xE2840020
	{  30, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB00005E
	{  31, 0xe1a05000, 0xfdffffff }, // mov:6:0xE1A05000
	{ -1, -1, -1 },
	/* 25/32 */
};

static FuncSig func_sig_Fseek_Fut_1[] = {
	{   1, 0xe1b04000, 0xfdffffff }, // mov:6:0xE1B04000
	{   3, 0xe1a07002, 0xfdffffff }, // mov:6:0xE1A07002
	{   4, 0xe1a06001, 0xfdffffff }, // mov:6:0xE1A06001
	{   6, 0xe1a01001, 0xfdffffff }, // mov:6:0xE3A01001
	{   7, 0xe0840020, 0xfdffffff }, // add:6:0xE2840020
	{   8, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB000037
	{   9, 0xe1a05000, 0xfdffffff }, // mov:6:0xE1A05000
	{  10, 0xe1a00004, 0xfdffffff }, // mov:6:0xE1A00004
	{  11, 0xe1a02007, 0xfdffffff }, // mov:6:0xE1A02007
	{  12, 0xe1a01006, 0xfdffffff }, // mov:6:0xE1A01006
	{  13, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB00B233
	{  14, 0xe1a04000, 0xfdffffff }, // mov:6:0xE1A04000
	{  15, 0xe1a00005, 0xfdffffff }, // mov:6:0xE1A00005
	{  16, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB000039
	{  17, 0xe1a00004, 0xfdffffff }, // mov:6:0xE1A00004
	{  20, 0xe1b04000, 0xfdffffff }, // mov:6:0xE1B04000
	{  23, 0xe1a01001, 0xfdffffff }, // mov:6:0xE3A01001
	{  24, 0xe0840020, 0xfdffffff }, // add:6:0xE2840020
	{  25, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB000026
	{  26, 0xe1a05000, 0xfdffffff }, // mov:6:0xE1A05000
	{  27, 0xe1a00004, 0xfdffffff }, // mov:6:0xE1A00004
	{  28, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB00B234
	{  29, 0xe1a04000, 0xfdffffff }, // mov:6:0xE1A04000
	{  30, 0xe1a00005, 0xfdffffff }, // mov:6:0xE1A00005
	{  31, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB00002A
	{ -1, -1, -1 },
	/* 25/32 */
};

static FuncSig func_sig_Remove_1[] = {
	{   1, 0xe1a05000, 0xfdffffff }, // mov:6:0xE1A05000
	{   2, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFFFF2
	{   3, 0xe1b04000, 0xfdffffff }, // mov:6:0xE1B04000
	{   4, 0x1a000000, 0xff000000 }, // b, bl:3:0x1A000008
	{   5, 0xe1a00005, 0xfdffffff }, // mov:6:0xE1A00005
	{   6, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB00AADC
	{   7, 0xe1a01005, 0xfdffffff }, // mov:6:0xE1A01005
	{   8, 0xe1a0000d, 0xfdffffff }, // mov:6:0xE1A0000D
	{   9, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB000176
	{  10, 0xe1a0000d, 0xfdffffff }, // mov:6:0xE1A0000D
	{  11, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB000185
	{  12, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{  14, 0xe1a00004, 0xfdffffff }, // mov:6:0xE1A00004
	{  17, 0xe1a05000, 0xfdffffff }, // mov:6:0xE1A05000
	{  18, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFFFE2
	{  19, 0xe1b04000, 0xfdffffff }, // mov:6:0xE1B04000
	{  20, 0x01a00005, 0xfdffffff }, // mov:6:0x01A00005
	{  21, 0x0b000000, 0xff000000 }, // b, bl:3:0x0B00AACD
	{  22, 0xe1a00004, 0xfdffffff }, // mov:6:0xE1A00004
	{  24, 0xea000000, 0xff000000 }, // b, bl:3:0xEAFFD4DB
	{  26, 0xe1a06000, 0xfdffffff }, // mov:6:0xE1A06000
	{  27, 0xe1a05002, 0xfdffffff }, // mov:6:0xE1A05002
	{  28, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFD4EF
	{  29, 0xe1500005, 0xfdffffff }, // cmp:7:0xE1500005
	{  30, 0xe1a04000, 0xfdffffff }, // mov:6:0xE1A04000
	{  31, 0x11a00006, 0xfdffffff }, // mov:6:0x11A00006
	{ -1, -1, -1 },
	/* 26/32 */
};

static FuncSig func_sig_rename_1[] = {
	{   1, 0xe1a05001, 0xfdffffff }, // mov:6:0xE1A05001
	{   2, 0xe1a01000, 0xfdffffff }, // mov:6:0xE3A01000
	{   3, 0xe1a02000, 0xfdffffff }, // mov:6:0xE3A02000
	{   4, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFD426
	{   5, 0xe0504000, 0xfdffffff }, // sub:6:0xE2504000
	{   8, 0xe1a02005, 0xfdffffff }, // mov:6:0xE1A02005
	{   9, 0xe1a0100b, 0xfdffffff }, // mov:6:0xE3A0100B
	{  10, 0xe1a00004, 0xfdffffff }, // mov:6:0xE1A00004
	{  11, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFD529
	{  12, 0xe1a05000, 0xfdffffff }, // mov:6:0xE1A05000
	{  13, 0xe1a00004, 0xfdffffff }, // mov:6:0xE1A00004
	{  14, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFD448
	{  15, 0xe1a00005, 0xfdffffff }, // mov:6:0xE1A00005
	{  18, 0xe1a06001, 0xfdffffff }, // mov:6:0xE1A06001
	{  19, 0xe1a05000, 0xfdffffff }, // mov:6:0xE1A05000
	{  20, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFFFEA
	{  21, 0xe1b04000, 0xfdffffff }, // mov:6:0xE1B04000
	{  22, 0x01a01006, 0xfdffffff }, // mov:6:0x01A01006
	{  23, 0x01a00005, 0xfdffffff }, // mov:6:0x01A00005
	{  24, 0x0b000000, 0xff000000 }, // b, bl:3:0x0B00AABD
	{  25, 0xe1a00004, 0xfdffffff }, // mov:6:0xE1A00004
	{  28, 0xe1520000, 0xfdffffff }, // cmp:7:0xE3520000
	{  29, 0xe04dd034, 0xfdffffff }, // sub:6:0xE24DD034
	{  30, 0xe1a05000, 0xfdffffff }, // mov:6:0xE1A05000
	{  31, 0xe1a04001, 0xfdffffff }, // mov:6:0xE1A04001
	{ -1, -1, -1 },
	/* 25/32 */
};

static FuncSig func_sig_GetDrive_ClusterSize_1[] = {
	{   0, 0xe1500001, 0xfdffffff }, // cmp:7:0xE3500001
	{   2, 0xe1a04000, 0xfdffffff }, // mov:6:0xE1A04000
	{   3, 0xa59f0058, 0xfdffffff }, // ldr:4:0xA59F0058
	{   4, 0xa59f1084, 0xfdffffff }, // ldr:4:0xA59F1084
	{   5, 0xab000000, 0xff000000 }, // b, bl:3:0xABFF32EE
	{   6, 0xe1a00017, 0xfdffffff }, // mov:6:0xE3A00017
	{   7, 0xe51f1778, 0xfdffffff }, // ldr:4:0xE51F1778
	{   8, 0xe0000094, 0xfdffffff }, // and:6:0xE0000094 mul:11:0xE0000094
	{   9, 0xe0810100, 0xfdffffff }, // add:6:0xE0810100
	{  10, 0xe5900054, 0xfdffffff }, // ldr:4:0xE5900054
	{  12, 0xea000000, 0xff000000 }, // b, bl:3:0xEA0008E5
	{  13, 0xe1500001, 0xfdffffff }, // cmp:7:0xE3500001
	{  15, 0xe1a04000, 0xfdffffff }, // mov:6:0xE1A04000
	{  16, 0xa59f0024, 0xfdffffff }, // ldr:4:0xA59F0024
	{  17, 0xa1a01e57, 0xfdffffff }, // mov:6:0xA3A01E57
	{  18, 0xab000000, 0xff000000 }, // b, bl:3:0xABFF32E1
	{  19, 0xe1a00017, 0xfdffffff }, // mov:6:0xE3A00017
	{  20, 0xe51f17ac, 0xfdffffff }, // ldr:4:0xE51F17AC
	{  21, 0xe0000094, 0xfdffffff }, // and:6:0xE0000094 mul:11:0xE0000094
	{  22, 0xe0810100, 0xfdffffff }, // add:6:0xE0810100
	{  23, 0xe5900054, 0xfdffffff }, // ldr:4:0xE5900054
	{  25, 0xea000000, 0xff000000 }, // b, bl:3:0xEA0008DC
	{  26, 0x000004c4, 0xfdffffff }, // and:6:0x000004C4
	{  28, 0x000004cf, 0xfdffffff }, // and:6:0x000004CF
	{  29, 0x000004dd, 0xfdffffff }, // and:6:0x000004DD
	{  30, 0x000004f7, 0xfdffffff }, // and:6:0x000004F7
	{ -1, -1, -1 },
	/* 28/32 */
};

static FuncSig func_sig_GetDrive_TotalClusters_1[] = {
	{   0, 0xe1500001, 0xfdffffff }, // cmp:7:0xE3500001
	{   2, 0xe1a04000, 0xfdffffff }, // mov:6:0xE1A04000
	{   3, 0xa59f0024, 0xfdffffff }, // ldr:4:0xA59F0024
	{   4, 0xa1a01e57, 0xfdffffff }, // mov:6:0xA3A01E57
	{   5, 0xab000000, 0xff000000 }, // b, bl:3:0xABFF32E1
	{   6, 0xe1a00017, 0xfdffffff }, // mov:6:0xE3A00017
	{   7, 0xe51f17ac, 0xfdffffff }, // ldr:4:0xE51F17AC
	{   8, 0xe0000094, 0xfdffffff }, // and:6:0xE0000094 mul:11:0xE0000094
	{   9, 0xe0810100, 0xfdffffff }, // add:6:0xE0810100
	{  10, 0xe5900054, 0xfdffffff }, // ldr:4:0xE5900054
	{  12, 0xea000000, 0xff000000 }, // b, bl:3:0xEA0008DC
	{  13, 0x000004c4, 0xfdffffff }, // and:6:0x000004C4
	{  15, 0x000004cf, 0xfdffffff }, // and:6:0x000004CF
	{  16, 0x000004dd, 0xfdffffff }, // and:6:0x000004DD
	{  17, 0x000004f7, 0xfdffffff }, // and:6:0x000004F7
	{  19, 0x000004fd, 0xfdffffff }, // and:6:0x000004FD
	{  21, 0x00005450, 0xfdffffff }, // and:6:0x00005450
	{  22, 0x00000522, 0xfdffffff }, // and:6:0x00000522
	{  23, 0x00000531, 0xfdffffff }, // and:6:0x00000531
	{  24, 0x0000054e, 0xfdffffff }, // and:6:0x0000054E
	{  25, 0x00000554, 0xfdffffff }, // and:6:0x00000554
	{  26, 0x0000055f, 0xfdffffff }, // and:6:0x0000055F
	{  27, 0xe1500001, 0xfdffffff }, // cmp:7:0xE3500001
	{  29, 0xe1a04000, 0xfdffffff }, // mov:6:0xE1A04000
	{  30, 0xa51f0048, 0xfdffffff }, // ldr:4:0xA51F0048
	{  31, 0xa59f12e0, 0xfdffffff }, // ldr:4:0xA59F12E0
	{ -1, -1, -1 },
	/* 27/32 */
};

static FuncSig func_sig_GetDrive_FreeClusters_1[] = {
	{   0, 0xe1500001, 0xfdffffff }, // cmp:7:0xE3500001
	{   2, 0xe1a04000, 0xfdffffff }, // mov:6:0xE1A04000
	{   3, 0xa51f0048, 0xfdffffff }, // ldr:4:0xA51F0048
	{   4, 0xa59f12e0, 0xfdffffff }, // ldr:4:0xA59F12E0
	{   5, 0xab000000, 0xff000000 }, // b, bl:3:0xABFF32C6
	{   6, 0xe1a00017, 0xfdffffff }, // mov:6:0xE3A00017
	{   7, 0xe51f1818, 0xfdffffff }, // ldr:4:0xE51F1818
	{   8, 0xe0000094, 0xfdffffff }, // and:6:0xE0000094 mul:11:0xE0000094
	{   9, 0xe0810100, 0xfdffffff }, // add:6:0xE0810100
	{  10, 0xe5900054, 0xfdffffff }, // ldr:4:0xE5900054
	{  12, 0xea000000, 0xff000000 }, // b, bl:3:0xEA0008C6
	{  13, 0xe1500001, 0xfdffffff }, // cmp:7:0xE3500001
	{  15, 0xe1a04000, 0xfdffffff }, // mov:6:0xE1A04000
	{  16, 0xa51f007c, 0xfdffffff }, // ldr:4:0xA51F007C
	{  17, 0xa59f12b0, 0xfdffffff }, // ldr:4:0xA59F12B0
	{  18, 0xab000000, 0xff000000 }, // b, bl:3:0xABFF32B9
	{  19, 0xe1a00017, 0xfdffffff }, // mov:6:0xE3A00017
	{  20, 0xe51f184c, 0xfdffffff }, // ldr:4:0xE51F184C
	{  21, 0xe0000094, 0xfdffffff }, // and:6:0xE0000094 mul:11:0xE0000094
	{  22, 0xe0810100, 0xfdffffff }, // add:6:0xE0810100
	{  23, 0xe5900054, 0xfdffffff }, // ldr:4:0xE5900054
	{  25, 0xea000000, 0xff000000 }, // b, bl:3:0xEA0008BD
	{  26, 0xe1500001, 0xfdffffff }, // cmp:7:0xE3500001
	{  28, 0xe1a04000, 0xfdffffff }, // mov:6:0xE1A04000
	{  29, 0xa59f1284, 0xfdffffff }, // ldr:4:0xA59F1284
	{  30, 0xa04f0e85, 0xfdffffff }, // sub:6:0xA24F0E85
	{  31, 0xab000000, 0xff000000 }, // b, bl:3:0xABFF32AC
	{ -1, -1, -1 },
	/* 29/32 */
};

static FuncSig func_sig_LockMainPower_1[] = {
	{   1, 0xe59f410c, 0xfdffffff }, // ldr:4:0xE59F410C
	{   2, 0xe5940000, 0xfdffffff }, // ldr:4:0xE5940000
	{   3, 0xe1500001, 0xfdffffff }, // cmp:7:0xE3500001
	{   4, 0x11a010c1, 0xfdffffff }, // mov:6:0x13A010C1
	{   5, 0x108f0f41, 0xfdffffff }, // add:6:0x128F0F41
	{   6, 0x1b000000, 0xff000000 }, // b, bl:3:0x1BFEC043
	{   7, 0xe59f1108, 0xfdffffff }, // ldr:4:0xE59F1108
	{   8, 0xe5940024, 0xfdffffff }, // ldr:4:0xE5940024
	{   9, 0xe1a030c3, 0xfdffffff }, // mov:6:0xE3A030C3
	{  10, 0xe08f20f0, 0xfdffffff }, // add:6:0xE28F20F0
	{  11, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFEC02F
	{  12, 0xe5940018, 0xfdffffff }, // ldr:4:0xE5940018
	{  13, 0xe0800001, 0xfdffffff }, // add:6:0xE2800001
	{  14, 0xe1500001, 0xfdffffff }, // cmp:7:0xE3500001
	{  15, 0xe5840018, 0xfdffffff }, // str:4:0xE5840018
	{  16, 0x05940028, 0xfdffffff }, // ldr:4:0x05940028
	{  17, 0x01a01000, 0xfdffffff }, // mov:6:0x03A01000
	{  18, 0x0b000000, 0xff000000 }, // b, bl:3:0x0BFFFB41
	{  19, 0xe1a00001, 0xfdffffff }, // mov:6:0xE3A00001
	{  20, 0xe5840008, 0xfdffffff }, // str:4:0xE5840008
	{  21, 0xe5940004, 0xfdffffff }, // ldr:4:0xE5940004
	{  22, 0xe1500001, 0xfdffffff }, // cmp:7:0xE3500001
	{  23, 0x01a00000, 0xfdffffff }, // mov:6:0x03A00000
	{  24, 0x05840004, 0xfdffffff }, // str:4:0x05840004
	{  25, 0x0b000000, 0xff000000 }, // b, bl:3:0x0B00005B
	{  26, 0xe5940024, 0xfdffffff }, // ldr:4:0xE5940024
	{  28, 0xea000000, 0xff000000 }, // b, bl:3:0xEAFEF529
	{  30, 0xe59f4098, 0xfdffffff }, // ldr:4:0xE59F4098
	{  31, 0xe1a05000, 0xfdffffff }, // mov:6:0xE1A05000
	{ -1, -1, -1 },
	/* 29/32 */
};

static FuncSig func_sig_UnlockMainPower_1[] = {
	{   1, 0xe59f41b8, 0xfdffffff }, // ldr:4:0xE59F41B8
	{   2, 0xe5940000, 0xfdffffff }, // ldr:4:0xE5940000
	{   3, 0xe1500001, 0xfdffffff }, // cmp:7:0xE3500001
	{   4, 0x11a010d4, 0xfdffffff }, // mov:6:0x13A010D4
	{   5, 0x108f0e1b, 0xfdffffff }, // add:6:0x128F0E1B
	{   6, 0x1b000000, 0xff000000 }, // b, bl:3:0x1BFEC06E
	{   7, 0xe5940018, 0xfdffffff }, // ldr:4:0xE5940018
	{   8, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{  10, 0xe5940024, 0xfdffffff }, // ldr:4:0xE5940024
	{  11, 0xe59f11a4, 0xfdffffff }, // ldr:4:0xE59F11A4
	{  12, 0xe1a030d9, 0xfdffffff }, // mov:6:0xE3A030D9
	{  13, 0xe08f2e19, 0xfdffffff }, // add:6:0xE28F2E19
	{  14, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFEC057
	{  15, 0xe5940018, 0xfdffffff }, // ldr:4:0xE5940018
	{  16, 0xe0500001, 0xfdffffff }, // sub:6:0xE2500001
	{  17, 0xe5840018, 0xfdffffff }, // str:4:0xE5840018
	{  18, 0x1a000000, 0xff000000 }, // b, bl:3:0x1A000014
	{  19, 0xe1a00000, 0xfdffffff }, // mov:6:0xE3A00000
	{  20, 0xe5840008, 0xfdffffff }, // str:4:0xE5840008
	{  21, 0xe594002c, 0xfdffffff }, // ldr:4:0xE594002C
	{  22, 0xe1a01000, 0xfdffffff }, // mov:6:0xE3A01000
	{  23, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFFB67
	{  24, 0xe594000c, 0xfdffffff }, // ldr:4:0xE594000C
	{  25, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{  26, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A00000C
	{  27, 0xe5940010, 0xfdffffff }, // ldr:4:0xE5940010
	{  28, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{  29, 0x1a000000, 0xff000000 }, // b, bl:3:0x1A000009
	{  30, 0xe1a00001, 0xfdffffff }, // mov:6:0xE3A00001
	{  31, 0xe5840004, 0xfdffffff }, // str:4:0xE5840004
	{ -1, -1, -1 },
	/* 30/32 */
};

static FuncSig func_sig_GetCurrentAvValue_1[] = {
	{   0, 0xe51f093c, 0xfdffffff }, // ldr:4:0xE51F093C
	{   2, 0xe5900000, 0xfdffffff }, // ldr:4:0xE5900000
	{   3, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{   4, 0x059f154c, 0xfdffffff }, // ldr:4:0x059F154C
	{   5, 0x059f0514, 0xfdffffff }, // ldr:4:0x059F0514
	{   6, 0x0b000000, 0xff000000 }, // b, bl:3:0x0BFC30F4
	{   7, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB032C91
	{   8, 0xe1a04000, 0xfdffffff }, // mov:6:0xE1A04000
	{   9, 0xe08d0004, 0xfdffffff }, // add:6:0xE28D0004
	{  10, 0xe1a0100d, 0xfdffffff }, // mov:6:0xE1A0100D
	{  11, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB032E24
	{  13, 0xe1540000, 0xfdffffff }, // cmp:7:0xE1540000
	{  14, 0xb1a04000, 0xfdffffff }, // mov:6:0xB1A04000
	{  16, 0xe1540000, 0xfdffffff }, // cmp:7:0xE1540000
	{  17, 0xc1a04000, 0xfdffffff }, // mov:6:0xC1A04000
	{  18, 0xe1a00004, 0xfdffffff }, // mov:6:0xE1A00004
	{  19, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB032E75
	{  20, 0xe1a04000, 0xfdffffff }, // mov:6:0xE1A04000
	{  21, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB000CB6
	{  22, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB032DB4
	{  23, 0xe0840000, 0xfdffffff }, // add:6:0xE0840000
	{  24, 0xe1a00800, 0xfdffffff }, // mov:6:0xE1A00800
	{  25, 0xe1a00840, 0xfdffffff }, // mov:6:0xE1A00840
	{  28, 0xe1a07002, 0xfdffffff }, // mov:6:0xE1A07002
	{  29, 0xe1a05001, 0xfdffffff }, // mov:6:0xE1A05001
	{  30, 0xe1a04000, 0xfdffffff }, // mov:6:0xE1A04000
	{  31, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB000CAC
	{ -1, -1, -1 },
	/* 27/32 */
};

static FuncSig func_sig_MoveFocusLensToDistance_1[] = {
	{   1, 0xe59f5218, 0xfdffffff }, // ldr:4:0xE59F5218
	{   2, 0xe5904000, 0xfdffffff }, // ldr:4:0xE5904000
	{   3, 0xe5950000, 0xfdffffff }, // ldr:4:0xE5950000
	{   4, 0xe1a01001, 0xfdffffff }, // mov:6:0xE3A01001
	{   5, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBF9CA23
	{   6, 0xe1a02000, 0xfdffffff }, // mov:6:0xE3A02000
	{   7, 0xe04f1fb6, 0xfdffffff }, // sub:6:0xE24F1FB6
	{   8, 0xe1a00004, 0xfdffffff }, // mov:6:0xE1A00004
	{   9, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFFFF0
	{  10, 0xe5950000, 0xfdffffff }, // ldr:4:0xE5950000
	{  12, 0xe1a02000, 0xfdffffff }, // mov:6:0xE3A02000
	{  13, 0xe1a01001, 0xfdffffff }, // mov:6:0xE3A01001
	{  14, 0xea000000, 0xff000000 }, // b, bl:3:0xEAF9C9B2
	{  16, 0xe59f41dc, 0xfdffffff }, // ldr:4:0xE59F41DC
	{  17, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{  18, 0x004f0fca, 0xfdffffff }, // sub:6:0x024F0FCA
	{  20, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFD5A77
	{  21, 0xe584000c, 0xfdffffff }, // str:4:0xE584000C
	{  23, 0xe1a02000, 0xfdffffff }, // mov:6:0xE3A02000
	{  24, 0xe04f1fcf, 0xfdffffff }, // sub:6:0xE24F1FCF
	{  25, 0xea000000, 0xff000000 }, // b, bl:3:0xEAFD5ACB
	{  27, 0xe59f41b0, 0xfdffffff }, // ldr:4:0xE59F41B0
	{  28, 0xe1a01001, 0xfdffffff }, // mov:6:0xE3A01001
	{  29, 0xe5940000, 0xfdffffff }, // ldr:4:0xE5940000
	{  30, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBF9CA0A
	{  31, 0xe1a01000, 0xfdffffff }, // mov:6:0xE3A01000
	{ -1, -1, -1 },
	/* 26/32 */
};

static FuncSig func_sig_MoveZoomLensWithPoint_1[] = {
	{   2, 0xe1a02000, 0xfdffffff }, // mov:6:0xE3A02000
	{   3, 0xe04f10cc, 0xfdffffff }, // sub:6:0xE24F10CC
	{   4, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFFD5E
	{   5, 0xe51f0c78, 0xfdffffff }, // ldr:4:0xE51F0C78
	{   6, 0xe59f2148, 0xfdffffff }, // ldr:4:0xE59F2148
	{   7, 0xe59f11b0, 0xfdffffff }, // ldr:4:0xE59F11B0
	{   8, 0xe5900044, 0xfdffffff }, // ldr:4:0xE5900044
	{   9, 0xe1a03e36, 0xfdffffff }, // mov:6:0xE3A03E36
	{  10, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFC2132
	{  11, 0xe1100001, 0xfdffffff }, // tst:7:0xE3100001
	{  13, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFD0EEF
	{  14, 0xe1b00a20, 0xfdffffff }, // mov:6:0xE1B00A20
	{  19, 0xe1a02000, 0xfdffffff }, // mov:6:0xE3A02000
	{  20, 0xe04f1e11, 0xfdffffff }, // sub:6:0xE24F1E11
	{  21, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFFF1A
	{  22, 0xe59f3180, 0xfdffffff }, // ldr:4:0xE59F3180
	{  23, 0xe04f2ecb, 0xfdffffff }, // sub:6:0xE24F2ECB
	{  24, 0xe59f116c, 0xfdffffff }, // ldr:4:0xE59F116C
	{  25, 0xe51f0cc8, 0xfdffffff }, // ldr:4:0xE51F0CC8
	{  26, 0xe5900044, 0xfdffffff }, // ldr:4:0xE5900044
	{  27, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFC2121
	{  28, 0xe1100001, 0xfdffffff }, // tst:7:0xE3100001
	{  30, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFD0EDE
	{  31, 0xe1b00a20, 0xfdffffff }, // mov:6:0xE1B00A20
	{ -1, -1, -1 },
	/* 24/32 */
};

static FuncSig func_sig__log_1[] = {
	{   2, 0xe04dd028, 0xfdffffff }, // sub:6:0xE24DD028
	{   3, 0xe08d1028, 0xfdffffff }, // add:6:0xE28D1028
	{   4, 0xe59f3378, 0xfdffffff }, // ldr:4:0xE59F3378
	{   6, 0xe1a04000, 0xfdffffff }, // mov:6:0xE3A04000
	{   7, 0xe1510003, 0xfdffffff }, // cmp:7:0xE1510003
	{   8, 0xaa000000, 0xff000000 }, // b, bl:3:0xAA000006
	{  10, 0xe1520003, 0xfdffffff }, // cmp:7:0xE1520003
	{  11, 0x8a000000, 0xff000000 }, // b, bl:3:0x8A000003
	{  12, 0xe1520003, 0xfdffffff }, // cmp:7:0xE1520003
	{  13, 0x1a000000, 0xff000000 }, // b, bl:3:0x1A000008
	{  14, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{  15, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A000006
	{  16, 0xe08d1028, 0xfdffffff }, // add:6:0xE28D1028
	{  17, 0xe1a02001, 0xfdffffff }, // mov:6:0xE3A02001
	{  19, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB0007C5
	{  20, 0xe08dd030, 0xfdffffff }, // add:6:0xE28DD030
	{  23, 0xe1510601, 0xfdffffff }, // cmp:7:0xE3510601
	{  24, 0xaa000000, 0xff000000 }, // b, bl:3:0xAA000013
	{  26, 0x1a000000, 0xff000000 }, // b, bl:3:0x1A000003
	{  27, 0xe1a00001, 0xfdffffff }, // mov:6:0xE3A00001
	{  28, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFFFDD
	{  29, 0xe08f1fc6, 0xfdffffff }, // add:6:0xE28F1FC6
	{  30, 0xea000000, 0xff000000 }, // b, bl:3:0xEA000004
	{  31, 0xe1510000, 0xfdffffff }, // cmp:7:0xE3510000
	{ -1, -1, -1 },
	/* 24/32 */
};

static FuncSig func_sig__log10_1[] = {
	{   2, 0xe59f3134, 0xfdffffff }, // ldr:4:0xE59F3134
	{   4, 0xe1a04000, 0xfdffffff }, // mov:6:0xE3A04000
	{   5, 0xe1510003, 0xfdffffff }, // cmp:7:0xE1510003
	{   6, 0xaa000000, 0xff000000 }, // b, bl:3:0xAA000006
	{   8, 0xe1520003, 0xfdffffff }, // cmp:7:0xE1520003
	{   9, 0x8a000000, 0xff000000 }, // b, bl:3:0x8A000003
	{  10, 0xe1520003, 0xfdffffff }, // cmp:7:0xE1520003
	{  11, 0x1a000000, 0xff000000 }, // b, bl:3:0x1A000006
	{  12, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{  13, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A000004
	{  15, 0xe1a02001, 0xfdffffff }, // mov:6:0xE3A02001
	{  16, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB000BF7
	{  19, 0xe1510601, 0xfdffffff }, // cmp:7:0xE3510601
	{  20, 0xaa000000, 0xff000000 }, // b, bl:3:0xAA000011
	{  22, 0x1a000000, 0xff000000 }, // b, bl:3:0x1A000003
	{  23, 0xe1a00001, 0xfdffffff }, // mov:6:0xE3A00001
	{  24, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB000410
	{  25, 0xe08f10dc, 0xfdffffff }, // add:6:0xE28F10DC
	{  26, 0xea000000, 0xff000000 }, // b, bl:3:0xEA000004
	{  27, 0xe1510000, 0xfdffffff }, // cmp:7:0xE3510000
	{  28, 0xaa000000, 0xff000000 }, // b, bl:3:0xAA000004
	{  29, 0xe1a00001, 0xfdffffff }, // mov:6:0xE3A00001
	{  30, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB00040A
	{  31, 0xe08f10cc, 0xfdffffff }, // add:6:0xE28F10CC
	{ -1, -1, -1 },
	/* 24/32 */
};

static FuncSig func_sig__pow_1[] = {
	{   2, 0xe59f4358, 0xfdffffff }, // ldr:4:0xE59F4358
	{   4, 0xe04dd0a8, 0xfdffffff }, // sub:6:0xE24DD0A8
	{   5, 0xe59d30ac, 0xfdffffff }, // ldr:4:0xE59D30AC
	{   6, 0xe59d10b4, 0xfdffffff }, // ldr:4:0xE59D10B4
	{   7, 0xe59de0b0, 0xfdffffff }, // ldr:4:0xE59DE0B0
	{   9, 0xe59da0a8, 0xfdffffff }, // ldr:4:0xE59DA0A8
	{  10, 0xe1500004, 0xfdffffff }, // cmp:7:0xE1500004
	{  12, 0xca000000, 0xff000000 }, // b, bl:3:0xCA00000A
	{  13, 0xe1500004, 0xfdffffff }, // cmp:7:0xE1500004
	{  14, 0x1a000000, 0xff000000 }, // b, bl:3:0x1A000001
	{  15, 0xe15a0000, 0xfdffffff }, // cmp:7:0xE35A0000
	{  16, 0x1a000000, 0xff000000 }, // b, bl:3:0x1A000006
	{  17, 0xe1520004, 0xfdffffff }, // cmp:7:0xE1520004
	{  18, 0xca000000, 0xff000000 }, // b, bl:3:0xCA000004
	{  19, 0xe082c209, 0xfdffffff }, // add:6:0xE282C209
	{  20, 0xe05cc6ff, 0xfdffffff }, // sub:6:0xE25CC6FF
	{  21, 0x1a000000, 0xff000000 }, // b, bl:3:0x1A000007
	{  22, 0xe15e0000, 0xfdffffff }, // cmp:7:0xE35E0000
	{  23, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A000005
	{  24, 0xe08d30a8, 0xfdffffff }, // add:6:0xE28D30A8
	{  26, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB000546
	{  27, 0xe08dd0b8, 0xfdffffff }, // add:6:0xE28DD0B8
	{  30, 0xe59d40ac, 0xfdffffff }, // ldr:4:0xE59D40AC
	{  31, 0xe59d50a8, 0xfdffffff }, // ldr:4:0xE59D50A8
	{ -1, -1, -1 },
	/* 24/32 */
};

static FuncSig func_sig__sqrt_1[] = {
	{   0, 0xe1a0c207, 0xfdffffff }, // mov:6:0xE3A0C207
	{   2, 0xe111000c, 0xfdffffff }, // tst:7:0xE111000C
	{   4, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A000044
	{   6, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A000047
	{   7, 0xe1110102, 0xfdffffff }, // tst:7:0xE3110102
	{   8, 0x1a000000, 0xff000000 }, // b, bl:3:0x1A00004D
	{   9, 0xe1a0ca21, 0xfdffffff }, // mov:6:0xE1A0CA21
	{  12, 0xe08cc0fd, 0xfdffffff }, // add:6:0xE28CC0FD
	{  13, 0xe1b0c0ac, 0xfdffffff }, // mov:6:0xE1B0C0AC
	{  14, 0xe08ccd06, 0xfdffffff }, // add:6:0xE28CCD06
	{  15, 0x3a000000, 0xff000000 }, // b, bl:3:0x3A000001
	{  16, 0xe1b00080, 0xfdffffff }, // mov:6:0xE1B00080
	{  18, 0xe1a01501, 0xfdffffff }, // mov:6:0xE1A01501
	{  20, 0xe0411101, 0xfdffffff }, // sub:6:0xE2411101
	{  21, 0xe1a00500, 0xfdffffff }, // mov:6:0xE1A00500
	{  22, 0xe1a02101, 0xfdffffff }, // mov:6:0xE3A02101
	{  23, 0xe1a03000, 0xfdffffff }, // mov:6:0xE3A03000
	{  24, 0xe1a0e201, 0xfdffffff }, // mov:6:0xE3A0E201
	{  25, 0xe0514002, 0xfdffffff }, // sub:6:0xE0514002
	{  26, 0x2054400e, 0xfdffffff }, // sub:6:0x2054400E
	{  27, 0x21a01004, 0xfdffffff }, // mov:6:0x21A01004
	{  28, 0x2082208e, 0xfdffffff }, // add:6:0x2082208E
	{  29, 0xe1b00080, 0xfdffffff }, // mov:6:0xE1B00080
	{  31, 0xe1b0e0ae, 0xfdffffff }, // mov:6:0xE1B0E0AE
	{ -1, -1, -1 },
	/* 24/32 */
};

static FuncSig func_sig_malloc_1[] = {
	{   1, 0xe0800007, 0xfdffffff }, // add:6:0xE2800007
	{   3, 0x1a000000, 0xff000000 }, // b, bl:3:0x1A000001
	{   4, 0xe1a00000, 0xfdffffff }, // mov:6:0xE3A00000
	{   6, 0xe59f6184, 0xfdffffff }, // ldr:4:0xE59F6184
	{   7, 0xe1a01000, 0xfdffffff }, // mov:6:0xE3A01000
	{   8, 0xe5960014, 0xfdffffff }, // ldr:4:0xE5960014
	{   9, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFFA6A
	{  10, 0xe5964010, 0xfdffffff }, // ldr:4:0xE5964010
	{  11, 0xe0860008, 0xfdffffff }, // add:6:0xE2860008
	{  12, 0xea000000, 0xff000000 }, // b, bl:3:0xEA000022
	{  13, 0xe5941004, 0xfdffffff }, // ldr:4:0xE5941004
	{  14, 0xe1510005, 0xfdffffff }, // cmp:7:0xE1510005
	{  15, 0x3a000000, 0xff000000 }, // b, bl:3:0x3A00001D
	{  16, 0xe5941004, 0xfdffffff }, // ldr:4:0xE5941004
	{  17, 0xe0411005, 0xfdffffff }, // sub:6:0xE0411005
	{  18, 0xe151000c, 0xfdffffff }, // cmp:7:0xE351000C
	{  19, 0x35941008, 0xfdffffff }, // ldr:4:0x35941008
	{  20, 0x35801008, 0xfdffffff }, // str:4:0x35801008
	{  21, 0x3a000000, 0xff000000 }, // b, bl:3:0x3A000009
	{  22, 0xe0841005, 0xfdffffff }, // add:6:0xE0841005
	{  23, 0xe0811008, 0xfdffffff }, // add:6:0xE2811008
	{  24, 0xe5801008, 0xfdffffff }, // str:4:0xE5801008
	{  25, 0xe5940008, 0xfdffffff }, // ldr:4:0xE5940008
	{  26, 0xe5810008, 0xfdffffff }, // str:4:0xE5810008
	{  27, 0xe5940004, 0xfdffffff }, // ldr:4:0xE5940004
	{  28, 0xe0400005, 0xfdffffff }, // sub:6:0xE0400005
	{  29, 0xe0400008, 0xfdffffff }, // sub:6:0xE2400008
	{  30, 0xe5810004, 0xfdffffff }, // str:4:0xE5810004
	{  31, 0xe5845004, 0xfdffffff }, // str:4:0xE5845004
	{ -1, -1, -1 },
	/* 29/32 */
};

static FuncSig func_sig_free_1[] = {
	{   1, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{   3, 0xe0404008, 0xfdffffff }, // sub:6:0xE2404008
	{   4, 0xe59f50b8, 0xfdffffff }, // ldr:4:0xE59F50B8
	{   5, 0xe1a01000, 0xfdffffff }, // mov:6:0xE3A01000
	{   6, 0xe5950014, 0xfdffffff }, // ldr:4:0xE5950014
	{   7, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFFA37
	{   8, 0xe5950020, 0xfdffffff }, // ldr:4:0xE5950020
	{   9, 0xe5941004, 0xfdffffff }, // ldr:4:0xE5941004
	{  10, 0xe0400001, 0xfdffffff }, // sub:6:0xE0400001
	{  11, 0xe5850020, 0xfdffffff }, // str:4:0xE5850020
	{  12, 0xe5950028, 0xfdffffff }, // ldr:4:0xE5950028
	{  13, 0xe0400001, 0xfdffffff }, // sub:6:0xE2400001
	{  14, 0xe5850028, 0xfdffffff }, // str:4:0xE5850028
	{  15, 0xe5951010, 0xfdffffff }, // ldr:4:0xE5951010
	{  16, 0xe0850008, 0xfdffffff }, // add:6:0xE2850008
	{  17, 0xea000000, 0xff000000 }, // b, bl:3:0xEA00001D
	{  18, 0xe1510004, 0xfdffffff }, // cmp:7:0xE1510004
	{  19, 0x9a000000, 0xff000000 }, // b, bl:3:0x9A000019
	{  20, 0xe5841008, 0xfdffffff }, // str:4:0xE5841008
	{  21, 0xe5942004, 0xfdffffff }, // ldr:4:0xE5942004
	{  22, 0xe0823004, 0xfdffffff }, // add:6:0xE0823004
	{  23, 0xe0833008, 0xfdffffff }, // add:6:0xE2833008
	{  24, 0xe1530001, 0xfdffffff }, // cmp:7:0xE1530001
	{  25, 0x1a000000, 0xff000000 }, // b, bl:3:0x1A000005
	{  26, 0xe5913004, 0xfdffffff }, // ldr:4:0xE5913004
	{  27, 0xe0822003, 0xfdffffff }, // add:6:0xE0822003
	{  28, 0xe0822008, 0xfdffffff }, // add:6:0xE2822008
	{  29, 0xe5842004, 0xfdffffff }, // str:4:0xE5842004
	{  30, 0xe5911008, 0xfdffffff }, // ldr:4:0xE5911008
	{  31, 0xe5841008, 0xfdffffff }, // str:4:0xE5841008
	{ -1, -1, -1 },
	/* 30/32 */
};

static FuncSig func_sig_FreeUncacheableMemory_1[] = {
	{   0, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{   1, 0x10400020, 0xfdffffff }, // sub:6:0x12400020
	{   3, 0x1a000000, 0xff000000 }, // b, bl:3:0x1AFFFFC3
	{   6, 0xe1a05000, 0xfdffffff }, // mov:6:0xE1A05000
	{   7, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFFFEA
	{   8, 0xe1b04000, 0xfdffffff }, // mov:6:0xE1B04000
	{   9, 0x1a000000, 0xff000000 }, // b, bl:3:0x1A000005
	{  10, 0xe1a01005, 0xfdffffff }, // mov:6:0xE1A01005
	{  11, 0xe08f0014, 0xfdffffff }, // add:6:0xE28F0014
	{  12, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFF9F47
	{  13, 0xe1a01059, 0xfdffffff }, // mov:6:0xE3A01059
	{  14, 0xe08f0014, 0xfdffffff }, // add:6:0xE28F0014
	{  15, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFC9F6
	{  16, 0xe1a00004, 0xfdffffff }, // mov:6:0xE1A00004
	{  20, 0x00000064, 0xfdffffff }, // and:6:0x00000064
	{  22, 0x00632e65, 0xfdffffff }, // rsb:6:0x00632E65
	{  24, 0xe590200c, 0xfdffffff }, // ldr:4:0xE590200C
	{  25, 0xe1a04000, 0xfdffffff }, // mov:6:0xE1A04000
	{  26, 0xe59f0498, 0xfdffffff }, // ldr:4:0xE59F0498
	{  27, 0xe1a01014, 0xfdffffff }, // mov:6:0xE3A01014
	{  28, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB00EADD
	{  29, 0xe5940004, 0xfdffffff }, // ldr:4:0xE5940004
	{  30, 0xe5941000, 0xfdffffff }, // ldr:4:0xE5941000
	{  31, 0xe5810004, 0xfdffffff }, // str:4:0xE5810004
	{ -1, -1, -1 },
	/* 24/32 */
};

static FuncSig func_sig_AllocateUncacheableMemory_1[] = {
	{   1, 0xe1a05000, 0xfdffffff }, // mov:6:0xE1A05000
	{   2, 0xe0800040, 0xfdffffff }, // add:6:0xE2800040
	{   3, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFFFCF
	{   4, 0xe1b04000, 0xfdffffff }, // mov:6:0xE1B04000
	{   6, 0xe0852040, 0xfdffffff }, // add:6:0xE2852040
	{   7, 0xe1a01004, 0xfdffffff }, // mov:6:0xE1A01004
	{   8, 0xe1a00001, 0xfdffffff }, // mov:6:0xE3A00001
	{   9, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFF9BDB
	{  11, 0xe0800020, 0xfdffffff }, // add:6:0xE2800020
	{  13, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{  14, 0x10400020, 0xfdffffff }, // sub:6:0x12400020
	{  16, 0x1a000000, 0xff000000 }, // b, bl:3:0x1AFFFFC3
	{  19, 0xe1a05000, 0xfdffffff }, // mov:6:0xE1A05000
	{  20, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFFFEA
	{  21, 0xe1b04000, 0xfdffffff }, // mov:6:0xE1B04000
	{  22, 0x1a000000, 0xff000000 }, // b, bl:3:0x1A000005
	{  23, 0xe1a01005, 0xfdffffff }, // mov:6:0xE1A01005
	{  24, 0xe08f0014, 0xfdffffff }, // add:6:0xE28F0014
	{  25, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFF9F47
	{  26, 0xe1a01059, 0xfdffffff }, // mov:6:0xE3A01059
	{  27, 0xe08f0014, 0xfdffffff }, // add:6:0xE28F0014
	{  28, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFC9F6
	{  29, 0xe1a00004, 0xfdffffff }, // mov:6:0xE1A00004
	{ -1, -1, -1 },
	/* 23/32 */
};

static FuncSig func_sig_rand_1[] = {
	{   1, 0xe59f4064, 0xfdffffff }, // ldr:4:0xE59F4064
	{   2, 0xe1a01000, 0xfdffffff }, // mov:6:0xE3A01000
	{   3, 0xe5940004, 0xfdffffff }, // ldr:4:0xE5940004
	{   4, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFCE68
	{   5, 0xe5940000, 0xfdffffff }, // ldr:4:0xE5940000
	{   6, 0xe59f1054, 0xfdffffff }, // ldr:4:0xE59F1054
	{   7, 0xe0000091, 0xfdffffff }, // and:6:0xE0000091 mul:11:0xE0000091
	{   9, 0xe0800a03, 0xfdffffff }, // add:6:0xE2800A03
	{  10, 0xe0800039, 0xfdffffff }, // add:6:0xE2800039
	{  11, 0xe0015820, 0xfdffffff }, // and:6:0xE0015820
	{  12, 0xe5840000, 0xfdffffff }, // str:4:0xE5840000
	{  13, 0xe5940004, 0xfdffffff }, // ldr:4:0xE5940004
	{  14, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFCE51
	{  15, 0xe1a00005, 0xfdffffff }, // mov:6:0xE1A00005
	{  18, 0xe08f2028, 0xfdffffff }, // add:6:0xE28F2028
	{  19, 0xe1a01002, 0xfdffffff }, // mov:6:0xE3A01002
	{  20, 0xe1a00001, 0xfdffffff }, // mov:6:0xE3A00001
	{  21, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFCDE8
	{  22, 0xe59f1010, 0xfdffffff }, // ldr:4:0xE59F1010
	{  24, 0xe5810004, 0xfdffffff }, // str:4:0xE5810004
	{  26, 0x11a00000, 0xfdffffff }, // mov:6:0x13A00000
	{  28, 0x00001bf0, 0xfdffffff }, // and:6:0x00001BF0
	{  31, 0x006d6553, 0xfdffffff }, // rsb:6:0x006D6553
	{ -1, -1, -1 },
	/* 24/32 */
};

static FuncSig func_sig_srand_1[] = {
	{   0, 0xe59f1074, 0xfdffffff }, // ldr:4:0xE59F1074
	{   1, 0xe5810000, 0xfdffffff }, // str:4:0xE5810000
	{   4, 0xe59f4064, 0xfdffffff }, // ldr:4:0xE59F4064
	{   5, 0xe1a01000, 0xfdffffff }, // mov:6:0xE3A01000
	{   6, 0xe5940004, 0xfdffffff }, // ldr:4:0xE5940004
	{   7, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFCE68
	{   8, 0xe5940000, 0xfdffffff }, // ldr:4:0xE5940000
	{   9, 0xe59f1054, 0xfdffffff }, // ldr:4:0xE59F1054
	{  10, 0xe0000091, 0xfdffffff }, // and:6:0xE0000091 mul:11:0xE0000091
	{  12, 0xe0800a03, 0xfdffffff }, // add:6:0xE2800A03
	{  13, 0xe0800039, 0xfdffffff }, // add:6:0xE2800039
	{  14, 0xe0015820, 0xfdffffff }, // and:6:0xE0015820
	{  15, 0xe5840000, 0xfdffffff }, // str:4:0xE5840000
	{  16, 0xe5940004, 0xfdffffff }, // ldr:4:0xE5940004
	{  17, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFCE51
	{  18, 0xe1a00005, 0xfdffffff }, // mov:6:0xE1A00005
	{  21, 0xe08f2028, 0xfdffffff }, // add:6:0xE28F2028
	{  22, 0xe1a01002, 0xfdffffff }, // mov:6:0xE3A01002
	{  23, 0xe1a00001, 0xfdffffff }, // mov:6:0xE3A00001
	{  24, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFCDE8
	{  25, 0xe59f1010, 0xfdffffff }, // ldr:4:0xE59F1010
	{  27, 0xe5810004, 0xfdffffff }, // str:4:0xE5810004
	{  29, 0x11a00000, 0xfdffffff }, // mov:6:0x13A00000
	{  31, 0x00001bf0, 0xfdffffff }, // and:6:0x00001BF0
	{ -1, -1, -1 },
	/* 25/32 */
};

static FuncSig func_sig_stat_1[] = {
	{   1, 0xe1a05001, 0xfdffffff }, // mov:6:0xE1A05001
	{   2, 0xe1a01000, 0xfdffffff }, // mov:6:0xE3A01000
	{   3, 0xe1a02000, 0xfdffffff }, // mov:6:0xE3A02000
	{   4, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFD3D8
	{   5, 0xe0504000, 0xfdffffff }, // sub:6:0xE2504000
	{   8, 0xe1a02005, 0xfdffffff }, // mov:6:0xE1A02005
	{   9, 0xe1a01012, 0xfdffffff }, // mov:6:0xE3A01012
	{  10, 0xe1a00004, 0xfdffffff }, // mov:6:0xE1A00004
	{  11, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFD4DB
	{  12, 0xe1a05000, 0xfdffffff }, // mov:6:0xE1A05000
	{  13, 0xe1a00004, 0xfdffffff }, // mov:6:0xE1A00004
	{  14, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFD3FA
	{  15, 0xe1a00005, 0xfdffffff }, // mov:6:0xE1A00005
	{  18, 0xe04dd038, 0xfdffffff }, // sub:6:0xE24DD038
	{  19, 0xe1a04001, 0xfdffffff }, // mov:6:0xE1A04001
	{  20, 0xe08d1004, 0xfdffffff }, // add:6:0xE28D1004
	{  21, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFFFE9
	{  22, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{  24, 0x1a000000, 0xff000000 }, // b, bl:3:0x1A00000C
	{  25, 0xe59d000c, 0xfdffffff }, // ldr:4:0xE59D000C
	{  26, 0xe5840000, 0xfdffffff }, // str:4:0xE5840000
	{  28, 0xe5840004, 0xfdffffff }, // str:4:0xE5840004
	{  29, 0xe59d0020, 0xfdffffff }, // ldr:4:0xE59D0020
	{  30, 0xe5840008, 0xfdffffff }, // str:4:0xE5840008
	{  31, 0xe59d001c, 0xfdffffff }, // ldr:4:0xE59D001C
	{ -1, -1, -1 },
	/* 25/32 */
};

static FuncSig func_sig_openfastdir_1[] = {
	{   1, 0xe1a05000, 0xfdffffff }, // mov:6:0xE1A05000
	{   2, 0xe1a00014, 0xfdffffff }, // mov:6:0xE3A00014
	{   3, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBF95F20
	{   4, 0xe1b04000, 0xfdffffff }, // mov:6:0xE1B04000
	{   5, 0x01a01059, 0xfdffffff }, // mov:6:0x03A01059
	{   6, 0x008f0e26, 0xfdffffff }, // add:6:0x028F0E26
	{   7, 0x0b000000, 0xff000000 }, // b, bl:3:0x0BF9295C
	{   9, 0xe5840000, 0xfdffffff }, // str:4:0xE5840000
	{  10, 0xe1a00902, 0xfdffffff }, // mov:6:0xE3A00902
	{  11, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBF95F44
	{  12, 0xe1a01902, 0xfdffffff }, // mov:6:0xE3A01902
	{  14, 0xe1a01000, 0xfdffffff }, // mov:6:0xE3A01000
	{  15, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{  16, 0xe584100c, 0xfdffffff }, // str:4:0xE584100C
	{  17, 0xe5841010, 0xfdffffff }, // str:4:0xE5841010
	{  18, 0x01a01060, 0xfdffffff }, // mov:6:0x03A01060
	{  19, 0x008f0f8b, 0xfdffffff }, // add:6:0x028F0F8B
	{  20, 0x0b000000, 0xff000000 }, // b, bl:3:0x0BF9294F
	{  21, 0xe1a02f49, 0xfdffffff }, // mov:6:0xE3A02F49
	{  22, 0xe1a01000, 0xfdffffff }, // mov:6:0xE3A01000
	{  23, 0xe1a00005, 0xfdffffff }, // mov:6:0xE1A00005
	{  24, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBF94D26
	{  26, 0xe5840000, 0xfdffffff }, // str:4:0xE5840000
	{  27, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A000004
	{  28, 0xe1a00004, 0xfdffffff }, // mov:6:0xE1A00004
	{  29, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFFFB0
	{  30, 0xe1500002, 0xfdffffff }, // cmp:7:0xE3500002
	{  31, 0x11a00004, 0xfdffffff }, // mov:6:0x11A00004
	{ -1, -1, -1 },
	/* 28/32 */
};

static FuncSig func_sig_readfastdir_1[] = {
	{   1, 0xe1b05000, 0xfdffffff }, // mov:6:0xE1B05000
	{   2, 0xe1a07001, 0xfdffffff }, // mov:6:0xE1A07001
	{   3, 0xe1a06000, 0xfdffffff }, // mov:6:0xE3A06000
	{   4, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A000027
	{   5, 0xe5952010, 0xfdffffff }, // ldr:4:0xE5952010
	{   6, 0xe595400c, 0xfdffffff }, // ldr:4:0xE595400C
	{   7, 0xea000000, 0xff000000 }, // b, bl:3:0xEA000014
	{   8, 0xe5950004, 0xfdffffff }, // ldr:4:0xE5950004
	{   9, 0xe0800004, 0xfdffffff }, // add:6:0xE0800004
	{  11, 0xe151000f, 0xfdffffff }, // cmp:7:0xE351000F
	{  12, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A00000A
	{  13, 0xe1110008, 0xfdffffff }, // tst:7:0xE3110008
	{  14, 0x1a000000, 0xff000000 }, // b, bl:3:0x1A000008
	{  16, 0xe15100e5, 0xfdffffff }, // cmp:7:0xE35100E5
	{  17, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A000009
	{  18, 0xe1a01007, 0xfdffffff }, // mov:6:0xE1A01007
	{  19, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB000029
	{  20, 0xe0840020, 0xfdffffff }, // add:6:0xE2840020
	{  21, 0xe585000c, 0xfdffffff }, // str:4:0xE585000C
	{  22, 0xe1a00006, 0xfdffffff }, // mov:6:0xE1A00006
	{  23, 0xea000000, 0xff000000 }, // b, bl:3:0xEA000008
	{  25, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{  26, 0x01a00001, 0xfdffffff }, // mov:6:0x03A00001
	{  27, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A000004
	{  28, 0xe0844020, 0xfdffffff }, // add:6:0xE2844020
	{  29, 0xe1520004, 0xfdffffff }, // cmp:7:0xE1520004
	{  30, 0xca000000, 0xff000000 }, // b, bl:3:0xCAFFFFE8
	{  31, 0xe1a00002, 0xfdffffff }, // mov:6:0xE3A00002
	{ -1, -1, -1 },
	/* 28/32 */
};

static FuncSig func_sig_closefastdir_1[] = {
	{   1, 0xe1a04000, 0xfdffffff }, // mov:6:0xE1A04000
	{   2, 0xe5900000, 0xfdffffff }, // ldr:4:0xE5900000
	{   4, 0x1b000000, 0xff000000 }, // b, bl:3:0x1BF94CEB
	{   5, 0xe5940004, 0xfdffffff }, // ldr:4:0xE5940004
	{   6, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBF95EFD
	{   7, 0xe1a00004, 0xfdffffff }, // mov:6:0xE1A00004
	{   9, 0xea000000, 0xff000000 }, // b, bl:3:0xEAF95EC2
	{  11, 0xe1a05001, 0xfdffffff }, // mov:6:0xE1A05001
	{  12, 0xe1a01000, 0xfdffffff }, // mov:6:0xE1A01000
	{  13, 0xe1a04000, 0xfdffffff }, // mov:6:0xE1A04000
	{  14, 0xe1a00005, 0xfdffffff }, // mov:6:0xE1A00005
	{  15, 0xe1a02008, 0xfdffffff }, // mov:6:0xE3A02008
	{  16, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB000038
	{  18, 0xe1510020, 0xfdffffff }, // cmp:7:0xE3510020
	{  19, 0x11a0102e, 0xfdffffff }, // mov:6:0x13A0102E
	{  21, 0x10841008, 0xfdffffff }, // add:6:0x12841008
	{  22, 0x11a02003, 0xfdffffff }, // mov:6:0x13A02003
	{  23, 0x1b000000, 0xff000000 }, // b, bl:3:0x1B000031
	{  24, 0xe1a01000, 0xfdffffff }, // mov:6:0xE3A01000
	{  27, 0xe1500005, 0xfdffffff }, // cmp:7:0xE3500005
	{  28, 0x01a000e5, 0xfdffffff }, // mov:6:0x03A000E5
	{ -1, -1, -1 },
	/* 21/32 */
};

static FuncSig func_sig_qsort_1[] = {
	{   3, 0xe1120003, 0xfdffffff }, // tst:7:0xE3120003
	{   4, 0x059f2020, 0xfdffffff }, // ldr:4:0x059F2020
	{   5, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A000002
	{   6, 0xe1120001, 0xfdffffff }, // tst:7:0xE3120001
	{   7, 0x104f2e4b, 0xfdffffff }, // sub:6:0x124F2E4B
	{   8, 0x004f2e49, 0xfdffffff }, // sub:6:0x024F2E49
	{   9, 0xe58d2008, 0xfdffffff }, // str:4:0xE58D2008
	{  10, 0xe1a0200d, 0xfdffffff }, // mov:6:0xE1A0200D
	{  11, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFFFC1
	{  13, 0x0000bb00, 0xfdffffff }, // and:6:0x0000BB00
	{  17, 0xe59d100c, 0xfdffffff }, // ldr:4:0xE59D100C
	{  18, 0xe08d2010, 0xfdffffff }, // add:6:0xE28D2010
	{  19, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB02AE7D
	{  20, 0xe49d4004, 0xfdffffff }, // ldr:4:0xE49D4004
	{  21, 0xe49df014, 0xfdffffff }, // ldr:4:0xE49DF014
	{  22, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{  23, 0x1590101c, 0xfdffffff }, // ldr:4:0x1590101C
	{  24, 0x11510000, 0xfdffffff }, // cmp:7:0x13510000
	{  27, 0xe1a02000, 0xfdffffff }, // mov:6:0xE3A02000
	{  28, 0xe5802008, 0xfdffffff }, // str:4:0xE5802008
	{  29, 0xe5802014, 0xfdffffff }, // str:4:0xE5802014
	{  30, 0xe1a03001, 0xfdffffff }, // mov:6:0xE3A03001
	{  31, 0xe5a02018, 0xfdffffff }, // str:4:0xE5A02018
	{ -1, -1, -1 },
	/* 23/32 */
};

static FuncSig func_sig_strncpy_1[] = {
	{   0, 0xe1a03000, 0xfdffffff }, // mov:6:0xE1A03000
	{   1, 0xea000000, 0xff000000 }, // b, bl:3:0xEA000009
	{   3, 0xe15c0000, 0xfdffffff }, // cmp:7:0xE35C0000
	{   5, 0x1a000000, 0xff000000 }, // b, bl:3:0x1A000005
	{   6, 0xe1a01000, 0xfdffffff }, // mov:6:0xE3A01000
	{   7, 0xe0422001, 0xfdffffff }, // sub:6:0xE2422001
	{  10, 0x1a000000, 0xff000000 }, // b, bl:3:0x1AFFFFFB
	{  12, 0xe0522001, 0xfdffffff }, // sub:6:0xE2522001
	{  13, 0x2a000000, 0xff000000 }, // b, bl:3:0x2AFFFFF3
	{  15, 0xea000000, 0xff000000 }, // b, bl:3:0xEA000008
	{  17, 0xe1520003, 0xfdffffff }, // cmp:7:0xE1520003
	{  18, 0x00800001, 0xfdffffff }, // add:6:0x02800001
	{  19, 0x00811001, 0xfdffffff }, // add:6:0x02811001
	{  20, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A000003
	{  23, 0xe0400001, 0xfdffffff }, // sub:6:0xE0400001
	{  26, 0xe1520000, 0xfdffffff }, // cmp:7:0xE3520000
	{  28, 0x01530000, 0xfdffffff }, // cmp:7:0x03530000
	{  29, 0x1a000000, 0xff000000 }, // b, bl:3:0x1AFFFFF1
	{  30, 0xe1a00000, 0xfdffffff }, // mov:6:0xE3A00000
	{ -1, -1, -1 },
	/* 19/32 */
};

static FuncSig func_sig_strrchr_1[] = {
	{   0, 0xe1a02000, 0xfdffffff }, // mov:6:0xE3A02000
	{   1, 0xe00130ff, 0xfdffffff }, // and:6:0xE20130FF
	{   3, 0xe1510003, 0xfdffffff }, // cmp:7:0xE1510003
	{   4, 0x01a02000, 0xfdffffff }, // mov:6:0x01A02000
	{   5, 0xe1510000, 0xfdffffff }, // cmp:7:0xE3510000
	{   6, 0xe0800001, 0xfdffffff }, // add:6:0xE2800001
	{   7, 0x1a000000, 0xff000000 }, // b, bl:3:0x1AFFFFF9
	{   8, 0xe1a00002, 0xfdffffff }, // mov:6:0xE1A00002
	{  10, 0xe1520010, 0xfdffffff }, // cmp:7:0xE3520010
	{  11, 0xe1a03000, 0xfdffffff }, // mov:6:0xE1A03000
	{  12, 0x3a000000, 0xff000000 }, // b, bl:3:0x3A000032
	{  13, 0xe1130003, 0xfdffffff }, // tst:7:0xE3130003
	{  15, 0x10422001, 0xfdffffff }, // sub:6:0x12422001
	{  17, 0x1a000000, 0xff000000 }, // b, bl:3:0x1AFFFFFA
	{  18, 0xe011c003, 0xfdffffff }, // and:6:0xE211C003
	{  19, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A00000D
	{  20, 0xe15c0001, 0xfdffffff }, // cmp:7:0xE35C0001
	{  21, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A000029
	{  22, 0xe15c0002, 0xfdffffff }, // cmp:7:0xE35C0002
	{  23, 0x1a000000, 0xff000000 }, // b, bl:3:0x1A000027
	{  24, 0xea000000, 0xff000000 }, // b, bl:3:0xEA00001A
	{  25, 0xe491c004, 0xfdffffff }, // ldr:4:0xE491C004
	{  26, 0xe0422010, 0xfdffffff }, // sub:6:0xE2422010
	{  27, 0xe483c004, 0xfdffffff }, // str:4:0xE483C004
	{  28, 0xe491c004, 0xfdffffff }, // ldr:4:0xE491C004
	{  29, 0xe483c004, 0xfdffffff }, // str:4:0xE483C004
	{  30, 0xe491c004, 0xfdffffff }, // ldr:4:0xE491C004
	{  31, 0xe483c004, 0xfdffffff }, // str:4:0xE483C004
	{ -1, -1, -1 },
	/* 28/32 */
};

static FuncSig func_sig_strncmp_1[] = {
	{   0, 0xea000000, 0xff000000 }, // b, bl:3:0xEA000008
	{   2, 0xe153000c, 0xfdffffff }, // cmp:7:0xE153000C
	{   3, 0x00800001, 0xfdffffff }, // add:6:0x02800001
	{   4, 0x00811001, 0xfdffffff }, // add:6:0x02811001
	{   5, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A000003
	{   8, 0xe0400001, 0xfdffffff }, // sub:6:0xE0400001
	{  10, 0xe0522001, 0xfdffffff }, // sub:6:0xE2522001
	{  11, 0x3a000000, 0xff000000 }, // b, bl:3:0x3A000004
	{  13, 0xe1530000, 0xfdffffff }, // cmp:7:0xE3530000
	{  15, 0x015c0000, 0xfdffffff }, // cmp:7:0x035C0000
	{  16, 0x1a000000, 0xff000000 }, // b, bl:3:0x1AFFFFEF
	{  17, 0xe1a00000, 0xfdffffff }, // mov:6:0xE3A00000
	{  19, 0xe00120ff, 0xfdffffff }, // and:6:0xE20120FF
	{  21, 0xe1510002, 0xfdffffff }, // cmp:7:0xE1510002
	{  23, 0xe1510000, 0xfdffffff }, // cmp:7:0xE3510000
	{  24, 0xe0800001, 0xfdffffff }, // add:6:0xE2800001
	{  25, 0x1a000000, 0xff000000 }, // b, bl:3:0x1AFFFFF9
	{  26, 0xe1a00000, 0xfdffffff }, // mov:6:0xE3A00000
	{  28, 0xe1a02000, 0xfdffffff }, // mov:6:0xE3A02000
	{  29, 0xe00130ff, 0xfdffffff }, // and:6:0xE20130FF
	{  31, 0xe1510003, 0xfdffffff }, // cmp:7:0xE1510003
	{ -1, -1, -1 },
	/* 21/32 */
};

static FuncSig func_sig_strchr_1[] = {
	{   0, 0xe00120ff, 0xfdffffff }, // and:6:0xE20120FF
	{   2, 0xe1510002, 0xfdffffff }, // cmp:7:0xE1510002
	{   4, 0xe1510000, 0xfdffffff }, // cmp:7:0xE3510000
	{   5, 0xe0800001, 0xfdffffff }, // add:6:0xE2800001
	{   6, 0x1a000000, 0xff000000 }, // b, bl:3:0x1AFFFFF9
	{   7, 0xe1a00000, 0xfdffffff }, // mov:6:0xE3A00000
	{   9, 0xe1a02000, 0xfdffffff }, // mov:6:0xE3A02000
	{  10, 0xe00130ff, 0xfdffffff }, // and:6:0xE20130FF
	{  12, 0xe1510003, 0xfdffffff }, // cmp:7:0xE1510003
	{  13, 0x01a02000, 0xfdffffff }, // mov:6:0x01A02000
	{  14, 0xe1510000, 0xfdffffff }, // cmp:7:0xE3510000
	{  15, 0xe0800001, 0xfdffffff }, // add:6:0xE2800001
	{  16, 0x1a000000, 0xff000000 }, // b, bl:3:0x1AFFFFF9
	{  17, 0xe1a00002, 0xfdffffff }, // mov:6:0xE1A00002
	{  19, 0xe1520010, 0xfdffffff }, // cmp:7:0xE3520010
	{  20, 0xe1a03000, 0xfdffffff }, // mov:6:0xE1A03000
	{  21, 0x3a000000, 0xff000000 }, // b, bl:3:0x3A000032
	{  22, 0xe1130003, 0xfdffffff }, // tst:7:0xE3130003
	{  24, 0x10422001, 0xfdffffff }, // sub:6:0x12422001
	{  26, 0x1a000000, 0xff000000 }, // b, bl:3:0x1AFFFFFA
	{  27, 0xe011c003, 0xfdffffff }, // and:6:0xE211C003
	{  28, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A00000D
	{  29, 0xe15c0001, 0xfdffffff }, // cmp:7:0xE35C0001
	{  30, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A000029
	{  31, 0xe15c0002, 0xfdffffff }, // cmp:7:0xE35C0002
	{ -1, -1, -1 },
	/* 25/32 */
};

static FuncSig func_sig_strcat_1[] = {
	{   0, 0xe1a03000, 0xfdffffff }, // mov:6:0xE1A03000
	{   2, 0xe1520000, 0xfdffffff }, // cmp:7:0xE3520000
	{   3, 0x10800001, 0xfdffffff }, // add:6:0x12800001
	{   4, 0x1a000000, 0xff000000 }, // b, bl:3:0x1AFFFFFB
	{   5, 0xea000000, 0xff000000 }, // b, bl:3:0xEA000001
	{   6, 0xe0811001, 0xfdffffff }, // add:6:0xE2811001
	{   9, 0xe1520000, 0xfdffffff }, // cmp:7:0xE3520000
	{  10, 0x1a000000, 0xff000000 }, // b, bl:3:0x1AFFFFFA
	{  11, 0xe1a01000, 0xfdffffff }, // mov:6:0xE3A01000
	{  13, 0xe1a00003, 0xfdffffff }, // mov:6:0xE1A00003
	{  15, 0xea000000, 0xff000000 }, // b, bl:3:0xEA000008
	{  17, 0xe153000c, 0xfdffffff }, // cmp:7:0xE153000C
	{  18, 0x00800001, 0xfdffffff }, // add:6:0x02800001
	{  19, 0x00811001, 0xfdffffff }, // add:6:0x02811001
	{  20, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A000003
	{  23, 0xe0400001, 0xfdffffff }, // sub:6:0xE0400001
	{  25, 0xe0522001, 0xfdffffff }, // sub:6:0xE2522001
	{  26, 0x3a000000, 0xff000000 }, // b, bl:3:0x3A000004
	{  28, 0xe1530000, 0xfdffffff }, // cmp:7:0xE3530000
	{  30, 0x015c0000, 0xfdffffff }, // cmp:7:0x035C0000
	{  31, 0x1a000000, 0xff000000 }, // b, bl:3:0x1AFFFFEF
	{ -1, -1, -1 },
	/* 21/32 */
};

static FuncSig func_sig_strtol_1[] = {
	{   0, 0xe1a03001, 0xfdffffff }, // mov:6:0xE3A03001
	{   1, 0xea000000, 0xff000000 }, // b, bl:3:0xEAFFFF7E
	{   2, 0xe1a03000, 0xfdffffff }, // mov:6:0xE3A03000
	{   3, 0xea000000, 0xff000000 }, // b, bl:3:0xEAFFFF7C
	{   5, 0xe1a03000, 0xfdffffff }, // mov:6:0xE3A03000
	{   6, 0xea000000, 0xff000000 }, // b, bl:3:0xEA00000F
	{   7, 0xe151000a, 0xfdffffff }, // cmp:7:0xE351000A
	{   8, 0xe042c030, 0xfdffffff }, // sub:6:0xE242C030
	{   9, 0x1a000000, 0xff000000 }, // b, bl:3:0x1A000002
	{  10, 0xe15c000a, 0xfdffffff }, // cmp:7:0xE35C000A
	{  11, 0x2a000000, 0xff000000 }, // b, bl:3:0x2A00000F
	{  12, 0xea000000, 0xff000000 }, // b, bl:3:0xEA000007
	{  13, 0xe15c000a, 0xfdffffff }, // cmp:7:0xE35C000A
	{  14, 0x2042c061, 0xfdffffff }, // sub:6:0x2242C061
	{  15, 0x215c0006, 0xfdffffff }, // cmp:7:0x235C0006
	{  16, 0x2a000000, 0xff000000 }, // b, bl:3:0x2A00000A
	{  17, 0xe042c061, 0xfdffffff }, // sub:6:0xE242C061
	{  18, 0xe15c0005, 0xfdffffff }, // cmp:7:0xE35C0005
	{  19, 0x90422057, 0xfdffffff }, // sub:6:0x92422057
	{  20, 0x9a000000, 0xff000000 }, // b, bl:3:0x9A000000
	{  21, 0xe0422030, 0xfdffffff }, // sub:6:0xE2422030
	{  24, 0xe1520000, 0xfdffffff }, // cmp:7:0xE3520000
	{  25, 0x1a000000, 0xff000000 }, // b, bl:3:0x1AFFFFEC
	{  26, 0xe1a00003, 0xfdffffff }, // mov:6:0xE1A00003
	{  28, 0xe1a00000, 0xfdffffff }, // mov:6:0xE3A00000
	{  31, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB002C2F
	{ -1, -1, -1 },
	/* 26/32 */
};

static FuncSig func_sig_time_1[] = {
	{   1, 0xe1a04000, 0xfdffffff }, // mov:6:0xE1A04000
	{   3, 0xe58d0000, 0xfdffffff }, // str:4:0xE58D0000
	{   4, 0xe1a0000d, 0xfdffffff }, // mov:6:0xE1A0000D
	{   5, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB02F26E
	{   6, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{   7, 0x1a000000, 0xff000000 }, // b, bl:3:0x1A000002
	{   8, 0xe1540000, 0xfdffffff }, // cmp:7:0xE3540000
	{   9, 0x159d0000, 0xfdffffff }, // ldr:4:0x159D0000
	{  10, 0x15840000, 0xfdffffff }, // str:4:0x15840000
	{  11, 0xe59d0000, 0xfdffffff }, // ldr:4:0xE59D0000
	{  14, 0xe1a04000, 0xfdffffff }, // mov:6:0xE1A04000
	{  15, 0xe1a00000, 0xfdffffff }, // mov:6:0xE3A00000
	{  16, 0xe5840024, 0xfdffffff }, // str:4:0xE5840024
	{  17, 0xe5940014, 0xfdffffff }, // ldr:4:0xE5940014
	{  18, 0xe0401046, 0xfdffffff }, // sub:6:0xE2401046
	{  19, 0xe1510044, 0xfdffffff }, // cmp:7:0xE3510044
	{  20, 0x2a000000, 0xff000000 }, // b, bl:3:0x2A000025
	{  21, 0xe59f129c, 0xfdffffff }, // ldr:4:0xE59F129C
	{  22, 0xe0811100, 0xfdffffff }, // add:6:0xE0811100
	{  23, 0xe5113118, 0xfdffffff }, // ldr:4:0xE5113118
	{  24, 0xe59f1294, 0xfdffffff }, // ldr:4:0xE59F1294
	{  25, 0xe0811100, 0xfdffffff }, // add:6:0xE0811100
	{  26, 0xe5112118, 0xfdffffff }, // ldr:4:0xE5112118
	{  27, 0xe5941010, 0xfdffffff }, // ldr:4:0xE5941010
	{  28, 0xe151000c, 0xfdffffff }, // cmp:7:0xE351000C
	{  29, 0x2a000000, 0xff000000 }, // b, bl:3:0x2A00001C
	{  30, 0xe59fc280, 0xfdffffff }, // ldr:4:0xE59FC280
	{  31, 0xe0833083, 0xfdffffff }, // add:6:0xE0833083
	{ -1, -1, -1 },
	/* 28/32 */
};

static FuncSig func_sig_LocalTime_1[] = {
	{   1, 0xe1a05000, 0xfdffffff }, // mov:6:0xE1A05000
	{   2, 0xe1a04001, 0xfdffffff }, // mov:6:0xE1A04001
	{   3, 0xe59f11b0, 0xfdffffff }, // ldr:4:0xE59F11B0
	{   4, 0xe5900000, 0xfdffffff }, // ldr:4:0xE5900000
	{   5, 0xe1500001, 0xfdffffff }, // cmp:7:0xE1500001
	{   6, 0x3a000000, 0xff000000 }, // b, bl:3:0x3A000003
	{   7, 0xe1a01004, 0xfdffffff }, // mov:6:0xE1A01004
	{   8, 0xe1a00005, 0xfdffffff }, // mov:6:0xE1A00005
	{   9, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB006F3C
	{  10, 0xea000000, 0xff000000 }, // b, bl:3:0xEA000049
	{  11, 0xe59f217c, 0xfdffffff }, // ldr:4:0xE59F217C
	{  12, 0xe1a01000, 0xfdffffff }, // mov:6:0xE3A01000
	{  13, 0xe5923101, 0xfdffffff }, // ldr:4:0xE7923101
	{  14, 0xe1530000, 0xfdffffff }, // cmp:7:0xE1530000
	{  15, 0xd0811001, 0xfdffffff }, // add:6:0xD2811001
	{  16, 0xd1510044, 0xfdffffff }, // cmp:7:0xD3510044
	{  17, 0xba000000, 0xff000000 }, // b, bl:3:0xBAFFFFFA
	{  18, 0xe0511001, 0xfdffffff }, // sub:6:0xE2511001
	{  19, 0x4a000000, 0xff000000 }, // b, bl:3:0x4AFFFFF2
	{  20, 0xe0816046, 0xfdffffff }, // add:6:0xE2816046
	{  21, 0xe5846014, 0xfdffffff }, // str:4:0xE5846014
	{  22, 0xe5921101, 0xfdffffff }, // ldr:4:0xE7921101
	{  23, 0xe1a02000, 0xfdffffff }, // mov:6:0xE3A02000
	{  24, 0xe0401001, 0xfdffffff }, // sub:6:0xE0401001
	{  25, 0xe59f0140, 0xfdffffff }, // ldr:4:0xE59F0140
	{  26, 0xe0800106, 0xfdffffff }, // add:6:0xE0800106
	{  27, 0xe5100118, 0xfdffffff }, // ldr:4:0xE5100118
	{  28, 0xe0808080, 0xfdffffff }, // add:6:0xE0808080
	{  29, 0xe59f0138, 0xfdffffff }, // ldr:4:0xE59F0138
	{  30, 0xe0800208, 0xfdffffff }, // add:6:0xE0800208
	{  31, 0xe5903102, 0xfdffffff }, // ldr:4:0xE7903102
	{ -1, -1, -1 },
	/* 31/32 */
};

static FuncSig func_sig_UpdateMBROnFlash_1[] = {
	{   1, 0xe1a07001, 0xfdffffff }, // mov:6:0xE1A07001
	{   2, 0xe1a06002, 0xfdffffff }, // mov:6:0xE1A06002
	{   3, 0xe1a04000, 0xfdffffff }, // mov:6:0xE1A04000
	{   4, 0xe1a00003, 0xfdffffff }, // mov:6:0xE3A00003
	{   5, 0xe1a02000, 0xfdffffff }, // mov:6:0xE3A02000
	{   6, 0xe1a01c02, 0xfdffffff }, // mov:6:0xE3A01C02
	{   7, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB005DB9
	{   8, 0xe1a05000, 0xfdffffff }, // mov:6:0xE1A05000
	{   9, 0xe1a00017, 0xfdffffff }, // mov:6:0xE3A00017
	{  10, 0xe0010490, 0xfdffffff }, // and:6:0xE0010490 mul:11:0xE0010490
	{  11, 0xe51f0550, 0xfdffffff }, // ldr:4:0xE51F0550
	{  12, 0xe1a03005, 0xfdffffff }, // mov:6:0xE1A03005
	{  13, 0xe0804101, 0xfdffffff }, // add:6:0xE0804101
	{  14, 0xe594c04c, 0xfdffffff }, // ldr:4:0xE594C04C
	{  15, 0xe5940038, 0xfdffffff }, // ldr:4:0xE5940038
	{  16, 0xe5941044, 0xfdffffff }, // ldr:4:0xE5941044
	{  17, 0xe1a02001, 0xfdffffff }, // mov:6:0xE3A02001
	{  19, 0xe1a00006, 0xfdffffff }, // mov:6:0xE1A00006
	{  20, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFF3D7A
	{  21, 0xe1a02000, 0xfdffffff }, // mov:6:0xE1A02000
	{  22, 0xe0850007, 0xfdffffff }, // add:6:0xE0850007
	{  23, 0xe1a01006, 0xfdffffff }, // mov:6:0xE1A01006
	{  24, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFF3D56
	{  25, 0xe5b40038, 0xfdffffff }, // ldr:4:0xE5B40038
	{  26, 0xe5b4100c, 0xfdffffff }, // ldr:4:0xE5B4100C
	{  27, 0xe594c00c, 0xfdffffff }, // ldr:4:0xE594C00C
	{  28, 0xe1a03005, 0xfdffffff }, // mov:6:0xE1A03005
	{  29, 0xe1a02001, 0xfdffffff }, // mov:6:0xE3A02001
	{ -1, -1, -1 },
	/* 29/32 */
};

static FuncSig func_sig_opendir_1[] = {
	{   1, 0xe1a05000, 0xfdffffff }, // mov:6:0xE1A05000
	{   2, 0xe1a00014, 0xfdffffff }, // mov:6:0xE3A00014
	{   3, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBF95F20
	{   4, 0xe1b04000, 0xfdffffff }, // mov:6:0xE1B04000
	{   5, 0x01a01059, 0xfdffffff }, // mov:6:0x03A01059
	{   6, 0x008f0e26, 0xfdffffff }, // add:6:0x028F0E26
	{   7, 0x0b000000, 0xff000000 }, // b, bl:3:0x0BF9295C
	{   9, 0xe5840000, 0xfdffffff }, // str:4:0xE5840000
	{  10, 0xe1a00902, 0xfdffffff }, // mov:6:0xE3A00902
	{  11, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBF95F44
	{  12, 0xe1a01902, 0xfdffffff }, // mov:6:0xE3A01902
	{  14, 0xe1a01000, 0xfdffffff }, // mov:6:0xE3A01000
	{  15, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{  16, 0xe584100c, 0xfdffffff }, // str:4:0xE584100C
	{  17, 0xe5841010, 0xfdffffff }, // str:4:0xE5841010
	{  18, 0x01a01060, 0xfdffffff }, // mov:6:0x03A01060
	{  19, 0x008f0f8b, 0xfdffffff }, // add:6:0x028F0F8B
	{  20, 0x0b000000, 0xff000000 }, // b, bl:3:0x0BF9294F
	{  21, 0xe1a02f49, 0xfdffffff }, // mov:6:0xE3A02F49
	{  22, 0xe1a01000, 0xfdffffff }, // mov:6:0xE3A01000
	{  23, 0xe1a00005, 0xfdffffff }, // mov:6:0xE1A00005
	{  24, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBF94D26
	{  26, 0xe5840000, 0xfdffffff }, // str:4:0xE5840000
	{  27, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A000004
	{  28, 0xe1a00004, 0xfdffffff }, // mov:6:0xE1A00004
	{  29, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFFFFB0
	{  30, 0xe1500002, 0xfdffffff }, // cmp:7:0xE3500002
	{  31, 0x11a00004, 0xfdffffff }, // mov:6:0x11A00004
	{ -1, -1, -1 },
	/* 28/32 */
};

static FuncSig func_sig_ReadFastDir_1[] = {
	{   1, 0xe1b05000, 0xfdffffff }, // mov:6:0xE1B05000
	{   2, 0xe1a07001, 0xfdffffff }, // mov:6:0xE1A07001
	{   3, 0xe1a06000, 0xfdffffff }, // mov:6:0xE3A06000
	{   4, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A000027
	{   5, 0xe5952010, 0xfdffffff }, // ldr:4:0xE5952010
	{   6, 0xe595400c, 0xfdffffff }, // ldr:4:0xE595400C
	{   7, 0xea000000, 0xff000000 }, // b, bl:3:0xEA000014
	{   8, 0xe5950004, 0xfdffffff }, // ldr:4:0xE5950004
	{   9, 0xe0800004, 0xfdffffff }, // add:6:0xE0800004
	{  11, 0xe151000f, 0xfdffffff }, // cmp:7:0xE351000F
	{  12, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A00000A
	{  13, 0xe1110008, 0xfdffffff }, // tst:7:0xE3110008
	{  14, 0x1a000000, 0xff000000 }, // b, bl:3:0x1A000008
	{  16, 0xe15100e5, 0xfdffffff }, // cmp:7:0xE35100E5
	{  17, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A000009
	{  18, 0xe1a01007, 0xfdffffff }, // mov:6:0xE1A01007
	{  19, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB000029
	{  20, 0xe0840020, 0xfdffffff }, // add:6:0xE2840020
	{  21, 0xe585000c, 0xfdffffff }, // str:4:0xE585000C
	{  22, 0xe1a00006, 0xfdffffff }, // mov:6:0xE1A00006
	{  23, 0xea000000, 0xff000000 }, // b, bl:3:0xEA000008
	{  25, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{  26, 0x01a00001, 0xfdffffff }, // mov:6:0x03A00001
	{  27, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A000004
	{  28, 0xe0844020, 0xfdffffff }, // add:6:0xE2844020
	{  29, 0xe1520004, 0xfdffffff }, // cmp:7:0xE1520004
	{  30, 0xca000000, 0xff000000 }, // b, bl:3:0xCAFFFFE8
	{  31, 0xe1a00002, 0xfdffffff }, // mov:6:0xE3A00002
	{ -1, -1, -1 },
	/* 28/32 */
};

static FuncSig func_sig_closedir_1[] = {
	{   1, 0xe1a04000, 0xfdffffff }, // mov:6:0xE1A04000
	{   2, 0xe5900000, 0xfdffffff }, // ldr:4:0xE5900000
	{   4, 0x1b000000, 0xff000000 }, // b, bl:3:0x1BF94CEB
	{   5, 0xe5940004, 0xfdffffff }, // ldr:4:0xE5940004
	{   6, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBF95EFD
	{   7, 0xe1a00004, 0xfdffffff }, // mov:6:0xE1A00004
	{   9, 0xea000000, 0xff000000 }, // b, bl:3:0xEAF95EC2
	{  11, 0xe1a05001, 0xfdffffff }, // mov:6:0xE1A05001
	{  12, 0xe1a01000, 0xfdffffff }, // mov:6:0xE1A01000
	{  13, 0xe1a04000, 0xfdffffff }, // mov:6:0xE1A04000
	{  14, 0xe1a00005, 0xfdffffff }, // mov:6:0xE1A00005
	{  15, 0xe1a02008, 0xfdffffff }, // mov:6:0xE3A02008
	{  16, 0xeb000000, 0xff000000 }, // b, bl:3:0xEB000038
	{  18, 0xe1510020, 0xfdffffff }, // cmp:7:0xE3510020
	{  19, 0x11a0102e, 0xfdffffff }, // mov:6:0x13A0102E
	{  21, 0x10841008, 0xfdffffff }, // add:6:0x12841008
	{  22, 0x11a02003, 0xfdffffff }, // mov:6:0x13A02003
	{  23, 0x1b000000, 0xff000000 }, // b, bl:3:0x1B000031
	{  24, 0xe1a01000, 0xfdffffff }, // mov:6:0xE3A01000
	{  27, 0xe1500005, 0xfdffffff }, // cmp:7:0xE3500005
	{  28, 0x01a000e5, 0xfdffffff }, // mov:6:0x03A000E5
	{ -1, -1, -1 },
	/* 21/32 */
};

static FuncSig func_sig_NewTaskShell_1[] = {
	{   1, 0xe51f4728, 0xfdffffff }, // ldr:4:0xE51F4728
	{   2, 0xe5940000, 0xfdffffff }, // ldr:4:0xE5940000
	{   3, 0xe1500064, 0xfdffffff }, // cmp:7:0xE3500064
	{   4, 0xa1a00005, 0xfdffffff }, // mov:6:0xA3A00005
	{   5, 0xaa000000, 0xff000000 }, // b, bl:3:0xAA000010
	{   6, 0xe0800001, 0xfdffffff }, // add:6:0xE2800001
	{   7, 0xe5840000, 0xfdffffff }, // str:4:0xE5840000
	{   8, 0xe1a03000, 0xfdffffff }, // mov:6:0xE3A03000
	{   9, 0xe58d3000, 0xfdffffff }, // str:4:0xE58D3000
	{  10, 0xe04f30e4, 0xfdffffff }, // sub:6:0xE24F30E4
	{  11, 0xe08f00dc, 0xfdffffff }, // add:6:0xE28F00DC
	{  12, 0xe1a02902, 0xfdffffff }, // mov:6:0xE3A02902
	{  13, 0xe1a01018, 0xfdffffff }, // mov:6:0xE3A01018
	{  14, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFEC934
	{  15, 0xe1100001, 0xfdffffff }, // tst:7:0xE3100001
	{  16, 0x1a000000, 0xff000000 }, // b, bl:3:0x1A000005
	{  17, 0xe59f10d8, 0xfdffffff }, // ldr:4:0xE59F10D8
	{  18, 0xe5940004, 0xfdffffff }, // ldr:4:0xE5940004
	{  19, 0xe1a030af, 0xfdffffff }, // mov:6:0xE3A030AF
	{  20, 0xe08f20c0, 0xfdffffff }, // add:6:0xE28F20C0
	{  21, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFECA1D
	{  22, 0xe1a00000, 0xfdffffff }, // mov:6:0xE3A00000
	{  25, 0xe59f10bc, 0xfdffffff }, // ldr:4:0xE59F10BC
	{  26, 0xe08f00bc, 0xfdffffff }, // add:6:0xE28F00BC
	{  27, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFECAAB
	{  28, 0xe1a01001, 0xfdffffff }, // mov:6:0xE3A01001
	{  29, 0xe1a00000, 0xfdffffff }, // mov:6:0xE3A00000
	{  30, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFEC9F9
	{  31, 0xe51f17a0, 0xfdffffff }, // ldr:4:0xE51F17A0
	{ -1, -1, -1 },
	/* 29/32 */
};

static FuncSig func_sig_UIFS_WriteFirmInfoToFile_1[] = {
	{   1, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{   2, 0xe04dd0a0, 0xfdffffff }, // sub:6:0xE24DD0A0
	{   3, 0x11a04000, 0xfdffffff }, // mov:6:0x11A04000
	{   4, 0xe1a05000, 0xfdffffff }, // mov:6:0xE3A05000
	{   5, 0xe08d0050, 0xfdffffff }, // add:6:0xE28D0050
	{   6, 0x008f4ff2, 0xfdffffff }, // add:6:0x028F4FF2
	{   8, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFB0FDC
	{   9, 0xe1a03000, 0xfdffffff }, // mov:6:0xE1A03000
	{  10, 0xe1a00004, 0xfdffffff }, // mov:6:0xE1A00004
	{  11, 0xe08d2050, 0xfdffffff }, // add:6:0xE28D2050
	{  13, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFB26B3
	{  14, 0xe08f1fee, 0xfdffffff }, // add:6:0xE28F1FEE
	{  15, 0xe1a00004, 0xfdffffff }, // mov:6:0xE1A00004
	{  16, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFB2815
	{  17, 0xe1a08000, 0xfdffffff }, // mov:6:0xE1A08000
	{  18, 0xe59f03ac, 0xfdffffff }, // ldr:4:0xE59F03AC
	{  19, 0xe1a02020, 0xfdffffff }, // mov:6:0xE3A02020
	{  20, 0xe08d1050, 0xfdffffff }, // add:6:0xE28D1050
	{  21, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFC4855
	{  22, 0xe08d2050, 0xfdffffff }, // add:6:0xE28D2050
	{  23, 0xe08f1fe7, 0xfdffffff }, // add:6:0xE28F1FE7
	{  24, 0xe08d0050, 0xfdffffff }, // add:6:0xE28D0050
	{  25, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFB0F74
	{  26, 0xe08d0050, 0xfdffffff }, // add:6:0xE28D0050
	{  27, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFB0FC9
	{  28, 0xe1a01000, 0xfdffffff }, // mov:6:0xE1A01000
	{  29, 0xe08d0050, 0xfdffffff }, // add:6:0xE28D0050
	{  30, 0xe1a03008, 0xfdffffff }, // mov:6:0xE1A03008
	{  31, 0xe1a02001, 0xfdffffff }, // mov:6:0xE3A02001
	{ -1, -1, -1 },
	/* 29/32 */
};

static FuncSig func_sig_SetAutoShutdownTime_1[] = {
	{   1, 0xe59f4098, 0xfdffffff }, // ldr:4:0xE59F4098
	{   2, 0xe1a05000, 0xfdffffff }, // mov:6:0xE1A05000
	{   3, 0xe5940000, 0xfdffffff }, // ldr:4:0xE5940000
	{   4, 0xe1500001, 0xfdffffff }, // cmp:7:0xE3500001
	{   5, 0x11a010a9, 0xfdffffff }, // mov:6:0x13A010A9
	{   6, 0x108f008c, 0xfdffffff }, // add:6:0x128F008C
	{   7, 0x1b000000, 0xff000000 }, // b, bl:3:0x1BFEC025
	{   8, 0xe59f1090, 0xfdffffff }, // ldr:4:0xE59F1090
	{   9, 0xe5940024, 0xfdffffff }, // ldr:4:0xE5940024
	{  10, 0xe1a030aa, 0xfdffffff }, // mov:6:0xE3A030AA
	{  11, 0xe08f2078, 0xfdffffff }, // add:6:0xE28F2078
	{  12, 0xeb000000, 0xff000000 }, // b, bl:3:0xEBFEC011
	{  13, 0xe1a00ffa, 0xfdffffff }, // mov:6:0xE3A00FFA
	{  14, 0xe0000095, 0xfdffffff }, // and:6:0xE0000095 mul:11:0xE0000095
	{  15, 0xe1a05000, 0xfdffffff }, // mov:6:0xE3A05000
	{  16, 0xe584001c, 0xfdffffff }, // str:4:0xE584001C
	{  17, 0xe5940004, 0xfdffffff }, // ldr:4:0xE5940004
	{  18, 0xe1500001, 0xfdffffff }, // cmp:7:0xE3500001
	{  19, 0x05845004, 0xfdffffff }, // str:4:0x05845004
	{  20, 0x0b000000, 0xff000000 }, // b, bl:3:0x0B000043
	{  21, 0xe594001c, 0xfdffffff }, // ldr:4:0xE594001C
	{  22, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{  23, 0x0584500c, 0xfdffffff }, // str:4:0x0584500C
	{  24, 0x0a000000, 0xff000000 }, // b, bl:3:0x0A00000C
	{  25, 0xe1a01001, 0xfdffffff }, // mov:6:0xE3A01001
	{  26, 0xe584100c, 0xfdffffff }, // str:4:0xE584100C
	{  27, 0xe5942008, 0xfdffffff }, // ldr:4:0xE5942008
	{  28, 0xe1520000, 0xfdffffff }, // cmp:7:0xE3520000
	{  29, 0x1a000000, 0xff000000 }, // b, bl:3:0x1A000007
	{  30, 0xe5841004, 0xfdffffff }, // str:4:0xE5841004
	{  31, 0xe04f2e2a, 0xfdffffff }, // sub:6:0xE24F2E2A
	{ -1, -1, -1 },
	/* 32/32 */
};

FuncsList func_list[] = {
	{ "AllocateMemory", func_sig_AllocateMemory_1 },
	{ "AllocateUncacheableMemory", func_sig_AllocateUncacheableMemory_1 },
	{ "Close", func_sig_Close_1 },
	{ "CreateTask", func_sig_CreateTask_1 },
	{ "ExecuteEventProcedure", func_sig_ExecuteEventProcedure_1 },
	{ "ExitTask", func_sig_ExitTask_1 },
	{ "Fclose_Fut", func_sig_Fclose_Fut_1 },
	{ "Fopen_Fut", func_sig_Fopen_Fut_1 },
	{ "Fread_Fut", func_sig_Fread_Fut_1 },
	{ "FreeMemory", func_sig_FreeMemory_1 },
	{ "FreeUncacheableMemory", func_sig_FreeUncacheableMemory_1 },
	{ "Fseek_Fut", func_sig_Fseek_Fut_1 },
	{ "Fwrite_Fut", func_sig_Fwrite_Fut_1 },
	{ "GetCurrentAvValue", func_sig_GetCurrentAvValue_1 },
	{ "GetCurrentTargetDistance", func_sig_GetCurrentTargetDistance_1 },
	{ "GetDrive_ClusterSize", func_sig_GetDrive_ClusterSize_1 },
	{ "GetDrive_FreeClusters", func_sig_GetDrive_FreeClusters_1 },
	{ "GetDrive_TotalClusters", func_sig_GetDrive_TotalClusters_1 },
	{ "GetFocusLensSubjectDistance", func_sig_GetFocusLensSubjectDistance_1 },
	{ "GetParameterData", func_sig_GetParameterData_1 },
	{ "GetPropertyCase", func_sig_GetPropertyCase_1 },
	{ "GetSystemTime", func_sig_GetSystemTime_1 },
	{ "GetZoomLensCurrentPoint", func_sig_GetZoomLensCurrentPoint_1 },
	{ "GetZoomLensCurrentPosition", func_sig_GetZoomLensCurrentPosition_1 },
	{ "IsStrobeChargeCompleted", func_sig_IsStrobeChargeCompleted_1 },
	{ "LocalTime", func_sig_LocalTime_1 },
	{ "LockMainPower", func_sig_LockMainPower_1 },
	{ "Lseek", func_sig_Lseek_1 },
	{ "MoveFocusLensToDistance", func_sig_MoveFocusLensToDistance_1 },
	{ "MoveZoomLensWithPoint", func_sig_MoveZoomLensWithPoint_1 },
	{ "NewTaskShell", func_sig_NewTaskShell_1 },
	{ "Open", func_sig_Open_1 },
	{ "Read", func_sig_Read_1 },
	{ "ReadFastDir", func_sig_ReadFastDir_1 },
	{ "RefreshPhysicalScreen", func_sig_RefreshPhysicalScreen_1 },
	{ "Remove", func_sig_Remove_1 },
	{ "SetAutoShutdownTime", func_sig_SetAutoShutdownTime_1 },
	{ "SetParameterData", func_sig_SetParameterData_1 },
	{ "SetPropertyCase", func_sig_SetPropertyCase_1 },
	{ "SleepTask", func_sig_SleepTask_1 },
	{ "TakeSemaphore", func_sig_TakeSemaphore_1 },
	{ "UIFS_WriteFirmInfoToFile", func_sig_UIFS_WriteFirmInfoToFile_1 },
	{ "UnlockMainPower", func_sig_UnlockMainPower_1 },
	{ "UpdateMBROnFlash", func_sig_UpdateMBROnFlash_1 },
	{ "VbattGet", func_sig_VbattGet_1 },
	{ "Write", func_sig_Write_1 },
	{ "_log", func_sig__log_1 },
	{ "_log10", func_sig__log10_1 },
	{ "_pow", func_sig__pow_1 },
	{ "_sqrt", func_sig__sqrt_1 },
	{ "close", func_sig_close_1 },
	{ "closedir", func_sig_closedir_1 },
	{ "closefastdir", func_sig_closefastdir_1 },
	{ "free", func_sig_free_1 },
	{ "kbd_p1_f", func_sig_kbd_p1_f_1 },
	{ "kbd_p1_f_cont", func_sig_kbd_p1_f_cont_1 },
	{ "kbd_p2_f", func_sig_kbd_p2_f_1 },
	{ "kbd_pwr_off", func_sig_kbd_pwr_off_1 },
	{ "kbd_pwr_on", func_sig_kbd_pwr_on_1 },
	{ "kbd_read_keys", func_sig_kbd_read_keys_1 },
	{ "kbd_read_keys_r2", func_sig_kbd_read_keys_r2_1 },
	{ "lseek", func_sig_lseek_1 },
	{ "malloc", func_sig_malloc_1 },
	{ "memcmp", func_sig_memcmp_1 },
	{ "memcpy", func_sig_memcpy_1 },
	{ "memset", func_sig_memset_1 },
	{ "mkdir", func_sig_mkdir_1 },
	{ "open", func_sig_open_1 },
	{ "opendir", func_sig_opendir_1 },
	{ "openfastdir", func_sig_openfastdir_1 },
	{ "qsort", func_sig_qsort_1 },
	{ "rand", func_sig_rand_1 },
	{ "read", func_sig_read_1 },
	{ "readfastdir", func_sig_readfastdir_1 },
	{ "rename", func_sig_rename_1 },
	{ "srand", func_sig_srand_1 },
	{ "stat", func_sig_stat_1 },
	{ "strcat", func_sig_strcat_1 },
	{ "strchr", func_sig_strchr_1 },
	{ "strcmp", func_sig_strcmp_1 },
	{ "strcpy", func_sig_strcpy_1 },
	{ "strlen", func_sig_strlen_1 },
	{ "strncmp", func_sig_strncmp_1 },
	{ "strncpy", func_sig_strncpy_1 },
	{ "strrchr", func_sig_strrchr_1 },
	{ "strtol", func_sig_strtol_1 },
	{ "time", func_sig_time_1 },
	{ "vsprintf", func_sig_vsprintf_1 },
	{ "write", func_sig_write_1 },
	{ NULL }
};
