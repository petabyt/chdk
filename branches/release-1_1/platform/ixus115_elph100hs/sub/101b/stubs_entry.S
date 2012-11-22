// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R47 (DRYOS version 2.3, release #0047)
//   Firmware Ver GM1.01B
//   Canon IXUS 115 HS

// Values for makefile.inc
//   PLATFORMOSVER = 47
//   PLATFORMID = 12839 (0x3227) // Found @ 0xfffe0040
//   MAXRAMADDR = 0x07ffffff
//   KEYSYS = d4c                // Found @ 0xffff3630
//   NEED_ENCODED_DISKBOOT = 6   // Found @ 0xffff3640

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
NSTUB(kbd_pwr_off                             ,0xff86470c) //  2 60%
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0xff907390

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff89d1ac -> ff899b4c -> ff9ad4b8 -> ffafc614 -> ffc436c8
// Mode 33320 in firmware but not in current modemap
// Mode 33322 in firmware but not in current modemap

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00033f48) // Found @0xff834968
DEF(physw_run                               ,0x00001c44) // Found @0xff834508
DEF(physw_sleep_delay                       ,0x00001c4c) // Found @0xff834508
DEF(levent_table                            ,0xffbe12ec) // Found @0xffbe12ec
DEF(FlashParamsTable                        ,0xffc43904) // Found @0xffc43904
DEF(movie_status                            ,0x00006d54) // Found @0xff980d7c
DEF(full_screen_refresh                     ,0x00009ca4) // Found @0xffa2efa0
DEF(canon_menu_active                       ,0x000031b4) // Found @0xff8952c0
DEF(canon_shoot_menu_active                 ,0x0000836d) // Found @0xff9c4c44
DEF(playrec_mode                            ,0x00002ee0) // Found @0xff8871b4
DEF(zoom_status                             ,0x0000dd08) // Found @0xffaffcf4
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

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40471000; }             // Found @0xff85f59c
//void *vid_get_viewport_fb()      { return (void*)0x405c6b80; }             // Found @0xffb5636c
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2ba0+0x58)); } // Found @0xff877260 & 0xff877298
//char *camera_jpeg_count_str()    { return (char*)0x000bb3a8; }             // Found @0xffa2629c
//long hook_raw_size()             { return 0x0123eaf0; }                    // Found @0xffb59864
//int get_flash_params_count(void) { return 0xa0; }                          // Found @0xff9ae4f0

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffb99718, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x04000000 // Found @0xffb99738, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_PLAYBACK        ,0x00000001 }, // Found @0xffb99688, levent 0x601
//    { 0, KEY_POWER           ,0x00000002 }, // Found @0xffb99690, levent 0x600
//    { 1, KEY_MENU            ,0x01000000 }, // Found @0xffb996a8, levent 0x09
//    { 1, KEY_SET             ,0x04000000 }, // Found @0xffb996b0, levent 0x08
//    { 1, KEY_ZOOM_OUT        ,0x10000000 }, // Found @0xffb996b8, levent 0x03
//    { 1, KEY_ZOOM_IN         ,0x20000000 }, // Found @0xffb996c0, levent 0x02
//    { 1, KEY_VIDEO           ,0x80000000 }, // Found @0xffb996d0, levent 0x12
//    { 2, KEY_UP              ,0x00000001 }, // Found @0xffb996d8, levent 0x04
//    { 2, KEY_DOWN            ,0x00000002 }, // Found @0xffb996e0, levent 0x05
//    { 2, KEY_LEFT            ,0x00000004 }, // Found @0xffb996e8, levent 0x06
//    { 2, KEY_RIGHT           ,0x00000008 }, // Found @0xffb996f0, levent 0x07
//    { 2, KEY_SHOOT_FULL      ,0x00000030 }, // Found @0xffb99700, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000020 }, // Found @0xffb99700, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000010 }, // Found @0xffb996f8, levent 0x00
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
DEF(ctypes, 0xffb97e0a)

// For capt_seq.c
//static long *nrflag = (long*)(0x718c+0x08);  // Found @ ff989be4 & ff989c50
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NSTUB(AllocateMemory                          ,0xffaea908) //101
NSTUB(AllocateUncacheableMemory               ,0xff83bb5c) //112
NSTUB(Close                                   ,0xff837ebc) //101
NSTUB(CreateTask                              ,0xff81e9b0) //101
NSTUB(DebugAssert                             ,0xff81ec88) //111
NSTUB(DeleteDirectory_Fut                     ,0xff8378b8) //  1
NSTUB(DeleteFile_Fut                          ,0xff8377d4) //112
NSTUB(DoAFLock                                ,0xff8396dc) //102
NSTUB(EnterToCompensationEVF                  ,0xff839938) //104
NSTUB(ExecuteEventProcedure                   ,0xff890b4c) //  2
NSTUB(ExitFromCompensationEVF                 ,0xff83997c) //104
NSTUB(ExitTask                                ,0xff81ec40) //101
NSTUB(ExpCtrlTool_StartContiAE                ,0xff8481e8) //104
NSTUB(ExpCtrlTool_StopContiAE                 ,0xff8482c0) //104
NSTUB(Fclose_Fut                              ,0xff837950) //101
NSTUB(Feof_Fut                                ,0xff837b3c) //  1
NSTUB(Fflush_Fut                              ,0xff837b78) //  1
NSTUB(Fgets_Fut                               ,0xff837aa4) //  6
NSTUB(Fopen_Fut                               ,0xff837910) //101
NSTUB(Fread_Fut                               ,0xff8379fc) //101
NSTUB(FreeMemory                              ,0xffaea900) //101
NSTUB(FreeUncacheableMemory                   ,0xff83bb9c) //112
NSTUB(Fseek_Fut                               ,0xff837af0) //101
NSTUB(Fwrite_Fut                              ,0xff837a50) //101
NSTUB(GetBatteryTemperature                   ,0xff8677dc) //102
NSTUB(GetCCDTemperature                       ,0xff867768) //102
NSTUB(GetCurrentAvValue                       ,0xff97902c) //102
NSTUB(GetDrive_ClusterSize                    ,0xff874d54) //  6
NSTUB(GetDrive_FreeClusters                   ,0xff874dac) //  6
NSTUB(GetDrive_TotalClusters                  ,0xff874d84) //  6
NSTUB(GetFocusLensSubjectDistance             ,0xff978220) //102
NSTUB(GetFocusLensSubjectDistanceFromLens     ,0xff978680) //  3
NSTUB(GetImageFolder                          ,0xff956f00) //  6
NSTUB(GetKbdState                             ,0xff8646f4) //109
NSTUB(GetMemInfo                              ,0xff81a29c) //  3
NSTUB(GetOpticalTemperature                   ,0xff867850) //102
NSTUB(GetParameterData                        ,0xff9ae4b0) //101
NSTUB(GetPropertyCase                         ,0xff894810) //102
NSTUB(GetSystemTime                           ,0xffaea960) //101
NSTUB(GetVRAMHPixelsSize                      ,0xff855b74) //102
NSTUB(GetVRAMVPixelsSize                      ,0xff855b80) //102
NSTUB(GetZoomLensCurrentPoint                 ,0xff97c4c8) //102
NSTUB(GetZoomLensCurrentPosition              ,0xffad56d4) //102
NSTUB(GiveSemaphore                           ,0xff83b554) //112
NSTUB(IsStrobeChargeCompleted                 ,0xff8e72f4) //102
NSTUB(LEDDrive                                ,0xff863c4c) //101
NSTUB(LocalTime                               ,0xff88e3dc) //115
NSTUB(LockMainPower                           ,0xff89973c) //103
NSTUB(Lseek                                   ,0xff8380d8) //101
NSTUB(MakeDirectory_Fut                       ,0xff837848) //116
NSTUB(MakeSDCardBootable                      ,0xff874fe4) //105
NSTUB(MoveFocusLensToDistance                 ,0xffb52668) //102
NSTUB(MoveIrisWithAv                          ,0xffae7160) //102
NSTUB(MoveZoomLensWithPoint                   ,0xffae7818) //102
NSTUB(NewTaskShell                            ,0xff894258) //101
NSTUB(Open                                    ,0xff837df4) //101
NSTUB(PB2Rec                                  ,0xff89c6dc) //104
NSTUB(PT_MoveDigitalZoomToWide                ,0xff87e614) //102
NSTUB(PT_MoveOpticalZoomAt                    ,0xff87e5ec) //102
NSTUB(PT_PlaySound                            ,0xff8891c8) //  6
NSTUB(PostLogicalEventForNotPowerType         ,0xff898ef8) //103
NSTUB(PostLogicalEventToUI                    ,0xff898f44) //103
NSTUB(PutInNdFilter                           ,0xffae7660) //102
NSTUB(PutOutNdFilter                          ,0xffae7684) //102
NSTUB(Read                                    ,0xff81ad58) //101
NSTUB(ReadFastDir                             ,0xffac2e78) //  6
NSTUB(Rec2PB                                  ,0xff89c71c) //104
NSTUB(RefreshPhysicalScreen                   ,0xff8b06fc) //104
NSTUB(Remove                                  ,0xff838030) //  6
NSTUB(RenameFile_Fut                          ,0xff837740) //  6
NSTUB(Restart                                 ,0xff83d370) //106
NSTUB(ScreenLock                              ,0xff8b18f4) //  4
NSTUB(ScreenUnlock                            ,0xff8b1958) //  3
NSTUB(SetAE_ShutterSpeed                      ,0xffb554e4) //102
NSTUB(SetAutoShutdownTime                     ,0xff8997b0) //103
NSTUB(SetCurrentCaptureModeType               ,0xff8a1ed4) //101
NSTUB(SetFileAttributes                       ,0xff8382c0) //  6
NSTUB(SetFileTimeStamp                        ,0xff838248) //  6
NSTUB(SetLogicalEventActive                   ,0xff8994a4) //101
NSTUB(SetParameterData                        ,0xff9ae420) //101
NSTUB(SetPropertyCase                         ,0xff8946f4) //102
NSTUB(SetScriptMode                           ,0xff8994f4) //101
NSTUB(SleepTask                               ,0xff83b800) //101
NSTUB(TakeSemaphore                           ,0xff83b484) //101
NSTUB(TurnOffBackLight                        ,0xff8a8cbc) //104
NSTUB(TurnOnBackLight                         ,0xff8a8ca4) //104
NSTUB(UIFS_WriteFirmInfoToFile                ,0xff99e2a0) //101
NSTUB(UnlockAF                                ,0xff839714) //102
NSTUB(UnlockMainPower                         ,0xff899690) //103
NSTUB(UnsetZoomForMovie                       ,0xff9b52e4) //104
NSTUB(VbattGet                                ,0xff833118) //101
NSTUB(Write                                   ,0xff837f10) //101
NSTUB(WriteSDCard                             ,0xff968358) //108
NSTUB(_log                                    ,0xffb94930) //111
NSTUB(_log10                                  ,0xffb94e70) //112
NSTUB(_pow                                    ,0xffb94fe8) //114
NSTUB(_sqrt                                   ,0xffb96c0c) //  6
NSTUB(add_ptp_handler                         ,0xffa7532c) //  6
NSTUB(apex2us                                 ,0xffa37330) //  4
NSTUB(close                                   ,0xff81abb4) //  6
NSTUB(closedir                                ,0xffac2cd4) //  4
NSTUB(err_init_task                           ,0xff815fd4) //  4
NSTUB(exmem_alloc                             ,0xff88f3a4) //101
NSTUB(free                                    ,0xff814244) //112
NSTUB(kbd_p1_f                                ,0xff8349e4) //109
NSTUB(kbd_p1_f_cont                           ,0xff8349f0) //109
NSTUB(kbd_p2_f                                ,0xff8341d8) //109
NSTUB(kbd_read_keys                           ,0xff834968) //109
NSTUB(kbd_read_keys_r2                        ,0xff86410c) //109
NSTUB(lseek                                   ,0xff8380d8) //101
NSTUB(malloc                                  ,0xff8141ec) //112
NSTUB(memcmp                                  ,0xff82092c) //101
NSTUB(memcpy                                  ,0xff841250) //101
NSTUB(memset                                  ,0xffa36330) //101
NSTUB(mkdir                                   ,0xff838358) //109
NSTUB(mktime_ext                              ,0xff8b276c) //  1
NSTUB(open                                    ,0xff81ab04) //  6
NSTUB(opendir                                 ,0xffac2d24) //  6
NSTUB(openfastdir                             ,0xffac2d24) //  6
NSTUB(qsort                                   ,0xffb35a6c) //  6
NSTUB(rand                                    ,0xffa36470) //  6
NSTUB(read                                    ,0xff81ad58) //101
NSTUB(reboot_fw_update                        ,0xffac8314) //106
NSTUB(rename                                  ,0xff837740) //  6
NSTUB(set_control_event                       ,0xff899168) //111
NSTUB(srand                                   ,0xffa36464) //  6
NSTUB(stat                                    ,0xff838120) //  3
NSTUB(strcat                                  ,0xff8b1f24) //  1
NSTUB(strchr                                  ,0xff8140b8) //  1
NSTUB(strcmp                                  ,0xff8208e8) //101
NSTUB(strcpy                                  ,0xff8208d0) //101
NSTUB(strftime                                ,0xff8b216c) //113
NSTUB(strlen                                  ,0xff814104) //101
NSTUB(strncmp                                 ,0xff81406c) //  1
NSTUB(strncpy                                 ,0xff814030) //  1
NSTUB(strrchr                                 ,0xff8140dc) //  1
NSTUB(strtol                                  ,0xff841550) //101
NSTUB(strtolx                                 ,0xff841354) //109
  DEF(task_CaptSeq                            ,0xff881368) //110
  DEF(task_ExpDrv                             ,0xff8ca428) //110
  DEF(task_InitFileModules                    ,0xff89d020) //110
  DEF(task_MovieRecord                        ,0xff982008) //110
  DEF(task_PhySw                              ,0xff834504) //110
NSTUB(time                                    ,0xff88e9b8) //  6
NSTUB(vsprintf                                ,0xff820890) //  6
NSTUB(write                                   ,0xff837f10) //101
