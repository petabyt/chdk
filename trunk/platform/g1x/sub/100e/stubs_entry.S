// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R49 (DRYOS version 2.3, release #0049)
//   Firmware Ver GM1.00E
//   Canon PowerShot G1 X

// Values for makefile.inc
//   PLATFORMOSVER = 49
//   PLATFORMID = 12851 (0x3233) // Found @ 0xfff40040
//   MAXRAMADDR = 0x0fffffff
//   MEMISOSTART = 0x0018c774
//   KEYSYS = d4c                // Found @ 0xffff3bb0
//   NEED_ENCODED_DISKBOOT = 7   // Found @ 0xffff3bc0

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
// ERROR: kbd_pwr_off is not found.                        //--- ---    *** != 0x00000000
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff09ab04 -> ff097130 -> ff205130 -> ff388668 -> ff639724
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00038bfc) // Found @0xff023c4c
DEF(physw_run                               ,0x00001bf4) // Found @0xff0237dc
DEF(physw_sleep_delay                       ,0x00001bfc) // Found @0xff0237dc
DEF(levent_table                            ,0xff59d734) // Found @0xff59d734
DEF(FlashParamsTable                        ,0xff639988) // Found @0xff639988
DEF(movie_status                            ,0x00009ddc) // Found @0xff1c8b34
DEF(video_compression_rate                  ,0x00009e1c) // Found @0xff1c9fdc
DEF(full_screen_refresh                     ,0x0000cd94) // Found @0xff29aeac
DEF(canon_menu_active                       ,0x00004464) // Found @0xff090524
DEF(canon_shoot_menu_active                 ,0x0000b4e9) // Found @0xff22c6d4
DEF(playrec_mode                            ,0x00004184) // Found @0xff081de0
DEF(zoom_status                             ,0x0000b010) // Found @0xff213710
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 101 entries in the table - set NUM_FL to 101
DEF(focus_len_table                         ,0xfff4a6c8) // Found @0xfff4a6c8
DEF(zoom_busy                               ,0x00009c94) // Found @0xff1c382c
DEF(focus_busy                              ,0x00009ae4) // Found @0xff1bd34c
DEF(recreview_hold                          ,0x00005144) // Found @0xff0a3164
// Palette colour tables  found @ 0xff5ba1f8
DEF(palette_control                         ,0x0000cd94) // Found @0xff29ae28
DEF(active_palette_buffer                   ,0x0000cd9c) // Found @0xff29ae2c
DEF(palette_buffer_ptr                      ,0x0000cda0) // Found @0xff29b2e4
DEF(palette_buffer                          ,0x000cc858) // Found @0xff29b2f4
// Offset from start of palette_buffer to color data = 4 (Found @0xff3ca8d0)
DEF(bitmap_buffer                           ,0x0000cdd8) // Found @0xff29eb38
DEF(active_bitmap_buffer                    ,0x0000cdd0) // Found @0xff29eb3c
DEF(viewport_buffers                        ,0xff4640d4) // Found @0xff045214
DEF(active_viewport_buffer                  ,0x00002150) // Found @0xff044ee8
// Camera has 2 RAW buffers @ 0x44000000 & 0x4a6ba6a0
//  Note: active buffer --> raw_buffers[active_raw_buffer]
//        other buffer  --> raw_buffers[active_raw_buffer^1]
DEF(raw_buffers                             ,0xff475cc4) // Found @0xff475cc4
DEF(active_raw_buffer                       ,0x000040d4) // Found @0xff07da9c

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40685000; }             // Found @0xff0501b8
//void *vid_get_viewport_fb()      { return (void*)0x407dab80; }             // Found @0xff407478
DEF(viewport_fb_d                           ,0x00003de0) // Found 0x3d88 (@0xff06e504) + 0x58 (@0xff06e53c)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x3d88+0x58)); } // Found @0xff06e504 & 0xff06e53c
DEF(jpeg_count_str                          ,0x000cc108) // Found @0xff28c994
//char *camera_jpeg_count_str()    { return (char*)0x000cc108; }             // Found @0xff28c994
//long hook_raw_size()             { return 0x01941be8; }                    // Found @0xff40a294
//int get_flash_params_count(void) { return 0x9f; }                          // Found @0xff206724

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00000002 // Found @0xff46478c, levent 0x20a
//#define SD_READONLY_IDX     1
//#define USB_MASK            0x10000000 // Found @0xff464804, levent 0x202
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_SET             ,0x00000800 }, // Found @0xff464714, levent 0x08
//    { 0, KEY_RIGHT           ,0x00001000 }, // Found @0xff46471c, levent 0x07
//    { 0, KEY_DOWN            ,0x00002000 }, // Found @0xff464724, levent 0x05
//    { 0, KEY_MENU            ,0x00004000 }, // Found @0xff46472c, levent 0x09
//    { 0, KEY_LEFT            ,0x00008000 }, // Found @0xff464734, levent 0x06
//    { 0, KEY_UP              ,0x00040000 }, // Found @0xff46474c, levent 0x04
//    { 0, KEY_VIDEO           ,0x00080000 }, // Found @0xff464754, levent 0x19
//    { 0, KEY_ZOOM_IN         ,0x00100000 }, // Found @0xff46475c, levent 0x02
//    { 0, KEY_ZOOM_OUT        ,0x00200000 }, // Found @0xff464764, levent 0x03
//    { 2, KEY_POWER           ,0x00000800 }, // Found @0xff4647a4, levent 0x100
//    { 2, KEY_PLAYBACK        ,0x00008000 }, // Found @0xff4647c4, levent 0x101
//    { 2, KEY_SHOOT_FULL      ,0x000c0000 }, // Found @0xff4647d4, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00080000 }, // Found @0xff4647d4, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00040000 }, // Found @0xff4647cc, levent 0x00
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    4496 // Found @0xff190c98
//#define CAM_RAW_ROWS      3366 // Found @0xff190ca4
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff02ac74

// Misc stuff
DEF(ctypes, 0xff46343e)

// For capt_seq.c
DEF(_nrflag,0xceb0) // Found @ ff2a7988 (0xceac) & ff2a79c4 (+0x04)
//static long *nrflag = (long*)(0xceac+0x04);  // Found @ ff2a7988 & ff2a79c4
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
//NHSTUB(CreateJumptable                      ,0xff40a45c) //  1
// ALT: NHSTUB(CreateJumptable, 0xff40c6e0) // 1 32/0
//NHSTUB(_uartr_req                           ,0xff00fef8) //111
//NHSTUB(StartRecModeMenu                     ,0xff090520) //102
//NHSTUB(AllocateMemory                       ,0xff37459c) //101
NHSTUB(AllocateUncacheableMemory              ,0xff02ac2c) //112
NHSTUB(Close                                  ,0xff026458) //101
//NHSTUB(CreateBinarySemaphore                ,0xff02a158) //115
//NHSTUB(CreateCountingSemaphore              ,0xff02a1c0) //105
NHSTUB(CreateTask                             ,0xff00eaf0) //101
NHSTUB(DebugAssert                            ,0xff00edc8) //111
NHSTUB(DeleteDirectory_Fut                    ,0xff025e54) //116
NHSTUB(DeleteFile_Fut                         ,0xff025d70) //112
//NHSTUB(DeleteSemaphore                      ,0xff02a218) //105
NHSTUB(DoAFLock                               ,0xff0280d0) //102
NHSTUB(EnterToCompensationEVF                 ,0xff0284a4) //104
NHSTUB(ExecuteEventProcedure                  ,0xff08b9c0) //104
NHSTUB(ExitFromCompensationEVF                ,0xff0284e8) //104
NHSTUB(ExitTask                               ,0xff00ed80) //101
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff036ba4) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff036c84) //104
NHSTUB(Fclose_Fut                             ,0xff025eec) //101
NHSTUB(Feof_Fut                               ,0xff0260d8) //  1
NHSTUB(Fflush_Fut                             ,0xff026114) //  1
NHSTUB(Fgets_Fut                              ,0xff026040) //  6
NHSTUB(Fopen_Fut                              ,0xff025eac) //101
NHSTUB(Fread_Fut                              ,0xff025f98) //101
//NHSTUB(FreeMemory                           ,0xff374594) //101
NHSTUB(FreeUncacheableMemory                  ,0xff02ac6c) //112
NHSTUB(Fseek_Fut                              ,0xff02608c) //101
NHSTUB(Fwrite_Fut                             ,0xff025fec) //101
NHSTUB(GetBatteryTemperature                  ,0xff05de30) //102
NHSTUB(GetCCDTemperature                      ,0xff05ddbc) //102
NHSTUB(GetCurrentAvValue                      ,0xff1c0284) //102
NHSTUB(GetDrive_ClusterSize                   ,0xff06cbb8) //  6
NHSTUB(GetDrive_FreeClusters                  ,0xff06cc10) //  6
NHSTUB(GetDrive_TotalClusters                 ,0xff06cbe8) //  6
NHSTUB(GetFocusLensSubjectDistance            ,0xff1be0c8) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff1be518) //  3
NHSTUB(GetImageFolder                         ,0xff19a434) //  6
NHSTUB(GetKbdState                            ,0xff05726c) //109
NHSTUB(GetMemInfo                             ,0xff00a2b8) //115
NHSTUB(GetOpticalTemperature                  ,0xff05dea4) //102
NHSTUB(GetParameterData                       ,0xff2066e4) //101
NHSTUB(GetPropertyCase                        ,0xff08fa60) //102
NHSTUB(GetSystemTime                          ,0xff3745f4) //101
NHSTUB(GetVRAMHPixelsSize                     ,0xff047814) //102
NHSTUB(GetVRAMVPixelsSize                     ,0xff047820) //102
NHSTUB(GetZoomLensCurrentPoint                ,0xff1c3ca4) //102
NHSTUB(GetZoomLensCurrentPosition             ,0xff360b28) //102
NHSTUB(GiveSemaphore                          ,0xff02a394) //112
NHSTUB(IsStrobeChargeCompleted                ,0xff0f2418) //102
NHSTUB(LEDDrive                               ,0xff056488) //101
NHSTUB(LocalTime                              ,0xff089384) //115
NHSTUB(LockMainPower                          ,0xff096d28) //103
//NHSTUB(Lseek                                ,0xff026674) //101
NHSTUB(MakeDirectory_Fut                      ,0xff025de4) //116
NHSTUB(MakeSDCardBootable                     ,0xff06ce48) //105
NHSTUB(MoveFocusLensToDistance                ,0xff4036b0) //102
NHSTUB(MoveIrisWithAv                         ,0xff370d44) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xff3716d4) //102
//NHSTUB(NewTaskShell                         ,0xff08f3e0) //101
NHSTUB(Open                                   ,0xff026390) //101
NHSTUB(PB2Rec                                 ,0xff09a0d4) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff0780fc) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff0780d4) //102
NHSTUB(PT_PlaySound                           ,0xff083df4) //  6
NHSTUB(PostLogicalEventForNotPowerType        ,0xff094594) //103
NHSTUB(PostLogicalEventToUI                   ,0xff0945e0) //103
NHSTUB(PutInNdFilter                          ,0xff3714ac) //102
NHSTUB(PutOutNdFilter                         ,0xff3714d0) //102
NHSTUB(Read                                   ,0xff00ad74) //101
NHSTUB(ReadFastDir                            ,0xff34c3a4) //115
NHSTUB(Rec2PB                                 ,0xff09a114) //104
NHSTUB(RefreshPhysicalScreen                  ,0xff0b3058) //104
//NHSTUB(Remove                               ,0xff0265cc) //  6
NHSTUB(RenameFile_Fut                         ,0xff025cdc) //116
NHSTUB(Restart                                ,0xff02c444) //106
NHSTUB(ScreenLock                             ,0xff0b4284) //117
NHSTUB(ScreenUnlock                           ,0xff0b42e8) //117
NHSTUB(SetAE_ShutterSpeed                     ,0xff4065f0) //102
NHSTUB(SetAutoShutdownTime                    ,0xff096d9c) //103
NHSTUB(SetCurrentCaptureModeType              ,0xff0a0250) //101
NHSTUB(SetFileAttributes                      ,0xff02685c) //  6
NHSTUB(SetFileTimeStamp                       ,0xff0267e4) //  6
NHSTUB(SetLogicalEventActive                  ,0xff096a74) //101
NHSTUB(SetParameterData                       ,0xff2065c0) //101
NHSTUB(SetPropertyCase                        ,0xff08f8d8) //102
NHSTUB(SetScriptMode                          ,0xff096ac4) //101
NHSTUB(SleepTask                              ,0xff02a640) //101
NHSTUB(TakeSemaphore                          ,0xff02a2c4) //101
NHSTUB(TurnOffBackLight                       ,0xff0aab48) //104
NHSTUB(TurnOnBackLight                        ,0xff0aab30) //104
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff1f08d8) //101
NHSTUB(UnlockAF                               ,0xff028108) //102
NHSTUB(UnlockMainPower                        ,0xff096c7c) //103
NHSTUB(VbattGet                               ,0xff022338) //101
NHSTUB(Write                                  ,0xff0264ac) //101
NHSTUB(WriteSDCard                            ,0xff1aed6c) //108
NHSTUB(_log                                   ,0xff45fc28) //111
NHSTUB(_log10                                 ,0xff460168) //112
NHSTUB(_pow                                   ,0xff4602e0) //114
NHSTUB(_sqrt                                  ,0xff462240) //  6
NHSTUB(add_ptp_handler                        ,0xff2eb4f0) //  6
NHSTUB(apex2us                                ,0xff2a1304) //  4
NHSTUB(close                                  ,0xff00abd0) //  6
NHSTUB(closedir                               ,0xff34c200) //  4
NHSTUB(err_init_task                          ,0xff00602c) //111
NHSTUB(exmem_alloc                            ,0xff08a344) //101
NHSTUB(exmem_free                             ,0xff08a3bc) //101
NHSTUB(free                                   ,0xff004264) //112
NHSTUB(kbd_p1_f                               ,0xff023c9c) //109
NHSTUB(kbd_p1_f_cont                          ,0xff023ca8) //109
NHSTUB(kbd_p2_f                               ,0xff023474) //109
NHSTUB(kbd_read_keys                          ,0xff023c4c) //109
NHSTUB(kbd_read_keys_r2                       ,0xff056960) //109
NHSTUB(lseek                                  ,0xff026674) //101
NHSTUB(malloc                                 ,0xff00420c) //112
NHSTUB(memcmp                                 ,0xff010a1c) //101
NHSTUB(memcpy                                 ,0xff0304a4) //101
NHSTUB(memset                                 ,0xff29f328) //101
NHSTUB(mkdir                                  ,0xff0268f4) //109
NHSTUB(mktime_ext                             ,0xff0b51a0) //  1
NHSTUB(open                                   ,0xff00ab20) //  6
NHSTUB(OpenFastDir                            ,0xff34c250) //115
NHSTUB(qsort                                  ,0xff3cb494) //  6
NHSTUB(rand                                   ,0xff29f464) //  6
//NHSTUB(read                                 ,0xff00ad74) //101
NHSTUB(realloc                                ,0xff29f3a4) //115
NHSTUB(reboot_fw_update                       ,0xff351af8) //106
NHSTUB(set_control_event                      ,0xff096668) //111
NHSTUB(srand                                  ,0xff29f458) //  6
NHSTUB(stat                                   ,0xff0266bc) //109
NHSTUB(strcat                                 ,0xff0b4958) //  1
NHSTUB(strchr                                 ,0xff0040d8) //  1
NHSTUB(strcmp                                 ,0xff0109d8) //101
NHSTUB(strcpy                                 ,0xff0109c0) //101
NHSTUB(strftime                               ,0xff0b4ba0) //113
NHSTUB(strlen                                 ,0xff004124) //101
NHSTUB(strncmp                                ,0xff00408c) //  1
NHSTUB(strncpy                                ,0xff004050) //  1
NHSTUB(strrchr                                ,0xff0040fc) //  1
NHSTUB(strtol                                 ,0xff0307a4) //101
NHSTUB(strtolx                                ,0xff0305a8) //109
   DEF(task_CaptSeq                           ,0xff07b330) //110
   DEF(task_ExpDrv                            ,0xff0cd9f0) //110
   DEF(task_FileWrite                         ,0xff34a198) //110
   DEF(task_InitFileModules                   ,0xff09a978) //110
   DEF(task_MovieRecord                       ,0xff1ca86c) //110
   DEF(task_PhySw                             ,0xff0237d8) //110
   DEF(task_RotaryEncoder                     ,0xff0575cc) //110
NHSTUB(time                                   ,0xff089960) //109
NHSTUB(vsprintf                               ,0xff010980) //115
//NHSTUB(write                                ,0xff0264ac) //101
//NHSTUB(EngDrvIn                             ,0xff024ac0) //102
//NHSTUB(EngDrvOut                            ,0xff024aa8) //102
//NHSTUB(EngDrvRead                           ,0xff024ac8) //102
//NHSTUB(EngDrvBits                           ,0xff024adc) //102
//NHSTUB(GetSDProtect                         ,0xff023c04) //101
//NHSTUB(DispCon_ShowBitmapColorBar           ,0xff050174) //102
//NHSTUB(ResetZoomLens                        ,0xff371628) //102
//NHSTUB(ResetFocusLens                       ,0xff36ff24) //102
//NHSTUB(NR_GetDarkSubType                    ,0xff2a7a48) //102
//NHSTUB(NR_SetDarkSubType                    ,0xff2a7980) //102
//NHSTUB(SavePaletteData                      ,0xff1ce16c) //102
//NHSTUB(GUISrv_StartGUISystem                ,0xff0b2870) //101
