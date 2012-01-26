// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R49 (DRYOS version 2.3, release #0049)
//   Firmware Ver GM1.00D
//   Canon PowerShot SX40 HS

// Values for makefile.inc
//   PLATFORMID = 12856 (0x3238) // Found @ 0xfff40040
//   MAXRAMADDR = 0x0fffffff
//   KEYSYS = d4c                // Found @ 0xffff3b48
//   NEED_ENCODED_DISKBOOT = 7   // Found @ 0xffff3b58

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
// ERROR: kbd_pwr_off is not found.                        //--- ---    *** != 0xff057e44
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0xff057e44
NSTUB(reboot_fw_update                        ,0xff33ede8) //  6 96%

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff09bd14 -> ff098594 -> ff204788 -> ff36a8b0 -> ff607cdc
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00037548) // Found @0xff024dd8
DEF(physw_run                               ,0x00001c10) // Found @0xff024968
DEF(levent_table                            ,0xff5939d4) // Found @0xff5939d4
DEF(FlashParamsTable                        ,0xff607f3c) // Found @0xff607f3c
DEF(movie_status                            ,0x00002f1c) // Found @0xff077290
DEF(full_screen_refresh                     ,0x0000c2d8) // Found @0xff2917a8
DEF(canon_menu_active                       ,0x000034f0) // Found @0xff091b44
DEF(canon_shoot_menu_active                 ,0x0000ab6d) // Found @0xff22a6cc
DEF(playrec_mode                            ,0x00003214) // Found @0xff0834dc
DEF(zoom_status                             ,0x000111f8) // Found @0xff36e6a0
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 1 int value, which is the the zoom focus length.
// there are 201 entries in the table - set NUM_FL to 201
DEF(focus_len_table                         ,0xfff4a7b4) // Found @0xfff4a7b4
DEF(zoom_busy                               ,0x00002e2c) // Found @0xff071c54
DEF(focus_busy                              ,0x00008d08) // Found @0xff1bbe54
DEF(recreview_hold                          ,0x000041e4) // Found @0xff0a4414

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40685000; } // Found @0xff0515c4
//void *vid_get_viewport_fb()      { return (void*)0x407dab80; } // Found @0xff3e0b00
//char *camera_jpeg_count_str()    { return (char*)0x000df0e8; } // Found @0xff285400
//long hook_raw_size()             { return 0x01247a60; }        // Found @0xff3e3904
//int get_flash_params_count(void) { return 0x9f; }              // Found @0xff205d7c

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00000002 // Found @0xff434b34, levent 0x20a
//#define SD_READONLY_IDX     1
//#define USB_MASK            0x40000000 // Found @0xff434bac, levent 0x202
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_UP              ,0x00000400 }, // Found @0xff434ab4, levent 0x04
//    { 0, KEY_DOWN            ,0x00000800 }, // Found @0xff434abc, levent 0x05
//    { 0, KEY_LEFT            ,0x00001000 }, // Found @0xff434ac4, levent 0x06
//    { 0, KEY_RIGHT           ,0x00002000 }, // Found @0xff434acc, levent 0x07
//    { 0, KEY_SET             ,0x00004000 }, // Found @0xff434ad4, levent 0x08
//    { 0, KEY_DISPLAY         ,0x00020000 }, // Found @0xff434aec, levent 0x0a
//    { 0, KEY_MENU            ,0x00040000 }, // Found @0xff434af4, levent 0x09
//    { 2, KEY_SHOOT_FULL      ,0x0000c000 }, // Found @0xff434b74, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00008000 }, // Found @0xff434b74, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00004000 }, // Found @0xff434b6c, levent 0x00
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    4176 // Found @0xff18e020
//#define CAM_RAW_ROWS      3060 // Found @0xff18e02c
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff02bea8

// Misc stuff
DEF(ctypes, 0xff4337e2)

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NSTUB(AllocateMemory                          ,0xff35972c) //101
NSTUB(AllocateUncacheableMemory               ,0xff02be60) //112
NSTUB(Close                                   ,0xff0275e4) //101
NSTUB(CreateTask                              ,0xff00eaf0) //101
NSTUB(DebugAssert                             ,0xff00edc8) //111
NSTUB(DeleteDirectory_Fut                     ,0xff026fe0) //  1
NSTUB(DeleteFile_Fut                          ,0xff026efc) //112
NSTUB(DoAFLock                                ,0xff029330) //102
NSTUB(EnterToCompensationEVF                  ,0xff029704) //104
NSTUB(ExecuteEventProcedure                   ,0xff08cfdc) //  1
NSTUB(ExitFromCompensationEVF                 ,0xff029748) //104
NSTUB(ExitTask                                ,0xff00ed80) //101
NSTUB(ExpCtrlTool_StartContiAE                ,0xff037bf0) //104
NSTUB(ExpCtrlTool_StopContiAE                 ,0xff037cd0) //104
NSTUB(Fclose_Fut                              ,0xff027078) //101
NSTUB(Feof_Fut                                ,0xff027264) //  1
NSTUB(Fflush_Fut                              ,0xff0272a0) //  1
NSTUB(Fgets_Fut                               ,0xff0271cc) //  6
NSTUB(Fopen_Fut                               ,0xff027038) //101
NSTUB(Fread_Fut                               ,0xff027124) //101
NSTUB(FreeMemory                              ,0xff359724) //101
NSTUB(FreeUncacheableMemory                   ,0xff02bea0) //112
NSTUB(Fseek_Fut                               ,0xff027218) //101
NSTUB(Fwrite_Fut                              ,0xff027178) //101
NSTUB(GetBatteryTemperature                   ,0xff05bbd0) //102
NSTUB(GetCCDTemperature                       ,0xff05bb5c) //102
NSTUB(GetCurrentAvValue                       ,0xff1beb90) //102
NSTUB(GetDrive_ClusterSize                    ,0xff06a5f4) //  6
NSTUB(GetDrive_FreeClusters                   ,0xff06a64c) //  6
NSTUB(GetDrive_TotalClusters                  ,0xff06a624) //  6
NSTUB(GetFocusLensSubjectDistance             ,0xff1bca4c) //102
NSTUB(GetFocusLensSubjectDistanceFromLens     ,0xff1bcdb8) //  3
NSTUB(GetImageFolder                          ,0xff197630) //  6
NSTUB(GetKbdState                             ,0xff057bec) //109
NSTUB(GetMemInfo                              ,0xff00a2b8) //  3
NSTUB(GetOpticalTemperature                   ,0xff05bc44) //102
NSTUB(GetParameterData                        ,0xff205d3c) //101
NSTUB(GetPropertyCase                         ,0xff09107c) //102
NSTUB(GetSystemTime                           ,0xff359784) //101
NSTUB(GetZoomLensCurrentPoint                 ,0xff071fe4) //102
NSTUB(GetZoomLensCurrentPosition              ,0xff1c4f7c) //102
NSTUB(GiveSemaphore                           ,0xff02b5e0) //112
NSTUB(IsStrobeChargeCompleted                 ,0xff0efddc) //102
NSTUB(LEDDrive                                ,0xff056e40) //101
NSTUB(LocalTime                               ,0xff08a9a0) //  6
NSTUB(LockMainPower                           ,0xff09818c) //103
NSTUB(Lseek                                   ,0xff027800) //101
NSTUB(MakeDirectory_Fut                       ,0xff026f70) //  6
NSTUB(MakeSDCardBootable                      ,0xff06a884) //105
NSTUB(MoveFocusLensToDistance                 ,0xff3dc634) //102
NSTUB(MoveIrisWithAv                          ,0xff35503c) //102
NSTUB(MoveZoomLensWithPoint                   ,0xff355898) //102
NSTUB(NewTaskShell                            ,0xff0909fc) //101
NSTUB(Open                                    ,0xff02751c) //101
NSTUB(PB2Rec                                  ,0xff09b384) //104
NSTUB(PT_MoveDigitalZoomToWide                ,0xff079090) //102
NSTUB(PT_MoveOpticalZoomAt                    ,0xff079068) //102
NSTUB(PT_PlaySound                            ,0xff085410) //  6
NSTUB(PostLogicalEventForNotPowerType         ,0xff095b70) //103
NSTUB(PostLogicalEventToUI                    ,0xff095bbc) //103
NSTUB(PutInNdFilter                           ,0xff3da118) //102
NSTUB(PutOutNdFilter                          ,0xff3da150) //102
NSTUB(Read                                    ,0xff00ad74) //101
NSTUB(ReadFastDir                             ,0xff339694) //  6
NSTUB(Rec2PB                                  ,0xff099af4) //104
NSTUB(RefreshPhysicalScreen                   ,0xff0b19fc) //104
NSTUB(Remove                                  ,0xff027758) //  6
NSTUB(RenameFile_Fut                          ,0xff026e68) //  6
NSTUB(Restart                                 ,0xff02d6a0) //106
NSTUB(ScreenLock                              ,0xff0b2c28) //  4
NSTUB(ScreenUnlock                            ,0xff0b2c8c) //  3
NSTUB(SetAE_ShutterSpeed                      ,0xff3dfc78) //102
NSTUB(SetAutoShutdownTime                     ,0xff098200) //103
NSTUB(SetCurrentCaptureModeType               ,0xff0a1628) //101
NSTUB(SetFileTimeStamp                        ,0xff027970) //  6
NSTUB(SetLogicalEventActive                   ,0xff097ec8) //101
NSTUB(SetParameterData                        ,0xff205c18) //101
NSTUB(SetPropertyCase                         ,0xff090ef4) //102
NSTUB(SetScriptMode                           ,0xff097f64) //101
NSTUB(SleepTask                               ,0xff02b88c) //101
NSTUB(TakeSemaphore                           ,0xff02b510) //101
NSTUB(TurnOffBackLight                        ,0xff0a9688) //104
NSTUB(TurnOnBackLight                         ,0xff0a9670) //104
NSTUB(UIFS_WriteFirmInfoToFile                ,0xff1f157c) //101
NSTUB(UnlockAF                                ,0xff029368) //102
NSTUB(UnlockMainPower                         ,0xff0980e0) //103
NSTUB(VbattGet                                ,0xff022364) //101
NSTUB(Write                                   ,0xff027638) //101
NSTUB(WriteSDCard                             ,0xff1ab440) //108
NSTUB(_log                                    ,0xff430308) //111
NSTUB(_log10                                  ,0xff430848) //112
NSTUB(_pow                                    ,0xff4309c0) //114
NSTUB(_sqrt                                   ,0xff4325e4) //  6
NSTUB(add_ptp_handler                         ,0xff2dffb8) //  6
NSTUB(apex2us                                 ,0xff297bec) //  4
NSTUB(close                                   ,0xff00abd0) //  6
NSTUB(closedir                                ,0xff3394f0) //  4
NSTUB(err_init_task                           ,0xff00602c) //  4
NSTUB(exmem_alloc                             ,0xff08b960) //101
NSTUB(free                                    ,0xff004264) //112
NSTUB(kbd_p1_f                                ,0xff024e28) //109
NSTUB(kbd_p1_f_cont                           ,0xff024e34) //109
NSTUB(kbd_p2_f                                ,0xff024600) //109
NSTUB(kbd_read_keys                           ,0xff024dd8) //109
NSTUB(kbd_read_keys_r2                        ,0xff0572f4) //109
NSTUB(lseek                                   ,0xff027800) //101
NSTUB(malloc                                  ,0xff00420c) //112
NSTUB(memcmp                                  ,0xff010a48) //101
NSTUB(memcpy                                  ,0xff03169c) //101
NSTUB(memset                                  ,0xff295c24) //101
NSTUB(mkdir                                   ,0xff027a80) //  6
NSTUB(mktime_ext                              ,0xff0b3b98) //  1
NSTUB(open                                    ,0xff00ab20) //  6
NSTUB(opendir                                 ,0xff339540) //  6
NSTUB(openfastdir                             ,0xff339540) //  6
NSTUB(qsort                                   ,0xff3ae998) //  6
NSTUB(rand                                    ,0xff295d60) //  6
NSTUB(read                                    ,0xff00ad74) //101
NSTUB(readfastdir                             ,0xff339694) //  6
NSTUB(rename                                  ,0xff026e68) //  6
NSTUB(set_control_event                       ,0xff097a6c) //111
NSTUB(srand                                   ,0xff295d54) //  6
NSTUB(stat                                    ,0xff027848) //  3
NSTUB(strcat                                  ,0xff0b3350) //  1
NSTUB(strchr                                  ,0xff0040d8) //  1
NSTUB(strcmp                                  ,0xff010a04) //101
NSTUB(strcpy                                  ,0xff0109ec) //101
NSTUB(strftime                                ,0xff0b3598) //113
NSTUB(strlen                                  ,0xff004124) //101
NSTUB(strncmp                                 ,0xff00408c) //  1
NSTUB(strncpy                                 ,0xff004050) //  1
NSTUB(strrchr                                 ,0xff0040fc) //  1
NSTUB(strtol                                  ,0xff03199c) //101
NSTUB(strtolx                                 ,0xff0317a0) //109
  DEF(task_CaptSeq                            ,0xff07c454) //110
  DEF(task_ExpDrv                             ,0xff0cc408) //110
  DEF(task_InitFileModules                    ,0xff09bb88) //110
  DEF(task_MovieRecord                        ,0xff078534) //110
  DEF(task_PhySw                              ,0xff024964) //110
  DEF(task_RotaryEncoder                      ,0xff057f4c) //110
NSTUB(time                                    ,0xff08af7c) //  6
NSTUB(vsprintf                                ,0xff0109ac) //  6
NSTUB(write                                   ,0xff027638) //101
