// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R31 (DRYOS version 2.3, release #0031)
//   Firmware Ver GM1.00E
//   Canon DIGITAL IXUS 980 IS

// Values for makefile.inc
//   PLATFORMOSVER = 31
//   PLATFORMID = 12691 (0x3193) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x07ffffff
//   KEYSYS = d4                 // Found @ 0xffff363c
//   NEED_ENCODED_DISKBOOT = 1   // Found @ 0xffff364c

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NHSTUB(DoAFLock                             ,0xff8258d0) //102        *** != 0xff863a80
//NHSTUB(UnlockAF                             ,0xff825908) //102        *** != 0xff863a90
//NHSTUB(kbd_pwr_off                          ,0xff84a3a8) //  2 64%    *** != 0x00000000
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff8816a8 -> ff87de64 -> ff961a3c -> ffa58654 -> ffb49820
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00011318) // Found @0xff821c24
DEF(physw_run                               ,0x00001c28) // Found @0xff821898
DEF(physw_sleep_delay                       ,0x00001c26) // Found @0xff821898
DEF(levent_table                            ,0xffb198b0) // Found @0xffb198b0
DEF(FlashParamsTable                        ,0xffb499f4) // Found @0xffb499f4
DEF(movie_status                            ,0x000053dc) // Found @0xff861ed0
DEF(canon_menu_active                       ,0x00005830) // Found @0xff876e48
DEF(canon_shoot_menu_active                 ,0x0000a351) // Found @0xff973b2c
DEF(playrec_mode                            ,0x00005594) // Found @0xff869e90
DEF(zoom_status                             ,0x0000d890) // Found @0xffa59e68
DEF(some_flag_for_af_scan                   ,0x000093e0) // Found @0xff93be2c
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 8 entries in the table - set NUM_FL to 8
DEF(focus_len_table                         ,0xfffe2a8c) // Found @0xfffe2a8c
DEF(zoom_busy                               ,0x00008a1c) // Found @0xff93378c
DEF(focus_busy                              ,0x00008914) // Found @0xff92e770
//DEF(recreview_hold                          ,0x000061b8) // Found @0xff887648, ** != ** stubs_min = 0x0000a0a0 (0xA0A0)

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40471000; }             // Found @0xff845f24
//void *vid_get_viewport_fb()      { return (void*)0x407f6dc0; }             // Found @0xffaadbb8
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x5210+0x58)); } // Found @0xff85af1c & 0xff85af54
//char *camera_jpeg_count_str()    { return (char*)0x0004af18; }             // Found @0xff9b957c
//long hook_raw_size()             { return 0x01574d00; }                    // Found @0xffaaff70
//int get_flash_params_count(void) { return 0x78; }                          // Found @0xff962af8

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffae86d0, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00040000 // Found @0xffae86dc, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 1, KEY_POWER           ,0x40000000 }, // Found @0xffae8610, levent 0x600
//    { 1, KEY_PLAYBACK        ,0x80000000 }, // Found @0xffae861c, levent 0x601
//    { 2, KEY_SHOOT_FULL      ,0x00000003 }, // Found @0xffae8634, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000002 }, // Found @0xffae8634, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000001 }, // Found @0xffae8628, levent 0x00
//    { 2, KEY_ZOOM_IN         ,0x00000004 }, // Found @0xffae8640, levent 0x02
//    { 2, KEY_ZOOM_OUT        ,0x00000008 }, // Found @0xffae864c, levent 0x03
//    { 2, KEY_LEFT            ,0x00000010 }, // Found @0xffae8658, levent 0x06
//    { 2, KEY_RIGHT           ,0x00000020 }, // Found @0xffae8664, levent 0x07
//    { 2, KEY_DOWN            ,0x00000040 }, // Found @0xffae8670, levent 0x05
//    { 2, KEY_UP              ,0x00000080 }, // Found @0xffae867c, levent 0x04
//    { 2, KEY_SET             ,0x00000100 }, // Found @0xffae8688, levent 0x08
//    { 2, KEY_DISPLAY         ,0x00000200 }, // Found @0xffae8694, levent 0x0a
//    { 2, KEY_MENU            ,0x00000400 }, // Found @0xffae86a0, levent 0x09
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_RAW_ROWPIX    4480 // Found @0xffaa6e8c
//#define CAM_RAW_ROWS      3348 // Found @0xffaa6e90
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff827f80

// Misc stuff
DEF(ctypes, 0xffae283e)

// For capt_seq.c
//static long *nrflag = (long*)(0x93cc-0x04);  // Found @ ff93de40 & ff93de58

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
//NHSTUB(CreateJumptable                      ,0xffab06a4) //  1
//NHSTUB(_uartr_req                           ,0xff81c294) //111
//NHSTUB(AllocateMemory                       ,0xffa49a40) //101
NHSTUB(AllocateUncacheableMemory              ,0xff827f3c) //112
NHSTUB(Close                                  ,0xff823b74) //101
NHSTUB(CreateTask                             ,0xff81aef4) //101
NHSTUB(DebugAssert                            ,0xff81b1cc) //111
NHSTUB(DeleteDirectory_Fut                    ,0xff823504) //116
NHSTUB(DeleteFile_Fut                         ,0xff823420) //112
NHSTUB(EnterToCompensationEVF                 ,0xff825b7c) //104
NHSTUB(ExecuteEventProcedure                  ,0xff872670) //104
NHSTUB(ExitFromCompensationEVF                ,0xff825bc0) //104
NHSTUB(ExitTask                               ,0xff81b184) //101
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff8310e4) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff831228) //104
NHSTUB(Fclose_Fut                             ,0xff82359c) //101
NHSTUB(Feof_Fut                               ,0xff823788) //  1
NHSTUB(Fflush_Fut                             ,0xff8237c4) //  1
NHSTUB(Fgets_Fut                              ,0xff8236f0) //  1
NHSTUB(Fopen_Fut                              ,0xff82355c) //101
NHSTUB(Fread_Fut                              ,0xff823648) //101
//NHSTUB(FreeMemory                           ,0xffa49a38) //101
NHSTUB(FreeUncacheableMemory                  ,0xff827f7c) //112
NHSTUB(Fseek_Fut                              ,0xff82373c) //101
NHSTUB(Fwrite_Fut                             ,0xff82369c) //101
NHSTUB(GetBatteryTemperature                  ,0xff84ce3c) //102
NHSTUB(GetCCDTemperature                      ,0xff84cdcc) //102
NHSTUB(GetCurrentAvValue                      ,0xff9303b0) //102
NHSTUB(GetDrive_ClusterSize                   ,0xff859648) //  1
NHSTUB(GetDrive_FreeClusters                  ,0xff8596b0) //  1
NHSTUB(GetDrive_TotalClusters                 ,0xff85967c) //  1
NHSTUB(GetFocusLensSubjectDistance            ,0xff92f474) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff92f85c) //  3
NHSTUB(GetKbdState                            ,0xff84a390) //109
NHSTUB(GetMemInfo                             ,0xff813c24) //115
NHSTUB(GetOpticalTemperature                  ,0xff84ceac) //102
NHSTUB(GetParameterData                       ,0xff962ab8) //101
NHSTUB(GetPropertyCase                        ,0xff876358) //102
NHSTUB(GetSystemTime                          ,0xffa49a98) //101
NHSTUB(GetVRAMHPixelsSize                     ,0xff83c2a8) //102
NHSTUB(GetVRAMVPixelsSize                     ,0xff83c2b4) //102
NHSTUB(GetZoomLensCurrentPoint                ,0xff933afc) //102
NHSTUB(GetZoomLensCurrentPosition             ,0xffa4059c) //102
NHSTUB(GiveSemaphore                          ,0xff827958) //112
NHSTUB(IsStrobeChargeCompleted                ,0xff8b0638) //102
NHSTUB(LEDDrive                               ,0xff849b2c) //103
NHSTUB(LocalTime                              ,0xff86fe0c) //115
NHSTUB(LockMainPower                          ,0xff87da7c) //103
//NHSTUB(Lseek                                ,0xff823cb4) //101
NHSTUB(MakeDirectory_Fut                      ,0xff823494) //116
NHSTUB(MoveFocusLensToDistance                ,0xffaaa5fc) //102
NHSTUB(MoveIrisWithAv                         ,0xffa46ae4) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xffa4706c) //102
//NHSTUB(NewTaskShell                         ,0xff875e00) //103
NHSTUB(Open                                   ,0xff823b4c) //101
NHSTUB(PB2Rec                                 ,0xff880ac0) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff863a48) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff863a20) //102
NHSTUB(PT_PlaySound                           ,0xff863398) //102
NHSTUB(PostLogicalEventForNotPowerType        ,0xff87b858) //103
NHSTUB(PostLogicalEventToUI                   ,0xff87b8a4) //103
NHSTUB(PutInNdFilter                          ,0xffa46ed0) //102
NHSTUB(PutOutNdFilter                         ,0xffa46ef4) //102
NHSTUB(Read                                   ,0xff819a4c) //101
NHSTUB(ReadFastDir                            ,0xffa2eb80) //  1
NHSTUB(Rec2PB                                 ,0xff87f458) //104
NHSTUB(RefreshPhysicalScreen                  ,0xff9c7c94) //104
//NHSTUB(Remove                               ,0xff823bbc) //  1
NHSTUB(RenameFile_Fut                         ,0xff8233cc) //  1
NHSTUB(Restart                                ,0xff8297b0) //106
NHSTUB(SetAE_ShutterSpeed                     ,0xffaacdc8) //102
NHSTUB(SetAutoShutdownTime                    ,0xff87daf0) //103
NHSTUB(SetCurrentCaptureModeType              ,0xff884c28) //101
NHSTUB(SetFileAttributes                      ,0xff823ea0) //  1
NHSTUB(SetFileTimeStamp                       ,0xff823e50) //  1
NHSTUB(SetLogicalEventActive                  ,0xff87d7cc) //101
NHSTUB(SetParameterData                       ,0xff962a28) //101
NHSTUB(SetPropertyCase                        ,0xff876250) //102
NHSTUB(SetScriptMode                          ,0xff87d81c) //101
NHSTUB(SleepTask                              ,0xff827bc0) //101
NHSTUB(TakeSemaphore                          ,0xff827888) //101
NHSTUB(TurnOffBackLight                       ,0xff88aca0) //104
NHSTUB(TurnOnBackLight                        ,0xff88ac88) //104
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff953ba0) //101
NHSTUB(UnlockMainPower                        ,0xff87d9d0) //103
NHSTUB(UnsetZoomForMovie                      ,0xff9689ec) //104
NHSTUB(UpdateMBROnFlash                       ,0xff859488) //105
NHSTUB(VbattGet                               ,0xff820560) //103
NHSTUB(Write                                  ,0xff823c20) //101
NHSTUB(WriteSDCard                            ,0xff9210a4) //108
NHSTUB(_log                                   ,0xffadfabc) //111
NHSTUB(_log10                                 ,0xffade748) //112
NHSTUB(_pow                                   ,0xffade8b8) //114
NHSTUB(_sqrt                                  ,0xffae1718) //  1
NHSTUB(add_ptp_handler                        ,0xff9fbed8) //  3
NHSTUB(apex2us                                ,0xff9c8cb0) //  4
NHSTUB(close                                  ,0xff819864) //  1
NHSTUB(closedir                               ,0xffa2ec50) //  1
NHSTUB(err_init_task                          ,0xff814e80) //111
NHSTUB(exmem_alloc                            ,0xff870d4c) //103
NHSTUB(exmem_free                             ,0xff870dc4) //103
NHSTUB(free                                   ,0xff813a7c) //112
NHSTUB(kbd_p1_f                               ,0xff821d20) //109
NHSTUB(kbd_p1_f_cont                          ,0xff821d2c) //109
NHSTUB(kbd_p2_f                               ,0xff821538) //109
NHSTUB(kbd_read_keys                          ,0xff821c24) //109
NHSTUB(kbd_read_keys_r2                       ,0xff849f24) //109
NHSTUB(lseek                                  ,0xff823cb4) //101
NHSTUB(malloc                                 ,0xff8139a8) //112
NHSTUB(memcmp                                 ,0xff81cba4) //101
NHSTUB(memcpy                                 ,0xff8977a4) //101
NHSTUB(memset                                 ,0xff9c7fe8) //101
NHSTUB(mkdir                                  ,0xff823f18) //109
NHSTUB(mktime_ext                             ,0xff898010) //  1
NHSTUB(open                                   ,0xff8197b4) //  1
NHSTUB(OpenFastDir                            ,0xffa2eaec) //  1
NHSTUB(qsort                                  ,0xffa93dc0) //  1
NHSTUB(rand                                   ,0xff81ccac) //  1
//NHSTUB(read                                 ,0xff819a4c) //101
NHSTUB(realloc                                ,0xff813b5c) //115
NHSTUB(reboot_fw_update                       ,0xffa36580) //106
NHSTUB(set_control_event                      ,0xff87d448) //  1
NHSTUB(srand                                  ,0xff81cca0) //  1
NHSTUB(stat                                   ,0xff823d80) //  1
NHSTUB(strcat                                 ,0xff8975b8) //  1
NHSTUB(strchr                                 ,0xff897640) //  1
NHSTUB(strcmp                                 ,0xff81cb3c) //101
NHSTUB(strcpy                                 ,0xff81cb24) //101
NHSTUB(strftime                               ,0xff897a18) //  1
NHSTUB(strlen                                 ,0xff81cb80) //101
NHSTUB(strncmp                                ,0xff8975f4) //  1
NHSTUB(strncpy                                ,0xff82da50) //  1
NHSTUB(strrchr                                ,0xff9c7fc0) //  1
NHSTUB(strtol                                 ,0xff82dc88) //101
NHSTUB(strtolx                                ,0xff82da8c) //109
   DEF(task_CaptSeq                           ,0xff865f0c) //107
   DEF(task_ExpDrv                            ,0xff8a9554) //110
   DEF(task_InitFileModules                   ,0xff881534) //107
   DEF(task_MovieRecord                       ,0xff862148) //107
   DEF(task_PhySw                             ,0xff821894) //107
NHSTUB(time                                   ,0xff8703ec) //109
NHSTUB(vsprintf                               ,0xff81cae8) //115
//NHSTUB(write                                ,0xff823c20) //101
//NHSTUB(EngDrvIn                             ,0xff822b58) //102
//NHSTUB(EngDrvOut                            ,0xff822b40) //102
//NHSTUB(EngDrvRead                           ,0xff822b60) //102
//NHSTUB(EngDrvBits                           ,0xff822b74) //102
//NHSTUB(GetSDProtect                         ,0xff821bfc) //103
//NHSTUB(StartRecModeMenu                     ,0xff876e44) //102
//NHSTUB(DispCon_ShowBitmapColorBar           ,0xff845ef0) //102
//NHSTUB(ResetZoomLens                        ,0xffa46fc0) //102
//NHSTUB(ResetFocusLens                       ,0xffa45fd0) //102
//NHSTUB(NR_GetDarkSubType                    ,0xff93f250) //102
//NHSTUB(NR_SetDarkSubType                    ,0xff93f1a4) //102
//NHSTUB(SavePaletteData                      ,0xffaaee48) //102
