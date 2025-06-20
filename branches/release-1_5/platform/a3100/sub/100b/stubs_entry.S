// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R43 (DRYOS version 2.3, release #0043)
//   Firmware Ver GM1.00B   // Found @ 0xff87d108, "GM1.00B" @ 0xff87d115
//   Firmware build timestamp: Jan  7 2010 13:52:57
//   Canon PowerShot A3100 IS

// Values for makefile.inc
//   DIGIC = 30# DIGIC III
//   PLATFORMOSVER = 43
//   PLATFORMID = 12785# (0x31f1) Found @ 0xfffe0130
//   MAXRAMADDR = 0x03ffffff
//   MEMISOSTART = 0x001488e0
//   KEYSYS = d4a# Found @ 0xffff33e0
//   NEED_ENCODED_DISKBOOT = 4# Found @ 0xffff33f0
//   ARAM_HEAP_START = 0x34e000# Found @ 0xff93a534
//   ARAM_HEAP_SIZE  = 0x32000# Found @ 0xff93a4f4

// Detected address ranges:
// ROM      0xff810000 - 0xffffffff (8323072 bytes)
// RAM data 0x00001900 - 0x0000c4c8 copied from 0xffb65704 (  43976 bytes)

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NHSTUB(kbd_pwr_off                          ,0xff85471c) //  2 64%    *** != 0xff85472c
NHSTUB(kbd_pwr_on                             ,0xff8546dc) //  2 82%

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ffa57d00 -> ffb44950
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
DEF(viewport_buffers                        ,0xffae1430) // Found @0xff8cecc4
DEF(active_viewport_buffer                  ,0x0000437c) // Found @0xff8ceb0c
// Camera appears to have only 1 RAW buffer @ 0x110b7260 (Found @0xffaadcf4)
DEF(fileio_semaphore                        ,0x000025dc) // Found @0xff86162c
DEF(exmem_alloc_table                       ,0x00035da0) // Found @0xff878754
DEF(exmem_types_table                       ,0xffb667fc) // Found @0x000029f8
DEF_CONST(exmem_type_count                  ,0x00000012)
DEF(imager_active                           ,0x00001ecc) // Found @0xff8487ec (0x1ec8 + 4)
DEF_CONST(uiprop_count                      ,0x00000074) // Found @0xff955e1c

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x103e1000; }             // Found @0xff84fdfc
//void *vid_get_viewport_fb()      { return (void*)0x106f3bc0; }             // Found @0xffaaa9c4
DEF(viewport_fb_d                           ,0x00002684) // Found 0x2630 (@0xff8647ac) + 0x54 (@0xff8647d8)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2630+0x54)); } // Found @0xff8647ac & 0xff8647d8
DEF(jpeg_count_str                          ,0x00076b3c) // Found @0xff9a9124
//char *camera_jpeg_count_str()    { return (char*)0x00076b3c; }             // Found @0xff9a9124
//int get_flash_params_count(void) { return 0x94; }                          // Found @0xff956860

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffad99bc, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00040000 // Found @0xffad99c8, levent 0x902
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x00008000 // Found @0xffad99a4, levent 0x905
//#define BATTCOVER_IDX       2
//#define ANALOG_AV_FLAG      0x10000000 // Found @0xffad98c0, levent 0x900 (non-inverted logic)
//#define ANALOG_AV_IDX       1

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
//#define CAM_DATE_FOLDER_NAMING 0x100 // Found @0xffa1729c (pass as 3rd param to GetImageFolder)
//#define PARAM_CAMERA_NAME 4 // Found @0xffb46dac

// Below goes in 'filewrite.c' or 'platform_camera.h':
//#define MAX_CHUNKS_FOR_FWT 4 // Found @0xffa27d3c

// Known propcases
// //      PROPCASE_AFSTEP 13
// #define PROPCASE_FOCUS_STATE 18
// #define PROPCASE_AV 23
// #define PROPCASE_BV 34
// //      PROPCASE_DELTA_DIGITALGAIN 77
// #define PROPCASE_DELTA_SV 79
// //      PROPCASE_DELTA_ND 80
// #define PROPCASE_EV_CORRECTION_2 209
// #define PROPCASE_ORIENTATION_SENSOR 221
// #define PROPCASE_SV_MARKET 248
// //      PROPCASE_SVFIX 249
// #define PROPCASE_TV 264
// Guessed propset: 3

// Misc stuff
DEF(ctypes, 0xffad91d2)

// EXMEM types:
// EXMEM_RAMDISK        0
// EXMEM_COM            1
// EXMEM_FORMATTER      2
// EXMEM_SHADING        3
// EXMEM_FAMODE         4
// EXMEM_FIRMUP         5
// EXMEM_FIRMUP_VRAM    6
// EXMEM_FIRMUP_INFLATE 7
// EXMEM_DVLPWORK       8
// EXMEM_EVF            9
// EXMEM_SCRIPT         10
// EXMEM_FILESTORE      11
// EXMEM_MOVIE_REC      12
// EXMEM_MOVIE_PLY      13
// EXMEM_WIDE           14
// EXMEM_NARROW         15
// EXMEM_CRAW_REC       16
// EXMEM_PCEVF          17

// ISR flag: 0x1964, pointer to current task's control block: 0x1960
// pointer to TCB area: 0x19f4, found @ 0xff816efc

// LED table init @ 0xff8ecad0
// LED #1: 0xc0220010, offset 0x170
// LED #2: 0xc0220008, offset 0x1d8

// For capt_seq.c
DEF(_nrflag,0x5c98) // Found @ ff93271c (0x5ca0) & ff93273c (-0x08)
//static long *nrflag = (long*)(0x5ca0-0x08);  // Found @ ff93271c & ff932738

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NHSTUB(AllocateUncacheableMemory              ,0xff8397a4) //112
NHSTUB(Close                                  ,0xff8362b8) //120
NHSTUB(CreateBinarySemaphore                  ,0xff81ee30) //115
NHSTUB(CreateTask                             ,0xff81f110) //120
NHSTUB(DebugAssert                            ,0xff81f5e8) //107
NHSTUB(DeleteDirectory_Fut                    ,0xff835d14) //116
NHSTUB(DeleteFile_Fut                         ,0xff835c30) //112
NHSTUB(DoAELock                               ,0xff83788c) //120
NHSTUB(DoAFLock                               ,0xff837744) //120
NHSTUB(EnterToCompensationEVF                 ,0xff8377f4) //104
NHSTUB(ExecuteEventProcedure                  ,0xff87a3a0) //104
NHSTUB(ExitFromCompensationEVF                ,0xff837838) //104
NHSTUB(ExitTask                               ,0xff81f3a0) //120
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff8452e8) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff8453c0) //104
NHSTUB(Fclose_Fut                             ,0xff835dac) //120
NHSTUB(Feof_Fut                               ,0xff835f98) //  1
NHSTUB(Fflush_Fut                             ,0xff835fd4) //  1
NHSTUB(Fgets_Fut                              ,0xff835f00) //  1
NHSTUB(Fopen_Fut                              ,0xff835d6c) //120
NHSTUB(Fread_Fut                              ,0xff835e58) //120
NHSTUB(FreeUncacheableMemory                  ,0xff8397e4) //112
NHSTUB(Fseek_Fut                              ,0xff835f4c) //120
NHSTUB(Fwrite_Fut                             ,0xff835eac) //120
NHSTUB(GetBatteryTemperature                  ,0xff8567fc) //102
NHSTUB(GetCCDTemperature                      ,0xff856788) //102
NHSTUB(GetCurrentAvValue                      ,0xff926d50) //120
NHSTUB(GetCurrentShutterSpeed                 ,0xff899ed0) //120
NHSTUB(GetDrive_ClusterSize                   ,0xff863130) //122
NHSTUB(GetDrive_FreeClusters                  ,0xff863190) //  4
NHSTUB(GetDrive_TotalClusters                 ,0xff863164) //  3
NHSTUB(GetFocusLensSubjectDistance            ,0xff926048) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff9264a0) //  3
NHSTUB(GetImageFolder                         ,0xff90c4b4) //122
NHSTUB(GetKbdState                            ,0xff8546a8) //109
NHSTUB(GetMemInfo                             ,0xff81a760) //115
NHSTUB(GetOpticalTemperature                  ,0xff856870) //120
NHSTUB(GetParameterData                       ,0xff956820) //101
NHSTUB(GetPropertyCase                        ,0xff87e0ac) //102
NHSTUB(GetSystemTime                          ,0xffa47234) //120
NHSTUB(GetVRAMHPixelsSize                     ,0xff8d015c) //120
NHSTUB(GetVRAMVPixelsSize                     ,0xff8d0168) //120
NHSTUB(GetZoomLensCurrentPoint                ,0xff929e1c) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xffa37bc4) //102
NHSTUB(GiveSemaphore                          ,0xff81f06c) //120
NHSTUB(IsStrobeChargeCompleted                ,0xff8c04f8) //102
NHSTUB(LEDDrive                               ,0xff853b80) //120
NHSTUB(LocalTime                              ,0xff877e10) //115
NHSTUB(LockMainPower                          ,0xff882a7c) //120
NHSTUB(MakeDirectory_Fut                      ,0xff835ca4) //116
NHSTUB(MoveFocusLensToDistance                ,0xffaa7438) //102
NHSTUB(MoveIrisWithAv                         ,0xffa438cc) //120
NHSTUB(MoveZoomLensWithPoint                  ,0xffa43e5c) //120
NHSTUB(MoveOpticalZoomAt                      ,0xff837304) //109
NHSTUB(Open                                   ,0xff83624c) //120
NHSTUB(PB2Rec                                 ,0xff885af4) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff86b22c) //120
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff86b204) //120
NHSTUB(PT_PlaySound                           ,0xff873af0) //122
NHSTUB(PostLogicalEventForNotPowerType        ,0xff8822ac) //120
NHSTUB(PostLogicalEventToUI                   ,0xff8822f8) //120
NHSTUB(PutInNdFilter                          ,0xffa43cc0) //102
NHSTUB(PutOutNdFilter                         ,0xffa43ce4) //102
NHSTUB(Read                                   ,0xff81b270) //120
NHSTUB(ReadFastDir                            ,0xffa2d1fc) //  4
NHSTUB(Rec2PB                                 ,0xff885b34) //104
NHSTUB(RefreshPhysicalScreen                  ,0xff9b3304) //104
NHSTUB(RenameFile_Fut                         ,0xff835b9c) //116
NHSTUB(Restart                                ,0xff83af88) //122
NHSTUB(ScreenLock                             ,0xff9b44c4) //117
NHSTUB(ScreenUnlock                           ,0xff9b4508) //117
NHSTUB(SetAE_ShutterSpeed                     ,0xffaa9bd4) //102
NHSTUB(SetAutoShutdownTime                    ,0xff882af0) //120
NHSTUB(SetCurrentCaptureModeType              ,0xff88948c) //120
NHSTUB(SetDate                                ,0xffaab610) //120
NHSTUB(SetFileAttributes                      ,0xff8365b0) //  3
NHSTUB(SetFileTimeStamp                       ,0xff836554) //  4
NHSTUB(SetLogicalEventActive                  ,0xff8827f4) //120
NHSTUB(SetParameterData                       ,0xff956790) //101
NHSTUB(SetPropertyCase                        ,0xff87df7c) //102
NHSTUB(SetScriptMode                          ,0xff882844) //120
NHSTUB(SleepTask                              ,0xff839628) //120
NHSTUB(TakeSemaphore                          ,0xff81ef9c) //120
NHSTUB(TurnOffBackLight                       ,0xff88e2f8) //104
NHSTUB(TurnOnBackLight                        ,0xff88e2e0) //104
NHSTUB(TurnOnDisplay                          ,0xff8500d8) //120
NHSTUB(TurnOffDisplay                         ,0xff850104) //120
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff944cac) //120
NHSTUB(UnlockAE                               ,0xff8378b0) //120
NHSTUB(UnlockAF                               ,0xff83777c) //120
NHSTUB(UnlockMainPower                        ,0xff8829d0) //120
NHSTUB(UnsetZoomForMovie                      ,0xff95c778) //104
NHSTUB(UpdateMBROnFlash                       ,0xff862fb0) //105
NHSTUB(VbattGet                               ,0xff832cf0) //120
NHSTUB(Write                                  ,0xff836348) //120
NHSTUB(WriteSDCard                            ,0xff919788) //108
NHSTUB(_log                                   ,0xffad6c94) //111
NHSTUB(_log10                                 ,0xffad5bd8) //112
NHSTUB(_pow                                   ,0xffad5d48) //121
NHSTUB(_sqrt                                  ,0xffad7ffc) //  1
NHSTUB(add_ptp_handler                        ,0xff9f670c) //121
NHSTUB(apex2us                                ,0xff9b582c) //121
NHSTUB(close                                  ,0xff81b088) //109
NHSTUB(err_init_task                          ,0xff815f50) //111
NHSTUB(exmem_alloc                            ,0xff878d50) //103
NHSTUB(exmem_ualloc                           ,0xff878ba4) //103
NHSTUB(exmem_ufree                            ,0xff878cf0) //103
NHSTUB(free                                   ,0xff814160) //112
NHSTUB(get_nd_value                           ,0xffa35e98) //123
NHSTUB(get_current_nd_value                   ,0xffa35e54) //122
NHSTUB(kbd_p1_f                               ,0xff833d54) //109
NHSTUB(kbd_p1_f_cont                          ,0xff833d60) //109
NHSTUB(kbd_p2_f                               ,0xff833604) //109
NHSTUB(kbd_read_keys                          ,0xff833cd4) //109
NHSTUB(kbd_read_keys_r2                       ,0xff854028) //109
NHSTUB(lseek                                  ,0xff8363d4) //120
NHSTUB(malloc                                 ,0xff814104) //112
NHSTUB(memcmp                                 ,0xff821280) //120
NHSTUB(memcpy                                 ,0xff83ee14) //120
NHSTUB(memset                                 ,0xff9b4864) //120
NHSTUB(mkdir                                  ,0xff836754) //109
NHSTUB(mktime_ext                             ,0xff895a30) //  1
NHSTUB(open                                   ,0xff81afd8) //109
NHSTUB(OpenFastDir                            ,0xffa2d0a8) //  4
NHSTUB(closedir                               ,0xffa2d058) //121
NHSTUB(get_fstype                             ,0xff8631b4) //122
NHSTUB(qsort                                  ,0xffa8df60) //  4
NHSTUB(rand                                   ,0xff821388) //121
NHSTUB(realloc                                ,0xff9b48e0) //115
NHSTUB(reboot_fw_update                       ,0xffa2ea70) //106
NHSTUB(set_control_event                      ,0xff882514) //111
NHSTUB(srand                                  ,0xff82137c) //122
NHSTUB(stat                                   ,0xff83641c) //109
NHSTUB(strcat                                 ,0xff8951ec) //  1
NHSTUB(strchr                                 ,0xff813fe8) //  1
NHSTUB(strcmp                                 ,0xff82123c) //120
NHSTUB(strcpy                                 ,0xff821224) //120
NHSTUB(strftime                               ,0xff895438) //113
NHSTUB(strlen                                 ,0xff814034) //120
NHSTUB(strncmp                                ,0xff813f9c) //  1
NHSTUB(strncpy                                ,0xff813f60) //  1
NHSTUB(strrchr                                ,0xff81400c) //  1
NHSTUB(strtol                                 ,0xff83f0f4) //101
NHSTUB(strtolx                                ,0xff83eef8) //109
   DEF(task_CaptSeq                           ,0xff86d6f0) //120
   DEF(task_DvlpSeqTask                       ,0xff933358) //120
   DEF(task_ExpDrv                            ,0xff8aa798) //120
   DEF(task_FileWrite                         ,0xffa27cd4) //120
   DEF(task_InitFileModules                   ,0xff8864c0) //120
   DEF(task_MovieRecord                       ,0xff92dbec) //120
   DEF(task_PhySw                             ,0xff833934) //120
NHSTUB(time                                   ,0xff8783f0) //109
NHSTUB(vsprintf                               ,0xff8211e8) //115
NHSTUB(EngDrvRead                             ,0xff834ba8) //102
NHSTUB(PTM_GetCurrentItem                     ,0xff8834b0) //105
NHSTUB(DisableISDriveError                    ,0xffa44690) //120
NHSTUB(CancelHPTimer                          ,0xff879a88) //119
NHSTUB(SetHPTimerAfterNow                     ,0xff879980) //119
NHSTUB(PT_MFOn                                ,0xff86b2bc) //120
NHSTUB(PT_MFOff                               ,0xff86b2cc) //120
NHSTUB(GetAdChValue                           ,0xff85180c) //120
NHSTUB(get_ptp_buf_size                       ,0xff8d32f0) //122
NHSTUB(get_ptp_file_buf                       ,0xff9f80a4) //121
NHSTUB(SetVideoOutType                        ,0xffaaa3c0) //109
NHSTUB(GetVideoOutType                        ,0xffaaa324) //120
