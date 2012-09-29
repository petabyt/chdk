// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R50 (DRYOS version 2.3, release #0050)
//   Firmware Ver GM1.00B
//   Canon PowerShot A810

// Values for makefile.inc
//   PLATFORMOSVER = 50
//   PLATFORMID = 12863 (0x323f) // Found @ 0xfffe0040
//   MAXRAMADDR = 0x03ffffff
//   KEYSYS = d4c                // Found @ 0xffff1d4c
//   NEED_ENCODED_DISKBOOT = 8   // Found @ 0xffff1d5c

// Note, ROM copied to RAM :- from 0xffc011a8, to 0x003f1000, len 15733 words.

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NSTUB(DeleteFile_Fut                        ,0xff82fa00) //  1 90%        == 0xff82fa00
//NSTUB(GetBatteryTemperature                 ,0xff85875c) //102        *** != 0x00000000
// ERROR: MakeDirectory_Fut is not found.                  //--- ---    *** != 0xff8305a4
//NSTUB(PT_PlaySound                          ,0xff87503c) //  4 93%        == 0xff87503c
//NSTUB(Remove                                ,0xff830254) //  6 60%    *** != 0xff830248
//NSTUB(kbd_pwr_off                           ,0xff856660) //  2 60%    *** != 0x00000000
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000
//NSTUB(mkdir                                 ,0xff83064c) //  6 60%    *** != 0xff8305a4
// ERROR: rand is not found.                               //--- ---    *** != 0x00000000
//NSTUB(reboot_fw_update                      ,0xffa59070) //  6 64%    *** != 0xffa5906c
// ERROR: srand is not found.                              //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff886900 -> ff883434 -> ff984518 -> ffa7f73c -> ffb9f8c8
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00030fb8) // Found @0xff82d96c
DEF(physw_run                               ,0x00001bf8) // Found @0xff82d51c
DEF(physw_sleep_delay                       ,0x00001c00) // Found @0xff82d51c
DEF(levent_table                            ,0xffb5b8bc) // Found @0xffb5b8bc
DEF(FlashParamsTable                        ,0xffb9fb24) // Found @0xffb9fb24
DEF(movie_status                            ,0x0000633c) // Found @0xff95a888
DEF(full_screen_refresh                     ,0x00008600) // Found @0xff9d2a00
DEF(canon_menu_active                       ,0x00002e2c) // Found @0xff87f32c
DEF(canon_shoot_menu_active                 ,0x00007789) // Found @0xff99b3d0
DEF(playrec_mode                            ,0x00002b80) // Found @0xff8733d8
DEF(zoom_status                             ,0x0000b3c0) // Found @0xffa82ed4
DEF(some_flag_for_af_scan                   ,0xffb724d0) // Found @0xff9db1d0
DEF(some_flag_for_af_scan                   ,0xffb724d0) // Found @0xff9ddee8
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 64 entries in the table - set NUM_FL to 64
DEF(focus_len_table                         ,0xfffeabc8) // Found @0xfffeabc8
DEF(zoom_busy                               ,0x0000621c) // Found @0xff95624c
DEF(focus_busy                              ,0x000060f4) // Found @0xff953320
DEF(recreview_hold                          ,0x000033d8) // Found @0xff88ce28
DEF(palette_control                         ,0x00008600) // Found @0xff9d297c
DEF(active_palette_buffer                   ,0x00008608) // Found @0xff9d2980
DEF(palette_buffer                          ,0x000b3ec0) // Found @0xff9d2d24

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40411000; }             // Found @0xff8521ac
//void *vid_get_viewport_fb()      { return (void*)0x40566b80; }             // Found @0xffade038
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2950+0x54)); } // Found @0xff867ad4 & 0xff867b0c
//char *camera_jpeg_count_str()    { return (char*)0x000b376c; }             // Found @0xff9c9134
//long hook_raw_size()             { return 0x01794300; }                    // Found @0xffae0e6c
//int get_flash_params_count(void) { return 0xa6; }                          // Found @0xff985564

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffb10078, levent 0x20a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00040000 // Found @0xffb10080, levent 0x202
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_ZOOM_OUT        ,0x00001000 }, // Found @0xffb10000, levent 0x03
//    { 0, KEY_ZOOM_IN         ,0x00002000 }, // Found @0xffb10008, levent 0x02
//    { 1, KEY_SHOOT_FULL      ,0x00300000 }, // Found @0xffb10018, levent 0x01
//    { 1, KEY_SHOOT_FULL_ONLY ,0x00200000 }, // Found @0xffb10018, levent 0x01
//    { 1, KEY_SHOOT_HALF      ,0x00100000 }, // Found @0xffb10010, levent 0x00
//    { 1, KEY_UP              ,0x00400000 }, // Found @0xffb10020, levent 0x04
//    { 1, KEY_DOWN            ,0x00800000 }, // Found @0xffb10028, levent 0x05
//    { 1, KEY_RIGHT           ,0x01000000 }, // Found @0xffb10030, levent 0x07
//    { 1, KEY_LEFT            ,0x02000000 }, // Found @0xffb10038, levent 0x06
//    { 1, KEY_MENU            ,0x04000000 }, // Found @0xffb10040, levent 0x09
//    { 1, KEY_SET             ,0x08000000 }, // Found @0xffb10048, levent 0x08
//    { 1, KEY_POWER           ,0x40000000 }, // Found @0xffb10060, levent 0x100
//    { 1, KEY_PLAYBACK        ,0x80000000 }, // Found @0xffb10068, levent 0x101
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    4704 // Found @0xff92def4
//#define CAM_RAW_ROWS      3504 // Found @0xff92df00
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff832e74

// Misc stuff
DEF(ctypes, 0xffb0f440)

// For capt_seq.c
//static long *nrflag = (long*)(0x873c+0x00);  // Found @ ff9df3a8 & ff9df408
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NSTUB(AllocateMemory                          ,0xffa71ac0) //101
NSTUB(AllocateUncacheableMemory               ,0xff832e2c) //112
NSTUB(Close                                   ,0xff830074) //101
NSTUB(CreateTask                              ,0x003f6824) //105
NSTUB(DebugAssert                             ,0x003f6afc) //111
NSTUB(DeleteDirectory_Fut                     ,0xff82fa74) //  1
NSTUB(DoAFLock                                ,0xff831a04) //102
NSTUB(EnterToCompensationEVF                  ,0xff831c60) //104
NSTUB(ExecuteEventProcedure                   ,0xff87a800) //  2
NSTUB(ExitFromCompensationEVF                 ,0xff831ca4) //104
NSTUB(ExitTask                                ,0x003f6ab4) //105
NSTUB(ExpCtrlTool_StartContiAE                ,0xff83ca58) //104
NSTUB(ExpCtrlTool_StopContiAE                 ,0xff83cbb4) //104
NSTUB(Fclose_Fut                              ,0xff82fb0c) //101
NSTUB(Feof_Fut                                ,0xff82fcf8) //  1
NSTUB(Fflush_Fut                              ,0xff82fd34) //  1
NSTUB(Fgets_Fut                               ,0xff82fc60) //  6
NSTUB(Fopen_Fut                               ,0xff82facc) //101
NSTUB(Fread_Fut                               ,0xff82fbb8) //101
NSTUB(FreeMemory                              ,0xffa71ab8) //101
NSTUB(FreeUncacheableMemory                   ,0xff832e6c) //112
NSTUB(Fseek_Fut                               ,0xff82fcac) //101
NSTUB(Fwrite_Fut                              ,0xff82fc0c) //101
NSTUB(GetCCDTemperature                       ,0xff8586e8) //102
NSTUB(GetCurrentAvValue                       ,0xff954e8c) //102
NSTUB(GetDrive_ClusterSize                    ,0xff86653c) //  6
NSTUB(GetDrive_FreeClusters                   ,0xff866594) //  6
NSTUB(GetDrive_TotalClusters                  ,0xff86656c) //  6
NSTUB(GetFocusLensSubjectDistance             ,0xff9540e4) //102
NSTUB(GetFocusLensSubjectDistanceFromLens     ,0xff954534) //  3
NSTUB(GetImageFolder                          ,0xff937474) //  6
NSTUB(GetKbdState                             ,0xff856650) //109
NSTUB(GetMemInfo                              ,0xff8150cc) //  3
NSTUB(GetOpticalTemperature                   ,0xff8587d4) //102
NSTUB(GetParameterData                        ,0xff985524) //101
NSTUB(GetPropertyCase                         ,0xff87e8cc) //102
NSTUB(GetSystemTime                           ,0xffa71b3c) //101
NSTUB(GetVRAMHPixelsSize                      ,0xff84b138) //102
NSTUB(GetVRAMVPixelsSize                      ,0xff84b144) //102
NSTUB(GetZoomLensCurrentPoint                 ,0xff9566cc) //102
NSTUB(GetZoomLensCurrentPosition              ,0xffa63760) //102
NSTUB(GiveSemaphore                           ,0x003f7704) //112
NSTUB(IsStrobeChargeCompleted                 ,0xff8c9990) //102
NSTUB(LEDDrive                                ,0xff95c140) //101
NSTUB(LocalTime                               ,0x003fb1b8) //  6
NSTUB(LockMainPower                           ,0xff883170) //103
NSTUB(Lseek                                   ,0xff8302f0) //101
NSTUB(MakeSDCardBootable                      ,0xff866814) //105
NSTUB(MoveFocusLensToDistance                 ,0xffada0f0) //102
NSTUB(MoveIrisWithAv                          ,0xffa6d9d0) //102
NSTUB(MoveZoomLensWithPoint                   ,0xffa6e0f8) //102
NSTUB(NewTaskShell                            ,0xff87e24c) //101
NSTUB(Open                                    ,0xff82ffac) //101
NSTUB(PB2Rec                                  ,0xff885ed4) //104
NSTUB(PT_MoveDigitalZoomToWide                ,0xff86c594) //102
NSTUB(PT_MoveOpticalZoomAt                    ,0xff86c56c) //102
NSTUB(PostLogicalEventForNotPowerType         ,0xff882864) //103
NSTUB(PostLogicalEventToUI                    ,0xff8828b0) //103
NSTUB(PutInNdFilter                           ,0xffa6ded0) //102
NSTUB(PutOutNdFilter                          ,0xffa6def4) //102
NSTUB(Read                                    ,0xff815b88) //101
NSTUB(ReadFastDir                             ,0xffa53ba4) //  6
NSTUB(Rec2PB                                  ,0xff885f14) //104
NSTUB(RefreshPhysicalScreen                   ,0xff894a08) //104
NSTUB(RenameFile_Fut                          ,0xff82f96c) //  6
NSTUB(Restart                                 ,0xff83464c) //106
NSTUB(ScreenLock                              ,0xff895a28) //  4
NSTUB(ScreenUnlock                            ,0xff895a8c) //  3
NSTUB(SetAE_ShutterSpeed                      ,0xffadd210) //102
NSTUB(SetAutoShutdownTime                     ,0xff8831e4) //103
NSTUB(SetCurrentCaptureModeType               ,0xff88a0c4) //101
NSTUB(SetFileAttributes                       ,0xff83050c) //  6
NSTUB(SetFileTimeStamp                        ,0xff830494) //  6
NSTUB(SetLogicalEventActive                   ,0xff882eec) //101
NSTUB(SetParameterData                        ,0xff985494) //101
NSTUB(SetPropertyCase                         ,0xff87e744) //102
NSTUB(SetScriptMode                           ,0xff882f3c) //101
NSTUB(SleepTask                               ,0x003f79b0) //105
NSTUB(TakeSemaphore                           ,0x003f7634) //112
NSTUB(TurnOffBackLight                        ,0xff88fe88) //104
NSTUB(TurnOnBackLight                         ,0xff88fe70) //104
NSTUB(UIFS_WriteFirmInfoToFile                ,0xff977a68) //101
NSTUB(UnlockAF                                ,0xff831a3c) //102
NSTUB(UnlockMainPower                         ,0xff8830c4) //103
NSTUB(UnsetZoomForMovie                       ,0xff98bccc) //104
NSTUB(VbattGet                                ,0xff82c274) //101
NSTUB(Write                                   ,0xff8300c8) //101
NSTUB(WriteSDCard                             ,0xff9472dc) //108
NSTUB(_log                                    ,0x003fcce0) //111
NSTUB(_log10                                  ,0x003fd220) //112
NSTUB(_pow                                    ,0x003fd398) //114
NSTUB(_sqrt                                   ,0x003fefbc) //  6
NSTUB(add_ptp_handler                         ,0xffa171ac) //  6
NSTUB(apex2us                                 ,0xff9d8cbc) //  4
NSTUB(close                                   ,0xff8159e4) //  6
NSTUB(closedir                                ,0xffa539f0) //  4
NSTUB(err_init_task                           ,0xff81437c) //  4
NSTUB(exmem_alloc                             ,0xff8791d4) //101
NSTUB(free                                    ,0xff812f78) //112
NSTUB(kbd_p1_f                                ,0xff82d9bc) //109
NSTUB(kbd_p1_f_cont                           ,0xff82d9c8) //109
NSTUB(kbd_p2_f                                ,0xff82d1b4) //109
NSTUB(kbd_read_keys                           ,0xff82d96c) //109
NSTUB(kbd_read_keys_r2                        ,0xff85616c) //109
NSTUB(lseek                                   ,0xff8302f0) //101
NSTUB(malloc                                  ,0xff812f20) //112
NSTUB(memcmp                                  ,0xff81ae58) //101
NSTUB(memcpy                                  ,0xff835da4) //101
NSTUB(memset                                  ,0xff9d700c) //101
NSTUB(mktime_ext                              ,0xff895f58) //  1
NSTUB(open                                    ,0xff815934) //  6
NSTUB(opendir                                 ,0xffa53a40) //  6
NSTUB(openfastdir                             ,0xffa53a40) //  6
NSTUB(qsort                                   ,0xff9d6fac) //  6
NSTUB(read                                    ,0xff815b88) //101
NSTUB(rename                                  ,0xff82f96c) //  6
NSTUB(set_control_event                       ,0xff882bac) //111
NSTUB(stat                                    ,0xff830338) //  3
NSTUB(strcat                                  ,0xff8965d8) //  1
NSTUB(strchr                                  ,0xff812dec) //  1
NSTUB(strcmp                                  ,0xff81af54) //101
NSTUB(strcpy                                  ,0xff81ae40) //101
NSTUB(strftime                                ,0xff895fa4) //113
NSTUB(strlen                                  ,0xff812e38) //101
NSTUB(strncmp                                 ,0xff812da0) //  1
NSTUB(strncpy                                 ,0xff812d64) //  1
NSTUB(strrchr                                 ,0xff812e10) //  1
NSTUB(strtol                                  ,0xff835d90) //101
NSTUB(strtolx                                 ,0xff835b94) //109
  DEF(task_CaptSeq                            ,0xff86eca8) //110
  DEF(task_ExpDrv                             ,0xff8ae72c) //110
  DEF(task_InitFileModules                    ,0xff886780) //110
  DEF(task_MovieRecord                        ,0xff95b3ec) //110
  DEF(task_PhySw                              ,0xff82d518) //110
NSTUB(time                                    ,0x003fb794) //  6
NSTUB(vsprintf                                ,0xff81acf0) //  6
NSTUB(write                                   ,0xff8300c8) //101
