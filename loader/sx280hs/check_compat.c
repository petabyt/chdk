/* This file should be used in loader for boot compatibility checks */

#define LEDCNTRL_UNK  0     // LED control unknown (no blink possible)
#define LEDCNTRL_OLD  1     // DIGIC II...4; 0x46 to on, 0x44 to off
#define LEDCNTRL_NEW1 2     // DIGIC 5; bit5, inverted
#define LEDCNTRL_NEW2 3     // DIGIC 4+, 5; 0x93d800 to on, 0x83dc00 to off
#define LEDCNTRL_NEW3 4     // DIGIC 6; 0x4d0002 to on, 0x4c0003 to off

typedef struct {
    short *fw_pid;
    short pid;
} pid_sig_t;

typedef struct {
    const char *fw_str;
    const char *str;
} ver_sig_t;

typedef struct {
    unsigned short pid;     // camera P-ID
    short method;           // LED control method
    unsigned int led;       // LED MMIO address
    unsigned int addr;      // location of P-ID
} pid_led_t;

// following must be ordered by P-ID, order to be maintained inside NEED_ENCODED_DISKBOOT blocks only
pid_led_t pid_leds[]={
#ifndef NEED_ENCODED_DISKBOOT
{12479,LEDCNTRL_OLD,0xc02200e8, 0xffd7014e}, // dance: 0, ixus40_sd300, vx, power led
{12480,LEDCNTRL_OLD,0xc02200e8, 0xffd7014e}, // dance: 0, ixus30_sd200, vx,
{12528,LEDCNTRL_OLD,0xc0220088, 0xffd70130}, // dance: 0, s2is, vx, same leds as s3is
{12529,LEDCNTRL_OLD,0xc02200b0, 0xfffe0130}, // dance: 0, ixusw_sd430, vx,
{12530,LEDCNTRL_OLD,0xc02200e4, 0xffd70130}, // dance: 0, ixus700_sd500, vx, should be the print led
{12532,LEDCNTRL_OLD,0xc0220084, 0xffd70130}, // dance: 0, ixusizoom_sd30, vx,
{12536,LEDCNTRL_OLD,0xc0220084, 0xfffe0130}, // dance: 0, a430, vx,
{12537,LEDCNTRL_OLD,0xc0220084, 0xfffe0130}, // dance: 0, a410, vx,
{12538,LEDCNTRL_OLD,0xc0220088, 0xfffe0130}, // dance: 0, s80, vx, orange led
{12540,LEDCNTRL_OLD,0xc0220084, 0xfffe0130}, // dance: 0, a620, vx,
{12541,LEDCNTRL_OLD,0xc0220084, 0xfffe0130}, // dance: 0, a610, vx,
{12542,LEDCNTRL_OLD,0xc0220084, 0xfffe0130}, // dance: 0, ixus65_sd630, vx,
{12543,LEDCNTRL_OLD,0xc02200e4, 0xfffe0130}, // dance: 0, ixus55_sd450, vx,
//{12544,LEDCNTRL_OLD,0, 0xfffe0130}, // dance: 0, tx1, vx,
{12558,LEDCNTRL_OLD,0xc02200e4, 0xfffe0130}, // dance: 0, ixus50_sd400, vx,
{12559,LEDCNTRL_OLD,0xc0220084, 0xfffe0130}, // dance: 0, a420, vx,
{12565,LEDCNTRL_OLD,0xc02200c4, 0xfffe0130}, // dance: 0, ixus900_sd900, vx,
{12566,LEDCNTRL_OLD,0xc02200e4, 0xfffe0130}, // dance: 0, ixus750_sd550, vx,
{12567,LEDCNTRL_OLD,0xc0220084, 0xfffe0130}, // dance: 0, a700, vx,
{12569,LEDCNTRL_OLD,0xc0220084, 0xfffe0130}, // dance: 0, ixus800_sd700, vx,
{12570,LEDCNTRL_OLD,0xc0220088, 0xfffe0130}, // dance: 0, s3is, vx, orange led
{12571,LEDCNTRL_OLD,0xc0220084, 0xfffe0130}, // dance: 0, a540, vx,
{12572,LEDCNTRL_OLD,0xc0220084, 0xfffe0130}, // dance: 0, ixus60_sd600, vx,
{12581,LEDCNTRL_OLD,0xc022006c, 0xfffe0130}, // dance: 0, g7, vx,
{12582,LEDCNTRL_OLD,0xc0220084, 0xfffe0130}, // dance: 0, a530, vx,
{12598,LEDCNTRL_OLD,0xc02200c4, 0xfffe0130}, // dance: 0, ixus850_sd800, vx,
{12600,LEDCNTRL_OLD,0xc0220084, 0xfffe0130}, // dance: 0, a710, vx,
{12601,LEDCNTRL_OLD,0xc0220084, 0xfffe0130}, // dance: 0, a640, vx,
{12602,LEDCNTRL_OLD,0xc0220084, 0xfffe0130}, // dance: 0, a630, vx,
{12616,LEDCNTRL_OLD,0xc02200d4, 0xfffe0130}, // dance: 0, s5is, dry,
{12617,LEDCNTRL_OLD,0xc0220084, 0xfffe0130}, // dance: 0, a460, vx,
{12619,LEDCNTRL_OLD,0xc02200c4, 0xfffe0130}, // dance: 0, ixus950_sd850, vx,
{12620,LEDCNTRL_OLD,0xc02200c4, 0xfffe0130}, // dance: 0, a570, vx,
{12621,LEDCNTRL_OLD,0xc02200c4, 0xfffe0130}, // dance: 0, a560, vx,
{12622,LEDCNTRL_OLD,0xc02200c4, 0xfffe0130}, // dance: 0, ixus75_sd750, vx,
{12623,LEDCNTRL_OLD,0xc02200c4, 0xfffe0130}, // dance: 0, ixus70_sd1000, vx,
{12624,LEDCNTRL_OLD,0xc0220084, 0xfffe0130}, // dance: 0, a550, vx,
{12629,LEDCNTRL_OLD,0xc0220084, 0xfffe0130}, // dance: 0, a450, vx,
{12634,LEDCNTRL_OLD,0xc022006c, 0xfffe0130}, // dance: 0, g9, dry,
{12635,LEDCNTRL_OLD,0xc02200c4, 0xfffe0130}, // dance: 0, a650, dry,
{12637,LEDCNTRL_OLD,0xc02200c4, 0xfffe0130}, // dance: 0, a720, dry,
{12638,LEDCNTRL_OLD,0xc02200c4, 0xfffe0130}, // dance: 0, sx100is, dry,
{12639,LEDCNTRL_OLD,0xc02200cc, 0xfffe0130}, // dance: 0, ixus960_sd950, dry,
{12640,LEDCNTRL_OLD,0xc02200cc, 0xfffe0130}, // dance: 0, ixus860_sd870, dry,
#elif (NEED_ENCODED_DISKBOOT == 1)
{12659,LEDCNTRL_OLD,0xc02200d4, 0xfffe0130}, // dance: 1, ixus970_sd890, dry,
{12660,LEDCNTRL_OLD,0xc0220130, 0xfffe0130}, // dance: 1, ixus90_sd790, dry,
{12661,LEDCNTRL_OLD,0xc02200d4, 0xfffe0130}, // dance: 1, ixus85_sd770, dry,
{12662,LEDCNTRL_OLD,0xc02200c4, 0xfffe0130}, // dance: 1, a590, dry,
{12663,LEDCNTRL_OLD,0xc02200c4, 0xfffe0130}, // dance: 1, a580, dry,
{12666,LEDCNTRL_OLD,0xc0220084, 0xfffe0130}, // dance: 1, a470, dry,
{12676,LEDCNTRL_OLD,0xc02200d4, 0xfffe0130}, // dance: 1, ixus80_sd1100, dry,
{12685,LEDCNTRL_OLD,0xc0220060, 0xfffe0130}, // dance: 1, sx10, dry,
{12686,LEDCNTRL_OLD,0xc02200c4, 0xfffe0130}, // dance: 1, a1000, dry,
{12687,LEDCNTRL_OLD,0xc02200d4, 0xfffe0130}, // dance: 1, g10, dry,
{12689,LEDCNTRL_OLD,0xc02200c4, 0xfffe0130}, // dance: 1, a2000, dry,
{12690,LEDCNTRL_OLD,0xc02200c4, 0xfffe0130}, // dance: 1, sx110is, dry,
{12691,LEDCNTRL_OLD,0xc02200bc, 0xfffe0130}, // dance: 1, ixus980_sd990, dry,
//{12693,LEDCNTRL_UNK,0, 0xfffe0130}, // dance: 1, sx1, dry,
{12694,LEDCNTRL_OLD,0xc02200d4, 0xfffe0130}, // dance: 1, ixus870_sd880, dry,
#elif (NEED_ENCODED_DISKBOOT == 2)
{12732,LEDCNTRL_OLD,0xc0220134, 0xfffe0130}, // dance: 2, d10, dry,
{12733,LEDCNTRL_OLD,0xc0220130, 0xfffe0130}, // dance: 2, ixus110_sd960, dry,
{12734,LEDCNTRL_OLD,0xc0220018, 0xfffe0130}, // dance: 2, a2100, dry,
{12735,LEDCNTRL_OLD,0xc0220088, 0xfffe0130}, // dance: 2, a480, dry,
{12736,LEDCNTRL_OLD,0xc0220138, 0xfffe0130}, // dance: 2, sx200is, dry,
{12738,LEDCNTRL_OLD,0xc0220128, 0xfffe0130}, // dance: 2, ixus100_sd780, dry,
{12739,LEDCNTRL_OLD,0xc02200cc, 0xfffe0130}, // dance: 2, a1100, dry,
{12740,LEDCNTRL_OLD,0xc0220138, 0xfffe0130}, // dance: 2, ixus95_sd1200, dry,
#elif (NEED_ENCODED_DISKBOOT == 3)
{12767,LEDCNTRL_OLD,0xc0220128, 0xfffe0130}, // dance: 3, g11, dry,
{12768,LEDCNTRL_OLD,0xc0220010, 0xfffe0130}, // dance: 3, sx120is, dry,
{12769,LEDCNTRL_OLD,0xc0220130, 0xfffe0130}, // dance: 3, s90, dry,
//{12772,LEDCNTRL_UNK,0, 0xfffe0130}, // dance: 3, sx20, dry,
{12773,LEDCNTRL_OLD,0xc0220130, 0xfffe0130}, // dance: 3, ixus200_sd980, dry,
{12774,LEDCNTRL_OLD,0xc0220134, 0xfffe0130}, // dance: 3, ixus120_sd940, dry,
#elif (NEED_ENCODED_DISKBOOT == 4)
{12783,LEDCNTRL_OLD,0xc0220088, 0xfffe0130}, // dance: 4, a495, dry,
{12784,LEDCNTRL_OLD,0xc0220088, 0xfffe0130}, // dance: 4, a490, dry,
{12785,LEDCNTRL_OLD,0xc0220010, 0xfffe0130}, // dance: 4, a3100, dry,
{12786,LEDCNTRL_OLD,0xc0220010, 0xfffe0130}, // dance: 4, a3000, dry,
{12787,LEDCNTRL_OLD,0xc0220134, 0xfffe0130}, // dance: 4, ixus130_sd1400, dry,
{12788,LEDCNTRL_OLD,0xc0220108, 0xfffe0130}, // dance: 4, ixus105_sd1300, dry,
{12790,LEDCNTRL_OLD,0xc0220130, 0xfffe0130}, // dance: 4, sx210is, dry,
{12791,LEDCNTRL_OLD,0xc0220134, 0xfffe0130}, // dance: 4, ixus300_sd4000, dry,
#elif (NEED_ENCODED_DISKBOOT == 5)
{12792,LEDCNTRL_OLD,0xc0220138, 0xfffe0130}, // dance: 5, ixus1000_sd4500, dry,
{12815,LEDCNTRL_OLD,0xc0220138, 0xfffe0130}, // dance: 5, g12, dry,
{12816,LEDCNTRL_OLD,0xc0220134, 0xfffe0130}, // dance: 5, sx30, dry,
{12817,LEDCNTRL_OLD,0xc0220014, 0xfffe0130}, // dance: 5, sx130is, dry,
{12818,LEDCNTRL_OLD,0xc0220130, 0xfffe0130}, // dance: 5, s95, dry,
#elif (NEED_ENCODED_DISKBOOT == 6)
{12835,LEDCNTRL_OLD,0xc02200f0, 0xfffe0040}, // dance: 6, a3300, dry,
{12836,LEDCNTRL_OLD,0xc02200f0, 0xfffe0040}, // dance: 6, a3200, dry,
{12837,LEDCNTRL_OLD,0xc0220110, 0xfff40040}, // dance: 6, ixus310_elph500hs, dry,
{12838,LEDCNTRL_OLD,0xc0220088, 0xfffe0040}, // dance: 6, a800, dry,
{12839,LEDCNTRL_OLD,0xc0220130, 0xfffe0040}, // dance: 6, ixus115_elph100hs, dry,
{12840,LEDCNTRL_OLD,0xc0220130, 0xfff40040}, // dance: 6, sx230hs, dry,
{12841,LEDCNTRL_OLD,0xc0220130, 0xfffe0040}, // dance: 6, ixus220_elph300hs, dry,
{12842,LEDCNTRL_OLD,0xc0220130, 0xfffe0040}, // dance: 6, a2200, dry,
{12843,LEDCNTRL_OLD,0xc0220010, 0xfffe0040}, // dance: 6, a1200, dry,
{12844,LEDCNTRL_OLD,0xc0220130, 0xfff40040}, // dance: 6, sx220hs, dry,
#elif (NEED_ENCODED_DISKBOOT == 7)
{12851,LEDCNTRL_NEW1,0xc022c30c, 0xfff40040}, // dance: 7, g1x, dry,
{12852,LEDCNTRL_OLD,0xc0220014, 0xfffe0040}, // dance: 7, sx150is, dry,
{12854,LEDCNTRL_NEW1,0xc022c30c, 0xfff40040}, // dance: 7, s100, dry,
{12855,LEDCNTRL_OLD,0xc0220130, 0xfff40040}, // dance: 7, ixus230_elph310hs, dry,
{12856,LEDCNTRL_NEW1,0xc022c30c, 0xfff40040}, // dance: 7, sx40hs, dry,
#elif (NEED_ENCODED_DISKBOOT == 8)
{12862,LEDCNTRL_OLD,0xc0220120, 0xfffe0040}, // dance: 8, a1300, dry,
{12863,LEDCNTRL_OLD,0xc0220120, 0xfffe0040}, // dance: 8, a810, dry,
//{12864,LEDCNTRL_UNK,0, 0xfff40040}, // dance: 8, ixus240_elph320hs, dry,
//{12865,LEDCNTRL_UNK,0, 0xfff40040}, // dance: 8, ixus125_elph110hs, dry,
{12866,LEDCNTRL_OLD,0xc0220130, 0xfff40040}, // dance: 8, d20, dry,
{12867,LEDCNTRL_OLD,0xc0220120, 0xfffe0040}, // dance: 8, a4000, dry,
//{12868,LEDCNTRL_UNK,0, 0xfff40040}, // dance: 8, sx260hs, dry,
//{12869,LEDCNTRL_UNK,0, 0xfff40040}, // dance: 8, sx240hs, dry,
{12872,LEDCNTRL_OLD,0xc0220120, 0xfffe0040}, // dance: 8, a3400, dry,
{12873,LEDCNTRL_OLD,0xc0220120, 0xfffe0040}, // dance: 8, a2400, dry,
{12874,LEDCNTRL_OLD,0xc0220120, 0xfffe0040}, // dance: 8, a2300, dry,
{12932,LEDCNTRL_OLD,0xc0220130, 0xfff40040}, // dance: 8, d30, dry,
#elif (NEED_ENCODED_DISKBOOT == 9)
//{12888,LEDCNTRL_NEW1,0xC022C200, 0xfff40040}, // dance: 9, g15, dry,
{12889,LEDCNTRL_NEW1,0xc022c200, 0xfff40040}, // dance: 9, sx50hs, dry,
{12890,LEDCNTRL_OLD,0xc0220120, 0xfffe0040}, // dance: 9, sx160is, dry,
{12891,LEDCNTRL_NEW1,0xc022c30c, 0xfff40040}, // dance: 9, s110, dry,
//{12892,LEDCNTRL_OLD,0xc022302c, 0xfff40040}, // dance: 9, sx500is, dry,
#elif (NEED_ENCODED_DISKBOOT == 10)
{12894,LEDCNTRL_NEW1,0xc022c30c, 0xfff40040}, // dance: 10, N, dry,
{12895,LEDCNTRL_NEW3,0xd20b0994, 0xfff60040}, // sx280hs (using ROM mirror, real address is 0xfdf60040)
{12896,LEDCNTRL_NEW3,0xd20b0994, 0xfff60040}, // sx270hs (using ROM mirror, real address is 0xfdf60040)
{12899,LEDCNTRL_NEW3,0xd20b0994, 0xfff60040}, // sx275hs (using ROM mirror, real address is 0xfdf60040)
{12901,LEDCNTRL_OLD,0xc0220094, 0xfff40040}, // dance: 10, ixus140_elph130, dry,
{12904,LEDCNTRL_NEW2,0xc022c020, 0xfff40040}, // dance: 10, ixus255_elph330, dry,
{12939,LEDCNTRL_NEW1,0xc022c30c, 0xfff40040}, // dance: 10, N FB, dry,
#elif (NEED_ENCODED_DISKBOOT == 11)
{12918,LEDCNTRL_OLD,0xc0220120, 0xfffe0040}, // dance: 11, sx170is, dry,
{12919,LEDCNTRL_OLD,0xc022302c, 0xfff40040}, // dance: 11, sx510hs, dry,
#endif
};

// compatibility definitions from platform/sub
#include "bin_compat.h"

#ifndef DEBUG_DELAY
    #define DEBUG_DELAY 10000000
#endif

void set_led(int led, int state, int method) {
    volatile long *p = (void*)led;

    if (method == LEDCNTRL_NEW1) {
        // DIGIC 5
        *p = (*p & 0xFFFFFFCF) | ((state) ? 0x00 : 0x20);
    }
    else if (method == LEDCNTRL_NEW2) {
        // DIGIC 4+, 5
        *p = ((state) ? 0x93d800 : 0x83dc00);
    }
    else if (method == LEDCNTRL_NEW3) {
        // DIGIC 6
        *p = ((state) ? 0x4d0002 : 0x4c0003);
    }
    else if (method == LEDCNTRL_OLD) {
        *p = ((state) ? 0x46 : 0x44);
    }
}

const int num_pid_sigs = sizeof(pid_sigs)/sizeof(pid_sig_t);
const int num_ver_sigs = sizeof(ver_sigs)/sizeof(ver_sig_t);
const int led_addresses = sizeof(pid_leds)/sizeof(pid_led_t);

unsigned short get_pid(void) {
    int i;
    for(i=0;i<led_addresses;i++) {
        if( (*(unsigned short*)pid_leds[i].addr >= pid_leds[0].pid) &&
            (*(unsigned short*)pid_leds[i].addr <= pid_leds[led_addresses-1].pid) ) {
            // return the first possible number which looks like a valid P-ID
            return *(unsigned short*)pid_leds[i].addr;
        }
    }
    return 0;
}

void blink(unsigned short cam_pid) {
    unsigned int led = 0;
    int method = LEDCNTRL_UNK;
    int i;
    // check if there's a known LED
    for(i=0;i<led_addresses;i++) {
        if(cam_pid == pid_leds[i].pid) {
            led = pid_leds[i].led;
            method = pid_leds[i].method;
            break;
        }
    }
    // no known LED, no blink
    if (!led)
        while(1);
    // LED found, blink (control method chosen according to the type of GPIO)
    while(1) {
        set_led(led, 1, method);
        for(i=0;i<DEBUG_DELAY;i++) {
            asm("nop\n nop\n");
        };
        set_led(led, 0, method);
        for(i=0;i<DEBUG_DELAY;i++) {
            asm("nop\n nop\n");
        };
    }
}

// my_ver assumed to be a null terminated string like 1.00A
int ver_cmp(const char *my_ver, const char *fw_ver) {
    int i=0;
    while(my_ver[i] == fw_ver[i] && my_ver[i] != 0)
        i++;
    return my_ver[i] == 0; // hit the null in our string
}

unsigned short check_pid(void) {
    int i;
    // skip check if pid information not available
    if (num_pid_sigs == 0)
        return 0;
    for(i=0;i<num_pid_sigs;i++) {
        if(*pid_sigs[i].fw_pid == pid_sigs[i].pid) {
            return pid_sigs[i].pid;
        }
    }
    i = get_pid();
    blink(i);
    return 0; // to make the compiler happy
}

void check_compat(void) {
    int i;
    unsigned short cam_pid;
    cam_pid = check_pid();
    for(i=0;i<num_ver_sigs;i++) {
        if(ver_cmp(ver_sigs[i].str,ver_sigs[i].fw_str)) {
            return;
       }
    }
    blink(cam_pid);
}
