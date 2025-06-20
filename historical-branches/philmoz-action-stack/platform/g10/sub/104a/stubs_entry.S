// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R31 (DRYOS version 2.3, release #0031)
//   Firmware Ver GM1.04A
//   Canon PowerShot G10

// Values for makefile.inc
//   PLATFORMOSVER = 31
//   PLATFORMID = 12687 (0x318f) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x07ffffff
//   KEYSYS = d4                 // Found @ 0xffff368c
//   NEED_ENCODED_DISKBOOT = 1   // Found @ 0xffff369c

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NSTUB(kbd_pwr_off                           ,0xff84b174) //  2 60%        == 0xff84b174
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0xff81093c

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff88301c -> ff87f310 -> ff970650 -> ffa7aa88 -> ffb75080
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00011cb8) // Found @0xff821c28
DEF(physw_run                               ,0x00001c2c) // Found @0xff82189c
DEF(physw_sleep_delay                       ,0x00001c2a) // Found @0xff82189c
DEF(levent_table                            ,0xffb43ad0) // Found @0xffb43ad0
DEF(FlashParamsTable                        ,0xffb75260) // Found @0xffb75260
DEF(movie_status                            ,0x00005418) // Found @0xff8629c4
DEF(canon_menu_active                       ,0x00005868) // Found @0xff8782dc
DEF(canon_shoot_menu_active                 ,0x0000a8ad) // Found @0xff9879a4
DEF(playrec_mode                            ,0x000055d0) // Found @0xff86b300
DEF(zoom_status                             ,0x0000e0b0) // Found @0xffa7c768
DEF(some_flag_for_af_scan                   ,0x000096f8) // Found @0xff946b5c
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 3 int value(s), the first is the zoom focus length.
// there are 14 entries in the table - set NUM_FL to 14
DEF(focus_len_table                         ,0xfffe2a8c) // Found @0xfffe2a8c
DEF(zoom_busy                               ,0x00008d44) // Found @0xff93e458
DEF(focus_busy                              ,0x00008c44) // Found @0xff938b44
DEF(recreview_hold                          ,0x00006274) // Found @0xff888be8

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40471000; }             // Found @0xff846a4c
//void *vid_get_viewport_fb()      { return (void*)0x40816dc0; }             // Found @0xffad4d94
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x524c+0x58)); } // Found @0xff85b864 & 0xff85b89c
//char *camera_jpeg_count_str()    { return (char*)0x0004c95c; }             // Found @0xff9ccd00
//long hook_raw_size()             { return 0x01574d00; }                    // Found @0xffad7150
//int get_flash_params_count(void) { return 0x78; }                          // Found @0xff971c50

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffb0f994, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00040000 // Found @0xffb0f9a0, levent 0x902
//#define USB_IDX             2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_SHOOT_FULL      ,0x00000003 }, // Found @0xffb0f814, levent 0x01
//    { 0, KEY_SHOOT_FULL_ONLY ,0x00000002 }, // Found @0xffb0f814, levent 0x01
//    { 0, KEY_SHOOT_HALF      ,0x00000001 }, // Found @0xffb0f808, levent 0x00
//    { 0, KEY_POWER           ,0x40000000 }, // Found @0xffb0f844, levent 0x600 (uses inverted logic in physw_status)
//    { 0, KEY_PLAYBACK        ,0x80000000 }, // Found @0xffb0f850, levent 0x601 (uses inverted logic in physw_status)
//    { 1, KEY_ZOOM_OUT        ,0x00000008 }, // Found @0xffb0f880, levent 0x03
//    { 1, KEY_ZOOM_IN         ,0x00000010 }, // Found @0xffb0f88c, levent 0x02
//    { 1, KEY_LEFT            ,0x00000400 }, // Found @0xffb0f8d4, levent 0x06
//    { 1, KEY_SET             ,0x00000800 }, // Found @0xffb0f8e0, levent 0x08
//    { 1, KEY_RIGHT           ,0x00001000 }, // Found @0xffb0f8ec, levent 0x07
//    { 1, KEY_DOWN            ,0x00002000 }, // Found @0xffb0f8f8, levent 0x05
//    { 1, KEY_UP              ,0x00004000 }, // Found @0xffb0f904, levent 0x04
//    { 1, KEY_DISPLAY         ,0x00020000 }, // Found @0xffb0f928, levent 0x0a
//    { 1, KEY_MENU            ,0x00040000 }, // Found @0xffb0f934, levent 0x09
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_RAW_ROWPIX    4480 // Found @0xffacde5c
//#define CAM_RAW_ROWS      3348 // Found @0xffacde60
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff828844

// Misc stuff
DEF(ctypes, 0xffb0968a)

// For capt_seq.c
//static long *nrflag = (long*)(0x96e4-0x04);  // Found @ ff94921c & ff949234

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NSTUB(AllocateMemory                          ,0xffa6887c) //101
NSTUB(AllocateUncacheableMemory               ,0xff828800) //112
NSTUB(Close                                   ,0xff824088) //101
NSTUB(CreateTask                              ,0xff81aef4) //101
NSTUB(DebugAssert                             ,0xff81b1cc) //111
NSTUB(DeleteDirectory_Fut                     ,0xff823a18) //116
NSTUB(DeleteFile_Fut                          ,0xff823934) //112
NSTUB(DoAFLock                                ,0xff825e48) //102
NSTUB(EnterToCompensationEVF                  ,0xff826110) //104
NSTUB(ExecuteEventProcedure                   ,0xff873ae4) //104
NSTUB(ExitFromCompensationEVF                 ,0xff826154) //104
NSTUB(ExitTask                                ,0xff81b184) //101
NSTUB(ExpCtrlTool_StartContiAE                ,0xff831950) //104
NSTUB(ExpCtrlTool_StopContiAE                 ,0xff831a94) //104
NSTUB(Fclose_Fut                              ,0xff823ab0) //101
NSTUB(Feof_Fut                                ,0xff823c9c) //  1
NSTUB(Fflush_Fut                              ,0xff823cd8) //  1
NSTUB(Fgets_Fut                               ,0xff823c04) //  1
NSTUB(Fopen_Fut                               ,0xff823a70) //101
NSTUB(Fread_Fut                               ,0xff823b5c) //101
NSTUB(FreeMemory                              ,0xffa68874) //101
NSTUB(FreeUncacheableMemory                   ,0xff828840) //112
NSTUB(Fseek_Fut                               ,0xff823c50) //101
NSTUB(Fwrite_Fut                              ,0xff823bb0) //101
NSTUB(GetBatteryTemperature                   ,0xff84dc90) //102
NSTUB(GetCCDTemperature                       ,0xff84dc20) //102
NSTUB(GetCurrentAvValue                       ,0xff93b378) //102
NSTUB(GetDrive_ClusterSize                    ,0xff859f90) //  1
NSTUB(GetDrive_FreeClusters                   ,0xff859ff8) //  1
NSTUB(GetDrive_TotalClusters                  ,0xff859fc4) //  1
NSTUB(GetFocusLensSubjectDistance             ,0xff939848) //102
NSTUB(GetFocusLensSubjectDistanceFromLens     ,0xff939c30) //  3
NSTUB(GetKbdState                             ,0xff84afbc) //109
NSTUB(GetMemInfo                              ,0xff813c24) //115
NSTUB(GetOpticalTemperature                   ,0xff84dd00) //102
NSTUB(GetParameterData                        ,0xff971c10) //101
NSTUB(GetPropertyCase                         ,0xff8777cc) //102
NSTUB(GetSystemTime                           ,0xffa688d4) //101
NSTUB(GetVRAMHPixelsSize                      ,0xff83ce54) //102
NSTUB(GetVRAMVPixelsSize                      ,0xff83ce60) //102
NSTUB(GetZoomLensCurrentPoint                 ,0xff93e7c8) //102
NSTUB(GetZoomLensCurrentPosition              ,0xffa5dcc8) //102
NSTUB(GiveSemaphore                           ,0xff82821c) //112
NSTUB(IsStrobeChargeCompleted                 ,0xff8b4794) //102
NSTUB(LEDDrive                                ,0xff84a53c) //103
NSTUB(LocalTime                               ,0xff871280) //115
NSTUB(LockMainPower                           ,0xff87ef28) //103
NSTUB(Lseek                                   ,0xff8241c8) //101
NSTUB(MakeDirectory_Fut                       ,0xff8239a8) //116
NSTUB(MoveFocusLensToDistance                 ,0xffad17c8) //102
NSTUB(MoveIrisWithAv                          ,0xffa652a0) //102
NSTUB(MoveZoomLensWithPoint                   ,0xffa659b8) //102
NSTUB(NewTaskShell                            ,0xff877274) //103
NSTUB(Open                                    ,0xff824060) //101
NSTUB(PB2Rec                                  ,0xff8822ec) //104
NSTUB(PT_MoveDigitalZoomToWide                ,0xff864344) //102
NSTUB(PT_MoveOpticalZoomAt                    ,0xff86431c) //102
NSTUB(PT_PlaySound                            ,0xff863c98) //102
NSTUB(PostLogicalEventForNotPowerType         ,0xff87ccec) //103
NSTUB(PostLogicalEventToUI                    ,0xff87cd38) //103
NSTUB(PutInNdFilter                           ,0xffa6581c) //102
NSTUB(PutOutNdFilter                          ,0xffa65840) //102
NSTUB(Read                                    ,0xff819a4c) //101
NSTUB(ReadFastDir                             ,0xffa4a1a4) //  1
NSTUB(Rec2PB                                  ,0xff880c28) //104
//NSTUB(RefreshPhysicalScreen                 ,0xff9dae68) //104            == 0xff9dae68
NSTUB(Remove                                  ,0xff8240d0) //  1
NSTUB(RenameFile_Fut                          ,0xff8238e0) //  1
NSTUB(Restart                                 ,0xff82a074) //106
NSTUB(SetAE_ShutterSpeed                      ,0xffad3f98) //102
NSTUB(SetAutoShutdownTime                     ,0xff87ef9c) //103
NSTUB(SetCurrentCaptureModeType               ,0xff885d94) //101
NSTUB(SetFileAttributes                       ,0xff8243b4) //  1
NSTUB(SetFileTimeStamp                        ,0xff824364) //  1
NSTUB(SetLogicalEventActive                   ,0xff87ec78) //101
NSTUB(SetParameterData                        ,0xff971aec) //101
NSTUB(SetPropertyCase                         ,0xff8776c4) //102
NSTUB(SetScriptMode                           ,0xff87ecc8) //101
NSTUB(SleepTask                               ,0xff828484) //101
NSTUB(TakeSemaphore                           ,0xff82814c) //101
NSTUB(TurnOffBackLight                        ,0xff88c57c) //104
NSTUB(TurnOnBackLight                         ,0xff88c564) //104
NSTUB(UIFS_WriteFirmInfoToFile                ,0xff95fddc) //103
NSTUB(UnlockAF                                ,0xff825e9c) //102
NSTUB(UnlockMainPower                         ,0xff87ee7c) //103
NSTUB(UnsetZoomForMovie                       ,0xff977ed0) //104
NSTUB(UpdateMBROnFlash                        ,0xff859dd0) //105
NSTUB(VbattGet                                ,0xff820574) //103
NSTUB(Write                                   ,0xff824134) //101
NSTUB(WriteSDCard                             ,0xff92a7c0) //108
NSTUB(_log                                    ,0xffb06908) //111
NSTUB(_log10                                  ,0xffb05594) //112
NSTUB(_pow                                    ,0xffb05704) //114
NSTUB(_sqrt                                   ,0xffb08564) //  1
NSTUB(add_ptp_handler                         ,0xffa15960) //  3
NSTUB(apex2us                                 ,0xff9dc34c) //  4
NSTUB(close                                   ,0xff819864) //  1
NSTUB(closedir                                ,0xffa4a274) //  1
NSTUB(err_init_task                           ,0xff814e80) //111
NSTUB(exmem_alloc                             ,0xff8721c0) //103
NSTUB(free                                    ,0xff813a7c) //112
NSTUB(kbd_p1_f                                ,0xff821d24) //109
NSTUB(kbd_p1_f_cont                           ,0xff821d30) //109
NSTUB(kbd_p2_f                                ,0xff82153c) //109
NSTUB(kbd_read_keys                           ,0xff821c28) //109
NSTUB(kbd_read_keys_r2                        ,0xff84a99c) //109
NSTUB(lseek                                   ,0xff8241c8) //101
NSTUB(malloc                                  ,0xff8139a8) //112
NSTUB(memcmp                                  ,0xff81cbb0) //101
NSTUB(memcpy                                  ,0xff899344) //101
NSTUB(memset                                  ,0xff9db1bc) //101
NSTUB(mkdir                                   ,0xff82442c) //109
NSTUB(mktime_ext                              ,0xff899bb0) //  1
NSTUB(open                                    ,0xff8197b4) //  1
NSTUB(OpenFastDir                             ,0xffa4a110) //  1
NSTUB(qsort                                   ,0xff9db6c4) //  1
NSTUB(rand                                    ,0xff81ccb8) //  1
NSTUB(read                                    ,0xff819a4c) //101
NSTUB(reboot_fw_update                        ,0xffa51ba4) //106
NSTUB(set_control_event                       ,0xff87e8dc) //111
NSTUB(srand                                   ,0xff81ccac) //  1
NSTUB(stat                                    ,0xff824294) //  1
NSTUB(strcat                                  ,0xff899158) //  1
NSTUB(strchr                                  ,0xff8991e0) //  1
NSTUB(strcmp                                  ,0xff81cb48) //101
NSTUB(strcpy                                  ,0xff81cb30) //101
NSTUB(strftime                                ,0xff8995b8) //  1
NSTUB(strlen                                  ,0xff81cb8c) //101
NSTUB(strncmp                                 ,0xff899194) //  1
NSTUB(strncpy                                 ,0xff82e2bc) //  1
NSTUB(strrchr                                 ,0xff9db194) //  1
NSTUB(strtol                                  ,0xff82e4f4) //101
NSTUB(strtolx                                 ,0xff82e2f8) //109
  DEF(task_CaptSeq                            ,0xff866bfc) //107
  DEF(task_ExpDrv                             ,0xff8ab0e0) //110
  DEF(task_InitFileModules                    ,0xff882ea8) //107
  DEF(task_MovieRecord                        ,0xff862c0c) //107
  DEF(task_PhySw                              ,0xff821898) //107
NSTUB(time                                    ,0xff871860) //109
NSTUB(vsprintf                                ,0xff81caf4) //115
NSTUB(write                                   ,0xff824134) //101
