// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R49 (DRYOS version 2.3, release #0049)
//   Firmware Ver GM1.00A
//   Canon PowerShot SX150 IS

// Values for makefile.inc
//   PLATFORMOSVER = 49
//   PLATFORMID = 12852 (0x3234) // Found @ 0xfffe0040
//   MAXRAMADDR = 0x03ffffff
//   KEYSYS = d4c                // Found @ 0xffff3514
//   NEED_ENCODED_DISKBOOT = 7   // Found @ 0xffff3524

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
NHSTUB(kbd_pwr_off                            ,0xff8652c4) //  2 60%
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff89f7c4 -> ff89bf40 -> ff9af560 -> ffaf76d4 -> ffc4e108
// Mode 32818 in firmware but not in current modemap

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00033694) // Found @0xff834580
DEF(physw_run                               ,0x00001c30) // Found @0xff83412c
DEF(physw_sleep_delay                       ,0x00001c38) // Found @0xff83412c
DEF(levent_table                            ,0xffbe99e8) // Found @0xffbe99e8
DEF(FlashParamsTable                        ,0xffc4e360) // Found @0xffc4e360
DEF(movie_status                            ,0x00006ec4) // Found @0xff9856ec
DEF(video_compression_rate                  ,0x00006f04) // Found @0xff986274
DEF(full_screen_refresh                     ,0x00009654) // Found @0xffa2a00c
DEF(canon_menu_active                       ,0x00003194) // Found @0xff8958f0
DEF(canon_shoot_menu_active                 ,0x00008109) // Found @0xff9cec20
DEF(playrec_mode                            ,0x00002eb8) // Found @0xff8877d0
DEF(zoom_status                             ,0x0000d520) // Found @0xffafaf48
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 128 entries in the table - set NUM_FL to 128
DEF(focus_len_table                         ,0xfffeabd8) // Found @0xfffeabd8
DEF(zoom_busy                               ,0x00006dcc) // Found @0xff98138c
DEF(focus_busy                              ,0x00006c5c) // Found @0xff97b73c
DEF(recreview_hold                          ,0x00003b7c) // Found @0xff8a6484
// Palette colour tables  found @ 0xffc004ec
DEF(palette_control                         ,0x00009654) // Found @0xffa29f88
//DEF(active_palette_buffer                   ,0x0000965c) // Found @0xffa29f8c, ** != ** stubs_min = 0x00009654 (0x9654)
DEF(palette_buffer_ptr                      ,0x00009660) // Found @0xffa2a330
//DEF(palette_buffer                          ,0x000baa84) // Found @0xffa2a340,          stubs_min = 0x000baa84 (0xBAA84)
// Offset from start of palette_buffer to color data = 4 (Found @0xffb3203c)
DEF(viewport_buffers                        ,0xffb8fbd4) // Found @0xff852dc0
DEF(active_viewport_buffer                  ,0x0000214c) // Found @0xff852b34

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x403f1000; }             // Found @0xff860d18
//void *vid_get_viewport_fb()      { return (void*)0x40546b80; }             // Found @0xffb4d228
DEF(viewport_fb_d                           ,0x00002c00) // Found 0x2ba8 (@0xff8780cc) + 0x58 (@0xff878104)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2ba8+0x58)); } // Found @0xff8780cc & 0xff878104
DEF(jpeg_count_str                          ,0x000ba380) // Found @0xffa1ea9c
//char *camera_jpeg_count_str()    { return (char*)0x000ba380; }             // Found @0xffa1ea9c
//long hook_raw_size()             { return 0x014eb7e0; }                    // Found @0xffb50048
//int get_flash_params_count(void) { return 0x9f; }                          // Found @0xff9b0610

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffb90df0, levent 0x20a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00040000 // Found @0xffb90df8, levent 0x202
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 1, KEY_SHOOT_FULL      ,0x00003000 }, // Found @0xffb90d58, levent 0x01
//    { 1, KEY_SHOOT_FULL_ONLY ,0x00002000 }, // Found @0xffb90d58, levent 0x01
//    { 1, KEY_SHOOT_HALF      ,0x00001000 }, // Found @0xffb90d50, levent 0x00
//    { 1, KEY_ZOOM_IN         ,0x00004000 }, // Found @0xffb90d60, levent 0x02
//    { 1, KEY_ZOOM_OUT        ,0x00008000 }, // Found @0xffb90d68, levent 0x03
//    { 2, KEY_VIDEO           ,0x00000010 }, // Found @0xffb90d90, levent 0x19
//    { 2, KEY_POWER           ,0x00000020 }, // Found @0xffb90d98, levent 0x100
//    { 2, KEY_PLAYBACK        ,0x00000040 }, // Found @0xffb90da0, levent 0x101
//    { 2, KEY_UP              ,0x00000100 }, // Found @0xffb90da8, levent 0x04
//    { 2, KEY_DOWN            ,0x00000200 }, // Found @0xffb90db0, levent 0x05
//    { 2, KEY_RIGHT           ,0x00000400 }, // Found @0xffb90db8, levent 0x07
//    { 2, KEY_LEFT            ,0x00000800 }, // Found @0xffb90dc0, levent 0x06
//    { 2, KEY_SET             ,0x00001000 }, // Found @0xffb90dc8, levent 0x08
//    { 2, KEY_MENU            ,0x00002000 }, // Found @0xffb90dd0, levent 0x09
//    { 2, KEY_DISPLAY         ,0x00004000 }, // Found @0xffb90dd8, levent 0x0a
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    4464 // Found @0xff94fc10
//#define CAM_RAW_ROWS      3276 // Found @0xff94fc1c
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff83adb8

// Misc stuff
DEF(ctypes, 0xffb8f522)

// For capt_seq.c
DEF(_nrflag,0x9798) // Found @ ffa36d34 (0x9798) & ffa36d70 (+0x00)
//static long *nrflag = (long*)(0x9798+0x00);  // Found @ ffa36d34 & ffa36d70
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
//NHSTUB(CreateJumptable                      ,0xffb50214) //  1
// ALT: NHSTUB(CreateJumptable, 0xffb5245c) // 1 32/0
//NHSTUB(_uartr_req                           ,0xff81fedc) //111
//NHSTUB(StartRecModeMenu                     ,0xff8958ec) //102
//NHSTUB(AllocateMemory                       ,0xffae4dfc) //101
NHSTUB(AllocateUncacheableMemory              ,0xff83ad70) //112
NHSTUB(Close                                  ,0xff836d90) //101
NHSTUB(CreateTask                             ,0xff81eae4) //101
NHSTUB(DebugAssert                            ,0xff81edbc) //111
NHSTUB(DeleteDirectory_Fut                    ,0xff83678c) //116
NHSTUB(DeleteFile_Fut                         ,0xff8366a8) //112
NHSTUB(DoAFLock                               ,0xff838934) //102
NHSTUB(EnterToCompensationEVF                 ,0xff838bf0) //104
NHSTUB(ExecuteEventProcedure                  ,0xff890dd0) //104
NHSTUB(ExitFromCompensationEVF                ,0xff838c34) //104
NHSTUB(ExitTask                               ,0xff81ed74) //101
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff8469b8) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff846a98) //104
NHSTUB(Fclose_Fut                             ,0xff836824) //101
NHSTUB(Feof_Fut                               ,0xff836a10) //  1
NHSTUB(Fflush_Fut                             ,0xff836a4c) //  1
NHSTUB(Fgets_Fut                              ,0xff836978) //  6
NHSTUB(Fopen_Fut                              ,0xff8367e4) //101
NHSTUB(Fread_Fut                              ,0xff8368d0) //101
//NHSTUB(FreeMemory                           ,0xffae4df4) //101
NHSTUB(FreeUncacheableMemory                  ,0xff83adb0) //112
NHSTUB(Fseek_Fut                              ,0xff8369c4) //101
NHSTUB(Fwrite_Fut                             ,0xff836924) //101
NHSTUB(GetBatteryTemperature                  ,0xff86889c) //102
NHSTUB(GetCCDTemperature                      ,0xff868828) //102
NHSTUB(GetCurrentAvValue                      ,0xff97e650) //102
NHSTUB(GetDrive_ClusterSize                   ,0xff876a20) //  6
NHSTUB(GetDrive_FreeClusters                  ,0xff876a78) //  6
NHSTUB(GetDrive_TotalClusters                 ,0xff876a50) //  6
NHSTUB(GetFocusLensSubjectDistance            ,0xff97c4b8) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff97c908) //  3
NHSTUB(GetImageFolder                         ,0xff958ff0) //  6
NHSTUB(GetKbdState                            ,0xff8652ac) //109
NHSTUB(GetMemInfo                             ,0xff81a2ac) //115
NHSTUB(GetOpticalTemperature                  ,0xff868914) //102
NHSTUB(GetParameterData                       ,0xff9b05d0) //101
NHSTUB(GetPropertyCase                        ,0xff894e58) //102
NHSTUB(GetSystemTime                          ,0xffae4e54) //101
NHSTUB(GetVRAMHPixelsSize                     ,0xff855338) //102
NHSTUB(GetVRAMVPixelsSize                     ,0xff855344) //102
NHSTUB(GetZoomLensCurrentPoint                ,0xff981808) //102
NHSTUB(GetZoomLensCurrentPosition             ,0xffad21ac) //102
NHSTUB(GiveSemaphore                          ,0xff83a768) //112
NHSTUB(IsStrobeChargeCompleted                ,0xff8e5648) //102
NHSTUB(LEDDrive                               ,0xff864868) //101
NHSTUB(LocalTime                              ,0xff88e6c8) //115
NHSTUB(LockMainPower                          ,0xff89bb38) //103
//NHSTUB(Lseek                                ,0xff836fac) //101
NHSTUB(MakeDirectory_Fut                      ,0xff83671c) //116
NHSTUB(MakeSDCardBootable                     ,0xff876cb0) //105
NHSTUB(MoveFocusLensToDistance                ,0xffb494c8) //102
NHSTUB(MoveIrisWithAv                         ,0xffae167c) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xffae1ebc) //102
//NHSTUB(NewTaskShell                         ,0xff8947cc) //101
NHSTUB(Open                                   ,0xff836cc8) //101
NHSTUB(PB2Rec                                 ,0xff89edb8) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff87f620) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff87f5f8) //102
NHSTUB(PT_PlaySound                           ,0xff889628) //  6
NHSTUB(PostLogicalEventForNotPowerType        ,0xff8997dc) //103
NHSTUB(PostLogicalEventToUI                   ,0xff899828) //103
NHSTUB(PutInNdFilter                          ,0xffb47064) //102
NHSTUB(PutOutNdFilter                         ,0xffb4709c) //102
NHSTUB(Read                                   ,0xff81ad68) //101
NHSTUB(ReadFastDir                            ,0xffabec28) //115
NHSTUB(Rec2PB                                 ,0xff89edf8) //104
NHSTUB(RefreshPhysicalScreen                  ,0xff8b1cc8) //104
//NHSTUB(Remove                               ,0xff836f04) //  6
NHSTUB(RenameFile_Fut                         ,0xff836614) //116
NHSTUB(Restart                                ,0xff83c584) //106
NHSTUB(ScreenLock                             ,0xff8b2f00) //117
NHSTUB(ScreenUnlock                           ,0xff8b2f64) //117
NHSTUB(SetAE_ShutterSpeed                     ,0xffb4c400) //102
NHSTUB(SetAutoShutdownTime                    ,0xff89bbac) //103
NHSTUB(SetCurrentCaptureModeType              ,0xff8a3c5c) //101
NHSTUB(SetFileAttributes                      ,0xff837194) //  6
NHSTUB(SetFileTimeStamp                       ,0xff83711c) //  6
NHSTUB(SetLogicalEventActive                  ,0xff89b884) //101
NHSTUB(SetParameterData                       ,0xff9b0540) //101
NHSTUB(SetPropertyCase                        ,0xff894ccc) //102
NHSTUB(SetScriptMode                          ,0xff89b8d4) //101
NHSTUB(SleepTask                              ,0xff83aa14) //101
NHSTUB(TakeSemaphore                          ,0xff83a698) //101
NHSTUB(TurnOffBackLight                       ,0xff8aa24c) //104
NHSTUB(TurnOnBackLight                        ,0xff8aa234) //104
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff9a14b0) //101
NHSTUB(UnlockAF                               ,0xff83896c) //102
NHSTUB(UnlockMainPower                        ,0xff89ba8c) //103
NHSTUB(VbattGet                               ,0xff832df0) //101
NHSTUB(Write                                  ,0xff836de4) //101
NHSTUB(WriteSDCard                            ,0xff96b754) //108
NHSTUB(_log                                   ,0xffb8c048) //111
NHSTUB(_log10                                 ,0xffb8c588) //112
NHSTUB(_pow                                   ,0xffb8c700) //114
NHSTUB(_sqrt                                  ,0xffb8e324) //  6
NHSTUB(add_ptp_handler                        ,0xffa74894) //  6
NHSTUB(apex2us                                ,0xffa300ec) //  4
NHSTUB(close                                  ,0xff81abc4) //  6
NHSTUB(closedir                               ,0xffabea84) //  4
NHSTUB(err_init_task                          ,0xff816020) //111
NHSTUB(exmem_alloc                            ,0xff88f688) //101
NHSTUB(exmem_free                             ,0xff88f700) //101
NHSTUB(free                                   ,0xff814258) //112
NHSTUB(kbd_p1_f                               ,0xff8345d0) //109
NHSTUB(kbd_p1_f_cont                          ,0xff8345dc) //109
NHSTUB(kbd_p2_f                               ,0xff833dc4) //109
NHSTUB(kbd_read_keys                          ,0xff834580) //109
NHSTUB(kbd_read_keys_r2                       ,0xff864cac) //109
NHSTUB(lseek                                  ,0xff836fac) //101
NHSTUB(malloc                                 ,0xff814200) //112
NHSTUB(memcmp                                 ,0xff820a00) //101
NHSTUB(memcpy                                 ,0xff840494) //101
NHSTUB(memset                                 ,0xffa2e124) //101
NHSTUB(mkdir                                  ,0xff83722c) //109
NHSTUB(mktime_ext                             ,0xff8b3d28) //  1
NHSTUB(open                                   ,0xff81ab14) //  6
NHSTUB(OpenFastDir                            ,0xffabead4) //115
NHSTUB(qsort                                  ,0xffb32c40) //  6
NHSTUB(rand                                   ,0xffa2e260) //  6
//NHSTUB(read                                 ,0xff81ad68) //101
NHSTUB(realloc                                ,0xffa2e1a0) //115
NHSTUB(reboot_fw_update                       ,0xffac4168) //106
NHSTUB(set_control_event                      ,0xff89b478) //111
NHSTUB(srand                                  ,0xffa2e254) //  6
NHSTUB(stat                                   ,0xff836ff4) //109
NHSTUB(strcat                                 ,0xff8b34e0) //  1
NHSTUB(strchr                                 ,0xff8140cc) //  1
NHSTUB(strcmp                                 ,0xff8209bc) //101
NHSTUB(strcpy                                 ,0xff8209a4) //101
NHSTUB(strftime                               ,0xff8b3728) //113
NHSTUB(strlen                                 ,0xff814118) //101
NHSTUB(strncmp                                ,0xff814080) //  1
NHSTUB(strncpy                                ,0xff814044) //  1
NHSTUB(strrchr                                ,0xff8140f0) //  1
NHSTUB(strtol                                 ,0xff840794) //101
NHSTUB(strtolx                                ,0xff840598) //109
   DEF(task_CaptSeq                           ,0xff881eb4) //110
   DEF(task_ExpDrv                            ,0xff8ca794) //110
   DEF(task_InitFileModules                   ,0xff89f638) //110
   DEF(task_MovieRecord                       ,0xff986a84) //110
   DEF(task_PhySw                             ,0xff834128) //110
   DEF(task_RotaryEncoder                     ,0xff865420) //110
NHSTUB(time                                   ,0xff88eca4) //109
NHSTUB(vsprintf                               ,0xff820964) //115
//NHSTUB(write                                ,0xff836de4) //101
//NHSTUB(EngDrvIn                             ,0xff8353f8) //102
//NHSTUB(EngDrvOut                            ,0xff8353e0) //102
//NHSTUB(EngDrvRead                           ,0xff835400) //102
//NHSTUB(EngDrvBits                           ,0xff835414) //102
//NHSTUB(GetSDProtect                         ,0xff834538) //101
//NHSTUB(DispCon_ShowBitmapColorBar           ,0xff860ce8) //102
//NHSTUB(ResetZoomLens                        ,0xffae1e10) //102
//NHSTUB(ResetFocusLens                       ,0xffae0858) //102
//NHSTUB(NR_GetDarkSubType                    ,0xffa36df4) //102
//NHSTUB(NR_SetDarkSubType                    ,0xffa36d2c) //102
//NHSTUB(SavePaletteData                      ,0xff98a28c) //102
//NHSTUB(GUISrv_StartGUISystem                ,0xff8b1540) //101
