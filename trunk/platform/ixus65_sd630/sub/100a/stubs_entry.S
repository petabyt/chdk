// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   Firmware Ver GM1.00A   // Found @ 0xff81a5c4, "GM1.00A" @ 0xff81a5d1
//   Firmware build timestamp: Jan 23 2006 19:44:50
//   Canon DIGITAL IXUS 65

// Values for makefile.inc
//   DIGIC = 20# DIGIC II
//   PLATFORMID = 12542# (0x30fe) Found @ 0xfffe0130
//   MAXRAMADDR = 0x01ffffff
//   MEMISOSTART = 0x0009c6b0

// Detected address ranges:
// ROM      0xff810000 - 0xffffffff (8323072 bytes)
// RAM data 0x00001900 - 0x0000d6e0 copied from 0xffb29580 (  48608 bytes)

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
// ERROR: EnterToCompensationEVF is not found.             //--- ---    *** != 0x00000000
//NHSTUB(ExitFromCompensationEVF              ,0xff95ebd0) //  1 70%    *** != 0x00000000
//NHSTUB(GetDrive_FreeClusters                ,0xff86fdd0) //1103        *** != 0xff868ad4
NHSTUB(GetFocusLensSubjectDistance            ,0xffabed90) //  1 96%
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xffabf330) //  3 92%
NHSTUB(GetParameterData                       ,0xff9786ac) //  1 86%
NHSTUB(GetSystemTime                          ,0xff814ee8) //  1 96%
NHSTUB(PutInNdFilter                          ,0xffacaac4) //  1 92%
// ALT: NHSTUB(PutInNdFilter, 0xffacc654) // 1 25/2
// ALT: NHSTUB(PutInNdFilter, 0xffacc69c) // 1 25/2
// ALT: NHSTUB(PutInNdFilter, 0xffacc654) // 2 25/2
// ALT: NHSTUB(PutInNdFilter, 0xffacc69c) // 2 25/2
NHSTUB(PutOutNdFilter                         ,0xffacab0c) //  1 94%
NHSTUB(SetParameterData                       ,0xff9785cc) //  1 86%
NHSTUB(UnsetZoomForMovie                      ,0xff9b1680) //  1 89%
NHSTUB(WriteSDCard                            ,0xff87ef94) //  3 64%
NHSTUB(add_ptp_handler                        ,0xffa7e780) //  1 96%
// ERROR: free is not found.                               //--- ---    *** != 0xffb1551c
//NHSTUB(kbd_pwr_off                          ,0xff827fdc) //  1 83%    *** != 0xff827f94
// ALT: NHSTUB(kbd_pwr_off, 0xff827ff8) // 1 5/1
// ALT: NHSTUB(kbd_pwr_off, 0xff82a1a4) // 1 5/1
// ALT: NHSTUB(kbd_pwr_off, 0xff82a1c0) // 1 5/1
// ALT: NHSTUB(kbd_pwr_off, 0xff827ff8) // 3 5/1
// ALT: NHSTUB(kbd_pwr_off, 0xff829e4c) // 3 5/1
// ALT: NHSTUB(kbd_pwr_off, 0xff829e68) // 3 5/1
// ALT: NHSTUB(kbd_pwr_off, 0xff829f54) // 3 5/1
// ALT: NHSTUB(kbd_pwr_off, 0xff829f70) // 3 5/1
// ALT: NHSTUB(kbd_pwr_off, 0xff82a040) // 3 5/1
// ALT: NHSTUB(kbd_pwr_off, 0xff82a05c) // 3 5/1
// ERROR: kbd_pwr_on is not found.                         //--- ---    *** != 0xff827f54
NHSTUB(malloc                                 ,0xffb15510) //  1 53%
//NHSTUB(realloc                              ,0xffafe640) //115        *** != 0xffb1475c
NHSTUB(taskIdListGet                          ,0xffb22b58) //  1 82%
NHSTUB(localtime                              ,0xffb0e14c) //  1 93%
NHSTUB(Mount_FileSystem                       ,0xff86f89c) //  1 90%
// ERROR: MakeAFScan is not found.                         //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff973ad4 -> ff973ad4
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(levent_table                            ,0xff96c760) // Found @0xff96c760
DEF(FlashParamsTable                        ,0xff975eb0) // Found @0xff975eb0
DEF(fileio_semaphore                        ,0x000027f4) // Found @0xff86dcc0
DEF(exmem_alloc_table                       ,0x00001bc0) // Found @0xff811f28
DEF(exmem_types_table                       ,0xff811d40) // Found @0xff811d40
DEF_CONST(exmem_type_count                  ,0x0000000d)
DEF(imager_active                           ,0x000054cc) // Found @0xff8ced04 (0x54cc + 0)
DEF_CONST(uiprop_count                      ,0x00000057) // Found @0xff97791c

// Values below go in 'lib.c':
//int get_flash_params_count(void) { return 0x6c; }                          // Found @0xff978718

// Values below go in 'platform_camera.h':
//#define PARAM_CAMERA_NAME 3 // Found @0xff97566c

// Misc stuff

// EXMEM types:
// EXMEM_RAMDISK   0
// EXMEM_COM       1
// EXMEM_COMTMP    2
// EXMEM_FORMATTER 3
// EXMEM_SHADING   4
// EXMEM_FAMODE    5
// EXMEM_FIRMUP    6
// EXMEM_FILESTORE 7
// EXMEM_MOVIE_REC 8
// EXMEM_MOVIE_PLY 9
// EXMEM_WIDE      10
// EXMEM_NARROW    11
// EXMEM_PCEVF     12

// LED table init @ 0xff82eb64
// LED #1: 0xc022008c, offset 0x4
// LED #2: 0xc0220088, offset 0x44
// LED #3: 0xc0220098, offset 0xc4
// LED #4: 0xc0220084, offset 0x204
// LED #5: 0xc0220080, offset 0x244

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NHSTUB(AllocateUncacheableMemory              ,0xff814cb0) //  1
NHSTUB(Close                                  ,0xff87056c) //120
NHSTUB(CreateBinarySemaphore                  ,0xff820c6c) //115
NHSTUB(CreateTask                             ,0xff82161c) //120
NHSTUB(DebugAssert                            ,0xff813b80) //1100
NHSTUB(DeleteFile_Fut                         ,0xff86970c) //  1
NHSTUB(DoAELock                               ,0xff95cc0c) //120
NHSTUB(DoAFLock                               ,0xff95cabc) //120
NHSTUB(ExecuteEventProcedure                  ,0xff816bc8) //  1
NHSTUB(ExitTask                               ,0xff8219dc) //120
NHSTUB(Fclose_Fut                             ,0xff86984c) //120
NHSTUB(Feof_Fut                               ,0xff869a60) //  1
NHSTUB(Fflush_Fut                             ,0xff869a98) //  1
NHSTUB(Fgets_Fut                              ,0xff8699d0) //  1
NHSTUB(Fopen_Fut                              ,0xff869810) //120
NHSTUB(Fread_Fut                              ,0xff869930) //120
NHSTUB(FreeUncacheableMemory                  ,0xff814ce4) //  1
NHSTUB(Fseek_Fut                              ,0xff869a18) //120
NHSTUB(Fwrite_Fut                             ,0xff869980) //120
NHSTUB(GetBatteryTemperature                  ,0xff82e220) //102
NHSTUB(GetCCDTemperature                      ,0xff82e20c) //102
NHSTUB(GetCurrentAvValue                      ,0xffaca940) //120
NHSTUB(GetCurrentShutterSpeed                 ,0xffaca5f0) //120
NHSTUB(GetDrive_ClusterSize                   ,0xff86fd58) //119
NHSTUB(GetDrive_TotalClusters                 ,0xff86fd94) //119
NHSTUB(GetOpticalTemperature                  ,0xff82e1f8) //120
NHSTUB(GetPropertyCase                        ,0xff8248e0) //  1
NHSTUB(GetZoomLensCurrentPoint                ,0xffaafa08) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xffaafa1c) //102
NHSTUB(GiveSemaphore                          ,0xff821214) //120
NHSTUB(IsStrobeChargeCompleted                ,0xff9112ec) //  1
NHSTUB(LEDDrive                               ,0xff82e778) //120
NHSTUB(LocalTime                              ,0xff814208) //115
NHSTUB(LockMainPower                          ,0xff973874) //120
NHSTUB(MakeDirectory_Fut                      ,0xff869798) //  1
NHSTUB(MoveFocusLensToDistance                ,0xffacccf0) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xffaaf8e8) //120
NHSTUB(Open                                   ,0xff870544) //120
NHSTUB(PT_PlaySound                           ,0xff96aa98) //  1
NHSTUB(PostLogicalEventForNotPowerType        ,0xff96f5c8) //120
NHSTUB(PostLogicalEventToUI                   ,0xff96f644) //120
NHSTUB(Read                                   ,0xff870600) //120
NHSTUB(RefreshPhysicalScreen                  ,0xff98a644) //120
NHSTUB(RenameFile_Fut                         ,0xff86968c) //  1
NHSTUB(Restart                                ,0xff822b34) //  1
NHSTUB(SetAE_ShutterSpeed                     ,0xffad0598) //102
NHSTUB(SetAutoShutdownTime                    ,0xff973778) //120
NHSTUB(SetCurrentCaptureModeType              ,0xff9a66a0) //120
NHSTUB(SetFileAttributes                      ,0xff870724) //  1
NHSTUB(SetLogicalEventActive                  ,0xff971544) //1104
NHSTUB(SetPropertyCase                        ,0xff8247c4) //  1
NHSTUB(SetScriptMode                          ,0xff9715ac) //120
NHSTUB(SleepTask                              ,0xff821530) //120
NHSTUB(TakeSemaphore                          ,0xff82102c) //1101
NHSTUB(TurnOffBackLight                       ,0xff9be4e8) //  2
NHSTUB(TurnOnBackLight                        ,0xff9be4b8) //  2
NHSTUB(TurnOnDisplay                          ,0xff9348e8) //120
NHSTUB(TurnOffDisplay                         ,0xff9348f8) //120
NHSTUB(UnlockAE                               ,0xff95cc2c) //120
NHSTUB(UnlockAF                               ,0xff95cb00) //120
NHSTUB(UnlockMainPower                        ,0xff97390c) //120
NHSTUB(UpdateMBROnFlash                       ,0xff86fa90) //  1
NHSTUB(VbattGet                               ,0xff82d154) //120
NHSTUB(Write                                  ,0xff87060c) //120
NHSTUB(_log                                   ,0xffb079f8) //121
NHSTUB(_log10                                 ,0xffb03d98) //121
NHSTUB(_pow                                   ,0xffb03f20) //121
NHSTUB(_sqrt                                  ,0xffb05df4) //  1
NHSTUB(apex2us                                ,0xff8b2d78) //  1
NHSTUB(close                                  ,0xffb124d0) //109
NHSTUB(exmem_alloc                            ,0xff8129fc) //122
NHSTUB(exmem_ualloc                           ,0xff81282c) //122
NHSTUB(exmem_ufree                            ,0xff8128fc) //122
NHSTUB(get_nd_value                           ,0xffab81cc) //115
NHSTUB(get_current_nd_value                   ,0xffab8128) //122
NHSTUB(kbd_p1_f                               ,0xff826cec) //  1
NHSTUB(kbd_p1_f_cont                          ,0xff826cf8) //109
NHSTUB(kbd_p2_f                               ,0xff8270d0) //  1
NHSTUB(kbd_read_keys_r2                       ,0xff827aac) //  1
NHSTUB(lseek                                  ,0xffb12614) //  1
NHSTUB(memcmp                                 ,0xffb0d52c) //120
NHSTUB(memcpy                                 ,0xffb0d568) //120
NHSTUB(memset                                 ,0xffb0d5e0) //120
NHSTUB(mkdir                                  ,0xff870754) //  1
NHSTUB(open                                   ,0xffb12b14) //109
NHSTUB(closedir                               ,0xffb0f958) //  1
NHSTUB(qsort                                  ,0xffb0cd8c) //  1
NHSTUB(rand                                   ,0xffb0cdb0) //  1
NHSTUB(srand                                  ,0xffb0cdd4) //  1
NHSTUB(stat                                   ,0xffb0fa20) //  1
NHSTUB(strcat                                 ,0xffb0d600) //  1
NHSTUB(strchr                                 ,0xffb0d62c) //  1
NHSTUB(strcmp                                 ,0xffb0d650) //120
NHSTUB(strcpy                                 ,0xffb0d7e4) //120
NHSTUB(strftime                               ,0xffb0ee6c) //  1
NHSTUB(strlen                                 ,0xffb0d948) //120
NHSTUB(strncmp                                ,0xffb0d9ac) //  1
NHSTUB(strncpy                                ,0xffb0d9f0) //  1
NHSTUB(strrchr                                ,0xffb0da74) //  1
NHSTUB(strtol                                 ,0xffb0d1c8) //  1
NHSTUB(isdigit                                ,0xffb09a2c) //  1
NHSTUB(isspace                                ,0xffb09aa4) //  1
NHSTUB(isalpha                                ,0xffb099fc) //  1
NHSTUB(isupper                                ,0xffb09abc) //  1
NHSTUB(islower                                ,0xffb09a5c) //  1
NHSTUB(ispunct                                ,0xffb09a8c) //  1
NHSTUB(isxdigit                               ,0xffb09ad4) //  1
NHSTUB(toupper                                ,0xffb09afc) //  1
NHSTUB(tolower                                ,0xffb09aec) //  1
NHSTUB(taskLock                               ,0xffb23214) //  1
NHSTUB(taskUnlock                             ,0xffb232bc) //  1
NHSTUB(taskName                               ,0xffb22a50) //  1
NHSTUB(errnoOfTaskGet                         ,0xffb10124) //  1
NHSTUB(readdir                                ,0xffb0f924) //  1
NHSTUB(strtoul                                ,0xffb0d370) //  1
NHSTUB(strpbrk                                ,0xffb0da38) //  1
NHSTUB(utime                                  ,0xffb0fab4) //  1
NHSTUB(mktime                                 ,0xffb0e314) //  1
NHSTUB(opendir                                ,0xffb0f98c) //  1
NHSTUB(memchr                                 ,0xffb0d4f8) //  1
NHSTUB(memPartInfoGet                         ,0xffb15930) //  1
NHSTUB(iosDrvInstall                          ,0xffb139b4) //  1
NHSTUB(iosDevAdd                              ,0xffb136f0) //  1
NHSTUB(iosDevDelete                           ,0xffb136c8) //  1
NHSTUB(GetCurrentTargetDistance               ,0xffacca50) //  1
NHSTUB(taskCreateHookAdd                      ,0xffb18b90) //  1
NHSTUB(taskDeleteHookAdd                      ,0xffb18acc) //  1
NHSTUB(Unmount_FileSystem                     ,0xff86f940) //  1
NHSTUB(taskSuspend                            ,0xffb22c60) //  1
NHSTUB(taskResume                             ,0xffb22e34) //  1
NHSTUB(time                                   ,0xffb0ee98) //  1
NHSTUB(vsprintf                               ,0xffb11278) //115
NHSTUB(EngDrvRead                             ,0xff8814dc) //102
NHSTUB(PTM_GetCurrentItem                     ,0xff9765ec) //102
NHSTUB(CancelHPTimer                          ,0xff815dac) //119
NHSTUB(SetHPTimerAfterNow                     ,0xff815938) //119
NHSTUB(MFOn                                   ,0xff95d5d8) //120
NHSTUB(MFOff                                  ,0xff95d608) //120
NHSTUB(GetAdChValue                           ,0xff82a918) //120
NHSTUB(get_ptp_buf_size                       ,0xffa6fc08) //122
NHSTUB(get_ptp_file_buf                       ,0xffa8ee20) //121
