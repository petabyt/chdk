// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R31 (DRYOS version 2.3, release #0031)
//   Firmware Ver GM1.00C
//   Canon PowerShot SX10 IS

// Values for makefile.inc
//   PLATFORMOSVER = 31
//   PLATFORMID = 12685 (0x318d) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x03ffffff
//   MEMISOSTART = 0x000acb74
//   KEYSYS = d4                 // Found @ 0xffff3570
//   NEED_ENCODED_DISKBOOT = 1   // Found @ 0xffff3580

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NHSTUB(kbd_pwr_off                          ,0xff84b810) //  2 60%    *** != 0x00000000
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff884bc0 -> ff881350 -> ff973e64 -> ffa79978 -> ffb74378
// Current modemap entry not found in firmware - MODE_VIDEO_STD            3622

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00011ec4) // Found @0xff821b14
DEF(physw_run                               ,0x00001c30) // Found @0xff821788
DEF(physw_sleep_delay                       ,0x00001c2e) // Found @0xff821788
DEF(levent_table                            ,0xffb4acb8) // Found @0xffb4acb8
DEF(FlashParamsTable                        ,0xffb7454c) // Found @0xffb7454c
DEF(movie_status                            ,0x00005430) // Found @0xff8642fc
DEF(video_compression_rate                  ,0x0000545c) // Found @0xff864508
DEF(canon_menu_active                       ,0x000058d8) // Found @0xff87a1e4
DEF(canon_shoot_menu_active                 ,0x0000ac29) // Found @0xff98cb14
DEF(playrec_mode                            ,0x00005640) // Found @0xff86d210
DEF(zoom_status                             ,0x0000e3e0) // Found @0xffa7b644
DEF(some_flag_for_af_scan                   ,0x00009b58) // Found @0xff94a2ac
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 1 int value, which is the the zoom focus length.
// there are 6 entries in the table - set NUM_FL to 6
DEF(focus_len_table                         ,0xffb77cd0) // Found @0xffb77cd0
DEF(zoom_busy                               ,0x00009100) // Found @0xff9407e8
DEF(focus_busy                              ,0x00008f8c) // Found @0xff9397fc
//DEF(recreview_hold                          ,0x0000645c) // Found @0xff88b558, ** != ** stubs_min = 0x0000a868 (0xA78C+0xDC)
// Camera has 2 RAW buffers @ 0x40f65b18 & 0x424f1948
//  Note: active buffer --> raw_buffers[ active_raw_buffer   *3]
//        other buffer  --> raw_buffers[(active_raw_buffer^1)*3]
DEF(raw_buffers                             ,0xffb0b4fc) // Found @0xffb0b4fc
DEF(active_raw_buffer                       ,0x000055e4) // Found @0xff86a564

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x403b1000; }             // Found @0xff846c28
//void *vid_get_viewport_fb()      { return (void*)0x4070d9d0; }             // Found @0xffad159c
DEF(viewport_fb_d                           ,0x000052b8) // Found 0x5260 (@0xff85c764) + 0x58 (@0xff85c79c)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x5260+0x58)); } // Found @0xff85c764 & 0xff85c79c
DEF(jpeg_count_str                          ,0x0004c138) // Found @0xff9d283c
//char *camera_jpeg_count_str()    { return (char*)0x0004c138; }             // Found @0xff9d283c
//long hook_raw_size()             { return 0x00ec04f0; }                    // Found @0xffad3a20
//int get_flash_params_count(void) { return 0x78; }                          // Found @0xff975464

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffb0ad4c, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00040000 // Found @0xffb0ad58, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_SHOOT_FULL      ,0x00000003 }, // Found @0xffb0abd8, levent 0x01
//    { 0, KEY_SHOOT_FULL_ONLY ,0x00000002 }, // Found @0xffb0abd8, levent 0x01
//    { 0, KEY_SHOOT_HALF      ,0x00000001 }, // Found @0xffb0abcc, levent 0x00
//    { 0, KEY_POWER           ,0x00002000 }, // Found @0xffb0abe4, levent 0x600
//    { 0, KEY_PLAYBACK        ,0x00004000 }, // Found @0xffb0abf0, levent 0x601
//    { 1, KEY_VIDEO           ,0x00000020 }, // Found @0xffb0ac50, levent 0x12
//    { 1, KEY_SET             ,0x00000100 }, // Found @0xffb0ac74, levent 0x08
//    { 1, KEY_DISPLAY         ,0x00000200 }, // Found @0xffb0ac80, levent 0x0a
//    { 1, KEY_UP              ,0x00000400 }, // Found @0xffb0ac8c, levent 0x04
//    { 1, KEY_DOWN            ,0x00000800 }, // Found @0xffb0ac98, levent 0x05
//    { 1, KEY_RIGHT           ,0x00001000 }, // Found @0xffb0aca4, levent 0x07
//    { 1, KEY_LEFT            ,0x00002000 }, // Found @0xffb0acb0, levent 0x06
//    { 1, KEY_MENU            ,0x00004000 }, // Found @0xffb0acbc, levent 0x09
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_RAW_ROWPIX    3720 // Found @0xffaca160
//#define CAM_RAW_ROWS      2772 // Found @0xffaca168
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff828010

// Misc stuff
DEF(ctypes, 0xffb04656)

// For capt_seq.c
DEF(_nrflag,0x9b40) // Found @ ff94c9a0 (0x9b44) & ff94c9bc (-0x04)
//static long *nrflag = (long*)(0x9b44-0x04);  // Found @ ff94c9a0 & ff94c9b8

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
//NHSTUB(CreateJumptable                      ,0xffad4380) //  1
//NHSTUB(_uartr_req                           ,0xff81c294) //111
//NHSTUB(StartRecModeMenu                     ,0xff87a1e0) //102
//NHSTUB(AllocateMemory                       ,0xffa67ae4) //101
NHSTUB(AllocateUncacheableMemory              ,0xff827fcc) //112
NHSTUB(Close                                  ,0xff823a64) //101
//NHSTUB(CreateBinarySemaphore                ,0xff8277ac) //115
//NHSTUB(CreateCountingSemaphore              ,0xff827814) //105
NHSTUB(CreateTask                             ,0xff81aef4) //101
NHSTUB(DebugAssert                            ,0xff81b1cc) //111
NHSTUB(DeleteDirectory_Fut                    ,0xff8233f4) //116
NHSTUB(DeleteFile_Fut                         ,0xff823310) //112
//NHSTUB(DeleteSemaphore                      ,0xff82786c) //105
NHSTUB(DoAFLock                               ,0xff825864) //102
NHSTUB(EnterToCompensationEVF                 ,0xff825b10) //104
NHSTUB(ExecuteEventProcedure                  ,0xff8759e8) //104
NHSTUB(ExitFromCompensationEVF                ,0xff825b54) //104
NHSTUB(ExitTask                               ,0xff81b184) //101
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff8311d8) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff83131c) //104
NHSTUB(Fclose_Fut                             ,0xff82348c) //101
NHSTUB(Feof_Fut                               ,0xff823678) //  1
NHSTUB(Fflush_Fut                             ,0xff8236b4) //  1
NHSTUB(Fgets_Fut                              ,0xff8235e0) //  1
NHSTUB(Fopen_Fut                              ,0xff82344c) //101
NHSTUB(Fread_Fut                              ,0xff823538) //101
//NHSTUB(FreeMemory                           ,0xffa67adc) //101
NHSTUB(FreeUncacheableMemory                  ,0xff82800c) //112
NHSTUB(Fseek_Fut                              ,0xff82362c) //101
NHSTUB(Fwrite_Fut                             ,0xff82358c) //101
NHSTUB(GetBatteryTemperature                  ,0xff84e658) //102
NHSTUB(GetCCDTemperature                      ,0xff84e5e8) //102
NHSTUB(GetCurrentAvValue                      ,0xff93be7c) //102
NHSTUB(GetDrive_ClusterSize                   ,0xff85ae90) //  1
NHSTUB(GetDrive_FreeClusters                  ,0xff85aef8) //  1
NHSTUB(GetDrive_TotalClusters                 ,0xff85aec4) //  1
NHSTUB(GetFocusLensSubjectDistance            ,0xff93a304) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff93a610) //  3
NHSTUB(GetKbdState                            ,0xff84b660) //109
NHSTUB(GetMemInfo                             ,0xff813c24) //115
NHSTUB(GetOpticalTemperature                  ,0xff84e6c8) //102
NHSTUB(GetParameterData                       ,0xff975424) //101
NHSTUB(GetPropertyCase                        ,0xff8796d0) //102
NHSTUB(GetSystemTime                          ,0xffa67b3c) //101
NHSTUB(GetVRAMHPixelsSize                     ,0xff83ccb4) //102
NHSTUB(GetVRAMVPixelsSize                     ,0xff83ccc0) //102
NHSTUB(GetZoomLensCurrentPoint                ,0xff941128) //102
NHSTUB(GetZoomLensCurrentPosition             ,0xffa5b23c) //102
NHSTUB(GiveSemaphore                          ,0xff8279e8) //112
NHSTUB(IsStrobeChargeCompleted                ,0xff8b69f8) //102
NHSTUB(LEDDrive                               ,0xff84ab48) //103
NHSTUB(LocalTime                              ,0xff873184) //115
NHSTUB(LockMainPower                          ,0xff880f68) //103
//NHSTUB(Lseek                                ,0xff823ba4) //101
NHSTUB(MakeDirectory_Fut                      ,0xff823384) //116
NHSTUB(MoveFocusLensToDistance                ,0xffacd91c) //102
NHSTUB(MoveIrisWithAv                         ,0xffa63110) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xffa63838) //102
//NHSTUB(NewTaskShell                         ,0xff879178) //103
NHSTUB(Open                                   ,0xff823a3c) //101
NHSTUB(PB2Rec                                 ,0xff883fd0) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff866084) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff86605c) //102
NHSTUB(PT_PlaySound                           ,0xff8659d4) //102
NHSTUB(PostLogicalEventForNotPowerType        ,0xff87ec94) //103
NHSTUB(PostLogicalEventToUI                   ,0xff87ece0) //103
NHSTUB(PutInNdFilter                          ,0xffa636bc) //102
NHSTUB(PutOutNdFilter                         ,0xffa636e0) //102
NHSTUB(Read                                   ,0xff819a4c) //101
NHSTUB(ReadFastDir                            ,0xffa49114) //  1
NHSTUB(Rec2PB                                 ,0xff882958) //104
NHSTUB(RefreshPhysicalScreen                  ,0xff9df030) //104
//NHSTUB(Remove                               ,0xff823aac) //  1
NHSTUB(RenameFile_Fut                         ,0xff8232bc) //  1
NHSTUB(Restart                                ,0xff829848) //106
NHSTUB(SetAE_ShutterSpeed                     ,0xffad07ac) //102
NHSTUB(SetAutoShutdownTime                    ,0xff880fdc) //103
NHSTUB(SetCurrentCaptureModeType              ,0xff8886ac) //101
NHSTUB(SetFileAttributes                      ,0xff823d90) //  1
NHSTUB(SetFileTimeStamp                       ,0xff823d40) //  1
NHSTUB(SetLogicalEventActive                  ,0xff880c28) //101
NHSTUB(SetParameterData                       ,0xff975300) //101
NHSTUB(SetPropertyCase                        ,0xff8795c8) //102
NHSTUB(SetScriptMode                          ,0xff880c78) //101
NHSTUB(SleepTask                              ,0xff827c50) //101
NHSTUB(TakeSemaphore                          ,0xff827918) //101
NHSTUB(TurnOffBackLight                       ,0xff88f284) //104
NHSTUB(TurnOnBackLight                        ,0xff88f26c) //104
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff963734) //103
NHSTUB(UnlockAF                               ,0xff82589c) //102
NHSTUB(UnlockMainPower                        ,0xff880ebc) //103
NHSTUB(UpdateMBROnFlash                       ,0xff85acd0) //105
NHSTUB(VbattGet                               ,0xff82046c) //103
NHSTUB(Write                                  ,0xff823b10) //101
NHSTUB(WriteSDCard                            ,0xff92a99c) //108
NHSTUB(_log                                   ,0xffb018d4) //111
NHSTUB(_log10                                 ,0xffb00560) //112
NHSTUB(_pow                                   ,0xffb006d0) //114
NHSTUB(_sqrt                                  ,0xffb03530) //  1
NHSTUB(add_ptp_handler                        ,0xffa1726c) //  3
NHSTUB(apex2us                                ,0xff9e0118) //  4
NHSTUB(close                                  ,0xff819864) //  1
NHSTUB(closedir                               ,0xffa491e4) //  1
NHSTUB(err_init_task                          ,0xff814e80) //111
NHSTUB(exmem_alloc                            ,0xff8740c4) //103
NHSTUB(exmem_free                             ,0xff87413c) //103
NHSTUB(free                                   ,0xff813a7c) //112
NHSTUB(kbd_p1_f                               ,0xff821c10) //109
NHSTUB(kbd_p1_f_cont                          ,0xff821c1c) //109
NHSTUB(kbd_p2_f                               ,0xff821428) //109
NHSTUB(kbd_read_keys                          ,0xff821b14) //109
NHSTUB(kbd_read_keys_r2                       ,0xff84af6c) //109
NHSTUB(lseek                                  ,0xff823ba4) //101
NHSTUB(malloc                                 ,0xff8139a8) //112
NHSTUB(memcmp                                 ,0xff81cba4) //101
NHSTUB(memcpy                                 ,0xff89ba80) //101
NHSTUB(memset                                 ,0xff9df450) //101
NHSTUB(mkdir                                  ,0xff823e08) //109
NHSTUB(mktime_ext                             ,0xff89c2ec) //  1
NHSTUB(open                                   ,0xff8197b4) //  1
NHSTUB(OpenFastDir                            ,0xffa49080) //  1
NHSTUB(qsort                                  ,0xffab814c) //  1
NHSTUB(rand                                   ,0xff81ccac) //  1
//NHSTUB(read                                 ,0xff819a4c) //101
NHSTUB(realloc                                ,0xff813b5c) //115
NHSTUB(reboot_fw_update                       ,0xffa50b14) //106
NHSTUB(set_control_event                      ,0xff880884) //111
NHSTUB(srand                                  ,0xff81cca0) //  1
NHSTUB(stat                                   ,0xff823c70) //  1
NHSTUB(strcat                                 ,0xff89b894) //  1
NHSTUB(strchr                                 ,0xff89b91c) //  1
NHSTUB(strcmp                                 ,0xff81cb3c) //101
NHSTUB(strcpy                                 ,0xff81cb24) //101
NHSTUB(strftime                               ,0xff89bcf4) //  1
NHSTUB(strlen                                 ,0xff81cb80) //101
NHSTUB(strncmp                                ,0xff89b8d0) //  1
NHSTUB(strncpy                                ,0xff82db14) //  1
NHSTUB(strrchr                                ,0xff9df428) //  1
NHSTUB(strtol                                 ,0xff82dd4c) //101
NHSTUB(strtolx                                ,0xff82db50) //109
   DEF(task_CaptSeq                           ,0xff868b90) //110
   DEF(task_ExpDrv                            ,0xff8ad7c4) //110
   DEF(task_FileWrite                         ,0xffa45a34) //110
   DEF(task_InitFileModules                   ,0xff884a4c) //110
   DEF(task_MovieRecord                       ,0xff864584) //110
   DEF(task_PhySw                             ,0xff821784) //110
   DEF(task_RotaryEncoder                     ,0xff84b8d8) //110
NHSTUB(time                                   ,0xff873764) //109
NHSTUB(vsprintf                               ,0xff81cae8) //115
//NHSTUB(write                                ,0xff823b10) //101
//NHSTUB(EngDrvIn                             ,0xff822a48) //102
//NHSTUB(EngDrvOut                            ,0xff822a30) //102
//NHSTUB(EngDrvRead                           ,0xff822a50) //102
//NHSTUB(EngDrvBits                           ,0xff822a64) //102
//NHSTUB(_GetSystemTime                       ,0xff828278) //109
//NHSTUB(SetTimerAfter                        ,0xff8283b0) //119
//NHSTUB(SetTimerWhen                         ,0xff828430) //119
//NHSTUB(CancelTimer                          ,0xff828494) //119
//NHSTUB(CancelHPTimer                        ,0xff874f24) //119
//NHSTUB(SetHPTimerAfterTimeout               ,0xff874e9c) //115
//NHSTUB(SetHPTimerAfterNow                   ,0xff874e1c) //119
//NHSTUB(CreateTaskStrictly                   ,0xff827d10) //107
//NHSTUB(CreateMessageQueue                   ,0xff8273e8) //109
//NHSTUB(CreateRecursiveLock                  ,0xff8715ec) //109
//NHSTUB(GetSemaphoreValue                    ,0xff827a20) //119
//NHSTUB(TryTakeSemaphore                     ,0xff8278c4) //119
//NHSTUB(CreateMessageQueueStrictly           ,0xff827d44) //119
//NHSTUB(CreateEventFlagStrictly              ,0xff827d68) //119
//NHSTUB(CreateBinarySemaphoreStrictly        ,0xff827d8c) //119
//NHSTUB(CreateCountingSemaphoreStrictly      ,0xff827db0) //119
//NHSTUB(CreateRecursiveLockStrictly          ,0xff827dd4) //119
//NHSTUB(TakeSemaphoreStrictly                ,0xff827df8) //119
//NHSTUB(ReceiveMessageQueueStrictly          ,0xff827e24) //119
//NHSTUB(PostMessageQueueStrictly             ,0xff827e50) //119
//NHSTUB(WaitForAnyEventFlagStrictly          ,0xff827e7c) //119
//NHSTUB(WaitForAllEventFlagStrictly          ,0xff827ea8) //119
//NHSTUB(AcquireRecursiveLockStrictly         ,0xff827ed4) //119
//NHSTUB(DeleteMessageQueue                   ,0xff82746c) //119
//NHSTUB(PostMessageQueue                     ,0xff827648) //109
//NHSTUB(ReceiveMessageQueue                  ,0xff8274fc) //119
//NHSTUB(TryReceiveMessageQueue               ,0xff8275c4) //119
//NHSTUB(TryPostMessageQueue                  ,0xff827700) //119
//NHSTUB(GetNumberOfPostedMessages            ,0xff827740) //119
//NHSTUB(DeleteRecursiveLock                  ,0xff87163c) //119
//NHSTUB(AcquireRecursiveLock                 ,0xff87168c) //119
//NHSTUB(ReleaseRecursiveLock                 ,0xff8717ac) //119
//NHSTUB(WaitForAnyEventFlag                  ,0xff871258) //109
//NHSTUB(WaitForAllEventFlag                  ,0xff87133c) //109
//NHSTUB(ClearEventFlag                       ,0xff871430) //112
//NHSTUB(SetEventFlag                         ,0xff8713fc) //112
//NHSTUB(GetEventFlagValue                    ,0xff871468) //119
//NHSTUB(CreateEventFlag                      ,0xff871120) //109
//NHSTUB(DeleteEventFlag                      ,0xff871178) //119
//NHSTUB(CheckAnyEventFlag                    ,0xff8711c8) //119
//NHSTUB(CheckAllEventFlag                    ,0xff871210) //119
//NHSTUB(GetSDProtect                         ,0xff821aec) //103
//NHSTUB(DispCon_ShowBitmapColorBar           ,0xff846bf4) //102
//NHSTUB(ResetZoomLens                        ,0xffa6378c) //102
//NHSTUB(ResetFocusLens                       ,0xffa62654) //102
//NHSTUB(NR_GetDarkSubType                    ,0xff94ddcc) //102
//NHSTUB(NR_SetDarkSubType                    ,0xff94dd20) //102
//NHSTUB(SavePaletteData                      ,0xffad2888) //102
