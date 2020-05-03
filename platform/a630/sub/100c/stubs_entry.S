// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   Firmware Ver GM1.00C   // Found @ 0xffc0a398, "GM1.00C" @ 0xffc0a3a5
//   Firmware build timestamp: Jul  4 2006 21:35:08
//   Canon PowerShot A630

// Values for makefile.inc
//   DIGIC = 20# DIGIC II
//   PLATFORMID = 12602# (0x313a) Found @ 0xfffe0130
//   MAXRAMADDR = 0x01ffffff
//   MEMISOSTART = 0x00094810

// Detected address ranges:
// ROM      0xffc00000 - 0xffffffff (4194304 bytes)
// RAM data 0x00001900 - 0x0000d540 copied from 0xfff06100 (  48192 bytes)

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
NHSTUB(EnterToCompensationEVF                 ,0xffd4fd90) //  2 96%
NHSTUB(GetFocusLensSubjectDistance            ,0xffe9b4fc) //  2 96%
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xffe9bab0) //  2 57%
NHSTUB(PutInNdFilter                          ,0xffea7484) //  1 92%
NHSTUB(PutOutNdFilter                         ,0xffea74cc) //  1 94%
NHSTUB(Restart                                ,0xffc12fd4) //  1 96%
NHSTUB(UnsetZoomForMovie                      ,0xffda1ce4) //  1 89%
NHSTUB(add_ptp_handler                        ,0xffe5291c) //  1 96%
// ERROR: free is not found.                               //--- ---    *** != 0xffef3284
NHSTUB(malloc                                 ,0xffef3278) //  1 53%
NHSTUB(taskIdListGet                          ,0xffeffea0) //  1 82%
NHSTUB(localtime                              ,0xffeebeb4) //  1 93%
NHSTUB(Mount_FileSystem                       ,0xffc60810) //  1 90%
NHSTUB(MakeAFScan                             ,0xffd54358) //  2 79%

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ffd682d0 -> ffd682d0
// Mode  8221 in firmware but not in current modemap

// Values below can be overridden in 'stubs_min.S':
//DEF(levent_table                            ,0xffd60ce4) // Found @0xffd60ce4,          stubs_min = 0xffd60ce4 (0xFFD60CE4)
//DEF(FlashParamsTable                        ,0xffd6aa78) // Found @0xffd6aa78,          stubs_min = 0xffd6aa78 (0xFFD6AA78)
DEF(fileio_semaphore                        ,0x0000273c) // Found @0xffc5ebb4
DEF(exmem_alloc_table                       ,0x00001bcc) // Found @0xffc01f28
DEF(exmem_types_table                       ,0xffc01d3c) // Found @0xffc01d3c
DEF_CONST(exmem_type_count                  ,0x0000000e)
DEF(imager_active                           ,0x000054e8) // Found @0xffcc40dc (0x54e8 + 0)
DEF_CONST(uiprop_count                      ,0x0000005b) // Found @0xffd6c6b4

// Values below go in 'lib.c':
//int get_flash_params_count(void) { return 0x6e; }                          // Found @0xffd6d8c0

// Values below go in 'platform_camera.h':
//#define PARAM_CAMERA_NAME 4 // Found @0xffd6a218

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
// EXMEM_FILESTORE 8
// EXMEM_MOVIE_REC 9
// EXMEM_MOVIE_PLY 10
// EXMEM_WIDE      11
// EXMEM_NARROW    12
// EXMEM_PCEVF     13

// LED table init @ 0xffc1e0e8
// LED #1: 0xc022008c, offset 0x4
// LED #2: 0xc0220088, offset 0x44
// LED #3: 0xc0220090, offset 0x84
// LED #4: 0xc0220094, offset 0xc4
// LED #5: 0xc0220084, offset 0x204
// LED #6: 0xc0220080, offset 0x244

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NHSTUB(AllocateUncacheableMemory              ,0xffc04b00) //  1
NHSTUB(Close                                  ,0xffc614e8) //120
NHSTUB(CreateBinarySemaphore                  ,0xffc1110c) //115
NHSTUB(CreateTask                             ,0xffc11abc) //120
NHSTUB(DebugAssert                            ,0xffc03cf8) //1100
NHSTUB(DeleteFile_Fut                         ,0xffc5a398) //  1
NHSTUB(DoAELock                               ,0xffd4fe30) //120
NHSTUB(DoAFLock                               ,0xffd4fc44) //120
NHSTUB(ExecuteEventProcedure                  ,0xffc0699c) //  1
NHSTUB(ExitFromCompensationEVF                ,0xffd5337c) //  2
NHSTUB(ExitTask                               ,0xffc11e7c) //120
NHSTUB(Fclose_Fut                             ,0xffc5a4d8) //120
NHSTUB(Feof_Fut                               ,0xffc5a6ec) //  1
NHSTUB(Fflush_Fut                             ,0xffc5a724) //  1
NHSTUB(Fgets_Fut                              ,0xffc5a65c) //  1
NHSTUB(Fopen_Fut                              ,0xffc5a49c) //120
NHSTUB(Fread_Fut                              ,0xffc5a5bc) //120
NHSTUB(FreeUncacheableMemory                  ,0xffc04b34) //  1
NHSTUB(Fseek_Fut                              ,0xffc5a6a4) //120
NHSTUB(Fwrite_Fut                             ,0xffc5a60c) //120
NHSTUB(GetBatteryTemperature                  ,0xffc1d7a4) //102
NHSTUB(GetCCDTemperature                      ,0xffc1d790) //102
NHSTUB(GetCurrentAvValue                      ,0xffea6ffc) //120
NHSTUB(GetCurrentShutterSpeed                 ,0xffea6c3c) //120
NHSTUB(GetUsableMaxAv                         ,0xffea72b8) //120
NHSTUB(GetUsableMinAv                         ,0xffea7294) //120
//NHSTUB(GetDrive_ClusterSize                 ,0xffc60cd4) //119            == 0xffc60cd4
//NHSTUB(GetDrive_FreeClusters                ,0xffc60d4c) //1103            == 0xffc60d4c
NHSTUB(GetDrive_TotalClusters                 ,0xffc60d10) //119
NHSTUB(GetOpticalTemperature                  ,0xffc1d77c) //120
NHSTUB(GetParameterData                       ,0xffd6d854) //  2
NHSTUB(GetPropertyCase                        ,0xffc14de4) //  2
NHSTUB(GetSystemTime                          ,0xffc04d38) //  2
NHSTUB(GetZoomLensCurrentPoint                ,0xffe87928) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xffe8793c) //102
NHSTUB(GiveSemaphore                          ,0xffc116b4) //120
NHSTUB(IsStrobeChargeCompleted                ,0xffd08620) //  2
NHSTUB(LEDDrive                               ,0xffc1dcfc) //120
NHSTUB(LocalTime                              ,0xffc043c8) //115
NHSTUB(LockMainPower                          ,0xffd68070) //120
NHSTUB(MakeDirectory_Fut                      ,0xffc5a424) //  1
NHSTUB(MoveFocusLensToDistance                ,0xffea9770) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xffe87808) //120
NHSTUB(Open                                   ,0xffc614c0) //120
NHSTUB(PT_PlaySound                           ,0xffd5eee0) //  1
NHSTUB(PostLogicalEventForNotPowerType        ,0xffd63df0) //120
NHSTUB(PostLogicalEventToUI                   ,0xffd63e6c) //120
NHSTUB(Read                                   ,0xffc6157c) //120
NHSTUB(RefreshPhysicalScreen                  ,0xffd7f49c) //120
NHSTUB(RenameFile_Fut                         ,0xffc5a318) //  1
NHSTUB(SetAE_ShutterSpeed                     ,0xffeac3e0) //102
NHSTUB(SetAutoShutdownTime                    ,0xffd67f74) //120
NHSTUB(SetCurrentCaptureModeType              ,0xffd964c8) //120
NHSTUB(SetFileAttributes                      ,0xffc61710) //  1
NHSTUB(SetLogicalEventActive                  ,0xffd65bd8) //1104
NHSTUB(SetParameterData                       ,0xffd6d774) //  2
NHSTUB(SetPropertyCase                        ,0xffc14c94) //  2
//NHSTUB(SetScriptMode                        ,0xffd65c40) //120            == 0xffd65c40
NHSTUB(SleepTask                              ,0xffc119d0) //120
NHSTUB(TakeSemaphore                          ,0xffc114cc) //1101
NHSTUB(TurnOffBackLight                       ,0xffdb63f4) //  2
NHSTUB(TurnOnBackLight                        ,0xffdb63c4) //  2
NHSTUB(TurnOnDisplay                          ,0xffd2cf00) //120
NHSTUB(TurnOffDisplay                         ,0xffd2cf10) //120
NHSTUB(UnlockAE                               ,0xffd4fe50) //120
NHSTUB(UnlockAF                               ,0xffd4fc90) //120
NHSTUB(UnlockMainPower                        ,0xffd68108) //120
NHSTUB(UpdateMBROnFlash                       ,0xffc60a08) //  1
NHSTUB(VbattGet                               ,0xffc1c6d0) //120
NHSTUB(Write                                  ,0xffc61588) //120
NHSTUB(WriteSDCard                            ,0xffc707ac) //  2
NHSTUB(_log                                   ,0xffee5cf0) //121
NHSTUB(_log10                                 ,0xffee2090) //121
NHSTUB(_pow                                   ,0xffee2218) //121
NHSTUB(_sqrt                                  ,0xffee40ec) //  1
NHSTUB(apex2us                                ,0xffca4bf8) //  1
NHSTUB(close                                  ,0xffef0238) //109
NHSTUB(exmem_alloc                            ,0xffc02a04) //122
NHSTUB(exmem_ualloc                           ,0xffc02834) //122
NHSTUB(exmem_ufree                            ,0xffc02904) //122
NHSTUB(kbd_p1_f                               ,0xffc17478) //  1
NHSTUB(kbd_p1_f_cont                          ,0xffc17484) //109
NHSTUB(kbd_p2_f                               ,0xffc1785c) //  1
NHSTUB(kbd_read_keys_r2                       ,0xffc18274) //  1
NHSTUB(kbd_pwr_off                            ,0xffc188f0) //  1
// ALT: NHSTUB(kbd_pwr_off, 0xffc18920) // 1 6/0
// ALT: NHSTUB(kbd_pwr_off, 0xffc1893c) // 1 6/0
NHSTUB(kbd_pwr_on                             ,0xffc188c8) //  1
NHSTUB(lseek                                  ,0xffef037c) //  1
NHSTUB(memcmp                                 ,0xffeeb294) //120
NHSTUB(memcpy                                 ,0xffeeb2d0) //120
NHSTUB(memset                                 ,0xffeeb348) //120
NHSTUB(mkdir                                  ,0xffc61740) //  1
NHSTUB(open                                   ,0xffef087c) //109
NHSTUB(closedir                               ,0xffeed6c0) //  1
NHSTUB(qsort                                  ,0xffeeaaf4) //  1
NHSTUB(rand                                   ,0xffeeab18) //  1
NHSTUB(realloc                                ,0xffedc240) //115
NHSTUB(srand                                  ,0xffeeab3c) //  1
NHSTUB(stat                                   ,0xffeed788) //  1
NHSTUB(strcat                                 ,0xffeeb368) //  1
NHSTUB(strchr                                 ,0xffeeb394) //  1
NHSTUB(strcmp                                 ,0xffeeb3b8) //120
NHSTUB(strcpy                                 ,0xffeeb54c) //120
NHSTUB(strftime                               ,0xffeecbd4) //  1
NHSTUB(strlen                                 ,0xffeeb6b0) //120
NHSTUB(strncmp                                ,0xffeeb714) //  1
NHSTUB(strncpy                                ,0xffeeb758) //  1
NHSTUB(strrchr                                ,0xffeeb7dc) //  1
NHSTUB(strtol                                 ,0xffeeaf30) //  1
NHSTUB(isdigit                                ,0xffee7664) //  1
NHSTUB(isspace                                ,0xffee76dc) //  1
NHSTUB(isalpha                                ,0xffee7634) //  1
NHSTUB(isupper                                ,0xffee76f4) //  1
NHSTUB(islower                                ,0xffee7694) //  1
NHSTUB(ispunct                                ,0xffee76c4) //  1
NHSTUB(isxdigit                               ,0xffee770c) //  1
NHSTUB(toupper                                ,0xffee7734) //  1
NHSTUB(tolower                                ,0xffee7724) //  1
NHSTUB(taskLock                               ,0xfff0055c) //  1
NHSTUB(taskUnlock                             ,0xfff00604) //  1
NHSTUB(taskName                               ,0xffeffd98) //  1
NHSTUB(errnoOfTaskGet                         ,0xffeede8c) //  1
NHSTUB(readdir                                ,0xffeed68c) //  1
NHSTUB(strtoul                                ,0xffeeb0d8) //  1
NHSTUB(strpbrk                                ,0xffeeb7a0) //  1
NHSTUB(utime                                  ,0xffeed81c) //  1
NHSTUB(mktime                                 ,0xffeec07c) //  1
NHSTUB(opendir                                ,0xffeed6f4) //  1
NHSTUB(memchr                                 ,0xffeeb260) //  1
NHSTUB(memPartInfoGet                         ,0xffef3698) //  1
NHSTUB(iosDrvInstall                          ,0xffef171c) //  1
NHSTUB(iosDevAdd                              ,0xffef1458) //  1
NHSTUB(iosDevDelete                           ,0xffef1430) //  1
NHSTUB(GetCurrentTargetDistance               ,0xffea94d0) //  1
NHSTUB(taskCreateHookAdd                      ,0xffef5ed8) //  1
NHSTUB(taskDeleteHookAdd                      ,0xffef5e14) //  1
NHSTUB(Unmount_FileSystem                     ,0xffc608b4) //  1
NHSTUB(taskSuspend                            ,0xffefffa8) //  1
NHSTUB(taskResume                             ,0xfff0017c) //  1
NHSTUB(time                                   ,0xffeecc00) //  1
NHSTUB(vsprintf                               ,0xffeeefe0) //115
NHSTUB(EngDrvRead                             ,0xffc72e8c) //102
NHSTUB(PTM_GetCurrentItem                     ,0xffd6b008) //102
NHSTUB(CancelHPTimer                          ,0xffc05bfc) //119
NHSTUB(SetHPTimerAfterNow                     ,0xffc05788) //119
NHSTUB(MFOn                                   ,0xffd5098c) //120
NHSTUB(MFOff                                  ,0xffd509bc) //120
NHSTUB(GetAdChValue                           ,0xffc19b38) //120
NHSTUB(get_ptp_buf_size                       ,0xffe43c4c) //122
NHSTUB(get_ptp_file_buf                       ,0xffe635a0) //121
