// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R23 (DRYOS version 2.3, release #0023)
//   Firmware Ver GM1.00D
//   Possible corrupt firmware dump - file size to small for start address 0xff810000
//     file size = 3.10MB, should be 7.94MB
//   Could not find Camera name - possible corrupt firmware dump

// Values for makefile.inc
//   PLATFORMOSVER = 23
//   MAXRAMADDR = 0x03ffffff

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NHSTUB(PutInNdFilter                        ,0xffa299b0) //102        *** != 0xffa82744
//NHSTUB(PutOutNdFilter                       ,0xffa299d4) //102        *** != 0xffa8277c

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff879344 -> ff875af0 -> ff95c5ac -> ffa3dc58 -> ffaf7e70
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00010610) // Found @0xff821e48
DEF(physw_run                               ,0x00001c00) // Found @0xff821ae0
DEF(physw_sleep_delay                       ,0x00001bfe) // Found @0xff821ae0
DEF(levent_table                            ,0xffad2ce4) // Found @0xffad2ce4
DEF(FlashParamsTable                        ,0xffaf8034) // Found @0xffaf8034
DEF(movie_status                            ,0x000053cc) // Found @0xff859fec
DEF(canon_menu_active                       ,0x000099e8) // Found @0xff94fe8c
DEF(canon_shoot_menu_active                 ,0x00009fcd) // Found @0xff96c438
DEF(playrec_mode                            ,0x0000555c) // Found @0xff8613c4
DEF(zoom_status                             ,0x0000d474) // Found @0xffa3f458
DEF(some_flag_for_af_scan                   ,0x0000d1f8) // Found @0xffa2a328
DEF(zoom_busy                               ,0x00008a88) // Found @0xff932810
DEF(focus_busy                              ,0x00008994) // Found @0xff92e3bc
//DEF(recreview_hold                          ,0x000061a4) // Found @0xff87ee14, ** != ** stubs_min = 0x00009da4 (0x9CF8+0xAC)

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x10361000; }             // Found @0xff83e9ac
//void *vid_get_viewport_fb()      { return (void*)0x1065adc0; }             // Found @0xffa8797c
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x51fc+0x50)); } // Found @0xff8532b8 & 0xff8532f0
//char *camera_jpeg_count_str()    { return (char*)0x0004c97c; }             // Found @0xff9a66f4
//long hook_raw_size()             { return 0x00ec04f0; }                    // Found @0xffa89c00
//int get_flash_params_count(void) { return 0x73; }                          // Found @0xff95d668

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffab0780, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00040000 // Found @0xffab078c, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 1, KEY_POWER           ,0x40000000 }, // Found @0xffab06c0, levent 0x600
//    { 1, KEY_PLAYBACK        ,0x80000000 }, // Found @0xffab06cc, levent 0x601
//    { 2, KEY_SHOOT_FULL      ,0x00000003 }, // Found @0xffab06e4, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000002 }, // Found @0xffab06e4, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000001 }, // Found @0xffab06d8, levent 0x00
//    { 2, KEY_ZOOM_IN         ,0x00000004 }, // Found @0xffab06f0, levent 0x02
//    { 2, KEY_ZOOM_OUT        ,0x00000008 }, // Found @0xffab06fc, levent 0x03
//    { 2, KEY_LEFT            ,0x00000010 }, // Found @0xffab0708, levent 0x06
//    { 2, KEY_RIGHT           ,0x00000020 }, // Found @0xffab0714, levent 0x07
//    { 2, KEY_DOWN            ,0x00000040 }, // Found @0xffab0720, levent 0x05
//    { 2, KEY_UP              ,0x00000080 }, // Found @0xffab072c, levent 0x04
//    { 2, KEY_SET             ,0x00000100 }, // Found @0xffab0738, levent 0x08
//    { 2, KEY_DISPLAY         ,0x00000200 }, // Found @0xffab0744, levent 0x0a
//    { 2, KEY_MENU            ,0x00000400 }, // Found @0xffab0750, levent 0x09
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_RAW_ROWPIX    3720 // Found @0xffa812ac
//#define CAM_RAW_ROWS      2772 // Found @0xffa812b4
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x10000000 // Found @0xff8285b8

// Misc stuff
DEF(ctypes, 0xffab025a)

// For capt_seq.c
//static long *nrflag = (long*)(0x91ac);       // Found @ ff93d88c

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
//NHSTUB(CreateJumptable                      ,0xffa8a288) //  1
//NHSTUB(_uartr_req                           ,0xff81cdb0) //111
//NHSTUB(AllocateMemory                       ,0xffa2d1c0) //101
NHSTUB(AllocateUncacheableMemory              ,0xff82857c) //112
NHSTUB(Close                                  ,0xff823da0) //101
NHSTUB(CreateTask                             ,0xff81b818) //101
NHSTUB(DebugAssert                            ,0xff81bcf0) //111
NHSTUB(DeleteDirectory_Fut                    ,0xff823730) //116
NHSTUB(DeleteFile_Fut                         ,0xff82364c) //112
NHSTUB(DoAFLock                               ,0xff825b98) //102
NHSTUB(EnterToCompensationEVF                 ,0xff825e94) //104
NHSTUB(ExecuteEventProcedure                  ,0xff86965c) //104
NHSTUB(ExitFromCompensationEVF                ,0xff825ee4) //104
NHSTUB(ExitTask                               ,0xff81baa8) //101
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff832b14) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff832c58) //104
NHSTUB(Fclose_Fut                             ,0xff8237c8) //101
NHSTUB(Feof_Fut                               ,0xff8239b4) //  1
NHSTUB(Fflush_Fut                             ,0xff8239f0) //  1
NHSTUB(Fgets_Fut                              ,0xff82391c) //  1
NHSTUB(Fopen_Fut                              ,0xff823788) //101
NHSTUB(Fread_Fut                              ,0xff823874) //101
//NHSTUB(FreeMemory                           ,0xffa2d1b8) //101
NHSTUB(FreeUncacheableMemory                  ,0xff8285b0) //112
NHSTUB(Fseek_Fut                              ,0xff823968) //101
NHSTUB(Fwrite_Fut                             ,0xff8238c8) //101
NHSTUB(GetBatteryTemperature                  ,0xff8455e0) //102
NHSTUB(GetCCDTemperature                      ,0xff845570) //102
NHSTUB(GetCurrentAvValue                      ,0xff92fdd0) //102
NHSTUB(GetDrive_ClusterSize                   ,0xff84f500) //  1
NHSTUB(GetDrive_FreeClusters                  ,0xff84f568) //  1
NHSTUB(GetDrive_TotalClusters                 ,0xff84f534) //  1
NHSTUB(GetFocusLensSubjectDistance            ,0xff92eec8) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff92f1d4) //  1
NHSTUB(GetKbdState                            ,0xff842b28) //109
NHSTUB(GetMemInfo                             ,0xff813c40) //115
NHSTUB(GetOpticalTemperature                  ,0xff845650) //102
NHSTUB(GetParameterData                       ,0xff95d628) //101
NHSTUB(GetPropertyCase                        ,0xff86d25c) //102
NHSTUB(GetSystemTime                          ,0xffa2d218) //101
NHSTUB(GetVRAMHPixelsSize                     ,0xff8c8aec) //102
NHSTUB(GetVRAMVPixelsSize                     ,0xff8c8af8) //102
NHSTUB(GetZoomLensCurrentPoint                ,0xff932b74) //102
NHSTUB(GetZoomLensCurrentPosition             ,0xffa23268) //102
NHSTUB(GiveSemaphore                          ,0xff81b77c) //112
NHSTUB(IsStrobeChargeCompleted                ,0xff8bdc20) //102
NHSTUB(LEDDrive                               ,0xff8422b8) //103
NHSTUB(LocalTime                              ,0xff866d20) //115
NHSTUB(LockMainPower                          ,0xff875708) //103
//NHSTUB(Lseek                                ,0xff823ee0) //101
NHSTUB(MakeDirectory_Fut                      ,0xff8236c0) //116
NHSTUB(MoveFocusLensToDistance                ,0xffa844b8) //102
NHSTUB(MoveIrisWithAv                         ,0xffa295c8) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xffa29b4c) //102
//NHSTUB(NewTaskShell                         ,0xff86cd20) //103
NHSTUB(Open                                   ,0xff823d78) //101
NHSTUB(PB2Rec                                 ,0xff87871c) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff85be58) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff85be30) //102
NHSTUB(PT_PlaySound                           ,0xff85b4b4) //102
NHSTUB(PostLogicalEventForNotPowerType        ,0xff8734c8) //103
NHSTUB(PostLogicalEventToUI                   ,0xff873514) //103
NHSTUB(Read                                   ,0xff81a094) //101
NHSTUB(ReadFastDir                            ,0xffa122e8) //  1
NHSTUB(Rec2PB                                 ,0xff877120) //104
NHSTUB(RefreshPhysicalScreen                  ,0xff9b0484) //104
//NHSTUB(Remove                               ,0xff823de8) //  1
NHSTUB(RenameFile_Fut                         ,0xff8235f8) //  1
NHSTUB(Restart                                ,0xff829df4) //106
NHSTUB(SetAE_ShutterSpeed                     ,0xffa86b8c) //102
NHSTUB(SetAutoShutdownTime                    ,0xff87577c) //103
NHSTUB(SetCurrentCaptureModeType              ,0xff87c5b8) //101
NHSTUB(SetFileAttributes                      ,0xff8240cc) //  1
NHSTUB(SetFileTimeStamp                       ,0xff82407c) //  1
NHSTUB(SetLogicalEventActive                  ,0xff8753e8) //  1
NHSTUB(SetParameterData                       ,0xff95d598) //101
NHSTUB(SetPropertyCase                        ,0xff86d15c) //102
NHSTUB(SetScriptMode                          ,0xff875438) //101
NHSTUB(SleepTask                              ,0xff828400) //101
NHSTUB(TakeSemaphore                          ,0xff81b6ac) //101
NHSTUB(TurnOffBackLight                       ,0xff881e30) //104
NHSTUB(TurnOnBackLight                        ,0xff881e18) //104
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff950de8) //103
NHSTUB(UnlockAF                               ,0xff825bdc) //102
NHSTUB(UnlockMainPower                        ,0xff87565c) //103
NHSTUB(UnsetZoomForMovie                      ,0xff962c8c) //104
NHSTUB(UpdateMBROnFlash                       ,0xff84f340) //105
NHSTUB(VbattGet                               ,0xff82072c) //103
NHSTUB(Write                                  ,0xff823e4c) //101
NHSTUB(WriteSDCard                            ,0xff922a68) //108
NHSTUB(_log                                   ,0xffaadd14) //111
NHSTUB(_log10                                 ,0xffaacc58) //112
NHSTUB(_pow                                   ,0xffaacdc8) //114
NHSTUB(_sqrt                                  ,0xffaaf134) //  1
NHSTUB(add_ptp_handler                        ,0xff9e0924) //  1
NHSTUB(apex2us                                ,0xff9b19c0) //  4
NHSTUB(close                                  ,0xff819eac) //  1
NHSTUB(closedir                               ,0xffa123b8) //  1
NHSTUB(err_init_task                          ,0xff814e98) //111
NHSTUB(exmem_alloc                            ,0xff867e44) //103
NHSTUB(exmem_free                             ,0xff867ebc) //103
NHSTUB(free                                   ,0xff813a98) //112
NHSTUB(kbd_p1_f                               ,0xff821f4c) //109
NHSTUB(kbd_p1_f_cont                          ,0xff821f58) //109
NHSTUB(kbd_p2_f                               ,0xff821780) //109
NHSTUB(kbd_read_keys                          ,0xff821e48) //109
NHSTUB(kbd_read_keys_r2                       ,0xff8426e0) //109
NHSTUB(kbd_pwr_off                            ,0xff842bac) //  2
NHSTUB(kbd_pwr_on                             ,0xff842b5c) //  2
NHSTUB(lseek                                  ,0xff823ee0) //101
NHSTUB(malloc                                 ,0xff8139c4) //112
NHSTUB(memcmp                                 ,0xff81d854) //101
NHSTUB(memcpy                                 ,0xff894584) //101
NHSTUB(memset                                 ,0xff9b0838) //101
NHSTUB(mkdir                                  ,0xff824144) //109
NHSTUB(mktime_ext                             ,0xff894df0) //  1
NHSTUB(open                                   ,0xff819dfc) //  1
NHSTUB(OpenFastDir                            ,0xffa12254) //  1
NHSTUB(qsort                                  ,0xff9b0d40) //  1
NHSTUB(rand                                   ,0xff81d95c) //  1
//NHSTUB(read                                 ,0xff81a094) //101
NHSTUB(realloc                                ,0xff813b78) //115
NHSTUB(reboot_fw_update                       ,0xffa19ce8) //106
NHSTUB(set_control_event                      ,0xff875064) //  1
NHSTUB(srand                                  ,0xff81d950) //  1
NHSTUB(stat                                   ,0xff823fac) //  1
NHSTUB(strcat                                 ,0xff894370) //  1
NHSTUB(strchr                                 ,0xff8943f8) //  1
NHSTUB(strcmp                                 ,0xff81d7ec) //101
NHSTUB(strcpy                                 ,0xff81d7d4) //101
NHSTUB(strftime                               ,0xff8947f8) //  1
NHSTUB(strlen                                 ,0xff81d830) //101
NHSTUB(strncmp                                ,0xff8943ac) //  1
NHSTUB(strncpy                                ,0xff82e210) //  1
NHSTUB(strrchr                                ,0xff89441c) //  1
NHSTUB(strtol                                 ,0xff82e448) //101
NHSTUB(strtolx                                ,0xff82e24c) //109
   DEF(task_CaptSeq                           ,0xff85e2b0) //107
   DEF(task_ExpDrv                            ,0xff8b6a80) //110
   DEF(task_InitFileModules                   ,0xff8791d0) //107
   DEF(task_MovieRecord                       ,0xff85a278) //107
   DEF(task_PhySw                             ,0xff821adc) //107
NHSTUB(time                                   ,0xff867224) //109
NHSTUB(vsprintf                               ,0xff81d754) //115
//NHSTUB(write                                ,0xff823e4c) //101
//NHSTUB(EngDrvIn                             ,0xff822d84) //102
//NHSTUB(EngDrvOut                            ,0xff822d6c) //102
//NHSTUB(EngDrvRead                           ,0xff822d8c) //102
//NHSTUB(EngDrvBits                           ,0xff822da0) //102
//NHSTUB(GetSDProtect                         ,0xff821e28) //103
//NHSTUB(StartRecModeMenu                     ,0xff94fe88) //102            == 0xff94fe88
//NHSTUB(DispCon_ShowBitmapColorBar           ,0xff83e978) //102
//NHSTUB(ResetZoomLens                        ,0xffa29aa0) //102
//NHSTUB(ResetFocusLens                       ,0xffa28aa8) //102
//NHSTUB(NR_GetDarkSubType                    ,0xff93ea60) //102
//NHSTUB(NR_SetDarkSubType                    ,0xff93e9ec) //102
//NHSTUB(SavePaletteData                      ,0xffa88be8) //102
