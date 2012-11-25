// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R45 (DRYOS version 2.3, release #0045)
//   Firmware Ver GM1.02B
//   Canon PowerShot SD4500 IS

// Values for makefile.inc
//   PLATFORMOSVER = 45
//   PLATFORMID = 12792 (0x31f8) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x07ffffff
//   KEYSYS = d4b                // Found @ 0xffff3624
//   NEED_ENCODED_DISKBOOT = 5   // Found @ 0xffff3634

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NSTUB(kbd_pwr_off                           ,0xff8634fc) //  2 60%    *** != 0x00000000
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff8a0354 -> ff89cae0 -> ff9b0d28 -> ffaf49cc -> ffc28e24
// Mode 33320 in firmware but not in current modemap
// Mode 33322 in firmware but not in current modemap

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00034408) // Found @0xff834b8c
DEF(physw_run                               ,0x00001c40) // Found @0xff834758
DEF(physw_sleep_delay                       ,0x00001c48) // Found @0xff834758
DEF(levent_table                            ,0xffbcdc60) // Found @0xffbcdc60
DEF(FlashParamsTable                        ,0xffc29028) // Found @0xffc29028
DEF(movie_status                            ,0x000078dc) // Found @0xff9858b4
DEF(full_screen_refresh                     ,0x0000a340) // Found @0xffa2bea0
DEF(canon_menu_active                       ,0x00003840) // Found @0xff896980
DEF(canon_shoot_menu_active                 ,0x00008aed) // Found @0xff9c6550
DEF(playrec_mode                            ,0x00003574) // Found @0xff888a64
//DEF(zoom_status                             ,0x0000e2c8) // Found @0xffaf7f50, ** != ** stubs_min = 0x0000e2a0 (0xE2A0)
DEF(some_flag_for_af_scan                   ,0x00007cb4) // Found @0xff989794
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 101 entries in the table - set NUM_FL to 101
DEF(focus_len_table                         ,0xfffe9eac) // Found @0xfffe9eac
DEF(zoom_busy                               ,0x00007618) // Found @0xff97a3fc
DEF(focus_busy                              ,0x00007394) // Found @0xff972b7c
//DEF(recreview_hold                          ,0x00004294) // Found @0xff8a882c, ** != ** stubs_min = 0x000087e0 (0x86F4+0xEC)
DEF(palette_control                         ,0x0000a340) // Found @0xffa2be1c
DEF(active_palette_buffer                   ,0x0000a348) // Found @0xffa2be20
DEF(palette_buffer                          ,0x000b84ac) // Found @0xffa2c354
DEF(bitmap_buffer                           ,0x0000a37c) // Found @0xffa31004
DEF(active_bitmap_buffer                    ,0x0000a374) // Found @0xffa31008

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40471000; }             // Found @0xff85d3b0
//void *vid_get_viewport_fb()      { return (void*)0x40587700; }             // Found @0xffb4cc1c
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x3230+0x58)); } // Found @0xff877d3c & 0xff877d74
//char *camera_jpeg_count_str()    { return (char*)0x000b7e00; }             // Found @0xffa238cc
//long hook_raw_size()             { return 0x00f32880; }                    // Found @0xffb500e4
//int get_flash_params_count(void) { return 0x9a; }                          // Found @0xff9b1d60

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffb8d644, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00080000 // Found @0xffb8d654, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 1, KEY_VIDEO           ,0x00000080 }, // Found @0xffb8d5a4, levent 0x12
//    { 1, KEY_UP              ,0x00000400 }, // Found @0xffb8d5bc, levent 0x04
//    { 1, KEY_RIGHT           ,0x00000800 }, // Found @0xffb8d5c4, levent 0x07
//    { 1, KEY_SET             ,0x00001000 }, // Found @0xffb8d5cc, levent 0x08
//    { 1, KEY_LEFT            ,0x00008000 }, // Found @0xffb8d5e4, levent 0x06
//    { 1, KEY_MENU            ,0x00010000 }, // Found @0xffb8d5ec, levent 0x09
//    { 1, KEY_DOWN            ,0x00020000 }, // Found @0xffb8d5f4, levent 0x05
//    { 2, KEY_POWER           ,0x00000008 }, // Found @0xffb8d61c, levent 0x600
//    { 2, KEY_PLAYBACK        ,0x00000100 }, // Found @0xffb8d624, levent 0x601
//    { 2, KEY_SHOOT_FULL      ,0x00002002 }, // Found @0xffb8d614, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00002000 }, // Found @0xffb8d62c, levent 0x00
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000002 }, // Found @0xffb8d614, levent 0x01
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_RAW_ROWPIX    3816 // Found @0xff94b510
//#define CAM_RAW_ROWS      2784 // Found @0xff94b51c
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff83b934

// Misc stuff
DEF(ctypes, 0xffb8be66)

// For capt_seq.c
//static long *nrflag = (long*)(0x7cf0+0x08);  // Found @ ff98d7d0 & ff98d7d4
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NSTUB(AllocateMemory                          ,0xffae5788) //101
NSTUB(AllocateUncacheableMemory               ,0xff83b8f0) //112
NSTUB(Close                                   ,0xff838060) //101
NSTUB(CreateTask                              ,0xff81e8a0) //101
NSTUB(DebugAssert                             ,0xff81eb78) //111
NSTUB(DeleteDirectory_Fut                     ,0xff837abc) //116
NSTUB(DeleteFile_Fut                          ,0xff8379d8) //112
NSTUB(DoAFLock                                ,0xff839670) //102
NSTUB(EnterToCompensationEVF                  ,0xff839770) //104
NSTUB(ExecuteEventProcedure                   ,0xff8920e0) //104
NSTUB(ExitFromCompensationEVF                 ,0xff8397b4) //104
NSTUB(ExitTask                                ,0xff81eb30) //101
NSTUB(ExpCtrlTool_StartContiAE                ,0xff847d34) //104
NSTUB(ExpCtrlTool_StopContiAE                 ,0xff847ec0) //104
NSTUB(Fclose_Fut                              ,0xff837b54) //101
NSTUB(Feof_Fut                                ,0xff837d40) //  1
NSTUB(Fflush_Fut                              ,0xff837d7c) //  1
NSTUB(Fgets_Fut                               ,0xff837ca8) //  1
NSTUB(Fopen_Fut                               ,0xff837b14) //101
NSTUB(Fread_Fut                               ,0xff837c00) //101
NSTUB(FreeMemory                              ,0xffae5780) //101
NSTUB(FreeUncacheableMemory                   ,0xff83b930) //112
NSTUB(Fseek_Fut                               ,0xff837cf4) //101
NSTUB(Fwrite_Fut                              ,0xff837c54) //101
NSTUB(GetBatteryTemperature                   ,0xff86839c) //102
NSTUB(GetCCDTemperature                       ,0xff868328) //102
NSTUB(GetCurrentAvValue                       ,0xff9752ac) //102
NSTUB(GetDrive_ClusterSize                    ,0xff8757e8) //  4
NSTUB(GetDrive_FreeClusters                   ,0xff875848) //  4
NSTUB(GetDrive_TotalClusters                  ,0xff87581c) //  3
NSTUB(GetFocusLensSubjectDistance             ,0xff973864) //102
NSTUB(GetFocusLensSubjectDistanceFromLens     ,0xff973cb8) //  3
NSTUB(GetImageFolder                          ,0xff952d68) //106
NSTUB(GetKbdState                             ,0xff8633c4) //109
NSTUB(GetMemInfo                              ,0xff81a264) //115
NSTUB(GetOpticalTemperature                   ,0xff868410) //102
NSTUB(GetParameterData                        ,0xff9b1d24) //101
NSTUB(GetPropertyCase                         ,0xff895de8) //102
NSTUB(GetSystemTime                           ,0xffae57e0) //101
NSTUB(GetVRAMHPixelsSize                      ,0xff854030) //102
NSTUB(GetVRAMVPixelsSize                      ,0xff85403c) //102
NSTUB(GetZoomLensCurrentPoint                 ,0xff97aec0) //102
NSTUB(GetZoomLensCurrentPosition              ,0xffacd274) //102
NSTUB(GiveSemaphore                           ,0xff83b30c) //112
NSTUB(IsStrobeChargeCompleted                 ,0xff8e5d34) //102
NSTUB(LEDDrive                                ,0xff8626a8) //103
NSTUB(LocalTime                               ,0xff88f9c8) //115
NSTUB(LockMainPower                           ,0xff89c6e4) //103
NSTUB(Lseek                                   ,0xff83817c) //101
NSTUB(MakeDirectory_Fut                       ,0xff837a4c) //116
NSTUB(MoveFocusLensToDistance                 ,0xffb49128) //102
NSTUB(MoveIrisWithAv                          ,0xffae0590) //102
NSTUB(MoveZoomLensWithPoint                   ,0xffae0e0c) //102
NSTUB(NewTaskShell                            ,0xff895804) //103
NSTUB(Open                                    ,0xff837ff4) //101
NSTUB(PB2Rec                                  ,0xff89f768) //104
NSTUB(PT_MoveDigitalZoomToWide                ,0xff880aac) //102
NSTUB(PT_MoveOpticalZoomAt                    ,0xff880a84) //102
NSTUB(PT_PlaySound                            ,0xff88a830) //  4
NSTUB(PostLogicalEventForNotPowerType         ,0xff89a444) //103
NSTUB(PostLogicalEventToUI                    ,0xff89a490) //103
NSTUB(PutInNdFilter                           ,0xffb46528) //102
NSTUB(PutOutNdFilter                          ,0xffb46560) //102
NSTUB(Read                                    ,0xff81ad74) //101
NSTUB(ReadFastDir                             ,0xffab91ec) //  4
NSTUB(Rec2PB                                  ,0xff89e010) //104
NSTUB(RefreshPhysicalScreen                   ,0xff8b3d28) //104
NSTUB(Remove                                  ,0xff838094) //  4
NSTUB(RenameFile_Fut                          ,0xff837944) //116
NSTUB(Restart                                 ,0xff83d0dc) //106
NSTUB(ScreenLock                              ,0xff8b4eec) //  4
NSTUB(ScreenUnlock                            ,0xff8b4f50) //  9
NSTUB(SetAE_ShutterSpeed                      ,0xffb4bcc8) //102
NSTUB(SetAutoShutdownTime                     ,0xff89c758) //103
NSTUB(SetCurrentCaptureModeType               ,0xff8a5a00) //101
NSTUB(SetFileAttributes                       ,0xff838358) //  3
NSTUB(SetFileTimeStamp                        ,0xff8382fc) //  4
NSTUB(SetLogicalEventActive                   ,0xff89c420) //101
NSTUB(SetParameterData                        ,0xff9b1c90) //101
NSTUB(SetPropertyCase                         ,0xff895cc0) //102
NSTUB(SetScriptMode                           ,0xff89c470) //101
NSTUB(SleepTask                               ,0xff83b574) //101
NSTUB(TakeSemaphore                           ,0xff83b23c) //101
NSTUB(TurnOffBackLight                        ,0xff8ac5bc) //104
NSTUB(TurnOnBackLight                         ,0xff8ac5a4) //104
NSTUB(UIFS_WriteFirmInfoToFile                ,0xff9a138c) //103
NSTUB(UnlockAF                                ,0xff8396a8) //102
NSTUB(UnlockMainPower                         ,0xff89c638) //103
NSTUB(UpdateMBROnFlash                        ,0xff875668) //105
NSTUB(VbattGet                                ,0xff833308) //103
NSTUB(Write                                   ,0xff8380f0) //101
NSTUB(WriteSDCard                             ,0xff962f74) //108
NSTUB(_log                                    ,0xffb88f74) //111
NSTUB(_log10                                  ,0xffb87c00) //112
NSTUB(_pow                                    ,0xffb87d70) //114
NSTUB(_sqrt                                   ,0xffb8ab7c) //  1
NSTUB(add_ptp_handler                         ,0xffa72b9c) //  3
NSTUB(apex2us                                 ,0xffa34f70) //  4
NSTUB(close                                   ,0xff81ab8c) //  1
NSTUB(closedir                                ,0xffab9048) //  4
NSTUB(err_init_task                           ,0xff815fd4) //111
NSTUB(exmem_alloc                             ,0xff890914) //103
NSTUB(free                                    ,0xff814244) //112
NSTUB(kbd_p1_f                                ,0xff834c04) //109
NSTUB(kbd_p1_f_cont                           ,0xff834c10) //109
NSTUB(kbd_p2_f                                ,0xff834424) //109
NSTUB(kbd_read_keys                           ,0xff834b8c) //109
NSTUB(kbd_read_keys_r2                        ,0xff862c10) //109
NSTUB(lseek                                   ,0xff83817c) //101
NSTUB(malloc                                  ,0xff8141e8) //112
NSTUB(memcmp                                  ,0xff820750) //101
NSTUB(memcpy                                  ,0xff84110c) //101
NSTUB(memset                                  ,0xffa33f6c) //101
NSTUB(mkdir                                   ,0xff8384fc) //109
NSTUB(mktime_ext                              ,0xff8b5cf4) //  1
NSTUB(open                                    ,0xff81aadc) //  1
NSTUB(OpenFastDir                             ,0xffab9098) //  4
NSTUB(qsort                                   ,0xffb2e2f4) //  4
NSTUB(rand                                    ,0xffa340ac) //  4
NSTUB(read                                    ,0xff81ad74) //101
NSTUB(reboot_fw_update                        ,0xffabe60c) //106
NSTUB(set_control_event                       ,0xff89c010) //111
NSTUB(srand                                   ,0xffa340a0) //  4
NSTUB(stat                                    ,0xff8381c4) //109
//NSTUB(strcat                                ,0xff8b54b0) //  1            == 0xff8b54b0
NSTUB(strchr                                  ,0xff8140b4) //  1
NSTUB(strcmp                                  ,0xff82070c) //101
NSTUB(strcpy                                  ,0xff8206f4) //101
NSTUB(strftime                                ,0xff8b56fc) //113
NSTUB(strlen                                  ,0xff814100) //101
NSTUB(strncmp                                 ,0xff814068) //  1
NSTUB(strncpy                                 ,0xff81402c) //  1
NSTUB(strrchr                                 ,0xff8140d8) //  1
NSTUB(strtol                                  ,0xff8413ec) //101
NSTUB(strtolx                                 ,0xff8411f0) //109
  DEF(task_CaptSeq                            ,0xff88365c) //107
  DEF(task_ExpDrv                             ,0xff8ccab4) //110
  DEF(task_InitFileModules                    ,0xff8a01e0) //107
  DEF(task_MovieRecord                        ,0xff986714) //107
  DEF(task_PhySw                              ,0xff834754) //107
  DEF(task_RotaryEncoder                      ,0xff863668) //107
NSTUB(time                                    ,0xff88ffa8) //109
NSTUB(vsprintf                                ,0xff8206b8) //115
NSTUB(write                                   ,0xff8380f0) //101
