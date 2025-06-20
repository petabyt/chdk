// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R45 (DRYOS version 2.3, release #0045)
//   Firmware Ver GM1.00G
//   Canon PowerShot G12

// Values for makefile.inc
//   PLATFORMOSVER = 45
//   PLATFORMID = 12815 (0x320f) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x07ffffff
//   KEYSYS = d4b                // Found @ 0xffff36ac
//   NEED_ENCODED_DISKBOOT = 5   // Found @ 0xffff36bc

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NHSTUB(kbd_pwr_off                          ,0xff865690) //  2 60%    *** != 0x00000000
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff89fdf0 -> ff89c600 -> ff9bd794 -> ffb1ee44 -> ffc896dc
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00034474) // Found @0xff8349f4
DEF(physw_run                               ,0x00001c3c) // Found @0xff8345f0
DEF(physw_sleep_delay                       ,0x00001c44) // Found @0xff8345f0
DEF(levent_table                            ,0xffc0c01c) // Found @0xffc0c01c
DEF(FlashParamsTable                        ,0xffc898ec) // Found @0xffc898ec
DEF(movie_status                            ,0x000072d4) // Found @0xff986d88
DEF(full_screen_refresh                     ,0x0000a5dc) // Found @0xffa53cb4
DEF(canon_menu_active                       ,0x00003214) // Found @0xff896098
DEF(canon_shoot_menu_active                 ,0x00008afd) // Found @0xff9dc738
DEF(playrec_mode                            ,0x00002f38) // Found @0xff8880fc
DEF(zoom_status                             ,0x0000e590) // Found @0xffb2290c
DEF(some_flag_for_af_scan                   ,0x000076b4) // Found @0xff98a814
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 14 entries in the table - set NUM_FL to 14
DEF(focus_len_table                         ,0xfffe2a80) // Found @0xfffe2a80
DEF(zoom_busy                               ,0x000071e8) // Found @0xff98166c
DEF(focus_busy                              ,0x000070c0) // Found @0xff97d6c8
DEF(recreview_hold                          ,0x00003f50) // Found @0xff8a8134
DEF(palette_control                         ,0x0000a5dc) // Found @0xffa53c30
DEF(active_palette_buffer                   ,0x0000a5e4) // Found @0xffa53c34
DEF(palette_buffer                          ,0x000bbf5c) // Found @0xffa54168
DEF(bitmap_buffer                           ,0x0000a618) // Found @0xffa57bc0
DEF(active_bitmap_buffer                    ,0x0000a610) // Found @0xffa57bc4
DEF(viewport_buffers                        ,0xffbb83b8) // Found @0xff851f24
DEF(active_viewport_buffer                  ,0x000020ac) // Found @0xff851cf0

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40471000; }             // Found @0xff85ea60
//void *vid_get_viewport_fb()      { return (void*)0x40587700; }             // Found @0xffb75704
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2c10+0x58)); } // Found @0xff8781ac & 0xff8781e4
//char *camera_jpeg_count_str()    { return (char*)0x000bb618; }             // Found @0xffa43614
//long hook_raw_size()             { return 0x00ee9200; }                    // Found @0xffb78bc4
//int get_flash_params_count(void) { return 0x9a; }                          // Found @0xff9bed2c

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffbb95d4, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x04000000 // Found @0xffbb9604, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_ZOOM_IN         ,0x00000020 }, // Found @0xffbb94dc, levent 0x02
//    { 0, KEY_ZOOM_OUT        ,0x00000800 }, // Found @0xffbb950c, levent 0x03
//    { 0, KEY_LEFT            ,0x00001000 }, // Found @0xffbb9514, levent 0x06
//    { 0, KEY_SET             ,0x00002000 }, // Found @0xffbb951c, levent 0x08
//    { 0, KEY_RIGHT           ,0x00004000 }, // Found @0xffbb9524, levent 0x07
//    { 0, KEY_DOWN            ,0x00008000 }, // Found @0xffbb952c, levent 0x05
//    { 0, KEY_UP              ,0x00010000 }, // Found @0xffbb9534, levent 0x04
//    { 0, KEY_DISPLAY         ,0x00100000 }, // Found @0xffbb954c, levent 0x0a
//    { 0, KEY_MENU            ,0x00200000 }, // Found @0xffbb9554, levent 0x09
//    { 2, KEY_SHOOT_FULL      ,0x00000003 }, // Found @0xffbb95ac, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000002 }, // Found @0xffbb95ac, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000001 }, // Found @0xffbb95a4, levent 0x00
//    { 2, KEY_POWER           ,0x00000004 }, // Found @0xffbb95b4, levent 0x600 (uses inverted logic in physw_status)
//    { 2, KEY_PLAYBACK        ,0x00000008 }, // Found @0xffbb95bc, levent 0x601 (uses inverted logic in physw_status)
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_RAW_ROWPIX    3744 // Found @0xff9579d0
//#define CAM_RAW_ROWS      2784 // Found @0xff9579d8
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff83af74

// Misc stuff
DEF(ctypes, 0xffbb7cce)

// For capt_seq.c
DEF(_nrflag,0x7704) // Found @ ff98fae8 (0x76fc) & ff98fb1c (+0x08)
//static long *nrflag = (long*)(0x76fc+0x08);  // Found @ ff98fae8 & ff98fb1c
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
//NHSTUB(CreateJumptable                      ,0xffb78d8c) //  1
//NHSTUB(_uartr_req                           ,0xff81fc54) //111
//NHSTUB(AllocateMemory                       ,0xffb08e9c) //101
NHSTUB(AllocateUncacheableMemory              ,0xff83af30) //112
NHSTUB(Close                                  ,0xff8370e0) //101
NHSTUB(CreateTask                             ,0xff81e8a0) //101
NHSTUB(DebugAssert                            ,0xff81eb78) //111
NHSTUB(DeleteDirectory_Fut                    ,0xff836b3c) //116
NHSTUB(DeleteFile_Fut                         ,0xff836a58) //112
NHSTUB(DoAFLock                               ,0xff838940) //102
NHSTUB(EnterToCompensationEVF                 ,0xff838d24) //104
NHSTUB(ExecuteEventProcedure                  ,0xff8917a4) //104
NHSTUB(ExitFromCompensationEVF                ,0xff838d68) //104
NHSTUB(ExitTask                               ,0xff81eb30) //101
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff847454) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff8475ec) //104
NHSTUB(Fclose_Fut                             ,0xff836bd4) //101
NHSTUB(Feof_Fut                               ,0xff836dc0) //  1
NHSTUB(Fflush_Fut                             ,0xff836dfc) //  1
NHSTUB(Fgets_Fut                              ,0xff836d28) //  1
NHSTUB(Fopen_Fut                              ,0xff836b94) //101
NHSTUB(Fread_Fut                              ,0xff836c80) //101
//NHSTUB(FreeMemory                           ,0xffb08e94) //101
NHSTUB(FreeUncacheableMemory                  ,0xff83af70) //112
NHSTUB(Fseek_Fut                              ,0xff836d74) //101
NHSTUB(Fwrite_Fut                             ,0xff836cd4) //101
NHSTUB(GetBatteryTemperature                  ,0xff868f80) //102
NHSTUB(GetCCDTemperature                      ,0xff868f0c) //102
NHSTUB(GetCurrentAvValue                      ,0xff97fcb8) //102
NHSTUB(GetDrive_ClusterSize                   ,0xff876948) //  4
NHSTUB(GetDrive_FreeClusters                  ,0xff8769a8) //  4
NHSTUB(GetDrive_TotalClusters                 ,0xff87697c) //  3
NHSTUB(GetFocusLensSubjectDistance            ,0xff97e348) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff97e794) //  3
NHSTUB(GetImageFolder                         ,0xff95f2fc) //106
NHSTUB(GetKbdState                            ,0xff865678) //109
NHSTUB(GetMemInfo                             ,0xff81a264) //115
NHSTUB(GetOpticalTemperature                  ,0xff868ff4) //102
NHSTUB(GetParameterData                       ,0xff9becf0) //101
NHSTUB(GetPropertyCase                        ,0xff8954f0) //102
NHSTUB(GetSystemTime                          ,0xffb08ef4) //101
NHSTUB(GetVRAMHPixelsSize                     ,0xff854320) //102
NHSTUB(GetVRAMVPixelsSize                     ,0xff85432c) //102
NHSTUB(GetZoomLensCurrentPoint                ,0xff9819e0) //102
NHSTUB(GetZoomLensCurrentPosition             ,0xffaf6880) //102
NHSTUB(GiveSemaphore                          ,0xff83a94c) //112
NHSTUB(IsStrobeChargeCompleted                ,0xff8ea5f0) //102
NHSTUB(LEDDrive                               ,0xff8647ec) //103
NHSTUB(LocalTime                              ,0xff88f08c) //115
NHSTUB(LockMainPower                          ,0xff89c204) //103
//NHSTUB(Lseek                                ,0xff8371fc) //101
NHSTUB(MakeDirectory_Fut                      ,0xff836acc) //116
NHSTUB(MoveFocusLensToDistance                ,0xffb72134) //102
NHSTUB(MoveIrisWithAv                         ,0xffb04a34) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xffb051c4) //102
//NHSTUB(NewTaskShell                         ,0xff894f0c) //103
NHSTUB(Open                                   ,0xff837074) //101
NHSTUB(PB2Rec                                 ,0xff89f18c) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff87f5c0) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff87f598) //102
NHSTUB(PT_PlaySound                           ,0xff88a140) //  4
NHSTUB(PostLogicalEventForNotPowerType        ,0xff899b70) //103
NHSTUB(PostLogicalEventToUI                   ,0xff899bbc) //103
NHSTUB(PutInNdFilter                          ,0xffb05028) //102
NHSTUB(PutOutNdFilter                         ,0xffb0504c) //102
NHSTUB(Read                                   ,0xff81ad74) //101
NHSTUB(ReadFastDir                            ,0xffae2c20) //  4
NHSTUB(Rec2PB                                 ,0xff89f1cc) //104
NHSTUB(RefreshPhysicalScreen                  ,0xff8b3a68) //104
//NHSTUB(Remove                               ,0xff837114) //  4
NHSTUB(RenameFile_Fut                         ,0xff8369c4) //116
NHSTUB(Restart                                ,0xff83c71c) //106
NHSTUB(ScreenLock                             ,0xff8b4c98) //  4
NHSTUB(ScreenUnlock                           ,0xff8b4cfc) //  3
NHSTUB(SetAE_ShutterSpeed                     ,0xffb7487c) //102
NHSTUB(SetAutoShutdownTime                    ,0xff89c278) //103
NHSTUB(SetCurrentCaptureModeType              ,0xff8a4d44) //101
NHSTUB(SetFileAttributes                      ,0xff8373d8) //  3
NHSTUB(SetFileTimeStamp                       ,0xff83737c) //  4
NHSTUB(SetLogicalEventActive                  ,0xff89bf40) //101
NHSTUB(SetParameterData                       ,0xff9bebc8) //101
NHSTUB(SetPropertyCase                        ,0xff8953c8) //102
NHSTUB(SetScriptMode                          ,0xff89bf90) //101
NHSTUB(SleepTask                              ,0xff83abb4) //101
NHSTUB(TakeSemaphore                          ,0xff83a87c) //101
NHSTUB(TurnOffBackLight                       ,0xff8abd94) //104
NHSTUB(TurnOnBackLight                        ,0xff8abd7c) //104
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff9a9e9c) //101
NHSTUB(UnlockAF                               ,0xff838978) //102
NHSTUB(UnlockMainPower                        ,0xff89c158) //103
NHSTUB(UnsetZoomForMovie                      ,0xff9c57dc) //104
NHSTUB(UpdateMBROnFlash                       ,0xff8767c8) //105
NHSTUB(VbattGet                               ,0xff833180) //103
NHSTUB(Write                                  ,0xff837170) //101
NHSTUB(WriteSDCard                            ,0xff96e820) //108
NHSTUB(_log                                   ,0xffbb4ddc) //111
NHSTUB(_log10                                 ,0xffbb3a68) //112
NHSTUB(_pow                                   ,0xffbb3bd8) //114
NHSTUB(_sqrt                                  ,0xffbb69e4) //  1
NHSTUB(add_ptp_handler                        ,0xffa9d218) //  3
NHSTUB(apex2us                                ,0xffa5c248) //  4
NHSTUB(close                                  ,0xff81ab8c) //  1
NHSTUB(closedir                               ,0xffae2a7c) //  4
NHSTUB(err_init_task                          ,0xff815fd4) //111
NHSTUB(exmem_alloc                            ,0xff88ffd8) //103
NHSTUB(exmem_free                             ,0xff890050) //103
NHSTUB(free                                   ,0xff814244) //112
NHSTUB(kbd_p1_f                               ,0xff834a6c) //109
NHSTUB(kbd_p1_f_cont                          ,0xff834a78) //109
NHSTUB(kbd_p2_f                               ,0xff8342bc) //109
NHSTUB(kbd_read_keys                          ,0xff8349f4) //109
NHSTUB(kbd_read_keys_r2                       ,0xff864d8c) //109
NHSTUB(lseek                                  ,0xff8371fc) //101
NHSTUB(malloc                                 ,0xff8141e8) //112
NHSTUB(memcmp                                 ,0xff8206d8) //101
NHSTUB(memcpy                                 ,0xff840674) //101
NHSTUB(memset                                 ,0xffa5b230) //101
NHSTUB(mkdir                                  ,0xff83757c) //109
NHSTUB(mktime_ext                             ,0xff8b5b6c) //  1
NHSTUB(open                                   ,0xff81aadc) //  1
NHSTUB(OpenFastDir                            ,0xffae2acc) //  4
NHSTUB(qsort                                  ,0xffb5fbc8) //  4
NHSTUB(rand                                   ,0xffa5b370) //  4
//NHSTUB(read                                 ,0xff81ad74) //101
NHSTUB(realloc                                ,0xffa5b2ac) //115
NHSTUB(reboot_fw_update                       ,0xffae8040) //106
NHSTUB(set_control_event                      ,0xff89bb30) //111
NHSTUB(srand                                  ,0xffa5b364) //  4
NHSTUB(stat                                   ,0xff837244) //109
NHSTUB(strcat                                 ,0xff8b5328) //  1
NHSTUB(strchr                                 ,0xff8140b4) //  1
NHSTUB(strcmp                                 ,0xff820694) //101
NHSTUB(strcpy                                 ,0xff82067c) //101
NHSTUB(strftime                               ,0xff8b5574) //113
NHSTUB(strlen                                 ,0xff814100) //101
NHSTUB(strncmp                                ,0xff814068) //  1
NHSTUB(strncpy                                ,0xff81402c) //  1
NHSTUB(strrchr                                ,0xff8140d8) //  1
NHSTUB(strtol                                 ,0xff840954) //101
NHSTUB(strtolx                                ,0xff840758) //109
   DEF(task_CaptSeq                           ,0xff88261c) //107
   DEF(task_ExpDrv                            ,0xff8cc0d0) //110
   DEF(task_FileWrite                         ,0xffae0af0) //107
   DEF(task_InitFileModules                   ,0xff89fc7c) //107
   DEF(task_MovieRecord                       ,0xff987094) //107
   DEF(task_PhySw                             ,0xff8345ec) //107
   DEF(task_RotaryEncoder                     ,0xff8657ec) //107
NHSTUB(time                                   ,0xff88f66c) //109
NHSTUB(vsprintf                               ,0xff820640) //115
//NHSTUB(write                                ,0xff837170) //101
//NHSTUB(EngDrvIn                             ,0xff8358bc) //102
//NHSTUB(EngDrvOut                            ,0xff8358a4) //102
//NHSTUB(EngDrvRead                           ,0xff8358c4) //102
//NHSTUB(EngDrvBits                           ,0xff8358d8) //102
//NHSTUB(GetSDProtect                         ,0xff8349c4) //103
//NHSTUB(StartRecModeMenu                     ,0xff896094) //102
//NHSTUB(DispCon_ShowBitmapColorBar           ,0xff85ea18) //102
//NHSTUB(ResetZoomLens                        ,0xffb05118) //102
//NHSTUB(ResetFocusLens                       ,0xffb03cd8) //102
//NHSTUB(NR_GetDarkSubType                    ,0xff98fb90) //102
//NHSTUB(NR_SetDarkSubType                    ,0xff98fae0) //102
//NHSTUB(SavePaletteData                      ,0xffb76d18) //102
//NHSTUB(GUISrv_StartGUISystem                ,0xff8b3260) //101
