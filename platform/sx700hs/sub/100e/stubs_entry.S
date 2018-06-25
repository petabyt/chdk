// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   Main firmware start: 0xfc020000
//   DRYOS R54 (DRYOS version 2.3, release #0054+p3)
//   Firmware Ver GM1.00E   // Found @ 0xfc1366bc, "GM1.00E" @ 0xfc1366c9

// Values for makefile.inc
//   PLATFORMOSVER = 54
//   MEMISOSTART = 0x35bb28
//   MEMBASEADDR = 0x8000
//   ARAM_HEAP_START = 0x006ce000 #  Found @0xfc1bc880
//   ARAM_HEAP_SIZE = 0x00022000 #  Found @0xfc1bc85a

// Detected address ranges:
// ROM      0xfc000000 - 0xfe000000 (33554432 bytes)
// RAM code 0x010c1000 - 0x010df808 copied from 0xfcc64c5c ( 124936 bytes)
// RAM data 0x00008000 - 0x0002efdc copied from 0xfcc3dc80 ( 159708 bytes)

// Zico Xtensa blobs:
// zico_0 0xbff20000 - 0xbff27398 copied from 0xfca30bec (  29592 bytes)
// zico_1 0xbff00000 - 0xbff04a70 copied from 0xfca37f8c (  19056 bytes)
// zico_2 0x80a00000 - 0x80b09020 copied from 0xfca3ca04 (1085472 bytes)

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xfc148c98

// physw_event_table 0xfc5693dc Found @0xfc06e124
// Values below go in 'platform_kbd.h':
//#define SD_READONLY_FLAG    0x20000000 // Found @0xfc569464, levent 0x20a
//#define SD_READONLY_IDX     1
//#define USB_MASK            0x10000000 // Found @0xfc5694e4, levent 0x202
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x04000000 // Found @0xfc5694dc, levent 0x205
//#define BATTCOVER_IDX       2
//#define ANALOG_AV_FLAG      0x00008000 // Found @0xfc56944c, levent 0x200 (non-inverted logic)
//#define ANALOG_AV_IDX       1

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
// WARNING: Values only verified on sx280hs (R52) and g7x (R55p6) errors likely on other cams!
//KeyMap keymap[] = {
//    { 0, KEY_POWER           ,0x00000001 }, // Found @0xfc5693dc, levent 0x100
//    { 0, KEY_PLAYBACK        ,0x00000002 }, // Found @0xfc5693e4, levent 0x101
//    { 0, KEY_SHOOT_FULL      ,0x0000000c }, // Found @0xfc5693f4, levent 0x01
//    { 0, KEY_SHOOT_FULL_ONLY ,0x00000008 }, // Found @0xfc5693f4, levent 0x01
//    { 0, KEY_SHOOT_HALF      ,0x00000004 }, // Found @0xfc5693ec, levent 0x00
//    { 0, KEY_VIDEO           ,0x00000100 }, // Found @0xfc5693fc, levent 0x02
//    { 0, KEY_MENU            ,0x00000200 }, // Found @0xfc569404, levent 0x0e
//    { 0, KEY_HELP            ,0x00002000 }, // Found @0xfc56940c, levent 0x0d
//    { 0, KEY_UP              ,0x00004000 }, // Found @0xfc569414, levent 0x06
//    { 0, KEY_DOWN            ,0x00008000 }, // Found @0xfc56941c, levent 0x07
//    { 0, KEY_RIGHT           ,0x00010000 }, // Found @0xfc569424, levent 0x09
//    { 1, KEY_LEFT            ,0x00000004 }, // Found @0xfc56942c, levent 0x08
//    { 1, KEY_SET             ,0x00000008 }, // Found @0xfc569434, levent 0x0a
//    { 0, 0, 0 }
//};

// canon_mode_list 0xfc867474 Found @0xfc3761bc
// Check modemap values from 'platform/CAMERA/shooting.c':
// 33335  0x8237 In firmware but not in current modemap
// 32832  0x8040 In firmware but not in current modemap
// 16943  0x422f In firmware but not in current modemap
// 16945  0x4231 In firmware but not in current modemap
// 33295  0x820f In firmware but not in current modemap

// Values below can be overridden in 'stubs_min.S':
DEF(ctypes                            ,0xfc5149c8)
DEF(physw_run                         ,0x000082c8) // Found @0xfc07a0be
DEF(physw_sleep_delay                 ,0x000082d0) // (0x82c8+0x8) Found @0xfc07a0c2
DEF(physw_status                      ,0x000308b0) // Found @0xfc07a3bc
DEF(fileio_semaphore                  ,0x00013264) // Found @0xfc06c076
DEF(levent_table                      ,0xfc635680) // Found @0xfc0bb1bc
DEF(FlashParamsTable                  ,0xfc86772c) // Found @0xfc3761d0
DEF(playrec_mode                      ,0x0000bbb4) // (0xbbb0+0x4) Found @0xfc2b719a
DEF(jpeg_count_str                    ,0x00157130) // Found @0xfc1f5a7a
DEF(zoom_busy                         ,0x0000b88c) // (0xb86c+0x20) Found @0xfc12a982
DEF(focus_busy                        ,0x00013448) // (0x13440+0x8) Found @0xfc2dc05a
DEF(_nrflag                           ,0x0001b8e4) // (0x1b8e0+0x4) Found @0xfc3145f2
DEF(active_bitmap_buffer              ,0x0000c784) // (0xc754+0x30) Found @0xfc30d300
DEF_CONST(uiprop_count                      ,0x0000009d) // Found @0xfc0bb660

//NHSTUB(EnterToCompensationEVF               ,0x00000000) //  0        *** != 0xfc25c1a9
//NHSTUB(ExitFromCompensationEVF              ,0x00000000) //  0        *** != 0xfc254ce9
//NHSTUB(ExpCtrlTool_StartContiAE             ,0x00000000) //  0        *** != 0xfc24d359
//NHSTUB(ExpCtrlTool_StopContiAE              ,0x00000000) //  0        *** != 0xfc24d439
//NHSTUB(Feof_Fut                             ,0x00000000) //  0        *** != 0xfc2d7d95
//NHSTUB(Fflush_Fut                           ,0x00000000) //  0        *** != 0xfc2d7dbd
//NHSTUB(GetDrive_TotalClusters               ,0x00000000) //  0        *** != 0xfc307985
//NHSTUB(GetFocusLensSubjectDistanceFromLens  ,0x00000000) //  0        *** != 0xfc2dcf41
//NHSTUB(GetImageFolder                       ,0x00000000) //  0        *** != 0xfc2e07d9
//NHSTUB(MakeSDCardBootable                   ,0x00000000) //  0        *** != 0xfc307d93
//NHSTUB(RenameFile_Fut                       ,0x00000000) //  0        *** != 0xfc2d7b45
//NHSTUB(Restart                              ,0x00000000) //  0        *** != 0xfc0a6e95
//NHSTUB(SetFileAttributes                    ,0x00000000) //  0        *** != 0xfc308145
//NHSTUB(SetFileTimeStamp                     ,0x00000000) //  0        *** != 0xfc3080fd
//NHSTUB(SetParameterData                     ,0x00000000) //  0        *** != 0xfc0bbdd7
//NHSTUB(WriteSDCard                          ,0x00000000) //  0        *** != 0xfc0e851d
//NHSTUB(apex2us                              ,0x00000000) //  0        *** != 0xfc313637
//NHSTUB(reboot_fw_update                     ,0x00000000) //  0        *** != 0xfc370b89
//NHSTUB(CancelHPTimer                        ,0x00000000) //  0        *** != 0xfc1360f5

NHSTUB(AllocateUncacheableMemory              ,0xfc148c69) //  0
NHSTUB(Close                                  ,0xfc307eb1) //  0
NHSTUB(CreateBinarySemaphore                  ,0x010c5919) //  0
NHSTUB(CreateTask                             ,0x010c5075) //  0
NHSTUB(DebugAssert                            ,0x010c5c6d) //  0
NHSTUB(DeleteDirectory_Fut                    ,0xfc2d7bf1) //  0
NHSTUB(DeleteFile_Fut                         ,0xfc2d7ba7) //  0
NHSTUB(DoAELock                               ,0xfc25c231) //  0
NHSTUB(DoAFLock                               ,0xfc25bebf) //  0
NHSTUB2(ExecuteEventProcedure                  ,0xfc2ddb69) //  0
NHSTUB(ExitTask                               ,0x010c5249) //  0
NHSTUB(Fclose_Fut                             ,0xfc2d7c53) //  0
NHSTUB(Fgets_Fut                              ,0xfc2d7d31) //  0
NHSTUB(Fopen_Fut                              ,0xfc2d7c2b) //  0
NHSTUB(Fread_Fut                              ,0xfc2d7cc5) //  0
NHSTUB(FreeUncacheableMemory                  ,0xfc148c95) //  0
NHSTUB(Fseek_Fut                              ,0xfc2d7d63) //  0
NHSTUB(Fwrite_Fut                             ,0xfc2d7cfb) //  0
NHSTUB(GetBatteryTemperature                  ,0xfc12452d) //  0
NHSTUB(GetCCDTemperature                      ,0xfc1244d1) //  0
NHSTUB(GetCurrentAvValue                      ,0xfc12a525) //  0
NHSTUB(GetUsableMaxAv                         ,0xfc1a2c7b) //  0
NHSTUB(GetUsableMinAv                         ,0xfc1a2c69) //  0
NHSTUB(GetDrive_ClusterSize                   ,0xfc30747b) //  0
NHSTUB(GetDrive_FreeClusters                  ,0xfc3079a9) //  0
NHSTUB(GetFocusLensSubjectDistance            ,0xfc2dcc47) //  0
NHSTUB(GetKbdState                            ,0xfc06e207) //  0
NHSTUB(GetMemInfo                             ,0xfc3d4cdd) //  0
NHSTUB(GetOpticalTemperature                  ,0xfc124587) //  0
NHSTUB(GetParameterData                       ,0xfc0bbe57) //  0
NHSTUB(GetPropertyCase                        ,0xfc2ef51d) //  0
NHSTUB(GetSystemTime                          ,0xfc40e739) //  0
NHSTUB(GetVRAMHPixelsSize                     ,0xfc12006d) //  0
NHSTUB(GetVRAMVPixelsSize                     ,0xfc120075) //  0
NHSTUB(GetZoomLensCurrentPoint                ,0xfc12abcd) //  0
NHSTUB(GetZoomLensCurrentPosition             ,0xfc12ab61) //  0
NHSTUB(GiveSemaphore                          ,0x010c5a85) //  0
NHSTUB(IsStrobeChargeCompleted                ,0xfc16c6a3) //  0
NHSTUB(LEDDrive                               ,0xfc1b6911) //  0
NHSTUB(LocalTime                              ,0x010c6281) //  0
NHSTUB(LockMainPower                          ,0xfc136c6f) //  0
NHSTUB(MakeDirectory_Fut                      ,0xfc30819b) //  0
NHSTUB(MoveFocusLensToDistance                ,0xfc45d257) //  0
NHSTUB(MoveIrisWithAv                         ,0xfc40cb75) //  0
NHSTUB(MoveZoomLensWithPoint                  ,0xfc40d325) //  0
NHSTUB(Open                                   ,0xfc307e2d) //  0
NHSTUB(PB2Rec                                 ,0xfc0cd749) //  0
NHSTUB(PT_MoveDigitalZoomToWide               ,0xfc25b817) //  0
NHSTUB(PT_MoveOpticalZoomAt                   ,0xfc1b7795) //  0
NHSTUB(PT_PlaySound                           ,0xfc13a0f9) //  0
NHSTUB(PostLogicalEventForNotPowerType        ,0xfc305e69) //  0
NHSTUB(PostLogicalEventToUI                   ,0xfc305e95) //  0
NHSTUB(PutInNdFilter                          ,0xfc45d539) //  0
NHSTUB(PutOutNdFilter                         ,0xfc45d55f) //  0
NHSTUB(Read                                   ,0xfc119b79) //  0
NHSTUB(ReadFastDir                            ,0xfc0faf71) //  0
NHSTUB(Rec2PB                                 ,0xfc0cd787) //  0
//NHSTUB(RefreshPhysicalScreen                ,0x00000000) //  0            == 0x00000000
NHSTUB(ScreenLock                             ,0xfc30d24f) //  0
NHSTUB(ScreenUnlock                           ,0xfc30d28d) //  0
NHSTUB(SetAE_ShutterSpeed                     ,0xfc459d69) //  0
NHSTUB(SetAutoShutdownTime                    ,0xfc136cbb) //  0
NHSTUB(SetCurrentCaptureModeType              ,0xfc2de78d) //  0
NHSTUB(SetLogicalEventActive                  ,0xfc3068a7) //  0
NHSTUB(SetPropertyCase                        ,0xfc2ef3e7) //  0
NHSTUB(SetScriptMode                          ,0xfc3068df) //  0
NHSTUB(SleepTask                              ,0x010c4fdd) //  0
NHSTUB(TakeSemaphore                          ,0x010c5a0d) //  0
NHSTUB(TurnOffBackLight                       ,0xfc1212c3) //  0
NHSTUB(TurnOnBackLight                        ,0xfc121283) //  0
NHSTUB(TurnOnDisplay                          ,0xfc0e3a1d) //  0
NHSTUB(TurnOffDisplay                         ,0xfc0e3a2f) //  0
NHSTUB(UnlockAE                               ,0xfc25c24f) //  0
NHSTUB(UnlockAF                               ,0xfc25bee7) //  0
NHSTUB(UnlockMainPower                        ,0xfc136c0b) //  0
//NHSTUB(UnsetZoomForMovie                    ,0x00000000) //  0            == 0x00000000
NHSTUB(VbattGet                               ,0xfc11a537) //  0
NHSTUB(Write                                  ,0xfc307ee9) //  0
NHSTUB(_log                                   ,0x010daf58) //  0
NHSTUB(_log10                                 ,0x010db478) //  0
NHSTUB(_pow                                   ,0x010db5e0) //  0
NHSTUB(_sqrt                                  ,0x010dd660) //  0
NHSTUB(add_ptp_handler                        ,0xfc0b2aef) //  0
NHSTUB(close                                  ,0xfc119a73) //  0
NHSTUB(exmem_alloc                            ,0xfc06ebed) //  0
NHSTUB(exmem_free                             ,0xfc06ec2d) //  0
NHSTUB(free                                   ,0xfc30faf7) //  0
NHSTUB(kbd_p1_f                               ,0xfc07a3b5) //  0
NHSTUB(kbd_p1_f_cont                          ,0xfc07a3bd) //  0
NHSTUB(kbd_p2_f                               ,0xfc079e89) //  0
NHSTUB(kbd_read_keys                          ,0xfc07a37f) //  0
NHSTUB(kbd_read_keys_r2                       ,0xfc06e121) //  0
NHSTUB(lseek                                  ,0xfc30800d) //  0
NHSTUB(malloc                                 ,0xfc30fac1) //  0
NHSTUB(memcmp                                 ,0xfc30fb3b) //  0
NHSTUB(memcpy                                 ,0xfc0d91c1) //  0
NHSTUB(memset                                 ,0xfc1febc5) //  0
NHSTUB(mktime_ext                             ,0xfc3d695d) //  0
NHSTUB(open                                   ,0xfc119a03) //  0
NHSTUB(OpenFastDir                            ,0xfc0faed1) //  0
NHSTUB(closedir                               ,0xfc0fae99) //  0
NHSTUB(get_fstype                             ,0xfc307415) //  0
NHSTUB(qsort                                  ,0xfc3ed63d) //  0
NHSTUB(rand                                   ,0xfc1feba7) //  0
NHSTUB(set_control_event                      ,0xfc3065ed) //  0
NHSTUB(srand                                  ,0xfc1feba1) //  0
NHSTUB(stat                                   ,0xfc308045) //  0
NHSTUB(strcat                                 ,0xfc30f979) //  0
NHSTUB(strchr                                 ,0xfc13c83d) //  0
NHSTUB(strcmp                                 ,0xfc30f9e3) //  0
NHSTUB(strcpy                                 ,0xfc30f9bf) //  0
NHSTUB(strftime                               ,0xfc13c275) //  0
NHSTUB(strlen                                 ,0xfc30fa35) //  0
NHSTUB(strncmp                                ,0xfc13c813) //  0
NHSTUB(strncpy                                ,0xfc30f99b) //  0
NHSTUB(strrchr                                ,0xfc0d9255) //  0
NHSTUB(strtol                                 ,0xfc13c7db) //  0
NHSTUB(strtolx                                ,0xfc13c699) //  0
   DEF(task_CaptSeq                           ,0xfc12de09) //  0
   DEF(task_DvlpSeqTask                       ,0xfc1ba4f7) //  0
   DEF(task_ExpDrv                            ,0xfc276991) //  0
   DEF(task_FileWrite                         ,0xfc0640ad) //  0
   DEF(task_InitFileModules                   ,0xfc0aa0a1) //  0
   DEF(task_MovieRecord                       ,0xfc1b40e3) //  0
   DEF(task_PhySw                             ,0xfc07a0bd) //  0
   DEF(task_TricInitTask                      ,0xfc3c5ded) //  0
   DEF(hook_CreateTask                        ,0x010c5074) //  0
NHSTUB(time                                   ,0x010c5f21) //  0
NHSTUB(vsprintf                               ,0xfc0afa03) //  0
NHSTUB(EngDrvRead                             ,0xfc30f865) //  0
NHSTUB(PTM_GetCurrentItem                     ,0xfc30f5e5) //  0
NHSTUB(DisableISDriveError                    ,0xfc40d9b5) //  0
NHSTUB(SetHPTimerAfterNow                     ,0xfc13605d) //  0
NHSTUB(SetEventFlag                           ,0x010c547b) //  0
NHSTUB(transfer_src_overlay                   ,0xfc30c92d) //  0
NHSTUB(bzero                                  ,0x010d87a0) //  0
NHSTUB(memset32                               ,0x010d87a4) //  0
NHSTUB(PT_MFOn                                ,0xfc25d123) //  0
NHSTUB(PT_MFOff                               ,0xfc25d153) //  0
NHSTUB(GetAdChValue                           ,0xfc0cf693) //  0
NHSTUB(EnableHDMIPower                        ,0xfc0ab3c3) //  0
NHSTUB(DisableHDMIPower                       ,0xfc0ab3f9) //  0
