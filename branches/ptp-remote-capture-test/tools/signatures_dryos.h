
static FuncSig func_sig_CreateJumptable_1[] = {
	{   0, 0xe00f0000, 0xf00ff000 }, // ldr:8:0xE59F039C
	{   1, 0xe00f1000, 0xf00ff000 }, // add:10:0xE28F1E39
	{   2, 0xe5801000, 0xfdfff000 }, // str:4:0xE5801000
	{   3, 0xe00f1000, 0xf00ff000 }, // ldr:8:0xE59F1394
	{   4, 0xe5801000, 0xfdfff000 }, // str:4:0xE5801004
	{   5, 0xe00f1000, 0xf00ff000 }, // ldr:8:0xE59F1390
	{   6, 0xe5801000, 0xfdfff000 }, // str:4:0xE5801008
	{   7, 0xe00f1000, 0xf00ff000 }, // ldr:8:0xE59F138C
	{   8, 0xe5801000, 0xfdfff000 }, // str:4:0xE580100C
	{   9, 0xe00f1000, 0xf00ff000 }, // ldr:8:0xE59F1388
	{  10, 0xe5801000, 0xfdfff000 }, // str:4:0xE5801010
	{  11, 0xe00f1000, 0xf00ff000 }, // ldr:8:0xE59F1384
	{  12, 0xe5801000, 0xfdfff000 }, // str:4:0xE5801014
	{  13, 0xe00f1000, 0xf00ff000 }, // ldr:8:0xE59F1380
	{  14, 0xe5801000, 0xfdfff000 }, // str:4:0xE5801018
	{  15, 0xe00f1000, 0xf00ff000 }, // ldr:8:0xE59F137C
	{  16, 0xe5801000, 0xfdfff000 }, // str:4:0xE580101C
	{  17, 0xe00f1000, 0xf00ff000 }, // ldr:8:0xE59F1378
	{  18, 0xe5801000, 0xfdfff000 }, // str:4:0xE5801020
	{  19, 0xe00f1000, 0xf00ff000 }, // ldr:8:0xE59F1374
	{  20, 0xe5801000, 0xfdfff000 }, // str:4:0xE5801024
	{  21, 0xe00f1000, 0xf00ff000 }, // ldr:8:0xE59F1370
	{  22, 0xe5801000, 0xfdfff000 }, // str:4:0xE5801028
	{  23, 0xe00f1000, 0xf00ff000 }, // ldr:8:0xE59F136C
	{  24, 0xe5801000, 0xfdfff000 }, // str:4:0xE580102C
	{  25, 0xe00f1000, 0xf00ff000 }, // ldr:8:0xE59F1368
	{  26, 0xe5801000, 0xfdfff000 }, // str:4:0xE5801030
	{  27, 0xe00f1000, 0xf00ff000 }, // ldr:8:0xE59F1364
	{  28, 0xe5801000, 0xfdfff000 }, // str:4:0xE5801034
	{  29, 0xe00f1000, 0xf00ff000 }, // ldr:8:0xE59F1360
	{  30, 0xe5801000, 0xfdfff000 }, // str:4:0xE5801038
	{  31, 0xe00f1000, 0xf00ff000 }, // ldr:8:0xE59F135C
	/* 32/32 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_GetSystemTime_1[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4008
	{   1, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A0000D
	{   2, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBF906F7
	{   3, 0xe59d0000, 0xfdfff000 }, // ldr:4:0xE59D0000
	{   4, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD9000
	{   5, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D401F
	{   6, 0xe1a0e000, 0xfdfff000 }, // mov:6:0xE1A0E001
	{   7, 0xe00f1000, 0xf00ff000 }, // ldr:8:0xE59F139C
	{   8, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE1A0400D
	{   9, 0xe8910000, 0xffff0000 }, // ldm:5:0xE891100E
	{  10, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500004
	{  11, 0x315e0000, 0xfdfff000 }, // cmp:7:0x335E0050
	{  12, 0x21a00000, 0xfdfff000 }, // mov:6:0x23A00001
	{  13, 0xe8840000, 0xffff0000 }, // stm:5:0xE884100E
	{  14, 0x0a000000, 0x0f000000 }, // b, bl:3:0x2A00000D
	{  15, 0xe00f1000, 0xf00ff000 }, // ldr:8:0xE51F1118
	{  16, 0xe00f3000, 0xf00ff000 }, // ldr:8:0xE59F337C
	{  18, 0xe1520000, 0xfdfff000 }, // cmp:7:0xE3520000
	{  19, 0x1583e000, 0xfdfff000 }, // str:4:0x1583E108
	{  20, 0x11a02000, 0xfdfff000 }, // mov:6:0x13A02E1A
	{  21, 0x0583e000, 0xfdfff000 }, // str:4:0x0583E104
	{  22, 0xe5940000, 0xfdfff000 }, // ldr:4:0xE7940100
	{  23, 0x01a02000, 0xfdfff000 }, // mov:6:0x03A02E19
	{  24, 0xe5802000, 0xfdfff000 }, // str:4:0xE5802000
	{  25, 0x11a00000, 0xfdfff000 }, // mov:6:0x13A00000
	{  26, 0x01a00000, 0xfdfff000 }, // mov:6:0x03A00001
	{  27, 0xe5c10000, 0xfdfff000 }, // strb:4:0xE5C10000
	{  28, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE3A00000
	{  29, 0xe080d000, 0xfdf0f000 }, // add:6:0xE28DD010
	{  30, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD8010
	{  31, 0xe0801000, 0xfdf0f000 }, // add:6:0xE2801004
	/* 31/32 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_kbd_pwr_on_1[] = {
	{   0, 0xe00f0000, 0xf00ff000 }, // ldr:8:0xE59F00F8
	{   1, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4010
	{   2, 0xe5901000, 0xfdfff000 }, // ldr:4:0xE59010E0
	{   4, 0xe5801000, 0xfdfff000 }, // str:4:0xE58010E0
	{   5, 0xe00f2000, 0xf00ff000 }, // sub:10:0xE24F2028
	{   6, 0xe0801000, 0xfdf0f000 }, // add:6:0xE2821000
	{   7, 0xe1a03000, 0xfdfff000 }, // mov:6:0xE3A03000
	{   8, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE3A00032
	{   9, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB0081BD
	{  10, 0xe1100001, 0xfdffffff }, // tst:7:0xE3100001
	{  11, 0x11500000, 0xfdfff000 }, // cmp:7:0x13500015
	{  12, 0x11a01000, 0xfdfff000 }, // mov:6:0x13A010EC
	{  13, 0x100f0000, 0xf00ff000 }, // add:10:0x128F00C8
	{  14, 0x0b000000, 0x0f000000 }, // b, bl:3:0x1BFF53FC
	{  15, 0xe00f0000, 0xf00ff000 }, // ldr:8:0xE59F00B8
	{  16, 0xe00f1000, 0xf00ff000 }, // ldr:8:0xE59F10C8
	{  17, 0xe5900000, 0xfdfff000 }, // ldr:4:0xE5900004
	{  18, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD4010
	{  19, 0xe1a03000, 0xfdfff000 }, // mov:6:0xE3A030ED
	{  20, 0xe00f2000, 0xf00ff000 }, // add:10:0xE28F20AC
	{  21, 0x0a000000, 0x0f000000 }, // b, bl:3:0xEAFF53AF
	{  22, 0xe00f0000, 0xf00ff000 }, // ldr:8:0xE59F00A0
	{  23, 0xe5901000, 0xfdfff000 }, // ldr:4:0xE59010E0
	{  24, 0xe1c11000, 0xfdfff000 }, // bic:6:0xE3C11002
	{  25, 0xe5801000, 0xfdfff000 }, // str:4:0xE58010E0
	{  27, 0xe5900000, 0xfdfff000 }, // ldr:4:0xE5900000
	{  28, 0xe2000000, 0xfffff000 }, // and:7:0xE2000001
	{  30, 0xe5801000, 0xfdfff000 }, // str:4:0xE5801000
	/* 28/32 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_kbd_pwr_off_1[] = {
	{   0, 0xe00f0000, 0xf00ff000 }, // ldr:8:0xE59F00A0
	{   1, 0xe5901000, 0xfdfff000 }, // ldr:4:0xE59010E0
	{   2, 0xe1c11000, 0xfdfff000 }, // bic:6:0xE3C11002
	{   3, 0xe5801000, 0xfdfff000 }, // str:4:0xE58010E0
	{   5, 0xe5900000, 0xfdfff000 }, // ldr:4:0xE5900000
	{   6, 0xe2000000, 0xfffff000 }, // and:7:0xE2000001
	{   8, 0xe5801000, 0xfdfff000 }, // str:4:0xE5801000
	{  10, 0xe00f0000, 0xf00ff000 }, // ldr:8:0xE59F0078
	{  11, 0xe5901000, 0xfdfff000 }, // ldr:4:0xE59010E0
	{  13, 0xe5801000, 0xfdfff000 }, // str:4:0xE58010E0
	{  15, 0xe00f0000, 0xf00ff000 }, // ldr:8:0xE59F0064
	{  16, 0xe5901000, 0xfdfff000 }, // ldr:4:0xE59010E0
	{  17, 0xe1c11000, 0xfdfff000 }, // bic:6:0xE3C11002
	{  18, 0xe5801000, 0xfdfff000 }, // str:4:0xE58010E0
	{  20, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4070
	{  21, 0xe1a05000, 0xfdfff000 }, // mov:6:0xE1A05000
	{  22, 0xe00f0000, 0xf00ff000 }, // ldr:8:0xE59F0044
	{  23, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE3A04000
	{  24, 0xe5900000, 0xfdfff000 }, // ldr:4:0xE5900000
	{  25, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500000
	{  26, 0x11a01000, 0xfdfff000 }, // mov:6:0x13A010C7
	{  27, 0x100f0000, 0xf00ff000 }, // add:10:0x128F0038
	{  28, 0x0b000000, 0x0f000000 }, // b, bl:3:0x1BFF53D8
	{  29, 0xe00f0000, 0xf00ff000 }, // ldr:8:0xE59F0040
	{  30, 0xe1550000, 0xfdfff000 }, // cmp:7:0xE3550000
	{  31, 0x05904000, 0xfdfff000 }, // ldr:4:0x0590401C
	/* 26/32 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_GetParameterData_1[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D41F0
	{   1, 0xe00f5000, 0xf00ff000 }, // ldr:8:0xE51F5CFC
	{   2, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE1A04000
	{   3, 0xe5950000, 0xfdfff000 }, // ldr:4:0xE5950000
	{   4, 0xe00f6000, 0xf00ff000 }, // ldr:8:0xE59F6260
	{   5, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500000
	{   6, 0xe1a07000, 0xfdfff000 }, // mov:6:0xE1A07001
	{   7, 0x000f0000, 0xf00ff000 }, // ldr:8:0x059F01E4
	{   8, 0x01a01000, 0xfdfff000 }, // mov:6:0x01A01006
	{   9, 0xe1a08000, 0xfdfff000 }, // mov:6:0xE1A08002
	{  10, 0x0b000000, 0x0f000000 }, // b, bl:3:0x0BFBBEAC
	{  11, 0xe1140901, 0xfdffffff }, // tst:7:0xE3140901
	{  12, 0x000f0000, 0xf00ff000 }, // ldr:8:0x059F01D0
	{  13, 0x01a01000, 0xfdfff000 }, // mov:6:0x01A01006
	{  14, 0x0b000000, 0x0f000000 }, // b, bl:3:0x0BFBBEA8
	{  15, 0xe1c44000, 0xfdfff000 }, // bic:6:0xE3C44901
	{  16, 0xe1540000, 0xfdfff000 }, // cmp:7:0xE3540072
	{  17, 0x200f0000, 0xf00ff000 }, // ldr:8:0x259F01BC
	{  18, 0x21a01000, 0xfdfff000 }, // mov:6:0x21A01006
	{  19, 0x0b000000, 0x0f000000 }, // b, bl:3:0x2BFBBEA3
	{  20, 0xe00f3000, 0xf00ff000 }, // ldr:8:0xE59F3224
	{  21, 0xe00f2000, 0xf00ff000 }, // ldr:8:0xE59F21AC
	{  22, 0xe00f1000, 0xf00ff000 }, // ldr:8:0xE51F1D24
	{  23, 0xe5950000, 0xfdfff000 }, // ldr:4:0xE5950008
	{  24, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFBBE8F
	{  25, 0xe00f0000, 0xf00ff000 }, // ldr:8:0xE51F0D3C
	{  26, 0xe1a03000, 0xfdfff000 }, // mov:6:0xE1A03008
	{  27, 0xe5901000, 0xfdfff000 }, // ldr:4:0xE5901004
	{  28, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00004
	{  29, 0xe1a02000, 0xfdfff000 }, // mov:6:0xE1A02007
	{  30, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB030271
	{  31, 0xe5950000, 0xfdfff000 }, // ldr:4:0xE5950008
	/* 32/32 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_SetParameterData_1[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D41FC
	{   1, 0xe00f5000, 0xf00ff000 }, // ldr:8:0xE51F5C6C
	{   2, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE1A04000
	{   3, 0xe5950000, 0xfdfff000 }, // ldr:4:0xE5950000
	{   4, 0xe1a06000, 0xfdfff000 }, // mov:6:0xE1A06001
	{   5, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500000
	{   6, 0x000f0000, 0xf00ff000 }, // ldr:8:0x059F0278
	{   7, 0x01a01000, 0xfdfff000 }, // mov:6:0x03A01FF7
	{   8, 0xe1a07000, 0xfdfff000 }, // mov:6:0xE1A07002
	{   9, 0x0b000000, 0x0f000000 }, // b, bl:3:0x0BFBBED1
	{  10, 0xe1140901, 0xfdffffff }, // tst:7:0xE3140901
	{  11, 0x000f0000, 0xf00ff000 }, // ldr:8:0x059F0264
	{  12, 0x01a01000, 0xfdfff000 }, // mov:6:0x03A01FF7
	{  13, 0x0b000000, 0x0f000000 }, // b, bl:3:0x0BFBBECD
	{  14, 0xe1c44000, 0xfdfff000 }, // bic:6:0xE3C44901
	{  15, 0xe1540000, 0xfdfff000 }, // cmp:7:0xE3540072
	{  16, 0x200f0000, 0xf00ff000 }, // ldr:8:0x259F0250
	{  17, 0x21a01000, 0xfdfff000 }, // mov:6:0x23A01FF7
	{  18, 0x0b000000, 0x0f000000 }, // b, bl:3:0x2BFBBEC8
	{  19, 0xe00f3000, 0xf00ff000 }, // ldr:8:0xE59F32B0
	{  20, 0xe00f2000, 0xf00ff000 }, // ldr:8:0xE59F2240
	{  21, 0xe00f1000, 0xf00ff000 }, // ldr:8:0xE51F1C90
	{  22, 0xe5950000, 0xfdfff000 }, // ldr:4:0xE5950008
	{  23, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFBBEB4
	{  24, 0xe1a03000, 0xfdfff000 }, // mov:6:0xE3A03000
	{  25, 0xe1a02000, 0xfdfff000 }, // mov:6:0xE3A02001
	{  26, 0xe1cd2000, 0xfdfff000 }, // bic:6:0xE1CD20F0
	{  27, 0xe00f0000, 0xf00ff000 }, // ldr:8:0xE51F0CB4
	{  28, 0xe1a03000, 0xfdfff000 }, // mov:6:0xE1A03007
	{  29, 0xe5901000, 0xfdfff000 }, // ldr:4:0xE5901004
	{  30, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00004
	{  31, 0xe1a02000, 0xfdfff000 }, // mov:6:0xE1A02006
	/* 32/32 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_open_1[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D40FE
	{   1, 0xe1a07000, 0xfdfff000 }, // mov:6:0xE1A07002
	{   2, 0xe1a06000, 0xfdfff000 }, // mov:6:0xE1A06001
	{   3, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE1A04000
	{   4, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFFE9C
	{   5, 0xe0505000, 0xfdfff000 }, // sub:6:0xE2505000
	{   6, 0x0a000000, 0x0f000000 }, // b, bl:3:0xAA000002
	{   7, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFE576
	{   8, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01017
	{   9, 0x0a000000, 0x0f000000 }, // b, bl:3:0xEA000009
	{  10, 0xe0802000, 0xfdf0f000 }, // add:6:0xE28D2008
	{  11, 0xe0801000, 0xfdf0f000 }, // add:6:0xE28D1004
	{  12, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00004
	{  13, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFFFBC
	{  14, 0xe1b04000, 0xfdfff000 }, // mov:6:0xE1B04000
	{  15, 0x0a000000, 0x0f000000 }, // b, bl:3:0x1A000005
	{  16, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00005
	{  17, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFFEB1
	{  18, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFE56B
	{  19, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01002
	{  20, 0xe5801000, 0xfdfff000 }, // str:4:0xE5801000
	{  21, 0x0a000000, 0x0f000000 }, // b, bl:3:0xEA00000D
	{  22, 0xe00f0000, 0xf00ff000 }, // ldr:8:0xE59F0420
	{  23, 0xe59d1000, 0xfdfff000 }, // ldr:4:0xE59D1008
	{  24, 0xe58d5000, 0xfdfff000 }, // str:4:0xE58D5000
	{  25, 0xe5900000, 0xfdfff000 }, // ldr:4:0xE7900101
	{  26, 0xe59d1000, 0xfdfff000 }, // ldr:4:0xE59D1004
	{  27, 0xe590c000, 0xfdfff000 }, // ldr:4:0xE590C000
	{  28, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00004
	{  29, 0xe1a03000, 0xfdfff000 }, // mov:6:0xE1A03007
	{  30, 0xe1a02000, 0xfdfff000 }, // mov:6:0xE1A02006
	/* 31/32 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_close_1[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D401C
	{   1, 0xe1a02000, 0xfdfff000 }, // mov:6:0xE1A0200D
	{   2, 0xe0801000, 0xfdf0f000 }, // add:6:0xE28D1004
	{   3, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE1A04000
	{   4, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFFEA4
	{   5, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500000
	{   6, 0x0a000000, 0x0f000000 }, // b, bl:3:0xAA000004
	{   7, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFE54A
	{   8, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01009
	{   9, 0xe5801000, 0xfdfff000 }, // str:4:0xE5801000
	{  10, 0xe1e00000, 0xfdfff000 }, // mvn:6:0xE3E00000
	{  11, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD801C
	{  12, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00004
	{  13, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFFE89
	{  14, 0xe00f0000, 0xf00ff000 }, // ldr:8:0xE59F0390
	{  15, 0xe59d1000, 0xfdfff000 }, // ldr:4:0xE59D1004
	{  16, 0xe5900000, 0xfdfff000 }, // ldr:4:0xE7900101
	{  17, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE1A01004
	{  18, 0xe5902000, 0xfdfff000 }, // ldr:4:0xE5902004
	{  19, 0xe59d0000, 0xfdfff000 }, // ldr:4:0xE59D0000
	{  21, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD801C
	/* 21/22 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_Remove_1[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4038
	{   1, 0xe1a05000, 0xfdfff000 }, // mov:6:0xE1A05000
	{   2, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFFFF2
	{   3, 0xe1b04000, 0xfdfff000 }, // mov:6:0xE1B04000
	{   4, 0x0a000000, 0x0f000000 }, // b, bl:3:0x1A000008
	{   5, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00005
	{   6, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB00AADC
	{   7, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE1A01005
	{   8, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A0000D
	{   9, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB000176
	{  10, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A0000D
	{  11, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB000185
	{  12, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500000
	{  13, 0x01e04000, 0xfdfff000 }, // mvn:6:0x03E04000
	{  14, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00004
	{  15, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD8038
	/* 16/16 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_GetDrive_ClusterSize_1[] = {
	{   0, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500001
	{   1, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4010
	{   2, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE1A04000
	{   3, 0xa00f0000, 0xf00ff000 }, // ldr:8:0xA59F0058
	{   4, 0xa00f1000, 0xf00ff000 }, // ldr:8:0xA59F1084
	{   5, 0x0b000000, 0x0f000000 }, // b, bl:3:0xABFF32EE
	{   6, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE3A00017
	{   7, 0xe00f1000, 0xf00ff000 }, // ldr:8:0xE51F1778
	{   8, 0xe0000094, 0xffffffff }, // mul:11:0xE0000094
	{   9, 0xe0800000, 0xfdf0f000 }, // add:6:0xE0810100
	{  10, 0xe5900000, 0xfdfff000 }, // ldr:4:0xE5900054
	{  11, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD4010
	{  12, 0x0a000000, 0x0f000000 }, // b, bl:3:0xEA0008E5
	/* 13/13 */
	{ -1, 12, -2 },
	{   0, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{   1, 0x15900064, 0xfdffffff }, // ldr:4:0x15900064
	{   2, 0x01a00000, 0xfdffffff }, // mov:6:0x03A00000
	/* 3/4 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_GetDrive_TotalClusters_1[] = {
	{   0, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500001
	{   1, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4010
	{   2, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE1A04000
	{   3, 0xa00f0000, 0xf00ff000 }, // ldr:8:0xA59F0024
	{   4, 0xa1a01000, 0xfdfff000 }, // mov:6:0xA3A01E57
	{   5, 0x0b000000, 0x0f000000 }, // b, bl:3:0xABFF32E1
	{   6, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE3A00017
	{   7, 0xe00f1000, 0xf00ff000 }, // ldr:8:0xE51F17AC
	{   8, 0xe0000094, 0xffffffff }, // mul:11:0xE0000094
	{   9, 0xe0800000, 0xfdf0f000 }, // add:6:0xE0810100
	{  10, 0xe5900000, 0xfdfff000 }, // ldr:4:0xE5900054
	{  11, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD4010
	{  12, 0x0a000000, 0x0f000000 }, // b, bl:3:0xEA0008DC
	/* 13/13 */
	{ -1, 12, -2 },
	{   0, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{   1, 0x15900054, 0xfdffffff }, // ldr:4:0x15900054
	{   2, 0x10400001, 0xfdffffff }, // sub:6:0x12400001
	{   3, 0x01a00000, 0xfdffffff }, // mov:6:0x03A00000
	/* 4/5 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_GetDrive_FreeClusters_1[] = {
	{   0, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500001
	{   1, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4010
	{   2, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE1A04000
	{   3, 0xa00f0000, 0xf00ff000 }, // ldr:8:0xA51F0048
	{   4, 0xa00f1000, 0xf00ff000 }, // ldr:8:0xA59F12E0
	{   5, 0x0b000000, 0x0f000000 }, // b, bl:3:0xABFF32C6
	{   6, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE3A00017
	{   7, 0xe00f1000, 0xf00ff000 }, // ldr:8:0xE51F1818
	{   8, 0xe0000094, 0xffffffff }, // mul:11:0xE0000094
	{   9, 0xe0800000, 0xfdf0f000 }, // add:6:0xE0810100
	{  10, 0xe5900000, 0xfdfff000 }, // ldr:4:0xE5900054
	{  11, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD4010
	{  12, 0x0a000000, 0x0f000000 }, // b, bl:3:0xEA0008C6
	/* 13/13 */
	{ -1, 12, -2 },
	{   0, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{   1, 0x15900060, 0xfdffffff }, // ldr:4:0x15900060
	{   2, 0x01a00000, 0xfdffffff }, // mov:6:0x03A00000
	/* 3/4 */
	{ -1, -1, -1 },
};

static FuncSig func_sig__sqrt_1[] = {
	{   0, 0xe1a0c000, 0xfdfff000 }, // mov:6:0xE3A0C207
	{   2, 0xe111000c, 0xfdffffff }, // tst:7:0xE111000C
	{   3, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4070
	{   4, 0x0a000000, 0x0f000000 }, // b, bl:3:0x0A000044
	{   5, 0xe1dce000, 0xfdfff000 }, // bic:6:0xE1DCE001
	{   6, 0x0a000000, 0x0f000000 }, // b, bl:3:0x0A000047
	{   7, 0xe1110102, 0xfdffffff }, // tst:7:0xE3110102
	{   8, 0x0a000000, 0x0f000000 }, // b, bl:3:0x1A00004D
	{   9, 0xe1a0c000, 0xfdfff000 }, // mov:6:0xE1A0CA21
	{  10, 0xe1c11000, 0xfdfff000 }, // bic:6:0xE1C11A0C
	{  12, 0xe080c000, 0xfdf0f000 }, // add:6:0xE28CC0FD
	{  13, 0xe1b0c000, 0xfdfff000 }, // mov:6:0xE1B0C0AC
	{  14, 0xe080c000, 0xfdf0f000 }, // add:6:0xE28CCD06
	{  15, 0x0a000000, 0x0f000000 }, // b, bl:3:0x3A000001
	{  16, 0xe1b00000, 0xfdfff000 }, // mov:6:0xE1B00080
	{  18, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE1A01501
	{  20, 0xe0411000, 0xfdfff000 }, // sub:6:0xE2411101
	{  21, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00500
	{  22, 0xe1a02000, 0xfdfff000 }, // mov:6:0xE3A02101
	{  23, 0xe1a03000, 0xfdfff000 }, // mov:6:0xE3A03000
	{  24, 0xe1a0e000, 0xfdfff000 }, // mov:6:0xE3A0E201
	{  25, 0xe0514000, 0xfdfff000 }, // sub:6:0xE0514002
	{  26, 0x20544000, 0xfdfff000 }, // sub:6:0x2054400E
	{  27, 0x21a01000, 0xfdfff000 }, // mov:6:0x21A01004
	{  28, 0x20802000, 0xfdf0f000 }, // add:6:0x2082208E
	{  29, 0xe1b00000, 0xfdfff000 }, // mov:6:0xE1B00080
	{  31, 0xe1b0e000, 0xfdfff000 }, // mov:6:0xE1B0E0AE
	/* 27/32 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_rand_1[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4070
	{   1, 0xe00f4000, 0xf00ff000 }, // ldr:8:0xE59F4064
	{   2, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01000
	{   3, 0xe5940000, 0xfdfff000 }, // ldr:4:0xE5940004
	{   4, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFCE68
	{   5, 0xe5940000, 0xfdfff000 }, // ldr:4:0xE5940000
	{   6, 0xe00f1000, 0xf00ff000 }, // ldr:8:0xE59F1054
	{   7, 0xe0000091, 0xffffffff }, // mul:11:0xE0000091
	{   8, 0xe1e01000, 0xfdfff000 }, // mvn:6:0xE3E01902
	{   9, 0xe0800000, 0xfdf0f000 }, // add:6:0xE2800A03
	{  10, 0xe0800000, 0xfdf0f000 }, // add:6:0xE2800039
	{  12, 0xe5840000, 0xfdfff000 }, // str:4:0xE5840000
	{  13, 0xe5940000, 0xfdfff000 }, // ldr:4:0xE5940004
	{  14, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFCE51
	{  15, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00005
	{  16, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD8070
	{  17, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4010
	{  18, 0xe00f2000, 0xf00ff000 }, // add:10:0xE28F2028
	{  19, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01002
	{  20, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE3A00001
	{  21, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFCDE8
	{  22, 0xe00f1000, 0xf00ff000 }, // ldr:8:0xE59F1010
	{  23, 0xe1700001, 0xfdffffff }, // cmn:7:0xE3700001
	{  24, 0xe5810000, 0xfdfff000 }, // str:4:0xE5810004
	{  25, 0x01e00000, 0xfdfff000 }, // mvn:6:0x03E00000
	{  26, 0x11a00000, 0xfdfff000 }, // mov:6:0x13A00000
	{  27, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD8010
	{  29, 0x41c64000, 0xfdfff000 }, // bic:6:0x41C64E6D
	{  30, 0x646e6000, 0xfdfff000 }, // strb:4:0x646E6172
	{  31, 0x006d6553, 0xfdffffff }, // rsb:6:0x006D6553
	/* 30/32 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_srand_1[] = {
	{   0, 0xe00f1000, 0xf00ff000 }, // ldr:8:0xE59F1074
	{   1, 0xe5810000, 0xfdfff000 }, // str:4:0xE5810000
	{   3, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4070
	{   4, 0xe00f4000, 0xf00ff000 }, // ldr:8:0xE59F4064
	{   5, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01000
	{   6, 0xe5940000, 0xfdfff000 }, // ldr:4:0xE5940004
	{   7, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFCE68
	{   8, 0xe5940000, 0xfdfff000 }, // ldr:4:0xE5940000
	{   9, 0xe00f1000, 0xf00ff000 }, // ldr:8:0xE59F1054
	{  10, 0xe0000091, 0xffffffff }, // mul:11:0xE0000091
	{  11, 0xe1e01000, 0xfdfff000 }, // mvn:6:0xE3E01902
	{  12, 0xe0800000, 0xfdf0f000 }, // add:6:0xE2800A03
	{  13, 0xe0800000, 0xfdf0f000 }, // add:6:0xE2800039
	{  15, 0xe5840000, 0xfdfff000 }, // str:4:0xE5840000
	{  16, 0xe5940000, 0xfdfff000 }, // ldr:4:0xE5940004
	{  17, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFCE51
	{  18, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00005
	{  19, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD8070
	{  20, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4010
	{  21, 0xe00f2000, 0xf00ff000 }, // add:10:0xE28F2028
	{  22, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01002
	{  23, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE3A00001
	{  24, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFCDE8
	{  25, 0xe00f1000, 0xf00ff000 }, // ldr:8:0xE59F1010
	{  26, 0xe1700001, 0xfdffffff }, // cmn:7:0xE3700001
	{  27, 0xe5810000, 0xfdfff000 }, // str:4:0xE5810004
	{  28, 0x01e00000, 0xfdfff000 }, // mvn:6:0x03E00000
	{  29, 0x11a00000, 0xfdfff000 }, // mov:6:0x13A00000
	{  30, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD8010
	/* 29/32 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_stat_1[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4070
	{   1, 0xe1a05000, 0xfdfff000 }, // mov:6:0xE1A05001
	{   2, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01000
	{   3, 0xe1a02000, 0xfdfff000 }, // mov:6:0xE3A02000
	{   4, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFD3D8
	{   5, 0xe0504000, 0xfdfff000 }, // sub:6:0xE2504000
	{   6, 0xb1e00000, 0xfdfff000 }, // mvn:6:0xB3E00000
	{   7, 0xb8bd0000, 0xffff0000 }, // ldm:5:0xB8BD8070
	{   8, 0xe1a02000, 0xfdfff000 }, // mov:6:0xE1A02005
	{   9, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01012
	{  10, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00004
	{  11, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFD4DB
	{  12, 0xe1a05000, 0xfdfff000 }, // mov:6:0xE1A05000
	{  13, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00004
	{  14, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFD3FA
	{  15, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00005
	{  16, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD8070
	{  17, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4010
	{  18, 0xe04dd000, 0xfdfff000 }, // sub:6:0xE24DD038
	{  19, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE1A04001
	{  20, 0xe0801000, 0xfdf0f000 }, // add:6:0xE28D1004
	{  21, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFFFE9
	{  22, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500000
	{  23, 0x11e00000, 0xfdfff000 }, // mvn:6:0x13E00000
	{  24, 0x0a000000, 0x0f000000 }, // b, bl:3:0x1A00000C
	{  25, 0xe59d0000, 0xfdfff000 }, // ldr:4:0xE59D000C
	{  26, 0xe5840000, 0xfdfff000 }, // str:4:0xE5840000
	{  28, 0xe5840000, 0xfdfff000 }, // str:4:0xE5840004
	{  29, 0xe59d0000, 0xfdfff000 }, // ldr:4:0xE59D0020
	{  30, 0xe5840000, 0xfdfff000 }, // str:4:0xE5840008
	{  31, 0xe59d0000, 0xfdfff000 }, // ldr:4:0xE59D001C
	/* 31/32 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_OpenFastDir_1[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4070
	{   1, 0xe1a05000, 0xfdfff000 }, // mov:6:0xE1A05000
	{   2, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE3A00014
	{   3, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBF95F20
	{   4, 0xe1b04000, 0xfdfff000 }, // mov:6:0xE1B04000
	{   5, 0x01a01000, 0xfdfff000 }, // mov:6:0x03A01059
	{   6, 0x000f0000, 0xf00ff000 }, // add:10:0x028F0E26
	{   7, 0x0b000000, 0x0f000000 }, // b, bl:3:0x0BF9295C
	{   8, 0xe1e00000, 0xfdfff000 }, // mvn:6:0xE3E00000
	{   9, 0xe5840000, 0xfdfff000 }, // str:4:0xE5840000
	{  10, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE3A00902
	{  11, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBF95F44
	{  12, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01902
	{  13, 0xe9840000, 0xffff0000 }, // stm:5:0xE9840003
	{  14, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01000
	{  15, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500000
	{  16, 0xe5841000, 0xfdfff000 }, // str:4:0xE584100C
	{  17, 0xe5841000, 0xfdfff000 }, // str:4:0xE5841010
	{  18, 0x01a01000, 0xfdfff000 }, // mov:6:0x03A01060
	{  19, 0x000f0000, 0xf00ff000 }, // add:10:0x028F0F8B
	{  20, 0x0b000000, 0x0f000000 }, // b, bl:3:0x0BF9294F
	{  21, 0xe1a02000, 0xfdfff000 }, // mov:6:0xE3A02F49
	{  22, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01000
	{  23, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00005
	{  24, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBF94D26
	{  25, 0xe1700001, 0xfdffffff }, // cmn:7:0xE3700001
	{  26, 0xe5840000, 0xfdfff000 }, // str:4:0xE5840000
	{  27, 0x0a000000, 0x0f000000 }, // b, bl:3:0x0A000004
	{  28, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00004
	{  29, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFFFB0
	{  30, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500002
	{  31, 0x11a00000, 0xfdfff000 }, // mov:6:0x11A00004
	/* 32/32 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_ReadFastDir_1[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D41F0
	{   1, 0xe1b05000, 0xfdfff000 }, // mov:6:0xE1B05000
	{   2, 0xe1a07000, 0xfdfff000 }, // mov:6:0xE1A07001
	{   3, 0xe1a06000, 0xfdfff000 }, // mov:6:0xE3A06000
	{   4, 0x0a000000, 0x0f000000 }, // b, bl:3:0x0A000027
	{   5, 0xe5952000, 0xfdfff000 }, // ldr:4:0xE5952010
	{   6, 0xe5954000, 0xfdfff000 }, // ldr:4:0xE595400C
	{   7, 0x0a000000, 0x0f000000 }, // b, bl:3:0xEA000014
	{   8, 0xe5950000, 0xfdfff000 }, // ldr:4:0xE5950004
	{   9, 0xe0800000, 0xfdf0f000 }, // add:6:0xE0800004
	{  11, 0xe1510000, 0xfdfff000 }, // cmp:7:0xE351000F
	{  12, 0x0a000000, 0x0f000000 }, // b, bl:3:0x0A00000A
	{  13, 0xe1110008, 0xfdffffff }, // tst:7:0xE3110008
	{  14, 0x0a000000, 0x0f000000 }, // b, bl:3:0x1A000008
	{  16, 0xe1510000, 0xfdfff000 }, // cmp:7:0xE35100E5
	{  17, 0x0a000000, 0x0f000000 }, // b, bl:3:0x0A000009
	{  18, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE1A01007
	{  19, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB000029
	{  20, 0xe0800000, 0xfdf0f000 }, // add:6:0xE2840020
	{  21, 0xe5850000, 0xfdfff000 }, // str:4:0xE585000C
	{  22, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00006
	{  23, 0x0a000000, 0x0f000000 }, // b, bl:3:0xEA000008
	{  25, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500000
	{  26, 0x01a00000, 0xfdfff000 }, // mov:6:0x03A00001
	{  27, 0x0a000000, 0x0f000000 }, // b, bl:3:0x0A000004
	{  28, 0xe0804000, 0xfdf0f000 }, // add:6:0xE2844020
	{  29, 0xe1520000, 0xfdfff000 }, // cmp:7:0xE1520004
	{  30, 0x0a000000, 0x0f000000 }, // b, bl:3:0xCAFFFFE8
	{  31, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE3A00002
	/* 29/32 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_closedir_1[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4010
	{   1, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE1A04000
	{   2, 0xe5900000, 0xfdfff000 }, // ldr:4:0xE5900000
	{   3, 0xe1700001, 0xfdffffff }, // cmn:7:0xE3700001
	{   4, 0x0b000000, 0x0f000000 }, // b, bl:3:0x1BF94CEB
	{   5, 0xe5940000, 0xfdfff000 }, // ldr:4:0xE5940004
	{   6, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBF95EFD
	{   7, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00004
	{   8, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD4010
	{   9, 0x0a000000, 0x0f000000 }, // b, bl:3:0xEAF95EC2
	/* 10/10 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_qsort_1[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D400E
	{   1, 0xe1cd2000, 0xfdfff000 }, // bic:6:0xE1CD20F0
	{   3, 0xe1120003, 0xfdffffff }, // tst:7:0xE3120003
	{   4, 0x000f2000, 0xf00ff000 }, // ldr:8:0x059F2020
	{   5, 0x0a000000, 0x0f000000 }, // b, bl:3:0x0A000002
	{   6, 0xe1120001, 0xfdffffff }, // tst:7:0xE3120001
	{   7, 0x100f2000, 0xf00ff000 }, // sub:10:0x124F2E4B
	{   8, 0x000f2000, 0xf00ff000 }, // sub:10:0x024F2E49
	{   9, 0xe58d2000, 0xfdfff000 }, // str:4:0xE58D2008
	{  10, 0xe1a02000, 0xfdfff000 }, // mov:6:0xE1A0200D
	{  11, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFFFC1
	{  12, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD900C
	/* 12/13 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_strncpy_1[] = {
	{   0, 0xe1a03000, 0xfdfff000 }, // mov:6:0xE1A03000
	{   1, 0x0a000000, 0x0f000000 }, // b, bl:3:0xEA000009
	{   3, 0xe15c0000, 0xfdfff000 }, // cmp:7:0xE35C0000
	{   4, 0xe4c3c000, 0xfdfff000 }, // strb:4:0xE4C3C001
	{   5, 0x0a000000, 0x0f000000 }, // b, bl:3:0x1A000005
	{   6, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01000
	{   7, 0xe0422000, 0xfdfff000 }, // sub:6:0xE2422001
	{   8, 0xe1720001, 0xfdffffff }, // cmn:7:0xE3720001
	{   9, 0x14c31000, 0xfdfff000 }, // strb:4:0x14C31001
	{  10, 0x0a000000, 0x0f000000 }, // b, bl:3:0x1AFFFFFB
	{  12, 0xe0522000, 0xfdfff000 }, // sub:6:0xE2522001
	{  13, 0x0a000000, 0x0f000000 }, // b, bl:3:0x2AFFFFF3
	/* 12/15 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_strrchr_1[] = {
	{   0, 0xe1a02000, 0xfdfff000 }, // mov:6:0xE3A02000
	{   1, 0xe2013000, 0xfffff000 }, // and:7:0xE20130FF
	{   3, 0xe1510000, 0xfdfff000 }, // cmp:7:0xE1510003
	{   4, 0x01a02000, 0xfdfff000 }, // mov:6:0x01A02000
	{   5, 0xe1510000, 0xfdfff000 }, // cmp:7:0xE3510000
	{   6, 0xe0800000, 0xfdf0f000 }, // add:6:0xE2800001
	{   7, 0x0a000000, 0x0f000000 }, // b, bl:3:0x1AFFFFF9
	{   8, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00002
	/* 8/10 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_strncmp_1[] = {
	{   0, 0x0a000000, 0x0f000000 }, // b, bl:3:0xEA000008
	{   2, 0xe1530000, 0xfdfff000 }, // cmp:7:0xE153000C
	{   3, 0x00800000, 0xfdf0f000 }, // add:6:0x02800001
	{   4, 0x00801000, 0xfdf0f000 }, // add:6:0x02811001
	{   5, 0x0a000000, 0x0f000000 }, // b, bl:3:0x0A000003
	{   8, 0xe0400000, 0xfdfff000 }, // sub:6:0xE0400001
	{  10, 0xe0522000, 0xfdfff000 }, // sub:6:0xE2522001
	{  11, 0x0a000000, 0x0f000000 }, // b, bl:3:0x3A000004
	{  13, 0xe1530000, 0xfdfff000 }, // cmp:7:0xE3530000
	{  15, 0x015c0000, 0xfdfff000 }, // cmp:7:0x035C0000
	{  16, 0x0a000000, 0x0f000000 }, // b, bl:3:0x1AFFFFEF
	{  17, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE3A00000
	/* 12/19 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_strchr_1[] = {
	{   0, 0xe2012000, 0xfffff000 }, // and:7:0xE20120FF
	{   2, 0xe1510000, 0xfdfff000 }, // cmp:7:0xE1510002
	{   4, 0xe1510000, 0xfdfff000 }, // cmp:7:0xE3510000
	{   5, 0xe0800000, 0xfdf0f000 }, // add:6:0xE2800001
	{   6, 0x0a000000, 0x0f000000 }, // b, bl:3:0x1AFFFFF9
	{   7, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE3A00000
	/* 6/9 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_strcat_1[] = {
	{   0, 0xe1a03000, 0xfdfff000 }, // mov:6:0xE1A03000
	{   2, 0xe1520000, 0xfdfff000 }, // cmp:7:0xE3520000
	{   3, 0x10800000, 0xfdf0f000 }, // add:6:0x12800001
	{   4, 0x0a000000, 0x0f000000 }, // b, bl:3:0x1AFFFFFB
	{   5, 0x0a000000, 0x0f000000 }, // b, bl:3:0xEA000001
	{   6, 0xe0801000, 0xfdf0f000 }, // add:6:0xE2811001
	{   7, 0xe4c02000, 0xfdfff000 }, // strb:4:0xE4C02001
	{   9, 0xe1520000, 0xfdfff000 }, // cmp:7:0xE3520000
	{  10, 0x0a000000, 0x0f000000 }, // b, bl:3:0x1AFFFFFA
	{  11, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01000
	{  12, 0xe5c01000, 0xfdfff000 }, // strb:4:0xE5C01000
	{  13, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00003
	/* 12/15 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_Fgets_Fut_1[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D41F0
	{   1, 0xe1b04000, 0xfdfff000 }, // mov:6:0xE1B04002
	{   2, 0xe1a06000, 0xfdfff000 }, // mov:6:0xE1A06000
	{   3, 0x01a00000, 0xfdfff000 }, // mov:6:0x03A00000
	{   4, 0xe1a07000, 0xfdfff000 }, // mov:6:0xE1A07001
	{   5, 0x08bd0000, 0xffff0000 }, // ldm:5:0x08BD81F0
	{   6, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01001
	{   7, 0xe0800000, 0xfdf0f000 }, // add:6:0xE2840020
	{   8, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB00004A
	{   9, 0xe1a05000, 0xfdfff000 }, // mov:6:0xE1A05000
	{  10, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00006
	{  11, 0xe1a02000, 0xfdfff000 }, // mov:6:0xE1A02004
	{  12, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE1A01007
	{  13, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB00B206
	{  14, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE1A04000
	{  15, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00005
	{  16, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB00004C
	{  17, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00004
	{  18, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD81F0
	/* 19/19 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_Feof_Fut_1[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4070
	{   1, 0xe1b04000, 0xfdfff000 }, // mov:6:0xE1B04000
	{   2, 0x01e00000, 0xfdfff000 }, // mvn:6:0x03E00000
	{   3, 0x08bd0000, 0xffff0000 }, // ldm:5:0x08BD8070
	{   4, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01001
	{   5, 0xe0800000, 0xfdf0f000 }, // add:6:0xE2840020
	{   6, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB000026
	{   7, 0xe1a05000, 0xfdfff000 }, // mov:6:0xE1A05000
	{   8, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00004
	{   9, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB00B234
	{  10, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE1A04000
	{  11, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00005
	{  12, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB00002A
	{  13, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00004
	/* 14/14 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_Fflush_Fut_1[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4070
	{   1, 0xe1b04000, 0xfdfff000 }, // mov:6:0xE1B04000
	{   2, 0x01e00000, 0xfdfff000 }, // mvn:6:0x03E00000
	{   3, 0x08bd0000, 0xffff0000 }, // ldm:5:0x08BD8070
	{   4, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01001
	{   5, 0xe0800000, 0xfdf0f000 }, // add:6:0xE2840020
	{   6, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB000017
	{   7, 0xe1a05000, 0xfdfff000 }, // mov:6:0xE1A05000
	{   8, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00004
	{   9, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB00B22B
	{  10, 0xe1a06000, 0xfdfff000 }, // mov:6:0xE1A06000
	{  11, 0xe0800000, 0xfdf0f000 }, // add:6:0xE2840020
	{  12, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFFD26
	{  13, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00005
	{  14, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB000019
	{  15, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00006
	{  16, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD8070
	/* 17/17 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_strftime_1[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4FFE
	{   1, 0xe00f9000, 0xf00ff000 }, // ldr:8:0xE59F940C
	{   2, 0xe1a0b000, 0xfdfff000 }, // mov:6:0xE3A0B025
	{   3, 0xe1a08000, 0xfdfff000 }, // mov:6:0xE1A08002
	{   4, 0xe0417000, 0xfdfff000 }, // sub:6:0xE2417001
	{   5, 0xe1a06000, 0xfdfff000 }, // mov:6:0xE1A06003
	{   6, 0xe1a05000, 0xfdfff000 }, // mov:6:0xE3A05000
	{   7, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE1A04000
	{   8, 0xe080a000, 0xfdf0f000 }, // add:6:0xE289A01C
	{   9, 0x0a000000, 0x0f000000 }, // b, bl:3:0xEA00012F
	{  10, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500025
	{  11, 0x0a000000, 0x0f000000 }, // b, bl:3:0x0A000004
	{  12, 0xe0805000, 0xfdf0f000 }, // add:6:0xE2855001
	{  13, 0xe1550000, 0xfdfff000 }, // cmp:7:0xE1550007
	{  14, 0x0a000000, 0x0f000000 }, // b, bl:3:0x8A000125
	{  15, 0xe5c40000, 0xfdfff000 }, // strb:4:0xE5C40000
	{  16, 0x0a000000, 0x0f000000 }, // b, bl:3:0xEA00011E
	{  18, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500059
	{  19, 0x0a000000, 0x0f000000 }, // b, bl:3:0x0A00010C
	{  20, 0x0a000000, 0x0f000000 }, // b, bl:3:0xCA00003A
	{  21, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE350004D
	{  22, 0x0a000000, 0x0f000000 }, // b, bl:3:0x0A0000BE
	{  23, 0x0a000000, 0x0f000000 }, // b, bl:3:0xCA000023
	{  24, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500042
	{  25, 0x0a000000, 0x0f000000 }, // b, bl:3:0x0A00007A
	{  26, 0x0a000000, 0x0f000000 }, // b, bl:3:0xCA000010
	{  27, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500025
	{  28, 0x0a000000, 0x0f000000 }, // b, bl:3:0x0A00010E
	{  29, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500041
	{  30, 0x0a000000, 0x0f000000 }, // b, bl:3:0x1A000112
	{  31, 0xe00f1000, 0xf00ff000 }, // ldr:8:0xE59F1398
	/* 31/32 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_mktime_ext_1[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4070
	{   1, 0xe5905000, 0xfdfff000 }, // ldr:4:0xE5905024
	{   2, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE1A04000
	{   3, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE3A00000
	{   4, 0xe5840000, 0xfdfff000 }, // str:4:0xE5840024
	{   5, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00004
	{   6, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFE4684
	{   7, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500000
	{   8, 0x01e00000, 0xfdfff000 }, // mvn:6:0x03E00000
	{   9, 0x08bd0000, 0xffff0000 }, // ldm:5:0x08BD8070
	{  10, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFE3BDF
	{  11, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE1A01000
	{  12, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00004
	{  13, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFFFC5
	{  14, 0xe5845000, 0xfdfff000 }, // str:4:0xE5845024
	{  15, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD8070
	/* 16/16 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_DeleteFile_Fut_1[] = {
	{   0, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01001
	{   1, 0x0a000000, 0x0f000000 }, // b, bl:3:0xEA000192
	{   2, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01000
	{   3, 0x0a000000, 0x0f000000 }, // b, bl:3:0xEA000190
	{   4, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4070
	{   5, 0xe1a05000, 0xfdfff000 }, // mov:6:0xE1A05000
	{   6, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01001
	{   7, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB0000FF
	{   8, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE1A04000
	{   9, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00005
	{  10, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01000
	{  11, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFFEC4
	{  12, 0xe1a05000, 0xfdfff000 }, // mov:6:0xE1A05000
	{  13, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00004
	{  14, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB000102
	{  15, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00005
	{  16, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD8070
	{  17, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4070
	{  18, 0xe1a05000, 0xfdfff000 }, // mov:6:0xE1A05000
	{  19, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01001
	{  20, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB0000F2
	{  21, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE1A04000
	{  22, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00005
	{  23, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB00B394
	{  24, 0xe1a05000, 0xfdfff000 }, // mov:6:0xE1A05000
	{  25, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00004
	{  26, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB0000F6
	{  27, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00005
	{  28, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD8070
	{  29, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4070
	{  30, 0xe1a05000, 0xfdfff000 }, // mov:6:0xE1A05001
	{  31, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01001
	/* 32/32 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_RenameFile_Fut_1[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4070
	{   1, 0xe1a06000, 0xfdfff000 }, // mov:6:0xE1A06001
	{   2, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01001
	{   3, 0xe1a05000, 0xfdfff000 }, // mov:6:0xE1A05000
	{   4, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB000117
	{   5, 0xe00f1000, 0xf00ff000 }, // ldr:8:0xE59F1604
	{   6, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE1A04000
	{   7, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE3A00001
	{   8, 0xe5810000, 0xfdfff000 }, // str:4:0xE7810104
	{   9, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE1A01006
	{  10, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00005
	{  11, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB000137
	{  12, 0xe1a05000, 0xfdfff000 }, // mov:6:0xE1A05000
	{  13, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00004
	{  14, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB000117
	{  15, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00005
	{  16, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD8070
	/* 17/17 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_SetFileTimeStamp_1[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D401C
	{   1, 0xe58d1000, 0xfdfff000 }, // str:4:0xE58D1004
	{   2, 0xe58d2000, 0xfdfff000 }, // str:4:0xE58D2000
	{   3, 0xe1a02000, 0xfdfff000 }, // mov:6:0xE1A0200D
	{   4, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01002
	{   5, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE1A04000
	{   6, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFD4AC
	{   7, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500000
	{   8, 0x0a000000, 0x0f000000 }, // b, bl:3:0x1A000008
	{   9, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00004
	{  10, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB00A9F8
	{  11, 0xe1a02000, 0xfdfff000 }, // mov:6:0xE3A02000
	{  12, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01000
	{  13, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00004
	{  14, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFD4A4
	{  15, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500000
	{  16, 0x01a00000, 0xfdfff000 }, // mov:6:0x03A00001
	{  17, 0x0a000000, 0x0f000000 }, // b, bl:3:0x0A000000
	{  18, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE3A00000
	{  19, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD801C
	/* 20/20 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_SetLogicalEventActive_1[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4070
	{   1, 0xe00f4000, 0xf00ff000 }, // ldr:8:0xE59F40C8
	{   2, 0xe1a05000, 0xfdfff000 }, // mov:6:0xE1A05000
	{   4, 0xe1a06000, 0xfdfff000 }, // mov:6:0xE1A06001
	{   5, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500026
	{   6, 0x01a01000, 0xfdfff000 }, // mov:6:0x03A01E1B
	{   7, 0x000f0000, 0xf00ff000 }, // add:10:0x028F00B8
	{   8, 0x0b000000, 0x0f000000 }, // b, bl:3:0x0BFEC0E8
	{   9, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00005
	{  10, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB00001A
	{  11, 0xe1700001, 0xfdffffff }, // cmn:7:0xE3700001
	{  13, 0x00801000, 0xfdf0f000 }, // add:6:0x02801001
	{  14, 0x05c41000, 0xfdfff000 }, // strb:4:0x05C41000
	{  15, 0xe00f1000, 0xf00ff000 }, // ldr:8:0xE59F1094
	{  16, 0xe5815000, 0xfdfff000 }, // str:4:0xE7815180
	{  17, 0xe0800000, 0xfdf0f000 }, // add:6:0xE0810180
	{  18, 0xe5806000, 0xfdfff000 }, // str:4:0xE5806004
	{  19, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD8070
	/* 18/20 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_GetFocusLensSubjectDistanceFromLens_1[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D407C
	{   1, 0xe00f5000, 0xf00ff000 }, // ldr:8:0xE51F5DA4
	{   2, 0xe5950000, 0xfdfff000 }, // ldr:4:0xE5950000
	{   3, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500000
	{   4, 0x000f1000, 0xf00ff000 }, // ldr:8:0x059F1128
	{   5, 0x000f0000, 0xf00ff000 }, // sub:10:0x024F0EDD
	{   6, 0x0b000000, 0x0f000000 }, // b, bl:3:0x0BFC388C
	{   7, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFFF34
	{   8, 0xe040c000, 0xfdfff000 }, // sub:6:0xE240CCFF
	{   9, 0xe05cc000, 0xfdfff000 }, // sub:6:0xE25CC0FF
	{  10, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE1A04000
	{  11, 0x0a000000, 0x0f000000 }, // b, bl:3:0x0A00000B
	{  12, 0xe1a02000, 0xfdfff000 }, // mov:6:0xE3A02000
	{  13, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE1A0100D
	{  14, 0xe0800000, 0xfdf0f000 }, // add:6:0xE28D0004
	{  15, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB0015C7
	{  16, 0xe1dd1000, 0xfdfff000 }, // bic:6:0xE1DD10F4
	{  17, 0xe5950000, 0xfdfff000 }, // ldr:4:0xE5950034
	{  18, 0xe0800000, 0xfdf0f000 }, // add:6:0xE0800081
	{  19, 0xe0800000, 0xfdf0f000 }, // add:6:0xE2800C01
	{  20, 0xe1d00000, 0xfdfff000 }, // bic:6:0xE1D00CB6
	{  21, 0xe0440000, 0xfdfff000 }, // sub:6:0xE0440000
	/* 22/22 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_add_ptp_handler_1[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D47F0
	{   1, 0xe1a07000, 0xfdfff000 }, // mov:6:0xE1A07000
	{   2, 0xe00f0000, 0xf00ff000 }, // ldr:8:0xE59F00C0
	{   3, 0xe1a08000, 0xfdfff000 }, // mov:6:0xE1A08002
	{   4, 0xe5900000, 0xfdfff000 }, // ldr:4:0xE5900000
	{   5, 0xe1a05000, 0xfdfff000 }, // mov:6:0xE1A05001
	{   6, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500000
	{   7, 0x01a00000, 0xfdfff000 }, // mov:6:0x03A00017
	{   8, 0x08bd0000, 0xffff0000 }, // ldm:5:0x08BD87F0
	{   9, 0xe1550000, 0xfdfff000 }, // cmp:7:0xE3550000
	{  10, 0x01a00000, 0xfdfff000 }, // mov:6:0x03A00003
	{  11, 0x08bd0000, 0xffff0000 }, // ldm:5:0x08BD87F0
	{  12, 0xe5909000, 0xfdfff000 }, // ldr:4:0xE5909000
	{  13, 0xe0804000, 0xfdf0f000 }, // add:6:0xE2804004
	{  14, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00009
	{  15, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01000
	{  16, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFD7891
	{  17, 0xe1100001, 0xfdffffff }, // tst:7:0xE3100001
	{  18, 0x11a06000, 0xfdfff000 }, // mov:6:0x13A06001
	{  19, 0x0a000000, 0x0f000000 }, // b, bl:3:0x1A000018
	{  20, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE1A01007
	{  21, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00004
	{  22, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB00016F
	{  23, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500000
	{  24, 0x0a000000, 0x0f000000 }, // b, bl:3:0x0A000004
	{  25, 0xe5805000, 0xfdfff000 }, // str:4:0xE580500C
	{  26, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00009
	{  27, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFD78BA
	{  28, 0xe1a06000, 0xfdfff000 }, // mov:6:0xE3A06013
	{  29, 0x0a000000, 0x0f000000 }, // b, bl:3:0xEA00000E
	{  30, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE3A00010
	{  31, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFDAFD3
	/* 32/32 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_set_control_event_1[] = {
	{   0, 0xe2001000, 0xfffff000 }, // and:7:0xE2001CFF
	{   1, 0xe200c000, 0xfffff000 }, // and:7:0xE200C101
	{   2, 0xe1700001, 0xfdffffff }, // cmn:7:0xE3700001
	{   3, 0xe1a0c000, 0xfdfff000 }, // mov:6:0xE1A0CF2C
	{   4, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE1A01421
	{   5, 0xe2002000, 0xfffff000 }, // and:7:0xE20020FF
	{   6, 0xe1a03000, 0xfdfff000 }, // mov:6:0xE1A03FA0
	{   8, 0xe15c0000, 0xfdfff000 }, // cmp:7:0xE35C0000
	{   9, 0xe00f0000, 0xf00ff000 }, // ldr:8:0xE59F02D0
	{  10, 0x0a000000, 0x0f000000 }, // b, bl:3:0x1A000006
	{  11, 0xe1a0c000, 0xfdfff000 }, // mov:6:0xE3A0C001
	{  12, 0xe1530000, 0xfdfff000 }, // cmp:7:0xE3530000
	{  13, 0xe5903000, 0xfdfff000 }, // ldr:4:0xE7903101
	{  14, 0xe1a02000, 0xfdfff000 }, // mov:6:0xE1A0221C
	{  15, 0x01e02000, 0xfdfff000 }, // mvn:6:0x01E02002
	{  18, 0xe5802000, 0xfdfff000 }, // str:4:0xE7802101
	/* 16/20 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_exmem_alloc_1[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D41F0
	{   1, 0xe00f7000, 0xf00ff000 }, // ldr:8:0xE51F72E0
	{   2, 0xe1a06000, 0xfdfff000 }, // mov:6:0xE1A06001
	{   3, 0xe1a05000, 0xfdfff000 }, // mov:6:0xE1A05002
	{   4, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE1A04000
	{   5, 0xe5970000, 0xfdfff000 }, // ldr:4:0xE5970000
	{   6, 0xe00f1000, 0xf00ff000 }, // ldr:8:0xE59F10DC
	{   7, 0xe00f3000, 0xf00ff000 }, // ldr:8:0xE59F3128
	{   8, 0xe00f2000, 0xf00ff000 }, // sub:10:0xE24F2FC2
	{   9, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFED504
	{  10, 0xe1a03000, 0xfdfff000 }, // mov:6:0xE3A03000
	{  11, 0xe1a02000, 0xfdfff000 }, // mov:6:0xE1A02005
	{  12, 0xe0801000, 0xfdf0f000 }, // add:6:0xE2861040
	{  13, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00004
	{  14, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFFEE8
	{  15, 0xe00f2000, 0xf00ff000 }, // ldr:8:0xE59F20BC
	{  16, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01001
	{  17, 0xe1c00000, 0xfdfff000 }, // bic:6:0xE3C00201
	{  18, 0xe5821000, 0xfdfff000 }, // str:4:0xE7821104
	{  19, 0xe1550000, 0xfdfff000 }, // cmp:7:0xE3550000
	{  20, 0xe0804000, 0xfdf0f000 }, // add:6:0xE2804020
	{  21, 0x18850000, 0xffff0000 }, // stm:5:0x18850050
	{  22, 0xe5970000, 0xfdfff000 }, // ldr:4:0xE5970000
	{  23, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFED3E1
	{  24, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00004
	{  25, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD81F0
	/* 26/26 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_SetFileAttributes_1[] = {
	{   0, 0xe1a02000, 0xfdfff000 }, // mov:6:0xE1A02001
	{   1, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4010
	{   2, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE1A04000
	{   3, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01003
	{   4, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFD49A
	{   5, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500000
	{   6, 0x0a000000, 0x0f000000 }, // b, bl:3:0x1A000008
	{   7, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00004
	{   8, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB00A9E6
	{   9, 0xe1a02000, 0xfdfff000 }, // mov:6:0xE3A02000
	{  10, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01000
	{  11, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00004
	{  12, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFD492
	{  13, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500000
	{  14, 0x01a00000, 0xfdfff000 }, // mov:6:0x03A00001
	{  15, 0x08bd0000, 0xffff0000 }, // ldm:5:0x08BD8010
	{  16, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE3A00000
	{  17, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD8010
	{  18, 0xe1a02000, 0xfdfff000 }, // mov:6:0xE1A02001
	{  19, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4010
	{  20, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE1A04000
	{  21, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01003
	{  22, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFD488
	{  23, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500000
	{  24, 0x11a00000, 0xfdfff000 }, // mov:6:0x13A00000
	{  25, 0x18bd0000, 0xffff0000 }, // ldm:5:0x18BD8010
	{  26, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00004
	{  27, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB00A9D3
	{  28, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE3A00001
	{  29, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD8010
	{  30, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D43F8
	{  31, 0xe1a07000, 0xfdfff000 }, // mov:6:0xE1A07000
	/* 32/32 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_kbd_pwr_off_2[] = {
	{   0, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE3A00000
	{   1, 0x0a000000, 0x0f000000 }, // b, bl:3:0xEAFFFEC5
	{   2, 0xe5900000, 0xfdfff000 }, // ldr:4:0xE5900000
	{   3, 0xe2000000, 0xfffff000 }, // and:7:0xE2000001
	{   5, 0xe5801000, 0xfdfff000 }, // str:4:0xE5801000
	{   7, 0xe00f1000, 0xf00ff000 }, // ldr:8:0xE59F107C
	{   8, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE3A00020
	{   9, 0xe5810000, 0xfdfff000 }, // str:4:0xE581001C
	{  10, 0xe5810000, 0xfdfff000 }, // str:4:0xE5810024
	{  13, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4070
	{  14, 0xe1a05000, 0xfdfff000 }, // mov:6:0xE1A05000
	{  15, 0xe00f0000, 0xf00ff000 }, // ldr:8:0xE59F0044
	{  16, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE3A04000
	{  17, 0xe5900000, 0xfdfff000 }, // ldr:4:0xE5900000
	{  18, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500000
	{  19, 0x11a01000, 0xfdfff000 }, // mov:6:0x13A010D4
	{  20, 0x100f0000, 0xf00ff000 }, // add:10:0x128F0038
	{  21, 0x0b000000, 0x0f000000 }, // b, bl:3:0x1BFF64B5
	{  22, 0xe00f0000, 0xf00ff000 }, // ldr:8:0xE59F0040
	{  23, 0xe1550000, 0xfdfff000 }, // cmp:7:0xE3550000
	{  24, 0x05904000, 0xfdfff000 }, // ldr:4:0x0590401C
	{  25, 0x0a000000, 0x0f000000 }, // b, bl:3:0x0A000005
	{  26, 0xe1550000, 0xfdfff000 }, // cmp:7:0xE3550001
	{  27, 0x05904000, 0xfdfff000 }, // ldr:4:0x05904024
	{  28, 0x0a000000, 0x0f000000 }, // b, bl:3:0x0A000002
	{  29, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A010E5
	{  30, 0xe00f0000, 0xf00ff000 }, // add:10:0xE28F0010
	{  31, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFF64AB
	/* 28/32 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_kbd_pwr_on_2[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4010
	{   1, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE3A00020
	{   2, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFFED8
	{   3, 0xe00f2000, 0xf00ff000 }, // sub:10:0xE24F2020
	{   4, 0xe0801000, 0xfdf0f000 }, // add:6:0xE2821000
	{   5, 0xe1a03000, 0xfdfff000 }, // mov:6:0xE3A03000
	{   6, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE3A0000A
	{   7, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB0096D6
	{   8, 0xe1100001, 0xfdffffff }, // tst:7:0xE3100001
	{   9, 0x11500000, 0xfdfff000 }, // cmp:7:0x13500015
	{  10, 0x11a01000, 0xfdfff000 }, // mov:6:0x13A010F9
	{  11, 0x100f0000, 0xf00ff000 }, // add:10:0x128F00AC
	{  12, 0x0b000000, 0x0f000000 }, // b, bl:3:0x1BFF64D2
	{  13, 0xe00f0000, 0xf00ff000 }, // ldr:8:0xE59F009C
	{  14, 0xe00f1000, 0xf00ff000 }, // ldr:8:0xE59F10AC
	{  15, 0xe5900000, 0xfdfff000 }, // ldr:4:0xE5900004
	{  16, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD4010
	{  17, 0xe1a03000, 0xfdfff000 }, // mov:6:0xE3A030FA
	{  18, 0xe00f2000, 0xf00ff000 }, // add:10:0xE28F2090
	{  19, 0x0a000000, 0x0f000000 }, // b, bl:3:0xEAFF6485
	{  20, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE3A00000
	{  21, 0x0a000000, 0x0f000000 }, // b, bl:3:0xEAFFFEC5
	{  22, 0xe5900000, 0xfdfff000 }, // ldr:4:0xE5900000
	{  23, 0xe2000000, 0xfffff000 }, // and:7:0xE2000001
	{  25, 0xe5801000, 0xfdfff000 }, // str:4:0xE5801000
	{  27, 0xe00f1000, 0xf00ff000 }, // ldr:8:0xE59F107C
	{  28, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE3A00020
	{  29, 0xe5810000, 0xfdfff000 }, // str:4:0xE581001C
	{  30, 0xe5810000, 0xfdfff000 }, // str:4:0xE5810024
	/* 29/32 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_GetDrive_ClusterSize_3[] = {
	{   0, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500001
	{   1, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4010
	{   2, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE1A04000
	{   3, 0x200f1000, 0xf00ff000 }, // ldr:8:0x259F1350
	{   4, 0x200f0000, 0xf00ff000 }, // sub:10:0x224F0E92
	{   5, 0x0b000000, 0x0f000000 }, // b, bl:3:0x2BFECB5B
	{   6, 0xe00f0000, 0xf00ff000 }, // ldr:8:0xE51F0944
	{   7, 0xe0801000, 0xfdf0f000 }, // add:6:0xE0841204
	{   8, 0xe0800000, 0xfdf0f000 }, // add:6:0xE0800101
	{   9, 0xe5901000, 0xfdfff000 }, // ldr:4:0xE5901004
	{  10, 0xe5900000, 0xfdfff000 }, // ldr:4:0xE5900008
	{  11, 0xe0000091, 0xffffffff }, // mul:11:0xE0000091
	{  12, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD8010
	/* 13/13 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_GetDrive_TotalClusters_3[] = {
	{   0, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500001
	{   1, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4010
	{   2, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE1A04000
	{   3, 0x200f0000, 0xf00ff000 }, // ldr:8:0x251F032C
	{   4, 0x200f1000, 0xf00ff000 }, // ldr:8:0x259F131C
	{   5, 0x0b000000, 0x0f000000 }, // b, bl:3:0x2BFECB4E
	{   6, 0xe00f1000, 0xf00ff000 }, // ldr:8:0xE51F1978
	{   7, 0xe0800000, 0xfdf0f000 }, // add:6:0xE0840204
	{   8, 0xe0800000, 0xfdf0f000 }, // add:6:0xE0810100
	{   9, 0xe5900000, 0xfdfff000 }, // ldr:4:0xE5900034
	{  10, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD8010
	/* 11/11 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_GetDrive_FreeClusters_3[] = {
	{   0, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500001
	{   1, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4010
	{   2, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE1A04000
	{   3, 0x200f1000, 0xf00ff000 }, // ldr:8:0x259F12F8
	{   4, 0x200f0000, 0xf00ff000 }, // sub:10:0x224F0D26
	{   5, 0x0b000000, 0x0f000000 }, // b, bl:3:0x2BFECB43
	{   6, 0xe00f0000, 0xf00ff000 }, // ldr:8:0xE51F0370
	{   7, 0xe5900000, 0xfdfff000 }, // ldr:4:0xE7900104
	{   8, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD8010
	/* 9/9 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_ReadFastDir_3[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D41F0
	{   1, 0xe1b05000, 0xfdfff000 }, // mov:6:0xE1B05000
	{   2, 0xe04dd000, 0xfdfff000 }, // sub:6:0xE24DD040
	{   3, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE1A04001
	{   4, 0x0a000000, 0x0f000000 }, // b, bl:3:0x0A000060
	{   5, 0xe5950000, 0xfdfff000 }, // ldr:4:0xE5950000
	{   6, 0xe1a08000, 0xfdfff000 }, // mov:6:0xE3A08001
	{   7, 0xe1700001, 0xfdffffff }, // cmn:7:0xE3700001
	{   8, 0xe1a07000, 0xfdfff000 }, // mov:6:0xE3A07000
	{   9, 0x0a000000, 0x0f000000 }, // b, bl:3:0x1A000032
	{  10, 0xe1a03000, 0xfdfff000 }, // mov:6:0xE3A03001
	{  11, 0xe1a02000, 0xfdfff000 }, // mov:6:0xE3A02020
	{  12, 0xe98d0000, 0xffff0000 }, // stm:5:0xE98D000C
	{  13, 0xe0803000, 0xfdf0f000 }, // add:6:0xE28D3010
	{  14, 0xe1a02000, 0xfdfff000 }, // mov:6:0xE3A02000
	{  15, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01000
	{  16, 0xe0800000, 0xfdf0f000 }, // add:6:0xE2850018
	{  17, 0xe58d4000, 0xfdfff000 }, // str:4:0xE58D4000
	{  18, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFDF916
	{  19, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500000
	{  20, 0x0a000000, 0x0f000000 }, // b, bl:3:0xDA000021
	{  21, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE350000C
	{  22, 0xd5847000, 0xfdfff000 }, // str:4:0xD5847038
	{  23, 0x0a000000, 0x0f000000 }, // b, bl:3:0xDA000003
	{  24, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE350001F
	{  25, 0xe5848000, 0xfdfff000 }, // str:4:0xE5848038
	{  26, 0xc5c47000, 0xfdfff000 }, // strb:4:0xC5C4701F
	{  27, 0x0a000000, 0x0f000000 }, // b, bl:3:0xCA000000
	{  28, 0xe5c47000, 0xfdfff000 }, // strb:4:0xE7C47000
	{  29, 0xe1cd0000, 0xfdfff000 }, // bic:6:0xE1CD02D8
	{  30, 0xe1e02000, 0xfdfff000 }, // mvn:6:0xE3E02000
	{  31, 0xe1510000, 0xfdfff000 }, // cmp:7:0xE3510000
	/* 32/32 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_OpenFastDir_3[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D43F8
	{   1, 0xe1a06000, 0xfdfff000 }, // mov:6:0xE1A06000
	{   3, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBF7B22B
	{   4, 0xe1a08000, 0xfdfff000 }, // mov:6:0xE1A08000
	{   5, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBF7B6AF
	{   6, 0xe1b05000, 0xfdfff000 }, // mov:6:0xE1B05000
	{   7, 0x0a000000, 0x0f000000 }, // b, bl:3:0x1A000001
	{   8, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE3A00000
	{   9, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD83F8
	{  10, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE3A0003C
	{  11, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBF6EA10
	{  12, 0xe1b04000, 0xfdfff000 }, // mov:6:0xE1B04000
	{  13, 0x000f1000, 0xf00ff000 }, // ldr:8:0x059F12A4
	{  14, 0x000f0000, 0xf00ff000 }, // add:10:0x028F0FA9
	{  15, 0x0b000000, 0x0f000000 }, // b, bl:3:0x0BF681E6
	{  16, 0xe1550000, 0xfdfff000 }, // cmp:7:0xE3550004
	{  17, 0xe1a07000, 0xfdfff000 }, // mov:6:0xE3A07000
	{  18, 0x05847000, 0xfdfff000 }, // str:4:0x05847004
	{  19, 0x05847000, 0xfdfff000 }, // str:4:0x05847008
	{  20, 0x0a000000, 0x0f000000 }, // b, bl:3:0x0A000007
	{  21, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE3A00902
	{  22, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBF6EA32
	{  23, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01902
	{  24, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500000
	{  25, 0xe9840000, 0xffff0000 }, // stm:5:0xE9840003
	{  26, 0x000f1000, 0xf00ff000 }, // ldr:8:0x059F1280
	{  27, 0x000f0000, 0xf00ff000 }, // add:10:0x028F0E27
	{  28, 0x0b000000, 0x0f000000 }, // b, bl:3:0x0BF681D9
	{  29, 0xe1e00000, 0xfdfff000 }, // mvn:6:0xE3E00000
	{  30, 0xe5840000, 0xfdfff000 }, // str:4:0xE5840000
	{  31, 0xe5847000, 0xfdfff000 }, // str:4:0xE584700C
	/* 31/32 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_closedir_3[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4010
	{   1, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE1A04000
	{   2, 0xe5900000, 0xfdfff000 }, // ldr:4:0xE5900004
	{   3, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500000
	{   4, 0x0b000000, 0x0f000000 }, // b, bl:3:0x1BF6EA65
	{   5, 0xe5940000, 0xfdfff000 }, // ldr:4:0xE5940000
	{   6, 0xe1700001, 0xfdffffff }, // cmn:7:0xE3700001
	{   7, 0x0a000000, 0x0f000000 }, // b, bl:3:0x0A000001
	{   8, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBF6DCDD
	{   9, 0x0a000000, 0x0f000000 }, // b, bl:3:0xEA000003
	{  10, 0xe5940000, 0xfdfff000 }, // ldr:4:0xE5940014
	{  11, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500001
	{  12, 0x00800000, 0xfdf0f000 }, // add:6:0x02840018
	{  13, 0x0b000000, 0x0f000000 }, // b, bl:3:0x0BF8A5A8
	{  14, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00004
	{  15, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD4010
	{  16, 0x0a000000, 0x0f000000 }, // b, bl:3:0xEAF6EA1D
	/* 17/17 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_GetFocusLensSubjectDistanceFromLens_3[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D407C
	{   1, 0xe00f5000, 0xf00ff000 }, // ldr:8:0xE59F5618
	{   2, 0xe5950000, 0xfdfff000 }, // ldr:4:0xE5950000
	{   3, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500000
	{   4, 0x000f1000, 0xf00ff000 }, // ldr:8:0x059F1624
	{   5, 0x000f0000, 0xf00ff000 }, // ldr:8:0x051F0290
	{   6, 0x0b000000, 0x0f000000 }, // b, bl:3:0x0BFB6DE1
	{   7, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFFEE5
	{   8, 0xe1700001, 0xfdffffff }, // cmn:7:0xE3700001
	{   9, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE1A04000
	{  10, 0x0a000000, 0x0f000000 }, // b, bl:3:0x0A000008
	{  11, 0xe1a02000, 0xfdfff000 }, // mov:6:0xE3A02000
	{  12, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE1A0100D
	{  13, 0xe0800000, 0xfdf0f000 }, // add:6:0xE28D0004
	{  14, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB001191
	{  15, 0xe1dd1000, 0xfdfff000 }, // bic:6:0xE1DD10F4
	{  16, 0xe5950000, 0xfdfff000 }, // ldr:4:0xE595002C
	{  17, 0xe0800000, 0xfdf0f000 }, // add:6:0xE0800101
	{  18, 0xe5900000, 0xfdfff000 }, // ldr:4:0xE59003A8
	{  19, 0xe0444000, 0xfdfff000 }, // sub:6:0xE0444000
	{  20, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00004
	{  21, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD807C
	/* 22/22 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_add_ptp_handler_3[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D47F0
	{   1, 0xe00f4000, 0xf00ff000 }, // ldr:8:0xE51F4030
	{   2, 0xe1a07000, 0xfdfff000 }, // mov:6:0xE1A07000
	{   3, 0xe5940000, 0xfdfff000 }, // ldr:4:0xE5940000
	{   4, 0xe1a08000, 0xfdfff000 }, // mov:6:0xE1A08002
	{   5, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500000
	{   6, 0x01a00000, 0xfdfff000 }, // mov:6:0x03A00017
	{   7, 0xe1a05000, 0xfdfff000 }, // mov:6:0xE1A05001
	{   8, 0x08bd0000, 0xffff0000 }, // ldm:5:0x08BD87F0
	{   9, 0xe1550000, 0xfdfff000 }, // cmp:7:0xE3550000
	{  10, 0x01a00000, 0xfdfff000 }, // mov:6:0x03A00003
	{  11, 0x08bd0000, 0xffff0000 }, // ldm:5:0x08BD87F0
	{  12, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBF87F0F
	{  13, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500000
	{  14, 0x0a000000, 0x0f000000 }, // b, bl:3:0x0A000004
	{  15, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00007
	{  16, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFFFB5
	{  17, 0xe1100001, 0xfdffffff }, // tst:7:0xE3100001
	{  18, 0x11a00000, 0xfdfff000 }, // mov:6:0x13A00000
	{  19, 0x18bd0000, 0xffff0000 }, // ldm:5:0x18BD87F0
	{  20, 0xe5940000, 0xfdfff000 }, // ldr:4:0xE5940000
	{  21, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01000
	{  22, 0xe5909000, 0xfdfff000 }, // ldr:4:0xE5909000
	{  23, 0xe0804000, 0xfdf0f000 }, // add:6:0xE2804004
	{  24, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00009
	{  25, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBF7E24F
	{  26, 0xe1100001, 0xfdffffff }, // tst:7:0xE3100001
	{  27, 0x11a06000, 0xfdfff000 }, // mov:6:0x13A06001
	{  28, 0x0a000000, 0x0f000000 }, // b, bl:3:0x1A000018
	{  29, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE1A01007
	{  30, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00004
	{  31, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB000133
	/* 32/32 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_SetFileTimeStamp_3[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D407C
	{   1, 0xe58d1000, 0xfdfff000 }, // str:4:0xE58D1004
	{   2, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE1A0100D
	{   3, 0xe1a05000, 0xfdfff000 }, // mov:6:0xE1A05000
	{   4, 0xe58d2000, 0xfdfff000 }, // str:4:0xE58D2000
	{   5, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB002D01
	{   6, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE1A04000
	{   7, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00005
	{   8, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB00CD58
	{   9, 0xe1540000, 0xfdfff000 }, // cmp:7:0xE3540000
	{  10, 0x01500000, 0xfdfff000 }, // cmp:7:0x03500001
	{  11, 0x11a00000, 0xfdfff000 }, // mov:6:0x13A00000
	{  12, 0x0a000000, 0x0f000000 }, // b, bl:3:0x1A000002
	{  13, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00005
	{  14, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB00CCC2
	{  15, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE3A00001
	{  16, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD807C
	/* 17/17 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_ScreenLock_3[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4010
	{   1, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB000075
	{   2, 0xe1100001, 0xfdffffff }, // tst:7:0xE3100001
	{   3, 0x18bd0000, 0xffff0000 }, // ldm:5:0x18BD8010
	{   4, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB00005E
	{   5, 0xe00f0000, 0xf00ff000 }, // ldr:8:0xE51F0F5C
	{   6, 0xe5900000, 0xfdfff000 }, // ldr:4:0xE590000C
	{   7, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBF8FAC7
	{   8, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE3A00000
	{   9, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD8010
	/* 10/10 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_ScreenUnlock_3[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4010
	{   1, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB00006B
	{   2, 0xe1100001, 0xfdffffff }, // tst:7:0xE3100001
	{   3, 0x18bd0000, 0xffff0000 }, // ldm:5:0x18BD8010
	{   4, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFFB68
	{   5, 0xe00f0000, 0xf00ff000 }, // ldr:8:0xE51F0F84
	{   6, 0xe5900000, 0xfdfff000 }, // ldr:4:0xE590000C
	{   7, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD4010
	{   8, 0x0a000000, 0x0f000000 }, // b, bl:3:0xEAF8FABC
	/* 9/9 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_SetFileAttributes_3[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4070
	{   1, 0xe1a05000, 0xfdfff000 }, // mov:6:0xE1A05000
	{   2, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB002DD8
	{   3, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE1A04000
	{   4, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00005
	{   5, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB00CD4A
	{   6, 0xe1540000, 0xfdfff000 }, // cmp:7:0xE3540000
	{   7, 0x01500000, 0xfdfff000 }, // cmp:7:0x03500001
	{   8, 0x11a00000, 0xfdfff000 }, // mov:6:0x13A00000
	{   9, 0x18bd0000, 0xffff0000 }, // ldm:5:0x18BD8070
	{  10, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00005
	{  11, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB00CCB4
	{  12, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE3A00001
	{  13, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD8070
	{  14, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4010
	{  15, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE1A04000
	{  16, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB002DCA
	{  17, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500000
	{  18, 0x11a00000, 0xfdfff000 }, // mov:6:0x13A00000
	{  19, 0x18bd0000, 0xffff0000 }, // ldm:5:0x18BD8010
	{  20, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00004
	{  21, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB00CCAA
	{  22, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE3A00001
	{  23, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD8010
	{  24, 0x0a000000, 0x0f000000 }, // b, bl:3:0xEA00004F
	{  25, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4070
	{  26, 0xe1a05000, 0xfdfff000 }, // mov:6:0xE1A05000
	{  27, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB002BE6
	{  28, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE1A04000
	{  29, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00005
	{  30, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB00CD31
	{  31, 0xe1540000, 0xfdfff000 }, // cmp:7:0xE3540000
	/* 32/32 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_GetDrive_ClusterSize_4[] = {
	{   0, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500001
	{   1, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4010
	{   2, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE1A04000
	{   3, 0x200f0000, 0xf00ff000 }, // ldr:8:0x251F0350
	{   4, 0x200f1000, 0xf00ff000 }, // ldr:8:0x259F1378
	{   5, 0x0b000000, 0x0f000000 }, // b, bl:3:0x2BFEA085
	{   6, 0xe00f0000, 0xf00ff000 }, // ldr:8:0xE51F0C40
	{   7, 0xe0801000, 0xfdf0f000 }, // add:6:0xE0841204
	{   8, 0xe0800000, 0xfdf0f000 }, // add:6:0xE0800101
	{   9, 0xe5901000, 0xfdfff000 }, // ldr:4:0xE5901004
	{  10, 0xe5900000, 0xfdfff000 }, // ldr:4:0xE5900008
	{  11, 0xe0000091, 0xffffffff }, // mul:11:0xE0000091
	{  12, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD8010
	/* 13/13 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_GetDrive_FreeClusters_4[] = {
	{   0, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500001
	{   1, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4010
	{   2, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE1A04000
	{   3, 0x200f0000, 0xf00ff000 }, // ldr:8:0x251F03B0
	{   4, 0x200f1000, 0xf00ff000 }, // ldr:8:0x259F1320
	{   5, 0x0b000000, 0x0f000000 }, // b, bl:3:0x2BFEA06D
	{   6, 0xe00f0000, 0xf00ff000 }, // ldr:8:0xE51F03CC
	{   7, 0xe5900000, 0xfdfff000 }, // ldr:4:0xE7900104
	{   8, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD8010
	/* 9/9 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_srand_4[] = {
	{   0, 0xe00f1000, 0xf00ff000 }, // ldr:8:0xE59F102C
	{   1, 0xe5810000, 0xfdfff000 }, // str:4:0xE5810000
	{   3, 0xe00f2000, 0xf00ff000 }, // ldr:8:0xE59F2020
	{   4, 0xe00f1000, 0xf00ff000 }, // ldr:8:0xE59F1020
	{   5, 0xe5920000, 0xfdfff000 }, // ldr:4:0xE5920000
	{   6, 0xe0000091, 0xffffffff }, // mul:11:0xE0000091
	{   7, 0xe1e01000, 0xfdfff000 }, // mvn:6:0xE3E01902
	{   8, 0xe0800000, 0xfdf0f000 }, // add:6:0xE2800A03
	{   9, 0xe0800000, 0xfdf0f000 }, // add:6:0xE2800039
	{  10, 0xe5820000, 0xfdfff000 }, // str:4:0xE5820000
	/* 10/13 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_rand_4[] = {
	{   0, 0xe00f2000, 0xf00ff000 }, // ldr:8:0xE59F2020
	{   1, 0xe00f1000, 0xf00ff000 }, // ldr:8:0xE59F1020
	{   2, 0xe5920000, 0xfdfff000 }, // ldr:4:0xE5920000
	{   3, 0xe0000091, 0xffffffff }, // mul:11:0xE0000091
	{   4, 0xe1e01000, 0xfdfff000 }, // mvn:6:0xE3E01902
	{   5, 0xe0800000, 0xfdf0f000 }, // add:6:0xE2800A03
	{   6, 0xe0800000, 0xfdf0f000 }, // add:6:0xE2800039
	{   7, 0xe5820000, 0xfdfff000 }, // str:4:0xE5820000
	/* 8/10 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_qsort_4[] = {
	{   0, 0xe52de000, 0xfdfff000 }, // str:4:0xE52DE004
	{   1, 0xe04dd000, 0xfdfff000 }, // sub:6:0xE24DD014
	{   2, 0xe1cd2000, 0xfdfff000 }, // bic:6:0xE1CD20F0
	{   4, 0xe1120003, 0xfdffffff }, // tst:7:0xE3120003
	{   5, 0x000f2000, 0xf00ff000 }, // ldr:8:0x059F202C
	{   6, 0x0a000000, 0x0f000000 }, // b, bl:3:0x0A000002
	{   7, 0xe1120001, 0xfdffffff }, // tst:7:0xE3120001
	{   8, 0x100f2000, 0xf00ff000 }, // sub:10:0x124F2D13
	{   9, 0x000f2000, 0xf00ff000 }, // sub:10:0x024F2E4A
	{  10, 0xe58d2000, 0xfdfff000 }, // str:4:0xE58D2008
	{  11, 0xe00f2000, 0xf00ff000 }, // sub:10:0xE24F2FFF
	{  12, 0xe58d2000, 0xfdfff000 }, // str:4:0xE58D200C
	{  13, 0xe00f2000, 0xf00ff000 }, // ldr:8:0xE59F2010
	{  14, 0xe58d2000, 0xfdfff000 }, // str:4:0xE58D2010
	{  15, 0xe1a02000, 0xfdfff000 }, // mov:6:0xE1A0200D
	{  16, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFFFB9
	{  17, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD900F
	/* 17/18 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_closedir_4[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4010
	{   1, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE1A04000
	{   2, 0xe5900000, 0xfdfff000 }, // ldr:4:0xE5900004
	{   3, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500000
	{   4, 0x0b000000, 0x0f000000 }, // b, bl:3:0x1BF5613A
	{   5, 0xe5940000, 0xfdfff000 }, // ldr:4:0xE5940000
	{   6, 0xe1700001, 0xfdffffff }, // cmn:7:0xE3700001
	{   7, 0x0a000000, 0x0f000000 }, // b, bl:3:0x0A000001
	{   8, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBF55192
	{   9, 0x0a000000, 0x0f000000 }, // b, bl:3:0xEA000006
	{  10, 0xe5940000, 0xfdfff000 }, // ldr:4:0xE5940014
	{  11, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500000
	{  12, 0x0b000000, 0x0f000000 }, // b, bl:3:0x1BF56132
	{  13, 0xe5940000, 0xfdfff000 }, // ldr:4:0xE594001C
	{  14, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500001
	{  15, 0x00800000, 0xfdf0f000 }, // add:6:0x02840020
	{  16, 0x0b000000, 0x0f000000 }, // b, bl:3:0x0BF752CA
	{  17, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00004
	{  18, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD4010
	{  19, 0x0a000000, 0x0f000000 }, // b, bl:3:0xEAF560EF
	/* 20/20 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_SetFileTimeStamp_4[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D407C
	{   1, 0xe1a05000, 0xfdfff000 }, // mov:6:0xE1A05000
	{   2, 0xe00f0000, 0xf00ff000 }, // ldr:8:0xE59F0240
	{   3, 0xe1510000, 0xfdfff000 }, // cmp:7:0xE1510000
	{   4, 0xb1a01000, 0xfdfff000 }, // mov:6:0xB1A01000
	{   5, 0xe1520000, 0xfdfff000 }, // cmp:7:0xE1520000
	{   6, 0xb1a02000, 0xfdfff000 }, // mov:6:0xB1A02000
	{   7, 0xe58d1000, 0xfdfff000 }, // str:4:0xE58D1004
	{   8, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE1A0100D
	{   9, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00005
	{  10, 0xe58d2000, 0xfdfff000 }, // str:4:0xE58D2000
	{  11, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB003058
	{  12, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE1A04000
	{  13, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00005
	{  14, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB00F18A
	{  15, 0xe1540000, 0xfdfff000 }, // cmp:7:0xE3540000
	{  16, 0x01500000, 0xfdfff000 }, // cmp:7:0x03500001
	{  17, 0x11a00000, 0xfdfff000 }, // mov:6:0x13A00000
	{  18, 0x0a000000, 0x0f000000 }, // b, bl:3:0x1A000002
	{  19, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00005
	{  20, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB00F0F4
	{  21, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE3A00001
	{  22, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD807C
	/* 23/23 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_ReadFastDir_4[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4070
	{   1, 0xe1b05000, 0xfdfff000 }, // mov:6:0xE1B05000
	{   2, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE1A04001
	{   3, 0x0a000000, 0x0f000000 }, // b, bl:3:0x0A00000F
	{   4, 0xe1a06000, 0xfdfff000 }, // mov:6:0xE3A06000
	{   5, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE1A01004
	{   6, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00005
	{   7, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFFF18
	{   8, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500000
	{   9, 0x0a000000, 0x0f000000 }, // b, bl:3:0x0A00000B
	{  10, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500001
	{  11, 0x0a000000, 0x0f000000 }, // b, bl:3:0x0A00000B
	{  12, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00005
	{  13, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFFEE2
	{  14, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500000
	{  15, 0x0a000000, 0x0f000000 }, // b, bl:3:0x0AFFFFF4
	{  16, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500001
	{  17, 0x0a000000, 0x0f000000 }, // b, bl:3:0x0A000005
	{  18, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500002
	{  19, 0x0a000000, 0x0f000000 }, // b, bl:3:0x1AFFFFF0
	{  20, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE3A00000
	{  21, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD8070
	{  22, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE3A00001
	{  23, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD8070
	{  24, 0xe5c46000, 0xfdfff000 }, // strb:4:0xE5C46000
	{  25, 0x0a000000, 0x0f000000 }, // b, bl:3:0xEAFFFFFB
	/* 26/26 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_PT_PlaySound_4[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4070
	{   1, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE1A04000
	{   2, 0xe1a05000, 0xfdfff000 }, // mov:6:0xE1A05804
	{   3, 0xe1100901, 0xfdffffff }, // tst:7:0xE3100901
	{   4, 0xe1a05000, 0xfdfff000 }, // mov:6:0xE1A05825
	{   5, 0xe1a06000, 0xfdfff000 }, // mov:6:0xE1A06001
	{   6, 0x0a000000, 0x0f000000 }, // b, bl:3:0x0A000007
	{   7, 0xe1a02000, 0xfdfff000 }, // mov:6:0xE1A02006
	{   8, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01000
	{   9, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00005
	{  10, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFFF11
	{  11, 0xe1100001, 0xfdffffff }, // tst:7:0xE3100001
	{  12, 0x08bd0000, 0xffff0000 }, // ldm:5:0x08BD8070
	{  13, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01F7D
	{  14, 0x0a000000, 0x0f000000 }, // b, bl:3:0xEA00000E
	{  15, 0xe00f0000, 0xf00ff000 }, // ldr:8:0xE51F00C0
	{  16, 0xe5900000, 0xfdfff000 }, // ldr:4:0xE5900004
	{  17, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500001
	{  18, 0x100f1000, 0xf00ff000 }, // ldr:8:0x159F11E0
	{  19, 0x100f0000, 0xf00ff000 }, // sub:10:0x124F00C8
	{  20, 0x0b000000, 0x0f000000 }, // b, bl:3:0x1BFE5278
	{  21, 0xe1140a02, 0xfdffffff }, // tst:7:0xE3140A02
	{  22, 0x08bd0000, 0xffff0000 }, // ldm:5:0x08BD8070
	{  23, 0xe1a02000, 0xfdfff000 }, // mov:6:0xE1A02006
	{  24, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01000
	{  25, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00005
	{  26, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFFF3F
	{  27, 0xe1100001, 0xfdffffff }, // tst:7:0xE3100001
	{  28, 0x08bd0000, 0xffff0000 }, // ldm:5:0x08BD8070
	{  29, 0xe00f1000, 0xf00ff000 }, // ldr:8:0xE59F11B8
	{  30, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD4070
	{  31, 0xe00f0000, 0xf00ff000 }, // sub:10:0xE24F00F8
	/* 32/32 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_Remove_4[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4070
	{   1, 0xe1a05000, 0xfdfff000 }, // mov:6:0xE1A05000
	{   2, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB0030DF
	{   3, 0xe1b04000, 0xfdfff000 }, // mov:6:0xE1B04000
	{   4, 0x0a000000, 0x0f000000 }, // b, bl:3:0x1A000006
	{   5, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00005
	{   6, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB00F22C
	{   7, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500001
	{   8, 0x11e04000, 0xfdfff000 }, // mvn:6:0x13E04000
	{   9, 0x0a000000, 0x0f000000 }, // b, bl:3:0x1A000001
	{  10, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00005
	{  11, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB00F1B1
	{  12, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00004
	{  13, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD8070
	/* 14/14 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_OpenFastDir_4[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D43F8
	{   1, 0xe1a06000, 0xfdfff000 }, // mov:6:0xE1A06000
	{   3, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBF64AEF
	{   4, 0xe1a08000, 0xfdfff000 }, // mov:6:0xE1A08000
	{   5, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBF64FBC
	{   6, 0xe1b05000, 0xfdfff000 }, // mov:6:0xE1B05000
	{   7, 0x0a000000, 0x0f000000 }, // b, bl:3:0x1A000001
	{   8, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE3A00000
	{   9, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD83F8
	{  10, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE3A00044
	{  11, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBF560E2
	{  12, 0xe1b04000, 0xfdfff000 }, // mov:6:0xE1B04000
	{  13, 0x01a01000, 0xfdfff000 }, // mov:6:0x03A01E1B
	{  14, 0x000f0000, 0xf00ff000 }, // add:10:0x028F0F9D
	{  15, 0x0b000000, 0x0f000000 }, // b, bl:3:0x0BF4F01D
	{  16, 0xe1550000, 0xfdfff000 }, // cmp:7:0xE3550004
	{  17, 0xe1a07000, 0xfdfff000 }, // mov:6:0xE3A07000
	{  18, 0x05847000, 0xfdfff000 }, // str:4:0x05847004
	{  19, 0x05847000, 0xfdfff000 }, // str:4:0x05847008
	{  20, 0x0a000000, 0x0f000000 }, // b, bl:3:0x0A000007
	{  21, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE3A00902
	{  22, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBF56104
	{  23, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01902
	{  24, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500000
	{  25, 0xe9840000, 0xffff0000 }, // stm:5:0xE9840003
	{  26, 0x000f1000, 0xf00ff000 }, // ldr:8:0x059F1250
	{  27, 0x000f0000, 0xf00ff000 }, // add:10:0x028F0D09
	{  28, 0x0b000000, 0x0f000000 }, // b, bl:3:0x0BF4F010
	{  29, 0xe1e00000, 0xfdfff000 }, // mvn:6:0xE3E00000
	{  30, 0xe5840000, 0xfdfff000 }, // str:4:0xE5840000
	{  31, 0xe5847000, 0xfdfff000 }, // str:4:0xE584700C
	/* 31/32 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_ScreenLock_4[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4010
	{   1, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB000100
	{   2, 0xe1100001, 0xfdffffff }, // tst:7:0xE3100001
	{   3, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE1A04000
	{   4, 0x0a000000, 0x0f000000 }, // b, bl:3:0x1A000003
	{   5, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB00010C
	{   6, 0xe00f0000, 0xf00ff000 }, // ldr:8:0xE59F00F4
	{   7, 0xe5900000, 0xfdfff000 }, // ldr:4:0xE590000C
	{   8, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFE1723
	{   9, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00004
	{  10, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD8010
	/* 11/11 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_apex2us_4[] = {
	{   0, 0xe1700d09, 0xfdffffff }, // cmn:7:0xE3700D09
	{   1, 0xb00f0000, 0xf00ff000 }, // ldr:8:0xB59F0068
	{   2, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4010
	{   3, 0x0a000000, 0x0f000000 }, // b, bl:3:0xBA000006
	{   4, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500E5A
	{   5, 0xc1a00000, 0xfdfff000 }, // mov:6:0xC3A00E5A
	{   6, 0x0a000000, 0x0f000000 }, // b, bl:3:0xCA00000B
	{   7, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500D09
	{   8, 0x0a000000, 0x0f000000 }, // b, bl:3:0xAA000009
	{   9, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500000
	{  10, 0x0a000000, 0x0f000000 }, // b, bl:3:0x0A000001
	{  11, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01003
	{  12, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB055C53
	{  13, 0xe00f1000, 0xf00ff000 }, // ldr:8:0xE59F103C
	{  14, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00800
	{  15, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00840
	{  16, 0xe0800000, 0xfdf0f000 }, // add:6:0xE0810100
	{  17, 0xe5900000, 0xfdfff000 }, // ldr:4:0xE5900300
	{  18, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD8010
	{  19, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00300
	{  20, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01060
	{  21, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB055C4A
	{  22, 0xe00f1000, 0xf00ff000 }, // ldr:8:0xE59F1020
	{  23, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00800
	{  24, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00840
	{  25, 0xe0800000, 0xfdf0f000 }, // add:6:0xE0810080
	{  26, 0xe0400000, 0xfdfff000 }, // sub:6:0xE2400C03
	{  27, 0xe1d00000, 0xfdfff000 }, // bic:6:0xE1D000B0
	{  28, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD8010
	/* 29/32 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_GetDrive_ClusterSize_5[] = {
	{   0, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500001
	{   1, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4010
	{   2, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE1A04000
	{   3, 0x200f0000, 0xf00ff000 }, // ldr:8:0x251F03E4
	{   4, 0x200f1000, 0xf00ff000 }, // ldr:8:0x259F1270
	{   5, 0x0b000000, 0x0f000000 }, // b, bl:3:0x2BFF154B
	{   6, 0xe00f0000, 0xf00ff000 }, // ldr:8:0xE51F097C
	{   7, 0xe0800000, 0xfdf0f000 }, // add:6:0xE0800384
	{   8, 0xe5900000, 0xfdfff000 }, // ldr:4:0xE5900054
	{   9, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD4010
	{  10, 0x0a000000, 0x0f000000 }, // b, bl:3:0xEAFFF30C
	/* 11/11 */
	{ -1, 10, -2 },
	{   0, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{   1, 0x15900064, 0xfdffffff }, // ldr:4:0x15900064
	{   2, 0x01a00000, 0xfdffffff }, // mov:6:0x03A00000
	/* 3/4 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_GetDrive_TotalClusters_5[] = {
	{   0, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500001
	{   1, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4010
	{   2, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE1A04000
	{   3, 0x200f1000, 0xf00ff000 }, // ldr:8:0x259F124C
	{   4, 0x200f0000, 0xf00ff000 }, // sub:10:0x224F0D26
	{   5, 0x0b000000, 0x0f000000 }, // b, bl:3:0x2BFF1540
	{   6, 0xe00f0000, 0xf00ff000 }, // ldr:8:0xE51F09A8
	{   7, 0xe0800000, 0xfdf0f000 }, // add:6:0xE0800384
	{   8, 0xe5900000, 0xfdfff000 }, // ldr:4:0xE5900054
	{   9, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD4010
	{  10, 0x0a000000, 0x0f000000 }, // b, bl:3:0xEAFFF305
	/* 11/11 */
	{ -1, 10, -2 },
	{   0, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{   1, 0x15900054, 0xfdffffff }, // ldr:4:0x15900054
	{   2, 0x10400001, 0xfdffffff }, // sub:6:0x12400001
	{   3, 0x01a00000, 0xfdffffff }, // mov:6:0x03A00000
	/* 4/5 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_GetDrive_FreeClusters_5[] = {
	{   0, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500001
	{   1, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4010
	{   2, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE1A04000
	{   3, 0x200f0000, 0xf00ff000 }, // ldr:8:0x251F043C
	{   4, 0x200f1000, 0xf00ff000 }, // ldr:8:0x259F1220
	{   5, 0x0b000000, 0x0f000000 }, // b, bl:3:0x2BFF1535
	{   6, 0xe00f0000, 0xf00ff000 }, // ldr:8:0xE51F09D4
	{   7, 0xe0800000, 0xfdf0f000 }, // add:6:0xE0800384
	{   8, 0xe5900000, 0xfdfff000 }, // ldr:4:0xE5900054
	{   9, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD4010
	{  10, 0x0a000000, 0x0f000000 }, // b, bl:3:0xEAFFF2FF
	/* 11/11 */
	{ -1, 10, -2 },
	{   0, 0xe1500000, 0xfdffffff }, // cmp:7:0xE3500000
	{   1, 0x15900060, 0xfdffffff }, // ldr:4:0x15900060
	{   2, 0x01a00000, 0xfdffffff }, // mov:6:0x03A00000
	/* 3/4 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_Fgets_Fut_6[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D41F0
	{   1, 0xe1b04000, 0xfdfff000 }, // mov:6:0xE1B04002
	{   2, 0xe1a05000, 0xfdfff000 }, // mov:6:0xE1A05000
	{   3, 0xe1a06000, 0xfdfff000 }, // mov:6:0xE1A06001
	{   4, 0x01a00000, 0xfdfff000 }, // mov:6:0x03A00000
	{   5, 0x08bd0000, 0xffff0000 }, // ldm:5:0x08BD81F0
	{   6, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01001
	{   7, 0xe0800000, 0xfdf0f000 }, // add:6:0xE2840020
	{   8, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB00003C
	{   9, 0xe1a07000, 0xfdfff000 }, // mov:6:0xE1A07000
	{  10, 0xe1a02000, 0xfdfff000 }, // mov:6:0xE1A02004
	{  11, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE1A01006
	{  12, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00005
	{  13, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB010B0A
	{  14, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE1A04000
	{  15, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00007
	{  16, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB00003E
	{  17, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00004
	{  18, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD81F0
	/* 19/19 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_srand_6[] = {
	{   0, 0xe00f1000, 0xf00ff000 }, // ldr:8:0xE59F102C
	{   1, 0xe5810000, 0xfdfff000 }, // str:4:0xE5810000
	{   3, 0xe00f1000, 0xf00ff000 }, // ldr:8:0xE59F1020
	{   4, 0xe00f2000, 0xf00ff000 }, // ldr:8:0xE59F2020
	{   5, 0xe5910000, 0xfdfff000 }, // ldr:4:0xE5910000
	{   6, 0xe0000092, 0xffffffff }, // mul:11:0xE0000092
	{   7, 0xe0800000, 0xfdf0f000 }, // add:6:0xE2800A03
	{   8, 0xe0800000, 0xfdf0f000 }, // add:6:0xE2800039
	{   9, 0xe5810000, 0xfdfff000 }, // str:4:0xE5810000
	{  10, 0xe1e01000, 0xfdfff000 }, // mvn:6:0xE3E01902
	/* 10/13 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_rand_6[] = {
	{   0, 0xe00f1000, 0xf00ff000 }, // ldr:8:0xE59F1020
	{   1, 0xe00f2000, 0xf00ff000 }, // ldr:8:0xE59F2020
	{   2, 0xe5910000, 0xfdfff000 }, // ldr:4:0xE5910000
	{   3, 0xe0000092, 0xffffffff }, // mul:11:0xE0000092
	{   4, 0xe0800000, 0xfdf0f000 }, // add:6:0xE2800A03
	{   5, 0xe0800000, 0xfdf0f000 }, // add:6:0xE2800039
	{   6, 0xe5810000, 0xfdfff000 }, // str:4:0xE5810000
	{   7, 0xe1e01000, 0xfdfff000 }, // mvn:6:0xE3E01902
	/* 8/10 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_set_control_event_6[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4010
	{   1, 0xe2001000, 0xfffff000 }, // and:7:0xE2001CFF
	{   2, 0xe2003000, 0xfffff000 }, // and:7:0xE2003101
	{   3, 0xe1700001, 0xfdffffff }, // cmn:7:0xE3700001
	{   4, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE1A01421
	{   5, 0xe2002000, 0xfffff000 }, // and:7:0xE20020FF
	{   6, 0xe1a0c000, 0xfdfff000 }, // mov:6:0xE1A0CFA0
	{   7, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE1A04F23
	{   8, 0x08bd0000, 0xffff0000 }, // ldm:5:0x08BD8010
	{   9, 0xe1540000, 0xfdfff000 }, // cmp:7:0xE3540000
	{  10, 0xe00f3000, 0xf00ff000 }, // ldr:8:0xE59F344C
	{  11, 0x15832000, 0xfdfff000 }, // str:4:0x17832101
	{  12, 0x18bd0000, 0xffff0000 }, // ldm:5:0x18BD8010
	{  13, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE3A00001
	{  14, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00210
	{  15, 0xe5932000, 0xfdfff000 }, // ldr:4:0xE7932101
	{  16, 0xe15c0000, 0xfdfff000 }, // cmp:7:0xE35C0000
	{  17, 0x01e00000, 0xfdfff000 }, // mvn:6:0x01E00000
	{  20, 0xe5830000, 0xfdfff000 }, // str:4:0xE7830101
	{  21, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD8010
	/* 20/22 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_GetDrive_ClusterSize_6[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4010
	{   1, 0xe1b04000, 0xfdfff000 }, // mov:6:0xE1B04000
	{   2, 0x100f1000, 0xf00ff000 }, // ldr:8:0x159F1358
	{   3, 0x100f0000, 0xf00ff000 }, // ldr:8:0x151F0310
	{   4, 0x0b000000, 0x0f000000 }, // b, bl:3:0x1BFE8FAD
	{   5, 0xe00f1000, 0xf00ff000 }, // ldr:8:0xE51F1CC4
	{   6, 0xe0800000, 0xfdf0f000 }, // add:6:0xE0840204
	{   7, 0xe0800000, 0xfdf0f000 }, // add:6:0xE0810100
	{   8, 0xe5901000, 0xfdfff000 }, // ldr:4:0xE5901004
	{   9, 0xe5900000, 0xfdfff000 }, // ldr:4:0xE5900008
	{  10, 0xe0000091, 0xffffffff }, // mul:11:0xE0000091
	{  11, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD8010
	/* 12/12 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_GetDrive_TotalClusters_6[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4010
	{   1, 0xe1b04000, 0xfdfff000 }, // mov:6:0xE1B04000
	{   2, 0x100f1000, 0xf00ff000 }, // ldr:8:0x159F132C
	{   3, 0x100f0000, 0xf00ff000 }, // ldr:8:0x151F0340
	{   4, 0x0b000000, 0x0f000000 }, // b, bl:3:0x1BFE8FA1
	{   5, 0xe00f1000, 0xf00ff000 }, // ldr:8:0xE51F1CF4
	{   6, 0xe0800000, 0xfdf0f000 }, // add:6:0xE0840204
	{   7, 0xe0800000, 0xfdf0f000 }, // add:6:0xE0810100
	{   8, 0xe5900000, 0xfdfff000 }, // ldr:4:0xE5900034
	{   9, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD8010
	/* 10/10 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_GetDrive_FreeClusters_6[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4010
	{   1, 0xe1b04000, 0xfdfff000 }, // mov:6:0xE1B04000
	{   2, 0x100f1000, 0xf00ff000 }, // ldr:8:0x159F1308
	{   3, 0x100f0000, 0xf00ff000 }, // ldr:8:0x151F0368
	{   4, 0x0b000000, 0x0f000000 }, // b, bl:3:0x1BFE8F97
	{   5, 0xe00f0000, 0xf00ff000 }, // ldr:8:0xE51F0378
	{   6, 0xe5900000, 0xfdfff000 }, // ldr:4:0xE7900104
	{   7, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD8010
	/* 8/8 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_mkdir_6[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D41F0
	{   1, 0xe1a05000, 0xfdfff000 }, // mov:6:0xE1A05000
	{   3, 0xe1a07000, 0xfdfff000 }, // mov:6:0xE1A07001
	{   4, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB01094E
	{   5, 0xe1a08000, 0xfdfff000 }, // mov:6:0xE1A08000
	{   7, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE3A04000
	{   8, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB01097D
	{   9, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500000
	{  10, 0x0a000000, 0x0f000000 }, // b, bl:3:0x1A000014
	{  11, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01001
	{  12, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00008
	{  13, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB010E49
	{  14, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01092
	{  15, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00005
	{  16, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB0030ED
	{  17, 0xe1a06000, 0xfdfff000 }, // mov:6:0xE1A06000
	{  18, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00008
	{  19, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB010E60
	{  20, 0xe1560000, 0xfdfff000 }, // cmp:7:0xE3560000
	{  21, 0x0a000000, 0x0f000000 }, // b, bl:3:0x1A000009
	{  22, 0xe1570000, 0xfdfff000 }, // cmp:7:0xE3570001
	{  23, 0x11a04000, 0xfdfff000 }, // mov:6:0x13A04001
	{  24, 0x0a000000, 0x0f000000 }, // b, bl:3:0x1A000004
	{  25, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00005
	{  26, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB010250
	{  27, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500001
	{  28, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE1A04000
	{  29, 0x0a000000, 0x0f000000 }, // b, bl:3:0x1A000001
	{  30, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00005
	{  31, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB0101A1
	/* 30/32 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_GetImageFolder_6[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D43F0
	{   1, 0xe00f4000, 0xf00ff000 }, // ldr:8:0xE59F42EC
	{   2, 0xe1a05000, 0xfdfff000 }, // mov:6:0xE1A05001
	{   3, 0xe1a06000, 0xfdfff000 }, // mov:6:0xE1A06000
	{   4, 0xe04dd000, 0xfdfff000 }, // sub:6:0xE24DD014
	{   5, 0xe1a07000, 0xfdfff000 }, // mov:6:0xE1A07002
	{   6, 0xe1a08000, 0xfdfff000 }, // mov:6:0xE1A08003
	{   7, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE1A01004
	{   8, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00005
	{   9, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFFC39
	{  10, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500000
	{  11, 0x000f0000, 0xf00ff000 }, // ldr:8:0x059F02A8
	{  12, 0x01a01000, 0xfdfff000 }, // mov:6:0x01A01004
	{  13, 0x0b000000, 0x0f000000 }, // b, bl:3:0x0BFAD4E5
	{  14, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00005
	{  15, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFFD0D
	{  16, 0xe1b04000, 0xfdfff000 }, // mov:6:0xE1B04000
	{  17, 0x01a00000, 0xfdfff000 }, // mov:6:0x03A00001
	{  18, 0x0a000000, 0x0f000000 }, // b, bl:3:0x0A00002A
	{  19, 0xe5940000, 0xfdfff000 }, // ldr:4:0xE5940008
	{  20, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01000
	{  21, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFB4616
	{  22, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00205
	{  23, 0xe1a09000, 0xfdfff000 }, // mov:6:0xE1A09B20
	{  24, 0xe00f1000, 0xf00ff000 }, // ldr:8:0xE59F1288
	{  25, 0xe5940000, 0xfdfff000 }, // ldr:4:0xE5940010
	{  26, 0xe1a02000, 0xfdfff000 }, // mov:6:0xE1A02009
	{  27, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB058DEF
	{  28, 0xe00f0000, 0xf00ff000 }, // ldr:8:0xE59F0278
	{  29, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFAA9F4
	{  30, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE350000E
	{  31, 0x0a000000, 0x0f000000 }, // b, bl:3:0x0A00000E
	/* 32/32 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_PT_PlaySound_6[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4070
	{   1, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE1A04000
	{   2, 0xe1a05000, 0xfdfff000 }, // mov:6:0xE1A05804
	{   3, 0xe1100901, 0xfdffffff }, // tst:7:0xE3100901
	{   4, 0xe1a06000, 0xfdfff000 }, // mov:6:0xE1A06001
	{   5, 0xe1a05000, 0xfdfff000 }, // mov:6:0xE1A05825
	{   6, 0x0a000000, 0x0f000000 }, // b, bl:3:0x0A000007
	{   7, 0xe1a02000, 0xfdfff000 }, // mov:6:0xE1A02006
	{   8, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01000
	{   9, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00005
	{  10, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFFF0C
	{  11, 0xe1100001, 0xfdffffff }, // tst:7:0xE3100001
	{  12, 0x08bd0000, 0xffff0000 }, // ldm:5:0x08BD8070
	{  13, 0xe00f1000, 0xf00ff000 }, // ldr:8:0xE59F13DC
	{  14, 0x0a000000, 0x0f000000 }, // b, bl:3:0xEA00000E
	{  15, 0xe00f0000, 0xf00ff000 }, // ldr:8:0xE51F00AC
	{  16, 0xe5900000, 0xfdfff000 }, // ldr:4:0xE5900004
	{  17, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500001
	{  18, 0x11a01000, 0xfdfff000 }, // mov:6:0x13A01F7F
	{  19, 0x100f0000, 0xf00ff000 }, // sub:10:0x124F00B4
	{  20, 0x0b000000, 0x0f000000 }, // b, bl:3:0x1BFE3CFA
	{  21, 0xe1140a02, 0xfdffffff }, // tst:7:0xE3140A02
	{  22, 0x08bd0000, 0xffff0000 }, // ldm:5:0x08BD8070
	{  23, 0xe1a02000, 0xfdfff000 }, // mov:6:0xE1A02006
	{  24, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01000
	{  25, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00005
	{  26, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFFF3B
	{  27, 0xe1100001, 0xfdffffff }, // tst:7:0xE3100001
	{  28, 0x08bd0000, 0xffff0000 }, // ldm:5:0x08BD8070
	{  29, 0xe00f1000, 0xf00ff000 }, // ldr:8:0xE59F13A0
	{  30, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD4070
	{  31, 0xe00f0000, 0xf00ff000 }, // sub:10:0xE24F00E4
	/* 32/32 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_ReadFastDir_6[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4070
	{   1, 0xe1b04000, 0xfdfff000 }, // mov:6:0xE1B04000
	{   2, 0xe1a05000, 0xfdfff000 }, // mov:6:0xE1A05001
	{   3, 0x0a000000, 0x0f000000 }, // b, bl:3:0x0A00000F
	{   4, 0xe1a06000, 0xfdfff000 }, // mov:6:0xE3A06000
	{   5, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE1A01005
	{   6, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00004
	{   7, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFFF19
	{   8, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500000
	{   9, 0x0a000000, 0x0f000000 }, // b, bl:3:0x0A00000B
	{  10, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500001
	{  11, 0x0a000000, 0x0f000000 }, // b, bl:3:0x0A00000B
	{  12, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00004
	{  13, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFFEE4
	{  14, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500000
	{  15, 0x0a000000, 0x0f000000 }, // b, bl:3:0x0AFFFFF4
	{  16, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500001
	{  17, 0x0a000000, 0x0f000000 }, // b, bl:3:0x0A000005
	{  18, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500002
	{  19, 0x0a000000, 0x0f000000 }, // b, bl:3:0x1AFFFFF0
	{  20, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE3A00000
	{  21, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD8070
	{  22, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE3A00001
	{  23, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD8070
	{  24, 0xe5c56000, 0xfdfff000 }, // strb:4:0xE5C56000
	{  25, 0x0a000000, 0x0f000000 }, // b, bl:3:0xEAFFFFFB
	{  26, 0x0a000000, 0x0f000000 }, // b, bl:3:0xEAFFFF7B
	{  27, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D5FF0
	{  28, 0xe1a05000, 0xfdfff000 }, // mov:6:0xE1A05001
	{  29, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE1A04000
	{  30, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE1A01000
	{  31, 0xe1a02000, 0xfdfff000 }, // mov:6:0xE3A02008
	/* 32/32 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_Remove_6[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4070
	{   1, 0xe1a05000, 0xfdfff000 }, // mov:6:0xE1A05000
	{   3, 0xe1e04000, 0xfdfff000 }, // mvn:6:0xE3E04000
	{   4, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB010A42
	{   5, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500000
	{   6, 0x0a000000, 0x0f000000 }, // b, bl:3:0x0A000004
	{   7, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00005
	{   8, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB00330C
	{   9, 0xe1b04000, 0xfdfff000 }, // mov:6:0xE1B04000
	{  10, 0x01a00000, 0xfdfff000 }, // mov:6:0x01A00005
	{  11, 0x0b000000, 0x0f000000 }, // b, bl:3:0x0B0102B3
	{  12, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00004
	{  13, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD8070
	/* 13/14 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_SetFileTimeStamp_6[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D41FC
	{   1, 0xe1a07000, 0xfdfff000 }, // mov:6:0xE1A07000
	{   3, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE1A04001
	{   4, 0xe1a05000, 0xfdfff000 }, // mov:6:0xE1A05002
	{   5, 0xe1a06000, 0xfdfff000 }, // mov:6:0xE3A06000
	{   6, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB0109BA
	{   7, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500000
	{   8, 0x0a000000, 0x0f000000 }, // b, bl:3:0x0A000012
	{   9, 0xe00f1000, 0xf00ff000 }, // ldr:8:0xE59F12E8
	{  10, 0xe1540000, 0xfdfff000 }, // cmp:7:0xE1540001
	{  11, 0xb1a04000, 0xfdfff000 }, // mov:6:0xB1A04001
	{  12, 0xe1550000, 0xfdfff000 }, // cmp:7:0xE1550001
	{  13, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00001
	{  14, 0xb1a05000, 0xfdfff000 }, // mov:6:0xB1A05000
	{  15, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE1A0100D
	{  16, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00007
	{  17, 0xe58d4000, 0xfdfff000 }, // str:4:0xE58D4004
	{  18, 0xe58d5000, 0xfdfff000 }, // str:4:0xE58D5000
	{  19, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB003297
	{  20, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500000
	{  21, 0x0a000000, 0x0f000000 }, // b, bl:3:0x1A000005
	{  22, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00007
	{  23, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB010297
	{  24, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500001
	{  25, 0xe1a06000, 0xfdfff000 }, // mov:6:0xE1A06000
	{  26, 0x01a00000, 0xfdfff000 }, // mov:6:0x01A00007
	{  27, 0x0b000000, 0x0f000000 }, // b, bl:3:0x0B010203
	{  28, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00006
	{  29, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD81FC
	{  30, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4070
	{  31, 0xe1a05000, 0xfdfff000 }, // mov:6:0xE1A05000
	/* 31/32 */
	{ -1, -1, -1 },
};

static FuncSig func_sig__sqrt_6[] = {
	{   0, 0xe1a0c000, 0xfdfff000 }, // mov:6:0xE3A0C207
	{   2, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4070
	{   3, 0xe111000c, 0xfdffffff }, // tst:7:0xE111000C
	{   4, 0x0a000000, 0x0f000000 }, // b, bl:3:0x0A000044
	{   5, 0xe1dce000, 0xfdfff000 }, // bic:6:0xE1DCE001
	{   6, 0x0a000000, 0x0f000000 }, // b, bl:3:0x0A000047
	{   7, 0xe1110102, 0xfdffffff }, // tst:7:0xE3110102
	{   8, 0x0a000000, 0x0f000000 }, // b, bl:3:0x1A00004D
	{   9, 0xe1a0c000, 0xfdfff000 }, // mov:6:0xE1A0CA21
	{  10, 0xe1c11000, 0xfdfff000 }, // bic:6:0xE1C11A0C
	{  12, 0xe080c000, 0xfdf0f000 }, // add:6:0xE28CC0FD
	{  13, 0xe1b0c000, 0xfdfff000 }, // mov:6:0xE1B0C0AC
	{  14, 0xe080c000, 0xfdf0f000 }, // add:6:0xE28CCD06
	{  15, 0x0a000000, 0x0f000000 }, // b, bl:3:0x3A000001
	{  16, 0xe1b00000, 0xfdfff000 }, // mov:6:0xE1B00080
	{  18, 0xe1a03000, 0xfdfff000 }, // mov:6:0xE3A03000
	{  19, 0xe1a02000, 0xfdfff000 }, // mov:6:0xE3A02101
	{  20, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE1A01501
	{  22, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00500
	{  23, 0xe0411000, 0xfdfff000 }, // sub:6:0xE2411101
	{  24, 0xe1a0e000, 0xfdfff000 }, // mov:6:0xE3A0E201
	{  25, 0xe0514000, 0xfdfff000 }, // sub:6:0xE0514002
	{  26, 0x20544000, 0xfdfff000 }, // sub:6:0x2054400E
	{  27, 0x20802000, 0xfdf0f000 }, // add:6:0x2082208E
	{  28, 0x21a01000, 0xfdfff000 }, // mov:6:0x21A01004
	{  29, 0xe1b00000, 0xfdfff000 }, // mov:6:0xE1B00080
	{  31, 0xe1b0e000, 0xfdfff000 }, // mov:6:0xE1B0E0AE
	/* 27/32 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_add_ptp_handler_6[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D47F0
	{   1, 0xe00f4000, 0xf00ff000 }, // ldr:8:0xE51F4030
	{   2, 0xe1a08000, 0xfdfff000 }, // mov:6:0xE1A08000
	{   3, 0xe5940000, 0xfdfff000 }, // ldr:4:0xE5940000
	{   4, 0xe1a06000, 0xfdfff000 }, // mov:6:0xE1A06001
	{   5, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500000
	{   6, 0xe1a07000, 0xfdfff000 }, // mov:6:0xE1A07002
	{   7, 0x01a00000, 0xfdfff000 }, // mov:6:0x03A00017
	{   8, 0x08bd0000, 0xffff0000 }, // ldm:5:0x08BD87F0
	{   9, 0xe1560000, 0xfdfff000 }, // cmp:7:0xE3560000
	{  10, 0x01a00000, 0xfdfff000 }, // mov:6:0x03A00003
	{  11, 0x08bd0000, 0xffff0000 }, // ldm:5:0x08BD87F0
	{  12, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBF66D22
	{  13, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500000
	{  14, 0x0a000000, 0x0f000000 }, // b, bl:3:0x0A000004
	{  15, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00008
	{  16, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFFFB9
	{  17, 0xe1100001, 0xfdffffff }, // tst:7:0xE3100001
	{  18, 0x11a00000, 0xfdfff000 }, // mov:6:0x13A00000
	{  19, 0x18bd0000, 0xffff0000 }, // ldm:5:0x18BD87F0
	{  20, 0xe5940000, 0xfdfff000 }, // ldr:4:0xE5940000
	{  21, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01000
	{  22, 0xe5909000, 0xfdfff000 }, // ldr:4:0xE5909000
	{  23, 0xe0804000, 0xfdf0f000 }, // add:6:0xE2804004
	{  24, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00009
	{  25, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBF681B9
	{  26, 0xe1100001, 0xfdffffff }, // tst:7:0xE3100001
	{  27, 0x11a05000, 0xfdfff000 }, // mov:6:0x13A05001
	{  28, 0x0a000000, 0x0f000000 }, // b, bl:3:0x1A000018
	{  29, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE1A01008
	{  30, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00004
	{  31, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB000130
	/* 32/32 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_close_6[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D401C
	{   1, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE1A04000
	{   2, 0xe1a02000, 0xfdfff000 }, // mov:6:0xE1A0200D
	{   3, 0xe0801000, 0xfdf0f000 }, // add:6:0xE28D1004
	{   4, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFFEA4
	{   5, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500000
	{   6, 0x0a000000, 0x0f000000 }, // b, bl:3:0xAA000004
	{   7, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFFC7E
	{   8, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01009
	{   9, 0xe5801000, 0xfdfff000 }, // str:4:0xE5801000
	{  10, 0xe1e00000, 0xfdfff000 }, // mvn:6:0xE3E00000
	{  11, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD801C
	{  12, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00004
	{  13, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFFE89
	{  14, 0xe00f0000, 0xf00ff000 }, // ldr:8:0xE59F03D4
	{  15, 0xe59d1000, 0xfdfff000 }, // ldr:4:0xE59D1004
	{  16, 0xe5900000, 0xfdfff000 }, // ldr:4:0xE7900101
	{  17, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE1A01004
	{  18, 0xe5902000, 0xfdfff000 }, // ldr:4:0xE5902004
	{  19, 0xe59d0000, 0xfdfff000 }, // ldr:4:0xE59D0000
	{  21, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD801C
	/* 21/22 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_open_6[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D40FE
	{   1, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE1A04000
	{   2, 0xe1a06000, 0xfdfff000 }, // mov:6:0xE1A06001
	{   3, 0xe1a07000, 0xfdfff000 }, // mov:6:0xE1A07002
	{   4, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFFE9C
	{   5, 0xe0505000, 0xfdfff000 }, // sub:6:0xE2505000
	{   6, 0x0a000000, 0x0f000000 }, // b, bl:3:0xAA000002
	{   7, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFFCAA
	{   8, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01017
	{   9, 0x0a000000, 0x0f000000 }, // b, bl:3:0xEA000009
	{  10, 0xe0802000, 0xfdf0f000 }, // add:6:0xE28D2008
	{  11, 0xe0801000, 0xfdf0f000 }, // add:6:0xE28D1004
	{  12, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00004
	{  13, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFFFBD
	{  14, 0xe1b04000, 0xfdfff000 }, // mov:6:0xE1B04000
	{  15, 0x0a000000, 0x0f000000 }, // b, bl:3:0x1A000005
	{  16, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00005
	{  17, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFFEB1
	{  18, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFFC9F
	{  19, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01002
	{  20, 0xe5801000, 0xfdfff000 }, // str:4:0xE5801000
	{  21, 0x0a000000, 0x0f000000 }, // b, bl:3:0xEA00000D
	{  22, 0xe00f0000, 0xf00ff000 }, // ldr:8:0xE59F0464
	{  23, 0xe59d1000, 0xfdfff000 }, // ldr:4:0xE59D1008
	{  24, 0xe58d5000, 0xfdfff000 }, // str:4:0xE58D5000
	{  25, 0xe5900000, 0xfdfff000 }, // ldr:4:0xE7900101
	{  26, 0xe59d1000, 0xfdfff000 }, // ldr:4:0xE59D1004
	{  27, 0xe590c000, 0xfdfff000 }, // ldr:4:0xE590C000
	{  28, 0xe1a03000, 0xfdfff000 }, // mov:6:0xE1A03007
	{  29, 0xe1a02000, 0xfdfff000 }, // mov:6:0xE1A02006
	{  30, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00004
	/* 31/32 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_OpenFastDir_6[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D43F8
	{   1, 0xe1a07000, 0xfdfff000 }, // mov:6:0xE1A07000
	{   3, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBF631EB
	{   4, 0xe1a08000, 0xfdfff000 }, // mov:6:0xE1A08000
	{   5, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBF636DA
	{   6, 0xe1b05000, 0xfdfff000 }, // mov:6:0xE1B05000
	{   7, 0x0a000000, 0x0f000000 }, // b, bl:3:0x1A000001
	{   8, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE3A00000
	{   9, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD83F8
	{  10, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE3A00044
	{  11, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBF5392B
	{  12, 0xe1b04000, 0xfdfff000 }, // mov:6:0xE1B04000
	{  13, 0x01a01000, 0xfdfff000 }, // mov:6:0x03A01E1B
	{  14, 0x000f0000, 0xf00ff000 }, // add:10:0x028F0F9D
	{  15, 0x0b000000, 0x0f000000 }, // b, bl:3:0x0BF4C665
	{  16, 0xe1550000, 0xfdfff000 }, // cmp:7:0xE3550004
	{  17, 0xe1a06000, 0xfdfff000 }, // mov:6:0xE3A06000
	{  18, 0x05846000, 0xfdfff000 }, // str:4:0x05846004
	{  19, 0x05846000, 0xfdfff000 }, // str:4:0x05846008
	{  20, 0x0a000000, 0x0f000000 }, // b, bl:3:0x0A000007
	{  21, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE3A00902
	{  22, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBF5394D
	{  23, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01902
	{  24, 0xe9840000, 0xffff0000 }, // stm:5:0xE9840003
	{  25, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500000
	{  26, 0x000f1000, 0xf00ff000 }, // ldr:8:0x059F1250
	{  27, 0x000f0000, 0xf00ff000 }, // add:10:0x028F0D09
	{  28, 0x0b000000, 0x0f000000 }, // b, bl:3:0x0BF4C658
	{  29, 0xe1e00000, 0xfdfff000 }, // mvn:6:0xE3E00000
	{  30, 0xe5840000, 0xfdfff000 }, // str:4:0xE5840000
	{  31, 0xe5846000, 0xfdfff000 }, // str:4:0xE584600C
	/* 31/32 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_qsort_6[] = {
	{   0, 0xe52de000, 0xfdfff000 }, // str:4:0xE52DE004
	{   1, 0xe04dd000, 0xfdfff000 }, // sub:6:0xE24DD014
	{   2, 0xe1cd2000, 0xfdfff000 }, // bic:6:0xE1CD20F0
	{   4, 0xe1120003, 0xfdffffff }, // tst:7:0xE3120003
	{   5, 0x000f2000, 0xf00ff000 }, // ldr:8:0x059F2030
	{   6, 0x0a000000, 0x0f000000 }, // b, bl:3:0x0A000002
	{   7, 0xe1120001, 0xfdffffff }, // tst:7:0xE3120001
	{   8, 0x100f2000, 0xf00ff000 }, // ldr:8:0x159F2028
	{   9, 0x000f2000, 0xf00ff000 }, // ldr:8:0x059F2028
	{  10, 0xe58d2000, 0xfdfff000 }, // str:4:0xE58D2008
	{  11, 0xe00f2000, 0xf00ff000 }, // ldr:8:0xE59F2024
	{  12, 0xe58d2000, 0xfdfff000 }, // str:4:0xE58D200C
	{  13, 0xe00f2000, 0xf00ff000 }, // ldr:8:0xE59F2020
	{  14, 0xe58d2000, 0xfdfff000 }, // str:4:0xE58D2010
	{  15, 0xe1a02000, 0xfdfff000 }, // mov:6:0xE1A0200D
	{  16, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFFFB9
	{  17, 0xe080d000, 0xfdf0f000 }, // add:6:0xE28DD014
	{  18, 0xe49df000, 0xfdfff000 }, // ldr:4:0xE49DF004
	/* 18/19 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_time_6[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4038
	{   1, 0xe1a05000, 0xfdfff000 }, // mov:6:0xE1A05000
	{   2, 0xe00f4000, 0xf00ff000 }, // ldr:8:0xE51F41BC
	{   3, 0xe1e00000, 0xfdfff000 }, // mvn:6:0xE3E00000
	{   4, 0xe58d0000, 0xfdfff000 }, // str:4:0xE58D0000
	{   5, 0xe5940000, 0xfdfff000 }, // ldr:4:0xE5940000
	{   6, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500000
	{   7, 0x0a000000, 0x0f000000 }, // b, bl:3:0x1A000007
	{   8, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01001
	{   9, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE3A00000
	{  10, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFE9962
	{  11, 0xe1100001, 0xfdffffff }, // tst:7:0xE3100001
	{  12, 0x100f1000, 0xf00ff000 }, // ldr:8:0x159F1368
	{  13, 0xe5840000, 0xfdfff000 }, // str:4:0xE5840000
	{  14, 0x100f0000, 0xf00ff000 }, // sub:10:0x124F0F79
	{  15, 0x0b000000, 0x0f000000 }, // b, bl:3:0x1BFE287F
	{  16, 0xe5940000, 0xfdfff000 }, // ldr:4:0xE5940000
	{  17, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01000
	{  18, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFE99B5
	{  19, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A0000D
	{  20, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFE9A67
	{  21, 0xe1a02000, 0xfdfff000 }, // mov:6:0xE3A02001
	{  22, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01000
	{  23, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A0000D
	{  24, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFFFB4
	{  25, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500000
	{  26, 0x0a000000, 0x0f000000 }, // b, bl:3:0x1A000009
	{  27, 0xe5940000, 0xfdfff000 }, // ldr:4:0xE5940008
	{  28, 0xe5941000, 0xfdfff000 }, // ldr:4:0xE594100C
	{  29, 0xe1a02000, 0xfdfff000 }, // mov:6:0xE3A02000
	{  30, 0xe0800000, 0xfdf0f000 }, // add:6:0xE0800001
	{  31, 0xe59d1000, 0xfdfff000 }, // ldr:4:0xE59D1000
	/* 32/32 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_SetFileAttributes_6[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4070
	{   1, 0xe1a05000, 0xfdfff000 }, // mov:6:0xE1A05000
	{   3, 0xe1a06000, 0xfdfff000 }, // mov:6:0xE1A06001
	{   4, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE3A04000
	{   5, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB01099D
	{   6, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500000
	{   7, 0x0a000000, 0x0f000000 }, // b, bl:3:0x0A00000A
	{   8, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE1A01006
	{   9, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00005
	{  10, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB003370
	{  11, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500000
	{  12, 0x0a000000, 0x0f000000 }, // b, bl:3:0x1A000005
	{  13, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00005
	{  14, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB010282
	{  15, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500001
	{  16, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE1A04000
	{  17, 0x01a00000, 0xfdfff000 }, // mov:6:0x01A00005
	{  18, 0x0b000000, 0x0f000000 }, // b, bl:3:0x0B0101EE
	{  19, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00004
	{  20, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD8070
	/* 20/21 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_PT_PlaySound_7[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4070
	{   1, 0xe1100901, 0xfdffffff }, // tst:7:0xE3100901
	{   2, 0xe1a05000, 0xfdfff000 }, // mov:6:0xE1A05001
	{   3, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE1A04000
	{   4, 0x0a000000, 0x0f000000 }, // b, bl:3:0x0A000007
	{   5, 0xe1a02000, 0xfdfff000 }, // mov:6:0xE1A02005
	{   6, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01000
	{   7, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00004
	{   8, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFFF2C
	{   9, 0xe1100001, 0xfdffffff }, // tst:7:0xE3100001
	{  10, 0x08bd0000, 0xffff0000 }, // ldm:5:0x08BD8070
	{  11, 0xe00f1000, 0xf00ff000 }, // ldr:8:0xE59F11A4
	{  12, 0x0a000000, 0x0f000000 }, // b, bl:3:0xEA00000E
	{  13, 0xe00f0000, 0xf00ff000 }, // ldr:8:0xE51F008C
	{  14, 0xe5900000, 0xfdfff000 }, // ldr:4:0xE5900004
	{  15, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500001
	{  16, 0x11a01000, 0xfdfff000 }, // mov:6:0x13A01F7D
	{  17, 0x100f0000, 0xf00ff000 }, // sub:10:0x124F0098
	{  18, 0x0b000000, 0x0f000000 }, // b, bl:3:0x1BFEC0A0
	{  19, 0xe1140a02, 0xfdffffff }, // tst:7:0xE3140A02
	{  20, 0x08bd0000, 0xffff0000 }, // ldm:5:0x08BD8070
	{  21, 0xe1a02000, 0xfdfff000 }, // mov:6:0xE1A02005
	{  22, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01000
	{  23, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00004
	{  24, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFFF5A
	{  25, 0xe1100001, 0xfdffffff }, // tst:7:0xE3100001
	{  26, 0x08bd0000, 0xffff0000 }, // ldm:5:0x08BD8070
	{  27, 0xe00f1000, 0xf00ff000 }, // ldr:8:0xE59F1168
	{  28, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD4070
	{  29, 0xe00f0000, 0xf00ff000 }, // sub:10:0xE24F00C8
	{  30, 0x0a000000, 0x0f000000 }, // b, bl:3:0xEAFEC094
	{  31, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4010
	/* 32/32 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_ScreenUnlock_7[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4010
	{   1, 0xe00f4000, 0xf00ff000 }, // ldr:8:0xE59F4088
	{   2, 0xe5940000, 0xfdfff000 }, // ldr:4:0xE5940020
	{   3, 0xe1700001, 0xfdffffff }, // cmn:7:0xE3700001
	{   4, 0x000f1000, 0xf00ff000 }, // ldr:8:0x059F1080
	{   5, 0x000f0000, 0xf00ff000 }, // add:10:0x028F0080
	{   6, 0x0b000000, 0x0f000000 }, // b, bl:3:0x0BFA4C49
	{   7, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB00007F
	{   8, 0xe1100001, 0xfdffffff }, // tst:7:0xE3100001
	{   9, 0x18bd0000, 0xffff0000 }, // ldm:5:0x18BD8010
	{  10, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFFB91
	{  11, 0xe5940000, 0xfdfff000 }, // ldr:4:0xE594000C
	{  12, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD4010
	{  13, 0x0a000000, 0x0f000000 }, // b, bl:3:0xEAFA4AE3
	/* 14/14 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_ScreenLock_8[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4010
	{   1, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB0000CF
	{   2, 0xe1100001, 0xfdffffff }, // tst:7:0xE3100001
	{   3, 0x18bd0000, 0xffff0000 }, // ldm:5:0x18BD8010
	{   4, 0xe00f4000, 0xf00ff000 }, // ldr:8:0xE51F47E0
	{   5, 0xe5940000, 0xfdfff000 }, // ldr:4:0xE5940028
	{   6, 0xe0800000, 0xfdf0f000 }, // add:6:0xE2800001
	{   7, 0xe5840000, 0xfdfff000 }, // str:4:0xE5840028
	{   8, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB0000D8
	{   9, 0xe5940000, 0xfdfff000 }, // ldr:4:0xE594000C
	{  10, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBF8CF4C
	{  11, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE3A00000
	{  12, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD8010
	/* 13/13 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_ScreenUnlock_8[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4010
	{   1, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB0000A6
	{   2, 0xe1100001, 0xfdffffff }, // tst:7:0xE3100001
	{   3, 0x18bd0000, 0xffff0000 }, // ldm:5:0x18BD8010
	{   4, 0xe00f4000, 0xf00ff000 }, // ldr:8:0xE51F4884
	{   5, 0xe5940000, 0xfdfff000 }, // ldr:4:0xE5940028
	{   6, 0xe0400000, 0xfdfff000 }, // sub:6:0xE2400001
	{   7, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500000
	{   8, 0xe5840000, 0xfdfff000 }, // str:4:0xE5840028
	{   9, 0x0a000000, 0x0f000000 }, // b, bl:3:0x1A000001
	{  10, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFFFD8
	{  11, 0x0a000000, 0x0f000000 }, // b, bl:3:0xEA000001
	{  12, 0xb1a00000, 0xfdfff000 }, // mov:6:0xB3A00000
	{  13, 0xb5840000, 0xfdfff000 }, // str:4:0xB5840028
	{  14, 0xe5940000, 0xfdfff000 }, // ldr:4:0xE594000C
	{  15, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD4010
	{  16, 0x0a000000, 0x0f000000 }, // b, bl:3:0xEAF8CF1D
	/* 17/17 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_ScreenUnlock_9[] = {
	{   0, 0xe00f0000, 0xf00ff000 }, // ldr:8:0xE59F00B4
	{   1, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4010
	{   2, 0xe5900000, 0xfdfff000 }, // ldr:4:0xE5900000
	{   3, 0xe1700001, 0xfdffffff }, // cmn:7:0xE3700001
	{   4, 0x000f1000, 0xf00ff000 }, // ldr:8:0x059F10A8
	{   5, 0x000f0000, 0xf00ff000 }, // add:10:0x028F00A8
	{   6, 0x0b000000, 0x0f000000 }, // b, bl:3:0x0BFD9B29
	{   7, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB0000AB
	{   8, 0xe1100001, 0xfdffffff }, // tst:7:0xE3100001
	{   9, 0x18bd0000, 0xffff0000 }, // ldm:5:0x18BD8010
	{  10, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB0000B8
	{  11, 0xe00f0000, 0xf00ff000 }, // ldr:8:0xE59F0084
	{  12, 0xe5900000, 0xfdfff000 }, // ldr:4:0xE590000C
	{  13, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD4010
	{  14, 0x0a000000, 0x0f000000 }, // b, bl:3:0xEAFE0A3C
	/* 15/15 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_ScreenLock_10[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4010
	{   1, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB00006F
	{   2, 0xe1100001, 0xfdffffff }, // tst:7:0xE3100001
	{   3, 0x18bd0000, 0xffff0000 }, // ldm:5:0x18BD8010
	{   4, 0xe00f4000, 0xf00ff000 }, // ldr:8:0xE51F47E0
	{   5, 0xe00f1000, 0xf00ff000 }, // add:10:0xE28F1F7B
	{   6, 0xe5940000, 0xfdfff000 }, // ldr:4:0xE5940020
	{   7, 0xe0800000, 0xfdf0f000 }, // add:6:0xE2800001
	{   8, 0xe5840000, 0xfdfff000 }, // str:4:0xE5840020
	{   9, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE3A00060
	{  10, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFABF6E
	{  11, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFFA06
	{  12, 0xe5940000, 0xfdfff000 }, // ldr:4:0xE594000C
	{  13, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBF9990D
	{  14, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE3A00000
	{  15, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD8010
	/* 16/16 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_GetImageFolder_11[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D43F0
	{   1, 0xe1a05000, 0xfdfff000 }, // mov:6:0xE1A05001
	{   2, 0xe1a06000, 0xfdfff000 }, // mov:6:0xE1A06000
	{   3, 0xe04dd000, 0xfdfff000 }, // sub:6:0xE24DD014
	{   4, 0xe1a07000, 0xfdfff000 }, // mov:6:0xE1A07002
	{   5, 0xe1a08000, 0xfdfff000 }, // mov:6:0xE1A08003
	{   6, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01E65
	{   7, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00005
	{   8, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFFC1B
	{   9, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500000
	{  10, 0x000f0000, 0xf00ff000 }, // ldr:8:0x059F0224
	{  11, 0x01a01000, 0xfdfff000 }, // mov:6:0x03A01E65
	{  12, 0x0b000000, 0x0f000000 }, // b, bl:3:0x0B534B11
	{  13, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00005
	{  14, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFFCF7
	{  15, 0xe1b04000, 0xfdfff000 }, // mov:6:0xE1B04000
	{  16, 0x01a00000, 0xfdfff000 }, // mov:6:0x03A00001
	{  17, 0x0a000000, 0x0f000000 }, // b, bl:3:0x0A00002A
	{  18, 0xe5940000, 0xfdfff000 }, // ldr:4:0xE5940008
	{  19, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01000
	{  20, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB53494F
	{  21, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00205
	{  22, 0xe1a09000, 0xfdfff000 }, // mov:6:0xE1A09B20
	{  23, 0xe00f1000, 0xf00ff000 }, // ldr:8:0xE59F120C
	{  24, 0xe5940000, 0xfdfff000 }, // ldr:4:0xE5940010
	{  25, 0xe1a02000, 0xfdfff000 }, // mov:6:0xE1A02009
	{  26, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFFA2E
	{  27, 0xe00f0000, 0xf00ff000 }, // ldr:8:0xE59F01FC
	{  28, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBF92A33
	{  29, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE350000E
	{  30, 0x0a000000, 0x0f000000 }, // b, bl:3:0x0A00000E
	{  31, 0xe1a02000, 0xfdfff000 }, // mov:6:0xE1A0200D
	/* 32/32 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_PT_PlaySound_11[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D4070
	{   1, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE1A04000
	{   2, 0xe1a05000, 0xfdfff000 }, // mov:6:0xE1A05804
	{   3, 0xe1100901, 0xfdffffff }, // tst:7:0xE3100901
	{   4, 0xe1a06000, 0xfdfff000 }, // mov:6:0xE1A06001
	{   5, 0xe1a05000, 0xfdfff000 }, // mov:6:0xE1A05825
	{   6, 0x0a000000, 0x0f000000 }, // b, bl:3:0x0A000007
	{   7, 0xe1a02000, 0xfdfff000 }, // mov:6:0xE1A02006
	{   8, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01000
	{   9, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00005
	{  10, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFFF0A
	{  11, 0xe1100001, 0xfdffffff }, // tst:7:0xE3100001
	{  12, 0x08bd0000, 0xffff0000 }, // ldm:5:0x08BD8070
	{  13, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01F7F
	{  14, 0x0a000000, 0x0f000000 }, // b, bl:3:0xEA00000E
	{  15, 0xe00f0000, 0xf00ff000 }, // ldr:8:0xE51F00B4
	{  16, 0xe5900000, 0xfdfff000 }, // ldr:4:0xE5900004
	{  17, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500001
	{  18, 0x100f1000, 0xf00ff000 }, // ldr:8:0x159F13B0
	{  19, 0x100f0000, 0xf00ff000 }, // sub:10:0x124F00B8
	{  20, 0x0b000000, 0x0f000000 }, // b, bl:3:0x1B57E54B
	{  21, 0xe1140a02, 0xfdffffff }, // tst:7:0xE3140A02
	{  22, 0x08bd0000, 0xffff0000 }, // ldm:5:0x08BD8070
	{  23, 0xe1a02000, 0xfdfff000 }, // mov:6:0xE1A02006
	{  24, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01000
	{  25, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00005
	{  26, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFFFF39
	{  27, 0xe1100001, 0xfdffffff }, // tst:7:0xE3100001
	{  28, 0x08bd0000, 0xffff0000 }, // ldm:5:0x08BD8070
	{  29, 0xe00f1000, 0xf00ff000 }, // ldr:8:0xE59F1388
	{  30, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD4070
	{  31, 0xe00f0000, 0xf00ff000 }, // sub:10:0xE24F00E8
	/* 32/32 */
	{ -1, -1, -1 },
};

static FuncSig func_sig_mkdir_12[] = {
	{   0, 0xe92d0000, 0xffff0000 }, // stm:5:0xE92D41FF
	{   1, 0xe1a05000, 0xfdfff000 }, // mov:6:0xE1A05000
	{   3, 0xe1a07000, 0xfdfff000 }, // mov:6:0xE1A07001
	{   4, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB00D291
	{   5, 0xe1a08000, 0xfdfff000 }, // mov:6:0xE1A08000
	{   7, 0xe1a04000, 0xfdfff000 }, // mov:6:0xE3A04000
	{   8, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB00D2C7
	{   9, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500000
	{  10, 0x0a000000, 0x0f000000 }, // b, bl:3:0x1A00003E
	{  11, 0xe1a01000, 0xfdfff000 }, // mov:6:0xE3A01001
	{  12, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00008
	{  13, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB00D808
	{  14, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00008
	{  15, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB00D27B
	{  16, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB00D2C8
	{  17, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500000
	{  18, 0x0a000000, 0x0f000000 }, // b, bl:3:0x0A000024
	{  19, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE1A00008
	{  20, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEB00D6CB
	{  21, 0xe0803000, 0xfdf0f000 }, // add:6:0xE28D3004
	{  22, 0xe0802000, 0xfdf0f000 }, // add:6:0xE28D200C
	{  23, 0xe0801000, 0xfdf0f000 }, // add:6:0xE2851001
	{  24, 0x0b000000, 0x0f000000 }, // b, bl:3:0xEBFF8C63
	{  25, 0xe1500000, 0xfdfff000 }, // cmp:7:0xE3500000
	{  26, 0x0a000000, 0x0f000000 }, // b, bl:3:0xAA000002
	{  27, 0xe1a00000, 0xfdfff000 }, // mov:6:0xE3A00000
	{  28, 0xe080d000, 0xfdf0f000 }, // add:6:0xE28DD010
	{  29, 0xe8bd0000, 0xffff0000 }, // ldm:5:0xE8BD81F0
	{  30, 0xe0803000, 0xfdf0f000 }, // add:6:0xE28D3008
	{  31, 0xe58d3000, 0xfdfff000 }, // str:4:0xE58D3000
	/* 30/32 */
	{ -1, -1, -1 },
};

FuncsList func_list[] = {
	{ "CreateJumptable", func_sig_CreateJumptable_1, 1 },
	{ "DeleteFile_Fut", func_sig_DeleteFile_Fut_1, 1 },
	{ "Feof_Fut", func_sig_Feof_Fut_1, 1 },
	{ "Fflush_Fut", func_sig_Fflush_Fut_1, 1 },
	{ "Fgets_Fut", func_sig_Fgets_Fut_1, 1 },
	{ "Fgets_Fut", func_sig_Fgets_Fut_6, 6 },
	{ "GetDrive_ClusterSize", func_sig_GetDrive_ClusterSize_1, 1 },
	{ "GetDrive_ClusterSize", func_sig_GetDrive_ClusterSize_3, 3 },
	{ "GetDrive_ClusterSize", func_sig_GetDrive_ClusterSize_4, 4 },
	{ "GetDrive_ClusterSize", func_sig_GetDrive_ClusterSize_5, 5 },
	{ "GetDrive_ClusterSize", func_sig_GetDrive_ClusterSize_6, 6 },
	{ "GetDrive_FreeClusters", func_sig_GetDrive_FreeClusters_1, 1 },
	{ "GetDrive_FreeClusters", func_sig_GetDrive_FreeClusters_3, 3 },
	{ "GetDrive_FreeClusters", func_sig_GetDrive_FreeClusters_4, 4 },
	{ "GetDrive_FreeClusters", func_sig_GetDrive_FreeClusters_5, 5 },
	{ "GetDrive_FreeClusters", func_sig_GetDrive_FreeClusters_6, 6 },
	{ "GetDrive_TotalClusters", func_sig_GetDrive_TotalClusters_1, 1 },
	{ "GetDrive_TotalClusters", func_sig_GetDrive_TotalClusters_3, 3 },
	{ "GetDrive_TotalClusters", func_sig_GetDrive_TotalClusters_5, 5 },
	{ "GetDrive_TotalClusters", func_sig_GetDrive_TotalClusters_6, 6 },
	{ "GetFocusLensSubjectDistanceFromLens", func_sig_GetFocusLensSubjectDistanceFromLens_1, 1 },
	{ "GetFocusLensSubjectDistanceFromLens", func_sig_GetFocusLensSubjectDistanceFromLens_3, 3 },
	{ "GetImageFolder", func_sig_GetImageFolder_11, 11 },
	{ "GetImageFolder", func_sig_GetImageFolder_6, 6 },
	{ "GetParameterData", func_sig_GetParameterData_1, 1 },
	{ "GetSystemTime", func_sig_GetSystemTime_1, 1 },
	{ "OpenFastDir", func_sig_OpenFastDir_1, 1 },
	{ "OpenFastDir", func_sig_OpenFastDir_3, 3 },
	{ "OpenFastDir", func_sig_OpenFastDir_4, 4 },
	{ "OpenFastDir", func_sig_OpenFastDir_6, 6 },
	{ "PT_PlaySound", func_sig_PT_PlaySound_11, 11 },
	{ "PT_PlaySound", func_sig_PT_PlaySound_4, 4 },
	{ "PT_PlaySound", func_sig_PT_PlaySound_6, 6 },
	{ "PT_PlaySound", func_sig_PT_PlaySound_7, 7 },
	{ "ReadFastDir", func_sig_ReadFastDir_1, 1 },
	{ "ReadFastDir", func_sig_ReadFastDir_3, 3 },
	{ "ReadFastDir", func_sig_ReadFastDir_4, 4 },
	{ "ReadFastDir", func_sig_ReadFastDir_6, 6 },
	{ "Remove", func_sig_Remove_1, 1 },
	{ "Remove", func_sig_Remove_4, 4 },
	{ "Remove", func_sig_Remove_6, 6 },
	{ "RenameFile_Fut", func_sig_RenameFile_Fut_1, 1 },
	{ "ScreenLock", func_sig_ScreenLock_10, 10 },
	{ "ScreenLock", func_sig_ScreenLock_3, 3 },
	{ "ScreenLock", func_sig_ScreenLock_4, 4 },
	{ "ScreenLock", func_sig_ScreenLock_8, 8 },
	{ "ScreenUnlock", func_sig_ScreenUnlock_3, 3 },
	{ "ScreenUnlock", func_sig_ScreenUnlock_7, 7 },
	{ "ScreenUnlock", func_sig_ScreenUnlock_8, 8 },
	{ "ScreenUnlock", func_sig_ScreenUnlock_9, 9 },
	{ "SetFileAttributes", func_sig_SetFileAttributes_1, 1 },
	{ "SetFileAttributes", func_sig_SetFileAttributes_3, 3 },
	{ "SetFileAttributes", func_sig_SetFileAttributes_6, 6 },
	{ "SetFileTimeStamp", func_sig_SetFileTimeStamp_1, 1 },
	{ "SetFileTimeStamp", func_sig_SetFileTimeStamp_3, 3 },
	{ "SetFileTimeStamp", func_sig_SetFileTimeStamp_4, 4 },
	{ "SetFileTimeStamp", func_sig_SetFileTimeStamp_6, 6 },
	{ "SetLogicalEventActive", func_sig_SetLogicalEventActive_1, 1 },
	{ "SetParameterData", func_sig_SetParameterData_1, 1 },
	{ "_sqrt", func_sig__sqrt_1, 1 },
	{ "_sqrt", func_sig__sqrt_6, 6 },
	{ "add_ptp_handler", func_sig_add_ptp_handler_1, 1 },
	{ "add_ptp_handler", func_sig_add_ptp_handler_3, 3 },
	{ "add_ptp_handler", func_sig_add_ptp_handler_6, 6 },
	{ "apex2us", func_sig_apex2us_4, 4 },
	{ "close", func_sig_close_1, 1 },
	{ "close", func_sig_close_6, 6 },
	{ "closedir", func_sig_closedir_1, 1 },
	{ "closedir", func_sig_closedir_3, 3 },
	{ "closedir", func_sig_closedir_4, 4 },
	{ "exmem_alloc", func_sig_exmem_alloc_1, 1 },
	{ "kbd_pwr_off", func_sig_kbd_pwr_off_1, 1 },
	{ "kbd_pwr_off", func_sig_kbd_pwr_off_2, 2 },
	{ "kbd_pwr_on", func_sig_kbd_pwr_on_1, 1 },
	{ "kbd_pwr_on", func_sig_kbd_pwr_on_2, 2 },
	{ "mkdir", func_sig_mkdir_12, 12 },
	{ "mkdir", func_sig_mkdir_6, 6 },
	{ "mktime_ext", func_sig_mktime_ext_1, 1 },
	{ "open", func_sig_open_1, 1 },
	{ "open", func_sig_open_6, 6 },
	{ "qsort", func_sig_qsort_1, 1 },
	{ "qsort", func_sig_qsort_4, 4 },
	{ "qsort", func_sig_qsort_6, 6 },
	{ "rand", func_sig_rand_1, 1 },
	{ "rand", func_sig_rand_4, 4 },
	{ "rand", func_sig_rand_6, 6 },
	{ "set_control_event", func_sig_set_control_event_1, 1 },
	{ "set_control_event", func_sig_set_control_event_6, 6 },
	{ "srand", func_sig_srand_1, 1 },
	{ "srand", func_sig_srand_4, 4 },
	{ "srand", func_sig_srand_6, 6 },
	{ "stat", func_sig_stat_1, 1 },
	{ "strcat", func_sig_strcat_1, 1 },
	{ "strchr", func_sig_strchr_1, 1 },
	{ "strftime", func_sig_strftime_1, 1 },
	{ "strncmp", func_sig_strncmp_1, 1 },
	{ "strncpy", func_sig_strncpy_1, 1 },
	{ "strrchr", func_sig_strrchr_1, 1 },
	{ "time", func_sig_time_6, 6 },
	{ NULL }
};
