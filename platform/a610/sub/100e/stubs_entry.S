// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   Firmware Ver GM1.00E   // Found @ 0xffc0a1ac, "GM1.00E" @ 0xffc0a1b9
//   Firmware build timestamp: Aug 25 2005 11:33:06
//   Canon PowerShot A610

// Values for makefile.inc
//   PLATFORMID = 12541 (0x30fd) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x01ffffff
//   MEMISOSTART = 0x000a0b70

// Detected address ranges:
// ROM      0xffc00000 - 0xffffffff (4194304 bytes)
// RAM data 0x00001900 - 0x00010210 copied from 0xffed3720 (  59664 bytes)

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xffe66d90) //  3 52%
//NHSTUB(Remove                               ,0xffcaf510) //  3 52%

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ffd49168 -> ffd49168
// Strange mode 0x00010012 in firmware, found in modemap as 18 (MODE_VIDEO_STD)
// Strange mode 0x00010013 in firmware but not in current modemap
// Strange mode 0x00010014 in firmware but not in current modemap
// Strange mode 0x00010015 in firmware but not in current modemap
// Strange mode 0x00020016 in firmware but not in current modemap

// Values below can be overridden in 'stubs_min.S':
DEF(levent_table                            ,0xffd42290) // Found @0xffd42290
DEF(FlashParamsTable                        ,0xffd4b62c) // Found @0xffd4b62c
DEF(fileio_semaphore                        ,0x00002814) // Found @0xffc59de4
DEF(exmem_alloc_table                       ,0x00001c30) // Found @0xffc02034
DEF(exmem_types_table                       ,0xffc01d94) // Found @0xffc01d94
DEF_CONST(exmem_type_count                  ,0x0000000d)
DEF(imager_active                           ,0x000054b4) // Found @0xffcb2a14 (0x54b4 + 0)
DEF_CONST(uiprop_count                      ,0x00000057) // Found @0xffd4d30c

// Values below go in 'lib.c':
//int get_flash_params_count(void) { return 0x5e; }                          // Found @0xffd4e368

// Values below go in 'platform_camera.h':
//#define PARAM_CAMERA_NAME 3 // Found @0xffd4af00

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

// LED table init @ 0xffc1ce80
// LED #1: 0xc022008c, offset 0x4
// LED #2: 0xc0220088, offset 0x44
// LED #3: 0xc0220090, offset 0x84
// LED #4: 0xc0220094, offset 0xc4
// LED #5: 0xc0220084, offset 0x204
// LED #6: 0xc0220080, offset 0x244


// For capt_seq.c
DEF(_nrflag,0x6ce0) // Found @ ffd395ec (0x6ce0)
//static long *nrflag = (long*)(0x6ce0);       // Found @ ffd395ec

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NHSTUB(AllocateUncacheableMemory              ,0xffc048d8) //  1
NHSTUB(Close                                  ,0xffc5c70c) //120
NHSTUB(CreateBinarySemaphore                  ,0xffc10860) //115
NHSTUB(CreateTask                             ,0xffc11250) //120
NHSTUB(DebugAssert                            ,0xffc03ad0) //1100
NHSTUB(DeleteFile_Fut                         ,0xffc55a2c) //  1
NHSTUB(DoAELock                               ,0xffd331e4) //120
NHSTUB(DoAFLock                               ,0xffd33094) //120
NHSTUB(EnterToCompensationEVF                 ,0xffd34f38) //  1
NHSTUB(ExecuteEventProcedure                  ,0xffc067f0) //  1
NHSTUB(ExitFromCompensationEVF                ,0xffd34f98) //  1
NHSTUB(ExitTask                               ,0xffc11610) //120
NHSTUB(Fclose_Fut                             ,0xffc55b6c) //120
NHSTUB(Feof_Fut                               ,0xffc55d80) //  1
NHSTUB(Fflush_Fut                             ,0xffc55db8) //  1
NHSTUB(Fgets_Fut                              ,0xffc55cf0) //  1
NHSTUB(Fopen_Fut                              ,0xffc55b30) //120
NHSTUB(Fread_Fut                              ,0xffc55c50) //120
NHSTUB(FreeUncacheableMemory                  ,0xffc0490c) //  1
NHSTUB(Fseek_Fut                              ,0xffc55d38) //120
NHSTUB(Fwrite_Fut                             ,0xffc55ca0) //120
NHSTUB(GetBatteryTemperature                  ,0xffc1c488) //102
NHSTUB(GetCCDTemperature                      ,0xffc1c474) //102
NHSTUB(GetCurrentAvValue                      ,0xffe71314) //120
NHSTUB(GetCurrentShutterSpeed                 ,0xffe70f6c) //120
NHSTUB(GetUsableMaxAv                         ,0xffe71540) //120
NHSTUB(GetUsableMinAv                         ,0xffe7151c) //120
NHSTUB(GetDrive_ClusterSize                   ,0xffc5bee8) //119
NHSTUB(GetDrive_FreeClusters                  ,0xffc5bf60) //1103
NHSTUB(GetDrive_TotalClusters                 ,0xffc5bf24) //119
NHSTUB(GetFocusLensSubjectDistance            ,0xffe667f0) //  1
NHSTUB(GetOpticalTemperature                  ,0xffc1c460) //120
NHSTUB(GetParameterData                       ,0xffd4e2fc) //  1
NHSTUB(GetPropertyCase                        ,0xffc141a8) //  1
NHSTUB(GetSystemTime                          ,0xffc04b10) //  1
NHSTUB(GetZoomLensCurrentPoint                ,0xffe5305c) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xffe53070) //102
NHSTUB(GiveSemaphore                          ,0xffc10e48) //120
NHSTUB(IsStrobeChargeCompleted                ,0xffcebe00) //  1
NHSTUB(LEDDrive                               ,0xffc1c9e0) //120
NHSTUB(LocalTime                              ,0xffc041a0) //115
NHSTUB(LockMainPower                          ,0xffd48ee0) //120
NHSTUB(MakeDirectory_Fut                      ,0xffc55ab8) //  1
NHSTUB(MoveFocusLensToDistance                ,0xffe7394c) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xffe52f3c) //120
NHSTUB(Open                                   ,0xffc5c6e4) //120
NHSTUB(PT_PlaySound                           ,0xffd4074c) //  1
NHSTUB(PostLogicalEventForNotPowerType        ,0xffd44f04) //120
NHSTUB(PostLogicalEventToUI                   ,0xffd44f90) //120
NHSTUB(PutInNdFilter                          ,0xffe71734) //  1
NHSTUB(PutOutNdFilter                         ,0xffe7177c) //  1
NHSTUB(Read                                   ,0xffc5c7a0) //120
NHSTUB(RefreshPhysicalScreen                  ,0xffd5f6c0) //120
NHSTUB(RenameFile_Fut                         ,0xffc559ac) //  1
NHSTUB(Restart                                ,0xffc12800) //  1
NHSTUB(SetAE_ShutterSpeed                     ,0xffe76a00) //102
NHSTUB(SetAutoShutdownTime                    ,0xffd48dd8) //120
NHSTUB(SetCurrentCaptureModeType              ,0xffd76e1c) //120
NHSTUB(SetFileAttributes                      ,0xffc5c8c4) //  1
NHSTUB(SetLogicalEventActive                  ,0xffd46f7c) //1104
NHSTUB(SetParameterData                       ,0xffd4e21c) //  1
NHSTUB(SetPropertyCase                        ,0xffc1408c) //  1
NHSTUB(SetScriptMode                          ,0xffd46fe4) //120
NHSTUB(SleepTask                              ,0xffc11164) //120
NHSTUB(TakeSemaphore                          ,0xffc10c60) //1101
NHSTUB(TurnOffBackLight                       ,0xffd93454) //  1
NHSTUB(TurnOnBackLight                        ,0xffd93428) //  1
NHSTUB(TurnOnDisplay                          ,0xffd103b4) //120
NHSTUB(TurnOffDisplay                         ,0xffd103c4) //120
NHSTUB(UnlockAE                               ,0xffd33204) //120
NHSTUB(UnlockAF                               ,0xffd330d4) //120
NHSTUB(UnlockMainPower                        ,0xffd48f94) //120
NHSTUB(UnsetZoomForMovie                      ,0xffd81b80) //  1
NHSTUB(UpdateMBROnFlash                       ,0xffc5bc20) //  1
NHSTUB(VbattGet                               ,0xffc1b4cc) //120
NHSTUB(Write                                  ,0xffc5c7ac) //120
NHSTUB(WriteSDCard                            ,0xffc6afd8) //  1
NHSTUB(_log                                   ,0xffea83dc) //121
NHSTUB(_log10                                 ,0xffea8a84) //121
NHSTUB(_pow                                   ,0xffea8f74) //121
NHSTUB(_sqrt                                  ,0xffead2c0) //  1
NHSTUB(add_ptp_handler                        ,0xffe222d0) //  1
NHSTUB(apex2us                                ,0xffc987ec) //  1
NHSTUB(close                                  ,0xffebbe5c) //109
NHSTUB(exmem_alloc                            ,0xffc02830) //122
//NHSTUB(exmem_free                           ,0xffc0287c) //122            == 0xffc0287c
NHSTUB(free                                   ,0xffebeea8) //  1
NHSTUB(kbd_p1_f                               ,0xffc16184) //  1
NHSTUB(kbd_p1_f_cont                          ,0xffc16190) //109
NHSTUB(kbd_p2_f                               ,0xffc16568) //  1
NHSTUB(kbd_read_keys_r2                       ,0xffc16fd8) //  1
NHSTUB(kbd_pwr_off                            ,0xffc1758c) //  1
// ALT: NHSTUB(kbd_pwr_off, 0xffc17620) // 1 6/0
// ALT: NHSTUB(kbd_pwr_off, 0xffc1763c) // 1 6/0
NHSTUB(kbd_pwr_on                             ,0xffc17564) //  1
NHSTUB(lseek                                  ,0xffebbfa0) //  1
NHSTUB(malloc                                 ,0xffebee9c) //  1
NHSTUB(memcmp                                 ,0xffeb59d0) //120
NHSTUB(memcpy                                 ,0xffeb5a0c) //120
NHSTUB(memset                                 ,0xffeb5a84) //120
NHSTUB(mkdir                                  ,0xffc5c8f4) //  1
NHSTUB(open                                   ,0xffebc4a0) //109
NHSTUB(closedir                               ,0xffeb7dfc) //  1
NHSTUB(qsort                                  ,0xffeb5230) //  1
NHSTUB(rand                                   ,0xffeb5254) //  1
NHSTUB(realloc                                ,0xffea0514) //115
NHSTUB(srand                                  ,0xffeb5278) //  1
NHSTUB(stat                                   ,0xffeb7ec4) //  1
NHSTUB(strcat                                 ,0xffeb5aa4) //  1
NHSTUB(strchr                                 ,0xffeb5ad0) //  1
NHSTUB(strcmp                                 ,0xffeb5af4) //120
NHSTUB(strcpy                                 ,0xffeb5c88) //120
NHSTUB(strftime                               ,0xffeb7310) //  1
NHSTUB(strlen                                 ,0xffeb5dec) //120
NHSTUB(strncmp                                ,0xffeb5e50) //  1
NHSTUB(strncpy                                ,0xffeb5e94) //  1
NHSTUB(strrchr                                ,0xffeb5f18) //  1
NHSTUB(strtol                                 ,0xffeb566c) //  1
NHSTUB(isdigit                                ,0xffeb1da0) //  1
NHSTUB(isspace                                ,0xffeb1e18) //  1
NHSTUB(isalpha                                ,0xffeb1d70) //  1
NHSTUB(isupper                                ,0xffeb1e30) //  1
NHSTUB(islower                                ,0xffeb1dd0) //  1
NHSTUB(ispunct                                ,0xffeb1e00) //  1
NHSTUB(isxdigit                               ,0xffeb1e48) //  1
NHSTUB(toupper                                ,0xffeb1e70) //  1
NHSTUB(tolower                                ,0xffeb1e60) //  1
NHSTUB(taskLock                               ,0xffecd19c) //  1
NHSTUB(taskUnlock                             ,0xffecd244) //  1
NHSTUB(taskName                               ,0xffecc9d8) //  1
NHSTUB(taskIdListGet                          ,0xffeccae0) //  1
NHSTUB(errnoOfTaskGet                         ,0xffeb85c8) //  1
NHSTUB(readdir                                ,0xffeb7dc8) //  1
NHSTUB(strtoul                                ,0xffeb5814) //  1
NHSTUB(strpbrk                                ,0xffeb5edc) //  1
NHSTUB(utime                                  ,0xffeb7f58) //  1
NHSTUB(localtime                              ,0xffeb65f0) //  1
NHSTUB(mktime                                 ,0xffeb67b8) //  1
NHSTUB(opendir                                ,0xffeb7e30) //  1
NHSTUB(memchr                                 ,0xffeb599c) //  1
NHSTUB(memPartInfoGet                         ,0xffebf2bc) //  1
NHSTUB(iosDrvInstall                          ,0xffebd340) //  1
NHSTUB(iosDevAdd                              ,0xffebd07c) //  1
NHSTUB(iosDevDelete                           ,0xffebd054) //  1
NHSTUB(GetCurrentTargetDistance               ,0xffe736bc) //  1
NHSTUB(taskCreateHookAdd                      ,0xffec251c) //  1
NHSTUB(taskDeleteHookAdd                      ,0xffec2458) //  1
NHSTUB(Mount_FileSystem                       ,0xffc5b9c0) //  1
NHSTUB(Unmount_FileSystem                     ,0xffc5bac8) //  1
NHSTUB(MakeAFScan                             ,0xffd377b0) //  1
NHSTUB(taskSuspend                            ,0xffeccbe8) //  1
NHSTUB(taskResume                             ,0xffeccdbc) //  1
NHSTUB(time                                   ,0xffeb733c) //  1
NHSTUB(vsprintf                               ,0xffeb971c) //115
NHSTUB(EngDrvRead                             ,0xffc6d238) //102
NHSTUB(PTM_GetCurrentItem                     ,0xffd4bd84) //102
NHSTUB(CancelHPTimer                          ,0xffc059d4) //119
NHSTUB(SetHPTimerAfterNow                     ,0xffc05560) //119
NHSTUB(MFOn                                   ,0xffd33b70) //120
NHSTUB(MFOff                                  ,0xffd33ba0) //120
NHSTUB(GetAdChValue                           ,0xffc18d60) //120
NHSTUB(get_ptp_buf_size                       ,0xffe1373c) //122
NHSTUB(get_ptp_file_buf                       ,0xffe3285c) //121
