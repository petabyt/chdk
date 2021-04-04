// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R52 (DRYOS version 2.3, release #0052)
//   Firmware Ver GM1.00C   // Found @ 0xff88ebe0, "GM1.00C" @ 0xff88ebed
//   Firmware build timestamp: Dec 14 2012 16:56:29
//   Canon PowerShot A2600 

// Values for makefile.inc
//   DIGIC = 40# DIGIC 4
//   PLATFORMOSVER = 52
//   PLATFORMID = 12898# (0x3262) Found @ 0xfffe0040
//   MAXRAMADDR = 0x03ffffff
//   MEMISOSTART = 0x0015afe8
//   KEYSYS = d4d# Found @ 0xffff1d30
//   NEED_ENCODED_DISKBOOT = 10# Found @ 0xffff1d40
//   ARAM_HEAP_START = 0x34e000# Found @ 0xff981720
//   ARAM_HEAP_SIZE  = 0x22000# Found @ 0xff9816e4

// Detected address ranges:
// ROM      0xff810000 - 0xffffffff (8323072 bytes)
// RAM code 0x003f1000 - 0x0040099c copied from 0xffc56f78 (  63900 bytes)
// RAM data 0x00001900 - 0x0000e6c8 copied from 0xffc4a1b0 (  52680 bytes)

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NHSTUB(DeleteFile_Fut                       ,0xff82d058) //  1 90%        == 0xff82d058
// ERROR: MakeDirectory_Fut is not found.                  //--- ---    *** != 0xff82db68
// ERROR: RefreshPhysicalScreen is not found.              //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ffa9ce88 -> ffbef210
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00032764) // Found @0xff82af1c
DEF(physw_run                               ,0x00001c90) // Found @0xff82aa6c
DEF(physw_sleep_delay                       ,0x00001c98) // Found @0xff82aa6c
DEF(levent_table                            ,0xffb9c63c) // Found @0xffb9c63c
DEF(FlashParamsTable                        ,0xffbef440) // Found @0xffbef440
DEF(movie_status                            ,0x00006b5c) // Found @0xff972a10
DEF(video_compression_rate                  ,0x00006b8c) // Found @0xff973174
DEF(full_screen_refresh                     ,0x0000759c) // Found @0xff98f278
DEF(canon_menu_active                       ,0x000038c0) // Found @0xff897220
DEF(canon_shoot_menu_active                 ,0x00008b65) // Found @0xff9e76cc
DEF(playrec_mode                            ,0x00003304) // Found @0xff884720
DEF(zoom_status                             ,0x0000a02c) // Found @0xffa39e40
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 64 entries in the table - set NUM_FL to 64
DEF(focus_len_table                         ,0xfffea3e0) // Found @0xfffea3e0
DEF(zoom_busy                               ,0x00006a64) // Found @0xff96f04c
DEF(focus_busy                              ,0x00006930) // Found @0xff96bae8
DEF(recreview_hold                          ,0x00002718) // Found @0xff859f48
// Palette colour tables  found @ 0xffba3278
DEF(active_palette_buffer                   ,0x000075a4) // Found @0xff98f1fc
DEF(palette_buffer_ptr                      ,0x000075a8) // Found @0xff98f58c
// Offset from start of palette_buffer to color data = 4 (Found @0xffabd92c)
// Camera appears to have only 1 RAW buffer @ 0x420e5c30 (Found @0xffb18778)
DEF(fileio_semaphore                        ,0x00003064) // Found @0xff8756c4
DEF(exmem_alloc_table                       ,0x00039110) // Found @0xff88a010
DEF(exmem_types_table                       ,0xffc4bc80) // Found @0x000033d0
DEF_CONST(exmem_type_count                  ,0x0000001b)
DEF(imager_active                           ,0x00001f04) // Found @0xff84545c (0x1f00 + 4)
DEF_CONST(uiprop_count                      ,0x00000083) // Found @0xff9868d8
DEF(cameracon_state                         ,0x000022e4) // Found @0xff851438

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40431000; }             // Found @0xff85cf34
//void *vid_get_viewport_fb()      { return (void*)0x40586b80; }             // Found @0xffb16e60
DEF(viewport_fb_d                           ,0x00003110) // Found 0x30bc (@0xff878d44) + 0x54 (@0xff878d7c)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x30bc+0x54)); } // Found @0xff878d44 & 0xff878d7c
DEF(jpeg_count_str                          ,0x000c86fc) // Found @0xff9d5fb8
//char *camera_jpeg_count_str()    { return (char*)0x000c86fc; }             // Found @0xff9d5fb8
//int get_flash_params_count(void) { return 0x91; }                          // Found @0xff9872bc

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x02000000 // Found @0xffb4902c, levent 0x20a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x10000000 // Found @0xffb4903c, levent 0x202
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x04000000 // Found @0xffb49034, levent 0x205
//#define BATTCOVER_IDX       2
//#define ANALOG_AV_FLAG      0x02000000 // Found @0xffb48f94, levent 0x200 (non-inverted logic)
//#define ANALOG_AV_IDX       1

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 2, KEY_POWER           ,0x00000001 }, // Found @0xffb48f9c, levent 0x100
//    { 2, KEY_PLAYBACK        ,0x00000002 }, // Found @0xffb48fa4, levent 0x101
//    { 2, KEY_SHOOT_FULL      ,0x0000000c }, // Found @0xffb48fb4, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000008 }, // Found @0xffb48fb4, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000004 }, // Found @0xffb48fac, levent 0x00
//    { 2, KEY_ZOOM_IN         ,0x00000010 }, // Found @0xffb48fbc, levent 0x03
//    { 2, KEY_ZOOM_OUT        ,0x00000040 }, // Found @0xffb48fc4, levent 0x04
//    { 2, KEY_UP              ,0x00000080 }, // Found @0xffb48fcc, levent 0x06
//    { 2, KEY_DOWN            ,0x00000100 }, // Found @0xffb48fd4, levent 0x07
//    { 2, KEY_RIGHT           ,0x00000200 }, // Found @0xffb48fdc, levent 0x09
//    { 2, KEY_LEFT            ,0x00000400 }, // Found @0xffb48fe4, levent 0x08
//    { 2, KEY_SET             ,0x00001000 }, // Found @0xffb48fec, levent 0x0a
//    { 2, KEY_MENU            ,0x00002000 }, // Found @0xffb48ff4, levent 0x0b
//    { 2, KEY_VIDEO           ,0x00004000 }, // Found @0xffb48ffc, levent 0x02
//    { 2, KEY_HELP            ,0x00008000 }, // Found @0xffb49004, levent 0x12
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    4704 // Found @0xff945820
//#define CAM_RAW_ROWS      3504 // Found @0xff94582c
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff83200c
//#define CAM_DATE_FOLDER_NAMING 0x080 // Found @0xffa6923c (pass as 3rd param to GetImageFolder)
//#define PARAM_CAMERA_NAME 3 // Found @0xffbee704

// Below goes in 'filewrite.c' or 'platform_camera.h':
//#define MAX_CHUNKS_FOR_FWT 7 // Found @0xffa75d20

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
DEF(ctypes, 0xffb48494)

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
// EXMEM_GPS            11
// EXMEM_FACEAUTH       12
// EXMEM_OHYEARLOG      13
// EXMEM_WIFI           14
// EXMEM_FILESTORE      15
// EXMEM_MOVIE_REC      16
// EXMEM_MOVIE_PLY      17
// EXMEM_WIDE           18
// EXMEM_NARROW         19
// EXMEM_AUTO_GIS_MODE  20
// EXMEM_NP_GIS_MODE    21
// EXMEM_TRIPODHDR_MODE 22
// EXMEM_HSHQ_MODE      23
// EXMEM_CRAW_REC       24
// EXMEM_PCEVF          25
// EXMEM_WIFI_RESIZE    26

// ISR flag: 0x1958, pointer to current task's control block: 0x1954
// pointer to TCB area: 0x19e8, found @ 0xffc5919c

// LED table init @ 0xff926084
// LED #1: 0xc0223030, offset 0x104
// LED #2: 0xc0220094, offset 0x4

// For capt_seq.c
DEF(_nrflag,0x9870) // Found @ ff9f6354 (0x9870) & ff9f6390 (+0x00)
//static long *nrflag = (long*)(0x9870+0x00);  // Found @ ff9f6354 & ff9f6390
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NHSTUB(AllocateUncacheableMemory              ,0xff831fc4) //112
NHSTUB(Close                                  ,0xff82d6cc) //120
NHSTUB(CreateBinarySemaphore                  ,0x003f76c8) //115
NHSTUB(CreateTask                             ,0x003f68b0) //120
NHSTUB(DebugAssert                            ,0x003f6c28) //107
NHSTUB(DeleteDirectory_Fut                    ,0xff82d0cc) //116
NHSTUB(DoAELock                               ,0xff82f198) //120
NHSTUB(DoAFLock                               ,0xff82eeb8) //120
NHSTUB(EnterToCompensationEVF                 ,0xff82f100) //104
NHSTUB(ExecuteEventProcedure                  ,0xff88bc40) //104
NHSTUB(ExitFromCompensationEVF                ,0xff82f144) //104
NHSTUB(ExitTask                               ,0x003f6b40) //120
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff83e914) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff83ea7c) //104
NHSTUB(Fclose_Fut                             ,0xff82d164) //120
NHSTUB(Feof_Fut                               ,0xff82d350) //  1
NHSTUB(Fflush_Fut                             ,0xff82d38c) //  1
NHSTUB(Fgets_Fut                              ,0xff82d2b8) //  6
NHSTUB(Fopen_Fut                              ,0xff82d124) //120
NHSTUB(Fread_Fut                              ,0xff82d210) //120
NHSTUB(FreeUncacheableMemory                  ,0xff832004) //112
NHSTUB(Fseek_Fut                              ,0xff82d304) //120
NHSTUB(Fwrite_Fut                             ,0xff82d264) //120
NHSTUB(GetBatteryTemperature                  ,0xff864ea8) //102
NHSTUB(GetCCDTemperature                      ,0xff864e34) //102
NHSTUB(GetCurrentAvValue                      ,0xff96d94c) //120
NHSTUB(GetCurrentShutterSpeed                 ,0xff8a6170) //120
NHSTUB(GetDrive_ClusterSize                   ,0xff876d34) //122
NHSTUB(GetDrive_FreeClusters                  ,0xff877548) //119
NHSTUB(GetDrive_TotalClusters                 ,0xff877520) //122
NHSTUB(GetFocusLensSubjectDistance            ,0xff96cc18) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff96cfac) //  3
NHSTUB(GetImageFolder                         ,0xff94cf4c) //122
NHSTUB(GetKbdState                            ,0xff862054) //109
NHSTUB(GetMemInfo                             ,0xff814fcc) //115
NHSTUB(GetOpticalTemperature                  ,0xff864f1c) //120
NHSTUB(GetParameterData                       ,0xff98727c) //101
NHSTUB(GetPropertyCase                        ,0xff88fff4) //101
NHSTUB(GetSystemTime                          ,0xffa99f80) //120
NHSTUB(GetVRAMHPixelsSize                     ,0xff84abe8) //120
NHSTUB(GetVRAMVPixelsSize                     ,0xff84abf4) //120
NHSTUB(GetZoomLensCurrentPoint                ,0xff96f4c8) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xffa8ab28) //102
NHSTUB(GiveSemaphore                          ,0x003f7904) //120
NHSTUB(IsStrobeChargeCompleted                ,0xff8d64d0) //102
NHSTUB(LEDDrive                               ,0xff974700) //120
NHSTUB(LocalTime                              ,0x003fb2e8) //115
NHSTUB(LockMainPower                          ,0xff892468) //120
NHSTUB(MakeSDCardBootable                     ,0xff8779cc) //105
NHSTUB(MoveFocusLensToDistance                ,0xffb129c8) //102
NHSTUB(MoveIrisWithAv                         ,0xffa954ec) //120
NHSTUB(MoveZoomLensWithPoint                  ,0xffa95c1c) //120
NHSTUB(MoveOpticalZoomAt                      ,0xff82e9ac) //109
NHSTUB(Open                                   ,0xff82d604) //120
NHSTUB(PB2Rec                                 ,0xff852fec) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff975804) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff9757d4) //102
NHSTUB(PT_PlaySound                           ,0xff89eba0) //122
NHSTUB(PostLogicalEventForNotPowerType        ,0xff891b58) //120
NHSTUB(PostLogicalEventToUI                   ,0xff891ba4) //120
NHSTUB(PutInNdFilter                          ,0xffa959f4) //102
NHSTUB(PutOutNdFilter                         ,0xffa95a18) //102
NHSTUB(Read                                   ,0xff815a88) //120
NHSTUB(ReadFastDir                            ,0xffa79b64) //115
NHSTUB(Rec2PB                                 ,0xff85302c) //104
NHSTUB(RenameFile_Fut                         ,0xff82cfc4) //116
NHSTUB(Restart                                ,0xff83146c) //122
NHSTUB(ScreenLock                             ,0xff896d18) //117
NHSTUB(ScreenUnlock                           ,0xff896d6c) //117
NHSTUB(SetAE_ShutterSpeed                     ,0xffb15d38) //102
NHSTUB(SetAutoShutdownTime                    ,0xff8924dc) //120
NHSTUB(SetCurrentCaptureModeType              ,0xff89cfa4) //120
NHSTUB(SetDate                                ,0xffb17ac0) //120
NHSTUB(SetFileAttributes                      ,0xff82dad0) //  6
NHSTUB(SetFileTimeStamp                       ,0xff82da58) //  6
NHSTUB(SetLogicalEventActive                  ,0xff8921e0) //120
NHSTUB(SetParameterData                       ,0xff9871e8) //101
NHSTUB(SetPropertyCase                        ,0xff88fe64) //101
NHSTUB(SetScriptMode                          ,0xff892230) //120
NHSTUB(SleepTask                              ,0x003f7bb0) //120
NHSTUB(TakeSemaphore                          ,0x003f7834) //120
NHSTUB(TurnOffBackLight                       ,0xff89e46c) //104
NHSTUB(TurnOnBackLight                        ,0xff89e454) //104
NHSTUB(TurnOnDisplay                          ,0xff85d33c) //120
NHSTUB(TurnOffDisplay                         ,0xff85d34c) //120
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff9a2998) //120
NHSTUB(UnlockAE                               ,0xff82f1bc) //120
NHSTUB(UnlockAF                               ,0xff82eee8) //120
NHSTUB(UnlockMainPower                        ,0xff8923bc) //120
NHSTUB(VbattGet                               ,0xff829cb0) //120
NHSTUB(Write                                  ,0xff82d720) //120
NHSTUB(WriteSDCard                            ,0xff95e75c) //108
NHSTUB(_log                                   ,0x003fd0b0) //111
NHSTUB(_log10                                 ,0x003fd5f0) //112
NHSTUB(_pow                                   ,0x003fd768) //121
NHSTUB(_sqrt                                  ,0x003ff38c) //  6
NHSTUB(add_ptp_handler                        ,0xffa3375c) //121
NHSTUB(apex2us                                ,0xff9ef420) //121
NHSTUB(close                                  ,0xff8158e4) //109
NHSTUB(err_init_task                          ,0xff8142ac) //111
NHSTUB(exmem_alloc                            ,0xff88a608) //101
NHSTUB(exmem_ualloc                           ,0xff88a45c) //101
NHSTUB(exmem_ufree                            ,0xff88a5a8) //101
NHSTUB(free                                   ,0xff812ea8) //112
NHSTUB(get_nd_value                           ,0xffa88664) //123
NHSTUB(get_current_nd_value                   ,0xffa88604) //122
NHSTUB(get_current_deltasv                    ,0xff8a6dc4) //122
NHSTUB(GetCurrentDriveBaseSvValue             ,0xff8acd0c) //120
NHSTUB(kbd_p1_f                               ,0xff82af6c) //109
NHSTUB(kbd_p1_f_cont                          ,0xff82af78) //109
NHSTUB(kbd_p2_f                               ,0xff82a704) //109
NHSTUB(kbd_read_keys                          ,0xff82af1c) //109
NHSTUB(kbd_read_keys_r2                       ,0xff861b64) //109
NHSTUB(lseek                                  ,0xff82d8e8) //120
NHSTUB(malloc                                 ,0xff812e50) //112
NHSTUB(memcmp                                 ,0xff81a938) //120
NHSTUB(memcpy                                 ,0xff832398) //120
NHSTUB(memset                                 ,0xff8a210c) //120
NHSTUB(mkdir                                  ,0xff82db68) //121
NHSTUB(mktime_ext                             ,0xff8a1914) //  1
NHSTUB(open                                   ,0xff815834) //109
NHSTUB(OpenFastDir                            ,0xffa79a10) //115
NHSTUB(closedir                               ,0xffa799c0) //121
NHSTUB(get_fstype                             ,0xff876cb0) //122
NHSTUB(qsort                                  ,0xffaeb6a0) //  6
NHSTUB(rand                                   ,0xffaeb174) //121
NHSTUB(realloc                                ,0xff9ecff0) //115
NHSTUB(reboot_fw_update                       ,0xffa995f0) //106
NHSTUB(set_control_event                      ,0xff891ea0) //111
NHSTUB(srand                                  ,0xffaeb168) //122
NHSTUB(stat                                   ,0xff82d930) //109
NHSTUB(strcat                                 ,0xff8a1f94) //  1
NHSTUB(strchr                                 ,0xff812d1c) //  1
NHSTUB(strcmp                                 ,0xff81aa34) //120
NHSTUB(strcpy                                 ,0xff81a920) //120
NHSTUB(strftime                               ,0xff8a1960) //113
NHSTUB(strlen                                 ,0xff812d68) //120
NHSTUB(strncmp                                ,0xff812cd0) //  1
NHSTUB(strncpy                                ,0xff812c94) //  1
NHSTUB(strrchr                                ,0xff812d40) //  1
NHSTUB(strtol                                 ,0xff832384) //101
NHSTUB(strtolx                                ,0xff832188) //109
   DEF(task_CaptSeq                           ,0xff87f1f4) //120
   DEF(task_DvlpSeqTask                       ,0xff978aa4) //120
   DEF(task_ExpDrv                            ,0xff8bbb70) //120
   DEF(task_FileWrite                         ,0xffa75cc4) //120
   DEF(task_InitFileModules                   ,0xff853908) //120
   DEF(task_MovieRecord                       ,0xff973648) //120
   DEF(task_PhySw                             ,0xff82aa68) //120
   DEF(hook_CreateTask                        ,0x003f68b0) //105
NHSTUB(time                                   ,0x003fb790) //119
NHSTUB(vsprintf                               ,0xff81a7d0) //115
NHSTUB(EngDrvRead                             ,0xff82bdac) //102
NHSTUB(PTM_GetCurrentItem                     ,0xff892f18) //105
NHSTUB(CancelHPTimer                          ,0xff88b328) //119
NHSTUB(SetHPTimerAfterNow                     ,0xff88b220) //119
NHSTUB(SS_MFOn                                ,0xff975898) //120
NHSTUB(SS_MFOff                               ,0xff9758a8) //120
NHSTUB(GetAdChValue                           ,0xff85e4a4) //120
NHSTUB(get_ptp_buf_size                       ,0xff9049f0) //122
NHSTUB(get_ptp_file_buf                       ,0xffa352cc) //121
NHSTUB(SetVideoOutType                        ,0xffb16580) //109
NHSTUB(GetVideoOutType                        ,0xffb164d0) //120
