// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R43 (DRYOS version 2.3, release #0043)
//   Firmware Ver GM1.00B
//   Canon PowerShot A3100 IS

// Values for makefile.inc
//   PLATFORMOSVER = 43
//   PLATFORMID = 12785 (0x31f1) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x03ffffff
//   KEYSYS = d4a                // Found @ 0xffff33e0
//   NEED_ENCODED_DISKBOOT = 4   // Found @ 0xffff33f0

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NSTUB(GetDrive_FreeClusters                 ,0xff8339b8) //  3        *** != 0xff863190
// ALT: NSTUB(GetDrive_FreeClusters, 0xff863190) // 4 9/0
//NSTUB(kbd_pwr_off                           ,0xff85471c) //  2 64%    *** != 0x00000000
NSTUB(kbd_pwr_on                              ,0xff8546dc) //  2 82%

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff886634 -> ff882e74 -> ff9557a4 -> ffa57d00 -> ffb44950
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00030114) // Found @0xff833cd4
DEF(physw_run                               ,0x00001bf0) // Found @0xff833938
DEF(physw_sleep_delay                       ,0x00001bf8) // Found @0xff833938
DEF(levent_table                            ,0xffafa8a0) // Found @0xffafa8a0
DEF(FlashParamsTable                        ,0xffb44b48) // Found @0xffb44b48
DEF(movie_status                            ,0x00005908) // Found @0xff92d998
DEF(full_screen_refresh                     ,0x00007e5c) // Found @0xff9b2920
DEF(canon_menu_active                       ,0x00002ba8) // Found @0xff87ec84
DEF(canon_shoot_menu_active                 ,0x00006c15) // Found @0xff967ef8
DEF(playrec_mode                            ,0x000028f0) // Found @0xff871ef4
DEF(zoom_status                             ,0x0000a9b0) // Found @0xffa5b1ec
DEF(some_flag_for_af_scan                   ,0x00005cb8) // Found @0xff930790
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 8 entries in the table - set NUM_FL to 8
DEF(focus_len_table                         ,0xfffe29b0) // Found @0xfffe29b0
DEF(zoom_busy                               ,0x0000585c) // Found @0xff929aa4
DEF(focus_busy                              ,0x00005700) // Found @0xff9254d0
DEF(recreview_hold                          ,0x000031e0) // Found @0xff88bb74

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x103e1000; }             // Found @0xff84fdfc
//void *vid_get_viewport_fb()      { return (void*)0x106f3bc0; }             // Found @0xffaaa9c4
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2630+0x54)); } // Found @0xff8647ac & 0xff8647d8
//char *camera_jpeg_count_str()    { return (char*)0x00076b3c; }             // Found @0xff9a9124
//long hook_raw_size()             { return 0x011ca240; }                    // Found @0xffaadd50
//int get_flash_params_count(void) { return 0x94; }                          // Found @0xff956860

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffad99bc, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00040000 // Found @0xffad99c8, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 1, KEY_POWER           ,0x00000400 }, // Found @0xffad98b4, levent 0x600
//    { 1, KEY_PLAYBACK        ,0x20000000 }, // Found @0xffad98cc, levent 0x601
//    { 2, KEY_SHOOT_FULL      ,0x00000003 }, // Found @0xffad98fc, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000002 }, // Found @0xffad98fc, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000001 }, // Found @0xffad98f0, levent 0x00
//    { 2, KEY_ZOOM_IN         ,0x00000004 }, // Found @0xffad9908, levent 0x02
//    { 2, KEY_ZOOM_OUT        ,0x00000008 }, // Found @0xffad9914, levent 0x03
//    { 2, KEY_UP              ,0x00000010 }, // Found @0xffad9920, levent 0x04
//    { 2, KEY_DOWN            ,0x00000020 }, // Found @0xffad992c, levent 0x05
//    { 2, KEY_RIGHT           ,0x00000040 }, // Found @0xffad9938, levent 0x07
//    { 2, KEY_LEFT            ,0x00000080 }, // Found @0xffad9944, levent 0x06
//    { 2, KEY_SET             ,0x00000100 }, // Found @0xffad9950, levent 0x08
//    { 2, KEY_MENU            ,0x00000200 }, // Found @0xffad995c, levent 0x09
//    { 2, KEY_DISPLAY         ,0x00000400 }, // Found @0xffad9968, levent 0x0a
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
DEF(ctypes, 0xffad91d2)

// For capt_seq.c
//static long *nrflag = (long*)(0x5ca0-0x08);  // Found @ ff93271c & ff932738

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NSTUB(AllocateMemory                          ,0xffa471dc) //101
NSTUB(AllocateUncacheableMemory               ,0xff8397a4) //112
NSTUB(Close                                   ,0xff8362b8) //101
NSTUB(CreateTask                              ,0xff81f110) //101
NSTUB(DebugAssert                             ,0xff81f5e8) //111
NSTUB(DeleteDirectory_Fut                     ,0xff835d14) //  1
NSTUB(DeleteFile_Fut                          ,0xff835c30) //112
NSTUB(DoAFLock                                ,0xff837744) //102
NSTUB(EnterToCompensationEVF                  ,0xff8377f4) //104
NSTUB(ExecuteEventProcedure                   ,0xff87a3a0) //  2
NSTUB(ExitFromCompensationEVF                 ,0xff837838) //104
NSTUB(ExitTask                                ,0xff81f3a0) //101
NSTUB(ExpCtrlTool_StartContiAE                ,0xff8452e8) //104
NSTUB(ExpCtrlTool_StopContiAE                 ,0xff8453c0) //104
NSTUB(Fclose_Fut                              ,0xff835dac) //101
NSTUB(Feof_Fut                                ,0xff835f98) //  1
NSTUB(Fflush_Fut                              ,0xff835fd4) //  1
NSTUB(Fgets_Fut                               ,0xff835f00) //  1
NSTUB(Fopen_Fut                               ,0xff835d6c) //101
NSTUB(Fread_Fut                               ,0xff835e58) //101
NSTUB(FreeMemory                              ,0xffa471d4) //101
NSTUB(FreeUncacheableMemory                   ,0xff8397e4) //112
NSTUB(Fseek_Fut                               ,0xff835f4c) //101
NSTUB(Fwrite_Fut                              ,0xff835eac) //101
NSTUB(GetBatteryTemperature                   ,0xff8567fc) //102
NSTUB(GetCCDTemperature                       ,0xff856788) //102
NSTUB(GetCurrentAvValue                       ,0xff926d50) //102
NSTUB(GetDrive_ClusterSize                    ,0xff863130) //  4
NSTUB(GetDrive_TotalClusters                  ,0xff863164) //  3
NSTUB(GetFocusLensSubjectDistance             ,0xff926048) //102
NSTUB(GetFocusLensSubjectDistanceFromLens     ,0xff9264a0) //  3
NSTUB(GetImageFolder                          ,0xff90c4b4) //106
NSTUB(GetKbdState                             ,0xff8546a8) //109
NSTUB(GetMemInfo                              ,0xff81a760) //  3
NSTUB(GetOpticalTemperature                   ,0xff856870) //102
NSTUB(GetParameterData                        ,0xff956820) //101
NSTUB(GetPropertyCase                         ,0xff87e0ac) //102
NSTUB(GetSystemTime                           ,0xffa47234) //101
NSTUB(GetVRAMHPixelsSize                      ,0xff8d015c) //102
NSTUB(GetVRAMVPixelsSize                      ,0xff8d0168) //102
NSTUB(GetZoomLensCurrentPoint                 ,0xff929e1c) //102
NSTUB(GetZoomLensCurrentPosition              ,0xffa37bc4) //102
NSTUB(GiveSemaphore                           ,0xff81f06c) //112
NSTUB(IsStrobeChargeCompleted                 ,0xff8c04f8) //102
NSTUB(LEDDrive                                ,0xff853b80) //103
NSTUB(LocalTime                               ,0xff877e10) //115
NSTUB(LockMainPower                           ,0xff882a7c) //103
NSTUB(Lseek                                   ,0xff8363d4) //101
NSTUB(MakeDirectory_Fut                       ,0xff835ca4) //116
NSTUB(MoveFocusLensToDistance                 ,0xffaa7438) //102
NSTUB(MoveIrisWithAv                          ,0xffa438cc) //102
NSTUB(MoveZoomLensWithPoint                   ,0xffa43e5c) //102
NSTUB(NewTaskShell                            ,0xff87dab8) //103
NSTUB(Open                                    ,0xff83624c) //101
NSTUB(PB2Rec                                  ,0xff885af4) //104
NSTUB(PT_MoveDigitalZoomToWide                ,0xff86b22c) //102
NSTUB(PT_MoveOpticalZoomAt                    ,0xff86b204) //102
NSTUB(PT_PlaySound                            ,0xff873af0) //  7
NSTUB(PostLogicalEventForNotPowerType         ,0xff8822ac) //103
NSTUB(PostLogicalEventToUI                    ,0xff8822f8) //103
NSTUB(PutInNdFilter                           ,0xffa43cc0) //102
NSTUB(PutOutNdFilter                          ,0xffa43ce4) //102
NSTUB(Read                                    ,0xff81b270) //101
NSTUB(ReadFastDir                             ,0xffa2d1fc) //  4
NSTUB(Rec2PB                                  ,0xff885b34) //104
NSTUB(RefreshPhysicalScreen                   ,0xff9b3304) //104
NSTUB(Remove                                  ,0xff8362ec) //  4
NSTUB(RenameFile_Fut                          ,0xff835b9c) //  4
NSTUB(Restart                                 ,0xff83af88) //106
NSTUB(ScreenLock                              ,0xff9b44c4) //  3
NSTUB(ScreenUnlock                            ,0xff9b4508) //  7
NSTUB(SetAE_ShutterSpeed                      ,0xffaa9bd4) //102
NSTUB(SetAutoShutdownTime                     ,0xff882af0) //103
NSTUB(SetCurrentCaptureModeType               ,0xff88948c) //101
NSTUB(SetFileAttributes                       ,0xff8365b0) //  3
NSTUB(SetFileTimeStamp                        ,0xff836554) //  4
NSTUB(SetLogicalEventActive                   ,0xff8827f4) //101
NSTUB(SetParameterData                        ,0xff956790) //101
NSTUB(SetPropertyCase                         ,0xff87df7c) //102
NSTUB(SetScriptMode                           ,0xff882844) //101
NSTUB(SleepTask                               ,0xff839628) //101
NSTUB(TakeSemaphore                           ,0xff81ef9c) //101
NSTUB(TurnOffBackLight                        ,0xff88e2f8) //104
NSTUB(TurnOnBackLight                         ,0xff88e2e0) //104
NSTUB(UIFS_WriteFirmInfoToFile                ,0xff944cac) //103
NSTUB(UnlockAF                                ,0xff83777c) //102
NSTUB(UnlockMainPower                         ,0xff8829d0) //103
NSTUB(UnsetZoomForMovie                       ,0xff95c778) //104
NSTUB(UpdateMBROnFlash                        ,0xff862fb0) //105
NSTUB(VbattGet                                ,0xff832cf0) //103
NSTUB(Write                                   ,0xff836348) //101
NSTUB(WriteSDCard                             ,0xff919788) //108
NSTUB(_log                                    ,0xffad6c94) //111
NSTUB(_log10                                  ,0xffad5bd8) //112
NSTUB(_pow                                    ,0xffad5d48) //114
NSTUB(_sqrt                                   ,0xffad7ffc) //  1
NSTUB(add_ptp_handler                         ,0xff9f670c) //  3
NSTUB(apex2us                                 ,0xff9b582c) //  4
NSTUB(close                                   ,0xff81b088) //  1
NSTUB(closedir                                ,0xffa2d058) //  4
NSTUB(err_init_task                           ,0xff815f50) //  4
NSTUB(exmem_alloc                             ,0xff878d50) //103
NSTUB(free                                    ,0xff814160) //112
NSTUB(kbd_p1_f                                ,0xff833d54) //109
NSTUB(kbd_p1_f_cont                           ,0xff833d60) //109
NSTUB(kbd_p2_f                                ,0xff833604) //109
NSTUB(kbd_read_keys                           ,0xff833cd4) //109
NSTUB(kbd_read_keys_r2                        ,0xff854028) //109
NSTUB(lseek                                   ,0xff8363d4) //101
NSTUB(malloc                                  ,0xff814104) //112
NSTUB(memcmp                                  ,0xff821280) //101
NSTUB(memcpy                                  ,0xff83ee14) //101
NSTUB(memset                                  ,0xff9b4864) //101
NSTUB(mkdir                                   ,0xff836754) //109
NSTUB(mktime_ext                              ,0xff895a30) //  1
NSTUB(open                                    ,0xff81afd8) //  1
NSTUB(opendir                                 ,0xffa2d0a8) //  4
NSTUB(openfastdir                             ,0xffa2d0a8) //  4
NSTUB(qsort                                   ,0xffa8df60) //  4
NSTUB(rand                                    ,0xff821388) //  1
NSTUB(read                                    ,0xff81b270) //101
NSTUB(reboot_fw_update                        ,0xffa2ea70) //106
NSTUB(rename                                  ,0xff835b9c) //  4
NSTUB(set_control_event                       ,0xff882514) //111
NSTUB(srand                                   ,0xff82137c) //  1
NSTUB(stat                                    ,0xff83641c) //  3
NSTUB(strcat                                  ,0xff8951ec) //  1
NSTUB(strchr                                  ,0xff813fe8) //  1
NSTUB(strcmp                                  ,0xff82123c) //101
NSTUB(strcpy                                  ,0xff821224) //101
NSTUB(strftime                                ,0xff895438) //113
NSTUB(strlen                                  ,0xff814034) //101
NSTUB(strncmp                                 ,0xff813f9c) //  1
NSTUB(strncpy                                 ,0xff813f60) //  1
NSTUB(strrchr                                 ,0xff81400c) //  1
NSTUB(strtol                                  ,0xff83f0f4) //101
NSTUB(strtolx                                 ,0xff83eef8) //109
  DEF(task_CaptSeq                            ,0xff86d6f0) //107
  DEF(task_ExpDrv                             ,0xff8aa798) //110
  DEF(task_InitFileModules                    ,0xff8864c0) //107
  DEF(task_MovieRecord                        ,0xff92dbec) //107
  DEF(task_PhySw                              ,0xff833934) //107
NSTUB(time                                    ,0xff8783f0) //  2
NSTUB(vsprintf                                ,0xff8211e8) //  4
NSTUB(write                                   ,0xff836348) //101
