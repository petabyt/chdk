// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R50 (DRYOS version 2.3, release #0050)
//   Firmware Ver GM1.00D
//   Canon PowerShot A810

// Values for makefile.inc
//   PLATFORMOSVER = 50
//   PLATFORMID = 12863 (0x323f) // Found @ 0xfffe0040
//   MAXRAMADDR = 0x03ffffff
//   KEYSYS = d4c                // Found @ 0xffff1d4c
//   NEED_ENCODED_DISKBOOT = 8   // Found @ 0xffff1d5c

// Note, ROM copied to RAM :- from 0xffc012e0, to 0x003f1000, len 15733 words.

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NHSTUB(DeleteFile_Fut                       ,0xff82fa00) //  1 90%        == 0xff82fa00
//NHSTUB(GetBatteryTemperature                ,0xff85875c) //102        *** != 0x00000000
// ERROR: MakeDirectory_Fut is not found.                  //--- ---    *** != 0xff8305a4
//NHSTUB(kbd_pwr_off                          ,0xff856660) //  2 60%    *** != 0x00000000
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0x00000000
// ERROR: rand is not found.                               //--- ---    *** != 0x00000000
// ERROR: srand is not found.                              //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff886a0c -> ff883434 -> ff984624 -> ffa7f86c -> ffb9f9f8
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00030fd8) // Found @0xff82d96c
DEF(physw_run                               ,0x00001bf8) // Found @0xff82d51c
DEF(physw_sleep_delay                       ,0x00001c00) // Found @0xff82d51c
DEF(levent_table                            ,0xffb5b9ec) // Found @0xffb5b9ec
DEF(FlashParamsTable                        ,0xffb9fc54) // Found @0xffb9fc54
DEF(movie_status                            ,0x0000633c) // Found @0xff95a994
DEF(full_screen_refresh                     ,0x00008608) // Found @0xff9d2b30
DEF(canon_menu_active                       ,0x00002e2c) // Found @0xff87f32c
DEF(canon_shoot_menu_active                 ,0x0000778d) // Found @0xff99b500
DEF(playrec_mode                            ,0x00002b80) // Found @0xff8733d8
DEF(zoom_status                             ,0x0000b3c8) // Found @0xffa83004
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 64 entries in the table - set NUM_FL to 64
DEF(focus_len_table                         ,0xfffeabc8) // Found @0xfffeabc8
DEF(zoom_busy                               ,0x0000621c) // Found @0xff956358
DEF(focus_busy                              ,0x000060f4) // Found @0xff95342c
DEF(recreview_hold                          ,0x000033d8) // Found @0xff88cf34
DEF(palette_control                         ,0x00008608) // Found @0xff9d2aac
DEF(active_palette_buffer                   ,0x00008610) // Found @0xff9d2ab0
DEF(palette_buffer                          ,0x000b42c0) // Found @0xff9d2e54
DEF(viewport_buffers                        ,0xffb0fc40) // Found @0xff849058
DEF(active_viewport_buffer                  ,0x00002094) // Found @0xff848dc0

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40411000; }             // Found @0xff8521ac
//void *vid_get_viewport_fb()      { return (void*)0x40566b80; }             // Found @0xffade168
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2950+0x54)); } // Found @0xff867ad4 & 0xff867b0c
//char *camera_jpeg_count_str()    { return (char*)0x000b3b6c; }             // Found @0xff9c9264
//long hook_raw_size()             { return 0x01794300; }                    // Found @0xffae0f9c
//int get_flash_params_count(void) { return 0xa6; }                          // Found @0xff985670

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffb101a8, levent 0x20a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00040000 // Found @0xffb101b0, levent 0x202
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_ZOOM_OUT        ,0x00001000 }, // Found @0xffb10130, levent 0x03
//    { 0, KEY_ZOOM_IN         ,0x00002000 }, // Found @0xffb10138, levent 0x02
//    { 1, KEY_SHOOT_FULL      ,0x00300000 }, // Found @0xffb10148, levent 0x01
//    { 1, KEY_SHOOT_FULL_ONLY ,0x00200000 }, // Found @0xffb10148, levent 0x01
//    { 1, KEY_SHOOT_HALF      ,0x00100000 }, // Found @0xffb10140, levent 0x00
//    { 1, KEY_UP              ,0x00400000 }, // Found @0xffb10150, levent 0x04
//    { 1, KEY_DOWN            ,0x00800000 }, // Found @0xffb10158, levent 0x05
//    { 1, KEY_RIGHT           ,0x01000000 }, // Found @0xffb10160, levent 0x07
//    { 1, KEY_LEFT            ,0x02000000 }, // Found @0xffb10168, levent 0x06
//    { 1, KEY_MENU            ,0x04000000 }, // Found @0xffb10170, levent 0x09
//    { 1, KEY_SET             ,0x08000000 }, // Found @0xffb10178, levent 0x08
//    { 1, KEY_VIDEO           ,0x10000000 }, // Found @0xffb10180, levent 0x1a
//    { 1, KEY_HELP            ,0x20000000 }, // Found @0xffb10188, levent 0x14
//    { 1, KEY_POWER           ,0x40000000 }, // Found @0xffb10190, levent 0x100
//    { 1, KEY_PLAYBACK        ,0x80000000 }, // Found @0xffb10198, levent 0x101
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    4704 // Found @0xff92e000
//#define CAM_RAW_ROWS      3504 // Found @0xff92e00c
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff832e74

// Misc stuff
DEF(ctypes, 0xffb0f570)

// For capt_seq.c
//static long *nrflag = (long*)(0x8744+0x00);  // Found @ ff9df5e0 & ff9df61c
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
//NHSTUB(CreateJumptable                      ,0xffae1168) //  1
// ALT: NHSTUB(CreateJumptable, 0xffae25ac) // 1 32/0
//NHSTUB(_uartr_req                           ,0xff81a804) //111
//NHSTUB(AllocateMemory                       ,0xffa71bf0) //101
NHSTUB(AllocateUncacheableMemory              ,0xff832e2c) //112
NHSTUB(Close                                  ,0xff830074) //101
NHSTUB(CreateTask                             ,0x003f6824) //101
NHSTUB(DebugAssert                            ,0x003f6afc) //111
NHSTUB(DeleteDirectory_Fut                    ,0xff82fa74) //116
NHSTUB(DoAFLock                               ,0xff831a04) //102
NHSTUB(EnterToCompensationEVF                 ,0xff831c60) //104
NHSTUB(ExecuteEventProcedure                  ,0xff87a800) //104
NHSTUB(ExitFromCompensationEVF                ,0xff831ca4) //104
NHSTUB(ExitTask                               ,0x003f6ab4) //101
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff83ca58) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff83cbb4) //104
NHSTUB(Fclose_Fut                             ,0xff82fb0c) //101
NHSTUB(Feof_Fut                               ,0xff82fcf8) //  1
NHSTUB(Fflush_Fut                             ,0xff82fd34) //  1
NHSTUB(Fgets_Fut                              ,0xff82fc60) //  6
NHSTUB(Fopen_Fut                              ,0xff82facc) //101
NHSTUB(Fread_Fut                              ,0xff82fbb8) //101
//NHSTUB(FreeMemory                           ,0xffa71be8) //101
NHSTUB(FreeUncacheableMemory                  ,0xff832e6c) //112
NHSTUB(Fseek_Fut                              ,0xff82fcac) //101
NHSTUB(Fwrite_Fut                             ,0xff82fc0c) //101
NHSTUB(GetCCDTemperature                      ,0xff8586e8) //102
NHSTUB(GetCurrentAvValue                      ,0xff954f98) //102
NHSTUB(GetDrive_ClusterSize                   ,0xff86653c) //  6
NHSTUB(GetDrive_FreeClusters                  ,0xff866594) //  6
NHSTUB(GetDrive_TotalClusters                 ,0xff86656c) //  6
NHSTUB(GetFocusLensSubjectDistance            ,0xff9541f0) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff954640) //  3
NHSTUB(GetImageFolder                         ,0xff937580) //  6
NHSTUB(GetKbdState                            ,0xff856650) //109
NHSTUB(GetMemInfo                             ,0xff8150cc) //115
NHSTUB(GetOpticalTemperature                  ,0xff8587d4) //102
NHSTUB(GetParameterData                       ,0xff985630) //101
NHSTUB(GetPropertyCase                        ,0xff87e8cc) //102
NHSTUB(GetSystemTime                          ,0xffa71c6c) //101
NHSTUB(GetVRAMHPixelsSize                     ,0xff84b138) //102
NHSTUB(GetVRAMVPixelsSize                     ,0xff84b144) //102
NHSTUB(GetZoomLensCurrentPoint                ,0xff9567d8) //102
NHSTUB(GetZoomLensCurrentPosition             ,0xffa63890) //102
NHSTUB(GiveSemaphore                          ,0x003f7704) //112
NHSTUB(IsStrobeChargeCompleted                ,0xff8c9a9c) //102
NHSTUB(LEDDrive                               ,0xff95c24c) //101
NHSTUB(LocalTime                              ,0x003fb1b8) //115
NHSTUB(LockMainPower                          ,0xff883170) //103
//NHSTUB(Lseek                                ,0xff8302f0) //101
NHSTUB(MakeSDCardBootable                     ,0xff866814) //105
NHSTUB(MoveFocusLensToDistance                ,0xffada220) //102
NHSTUB(MoveIrisWithAv                         ,0xffa6db00) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xffa6e228) //102
//NHSTUB(NewTaskShell                         ,0xff87e24c) //101
NHSTUB(Open                                   ,0xff82ffac) //101
NHSTUB(PB2Rec                                 ,0xff885fe0) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff86c594) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff86c56c) //102
NHSTUB(PT_PlaySound                           ,0xff87503c) // 11
NHSTUB(PostLogicalEventForNotPowerType        ,0xff882864) //103
NHSTUB(PostLogicalEventToUI                   ,0xff8828b0) //103
NHSTUB(PutInNdFilter                          ,0xffa6e000) //102
NHSTUB(PutOutNdFilter                         ,0xffa6e024) //102
NHSTUB(Read                                   ,0xff815b88) //101
NHSTUB(ReadFastDir                            ,0xffa53cd4) //115
NHSTUB(Rec2PB                                 ,0xff886020) //104
NHSTUB(RefreshPhysicalScreen                  ,0xff894b14) //104
//NHSTUB(Remove                               ,0xff830248) //  6
NHSTUB(RenameFile_Fut                         ,0xff82f96c) //116
NHSTUB(Restart                                ,0xff83464c) //106
NHSTUB(ScreenLock                             ,0xff895b34) //  4
NHSTUB(ScreenUnlock                           ,0xff895b98) //  3
NHSTUB(SetAE_ShutterSpeed                     ,0xffadd340) //102
NHSTUB(SetAutoShutdownTime                    ,0xff8831e4) //103
NHSTUB(SetCurrentCaptureModeType              ,0xff88a1d0) //101
NHSTUB(SetFileAttributes                      ,0xff83050c) //  6
NHSTUB(SetFileTimeStamp                       ,0xff830494) //  6
NHSTUB(SetLogicalEventActive                  ,0xff882eec) //101
NHSTUB(SetParameterData                       ,0xff9855a0) //101
NHSTUB(SetPropertyCase                        ,0xff87e744) //102
NHSTUB(SetScriptMode                          ,0xff882f3c) //101
NHSTUB(SleepTask                              ,0x003f79b0) //101
NHSTUB(TakeSemaphore                          ,0x003f7634) //101
NHSTUB(TurnOffBackLight                       ,0xff88ff94) //104
NHSTUB(TurnOnBackLight                        ,0xff88ff7c) //104
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff977b74) //101
NHSTUB(UnlockAF                               ,0xff831a3c) //102
NHSTUB(UnlockMainPower                        ,0xff8830c4) //103
NHSTUB(UnsetZoomForMovie                      ,0xff98bdd8) //104
NHSTUB(VbattGet                               ,0xff82c274) //101
NHSTUB(Write                                  ,0xff8300c8) //101
NHSTUB(WriteSDCard                            ,0xff9473e8) //108
NHSTUB(_log                                   ,0x003fcce0) //111
NHSTUB(_log10                                 ,0x003fd220) //112
NHSTUB(_pow                                   ,0x003fd398) //114
NHSTUB(_sqrt                                  ,0x003fefbc) //  6
NHSTUB(add_ptp_handler                        ,0xffa172dc) //  6
NHSTUB(apex2us                                ,0xff9d8dec) //  4
NHSTUB(close                                  ,0xff8159e4) //  6
NHSTUB(closedir                               ,0xffa53b20) //  4
NHSTUB(err_init_task                          ,0xff81437c) //111
NHSTUB(exmem_alloc                            ,0xff8791d4) //101
NHSTUB(exmem_free                             ,0xff87924c) //101
NHSTUB(free                                   ,0xff812f78) //112
NHSTUB(kbd_p1_f                               ,0xff82d9bc) //109
NHSTUB(kbd_p1_f_cont                          ,0xff82d9c8) //109
NHSTUB(kbd_p2_f                               ,0xff82d1b4) //109
NHSTUB(kbd_read_keys                          ,0xff82d96c) //109
NHSTUB(kbd_read_keys_r2                       ,0xff85616c) //109
NHSTUB(lseek                                  ,0xff8302f0) //101
NHSTUB(malloc                                 ,0xff812f20) //112
NHSTUB(memcmp                                 ,0xff81ae58) //101
NHSTUB(memcpy                                 ,0xff835da4) //101
NHSTUB(memset                                 ,0xff9d713c) //101
NHSTUB(mkdir                                  ,0xff8305a4) // 12
NHSTUB(mktime_ext                             ,0xff896064) //  1
NHSTUB(open                                   ,0xff815934) //  6
NHSTUB(OpenFastDir                            ,0xffa53b70) //115
NHSTUB(qsort                                  ,0xff9d70dc) //  6
//NHSTUB(read                                 ,0xff815b88) //101
NHSTUB(realloc                                ,0xff9d71b8) //115
NHSTUB(reboot_fw_update                       ,0xffa5919c) //106
NHSTUB(set_control_event                      ,0xff882bac) //111
NHSTUB(stat                                   ,0xff830338) //109
NHSTUB(strcat                                 ,0xff8966e4) //  1
NHSTUB(strchr                                 ,0xff812dec) //  1
NHSTUB(strcmp                                 ,0xff81af54) //101
NHSTUB(strcpy                                 ,0xff81ae40) //101
NHSTUB(strftime                               ,0xff8960b0) //113
NHSTUB(strlen                                 ,0xff812e38) //101
NHSTUB(strncmp                                ,0xff812da0) //  1
NHSTUB(strncpy                                ,0xff812d64) //  1
NHSTUB(strrchr                                ,0xff812e10) //  1
NHSTUB(strtol                                 ,0xff835d90) //101
NHSTUB(strtolx                                ,0xff835b94) //109
   DEF(task_CaptSeq                           ,0xff86eca8) //110
   DEF(task_ExpDrv                            ,0xff8ae838) //110
   DEF(task_InitFileModules                   ,0xff88688c) //110
   DEF(task_MovieRecord                       ,0xff95b4f8) //110
   DEF(task_PhySw                             ,0xff82d518) //110
NHSTUB(time                                   ,0x003fb794) //  6
NHSTUB(vsprintf                               ,0xff81acf0) //115
//NHSTUB(write                                ,0xff8300c8) //101
//NHSTUB(EngDrvIn                             ,0xff82e7f4) //102
//NHSTUB(EngDrvOut                            ,0xff82e7dc) //102
//NHSTUB(EngDrvRead                           ,0xff82e7fc) //102
//NHSTUB(EngDrvBits                           ,0xff82e810) //102
//NHSTUB(GetSDProtect                         ,0xff82d928) //101
//NHSTUB(StartRecModeMenu                     ,0xff87f328) //102
//NHSTUB(DispCon_ShowBitmapColorBar           ,0xff85217c) //102
//NHSTUB(ResetZoomLens                        ,0xffa6e17c) //102
//NHSTUB(ResetFocusLens                       ,0xffa6cd04) //102
//NHSTUB(NR_GetDarkSubType                    ,0xff9df6a0) //102
//NHSTUB(NR_SetDarkSubType                    ,0xff9df5d8) //102
//NHSTUB(SavePaletteData                      ,0xff95ecc8) //102
//NHSTUB(GUISrv_StartGUISystem                ,0xff8943c8) //101
