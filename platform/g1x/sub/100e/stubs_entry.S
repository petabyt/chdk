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
//   KEYSYS = d4c                // Found @ 0xffff3bb0
//   NEED_ENCODED_DISKBOOT = 7   // Found @ 0xffff3bc0

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
// ERROR: kbd_pwr_off is not found.                        //--- ---    *** != 0x00000000
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000
NSTUB(reboot_fw_update                        ,0xff351af8) //  6 96%

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff09ab04 -> ff097130 -> ff205130 -> ff388668 -> ff639724
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00038bfc) // Found @0xff023c4c
DEF(physw_run                               ,0x00001bf4) // Found @0xff0237dc
DEF(physw_sleep_delay                       ,0x00001bfc) // Found @0xff0237dc
DEF(levent_table                            ,0xff59d734) // Found @0xff59d734
DEF(FlashParamsTable                        ,0xff639988) // Found @0xff639988
DEF(movie_status                            ,0x00009ddc) // Found @0xff1c98c0
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
DEF(palette_control                         ,0x0000cd94) // Found @0xff29ae28
DEF(active_palette_buffer                   ,0x0000cd9c) // Found @0xff29ae2c
DEF(palette_buffer                          ,0x000cc858) // Found @0xff29b2f4
DEF(bitmap_buffer                           ,0x0000cdd8) // Found @0xff29eb38
DEF(active_bitmap_buffer                    ,0x0000cdd0) // Found @0xff29eb3c

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40685000; }             // Found @0xff0501b8
//void *vid_get_viewport_fb()      { return (void*)0x407dab80; }             // Found @0xff407478
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x3d88+0x58)); } // Found @0xff06e504 & 0xff06e53c
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

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NSTUB(AllocateMemory                          ,0xff37459c) //101
NSTUB(AllocateUncacheableMemory               ,0xff02ac2c) //112
NSTUB(Close                                   ,0xff026458) //101
NSTUB(CreateTask                              ,0xff00eaf0) //101
NSTUB(DebugAssert                             ,0xff00edc8) //111
NSTUB(DeleteDirectory_Fut                     ,0xff025e54) //  1
NSTUB(DeleteFile_Fut                          ,0xff025d70) //112
NSTUB(DoAFLock                                ,0xff0280d0) //102
NSTUB(EnterToCompensationEVF                  ,0xff0284a4) //104
NSTUB(ExecuteEventProcedure                   ,0xff08b9c0) //  1
NSTUB(ExitFromCompensationEVF                 ,0xff0284e8) //104
NSTUB(ExitTask                                ,0xff00ed80) //101
NSTUB(ExpCtrlTool_StartContiAE                ,0xff036ba4) //104
NSTUB(ExpCtrlTool_StopContiAE                 ,0xff036c84) //104
NSTUB(Fclose_Fut                              ,0xff025eec) //101
NSTUB(Feof_Fut                                ,0xff0260d8) //  1
NSTUB(Fflush_Fut                              ,0xff026114) //  1
NSTUB(Fgets_Fut                               ,0xff026040) //  6
NSTUB(Fopen_Fut                               ,0xff025eac) //101
NSTUB(Fread_Fut                               ,0xff025f98) //101
NSTUB(FreeMemory                              ,0xff374594) //101
NSTUB(FreeUncacheableMemory                   ,0xff02ac6c) //112
NSTUB(Fseek_Fut                               ,0xff02608c) //101
NSTUB(Fwrite_Fut                              ,0xff025fec) //101
NSTUB(GetBatteryTemperature                   ,0xff05de30) //102
NSTUB(GetCCDTemperature                       ,0xff05ddbc) //102
NSTUB(GetCurrentAvValue                       ,0xff1c0284) //102
NSTUB(GetDrive_ClusterSize                    ,0xff06cbb8) //  6
NSTUB(GetDrive_FreeClusters                   ,0xff06cc10) //  6
NSTUB(GetDrive_TotalClusters                  ,0xff06cbe8) //  6
NSTUB(GetFocusLensSubjectDistance             ,0xff1be0c8) //102
NSTUB(GetFocusLensSubjectDistanceFromLens     ,0xff1be518) //  3
NSTUB(GetImageFolder                          ,0xff19a434) //  6
NSTUB(GetKbdState                             ,0xff05726c) //109
NSTUB(GetMemInfo                              ,0xff00a2b8) //  3
NSTUB(GetOpticalTemperature                   ,0xff05dea4) //102
NSTUB(GetParameterData                        ,0xff2066e4) //101
NSTUB(GetPropertyCase                         ,0xff08fa60) //102
NSTUB(GetSystemTime                           ,0xff3745f4) //101
NSTUB(GetVRAMHPixelsSize                      ,0xff047814) //102
NSTUB(GetVRAMVPixelsSize                      ,0xff047820) //102
NSTUB(GetZoomLensCurrentPoint                 ,0xff1c3ca4) //102
NSTUB(GetZoomLensCurrentPosition              ,0xff360b28) //102
NSTUB(GiveSemaphore                           ,0xff02a394) //112
NSTUB(IsStrobeChargeCompleted                 ,0xff0f2418) //102
NSTUB(LEDDrive                                ,0xff056488) //101
NSTUB(LocalTime                               ,0xff089384) //  6
NSTUB(LockMainPower                           ,0xff096d28) //103
NSTUB(Lseek                                   ,0xff026674) //101
NSTUB(MakeDirectory_Fut                       ,0xff025de4) //  6
NSTUB(MakeSDCardBootable                      ,0xff06ce48) //105
NSTUB(MoveFocusLensToDistance                 ,0xff4036b0) //102
NSTUB(MoveIrisWithAv                          ,0xff370d44) //102
NSTUB(MoveZoomLensWithPoint                   ,0xff3716d4) //102
NSTUB(NewTaskShell                            ,0xff08f3e0) //101
NSTUB(Open                                    ,0xff026390) //101
NSTUB(PB2Rec                                  ,0xff09a0d4) //104
NSTUB(PT_MoveDigitalZoomToWide                ,0xff0780fc) //102
NSTUB(PT_MoveOpticalZoomAt                    ,0xff0780d4) //102
NSTUB(PT_PlaySound                            ,0xff083df4) //  6
NSTUB(PostLogicalEventForNotPowerType         ,0xff094594) //103
NSTUB(PostLogicalEventToUI                    ,0xff0945e0) //103
NSTUB(PutInNdFilter                           ,0xff3714ac) //102
NSTUB(PutOutNdFilter                          ,0xff3714d0) //102
NSTUB(Read                                    ,0xff00ad74) //101
NSTUB(ReadFastDir                             ,0xff34c3a4) //  6
NSTUB(Rec2PB                                  ,0xff09a114) //104
NSTUB(RefreshPhysicalScreen                   ,0xff0b3058) //104
NSTUB(Remove                                  ,0xff0265cc) //  6
NSTUB(RenameFile_Fut                          ,0xff025cdc) //  6
NSTUB(Restart                                 ,0xff02c444) //106
NSTUB(ScreenLock                              ,0xff0b4284) //  4
NSTUB(ScreenUnlock                            ,0xff0b42e8) //  3
NSTUB(SetAE_ShutterSpeed                      ,0xff4065f0) //102
NSTUB(SetAutoShutdownTime                     ,0xff096d9c) //103
NSTUB(SetCurrentCaptureModeType               ,0xff0a0250) //101
NSTUB(SetFileAttributes                       ,0xff02685c) //  6
NSTUB(SetFileTimeStamp                        ,0xff0267e4) //  6
NSTUB(SetLogicalEventActive                   ,0xff096a74) //101
NSTUB(SetParameterData                        ,0xff2065c0) //101
NSTUB(SetPropertyCase                         ,0xff08f8d8) //102
NSTUB(SetScriptMode                           ,0xff096ac4) //101
NSTUB(SleepTask                               ,0xff02a640) //101
NSTUB(TakeSemaphore                           ,0xff02a2c4) //101
NSTUB(TurnOffBackLight                        ,0xff0aab48) //104
NSTUB(TurnOnBackLight                         ,0xff0aab30) //104
NSTUB(UIFS_WriteFirmInfoToFile                ,0xff1f08d8) //101
NSTUB(UnlockAF                                ,0xff028108) //102
NSTUB(UnlockMainPower                         ,0xff096c7c) //103
NSTUB(VbattGet                                ,0xff022338) //101
NSTUB(Write                                   ,0xff0264ac) //101
NSTUB(WriteSDCard                             ,0xff1aed6c) //108
NSTUB(_log                                    ,0xff45fc28) //111
NSTUB(_log10                                  ,0xff460168) //112
NSTUB(_pow                                    ,0xff4602e0) //114
NSTUB(_sqrt                                   ,0xff462240) //  6
NSTUB(add_ptp_handler                         ,0xff2eb4f0) //  6
NSTUB(apex2us                                 ,0xff2a1304) //  4
NSTUB(close                                   ,0xff00abd0) //  6
NSTUB(closedir                                ,0xff34c200) //  4
NSTUB(err_init_task                           ,0xff00602c) //  4
NSTUB(exmem_alloc                             ,0xff08a344) //101
NSTUB(free                                    ,0xff004264) //112
NSTUB(kbd_p1_f                                ,0xff023c9c) //109
NSTUB(kbd_p1_f_cont                           ,0xff023ca8) //109
NSTUB(kbd_p2_f                                ,0xff023474) //109
NSTUB(kbd_read_keys                           ,0xff023c4c) //109
NSTUB(kbd_read_keys_r2                        ,0xff056960) //109
NSTUB(lseek                                   ,0xff026674) //101
NSTUB(malloc                                  ,0xff00420c) //112
NSTUB(memcmp                                  ,0xff010a1c) //101
NSTUB(memcpy                                  ,0xff0304a4) //101
NSTUB(memset                                  ,0xff29f328) //101
NSTUB(mkdir                                   ,0xff0268f4) //  6
NSTUB(mktime_ext                              ,0xff0b51a0) //  1
NSTUB(open                                    ,0xff00ab20) //  6
NSTUB(opendir                                 ,0xff34c250) //  6
NSTUB(openfastdir                             ,0xff34c250) //  6
NSTUB(qsort                                   ,0xff3cb494) //  6
NSTUB(rand                                    ,0xff29f464) //  6
NSTUB(read                                    ,0xff00ad74) //101
NSTUB(rename                                  ,0xff025cdc) //  6
NSTUB(set_control_event                       ,0xff096668) //111
NSTUB(srand                                   ,0xff29f458) //  6
NSTUB(stat                                    ,0xff0266bc) //  3
NSTUB(strcat                                  ,0xff0b4958) //  1
NSTUB(strchr                                  ,0xff0040d8) //  1
NSTUB(strcmp                                  ,0xff0109d8) //101
NSTUB(strcpy                                  ,0xff0109c0) //101
NSTUB(strftime                                ,0xff0b4ba0) //113
NSTUB(strlen                                  ,0xff004124) //101
NSTUB(strncmp                                 ,0xff00408c) //  1
NSTUB(strncpy                                 ,0xff004050) //  1
NSTUB(strrchr                                 ,0xff0040fc) //  1
NSTUB(strtol                                  ,0xff0307a4) //101
NSTUB(strtolx                                 ,0xff0305a8) //109
  DEF(task_CaptSeq                            ,0xff07b330) //110
  DEF(task_ExpDrv                             ,0xff0cd9f0) //110
  DEF(task_InitFileModules                    ,0xff09a978) //110
  DEF(task_MovieRecord                        ,0xff1ca86c) //110
  DEF(task_PhySw                              ,0xff0237d8) //110
  DEF(task_RotaryEncoder                      ,0xff0575cc) //110
NSTUB(time                                    ,0xff089960) //  6
NSTUB(vsprintf                                ,0xff010980) //  6
NSTUB(write                                   ,0xff0264ac) //101
