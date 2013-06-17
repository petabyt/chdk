// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R50 (DRYOS version 2.3, release #0050)
//   Firmware Ver GM1.01A
//   Canon PowerShot ELPH 110 HS

// Values for makefile.inc
//   PLATFORMOSVER = 50
//   PLATFORMID = 12865 (0x3241) // Found @ 0xfff40040
//   MAXRAMADDR = 0x0fffffff
//   KEYSYS = d4c                // Found @ 0xffff3cbc
//   NEED_ENCODED_DISKBOOT = 8   // Found @ 0xffff3ccc

// Note, ROM copied to RAM :- from 0xff63ce38, to 0x00685000, len 15799 words.

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NHSTUB(DeleteFile_Fut                       ,0xff0208dc) //  1 90%        == 0xff0208dc
// ERROR: MakeDirectory_Fut is not found.                  //--- ---    *** != 0xff021480
// ERROR: kbd_pwr_off is not found.                        //--- ---    *** != 0x00000000
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff0841bc -> ff080a6c -> ff1ca4f0 -> ff333640 -> ff5e8cf0
// Mode 33326 in firmware but not in current modemap

// Values below can be overridden in 'stubs_min.S':
DEF(file_system_started                     ,0x00002b80) // Found @0xff05a1d4
DEF(physw_status                            ,0x00037bdc) // Found @0xff01e84c
DEF(physw_run                               ,0x00001c20) // Found @0xff01e408
DEF(physw_sleep_delay                       ,0x00001c28) // Found @0xff01e408
DEF(levent_table                            ,0xff474dec) // Found @0xff474dec
DEF(FlashParamsTable                        ,0xff5e8f5c) // Found @0xff5e8f5c
DEF(movie_status                            ,0x0000a1c4) // Found @0xff191b24
DEF(video_compression_rate                  ,0x0000a204) // Found @0xff193518
DEF(full_screen_refresh                     ,0x0000d134) // Found @0xff243138
DEF(canon_menu_active                       ,0x000031e0) // Found @0xff07be34
DEF(canon_shoot_menu_active                 ,0x0000ba59) // Found @0xff1e4f50
DEF(playrec_mode                            ,0x00002f34) // Found @0xff06fdfc
DEF(zoom_status                             ,0x000109d0) // Found @0xff336de4
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 64 entries in the table - set NUM_FL to 64
DEF(focus_len_table                         ,0xfff4a4c8) // Found @0xfff4a4c8
DEF(zoom_busy                               ,0x0000a05c) // Found @0xff18ca18
DEF(focus_busy                              ,0x00009ef0) // Found @0xff188164
DEF(recreview_hold                          ,0x000037fc) // Found @0xff08c128
// Palette colour tables  found @ 0xff4900d0
DEF(palette_control                         ,0x0000d134) // Found @0xff2430b4
DEF(active_palette_buffer                   ,0x0000d13c) // Found @0xff2430b8
DEF(palette_buffer_ptr                      ,0x0000d140) // Found @0xff243570
DEF(palette_buffer                          ,0x000c78c8) // Found @0xff243580
// Offset from start of palette_buffer to color data = 4 (Found @0xff377ca0)
DEF(bitmap_buffer                           ,0x0000d178) // Found @0xff246cb4
DEF(active_bitmap_buffer                    ,0x0000d170) // Found @0xff246cb8
DEF(viewport_buffers                        ,0xff4132b4) // Found @0xff03b2d0
DEF(active_viewport_buffer                  ,0x00002138) // Found @0xff03af6c
// Camera has 2 RAW buffers @ 0x44000000 & 0x4a7eca00
//  Note: active buffer --> raw_buffers[active_raw_buffer]
//        other buffer  --> raw_buffers[active_raw_buffer^1]
DEF(raw_buffers                             ,0xff427974) // Found @0xff427974
DEF(active_raw_buffer                       ,0x00002eac) // Found @0xff06c918

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x406c5000; }             // Found @0xff0448b8
//void *vid_get_viewport_fb()      { return (void*)0x4081ab80; }             // Found @0xff3a8354
DEF(viewport_fb_d                           ,0x00002c2c) // Found 0x2bd8 (@0xff05e4c8) + 0x54 (@0xff05e500)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2bd8+0x54)); } // Found @0xff05e4c8 & 0xff05e500
DEF(jpeg_count_str                          ,0x000c7158) // Found @0xff239220
//char *camera_jpeg_count_str()    { return (char*)0x000c7158; }             // Found @0xff239220
//long hook_raw_size()             { return 0x0180fde0; }                    // Found @0xff3ab168
//int get_flash_params_count(void) { return 0xa6; }                          // Found @0xff1cb53c

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x02000000 // Found @0xff41384c, levent 0x20a
//#define SD_READONLY_IDX     1
//#define USB_MASK            0x40000000 // Found @0xff413884, levent 0x202
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_MENU            ,0x00000001 }, // Found @0xff4137cc, levent 0x09
//    { 0, KEY_SET             ,0x00000002 }, // Found @0xff4137d4, levent 0x08
//    { 0, KEY_ZOOM_OUT        ,0x00000004 }, // Found @0xff4137dc, levent 0x03
//    { 0, KEY_ZOOM_IN         ,0x00000008 }, // Found @0xff4137e4, levent 0x02
//    { 0, KEY_VIDEO           ,0x00000040 }, // Found @0xff4137f4, levent 0x1a
//    { 0, KEY_UP              ,0x00000100 }, // Found @0xff4137fc, levent 0x04
//    { 0, KEY_RIGHT           ,0x00000200 }, // Found @0xff413804, levent 0x07
//    { 0, KEY_LEFT            ,0x00000400 }, // Found @0xff41380c, levent 0x06
//    { 0, KEY_DOWN            ,0x00000800 }, // Found @0xff413814, levent 0x05
//    { 1, KEY_SHOOT_FULL      ,0x00300000 }, // Found @0xff41382c, levent 0x01
//    { 1, KEY_SHOOT_FULL_ONLY ,0x00200000 }, // Found @0xff41382c, levent 0x01
//    { 1, KEY_SHOOT_HALF      ,0x00100000 }, // Found @0xff413824, levent 0x00
//    { 1, KEY_POWER           ,0x00400000 }, // Found @0xff413834, levent 0x100
//    { 1, KEY_PLAYBACK        ,0x00800000 }, // Found @0xff41383c, levent 0x101
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    4784 // Found @0xff15d368
//#define CAM_RAW_ROWS      3516 // Found @0xff15d374
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff024684

// Misc stuff
DEF(ctypes, 0xff412730)

// For capt_seq.c
DEF(_nrflag,0xd234) // Found @ ff24faf8 (0xd234) & ff24fb34 (+0x00)
//static long *nrflag = (long*)(0xd234+0x00);  // Found @ ff24faf8 & ff24fb34
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
//NHSTUB(CreateJumptable                      ,0xff3ab330) //  1
// ALT: NHSTUB(CreateJumptable, 0xff3ad694) // 1 32/0
//NHSTUB(_uartr_req                           ,0xff00b2ec) //111
//NHSTUB(StartRecModeMenu                     ,0xff07be30) //102
//NHSTUB(AllocateMemory                       ,0xff321f94) //101
NHSTUB(AllocateUncacheableMemory              ,0xff02463c) //112
NHSTUB(Close                                  ,0xff020f50) //101
NHSTUB(CreateTask                             ,0x0068ab00) //101
NHSTUB(DebugAssert                            ,0x0068afd8) //111
NHSTUB(DeleteDirectory_Fut                    ,0xff020950) //116
NHSTUB(DoAFLock                               ,0xff0229e8) //102
NHSTUB(EnterToCompensationEVF                 ,0xff022c4c) //104
NHSTUB(ExecuteEventProcedure                  ,0xff077304) //104
NHSTUB(ExitFromCompensationEVF                ,0xff022c90) //104
NHSTUB(ExitTask                               ,0x0068ad90) //101
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff02e398) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff02e4e8) //104
NHSTUB(Fclose_Fut                             ,0xff0209e8) //101
NHSTUB(Feof_Fut                               ,0xff020bd4) //  1
NHSTUB(Fflush_Fut                             ,0xff020c10) //  1
NHSTUB(Fgets_Fut                              ,0xff020b3c) //  6
NHSTUB(Fopen_Fut                              ,0xff0209a8) //101
NHSTUB(Fread_Fut                              ,0xff020a94) //101
//NHSTUB(FreeMemory                           ,0xff321f8c) //101
NHSTUB(FreeUncacheableMemory                  ,0xff02467c) //112
NHSTUB(Fseek_Fut                              ,0xff020b88) //101
NHSTUB(Fwrite_Fut                             ,0xff020ae8) //101
NHSTUB(GetBatteryTemperature                  ,0xff04d97c) //102
NHSTUB(GetCCDTemperature                      ,0xff04d908) //102
NHSTUB(GetCurrentAvValue                      ,0xff189d14) //102
NHSTUB(GetDrive_ClusterSize                   ,0xff05c09c) //  6
NHSTUB(GetDrive_FreeClusters                  ,0xff05c0f4) //  6
NHSTUB(GetDrive_TotalClusters                 ,0xff05c0cc) //  6
NHSTUB(GetFocusLensSubjectDistance            ,0xff188f24) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff189374) //  3
NHSTUB(GetImageFolder                         ,0xff166a24) //  6
NHSTUB(GetKbdState                            ,0xff04a378) //109
NHSTUB(GetMemInfo                             ,0xff0052d0) //115
NHSTUB(GetOpticalTemperature                  ,0xff04d9f0) //102
NHSTUB(GetParameterData                       ,0xff1cb4fc) //101
NHSTUB(GetPropertyCase                        ,0xff07b378) //102
NHSTUB(GetSystemTime                          ,0xff321fec) //101
NHSTUB(GetVRAMHPixelsSize                     ,0xff03d5a0) //102
NHSTUB(GetVRAMVPixelsSize                     ,0xff03d5ac) //102
NHSTUB(GetZoomLensCurrentPoint                ,0xff18ce90) //102
NHSTUB(GetZoomLensCurrentPosition             ,0xff30f874) //102
NHSTUB(GiveSemaphore                          ,0x0068aa60) //112
NHSTUB(IsStrobeChargeCompleted                ,0xff0d4ca0) //102
NHSTUB(LEDDrive                               ,0xff195280) //101
NHSTUB(LocalTime                              ,0x0068f2f4) //115
NHSTUB(LockMainPower                          ,0xff0807a8) //103
//NHSTUB(Lseek                                ,0xff0211cc) //101
NHSTUB(MakeSDCardBootable                     ,0xff05c374) //105
NHSTUB(MoveFocusLensToDistance                ,0xff3a43f8) //102
NHSTUB(MoveIrisWithAv                         ,0xff31e9b4) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xff31f0e8) //102
//NHSTUB(NewTaskShell                         ,0xff07acfc) //101
NHSTUB(Open                                   ,0xff020e88) //101
NHSTUB(PB2Rec                                 ,0xff0837e0) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff0659b0) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff065988) //102
NHSTUB(PT_PlaySound                           ,0xff071d64) // 11
NHSTUB(PostLogicalEventForNotPowerType        ,0xff07fe9c) //103
NHSTUB(PostLogicalEventToUI                   ,0xff07fee8) //103
NHSTUB(PutInNdFilter                          ,0xff31eec0) //102
NHSTUB(PutOutNdFilter                         ,0xff31eee4) //102
NHSTUB(Read                                   ,0xff005d8c) //101
NHSTUB(ReadFastDir                            ,0xff2fcbe0) //115
NHSTUB(Rec2PB                                 ,0xff083820) //104
NHSTUB(RefreshPhysicalScreen                  ,0xff098024) //104
//NHSTUB(Remove                               ,0xff021124) //  6
NHSTUB(RenameFile_Fut                         ,0xff020848) //116
NHSTUB(Restart                                ,0xff025e54) //106
NHSTUB(ScreenLock                             ,0xff099004) //117
NHSTUB(ScreenUnlock                           ,0xff099068) //117
NHSTUB(SetAE_ShutterSpeed                     ,0xff3a74cc) //102
NHSTUB(SetAutoShutdownTime                    ,0xff08081c) //103
NHSTUB(SetCurrentCaptureModeType              ,0xff0872d8) //101
NHSTUB(SetFileAttributes                      ,0xff0213e8) //  6
NHSTUB(SetFileTimeStamp                       ,0xff021370) //  6
NHSTUB(SetLogicalEventActive                  ,0xff080524) //101
NHSTUB(SetParameterData                       ,0xff1cb46c) //101
NHSTUB(SetPropertyCase                        ,0xff07b1f0) //102
NHSTUB(SetScriptMode                          ,0xff080574) //101
NHSTUB(SleepTask                              ,0x0068c2e8) //101
NHSTUB(TakeSemaphore                          ,0x0068a990) //101
NHSTUB(TurnOffBackLight                       ,0xff090158) //104
NHSTUB(TurnOnBackLight                        ,0xff090140) //104
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff1b0720) //101
NHSTUB(UnlockAF                               ,0xff022a20) //102
NHSTUB(UnlockMainPower                        ,0xff0806fc) //103
NHSTUB(VbattGet                               ,0xff01d094) //101
NHSTUB(Write                                  ,0xff020fa4) //101
NHSTUB(WriteSDCard                            ,0xff17b5a4) //108
NHSTUB(_log                                   ,0x00690ce0) //111
NHSTUB(_log10                                 ,0x00691220) //112
NHSTUB(_pow                                   ,0x00691398) //114
NHSTUB(_sqrt                                  ,0x00693038) //  6
NHSTUB(add_ptp_handler                        ,0xff29a034) //  6
NHSTUB(apex2us                                ,0xff249914) //  4
NHSTUB(close                                  ,0xff005be8) //  6
NHSTUB(closedir                               ,0xff2fca2c) //  4
NHSTUB(err_init_task                          ,0xff004378) //111
NHSTUB(exmem_alloc                            ,0xff075cd8) //101
NHSTUB(exmem_free                             ,0xff075d50) //101
NHSTUB(free                                   ,0xff002f74) //112
NHSTUB(kbd_p1_f                               ,0xff01e89c) //109
NHSTUB(kbd_p1_f_cont                          ,0xff01e8a8) //109
NHSTUB(kbd_p2_f                               ,0xff01e0a0) //109
NHSTUB(kbd_read_keys                          ,0xff01e84c) //109
NHSTUB(kbd_read_keys_r2                       ,0xff049d58) //109
NHSTUB(lseek                                  ,0xff0211cc) //101
NHSTUB(malloc                                 ,0xff002f1c) //112
NHSTUB(memcmp                                 ,0xff00b940) //101
NHSTUB(memcpy                                 ,0xff0276e4) //101
NHSTUB(memset                                 ,0xff247a3c) //101
NHSTUB(mkdir                                  ,0xff021480) //118
NHSTUB(mktime_ext                             ,0xff099564) //  1
NHSTUB(open                                   ,0xff005b38) //  6
NHSTUB(OpenFastDir                            ,0xff2fca7c) //115
NHSTUB(qsort                                  ,0xff2479dc) //  6
NHSTUB(rand                                   ,0xff247514) //  6
//NHSTUB(read                                 ,0xff005d8c) //101
NHSTUB(realloc                                ,0xff247ab8) //115
NHSTUB(reboot_fw_update                       ,0xff3022c4) //106
NHSTUB(set_control_event                      ,0xff0801e4) //111
NHSTUB(srand                                  ,0xff247508) //  6
NHSTUB(stat                                   ,0xff021214) //109
NHSTUB(strcat                                 ,0xff099be4) //  1
NHSTUB(strchr                                 ,0xff002de8) //  1
NHSTUB(strcmp                                 ,0xff00ba3c) //101
NHSTUB(strcpy                                 ,0xff00b928) //101
NHSTUB(strftime                               ,0xff0995b0) //113
NHSTUB(strlen                                 ,0xff002e34) //101
NHSTUB(strncmp                                ,0xff002d9c) //  1
NHSTUB(strncpy                                ,0xff002d60) //  1
NHSTUB(strrchr                                ,0xff002e0c) //  1
NHSTUB(strtol                                 ,0xff0276d0) //101
NHSTUB(strtolx                                ,0xff0274d4) //109
   DEF(task_CaptSeq                           ,0xff068e64) //110
   DEF(task_ExpDrv                            ,0xff0b2aa8) //110
   DEF(task_InitFileModules                   ,0xff084030) //110
   DEF(task_MovieRecord                       ,0xff193d4c) //110
   DEF(task_PhySw                             ,0xff01e404) //110
NHSTUB(time                                   ,0x0068f8d0) //  6
NHSTUB(vsprintf                               ,0xff00b7d8) //115
//NHSTUB(write                                ,0xff020fa4) //101
//NHSTUB(EngDrvIn                             ,0xff01f6d0) //102
//NHSTUB(EngDrvOut                            ,0xff01f6b8) //102
//NHSTUB(EngDrvRead                           ,0xff01f6d8) //102
//NHSTUB(EngDrvBits                           ,0xff01f6ec) //102
//NHSTUB(GetSDProtect                         ,0xff01e80c) //101
//NHSTUB(DispCon_ShowBitmapColorBar           ,0xff044874) //102
//NHSTUB(ResetZoomLens                        ,0xff31f03c) //102
//NHSTUB(ResetFocusLens                       ,0xff31dbb8) //102
//NHSTUB(NR_GetDarkSubType                    ,0xff24fbb8) //102
//NHSTUB(NR_SetDarkSubType                    ,0xff24faf0) //102
//NHSTUB(SavePaletteData                      ,0xff197c40) //102
//NHSTUB(GUISrv_StartGUISystem                ,0xff097878) //101
