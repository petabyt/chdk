// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R43 (DRYOS version 2.3, release #0043)
//   Firmware Ver GM1.00D
//   Canon PowerShot A3100 IS

// Values for makefile.inc
//   PLATFORMOSVER = 43
//   PLATFORMID = 12785 (0x31f1) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x03ffffff
//   KEYSYS = d4a                // Found @ 0xffff33e0
//   NEED_ENCODED_DISKBOOT = 4   // Found @ 0xffff33f0

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NHSTUB(kbd_pwr_off                          ,0xff85471c) //  2 64%    *** != 0x00000000
NHSTUB(kbd_pwr_on                             ,0xff8546dc) //  2 82%

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff886634 -> ff882e74 -> ff9557a4 -> ffa57c54 -> ffb448a4
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00030114) // Found @0xff833cd4
DEF(physw_run                               ,0x00001bf0) // Found @0xff833938
DEF(physw_sleep_delay                       ,0x00001bf8) // Found @0xff833938
DEF(levent_table                            ,0xffafa7f4) // Found @0xffafa7f4
DEF(FlashParamsTable                        ,0xffb44a9c) // Found @0xffb44a9c
DEF(movie_status                            ,0x00005908) // Found @0xff92d998
DEF(full_screen_refresh                     ,0x00007e5c) // Found @0xff9b2920
DEF(canon_menu_active                       ,0x00002ba8) // Found @0xff87ec84
DEF(canon_shoot_menu_active                 ,0x00006c15) // Found @0xff967ef8
DEF(playrec_mode                            ,0x000028f0) // Found @0xff871ef4
DEF(zoom_status                             ,0x0000a9b0) // Found @0xffa5b140
DEF(some_flag_for_af_scan                   ,0x00005cb8) // Found @0xff930790
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 8 entries in the table - set NUM_FL to 8
DEF(focus_len_table                         ,0xfffe29b0) // Found @0xfffe29b0
DEF(zoom_busy                               ,0x0000585c) // Found @0xff929aa4
DEF(focus_busy                              ,0x00005700) // Found @0xff9254d0
DEF(recreview_hold                          ,0x000031e0) // Found @0xff88bb74
DEF(viewport_buffers                        ,0xffae1384) // Found @0xff8cecc4
DEF(active_viewport_buffer                  ,0x0000437c) // Found @0xff8ceb0c

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x103e1000; }             // Found @0xff84fdfc
//void *vid_get_viewport_fb()      { return (void*)0x106f3bc0; }             // Found @0xffaaa918
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2630+0x54)); } // Found @0xff8647ac & 0xff8647d8
//char *camera_jpeg_count_str()    { return (char*)0x00076b3c; }             // Found @0xff9a9124
//long hook_raw_size()             { return 0x011ca240; }                    // Found @0xffaadca4
//int get_flash_params_count(void) { return 0x94; }                          // Found @0xff956860

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffad9910, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00040000 // Found @0xffad991c, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 1, KEY_POWER           ,0x00000400 }, // Found @0xffad9808, levent 0x600
//    { 1, KEY_PLAYBACK        ,0x20000000 }, // Found @0xffad9820, levent 0x601
//    { 2, KEY_SHOOT_FULL      ,0x00000003 }, // Found @0xffad9850, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000002 }, // Found @0xffad9850, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000001 }, // Found @0xffad9844, levent 0x00
//    { 2, KEY_ZOOM_IN         ,0x00000004 }, // Found @0xffad985c, levent 0x02
//    { 2, KEY_ZOOM_OUT        ,0x00000008 }, // Found @0xffad9868, levent 0x03
//    { 2, KEY_UP              ,0x00000010 }, // Found @0xffad9874, levent 0x04
//    { 2, KEY_DOWN            ,0x00000020 }, // Found @0xffad9880, levent 0x05
//    { 2, KEY_RIGHT           ,0x00000040 }, // Found @0xffad988c, levent 0x07
//    { 2, KEY_LEFT            ,0x00000080 }, // Found @0xffad9898, levent 0x06
//    { 2, KEY_SET             ,0x00000100 }, // Found @0xffad98a4, levent 0x08
//    { 2, KEY_MENU            ,0x00000200 }, // Found @0xffad98b0, levent 0x09
//    { 2, KEY_DISPLAY         ,0x00000400 }, // Found @0xffad98bc, levent 0x0a
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_RAW_ROWPIX    4080 // Found @0xff905530
//#define CAM_RAW_ROWS      3048 // Found @0xff905538
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x10000000 // Found @0xff8397e8

// Misc stuff
DEF(ctypes, 0xffad9126)

// For capt_seq.c
DEF(_nrflag,0x5c98) // Found @ ff93271c (0x5ca0) & ff93273c (-0x08)
//static long *nrflag = (long*)(0x5ca0-0x08);  // Found @ ff93271c & ff932738

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
//NHSTUB(CreateJumptable                      ,0xffaae6dc) //  1
//NHSTUB(_uartr_req                           ,0xff8206ac) //111
//NHSTUB(AllocateMemory                       ,0xffa47130) //101
NHSTUB(AllocateUncacheableMemory              ,0xff8397a4) //112
NHSTUB(Close                                  ,0xff8362b8) //101
NHSTUB(CreateTask                             ,0xff81f110) //101
NHSTUB(DebugAssert                            ,0xff81f5e8) //111
NHSTUB(DeleteDirectory_Fut                    ,0xff835d14) //116
NHSTUB(DeleteFile_Fut                         ,0xff835c30) //112
NHSTUB(DoAFLock                               ,0xff837744) //102
NHSTUB(EnterToCompensationEVF                 ,0xff8377f4) //104
NHSTUB(ExecuteEventProcedure                  ,0xff87a3a0) //104
NHSTUB(ExitFromCompensationEVF                ,0xff837838) //104
NHSTUB(ExitTask                               ,0xff81f3a0) //101
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff8452e8) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff8453c0) //104
NHSTUB(Fclose_Fut                             ,0xff835dac) //101
NHSTUB(Feof_Fut                               ,0xff835f98) //  1
NHSTUB(Fflush_Fut                             ,0xff835fd4) //  1
NHSTUB(Fgets_Fut                              ,0xff835f00) //  1
NHSTUB(Fopen_Fut                              ,0xff835d6c) //101
NHSTUB(Fread_Fut                              ,0xff835e58) //101
//NHSTUB(FreeMemory                           ,0xffa47128) //101
NHSTUB(FreeUncacheableMemory                  ,0xff8397e4) //112
NHSTUB(Fseek_Fut                              ,0xff835f4c) //101
NHSTUB(Fwrite_Fut                             ,0xff835eac) //101
NHSTUB(GetBatteryTemperature                  ,0xff8567fc) //102
NHSTUB(GetCCDTemperature                      ,0xff856788) //102
NHSTUB(GetCurrentAvValue                      ,0xff926d50) //102
NHSTUB(GetDrive_ClusterSize                   ,0xff863130) //  4
//NHSTUB(GetDrive_FreeClusters                ,0xff863190) //  4            == 0xff863190
NHSTUB(GetDrive_TotalClusters                 ,0xff863164) //  3
NHSTUB(GetFocusLensSubjectDistance            ,0xff926048) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff9264a0) //  3
NHSTUB(GetImageFolder                         ,0xff90c4b4) //106
NHSTUB(GetKbdState                            ,0xff8546a8) //109
NHSTUB(GetMemInfo                             ,0xff81a760) //115
NHSTUB(GetOpticalTemperature                  ,0xff856870) //102
NHSTUB(GetParameterData                       ,0xff956820) //101
NHSTUB(GetPropertyCase                        ,0xff87e0ac) //102
NHSTUB(GetSystemTime                          ,0xffa47188) //101
NHSTUB(GetVRAMHPixelsSize                     ,0xff8d015c) //102
NHSTUB(GetVRAMVPixelsSize                     ,0xff8d0168) //102
NHSTUB(GetZoomLensCurrentPoint                ,0xff929e1c) //102
NHSTUB(GetZoomLensCurrentPosition             ,0xffa37b18) //102
NHSTUB(GiveSemaphore                          ,0xff81f06c) //112
NHSTUB(IsStrobeChargeCompleted                ,0xff8c04f8) //102
NHSTUB(LEDDrive                               ,0xff853b80) //103
NHSTUB(LocalTime                              ,0xff877e10) //115
NHSTUB(LockMainPower                          ,0xff882a7c) //103
//NHSTUB(Lseek                                ,0xff8363d4) //101
NHSTUB(MakeDirectory_Fut                      ,0xff835ca4) //116
NHSTUB(MoveFocusLensToDistance                ,0xffaa738c) //102
NHSTUB(MoveIrisWithAv                         ,0xffa43820) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xffa43db0) //102
//NHSTUB(NewTaskShell                         ,0xff87dab8) //103
NHSTUB(Open                                   ,0xff83624c) //101
NHSTUB(PB2Rec                                 ,0xff885af4) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff86b22c) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff86b204) //102
NHSTUB(PT_PlaySound                           ,0xff873af0) //  7
NHSTUB(PostLogicalEventForNotPowerType        ,0xff8822ac) //103
NHSTUB(PostLogicalEventToUI                   ,0xff8822f8) //103
NHSTUB(PutInNdFilter                          ,0xffa43c14) //102
NHSTUB(PutOutNdFilter                         ,0xffa43c38) //102
NHSTUB(Read                                   ,0xff81b270) //101
NHSTUB(ReadFastDir                            ,0xffa2d150) //  4
NHSTUB(Rec2PB                                 ,0xff885b34) //104
NHSTUB(RefreshPhysicalScreen                  ,0xff9b3304) //104
//NHSTUB(Remove                               ,0xff8362ec) //  4
NHSTUB(RenameFile_Fut                         ,0xff835b9c) //116
NHSTUB(Restart                                ,0xff83af88) //106
NHSTUB(ScreenLock                             ,0xff9b44c4) //  3
NHSTUB(ScreenUnlock                           ,0xff9b4508) //  7
NHSTUB(SetAE_ShutterSpeed                     ,0xffaa9b28) //102
NHSTUB(SetAutoShutdownTime                    ,0xff882af0) //103
NHSTUB(SetCurrentCaptureModeType              ,0xff88948c) //101
NHSTUB(SetFileAttributes                      ,0xff8365b0) //  3
NHSTUB(SetFileTimeStamp                       ,0xff836554) //  4
NHSTUB(SetLogicalEventActive                  ,0xff8827f4) //101
NHSTUB(SetParameterData                       ,0xff956790) //101
NHSTUB(SetPropertyCase                        ,0xff87df7c) //102
NHSTUB(SetScriptMode                          ,0xff882844) //101
NHSTUB(SleepTask                              ,0xff839628) //101
NHSTUB(TakeSemaphore                          ,0xff81ef9c) //101
NHSTUB(TurnOffBackLight                       ,0xff88e2f8) //104
NHSTUB(TurnOnBackLight                        ,0xff88e2e0) //104
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff944cac) //103
NHSTUB(UnlockAF                               ,0xff83777c) //102
NHSTUB(UnlockMainPower                        ,0xff8829d0) //103
NHSTUB(UnsetZoomForMovie                      ,0xff95c778) //104
NHSTUB(UpdateMBROnFlash                       ,0xff862fb0) //105
NHSTUB(VbattGet                               ,0xff832cf0) //103
NHSTUB(Write                                  ,0xff836348) //101
NHSTUB(WriteSDCard                            ,0xff919788) //108
NHSTUB(_log                                   ,0xffad6be8) //111
NHSTUB(_log10                                 ,0xffad5b2c) //112
NHSTUB(_pow                                   ,0xffad5c9c) //114
NHSTUB(_sqrt                                  ,0xffad7f50) //  1
NHSTUB(add_ptp_handler                        ,0xff9f6660) //  3
NHSTUB(apex2us                                ,0xff9b582c) //  4
NHSTUB(close                                  ,0xff81b088) //  1
NHSTUB(closedir                               ,0xffa2cfac) //  4
NHSTUB(err_init_task                          ,0xff815f50) //111
NHSTUB(exmem_alloc                            ,0xff878d50) //103
NHSTUB(exmem_free                             ,0xff878dc8) //103
NHSTUB(free                                   ,0xff814160) //112
NHSTUB(kbd_p1_f                               ,0xff833d54) //109
NHSTUB(kbd_p1_f_cont                          ,0xff833d60) //109
NHSTUB(kbd_p2_f                               ,0xff833604) //109
NHSTUB(kbd_read_keys                          ,0xff833cd4) //109
NHSTUB(kbd_read_keys_r2                       ,0xff854028) //109
NHSTUB(lseek                                  ,0xff8363d4) //101
NHSTUB(malloc                                 ,0xff814104) //112
NHSTUB(memcmp                                 ,0xff821280) //101
NHSTUB(memcpy                                 ,0xff83ee14) //101
NHSTUB(memset                                 ,0xff9b4864) //101
NHSTUB(mkdir                                  ,0xff836754) //109
NHSTUB(mktime_ext                             ,0xff895a30) //  1
NHSTUB(open                                   ,0xff81afd8) //  1
NHSTUB(OpenFastDir                            ,0xffa2cffc) //  4
NHSTUB(qsort                                  ,0xffa8deb4) //  4
NHSTUB(rand                                   ,0xff821388) //  1
//NHSTUB(read                                 ,0xff81b270) //101
NHSTUB(realloc                                ,0xff9b48e0) //115
NHSTUB(reboot_fw_update                       ,0xffa2e9c4) //106
NHSTUB(set_control_event                      ,0xff882514) //111
NHSTUB(srand                                  ,0xff82137c) //  1
NHSTUB(stat                                   ,0xff83641c) //109
NHSTUB(strcat                                 ,0xff8951ec) //  1
NHSTUB(strchr                                 ,0xff813fe8) //  1
NHSTUB(strcmp                                 ,0xff82123c) //101
NHSTUB(strcpy                                 ,0xff821224) //101
NHSTUB(strftime                               ,0xff895438) //113
NHSTUB(strlen                                 ,0xff814034) //101
NHSTUB(strncmp                                ,0xff813f9c) //  1
NHSTUB(strncpy                                ,0xff813f60) //  1
NHSTUB(strrchr                                ,0xff81400c) //  1
NHSTUB(strtol                                 ,0xff83f0f4) //101
NHSTUB(strtolx                                ,0xff83eef8) //109
   DEF(task_CaptSeq                           ,0xff86d6f0) //107
   DEF(task_ExpDrv                            ,0xff8aa798) //110
   DEF(task_FileWrite                         ,0xffa27c28) //107
   DEF(task_InitFileModules                   ,0xff8864c0) //107
   DEF(task_MovieRecord                       ,0xff92dbec) //107
   DEF(task_PhySw                             ,0xff833934) //107
NHSTUB(time                                   ,0xff8783f0) //109
NHSTUB(vsprintf                               ,0xff8211e8) //115
//NHSTUB(write                                ,0xff836348) //101
//NHSTUB(EngDrvIn                             ,0xff834ba0) //102
//NHSTUB(EngDrvOut                            ,0xff834b88) //102
//NHSTUB(EngDrvRead                           ,0xff834ba8) //102
//NHSTUB(EngDrvBits                           ,0xff834bbc) //102
//NHSTUB(GetSDProtect                         ,0xff833ca8) //103
//NHSTUB(StartRecModeMenu                     ,0xff87ec80) //102
//NHSTUB(DispCon_ShowBitmapColorBar           ,0xff84fdc8) //102
//NHSTUB(ResetZoomLens                        ,0xffa43d04) //102
//NHSTUB(ResetFocusLens                       ,0xffa42d00) //102
//NHSTUB(NR_GetDarkSubType                    ,0xff933a28) //102
//NHSTUB(NR_SetDarkSubType                    ,0xff933978) //102
//NHSTUB(SavePaletteData                      ,0xffaabdcc) //102
//NHSTUB(GUISrv_StartGUISystem                ,0xff894c24) //101
