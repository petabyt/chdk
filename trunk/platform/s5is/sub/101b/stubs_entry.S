// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R20 (DRYOS version 2.3, release #0020)
//   Firmware Ver GM1.01B
//   Canon PowerShot S5 IS

// Values for makefile.inc
//   PLATFORMOSVER = 20
//   PLATFORMID = 12616 (0x3148) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x03ffffff
//   KEYSYS = d3                 // Found @ 0xffff31c8
//   NEED_ENCODED_DISKBOOT = 1   // Found @ 0xffff31a8

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NSTUB(GetZoomLensCurrentPoint               ,0xff957774) //102        *** != 0xff957cbc
//NSTUB(GetZoomLensCurrentPosition            ,0xff9575f0) //102        *** != 0xff957cc0
//NSTUB(Lseek                                 ,0xff825e04) //101        *** != 0xff825ecc
//NSTUB(Read                                  ,0xff81a200) //101        *** != 0xff825d6c
//NSTUB(SetParameterData                      ,0xff972e4c) //  1 59%    *** != 0xff972ed4
// ERROR: UIFS_WriteFirmInfoToFile is not found.           //--- ---    *** != 0x00000000
//NSTUB(kbd_pwr_off                           ,0xff84db70) //  2 67%    *** != 0x00000000
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000
//NSTUB(rename                                ,0xff8254d8) //  1        *** != 0xff825d98
//NSTUB(srand                                 ,0xff81e760) //  1        *** != 0xff81bcec
//NSTUB(write                                 ,0xff825d70) //101        *** != 0xff81a260

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff87c0a4 -> ff878358 -> ff971a9c -> ffa45020 -> ffaefdf8
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00011abc) // Found @0xff8238c8
DEF(physw_run                               ,0x00001cd8) // Found @0xff8235a4
DEF(physw_sleep_delay                       ,0x00001cda) // Found @0xff8235a4
DEF(levent_table                            ,0xffac64ec) // Found @0xffac64ec
DEF(FlashParamsTable                        ,0xffaeff98) // Found @0xffaeff98
DEF(movie_status                            ,0x000058a0) // Found @0xff862b98
DEF(canon_menu_active                       ,0x00006e3c) // Found @0xff897014
DEF(canon_shoot_menu_active                 ,0x0000c05d) // Found @0xff982580
DEF(playrec_mode                            ,0x00005aa0) // Found @0xff869c54
DEF(zoom_status                             ,0x000068f8) // Found @0xff88635c
DEF(some_flag_for_af_scan                   ,0x0000ecbc) // Found @0xffa3e1f4
DEF(focus_busy                              ,0x0000b27c) // Found @0xff950718
//DEF(recreview_hold                          ,0x000067c4) // Found @0xff882a00, ** != ** stubs_min = 0x0000be2c (0xBE2C)

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x10361000; }             // Found @0xff849fec
//void *vid_get_viewport_fb()      { return (void*)0x10d29360; }             // Found @0xffa103d8
//char *camera_jpeg_count_str()    { return (char*)0x00058304; }             // Found @0xff9be548
//long hook_raw_size()             { return 0x009dcce0; }                    // Found @0xffa11ee0
//int get_flash_params_count(void) { return 0x6f; }                          // Found @0xff972f9c

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffa9cdc4, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00200000 // Found @0xffa9cde4, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_SHOOT_FULL      ,0x00000003 }, // Found @0xffa9ccbc, levent 0x01
//    { 0, KEY_SHOOT_FULL_ONLY ,0x00000002 }, // Found @0xffa9ccbc, levent 0x01
//    { 0, KEY_SHOOT_HALF      ,0x00000001 }, // Found @0xffa9ccb4, levent 0x00
//    { 0, KEY_PLAYBACK        ,0x00000004 }, // Found @0xffa9ccc4, levent 0x601 (uses inverted logic in physw_status)
//    { 1, KEY_LEFT            ,0x00001000 }, // Found @0xffa9cd34, levent 0x06
//    { 1, KEY_VIDEO           ,0x00002000 }, // Found @0xffa9cd3c, levent 0x12
//    { 1, KEY_SET             ,0x00010000 }, // Found @0xffa9cd4c, levent 0x08
//    { 1, KEY_DISPLAY         ,0x00020000 }, // Found @0xffa9cd54, levent 0x0a
//    { 1, KEY_MENU            ,0x00040000 }, // Found @0xffa9cd5c, levent 0x09
//    { 1, KEY_DOWN            ,0x00080000 }, // Found @0xffa9cd64, levent 0x05
//    { 1, KEY_UP              ,0x00100000 }, // Found @0xffa9cd6c, levent 0x04
//    { 1, KEY_RIGHT           ,0x00200000 }, // Found @0xffa9cd74, levent 0x07
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_RAW_ROWPIX    *** Not Found ***
//#define CAM_RAW_ROWS      *** Not Found ***
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x10000000 // Found @0xff82ad10

// Misc stuff
DEF(ctypes, 0xffa9635a)

// For capt_seq.c
//static long *nrflag = (long*)(0xb704);       // Found @ ff960ff4

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NSTUB(AllocateMemory                          ,0xffa410a8) //103
NSTUB(AllocateUncacheableMemory               ,0xff82acd4) //112
NSTUB(Close                                   ,0xff825cc4) //101
NSTUB(CreateTask                              ,0xff81b8fc) //101
NSTUB(DebugAssert                             ,0xff81bccc) //111
NSTUB(DeleteDirectory_Fut                     ,0xff825610) //  1
NSTUB(DeleteFile_Fut                          ,0xff82552c) //112
NSTUB(DoAFLock                                ,0xff827bc8) //103
NSTUB(EnterToCompensationEVF                  ,0xff827fa8) //104
NSTUB(ExecuteEventProcedure                   ,0xff81be9c) //  1
NSTUB(ExitFromCompensationEVF                 ,0xff82809c) //104
NSTUB(ExitTask                                ,0xff81bb8c) //101
NSTUB(ExpCtrlTool_StartContiAE                ,0xff838dd8) //104
NSTUB(ExpCtrlTool_StopContiAE                 ,0xff838e80) //104
NSTUB(Fclose_Fut                              ,0xff8256a8) //101
NSTUB(Feof_Fut                                ,0xff825894) //  1
NSTUB(Fflush_Fut                              ,0xff8258d0) //  1
NSTUB(Fgets_Fut                               ,0xff8257fc) //  1
NSTUB(Fopen_Fut                               ,0xff825668) //101
NSTUB(Fread_Fut                               ,0xff825754) //101
NSTUB(FreeMemory                              ,0xffa41094) //103
NSTUB(FreeUncacheableMemory                   ,0xff82ad08) //112
NSTUB(Fseek_Fut                               ,0xff825848) //101
NSTUB(Fwrite_Fut                              ,0xff8257a8) //101
NSTUB(GetBatteryTemperature                   ,0xff850564) //102
NSTUB(GetCCDTemperature                       ,0xff8504f4) //102
NSTUB(GetCurrentAvValue                       ,0xff952d94) //102
NSTUB(GetDrive_ClusterSize                    ,0xff856d08) //  1
NSTUB(GetDrive_FreeClusters                   ,0xff856da8) //  1
NSTUB(GetDrive_TotalClusters                  ,0xff856d3c) //  1
NSTUB(GetFocusLensSubjectDistance             ,0xff9511a4) //102
NSTUB(GetFocusLensSubjectDistanceFromLens     ,0xff9514a0) //  1
NSTUB(GetKbdState                             ,0xff84da24) //109
NSTUB(GetMemInfo                              ,0xff813ca8) //  1
NSTUB(GetOpticalTemperature                   ,0xff8505d4) //102
NSTUB(GetParameterData                        ,0xff972f60) //101
NSTUB(GetPropertyCase                         ,0xff87479c) //101
NSTUB(GetSystemTime                           ,0xffa411a4) //  1
NSTUB(GetVRAMHPixelsSize                      ,0xff841228) //102
NSTUB(GetVRAMVPixelsSize                      ,0xff841234) //102
NSTUB(GiveSemaphore                           ,0xff81b868) //112
NSTUB(IsStrobeChargeCompleted                 ,0xff8db534) //102
NSTUB(LocalTime                               ,0xff870604) //  1
NSTUB(LockMainPower                           ,0xff877d30) //103
NSTUB(MakeDirectory_Fut                       ,0xff8255a0) //  1
NSTUB(MoveFocusLensToDistance                 ,0xffa0d41c) //102
NSTUB(MoveIrisWithAv                          ,0xff9536f0) //102
NSTUB(MoveZoomLensWithPoint                   ,0xff957b34) //102
NSTUB(NewTaskShell                            ,0xff874268) //103
NSTUB(Open                                    ,0xff825c9c) //101
NSTUB(PB2Rec                                  ,0xff87b318) //104
NSTUB(PT_MoveDigitalZoomToWide                ,0xff86b964) //103
NSTUB(PT_MoveOpticalZoomAt                    ,0xff86b930) //103
NSTUB(PT_PlaySound                            ,0xff86b4dc) //103
NSTUB(PostLogicalEventForNotPowerType         ,0xff8760b4) //103
NSTUB(PostLogicalEventToUI                    ,0xff876100) //103
NSTUB(PutInNdFilter                           ,0xffa0bd00) //102
NSTUB(PutOutNdFilter                          ,0xffa0bd38) //102
NSTUB(ReadFastDir                             ,0xffa27900) //  1
NSTUB(Rec2PB                                  ,0xff87b358) //104
NSTUB(RefreshPhysicalScreen                   ,0xff8b2d90) //101
NSTUB(Remove                                  ,0xff825d0c) //  1
NSTUB(RenameFile_Fut                          ,0xff8254d8) //  1
NSTUB(Restart                                 ,0xff82cd1c) //106
NSTUB(SetAE_ShutterSpeed                      ,0xffa0f5b8) //102
NSTUB(SetAutoShutdownTime                     ,0xff877e90) //103
NSTUB(SetCurrentCaptureModeType               ,0xff87f884) //101
NSTUB(SetFileAttributes                       ,0xff825ff0) //  1
NSTUB(SetFileTimeStamp                        ,0xff825fa0) //  1
NSTUB(SetLogicalEventActive                   ,0xff877aec) //  1
NSTUB(SetPropertyCase                         ,0xff8746ac) //101
NSTUB(SetScriptMode                           ,0xff877b3c) //101
NSTUB(SleepTask                               ,0xff82ab58) //101
NSTUB(TakeSemaphore                           ,0xff81b798) //101
NSTUB(TurnOffBackLight                        ,0xff8883a0) //104
NSTUB(TurnOnBackLight                         ,0xff888388) //104
NSTUB(UnlockAF                                ,0xff827c34) //103
NSTUB(UnlockMainPower                         ,0xff877c8c) //103
NSTUB(UpdateMBROnFlash                        ,0xff856ad0) //105
NSTUB(VbattGet                                ,0xff822204) //101
NSTUB(Write                                   ,0xff825d70) //101
NSTUB(WriteSDCard                             ,0xff944124) //108
NSTUB(_log                                    ,0xffa93ecc) //111
NSTUB(_log10                                  ,0xffa92e10) //112
NSTUB(_pow                                    ,0xffa92f80) //114
NSTUB(_sqrt                                   ,0xffa95234) //  1
NSTUB(add_ptp_handler                         ,0xff8f03c4) //  1
NSTUB(apex2us                                 ,0xff9cae4c) //  4
NSTUB(close                                   ,0xff81a018) //  1
NSTUB(closedir                                ,0xffa279d0) //  1
NSTUB(err_init_task                           ,0xff814f00) //  4
NSTUB(exmem_alloc                             ,0xff871424) //101
NSTUB(free                                    ,0xff813b00) //112
NSTUB(kbd_p1_f                                ,0xff8239a4) //109
NSTUB(kbd_p1_f_cont                           ,0xff8239b0) //109
NSTUB(kbd_p2_f                                ,0xff823244) //109
NSTUB(kbd_read_keys                           ,0xff8238c8) //109
NSTUB(kbd_read_keys_r2                        ,0xff84d3e4) //109
NSTUB(lseek                                   ,0xff825e04) //101
NSTUB(malloc                                  ,0xff813a2c) //112
NSTUB(memcmp                                  ,0xff81e664) //101
NSTUB(memcpy                                  ,0xff8b3200) //101
NSTUB(memset                                  ,0xffa64b94) //101
NSTUB(mkdir                                   ,0xff826068) //  1
// ALT: NSTUB(mkdir, 0xff826108) // 1 32/0
NSTUB(mktime_ext                              ,0xff8b3a6c) //  1
NSTUB(open                                    ,0xff819f68) //  1
NSTUB(opendir                                 ,0xffa2786c) //  1
NSTUB(openfastdir                             ,0xffa2786c) //  1
NSTUB(qsort                                   ,0xff9ca224) //  1
NSTUB(rand                                    ,0xff81e76c) //  1
NSTUB(read                                    ,0xff81a200) //101
NSTUB(reboot_fw_update                        ,0xffa2f75c) //  1
NSTUB(set_control_event                       ,0xff8778c0) //  1
NSTUB(stat                                    ,0xff825ed0) //  1
NSTUB(strcat                                  ,0xff8b312c) //  1
NSTUB(strchr                                  ,0xff8b31b4) //  1
NSTUB(strcmp                                  ,0xff81e5fc) //101
NSTUB(strcpy                                  ,0xff81e5a8) //101
NSTUB(strftime                                ,0xff8b3474) //  1
NSTUB(strlen                                  ,0xff81e640) //101
NSTUB(strncmp                                 ,0xff8b3168) //  1
NSTUB(strncpy                                 ,0xff81e5c0) //  1
NSTUB(strrchr                                 ,0xff8b31d8) //  1
NSTUB(strtol                                  ,0xff831ce4) //101
NSTUB(strtolx                                 ,0xff831ae8) //109
  DEF(task_CaptSeq                            ,0xff866c80) //107
  DEF(task_ExpDrv                             ,0xff8d37c0) //110
  DEF(task_InitFileModules                    ,0xff87bf28) //107
  DEF(task_MovieRecord                        ,0xff862e48) //107
  DEF(task_PhySw                              ,0xff8235a0) //107
NSTUB(time                                    ,0xff870b08) //  2
NSTUB(vsprintf                                ,0xff81e528) //  1
