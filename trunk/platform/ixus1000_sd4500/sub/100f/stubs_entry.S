// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R45 (DRYOS version 2.3, release #0045)
//   Firmware Ver GM1.00F
//   Canon IXUS 1000HS

// Values for makefile.inc
//   PLATFORMOSVER = 45
//   PLATFORMID = 12792 (0x31f8) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x07ffffff
//   MEMISOSTART = 0x00172bf8
//   KEYSYS = d4b                // Found @ 0xffff3624
//   NEED_ENCODED_DISKBOOT = 5   // Found @ 0xffff3634

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NHSTUB(kbd_pwr_off                          ,0xff8634d0) //  2 60%    *** != 0x00000000
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff8a0328 -> ff89cab4 -> ff9b0c78 -> ffaf48e0 -> ffc28d2c
// Mode 33320 in firmware but not in current modemap
// Mode 33322 in firmware but not in current modemap

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00034408) // Found @0xff834b8c
DEF(physw_run                               ,0x00001c40) // Found @0xff834758
DEF(physw_sleep_delay                       ,0x00001c48) // Found @0xff834758
DEF(levent_table                            ,0xffbcdb68) // Found @0xffbcdb68
DEF(FlashParamsTable                        ,0xffc28f30) // Found @0xffc28f30
DEF(movie_status                            ,0x000078dc) // Found @0xff985804
DEF(video_compression_rate                  ,0x0000791c) // Found @0xff985e74
DEF(full_screen_refresh                     ,0x0000a340) // Found @0xffa2bdf0
DEF(canon_menu_active                       ,0x00003840) // Found @0xff896954
DEF(canon_shoot_menu_active                 ,0x00008aed) // Found @0xff9c64a0
DEF(playrec_mode                            ,0x00003574) // Found @0xff888a38
//DEF(zoom_status                             ,0x0000e2c8) // Found @0xffaf7e64, ** != ** stubs_min = 0x0000e2a8 (0xE2A8)
DEF(some_flag_for_af_scan                   ,0x00007cb4) // Found @0xff9896e4
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 101 entries in the table - set NUM_FL to 101
DEF(focus_len_table                         ,0xfffe9eac) // Found @0xfffe9eac
DEF(zoom_busy                               ,0x00007618) // Found @0xff97a34c
DEF(focus_busy                              ,0x00007394) // Found @0xff972b30
//DEF(recreview_hold                          ,0x00004294) // Found @0xff8a8800, ** != ** stubs_min = 0x000087e8 (0x86FC+0xEC)
// Palette colour tables  found @ 0xffbe8cec
DEF(palette_control                         ,0x0000a340) // Found @0xffa2bd6c
DEF(active_palette_buffer                   ,0x0000a348) // Found @0xffa2bd70
DEF(palette_buffer_ptr                      ,0x0000a34c) // Found @0xffa2c294
DEF(palette_buffer                          ,0x000b84ac) // Found @0xffa2c2a4
// Offset from start of palette_buffer to color data = 8 (Found @0xffb2a74c)
DEF(bitmap_buffer                           ,0x0000a37c) // Found @0xffa30f54
DEF(active_bitmap_buffer                    ,0x0000a374) // Found @0xffa30f58
DEF(viewport_buffers                        ,0xffb8c55c) // Found @0xff851afc
DEF(active_viewport_buffer                  ,0x000020dc) // Found @0xff85183c
// Camera has 2 RAW buffers @ 0x4132cd20 & 0x46000000
//  Note: active buffer --> raw_buffers[ active_raw_buffer   *3]
//        other buffer  --> raw_buffers[(active_raw_buffer^1)*3]
DEF(raw_buffers                             ,0xffb8ed18) // Found @0xffb8ed18
DEF(active_raw_buffer                       ,0x000034d0) // Found @0xff8851f4

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40471000; }             // Found @0xff85d384
//void *vid_get_viewport_fb()      { return (void*)0x40587700; }             // Found @0xffb4cb30
DEF(viewport_fb_d                           ,0x00003288) // Found 0x3230 (@0xff877d10) + 0x58 (@0xff877d48)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x3230+0x58)); } // Found @0xff877d10 & 0xff877d48
DEF(jpeg_count_str                          ,0x000b7e00) // Found @0xffa2381c
//char *camera_jpeg_count_str()    { return (char*)0x000b7e00; }             // Found @0xffa2381c
//long hook_raw_size()             { return 0x00f32880; }                    // Found @0xffb4fff8
//int get_flash_params_count(void) { return 0x9a; }                          // Found @0xff9b1cb0

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffb8d54c, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00080000 // Found @0xffb8d55c, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 1, KEY_VIDEO           ,0x00000080 }, // Found @0xffb8d4ac, levent 0x12
//    { 1, KEY_UP              ,0x00000400 }, // Found @0xffb8d4c4, levent 0x04
//    { 1, KEY_RIGHT           ,0x00000800 }, // Found @0xffb8d4cc, levent 0x07
//    { 1, KEY_SET             ,0x00001000 }, // Found @0xffb8d4d4, levent 0x08
//    { 1, KEY_LEFT            ,0x00008000 }, // Found @0xffb8d4ec, levent 0x06
//    { 1, KEY_MENU            ,0x00010000 }, // Found @0xffb8d4f4, levent 0x09
//    { 1, KEY_DOWN            ,0x00020000 }, // Found @0xffb8d4fc, levent 0x05
//    { 2, KEY_SHOOT_FULL      ,0x00002002 }, // Found @0xffb8d51c, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00002000 }, // Found @0xffb8d534, levent 0x00
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000002 }, // Found @0xffb8d51c, levent 0x01
//    { 2, KEY_POWER           ,0x00000008 }, // Found @0xffb8d524, levent 0x600
//    { 2, KEY_PLAYBACK        ,0x00000100 }, // Found @0xffb8d52c, levent 0x601
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_RAW_ROWPIX    3816 // Found @0xff94b4c4
//#define CAM_RAW_ROWS      2784 // Found @0xff94b4d0
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff83b934

// Misc stuff
DEF(ctypes, 0xffb8bd6e)

// For capt_seq.c
DEF(_nrflag,0x7cf8) // Found @ ff98d814 (0x7cf0) & ff98d84c (+0x08)
//static long *nrflag = (long*)(0x7cf0+0x08);  // Found @ ff98d814 & ff98d84c
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
//NHSTUB(CreateJumptable                      ,0xffb501bc) //  1
//NHSTUB(_uartr_req                           ,0xff81fccc) //111
//NHSTUB(StartRecModeMenu                     ,0xff896950) //102
//NHSTUB(AllocateMemory                       ,0xffae569c) //101
NHSTUB(AllocateUncacheableMemory              ,0xff83b8f0) //112
NHSTUB(Close                                  ,0xff838060) //101
//NHSTUB(CreateBinarySemaphore                ,0xff83b0d0) //115
//NHSTUB(CreateCountingSemaphore              ,0xff83b138) //105
NHSTUB(CreateTask                             ,0xff81e8a0) //101
NHSTUB(DebugAssert                            ,0xff81eb78) //111
NHSTUB(DeleteDirectory_Fut                    ,0xff837abc) //116
NHSTUB(DeleteFile_Fut                         ,0xff8379d8) //112
//NHSTUB(DeleteSemaphore                      ,0xff83b190) //105
NHSTUB(DoAFLock                               ,0xff839670) //102
NHSTUB(EnterToCompensationEVF                 ,0xff839770) //104
NHSTUB(ExecuteEventProcedure                  ,0xff8920b4) //104
NHSTUB(ExitFromCompensationEVF                ,0xff8397b4) //104
NHSTUB(ExitTask                               ,0xff81eb30) //101
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff847d34) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff847ec0) //104
NHSTUB(Fclose_Fut                             ,0xff837b54) //101
NHSTUB(Feof_Fut                               ,0xff837d40) //  1
NHSTUB(Fflush_Fut                             ,0xff837d7c) //  1
NHSTUB(Fgets_Fut                              ,0xff837ca8) //  1
NHSTUB(Fopen_Fut                              ,0xff837b14) //101
NHSTUB(Fread_Fut                              ,0xff837c00) //101
//NHSTUB(FreeMemory                           ,0xffae5694) //101
NHSTUB(FreeUncacheableMemory                  ,0xff83b930) //112
NHSTUB(Fseek_Fut                              ,0xff837cf4) //101
NHSTUB(Fwrite_Fut                             ,0xff837c54) //101
NHSTUB(GetBatteryTemperature                  ,0xff868370) //102
NHSTUB(GetCCDTemperature                      ,0xff8682fc) //102
NHSTUB(GetCurrentAvValue                      ,0xff975264) //102
NHSTUB(GetDrive_ClusterSize                   ,0xff8757bc) //  4
NHSTUB(GetDrive_FreeClusters                  ,0xff87581c) //  4
NHSTUB(GetDrive_TotalClusters                 ,0xff8757f0) //  3
NHSTUB(GetFocusLensSubjectDistance            ,0xff973818) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff973c6c) //  3
NHSTUB(GetImageFolder                         ,0xff952d1c) //106
NHSTUB(GetKbdState                            ,0xff863398) //109
NHSTUB(GetMemInfo                             ,0xff81a264) //115
NHSTUB(GetOpticalTemperature                  ,0xff8683e4) //102
NHSTUB(GetParameterData                       ,0xff9b1c74) //101
NHSTUB(GetPropertyCase                        ,0xff895dbc) //102
NHSTUB(GetSystemTime                          ,0xffae56f4) //101
NHSTUB(GetVRAMHPixelsSize                     ,0xff854000) //102
NHSTUB(GetVRAMVPixelsSize                     ,0xff85400c) //102
NHSTUB(GetZoomLensCurrentPoint                ,0xff97ae10) //102
NHSTUB(GetZoomLensCurrentPosition             ,0xffacd188) //102
NHSTUB(GiveSemaphore                          ,0xff83b30c) //112
NHSTUB(IsStrobeChargeCompleted                ,0xff8e5d08) //102
NHSTUB(LEDDrive                               ,0xff86267c) //103
NHSTUB(LocalTime                              ,0xff88f99c) //115
NHSTUB(LockMainPower                          ,0xff89c6b8) //103
//NHSTUB(Lseek                                ,0xff83817c) //101
NHSTUB(MakeDirectory_Fut                      ,0xff837a4c) //116
NHSTUB(MoveFocusLensToDistance                ,0xffb4903c) //102
NHSTUB(MoveIrisWithAv                         ,0xffae04a4) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xffae0d20) //102
//NHSTUB(NewTaskShell                         ,0xff8957d8) //103
NHSTUB(Open                                   ,0xff837ff4) //101
NHSTUB(PB2Rec                                 ,0xff89f73c) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff880a80) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff880a58) //102
NHSTUB(PT_PlaySound                           ,0xff88a804) //  4
NHSTUB(PostLogicalEventForNotPowerType        ,0xff89a418) //103
NHSTUB(PostLogicalEventToUI                   ,0xff89a464) //103
NHSTUB(PutInNdFilter                          ,0xffb4643c) //102
NHSTUB(PutOutNdFilter                         ,0xffb46474) //102
NHSTUB(Read                                   ,0xff81ad74) //101
NHSTUB(ReadFastDir                            ,0xffab912c) //  4
NHSTUB(Rec2PB                                 ,0xff89dfe4) //104
NHSTUB(RefreshPhysicalScreen                  ,0xff8b3cfc) //104
//NHSTUB(Remove                               ,0xff838094) //  4
NHSTUB(RenameFile_Fut                         ,0xff837944) //116
NHSTUB(Restart                                ,0xff83d0dc) //106
NHSTUB(ScreenLock                             ,0xff8b4ec0) //117
NHSTUB(ScreenUnlock                           ,0xff8b4f24) //117
NHSTUB(SetAE_ShutterSpeed                     ,0xffb4bbdc) //102
NHSTUB(SetAutoShutdownTime                    ,0xff89c72c) //103
NHSTUB(SetCurrentCaptureModeType              ,0xff8a59d4) //101
NHSTUB(SetFileAttributes                      ,0xff838358) //  3
NHSTUB(SetFileTimeStamp                       ,0xff8382fc) //  4
NHSTUB(SetLogicalEventActive                  ,0xff89c3f4) //101
NHSTUB(SetParameterData                       ,0xff9b1be0) //101
NHSTUB(SetPropertyCase                        ,0xff895c94) //102
NHSTUB(SetScriptMode                          ,0xff89c444) //101
NHSTUB(SleepTask                              ,0xff83b574) //101
NHSTUB(TakeSemaphore                          ,0xff83b23c) //101
NHSTUB(TurnOffBackLight                       ,0xff8ac590) //104
NHSTUB(TurnOnBackLight                        ,0xff8ac578) //104
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff9a12dc) //103
NHSTUB(UnlockAF                               ,0xff8396a8) //102
NHSTUB(UnlockMainPower                        ,0xff89c60c) //103
NHSTUB(UpdateMBROnFlash                       ,0xff87563c) //105
NHSTUB(VbattGet                               ,0xff833308) //103
NHSTUB(Write                                  ,0xff8380f0) //101
NHSTUB(WriteSDCard                            ,0xff962f28) //108
NHSTUB(_log                                   ,0xffb88e7c) //111
NHSTUB(_log10                                 ,0xffb87b08) //112
NHSTUB(_pow                                   ,0xffb87c78) //114
NHSTUB(_sqrt                                  ,0xffb8aa84) //  1
NHSTUB(add_ptp_handler                        ,0xffa72adc) //  3
NHSTUB(apex2us                                ,0xffa34ec0) //  4
NHSTUB(close                                  ,0xff81ab8c) //  1
NHSTUB(closedir                               ,0xffab8f88) //  4
NHSTUB(err_init_task                          ,0xff815fd4) //111
NHSTUB(exmem_alloc                            ,0xff8908e8) //103
NHSTUB(exmem_free                             ,0xff890960) //103
NHSTUB(free                                   ,0xff814244) //112
NHSTUB(kbd_p1_f                               ,0xff834c04) //109
NHSTUB(kbd_p1_f_cont                          ,0xff834c10) //109
NHSTUB(kbd_p2_f                               ,0xff834424) //109
NHSTUB(kbd_read_keys                          ,0xff834b8c) //109
NHSTUB(kbd_read_keys_r2                       ,0xff862be4) //109
NHSTUB(lseek                                  ,0xff83817c) //101
NHSTUB(malloc                                 ,0xff8141e8) //112
NHSTUB(memcmp                                 ,0xff820750) //101
NHSTUB(memcpy                                 ,0xff84110c) //101
NHSTUB(memset                                 ,0xffa33ebc) //101
NHSTUB(mkdir                                  ,0xff8384fc) //109
NHSTUB(mktime_ext                             ,0xff8b5cc8) //  1
NHSTUB(open                                   ,0xff81aadc) //  1
NHSTUB(OpenFastDir                            ,0xffab8fd8) //  4
NHSTUB(qsort                                  ,0xffb2e208) //  4
NHSTUB(rand                                   ,0xffa33ffc) //  4
//NHSTUB(read                                 ,0xff81ad74) //101
NHSTUB(realloc                                ,0xffa33f38) //115
NHSTUB(reboot_fw_update                       ,0xffabe54c) //106
NHSTUB(set_control_event                      ,0xff89bfe4) //111
NHSTUB(srand                                  ,0xffa33ff0) //  4
NHSTUB(stat                                   ,0xff8381c4) //109
NHSTUB(strcat                                 ,0xff8b5484) //  1
NHSTUB(strchr                                 ,0xff8140b4) //  1
NHSTUB(strcmp                                 ,0xff82070c) //101
NHSTUB(strcpy                                 ,0xff8206f4) //101
NHSTUB(strftime                               ,0xff8b56d0) //113
NHSTUB(strlen                                 ,0xff814100) //101
NHSTUB(strncmp                                ,0xff814068) //  1
NHSTUB(strncpy                                ,0xff81402c) //  1
NHSTUB(strrchr                                ,0xff8140d8) //  1
NHSTUB(strtol                                 ,0xff8413ec) //101
NHSTUB(strtolx                                ,0xff8411f0) //109
   DEF(task_CaptSeq                           ,0xff883630) //110
   DEF(task_ExpDrv                            ,0xff8cca88) //110
   DEF(task_FileWrite                         ,0xffab7000) //110
   DEF(task_InitFileModules                   ,0xff8a01b4) //110
   DEF(task_MovieRecord                       ,0xff986664) //110
   DEF(task_PhySw                             ,0xff834754) //110
   DEF(task_RotaryEncoder                     ,0xff86363c) //110
NHSTUB(time                                   ,0xff88ff7c) //109
NHSTUB(vsprintf                               ,0xff8206b8) //115
//NHSTUB(write                                ,0xff8380f0) //101
//NHSTUB(EngDrvIn                             ,0xff835a54) //102
//NHSTUB(EngDrvOut                            ,0xff835a3c) //102
//NHSTUB(EngDrvRead                           ,0xff835a5c) //102
//NHSTUB(EngDrvBits                           ,0xff835a70) //102
//NHSTUB(_GetSystemTime                       ,0xff83bb9c) //109
//NHSTUB(SetTimerAfter                        ,0xff83bcd4) //119
//NHSTUB(SetTimerWhen                         ,0xff83bd54) //119
//NHSTUB(CancelTimer                          ,0xff83bdb8) //119
//NHSTUB(CancelHPTimer                        ,0xff89179c) //119
//NHSTUB(SetHPTimerAfterTimeout               ,0xff891714) //115
//NHSTUB(SetHPTimerAfterNow                   ,0xff891694) //119
//NHSTUB(CreateTaskStrictly                   ,0xff83b634) //107
//NHSTUB(CreateMessageQueue                   ,0xff83ad0c) //109
//NHSTUB(CreateRecursiveLock                  ,0xff88dd7c) //109
//NHSTUB(GetSemaphoreValue                    ,0xff83b344) //119
//NHSTUB(TryTakeSemaphore                     ,0xff83b1e8) //119
//NHSTUB(CreateMessageQueueStrictly           ,0xff83b668) //119
//NHSTUB(CreateEventFlagStrictly              ,0xff83b68c) //119
//NHSTUB(CreateBinarySemaphoreStrictly        ,0xff83b6b0) //119
//NHSTUB(CreateCountingSemaphoreStrictly      ,0xff83b6d4) //119
//NHSTUB(CreateRecursiveLockStrictly          ,0xff83b6f8) //119
//NHSTUB(TakeSemaphoreStrictly                ,0xff83b71c) //119
//NHSTUB(ReceiveMessageQueueStrictly          ,0xff83b748) //119
//NHSTUB(PostMessageQueueStrictly             ,0xff83b774) //119
//NHSTUB(WaitForAnyEventFlagStrictly          ,0xff83b7a0) //119
//NHSTUB(WaitForAllEventFlagStrictly          ,0xff83b7cc) //119
//NHSTUB(AcquireRecursiveLockStrictly         ,0xff83b7f8) //119
//NHSTUB(DeleteMessageQueue                   ,0xff83ad90) //119
//NHSTUB(PostMessageQueue                     ,0xff83af6c) //109
//NHSTUB(ReceiveMessageQueue                  ,0xff83ae20) //119
//NHSTUB(TryReceiveMessageQueue               ,0xff83aee8) //119
//NHSTUB(TryPostMessageQueue                  ,0xff83b024) //119
//NHSTUB(GetNumberOfPostedMessages            ,0xff83b064) //119
//NHSTUB(DeleteRecursiveLock                  ,0xff88ddcc) //119
//NHSTUB(AcquireRecursiveLock                 ,0xff88de1c) //119
//NHSTUB(ReleaseRecursiveLock                 ,0xff88df3c) //119
//NHSTUB(WaitForAnyEventFlag                  ,0xff88d9e8) //109
//NHSTUB(WaitForAllEventFlag                  ,0xff88dacc) //109
//NHSTUB(ClearEventFlag                       ,0xff88dbc0) //112
//NHSTUB(SetEventFlag                         ,0xff88db8c) //112
//NHSTUB(GetEventFlagValue                    ,0xff88dbf8) //119
//NHSTUB(CreateEventFlag                      ,0xff88d8b0) //109
//NHSTUB(DeleteEventFlag                      ,0xff88d908) //119
//NHSTUB(CheckAnyEventFlag                    ,0xff88d958) //119
//NHSTUB(CheckAllEventFlag                    ,0xff88d9a0) //119
//NHSTUB(RegisterInterruptHandler             ,0xff81e838) //107
//NHSTUB(UnregisterInterruptHandler           ,0xff81e85c) //119
//NHSTUB(GetSRAndDisableInterrupt             ,0xff81e874) //119
//NHSTUB(SetSR                                ,0xff81e878) //119
//NHSTUB(EnableInterrupt                      ,0xff81e898) //119
//NHSTUB(GetSDProtect                         ,0xff834b54) //103
//NHSTUB(DispCon_ShowBitmapColorBar           ,0xff85d33c) //102
//NHSTUB(ResetZoomLens                        ,0xffae0c74) //102
//NHSTUB(ResetFocusLens                       ,0xffadf920) //102
//NHSTUB(NR_GetDarkSubType                    ,0xff98d8cc) //102
//NHSTUB(NR_SetDarkSubType                    ,0xff98d80c) //102
//NHSTUB(SavePaletteData                      ,0xffb4e14c) //102
//NHSTUB(GUISrv_StartGUISystem                ,0xff8b34f4) //101
