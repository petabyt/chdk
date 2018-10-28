// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R55 (DRYOS version 2.3, release #0055+p6)
//   Firmware Ver GM1.00A   // Found @ 0xff89b5f4, "GM1.00A" @ 0xff89b601
//   Firmware build timestamp: Oct 23 2014 09:55:10
//   Canon IXUS 160

// Values for makefile.inc
//   PLATFORMOSVER = 55
//   PLATFORMID = 12970 (0x32aa) // Found @ 0xffff0040
//   MAXRAMADDR = 0x07ffffff
//   MEMISOSTART = 0x00185cb0
//   KEYSYS = d4g                // Found @ 0xff81296c
//   NEED_ENCODED_DISKBOOT = 13   // Found @ 0xff81297c
//   ARAM_HEAP_START = 0x60e000  // Found @ 0xff9a53d0
//   ARAM_HEAP_SIZE  = 0x22000   // Found @ 0xff9a5390

// Detected address ranges:
// ROM      0xff810000 - 0xffffffff (8323072 bytes)
// RAM code 0x006b1000 - 0x006be8d8 copied from 0xffcf60b4 (  55512 bytes)
// RAM data 0x00001900 - 0x0000f9ec copied from 0xffce7fc8 (  57580 bytes)

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NHSTUB(DeleteFile_Fut                       ,0xff8274a4) //  1 90%        == 0xff8274a4
//NHSTUB(GetFocusLensSubjectDistanceFromLens  ,0xff98df94) //  3 90%        == 0xff98df94
// ERROR: MakeDirectory_Fut is not found.                  //--- ---    *** != 0xff827fb4
// ERROR: RefreshPhysicalScreen is not found.              //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ffadd0bc -> ffcb2584
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x000107a4) // Found @0xff82dc98
DEF(physw_run                               ,0x00001c94) // Found @0xff82d7c8
DEF(physw_sleep_delay                       ,0x00001c9c) // Found @0xff82d7c8
DEF(levent_table                            ,0xffc025e8) // Found @0xffc025e8
DEF(FlashParamsTable                        ,0xffcb28c0) // Found @0xffcb28c0
DEF(movie_status                            ,0x000070cc) // Found @0xff994fc8
DEF(video_compression_rate                  ,0x0000707c) // Found @0xff995c90
DEF(full_screen_refresh                     ,0x00007c04) // Found @0xff9b8c04
DEF(canon_menu_active                       ,0x00003ac8) // Found @0xff8a38d8
DEF(canon_shoot_menu_active                 ,0x00009285) // Found @0xffa13df0
DEF(playrec_mode                            ,0x000035c4) // Found @0xff8921c4
DEF(zoom_status                             ,0x00005e6c) // Found @0xff9375fc
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 101 entries in the table - set NUM_FL to 101
DEF(focus_len_table                         ,0xffffae7c) // Found @0xffffae7c
DEF(zoom_busy                               ,0x00006f8c) // Found @0xff990358
DEF(focus_busy                              ,0x00006e54) // Found @0xff98c910
// Palette colour tables  found @ 0xffc062b8
// Camera appears to have only 1 RAW buffer @ 0x43737e20 (Found @0xffb7c910)
DEF(fileio_semaphore                        ,0x00001d0c) // Found @0xff83008c
DEF_CONST(uiprop_count                      ,0x000000c6) // Found @0xff9aeac4

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40711000; }             // Found @0xff8662d0
//void *vid_get_viewport_fb()      { return (void*)0x40866b80; }             // Found @0xffb7af7c
DEF(jpeg_count_str                          ,0x000d7868) // Found @0xff9ff7f0
//char *camera_jpeg_count_str()    { return (char*)0x000d7868; }             // Found @0xff9ff7f0
//int get_flash_params_count(void) { return 0xd4; }                          // Found @0xff9af548

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x02000000 // Found @0xffbc0ba0, levent 0x20a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x10000000 // Found @0xffbc0bb0, levent 0x202
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x04000000 // Found @0xffbc0ba8, levent 0x205
//#define BATTCOVER_IDX       2
//#define ANALOG_AV_FLAG      0x00002000 // Found @0xffbc0b48, levent 0x200 (non-inverted logic)
//#define ANALOG_AV_IDX       0

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_VIDEO           ,0x00000002 }, // Found @0xffbc0b08, levent 0x02
//    { 0, KEY_POWER           ,0x00000020 }, // Found @0xffbc0b10, levent 0x100
//    { 0, KEY_PLAYBACK        ,0x00000040 }, // Found @0xffbc0b18, levent 0x101
//    { 0, KEY_SET             ,0x00000100 }, // Found @0xffbc0b20, levent 0x0a
//    { 0, KEY_UP              ,0x00000200 }, // Found @0xffbc0b28, levent 0x06
//    { 0, KEY_RIGHT           ,0x00000400 }, // Found @0xffbc0b30, levent 0x09
//    { 0, KEY_DOWN            ,0x00000800 }, // Found @0xffbc0b38, levent 0x07
//    { 0, KEY_LEFT            ,0x00001000 }, // Found @0xffbc0b40, levent 0x08
//    { 0, KEY_HELP            ,0x00004000 }, // Found @0xffbc0b50, levent 0x0d
//    { 0, KEY_MENU            ,0x00008000 }, // Found @0xffbc0b58, levent 0x14
//    { 2, KEY_SHOOT_FULL      ,0x00000003 }, // Found @0xffbc0b68, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000002 }, // Found @0xffbc0b68, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000001 }, // Found @0xffbc0b60, levent 0x00
//    { 2, KEY_ZOOM_OUT        ,0x00000010 }, // Found @0xffbc0b70, levent 0x04
//    { 2, KEY_ZOOM_IN         ,0x00000020 }, // Found @0xffbc0b78, levent 0x03
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    5248 // Found @0xff96986c
//#define CAM_RAW_ROWS      3920 // Found @0xff969874
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff826238
//#define CAM_DATE_FOLDER_NAMING 0x080 // Found @0xffaab6e4 (pass as 3rd param to GetImageFolder)
//#define PARAM_CAMERA_NAME 3 // Found @0xffcb1568
//#define CAM_3ARG_DebugAssert 1

// Known propcases
// //      PROPCASE_AFSTEP 13
// #define PROPCASE_FOCUS_STATE 18
// #define PROPCASE_AV 23
// #define PROPCASE_BV 34
// //      PROPCASE_DELTA_DIGITALGAIN 77
// #define PROPCASE_DELTA_SV 79
// //      PROPCASE_DELTA_ND 80
// #define PROPCASE_EV_CORRECTION_2 210
// #define PROPCASE_ORIENTATION_SENSOR 222
// #define PROPCASE_SV_MARKET 249
// //      PROPCASE_SVFIX 250
// #define PROPCASE_TV 265
// Guessed propset: 6

// Misc stuff
DEF(ctypes, 0xffbbd7a0)

// ISR flag: 0x1944, pointer to current task's control block: 0x1940
// pointer to TCB area: 0x19c4, found @ 0xffcf765c

// LED table init @ 0xff945608
// LED #1: 0xc022d200 (#98 in GPIO table), offset 0x98
// LED #2: 0xc022d1fc (#97 in GPIO table), offset 0x8
// GPIO table @ 0xffbc059c

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NHSTUB(AllocateUncacheableMemory              ,0xff8261f4) //112
NHSTUB(Close                                  ,0xff827b18) //120
NHSTUB(CreateBinarySemaphore                  ,0xff8262cc) //115
NHSTUB(CreateTask                             ,0xff824a30) //120
NHSTUB(DebugAssert                            ,0xff824ddc) //107
NHSTUB(DeleteDirectory_Fut                    ,0xff827518) //116
NHSTUB(DoAELock                               ,0xff833690) //120
NHSTUB(DoAFLock                               ,0xff833354) //120
NHSTUB(EnterToCompensationEVF                 ,0xff8335f4) //104
NHSTUB(ExecuteEventProcedure                  ,0xff8353c0) //104
NHSTUB(ExitFromCompensationEVF                ,0xff83363c) //104
NHSTUB(ExitTask                               ,0xff824d78) //120
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff84393c) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff843ad4) //104
NHSTUB(Fclose_Fut                             ,0xff8275b0) //120
NHSTUB(Feof_Fut                               ,0xff82779c) //  1
NHSTUB(Fflush_Fut                             ,0xff8277d8) //  1
NHSTUB(Fgets_Fut                              ,0xff827704) //  6
NHSTUB(Fopen_Fut                              ,0xff827570) //120
NHSTUB(Fread_Fut                              ,0xff82765c) //120
NHSTUB(FreeUncacheableMemory                  ,0xff826230) //112
NHSTUB(Fseek_Fut                              ,0xff827750) //120
NHSTUB(Fwrite_Fut                             ,0xff8276b0) //120
NHSTUB(GetBatteryTemperature                  ,0xff86f06c) //102
NHSTUB(GetCCDTemperature                      ,0xff86eff4) //102
NHSTUB(GetCurrentAvValue                      ,0xff887d20) //120
NHSTUB(GetUsableMaxAv                         ,0xff96a074) //120
NHSTUB(GetUsableMinAv                         ,0xff96a058) //120
NHSTUB(GetDrive_ClusterSize                   ,0xff831724) //122
NHSTUB(GetDrive_FreeClusters                  ,0xff831f30) //119
NHSTUB(GetDrive_TotalClusters                 ,0xff831f04) //122
NHSTUB(GetFocusLensSubjectDistance            ,0xff98dbb0) //102
NHSTUB(GetImageFolder                         ,0xff9719f4) //122
NHSTUB(GetKbdState                            ,0xff86b89c) //109
NHSTUB(GetMemInfo                             ,0xff823400) //115
NHSTUB(GetOpticalTemperature                  ,0xff86f0e4) //120
NHSTUB(GetParameterData                       ,0xff9af504) //101
NHSTUB(GetPropertyCase                        ,0xff89cf04) //101
NHSTUB(GetSystemTime                          ,0xffadacc0) //120
NHSTUB(GetVRAMHPixelsSize                     ,0xff84fb9c) //120
NHSTUB(GetVRAMVPixelsSize                     ,0xff84fba8) //120
NHSTUB(GetZoomLensCurrentPoint                ,0xff9907e8) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xffacb53c) //102
NHSTUB(GiveSemaphore                          ,0xff82654c) //120
NHSTUB(IsStrobeChargeCompleted                ,0xff8e4df8) //102
NHSTUB(LEDDrive                               ,0xff9969d8) //120
NHSTUB(LocalTime                              ,0xff83e030) //115
NHSTUB(LockMainPower                          ,0xff89f850) //120
NHSTUB(MakeSDCardBootable                     ,0xff8322f8) //105
NHSTUB(MoveFocusLensToDistance                ,0xffb7e888) //102
NHSTUB(MoveIrisWithAv                         ,0xffad5c9c) //120
NHSTUB(MoveZoomLensWithPoint                  ,0xffad65e0) //120
NHSTUB(Open                                   ,0xff827a50) //120
NHSTUB(PB2Rec                                 ,0xff85a294) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff997b58) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff997b28) //102
NHSTUB(PT_PlaySound                           ,0xff8ad134) //122
NHSTUB(PostLogicalEventForNotPowerType        ,0xff89ed9c) //120
NHSTUB(PostLogicalEventToUI                   ,0xff89ede8) //120
NHSTUB(PutInNdFilter                          ,0xffad63a0) //102
NHSTUB(PutOutNdFilter                         ,0xffad63c4) //102
NHSTUB(Read                                   ,0xff823ebc) //120
NHSTUB(ReadFastDir                            ,0xffaba2a4) //115
NHSTUB(Rec2PB                                 ,0xff85897c) //104
NHSTUB(RenameFile_Fut                         ,0xff827410) //116
NHSTUB(Restart                                ,0xff83846c) //122
NHSTUB(ScreenLock                             ,0xff8a3200) //117
NHSTUB(ScreenUnlock                           ,0xff8a325c) //117
NHSTUB(SetAE_ShutterSpeed                     ,0xffb79db8) //102
NHSTUB(SetAutoShutdownTime                    ,0xff89f8c4) //120
NHSTUB(SetCurrentCaptureModeType              ,0xff8a9e5c) //120
NHSTUB(SetFileAttributes                      ,0xff827f1c) //  6
NHSTUB(SetFileTimeStamp                       ,0xff827ea4) //  6
NHSTUB(SetLogicalEventActive                  ,0xff89f444) //120
NHSTUB(SetParameterData                       ,0xff9af468) //101
NHSTUB(SetPropertyCase                        ,0xff89cd2c) //101
NHSTUB(SetScriptMode                          ,0xff89f498) //120
NHSTUB(SleepTask                              ,0xff82a760) //120
NHSTUB(TakeSemaphore                          ,0xff826474) //120
NHSTUB(TurnOffBackLight                       ,0xff8ac83c) //104
NHSTUB(TurnOnBackLight                        ,0xff8ac824) //104
NHSTUB(TurnOnDisplay                          ,0xff8666b0) //120
NHSTUB(TurnOffDisplay                         ,0xff8666c0) //120
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff9ccbb8) //120
NHSTUB(UnlockAE                               ,0xff8336b4) //120
NHSTUB(UnlockAF                               ,0xff833384) //120
NHSTUB(UnlockMainPower                        ,0xff89f7a8) //120
NHSTUB(VbattGet                               ,0xff82cab0) //120
NHSTUB(Write                                  ,0xff827b6c) //120
NHSTUB(WriteSDCard                            ,0xff881a2c) //108
NHSTUB(_log                                   ,0x006bb388) //111
//NHSTUB(_log10                               ,0x006bb8c8) //112            == 0x006bb8c8
NHSTUB(_pow                                   ,0x006bba40) //121
NHSTUB(_sqrt                                  ,0x006bd6e0) //  6
NHSTUB(add_ptp_handler                        ,0xffa714d4) //121
NHSTUB(apex2us                                ,0xffa215e8) //121
NHSTUB(close                                  ,0xff823d18) //109
NHSTUB(err_init_task                          ,0xff824798) //111
NHSTUB(exmem_alloc                            ,0xff834fa8) //101
NHSTUB(exmem_free                             ,0xff835010) //101
NHSTUB(free                                   ,0xff825628) //112
NHSTUB(get_nd_value                           ,0xffac8b48) //123
NHSTUB(get_current_nd_value                   ,0xffac8ae8) //122
NHSTUB(kbd_p1_f                               ,0xff82dce8) //109
NHSTUB(kbd_p1_f_cont                          ,0xff82dcf4) //109
NHSTUB(kbd_p2_f                               ,0xff82d460) //109
NHSTUB(kbd_read_keys                          ,0xff82dc98) //109
NHSTUB(kbd_read_keys_r2                       ,0xff86b35c) //109
NHSTUB(lseek                                  ,0xff827d34) //120
NHSTUB(malloc                                 ,0xff8255d0) //112
NHSTUB(memcmp                                 ,0xff8253a8) //120
NHSTUB(memcpy                                 ,0xff8b0f4c) //120
NHSTUB(memset                                 ,0xffa1b600) //120
NHSTUB(mkdir                                  ,0xff827fb4) //121
NHSTUB(mktime_ext                             ,0xff8b07d4) //  1
NHSTUB(open                                   ,0xff823c68) //109
NHSTUB(OpenFastDir                            ,0xffaba150) //115
NHSTUB(closedir                               ,0xffaba100) //121
NHSTUB(get_fstype                             ,0xff83169c) //122
NHSTUB(qsort                                  ,0xffb3476c) //  6
NHSTUB(rand                                   ,0xffa1b5d0) //121
NHSTUB(realloc                                ,0xffa1b67c) //115
NHSTUB(reboot_fw_update                       ,0xffada374) //106
NHSTUB(set_control_event                      ,0xff89f104) //111
NHSTUB(srand                                  ,0xffa1b5c4) //122
NHSTUB(stat                                   ,0xff827d7c) //109
NHSTUB(strcat                                 ,0xff838e14) //  1
NHSTUB(strchr                                 ,0xff838e9c) //  1
NHSTUB(strcmp                                 ,0xff8254a4) //120
NHSTUB(strcpy                                 ,0xff825390) //120
NHSTUB(strftime                               ,0xff8b0820) //113
NHSTUB(strlen                                 ,0xff8254e8) //120
NHSTUB(strncmp                                ,0xff838e50) //  1
NHSTUB(strncpy                                ,0xff8286ac) //  1
NHSTUB(strrchr                                ,0xff8b1098) //  1
NHSTUB(strtol                                 ,0xff838e00) //101
NHSTUB(strtolx                                ,0xff838c04) //109
   DEF(task_CaptSeq                           ,0xff88ca84) //120
   DEF(task_DvlpSeqTask                       ,0xff99bc70) //120
   DEF(task_ExpDrv                            ,0xff8db0b0) //120
   DEF(task_FileWrite                         ,0xffab8cf0) //120
   DEF(task_InitFileModules                   ,0xff85ab10) //120
   DEF(task_MovieRecord                       ,0xff995d5c) //120
   DEF(task_PhySw                             ,0xff82d7c4) //120
   DEF(hook_CreateTask                        ,0xff824a30) //105
NHSTUB(time                                   ,0xff82ab10) //119
NHSTUB(vsprintf                               ,0xff82866c) //115
NHSTUB(EngDrvRead                             ,0xff82ddf8) //102
NHSTUB(PTM_GetCurrentItem                     ,0xff8a1464) //105
NHSTUB(CancelHPTimer                          ,0xff899668) //119
NHSTUB(SetHPTimerAfterNow                     ,0xff899560) //119
NHSTUB(SS_MFOn                                ,0xff997bec) //120
NHSTUB(SS_MFOff                               ,0xff997bfc) //120
NHSTUB(GetAdChValue                           ,0xff8678ec) //120
