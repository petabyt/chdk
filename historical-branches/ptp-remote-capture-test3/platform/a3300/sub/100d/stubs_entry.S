// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R47 (DRYOS version 2.3, release #0047)
//   Firmware Ver GM1.00D
//   Canon PowerShot A3300 IS

// Values for makefile.inc
//   PLATFORMOSVER = 47
//   PLATFORMID = 12835 (0x3223) // Found @ 0xfffe0040
//   MAXRAMADDR = 0x03ffffff
//   KEYSYS = d4c                // Found @ 0xffff3504
//   NEED_ENCODED_DISKBOOT = 6   // Found @ 0xffff3514

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NSTUB(kbd_pwr_off                           ,0xff86031c) //  2 60%    *** != 0x00000000
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff8959c4 -> ff892270 -> ff9937f8 -> ffac8368 -> ffbeea50
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00032d34) // Found @0xff8345a0
DEF(physw_run                               ,0x00001c30) // Found @0xff834160
DEF(physw_sleep_delay                       ,0x00001c38) // Found @0xff834160
DEF(levent_table                            ,0xffba1198) // Found @0xffba1198
DEF(FlashParamsTable                        ,0xffbeec88) // Found @0xffbeec88
DEF(movie_status                            ,0x00006734) // Found @0xff96962c
DEF(full_screen_refresh                     ,0x0000916c) // Found @0xffa06cf4
DEF(canon_menu_active                       ,0x00002f60) // Found @0xff88da44
DEF(canon_shoot_menu_active                 ,0x00007bf5) // Found @0xff9ada14
DEF(playrec_mode                            ,0x00002c88) // Found @0xff87fd40
DEF(zoom_status                             ,0x0000cf5c) // Found @0xffacba3c
DEF(some_flag_for_af_scan                   ,0x00006b0c) // Found @0xff96d344
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 12 entries in the table - set NUM_FL to 12
DEF(focus_len_table                         ,0xfffe2f88) // Found @0xfffe2f88
DEF(zoom_busy                               ,0x0000665c) // Found @0xff964eb8
DEF(focus_busy                              ,0x000064d8) // Found @0xff960130
DEF(recreview_hold                          ,0x00003534) // Found @0xff89af5c
DEF(palette_control                         ,0x0000916c) // Found @0xffa06c70
DEF(active_palette_buffer                   ,0x00009174) // Found @0xffa06c74
DEF(palette_buffer                          ,0x000b477c) // Found @0xffa07028
DEF(viewport_buffers                        ,0xffb5cd28) // Found @0xff8519ec
DEF(active_viewport_buffer                  ,0x000020d0) // Found @0xff851760

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x403f1000; }             // Found @0xff85b880
//void *vid_get_viewport_fb()      { return (void*)0x40546b80; }             // Found @0xffb1e2b8
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x29a0+0x58)); } // Found @0xff8713ec & 0xff871424
//char *camera_jpeg_count_str()    { return (char*)0x000b40d4; }             // Found @0xff9fd850
//long hook_raw_size()             { return 0x01794300; }                    // Found @0xffb21774
//int get_flash_params_count(void) { return 0xa0; }                          // Found @0xff994830

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffb5dccc, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x04000000 // Found @0xffb5dcec, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_PLAYBACK        ,0x00002000 }, // Found @0xffb5dc34, levent 0x601
//    { 0, KEY_POWER           ,0x00004000 }, // Found @0xffb5dc3c, levent 0x600
//    { 2, KEY_UP              ,0x00000001 }, // Found @0xffb5dc4c, levent 0x04
//    { 2, KEY_DOWN            ,0x00000002 }, // Found @0xffb5dc54, levent 0x05
//    { 2, KEY_LEFT            ,0x00000004 }, // Found @0xffb5dc5c, levent 0x06
//    { 2, KEY_RIGHT           ,0x00000008 }, // Found @0xffb5dc64, levent 0x07
//    { 2, KEY_SET             ,0x00000010 }, // Found @0xffb5dc6c, levent 0x08
//    { 2, KEY_DISPLAY         ,0x00000020 }, // Found @0xffb5dc74, levent 0x0a
//    { 2, KEY_MENU            ,0x00000080 }, // Found @0xffb5dc84, levent 0x09
//    { 2, KEY_SHOOT_FULL      ,0x00003000 }, // Found @0xffb5dcac, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00002000 }, // Found @0xffb5dcac, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00001000 }, // Found @0xffb5dca4, levent 0x00
//    { 2, KEY_ZOOM_OUT        ,0x00004000 }, // Found @0xffb5dcb4, levent 0x03
//    { 2, KEY_ZOOM_IN         ,0x00008000 }, // Found @0xffb5dcbc, levent 0x02
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    4704 // Found @0xff93a6e0
//#define CAM_RAW_ROWS      3504 // Found @0xff93a6ec
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff83a714

// Misc stuff
DEF(ctypes, 0xffb5c5aa)

// For capt_seq.c
//static long *nrflag = (long*)(0x6b40+0x08);  // Found @ ff971604 & ff971648
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NSTUB(AllocateMemory                          ,0xffab6d38) //101
NSTUB(AllocateUncacheableMemory               ,0xff83a6cc) //112
NSTUB(Close                                   ,0xff836cc4) //101
NSTUB(CreateTask                              ,0xff81e9b0) //101
NSTUB(DebugAssert                             ,0xff81ec88) //111
NSTUB(DeleteDirectory_Fut                     ,0xff8366c0) //116
NSTUB(DeleteFile_Fut                          ,0xff8365dc) //112
NSTUB(DoAFLock                                ,0xff838480) //102
NSTUB(EnterToCompensationEVF                  ,0xff8386dc) //104
NSTUB(ExecuteEventProcedure                   ,0xff889244) //104
NSTUB(ExitFromCompensationEVF                 ,0xff838720) //104
NSTUB(ExitTask                                ,0xff81ec40) //101
NSTUB(ExpCtrlTool_StartContiAE                ,0xff846ce0) //104
NSTUB(ExpCtrlTool_StopContiAE                 ,0xff846db8) //104
NSTUB(Fclose_Fut                              ,0xff836758) //101
NSTUB(Feof_Fut                                ,0xff836944) //  1
NSTUB(Fflush_Fut                              ,0xff836980) //  1
NSTUB(Fgets_Fut                               ,0xff8368ac) //  6
NSTUB(Fopen_Fut                               ,0xff836718) //101
NSTUB(Fread_Fut                               ,0xff836804) //101
NSTUB(FreeMemory                              ,0xffab6d30) //101
NSTUB(FreeUncacheableMemory                   ,0xff83a70c) //112
NSTUB(Fseek_Fut                               ,0xff8368f8) //101
NSTUB(Fwrite_Fut                              ,0xff836858) //101
NSTUB(GetBatteryTemperature                   ,0xff86227c) //102
NSTUB(GetCCDTemperature                       ,0xff862208) //102
NSTUB(GetCurrentAvValue                       ,0xff961d00) //102
NSTUB(GetDrive_ClusterSize                    ,0xff86fd50) //  6
NSTUB(GetDrive_FreeClusters                   ,0xff86fda8) //  6
NSTUB(GetDrive_TotalClusters                  ,0xff86fd80) //  6
NSTUB(GetFocusLensSubjectDistance             ,0xff960db4) //102
NSTUB(GetFocusLensSubjectDistanceFromLens     ,0xff961214) //  3
NSTUB(GetImageFolder                          ,0xff941570) //  6
NSTUB(GetKbdState                             ,0xff860304) //109
NSTUB(GetMemInfo                              ,0xff81a29c) //115
NSTUB(GetOpticalTemperature                   ,0xff8622f0) //102
NSTUB(GetParameterData                        ,0xff9947f0) //101
NSTUB(GetPropertyCase                         ,0xff88cfac) //102
NSTUB(GetSystemTime                           ,0xffab6d90) //101
NSTUB(GetVRAMHPixelsSize                      ,0xff853c54) //102
NSTUB(GetVRAMVPixelsSize                      ,0xff853c60) //102
NSTUB(GetZoomLensCurrentPoint                 ,0xff96523c) //102
NSTUB(GetZoomLensCurrentPosition              ,0xffaa3b04) //102
NSTUB(GiveSemaphore                           ,0xff83a0c4) //112
NSTUB(IsStrobeChargeCompleted                 ,0xff8d8c68) //102
NSTUB(LEDDrive                                ,0xff85f918) //101
NSTUB(LocalTime                               ,0xff886b34) //115
NSTUB(LockMainPower                           ,0xff891e64) //103
NSTUB(Lseek                                   ,0xff836ee0) //101
NSTUB(MakeDirectory_Fut                       ,0xff836650) //116
NSTUB(MakeSDCardBootable                      ,0xff86ffe0) //105
NSTUB(MoveFocusLensToDistance                 ,0xffb1a614) //102
NSTUB(MoveIrisWithAv                          ,0xffab39f8) //102
NSTUB(MoveZoomLensWithPoint                   ,0xffab40b0) //102
NSTUB(NewTaskShell                            ,0xff88c9f4) //101
NSTUB(Open                                    ,0xff836bfc) //101
NSTUB(PB2Rec                                  ,0xff89502c) //104
NSTUB(PT_MoveDigitalZoomToWide                ,0xff878398) //102
NSTUB(PT_MoveOpticalZoomAt                    ,0xff878370) //102
NSTUB(PT_PlaySound                            ,0xff881b78) //  6
NSTUB(PostLogicalEventForNotPowerType         ,0xff891630) //103
NSTUB(PostLogicalEventToUI                    ,0xff89167c) //103
NSTUB(PutInNdFilter                           ,0xffab3ef8) //102
NSTUB(PutOutNdFilter                          ,0xffab3f1c) //102
NSTUB(Read                                    ,0xff81ad58) //101
NSTUB(ReadFastDir                             ,0xffa91334) //  6
NSTUB(Rec2PB                                  ,0xff89506c) //104
NSTUB(RefreshPhysicalScreen                   ,0xff8a59f0) //104
NSTUB(Remove                                  ,0xff836e38) //  6
NSTUB(RenameFile_Fut                          ,0xff836548) //116
NSTUB(Restart                                 ,0xff83bedc) //106
NSTUB(ScreenLock                              ,0xff8a6c28) //  4
NSTUB(ScreenUnlock                            ,0xff8a6c8c) //  3
NSTUB(SetAE_ShutterSpeed                      ,0xffb1d490) //102
NSTUB(SetAutoShutdownTime                     ,0xff891ed8) //103
NSTUB(SetCurrentCaptureModeType               ,0xff898be4) //101
NSTUB(SetFileAttributes                       ,0xff8370c8) //  6
NSTUB(SetFileTimeStamp                        ,0xff837050) //  6
NSTUB(SetLogicalEventActive                   ,0xff891bdc) //101
NSTUB(SetParameterData                        ,0xff994760) //101
NSTUB(SetPropertyCase                         ,0xff88ce90) //102
NSTUB(SetScriptMode                           ,0xff891c2c) //101
NSTUB(SleepTask                               ,0xff83a370) //101
NSTUB(TakeSemaphore                           ,0xff839ff4) //101
NSTUB(TurnOffBackLight                        ,0xff89e35c) //104
NSTUB(TurnOnBackLight                         ,0xff89e344) //104
NSTUB(UIFS_WriteFirmInfoToFile                ,0xff985c74) //101
NSTUB(UnlockAF                                ,0xff8384b8) //102
NSTUB(UnlockMainPower                         ,0xff891db8) //103
NSTUB(UnsetZoomForMovie                       ,0xff99dd04) //104
NSTUB(VbattGet                                ,0xff832e20) //101
NSTUB(Write                                   ,0xff836d18) //101
NSTUB(WriteSDCard                             ,0xff95145c) //108
NSTUB(_log                                    ,0xffb590d0) //111
NSTUB(_log10                                  ,0xffb59610) //112
NSTUB(_pow                                    ,0xffb59788) //114
NSTUB(_sqrt                                   ,0xffb5b3ac) //  6
NSTUB(add_ptp_handler                         ,0xffa4733c) //  6
NSTUB(apex2us                                 ,0xffa0c05c) //  4
NSTUB(close                                   ,0xff81abb4) //  6
NSTUB(closedir                                ,0xffa91190) //  4
NSTUB(err_init_task                           ,0xff815fd4) //111
NSTUB(exmem_alloc                             ,0xff887afc) //101
NSTUB(free                                    ,0xff814244) //112
NSTUB(kbd_p1_f                                ,0xff83461c) //109
NSTUB(kbd_p1_f_cont                           ,0xff834628) //109
NSTUB(kbd_p2_f                                ,0xff833e30) //109
NSTUB(kbd_read_keys                           ,0xff8345a0) //109
NSTUB(kbd_read_keys_r2                        ,0xff85fd5c) //109
NSTUB(lseek                                   ,0xff836ee0) //101
NSTUB(malloc                                  ,0xff8141ec) //112
NSTUB(memcmp                                  ,0xff8208bc) //101
NSTUB(memcpy                                  ,0xff83fd4c) //101
NSTUB(memset                                  ,0xffa0b05c) //101
NSTUB(mkdir                                   ,0xff837160) //109
NSTUB(mktime_ext                              ,0xff8a7a6c) //  1
NSTUB(open                                    ,0xff81ab04) //  6
NSTUB(OpenFastDir                             ,0xffa911e0) //  6
NSTUB(qsort                                   ,0xffafd518) //  6
NSTUB(rand                                    ,0xffa0b19c) //  6
NSTUB(read                                    ,0xff81ad58) //101
NSTUB(reboot_fw_update                        ,0xffa967d0) //106
NSTUB(set_control_event                       ,0xff8918a0) //111
NSTUB(srand                                   ,0xffa0b190) //  6
NSTUB(stat                                    ,0xff836f28) //109
NSTUB(strcat                                  ,0xff8a7224) //  1
NSTUB(strchr                                  ,0xff8140b8) //  1
NSTUB(strcmp                                  ,0xff820878) //101
NSTUB(strcpy                                  ,0xff820860) //101
NSTUB(strftime                                ,0xff8a746c) //113
NSTUB(strlen                                  ,0xff814104) //101
NSTUB(strncmp                                 ,0xff81406c) //  1
NSTUB(strncpy                                 ,0xff814030) //  1
NSTUB(strrchr                                 ,0xff8140dc) //  1
NSTUB(strtol                                  ,0xff84004c) //101
NSTUB(strtolx                                 ,0xff83fe50) //109
  DEF(task_CaptSeq                            ,0xff87ab40) //110
  DEF(task_ExpDrv                             ,0xff8be3ec) //110
  DEF(task_FileWrite                          ,0xffa8f1e4) //110
  DEF(task_InitFileModules                    ,0xff895844) //110
  DEF(task_MovieRecord                        ,0xff96a0f8) //110
  DEF(task_PhySw                              ,0xff83415c) //110
NSTUB(time                                    ,0xff887110) //109
NSTUB(vsprintf                                ,0xff820820) //115
NSTUB(write                                   ,0xff836d18) //101
