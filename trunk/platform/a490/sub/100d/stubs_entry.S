// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R43 (DRYOS version 2.3, release #0043)
//   Firmware Ver GM1.00D
//   Canon PowerShot A490

// Values for makefile.inc
//   PLATFORMOSVER = 43
//   PLATFORMID = 12784 (0x31f0) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x01ffffff
//   MEMISOSTART = 0x00129140
//   KEYSYS = d4a                // Found @ 0xffff1a0c
//   NEED_ENCODED_DISKBOOT = 4   // Found @ 0xffff1a1c

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
NHSTUB(kbd_pwr_off                            ,0xffc435ec) //  2 64%
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ffc705d8 -> ffc6d124 -> ffd2df78 -> ffe07c8c -> ffeca51c
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x0002e754) // Found @0xffc23b2c
DEF(physw_run                               ,0x00001bf0) // Found @0xffc23790
DEF(physw_sleep_delay                       ,0x00001bee) // Found @0xffc23790
DEF(levent_table                            ,0xffe9fe64) // Found @0xffe9fe64
DEF(FlashParamsTable                        ,0xffeca70c) // Found @0xffeca70c
DEF(movie_status                            ,0x00005470) // Found @0xffd0c5f4
DEF(full_screen_refresh                     ,0x000072e8) // Found @0xffd79414
DEF(canon_menu_active                       ,0x00002a3c) // Found @0xffc69fd8
DEF(canon_shoot_menu_active                 ,0x00006571) // Found @0xffd3f9c0
DEF(playrec_mode                            ,0x00002798) // Found @0xffc5d7d8
DEF(zoom_status                             ,0x000095a8) // Found @0xffe0ab68
DEF(some_flag_for_af_scan                   ,0x00005818) // Found @0xffd0ef60
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 7 entries in the table - set NUM_FL to 7
DEF(focus_len_table                         ,0xfffe2990) // Found @0xfffe2990
DEF(zoom_busy                               ,0x000053f0) // Found @0xffd09850
DEF(focus_busy                              ,0x00005300) // Found @0xffd06e88
DEF(recreview_hold                          ,0x0000302c) // Found @0xffc7578c
DEF(viewport_buffers                        ,0xffe88ea4) // Found @0xffcb5574
DEF(active_viewport_buffer                  ,0x000040f8) // Found @0xffcb53bc
// Camera appears to have only 1 RAW buffer @ 0x10e52420 (Found @0xffe56efc)

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x10361000; }             // Found @0xffc3f024
//void *vid_get_viewport_fb()      { return (void*)0x10648cc0; }             // Found @0xffe53bd0
DEF(viewport_fb_d                           ,0x00002594) // Found 0x2540 (@0xffc528c4) + 0x54 (@0xffc528fc)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2540+0x54)); } // Found @0xffc528c4 & 0xffc528fc
DEF(jpeg_count_str                          ,0x0007571c) // Found @0xffd70a4c
//char *camera_jpeg_count_str()    { return (char*)0x0007571c; }             // Found @0xffd70a4c
//long hook_raw_size()             { return 0x00ec04f0; }                    // Found @0xffe56f58
//int get_flash_params_count(void) { return 0x94; }                          // Found @0xffd2f034

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00040000 // Found @0xffe820bc, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00080000 // Found @0xffe820c8, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_PLAYBACK        ,0x00020000 }, // Found @0xffe82038, levent 0x601
//    { 0, KEY_POWER           ,0x00800000 }, // Found @0xffe82050, levent 0x600
//    { 2, KEY_RIGHT           ,0x00000004 }, // Found @0xffe8205c, levent 0x07
//    { 2, KEY_SHOOT_FULL      ,0x00000030 }, // Found @0xffe82074, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000020 }, // Found @0xffe82074, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000010 }, // Found @0xffe82068, levent 0x00
//    { 2, KEY_ZOOM_OUT        ,0x00000040 }, // Found @0xffe82080, levent 0x03
//    { 2, KEY_ZOOM_IN         ,0x00000080 }, // Found @0xffe8208c, levent 0x02
//    { 2, KEY_SET             ,0x00000100 }, // Found @0xffe82098, levent 0x08
//    { 2, KEY_UP              ,0x00100000 }, // Found @0xffe820d4, levent 0x04 (uses inverted logic in physw_status)
//    { 2, KEY_DOWN            ,0x00200000 }, // Found @0xffe820e0, levent 0x05 (uses inverted logic in physw_status)
//    { 2, KEY_LEFT            ,0x00400000 }, // Found @0xffe820ec, levent 0x06 (uses inverted logic in physw_status)
//    { 2, KEY_MENU            ,0x01000000 }, // Found @0xffe82104, levent 0x09 (uses inverted logic in physw_status)
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_RAW_ROWPIX    3720 // Found @0xffcea048
//#define CAM_RAW_ROWS      2772 // Found @0xffcea054
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x10000000 // Found @0xffc29320

// Misc stuff
DEF(ctypes, 0xffe81956)

// For capt_seq.c
DEF(_nrflag,0x57f8) // Found @ ffd10d74 (0x5800) & ffd10d94 (-0x08)
//static long *nrflag = (long*)(0x5800-0x08);  // Found @ ffd10d74 & ffd10d90

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
//NHSTUB(CreateJumptable                      ,0xffe57120) //  1
//NHSTUB(_uartr_req                           ,0xffc10744) //111
//NHSTUB(StartRecModeMenu                     ,0xffc69fd4) //102
//NHSTUB(AllocateMemory                       ,0xffdfa3a8) //101
NHSTUB(AllocateUncacheableMemory              ,0xffc292dc) //112
NHSTUB(Close                                  ,0xffc2610c) //101
//NHSTUB(CreateBinarySemaphore                ,0xffc0eec8) //115
//NHSTUB(CreateCountingSemaphore              ,0xffc0ef30) //105
NHSTUB(CreateTask                             ,0xffc0f1a8) //101
NHSTUB(DebugAssert                            ,0xffc0f680) //111
NHSTUB(DeleteDirectory_Fut                    ,0xffc25b68) //116
NHSTUB(DeleteFile_Fut                         ,0xffc25a84) //112
//NHSTUB(DeleteSemaphore                      ,0xffc0ef88) //105
NHSTUB(DoAFLock                               ,0xffc27558) //102
NHSTUB(EnterToCompensationEVF                 ,0xffc27608) //104
NHSTUB(ExecuteEventProcedure                  ,0xffc65748) //104
NHSTUB(ExitFromCompensationEVF                ,0xffc2764c) //104
NHSTUB(ExitTask                               ,0xffc0f438) //101
NHSTUB(ExpCtrlTool_StartContiAE               ,0xffc34ce8) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xffc34dc0) //104
NHSTUB(Fclose_Fut                             ,0xffc25c00) //101
NHSTUB(Feof_Fut                               ,0xffc25dec) //  1
NHSTUB(Fflush_Fut                             ,0xffc25e28) //  1
NHSTUB(Fgets_Fut                              ,0xffc25d54) //  1
NHSTUB(Fopen_Fut                              ,0xffc25bc0) //101
NHSTUB(Fread_Fut                              ,0xffc25cac) //101
//NHSTUB(FreeMemory                           ,0xffdfa3a0) //101
NHSTUB(FreeUncacheableMemory                  ,0xffc2931c) //112
NHSTUB(Fseek_Fut                              ,0xffc25da0) //101
NHSTUB(Fwrite_Fut                             ,0xffc25d00) //101
NHSTUB(GetBatteryTemperature                  ,0xffc45624) //102
NHSTUB(GetCCDTemperature                      ,0xffc455b0) //102
NHSTUB(GetCurrentAvValue                      ,0xffd08708) //102
NHSTUB(GetDrive_ClusterSize                   ,0xffc512bc) //  4
//NHSTUB(GetDrive_FreeClusters                ,0xffc5131c) //  4            == 0xffc5131c
NHSTUB(GetDrive_TotalClusters                 ,0xffc512f0) //  3
NHSTUB(GetFocusLensSubjectDistance            ,0xffd07a00) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xffd07e58) //  3
NHSTUB(GetImageFolder                         ,0xffcf1008) //106
NHSTUB(GetKbdState                            ,0xffc435d4) //109
NHSTUB(GetMemInfo                             ,0xffc0a7f8) //115
NHSTUB(GetOpticalTemperature                  ,0xffc4569c) //102
NHSTUB(GetParameterData                       ,0xffd2eff4) //101
NHSTUB(GetPropertyCase                        ,0xffc69454) //102
NHSTUB(GetSystemTime                          ,0xffdfa400) //101
NHSTUB(GetVRAMHPixelsSize                     ,0xffcb69ac) //102
NHSTUB(GetVRAMVPixelsSize                     ,0xffcb69b8) //102
NHSTUB(GetZoomLensCurrentPoint                ,0xffd09bc8) //102
NHSTUB(GetZoomLensCurrentPosition             ,0xffdf2444) //102
NHSTUB(GiveSemaphore                          ,0xffc0f104) //112
NHSTUB(IsStrobeChargeCompleted                ,0xffca6fa0) //102
NHSTUB(LEDDrive                               ,0xffc42bc8) //103
NHSTUB(LocalTime                              ,0xffc63458) //115
NHSTUB(LockMainPower                          ,0xffc6cd2c) //103
//NHSTUB(Lseek                                ,0xffc26228) //101
NHSTUB(MakeDirectory_Fut                      ,0xffc25af8) //116
NHSTUB(MoveFocusLensToDistance                ,0xffe50650) //102
NHSTUB(MoveIrisWithAv                         ,0xffdf7ae8) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xffdf8074) //102
//NHSTUB(NewTaskShell                         ,0xffc68e60) //103
NHSTUB(Open                                   ,0xffc260a0) //101
NHSTUB(PB2Rec                                 ,0xffc6f998) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xffc57098) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xffc57070) //102
NHSTUB(PT_PlaySound                           ,0xffc5f2d8) //  7
NHSTUB(PostLogicalEventForNotPowerType        ,0xffc6c55c) //103
NHSTUB(PostLogicalEventToUI                   ,0xffc6c5a8) //103
NHSTUB(PutInNdFilter                          ,0xffdf7ed8) //102
NHSTUB(PutOutNdFilter                         ,0xffdf7efc) //102
NHSTUB(Read                                   ,0xffc0b308) //101
NHSTUB(ReadFastDir                            ,0xffde8e40) //  4
NHSTUB(Rec2PB                                 ,0xffc6f9d8) //104
NHSTUB(RefreshPhysicalScreen                  ,0xffd79df0) //104
//NHSTUB(Remove                               ,0xffc26140) //  4
NHSTUB(RenameFile_Fut                         ,0xffc259f0) //116
NHSTUB(Restart                                ,0xffc2aab4) //106
NHSTUB(ScreenLock                             ,0xffd7af9c) //117
NHSTUB(ScreenUnlock                           ,0xffd7afe0) //117
NHSTUB(SetAE_ShutterSpeed                     ,0xffe52de0) //102
NHSTUB(SetAutoShutdownTime                    ,0xffc6cda0) //103
NHSTUB(SetCurrentCaptureModeType              ,0xffc730bc) //101
NHSTUB(SetFileAttributes                      ,0xffc26404) //  3
NHSTUB(SetFileTimeStamp                       ,0xffc263a8) //  4
NHSTUB(SetLogicalEventActive                  ,0xffc6caa4) //101
NHSTUB(SetParameterData                       ,0xffd2ef64) //101
NHSTUB(SetPropertyCase                        ,0xffc69324) //102
NHSTUB(SetScriptMode                          ,0xffc6caf4) //101
NHSTUB(SleepTask                              ,0xffc29160) //101
NHSTUB(TakeSemaphore                          ,0xffc0f034) //101
NHSTUB(TurnOffBackLight                       ,0xffc77d38) //104
NHSTUB(TurnOnBackLight                        ,0xffc77d20) //104
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xffd1f768) //101
NHSTUB(UnlockAF                               ,0xffc27590) //102
NHSTUB(UnlockMainPower                        ,0xffc6cc80) //103
NHSTUB(UnsetZoomForMovie                      ,0xffd354b4) //104
NHSTUB(UpdateMBROnFlash                       ,0xffc5113c) //105
NHSTUB(VbattGet                               ,0xffc22be4) //103
NHSTUB(Write                                  ,0xffc2619c) //101
NHSTUB(WriteSDCard                            ,0xffcfc6fc) //108
NHSTUB(_log                                   ,0xffe7f4b8) //111
NHSTUB(_log10                                 ,0xffe7e3fc) //112
NHSTUB(_pow                                   ,0xffe7e56c) //114
NHSTUB(_sqrt                                  ,0xffe80820) //  1
NHSTUB(add_ptp_handler                        ,0xffdbd2d4) //  3
NHSTUB(apex2us                                ,0xffd7c2ec) //  4
NHSTUB(close                                  ,0xffc0b120) //  1
NHSTUB(closedir                               ,0xffde8c9c) //  4
NHSTUB(err_init_task                          ,0xffc05f50) //111
NHSTUB(exmem_alloc                            ,0xffc640f8) //103
NHSTUB(exmem_free                             ,0xffc64170) //103
NHSTUB(free                                   ,0xffc04160) //112
NHSTUB(kbd_p1_f                               ,0xffc23ba8) //109
NHSTUB(kbd_p1_f_cont                          ,0xffc23bb4) //109
NHSTUB(kbd_p2_f                               ,0xffc2345c) //109
NHSTUB(kbd_read_keys                          ,0xffc23b2c) //109
NHSTUB(kbd_read_keys_r2                       ,0xffc42fb8) //109
NHSTUB(lseek                                  ,0xffc26228) //101
NHSTUB(malloc                                 ,0xffc04104) //112
NHSTUB(memcmp                                 ,0xffc11318) //101
NHSTUB(memcpy                                 ,0xffc2e864) //101
NHSTUB(memset                                 ,0xffd7b324) //101
NHSTUB(mkdir                                  ,0xffc265a8) //109
NHSTUB(mktime_ext                             ,0xffc7cb50) //  1
NHSTUB(open                                   ,0xffc0b070) //  1
NHSTUB(OpenFastDir                            ,0xffde8cec) //  4
NHSTUB(qsort                                  ,0xffe39368) //  4
NHSTUB(rand                                   ,0xffc11420) //  1
//NHSTUB(read                                 ,0xffc0b308) //101
NHSTUB(realloc                                ,0xffd7b3a0) //115
NHSTUB(reboot_fw_update                       ,0xffdea6b4) //106
NHSTUB(set_control_event                      ,0xffc6c7c4) //111
NHSTUB(srand                                  ,0xffc11414) //  1
NHSTUB(stat                                   ,0xffc26270) //109
NHSTUB(strcat                                 ,0xffc7c30c) //  1
NHSTUB(strchr                                 ,0xffc03fe8) //  1
NHSTUB(strcmp                                 ,0xffc112d4) //101
NHSTUB(strcpy                                 ,0xffc112bc) //101
NHSTUB(strftime                               ,0xffc7c558) //113
NHSTUB(strlen                                 ,0xffc04034) //101
NHSTUB(strncmp                                ,0xffc03f9c) //  1
NHSTUB(strncpy                                ,0xffc03f60) //  1
NHSTUB(strrchr                                ,0xffc0400c) //  1
NHSTUB(strtol                                 ,0xffc2eb44) //101
NHSTUB(strtolx                                ,0xffc2e948) //109
   DEF(task_CaptSeq                           ,0xffc5914c) //110
   DEF(task_ExpDrv                            ,0xffc91338) //110
   DEF(task_FileWrite                         ,0xffde3918) //110
   DEF(task_InitFileModules                   ,0xffc70464) //110
   DEF(task_MovieRecord                       ,0xffd0c848) //110
   DEF(task_PhySw                             ,0xffc2378c) //110
NHSTUB(time                                   ,0xffc6330c) //109
NHSTUB(vsprintf                               ,0xffc11280) //115
//NHSTUB(write                                ,0xffc2619c) //101
//NHSTUB(EngDrvIn                             ,0xffc249f4) //102
//NHSTUB(EngDrvOut                            ,0xffc249dc) //102
//NHSTUB(EngDrvRead                           ,0xffc249fc) //102
//NHSTUB(EngDrvBits                           ,0xffc24a10) //102
//NHSTUB(_GetSystemTime                       ,0xffc29588) //109
//NHSTUB(SetTimerAfter                        ,0xffc296c0) //119
//NHSTUB(SetTimerWhen                         ,0xffc29740) //119
//NHSTUB(CancelTimer                          ,0xffc297a4) //119
//NHSTUB(CancelHPTimer                        ,0xffc64e30) //119
//NHSTUB(SetHPTimerAfterTimeout               ,0xffc64da8) //115
//NHSTUB(SetHPTimerAfterNow                   ,0xffc64d28) //119
//NHSTUB(CreateTaskStrictly                   ,0xffc0f480) //107
//NHSTUB(CreateMessageQueue                   ,0xffc28990) //109
//NHSTUB(CreateRecursiveLock                  ,0xffc28d54) //109
//NHSTUB(GetSemaphoreValue                    ,0xffc0f13c) //119
//NHSTUB(TryTakeSemaphore                     ,0xffc0efe0) //119
//NHSTUB(CreateMessageQueueStrictly           ,0xffc0f4b4) //119
//NHSTUB(CreateEventFlagStrictly              ,0xffc0f4d8) //119
//NHSTUB(CreateBinarySemaphoreStrictly        ,0xffc0f4fc) //119
//NHSTUB(CreateCountingSemaphoreStrictly      ,0xffc0f520) //119
//NHSTUB(CreateRecursiveLockStrictly          ,0xffc0f544) //119
//NHSTUB(TakeSemaphoreStrictly                ,0xffc0f568) //119
//NHSTUB(ReceiveMessageQueueStrictly          ,0xffc0f594) //119
//NHSTUB(PostMessageQueueStrictly             ,0xffc0f5c0) //119
//NHSTUB(WaitForAnyEventFlagStrictly          ,0xffc0f5ec) //119
//NHSTUB(WaitForAllEventFlagStrictly          ,0xffc0f618) //119
//NHSTUB(AcquireRecursiveLockStrictly         ,0xffc0f644) //119
//NHSTUB(DeleteMessageQueue                   ,0xffc28a14) //119
//NHSTUB(PostMessageQueue                     ,0xffc28bf0) //109
//NHSTUB(ReceiveMessageQueue                  ,0xffc28aa4) //119
//NHSTUB(TryReceiveMessageQueue               ,0xffc28b6c) //119
//NHSTUB(TryPostMessageQueue                  ,0xffc28ca8) //119
//NHSTUB(GetNumberOfPostedMessages            ,0xffc28ce8) //119
//NHSTUB(DeleteRecursiveLock                  ,0xffc28da4) //119
//NHSTUB(AcquireRecursiveLock                 ,0xffc28df4) //119
//NHSTUB(ReleaseRecursiveLock                 ,0xffc28f14) //119
//NHSTUB(WaitForAnyEventFlag                  ,0xffc28670) //109
//NHSTUB(WaitForAllEventFlag                  ,0xffc28754) //109
//NHSTUB(ClearEventFlag                       ,0xffc28848) //112
//NHSTUB(SetEventFlag                         ,0xffc28814) //112
//NHSTUB(GetEventFlagValue                    ,0xffc28880) //119
//NHSTUB(CreateEventFlag                      ,0xffc28538) //109
//NHSTUB(DeleteEventFlag                      ,0xffc28590) //119
//NHSTUB(CheckAnyEventFlag                    ,0xffc285e0) //119
//NHSTUB(CheckAllEventFlag                    ,0xffc28628) //119
//NHSTUB(RegisterInterruptHandler             ,0xffc0ee60) //107
//NHSTUB(UnregisterInterruptHandler           ,0xffc0ee84) //119
//NHSTUB(GetSRAndDisableInterrupt             ,0xffc0ee9c) //119
//NHSTUB(SetSR                                ,0xffc0eea0) //119
//NHSTUB(EnableInterrupt                      ,0xffc0eec0) //119
//NHSTUB(GetSDProtect                         ,0xffc23b00) //103
//NHSTUB(DispCon_ShowBitmapColorBar           ,0xffc3eff0) //102
//NHSTUB(ResetZoomLens                        ,0xffdf7fc8) //102
//NHSTUB(ResetFocusLens                       ,0xffdf6fcc) //102
//NHSTUB(NR_GetDarkSubType                    ,0xffd12088) //102
//NHSTUB(NR_SetDarkSubType                    ,0xffd11fd8) //102
//NHSTUB(SavePaletteData                      ,0xffe55084) //102
//NHSTUB(GUISrv_StartGUISystem                ,0xffc7bd44) //101
