// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R45 (DRYOS version 2.3, release #0045)
//   Firmware Ver GM1.00I
//   Canon PowerShot S95

// Values for makefile.inc
//   PLATFORMOSVER = 45
//   PLATFORMID = 12818 (0x3212) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x07ffffff
//   KEYSYS = d4b                // Found @ 0xffff3624
//   NEED_ENCODED_DISKBOOT = 5   // Found @ 0xffff3634

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NHSTUB(kbd_pwr_off                          ,0xff865728) //  2 60%    *** != 0x00000000
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff8a0c14 -> ff89d474 -> ff9ba948 -> ffb0f330 -> ffc722ac
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00034cb4) // Found @0xff83498c
DEF(physw_run                               ,0x00001c3c) // Found @0xff834580
DEF(physw_sleep_delay                       ,0x00001c44) // Found @0xff834580
DEF(levent_table                            ,0xffbf5dfc) // Found @0xffbf5dfc
DEF(FlashParamsTable                        ,0xffc724b4) // Found @0xffc724b4
DEF(movie_status                            ,0x0000716c) // Found @0xff986120
DEF(full_screen_refresh                     ,0x0000a0d4) // Found @0xffa47620
DEF(canon_menu_active                       ,0x00003250) // Found @0xff896fc0
DEF(canon_shoot_menu_active                 ,0x00008759) // Found @0xff9d7e04
DEF(playrec_mode                            ,0x00002f78) // Found @0xff88910c
DEF(zoom_status                             ,0x0000835c) // Found @0xff9c3390
DEF(some_flag_for_af_scan                   ,0x00007534) // Found @0xff9894c0
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 10 entries in the table - set NUM_FL to 10
DEF(focus_len_table                         ,0xfffe2d2c) // Found @0xfffe2d2c
DEF(zoom_busy                               ,0x00007084) // Found @0xff9809c4
DEF(focus_busy                              ,0x00006f30) // Found @0xff97bec4
//DEF(recreview_hold                          ,0x00003e14) // Found @0xff8a8648, ** != ** stubs_min = 0x000082e0 (0x81f8+0xE8)
DEF(palette_control                         ,0x0000a0d4) // Found @0xffa4759c
DEF(active_palette_buffer                   ,0x0000a0dc) // Found @0xffa475a0
DEF(palette_buffer                          ,0x000bc434) // Found @0xffa47ad4
DEF(bitmap_buffer                           ,0x0000a110) // Found @0xffa4c784
DEF(active_bitmap_buffer                    ,0x0000a108) // Found @0xffa4c788
DEF(viewport_buffers                        ,0xffba4228) // Found @0xff851d74
DEF(active_viewport_buffer                  ,0x000020ac) // Found @0xff851b40

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40471000; }             // Found @0xff85e704
//void *vid_get_viewport_fb()      { return (void*)0x40587700; }             // Found @0xffb61b74
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2c20+0x58)); } // Found @0xff87822c & 0xff878264
//char *camera_jpeg_count_str()    { return (char*)0x000bbc9c; }             // Found @0xffa3acd0
//long hook_raw_size()             { return 0x00ee9200; }                    // Found @0xffb65034
//int get_flash_params_count(void) { return 0x9a; }                          // Found @0xff9bbee0

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffba53ec, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x04000000 // Found @0xffba5414, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 1, KEY_ZOOM_IN         ,0x00000010 }, // Found @0xffba5354, levent 0x02
//    { 1, KEY_ZOOM_OUT        ,0x00000020 }, // Found @0xffba535c, levent 0x03
//    { 1, KEY_LEFT            ,0x00000100 }, // Found @0xffba5374, levent 0x06
//    { 1, KEY_RIGHT           ,0x00000200 }, // Found @0xffba537c, levent 0x07
//    { 1, KEY_DOWN            ,0x00000400 }, // Found @0xffba5384, levent 0x05
//    { 1, KEY_DISPLAY         ,0x00001000 }, // Found @0xffba5394, levent 0x0a
//    { 1, KEY_MENU            ,0x00002000 }, // Found @0xffba539c, levent 0x09
//    { 1, KEY_UP              ,0x00004000 }, // Found @0xffba53a4, levent 0x04
//    { 1, KEY_SET             ,0x00008000 }, // Found @0xffba53ac, levent 0x08
//    { 2, KEY_SHOOT_FULL      ,0x00000300 }, // Found @0xffba53bc, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000200 }, // Found @0xffba53bc, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000100 }, // Found @0xffba53b4, levent 0x00
//    { 2, KEY_POWER           ,0x00000400 }, // Found @0xffba53c4, levent 0x600
//    { 2, KEY_PLAYBACK        ,0x00000800 }, // Found @0xffba53cc, levent 0x601
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_RAW_ROWPIX    3744 // Found @0xff956f20
//#define CAM_RAW_ROWS      2784 // Found @0xff956f28
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff83ae0c

// Misc stuff
DEF(ctypes, 0xffba3b3e)

// For capt_seq.c
DEF(_nrflag,0x7584) // Found @ ff98e30c (0x757c) & ff98e340 (+0x08)
//static long *nrflag = (long*)(0x757c+0x08);  // Found @ ff98e30c & ff98e340
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
//NHSTUB(CreateJumptable                      ,0xffb651fc) //  1
//NHSTUB(_uartr_req                           ,0xff81fc5c) //111
//NHSTUB(AllocateMemory                       ,0xffafae8c) //101
NHSTUB(AllocateUncacheableMemory              ,0xff83adc8) //112
NHSTUB(Close                                  ,0xff837030) //101
NHSTUB(CreateTask                             ,0xff81e8a0) //101
NHSTUB(DebugAssert                            ,0xff81eb78) //111
NHSTUB(DeleteDirectory_Fut                    ,0xff836a8c) //116
NHSTUB(DeleteFile_Fut                         ,0xff8369a8) //112
NHSTUB(DoAFLock                               ,0xff8388a0) //102
NHSTUB(EnterToCompensationEVF                 ,0xff838b40) //104
NHSTUB(ExecuteEventProcedure                  ,0xff89270c) //104
NHSTUB(ExitFromCompensationEVF                ,0xff838be4) //104
NHSTUB(ExitTask                               ,0xff81eb30) //101
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff84734c) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff8474e4) //104
NHSTUB(Fclose_Fut                             ,0xff836b24) //101
NHSTUB(Feof_Fut                               ,0xff836d10) //  1
NHSTUB(Fflush_Fut                             ,0xff836d4c) //  1
NHSTUB(Fgets_Fut                              ,0xff836c78) //  1
NHSTUB(Fopen_Fut                              ,0xff836ae4) //101
NHSTUB(Fread_Fut                              ,0xff836bd0) //101
//NHSTUB(FreeMemory                           ,0xffafae84) //101
NHSTUB(FreeUncacheableMemory                  ,0xff83ae08) //112
NHSTUB(Fseek_Fut                              ,0xff836cc4) //101
NHSTUB(Fwrite_Fut                             ,0xff836c24) //101
NHSTUB(GetBatteryTemperature                  ,0xff869038) //102
NHSTUB(GetCCDTemperature                      ,0xff868fc4) //102
NHSTUB(GetCurrentAvValue                      ,0xff97e4b4) //102
NHSTUB(GetDrive_ClusterSize                   ,0xff8769c8) //  4
NHSTUB(GetDrive_FreeClusters                  ,0xff876a28) //  4
NHSTUB(GetDrive_TotalClusters                 ,0xff8769fc) //  3
NHSTUB(GetFocusLensSubjectDistance            ,0xff97cb44) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff97cf90) //  3
NHSTUB(GetImageFolder                         ,0xff95e84c) //106
NHSTUB(GetKbdState                            ,0xff8655f0) //109
NHSTUB(GetMemInfo                             ,0xff81a264) //115
NHSTUB(GetOpticalTemperature                  ,0xff8690ac) //102
NHSTUB(GetParameterData                       ,0xff9bbea4) //101
NHSTUB(GetPropertyCase                        ,0xff896414) //102
NHSTUB(GetSystemTime                          ,0xffafaee4) //101
NHSTUB(GetVRAMHPixelsSize                     ,0xff854118) //102
NHSTUB(GetVRAMVPixelsSize                     ,0xff854124) //102
NHSTUB(GetZoomLensCurrentPoint                ,0xff980d38) //102
NHSTUB(GetZoomLensCurrentPosition             ,0xffae90f4) //102
NHSTUB(GiveSemaphore                          ,0xff83a7e4) //112
NHSTUB(IsStrobeChargeCompleted                ,0xff8eae58) //102
NHSTUB(LEDDrive                               ,0xff86491c) //103
NHSTUB(LocalTime                              ,0xff88fff4) //115
NHSTUB(LockMainPower                          ,0xff89d078) //103
//NHSTUB(Lseek                                ,0xff83714c) //101
NHSTUB(MakeDirectory_Fut                      ,0xff836a1c) //116
NHSTUB(MoveFocusLensToDistance                ,0xffb5e59c) //102
NHSTUB(MoveIrisWithAv                         ,0xffaf7418) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xffaf7b04) //102
//NHSTUB(NewTaskShell                         ,0xff895e30) //103
NHSTUB(Open                                   ,0xff836fc4) //101
NHSTUB(PB2Rec                                 ,0xff8a0008) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff8806a4) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff88067c) //102
NHSTUB(PT_PlaySound                           ,0xff88b0a8) //  4
NHSTUB(PostLogicalEventForNotPowerType        ,0xff89aa88) //103
NHSTUB(PostLogicalEventToUI                   ,0xff89aad4) //103
NHSTUB(PutInNdFilter                          ,0xffb5c2bc) //102
NHSTUB(PutOutNdFilter                         ,0xffb5c2f4) //102
NHSTUB(Read                                   ,0xff81ad74) //101
NHSTUB(ReadFastDir                            ,0xffad413c) //  4
NHSTUB(Rec2PB                                 ,0xff8a0048) //104
NHSTUB(RefreshPhysicalScreen                  ,0xff8b6c8c) //104
//NHSTUB(Remove                               ,0xff837064) //  4
NHSTUB(RenameFile_Fut                         ,0xff836914) //116
NHSTUB(Restart                                ,0xff83c5b8) //106
NHSTUB(ScreenLock                             ,0xff8b7e50) //  4
NHSTUB(ScreenUnlock                           ,0xff8b7eb4) //  9
NHSTUB(SetAE_ShutterSpeed                     ,0xffb60cec) //102
NHSTUB(SetAutoShutdownTime                    ,0xff89d0ec) //103
NHSTUB(SetCurrentCaptureModeType              ,0xff8a5444) //101
NHSTUB(SetFileAttributes                      ,0xff837328) //  3
NHSTUB(SetFileTimeStamp                       ,0xff8372cc) //  4
NHSTUB(SetLogicalEventActive                  ,0xff89cdb4) //101
NHSTUB(SetParameterData                       ,0xff9bbd7c) //101
NHSTUB(SetPropertyCase                        ,0xff8962ec) //102
NHSTUB(SetScriptMode                          ,0xff89ce04) //101
NHSTUB(SleepTask                              ,0xff83aa4c) //101
NHSTUB(TakeSemaphore                          ,0xff83a714) //101
NHSTUB(TurnOffBackLight                       ,0xff8af278) //104
NHSTUB(TurnOnBackLight                        ,0xff8af260) //104
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff9a7d6c) //101
NHSTUB(UnlockAF                               ,0xff8388d8) //102
NHSTUB(UnlockMainPower                        ,0xff89cfcc) //103
NHSTUB(UnsetZoomForMovie                      ,0xff8ab114) //104
NHSTUB(UpdateMBROnFlash                       ,0xff876848) //105
NHSTUB(VbattGet                               ,0xff833188) //103
NHSTUB(Write                                  ,0xff8370c0) //101
NHSTUB(WriteSDCard                            ,0xff96dd64) //108
NHSTUB(_log                                   ,0xffba0c4c) //111
NHSTUB(_log10                                 ,0xffb9f8d8) //112
NHSTUB(_pow                                   ,0xffb9fa48) //114
NHSTUB(_sqrt                                  ,0xffba2854) //  1
NHSTUB(add_ptp_handler                        ,0xffa8e800) //  3
NHSTUB(apex2us                                ,0xffa50d94) //  4
NHSTUB(close                                  ,0xff81ab8c) //  1
NHSTUB(closedir                               ,0xffad3f98) //  4
NHSTUB(err_init_task                          ,0xff815fd4) //111
NHSTUB(exmem_alloc                            ,0xff890f40) //103
NHSTUB(exmem_free                             ,0xff890fb8) //103
NHSTUB(free                                   ,0xff814244) //112
NHSTUB(kbd_p1_f                               ,0xff834a04) //109
NHSTUB(kbd_p1_f_cont                          ,0xff834a10) //109
NHSTUB(kbd_p2_f                               ,0xff83424c) //109
NHSTUB(kbd_read_keys                          ,0xff83498c) //109
NHSTUB(kbd_read_keys_r2                       ,0xff864ee8) //109
NHSTUB(lseek                                  ,0xff83714c) //101
NHSTUB(malloc                                 ,0xff8141e8) //112
NHSTUB(memcmp                                 ,0xff8206e0) //101
NHSTUB(memcpy                                 ,0xff840588) //101
NHSTUB(memset                                 ,0xffa4fd7c) //101
NHSTUB(mkdir                                  ,0xff8374cc) //109
NHSTUB(mktime_ext                             ,0xff8b8c58) //  1
NHSTUB(open                                   ,0xff81aadc) //  1
NHSTUB(OpenFastDir                            ,0xffad3fe8) //  4
NHSTUB(qsort                                  ,0xffb4c038) //  4
NHSTUB(rand                                   ,0xffa4febc) //  4
//NHSTUB(read                                 ,0xff81ad74) //101
NHSTUB(realloc                                ,0xffa4fdf8) //115
NHSTUB(reboot_fw_update                       ,0xffad955c) //106
NHSTUB(set_control_event                      ,0xff89c9a4) //111
NHSTUB(srand                                  ,0xffa4feb0) //  4
NHSTUB(stat                                   ,0xff837194) //109
NHSTUB(strcat                                 ,0xff8b8414) //  1
NHSTUB(strchr                                 ,0xff8140b4) //  1
NHSTUB(strcmp                                 ,0xff82069c) //101
NHSTUB(strcpy                                 ,0xff820684) //101
NHSTUB(strftime                               ,0xff8b8660) //113
NHSTUB(strlen                                 ,0xff814100) //101
NHSTUB(strncmp                                ,0xff814068) //  1
NHSTUB(strncpy                                ,0xff81402c) //  1
NHSTUB(strrchr                                ,0xff8140d8) //  1
NHSTUB(strtol                                 ,0xff840868) //101
NHSTUB(strtolx                                ,0xff84066c) //109
   DEF(task_CaptSeq                           ,0xff88322c) //107
   DEF(task_ExpDrv                            ,0xff8cf1a8) //110
   DEF(task_FileWrite                         ,0xffad200c) //107
   DEF(task_InitFileModules                   ,0xff8a0aa0) //107
   DEF(task_MovieRecord                       ,0xff98642c) //107
   DEF(task_PhySw                             ,0xff83457c) //107
   DEF(task_RotaryEncoder                     ,0xff865894) //107
NHSTUB(time                                   ,0xff8905d4) //109
NHSTUB(vsprintf                               ,0xff820648) //115
//NHSTUB(write                                ,0xff8370c0) //101
//NHSTUB(EngDrvIn                             ,0xff835854) //102
//NHSTUB(EngDrvOut                            ,0xff83583c) //102
//NHSTUB(EngDrvRead                           ,0xff83585c) //102
//NHSTUB(EngDrvBits                           ,0xff835870) //102
//NHSTUB(GetSDProtect                         ,0xff834954) //103
//NHSTUB(StartRecModeMenu                     ,0xff896fbc) //102
//NHSTUB(DispCon_ShowBitmapColorBar           ,0xff85e6bc) //102
//NHSTUB(ResetZoomLens                        ,0xffaf7a58) //102
//NHSTUB(ResetFocusLens                       ,0xffaf66bc) //102
//NHSTUB(NR_GetDarkSubType                    ,0xff98e3b4) //102
//NHSTUB(NR_SetDarkSubType                    ,0xff98e304) //102
//NHSTUB(SavePaletteData                      ,0xffb63188) //102
//NHSTUB(GUISrv_StartGUISystem                ,0xff8b6484) //101
