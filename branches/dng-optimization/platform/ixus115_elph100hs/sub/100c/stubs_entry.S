// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R47 (DRYOS version 2.3, release #0047)
//   Firmware Ver GM1.00C
//   Canon PowerShot ELPH 100 HS

// Values for makefile.inc
//   PLATFORMOSVER = 47
//   PLATFORMID = 12839 (0x3227) // Found @ 0xfffe0040
//   MAXRAMADDR = 0x07ffffff
//   KEYSYS = d4c                // Found @ 0xffff3630
//   NEED_ENCODED_DISKBOOT = 6   // Found @ 0xffff3640

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
NHSTUB(kbd_pwr_off                            ,0xff86470c) //  2 60%
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0xff907390

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff89d1ac -> ff899b4c -> ff9ad4b8 -> ffafc5ec -> ffc436a0
// Mode 33320 in firmware but not in current modemap
// Mode 33322 in firmware but not in current modemap

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00033f48) // Found @0xff834968
DEF(physw_run                               ,0x00001c44) // Found @0xff834508
DEF(physw_sleep_delay                       ,0x00001c4c) // Found @0xff834508
DEF(levent_table                            ,0xffbe12c4) // Found @0xffbe12c4
DEF(FlashParamsTable                        ,0xffc438dc) // Found @0xffc438dc
DEF(movie_status                            ,0x00006d54) // Found @0xff980d7c
DEF(full_screen_refresh                     ,0x00009ca4) // Found @0xffa2efa0
DEF(canon_menu_active                       ,0x000031b4) // Found @0xff8952c0
DEF(canon_shoot_menu_active                 ,0x0000836d) // Found @0xff9c4c44
DEF(playrec_mode                            ,0x00002ee0) // Found @0xff8871b4
DEF(zoom_status                             ,0x0000dd08) // Found @0xffaffccc
DEF(some_flag_for_af_scan                   ,0x00007158) // Found @0xff9853a0
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 10 entries in the table - set NUM_FL to 10
DEF(focus_len_table                         ,0xfffe9ca8) // Found @0xfffe9ca8
DEF(zoom_busy                               ,0x00006c7c) // Found @0xff97c144
DEF(focus_busy                              ,0x00006afc) // Found @0xff97759c
DEF(recreview_hold                          ,0x00003874) // Found @0xff8a4ecc
DEF(palette_control                         ,0x00009ca4) // Found @0xffa2ef1c
DEF(active_palette_buffer                   ,0x00009cac) // Found @0xffa2ef20
DEF(palette_buffer                          ,0x000bba50) // Found @0xffa2f3f8
DEF(bitmap_buffer                           ,0x00009ce4) // Found @0xffa32e44
DEF(active_bitmap_buffer                    ,0x00009cdc) // Found @0xffa32e48
DEF(viewport_buffers                        ,0xffb9866c) // Found @0xff8535c0
DEF(active_viewport_buffer                  ,0x0000216c) // Found @0xff853294

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40471000; }             // Found @0xff85f59c
//void *vid_get_viewport_fb()      { return (void*)0x405c6b80; }             // Found @0xffb56344
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2ba0+0x58)); } // Found @0xff877260 & 0xff877298
//char *camera_jpeg_count_str()    { return (char*)0x000bb3a8; }             // Found @0xffa2629c
//long hook_raw_size()             { return 0x0123eaf0; }                    // Found @0xffb5983c
//int get_flash_params_count(void) { return 0xa0; }                          // Found @0xff9ae4f0

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffb996f0, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x04000000 // Found @0xffb99710, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_PLAYBACK        ,0x00000001 }, // Found @0xffb99660, levent 0x601
//    { 0, KEY_POWER           ,0x00000002 }, // Found @0xffb99668, levent 0x600
//    { 1, KEY_MENU            ,0x01000000 }, // Found @0xffb99680, levent 0x09
//    { 1, KEY_SET             ,0x04000000 }, // Found @0xffb99688, levent 0x08
//    { 1, KEY_ZOOM_OUT        ,0x10000000 }, // Found @0xffb99690, levent 0x03
//    { 1, KEY_ZOOM_IN         ,0x20000000 }, // Found @0xffb99698, levent 0x02
//    { 1, KEY_VIDEO           ,0x80000000 }, // Found @0xffb996a8, levent 0x12
//    { 2, KEY_UP              ,0x00000001 }, // Found @0xffb996b0, levent 0x04
//    { 2, KEY_DOWN            ,0x00000002 }, // Found @0xffb996b8, levent 0x05
//    { 2, KEY_LEFT            ,0x00000004 }, // Found @0xffb996c0, levent 0x06
//    { 2, KEY_RIGHT           ,0x00000008 }, // Found @0xffb996c8, levent 0x07
//    { 2, KEY_SHOOT_FULL      ,0x00000030 }, // Found @0xffb996d8, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000020 }, // Found @0xffb996d8, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000010 }, // Found @0xffb996d0, levent 0x00
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    4168 // Found @0xff94ff68
//#define CAM_RAW_ROWS      3060 // Found @0xff94ff74
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff83bba4

// Misc stuff
DEF(ctypes, 0xffb97de2)

// For capt_seq.c
//static long *nrflag = (long*)(0x718c+0x08);  // Found @ ff989d4c & ff989d88
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
//NHSTUB(CreateJumptable                      ,0xffb59a08) //  1
//NHSTUB(_uartr_req                           ,0xff81fe08) //111
//NHSTUB(AllocateMemory                       ,0xffaea8e0) //101
NHSTUB(AllocateUncacheableMemory              ,0xff83bb5c) //112
NHSTUB(Close                                  ,0xff837ebc) //101
NHSTUB(CreateTask                             ,0xff81e9b0) //101
NHSTUB(DebugAssert                            ,0xff81ec88) //111
NHSTUB(DeleteDirectory_Fut                    ,0xff8378b8) //116
NHSTUB(DeleteFile_Fut                         ,0xff8377d4) //112
NHSTUB(DoAFLock                               ,0xff8396dc) //102
NHSTUB(EnterToCompensationEVF                 ,0xff839938) //104
NHSTUB(ExecuteEventProcedure                  ,0xff890b4c) //104
NHSTUB(ExitFromCompensationEVF                ,0xff83997c) //104
NHSTUB(ExitTask                               ,0xff81ec40) //101
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff8481e8) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff8482c0) //104
NHSTUB(Fclose_Fut                             ,0xff837950) //101
NHSTUB(Feof_Fut                               ,0xff837b3c) //  1
NHSTUB(Fflush_Fut                             ,0xff837b78) //  1
NHSTUB(Fgets_Fut                              ,0xff837aa4) //  6
NHSTUB(Fopen_Fut                              ,0xff837910) //101
NHSTUB(Fread_Fut                              ,0xff8379fc) //101
//NHSTUB(FreeMemory                           ,0xffaea8d8) //101
NHSTUB(FreeUncacheableMemory                  ,0xff83bb9c) //112
NHSTUB(Fseek_Fut                              ,0xff837af0) //101
NHSTUB(Fwrite_Fut                             ,0xff837a50) //101
NHSTUB(GetBatteryTemperature                  ,0xff8677dc) //102
NHSTUB(GetCCDTemperature                      ,0xff867768) //102
NHSTUB(GetCurrentAvValue                      ,0xff97902c) //102
NHSTUB(GetDrive_ClusterSize                   ,0xff874d54) //  6
NHSTUB(GetDrive_FreeClusters                  ,0xff874dac) //  6
NHSTUB(GetDrive_TotalClusters                 ,0xff874d84) //  6
NHSTUB(GetFocusLensSubjectDistance            ,0xff978220) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff978680) //  3
NHSTUB(GetImageFolder                         ,0xff956f00) //  6
NHSTUB(GetKbdState                            ,0xff8646f4) //109
NHSTUB(GetMemInfo                             ,0xff81a29c) //115
NHSTUB(GetOpticalTemperature                  ,0xff867850) //102
NHSTUB(GetParameterData                       ,0xff9ae4b0) //101
NHSTUB(GetPropertyCase                        ,0xff894810) //102
NHSTUB(GetSystemTime                          ,0xffaea938) //101
NHSTUB(GetVRAMHPixelsSize                     ,0xff855b74) //102
NHSTUB(GetVRAMVPixelsSize                     ,0xff855b80) //102
NHSTUB(GetZoomLensCurrentPoint                ,0xff97c4c8) //102
NHSTUB(GetZoomLensCurrentPosition             ,0xffad56d4) //102
NHSTUB(GiveSemaphore                          ,0xff83b554) //112
NHSTUB(IsStrobeChargeCompleted                ,0xff8e72f4) //102
NHSTUB(LEDDrive                               ,0xff863c4c) //101
NHSTUB(LocalTime                              ,0xff88e3dc) //115
NHSTUB(LockMainPower                          ,0xff89973c) //103
//NHSTUB(Lseek                                ,0xff8380d8) //101
NHSTUB(MakeDirectory_Fut                      ,0xff837848) //116
NHSTUB(MakeSDCardBootable                     ,0xff874fe4) //105
NHSTUB(MoveFocusLensToDistance                ,0xffb52640) //102
NHSTUB(MoveIrisWithAv                         ,0xffae7138) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xffae77f0) //102
//NHSTUB(NewTaskShell                         ,0xff894258) //101
NHSTUB(Open                                   ,0xff837df4) //101
NHSTUB(PB2Rec                                 ,0xff89c6dc) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff87e614) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff87e5ec) //102
NHSTUB(PT_PlaySound                           ,0xff8891c8) //  6
NHSTUB(PostLogicalEventForNotPowerType        ,0xff898ef8) //103
NHSTUB(PostLogicalEventToUI                   ,0xff898f44) //103
NHSTUB(PutInNdFilter                          ,0xffae7638) //102
NHSTUB(PutOutNdFilter                         ,0xffae765c) //102
NHSTUB(Read                                   ,0xff81ad58) //101
NHSTUB(ReadFastDir                            ,0xffac2e78) //  6
NHSTUB(Rec2PB                                 ,0xff89c71c) //104
NHSTUB(RefreshPhysicalScreen                  ,0xff8b06fc) //104
//NHSTUB(Remove                               ,0xff838030) //  6
NHSTUB(RenameFile_Fut                         ,0xff837740) //116
NHSTUB(Restart                                ,0xff83d370) //106
NHSTUB(ScreenLock                             ,0xff8b18f4) //  4
NHSTUB(ScreenUnlock                           ,0xff8b1958) //  3
NHSTUB(SetAE_ShutterSpeed                     ,0xffb554bc) //102
NHSTUB(SetAutoShutdownTime                    ,0xff8997b0) //103
NHSTUB(SetCurrentCaptureModeType              ,0xff8a1ed4) //101
NHSTUB(SetFileAttributes                      ,0xff8382c0) //  6
NHSTUB(SetFileTimeStamp                       ,0xff838248) //  6
NHSTUB(SetLogicalEventActive                  ,0xff8994a4) //101
NHSTUB(SetParameterData                       ,0xff9ae420) //101
NHSTUB(SetPropertyCase                        ,0xff8946f4) //102
NHSTUB(SetScriptMode                          ,0xff8994f4) //101
NHSTUB(SleepTask                              ,0xff83b800) //101
NHSTUB(TakeSemaphore                          ,0xff83b484) //101
NHSTUB(TurnOffBackLight                       ,0xff8a8cbc) //104
NHSTUB(TurnOnBackLight                        ,0xff8a8ca4) //104
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff99e2a0) //101
NHSTUB(UnlockAF                               ,0xff839714) //102
NHSTUB(UnlockMainPower                        ,0xff899690) //103
NHSTUB(UnsetZoomForMovie                      ,0xff9b52e4) //104
NHSTUB(VbattGet                               ,0xff833118) //101
NHSTUB(Write                                  ,0xff837f10) //101
NHSTUB(WriteSDCard                            ,0xff968358) //108
NHSTUB(_log                                   ,0xffb94908) //111
NHSTUB(_log10                                 ,0xffb94e48) //112
NHSTUB(_pow                                   ,0xffb94fc0) //114
NHSTUB(_sqrt                                  ,0xffb96be4) //  6
NHSTUB(add_ptp_handler                        ,0xffa7532c) //  6
NHSTUB(apex2us                                ,0xffa37330) //  4
NHSTUB(close                                  ,0xff81abb4) //  6
NHSTUB(closedir                               ,0xffac2cd4) //  4
NHSTUB(err_init_task                          ,0xff815fd4) //111
NHSTUB(exmem_alloc                            ,0xff88f3a4) //101
NHSTUB(exmem_free                             ,0xff88f41c) //101
NHSTUB(free                                   ,0xff814244) //112
NHSTUB(kbd_p1_f                               ,0xff8349e4) //109
NHSTUB(kbd_p1_f_cont                          ,0xff8349f0) //109
NHSTUB(kbd_p2_f                               ,0xff8341d8) //109
NHSTUB(kbd_read_keys                          ,0xff834968) //109
NHSTUB(kbd_read_keys_r2                       ,0xff86410c) //109
NHSTUB(lseek                                  ,0xff8380d8) //101
NHSTUB(malloc                                 ,0xff8141ec) //112
NHSTUB(memcmp                                 ,0xff82092c) //101
NHSTUB(memcpy                                 ,0xff841250) //101
NHSTUB(memset                                 ,0xffa36330) //101
NHSTUB(mkdir                                  ,0xff838358) //109
NHSTUB(mktime_ext                             ,0xff8b276c) //  1
NHSTUB(open                                   ,0xff81ab04) //  6
NHSTUB(OpenFastDir                            ,0xffac2d24) //  6
NHSTUB(qsort                                  ,0xffb35a44) //  6
NHSTUB(rand                                   ,0xffa36470) //  6
//NHSTUB(read                                 ,0xff81ad58) //101
NHSTUB(realloc                                ,0xffa363ac) //115
NHSTUB(reboot_fw_update                       ,0xffac8314) //106
NHSTUB(set_control_event                      ,0xff899168) //111
NHSTUB(srand                                  ,0xffa36464) //  6
NHSTUB(stat                                   ,0xff838120) //109
NHSTUB(strcat                                 ,0xff8b1f24) //  1
NHSTUB(strchr                                 ,0xff8140b8) //  1
NHSTUB(strcmp                                 ,0xff8208e8) //101
NHSTUB(strcpy                                 ,0xff8208d0) //101
NHSTUB(strftime                               ,0xff8b216c) //113
NHSTUB(strlen                                 ,0xff814104) //101
NHSTUB(strncmp                                ,0xff81406c) //  1
NHSTUB(strncpy                                ,0xff814030) //  1
NHSTUB(strrchr                                ,0xff8140dc) //  1
NHSTUB(strtol                                 ,0xff841550) //101
NHSTUB(strtolx                                ,0xff841354) //109
   DEF(task_CaptSeq                           ,0xff881368) //110
   DEF(task_ExpDrv                            ,0xff8ca428) //110
   DEF(task_InitFileModules                   ,0xff89d020) //110
   DEF(task_MovieRecord                       ,0xff982008) //110
   DEF(task_PhySw                             ,0xff834504) //110
NHSTUB(time                                   ,0xff88e9b8) //109
NHSTUB(vsprintf                               ,0xff820890) //115
//NHSTUB(write                                ,0xff837f10) //101
//NHSTUB(EngDrvIn                             ,0xff835828) //102
//NHSTUB(EngDrvOut                            ,0xff835810) //102
//NHSTUB(EngDrvRead                           ,0xff835830) //102
//NHSTUB(EngDrvBits                           ,0xff835844) //102
//NHSTUB(GetSDProtect                         ,0xff83492c) //101
//NHSTUB(StartRecModeMenu                     ,0xff8952bc) //102
//NHSTUB(DispCon_ShowBitmapColorBar           ,0xff85f558) //102
//NHSTUB(ResetZoomLens                        ,0xffae7744) //102
//NHSTUB(ResetFocusLens                       ,0xffae6410) //102
//NHSTUB(NR_GetDarkSubType                    ,0xff989e0c) //102
//NHSTUB(NR_SetDarkSubType                    ,0xff989d44) //102
//NHSTUB(SavePaletteData                      ,0xffb57950) //102
//NHSTUB(GUISrv_StartGUISystem                ,0xff8aff14) //101
