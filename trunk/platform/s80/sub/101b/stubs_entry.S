// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   Firmware Ver GM1.01B   // Found @ 0xff81a488, "GM1.01B" @ 0xff81a495
//   Firmware build timestamp: Jun 19 2006 19:51:31
//   Canon PowerShot S80

// Values for makefile.inc
//   DIGIC = 20                  // DIGIC II
//   PLATFORMID = 12538 (0x30fa) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x01ffffff
//   MEMISOSTART = 0x000a27f0

// Detected address ranges:
// ROM      0xff810000 - 0xffffffff (8323072 bytes)
// RAM data 0x00001900 - 0x000108e0 copied from 0xffb1a490 (  61408 bytes)

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
NHSTUB(EnterToCompensationEVF                 ,0xff95337c) //  1 87%
NHSTUB(ExitFromCompensationEVF                ,0xff954c88) //  2 90%
NHSTUB(GetFocusLensSubjectDistance            ,0xffaaabd4) //  1 96%
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xffaab174) //  3 52%
NHSTUB(GetSystemTime                          ,0xff814de8) //  1 96%
//NHSTUB(LEDDrive                             ,0xff82d8c8) //120        *** != 0xff82dbbc
//NHSTUB(PutInNdFilter                        ,0xffab6450) //  1 92%    *** != 0xffab685c
// ALT: NHSTUB(PutInNdFilter, 0xffab6498) // 1 25/2
// ALT: NHSTUB(PutInNdFilter, 0xffab685c) // 1 25/2
// ALT: NHSTUB(PutInNdFilter, 0xffab83e8) // 1 25/2
// ALT: NHSTUB(PutInNdFilter, 0xffab8430) // 1 25/2
// ALT: NHSTUB(PutInNdFilter, 0xffab6498) // 2 25/2
// ALT: NHSTUB(PutInNdFilter, 0xffab685c) // 2 25/2
// ALT: NHSTUB(PutInNdFilter, 0xffab83e8) // 2 25/2
// ALT: NHSTUB(PutInNdFilter, 0xffab8430) // 2 25/2
NHSTUB(PutOutNdFilter                         ,0xffab68a4) //  1 94%
//NHSTUB(Remove                               ,0xff8c6728) //  3 52%
NHSTUB(UnsetZoomForMovie                      ,0xff9a40c4) //  1 89%
NHSTUB(add_ptp_handler                        ,0xffa610ac) //  1 96%
// ERROR: free is not found.                               //--- ---    *** != 0xffb05c14
// ERROR: kbd_read_keys_r2 is not found.                   //--- ---    *** != 0xff827380
//NHSTUB(kbd_pwr_off                          ,0xff829348) //  1 83%    *** != 0xff828ff0
// ALT: NHSTUB(kbd_pwr_off, 0xff829364) // 1 5/1
// ALT: NHSTUB(kbd_pwr_off, 0xff828ff0) // 3 5/1
// ALT: NHSTUB(kbd_pwr_off, 0xff82900c) // 3 5/1
// ALT: NHSTUB(kbd_pwr_off, 0xff8290f8) // 3 5/1
// ALT: NHSTUB(kbd_pwr_off, 0xff829114) // 3 5/1
// ALT: NHSTUB(kbd_pwr_off, 0xff8291e4) // 3 5/1
// ALT: NHSTUB(kbd_pwr_off, 0xff829200) // 3 5/1
NHSTUB(kbd_pwr_on                             ,0xff928b2c) //  1 55%
// ALT: NHSTUB(kbd_pwr_on, 0xff928b58) // 1 5/4
// ALT: NHSTUB(kbd_pwr_on, 0xff928c94) // 1 5/4
// ALT: NHSTUB(kbd_pwr_on, 0xff92b548) // 1 5/4
// ALT: NHSTUB(kbd_pwr_on, 0xff92b574) // 1 5/4
NHSTUB(malloc                                 ,0xffb05c08) //  1 53%
NHSTUB(taskIdListGet                          ,0xffb1384c) //  1 82%
NHSTUB(localtime                              ,0xffafd35c) //  1 93%
NHSTUB(Mount_FileSystem                       ,0xff86f2c0) //  1 73%

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff96852c -> ff96852c
// Strange mode 0x00010013 in firmware, found in modemap as 19 (MODE_VIDEO_STD)
// Strange mode 0x00010014 in firmware but not in current modemap
// Strange mode 0x00010015 in firmware but not in current modemap
// Strange mode 0x00010016 in firmware but not in current modemap
// Strange mode 0x00020017 in firmware but not in current modemap
// Strange mode 0x00030018 in firmware but not in current modemap

// Values below can be overridden in 'stubs_min.S':
//DEF(levent_table                            ,0xff961230) // Found @0xff961230,          stubs_min = 0xff961230 (0xff961230)
//DEF(FlashParamsTable                        ,0xff96abe0) // Found @0xff96abe0,          stubs_min = 0xff96abe0 (0xff96abe0)
DEF(fileio_semaphore                        ,0x00002870) // Found @0xff86d6e4
DEF(exmem_alloc_table                       ,0x00001c30) // Found @0xff811fe4
DEF(exmem_types_table                       ,0xff811d44) // Found @0xff811d44
DEF_CONST(exmem_type_count                  ,0x0000000d)
DEF(imager_active                           ,0x0000553c) // Found @0xff8c9e4c (0x553c + 0)
DEF_CONST(uiprop_count                      ,0x00000057) // Found @0xff96cad0

// Values below go in 'lib.c':
//int get_flash_params_count(void) { return 0x5e; }                          // Found @0xff96db40

// Values below go in 'platform_camera.h':
//#define PARAM_CAMERA_NAME 3 // Found @0xff96a4b4

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

// LED table init @ 0xff82dd68
// LED #1: 0xc022007c, offset 0x104
// LED #2: 0xc022006c, offset 0x144
// LED #3: 0xc022008c, offset 0x4
// LED #4: 0xc0220088, offset 0x44
// LED #5: 0xc0220058, offset 0x84
// LED #6: 0xc0220084, offset 0x204
// LED #7: 0xc0220080, offset 0x244


// For capt_seq.c
DEF(_nrflag,0x6e10) // Found @ ff9580bc (0x6e10)
//static long *nrflag = (long*)(0x6e10);       // Found @ ff9580bc

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NHSTUB(AllocateUncacheableMemory              ,0xff814bb0) //  1
NHSTUB(Close                                  ,0xff87056c) //120
NHSTUB(CreateBinarySemaphore                  ,0xff820b78) //115
NHSTUB(CreateTask                             ,0xff821568) //120
NHSTUB(DebugAssert                            ,0xff813a80) //1100
NHSTUB(DeleteFile_Fut                         ,0xff86932c) //  1
NHSTUB(DoAELock                               ,0xff9513c8) //120
NHSTUB(DoAFLock                               ,0xff951250) //120
NHSTUB(ExecuteEventProcedure                  ,0xff816ac8) //  1
NHSTUB(ExitTask                               ,0xff821928) //120
NHSTUB(Fclose_Fut                             ,0xff86946c) //120
NHSTUB(Feof_Fut                               ,0xff869680) //  1
NHSTUB(Fflush_Fut                             ,0xff8696b8) //  1
NHSTUB(Fgets_Fut                              ,0xff8695f0) //  1
NHSTUB(Fopen_Fut                              ,0xff869430) //120
NHSTUB(Fread_Fut                              ,0xff869550) //120
NHSTUB(FreeUncacheableMemory                  ,0xff814be4) //  1
NHSTUB(Fseek_Fut                              ,0xff869638) //120
NHSTUB(Fwrite_Fut                             ,0xff8695a0) //120
NHSTUB(GetBatteryTemperature                  ,0xff82d370) //102
NHSTUB(GetCCDTemperature                      ,0xff82d35c) //102
NHSTUB(GetCurrentAvValue                      ,0xffab643c) //120
NHSTUB(GetCurrentShutterSpeed                 ,0xffab6080) //120
NHSTUB(GetUsableMaxAv                         ,0xffab6668) //120
NHSTUB(GetUsableMinAv                         ,0xffab6644) //120
NHSTUB(GetDrive_ClusterSize                   ,0xff86f8a8) //119
NHSTUB(GetDrive_FreeClusters                  ,0xff86f940) //1103
NHSTUB(GetDrive_TotalClusters                 ,0xff86f904) //119
NHSTUB(GetOpticalTemperature                  ,0xff82d348) //120
NHSTUB(GetParameterData                       ,0xff96dad4) //  1
NHSTUB(GetPropertyCase                        ,0xff824558) //  1
NHSTUB(GetZoomLensCurrentPoint                ,0xffa973d8) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xffa973ec) //102
NHSTUB(GiveSemaphore                          ,0xff821160) //120
NHSTUB(IsStrobeChargeCompleted                ,0xff904158) //  1
NHSTUB(LocalTime                              ,0xff814108) //115
NHSTUB(LockMainPower                          ,0xff9682a4) //120
NHSTUB(MakeDirectory_Fut                      ,0xff8693b8) //  1
//NHSTUB(MoveFocusLensToDistance              ,0xffab8a74) //102            Overridden
NHSTUB(MoveZoomLensWithPoint                  ,0xffa97268) //120
NHSTUB(Open                                   ,0xff870544) //120
NHSTUB(PT_PlaySound                           ,0xff95f6ec) //  1
NHSTUB(PostLogicalEventForNotPowerType        ,0xff963ef4) //120
NHSTUB(PostLogicalEventToUI                   ,0xff963f80) //120
NHSTUB(Read                                   ,0xff870600) //120
NHSTUB(RefreshPhysicalScreen                  ,0xff97eeac) //120
NHSTUB(RenameFile_Fut                         ,0xff8692ac) //  1
NHSTUB(Restart                                ,0xff822bb0) //  1
NHSTUB(SetAE_ShutterSpeed                     ,0xffabbb28) //102
NHSTUB(SetAutoShutdownTime                    ,0xff96819c) //120
NHSTUB(SetCurrentCaptureModeType              ,0xff998560) //120
NHSTUB(SetFileAttributes                      ,0xff870724) //  1
NHSTUB(SetLogicalEventActive                  ,0xff9660fc) //1104
NHSTUB(SetParameterData                       ,0xff96d9f4) //  1
NHSTUB(SetPropertyCase                        ,0xff82443c) //  1
NHSTUB(SetScriptMode                          ,0xff966164) //120
NHSTUB(SleepTask                              ,0xff82147c) //120
NHSTUB(TakeSemaphore                          ,0xff820f78) //1101
NHSTUB(TurnOffBackLight                       ,0xff9b93ac) //  1
NHSTUB(TurnOnBackLight                        ,0xff9b9380) //  1
NHSTUB(TurnOnDisplay                          ,0xff9289c4) //120
NHSTUB(TurnOffDisplay                         ,0xff9289d4) //120
NHSTUB(UnlockAE                               ,0xff9513e8) //120
NHSTUB(UnlockAF                               ,0xff9512b8) //120
NHSTUB(UnlockMainPower                        ,0xff968358) //120
NHSTUB(UpdateMBROnFlash                       ,0xff86f584) //  1
NHSTUB(VbattGet                               ,0xff82c2b8) //120
NHSTUB(Write                                  ,0xff87060c) //120
NHSTUB(WriteSDCard                            ,0xff87ee44) //  1
NHSTUB(_log                                   ,0xffaef148) //121
NHSTUB(_log10                                 ,0xffaef7f0) //121
NHSTUB(_pow                                   ,0xffaefce0) //121
NHSTUB(_sqrt                                  ,0xffaf402c) //  1
NHSTUB(apex2us                                ,0xff8aef8c) //  1
NHSTUB(close                                  ,0xffb02bc8) //109
NHSTUB(exmem_alloc                            ,0xff8127e0) //122
NHSTUB(exmem_free                             ,0xff81282c) //122
NHSTUB(kbd_p1_f                               ,0xff82655c) //  1
NHSTUB(kbd_p1_f_cont                          ,0xff826568) //109
NHSTUB(kbd_p2_f                               ,0xff826938) //  1
NHSTUB(lseek                                  ,0xffb02d0c) //  1
NHSTUB(memcmp                                 ,0xffafc73c) //120
NHSTUB(memcpy                                 ,0xffafc778) //120
NHSTUB(memset                                 ,0xffafc7f0) //120
NHSTUB(mkdir                                  ,0xff870754) //  1
NHSTUB(open                                   ,0xffb0320c) //109
NHSTUB(closedir                               ,0xffafeb68) //  1
NHSTUB(qsort                                  ,0xffafbf9c) //  1
NHSTUB(rand                                   ,0xffafbfc0) //  1
NHSTUB(realloc                                ,0xffae6014) //115
NHSTUB(srand                                  ,0xffafbfe4) //  1
NHSTUB(stat                                   ,0xffafec30) //  1
NHSTUB(strcat                                 ,0xffafc810) //  1
NHSTUB(strchr                                 ,0xffafc83c) //  1
NHSTUB(strcmp                                 ,0xffafc860) //120
NHSTUB(strcpy                                 ,0xffafc9f4) //120
NHSTUB(strftime                               ,0xffafe07c) //  1
NHSTUB(strlen                                 ,0xffafcb58) //120
NHSTUB(strncmp                                ,0xffafcbbc) //  1
NHSTUB(strncpy                                ,0xffafcc00) //  1
NHSTUB(strrchr                                ,0xffafcc84) //  1
NHSTUB(strtol                                 ,0xffafc3d8) //  1
NHSTUB(isdigit                                ,0xffaf8b0c) //  1
NHSTUB(isspace                                ,0xffaf8b84) //  1
NHSTUB(isalpha                                ,0xffaf8adc) //  1
NHSTUB(isupper                                ,0xffaf8b9c) //  1
NHSTUB(islower                                ,0xffaf8b3c) //  1
NHSTUB(ispunct                                ,0xffaf8b6c) //  1
NHSTUB(isxdigit                               ,0xffaf8bb4) //  1
NHSTUB(toupper                                ,0xffaf8bdc) //  1
NHSTUB(tolower                                ,0xffaf8bcc) //  1
NHSTUB(taskLock                               ,0xffb13f08) //  1
NHSTUB(taskUnlock                             ,0xffb13fb0) //  1
NHSTUB(taskName                               ,0xffb13744) //  1
NHSTUB(errnoOfTaskGet                         ,0xffaff334) //  1
NHSTUB(readdir                                ,0xffafeb34) //  1
NHSTUB(strtoul                                ,0xffafc580) //  1
NHSTUB(strpbrk                                ,0xffafcc48) //  1
NHSTUB(utime                                  ,0xffafecc4) //  1
NHSTUB(mktime                                 ,0xffafd524) //  1
NHSTUB(opendir                                ,0xffafeb9c) //  1
NHSTUB(memchr                                 ,0xffafc708) //  1
NHSTUB(memPartInfoGet                         ,0xffb06028) //  1
NHSTUB(iosDrvInstall                          ,0xffb040ac) //  1
NHSTUB(iosDevAdd                              ,0xffb03de8) //  1
NHSTUB(iosDevDelete                           ,0xffb03dc0) //  1
NHSTUB(GetCurrentTargetDistance               ,0xffab87e4) //  1
NHSTUB(taskCreateHookAdd                      ,0xffb09288) //  1
NHSTUB(taskDeleteHookAdd                      ,0xffb091c4) //  1
NHSTUB(Unmount_FileSystem                     ,0xff86f3d8) //  1
NHSTUB(MakeAFScan                             ,0xff955ddc) //  1
NHSTUB(taskSuspend                            ,0xffb13954) //  1
NHSTUB(taskResume                             ,0xffb13b28) //  1
NHSTUB(time                                   ,0xffafe0a8) //  1
NHSTUB(vsprintf                               ,0xffb00488) //115
NHSTUB(EngDrvRead                             ,0xff8810a4) //102
NHSTUB(PTM_GetCurrentItem                     ,0xff96b398) //102
NHSTUB(CancelHPTimer                          ,0xff815cac) //119
NHSTUB(SetHPTimerAfterNow                     ,0xff815838) //119
NHSTUB(MFOn                                   ,0xff951f20) //120
NHSTUB(MFOff                                  ,0xff951f50) //120
NHSTUB(GetAdChValue                           ,0xff829aa4) //120
NHSTUB(get_ptp_buf_size                       ,0xffa5251c) //122
NHSTUB(get_ptp_file_buf                       ,0xffa716c4) //121
