// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R50 (DRYOS version 2.3, release #0050)
//   Firmware Ver GM1.00A
//   Canon PowerShot SX240 HS

// Values for makefile.inc
//   PLATFORMOSVER = 50
//   PLATFORMID = 12869 (0x3245) // Found @ 0xfff40040
//   MAXRAMADDR = 0x0fffffff
//   KEYSYS = d4c                // Found @ 0xffff3ce0
//   NEED_ENCODED_DISKBOOT = 8   // Found @ 0xffff3cf0

// Note, ROM copied to RAM :- from 0xff6808fc, to 0x00685000, len 16659 words.

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NSTUB(DeleteFile_Fut                        ,0xff02163c) //  1 90%        == 0xff02163c
//NSTUB(LEDDrive                              ,0xff1b980c) //101        *** != 0xff04d06c
// ERROR: MakeDirectory_Fut is not found.                  //--- ---    *** != 0xff02214c
//NSTUB(PT_PlaySound                          ,0xff076e60) //  4 93%        == 0xff076e60
// ERROR: kbd_pwr_off is not found.                        //--- ---    *** != 0x00000000
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000
//NSTUB(reboot_fw_update                      ,0xff335514) //  6 64%    *** != 0xff335510

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff08bd50 -> ff0882ac -> ff1f2f40 -> ff365dac -> ff63fe50
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x000388e4) // Found @0xff01f5ac
DEF(physw_run                               ,0x00001c60) // Found @0xff01f158
DEF(physw_sleep_delay                       ,0x00001c68) // Found @0xff01f158
DEF(levent_table                            ,0xff587530) // Found @0xff587530
DEF(FlashParamsTable                        ,0xff6400cc) // Found @0xff6400cc
DEF(movie_status                            ,0x0000ab7c) // Found @0xff1b6f4c
DEF(full_screen_refresh                     ,0x0000dbe8) // Found @0xff27c44c
DEF(canon_menu_active                       ,0x000034d4) // Found @0xff0813dc
DEF(canon_shoot_menu_active                 ,0x0000c2f9) // Found @0xff2133b8
DEF(playrec_mode                            ,0x00003224) // Found @0xff074ec0
DEF(zoom_status                             ,0x0001150c) // Found @0xff3681dc
DEF(some_flag_for_af_scan                   ,0xff5ab5e4) // Found @0xff285f00
DEF(some_flag_for_af_scan                   ,0xff5ab5e4) // Found @0xff2884a0
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 101 entries in the table - set NUM_FL to 101
DEF(focus_len_table                         ,0xfff4bcf0) // Found @0xfff4bcf0
DEF(zoom_busy                               ,0x0000aa14) // Found @0xff1b0f84
DEF(focus_busy                              ,0x0000a870) // Found @0xff1aa4ec
DEF(recreview_hold                          ,0x00003ff0) // Found @0xff094c20
DEF(palette_control                         ,0x0000dbe8) // Found @0xff27c3c8
DEF(active_palette_buffer                   ,0x0000dbf0) // Found @0xff27c3cc
DEF(palette_buffer                          ,0x000ddb24) // Found @0xff27c894
DEF(bitmap_buffer                           ,0x0000dc24) // Found @0xff2810d4
DEF(active_bitmap_buffer                    ,0x0000dc1c) // Found @0xff2810d8

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x406c5000; }             // Found @0xff047848
//void *vid_get_viewport_fb()      { return (void*)0x4081ab80; }             // Found @0xff3e366c
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2ec0+0x54)); } // Found @0xff062d0c & 0xff062d44
//char *camera_jpeg_count_str()    { return (char*)0x000dd3b4; }             // Found @0xff26fdec
//long hook_raw_size()             { return 0x01247a60; }                    // Found @0xff3e6484
//int get_flash_params_count(void) { return 0xa6; }                          // Found @0xff1f3f8c

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00080000 // Found @0xff441600, levent 0x20a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x10000000 // Found @0xff441638, levent 0x202
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 1, KEY_POWER           ,0x00400000 }, // Found @0xff441548, levent 0x100
//    { 1, KEY_PLAYBACK        ,0x00800000 }, // Found @0xff441550, levent 0x101
//    { 1, KEY_SHOOT_FULL      ,0x03000000 }, // Found @0xff441560, levent 0x01
//    { 1, KEY_SHOOT_FULL_ONLY ,0x02000000 }, // Found @0xff441560, levent 0x01
//    { 1, KEY_SHOOT_HALF      ,0x01000000 }, // Found @0xff441558, levent 0x00
//    { 2, KEY_VIDEO           ,0x00000020 }, // Found @0xff4415b0, levent 0x1a
//    { 2, KEY_MENU            ,0x00000040 }, // Found @0xff4415b8, levent 0x09
//    { 2, KEY_DISPLAY         ,0x00000080 }, // Found @0xff4415c0, levent 0x0a
//    { 2, KEY_UP              ,0x00000100 }, // Found @0xff4415c8, levent 0x04
//    { 2, KEY_DOWN            ,0x00000200 }, // Found @0xff4415d0, levent 0x05
//    { 2, KEY_RIGHT           ,0x00000400 }, // Found @0xff4415d8, levent 0x07
//    { 2, KEY_LEFT            ,0x00000800 }, // Found @0xff4415e0, levent 0x06
//    { 2, KEY_SET             ,0x00001000 }, // Found @0xff4415e8, levent 0x08
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    4176 // Found @0xff17db18
//#define CAM_RAW_ROWS      3060 // Found @0xff17db24
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff025754

// Misc stuff
DEF(ctypes, 0xff440368)

// For capt_seq.c
//static long *nrflag = (long*)(0xdd10+0x00);  // Found @ ff289f38 & ff289f98
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NSTUB(AllocateMemory                          ,0xff35830c) //101
NSTUB(AllocateUncacheableMemory               ,0xff02570c) //112
NSTUB(Close                                   ,0xff021cb0) //101
NSTUB(CreateTask                              ,0x0068ab00) //105
NSTUB(DebugAssert                             ,0x0068afd8) //111
NSTUB(DeleteDirectory_Fut                     ,0xff0216b0) //  1
NSTUB(DoAFLock                                ,0xff02390c) //102
NSTUB(EnterToCompensationEVF                  ,0xff023bb0) //104
NSTUB(ExecuteEventProcedure                   ,0xff07c400) //  2
NSTUB(ExitFromCompensationEVF                 ,0xff023bf4) //104
NSTUB(ExitTask                                ,0x0068ad90) //105
NSTUB(ExpCtrlTool_StartContiAE                ,0xff02ee68) //104
NSTUB(ExpCtrlTool_StopContiAE                 ,0xff02efb8) //104
NSTUB(Fclose_Fut                              ,0xff021748) //101
NSTUB(Feof_Fut                                ,0xff021934) //  1
NSTUB(Fflush_Fut                              ,0xff021970) //  1
NSTUB(Fgets_Fut                               ,0xff02189c) //  6
NSTUB(Fopen_Fut                               ,0xff021708) //101
NSTUB(Fread_Fut                               ,0xff0217f4) //101
NSTUB(FreeMemory                              ,0xff358304) //101
NSTUB(FreeUncacheableMemory                   ,0xff02574c) //112
NSTUB(Fseek_Fut                               ,0xff0218e8) //101
NSTUB(Fwrite_Fut                              ,0xff021848) //101
NSTUB(GetBatteryTemperature                   ,0xff0523ac) //102
NSTUB(GetCCDTemperature                       ,0xff052338) //102
NSTUB(GetCurrentAvValue                       ,0xff1ad358) //102
NSTUB(GetDrive_ClusterSize                    ,0xff06093c) //  6
NSTUB(GetDrive_FreeClusters                   ,0xff060994) //  6
NSTUB(GetDrive_TotalClusters                  ,0xff06096c) //  6
NSTUB(GetFocusLensSubjectDistance             ,0xff1ab2b0) //102
NSTUB(GetFocusLensSubjectDistanceFromLens     ,0xff1ab700) //  3
NSTUB(GetImageFolder                          ,0xff18722c) //  6
NSTUB(GetKbdState                             ,0xff04dce8) //109
NSTUB(GetMemInfo                              ,0xff0052e0) //  3
NSTUB(GetOpticalTemperature                   ,0xff052420) //102
NSTUB(GetParameterData                        ,0xff1f3f4c) //101
NSTUB(GetPropertyCase                         ,0xff080520) //102
NSTUB(GetSystemTime                           ,0xff358364) //101
NSTUB(GetVRAMHPixelsSize                      ,0xff03fe34) //102
NSTUB(GetVRAMVPixelsSize                      ,0xff03fe40) //102
NSTUB(GetZoomLensCurrentPoint                 ,0xff1b13fc) //102
NSTUB(GetZoomLensCurrentPosition              ,0xff345770) //102
NSTUB(GiveSemaphore                           ,0x0068aa60) //112
NSTUB(IsStrobeChargeCompleted                 ,0xff0de27c) //102
NSTUB(LocalTime                               ,0x0068f2f4) //  6
NSTUB(LockMainPower                           ,0xff087fe8) //103
NSTUB(Lseek                                   ,0xff021ecc) //101
NSTUB(MakeSDCardBootable                      ,0xff060bbc) //105
NSTUB(MoveFocusLensToDistance                 ,0xff3df6bc) //102
NSTUB(MoveIrisWithAv                          ,0xff354bc0) //102
NSTUB(MoveZoomLensWithPoint                   ,0xff3553fc) //102
NSTUB(NewTaskShell                            ,0xff07fe4c) //101
NSTUB(Open                                    ,0xff021be8) //101
NSTUB(PB2Rec                                  ,0xff08b370) //104
NSTUB(PT_MoveDigitalZoomToWide                ,0xff06a190) //102
NSTUB(PT_MoveOpticalZoomAt                    ,0xff06a168) //102
NSTUB(PostLogicalEventForNotPowerType         ,0xff08598c) //103
NSTUB(PostLogicalEventToUI                    ,0xff0859d8) //103
NSTUB(PutInNdFilter                           ,0xff3dd204) //102
NSTUB(PutOutNdFilter                          ,0xff3dd23c) //102
NSTUB(Read                                    ,0xff005d9c) //101
NSTUB(ReadFastDir                             ,0xff32ff18) //  6
NSTUB(Rec2PB                                  ,0xff08b3b0) //104
NSTUB(RefreshPhysicalScreen                   ,0xff0a180c) //104
NSTUB(Remove                                  ,0xff021e24) //  6
NSTUB(RenameFile_Fut                          ,0xff0215a8) //  6
NSTUB(Restart                                 ,0xff026f7c) //106
NSTUB(ScreenLock                              ,0xff0a27ec) //  4
NSTUB(ScreenUnlock                            ,0xff0a2850) //  3
NSTUB(SetAE_ShutterSpeed                      ,0xff3e27e4) //102
NSTUB(SetAutoShutdownTime                     ,0xff08805c) //103
NSTUB(SetCurrentCaptureModeType               ,0xff08f718) //101
NSTUB(SetFileAttributes                       ,0xff0220b4) //  6
NSTUB(SetFileTimeStamp                        ,0xff02203c) //  6
NSTUB(SetLogicalEventActive                   ,0xff087d24) //101
NSTUB(SetParameterData                        ,0xff1f3ebc) //101
NSTUB(SetPropertyCase                         ,0xff080380) //102
NSTUB(SetScriptMode                           ,0xff087dc0) //101
NSTUB(SleepTask                               ,0x0068c2e8) //105
NSTUB(TakeSemaphore                           ,0x0068a990) //112
NSTUB(TurnOffBackLight                        ,0xff09953c) //104
NSTUB(TurnOnBackLight                         ,0xff099524) //104
NSTUB(UIFS_WriteFirmInfoToFile                ,0xff1d78ec) //101
NSTUB(UnlockAF                                ,0xff023944) //102
NSTUB(UnlockMainPower                         ,0xff087f3c) //103
NSTUB(VbattGet                                ,0xff01d0f0) //101
NSTUB(Write                                   ,0xff021d04) //101
NSTUB(WriteSDCard                             ,0xff19d9f8) //108
NSTUB(_log                                    ,0x006915c8) //111
NSTUB(_log10                                  ,0x00691b08) //112
NSTUB(_pow                                    ,0x00691c80) //114
NSTUB(_sqrt                                   ,0x00693c8c) //  6
NSTUB(add_ptp_handler                         ,0xff2c815c) //  6
NSTUB(apex2us                                 ,0xff283e20) //  4
NSTUB(close                                   ,0xff005bf8) //  6
NSTUB(closedir                                ,0xff32fd74) //  4
NSTUB(err_init_task                           ,0xff004388) //  4
NSTUB(exmem_alloc                             ,0xff07add4) //101
NSTUB(free                                    ,0xff002f84) //112
NSTUB(kbd_p1_f                                ,0xff01f5fc) //109
NSTUB(kbd_p1_f_cont                           ,0xff01f608) //109
NSTUB(kbd_p2_f                                ,0xff01edf0) //109
NSTUB(kbd_read_keys                           ,0xff01f5ac) //109
NSTUB(kbd_read_keys_r2                        ,0xff04d560) //109
NSTUB(lseek                                   ,0xff021ecc) //101
NSTUB(malloc                                  ,0xff002f2c) //112
NSTUB(memcmp                                  ,0xff00b99c) //101
NSTUB(memcpy                                  ,0xff028900) //101
NSTUB(memset                                  ,0xff281e84) //101
NSTUB(mkdir                                   ,0xff02214c) //  6
NSTUB(mktime_ext                              ,0xff0a2d4c) //  1
NSTUB(open                                    ,0xff005b48) //  6
NSTUB(opendir                                 ,0xff32fdc4) //  6
NSTUB(openfastdir                             ,0xff32fdc4) //  6
NSTUB(qsort                                   ,0xff281e24) //  6
NSTUB(rand                                    ,0xff28195c) //  6
NSTUB(read                                    ,0xff005d9c) //101
NSTUB(rename                                  ,0xff0215a8) //  6
NSTUB(set_control_event                       ,0xff0878c8) //111
NSTUB(srand                                   ,0xff281950) //  6
NSTUB(stat                                    ,0xff021f14) //  3
NSTUB(strcat                                  ,0xff0a33cc) //  1
NSTUB(strchr                                  ,0xff002df8) //  1
NSTUB(strcmp                                  ,0xff00ba98) //101
NSTUB(strcpy                                  ,0xff00b984) //101
NSTUB(strftime                                ,0xff0a2d98) //113
NSTUB(strlen                                  ,0xff002e44) //101
NSTUB(strncmp                                 ,0xff002dac) //  1
NSTUB(strncpy                                 ,0xff002d70) //  1
NSTUB(strrchr                                 ,0xff002e1c) //  1
NSTUB(strtol                                  ,0xff0288ec) //101
NSTUB(strtolx                                 ,0xff0286f0) //109
  DEF(task_CaptSeq                            ,0xff06d6bc) //110
  DEF(task_ExpDrv                             ,0xff0bc1b0) //110
  DEF(task_InitFileModules                    ,0xff08bbc4) //110
  DEF(task_MovieRecord                        ,0xff1b82c0) //110
  DEF(task_PhySw                              ,0xff01f154) //110
  DEF(task_RotaryEncoder                      ,0xff04deb0) //110
NSTUB(time                                    ,0x0068f8d0) //  6
NSTUB(vsprintf                                ,0xff00b834) //  6
NSTUB(write                                   ,0xff021d04) //101
