// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R23 (DRYOS version 2.3, release #0023)
//   Firmware Ver GM1.00F
//   Canon PowerShot SD890 IS

// Values for makefile.inc
//   PLATFORMOSVER = 23
//   PLATFORMID = 12659 (0x3173) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x03ffffff
//   KEYSYS = d3enc              // Found @ 0xffff33e0
//   NEED_ENCODED_DISKBOOT = 1   // Found @ 0xffff33c0

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NHSTUB(PutInNdFilter                        ,0xffa2ab90) //102        *** != 0xffa83868
//NHSTUB(PutOutNdFilter                       ,0xffa2abb4) //102        *** != 0xffa8389c

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff87907c -> ff875820 -> ff95c828 -> ffa3ee38 -> ffaf9518
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00010650) // Found @0xff821e38
DEF(physw_run                               ,0x00001c00) // Found @0xff821ad0
DEF(physw_sleep_delay                       ,0x00001bfe) // Found @0xff821ad0
DEF(levent_table                            ,0xffad4084) // Found @0xffad4084
DEF(FlashParamsTable                        ,0xffaf96d8) // Found @0xffaf96d8
DEF(movie_status                            ,0x000053cc) // Found @0xff859cfc
DEF(canon_menu_active                       ,0x000099e0) // Found @0xff950108
DEF(canon_shoot_menu_active                 ,0x00009fd9) // Found @0xff96cce0
DEF(playrec_mode                            ,0x0000555c) // Found @0xff8610f4
DEF(zoom_status                             ,0x0000d4a4) // Found @0xffa40638
DEF(some_flag_for_af_scan                   ,0x0000d228) // Found @0xffa2b508
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 12 entries in the table - set NUM_FL to 12
DEF(focus_len_table                         ,0xfffe297c) // Found @0xfffe297c
DEF(zoom_busy                               ,0x00008aa0) // Found @0xff932a0c
DEF(focus_busy                              ,0x0000898c) // Found @0xff92e0b8
//DEF(recreview_hold                          ,0x00006188) // Found @0xff87eb14, ** != ** stubs_min = 0x00009d98 (0x9CEC+0xAC)

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x10361000; }             // Found @0xff83e89c
//void *vid_get_viewport_fb()      { return (void*)0x1065adc0; }             // Found @0xffa88a6c
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x51fc+0x50)); } // Found @0xff853074 & 0xff8530ac
//char *camera_jpeg_count_str()    { return (char*)0x0004ca80; }             // Found @0xff9a6f4c
//long hook_raw_size()             { return 0x00ec04f0; }                    // Found @0xffa8acf0
//int get_flash_params_count(void) { return 0x73; }                          // Found @0xff95d8e4

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffab16e8, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00040000 // Found @0xffab16f4, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 1, KEY_POWER           ,0x40000000 }, // Found @0xffab1628, levent 0x600
//    { 1, KEY_PLAYBACK        ,0x80000000 }, // Found @0xffab1634, levent 0x601
//    { 2, KEY_SHOOT_FULL      ,0x00000003 }, // Found @0xffab164c, levent 0x01
//    { 2, KEY_SHOOT_FULL_ONLY ,0x00000002 }, // Found @0xffab164c, levent 0x01
//    { 2, KEY_SHOOT_HALF      ,0x00000001 }, // Found @0xffab1640, levent 0x00
//    { 2, KEY_ZOOM_IN         ,0x00000004 }, // Found @0xffab1658, levent 0x02
//    { 2, KEY_ZOOM_OUT        ,0x00000008 }, // Found @0xffab1664, levent 0x03
//    { 2, KEY_LEFT            ,0x00000010 }, // Found @0xffab1670, levent 0x06
//    { 2, KEY_RIGHT           ,0x00000020 }, // Found @0xffab167c, levent 0x07
//    { 2, KEY_DOWN            ,0x00000040 }, // Found @0xffab1688, levent 0x05
//    { 2, KEY_UP              ,0x00000080 }, // Found @0xffab1694, levent 0x04
//    { 2, KEY_SET             ,0x00000100 }, // Found @0xffab16a0, levent 0x08
//    { 2, KEY_DISPLAY         ,0x00000200 }, // Found @0xffab16ac, levent 0x0a
//    { 2, KEY_MENU            ,0x00000400 }, // Found @0xffab16b8, levent 0x09
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_RAW_ROWPIX    3720 // Found @0xffa8248c
//#define CAM_RAW_ROWS      2772 // Found @0xffa82494
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x10000000 // Found @0xff8285a4

// Misc stuff
DEF(ctypes, 0xffab11b6)

// For capt_seq.c
//static long *nrflag = (long*)(0x91a4);       // Found @ ff93db0c

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
//NHSTUB(CreateJumptable                      ,0xffa8b388) //  1
//NHSTUB(_uartr_req                           ,0xff81cda0) //111
//NHSTUB(AllocateMemory                       ,0xffa2e3a0) //101
NHSTUB(AllocateUncacheableMemory              ,0xff828568) //112
NHSTUB(Close                                  ,0xff823d90) //101
NHSTUB(CreateTask                             ,0xff81b818) //101
NHSTUB(DebugAssert                            ,0xff81bcf0) //111
NHSTUB(DeleteDirectory_Fut                    ,0xff823720) //116
NHSTUB(DeleteFile_Fut                         ,0xff82363c) //112
NHSTUB(DoAFLock                               ,0xff825b84) //102
NHSTUB(EnterToCompensationEVF                 ,0xff825e80) //104
NHSTUB(ExecuteEventProcedure                  ,0xff86938c) //104
NHSTUB(ExitFromCompensationEVF                ,0xff825ed0) //104
NHSTUB(ExitTask                               ,0xff81baa8) //101
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff832b00) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff832c44) //104
NHSTUB(Fclose_Fut                             ,0xff8237b8) //101
NHSTUB(Feof_Fut                               ,0xff8239a4) //  1
NHSTUB(Fflush_Fut                             ,0xff8239e0) //  1
NHSTUB(Fgets_Fut                              ,0xff82390c) //  1
NHSTUB(Fopen_Fut                              ,0xff823778) //101
NHSTUB(Fread_Fut                              ,0xff823864) //101
//NHSTUB(FreeMemory                           ,0xffa2e398) //101
NHSTUB(FreeUncacheableMemory                  ,0xff82859c) //112
NHSTUB(Fseek_Fut                              ,0xff823958) //101
NHSTUB(Fwrite_Fut                             ,0xff8238b8) //101
NHSTUB(GetBatteryTemperature                  ,0xff84539c) //102
NHSTUB(GetCCDTemperature                      ,0xff84532c) //102
NHSTUB(GetCurrentAvValue                      ,0xff92facc) //102
NHSTUB(GetDrive_ClusterSize                   ,0xff84f2bc) //  1
NHSTUB(GetDrive_FreeClusters                  ,0xff84f324) //  1
NHSTUB(GetDrive_TotalClusters                 ,0xff84f2f0) //  1
NHSTUB(GetFocusLensSubjectDistance            ,0xff92ebc4) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff92eed0) //  1
NHSTUB(GetKbdState                            ,0xff8428e4) //109
NHSTUB(GetMemInfo                             ,0xff813c40) //115
NHSTUB(GetOpticalTemperature                  ,0xff84540c) //102
NHSTUB(GetParameterData                       ,0xff95d8a4) //101
NHSTUB(GetPropertyCase                        ,0xff86cf8c) //102
NHSTUB(GetSystemTime                          ,0xffa2e3f8) //101
NHSTUB(GetVRAMHPixelsSize                     ,0xff8c851c) //102
NHSTUB(GetVRAMVPixelsSize                     ,0xff8c8528) //102
NHSTUB(GetZoomLensCurrentPoint                ,0xff932d74) //102
NHSTUB(GetZoomLensCurrentPosition             ,0xffa24448) //102
NHSTUB(GiveSemaphore                          ,0xff81b77c) //112
NHSTUB(IsStrobeChargeCompleted                ,0xff8bd988) //102
NHSTUB(LEDDrive                               ,0xff842068) //103
NHSTUB(LocalTime                              ,0xff866a50) //115
NHSTUB(LockMainPower                          ,0xff875438) //103
//NHSTUB(Lseek                                ,0xff823ed0) //101
NHSTUB(MakeDirectory_Fut                      ,0xff8236b0) //116
NHSTUB(MoveFocusLensToDistance                ,0xffa855a8) //102
NHSTUB(MoveIrisWithAv                         ,0xffa2a7a8) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xffa2ad2c) //102
//NHSTUB(NewTaskShell                         ,0xff86ca50) //103
NHSTUB(Open                                   ,0xff823d68) //101
NHSTUB(PB2Rec                                 ,0xff878454) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff85bb68) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff85bb40) //102
NHSTUB(PT_PlaySound                           ,0xff85b1c4) //102
NHSTUB(PostLogicalEventForNotPowerType        ,0xff8731f8) //103
NHSTUB(PostLogicalEventToUI                   ,0xff873244) //103
NHSTUB(Read                                   ,0xff81a094) //101
NHSTUB(ReadFastDir                            ,0xffa13470) //  1
NHSTUB(Rec2PB                                 ,0xff876e58) //104
NHSTUB(RefreshPhysicalScreen                  ,0xff9b1258) //104
//NHSTUB(Remove                               ,0xff823dd8) //  1
NHSTUB(RenameFile_Fut                         ,0xff8235e8) //  1
NHSTUB(Restart                                ,0xff829de0) //106
NHSTUB(SetAE_ShutterSpeed                     ,0xffa87c7c) //102
NHSTUB(SetAutoShutdownTime                    ,0xff8754ac) //103
NHSTUB(SetCurrentCaptureModeType              ,0xff87c2b8) //101
NHSTUB(SetFileAttributes                      ,0xff8240bc) //  1
NHSTUB(SetFileTimeStamp                       ,0xff82406c) //  1
NHSTUB(SetLogicalEventActive                  ,0xff875118) //  1
NHSTUB(SetParameterData                       ,0xff95d814) //101
NHSTUB(SetPropertyCase                        ,0xff86ce8c) //102
NHSTUB(SetScriptMode                          ,0xff875168) //101
NHSTUB(SleepTask                              ,0xff8283ec) //101
NHSTUB(TakeSemaphore                          ,0xff81b6ac) //101
NHSTUB(TurnOffBackLight                       ,0xff881cac) //104
NHSTUB(TurnOnBackLight                        ,0xff881c94) //104
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff951064) //103
NHSTUB(UnlockAF                               ,0xff825bc8) //102
NHSTUB(UnlockMainPower                        ,0xff87538c) //103
NHSTUB(UnsetZoomForMovie                      ,0xff962e40) //104
NHSTUB(UpdateMBROnFlash                       ,0xff84f0fc) //105
NHSTUB(VbattGet                               ,0xff82071c) //103
NHSTUB(Write                                  ,0xff823e3c) //101
NHSTUB(WriteSDCard                            ,0xff922764) //108
NHSTUB(_log                                   ,0xffaaec70) //111
NHSTUB(_log10                                 ,0xffaadbb4) //112
NHSTUB(_pow                                   ,0xffaadd24) //114
NHSTUB(_sqrt                                  ,0xffab0090) //  1
NHSTUB(add_ptp_handler                        ,0xff9e1a94) //  1
NHSTUB(apex2us                                ,0xff9b2794) //  4
NHSTUB(close                                  ,0xff819eac) //  1
NHSTUB(closedir                               ,0xffa13540) //  1
NHSTUB(err_init_task                          ,0xff814e98) //111
NHSTUB(exmem_alloc                            ,0xff867b74) //103
NHSTUB(exmem_free                             ,0xff867bec) //103
NHSTUB(free                                   ,0xff813a98) //112
NHSTUB(kbd_p1_f                               ,0xff821f3c) //109
NHSTUB(kbd_p1_f_cont                          ,0xff821f48) //109
NHSTUB(kbd_p2_f                               ,0xff821770) //109
NHSTUB(kbd_read_keys                          ,0xff821e38) //109
NHSTUB(kbd_read_keys_r2                       ,0xff842490) //109
NHSTUB(kbd_pwr_off                            ,0xff842968) //  2
NHSTUB(kbd_pwr_on                             ,0xff842918) //  2
NHSTUB(lseek                                  ,0xff823ed0) //101
NHSTUB(malloc                                 ,0xff8139c4) //112
NHSTUB(memcmp                                 ,0xff81d844) //101
NHSTUB(memcpy                                 ,0xff894328) //101
NHSTUB(memset                                 ,0xff9b160c) //101
NHSTUB(mkdir                                  ,0xff824134) //109
NHSTUB(mktime_ext                             ,0xff894b94) //  1
NHSTUB(open                                   ,0xff819dfc) //  1
NHSTUB(OpenFastDir                            ,0xffa133dc) //  1
NHSTUB(qsort                                  ,0xff9b1b14) //  1
NHSTUB(rand                                   ,0xff81d94c) //  1
//NHSTUB(read                                 ,0xff81a094) //101
NHSTUB(realloc                                ,0xff813b78) //115
NHSTUB(reboot_fw_update                       ,0xffa1ae70) //106
NHSTUB(set_control_event                      ,0xff874d94) //  1
NHSTUB(srand                                  ,0xff81d940) //  1
NHSTUB(stat                                   ,0xff823f9c) //  1
NHSTUB(strcat                                 ,0xff894114) //  1
NHSTUB(strchr                                 ,0xff89419c) //  1
NHSTUB(strcmp                                 ,0xff81d7dc) //101
NHSTUB(strcpy                                 ,0xff81d7c4) //101
NHSTUB(strftime                               ,0xff89459c) //  1
NHSTUB(strlen                                 ,0xff81d820) //101
NHSTUB(strncmp                                ,0xff894150) //  1
NHSTUB(strncpy                                ,0xff82e1fc) //  1
NHSTUB(strrchr                                ,0xff8941c0) //  1
NHSTUB(strtol                                 ,0xff82e434) //101
NHSTUB(strtolx                                ,0xff82e238) //109
   DEF(task_CaptSeq                           ,0xff85dfc0) //107
   DEF(task_ExpDrv                            ,0xff8b67e8) //110
   DEF(task_InitFileModules                   ,0xff878f08) //107
   DEF(task_MovieRecord                       ,0xff859f88) //107
   DEF(task_PhySw                             ,0xff821acc) //107
NHSTUB(time                                   ,0xff866f54) //109
NHSTUB(vsprintf                               ,0xff81d744) //115
//NHSTUB(write                                ,0xff823e3c) //101
//NHSTUB(EngDrvIn                             ,0xff822d74) //102
//NHSTUB(EngDrvOut                            ,0xff822d5c) //102
//NHSTUB(EngDrvRead                           ,0xff822d7c) //102
//NHSTUB(EngDrvBits                           ,0xff822d90) //102
//NHSTUB(GetSDProtect                         ,0xff821e18) //103
//NHSTUB(StartRecModeMenu                     ,0xff950104) //102
//NHSTUB(DispCon_ShowBitmapColorBar           ,0xff83e868) //102
//NHSTUB(ResetZoomLens                        ,0xffa2ac80) //102
//NHSTUB(ResetFocusLens                       ,0xffa29c88) //102
//NHSTUB(NR_GetDarkSubType                    ,0xff93ecdc) //102
//NHSTUB(NR_SetDarkSubType                    ,0xff93ec68) //102
//NHSTUB(SavePaletteData                      ,0xffa89cd8) //102
