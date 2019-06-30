// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   Firmware Ver GM1.00C   // Found @ 0xffc07c68, "GM1.00C" @ 0xffc07c75
//   Firmware build timestamp: Dec  4 2006 07:46:45
//   Canon PowerShot A550

// Values for makefile.inc
//   PLATFORMID = 12624 (0x3150) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x01ffffff
//   MEMISOSTART = 0x0009f2b0

// Detected address ranges:
// ROM      0xffc00000 - 0xffffffff (4194304 bytes)
// RAM data 0x00001900 - 0x0000ce40 copied from 0xffeeb4d0 (  46400 bytes)

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
NHSTUB(EnterToCompensationEVF                 ,0xffe6b9b0) //  3 96%
NHSTUB(FreeUncacheableMemory                  ,0xffc0e104) //  1 90%
NHSTUB(GetFocusLensSubjectDistance            ,0xffe43b08) //  1 83%
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xffe4400c) //  2 92%
NHSTUB(GetParameterData                       ,0xffea7dc8) //  1 86%
NHSTUB(GetPropertyCase                        ,0xffc0b7c4) //  2 89%
NHSTUB(GetSystemTime                          ,0xffc033c0) //  1 96%
NHSTUB(PutInNdFilter                          ,0xffde2d88) //  1 92%
NHSTUB(PutOutNdFilter                         ,0xffde2dd0) //  1 94%
NHSTUB(Restart                                ,0xffc0b278) //  1 96%
NHSTUB(SetParameterData                       ,0xffea7ce8) //  1 86%
NHSTUB(SetPropertyCase                        ,0xffc0b68c) //  3 96%
NHSTUB(UnsetZoomForMovie                      ,0xffc227d4) //  1 89%
//NHSTUB(WriteSDCard                          ,0xffe3437c) //  3 74%    *** != 0xffe34524
NHSTUB(add_ptp_handler                        ,0xffd7dff8) //  1 96%
// ERROR: free is not found.                               //--- ---    *** != 0xffcc8154
NHSTUB(kbd_p2_f                               ,0xffdca148) //  1 56%
//NHSTUB(kbd_read_keys_r2                     ,0xffdcb3a0) //  3 58%    *** != 0xffdcb384
NHSTUB(malloc                                 ,0xffcc8148) //  1 53%
NHSTUB(mkdir                                  ,0xffe22408) //  1 51%
// ALT: NHSTUB(mkdir, 0xffe224dc) // 1 16/15
NHSTUB(taskIdListGet                          ,0xffcd2290) //  1 82%
NHSTUB(utime                                  ,0xffebdeac) //  1 57%
NHSTUB(localtime                              ,0xffcc0f60) //  1 93%
NHSTUB(Mount_FileSystem                       ,0xffe214c4) //  3 93%
NHSTUB(MakeAFScan                             ,0xffe708d4) //  2 86%

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ffea9f04 -> ffea9f04
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(levent_table                            ,0xffe9d378) // Found @0xffe9d378
DEF(FlashParamsTable                        ,0xffeac254) // Found @0xffeac254
DEF(fileio_semaphore                        ,0x00008e24) // Found @0xffe24864
DEF(exmem_alloc_table                       ,0x00001e14) // Found @0xffc0d4c8
DEF(exmem_types_table                       ,0xffc0d2e8) // Found @0xffc0d2e8
DEF_CONST(exmem_type_count                  ,0x00000011)
DEF(imager_active                           ,0x00005d58) // Found @0xffd474b0 (0x5d58 + 0)
DEF_CONST(uiprop_count                      ,0x0000005d) // Found @0xffea6ec8

// Values below go in 'lib.c':
//int get_flash_params_count(void) { return 0x6f; }                          // Found @0xffea7e34

// Values below go in 'platform_camera.h':
//#define PARAM_CAMERA_NAME 4 // Found @0xffeab9e4

// Misc stuff

// EXMEM types:
// EXMEM_RAMDISK   0
// EXMEM_COM       1
// EXMEM_COMTMP    2
// EXMEM_FORMATTER 3
// EXMEM_SHADING   4
// EXMEM_FAMODE    5
// EXMEM_FIRMUP    6
// EXMEM_DVLPWORK  7
// EXMEM_EVF       8
// EXMEM_SCRIPT    9
// EXMEM_FILESTORE 10
// EXMEM_MOVIE_REC 11
// EXMEM_MOVIE_PLY 12
// EXMEM_WIDE      13
// EXMEM_NARROW    14
// EXMEM_CRAW_REC  15
// EXMEM_PCEVF     16

// LED table init @ 0xffdc9a58
// LED #1: 0xc022008c, offset 0x4
// LED #2: 0xc0220088, offset 0x44
// LED #3: 0xc0220090, offset 0x84
// LED #4: 0xc0220084, offset 0x204
// LED #5: 0xc0220080, offset 0x244

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NHSTUB(AllocateUncacheableMemory              ,0xffc0e0d0) //  1
NHSTUB(Close                                  ,0xffe221a0) //120
NHSTUB(CreateBinarySemaphore                  ,0xffe831e8) //115
NHSTUB(CreateTask                             ,0xffe83c00) //120
NHSTUB(DebugAssert                            ,0xffe8fb40) //1100
NHSTUB(DeleteFile_Fut                         ,0xffe1d778) //  1
NHSTUB(DoAELock                               ,0xffe6bb3c) //120
NHSTUB(DoAFLock                               ,0xffe6b77c) //120
NHSTUB(ExecuteEventProcedure                  ,0xffc04698) //  1
NHSTUB(ExitFromCompensationEVF                ,0xffe6ba34) //  3
NHSTUB(ExitTask                               ,0xffe83fc0) //120
NHSTUB(Fclose_Fut                             ,0xffe1d8ec) //120
NHSTUB(Feof_Fut                               ,0xffe1dae8) //  3
NHSTUB(Fflush_Fut                             ,0xffe1db24) //  3
NHSTUB(Fgets_Fut                              ,0xffe1da50) //  3
NHSTUB(Fopen_Fut                              ,0xffe1d8ac) //120
NHSTUB(Fread_Fut                              ,0xffe1d9a8) //120
NHSTUB(Fseek_Fut                              ,0xffe1da9c) //120
NHSTUB(Fwrite_Fut                             ,0xffe1d9fc) //120
NHSTUB(GetBatteryTemperature                  ,0xffdce750) //102
NHSTUB(GetCCDTemperature                      ,0xffdce73c) //102
NHSTUB(GetCurrentAvValue                      ,0xffde2ba4) //120
NHSTUB(GetCurrentShutterSpeed                 ,0xffde2860) //120
NHSTUB(GetDrive_ClusterSize                   ,0xffe2198c) //119
NHSTUB(GetDrive_FreeClusters                  ,0xffe21a04) //1103
NHSTUB(GetDrive_TotalClusters                 ,0xffe219c8) //119
NHSTUB(GetOpticalTemperature                  ,0xffdce728) //120
NHSTUB(GetZoomLensCurrentPoint                ,0xffe55a40) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xffe55a54) //102
NHSTUB(GiveSemaphore                          ,0xffe837cc) //120
NHSTUB(IsStrobeChargeCompleted                ,0xffd4269c) //  2
NHSTUB(LEDDrive                               ,0xffdc966c) //120
NHSTUB(LocalTime                              ,0xffe90454) //115
NHSTUB(LockMainPower                          ,0xffea4ccc) //120
NHSTUB(MakeDirectory_Fut                      ,0xffe1d82c) //  3
NHSTUB(MoveFocusLensToDistance                ,0xffde51b4) //102
NHSTUB(MoveIrisWithAv                         ,0xffe4a6b4) //120
NHSTUB(MoveZoomLensWithPoint                  ,0xffe55918) //120
NHSTUB(Open                                   ,0xffe22178) //120
NHSTUB(PT_MoveDigitalZoomToWide               ,0xffe7b5f4) //120
NHSTUB(PT_MoveOpticalZoomAt                   ,0xffe7b5b8) //120
NHSTUB(PT_PlaySound                           ,0xffe7b0b8) //  3
NHSTUB(PostLogicalEventForNotPowerType        ,0xffea08e4) //120
NHSTUB(PostLogicalEventToUI                   ,0xffea0960) //120
NHSTUB(Read                                   ,0xffe22234) //120
NHSTUB(RefreshPhysicalScreen                  ,0xffcb4b74) //120
NHSTUB(RenameFile_Fut                         ,0xffe1d6d0) //  3
NHSTUB(SetAE_ShutterSpeed                     ,0xffde82b4) //102
NHSTUB(SetAutoShutdownTime                    ,0xffea4bd0) //120
NHSTUB(SetCurrentCaptureModeType              ,0xffc17ec4) //120
NHSTUB(SetFileAttributes                      ,0xffe22388) //  3
NHSTUB(SetLogicalEventActive                  ,0xffea27dc) //1104
NHSTUB(SetScriptMode                          ,0xffea2844) //120
NHSTUB(SleepTask                              ,0xffe83b14) //120
NHSTUB(TakeSemaphore                          ,0xffe835c4) //1101
NHSTUB(TurnOffBackLight                       ,0xffc2ee94) //  2
NHSTUB(TurnOnBackLight                        ,0xffc2ee64) //  2
NHSTUB(TurnOnDisplay                          ,0xffdbf72c) //120
NHSTUB(TurnOffDisplay                         ,0xffdbf73c) //120
NHSTUB(UnlockAE                               ,0xffe6bb8c) //120
NHSTUB(UnlockAF                               ,0xffe6b7fc) //120
NHSTUB(UnlockMainPower                        ,0xffea4d64) //120
NHSTUB(UpdateMBROnFlash                       ,0xffe216c0) //  1
NHSTUB(VbattGet                               ,0xffdc78f4) //120
NHSTUB(Write                                  ,0xffe22240) //120
NHSTUB(_log                                   ,0xffebc690) //121
NHSTUB(_log10                                 ,0xffebbb10) //121
NHSTUB(_pow                                   ,0xffcb8ab8) //121
NHSTUB(_sqrt                                  ,0xffcba840) //  1
NHSTUB(apex2us                                ,0xffcd95d0) //  1
NHSTUB(close                                  ,0xffcc5108) //109
NHSTUB(exmem_alloc                            ,0xffc0dfac) //102
NHSTUB(exmem_free                             ,0xffc0e02c) //102
NHSTUB(get_nd_value                           ,0xffe4eb68) //115
NHSTUB(get_current_nd_value                   ,0xffe4eb54) //122
NHSTUB(kbd_p1_f                               ,0xffdc9d18) //  1
NHSTUB(kbd_p1_f_cont                          ,0xffdc9d24) //109
NHSTUB(kbd_pwr_off                            ,0xffdcb968) //  1
// ALT: NHSTUB(kbd_pwr_off, 0xffdcb998) // 1 6/0
// ALT: NHSTUB(kbd_pwr_off, 0xffdcb9b4) // 1 6/0
NHSTUB(kbd_pwr_on                             ,0xffdcb940) //  1
NHSTUB(lseek                                  ,0xffcc524c) //  1
NHSTUB(memcmp                                 ,0xffcc0340) //120
NHSTUB(memcpy                                 ,0xffcc037c) //120
NHSTUB(memset                                 ,0xffcc03f4) //120
NHSTUB(open                                   ,0xffcc574c) //109
NHSTUB(closedir                               ,0xffebdd50) //  1
NHSTUB(qsort                                  ,0xffcbfba0) //  1
NHSTUB(rand                                   ,0xffcbfbc4) //  1
NHSTUB(realloc                                ,0xffe8f74c) //115
NHSTUB(srand                                  ,0xffcbfbe8) //  1
NHSTUB(stat                                   ,0xffebde18) //  1
NHSTUB(strcat                                 ,0xffcc0414) //  1
NHSTUB(strchr                                 ,0xffcc0440) //  1
NHSTUB(strcmp                                 ,0xffcc0464) //120
NHSTUB(strcpy                                 ,0xffcc05f8) //120
NHSTUB(strftime                               ,0xffcc1c80) //  1
NHSTUB(strlen                                 ,0xffcc075c) //120
NHSTUB(strncmp                                ,0xffcc07c0) //  1
NHSTUB(strncpy                                ,0xffcc0804) //  1
NHSTUB(strrchr                                ,0xffcc0888) //  1
NHSTUB(strtol                                 ,0xffcbffdc) //  1
NHSTUB(isdigit                                ,0xffcbc710) //  1
NHSTUB(isspace                                ,0xffcbc788) //  1
NHSTUB(isalpha                                ,0xffcbc6e0) //  1
NHSTUB(isupper                                ,0xffcbc7a0) //  1
NHSTUB(islower                                ,0xffcbc740) //  1
NHSTUB(ispunct                                ,0xffcbc770) //  1
NHSTUB(isxdigit                               ,0xffcbc7b8) //  1
NHSTUB(toupper                                ,0xffcbc7e0) //  1
NHSTUB(tolower                                ,0xffcbc7d0) //  1
NHSTUB(taskLock                               ,0xffcd294c) //  1
NHSTUB(taskUnlock                             ,0xffcd29f4) //  1
NHSTUB(taskName                               ,0xffcd2188) //  1
NHSTUB(errnoOfTaskGet                         ,0xffcc2d5c) //  1
NHSTUB(readdir                                ,0xffebdd1c) //  1
NHSTUB(strtoul                                ,0xffcc0184) //  1
NHSTUB(strpbrk                                ,0xffcc084c) //  1
NHSTUB(mktime                                 ,0xffcc1128) //  1
NHSTUB(opendir                                ,0xffebdd84) //  1
NHSTUB(memchr                                 ,0xffcc030c) //  1
NHSTUB(memPartInfoGet                         ,0xffcc8568) //  1
NHSTUB(iosDrvInstall                          ,0xffcc65ec) //  1
NHSTUB(iosDevAdd                              ,0xffcc6328) //  1
NHSTUB(iosDevDelete                           ,0xffcc6300) //  1
NHSTUB(GetCurrentTargetDistance               ,0xffde4f1c) //  1
NHSTUB(taskCreateHookAdd                      ,0xffccada8) //  1
NHSTUB(taskDeleteHookAdd                      ,0xffccace4) //  1
NHSTUB(Unmount_FileSystem                     ,0xffe2156c) //  1
NHSTUB(taskSuspend                            ,0xffcd2398) //  1
NHSTUB(taskResume                             ,0xffcd256c) //  1
NHSTUB(time                                   ,0xffcc1cac) //  1
NHSTUB(vsprintf                               ,0xffcc3eb0) //115
NHSTUB(EngDrvRead                             ,0xffdd4054) //102
NHSTUB(PTM_GetCurrentItem                     ,0xffea5bc4) //102
NHSTUB(CancelHPTimer                          ,0xffc04284) //119
NHSTUB(SetHPTimerAfterNow                     ,0xffc03e10) //119
NHSTUB(MFOn                                   ,0xffe7bf9c) //120
NHSTUB(MFOff                                  ,0xffe7bfac) //120
NHSTUB(GetAdChValue                           ,0xffdc4b7c) //120
NHSTUB(get_ptp_buf_size                       ,0xffd73700) //122
NHSTUB(get_ptp_file_buf                       ,0xffd8b8a4) //121
