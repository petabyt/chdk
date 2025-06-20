// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R31 (DRYOS version 2.3, release #0031)
//   Firmware Ver GM1.00A
//   Canon PowerShot D10

// Values for makefile.inc
//   PLATFORMOSVER = 31
//   PLATFORMID = 12732 (0x31bc) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x03ffffff
//   KEYSYS = d4                 // Found @ 0xffff3564
//   NEED_ENCODED_DISKBOOT = 2   // Found @ 0xffff3574

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NHSTUB(DoAFLock                             ,0xff8255ec) //102        *** != 0xff85e914
//NHSTUB(EnterToCompensationEVF               ,0xff8256d8) //104        *** != 0x00000000
//NHSTUB(ExitFromCompensationEVF              ,0xff82571c) //104        *** != 0x00000000
//NHSTUB(UnlockAF                             ,0xff825624) //102        *** != 0xff85e924
//NHSTUB(exmem_free                           ,0xff86c888) //103        *** != 0xff86c7b0
//NHSTUB(kbd_pwr_off                          ,0xff8470e4) //  2 64%    *** != 0x00000000
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff87b9c0 -> ff878148 -> ff959440 -> ffa54a9c -> ffb32f18
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x0000e238) // Found @0xff821de4
DEF(physw_run                               ,0x00001c38) // Found @0xff821a58
DEF(physw_sleep_delay                       ,0x00001c36) // Found @0xff821a58
DEF(levent_table                            ,0xffb08638) // Found @0xffb08638
DEF(FlashParamsTable                        ,0xffb330f4) // Found @0xffb330f4
DEF(movie_status                            ,0x00005fe0) // Found @0xff92f390
DEF(canon_menu_active                       ,0x00002e2c) // Found @0xff872820
DEF(canon_shoot_menu_active                 ,0x00007405) // Found @0xff96b630
DEF(playrec_mode                            ,0x00002b8c) // Found @0xff865a74
DEF(zoom_status                             ,0x0000ad70) // Found @0xffa56cc8
DEF(some_flag_for_af_scan                   ,0x00006508) // Found @0xff932628
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 7 entries in the table - set NUM_FL to 7
DEF(focus_len_table                         ,0xfffe2a8c) // Found @0xfffe2a8c
DEF(zoom_busy                               ,0x00005f10) // Found @0xff92b6a0
DEF(focus_busy                              ,0x00005e08) // Found @0xff9265c0
//DEF(recreview_hold                          ,0x0000342c) // Found @0xff8819cc, ** != ** stubs_min = 0x00007174 (0x70B0+0xC4)

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x403f1000; }             // Found @0xff842dc8
//void *vid_get_viewport_fb()      { return (void*)0x40a05158; }             // Found @0xffa9c12c
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2884+0x58)); } // Found @0xff8575b4 & 0xff8575f4
//char *camera_jpeg_count_str()    { return (char*)0x000525e4; }             // Found @0xff9abbc0
//long hook_raw_size()             { return 0x011e4ee0; }                    // Found @0xffa9e694
//int get_flash_params_count(void) { return 0x7a; }                          // Found @0xff95a4fc

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffad634c, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00080000 // Found @0xffad6358, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 1, KEY_POWER           ,0x40000000 }, // Found @0xffad628c, levent 0x600
//    { 1, KEY_PLAYBACK        ,0x80000000 }, // Found @0xffad6298, levent 0x601
//    { 2, KEY_SHOOT_FULL      ,0x00000003 }, // Found @0xffad62b0, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000002 }, // Found @0xffad62b0, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000001 }, // Found @0xffad62a4, levent 0x00
//    { 2, KEY_ZOOM_IN         ,0x00000004 }, // Found @0xffad62bc, levent 0x02
//    { 2, KEY_ZOOM_OUT        ,0x00000008 }, // Found @0xffad62c8, levent 0x03
//    { 2, KEY_LEFT            ,0x00000010 }, // Found @0xffad62d4, levent 0x06
//    { 2, KEY_RIGHT           ,0x00000020 }, // Found @0xffad62e0, levent 0x07
//    { 2, KEY_DOWN            ,0x00000040 }, // Found @0xffad62ec, levent 0x05
//    { 2, KEY_UP              ,0x00000080 }, // Found @0xffad62f8, levent 0x04
//    { 2, KEY_SET             ,0x00000100 }, // Found @0xffad6304, levent 0x08
//    { 2, KEY_DISPLAY         ,0x00000200 }, // Found @0xffad6310, levent 0x0a
//    { 2, KEY_MENU            ,0x00000400 }, // Found @0xffad631c, levent 0x09
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_RAW_ROWPIX    4104 // Found @0xff8fb074
//#define CAM_RAW_ROWS      3048 // Found @0xff8fb07c
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff827744

// Misc stuff
DEF(ctypes, 0xffad03aa)

// For capt_seq.c
//static long *nrflag = (long*)(0x64f0-0x08);  // Found @ ff9345d0 & ff9345ec

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
//NHSTUB(CreateJumptable                      ,0xffa9f0d4) //  1
//NHSTUB(_uartr_req                           ,0xff81c350) //111
//NHSTUB(AllocateMemory                       ,0xffa485c4) //101
NHSTUB(AllocateUncacheableMemory              ,0xff827700) //112
NHSTUB(Close                                  ,0xff823cb0) //101
NHSTUB(CreateTask                             ,0xff81afac) //101
NHSTUB(DebugAssert                            ,0xff81b284) //111
NHSTUB(DeleteDirectory_Fut                    ,0xff823640) //116
NHSTUB(DeleteFile_Fut                         ,0xff82355c) //112
NHSTUB(ExecuteEventProcedure                  ,0xff86df60) //104
NHSTUB(ExitTask                               ,0xff81b23c) //101
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff83024c) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff830390) //104
NHSTUB(Fclose_Fut                             ,0xff8236d8) //101
NHSTUB(Feof_Fut                               ,0xff8238c4) //  1
NHSTUB(Fflush_Fut                             ,0xff823900) //  1
NHSTUB(Fgets_Fut                              ,0xff82382c) //  1
NHSTUB(Fopen_Fut                              ,0xff823698) //101
NHSTUB(Fread_Fut                              ,0xff823784) //101
//NHSTUB(FreeMemory                           ,0xffa485bc) //101
NHSTUB(FreeUncacheableMemory                  ,0xff827740) //112
NHSTUB(Fseek_Fut                              ,0xff823878) //101
NHSTUB(Fwrite_Fut                             ,0xff8237d8) //101
NHSTUB(GetBatteryTemperature                  ,0xff849844) //102
NHSTUB(GetCCDTemperature                      ,0xff8497d0) //102
NHSTUB(GetCurrentAvValue                      ,0xff928378) //102
NHSTUB(GetDrive_ClusterSize                   ,0xff855d3c) //  5
NHSTUB(GetDrive_FreeClusters                  ,0xff855d94) //  5
NHSTUB(GetDrive_TotalClusters                 ,0xff855d68) //  5
NHSTUB(GetFocusLensSubjectDistance            ,0xff927428) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff927804) //  3
NHSTUB(GetKbdState                            ,0xff8470cc) //109
NHSTUB(GetMemInfo                             ,0xff813be4) //115
NHSTUB(GetOpticalTemperature                  ,0xff8498b8) //102
NHSTUB(GetParameterData                       ,0xff95a4bc) //101
NHSTUB(GetPropertyCase                        ,0xff871ccc) //102
NHSTUB(GetSystemTime                          ,0xffa4861c) //101
NHSTUB(GetVRAMHPixelsSize                     ,0xff839b9c) //102
NHSTUB(GetVRAMVPixelsSize                     ,0xff839ba8) //102
NHSTUB(GetZoomLensCurrentPoint                ,0xff92ba1c) //102
NHSTUB(GetZoomLensCurrentPosition             ,0xffa3c378) //102
NHSTUB(GiveSemaphore                          ,0xff82711c) //112
NHSTUB(IsStrobeChargeCompleted                ,0xff8a74bc) //102
NHSTUB(LEDDrive                               ,0xff846818) //103
NHSTUB(LocalTime                              ,0xff86b950) //115
NHSTUB(LockMainPower                          ,0xff877d60) //103
//NHSTUB(Lseek                                ,0xff823df0) //101
NHSTUB(MakeDirectory_Fut                      ,0xff8235d0) //116
NHSTUB(MoveFocusLensToDistance                ,0xffa98b5c) //102
NHSTUB(MoveIrisWithAv                         ,0xffa46724) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xffa46cac) //102
//NHSTUB(NewTaskShell                         ,0xff871770) //103
NHSTUB(Open                                   ,0xff823c88) //101
NHSTUB(PB2Rec                                 ,0xff87ad90) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff85e8dc) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff85e8b4) //102
NHSTUB(PT_PlaySound                           ,0xff85e4ec) //102
NHSTUB(PostLogicalEventForNotPowerType        ,0xff877388) //103
NHSTUB(PostLogicalEventToUI                   ,0xff8773d4) //103
NHSTUB(PutInNdFilter                          ,0xffa46b10) //102
NHSTUB(PutOutNdFilter                         ,0xffa46b34) //102
NHSTUB(Read                                   ,0xff819ae4) //101
NHSTUB(ReadFastDir                            ,0xffa2a474) //  1
NHSTUB(Rec2PB                                 ,0xff8797fc) //104
NHSTUB(RefreshPhysicalScreen                  ,0xff9b96d0) //104
//NHSTUB(Remove                               ,0xff823cf8) //  1
NHSTUB(RenameFile_Fut                         ,0xff823508) //  1
NHSTUB(Restart                                ,0xff828e54) //106
NHSTUB(SetAE_ShutterSpeed                     ,0xffa9b33c) //102
NHSTUB(SetAutoShutdownTime                    ,0xff877dd4) //103
NHSTUB(SetCurrentCaptureModeType              ,0xff87edec) //101
NHSTUB(SetFileAttributes                      ,0xff823fdc) //  1
NHSTUB(SetFileTimeStamp                       ,0xff823f8c) //  1
NHSTUB(SetLogicalEventActive                  ,0xff877adc) //101
NHSTUB(SetParameterData                       ,0xff95a42c) //101
NHSTUB(SetPropertyCase                        ,0xff871bc4) //102
NHSTUB(SetScriptMode                          ,0xff877b2c) //101
NHSTUB(SleepTask                              ,0xff827384) //101
NHSTUB(TakeSemaphore                          ,0xff82704c) //101
NHSTUB(TurnOffBackLight                       ,0xff88527c) //104
NHSTUB(TurnOnBackLight                        ,0xff885264) //104
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff94656c) //101
NHSTUB(UnlockMainPower                        ,0xff877cb4) //103
NHSTUB(UnsetZoomForMovie                      ,0xff960e78) //104
NHSTUB(UpdateMBROnFlash                       ,0xff855b94) //105
NHSTUB(VbattGet                               ,0xff820690) //103
NHSTUB(Write                                  ,0xff823d5c) //101
NHSTUB(WriteSDCard                            ,0xff918b18) //108
NHSTUB(_log                                   ,0xffacd640) //111
NHSTUB(_log10                                 ,0xffacc2cc) //112
NHSTUB(_pow                                   ,0xffacc43c) //114
NHSTUB(_sqrt                                  ,0xffacf1e4) //  1
NHSTUB(add_ptp_handler                        ,0xff9f4f54) //  3
NHSTUB(apex2us                                ,0xff9ba774) //  4
NHSTUB(close                                  ,0xff8198fc) //  1
NHSTUB(closedir                               ,0xffa2a544) //  1
NHSTUB(err_init_task                          ,0xff814e2c) //111
NHSTUB(exmem_alloc                            ,0xff86c810) //103
NHSTUB(free                                   ,0xff813a3c) //112
NHSTUB(kbd_p1_f                               ,0xff821e60) //109
NHSTUB(kbd_p1_f_cont                          ,0xff821e6c) //109
NHSTUB(kbd_p2_f                               ,0xff821724) //109
NHSTUB(kbd_read_keys                          ,0xff821de4) //109
NHSTUB(kbd_read_keys_r2                       ,0xff846b8c) //109
NHSTUB(lseek                                  ,0xff823df0) //101
NHSTUB(malloc                                 ,0xff813968) //112
NHSTUB(memcmp                                 ,0xff81cc60) //101
NHSTUB(memcpy                                 ,0xff88b7f4) //101
NHSTUB(memset                                 ,0xff9b9a5c) //101
NHSTUB(mkdir                                  ,0xff824054) //109
NHSTUB(mktime_ext                             ,0xff88c060) //  1
NHSTUB(open                                   ,0xff81984c) //  1
NHSTUB(OpenFastDir                            ,0xffa2a3e0) //  1
NHSTUB(qsort                                  ,0xffa83b3c) //  1
NHSTUB(rand                                   ,0xff81cd68) //  1
//NHSTUB(read                                 ,0xff819ae4) //101
NHSTUB(realloc                                ,0xff813b1c) //115
NHSTUB(reboot_fw_update                       ,0xffa31b24) //106
NHSTUB(set_control_event                      ,0xff877810) //111
NHSTUB(srand                                  ,0xff81cd5c) //  1
NHSTUB(stat                                   ,0xff823ebc) //  1
NHSTUB(strcat                                 ,0xff88b608) //  1
NHSTUB(strchr                                 ,0xff88b690) //  1
NHSTUB(strcmp                                 ,0xff81cbf8) //101
NHSTUB(strcpy                                 ,0xff81cbe0) //101
NHSTUB(strftime                               ,0xff88ba68) //  1
NHSTUB(strlen                                 ,0xff81cc3c) //101
NHSTUB(strncmp                                ,0xff88b644) //  1
NHSTUB(strncpy                                ,0xff82d048) //  1
NHSTUB(strrchr                                ,0xff9b9a34) //  1
NHSTUB(strtol                                 ,0xff82d280) //101
NHSTUB(strtolx                                ,0xff82d084) //109
   DEF(task_CaptSeq                           ,0xff860f34) //107
   DEF(task_ExpDrv                            ,0xff89dc5c) //110
   DEF(task_InitFileModules                   ,0xff87b84c) //107
   DEF(task_MovieRecord                       ,0xff92f5c8) //107
   DEF(task_PhySw                             ,0xff821a54) //107
NHSTUB(time                                   ,0xff86bec8) //109
NHSTUB(vsprintf                               ,0xff81cba4) //115
//NHSTUB(write                                ,0xff823d5c) //101
//NHSTUB(EngDrvIn                             ,0xff822c94) //102
//NHSTUB(EngDrvOut                            ,0xff822c7c) //102
//NHSTUB(EngDrvRead                           ,0xff822c9c) //102
//NHSTUB(EngDrvBits                           ,0xff822cb0) //102
//NHSTUB(GetSDProtect                         ,0xff821dbc) //103
//NHSTUB(StartRecModeMenu                     ,0xff87281c) //102
//NHSTUB(DispCon_ShowBitmapColorBar           ,0xff842d94) //102
//NHSTUB(ResetZoomLens                        ,0xffa46c00) //102
//NHSTUB(ResetFocusLens                       ,0xffa45b68) //102
//NHSTUB(NR_GetDarkSubType                    ,0xff936abc) //102
//NHSTUB(NR_SetDarkSubType                    ,0xff936a14) //102
//NHSTUB(SavePaletteData                      ,0xffa9d458) //102
