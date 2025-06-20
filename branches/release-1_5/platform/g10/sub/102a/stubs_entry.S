// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R31 (DRYOS version 2.3, release #0031)
//   Firmware Ver GM1.02A   // Found @ 0xff8768bc, "GM1.02A" @ 0xff8768c9
//   Firmware build timestamp: Dec  3 2008 16:23:52
//   Canon PowerShot G10

// Values for makefile.inc
//   DIGIC = 40# DIGIC 4
//   PLATFORMOSVER = 31
//   PLATFORMID = 12687# (0x318f) Found @ 0xfffe0130
//   MAXRAMADDR = 0x07ffffff
//   MEMISOSTART = 0x000eeecc
//   KEYSYS = d4# Found @ 0xffff368c
//   NEED_ENCODED_DISKBOOT = 1# Found @ 0xffff369c
//   ARAM_HEAP_START = 0x3ce000# Found @ 0xff952c0c
//   ARAM_HEAP_SIZE  = 0x32000# Found @ 0xff952bcc

// Detected address ranges:
// ROM      0xff810000 - 0xffffffff (8323072 bytes)
// RAM data 0x00001900 - 0x00010834 copied from 0xffba09dc (  61236 bytes)

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NHSTUB(kbd_pwr_off                          ,0xff84b174) //  2 60%        == 0xff84b174

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ffa7aa78 -> ffb75040
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
DEF(fileio_semaphore                        ,0x00002a44) // Found @0xff8587b0
DEF(exmem_alloc_table                       ,0x0001c038) // Found @0xff871bc4
DEF(exmem_types_table                       ,0xffba479c) // Found @0x000056c0
DEF_CONST(exmem_type_count                  ,0x00000012)
DEF(imager_active                           ,0x00001fe0) // Found @0xff837d64 (0x1fdc + 4)
DEF_CONST(uiprop_count                      ,0x00000069) // Found @0xff970ffc

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40471000; }             // Found @0xff846a4c
//void *vid_get_viewport_fb()      { return (void*)0x40816dc0; }             // Found @0xffad4d84
DEF(viewport_fb_d                           ,0x000052a4) // Found 0x524c (@0xff85b864) + 0x58 (@0xff85b89c)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x524c+0x58)); } // Found @0xff85b864 & 0xff85b89c
DEF(jpeg_count_str                          ,0x0004c95c) // Found @0xff9cccf0
//char *camera_jpeg_count_str()    { return (char*)0x0004c95c; }             // Found @0xff9cccf0
//int get_flash_params_count(void) { return 0x78; }                          // Found @0xff971c50

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffb0f954, levent 0x90a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00040000 // Found @0xffb0f960, levent 0x902
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x00008000 // Found @0xffb0f7e0, levent 0x905
//#define BATTCOVER_IDX       0
//#define HOTSHOE_FLAG        0x10000000 // Found @0xffb0f7f8, levent 0x904
//#define HOTSHOE_IDX         0
//#define ANALOG_AV_FLAG      0x00200000 // Found @0xffb0f7ec, levent 0x900 (non-inverted logic)
//#define ANALOG_AV_IDX       0

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
//#define PARAM_CAMERA_NAME 4 // Found @0xffb778a8

// Below goes in 'filewrite.c' or 'platform_camera.h':
//#define MAX_CHUNKS_FOR_FWT 4 // Found @0xffa46a80

// Known propcases
// //      PROPCASE_AFSTEP 13
// #define PROPCASE_FOCUS_STATE 18
// #define PROPCASE_AV 23
// #define PROPCASE_BV 34
// //      PROPCASE_DELTA_DIGITALGAIN 77
// #define PROPCASE_DELTA_SV 79
// //      PROPCASE_DELTA_ND 80
// #define PROPCASE_EV_CORRECTION_2 207
// #define PROPCASE_ORIENTATION_SENSOR 219
// #define PROPCASE_SV_MARKET 246
// //      PROPCASE_SVFIX 247
// #define PROPCASE_TV 262
// Guessed propset: 2

// Misc stuff
DEF(ctypes, 0xffb0964a)

// EXMEM types:
// EXMEM_RAMDISK        0
// EXMEM_COM            1
// EXMEM_FORMATTER      2
// EXMEM_SHADING        3
// EXMEM_FAMODE         4
// EXMEM_FIRMUP         5
// EXMEM_FIRMUP_VRAM    6
// EXMEM_FIRMUP_INFLATE 7
// EXMEM_DVLPWORK       8
// EXMEM_EVF            9
// EXMEM_SCRIPT         10
// EXMEM_FILESTORE      11
// EXMEM_MOVIE_REC      12
// EXMEM_MOVIE_PLY      13
// EXMEM_WIDE           14
// EXMEM_NARROW         15
// EXMEM_CRAW_REC       16
// EXMEM_PCEVF          17

// ISR flag: 0x195c, pointer to current task's control block: 0x1958
// pointer to TCB area: 0x19e8, found @ 0xff815724

// LED table init @ 0xff8f3efc
// LED #1: 0xc02200d8, offset 0x3c4
// LED #2: 0xc02200d4, offset 0x204
// LED #3: 0xc02200d0, offset 0x384
// LED #4: 0xc0220138, offset 0x84
// LED #5: 0xc02200dc, offset 0xc4
// LED #6: 0xc0220134, offset 0x4
// LED #7: 0xc0220130, offset 0x44

// For capt_seq.c
DEF(_nrflag,0x96e0) // Found @ ff94921c (0x96e4) & ff949238 (-0x04)
//static long *nrflag = (long*)(0x96e4-0x04);  // Found @ ff94921c & ff949234

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NHSTUB(AllocateUncacheableMemory              ,0xff828800) //112
NHSTUB(Close                                  ,0xff824088) //120
NHSTUB(CreateBinarySemaphore                  ,0xff827fe0) //115
NHSTUB(CreateTask                             ,0xff81aef4) //120
NHSTUB(DebugAssert                            ,0xff81b1cc) //107
NHSTUB(DeleteDirectory_Fut                    ,0xff823a18) //116
NHSTUB(DeleteFile_Fut                         ,0xff823934) //112
NHSTUB(DoAELock                               ,0xff8261b4) //120
NHSTUB(DoAFLock                               ,0xff825e48) //120
NHSTUB(EnterToCompensationEVF                 ,0xff826110) //104
NHSTUB(ExecuteEventProcedure                  ,0xff873ae4) //104
NHSTUB(ExitFromCompensationEVF                ,0xff826154) //104
NHSTUB(ExitTask                               ,0xff81b184) //120
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff831950) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff831a94) //104
NHSTUB(Fclose_Fut                             ,0xff823ab0) //120
NHSTUB(Feof_Fut                               ,0xff823c9c) //  1
NHSTUB(Fflush_Fut                             ,0xff823cd8) //  1
NHSTUB(Fgets_Fut                              ,0xff823c04) //  1
NHSTUB(Fopen_Fut                              ,0xff823a70) //120
NHSTUB(Fread_Fut                              ,0xff823b5c) //120
NHSTUB(FreeUncacheableMemory                  ,0xff828840) //112
NHSTUB(Fseek_Fut                              ,0xff823c50) //120
NHSTUB(Fwrite_Fut                             ,0xff823bb0) //120
NHSTUB(GetBatteryTemperature                  ,0xff84dc90) //102
NHSTUB(GetCCDTemperature                      ,0xff84dc20) //102
NHSTUB(GetCurrentAvValue                      ,0xff93b378) //120
NHSTUB(GetCurrentShutterSpeed                 ,0xff89a7b4) //120
NHSTUB(GetUsableMaxAv                         ,0xffacf524) //120
NHSTUB(GetUsableMinAv                         ,0xffacf50c) //120
NHSTUB(GetDrive_ClusterSize                   ,0xff859f90) //  1
NHSTUB(GetDrive_FreeClusters                  ,0xff859ff8) //  1
NHSTUB(GetDrive_TotalClusters                 ,0xff859fc4) //  1
NHSTUB(GetFocusLensSubjectDistance            ,0xff939848) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff939c30) //  3
NHSTUB(GetKbdState                            ,0xff84afbc) //109
NHSTUB(GetMemInfo                             ,0xff813c24) //115
NHSTUB(GetOpticalTemperature                  ,0xff84dd00) //120
NHSTUB(GetParameterData                       ,0xff971c10) //101
NHSTUB(GetPropertyCase                        ,0xff8777cc) //102
NHSTUB(GetSystemTime                          ,0xffa688c4) //120
NHSTUB(GetVRAMHPixelsSize                     ,0xff83ce54) //120
NHSTUB(GetVRAMVPixelsSize                     ,0xff83ce60) //120
NHSTUB(GetZoomLensCurrentPoint                ,0xff93e7c8) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xffa5dcb8) //102
NHSTUB(GiveSemaphore                          ,0xff82821c) //120
NHSTUB(IsStrobeChargeCompleted                ,0xff8b4794) //102
NHSTUB(LEDDrive                               ,0xff84a53c) //120
NHSTUB(LocalTime                              ,0xff871280) //115
NHSTUB(LockMainPower                          ,0xff87ef28) //120
NHSTUB(MakeDirectory_Fut                      ,0xff8239a8) //116
NHSTUB(MoveFocusLensToDistance                ,0xffad17b8) //102
NHSTUB(MoveIrisWithAv                         ,0xffa65290) //120
NHSTUB(MoveZoomLensWithPoint                  ,0xffa659a8) //120
NHSTUB(MoveOpticalZoomAt                      ,0xff825694) //109
NHSTUB(Open                                   ,0xff824060) //120
NHSTUB(PB2Rec                                 ,0xff8822ec) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff864344) //120
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff86431c) //120
NHSTUB(PT_PlaySound                           ,0xff863c98) //102
NHSTUB(PostLogicalEventForNotPowerType        ,0xff87ccec) //120
NHSTUB(PostLogicalEventToUI                   ,0xff87cd38) //120
NHSTUB(PutInNdFilter                          ,0xffa6580c) //102
NHSTUB(PutOutNdFilter                         ,0xffa65830) //102
NHSTUB(Read                                   ,0xff819a4c) //120
NHSTUB(ReadFastDir                            ,0xffa4a194) //  1
NHSTUB(Rec2PB                                 ,0xff880c28) //104
//NHSTUB(RefreshPhysicalScreen                ,0xff9dae58) //104            == 0xff9dae58
NHSTUB(RenameFile_Fut                         ,0xff8238e0) //  1
NHSTUB(Restart                                ,0xff82a074) //122
NHSTUB(SetAE_ShutterSpeed                     ,0xffad3f88) //102
NHSTUB(SetAutoShutdownTime                    ,0xff87ef9c) //120
NHSTUB(SetCurrentCaptureModeType              ,0xff885d94) //120
NHSTUB(SetDate                                ,0xffad59d4) //120
NHSTUB(SetFileAttributes                      ,0xff8243b4) //  1
NHSTUB(SetFileTimeStamp                       ,0xff824364) //  1
NHSTUB(SetLogicalEventActive                  ,0xff87ec78) //120
NHSTUB(SetParameterData                       ,0xff971aec) //101
NHSTUB(SetPropertyCase                        ,0xff8776c4) //102
NHSTUB(SetScriptMode                          ,0xff87ecc8) //120
NHSTUB(SleepTask                              ,0xff828484) //120
NHSTUB(TakeSemaphore                          ,0xff82814c) //120
NHSTUB(TurnOffBackLight                       ,0xff88c57c) //104
NHSTUB(TurnOnBackLight                        ,0xff88c564) //104
NHSTUB(TurnOnDisplay                          ,0xff846b14) //120
NHSTUB(TurnOffDisplay                         ,0xff846b24) //120
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff95fddc) //120
NHSTUB(UnlockAE                               ,0xff8261d8) //120
NHSTUB(UnlockAF                               ,0xff825e9c) //120
NHSTUB(UnlockMainPower                        ,0xff87ee7c) //120
NHSTUB(UnsetZoomForMovie                      ,0xff977ed4) //104
NHSTUB(UpdateMBROnFlash                       ,0xff859dd0) //105
NHSTUB(VbattGet                               ,0xff820574) //120
NHSTUB(Write                                  ,0xff824134) //120
NHSTUB(WriteSDCard                            ,0xff92a7c0) //108
NHSTUB(_log                                   ,0xffb068c8) //111
NHSTUB(_log10                                 ,0xffb05554) //112
NHSTUB(_pow                                   ,0xffb056c4) //121
NHSTUB(_sqrt                                  ,0xffb08524) //  1
NHSTUB(add_ptp_handler                        ,0xffa15950) //121
NHSTUB(apex2us                                ,0xff9dc33c) //121
NHSTUB(close                                  ,0xff819864) //109
NHSTUB(err_init_task                          ,0xff814e80) //111
NHSTUB(exmem_alloc                            ,0xff8721c0) //103
NHSTUB(exmem_ualloc                           ,0xff872014) //103
NHSTUB(exmem_ufree                            ,0xff872160) //103
NHSTUB(free                                   ,0xff813a7c) //112
NHSTUB(get_nd_value                           ,0xffa5b89c) //122
NHSTUB(get_current_nd_value                   ,0xffa5b858) //122
NHSTUB(kbd_p1_f                               ,0xff821d24) //109
NHSTUB(kbd_p1_f_cont                          ,0xff821d30) //109
NHSTUB(kbd_p2_f                               ,0xff82153c) //109
NHSTUB(kbd_read_keys                          ,0xff821c28) //109
NHSTUB(kbd_read_keys_r2                       ,0xff84a99c) //109
NHSTUB(lseek                                  ,0xff8241c8) //120
NHSTUB(malloc                                 ,0xff8139a8) //112
NHSTUB(memcmp                                 ,0xff81cbb0) //120
NHSTUB(memcpy                                 ,0xff899344) //120
NHSTUB(memset                                 ,0xff9db1ac) //120
NHSTUB(mkdir                                  ,0xff82442c) //109
NHSTUB(mktime_ext                             ,0xff899bb0) //  1
NHSTUB(open                                   ,0xff8197b4) //109
NHSTUB(OpenFastDir                            ,0xffa4a100) //  1
NHSTUB(closedir                               ,0xffa4a264) //  1
NHSTUB(qsort                                  ,0xff9db6b4) //  1
NHSTUB(rand                                   ,0xff81ccb8) //121
NHSTUB(realloc                                ,0xff813b5c) //115
NHSTUB(reboot_fw_update                       ,0xffa51b94) //106
NHSTUB(set_control_event                      ,0xff87e8dc) //111
NHSTUB(srand                                  ,0xff81ccac) //122
NHSTUB(stat                                   ,0xff824294) //  1
NHSTUB(strcat                                 ,0xff899158) //  1
NHSTUB(strchr                                 ,0xff8991e0) //  1
NHSTUB(strcmp                                 ,0xff81cb48) //120
NHSTUB(strcpy                                 ,0xff81cb30) //120
NHSTUB(strftime                               ,0xff8995b8) //  1
NHSTUB(strlen                                 ,0xff81cb8c) //120
NHSTUB(strncmp                                ,0xff899194) //  1
NHSTUB(strncpy                                ,0xff82e2bc) //  1
NHSTUB(strrchr                                ,0xff9db184) //  1
NHSTUB(strtol                                 ,0xff82e4f4) //101
NHSTUB(strtolx                                ,0xff82e2f8) //109
   DEF(task_CaptSeq                           ,0xff866bfc) //120
   DEF(task_DvlpSeqTask                       ,0xff949fd4) //120
   DEF(task_ExpDrv                            ,0xff8ab0e0) //120
   DEF(task_FileWrite                         ,0xffa46a18) //120
   DEF(task_InitFileModules                   ,0xff882ea8) //120
   DEF(task_MovieRecord                       ,0xff862c0c) //120
   DEF(task_PhySw                             ,0xff821898) //120
   DEF(task_RotaryEncoder                     ,0xff84b23c) //120
NHSTUB(time                                   ,0xff871860) //109
NHSTUB(vsprintf                               ,0xff81caf4) //115
NHSTUB(EngDrvRead                             ,0xff822b64) //102
NHSTUB(PTM_GetCurrentItem                     ,0xff87f864) //105
NHSTUB(CancelHPTimer                          ,0xff873020) //119
NHSTUB(SetHPTimerAfterNow                     ,0xff872f18) //119
NHSTUB(PT_MFOn                                ,0xff8643bc) //120
NHSTUB(PT_MFOff                               ,0xff8643cc) //120
NHSTUB(GetAdChValue                           ,0xff8486cc) //120
NHSTUB(get_ptp_buf_size                       ,0xff8d4d34) //122
NHSTUB(get_ptp_file_buf                       ,0xffa172d4) //121
NHSTUB(SetVideoOutType                        ,0xffad4774) //109
NHSTUB(GetVideoOutType                        ,0xffad46d8) //120
