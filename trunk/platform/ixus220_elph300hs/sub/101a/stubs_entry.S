// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R47 (DRYOS version 2.3, release #0047)
//   Firmware Ver GM1.01A
//   Canon IXUS 220HS

// Values for makefile.inc
//   PLATFORMID = 12841 (0x3229) // Found @ 0xfffe0040
//   MAXRAMADDR = 0x07ffffff
//   KEYSYS = d4c                // Found @ 0xffff3620
//   NEED_ENCODED_DISKBOOT = 6   // Found @ 0xffff3630

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NSTUB(kbd_pwr_off                           ,0xff865570) //  2 60%        == 0xff865570
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0xff865570

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff89e7f8 -> ff89b194 -> ff9b139c -> ffb041fc -> ffc4ee58
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
//DEF(physw_status                            ,0x0003418c) // Found @0xff834e18,          stubs_min = 0x0003418c (0x0003418c)
//DEF(physw_run                               ,0x00001c3c) // Found @0xff8349bc,          stubs_min = 0x00001c3c (0x00001c3c)
//DEF(levent_table                            ,0xffbeb220) // Found @0xffbeb220,          stubs_min = 0xffbeb220 (0xffbeb220)
//DEF(FlashParamsTable                        ,0xffc4f098) // Found @0xffc4f098,          stubs_min = 0xffc4f098 (0xffc4f098)
//DEF(movie_status                            ,0x00006dcc) // Found @0xff984bd0,          stubs_min = 0x00006dcc (0x00006dcc)
//DEF(full_screen_refresh                     ,0x00009d00) // Found @0xffa32dfc,          stubs_min = 0x00009d00 (0x00009d00)
//DEF(canon_menu_active                       ,0x00003210) // Found @0xff896910,          stubs_min = 0x00003210 (0x00003210)
//DEF(canon_shoot_menu_active                 ,0x000083d9) // Found @0xff9c8c1c,          stubs_min = 0x000083d9 (0x000083d9)
//DEF(playrec_mode                            ,0x00002f38) // Found @0xff888774,          stubs_min = 0x00002f38 (0x00002f38)
//DEF(zoom_status                             ,0x0000ded8) // Found @0xffb078b8,          stubs_min = 0x0000ded8 (0x0000ded8)
//DEF(some_flag_for_af_scan                   ,0x000071cc) // Found @0xff989240,          stubs_min = 0x000071cc (0x000071cc)

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40471000; } // Found @0xff85fd1c
//void *vid_get_viewport_fb()      { return (void*)0x405c6b80; } // Found @0xffb5e134
//char *camera_jpeg_count_str()    { return (char*)0x000babac; } // Found @0xffa2a298
//long hook_raw_size()             { return 0x0123eaf0; }        // Found @0xffb6162c
//int get_flash_params_count(void) { return 0xa0; }              // Found @0xff9b23d4

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffba2bd0, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x04000000 // Found @0xffba2bf0, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 2, KEY_SHOOT_FULL      ,0x00000300 }, // Found @0xffba2b98, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000200 }, // Found @0xffba2b98, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000100 }, // Found @0xffba2b90, levent 0x00
//    { 2, KEY_MENU            ,0x00000001 }, // Found @0xffba2b50, levent 0x09
//    { 2, KEY_SET             ,0x00000002 }, // Found @0xffba2b58, levent 0x08
//    { 2, KEY_ZOOM_IN         ,0x00000004 }, // Found @0xffba2b60, levent 0x02
//    { 2, KEY_ZOOM_OUT        ,0x00000008 }, // Found @0xffba2b68, levent 0x03
//    { 2, KEY_LEFT            ,0x00000010 }, // Found @0xffba2b70, levent 0x06
//    { 2, KEY_RIGHT           ,0x00000020 }, // Found @0xffba2b78, levent 0x07
//    { 2, KEY_DOWN            ,0x00000040 }, // Found @0xffba2b80, levent 0x05
//    { 2, KEY_UP              ,0x00000080 }, // Found @0xffba2b88, levent 0x04
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    4168 // Found @0xff952bb4
//#define CAM_RAW_ROWS      3060 // Found @0xff952bc0
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff83c0f0

// Misc stuff
DEF(ctypes, 0xffba0102)

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
//NSTUB(AllocateMemory                        ,0xffaf24f4) //101            == 0xffaf24f4
//NSTUB(AllocateUncacheableMemory             ,0xff83c0a8) //112            == 0xff83c0a8
//NSTUB(Close                                 ,0xff8383e8) //101            == 0xff8383e8
//NSTUB(CreateTask                            ,0xff81e9b0) //101            == 0xff81e9b0
//NSTUB(DebugAssert                           ,0xff81ec88) //111            == 0xff81ec88
//NSTUB(DeleteFile_Fut                        ,0xff837d00) //112            == 0xff837d00
//NSTUB(DoAFLock                              ,0xff839c28) //102            == 0xff839c28
//NSTUB(EnterToCompensationEVF                ,0xff839e84) //104            == 0xff839e84
//NSTUB(ExecuteEventProcedure                 ,0xff8920f8) //  1            == 0xff8920f8
//NSTUB(ExitFromCompensationEVF               ,0xff839ec8) //104            == 0xff839ec8
//NSTUB(ExitTask                              ,0xff81ec40) //101            == 0xff81ec40
//NSTUB(ExpCtrlTool_StartContiAE              ,0xff848730) //104            == 0xff848730
//NSTUB(ExpCtrlTool_StopContiAE               ,0xff848808) //104            == 0xff848808
//NSTUB(Fclose_Fut                            ,0xff837e7c) //101            == 0xff837e7c
//NSTUB(Feof_Fut                              ,0xff838068) //  1            == 0xff838068
//NSTUB(Fflush_Fut                            ,0xff8380a4) //  1            == 0xff8380a4
//NSTUB(Fgets_Fut                             ,0xff837fd0) //  6            == 0xff837fd0
//NSTUB(Fopen_Fut                             ,0xff837e3c) //101            == 0xff837e3c
//NSTUB(Fread_Fut                             ,0xff837f28) //101            == 0xff837f28
//NSTUB(FreeMemory                            ,0xffaf24ec) //101            == 0xffaf24ec
//NSTUB(FreeUncacheableMemory                 ,0xff83c0e8) //112            == 0xff83c0e8
//NSTUB(Fseek_Fut                             ,0xff83801c) //101            == 0xff83801c
//NSTUB(Fwrite_Fut                            ,0xff837f7c) //101            == 0xff837f7c
//NSTUB(GetBatteryTemperature                 ,0xff868d7c) //102            == 0xff868d7c
//NSTUB(GetCCDTemperature                     ,0xff868d08) //102            == 0xff868d08
//NSTUB(GetCurrentAvValue                     ,0xff97cb48) //102            == 0xff97cb48
//NSTUB(GetDrive_ClusterSize                  ,0xff87630c) //  6            == 0xff87630c
//NSTUB(GetDrive_FreeClusters                 ,0xff876364) //  6            == 0xff876364
//NSTUB(GetDrive_TotalClusters                ,0xff87633c) //  6            == 0xff87633c
//NSTUB(GetFocusLensSubjectDistance           ,0xff97bbe4) //102            == 0xff97bbe4
//NSTUB(GetFocusLensSubjectDistanceFromLens   ,0xff97c044) //  3            == 0xff97c044
//NSTUB(GetImageFolder                        ,0xff959b4c) //  6            == 0xff959b4c
//NSTUB(GetKbdState                           ,0xff865558) //109            == 0xff865558
//NSTUB(GetMemInfo                            ,0xff81a29c) //  3            == 0xff81a29c
//NSTUB(GetOpticalTemperature                 ,0xff868df0) //102            == 0xff868df0
//NSTUB(GetParameterData                      ,0xff9b2394) //101            == 0xff9b2394
//NSTUB(GetPropertyCase                       ,0xff895e60) //102            == 0xff895e60
//NSTUB(GetSystemTime                         ,0xffaf254c) //101            == 0xffaf254c
//NSTUB(GetZoomLensCurrentPoint               ,0xff9801ec) //102            == 0xff9801ec
//NSTUB(GetZoomLensCurrentPosition            ,0xffadcc9c) //102            == 0xffadcc9c
//NSTUB(GiveSemaphore                         ,0xff83baa0) //112            == 0xff83baa0
//NSTUB(IsStrobeChargeCompleted               ,0xff8e8b94) //102            == 0xff8e8b94
//NSTUB(LEDDrive                              ,0xff864a7c) //101            == 0xff864a7c
//NSTUB(LocalTime                             ,0xff88f988) //  6            == 0xff88f988
//NSTUB(LockMainPower                         ,0xff89ad84) //103            == 0xff89ad84
//NSTUB(Lseek                                 ,0xff838604) //101            == 0xff838604
//NSTUB(MakeDirectory_Fut                     ,0xff837d74) //  6            == 0xff837d74
//NSTUB(MakeSDCardBootable                    ,0xff87659c) //105            == 0xff87659c
//NSTUB(MoveFocusLensToDistance               ,0xffb5a430) //102            == 0xffb5a430
//NSTUB(MoveIrisWithAv                        ,0xffaeecc4) //102            == 0xffaeecc4
//NSTUB(MoveZoomLensWithPoint                 ,0xffaef37c) //102            == 0xffaef37c
//NSTUB(NewTaskShell                          ,0xff8958a8) //101            == 0xff8958a8
//NSTUB(Open                                  ,0xff838320) //101            == 0xff838320
//NSTUB(PB2Rec                                ,0xff89dd28) //104            == 0xff89dd28
//NSTUB(PT_MoveDigitalZoomToWide              ,0xff87fbcc) //102            == 0xff87fbcc
//NSTUB(PT_MoveOpticalZoomAt                  ,0xff87fba4) //102            == 0xff87fba4
//NSTUB(PT_PlaySound                          ,0xff88a774) //  6            == 0xff88a774
//NSTUB(PostLogicalEventForNotPowerType       ,0xff89a540) //103            == 0xff89a540
//NSTUB(PostLogicalEventToUI                  ,0xff89a58c) //103            == 0xff89a58c
//NSTUB(PutInNdFilter                         ,0xffaef1c4) //102            == 0xffaef1c4
//NSTUB(PutOutNdFilter                        ,0xffaef1e8) //102            == 0xffaef1e8
//NSTUB(Read                                  ,0xff81ad58) //101            == 0xff81ad58
//NSTUB(ReadFastDir                           ,0xffaca2bc) //  6            == 0xffaca2bc
//NSTUB(Rec2PB                                ,0xff89dd68) //104            == 0xff89dd68
//NSTUB(RefreshPhysicalScreen                 ,0xff8b1da0) //104            == 0xff8b1da0
//NSTUB(Remove                                ,0xff83855c) //  6            == 0xff83855c
//NSTUB(RenameFile_Fut                        ,0xff837c6c) //  6            == 0xff837c6c
//NSTUB(Restart                               ,0xff83d8bc) //106            == 0xff83d8bc
//NSTUB(ScreenLock                            ,0xff8b2f98) //  4            == 0xff8b2f98
//NSTUB(ScreenUnlock                          ,0xff8b2ffc) //  3            == 0xff8b2ffc
NSTUB(SetAE_ShutterSpeed                      ,0xffb5d2ac) //102
//NSTUB(SetAutoShutdownTime                   ,0xff89adf8) //103            == 0xff89adf8
//NSTUB(SetCurrentCaptureModeType             ,0xff8a3510) //101            == 0xff8a3510
//NSTUB(SetFileTimeStamp                      ,0xff838774) //  6            == 0xff838774
//NSTUB(SetLogicalEventActive                 ,0xff89aaec) //101            == 0xff89aaec
//NSTUB(SetParameterData                      ,0xff9b2304) //101            == 0xff9b2304
//NSTUB(SetPropertyCase                       ,0xff895d44) //102            == 0xff895d44
//NSTUB(SetScriptMode                         ,0xff89ab3c) //101            == 0xff89ab3c
//NSTUB(SleepTask                             ,0xff83bd4c) //101            == 0xff83bd4c
//NSTUB(TakeSemaphore                         ,0xff83b9d0) //101            == 0xff83b9d0
//NSTUB(TurnOffBackLight                      ,0xff8aa31c) //104            == 0xff8aa31c
//NSTUB(TurnOnBackLight                       ,0xff8aa304) //104            == 0xff8aa304
//NSTUB(UIFS_WriteFirmInfoToFile              ,0xff9a2184) //101            == 0xff9a2184
//NSTUB(UnlockAF                              ,0xff839c60) //102            == 0xff839c60
//NSTUB(UnlockMainPower                       ,0xff89acd8) //103            == 0xff89acd8
//NSTUB(VbattGet                              ,0xff833050) //101            == 0xff833050
//NSTUB(Write                                 ,0xff83843c) //101            == 0xff83843c
//NSTUB(WriteSDCard                           ,0xff96b024) //108            == 0xff96b024
//NSTUB(_log                                  ,0xffb9cc28) //111            == 0xffb9cc28
//NSTUB(_log10                                ,0xffb9d168) //112            == 0xffb9d168
//NSTUB(_pow                                  ,0xffb9d2e0) //114            == 0xffb9d2e0
//NSTUB(_sqrt                                 ,0xffb9ef04) //  6            == 0xffb9ef04
//NSTUB(add_ptp_handler                       ,0xffa7be20) //  6            == 0xffa7be20
//NSTUB(apex2us                               ,0xffa3b18c) //  4            == 0xffa3b18c
//NSTUB(close                                 ,0xff81abb4) //  6            == 0xff81abb4
//NSTUB(closedir                              ,0xffaca118) //  4            == 0xffaca118
//NSTUB(err_init_task                         ,0xff815fd4) //  4            == 0xff815fd4
//NSTUB(exmem_alloc                           ,0xff890950) //101            == 0xff890950
//NSTUB(free                                  ,0xff814244) //112            == 0xff814244
//NSTUB(kbd_p1_f                              ,0xff834e94) //109            == 0xff834e94
//NSTUB(kbd_p1_f_cont                         ,0xff834ea0) //109            == 0xff834ea0
//NSTUB(kbd_p2_f                              ,0xff83468c) //109            == 0xff83468c
//NSTUB(kbd_read_keys                         ,0xff834e18) //109            == 0xff834e18
//NSTUB(kbd_read_keys_r2                      ,0xff864f74) //109            == 0xff864f74
//NSTUB(lseek                                 ,0xff838604) //101            == 0xff838604
//NSTUB(malloc                                ,0xff8141ec) //112            == 0xff8141ec
//NSTUB(memcmp                                ,0xff820934) //101            == 0xff820934
//NSTUB(memcpy                                ,0xff84179c) //101            == 0xff84179c
//NSTUB(memset                                ,0xffa3a18c) //101            == 0xffa3a18c
//NSTUB(mkdir                                 ,0xff838884) //  6            == 0xff838884
//NSTUB(mktime_ext                            ,0xff8b3e10) //  1            == 0xff8b3e10
//NSTUB(open                                  ,0xff81ab04) //  6            == 0xff81ab04
//NSTUB(opendir                               ,0xffaca168) //  6            == 0xffaca168
//NSTUB(openfastdir                           ,0xffaca168) //  6            == 0xffaca168
//NSTUB(qsort                                 ,0xffb3d684) //  6            == 0xffb3d684
//NSTUB(rand                                  ,0xffa3a2cc) //  6            == 0xffa3a2cc
//NSTUB(read                                  ,0xff81ad58) //101            == 0xff81ad58
//NSTUB(readfastdir                           ,0xffaca2bc) //  6            == 0xffaca2bc
//NSTUB(reboot_fw_update                      ,0xffacf758) //  6            == 0xffacf758
//NSTUB(rename                                ,0xff837c6c) //  6            == 0xff837c6c
//NSTUB(set_control_event                     ,0xff89a7b0) //111            == 0xff89a7b0
//NSTUB(srand                                 ,0xffa3a2c0) //  6            == 0xffa3a2c0
//NSTUB(stat                                  ,0xff83864c) //  3            == 0xff83864c
//NSTUB(strcat                                ,0xff8b35c8) //  1            == 0xff8b35c8
//NSTUB(strchr                                ,0xff8140b8) //  1            == 0xff8140b8
//NSTUB(strcmp                                ,0xff8208f0) //101            == 0xff8208f0
//NSTUB(strcpy                                ,0xff8208d8) //101            == 0xff8208d8
//NSTUB(strftime                              ,0xff8b3810) //113            == 0xff8b3810
//NSTUB(strlen                                ,0xff814104) //101            == 0xff814104
//NSTUB(strncmp                               ,0xff81406c) //  1            == 0xff81406c
//NSTUB(strncpy                               ,0xff814030) //  1            == 0xff814030
//NSTUB(strrchr                               ,0xff8140dc) //  1            == 0xff8140dc
//NSTUB(strtol                                ,0xff841a9c) //101            == 0xff841a9c
//NSTUB(strtolx                               ,0xff8418a0) //109            == 0xff8418a0
//  DEF(task_CaptSeq                          ,0xff882920) //110            == 0xff882920
//  DEF(task_ExpDrv                           ,0xff8cbcbc) //110            == 0xff8cbcbc
//  DEF(task_InitFileModules                  ,0xff89e66c) //110            == 0xff89e66c
//  DEF(task_MovieRecord                      ,0xff985e5c) //110            == 0xff985e5c
//  DEF(task_PhySw                            ,0xff8349b8) //110            == 0xff8349b8
//NSTUB(time                                  ,0xff88ff64) //  6            == 0xff88ff64
//NSTUB(vsprintf                              ,0xff820898) //  6            == 0xff820898
//NSTUB(write                                 ,0xff83843c) //101            == 0xff83843c
