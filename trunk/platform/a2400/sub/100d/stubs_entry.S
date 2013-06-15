// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R50 (DRYOS version 2.3, release #0050)
//   Firmware Ver GM1.00D
//   Canon PowerShot A2400 IS

// Values for makefile.inc
//   PLATFORMOSVER = 50
//   PLATFORMID = 12873 (0x3249) // Found @ 0xfffe0040
//   MAXRAMADDR = 0x03ffffff
//   KEYSYS = d4c                // Found @ 0xffff1d28
//   NEED_ENCODED_DISKBOOT = 8   // Found @ 0xffff1d38

// Note, ROM copied to RAM :- from 0xffc022ac, to 0x003f1000, len 15733 words.

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NHSTUB(DeleteFile_Fut                       ,0xff830e44) //  1 90%        == 0xff830e44
// ERROR: MakeDirectory_Fut is not found.                  //--- ---    *** != 0xff831954
//NHSTUB(kbd_pwr_off                          ,0xff8569fc) //  2 60%    *** != 0x00000000
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000
// ERROR: rand is not found.                               //--- ---    *** != 0x00000000
// ERROR: srand is not found.                              //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff889184 -> ff885d8c -> ff989654 -> ffa83524 -> ffb9f4b8
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00031440) // Found @0xff82edb0
DEF(physw_run                               ,0x00001c18) // Found @0xff82e960
DEF(physw_sleep_delay                       ,0x00001c20) // Found @0xff82e960
DEF(levent_table                            ,0xffb5b640) // Found @0xffb5b640
DEF(FlashParamsTable                        ,0xffb9f710) // Found @0xffb9f710
DEF(movie_status                            ,0x0000645c) // Found @0xff95e388
DEF(video_compression_rate                  ,0x0000649c) // Found @0xff95efa4
DEF(full_screen_refresh                     ,0x00008768) // Found @0xff9d83ac
DEF(canon_menu_active                       ,0x00002ed0) // Found @0xff881c78
DEF(canon_shoot_menu_active                 ,0x000078b9) // Found @0xff9a05b0
DEF(playrec_mode                            ,0x00002c20) // Found @0xff875b90
DEF(zoom_status                             ,0x0000b790) // Found @0xffa86cbc
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 64 entries in the table - set NUM_FL to 64
DEF(focus_len_table                         ,0xfffeabc8) // Found @0xfffeabc8
DEF(zoom_busy                               ,0x000062ec) // Found @0xff959250
DEF(focus_busy                              ,0x00006158) // Found @0xff95468c
DEF(recreview_hold                          ,0x0000347c) // Found @0xff88f588
// Palette colour tables  found @ 0xffb6c5f8
DEF(palette_control                         ,0x00008768) // Found @0xff9d8328
DEF(active_palette_buffer                   ,0x00008770) // Found @0xff9d832c
DEF(palette_buffer_ptr                      ,0x00008774) // Found @0xff9d86c0
DEF(palette_buffer                          ,0x000b2628) // Found @0xff9d86d0
// Offset from start of palette_buffer to color data = 4 (Found @0xffab9e1c)
DEF(viewport_buffers                        ,0xffb102a4) // Found @0xff849c9c
DEF(active_viewport_buffer                  ,0x000020b4) // Found @0xff849a04

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40411000; }             // Found @0xff852df0
//void *vid_get_viewport_fb()      { return (void*)0x40566b80; }             // Found @0xffae0064
DEF(viewport_fb_d                           ,0x000029b4) // Found 0x2960 (@0xff867a78) + 0x54 (@0xff867ab0)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2960+0x54)); } // Found @0xff867a78 & 0xff867ab0
DEF(jpeg_count_str                          ,0x000b1ebc) // Found @0xff9ce53c
//char *camera_jpeg_count_str()    { return (char*)0x000b1ebc; }             // Found @0xff9ce53c
//long hook_raw_size()             { return 0x01794300; }                    // Found @0xffae2e98
//int get_flash_params_count(void) { return 0xa6; }                          // Found @0xff98a6a0

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffb1076c, levent 0x20a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00040000 // Found @0xffb10774, levent 0x202
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_ZOOM_OUT        ,0x00001000 }, // Found @0xffb106f4, levent 0x03
//    { 0, KEY_ZOOM_IN         ,0x00002000 }, // Found @0xffb106fc, levent 0x02
//    { 1, KEY_SHOOT_FULL      ,0x00300000 }, // Found @0xffb1070c, levent 0x01
//    { 1, KEY_SHOOT_FULL_ONLY ,0x00200000 }, // Found @0xffb1070c, levent 0x01
//    { 1, KEY_SHOOT_HALF      ,0x00100000 }, // Found @0xffb10704, levent 0x00
//    { 1, KEY_UP              ,0x00400000 }, // Found @0xffb10714, levent 0x04
//    { 1, KEY_DOWN            ,0x00800000 }, // Found @0xffb1071c, levent 0x05
//    { 1, KEY_RIGHT           ,0x01000000 }, // Found @0xffb10724, levent 0x07
//    { 1, KEY_LEFT            ,0x02000000 }, // Found @0xffb1072c, levent 0x06
//    { 1, KEY_MENU            ,0x04000000 }, // Found @0xffb10734, levent 0x09
//    { 1, KEY_SET             ,0x08000000 }, // Found @0xffb1073c, levent 0x08
//    { 1, KEY_VIDEO           ,0x10000000 }, // Found @0xffb10744, levent 0x1a
//    { 1, KEY_HELP            ,0x20000000 }, // Found @0xffb1074c, levent 0x14
//    { 1, KEY_POWER           ,0x40000000 }, // Found @0xffb10754, levent 0x100
//    { 1, KEY_PLAYBACK        ,0x80000000 }, // Found @0xffb1075c, levent 0x101
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    4704 // Found @0xff92f42c
//#define CAM_RAW_ROWS      3504 // Found @0xff92f438
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff8342dc

// Misc stuff
DEF(ctypes, 0xffb0faf4)

// For capt_seq.c
DEF(_nrflag,0x88a4) // Found @ ff9e4f08 (0x88a4) & ff9e4f44 (+0x00)
//static long *nrflag = (long*)(0x88a4+0x00);  // Found @ ff9e4f08 & ff9e4f44
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
//NHSTUB(CreateJumptable                      ,0xffae3064) //  1
// ALT: NHSTUB(CreateJumptable, 0xffae53d4) // 1 32/0
//NHSTUB(_uartr_req                           ,0xff81a7dc) //111
//NHSTUB(AllocateMemory                       ,0xffa758cc) //101
NHSTUB(AllocateUncacheableMemory              ,0xff834294) //112
NHSTUB(Close                                  ,0xff8314b8) //101
NHSTUB(CreateTask                             ,0x003f6824) //101
NHSTUB(DebugAssert                            ,0x003f6afc) //111
NHSTUB(DeleteDirectory_Fut                    ,0xff830eb8) //116
NHSTUB(DoAFLock                               ,0xff832d38) //102
NHSTUB(EnterToCompensationEVF                 ,0xff832f9c) //104
NHSTUB(ExecuteEventProcedure                  ,0xff87d1a0) //104
NHSTUB(ExitFromCompensationEVF                ,0xff832fe0) //104
NHSTUB(ExitTask                               ,0x003f6ab4) //101
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff83d720) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff83d87c) //104
NHSTUB(Fclose_Fut                             ,0xff830f50) //101
NHSTUB(Feof_Fut                               ,0xff83113c) //  1
NHSTUB(Fflush_Fut                             ,0xff831178) //  1
NHSTUB(Fgets_Fut                              ,0xff8310a4) //  6
NHSTUB(Fopen_Fut                              ,0xff830f10) //101
NHSTUB(Fread_Fut                              ,0xff830ffc) //101
//NHSTUB(FreeMemory                           ,0xffa758c4) //101
NHSTUB(FreeUncacheableMemory                  ,0xff8342d4) //112
NHSTUB(Fseek_Fut                              ,0xff8310f0) //101
NHSTUB(Fwrite_Fut                             ,0xff831050) //101
NHSTUB(GetBatteryTemperature                  ,0xff8589e0) //102
NHSTUB(GetCCDTemperature                      ,0xff85896c) //102
NHSTUB(GetCurrentAvValue                      ,0xff956250) //102
NHSTUB(GetDrive_ClusterSize                   ,0xff8664cc) //  6
NHSTUB(GetDrive_FreeClusters                  ,0xff866524) //  6
NHSTUB(GetDrive_TotalClusters                 ,0xff8664fc) //  6
NHSTUB(GetFocusLensSubjectDistance            ,0xff955450) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff9558a0) //  3
NHSTUB(GetImageFolder                         ,0xff9389ac) //  6
NHSTUB(GetKbdState                            ,0xff8569ec) //109
NHSTUB(GetMemInfo                             ,0xff81509c) //115
NHSTUB(GetOpticalTemperature                  ,0xff858a54) //102
NHSTUB(GetParameterData                       ,0xff98a660) //101
NHSTUB(GetPropertyCase                        ,0xff881218) //102
NHSTUB(GetSystemTime                          ,0xffa75924) //101
NHSTUB(GetVRAMHPixelsSize                     ,0xff84bd7c) //102
NHSTUB(GetVRAMVPixelsSize                     ,0xff84bd88) //102
NHSTUB(GetZoomLensCurrentPoint                ,0xff9596d0) //102
NHSTUB(GetZoomLensCurrentPosition             ,0xffa66a78) //102
NHSTUB(GiveSemaphore                          ,0x003f7704) //112
NHSTUB(IsStrobeChargeCompleted                ,0xff8cb1e4) //102
NHSTUB(LEDDrive                               ,0xff96058c) //101
NHSTUB(LocalTime                              ,0x003fb1b8) //115
NHSTUB(LockMainPower                          ,0xff885ac8) //103
//NHSTUB(Lseek                                ,0xff8316d4) //101
NHSTUB(MakeSDCardBootable                     ,0xff86675c) //105
NHSTUB(MoveFocusLensToDistance                ,0xffadc11c) //102
NHSTUB(MoveIrisWithAv                         ,0xffa70d5c) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xffa71490) //102
//NHSTUB(NewTaskShell                         ,0xff880b98) //101
NHSTUB(Open                                   ,0xff8313f0) //101
NHSTUB(PB2Rec                                 ,0xff888810) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff86eab4) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff86ea8c) //102
NHSTUB(PT_PlaySound                           ,0xff8779dc) // 11
NHSTUB(PostLogicalEventForNotPowerType        ,0xff8851bc) //103
NHSTUB(PostLogicalEventToUI                   ,0xff885208) //103
NHSTUB(PutInNdFilter                          ,0xffa71268) //102
NHSTUB(PutOutNdFilter                         ,0xffa7128c) //102
NHSTUB(Read                                   ,0xff815b58) //101
NHSTUB(ReadFastDir                            ,0xffa56f9c) //115
NHSTUB(Rec2PB                                 ,0xff888850) //104
NHSTUB(RefreshPhysicalScreen                  ,0xff897430) //104
//NHSTUB(Remove                               ,0xff83162c) //  6
NHSTUB(RenameFile_Fut                         ,0xff830db0) //116
NHSTUB(Restart                                ,0xff835aa8) //106
NHSTUB(ScreenLock                             ,0xff898450) //  4
NHSTUB(ScreenUnlock                           ,0xff8984b4) //  3
NHSTUB(SetAE_ShutterSpeed                     ,0xffadf23c) //102
NHSTUB(SetAutoShutdownTime                    ,0xff885b3c) //103
NHSTUB(SetCurrentCaptureModeType              ,0xff88c9e8) //101
NHSTUB(SetFileAttributes                      ,0xff8318bc) //  6
NHSTUB(SetFileTimeStamp                       ,0xff831844) //  6
NHSTUB(SetLogicalEventActive                  ,0xff885844) //101
NHSTUB(SetParameterData                       ,0xff98a5d0) //101
NHSTUB(SetPropertyCase                        ,0xff881090) //102
NHSTUB(SetScriptMode                          ,0xff885894) //101
NHSTUB(SleepTask                              ,0x003f79b0) //101
NHSTUB(TakeSemaphore                          ,0x003f7634) //101
NHSTUB(TurnOffBackLight                       ,0xff892548) //104
NHSTUB(TurnOnBackLight                        ,0xff892530) //104
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff97c1a0) //101
NHSTUB(UnlockAF                               ,0xff832d70) //102
NHSTUB(UnlockMainPower                        ,0xff885a1c) //103
NHSTUB(UnsetZoomForMovie                      ,0xff990e30) //104
NHSTUB(VbattGet                               ,0xff82c3cc) //101
NHSTUB(Write                                  ,0xff83150c) //101
NHSTUB(WriteSDCard                            ,0xff948710) //108
NHSTUB(_log                                   ,0x003fcce0) //111
NHSTUB(_log10                                 ,0x003fd220) //112
NHSTUB(_pow                                   ,0x003fd398) //114
NHSTUB(_sqrt                                  ,0x003fefbc) //  6
NHSTUB(add_ptp_handler                        ,0xffa1ac68) //  6
NHSTUB(apex2us                                ,0xff9de728) //  4
NHSTUB(close                                  ,0xff8159b4) //  6
NHSTUB(closedir                               ,0xffa56df8) //  4
NHSTUB(err_init_task                          ,0xff81437c) //111
NHSTUB(exmem_alloc                            ,0xff87bb74) //101
NHSTUB(exmem_free                             ,0xff87bbec) //101
NHSTUB(free                                   ,0xff812f78) //112
NHSTUB(kbd_p1_f                               ,0xff82ee00) //109
NHSTUB(kbd_p1_f_cont                          ,0xff82ee0c) //109
NHSTUB(kbd_p2_f                               ,0xff82e5f8) //109
NHSTUB(kbd_read_keys                          ,0xff82edb0) //109
NHSTUB(kbd_read_keys_r2                       ,0xff856508) //109
NHSTUB(lseek                                  ,0xff8316d4) //101
NHSTUB(malloc                                 ,0xff812f20) //112
NHSTUB(memcmp                                 ,0xff81ae30) //101
NHSTUB(memcpy                                 ,0xff837214) //101
NHSTUB(memset                                 ,0xff9dc9b8) //101
NHSTUB(mkdir                                  ,0xff831954) //  6
NHSTUB(mktime_ext                             ,0xff898980) //  1
NHSTUB(open                                   ,0xff815904) //  6
NHSTUB(OpenFastDir                            ,0xffa56e48) //115
NHSTUB(qsort                                  ,0xff9dc958) //  6
//NHSTUB(read                                 ,0xff815b58) //101
NHSTUB(realloc                                ,0xff9dca34) //115
NHSTUB(reboot_fw_update                       ,0xffa5c378) //106
NHSTUB(set_control_event                      ,0xff885504) //111
NHSTUB(stat                                   ,0xff83171c) //109
NHSTUB(strcat                                 ,0xff899000) //  1
NHSTUB(strchr                                 ,0xff812dec) //  1
NHSTUB(strcmp                                 ,0xff81af2c) //101
NHSTUB(strcpy                                 ,0xff81ae18) //101
NHSTUB(strftime                               ,0xff8989cc) //113
NHSTUB(strlen                                 ,0xff812e38) //101
NHSTUB(strncmp                                ,0xff812da0) //  1
NHSTUB(strncpy                                ,0xff812d64) //  1
NHSTUB(strrchr                                ,0xff812e10) //  1
NHSTUB(strtol                                 ,0xff837200) //101
NHSTUB(strtolx                                ,0xff837004) //109
   DEF(task_CaptSeq                           ,0xff8712dc) //110
   DEF(task_ExpDrv                            ,0xff8b0198) //110
   DEF(task_InitFileModules                   ,0xff889004) //110
   DEF(task_MovieRecord                       ,0xff95f834) //110
   DEF(task_PhySw                             ,0xff82e95c) //110
NHSTUB(time                                   ,0x003fb794) //  6
NHSTUB(vsprintf                               ,0xff81acc8) //115
//NHSTUB(write                                ,0xff83150c) //101
//NHSTUB(EngDrvIn                             ,0xff82fc38) //102
//NHSTUB(EngDrvOut                            ,0xff82fc20) //102
//NHSTUB(EngDrvRead                           ,0xff82fc40) //102
//NHSTUB(EngDrvBits                           ,0xff82fc54) //102
//NHSTUB(GetSDProtect                         ,0xff82ed6c) //101
//NHSTUB(StartRecModeMenu                     ,0xff881c74) //102
//NHSTUB(DispCon_ShowBitmapColorBar           ,0xff852dc0) //102
//NHSTUB(ResetZoomLens                        ,0xffa713e4) //102
//NHSTUB(ResetFocusLens                       ,0xffa6ff60) //102
//NHSTUB(NR_GetDarkSubType                    ,0xff9e4fc8) //102
//NHSTUB(NR_SetDarkSubType                    ,0xff9e4f00) //102
//NHSTUB(SavePaletteData                      ,0xff962f8c) //102
//NHSTUB(GUISrv_StartGUISystem                ,0xff896ce4) //101
