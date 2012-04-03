// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R45 (DRYOS version 2.3, release #0045)
//   Firmware Ver GM1.01C
//   Canon PowerShot SX130 IS

// Values for makefile.inc
//   PLATFORMID = 12817 (0x3211) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x03ffffff
//   KEYSYS = d4b                // Found @ 0xffff3618
//   NEED_ENCODED_DISKBOOT = 5   // Found @ 0xffff3628

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NSTUB(DoAFLock                              ,0xff8384d8) //102        *** != 0xff878eec
//NSTUB(GetBatteryTemperature                 ,0xff863050) //102        *** != 0x00000000
//NSTUB(UnlockAF                              ,0xff838510) //102        *** != 0xff878efc
//NSTUB(kbd_pwr_off                           ,0xff85fc24) //  2 60%    *** != 0x00000000
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000
//NSTUB(rename                                ,0xff8365e0) //  4        *** != 0xff836dd8

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff897aac -> ff8943e4 -> ff992a10 -> ffac1640 -> ffbe80ac
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00032b34) // Found @0xff834658
DEF(physw_run                               ,0x00001c3c) // Found @0xff83424c
DEF(levent_table                            ,0xffb97a20) // Found @0xffb97a20
DEF(FlashParamsTable                        ,0xffbe82ac) // Found @0xffbe82ac
DEF(movie_status                            ,0x00006bac) // Found @0xff9698bc
DEF(full_screen_refresh                     ,0x00009458) // Found @0xffa09454
DEF(canon_menu_active                       ,0x00003038) // Found @0xff88e340
DEF(canon_shoot_menu_active                 ,0x00007d89) // Found @0xff9a95b8
DEF(playrec_mode                            ,0x00002d64) // Found @0xff880644
DEF(zoom_status                             ,0x0000ce70) // Found @0xffac4bf0
DEF(some_flag_for_af_scan                   ,0x00006f68) // Found @0xff96cc44
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 128 entries in the table - set NUM_FL to 128
DEF(focus_len_table                         ,0xfffe94ec) // Found @0xfffe94ec
DEF(zoom_busy                               ,0x00006a94) // Found @0xff963b60
DEF(focus_busy                              ,0x00006978) // Found @0xff95fd2c
//DEF(recreview_hold                          ,0x00003a50) // Found @0xff89d940, ** != ** stubs_min = 0x000079d0 (0x78E4+0xEC)
DEF(palette_control                         ,0x00009458) // Found @0xffa093d0
DEF(active_palette_buffer                   ,0x00009460) // Found @0xffa093d4
DEF(palette_buffer                          ,0x000b3a58) // Found @0xffa0978c

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x403f1000; }             // Found @0xff85b5cc
//void *vid_get_viewport_fb()      { return (void*)0x40507700; }             // Found @0xffb0cec8
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2a70+0x58)); } // Found @0xff872098 & 0xff8720d8
//char *camera_jpeg_count_str()    { return (char*)0x000b33a4; }             // Found @0xff9ff42c
//long hook_raw_size()             { return 0x011ca240; }                    // Found @0xffb10350
//int get_flash_params_count(void) { return 0x9a; }                          // Found @0xff993a48

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffb4f4e8, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x04000000 // Found @0xffb4f508, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 2, KEY_ZOOM_IN         ,0x00000010 }, // Found @0xffb4f480, levent 0x02
//    { 2, KEY_ZOOM_OUT        ,0x00000020 }, // Found @0xffb4f488, levent 0x03
//    { 2, KEY_UP              ,0x00000100 }, // Found @0xffb4f4a0, levent 0x04
//    { 2, KEY_DOWN            ,0x00000200 }, // Found @0xffb4f4a8, levent 0x05
//    { 2, KEY_RIGHT           ,0x00000400 }, // Found @0xffb4f4b0, levent 0x07
//    { 2, KEY_LEFT            ,0x00000800 }, // Found @0xffb4f4b8, levent 0x06
//    { 2, KEY_SET             ,0x00001000 }, // Found @0xffb4f4c0, levent 0x08
//    { 2, KEY_MENU            ,0x00002000 }, // Found @0xffb4f4c8, levent 0x09
//    { 2, KEY_DISPLAY         ,0x00004000 }, // Found @0xffb4f4d0, levent 0x0a
//    { 2, KEY_SHOOT_FULL      ,0x0000000c }, // Found @0xffb4f478, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000008 }, // Found @0xffb4f478, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000004 }, // Found @0xffb4f470, levent 0x00
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_RAW_ROWPIX    4080 // Found @0xff93a260
//#define CAM_RAW_ROWS      3048 // Found @0xff93a268
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff83a6a0

// Misc stuff
DEF(ctypes, 0xffb4dd8a)

// For capt_seq.c
//static long *nrflag = (long*)(0x6fa4+0x08);  // Found @ ff97084c & ff970864
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NSTUB(AllocateMemory                          ,0xffab19dc) //101
NSTUB(AllocateUncacheableMemory               ,0xff83a65c) //112
NSTUB(Close                                   ,0xff836cfc) //101
NSTUB(CreateTask                              ,0xff81e8a0) //101
NSTUB(DebugAssert                             ,0xff81eb78) //111
NSTUB(DeleteDirectory_Fut                     ,0xff836758) //  1
NSTUB(DeleteFile_Fut                          ,0xff836674) //112
NSTUB(EnterToCompensationEVF                  ,0xff838628) //104
NSTUB(ExecuteEventProcedure                   ,0xff889a98) //  1
NSTUB(ExitFromCompensationEVF                 ,0xff83866c) //104
NSTUB(ExitTask                                ,0xff81eb30) //101
NSTUB(ExpCtrlTool_StartContiAE                ,0xff846a84) //104
NSTUB(ExpCtrlTool_StopContiAE                 ,0xff846c14) //104
NSTUB(Fclose_Fut                              ,0xff8367f0) //101
NSTUB(Feof_Fut                                ,0xff8369dc) //  1
NSTUB(Fflush_Fut                              ,0xff836a18) //  1
NSTUB(Fgets_Fut                               ,0xff836944) //  1
NSTUB(Fopen_Fut                               ,0xff8367b0) //101
NSTUB(Fread_Fut                               ,0xff83689c) //101
NSTUB(FreeMemory                              ,0xffab19d4) //101
NSTUB(FreeUncacheableMemory                   ,0xff83a69c) //112
NSTUB(Fseek_Fut                               ,0xff836990) //101
NSTUB(Fwrite_Fut                              ,0xff8368f0) //101
NSTUB(GetCCDTemperature                       ,0xff862fdc) //102
NSTUB(GetCurrentAvValue                       ,0xff9625c0) //102
NSTUB(GetDrive_ClusterSize                    ,0xff8709b8) //  4
NSTUB(GetDrive_FreeClusters                   ,0xff870a18) //  4
NSTUB(GetDrive_TotalClusters                  ,0xff8709ec) //  3
NSTUB(GetFocusLensSubjectDistance             ,0xff9609ac) //102
NSTUB(GetFocusLensSubjectDistanceFromLens     ,0xff960df8) //  3
NSTUB(GetImageFolder                          ,0xff9419ac) //106
NSTUB(GetKbdState                             ,0xff85fc0c) //109
NSTUB(GetMemInfo                              ,0xff81a264) //  3
NSTUB(GetOpticalTemperature                   ,0xff8630c8) //102
NSTUB(GetParameterData                        ,0xff993a0c) //101
NSTUB(GetPropertyCase                         ,0xff88d7a0) //102
NSTUB(GetSystemTime                           ,0xffab1a34) //101
NSTUB(GetZoomLensCurrentPoint                 ,0xff963fc8) //102
NSTUB(GetZoomLensCurrentPosition              ,0xffa9fe7c) //102
NSTUB(GiveSemaphore                           ,0xff83a078) //112
NSTUB(IsStrobeChargeCompleted                 ,0xff8d7004) //102
NSTUB(LEDDrive                                ,0xff85f0f4) //103
NSTUB(LocalTime                               ,0xff8873e8) //  1
NSTUB(LockMainPower                           ,0xff893fec) //103
NSTUB(Lseek                                   ,0xff836e18) //101
NSTUB(MakeDirectory_Fut                       ,0xff8366e8) //  1
NSTUB(MoveFocusLensToDistance                 ,0xffb0994c) //102
NSTUB(MoveIrisWithAv                          ,0xffaae374) //102
NSTUB(MoveZoomLensWithPoint                   ,0xffaaea3c) //102
NSTUB(NewTaskShell                            ,0xff88d1bc) //103
NSTUB(Open                                    ,0xff836c90) //101
NSTUB(PB2Rec                                  ,0xff896f88) //104
NSTUB(PT_MoveDigitalZoomToWide                ,0xff878e9c) //102
NSTUB(PT_MoveOpticalZoomAt                    ,0xff878e74) //102
NSTUB(PT_PlaySound                            ,0xff8824e4) //  4
NSTUB(PostLogicalEventForNotPowerType         ,0xff891d90) //103
NSTUB(PostLogicalEventToUI                    ,0xff891ddc) //103
NSTUB(PutInNdFilter                           ,0xffb07608) //102
NSTUB(PutOutNdFilter                          ,0xffb07640) //102
NSTUB(Read                                    ,0xff81ad74) //101
NSTUB(ReadFastDir                             ,0xffa8c488) //  4
NSTUB(Rec2PB                                  ,0xff896fc8) //104
NSTUB(RefreshPhysicalScreen                   ,0xff8a788c) //104
NSTUB(Remove                                  ,0xff836d30) //  4
NSTUB(RenameFile_Fut                          ,0xff8365e0) //  4
NSTUB(Restart                                 ,0xff83be44) //106
NSTUB(ScreenLock                              ,0xff8a8a1c) //  4
NSTUB(ScreenUnlock                            ,0xff8a8a80) //  9
NSTUB(SetAE_ShutterSpeed                      ,0xffb0c094) //102
NSTUB(SetAutoShutdownTime                     ,0xff894060) //103
NSTUB(SetCurrentCaptureModeType               ,0xff89abfc) //101
NSTUB(SetFileAttributes                       ,0xff836ff4) //  3
NSTUB(SetFileTimeStamp                        ,0xff836f98) //  4
NSTUB(SetLogicalEventActive                   ,0xff893d38) //101
NSTUB(SetParameterData                        ,0xff993978) //101
NSTUB(SetPropertyCase                         ,0xff88d678) //102
NSTUB(SetScriptMode                           ,0xff893d88) //101
NSTUB(SleepTask                               ,0xff83a2e0) //101
NSTUB(TakeSemaphore                           ,0xff839fa8) //101
NSTUB(TurnOffBackLight                        ,0xff8a0584) //104
NSTUB(TurnOnBackLight                         ,0xff8a056c) //104
NSTUB(UIFS_WriteFirmInfoToFile                ,0xff98420c) //101
NSTUB(UnlockMainPower                         ,0xff893f40) //103
NSTUB(UpdateMBROnFlash                        ,0xff870838) //105
NSTUB(VbattGet                                ,0xff832fb4) //103
NSTUB(Write                                   ,0xff836d8c) //101
NSTUB(WriteSDCard                             ,0xff950268) //108
NSTUB(_log                                    ,0xffb4b6d4) //111
NSTUB(_log10                                  ,0xffb4a618) //112
NSTUB(_pow                                    ,0xffb4a788) //114
NSTUB(_sqrt                                   ,0xffb4caa0) //  1
NSTUB(add_ptp_handler                         ,0xffa4c81c) //  3
NSTUB(apex2us                                 ,0xffa0e804) //  4
NSTUB(close                                   ,0xff81ab8c) //  1
NSTUB(closedir                                ,0xffa8c2e4) //  4
NSTUB(err_init_task                           ,0xff815fd4) //  4
NSTUB(exmem_alloc                             ,0xff888334) //103
NSTUB(free                                    ,0xff814244) //112
NSTUB(kbd_p1_f                                ,0xff8346d0) //109
NSTUB(kbd_p1_f_cont                           ,0xff8346dc) //109
NSTUB(kbd_p2_f                                ,0xff833f18) //109
NSTUB(kbd_read_keys                           ,0xff834658) //109
NSTUB(kbd_read_keys_r2                        ,0xff85f5c4) //109
NSTUB(lseek                                   ,0xff836e18) //101
NSTUB(malloc                                  ,0xff8141e8) //112
NSTUB(memcmp                                  ,0xff8206d0) //101
NSTUB(memcpy                                  ,0xff83fd04) //101
NSTUB(memset                                  ,0xffa0d800) //101
NSTUB(mkdir                                   ,0xff837198) //  4
NSTUB(mktime_ext                              ,0xff8a9824) //  1
NSTUB(open                                    ,0xff81aadc) //  1
NSTUB(opendir                                 ,0xffa8c334) //  4
NSTUB(openfastdir                             ,0xffa8c334) //  4
NSTUB(qsort                                   ,0xffaf8800) //  4
NSTUB(rand                                    ,0xffa0d940) //  4
NSTUB(read                                    ,0xff81ad74) //101
NSTUB(reboot_fw_update                        ,0xffa918a8) //  4
NSTUB(set_control_event                       ,0xff893928) //111
NSTUB(srand                                   ,0xffa0d934) //  4
NSTUB(stat                                    ,0xff836e60) //  3
NSTUB(strcat                                  ,0xff8a8fe0) //  1
NSTUB(strchr                                  ,0xff8140b4) //  1
NSTUB(strcmp                                  ,0xff82068c) //101
NSTUB(strcpy                                  ,0xff820674) //101
NSTUB(strftime                                ,0xff8a922c) //113
NSTUB(strlen                                  ,0xff814100) //101
NSTUB(strncmp                                 ,0xff814068) //  1
NSTUB(strncpy                                 ,0xff81402c) //  1
NSTUB(strrchr                                 ,0xff8140d8) //  1
NSTUB(strtol                                  ,0xff83ffe4) //101
NSTUB(strtolx                                 ,0xff83fde8) //109
  DEF(task_CaptSeq                            ,0xff87b564) //107
  DEF(task_ExpDrv                             ,0xff8bfa94) //110
  DEF(task_InitFileModules                    ,0xff897938) //107
  DEF(task_MovieRecord                        ,0xff969bc8) //107
  DEF(task_PhySw                              ,0xff834248) //107
  DEF(task_RotaryEncoder                      ,0xff85fd80) //107
NSTUB(time                                    ,0xff8879c8) //  2
NSTUB(vsprintf                                ,0xff820638) //  4
NSTUB(write                                   ,0xff836d8c) //101
