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
//NSTUB(DoAFLock                              ,0xff8255ec) //102        *** != 0xff85e914
//NSTUB(EnterToCompensationEVF                ,0xff8256d8) //104        *** != 0x00000000
//NSTUB(ExitFromCompensationEVF               ,0xff82571c) //104        *** != 0x00000000
//NSTUB(UnlockAF                              ,0xff825624) //102        *** != 0xff85e924
//NSTUB(kbd_pwr_off                           ,0xff8470e4) //  2 64%    *** != 0x00000000
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
//NSTUB(CreateJumptable                       ,0xffa9f0d4) //  1
//NSTUB(_uartr_req                            ,0xff81c350) //111
//NSTUB(AllocateMemory                        ,0xffa485c4) //101
NSTUB(AllocateUncacheableMemory               ,0xff827700) //112
NSTUB(Close                                   ,0xff823cb0) //101
NSTUB(CreateTask                              ,0xff81afac) //101
NSTUB(DebugAssert                             ,0xff81b284) //111
NSTUB(DeleteDirectory_Fut                     ,0xff823640) //116
NSTUB(DeleteFile_Fut                          ,0xff82355c) //112
NSTUB(ExecuteEventProcedure                   ,0xff86df60) //104
NSTUB(ExitTask                                ,0xff81b23c) //101
NSTUB(ExpCtrlTool_StartContiAE                ,0xff83024c) //104
NSTUB(ExpCtrlTool_StopContiAE                 ,0xff830390) //104
NSTUB(Fclose_Fut                              ,0xff8236d8) //101
NSTUB(Feof_Fut                                ,0xff8238c4) //  1
NSTUB(Fflush_Fut                              ,0xff823900) //  1
NSTUB(Fgets_Fut                               ,0xff82382c) //  1
NSTUB(Fopen_Fut                               ,0xff823698) //101
NSTUB(Fread_Fut                               ,0xff823784) //101
//NSTUB(FreeMemory                            ,0xffa485bc) //101
NSTUB(FreeUncacheableMemory                   ,0xff827740) //112
NSTUB(Fseek_Fut                               ,0xff823878) //101
NSTUB(Fwrite_Fut                              ,0xff8237d8) //101
NSTUB(GetBatteryTemperature                   ,0xff849844) //102
NSTUB(GetCCDTemperature                       ,0xff8497d0) //102
NSTUB(GetCurrentAvValue                       ,0xff928378) //102
NSTUB(GetDrive_ClusterSize                    ,0xff855d3c) //  5
NSTUB(GetDrive_FreeClusters                   ,0xff855d94) //  5
NSTUB(GetDrive_TotalClusters                  ,0xff855d68) //  5
NSTUB(GetFocusLensSubjectDistance             ,0xff927428) //102
NSTUB(GetFocusLensSubjectDistanceFromLens     ,0xff927804) //  3
NSTUB(GetKbdState                             ,0xff8470cc) //109
NSTUB(GetMemInfo                              ,0xff813be4) //115
NSTUB(GetOpticalTemperature                   ,0xff8498b8) //102
NSTUB(GetParameterData                        ,0xff95a4bc) //101
NSTUB(GetPropertyCase                         ,0xff871ccc) //102
NSTUB(GetSystemTime                           ,0xffa4861c) //101
NSTUB(GetVRAMHPixelsSize                      ,0xff839b9c) //102
NSTUB(GetVRAMVPixelsSize                      ,0xff839ba8) //102
NSTUB(GetZoomLensCurrentPoint                 ,0xff92ba1c) //102
NSTUB(GetZoomLensCurrentPosition              ,0xffa3c378) //102
NSTUB(GiveSemaphore                           ,0xff82711c) //112
NSTUB(IsStrobeChargeCompleted                 ,0xff8a74bc) //102
NSTUB(LEDDrive                                ,0xff846818) //103
NSTUB(LocalTime                               ,0xff86b950) //115
NSTUB(LockMainPower                           ,0xff877d60) //103
//NSTUB(Lseek                                 ,0xff823df0) //101
NSTUB(MakeDirectory_Fut                       ,0xff8235d0) //116
NSTUB(MoveFocusLensToDistance                 ,0xffa98b5c) //102
NSTUB(MoveIrisWithAv                          ,0xffa46724) //102
NSTUB(MoveZoomLensWithPoint                   ,0xffa46cac) //102
//NSTUB(NewTaskShell                          ,0xff871770) //103
NSTUB(Open                                    ,0xff823c88) //101
NSTUB(PB2Rec                                  ,0xff87ad90) //104
NSTUB(PT_MoveDigitalZoomToWide                ,0xff85e8dc) //102
NSTUB(PT_MoveOpticalZoomAt                    ,0xff85e8b4) //102
NSTUB(PT_PlaySound                            ,0xff85e4ec) //102
NSTUB(PostLogicalEventForNotPowerType         ,0xff877388) //103
NSTUB(PostLogicalEventToUI                    ,0xff8773d4) //103
NSTUB(PutInNdFilter                           ,0xffa46b10) //102
NSTUB(PutOutNdFilter                          ,0xffa46b34) //102
NSTUB(Read                                    ,0xff819ae4) //101
NSTUB(ReadFastDir                             ,0xffa2a474) //  1
NSTUB(Rec2PB                                  ,0xff8797fc) //104
NSTUB(RefreshPhysicalScreen                   ,0xff9b96d0) //104
//NSTUB(Remove                                ,0xff823cf8) //  1
NSTUB(RenameFile_Fut                          ,0xff823508) //  1
NSTUB(Restart                                 ,0xff828e54) //106
NSTUB(SetAE_ShutterSpeed                      ,0xffa9b33c) //102
NSTUB(SetAutoShutdownTime                     ,0xff877dd4) //103
NSTUB(SetCurrentCaptureModeType               ,0xff87edec) //101
NSTUB(SetFileAttributes                       ,0xff823fdc) //  1
NSTUB(SetFileTimeStamp                        ,0xff823f8c) //  1
NSTUB(SetLogicalEventActive                   ,0xff877adc) //101
NSTUB(SetParameterData                        ,0xff95a42c) //101
NSTUB(SetPropertyCase                         ,0xff871bc4) //102
NSTUB(SetScriptMode                           ,0xff877b2c) //101
NSTUB(SleepTask                               ,0xff827384) //101
NSTUB(TakeSemaphore                           ,0xff82704c) //101
NSTUB(TurnOffBackLight                        ,0xff88527c) //104
NSTUB(TurnOnBackLight                         ,0xff885264) //104
NSTUB(UIFS_WriteFirmInfoToFile                ,0xff94656c) //101
NSTUB(UnlockMainPower                         ,0xff877cb4) //103
NSTUB(UnsetZoomForMovie                       ,0xff960e78) //104
NSTUB(UpdateMBROnFlash                        ,0xff855b94) //105
NSTUB(VbattGet                                ,0xff820690) //103
NSTUB(Write                                   ,0xff823d5c) //101
NSTUB(WriteSDCard                             ,0xff918b18) //108
NSTUB(_log                                    ,0xffacd640) //111
NSTUB(_log10                                  ,0xffacc2cc) //112
NSTUB(_pow                                    ,0xffacc43c) //114
NSTUB(_sqrt                                   ,0xffacf1e4) //  1
NSTUB(add_ptp_handler                         ,0xff9f4f54) //  3
NSTUB(apex2us                                 ,0xff9ba774) //  4
NSTUB(close                                   ,0xff8198fc) //  1
NSTUB(closedir                                ,0xffa2a544) //  1
NSTUB(err_init_task                           ,0xff814e2c) //111
NSTUB(exmem_alloc                             ,0xff86c810) //103
NSTUB(free                                    ,0xff813a3c) //112
NSTUB(kbd_p1_f                                ,0xff821e60) //109
NSTUB(kbd_p1_f_cont                           ,0xff821e6c) //109
NSTUB(kbd_p2_f                                ,0xff821724) //109
NSTUB(kbd_read_keys                           ,0xff821de4) //109
NSTUB(kbd_read_keys_r2                        ,0xff846b8c) //109
NSTUB(lseek                                   ,0xff823df0) //101
NSTUB(malloc                                  ,0xff813968) //112
NSTUB(memcmp                                  ,0xff81cc60) //101
NSTUB(memcpy                                  ,0xff88b7f4) //101
NSTUB(memset                                  ,0xff9b9a5c) //101
NSTUB(mkdir                                   ,0xff824054) //109
NSTUB(mktime_ext                              ,0xff88c060) //  1
NSTUB(open                                    ,0xff81984c) //  1
NSTUB(OpenFastDir                             ,0xffa2a3e0) //  1
NSTUB(qsort                                   ,0xffa83b3c) //  1
NSTUB(rand                                    ,0xff81cd68) //  1
//NSTUB(read                                  ,0xff819ae4) //101
NSTUB(reboot_fw_update                        ,0xffa31b24) //106
NSTUB(set_control_event                       ,0xff877810) //111
NSTUB(srand                                   ,0xff81cd5c) //  1
NSTUB(stat                                    ,0xff823ebc) //  1
NSTUB(strcat                                  ,0xff88b608) //  1
NSTUB(strchr                                  ,0xff88b690) //  1
NSTUB(strcmp                                  ,0xff81cbf8) //101
NSTUB(strcpy                                  ,0xff81cbe0) //101
NSTUB(strftime                                ,0xff88ba68) //  1
NSTUB(strlen                                  ,0xff81cc3c) //101
NSTUB(strncmp                                 ,0xff88b644) //  1
NSTUB(strncpy                                 ,0xff82d048) //  1
NSTUB(strrchr                                 ,0xff9b9a34) //  1
NSTUB(strtol                                  ,0xff82d280) //101
NSTUB(strtolx                                 ,0xff82d084) //109
  DEF(task_CaptSeq                            ,0xff860f34) //107
  DEF(task_ExpDrv                             ,0xff89dc5c) //110
  DEF(task_InitFileModules                    ,0xff87b84c) //107
  DEF(task_MovieRecord                        ,0xff92f5c8) //107
  DEF(task_PhySw                              ,0xff821a54) //107
NSTUB(time                                    ,0xff86bec8) //109
NSTUB(vsprintf                                ,0xff81cba4) //115
//NSTUB(write                                 ,0xff823d5c) //101
//NSTUB(GetSDProtect                          ,0xff821dbc) //103
//NSTUB(StartRecModeMenu                      ,0xff87281c) //102
//NSTUB(DispCon_ShowBitmapColorBar            ,0xff842d94) //102
//NSTUB(ResetZoomLens                         ,0xffa46c00) //102
//NSTUB(ResetFocusLens                        ,0xffa45b68) //102
//NSTUB(NR_GetDarkSubType                     ,0xff936abc) //102
//NSTUB(NR_SetDarkSubType                     ,0xff936a14) //102
//NSTUB(SavePaletteData                       ,0xffa9d458) //102
