// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R50 (DRYOS version 2.3, release #0050)
//   Firmware Ver GM1.00D
//   Canon PowerShot ELPH 110 HS

// Values for makefile.inc
//   PLATFORMOSVER = 50
//   PLATFORMID = 12865 (0x3241) // Found @ 0xfff40040
//   MAXRAMADDR = 0x0fffffff
//   KEYSYS = d4c                // Found @ 0xffff3cbc
//   NEED_ENCODED_DISKBOOT = 8   // Found @ 0xffff3ccc

// Note, ROM copied to RAM :- from 0xff63cd08, to 0x00685000, len 15799 words.

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NSTUB(DeleteFile_Fut                        ,0xff0208dc) //  1 90%        == 0xff0208dc
// ERROR: MakeDirectory_Fut is not found.                  //--- ---    *** != 0xff021480
// ERROR: kbd_pwr_off is not found.                        //--- ---    *** != 0x00000000
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff0841bc -> ff080a6c -> ff1ca450 -> ff333518 -> ff5e8bc8
// Mode 33326 in firmware but not in current modemap

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00037bdc) // Found @0xff01e84c
DEF(physw_run                               ,0x00001c20) // Found @0xff01e408
DEF(physw_sleep_delay                       ,0x00001c28) // Found @0xff01e408
DEF(levent_table                            ,0xff474cc4) // Found @0xff474cc4
DEF(FlashParamsTable                        ,0xff5e8e34) // Found @0xff5e8e34
DEF(movie_status                            ,0x0000a1c4) // Found @0xff192970
DEF(full_screen_refresh                     ,0x0000d12c) // Found @0xff243098
DEF(canon_menu_active                       ,0x000031e0) // Found @0xff07be34
DEF(canon_shoot_menu_active                 ,0x0000ba51) // Found @0xff1e4eb0
DEF(playrec_mode                            ,0x00002f34) // Found @0xff06fdfc
DEF(zoom_status                             ,0x000109c8) // Found @0xff336cbc
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 64 entries in the table - set NUM_FL to 64
DEF(focus_len_table                         ,0xfff4a4c8) // Found @0xfff4a4c8
DEF(zoom_busy                               ,0x0000a05c) // Found @0xff18c9b0
DEF(focus_busy                              ,0x00009ef0) // Found @0xff1880fc
DEF(recreview_hold                          ,0x000037fc) // Found @0xff08c128
DEF(palette_control                         ,0x0000d12c) // Found @0xff243014
DEF(active_palette_buffer                   ,0x0000d134) // Found @0xff243018
DEF(palette_buffer                          ,0x000c78c8) // Found @0xff2434e0
DEF(bitmap_buffer                           ,0x0000d170) // Found @0xff246c14
DEF(active_bitmap_buffer                    ,0x0000d168) // Found @0xff246c18
DEF(viewport_buffers                        ,0xff41318c) // Found @0xff03b2d0
DEF(active_viewport_buffer                  ,0x00002138) // Found @0xff03af6c

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x406c5000; }             // Found @0xff0448b8
//void *vid_get_viewport_fb()      { return (void*)0x4081ab80; }             // Found @0xff3a822c
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2bd8+0x54)); } // Found @0xff05e4c8 & 0xff05e500
//char *camera_jpeg_count_str()    { return (char*)0x000c7158; }             // Found @0xff239180
//long hook_raw_size()             { return 0x0180fde0; }                    // Found @0xff3ab040
//int get_flash_params_count(void) { return 0xa6; }                          // Found @0xff1cb49c

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x02000000 // Found @0xff413724, levent 0x20a
//#define SD_READONLY_IDX     1
//#define USB_MASK            0x40000000 // Found @0xff41375c, levent 0x202
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_MENU            ,0x00000001 }, // Found @0xff4136a4, levent 0x09
//    { 0, KEY_SET             ,0x00000002 }, // Found @0xff4136ac, levent 0x08
//    { 0, KEY_ZOOM_OUT        ,0x00000004 }, // Found @0xff4136b4, levent 0x03
//    { 0, KEY_ZOOM_IN         ,0x00000008 }, // Found @0xff4136bc, levent 0x02
//    { 0, KEY_VIDEO           ,0x00000040 }, // Found @0xff4136cc, levent 0x1a
//    { 0, KEY_UP              ,0x00000100 }, // Found @0xff4136d4, levent 0x04
//    { 0, KEY_RIGHT           ,0x00000200 }, // Found @0xff4136dc, levent 0x07
//    { 0, KEY_LEFT            ,0x00000400 }, // Found @0xff4136e4, levent 0x06
//    { 0, KEY_DOWN            ,0x00000800 }, // Found @0xff4136ec, levent 0x05
//    { 1, KEY_SHOOT_FULL      ,0x00300000 }, // Found @0xff413704, levent 0x01
//    { 1, KEY_SHOOT_FULL_ONLY ,0x00200000 }, // Found @0xff413704, levent 0x01
//    { 1, KEY_SHOOT_HALF      ,0x00100000 }, // Found @0xff4136fc, levent 0x00
//    { 1, KEY_POWER           ,0x00400000 }, // Found @0xff41370c, levent 0x100
//    { 1, KEY_PLAYBACK        ,0x00800000 }, // Found @0xff413714, levent 0x101
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    4784 // Found @0xff15d2f8
//#define CAM_RAW_ROWS      3516 // Found @0xff15d304
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff024684

// Misc stuff
DEF(ctypes, 0xff412608)

// For capt_seq.c
//static long *nrflag = (long*)(0xd22c+0x00);  // Found @ ff24f948 & ff24f9a4
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NSTUB(AllocateMemory                          ,0xff321e6c) //101
NSTUB(AllocateUncacheableMemory               ,0xff02463c) //112
NSTUB(Close                                   ,0xff020f50) //101
NSTUB(CreateTask                              ,0x0068ab00) //101
NSTUB(DebugAssert                             ,0x0068afd8) //111
NSTUB(DeleteDirectory_Fut                     ,0xff020950) //116
NSTUB(DoAFLock                                ,0xff0229e8) //102
NSTUB(EnterToCompensationEVF                  ,0xff022c4c) //104
NSTUB(ExecuteEventProcedure                   ,0xff077304) //104
NSTUB(ExitFromCompensationEVF                 ,0xff022c90) //104
NSTUB(ExitTask                                ,0x0068ad90) //101
NSTUB(ExpCtrlTool_StartContiAE                ,0xff02e398) //104
NSTUB(ExpCtrlTool_StopContiAE                 ,0xff02e4e8) //104
NSTUB(Fclose_Fut                              ,0xff0209e8) //101
NSTUB(Feof_Fut                                ,0xff020bd4) //  1
NSTUB(Fflush_Fut                              ,0xff020c10) //  1
NSTUB(Fgets_Fut                               ,0xff020b3c) //  6
NSTUB(Fopen_Fut                               ,0xff0209a8) //101
NSTUB(Fread_Fut                               ,0xff020a94) //101
NSTUB(FreeMemory                              ,0xff321e64) //101
NSTUB(FreeUncacheableMemory                   ,0xff02467c) //112
NSTUB(Fseek_Fut                               ,0xff020b88) //101
NSTUB(Fwrite_Fut                              ,0xff020ae8) //101
NSTUB(GetBatteryTemperature                   ,0xff04d97c) //102
NSTUB(GetCCDTemperature                       ,0xff04d908) //102
NSTUB(GetCurrentAvValue                       ,0xff189cac) //102
NSTUB(GetDrive_ClusterSize                    ,0xff05c09c) //  6
NSTUB(GetDrive_FreeClusters                   ,0xff05c0f4) //  6
NSTUB(GetDrive_TotalClusters                  ,0xff05c0cc) //  6
NSTUB(GetFocusLensSubjectDistance             ,0xff188ebc) //102
NSTUB(GetFocusLensSubjectDistanceFromLens     ,0xff18930c) //  3
NSTUB(GetImageFolder                          ,0xff1669bc) //  6
NSTUB(GetKbdState                             ,0xff04a378) //109
NSTUB(GetMemInfo                              ,0xff0052d0) //115
NSTUB(GetOpticalTemperature                   ,0xff04d9f0) //102
NSTUB(GetParameterData                        ,0xff1cb45c) //101
NSTUB(GetPropertyCase                         ,0xff07b378) //102
NSTUB(GetSystemTime                           ,0xff321ec4) //101
NSTUB(GetVRAMHPixelsSize                      ,0xff03d5a0) //102
NSTUB(GetVRAMVPixelsSize                      ,0xff03d5ac) //102
NSTUB(GetZoomLensCurrentPoint                 ,0xff18ce28) //102
NSTUB(GetZoomLensCurrentPosition              ,0xff30f7d4) //102
NSTUB(GiveSemaphore                           ,0x0068aa60) //112
NSTUB(IsStrobeChargeCompleted                 ,0xff0d4c30) //102
NSTUB(LEDDrive                                ,0xff195218) //101
NSTUB(LocalTime                               ,0x0068f2f4) //115
NSTUB(LockMainPower                           ,0xff0807a8) //103
NSTUB(Lseek                                   ,0xff0211cc) //101
NSTUB(MakeSDCardBootable                      ,0xff05c374) //105
NSTUB(MoveFocusLensToDistance                 ,0xff3a42d0) //102
NSTUB(MoveIrisWithAv                          ,0xff31e88c) //102
NSTUB(MoveZoomLensWithPoint                   ,0xff31efc0) //102
NSTUB(NewTaskShell                            ,0xff07acfc) //101
NSTUB(Open                                    ,0xff020e88) //101
NSTUB(PB2Rec                                  ,0xff0837e0) //104
NSTUB(PT_MoveDigitalZoomToWide                ,0xff0659b0) //102
NSTUB(PT_MoveOpticalZoomAt                    ,0xff065988) //102
NSTUB(PT_PlaySound                            ,0xff071d64) // 11
NSTUB(PostLogicalEventForNotPowerType         ,0xff07fe9c) //103
NSTUB(PostLogicalEventToUI                    ,0xff07fee8) //103
NSTUB(PutInNdFilter                           ,0xff31ed98) //102
NSTUB(PutOutNdFilter                          ,0xff31edbc) //102
NSTUB(Read                                    ,0xff005d8c) //101
NSTUB(ReadFastDir                             ,0xff2fcb40) //115
NSTUB(Rec2PB                                  ,0xff083820) //104
NSTUB(RefreshPhysicalScreen                   ,0xff098024) //104
NSTUB(Remove                                  ,0xff021124) //  6
NSTUB(RenameFile_Fut                          ,0xff020848) //116
NSTUB(Restart                                 ,0xff025e54) //106
NSTUB(ScreenLock                              ,0xff099004) //  4
NSTUB(ScreenUnlock                            ,0xff099068) //  3
NSTUB(SetAE_ShutterSpeed                      ,0xff3a73a4) //102
NSTUB(SetAutoShutdownTime                     ,0xff08081c) //103
NSTUB(SetCurrentCaptureModeType               ,0xff0872d8) //101
NSTUB(SetFileAttributes                       ,0xff0213e8) //  6
NSTUB(SetFileTimeStamp                        ,0xff021370) //  6
NSTUB(SetLogicalEventActive                   ,0xff080524) //101
NSTUB(SetParameterData                        ,0xff1cb3cc) //101
NSTUB(SetPropertyCase                         ,0xff07b1f0) //102
NSTUB(SetScriptMode                           ,0xff080574) //101
NSTUB(SleepTask                               ,0x0068c2e8) //101
NSTUB(TakeSemaphore                           ,0x0068a990) //101
NSTUB(TurnOffBackLight                        ,0xff090158) //104
NSTUB(TurnOnBackLight                         ,0xff090140) //104
NSTUB(UIFS_WriteFirmInfoToFile                ,0xff1b0680) //101
NSTUB(UnlockAF                                ,0xff022a20) //102
NSTUB(UnlockMainPower                         ,0xff0806fc) //103
NSTUB(VbattGet                                ,0xff01d094) //101
NSTUB(Write                                   ,0xff020fa4) //101
NSTUB(WriteSDCard                             ,0xff17b53c) //108
NSTUB(_log                                    ,0x00690ce0) //111
NSTUB(_log10                                  ,0x00691220) //112
NSTUB(_pow                                    ,0x00691398) //114
NSTUB(_sqrt                                   ,0x00693038) //  6
NSTUB(add_ptp_handler                         ,0xff299f94) //  6
NSTUB(apex2us                                 ,0xff249874) //  4
NSTUB(close                                   ,0xff005be8) //  6
NSTUB(closedir                                ,0xff2fc98c) //  4
NSTUB(err_init_task                           ,0xff004378) //111
NSTUB(exmem_alloc                             ,0xff075cd8) //101
NSTUB(free                                    ,0xff002f74) //112
NSTUB(kbd_p1_f                                ,0xff01e89c) //109
NSTUB(kbd_p1_f_cont                           ,0xff01e8a8) //109
NSTUB(kbd_p2_f                                ,0xff01e0a0) //109
NSTUB(kbd_read_keys                           ,0xff01e84c) //109
NSTUB(kbd_read_keys_r2                        ,0xff049d58) //109
NSTUB(lseek                                   ,0xff0211cc) //101
NSTUB(malloc                                  ,0xff002f1c) //112
NSTUB(memcmp                                  ,0xff00b940) //101
NSTUB(memcpy                                  ,0xff0276e4) //101
NSTUB(memset                                  ,0xff24799c) //101
NSTUB(mkdir                                   ,0xff021480) // 12
NSTUB(mktime_ext                              ,0xff099564) //  1
NSTUB(open                                    ,0xff005b38) //  6
NSTUB(OpenFastDir                             ,0xff2fc9dc) //115
NSTUB(qsort                                   ,0xff24793c) //  6
NSTUB(rand                                    ,0xff247474) //  6
NSTUB(read                                    ,0xff005d8c) //101
NSTUB(reboot_fw_update                        ,0xff302224) //106
NSTUB(set_control_event                       ,0xff0801e4) //111
NSTUB(srand                                   ,0xff247468) //  6
NSTUB(stat                                    ,0xff021214) //109
NSTUB(strcat                                  ,0xff099be4) //  1
NSTUB(strchr                                  ,0xff002de8) //  1
NSTUB(strcmp                                  ,0xff00ba3c) //101
NSTUB(strcpy                                  ,0xff00b928) //101
NSTUB(strftime                                ,0xff0995b0) //113
NSTUB(strlen                                  ,0xff002e34) //101
NSTUB(strncmp                                 ,0xff002d9c) //  1
NSTUB(strncpy                                 ,0xff002d60) //  1
NSTUB(strrchr                                 ,0xff002e0c) //  1
NSTUB(strtol                                  ,0xff0276d0) //101
NSTUB(strtolx                                 ,0xff0274d4) //109
  DEF(task_CaptSeq                            ,0xff068e64) //110
  DEF(task_ExpDrv                             ,0xff0b2aa8) //110
  DEF(task_InitFileModules                    ,0xff084030) //110
  DEF(task_MovieRecord                        ,0xff193ce4) //110
  DEF(task_PhySw                              ,0xff01e404) //110
NSTUB(time                                    ,0x0068f8d0) //  6
NSTUB(vsprintf                                ,0xff00b7d8) //115
NSTUB(write                                   ,0xff020fa4) //101
