// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R50 (DRYOS version 2.3, release #0050)
//   Firmware Ver GM1.01A
//   Canon PowerShot A3400 IS

// Values for makefile.inc
//   PLATFORMOSVER = 50
//   PLATFORMID = 12872 (0x3248) // Found @ 0xfffe0040
//   MAXRAMADDR = 0x03ffffff
//   KEYSYS = d4c                // Found @ 0xffff1d28
//   NEED_ENCODED_DISKBOOT = 8   // Found @ 0xffff1d38

// Note, ROM copied to RAM :- from 0xffc241c8, to 0x003f1000, len 15765 words.

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NSTUB(DeleteFile_Fut                        ,0xff830e64) //  1 90%        == 0xff830e64
// ERROR: MakeDirectory_Fut is not found.                  //--- ---    *** != 0xff831974
//NSTUB(kbd_pwr_off                           ,0xff8569b0) //  2 60%    *** != 0x00000000
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000
// ERROR: rand is not found.                               //--- ---    *** != 0x00000000
// ERROR: srand is not found.                              //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff88a7e8 -> ff887370 -> ff98e560 -> ffa97628 -> ffbc05c8
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00031ba0) // Found @0xff82edd0
DEF(physw_run                               ,0x00001c18) // Found @0xff82e980
DEF(physw_sleep_delay                       ,0x00001c20) // Found @0xff82e980
DEF(levent_table                            ,0xffb7afcc) // Found @0xffb7afcc
DEF(FlashParamsTable                        ,0xffbc0820) // Found @0xffbc0820
DEF(movie_status                            ,0x00006524) // Found @0xff962704
DEF(full_screen_refresh                     ,0x00008a28) // Found @0xff9ea698
DEF(canon_menu_active                       ,0x00002f10) // Found @0xff882dc0
DEF(canon_shoot_menu_active                 ,0x000079f1) // Found @0xff9a6af8
DEF(playrec_mode                            ,0x00002c60) // Found @0xff876cd8
DEF(zoom_status                             ,0x0000bb7c) // Found @0xffa9add0
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 64 entries in the table - set NUM_FL to 64
DEF(focus_len_table                         ,0xfffeabc8) // Found @0xfffeabc8
DEF(zoom_busy                               ,0x000063b0) // Found @0xff95cc84
DEF(focus_busy                              ,0x0000621c) // Found @0xff9580c0
DEF(recreview_hold                          ,0x000034d0) // Found @0xff890ce0
DEF(palette_control                         ,0x00008a28) // Found @0xff9ea614
DEF(active_palette_buffer                   ,0x00008a30) // Found @0xff9ea618
DEF(palette_buffer                          ,0x000b38f0) // Found @0xff9ea9bc

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40411000; }             // Found @0xff852d54
//void *vid_get_viewport_fb()      { return (void*)0x40566b80; }             // Found @0xffaf9ee8
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x29a0+0x54)); } // Found @0xff868904 & 0xff86893c
//char *camera_jpeg_count_str()    { return (char*)0x000b3004; }             // Found @0xff9dddec
//long hook_raw_size()             { return 0x01794300; }                    // Found @0xffafcd1c
//int get_flash_params_count(void) { return 0xa6; }                          // Found @0xff98f5ac

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffb2fdd4, levent 0x20a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00040000 // Found @0xffb2fddc, levent 0x202
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_ZOOM_OUT        ,0x00001000 }, // Found @0xffb2fd5c, levent 0x03
//    { 0, KEY_ZOOM_IN         ,0x00002000 }, // Found @0xffb2fd64, levent 0x02
//    { 1, KEY_SHOOT_FULL      ,0x00300000 }, // Found @0xffb2fd74, levent 0x01
//    { 1, KEY_SHOOT_FULL_ONLY ,0x00200000 }, // Found @0xffb2fd74, levent 0x01
//    { 1, KEY_SHOOT_HALF      ,0x00100000 }, // Found @0xffb2fd6c, levent 0x00
//    { 1, KEY_UP              ,0x00400000 }, // Found @0xffb2fd7c, levent 0x04
//    { 1, KEY_DOWN            ,0x00800000 }, // Found @0xffb2fd84, levent 0x05
//    { 1, KEY_RIGHT           ,0x01000000 }, // Found @0xffb2fd8c, levent 0x07
//    { 1, KEY_LEFT            ,0x02000000 }, // Found @0xffb2fd94, levent 0x06
//    { 1, KEY_MENU            ,0x04000000 }, // Found @0xffb2fd9c, levent 0x09
//    { 1, KEY_SET             ,0x08000000 }, // Found @0xffb2fda4, levent 0x08
//    { 1, KEY_VIDEO           ,0x10000000 }, // Found @0xffb2fdac, levent 0x1a
//    { 1, KEY_HELP            ,0x20000000 }, // Found @0xffb2fdb4, levent 0x14
//    { 1, KEY_POWER           ,0x40000000 }, // Found @0xffb2fdbc, levent 0x100
//    { 1, KEY_PLAYBACK        ,0x80000000 }, // Found @0xffb2fdc4, levent 0x101
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    4704 // Found @0xff932e60
//#define CAM_RAW_ROWS      3504 // Found @0xff932e6c
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff8342d0

// Misc stuff
DEF(ctypes, 0xffb2f15c)

// For capt_seq.c
//static long *nrflag = (long*)(0x8b64+0x00);  // Found @ ff9f7100 & ff9f7148
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NSTUB(AllocateMemory                          ,0xffa89d5c) //101
NSTUB(AllocateUncacheableMemory               ,0xff834288) //112
NSTUB(Close                                   ,0xff8314d8) //101
NSTUB(CreateTask                              ,0x003f6824) //101
NSTUB(DebugAssert                             ,0x003f6afc) //111
NSTUB(DeleteDirectory_Fut                     ,0xff830ed8) //116
NSTUB(DoAFLock                                ,0xff832d74) //102
NSTUB(EnterToCompensationEVF                  ,0xff832f90) //104
NSTUB(ExecuteEventProcedure                   ,0xff87e2e8) //104
NSTUB(ExitFromCompensationEVF                 ,0xff832fd4) //104
NSTUB(ExitTask                                ,0x003f6ab4) //101
NSTUB(ExpCtrlTool_StartContiAE                ,0xff83d718) //104
NSTUB(ExpCtrlTool_StopContiAE                 ,0xff83d874) //104
NSTUB(Fclose_Fut                              ,0xff830f70) //101
NSTUB(Feof_Fut                                ,0xff83115c) //  1
NSTUB(Fflush_Fut                              ,0xff831198) //  1
NSTUB(Fgets_Fut                               ,0xff8310c4) //  6
NSTUB(Fopen_Fut                               ,0xff830f30) //101
NSTUB(Fread_Fut                               ,0xff83101c) //101
NSTUB(FreeMemory                              ,0xffa89d54) //101
NSTUB(FreeUncacheableMemory                   ,0xff8342c8) //112
NSTUB(Fseek_Fut                               ,0xff831110) //101
NSTUB(Fwrite_Fut                              ,0xff831070) //101
NSTUB(GetBatteryTemperature                   ,0xff858994) //102
NSTUB(GetCCDTemperature                       ,0xff858920) //102
NSTUB(GetCurrentAvValue                       ,0xff959c84) //102
NSTUB(GetDrive_ClusterSize                    ,0xff867094) //  6
NSTUB(GetDrive_FreeClusters                   ,0xff8670ec) //  6
NSTUB(GetDrive_TotalClusters                  ,0xff8670c4) //  6
NSTUB(GetFocusLensSubjectDistance             ,0xff958e84) //102
NSTUB(GetFocusLensSubjectDistanceFromLens     ,0xff9592d4) //  3
NSTUB(GetImageFolder                          ,0xff93c3e0) //  6
NSTUB(GetKbdState                             ,0xff8569a0) //109
NSTUB(GetMemInfo                              ,0xff81509c) //115
NSTUB(GetOpticalTemperature                   ,0xff858a08) //102
NSTUB(GetParameterData                        ,0xff98f56c) //101
NSTUB(GetPropertyCase                         ,0xff882360) //102
NSTUB(GetSystemTime                           ,0xffa89db4) //101
NSTUB(GetVRAMHPixelsSize                      ,0xff84bce0) //102
NSTUB(GetVRAMVPixelsSize                      ,0xff84bcec) //102
NSTUB(GetZoomLensCurrentPoint                 ,0xff95d104) //102
NSTUB(GetZoomLensCurrentPosition              ,0xffa7ad40) //102
NSTUB(GiveSemaphore                           ,0x003f7704) //112
NSTUB(IsStrobeChargeCompleted                 ,0xff8cca9c) //102
NSTUB(LEDDrive                                ,0xff964050) //101
NSTUB(LocalTime                               ,0x003fb1b8) //115
NSTUB(LockMainPower                           ,0xff8870ac) //103
NSTUB(Lseek                                   ,0xff8316f4) //101
NSTUB(MakeSDCardBootable                      ,0xff867324) //105
NSTUB(MoveFocusLensToDistance                 ,0xffaf5fa0) //102
NSTUB(MoveIrisWithAv                          ,0xffa851ec) //102
NSTUB(MoveZoomLensWithPoint                   ,0xffa85920) //102
NSTUB(NewTaskShell                            ,0xff881ce0) //101
NSTUB(Open                                    ,0xff831410) //101
NSTUB(PB2Rec                                  ,0xff889df4) //104
NSTUB(PT_MoveDigitalZoomToWide                ,0xff86fbfc) //102
NSTUB(PT_MoveOpticalZoomAt                    ,0xff86fbd4) //102
//NSTUB(PT_PlaySound                          ,0xff878b24) // 11            == 0xff878b24
NSTUB(PostLogicalEventForNotPowerType         ,0xff886760) //103
NSTUB(PostLogicalEventToUI                    ,0xff8867ac) //103
NSTUB(PutInNdFilter                           ,0xffa856f8) //102
NSTUB(PutOutNdFilter                          ,0xffa8571c) //102
NSTUB(Read                                    ,0xff815b58) //101
NSTUB(ReadFastDir                             ,0xffa6a478) //115
NSTUB(Rec2PB                                  ,0xff889e34) //104
NSTUB(RefreshPhysicalScreen                   ,0xff898d00) //104
NSTUB(Remove                                  ,0xff83164c) //  6
NSTUB(RenameFile_Fut                          ,0xff830dd0) //116
NSTUB(Restart                                 ,0xff835a9c) //106
NSTUB(ScreenLock                              ,0xff899d20) //  4
NSTUB(ScreenUnlock                            ,0xff899d84) //  3
NSTUB(SetAE_ShutterSpeed                      ,0xffaf90c0) //102
NSTUB(SetAutoShutdownTime                     ,0xff887120) //103
NSTUB(SetCurrentCaptureModeType               ,0xff88e13c) //101
NSTUB(SetFileAttributes                       ,0xff8318dc) //  6
NSTUB(SetFileTimeStamp                        ,0xff831864) //  6
NSTUB(SetLogicalEventActive                   ,0xff886e28) //101
NSTUB(SetParameterData                        ,0xff98f4dc) //101
NSTUB(SetPropertyCase                         ,0xff8821d8) //102
NSTUB(SetScriptMode                           ,0xff886e78) //101
NSTUB(SleepTask                               ,0x003f79b0) //101
NSTUB(TakeSemaphore                           ,0x003f7634) //101
NSTUB(TurnOffBackLight                        ,0xff893d3c) //104
NSTUB(TurnOnBackLight                         ,0xff893d24) //104
NSTUB(UIFS_WriteFirmInfoToFile                ,0xff9800a0) //101
NSTUB(UnlockAF                                ,0xff832dac) //102
NSTUB(UnlockMainPower                         ,0xff887000) //103
NSTUB(UnsetZoomForMovie                       ,0xff995d98) //104
NSTUB(VbattGet                                ,0xff82c3cc) //101
NSTUB(Write                                   ,0xff83152c) //101
NSTUB(WriteSDCard                             ,0xff94c144) //108
NSTUB(_log                                    ,0x003fcce0) //111
NSTUB(_log10                                  ,0x003fd220) //112
NSTUB(_pow                                    ,0x003fd398) //114
NSTUB(_sqrt                                   ,0x003ff038) //  6
NSTUB(add_ptp_handler                         ,0xffa2cf44) //  6
NSTUB(apex2us                                 ,0xff9f0a14) //  4
NSTUB(close                                   ,0xff8159b4) //  6
NSTUB(closedir                                ,0xffa6a2d4) //  4
NSTUB(err_init_task                           ,0xff81437c) //111
NSTUB(exmem_alloc                             ,0xff87ccbc) //101
NSTUB(free                                    ,0xff812f78) //112
NSTUB(kbd_p1_f                                ,0xff82ee20) //109
NSTUB(kbd_p1_f_cont                           ,0xff82ee2c) //109
NSTUB(kbd_p2_f                                ,0xff82e618) //109
NSTUB(kbd_read_keys                           ,0xff82edd0) //109
NSTUB(kbd_read_keys_r2                        ,0xff8564b0) //109
NSTUB(lseek                                   ,0xff8316f4) //101
NSTUB(malloc                                  ,0xff812f20) //112
NSTUB(memcmp                                  ,0xff81ae30) //101
NSTUB(memcpy                                  ,0xff83720c) //101
NSTUB(memset                                  ,0xff9eeca4) //101
NSTUB(mkdir                                   ,0xff831974) //  6
NSTUB(mktime_ext                              ,0xff89a250) //  1
NSTUB(open                                    ,0xff815904) //  6
NSTUB(OpenFastDir                             ,0xffa6a324) //115
NSTUB(qsort                                   ,0xff9eec44) //  6
NSTUB(read                                    ,0xff815b58) //101
//NSTUB(reboot_fw_update                      ,0xffa6f854) //106            == 0xffa6f854
NSTUB(set_control_event                       ,0xff886ad4) //  6
NSTUB(stat                                    ,0xff83173c) //109
NSTUB(strcat                                  ,0xff89a8d0) //  1
NSTUB(strchr                                  ,0xff812dec) //  1
NSTUB(strcmp                                  ,0xff81af2c) //101
NSTUB(strcpy                                  ,0xff81ae18) //101
NSTUB(strftime                                ,0xff89a29c) //113
NSTUB(strlen                                  ,0xff812e38) //101
NSTUB(strncmp                                 ,0xff812da0) //  1
NSTUB(strncpy                                 ,0xff812d64) //  1
NSTUB(strrchr                                 ,0xff812e10) //  1
NSTUB(strtol                                  ,0xff8371f8) //101
NSTUB(strtolx                                 ,0xff836ffc) //109
  DEF(task_CaptSeq                            ,0xff872424) //110
  DEF(task_ExpDrv                             ,0xff8b1a4c) //110
  DEF(task_InitFileModules                    ,0xff88a668) //110
  DEF(task_MovieRecord                        ,0xff963268) //110
  DEF(task_PhySw                              ,0xff82e97c) //110
NSTUB(time                                    ,0x003fb794) //  6
NSTUB(vsprintf                                ,0xff81acc8) //115
NSTUB(write                                   ,0xff83152c) //101
