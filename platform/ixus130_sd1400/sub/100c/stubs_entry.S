// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R43 (DRYOS version 2.3, release #0043)
//   Firmware Ver GM1.00C
//   Canon IXUS 130

// Values for makefile.inc
//   PLATFORMOSVER = 43
//   PLATFORMID = 12787 (0x31f3) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x03ffffff
//   KEYSYS = d4a                // Found @ 0xffff3568
//   NEED_ENCODED_DISKBOOT = 4   // Found @ 0xffff3578

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NSTUB(GetDrive_FreeClusters                 ,0xff834280) //  3        *** != 0xff86f510
// ALT: NSTUB(GetDrive_FreeClusters, 0xff86f510) // 4 9/0
//NSTUB(kbd_pwr_off                           ,0xff85fb28) //  2 64%    *** != 0xff811800
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0xff811800

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff894840 -> ff891098 -> ff98518c -> ffaa2b24 -> ffbd0b5c
// Mode 33320 in firmware but not in current modemap
// Mode 33322 in firmware but not in current modemap

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00032800) // Found @0xff83459c
DEF(physw_run                               ,0x00001c2c) // Found @0xff834200
DEF(physw_sleep_delay                       ,0x00001c34) // Found @0xff834200
DEF(levent_table                            ,0xffb7a384) // Found @0xffb7a384
DEF(FlashParamsTable                        ,0xffbd0d60) // Found @0xffbd0d60
DEF(movie_status                            ,0x00006430) // Found @0xff95a30c
DEF(full_screen_refresh                     ,0x00008dcc) // Found @0xff9f6c30
DEF(canon_menu_active                       ,0x00002f60) // Found @0xff88ce14
DEF(canon_shoot_menu_active                 ,0x000077c5) // Found @0xff997ec8
DEF(playrec_mode                            ,0x00002c98) // Found @0xff87f244
DEF(zoom_status                             ,0x0000c6c4) // Found @0xffaa6010
DEF(some_flag_for_af_scan                   ,0x000067e8) // Found @0xff95d1cc
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 8 entries in the table - set NUM_FL to 8
DEF(focus_len_table                         ,0xfffe2aa0) // Found @0xfffe2aa0
DEF(zoom_busy                               ,0x00006390) // Found @0xff955f54
DEF(focus_busy                              ,0x00006234) // Found @0xff951814
DEF(recreview_hold                          ,0x000035c0) // Found @0xff89a9ac

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40431000; }             // Found @0xff859828
//void *vid_get_viewport_fb()      { return (void*)0x40547700; }             // Found @0xffb00b88
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x29a0+0x58)); } // Found @0xff870d10 & 0xff870d48
//char *camera_jpeg_count_str()    { return (char*)0x0009eb4c; }             // Found @0xff9eacbc
//long hook_raw_size()             { return 0x014d2400; }                    // Found @0xffb03f54
//int get_flash_params_count(void) { return 0x94; }                          // Found @0xff986248

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffb3eb24, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00080000 // Found @0xffb3eb3c, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_SET             ,0x00000004 }, // Found @0xffb3ea64, levent 0x08
//    { 0, KEY_DISPLAY         ,0x00000008 }, // Found @0xffb3ea70, levent 0x0a
//    { 2, KEY_MENU            ,0x00000001 }, // Found @0xffb3ea88, levent 0x09
//    { 2, KEY_ZOOM_IN         ,0x00000004 }, // Found @0xffb3ea94, levent 0x02
//    { 2, KEY_ZOOM_OUT        ,0x00000008 }, // Found @0xffb3eaa0, levent 0x03
//    { 2, KEY_LEFT            ,0x00000010 }, // Found @0xffb3eaac, levent 0x06
//    { 2, KEY_RIGHT           ,0x00000020 }, // Found @0xffb3eab8, levent 0x07
//    { 2, KEY_DOWN            ,0x00000040 }, // Found @0xffb3eac4, levent 0x05
//    { 2, KEY_UP              ,0x00000080 }, // Found @0xffb3ead0, levent 0x04
//    { 2, KEY_SHOOT_FULL      ,0x00000300 }, // Found @0xffb3eae8, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000200 }, // Found @0xffb3eae8, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000100 }, // Found @0xffb3eadc, levent 0x00
//    { 2, KEY_POWER           ,0x00000400 }, // Found @0xffb3eaf4, levent 0x600
//    { 2, KEY_PLAYBACK        ,0x00000800 }, // Found @0xffb3eb00, levent 0x601
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_RAW_ROWPIX    4416 // Found @0xff92e218
//#define CAM_RAW_ROWS      3296 // Found @0xff92e220
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff83a1f8

// Misc stuff
DEF(ctypes, 0xffb3d5de)

// For capt_seq.c
//static long *nrflag = (long*)(0x67c8-0x08);  // Found @ ff95f1b0 & ff95f1cc

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NSTUB(AllocateMemory                          ,0xffa92b10) //101
NSTUB(AllocateUncacheableMemory               ,0xff83a1b4) //112
NSTUB(Close                                   ,0xff836b78) //101
NSTUB(CreateTask                              ,0xff81e83c) //101
NSTUB(DebugAssert                             ,0xff81eb14) //111
NSTUB(DeleteDirectory_Fut                     ,0xff8365d4) //  1
NSTUB(DeleteFile_Fut                          ,0xff8364f0) //112
NSTUB(DoAFLock                                ,0xff83809c) //102
NSTUB(EnterToCompensationEVF                  ,0xff8381e8) //104
NSTUB(ExecuteEventProcedure                   ,0xff888538) //  1
NSTUB(ExitFromCompensationEVF                 ,0xff83822c) //104
NSTUB(ExitTask                                ,0xff81eacc) //101
NSTUB(ExpCtrlTool_StartContiAE                ,0xff845e30) //104
NSTUB(ExpCtrlTool_StopContiAE                 ,0xff845f08) //104
NSTUB(Fclose_Fut                              ,0xff83666c) //101
NSTUB(Feof_Fut                                ,0xff836858) //  1
NSTUB(Fflush_Fut                              ,0xff836894) //  1
NSTUB(Fgets_Fut                               ,0xff8367c0) //  1
NSTUB(Fopen_Fut                               ,0xff83662c) //101
NSTUB(Fread_Fut                               ,0xff836718) //101
NSTUB(FreeMemory                              ,0xffa92b08) //101
NSTUB(FreeUncacheableMemory                   ,0xff83a1f4) //112
NSTUB(Fseek_Fut                               ,0xff83680c) //101
NSTUB(Fwrite_Fut                              ,0xff83676c) //101
NSTUB(GetBatteryTemperature                   ,0xff862d18) //102
NSTUB(GetCCDTemperature                       ,0xff862ca4) //102
NSTUB(GetCurrentAvValue                       ,0xff953204) //102
NSTUB(GetDrive_ClusterSize                    ,0xff86f4b0) //  4
NSTUB(GetDrive_TotalClusters                  ,0xff86f4e4) //  3
NSTUB(GetFocusLensSubjectDistance             ,0xff952494) //102
NSTUB(GetFocusLensSubjectDistanceFromLens     ,0xff9528dc) //  3
NSTUB(GetImageFolder                          ,0xff935288) //106
NSTUB(GetKbdState                             ,0xff85fb10) //109
NSTUB(GetMemInfo                              ,0xff81a16c) //  3
NSTUB(GetOpticalTemperature                   ,0xff862d8c) //102
NSTUB(GetParameterData                        ,0xff986208) //101
NSTUB(GetPropertyCase                         ,0xff88c244) //102
NSTUB(GetSystemTime                           ,0xffa92b68) //101
NSTUB(GetVRAMHPixelsSize                      ,0xff85079c) //102
NSTUB(GetVRAMVPixelsSize                      ,0xff8507a8) //102
NSTUB(GetZoomLensCurrentPoint                 ,0xff9562cc) //102
NSTUB(GetZoomLensCurrentPosition              ,0xffa861d8) //102
NSTUB(GiveSemaphore                           ,0xff839bd0) //112
NSTUB(IsStrobeChargeCompleted                 ,0xff8d0c10) //102
NSTUB(LEDDrive                                ,0xff85ef6c) //103
NSTUB(LocalTime                               ,0xff885e2c) //  1
NSTUB(LockMainPower                           ,0xff890ca0) //103
NSTUB(Lseek                                   ,0xff836c94) //101
NSTUB(MakeDirectory_Fut                       ,0xff836564) //  1
NSTUB(MoveFocusLensToDistance                 ,0xffafd56c) //102
NSTUB(MoveIrisWithAv                          ,0xffa908c8) //102
NSTUB(MoveZoomLensWithPoint                   ,0xffa90e58) //102
NSTUB(NewTaskShell                            ,0xff88bc50) //103
NSTUB(Open                                    ,0xff836b0c) //101
NSTUB(PB2Rec                                  ,0xff893be0) //104
NSTUB(PT_MoveDigitalZoomToWide                ,0xff877c04) //102
NSTUB(PT_MoveOpticalZoomAt                    ,0xff877bdc) //102
NSTUB(PT_PlaySound                            ,0xff880eb4) //  7
NSTUB(PostLogicalEventForNotPowerType         ,0xff8904d0) //103
NSTUB(PostLogicalEventToUI                    ,0xff89051c) //103
NSTUB(PutInNdFilter                           ,0xffa90cbc) //102
NSTUB(PutOutNdFilter                          ,0xffa90ce0) //102
NSTUB(Read                                    ,0xff81ac7c) //101
NSTUB(ReadFastDir                             ,0xffa751f8) //  4
NSTUB(Rec2PB                                  ,0xff893c20) //104
NSTUB(RefreshPhysicalScreen                   ,0xff9f786c) //104
NSTUB(Remove                                  ,0xff836bac) //  4
NSTUB(RenameFile_Fut                          ,0xff83645c) //  4
NSTUB(Restart                                 ,0xff83b994) //106
NSTUB(ScreenLock                              ,0xff9f8a9c) //  3
NSTUB(ScreenUnlock                            ,0xff9f8ae0) //  7
NSTUB(SetAE_ShutterSpeed                      ,0xffaffcfc) //102
NSTUB(SetAutoShutdownTime                     ,0xff890d14) //103
NSTUB(SetCurrentCaptureModeType               ,0xff897e1c) //101
NSTUB(SetFileAttributes                       ,0xff836e70) //  3
NSTUB(SetFileTimeStamp                        ,0xff836e14) //  4
NSTUB(SetLogicalEventActive                   ,0xff890a18) //101
NSTUB(SetParameterData                        ,0xff986178) //101
NSTUB(SetPropertyCase                         ,0xff88c114) //102
NSTUB(SetScriptMode                           ,0xff890a68) //101
NSTUB(SleepTask                               ,0xff839e38) //101
NSTUB(TakeSemaphore                           ,0xff839b00) //101
NSTUB(TurnOffBackLight                        ,0xff89df30) //104
NSTUB(TurnOnBackLight                         ,0xff89df18) //104
NSTUB(UIFS_WriteFirmInfoToFile                ,0xff9734d0) //101
NSTUB(UnlockAF                                ,0xff838120) //102
NSTUB(UnlockMainPower                         ,0xff890bf4) //103
NSTUB(UnsetZoomForMovie                       ,0xff98c45c) //104
NSTUB(UpdateMBROnFlash                        ,0xff86f330) //105
NSTUB(VbattGet                                ,0xff832f14) //103
NSTUB(Write                                   ,0xff836c08) //101
NSTUB(WriteSDCard                             ,0xff942b50) //108
NSTUB(_log                                    ,0xffb3af28) //111
NSTUB(_log10                                  ,0xffb39e6c) //112
NSTUB(_pow                                    ,0xffb39fdc) //114
NSTUB(_sqrt                                   ,0xffb3c2f4) //  1
NSTUB(add_ptp_handler                         ,0xffa334cc) //  3
NSTUB(apex2us                                 ,0xff9fc310) //  4
NSTUB(close                                   ,0xff81aa94) //  1
NSTUB(closedir                                ,0xffa75054) //  4
NSTUB(err_init_task                           ,0xff815f4c) //  4
NSTUB(exmem_alloc                             ,0xff886d6c) //103
NSTUB(free                                    ,0xff81415c) //112
NSTUB(kbd_p1_f                                ,0xff834614) //109
NSTUB(kbd_p1_f_cont                           ,0xff834620) //109
NSTUB(kbd_p2_f                                ,0xff833ecc) //109
NSTUB(kbd_read_keys                           ,0xff83459c) //109
NSTUB(kbd_read_keys_r2                        ,0xff85f4cc) //109
NSTUB(lseek                                   ,0xff836c94) //101
NSTUB(malloc                                  ,0xff814100) //112
NSTUB(memcmp                                  ,0xff82066c) //101
NSTUB(memcpy                                  ,0xff83f81c) //101
NSTUB(memset                                  ,0xff9fb348) //101
NSTUB(mkdir                                   ,0xff837014) //  4
NSTUB(mktime_ext                              ,0xff8a5ad4) //  1
NSTUB(open                                    ,0xff81a9e4) //  1
NSTUB(opendir                                 ,0xffa750a4) //  4
NSTUB(openfastdir                             ,0xffa750a4) //  4
NSTUB(qsort                                   ,0xffae54e8) //  4
NSTUB(rand                                    ,0xff820774) //  1
NSTUB(read                                    ,0xff81ac7c) //101
NSTUB(reboot_fw_update                        ,0xffa7a63c) //  1
NSTUB(rename                                  ,0xff83645c) //  4
NSTUB(set_control_event                       ,0xff890738) //111
NSTUB(srand                                   ,0xff820768) //  1
NSTUB(stat                                    ,0xff836cdc) //  3
NSTUB(strcat                                  ,0xff8a5290) //  1
NSTUB(strchr                                  ,0xff813fe4) //  1
NSTUB(strcmp                                  ,0xff820628) //101
NSTUB(strcpy                                  ,0xff820610) //101
NSTUB(strftime                                ,0xff8a54dc) //113
NSTUB(strlen                                  ,0xff814030) //101
NSTUB(strncmp                                 ,0xff813f98) //  1
NSTUB(strncpy                                 ,0xff813f5c) //  1
NSTUB(strrchr                                 ,0xff814008) //  1
NSTUB(strtol                                  ,0xff83fafc) //101
NSTUB(strtolx                                 ,0xff83f900) //109
  DEF(task_CaptSeq                            ,0xff87a310) //107
  DEF(task_ExpDrv                             ,0xff8bab28) //110
  DEF(task_InitFileModules                    ,0xff8946cc) //107
  DEF(task_MovieRecord                        ,0xff95a5f4) //107
  DEF(task_PhySw                              ,0xff8341fc) //107
NSTUB(time                                    ,0xff88640c) //  2
NSTUB(vsprintf                                ,0xff8205d4) //  4
NSTUB(write                                   ,0xff836c08) //101
