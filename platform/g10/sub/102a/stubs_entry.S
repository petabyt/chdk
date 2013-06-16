// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R31 (DRYOS version 2.3, release #0031)
//   Firmware Ver GM1.02A
//   Canon PowerShot G10

// Values for makefile.inc
//   PLATFORMOSVER = 31
//   PLATFORMID = 12687 (0x318f) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x07ffffff
//   KEYSYS = d4                 // Found @ 0xffff368c
//   NEED_ENCODED_DISKBOOT = 1   // Found @ 0xffff369c

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NHSTUB(kbd_pwr_off                          ,0xff84b174) //  2 60%        == 0xff84b174
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0xff81093c

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff88301c -> ff87f310 -> ff970650 -> ffa7aa78 -> ffb75040
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00011cb8) // Found @0xff821c28
DEF(physw_run                               ,0x00001c2c) // Found @0xff82189c
DEF(physw_sleep_delay                       ,0x00001c2a) // Found @0xff82189c
DEF(levent_table                            ,0xffb43a90) // Found @0xffb43a90
DEF(FlashParamsTable                        ,0xffb75220) // Found @0xffb75220
DEF(movie_status                            ,0x00005418) // Found @0xff8629c4
DEF(video_compression_rate                  ,0x00005444) // Found @0xff862b90
DEF(canon_menu_active                       ,0x00005868) // Found @0xff8782dc
DEF(canon_shoot_menu_active                 ,0x0000a8ad) // Found @0xff987994
DEF(playrec_mode                            ,0x000055d0) // Found @0xff86b300
DEF(zoom_status                             ,0x0000e0b0) // Found @0xffa7c758
DEF(some_flag_for_af_scan                   ,0x000096f8) // Found @0xff946b5c
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 14 entries in the table - set NUM_FL to 14
DEF(focus_len_table                         ,0xfffe2a8c) // Found @0xfffe2a8c
DEF(zoom_busy                               ,0x00008d44) // Found @0xff93e458
DEF(focus_busy                              ,0x00008c44) // Found @0xff938b44
DEF(recreview_hold                          ,0x00006274) // Found @0xff888be8
// Palette colour tables  found @ 0xffb593f4
DEF(active_palette_buffer                   ,0x0000bac4) // Found @0xff9d642c
DEF(palette_buffer_ptr                      ,0x0000bab8) // Found @0xff9d62e0
// Offset from start of palette_buffer to color data = 16 (Found @0xff9d526c)
// Camera has 2 RAW buffers @ 0x413245a0 & 0x43164d80
//  Note: active buffer --> raw_buffers[ active_raw_buffer   *3]
//        other buffer  --> raw_buffers[(active_raw_buffer^1)*3]
DEF(raw_buffers                             ,0xffb101a0) // Found @0xffb101a0
DEF(active_raw_buffer                       ,0x00005574) // Found @0xff868430

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40471000; }             // Found @0xff846a4c
//void *vid_get_viewport_fb()      { return (void*)0x40816dc0; }             // Found @0xffad4d84
DEF(viewport_fb_d                           ,0x000052a4) // Found 0x524c (@0xff85b864) + 0x58 (@0xff85b89c)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x524c+0x58)); } // Found @0xff85b864 & 0xff85b89c
DEF(jpeg_count_str                          ,0x0004c95c) // Found @0xff9cccf0
//char *camera_jpeg_count_str()    { return (char*)0x0004c95c; }             // Found @0xff9cccf0
//long hook_raw_size()             { return 0x01574d00; }                    // Found @0xffad7140
//int get_flash_params_count(void) { return 0x78; }                          // Found @0xff971c50

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffb0f954, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00040000 // Found @0xffb0f960, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_SHOOT_FULL      ,0x00000003 }, // Found @0xffb0f7d4, levent 0x01
//    { 0, KEY_SHOOT_FULL_ONLY ,0x00000002 }, // Found @0xffb0f7d4, levent 0x01
//    { 0, KEY_SHOOT_HALF      ,0x00000001 }, // Found @0xffb0f7c8, levent 0x00
//    { 0, KEY_POWER           ,0x40000000 }, // Found @0xffb0f804, levent 0x600 (uses inverted logic in physw_status)
//    { 0, KEY_PLAYBACK        ,0x80000000 }, // Found @0xffb0f810, levent 0x601 (uses inverted logic in physw_status)
//    { 1, KEY_ZOOM_OUT        ,0x00000008 }, // Found @0xffb0f840, levent 0x03
//    { 1, KEY_ZOOM_IN         ,0x00000010 }, // Found @0xffb0f84c, levent 0x02
//    { 1, KEY_LEFT            ,0x00000400 }, // Found @0xffb0f894, levent 0x06
//    { 1, KEY_SET             ,0x00000800 }, // Found @0xffb0f8a0, levent 0x08
//    { 1, KEY_RIGHT           ,0x00001000 }, // Found @0xffb0f8ac, levent 0x07
//    { 1, KEY_DOWN            ,0x00002000 }, // Found @0xffb0f8b8, levent 0x05
//    { 1, KEY_UP              ,0x00004000 }, // Found @0xffb0f8c4, levent 0x04
//    { 1, KEY_DISPLAY         ,0x00020000 }, // Found @0xffb0f8e8, levent 0x0a
//    { 1, KEY_MENU            ,0x00040000 }, // Found @0xffb0f8f4, levent 0x09
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_RAW_ROWPIX    4480 // Found @0xffacde4c
//#define CAM_RAW_ROWS      3348 // Found @0xffacde50
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff828844

// Misc stuff
DEF(ctypes, 0xffb0964a)

// For capt_seq.c
DEF(_nrflag,0x96e0) // Found @ ff94921c (0x96e4) & ff949238 (-0x04)
//static long *nrflag = (long*)(0x96e4-0x04);  // Found @ ff94921c & ff949234

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
//NHSTUB(CreateJumptable                      ,0xffad7894) //  1
//NHSTUB(_uartr_req                           ,0xff81c2a0) //111
//NHSTUB(StartRecModeMenu                     ,0xff8782d8) //102
//NHSTUB(AllocateMemory                       ,0xffa6886c) //101
NHSTUB(AllocateUncacheableMemory              ,0xff828800) //112
NHSTUB(Close                                  ,0xff824088) //101
NHSTUB(CreateTask                             ,0xff81aef4) //101
NHSTUB(DebugAssert                            ,0xff81b1cc) //111
NHSTUB(DeleteDirectory_Fut                    ,0xff823a18) //116
NHSTUB(DeleteFile_Fut                         ,0xff823934) //112
NHSTUB(DoAFLock                               ,0xff825e48) //102
NHSTUB(EnterToCompensationEVF                 ,0xff826110) //104
NHSTUB(ExecuteEventProcedure                  ,0xff873ae4) //104
NHSTUB(ExitFromCompensationEVF                ,0xff826154) //104
NHSTUB(ExitTask                               ,0xff81b184) //101
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff831950) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff831a94) //104
NHSTUB(Fclose_Fut                             ,0xff823ab0) //101
NHSTUB(Feof_Fut                               ,0xff823c9c) //  1
NHSTUB(Fflush_Fut                             ,0xff823cd8) //  1
NHSTUB(Fgets_Fut                              ,0xff823c04) //  1
NHSTUB(Fopen_Fut                              ,0xff823a70) //101
NHSTUB(Fread_Fut                              ,0xff823b5c) //101
//NHSTUB(FreeMemory                           ,0xffa68864) //101
NHSTUB(FreeUncacheableMemory                  ,0xff828840) //112
NHSTUB(Fseek_Fut                              ,0xff823c50) //101
NHSTUB(Fwrite_Fut                             ,0xff823bb0) //101
NHSTUB(GetBatteryTemperature                  ,0xff84dc90) //102
NHSTUB(GetCCDTemperature                      ,0xff84dc20) //102
NHSTUB(GetCurrentAvValue                      ,0xff93b378) //102
NHSTUB(GetDrive_ClusterSize                   ,0xff859f90) //  1
NHSTUB(GetDrive_FreeClusters                  ,0xff859ff8) //  1
NHSTUB(GetDrive_TotalClusters                 ,0xff859fc4) //  1
NHSTUB(GetFocusLensSubjectDistance            ,0xff939848) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff939c30) //  3
NHSTUB(GetKbdState                            ,0xff84afbc) //109
NHSTUB(GetMemInfo                             ,0xff813c24) //115
NHSTUB(GetOpticalTemperature                  ,0xff84dd00) //102
NHSTUB(GetParameterData                       ,0xff971c10) //101
NHSTUB(GetPropertyCase                        ,0xff8777cc) //102
NHSTUB(GetSystemTime                          ,0xffa688c4) //101
NHSTUB(GetVRAMHPixelsSize                     ,0xff83ce54) //102
NHSTUB(GetVRAMVPixelsSize                     ,0xff83ce60) //102
NHSTUB(GetZoomLensCurrentPoint                ,0xff93e7c8) //102
NHSTUB(GetZoomLensCurrentPosition             ,0xffa5dcb8) //102
NHSTUB(GiveSemaphore                          ,0xff82821c) //112
NHSTUB(IsStrobeChargeCompleted                ,0xff8b4794) //102
NHSTUB(LEDDrive                               ,0xff84a53c) //103
NHSTUB(LocalTime                              ,0xff871280) //115
NHSTUB(LockMainPower                          ,0xff87ef28) //103
//NHSTUB(Lseek                                ,0xff8241c8) //101
NHSTUB(MakeDirectory_Fut                      ,0xff8239a8) //116
NHSTUB(MoveFocusLensToDistance                ,0xffad17b8) //102
NHSTUB(MoveIrisWithAv                         ,0xffa65290) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xffa659a8) //102
//NHSTUB(NewTaskShell                         ,0xff877274) //103
NHSTUB(Open                                   ,0xff824060) //101
NHSTUB(PB2Rec                                 ,0xff8822ec) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff864344) //102
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff86431c) //102
NHSTUB(PT_PlaySound                           ,0xff863c98) //102
NHSTUB(PostLogicalEventForNotPowerType        ,0xff87ccec) //103
NHSTUB(PostLogicalEventToUI                   ,0xff87cd38) //103
NHSTUB(PutInNdFilter                          ,0xffa6580c) //102
NHSTUB(PutOutNdFilter                         ,0xffa65830) //102
NHSTUB(Read                                   ,0xff819a4c) //101
NHSTUB(ReadFastDir                            ,0xffa4a194) //  1
NHSTUB(Rec2PB                                 ,0xff880c28) //104
//NHSTUB(RefreshPhysicalScreen                ,0xff9dae58) //104            == 0xff9dae58
//NHSTUB(Remove                               ,0xff8240d0) //  1
NHSTUB(RenameFile_Fut                         ,0xff8238e0) //  1
NHSTUB(Restart                                ,0xff82a074) //106
NHSTUB(SetAE_ShutterSpeed                     ,0xffad3f88) //102
NHSTUB(SetAutoShutdownTime                    ,0xff87ef9c) //103
NHSTUB(SetCurrentCaptureModeType              ,0xff885d94) //101
NHSTUB(SetFileAttributes                      ,0xff8243b4) //  1
NHSTUB(SetFileTimeStamp                       ,0xff824364) //  1
NHSTUB(SetLogicalEventActive                  ,0xff87ec78) //101
NHSTUB(SetParameterData                       ,0xff971aec) //101
NHSTUB(SetPropertyCase                        ,0xff8776c4) //102
NHSTUB(SetScriptMode                          ,0xff87ecc8) //101
NHSTUB(SleepTask                              ,0xff828484) //101
NHSTUB(TakeSemaphore                          ,0xff82814c) //101
NHSTUB(TurnOffBackLight                       ,0xff88c57c) //104
NHSTUB(TurnOnBackLight                        ,0xff88c564) //104
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff95fddc) //103
NHSTUB(UnlockAF                               ,0xff825e9c) //102
NHSTUB(UnlockMainPower                        ,0xff87ee7c) //103
NHSTUB(UnsetZoomForMovie                      ,0xff977ed4) //104
NHSTUB(UpdateMBROnFlash                       ,0xff859dd0) //105
NHSTUB(VbattGet                               ,0xff820574) //103
NHSTUB(Write                                  ,0xff824134) //101
NHSTUB(WriteSDCard                            ,0xff92a7c0) //108
NHSTUB(_log                                   ,0xffb068c8) //111
NHSTUB(_log10                                 ,0xffb05554) //112
NHSTUB(_pow                                   ,0xffb056c4) //114
NHSTUB(_sqrt                                  ,0xffb08524) //  1
NHSTUB(add_ptp_handler                        ,0xffa15950) //  3
NHSTUB(apex2us                                ,0xff9dc33c) //  4
NHSTUB(close                                  ,0xff819864) //  1
NHSTUB(closedir                               ,0xffa4a264) //  1
NHSTUB(err_init_task                          ,0xff814e80) //111
NHSTUB(exmem_alloc                            ,0xff8721c0) //103
NHSTUB(exmem_free                             ,0xff872238) //103
NHSTUB(free                                   ,0xff813a7c) //112
NHSTUB(kbd_p1_f                               ,0xff821d24) //109
NHSTUB(kbd_p1_f_cont                          ,0xff821d30) //109
NHSTUB(kbd_p2_f                               ,0xff82153c) //109
NHSTUB(kbd_read_keys                          ,0xff821c28) //109
NHSTUB(kbd_read_keys_r2                       ,0xff84a99c) //109
NHSTUB(lseek                                  ,0xff8241c8) //101
NHSTUB(malloc                                 ,0xff8139a8) //112
NHSTUB(memcmp                                 ,0xff81cbb0) //101
NHSTUB(memcpy                                 ,0xff899344) //101
NHSTUB(memset                                 ,0xff9db1ac) //101
NHSTUB(mkdir                                  ,0xff82442c) //109
NHSTUB(mktime_ext                             ,0xff899bb0) //  1
NHSTUB(open                                   ,0xff8197b4) //  1
NHSTUB(OpenFastDir                            ,0xffa4a100) //  1
NHSTUB(qsort                                  ,0xff9db6b4) //  1
NHSTUB(rand                                   ,0xff81ccb8) //  1
//NHSTUB(read                                 ,0xff819a4c) //101
NHSTUB(realloc                                ,0xff813b5c) //115
NHSTUB(reboot_fw_update                       ,0xffa51b94) //106
NHSTUB(set_control_event                      ,0xff87e8dc) //111
NHSTUB(srand                                  ,0xff81ccac) //  1
NHSTUB(stat                                   ,0xff824294) //  1
NHSTUB(strcat                                 ,0xff899158) //  1
NHSTUB(strchr                                 ,0xff8991e0) //  1
NHSTUB(strcmp                                 ,0xff81cb48) //101
NHSTUB(strcpy                                 ,0xff81cb30) //101
NHSTUB(strftime                               ,0xff8995b8) //  1
NHSTUB(strlen                                 ,0xff81cb8c) //101
NHSTUB(strncmp                                ,0xff899194) //  1
NHSTUB(strncpy                                ,0xff82e2bc) //  1
NHSTUB(strrchr                                ,0xff9db184) //  1
NHSTUB(strtol                                 ,0xff82e4f4) //101
NHSTUB(strtolx                                ,0xff82e2f8) //109
   DEF(task_CaptSeq                           ,0xff866bfc) //110
   DEF(task_ExpDrv                            ,0xff8ab0e0) //110
   DEF(task_InitFileModules                   ,0xff882ea8) //110
   DEF(task_MovieRecord                       ,0xff862c0c) //110
   DEF(task_PhySw                             ,0xff821898) //110
NHSTUB(time                                   ,0xff871860) //109
NHSTUB(vsprintf                               ,0xff81caf4) //115
//NHSTUB(write                                ,0xff824134) //101
//NHSTUB(EngDrvIn                             ,0xff822b5c) //102
//NHSTUB(EngDrvOut                            ,0xff822b44) //102
//NHSTUB(EngDrvRead                           ,0xff822b64) //102
//NHSTUB(EngDrvBits                           ,0xff822b78) //102
//NHSTUB(GetSDProtect                         ,0xff821c00) //103
//NHSTUB(DispCon_ShowBitmapColorBar           ,0xff846a18) //102
//NHSTUB(ResetZoomLens                        ,0xffa658fc) //102
//NHSTUB(ResetFocusLens                       ,0xffa64720) //102
//NHSTUB(NR_GetDarkSubType                    ,0xff94a648) //102
//NHSTUB(NR_SetDarkSubType                    ,0xff94a59c) //102
//NHSTUB(SavePaletteData                      ,0xffad6018) //102
