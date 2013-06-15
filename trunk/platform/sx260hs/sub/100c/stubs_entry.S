// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R50 (DRYOS version 2.3, release #0050)
//   Firmware Ver GM1.00C
//   Canon PowerShot SX260 HS

// Values for makefile.inc
//   PLATFORMOSVER = 50
//   PLATFORMID = 12868 (0x3244) // Found @ 0xfff40040
//   MAXRAMADDR = 0x0fffffff
//   KEYSYS = d4c                // Found @ 0xffff3ce0
//   NEED_ENCODED_DISKBOOT = 8   // Found @ 0xffff3cf0

// Note, ROM copied to RAM :- from 0xff680a14, to 0x00685000, len 16659 words.

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NHSTUB(DeleteFile_Fut                       ,0xff02163c) //  1 90%        == 0xff02163c
//NHSTUB(LEDDrive                             ,0xff1b989c) //101        *** != 0xff04d06c
// ERROR: MakeDirectory_Fut is not found.                  //--- ---    *** != 0xff02214c
// ERROR: kbd_pwr_off is not found.                        //--- ---    *** != 0x00000000
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff08bd50 -> ff0882ac -> ff1f2fd0 -> ff365ec4 -> ff63ff68
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x000388e4) // Found @0xff01f5ac
DEF(physw_run                               ,0x00001c60) // Found @0xff01f158
DEF(physw_sleep_delay                       ,0x00001c68) // Found @0xff01f158
DEF(levent_table                            ,0xff587648) // Found @0xff587648
DEF(FlashParamsTable                        ,0xff6401e4) // Found @0xff6401e4
DEF(movie_status                            ,0x0000ab7c) // Found @0xff1b6128
DEF(video_compression_rate                  ,0x0000abbc) // Found @0xff1b7b1c
DEF(full_screen_refresh                     ,0x0000dbe8) // Found @0xff27c4dc
DEF(canon_menu_active                       ,0x000034d4) // Found @0xff0813dc
DEF(canon_shoot_menu_active                 ,0x0000c2f9) // Found @0xff213448
DEF(playrec_mode                            ,0x00003224) // Found @0xff074ec0
DEF(zoom_status                             ,0x0001150c) // Found @0xff3682f4
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 101 entries in the table - set NUM_FL to 101
DEF(focus_len_table                         ,0xfff4bcf0) // Found @0xfff4bcf0
DEF(zoom_busy                               ,0x0000aa14) // Found @0xff1b1014
DEF(focus_busy                              ,0x0000a870) // Found @0xff1aa57c
DEF(recreview_hold                          ,0x00003ff0) // Found @0xff094c20
// Palette colour tables  found @ 0xff5a5c1c
DEF(palette_control                         ,0x0000dbe8) // Found @0xff27c458
DEF(active_palette_buffer                   ,0x0000dbf0) // Found @0xff27c45c
DEF(palette_buffer_ptr                      ,0x0000dbf4) // Found @0xff27c914
DEF(palette_buffer                          ,0x000ddb24) // Found @0xff27c924
// Offset from start of palette_buffer to color data = 4 (Found @0xff3acb90)
DEF(bitmap_buffer                           ,0x0000dc24) // Found @0xff281164
DEF(active_bitmap_buffer                    ,0x0000dc1c) // Found @0xff281168
DEF(viewport_buffers                        ,0xff441144) // Found @0xff03d9bc
DEF(active_viewport_buffer                  ,0x000021b0) // Found @0xff03d658
// Camera has 2 RAW buffers @ 0x44000000 & 0x4adb54a0
//  Note: active buffer --> raw_buffers[active_raw_buffer]
//        other buffer  --> raw_buffers[active_raw_buffer^1]
DEF(raw_buffers                             ,0xff45516c) // Found @0xff45516c
DEF(active_raw_buffer                       ,0x00003194) // Found @0xff0715e0

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x406c5000; }             // Found @0xff047848
//void *vid_get_viewport_fb()      { return (void*)0x4081ab80; }             // Found @0xff3e3784
DEF(viewport_fb_d                           ,0x00002f14) // Found 0x2ec0 (@0xff062d0c) + 0x54 (@0xff062d44)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2ec0+0x54)); } // Found @0xff062d0c & 0xff062d44
DEF(jpeg_count_str                          ,0x000dd3b4) // Found @0xff26fe7c
//char *camera_jpeg_count_str()    { return (char*)0x000dd3b4; }             // Found @0xff26fe7c
//long hook_raw_size()             { return 0x01247a60; }                    // Found @0xff3e659c
//int get_flash_params_count(void) { return 0xa6; }                          // Found @0xff1f401c

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00080000 // Found @0xff441718, levent 0x20a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x10000000 // Found @0xff441750, levent 0x202
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 1, KEY_POWER           ,0x00400000 }, // Found @0xff441660, levent 0x100
//    { 1, KEY_PLAYBACK        ,0x00800000 }, // Found @0xff441668, levent 0x101
//    { 1, KEY_SHOOT_FULL      ,0x03000000 }, // Found @0xff441678, levent 0x01
//    { 1, KEY_SHOOT_FULL_ONLY ,0x02000000 }, // Found @0xff441678, levent 0x01
//    { 1, KEY_SHOOT_HALF      ,0x01000000 }, // Found @0xff441670, levent 0x00
//    { 2, KEY_VIDEO           ,0x00000020 }, // Found @0xff4416c8, levent 0x1a
//    { 2, KEY_MENU            ,0x00000040 }, // Found @0xff4416d0, levent 0x09
//    { 2, KEY_DISPLAY         ,0x00000080 }, // Found @0xff4416d8, levent 0x0a
//    { 2, KEY_UP              ,0x00000100 }, // Found @0xff4416e0, levent 0x04
//    { 2, KEY_DOWN            ,0x00000200 }, // Found @0xff4416e8, levent 0x05
//    { 2, KEY_RIGHT           ,0x00000400 }, // Found @0xff4416f0, levent 0x07
//    { 2, KEY_LEFT            ,0x00000800 }, // Found @0xff4416f8, levent 0x06
//    { 2, KEY_SET             ,0x00001000 }, // Found @0xff441700, levent 0x08
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    4176 // Found @0xff17dbb0
//#define CAM_RAW_ROWS      3060 // Found @0xff17dbbc
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff025754

// Misc stuff
DEF(ctypes, 0xff440480)

// For capt_seq.c
DEF(_nrflag,0xdd10) // Found @ ff28a0d4 (0xdd10) & ff28a110 (+0x00)
//static long *nrflag = (long*)(0xdd10+0x00);  // Found @ ff28a0d4 & ff28a110
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
//NHSTUB(CreateJumptable                      ,0xff3e6764) //  1
// ALT: NHSTUB(CreateJumptable, 0xff3e8b0c) // 1 32/0
//NHSTUB(_uartr_req                           ,0xff00b348) //111
//NHSTUB(AllocateMemory                       ,0xff358424) //101
NHSTUB(AllocateUncacheableMemory              ,0xff02570c) //112
NHSTUB(Close                                  ,0xff021cb0) //101
NHSTUB(CreateTask                             ,0x0068ab00) //101
NHSTUB(DebugAssert                            ,0x0068afd8) //111
NHSTUB(DeleteDirectory_Fut                    ,0xff0216b0) //116
NHSTUB(DoAFLock                               ,0xff02390c) //102
NHSTUB(EnterToCompensationEVF                 ,0xff023bb0) //104
NHSTUB(ExecuteEventProcedure                  ,0xff07c400) //104
NHSTUB(ExitFromCompensationEVF                ,0xff023bf4) //104
NHSTUB(ExitTask                               ,0x0068ad90) //101
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff02ee68) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff02efb8) //104
NHSTUB(Fclose_Fut                             ,0xff021748) //101
NHSTUB(Feof_Fut                               ,0xff021934) //  1
NHSTUB(Fflush_Fut                             ,0xff021970) //  1
NHSTUB(Fgets_Fut                              ,0xff02189c) //  6
NHSTUB(Fopen_Fut                              ,0xff021708) //101
NHSTUB(Fread_Fut                              ,0xff0217f4) //101
//NHSTUB(FreeMemory                           ,0xff35841c) //101
NHSTUB(FreeUncacheableMemory                  ,0xff02574c) //112
NHSTUB(Fseek_Fut                              ,0xff0218e8) //101
NHSTUB(Fwrite_Fut                             ,0xff021848) //101
NHSTUB(GetBatteryTemperature                  ,0xff0523ac) //102
NHSTUB(GetCCDTemperature                      ,0xff052338) //102
NHSTUB(GetCurrentAvValue                      ,0xff1ad3e8) //102
NHSTUB(GetDrive_ClusterSize                   ,0xff06093c) //  6
NHSTUB(GetDrive_FreeClusters                  ,0xff060994) //  6
NHSTUB(GetDrive_TotalClusters                 ,0xff06096c) //  6
NHSTUB(GetFocusLensSubjectDistance            ,0xff1ab340) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff1ab790) //  3
NHSTUB(GetImageFolder                         ,0xff1872bc) //  6
NHSTUB(GetKbdState                            ,0xff04dce8) //109
NHSTUB(GetMemInfo                             ,0xff0052e0) //115
NHSTUB(GetOpticalTemperature                  ,0xff052420) //102
NHSTUB(GetParameterData                       ,0xff1f3fdc) //101
NHSTUB(GetPropertyCase                        ,0xff080520) //102
NHSTUB(GetSystemTime                          ,0xff35847c) //101
NHSTUB(GetVRAMHPixelsSize                     ,0xff03fe34) //102
NHSTUB(GetVRAMVPixelsSize                     ,0xff03fe40) //102
NHSTUB(GetZoomLensCurrentPoint                ,0xff1b148c) //102
NHSTUB(GetZoomLensCurrentPosition             ,0xff345800) //102
NHSTUB(GiveSemaphore                          ,0x0068aa60) //112
NHSTUB(IsStrobeChargeCompleted                ,0xff0de2ec) //102
NHSTUB(LocalTime                              ,0x0068f2f4) //115
NHSTUB(LockMainPower                          ,0xff087fe8) //103
//NHSTUB(Lseek                                ,0xff021ecc) //101
NHSTUB(MakeSDCardBootable                     ,0xff060bbc) //105
NHSTUB(MoveFocusLensToDistance                ,0xff3df7d4) //102
NHSTUB(MoveIrisWithAv                         ,0xff354cd8) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xff355514) //102
//NHSTUB(NewTaskShell                         ,0xff07fe4c) //101
NHSTUB(Open                                   ,0xff021be8) //101
NHSTUB(PB2Rec                                 ,0xff08b370) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff06a190) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff06a168) //102
NHSTUB(PT_PlaySound                           ,0xff076e60) // 11
NHSTUB(PostLogicalEventForNotPowerType        ,0xff08598c) //103
NHSTUB(PostLogicalEventToUI                   ,0xff0859d8) //103
NHSTUB(PutInNdFilter                          ,0xff3dd31c) //102
NHSTUB(PutOutNdFilter                         ,0xff3dd354) //102
NHSTUB(Read                                   ,0xff005d9c) //101
NHSTUB(ReadFastDir                            ,0xff32ffa8) //115
NHSTUB(Rec2PB                                 ,0xff08b3b0) //104
NHSTUB(RefreshPhysicalScreen                  ,0xff0a180c) //104
//NHSTUB(Remove                               ,0xff021e24) //  6
NHSTUB(RenameFile_Fut                         ,0xff0215a8) //116
NHSTUB(Restart                                ,0xff026f7c) //106
NHSTUB(ScreenLock                             ,0xff0a27ec) //  4
NHSTUB(ScreenUnlock                           ,0xff0a2850) //  3
NHSTUB(SetAE_ShutterSpeed                     ,0xff3e28fc) //102
NHSTUB(SetAutoShutdownTime                    ,0xff08805c) //103
NHSTUB(SetCurrentCaptureModeType              ,0xff08f718) //101
NHSTUB(SetFileAttributes                      ,0xff0220b4) //  6
NHSTUB(SetFileTimeStamp                       ,0xff02203c) //  6
NHSTUB(SetLogicalEventActive                  ,0xff087d24) //101
NHSTUB(SetParameterData                       ,0xff1f3f4c) //101
NHSTUB(SetPropertyCase                        ,0xff080380) //102
NHSTUB(SetScriptMode                          ,0xff087dc0) //101
NHSTUB(SleepTask                              ,0x0068c2e8) //101
NHSTUB(TakeSemaphore                          ,0x0068a990) //101
NHSTUB(TurnOffBackLight                       ,0xff09953c) //104
NHSTUB(TurnOnBackLight                        ,0xff099524) //104
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff1d797c) //101
NHSTUB(UnlockAF                               ,0xff023944) //102
NHSTUB(UnlockMainPower                        ,0xff087f3c) //103
NHSTUB(VbattGet                               ,0xff01d0f0) //101
NHSTUB(Write                                  ,0xff021d04) //101
NHSTUB(WriteSDCard                            ,0xff19da88) //108
NHSTUB(_log                                   ,0x006915c8) //111
NHSTUB(_log10                                 ,0x00691b08) //112
NHSTUB(_pow                                   ,0x00691c80) //114
NHSTUB(_sqrt                                  ,0x00693c8c) //  6
NHSTUB(add_ptp_handler                        ,0xff2c81ec) //  6
NHSTUB(apex2us                                ,0xff283eb0) //  4
NHSTUB(close                                  ,0xff005bf8) //  6
NHSTUB(closedir                               ,0xff32fe04) //  4
NHSTUB(err_init_task                          ,0xff004388) //111
NHSTUB(exmem_alloc                            ,0xff07add4) //101
NHSTUB(exmem_free                             ,0xff07ae4c) //101
NHSTUB(free                                   ,0xff002f84) //112
NHSTUB(kbd_p1_f                               ,0xff01f5fc) //109
NHSTUB(kbd_p1_f_cont                          ,0xff01f608) //109
NHSTUB(kbd_p2_f                               ,0xff01edf0) //109
NHSTUB(kbd_read_keys                          ,0xff01f5ac) //109
NHSTUB(kbd_read_keys_r2                       ,0xff04d560) //109
NHSTUB(lseek                                  ,0xff021ecc) //101
NHSTUB(malloc                                 ,0xff002f2c) //112
NHSTUB(memcmp                                 ,0xff00b99c) //101
NHSTUB(memcpy                                 ,0xff028900) //101
NHSTUB(memset                                 ,0xff281f14) //101
NHSTUB(mkdir                                  ,0xff02214c) //  6
NHSTUB(mktime_ext                             ,0xff0a2d4c) //  1
NHSTUB(open                                   ,0xff005b48) //  6
NHSTUB(OpenFastDir                            ,0xff32fe54) //115
NHSTUB(qsort                                  ,0xff281eb4) //  6
NHSTUB(rand                                   ,0xff2819ec) //  6
//NHSTUB(read                                 ,0xff005d9c) //101
NHSTUB(realloc                                ,0xff281f90) //115
NHSTUB(reboot_fw_update                       ,0xff3355a0) //106
NHSTUB(set_control_event                      ,0xff0878c8) //111
NHSTUB(srand                                  ,0xff2819e0) //  6
NHSTUB(stat                                   ,0xff021f14) //109
NHSTUB(strcat                                 ,0xff0a33cc) //  1
NHSTUB(strchr                                 ,0xff002df8) //  1
NHSTUB(strcmp                                 ,0xff00ba98) //101
NHSTUB(strcpy                                 ,0xff00b984) //101
NHSTUB(strftime                               ,0xff0a2d98) //113
NHSTUB(strlen                                 ,0xff002e44) //101
NHSTUB(strncmp                                ,0xff002dac) //  1
NHSTUB(strncpy                                ,0xff002d70) //  1
NHSTUB(strrchr                                ,0xff002e1c) //  1
NHSTUB(strtol                                 ,0xff0288ec) //101
NHSTUB(strtolx                                ,0xff0286f0) //109
   DEF(task_CaptSeq                           ,0xff06d6bc) //110
   DEF(task_ExpDrv                            ,0xff0bc1b0) //110
   DEF(task_InitFileModules                   ,0xff08bbc4) //110
   DEF(task_MovieRecord                       ,0xff1b8350) //110
   DEF(task_PhySw                             ,0xff01f154) //110
   DEF(task_RotaryEncoder                     ,0xff04deb0) //110
NHSTUB(time                                   ,0x0068f8d0) //  6
NHSTUB(vsprintf                               ,0xff00b834) //115
//NHSTUB(write                                ,0xff021d04) //101
//NHSTUB(EngDrvIn                             ,0xff020430) //102
//NHSTUB(EngDrvOut                            ,0xff020418) //102
//NHSTUB(EngDrvRead                           ,0xff020438) //102
//NHSTUB(EngDrvBits                           ,0xff02044c) //102
//NHSTUB(GetSDProtect                         ,0xff01f568) //101
//NHSTUB(StartRecModeMenu                     ,0xff0813d8) //102
//NHSTUB(DispCon_ShowBitmapColorBar           ,0xff047804) //102
//NHSTUB(ResetZoomLens                        ,0xff355468) //102
//NHSTUB(ResetFocusLens                       ,0xff353eb0) //102
//NHSTUB(NR_GetDarkSubType                    ,0xff28a194) //102
//NHSTUB(NR_SetDarkSubType                    ,0xff28a0cc) //102
//NHSTUB(SavePaletteData                      ,0xff1bc260) //102
//NHSTUB(GUISrv_StartGUISystem                ,0xff0a1064) //101
