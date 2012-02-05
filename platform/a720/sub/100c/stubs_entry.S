// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R23 (DRYOS version 2.3, release #0023)
//   Firmware Ver GM1.00C
//   Canon PowerShot A720 IS

// Values for makefile.inc
//   PLATFORMID = 12637 (0x315d) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x01ffffff
//   KEYSYS = d3                 // Found @ 0xffff1aa4
//   NEED_ENCODED_DISKBOOT = 1   // Found @ 0xffff1a84

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NSTUB(GetZoomLensCurrentPosition            ,0xffdd0040) //102        *** != 0xffd03b5c
//NSTUB(SetPropertyCase                       ,0xffc59b24) //103        *** != 0xffc50cc8
//NSTUB(rename                                ,0xffc14840) //  1        *** != 0xffc15100
//NSTUB(write                                 ,0xffc150d8) //101        *** != 0xffc0a4a8

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ffc5f8c8 -> ffc5c33c -> ffd1b53c -> ffddc128 -> ffe7cffc
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x0001061c) // Found @0xffc130cc
DEF(physw_run                               ,0x00001ca4) // Found @0xffc12d7c
DEF(levent_table                            ,0xffe60474) // Found @0xffe60474
DEF(FlashParamsTable                        ,0xffe7d1b4) // Found @0xffe7d1b4
DEF(movie_status                            ,0x00005570) // Found @0xffc498b4
DEF(canon_menu_active                       ,0x0000b55c) // Found @0xffd49f2c
DEF(canon_shoot_menu_active                 ,0x0000ae15) // Found @0xffd2b690
DEF(playrec_mode                            ,0x00005704) // Found @0xffc4fcb4
DEF(zoom_status                             ,0x0000d7c4) // Found @0xffddd920
DEF(some_flag_for_af_scan                   ,0x0000d688) // Found @0xffdd48c0
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 15 entries in the table - set NUM_FL to 15
DEF(focus_len_table                         ,0xfffe299c) // Found @0xfffe299c
DEF(zoom_busy                               ,0x00009dc0) // Found @0xffd02c78
//DEF(focus_busy                              ,0x00009cb8) // Found @0xffcfcffc, ** != ** stubs_min = 0x00009d50 (0x9D50)
//DEF(recreview_hold                          ,0x00005dc0) // Found @0xffc64708, ** != ** stubs_min = 0x0000abe8 (0xABE8)

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x10361000; }             // Found @0xffc32c24
//void *vid_get_viewport_fb()      { return (void*)0x1065a4d0; }             // Found @0xffda95c4
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x53c4+0x4c)); } // Found @0xffc42ec8 & 0xffc42f00
//char *camera_jpeg_count_str()    { return (char*)0x000580cc; }             // Found @0xffd55dcc
//long hook_raw_size()             { return 0x009dcce0; }                    // Found @0xffdab2b4
//int get_flash_params_count(void) { return 0x72; }                          // Found @0xffd1c5f8

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffe44040, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00040000 // Found @0xffe44048, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 1, KEY_SHOOT_FULL      ,0xc0000000 }, // Found @0xffe43fb0, levent 0x01
//    { 1, KEY_SHOOT_FULL_ONLY ,0x80000000 }, // Found @0xffe43fb0, levent 0x01
//    { 1, KEY_SHOOT_HALF      ,0x40000000 }, // Found @0xffe43fa8, levent 0x00
//    { 2, KEY_ZOOM_IN         ,0x00000004 }, // Found @0xffe43fc8, levent 0x02
//    { 2, KEY_ZOOM_OUT        ,0x00000008 }, // Found @0xffe43fd0, levent 0x03
//    { 2, KEY_UP              ,0x00000010 }, // Found @0xffe43fd8, levent 0x04
//    { 2, KEY_DOWN            ,0x00000020 }, // Found @0xffe43fe0, levent 0x05
//    { 2, KEY_RIGHT           ,0x00000040 }, // Found @0xffe43fe8, levent 0x07
//    { 2, KEY_LEFT            ,0x00000080 }, // Found @0xffe43ff0, levent 0x06
//    { 2, KEY_SET             ,0x00000100 }, // Found @0xffe43ff8, levent 0x08
//    { 2, KEY_DISPLAY         ,0x00000200 }, // Found @0xffe44000, levent 0x0a
//    { 2, KEY_MENU            ,0x00000400 }, // Found @0xffe44008, levent 0x09
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_RAW_ROWPIX    3336 // Found @0xffda3720
//#define CAM_RAW_ROWS      2480 // Found @0xffda3728
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x10000000 // Found @0xffc19884

// Misc stuff
DEF(ctypes, 0xffe3ead6)

// For capt_seq.c
//static long *nrflag = (long*)(0x9f90);       // Found @ ffd0a438

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NSTUB(AllocateMemory                          ,0xffdd7df4) //103
NSTUB(AllocateUncacheableMemory               ,0xffc19848) //112
NSTUB(Close                                   ,0xffc1502c) //101
NSTUB(CreateTask                              ,0xffc0bbc0) //101
NSTUB(DebugAssert                             ,0xffc0c098) //111
NSTUB(DeleteDirectory_Fut                     ,0xffc14978) //  1
NSTUB(DeleteFile_Fut                          ,0xffc14894) //112
NSTUB(DoAFLock                                ,0xffc16d2c) //103
NSTUB(EnterToCompensationEVF                  ,0xffc170a4) //104
NSTUB(ExecuteEventProcedure                   ,0xffc0c278) //  1
NSTUB(ExitFromCompensationEVF                 ,0xffc170f4) //104
NSTUB(ExitTask                                ,0xffc0be50) //101
NSTUB(ExpCtrlTool_StartContiAE                ,0xffc23930) //104
NSTUB(ExpCtrlTool_StopContiAE                 ,0xffc23a2c) //104
NSTUB(Fclose_Fut                              ,0xffc14a10) //101
NSTUB(Feof_Fut                                ,0xffc14bfc) //  1
NSTUB(Fflush_Fut                              ,0xffc14c38) //  1
NSTUB(Fgets_Fut                               ,0xffc14b64) //  1
NSTUB(Fopen_Fut                               ,0xffc149d0) //101
NSTUB(Fread_Fut                               ,0xffc14abc) //101
NSTUB(FreeMemory                              ,0xffdd7de0) //103
NSTUB(FreeUncacheableMemory                   ,0xffc1987c) //112
NSTUB(Fseek_Fut                               ,0xffc14bb0) //101
NSTUB(Fwrite_Fut                              ,0xffc14b10) //101
NSTUB(GetBatteryTemperature                   ,0xffc39178) //102
NSTUB(GetCCDTemperature                       ,0xffc39108) //102
NSTUB(GetCurrentAvValue                       ,0xffcffca8) //102
NSTUB(GetDrive_ClusterSize                    ,0xffc3f4c4) //  1
NSTUB(GetDrive_FreeClusters                   ,0xffc3f564) //  1
NSTUB(GetDrive_TotalClusters                  ,0xffc3f4f8) //  1
NSTUB(GetFocusLensSubjectDistance             ,0xffcfdb3c) //102
NSTUB(GetFocusLensSubjectDistanceFromLens     ,0xffcfde48) //  1
NSTUB(GetKbdState                             ,0xffc37034) //109
NSTUB(GetMemInfo                              ,0xffc03c58) //  1
NSTUB(GetOpticalTemperature                   ,0xffc391e8) //102
NSTUB(GetParameterData                        ,0xffd1c5b8) //101
NSTUB(GetPropertyCase                         ,0xffc59c2c) //101
NSTUB(GetSystemTime                           ,0xffdd7efc) //  1
NSTUB(GetZoomLensCurrentPoint                 ,0xffd02fdc) //102
NSTUB(GiveSemaphore                           ,0xffc0bb2c) //112
NSTUB(IsStrobeChargeCompleted                 ,0xffc974e4) //102
NSTUB(LEDDrive                                ,0xffc36638) //103
NSTUB(LocalTime                               ,0xffc56058) //  1
NSTUB(LockMainPower                           ,0xffc5bf6c) //103
NSTUB(Lseek                                   ,0xffc1516c) //101
NSTUB(MakeDirectory_Fut                       ,0xffc14908) //  1
NSTUB(MoveFocusLensToDistance                 ,0xffda6578) //102
NSTUB(MoveIrisWithAv                          ,0xffd00088) //102
NSTUB(MoveZoomLensWithPoint                   ,0xffd03a88) //102
NSTUB(NewTaskShell                            ,0xffc596b0) //103
NSTUB(Open                                    ,0xffc15004) //101
NSTUB(PB2Rec                                  ,0xffc5ecf8) //104
NSTUB(PT_MoveDigitalZoomToWide                ,0xffc513cc) //103
NSTUB(PT_MoveOpticalZoomAt                    ,0xffc51394) //103
NSTUB(PT_PlaySound                            ,0xffc50f40) //103
NSTUB(PostLogicalEventForNotPowerType         ,0xffc5b650) //103
NSTUB(PostLogicalEventToUI                    ,0xffc5b69c) //103
NSTUB(PutInNdFilter                           ,0xffda4a98) //102
NSTUB(PutOutNdFilter                          ,0xffda4ad0) //102
NSTUB(Read                                    ,0xffc0a448) //101
NSTUB(ReadFastDir                             ,0xffdc1b98) //  1
NSTUB(Rec2PB                                  ,0xffc5ed28) //104
NSTUB(RefreshPhysicalScreen                   ,0xffd62184) //104
NSTUB(Remove                                  ,0xffc15074) //  1
NSTUB(RenameFile_Fut                          ,0xffc14840) //  1
NSTUB(Restart                                 ,0xffc1b8a4) //106
NSTUB(SetAE_ShutterSpeed                      ,0xffda87c0) //102
NSTUB(SetAutoShutdownTime                     ,0xffc5bfe0) //103
NSTUB(SetCurrentCaptureModeType               ,0xffc6214c) //101
NSTUB(SetFileAttributes                       ,0xffc15358) //  1
NSTUB(SetFileTimeStamp                        ,0xffc15308) //  1
NSTUB(SetLogicalEventActive                   ,0xffc5bcd0) //  1
NSTUB(SetParameterData                        ,0xffd1c528) //101
NSTUB(SetScriptMode                           ,0xffc5bd20) //101
NSTUB(SleepTask                               ,0xffc196d0) //101
NSTUB(TakeSemaphore                           ,0xffc0ba5c) //101
NSTUB(TurnOffBackLight                        ,0xffc676f4) //104
NSTUB(TurnOnBackLight                         ,0xffc676dc) //104
NSTUB(UIFS_WriteFirmInfoToFile                ,0xffd4a934) //103
NSTUB(UnlockAF                                ,0xffc16d7c) //103
NSTUB(UnlockMainPower                         ,0xffc5bec0) //103
NSTUB(UnsetZoomForMovie                       ,0xffd22418) //104
NSTUB(UpdateMBROnFlash                        ,0xffc3f28c) //105
NSTUB(VbattGet                                ,0xffc119a8) //101
NSTUB(Write                                   ,0xffc150d8) //101
NSTUB(WriteSDCard                             ,0xffcf51b0) //108
NSTUB(_log                                    ,0xffe3c8dc) //111
NSTUB(_log10                                  ,0xffe3b820) //112
NSTUB(_pow                                    ,0xffe3b990) //114
NSTUB(_sqrt                                   ,0xffe3dc44) //  1
NSTUB(add_ptp_handler                         ,0xffcad7d0) //  1
NSTUB(apex2us                                 ,0xffd6363c) //  4
NSTUB(close                                   ,0xffc0a260) //  1
NSTUB(closedir                                ,0xffdc1c68) //  1
NSTUB(err_init_task                           ,0xffc04eb0) //  4
NSTUB(exmem_alloc                             ,0xffc56b44) //  1
NSTUB(free                                    ,0xffc03ab0) //112
NSTUB(kbd_p1_f                                ,0xffc131d0) //109
NSTUB(kbd_p1_f_cont                           ,0xffc131dc) //109
NSTUB(kbd_p2_f                                ,0xffc12a1c) //109
NSTUB(kbd_pwr_off                             ,0xffc370c0) //  1
NSTUB(kbd_pwr_on                              ,0xffc37068) //  1
NSTUB(kbd_read_keys                           ,0xffc130cc) //109
NSTUB(kbd_read_keys_r2                        ,0xffc36b14) //109
NSTUB(lseek                                   ,0xffc1516c) //101
NSTUB(malloc                                  ,0xffc039dc) //112
NSTUB(memcmp                                  ,0xffc0e8f0) //101
NSTUB(memcpy                                  ,0xffc71bf4) //101
NSTUB(memset                                  ,0xffe0e37c) //101
NSTUB(mkdir                                   ,0xffc153d0) //  1
// ALT: NSTUB(mkdir, 0xffc15470) // 1 32/0
NSTUB(mktime_ext                              ,0xffc72460) //  1
NSTUB(open                                    ,0xffc0a1b0) //  1
NSTUB(opendir                                 ,0xffdc1b04) //  1
NSTUB(openfastdir                             ,0xffdc1b04) //  1
NSTUB(qsort                                   ,0xffd62a14) //  1
NSTUB(rand                                    ,0xffc0e9f8) //  1
NSTUB(read                                    ,0xffc0a448) //101
NSTUB(reboot_fw_update                        ,0xffdc6538) //  1
NSTUB(set_control_event                       ,0xffc5baa4) //  1
NSTUB(srand                                   ,0xffc0e9ec) //  1
NSTUB(stat                                    ,0xffc15238) //  1
NSTUB(strcat                                  ,0xffc71b20) //  1
NSTUB(strchr                                  ,0xffc71ba8) //  1
NSTUB(strcmp                                  ,0xffc0e888) //101
NSTUB(strcpy                                  ,0xffc0e834) //101
NSTUB(strftime                                ,0xffc71e68) //  1
NSTUB(strlen                                  ,0xffc0e8cc) //101
NSTUB(strncmp                                 ,0xffc71b5c) //  1
NSTUB(strncpy                                 ,0xffc0e84c) //  1
NSTUB(strrchr                                 ,0xffc71bcc) //  1
NSTUB(strtol                                  ,0xffc1fc0c) //101
NSTUB(strtolx                                 ,0xffc1fa10) //109
  DEF(task_CaptSeq                            ,0xffc4cb64) //107
  DEF(task_ExpDrv                             ,0xffc91454) //110
  DEF(task_InitFileModules                    ,0xffc5f754) //107
  DEF(task_MovieRecord                        ,0xffc49b18) //107
  DEF(task_PhySw                              ,0xffc12d78) //107
NSTUB(time                                    ,0xffc55f0c) //  1
NSTUB(vsprintf                                ,0xffc0e7b4) //  1
