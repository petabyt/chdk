// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R23 (DRYOS version 2.3, release #0023)
//   Firmware Ver GM1.00C
//   Possible corrupt firmware dump - file size to small for start address 0xff810000
//     file size = 4.00MB, should be 7.94MB
//   Could not find Camera name - possible corrupt firmware dump

// Values for makefile.inc
//   PLATFORMOSVER = 23
//   MAXRAMADDR = 0x03ffffff

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NSTUB(PutInNdFilter                         ,0xffa299b4) //102        *** != 0xffa82748
//NSTUB(PutOutNdFilter                        ,0xffa299d8) //102        *** != 0xffa82780

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff879344 -> ff875af0 -> ff95c5ac -> ffa3dc5c -> ffaf7e70
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00010610) // Found @0xff821e48
DEF(physw_run                               ,0x00001c00) // Found @0xff821ae0
DEF(physw_sleep_delay                       ,0x00001bfe) // Found @0xff821ae0
DEF(levent_table                            ,0xffad2ce8) // Found @0xffad2ce8
DEF(FlashParamsTable                        ,0xffaf8034) // Found @0xffaf8034
DEF(movie_status                            ,0x000053cc) // Found @0xff859fec
DEF(canon_menu_active                       ,0x000099e8) // Found @0xff94fe8c
DEF(canon_shoot_menu_active                 ,0x00009fcd) // Found @0xff96c438
DEF(playrec_mode                            ,0x0000555c) // Found @0xff8613c4
DEF(zoom_status                             ,0x0000d474) // Found @0xffa3f45c
DEF(some_flag_for_af_scan                   ,0x0000d1f8) // Found @0xffa2a32c
DEF(zoom_busy                               ,0x00008a88) // Found @0xff932810
DEF(focus_busy                              ,0x00008994) // Found @0xff92e3bc
//DEF(recreview_hold                          ,0x000061a4) // Found @0xff87ee14, ** != ** stubs_min = 0x00009da4 (0x9CF8+0xAC)

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x10361000; }             // Found @0xff83e9ac
//void *vid_get_viewport_fb()      { return (void*)0x1065adc0; }             // Found @0xffa87980
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x51fc+0x50)); } // Found @0xff8532b8 & 0xff8532f0
//char *camera_jpeg_count_str()    { return (char*)0x0004c97c; }             // Found @0xff9a66f4
//long hook_raw_size()             { return 0x00ec04f0; }                    // Found @0xffa89c04
//int get_flash_params_count(void) { return 0x73; }                          // Found @0xff95d668

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffab0784, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00040000 // Found @0xffab0790, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 1, KEY_POWER           ,0x40000000 }, // Found @0xffab06c4, levent 0x600
//    { 1, KEY_PLAYBACK        ,0x80000000 }, // Found @0xffab06d0, levent 0x601
//    { 2, KEY_SHOOT_FULL      ,0x00000003 }, // Found @0xffab06e8, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000002 }, // Found @0xffab06e8, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000001 }, // Found @0xffab06dc, levent 0x00
//    { 2, KEY_ZOOM_IN         ,0x00000004 }, // Found @0xffab06f4, levent 0x02
//    { 2, KEY_ZOOM_OUT        ,0x00000008 }, // Found @0xffab0700, levent 0x03
//    { 2, KEY_LEFT            ,0x00000010 }, // Found @0xffab070c, levent 0x06
//    { 2, KEY_RIGHT           ,0x00000020 }, // Found @0xffab0718, levent 0x07
//    { 2, KEY_DOWN            ,0x00000040 }, // Found @0xffab0724, levent 0x05
//    { 2, KEY_UP              ,0x00000080 }, // Found @0xffab0730, levent 0x04
//    { 2, KEY_SET             ,0x00000100 }, // Found @0xffab073c, levent 0x08
//    { 2, KEY_DISPLAY         ,0x00000200 }, // Found @0xffab0748, levent 0x0a
//    { 2, KEY_MENU            ,0x00000400 }, // Found @0xffab0754, levent 0x09
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_RAW_ROWPIX    3720 // Found @0xffa812b0
//#define CAM_RAW_ROWS      2772 // Found @0xffa812b8
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x10000000 // Found @0xff8285b8

// Misc stuff
DEF(ctypes, 0xffab025e)

// For capt_seq.c
//static long *nrflag = (long*)(0x91ac);       // Found @ ff93d88c

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NSTUB(AllocateMemory                          ,0xffa2d1c4) //101
NSTUB(AllocateUncacheableMemory               ,0xff82857c) //112
NSTUB(Close                                   ,0xff823da0) //101
NSTUB(CreateTask                              ,0xff81b818) //101
NSTUB(DebugAssert                             ,0xff81bcf0) //111
NSTUB(DeleteDirectory_Fut                     ,0xff823730) //116
NSTUB(DeleteFile_Fut                          ,0xff82364c) //112
NSTUB(DoAFLock                                ,0xff825b98) //102
NSTUB(EnterToCompensationEVF                  ,0xff825e94) //104
NSTUB(ExecuteEventProcedure                   ,0xff86965c) //104
NSTUB(ExitFromCompensationEVF                 ,0xff825ee4) //104
NSTUB(ExitTask                                ,0xff81baa8) //101
NSTUB(ExpCtrlTool_StartContiAE                ,0xff832b14) //104
NSTUB(ExpCtrlTool_StopContiAE                 ,0xff832c58) //104
NSTUB(Fclose_Fut                              ,0xff8237c8) //101
NSTUB(Feof_Fut                                ,0xff8239b4) //  1
NSTUB(Fflush_Fut                              ,0xff8239f0) //  1
NSTUB(Fgets_Fut                               ,0xff82391c) //  1
NSTUB(Fopen_Fut                               ,0xff823788) //101
NSTUB(Fread_Fut                               ,0xff823874) //101
NSTUB(FreeMemory                              ,0xffa2d1bc) //101
NSTUB(FreeUncacheableMemory                   ,0xff8285b0) //112
NSTUB(Fseek_Fut                               ,0xff823968) //101
NSTUB(Fwrite_Fut                              ,0xff8238c8) //101
NSTUB(GetBatteryTemperature                   ,0xff8455e0) //102
NSTUB(GetCCDTemperature                       ,0xff845570) //102
NSTUB(GetCurrentAvValue                       ,0xff92fdd0) //102
NSTUB(GetDrive_ClusterSize                    ,0xff84f500) //  1
NSTUB(GetDrive_FreeClusters                   ,0xff84f568) //  1
NSTUB(GetDrive_TotalClusters                  ,0xff84f534) //  1
NSTUB(GetFocusLensSubjectDistance             ,0xff92eec8) //102
NSTUB(GetFocusLensSubjectDistanceFromLens     ,0xff92f1d4) //  1
NSTUB(GetKbdState                             ,0xff842b28) //109
NSTUB(GetMemInfo                              ,0xff813c40) //115
NSTUB(GetOpticalTemperature                   ,0xff845650) //102
NSTUB(GetParameterData                        ,0xff95d628) //101
NSTUB(GetPropertyCase                         ,0xff86d25c) //102
NSTUB(GetSystemTime                           ,0xffa2d21c) //101
NSTUB(GetVRAMHPixelsSize                      ,0xff8c8aec) //102
NSTUB(GetVRAMVPixelsSize                      ,0xff8c8af8) //102
NSTUB(GetZoomLensCurrentPoint                 ,0xff932b74) //102
NSTUB(GetZoomLensCurrentPosition              ,0xffa2326c) //102
NSTUB(GiveSemaphore                           ,0xff81b77c) //112
NSTUB(IsStrobeChargeCompleted                 ,0xff8bdc20) //102
NSTUB(LEDDrive                                ,0xff8422b8) //103
NSTUB(LocalTime                               ,0xff866d20) //115
NSTUB(LockMainPower                           ,0xff875708) //103
NSTUB(Lseek                                   ,0xff823ee0) //101
NSTUB(MakeDirectory_Fut                       ,0xff8236c0) //116
NSTUB(MoveFocusLensToDistance                 ,0xffa844bc) //102
NSTUB(MoveIrisWithAv                          ,0xffa295cc) //102
NSTUB(MoveZoomLensWithPoint                   ,0xffa29b50) //102
NSTUB(NewTaskShell                            ,0xff86cd20) //103
NSTUB(Open                                    ,0xff823d78) //101
NSTUB(PB2Rec                                  ,0xff87871c) //104
NSTUB(PT_MoveDigitalZoomToWide                ,0xff85be58) //102
NSTUB(PT_MoveOpticalZoomAt                    ,0xff85be30) //102
NSTUB(PT_PlaySound                            ,0xff85b4b4) //102
NSTUB(PostLogicalEventForNotPowerType         ,0xff8734c8) //103
NSTUB(PostLogicalEventToUI                    ,0xff873514) //103
NSTUB(Read                                    ,0xff81a094) //101
NSTUB(ReadFastDir                             ,0xffa122ec) //  1
NSTUB(Rec2PB                                  ,0xff877120) //104
NSTUB(RefreshPhysicalScreen                   ,0xff9b0484) //104
NSTUB(Remove                                  ,0xff823de8) //  1
NSTUB(RenameFile_Fut                          ,0xff8235f8) //  1
NSTUB(Restart                                 ,0xff829df4) //106
NSTUB(SetAE_ShutterSpeed                      ,0xffa86b90) //102
NSTUB(SetAutoShutdownTime                     ,0xff87577c) //103
NSTUB(SetCurrentCaptureModeType               ,0xff87c5b8) //101
NSTUB(SetFileAttributes                       ,0xff8240cc) //  1
NSTUB(SetFileTimeStamp                        ,0xff82407c) //  1
NSTUB(SetLogicalEventActive                   ,0xff8753e8) //  1
NSTUB(SetParameterData                        ,0xff95d598) //101
NSTUB(SetPropertyCase                         ,0xff86d15c) //102
NSTUB(SetScriptMode                           ,0xff875438) //101
NSTUB(SleepTask                               ,0xff828400) //101
NSTUB(TakeSemaphore                           ,0xff81b6ac) //101
NSTUB(TurnOffBackLight                        ,0xff881e30) //104
NSTUB(TurnOnBackLight                         ,0xff881e18) //104
NSTUB(UIFS_WriteFirmInfoToFile                ,0xff950de8) //103
NSTUB(UnlockAF                                ,0xff825bdc) //102
NSTUB(UnlockMainPower                         ,0xff87565c) //103
NSTUB(UnsetZoomForMovie                       ,0xff962c8c) //104
NSTUB(UpdateMBROnFlash                        ,0xff84f340) //105
NSTUB(VbattGet                                ,0xff82072c) //103
NSTUB(Write                                   ,0xff823e4c) //101
NSTUB(WriteSDCard                             ,0xff922a68) //108
NSTUB(_log                                    ,0xffaadd18) //111
NSTUB(_log10                                  ,0xffaacc5c) //112
NSTUB(_pow                                    ,0xffaacdcc) //114
NSTUB(_sqrt                                   ,0xffaaf138) //  1
NSTUB(add_ptp_handler                         ,0xff9e0928) //  1
NSTUB(apex2us                                 ,0xff9b19c0) //  4
NSTUB(close                                   ,0xff819eac) //  1
NSTUB(closedir                                ,0xffa123bc) //  1
NSTUB(err_init_task                           ,0xff814e98) //111
NSTUB(exmem_alloc                             ,0xff867e44) //103
NSTUB(free                                    ,0xff813a98) //112
NSTUB(kbd_p1_f                                ,0xff821f4c) //109
NSTUB(kbd_p1_f_cont                           ,0xff821f58) //109
NSTUB(kbd_p2_f                                ,0xff821780) //109
NSTUB(kbd_read_keys                           ,0xff821e48) //109
NSTUB(kbd_read_keys_r2                        ,0xff8426e0) //109
NSTUB(kbd_pwr_off                             ,0xff842bac) //  2
NSTUB(kbd_pwr_on                              ,0xff842b5c) //  2
NSTUB(lseek                                   ,0xff823ee0) //101
NSTUB(malloc                                  ,0xff8139c4) //112
NSTUB(memcmp                                  ,0xff81d854) //101
NSTUB(memcpy                                  ,0xff894584) //101
NSTUB(memset                                  ,0xff9b0838) //101
NSTUB(mkdir                                   ,0xff824144) //109
NSTUB(mktime_ext                              ,0xff894df0) //  1
NSTUB(open                                    ,0xff819dfc) //  1
NSTUB(OpenFastDir                             ,0xffa12258) //  1
NSTUB(qsort                                   ,0xff9b0d40) //  1
NSTUB(rand                                    ,0xff81d95c) //  1
NSTUB(read                                    ,0xff81a094) //101
NSTUB(reboot_fw_update                        ,0xffa19cec) //106
NSTUB(set_control_event                       ,0xff875064) //  1
NSTUB(srand                                   ,0xff81d950) //  1
NSTUB(stat                                    ,0xff823fac) //  1
NSTUB(strcat                                  ,0xff894370) //  1
NSTUB(strchr                                  ,0xff8943f8) //  1
NSTUB(strcmp                                  ,0xff81d7ec) //101
NSTUB(strcpy                                  ,0xff81d7d4) //101
NSTUB(strftime                                ,0xff8947f8) //  1
NSTUB(strlen                                  ,0xff81d830) //101
NSTUB(strncmp                                 ,0xff8943ac) //  1
NSTUB(strncpy                                 ,0xff82e210) //  1
NSTUB(strrchr                                 ,0xff89441c) //  1
NSTUB(strtol                                  ,0xff82e448) //101
NSTUB(strtolx                                 ,0xff82e24c) //109
  DEF(task_CaptSeq                            ,0xff85e2b0) //107
  DEF(task_ExpDrv                             ,0xff8b6a80) //110
  DEF(task_InitFileModules                    ,0xff8791d0) //107
  DEF(task_MovieRecord                        ,0xff85a278) //107
  DEF(task_PhySw                              ,0xff821adc) //107
NSTUB(time                                    ,0xff867224) //109
NSTUB(vsprintf                                ,0xff81d754) //115
NSTUB(write                                   ,0xff823e4c) //101
