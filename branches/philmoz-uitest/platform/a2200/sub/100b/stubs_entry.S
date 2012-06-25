// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R47 (DRYOS version 2.3, release #0047)
//   Firmware Ver GM1.00B
//   Canon PowerShot A2200

// Values for makefile.inc
//   PLATFORMOSVER = 47
//   PLATFORMID = 12842 (0x322a) // Found @ 0xfffe0040
//   MAXRAMADDR = 0x03ffffff
//   KEYSYS = d4c                // Found @ 0xffff350c
//   NEED_ENCODED_DISKBOOT = 6   // Found @ 0xffff351c

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NSTUB(SetFileAttributes                     ,0xff837180) //  6        *** != 0xffb370d8
//NSTUB(kbd_pwr_off                           ,0xff8602cc) //  2 60%    *** != 0x00000000
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000
//NSTUB(mkdir                                 ,0xff837214) //  6 53%        == 0xff837214

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff89353c -> ff88fde8 -> ff98d574 -> ffac1350 -> ffbe5140
// Current modemap entry not found in firmware - MODE_SCN_POSTER_EFFECT    8734
// Current modemap entry not found in firmware - MODE_SCN_SUPER_VIVID      8742
// Current modemap entry not found in firmware - MODE_SCN_MONOCHROME       8754
// Current modemap entry not found in firmware - MODE_SCN_TOY_CAMERA       8751
// Current modemap entry not found in firmware - MODE_SCN_MINIATURE        8748
// Current modemap entry not found in firmware - MODE_SCN_FISHEYE          8747

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00032914) // Found @0xff834658
DEF(physw_run                               ,0x00001c30) // Found @0xff834218
DEF(levent_table                            ,0xffb97b94) // Found @0xffb97b94
DEF(FlashParamsTable                        ,0xffbe537c) // Found @0xffbe537c
DEF(movie_status                            ,0x000065ec) // Found @0xff96367c
DEF(full_screen_refresh                     ,0x00009010) // Found @0xffa006a8
DEF(canon_menu_active                       ,0x00002eec) // Found @0xff88b5b8
DEF(canon_shoot_menu_active                 ,0x00007aa1) // Found @0xff9a7580
DEF(playrec_mode                            ,0x00002c18) // Found @0xff87da48
DEF(zoom_status                             ,0x0000cb38) // Found @0xffac4a24
DEF(some_flag_for_af_scan                   ,0x000069c4) // Found @0xff967364
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 8 entries in the table - set NUM_FL to 8
DEF(focus_len_table                         ,0xfffe2a98) // Found @0xfffe2a98
DEF(zoom_busy                               ,0x00006544) // Found @0xff9600c0
DEF(focus_busy                              ,0x00006454) // Found @0xff95d4a0
DEF(recreview_hold                          ,0x000034c0) // Found @0xff898ac8
//DEF(palette_control                         ,0x00009010) // Found @0xffa00624,          stubs_min = 0x00009010 (0x9010)
//DEF(active_palette_buffer                   ,0x00009018) // Found @0xffa00628,          stubs_min = 0x00009018 (0x9018)
//DEF(palette_buffer                          ,0x000b41e4) // Found @0xffa009dc,          stubs_min = 0x000b41e4 (0xB41E4)

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x403f1000; }             // Found @0xff85b81c
//void *vid_get_viewport_fb()      { return (void*)0x40546b80; }             // Found @0xffb17310
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x29a0+0x58)); } // Found @0xff871344 & 0xff87137c
//char *camera_jpeg_count_str()    { return (char*)0x000b3b14; }             // Found @0xff9f71c8
//long hook_raw_size()             { return 0x014d2400; }                    // Found @0xffb1a7d4
//int get_flash_params_count(void) { return 0xa0; }                          // Found @0xff98e5ac

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffb56264, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x04000000 // Found @0xffb5628c, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_MENU            ,0x04000000 }, // Found @0xffb561e4, levent 0x09
//    { 1, KEY_UP              ,0x00001000 }, // Found @0xffb56214, levent 0x04
//    { 1, KEY_RIGHT           ,0x00002000 }, // Found @0xffb5621c, levent 0x07
//    { 1, KEY_DOWN            ,0x00004000 }, // Found @0xffb56224, levent 0x05
//    { 1, KEY_LEFT            ,0x00008000 }, // Found @0xffb5622c, levent 0x06
//    { 1, KEY_ZOOM_OUT        ,0x00010000 }, // Found @0xffb56234, levent 0x03
//    { 1, KEY_ZOOM_IN         ,0x00020000 }, // Found @0xffb5623c, levent 0x02
//    { 1, KEY_SET             ,0x00040000 }, // Found @0xffb56244, levent 0x08
//    { 1, KEY_DISPLAY         ,0x00080000 }, // Found @0xffb5624c, levent 0x0a
//    { 1, KEY_SHOOT_FULL      ,0x00000003 }, // Found @0xffb5620c, levent 0x01
//    { 1, KEY_SHOOT_FULL_ONLY ,0x00000002 }, // Found @0xffb5620c, levent 0x01
//    { 1, KEY_SHOOT_HALF      ,0x00000001 }, // Found @0xffb56204, levent 0x00
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    4416 // Found @0xff937b24
//#define CAM_RAW_ROWS      3296 // Found @0xff937b2c
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff83a6a8

// Misc stuff
DEF(ctypes, 0xffb54b4a)

// For capt_seq.c
//static long *nrflag = (long*)(0x69f8+0x08);  // Found @ ff96b594 & ff96b5d8
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NSTUB(AllocateMemory                          ,0xffaafd20) //101
NSTUB(AllocateUncacheableMemory               ,0xff83a660) //112
NSTUB(Close                                   ,0xff836d7c) //101
NSTUB(CreateTask                              ,0xff81e9b0) //101
NSTUB(DebugAssert                             ,0xff81ec88) //111
NSTUB(DeleteDirectory_Fut                     ,0xff836778) //  1
NSTUB(DeleteFile_Fut                          ,0xff836694) //112
NSTUB(DoAFLock                                ,0xff8384c8) //102
NSTUB(EnterToCompensationEVF                  ,0xff838724) //104
NSTUB(ExecuteEventProcedure                   ,0xff886db8) //  1
NSTUB(ExitFromCompensationEVF                 ,0xff838768) //104
NSTUB(ExitTask                                ,0xff81ec40) //101
NSTUB(ExpCtrlTool_StartContiAE                ,0xff846c78) //104
NSTUB(ExpCtrlTool_StopContiAE                 ,0xff846d50) //104
NSTUB(Fclose_Fut                              ,0xff836810) //101
NSTUB(Feof_Fut                                ,0xff8369fc) //  1
NSTUB(Fflush_Fut                              ,0xff836a38) //  1
NSTUB(Fgets_Fut                               ,0xff836964) //  6
NSTUB(Fopen_Fut                               ,0xff8367d0) //101
NSTUB(Fread_Fut                               ,0xff8368bc) //101
NSTUB(FreeMemory                              ,0xffaafd18) //101
NSTUB(FreeUncacheableMemory                   ,0xff83a6a0) //112
NSTUB(Fseek_Fut                               ,0xff8369b0) //101
NSTUB(Fwrite_Fut                              ,0xff836910) //101
NSTUB(GetBatteryTemperature                   ,0xff8621dc) //102
NSTUB(GetCCDTemperature                       ,0xff862168) //102
NSTUB(GetCurrentAvValue                       ,0xff95f060) //102
NSTUB(GetDrive_ClusterSize                    ,0xff86fca8) //  6
NSTUB(GetDrive_FreeClusters                   ,0xff86fd00) //  6
NSTUB(GetDrive_TotalClusters                  ,0xff86fcd8) //  6
NSTUB(GetFocusLensSubjectDistance             ,0xff95e124) //102
NSTUB(GetFocusLensSubjectDistanceFromLens     ,0xff95e584) //  3
NSTUB(GetImageFolder                          ,0xff93e9ac) //  6
NSTUB(GetKbdState                             ,0xff8602b4) //109
NSTUB(GetMemInfo                              ,0xff81a29c) //  3
NSTUB(GetOpticalTemperature                   ,0xff862250) //102
NSTUB(GetParameterData                        ,0xff98e56c) //101
NSTUB(GetPropertyCase                         ,0xff88ab20) //102
NSTUB(GetSystemTime                           ,0xffaafd78) //101
NSTUB(GetVRAMHPixelsSize                      ,0xff853bf0) //102
NSTUB(GetVRAMVPixelsSize                      ,0xff853bfc) //102
NSTUB(GetZoomLensCurrentPoint                 ,0xff960444) //102
NSTUB(GetZoomLensCurrentPosition              ,0xffa9d884) //102
NSTUB(GiveSemaphore                           ,0xff83a058) //112
NSTUB(IsStrobeChargeCompleted                 ,0xff8d66c4) //102
NSTUB(LEDDrive                                ,0xff85f8c8) //101
NSTUB(LocalTime                               ,0xff8846a8) //  6
NSTUB(LockMainPower                           ,0xff88f9dc) //103
NSTUB(Lseek                                   ,0xff836f98) //101
NSTUB(MakeDirectory_Fut                       ,0xff836708) //  6
NSTUB(MakeSDCardBootable                      ,0xff86ff38) //105
NSTUB(MoveFocusLensToDistance                 ,0xffb1366c) //102
NSTUB(MoveIrisWithAv                          ,0xffaad658) //102
NSTUB(MoveZoomLensWithPoint                   ,0xffaadd00) //102
NSTUB(NewTaskShell                            ,0xff88a568) //101
NSTUB(Open                                    ,0xff836cb4) //101
NSTUB(PB2Rec                                  ,0xff892ba4) //104
NSTUB(PT_MoveDigitalZoomToWide                ,0xff8761b4) //102
NSTUB(PT_MoveOpticalZoomAt                    ,0xff87618c) //102
NSTUB(PT_PlaySound                            ,0xff87f6ec) //  6
NSTUB(PostLogicalEventForNotPowerType         ,0xff88f1a8) //103
NSTUB(PostLogicalEventToUI                    ,0xff88f1f4) //103
NSTUB(PutInNdFilter                           ,0xffaadb48) //102
NSTUB(PutOutNdFilter                          ,0xffaadb6c) //102
NSTUB(Read                                    ,0xff81ad58) //101
NSTUB(ReadFastDir                             ,0xffa8b014) //  6
NSTUB(Rec2PB                                  ,0xff892be4) //104
NSTUB(RefreshPhysicalScreen                   ,0xff8a3468) //104
NSTUB(Remove                                  ,0xff836ef0) //  6
NSTUB(RenameFile_Fut                          ,0xff836600) //  6
NSTUB(Restart                                 ,0xff83be70) //106
NSTUB(ScreenLock                              ,0xff8a46a0) //  4
NSTUB(ScreenUnlock                            ,0xff8a4704) //  3
NSTUB(SetAE_ShutterSpeed                      ,0xffb164e8) //102
NSTUB(SetAutoShutdownTime                     ,0xff88fa50) //103
NSTUB(SetCurrentCaptureModeType               ,0xff89675c) //101
NSTUB(SetFileTimeStamp                        ,0xff837108) //  6
NSTUB(SetLogicalEventActive                   ,0xff88f754) //101
NSTUB(SetParameterData                        ,0xff98e4dc) //101
NSTUB(SetPropertyCase                         ,0xff88aa04) //102
NSTUB(SetScriptMode                           ,0xff88f7a4) //101
NSTUB(SleepTask                               ,0xff83a304) //101
NSTUB(TakeSemaphore                           ,0xff839f88) //101
NSTUB(TurnOffBackLight                        ,0xff89beb8) //104
NSTUB(TurnOnBackLight                         ,0xff89bea0) //104
NSTUB(UIFS_WriteFirmInfoToFile                ,0xff97fad8) //101
NSTUB(UnlockAF                                ,0xff838500) //102
NSTUB(UnlockMainPower                         ,0xff88f930) //103
NSTUB(UnsetZoomForMovie                       ,0xff99797c) //104
NSTUB(VbattGet                                ,0xff832e20) //101
NSTUB(Write                                   ,0xff836dd0) //101
NSTUB(WriteSDCard                             ,0xff94e7cc) //108
NSTUB(_log                                    ,0xffb51670) //111
NSTUB(_log10                                  ,0xffb51bb0) //112
NSTUB(_pow                                    ,0xffb51d28) //114
NSTUB(_sqrt                                   ,0xffb5394c) //  6
NSTUB(add_ptp_handler                         ,0xffa40c00) //  6
NSTUB(apex2us                                 ,0xffa05a10) //  4
NSTUB(close                                   ,0xff81abb4) //  6
NSTUB(closedir                                ,0xffa8ae70) //  4
NSTUB(err_init_task                           ,0xff815fd4) //  4
NSTUB(exmem_alloc                             ,0xff885670) //101
NSTUB(free                                    ,0xff814244) //112
NSTUB(kbd_p1_f                                ,0xff8346d4) //109
NSTUB(kbd_p1_f_cont                           ,0xff8346e0) //109
NSTUB(kbd_p2_f                                ,0xff833ee8) //109
NSTUB(kbd_read_keys                           ,0xff834658) //109
NSTUB(kbd_read_keys_r2                        ,0xff85fd0c) //109
NSTUB(lseek                                   ,0xff836f98) //101
NSTUB(malloc                                  ,0xff8141ec) //112
NSTUB(memcmp                                  ,0xff8208bc) //101
NSTUB(memcpy                                  ,0xff83fce0) //101
NSTUB(memset                                  ,0xffa04a10) //101
NSTUB(mktime_ext                              ,0xff8a54e4) //  1
NSTUB(open                                    ,0xff81ab04) //  6
NSTUB(opendir                                 ,0xffa8aec0) //  6
NSTUB(openfastdir                             ,0xffa8aec0) //  6
NSTUB(qsort                                   ,0xffaf64f4) //  6
NSTUB(rand                                    ,0xffa04b50) //  6
NSTUB(read                                    ,0xff81ad58) //101
NSTUB(reboot_fw_update                        ,0xffa904b0) //  6
NSTUB(rename                                  ,0xff836600) //  6
NSTUB(set_control_event                       ,0xff88f418) //111
NSTUB(srand                                   ,0xffa04b44) //  6
NSTUB(stat                                    ,0xff836fe0) //  3
NSTUB(strcat                                  ,0xff8a4c9c) //  1
NSTUB(strchr                                  ,0xff8140b8) //  1
NSTUB(strcmp                                  ,0xff820878) //101
NSTUB(strcpy                                  ,0xff820860) //101
NSTUB(strftime                                ,0xff8a4ee4) //113
NSTUB(strlen                                  ,0xff814104) //101
NSTUB(strncmp                                 ,0xff81406c) //  1
NSTUB(strncpy                                 ,0xff814030) //  1
NSTUB(strrchr                                 ,0xff8140dc) //  1
NSTUB(strtol                                  ,0xff83ffe0) //101
NSTUB(strtolx                                 ,0xff83fde4) //109
  DEF(task_CaptSeq                            ,0xff8788f0) //110
  DEF(task_ExpDrv                             ,0xff8bbe80) //110
  DEF(task_InitFileModules                    ,0xff8933bc) //110
  DEF(task_MovieRecord                        ,0xff964148) //110
  DEF(task_PhySw                              ,0xff834214) //110
NSTUB(time                                    ,0xff884c84) //  6
NSTUB(vsprintf                                ,0xff820820) //  6
NSTUB(write                                   ,0xff836dd0) //101
