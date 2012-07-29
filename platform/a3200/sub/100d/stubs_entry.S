// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R47 (DRYOS version 2.3, release #0047)
//   Firmware Ver GM1.00D
//   Canon PowerShot A3200 IS

// Values for makefile.inc
//   PLATFORMOSVER = 47
//   PLATFORMID = 12836 (0x3224) // Found @ 0xfffe0040
//   MAXRAMADDR = 0x03ffffff
//   KEYSYS = d4c                // Found @ 0xffff350c
//   NEED_ENCODED_DISKBOOT = 6   // Found @ 0xffff351c

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NSTUB(kbd_pwr_off                           ,0xff860280) //  2 60%    *** != 0x00000000
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff895914 -> ff8921c0 -> ff9931ac -> ffac7c28 -> ffbedae8
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00032d14) // Found @0xff83454c
DEF(physw_run                               ,0x00001c30) // Found @0xff83410c
DEF(levent_table                            ,0xffb9ffb0) // Found @0xffb9ffb0
DEF(FlashParamsTable                        ,0xffbedd20) // Found @0xffbedd20
DEF(movie_status                            ,0x00006724) // Found @0xff969018
DEF(full_screen_refresh                     ,0x0000915c) // Found @0xffa066d0
DEF(canon_menu_active                       ,0x00002f60) // Found @0xff88d990
DEF(canon_shoot_menu_active                 ,0x00007be5) // Found @0xff9ad3bc
DEF(playrec_mode                            ,0x00002c88) // Found @0xff87fc8c
DEF(zoom_status                             ,0x0000cf3c) // Found @0xffacb2fc
DEF(some_flag_for_af_scan                   ,0x00006afc) // Found @0xff96cd0c
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 12 entries in the table - set NUM_FL to 12
DEF(focus_len_table                         ,0xfffe2f88) // Found @0xfffe2f88
DEF(zoom_busy                               ,0x0000664c) // Found @0xff9648a4
DEF(focus_busy                              ,0x000064c8) // Found @0xff95fb1c
DEF(recreview_hold                          ,0x00003534) // Found @0xff89aeac
DEF(palette_control                         ,0x0000915c) // Found @0xffa0664c
DEF(active_palette_buffer                   ,0x00009164) // Found @0xffa06650
DEF(palette_buffer                          ,0x000b4b7c) // Found @0xffa06a04

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x403f1000; }             // Found @0xff85b834
//void *vid_get_viewport_fb()      { return (void*)0x40546b80; }             // Found @0xffb1db58
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x29a0+0x58)); } // Found @0xff871340 & 0xff871378
//char *camera_jpeg_count_str()    { return (char*)0x000b44d4; }             // Found @0xff9fd22c
//long hook_raw_size()             { return 0x014d2400; }                    // Found @0xffb2101c
//int get_flash_params_count(void) { return 0xa0; }                          // Found @0xff9941e4

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffb5d574, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x04000000 // Found @0xffb5d594, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 2, KEY_SHOOT_FULL      ,0x00003000 }, // Found @0xffb5d554, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00002000 }, // Found @0xffb5d554, levent 0x01
//    { 2, KEY_UP              ,0x00000001 }, // Found @0xffb5d4f4, levent 0x04
//    { 2, KEY_DOWN            ,0x00000002 }, // Found @0xffb5d4fc, levent 0x05
//    { 2, KEY_SHOOT_HALF      ,0x00001000 }, // Found @0xffb5d54c, levent 0x00
//    { 2, KEY_LEFT            ,0x00000004 }, // Found @0xffb5d504, levent 0x06
//    { 2, KEY_RIGHT           ,0x00000008 }, // Found @0xffb5d50c, levent 0x07
//    { 2, KEY_SET             ,0x00000010 }, // Found @0xffb5d514, levent 0x08
//    { 2, KEY_DISPLAY         ,0x00000020 }, // Found @0xffb5d51c, levent 0x0a
//    { 2, KEY_MENU            ,0x00000080 }, // Found @0xffb5d52c, levent 0x09
//    { 2, KEY_ZOOM_OUT        ,0x00004000 }, // Found @0xffb5d55c, levent 0x03
//    { 2, KEY_ZOOM_IN         ,0x00008000 }, // Found @0xffb5d564, levent 0x02
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    4416 // Found @0xff93a144
//#define CAM_RAW_ROWS      3296 // Found @0xff93a14c
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff83a6c0

// Misc stuff
DEF(ctypes, 0xffb5be52)

// For capt_seq.c
//static long *nrflag = (long*)(0x6b30+0x08);  // Found @ ff970fcc & ff971010
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NSTUB(AllocateMemory                          ,0xffab65f8) //101
NSTUB(AllocateUncacheableMemory               ,0xff83a678) //112
NSTUB(Close                                   ,0xff836c70) //101
NSTUB(CreateTask                              ,0xff81e9b0) //101
NSTUB(DebugAssert                             ,0xff81ec88) //111
NSTUB(DeleteDirectory_Fut                     ,0xff83666c) //  1
NSTUB(DeleteFile_Fut                          ,0xff836588) //112
NSTUB(DoAFLock                                ,0xff83842c) //102
NSTUB(EnterToCompensationEVF                  ,0xff838688) //104
NSTUB(ExecuteEventProcedure                   ,0xff889190) //  1
NSTUB(ExitFromCompensationEVF                 ,0xff8386cc) //104
NSTUB(ExitTask                                ,0xff81ec40) //101
NSTUB(ExpCtrlTool_StartContiAE                ,0xff846c90) //104
NSTUB(ExpCtrlTool_StopContiAE                 ,0xff846d68) //104
NSTUB(Fclose_Fut                              ,0xff836704) //101
NSTUB(Feof_Fut                                ,0xff8368f0) //  1
NSTUB(Fflush_Fut                              ,0xff83692c) //  1
NSTUB(Fgets_Fut                               ,0xff836858) //  6
NSTUB(Fopen_Fut                               ,0xff8366c4) //101
NSTUB(Fread_Fut                               ,0xff8367b0) //101
NSTUB(FreeMemory                              ,0xffab65f0) //101
NSTUB(FreeUncacheableMemory                   ,0xff83a6b8) //112
NSTUB(Fseek_Fut                               ,0xff8368a4) //101
NSTUB(Fwrite_Fut                              ,0xff836804) //101
NSTUB(GetBatteryTemperature                   ,0xff8621e0) //102
NSTUB(GetCCDTemperature                       ,0xff86216c) //102
NSTUB(GetCurrentAvValue                       ,0xff9616ec) //102
NSTUB(GetDrive_ClusterSize                    ,0xff86fca4) //  6
NSTUB(GetDrive_FreeClusters                   ,0xff86fcfc) //  6
NSTUB(GetDrive_TotalClusters                  ,0xff86fcd4) //  6
NSTUB(GetFocusLensSubjectDistance             ,0xff9607a0) //102
NSTUB(GetFocusLensSubjectDistanceFromLens     ,0xff960c00) //  3
NSTUB(GetImageFolder                          ,0xff940fcc) //  6
NSTUB(GetKbdState                             ,0xff860268) //109
NSTUB(GetMemInfo                              ,0xff81a29c) //  3
NSTUB(GetOpticalTemperature                   ,0xff862254) //102
NSTUB(GetParameterData                        ,0xff9941a4) //101
NSTUB(GetPropertyCase                         ,0xff88cef8) //102
NSTUB(GetSystemTime                           ,0xffab6650) //101
NSTUB(GetVRAMHPixelsSize                      ,0xff853c08) //102
NSTUB(GetVRAMVPixelsSize                      ,0xff853c14) //102
NSTUB(GetZoomLensCurrentPoint                 ,0xff964c28) //102
NSTUB(GetZoomLensCurrentPosition              ,0xffaa33c8) //102
NSTUB(GiveSemaphore                           ,0xff83a070) //112
NSTUB(IsStrobeChargeCompleted                 ,0xff8d8b84) //102
NSTUB(LEDDrive                                ,0xff85f87c) //101
NSTUB(LocalTime                               ,0xff886a80) //  6
NSTUB(LockMainPower                           ,0xff891db4) //103
NSTUB(Lseek                                   ,0xff836e8c) //101
NSTUB(MakeDirectory_Fut                       ,0xff8365fc) //  6
NSTUB(MakeSDCardBootable                      ,0xff86ff34) //105
NSTUB(MoveFocusLensToDistance                 ,0xffb19eb4) //102
NSTUB(MoveIrisWithAv                          ,0xffab32b8) //102
NSTUB(MoveZoomLensWithPoint                   ,0xffab3970) //102
NSTUB(NewTaskShell                            ,0xff88c940) //101
NSTUB(Open                                    ,0xff836ba8) //101
NSTUB(PB2Rec                                  ,0xff894f7c) //104
NSTUB(PT_MoveDigitalZoomToWide                ,0xff8782e4) //102
NSTUB(PT_MoveOpticalZoomAt                    ,0xff8782bc) //102
NSTUB(PT_PlaySound                            ,0xff881ac4) //  6
NSTUB(PostLogicalEventForNotPowerType         ,0xff891580) //103
NSTUB(PostLogicalEventToUI                    ,0xff8915cc) //103
NSTUB(PutInNdFilter                           ,0xffab37b8) //102
NSTUB(PutOutNdFilter                          ,0xffab37dc) //102
NSTUB(Read                                    ,0xff81ad58) //101
NSTUB(ReadFastDir                             ,0xffa90bec) //  6
NSTUB(Rec2PB                                  ,0xff894fbc) //104
NSTUB(RefreshPhysicalScreen                   ,0xff8a5940) //104
NSTUB(Remove                                  ,0xff836de4) //  6
NSTUB(RenameFile_Fut                          ,0xff8364f4) //  6
NSTUB(Restart                                 ,0xff83be88) //106
NSTUB(ScreenLock                              ,0xff8a6b78) //  4
NSTUB(ScreenUnlock                            ,0xff8a6bdc) //  3
NSTUB(SetAE_ShutterSpeed                      ,0xffb1cd30) //102
NSTUB(SetAutoShutdownTime                     ,0xff891e28) //103
NSTUB(SetCurrentCaptureModeType               ,0xff898b34) //101
NSTUB(SetFileAttributes                       ,0xff837074) //  6
NSTUB(SetFileTimeStamp                        ,0xff836ffc) //  6
NSTUB(SetLogicalEventActive                   ,0xff891b2c) //101
NSTUB(SetParameterData                        ,0xff994114) //101
NSTUB(SetPropertyCase                         ,0xff88cddc) //102
NSTUB(SetScriptMode                           ,0xff891b7c) //101
NSTUB(SleepTask                               ,0xff83a31c) //101
NSTUB(TakeSemaphore                           ,0xff839fa0) //101
NSTUB(TurnOffBackLight                        ,0xff89e2ac) //104
NSTUB(TurnOnBackLight                         ,0xff89e294) //104
NSTUB(UIFS_WriteFirmInfoToFile                ,0xff985628) //101
NSTUB(UnlockAF                                ,0xff838464) //102
NSTUB(UnlockMainPower                         ,0xff891d08) //103
NSTUB(UnsetZoomForMovie                       ,0xff99d6b8) //104
NSTUB(VbattGet                                ,0xff832e20) //101
NSTUB(Write                                   ,0xff836cc4) //101
NSTUB(WriteSDCard                             ,0xff950e38) //108
NSTUB(_log                                    ,0xffb58978) //111
NSTUB(_log10                                  ,0xffb58eb8) //112
NSTUB(_pow                                    ,0xffb59030) //114
NSTUB(_sqrt                                   ,0xffb5ac54) //  6
NSTUB(add_ptp_handler                         ,0xffa46d50) //  6
NSTUB(apex2us                                 ,0xffa0ba38) //  4
NSTUB(close                                   ,0xff81abb4) //  6
NSTUB(closedir                                ,0xffa90a48) //  4
NSTUB(err_init_task                           ,0xff815fd4) //  4
NSTUB(exmem_alloc                             ,0xff887a48) //101
NSTUB(free                                    ,0xff814244) //112
NSTUB(kbd_p1_f                                ,0xff8345c8) //109
NSTUB(kbd_p1_f_cont                           ,0xff8345d4) //109
NSTUB(kbd_p2_f                                ,0xff833ddc) //109
NSTUB(kbd_read_keys                           ,0xff83454c) //109
NSTUB(kbd_read_keys_r2                        ,0xff85fcc0) //109
NSTUB(lseek                                   ,0xff836e8c) //101
NSTUB(malloc                                  ,0xff8141ec) //112
NSTUB(memcmp                                  ,0xff8208bc) //101
NSTUB(memcpy                                  ,0xff83fcf8) //101
NSTUB(memset                                  ,0xffa0aa38) //101
NSTUB(mkdir                                   ,0xff83710c) //  6
NSTUB(mktime_ext                              ,0xff8a79bc) //  1
NSTUB(open                                    ,0xff81ab04) //  6
NSTUB(opendir                                 ,0xffa90a98) //  6
NSTUB(openfastdir                             ,0xffa90a98) //  6
NSTUB(qsort                                   ,0xffafcdd8) //  6
NSTUB(rand                                    ,0xffa0ab78) //  6
NSTUB(read                                    ,0xff81ad58) //101
NSTUB(reboot_fw_update                        ,0xffa96088) //  6
NSTUB(rename                                  ,0xff8364f4) //  6
NSTUB(set_control_event                       ,0xff8917f0) //111
NSTUB(srand                                   ,0xffa0ab6c) //  6
NSTUB(stat                                    ,0xff836ed4) //  3
NSTUB(strcat                                  ,0xff8a7174) //  1
NSTUB(strchr                                  ,0xff8140b8) //  1
NSTUB(strcmp                                  ,0xff820878) //101
NSTUB(strcpy                                  ,0xff820860) //101
NSTUB(strftime                                ,0xff8a73bc) //113
NSTUB(strlen                                  ,0xff814104) //101
NSTUB(strncmp                                 ,0xff81406c) //  1
NSTUB(strncpy                                 ,0xff814030) //  1
NSTUB(strrchr                                 ,0xff8140dc) //  1
NSTUB(strtol                                  ,0xff83fff8) //101
NSTUB(strtolx                                 ,0xff83fdfc) //109
  DEF(task_CaptSeq                            ,0xff87aa8c) //110
  DEF(task_ExpDrv                             ,0xff8be348) //110
  DEF(task_InitFileModules                    ,0xff895794) //110
  DEF(task_MovieRecord                        ,0xff969ae4) //110
  DEF(task_PhySw                              ,0xff834108) //110
NSTUB(time                                    ,0xff88705c) //  6
NSTUB(vsprintf                                ,0xff820820) //  6
NSTUB(write                                   ,0xff836cc4) //101
