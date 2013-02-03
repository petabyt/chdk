// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R31 (DRYOS version 2.3, release #0031)
//   Firmware Ver GM1.01D
//   Canon IXY DIGITAL 510 IS

// Values for makefile.inc
//   PLATFORMOSVER = 31
//   PLATFORMID = 12733 (0x31bd) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x03ffffff
//   KEYSYS = d4                 // Found @ 0xffff3564
//   NEED_ENCODED_DISKBOOT = 2   // Found @ 0xffff3574

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NSTUB(kbd_pwr_off                           ,0xff844148) //  2 64%    *** != 0x00000000
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff87ac34 -> ff877368 -> ff94b0ec -> ffa6ab38 -> ffb5a350
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x0000ec78) // Found @0xff821dfc
DEF(physw_run                               ,0x00001c34) // Found @0xff821a64
DEF(physw_sleep_delay                       ,0x00001c32) // Found @0xff821a64
DEF(levent_table                            ,0xffb27e60) // Found @0xffb27e60
DEF(FlashParamsTable                        ,0xffb5a52c) // Found @0xffb5a52c
DEF(movie_status                            ,0x00005ef8) // Found @0xff921468
DEF(canon_menu_active                       ,0x00002d10) // Found @0xff870138
DEF(canon_shoot_menu_active                 ,0x000070c1) // Found @0xff95c900
DEF(playrec_mode                            ,0x00002a78) // Found @0xff8634f0
DEF(zoom_status                             ,0x0000b488) // Found @0xffa6cf28
DEF(some_flag_for_af_scan                   ,0x00006430) // Found @0xff92474c
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 10 entries in the table - set NUM_FL to 10
//DEF(focus_len_table                         ,0xfffe2a8c) // Found @0xfffe2a8c,          stubs_min = 0xfffe2a8c (0xfffe2a8c)
DEF(zoom_busy                               ,0x00005e28) // Found @0xff91d798
DEF(focus_busy                              ,0x00005d20) // Found @0xff918608
DEF(recreview_hold                          ,0x00003640) // Found @0xff881428

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x403f1000; }             // Found @0xff83dc44
//void *vid_get_viewport_fb()      { return (void*)0x415f3570; }             // Found @0xffabe714
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2764+0x58)); } // Found @0xff854ed8 & 0xff854f10
//char *camera_jpeg_count_str()    { return (char*)0x00035278; }             // Found @0xff9a6c84
//long hook_raw_size()             { return 0x011ca240; }                    // Found @0xffac0ca0
//int get_flash_params_count(void) { return 0x7a; }                          // Found @0xff94c1a8

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffaeeb8c, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00080000 // Found @0xffaeeba4, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 1, KEY_POWER           ,0x00000001 }, // Found @0xffaeea90, levent 0x600
//    { 1, KEY_SHOOT_FULL      ,0x00009000 }, // Found @0xffaeeacc, levent 0x01
//    { 1, KEY_SHOOT_FULL_ONLY ,0x00008000 }, // Found @0xffaeeacc, levent 0x01
//    { 1, KEY_SHOOT_HALF      ,0x00001000 }, // Found @0xffaeeaa8, levent 0x00
//    { 1, KEY_ZOOM_OUT        ,0x00002000 }, // Found @0xffaeeab4, levent 0x03
//    { 1, KEY_ZOOM_IN         ,0x00004000 }, // Found @0xffaeeac0, levent 0x02
//    { 2, KEY_LEFT            ,0x00000020 }, // Found @0xffaeeb14, levent 0x06
//    { 2, KEY_RIGHT           ,0x00000040 }, // Found @0xffaeeb20, levent 0x07
//    { 2, KEY_DOWN            ,0x00000080 }, // Found @0xffaeeb2c, levent 0x05
//    { 2, KEY_UP              ,0x00000200 }, // Found @0xffaeeb44, levent 0x04
//    { 2, KEY_SET             ,0x00000400 }, // Found @0xffaeeb50, levent 0x08
//    { 2, KEY_MENU            ,0x00000800 }, // Found @0xffaeeb5c, levent 0x09
//    { 2, KEY_PLAYBACK        ,0x00004000 }, // Found @0xffaeeb68, levent 0x601
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_RAW_ROWPIX    4080 // Found @0xff8eb014
//#define CAM_RAW_ROWS      3048 // Found @0xff8eb018
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff827520

// Misc stuff
DEF(ctypes, 0xffaed8de)

// For capt_seq.c
//static long *nrflag = (long*)(0x6418-0x08);  // Found @ ff9266dc & ff9266f8

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NSTUB(AllocateMemory                          ,0xffa5f01c) //101
NSTUB(AllocateUncacheableMemory               ,0xff8274dc) //112
NSTUB(Close                                   ,0xff823cc8) //101
NSTUB(CreateTask                              ,0xff81afac) //101
NSTUB(DebugAssert                             ,0xff81b284) //111
NSTUB(DeleteDirectory_Fut                     ,0xff823658) //116
NSTUB(DeleteFile_Fut                          ,0xff823574) //112
NSTUB(DoAFLock                                ,0xff825380) //102
NSTUB(EnterToCompensationEVF                  ,0xff82546c) //104
NSTUB(ExecuteEventProcedure                   ,0xff86b884) //104
NSTUB(ExitFromCompensationEVF                 ,0xff8254b0) //104
NSTUB(ExitTask                                ,0xff81b23c) //101
NSTUB(ExpCtrlTool_StartContiAE                ,0xff830020) //104
NSTUB(ExpCtrlTool_StopContiAE                 ,0xff830164) //104
NSTUB(Fclose_Fut                              ,0xff8236f0) //101
NSTUB(Feof_Fut                                ,0xff8238dc) //  1
NSTUB(Fflush_Fut                              ,0xff823918) //  1
NSTUB(Fgets_Fut                               ,0xff823844) //  1
NSTUB(Fopen_Fut                               ,0xff8236b0) //101
NSTUB(Fread_Fut                               ,0xff82379c) //101
NSTUB(FreeMemory                              ,0xffa5f014) //101
NSTUB(FreeUncacheableMemory                   ,0xff82751c) //112
NSTUB(Fseek_Fut                               ,0xff823890) //101
NSTUB(Fwrite_Fut                              ,0xff8237f0) //101
NSTUB(GetBatteryTemperature                   ,0xff847118) //102
NSTUB(GetCCDTemperature                       ,0xff8470a4) //102
NSTUB(GetCurrentAvValue                       ,0xff91a3c0) //102
NSTUB(GetDrive_ClusterSize                    ,0xff85360c) //  5
NSTUB(GetDrive_FreeClusters                   ,0xff853664) //  5
NSTUB(GetDrive_TotalClusters                  ,0xff853638) //  5
NSTUB(GetFocusLensSubjectDistance             ,0xff919470) //102
NSTUB(GetFocusLensSubjectDistanceFromLens     ,0xff91984c) //  3
NSTUB(GetKbdState                             ,0xff844130) //109
NSTUB(GetMemInfo                              ,0xff813be4) //115
NSTUB(GetOpticalTemperature                   ,0xff84718c) //102
NSTUB(GetParameterData                        ,0xff94c168) //101
NSTUB(GetPropertyCase                         ,0xff86f5f0) //102
NSTUB(GetSystemTime                           ,0xffa5f074) //101
NSTUB(GetVRAMHPixelsSize                      ,0xff8b58dc) //102
NSTUB(GetVRAMVPixelsSize                      ,0xff8b58e8) //102
NSTUB(GetZoomLensCurrentPoint                 ,0xff91db10) //102
NSTUB(GetZoomLensCurrentPosition              ,0xffa50a54) //102
NSTUB(GiveSemaphore                           ,0xff826ef8) //112
NSTUB(IsStrobeChargeCompleted                 ,0xff8a71a0) //102
NSTUB(LEDDrive                                ,0xff843600) //103
NSTUB(LocalTime                               ,0xff869274) //115
NSTUB(LockMainPower                           ,0xff876f80) //103
NSTUB(Lseek                                   ,0xff823e08) //101
NSTUB(MakeDirectory_Fut                       ,0xff8235e8) //116
NSTUB(MoveFocusLensToDistance                 ,0xffabb0ac) //102
NSTUB(MoveIrisWithAv                          ,0xffa5d178) //102
NSTUB(MoveZoomLensWithPoint                   ,0xffa5d700) //102
NSTUB(NewTaskShell                            ,0xff86f094) //103
NSTUB(Open                                    ,0xff823ca0) //101
NSTUB(PB2Rec                                  ,0xff879ff8) //104
NSTUB(PT_MoveDigitalZoomToWide                ,0xff85c4c8) //102
NSTUB(PT_MoveOpticalZoomAt                    ,0xff85c4a0) //102
NSTUB(PT_PlaySound                            ,0xff85c0a4) //102
NSTUB(PostLogicalEventForNotPowerType         ,0xff874ce0) //103
NSTUB(PostLogicalEventToUI                    ,0xff874d2c) //103
NSTUB(PutInNdFilter                           ,0xffa5d564) //102
NSTUB(PutOutNdFilter                          ,0xffa5d588) //102
NSTUB(Read                                    ,0xff819ae4) //101
NSTUB(ReadFastDir                             ,0xffa3d294) //  1
NSTUB(Rec2PB                                  ,0xff8789fc) //104
NSTUB(RefreshPhysicalScreen                   ,0xff9b77c8) //104
NSTUB(Remove                                  ,0xff823d10) //  1
NSTUB(RenameFile_Fut                          ,0xff823520) //  1
NSTUB(Restart                                 ,0xff828c2c) //106
NSTUB(SetAE_ShutterSpeed                      ,0xffabd88c) //102
NSTUB(SetAutoShutdownTime                     ,0xff876ff4) //103
NSTUB(SetCurrentCaptureModeType               ,0xff87ea48) //101
NSTUB(SetFileAttributes                       ,0xff823ff4) //  1
NSTUB(SetFileTimeStamp                        ,0xff823fa4) //  1
NSTUB(SetLogicalEventActive                   ,0xff876cd0) //101
NSTUB(SetParameterData                        ,0xff94c0d8) //101
NSTUB(SetPropertyCase                         ,0xff86f4e8) //102
NSTUB(SetScriptMode                           ,0xff876d20) //101
NSTUB(SleepTask                               ,0xff827160) //101
NSTUB(TakeSemaphore                           ,0xff826e28) //101
NSTUB(TurnOffBackLight                        ,0xff88492c) //104
NSTUB(TurnOnBackLight                         ,0xff884914) //104
NSTUB(UIFS_WriteFirmInfoToFile                ,0xff938fa8) //101
NSTUB(UnlockAF                                ,0xff8253b8) //102
NSTUB(UnlockMainPower                         ,0xff876ed4) //103
NSTUB(UnsetZoomForMovie                       ,0xff9529b0) //104
NSTUB(UpdateMBROnFlash                        ,0xff853464) //105
NSTUB(VbattGet                                ,0xff820644) //103
NSTUB(Write                                   ,0xff823d74) //101
NSTUB(WriteSDCard                             ,0xff90ab78) //108
NSTUB(_log                                    ,0xffaeab74) //111
NSTUB(_log10                                  ,0xffae9800) //112
NSTUB(_pow                                    ,0xffae9970) //114
NSTUB(_sqrt                                   ,0xffaec718) //  1
NSTUB(add_ptp_handler                         ,0xffa05144) //  3
NSTUB(apex2us                                 ,0xff9ba9d0) //  4
NSTUB(close                                   ,0xff8198fc) //  1
NSTUB(closedir                                ,0xffa3d364) //  1
NSTUB(err_init_task                           ,0xff814e2c) //111
NSTUB(exmem_alloc                             ,0xff86a134) //103
NSTUB(free                                    ,0xff813a3c) //112
NSTUB(kbd_p1_f                                ,0xff821e78) //109
NSTUB(kbd_p1_f_cont                           ,0xff821e84) //109
NSTUB(kbd_p2_f                                ,0xff821730) //109
NSTUB(kbd_read_keys                           ,0xff821dfc) //109
NSTUB(kbd_read_keys_r2                        ,0xff843ad4) //109
NSTUB(lseek                                   ,0xff823e08) //101
NSTUB(malloc                                  ,0xff813968) //112
NSTUB(memcmp                                  ,0xff81cc5c) //101
NSTUB(memcpy                                  ,0xff88b508) //101
NSTUB(memset                                  ,0xff9b9cb8) //101
NSTUB(mkdir                                   ,0xff82406c) //109
NSTUB(mktime_ext                              ,0xff88bd74) //  1
NSTUB(open                                    ,0xff81984c) //  1
NSTUB(OpenFastDir                             ,0xffa3d200) //  1
NSTUB(qsort                                   ,0xffa9ffc0) //  1
NSTUB(rand                                    ,0xff81cd64) //  1
NSTUB(read                                    ,0xff819ae4) //101
NSTUB(reboot_fw_update                        ,0xffa44944) //106
NSTUB(set_control_event                       ,0xff876934) //111
NSTUB(srand                                   ,0xff81cd58) //  1
NSTUB(stat                                    ,0xff823ed4) //  1
NSTUB(strcat                                  ,0xff88b31c) //  1
NSTUB(strchr                                  ,0xff88b3a4) //  1
NSTUB(strcmp                                  ,0xff81cbf4) //101
NSTUB(strcpy                                  ,0xff81cbdc) //101
NSTUB(strftime                                ,0xff88b77c) //  1
NSTUB(strlen                                  ,0xff81cc38) //101
NSTUB(strncmp                                 ,0xff88b358) //  1
NSTUB(strncpy                                 ,0xff82ce1c) //  1
NSTUB(strrchr                                 ,0xff9b9c90) //  1
NSTUB(strtol                                  ,0xff82d054) //101
NSTUB(strtolx                                 ,0xff82ce58) //109
  DEF(task_CaptSeq                            ,0xff85eae4) //107
  DEF(task_ExpDrv                             ,0xff89d8cc) //110
  DEF(task_InitFileModules                    ,0xff87aac0) //107
  DEF(task_MovieRecord                        ,0xff921750) //107
  DEF(task_PhySw                              ,0xff821a60) //107
NSTUB(time                                    ,0xff8697ec) //109
NSTUB(vsprintf                                ,0xff81cba0) //115
NSTUB(write                                   ,0xff823d74) //101
