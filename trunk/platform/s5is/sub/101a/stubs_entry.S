// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R20 (DRYOS version 2.3, release #0020)
//   Firmware Ver GM1.01A
//   Canon PowerShot S5 IS

// Values for makefile.inc
//   PLATFORMID = 12616 (0x3148) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x03ffffff
//   KEYSYS = d3                 // Found @ 0xffff31c8
//   NEED_ENCODED_DISKBOOT = 1   // Found @ 0xffff31a8

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NSTUB(GetZoomLensCurrentPoint               ,0xff95783c) //102        *** != 0xff957d84
//NSTUB(GetZoomLensCurrentPosition            ,0xff9576b8) //102        *** != 0xff957d88
//NSTUB(Lseek                                 ,0xff825ecc) //101        *** != 0xff825f94
//NSTUB(Read                                  ,0xff81a2c8) //101        *** != 0xff825e34
//NSTUB(SetParameterData                      ,0xff972f14) //  1 59%    *** != 0xff972f9c
// ERROR: UIFS_WriteFirmInfoToFile is not found.           //--- ---    *** != 0x00000000
//NSTUB(kbd_pwr_off                           ,0xff84dc38) //  2 67%    *** != 0x00000000
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000
//NSTUB(rename                                ,0xff8255a0) //  1        *** != 0xff825e60
//NSTUB(srand                                 ,0xff81e828) //  1        *** != 0xff81bdb4
//NSTUB(write                                 ,0xff825e38) //101        *** != 0xff81a328

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff87c16c -> ff878420 -> ff971b64 -> ffa450e8 -> ffaefee8
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00011abc) // Found @0xff823990
DEF(physw_run                               ,0x00001cd8) // Found @0xff82366c
DEF(levent_table                            ,0xffac65dc) // Found @0xffac65dc
DEF(FlashParamsTable                        ,0xffaf0088) // Found @0xffaf0088
DEF(movie_status                            ,0x000058a0) // Found @0xff862c60
DEF(canon_menu_active                       ,0x00006e3c) // Found @0xff8970dc
DEF(canon_shoot_menu_active                 ,0x0000c05d) // Found @0xff982648
DEF(playrec_mode                            ,0x00005aa0) // Found @0xff869d1c
DEF(zoom_status                             ,0x000068f8) // Found @0xff886424
DEF(some_flag_for_af_scan                   ,0x0000ecbc) // Found @0xffa3e2bc
DEF(focus_busy                              ,0x0000b27c) // Found @0xff9507e0
//DEF(recreview_hold                          ,0x000067c4) // Found @0xff882ac8, ** != ** stubs_min = 0x0000be2c (0xBE2C)

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x10361000; }             // Found @0xff84a0b4
//void *vid_get_viewport_fb()      { return (void*)0x10d29360; }             // Found @0xffa104a0
//char *camera_jpeg_count_str()    { return (char*)0x00058304; }             // Found @0xff9be610
//long hook_raw_size()             { return 0x009dcce0; }                    // Found @0xffa11fa8
//int get_flash_params_count(void) { return 0x6f; }                          // Found @0xff973064

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffa9ceb8, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00200000 // Found @0xffa9ced8, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_SHOOT_FULL      ,0x00000003 }, // Found @0xffa9cdb0, levent 0x01
//    { 0, KEY_SHOOT_FULL_ONLY ,0x00000002 }, // Found @0xffa9cdb0, levent 0x01
//    { 0, KEY_SHOOT_HALF      ,0x00000001 }, // Found @0xffa9cda8, levent 0x00
//    { 1, KEY_LEFT            ,0x00001000 }, // Found @0xffa9ce28, levent 0x06
//    { 1, KEY_SET             ,0x00010000 }, // Found @0xffa9ce40, levent 0x08
//    { 1, KEY_DISPLAY         ,0x00020000 }, // Found @0xffa9ce48, levent 0x0a
//    { 1, KEY_MENU            ,0x00040000 }, // Found @0xffa9ce50, levent 0x09
//    { 1, KEY_DOWN            ,0x00080000 }, // Found @0xffa9ce58, levent 0x05
//    { 1, KEY_UP              ,0x00100000 }, // Found @0xffa9ce60, levent 0x04
//    { 1, KEY_RIGHT           ,0x00200000 }, // Found @0xffa9ce68, levent 0x07
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_RAW_ROWPIX    *** Not Found ***
//#define CAM_RAW_ROWS      *** Not Found ***
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x10000000 // Found @0xff82add8

// Misc stuff
DEF(ctypes, 0xffa9644e)

// For capt_seq.c
//static long *nrflag = (long*)(0xb704);       // Found @ ff9610bc

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NSTUB(AllocateMemory                          ,0xffa41170) //103
NSTUB(AllocateUncacheableMemory               ,0xff82ad9c) //112
NSTUB(Close                                   ,0xff825d8c) //101
NSTUB(CreateTask                              ,0xff81b9c4) //101
NSTUB(DebugAssert                             ,0xff81bd94) //111
NSTUB(DeleteDirectory_Fut                     ,0xff8256d8) //  1
NSTUB(DeleteFile_Fut                          ,0xff8255f4) //112
NSTUB(DoAFLock                                ,0xff827c90) //103
NSTUB(EnterToCompensationEVF                  ,0xff828070) //104
NSTUB(ExecuteEventProcedure                   ,0xff81bf64) //  1
NSTUB(ExitFromCompensationEVF                 ,0xff828164) //104
NSTUB(ExitTask                                ,0xff81bc54) //101
NSTUB(ExpCtrlTool_StartContiAE                ,0xff838ea0) //104
NSTUB(ExpCtrlTool_StopContiAE                 ,0xff838f48) //104
NSTUB(Fclose_Fut                              ,0xff825770) //101
NSTUB(Feof_Fut                                ,0xff82595c) //  1
NSTUB(Fflush_Fut                              ,0xff825998) //  1
NSTUB(Fgets_Fut                               ,0xff8258c4) //  1
NSTUB(Fopen_Fut                               ,0xff825730) //101
NSTUB(Fread_Fut                               ,0xff82581c) //101
NSTUB(FreeMemory                              ,0xffa4115c) //103
NSTUB(FreeUncacheableMemory                   ,0xff82add0) //112
NSTUB(Fseek_Fut                               ,0xff825910) //101
NSTUB(Fwrite_Fut                              ,0xff825870) //101
NSTUB(GetBatteryTemperature                   ,0xff85062c) //102
NSTUB(GetCCDTemperature                       ,0xff8505bc) //102
NSTUB(GetCurrentAvValue                       ,0xff952e5c) //102
NSTUB(GetDrive_ClusterSize                    ,0xff856dd0) //  1
NSTUB(GetDrive_FreeClusters                   ,0xff856e70) //  1
NSTUB(GetDrive_TotalClusters                  ,0xff856e04) //  1
NSTUB(GetFocusLensSubjectDistance             ,0xff95126c) //102
NSTUB(GetFocusLensSubjectDistanceFromLens     ,0xff951568) //  1
NSTUB(GetKbdState                             ,0xff84daec) //109
NSTUB(GetMemInfo                              ,0xff813ca8) //  1
NSTUB(GetOpticalTemperature                   ,0xff85069c) //102
NSTUB(GetParameterData                        ,0xff973028) //101
NSTUB(GetPropertyCase                         ,0xff874864) //101
NSTUB(GetSystemTime                           ,0xffa4126c) //  1
NSTUB(GiveSemaphore                           ,0xff81b930) //112
NSTUB(IsStrobeChargeCompleted                 ,0xff8db5fc) //102
NSTUB(LocalTime                               ,0xff8706cc) //  1
NSTUB(LockMainPower                           ,0xff877df8) //103
NSTUB(MakeDirectory_Fut                       ,0xff825668) //  1
NSTUB(MoveFocusLensToDistance                 ,0xffa0d4e4) //102
NSTUB(MoveIrisWithAv                          ,0xff9537b8) //102
NSTUB(MoveZoomLensWithPoint                   ,0xff957bfc) //102
NSTUB(NewTaskShell                            ,0xff874330) //103
NSTUB(Open                                    ,0xff825d64) //101
NSTUB(PB2Rec                                  ,0xff87b3e0) //104
NSTUB(PT_MoveDigitalZoomToWide                ,0xff86ba2c) //103
NSTUB(PT_MoveOpticalZoomAt                    ,0xff86b9f8) //103
NSTUB(PT_PlaySound                            ,0xff86b5a4) //103
NSTUB(PostLogicalEventForNotPowerType         ,0xff87617c) //103
NSTUB(PostLogicalEventToUI                    ,0xff8761c8) //103
NSTUB(PutInNdFilter                           ,0xffa0bdc8) //102
NSTUB(PutOutNdFilter                          ,0xffa0be00) //102
NSTUB(ReadFastDir                             ,0xffa279c8) //  1
NSTUB(Rec2PB                                  ,0xff87b420) //104
NSTUB(RefreshPhysicalScreen                   ,0xff8b2e58) //101
NSTUB(Remove                                  ,0xff825dd4) //  1
NSTUB(RenameFile_Fut                          ,0xff8255a0) //  1
NSTUB(Restart                                 ,0xff82cde4) //106
NSTUB(SetAE_ShutterSpeed                      ,0xffa0f680) //102
NSTUB(SetAutoShutdownTime                     ,0xff877f58) //103
NSTUB(SetCurrentCaptureModeType               ,0xff87f94c) //101
NSTUB(SetFileAttributes                       ,0xff8260b8) //  1
NSTUB(SetFileTimeStamp                        ,0xff826068) //  1
NSTUB(SetLogicalEventActive                   ,0xff877bb4) //  1
NSTUB(SetPropertyCase                         ,0xff874774) //101
NSTUB(SetScriptMode                           ,0xff877c04) //101
NSTUB(SleepTask                               ,0xff82ac20) //101
NSTUB(TakeSemaphore                           ,0xff81b860) //101
NSTUB(TurnOffBackLight                        ,0xff888468) //104
NSTUB(TurnOnBackLight                         ,0xff888450) //104
NSTUB(UnlockAF                                ,0xff827cfc) //103
NSTUB(UnlockMainPower                         ,0xff877d54) //103
NSTUB(UpdateMBROnFlash                        ,0xff856b98) //105
NSTUB(VbattGet                                ,0xff8222cc) //101
NSTUB(Write                                   ,0xff825e38) //101
NSTUB(WriteSDCard                             ,0xff9441ec) //108
NSTUB(_log                                    ,0xffa93fc0) //111
NSTUB(_log10                                  ,0xffa92f04) //112
NSTUB(_pow                                    ,0xffa93074) //114
NSTUB(_sqrt                                   ,0xffa95328) //  1
NSTUB(add_ptp_handler                         ,0xff8f048c) //  1
NSTUB(apex2us                                 ,0xff9caf14) //  4
NSTUB(close                                   ,0xff81a0e0) //  1
NSTUB(closedir                                ,0xffa27a98) //  1
NSTUB(err_init_task                           ,0xff814f00) //  4
NSTUB(exmem_alloc                             ,0xff8714ec) //101
NSTUB(free                                    ,0xff813b00) //112
NSTUB(kbd_p1_f                                ,0xff823a6c) //109
NSTUB(kbd_p1_f_cont                           ,0xff823a78) //109
NSTUB(kbd_p2_f                                ,0xff82330c) //109
NSTUB(kbd_read_keys                           ,0xff823990) //109
NSTUB(kbd_read_keys_r2                        ,0xff84d4ac) //109
NSTUB(lseek                                   ,0xff825ecc) //101
NSTUB(malloc                                  ,0xff813a2c) //112
NSTUB(memcmp                                  ,0xff81e72c) //101
NSTUB(memcpy                                  ,0xff8b32c8) //101
NSTUB(memset                                  ,0xffa64c5c) //101
NSTUB(mkdir                                   ,0xff826130) //  1
// ALT: NSTUB(mkdir, 0xff8261d0) // 1 32/0
NSTUB(mktime_ext                              ,0xff8b3b34) //  1
NSTUB(open                                    ,0xff81a030) //  1
NSTUB(opendir                                 ,0xffa27934) //  1
NSTUB(openfastdir                             ,0xffa27934) //  1
NSTUB(qsort                                   ,0xff9ca2ec) //  1
NSTUB(rand                                    ,0xff81e834) //  1
NSTUB(read                                    ,0xff81a2c8) //101
NSTUB(reboot_fw_update                        ,0xffa2f824) //  1
NSTUB(set_control_event                       ,0xff877988) //  1
NSTUB(stat                                    ,0xff825f98) //  1
NSTUB(strcat                                  ,0xff8b31f4) //  1
NSTUB(strchr                                  ,0xff8b327c) //  1
NSTUB(strcmp                                  ,0xff81e6c4) //101
NSTUB(strcpy                                  ,0xff81e670) //101
NSTUB(strftime                                ,0xff8b353c) //  1
NSTUB(strlen                                  ,0xff81e708) //101
NSTUB(strncmp                                 ,0xff8b3230) //  1
NSTUB(strncpy                                 ,0xff81e688) //  1
NSTUB(strrchr                                 ,0xff8b32a0) //  1
NSTUB(strtol                                  ,0xff831dac) //101
NSTUB(strtolx                                 ,0xff831bb0) //109
  DEF(task_CaptSeq                            ,0xff866d48) //107
  DEF(task_ExpDrv                             ,0xff8d3888) //110
  DEF(task_InitFileModules                    ,0xff87bff0) //107
  DEF(task_MovieRecord                        ,0xff862f10) //107
  DEF(task_PhySw                              ,0xff823668) //107
NSTUB(time                                    ,0xff870bd0) //  2
NSTUB(vsprintf                                ,0xff81e5f0) //  1
