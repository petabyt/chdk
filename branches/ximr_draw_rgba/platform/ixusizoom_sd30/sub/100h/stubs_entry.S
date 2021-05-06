// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   Firmware Ver GM1.00H   // Found @ 0xff81b270, "GM1.00H" @ 0xff81b27d
//   Firmware build timestamp: Dec 19 2005 19:54:19
//   Canon DIGITAL IXUS i zoom

// Values for makefile.inc
//   DIGIC = 20# DIGIC II
//   PLATFORMID = 12532# (0x30f4) Found @ 0xffd70130
//   MAXRAMADDR = 0x01ffffff
//   MEMISOSTART = 0x000a85f0

// Detected address ranges:
// ROM      0xff810000 - 0xffffffff (8323072 bytes)
// RAM data 0x00001900 - 0x000100d0 copied from 0xffae8270 (  59344 bytes)

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NHSTUB(EnterToCompensationEVF               ,0xff94ad48) //  1 64%        == 0xff94ad48
//NHSTUB(ExitFromCompensationEVF              ,0xff94ae48) //  1 73%    *** != 0xff94ada8
NHSTUB(GetFocusLensSubjectDistance            ,0xffa7ac38) //  1 90%
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xffa7b1d8) //  3 52%
NHSTUB(GetSystemTime                          ,0xff815094) //  1 96%
NHSTUB(PutInNdFilter                          ,0xffa85854) //  1 92%
// ALT: NHSTUB(PutInNdFilter, 0xffa873e0) // 1 25/2
// ALT: NHSTUB(PutInNdFilter, 0xffa87428) // 1 25/2
// ALT: NHSTUB(PutInNdFilter, 0xffa873e0) // 2 25/2
// ALT: NHSTUB(PutInNdFilter, 0xffa87428) // 2 25/2
NHSTUB(PutOutNdFilter                         ,0xffa8589c) //  1 94%
//NHSTUB(Remove                               ,0xff8c2a54) //  3 52%
NHSTUB(UnsetZoomForMovie                      ,0xff9955a8) //  1 89%
NHSTUB(UpdateMBROnFlash                       ,0xff86fec4) //  1 96%
NHSTUB(WriteSDCard                            ,0xff87fa1c) //  1 93%
// ALT: NHSTUB(WriteSDCard, 0xff87fbf4) // 1 29/2
NHSTUB(add_ptp_handler                        ,0xffa39c94) //  1 96%
// ERROR: free is not found.                               //--- ---    *** != 0xffad39f4
// ERROR: kbd_read_keys_r2 is not found.                   //--- ---    *** != 0xff828950
//NHSTUB(kbd_pwr_off                          ,0xff828f30) //  1 83%    *** != 0xff828e84
// ALT: NHSTUB(kbd_pwr_off, 0xff828f4c) // 1 5/1
// ALT: NHSTUB(kbd_pwr_off, 0xff829f24) // 1 5/1
// ALT: NHSTUB(kbd_pwr_off, 0xff829f40) // 1 5/1
// ALT: NHSTUB(kbd_pwr_off, 0xff828f4c) // 3 5/1
// ALT: NHSTUB(kbd_pwr_off, 0xff829bcc) // 3 5/1
// ALT: NHSTUB(kbd_pwr_off, 0xff829be8) // 3 5/1
// ALT: NHSTUB(kbd_pwr_off, 0xff829cd4) // 3 5/1
// ALT: NHSTUB(kbd_pwr_off, 0xff829cf0) // 3 5/1
// ALT: NHSTUB(kbd_pwr_off, 0xff829dc0) // 3 5/1
// ALT: NHSTUB(kbd_pwr_off, 0xff829ddc) // 3 5/1
//NHSTUB(kbd_pwr_on                           ,0xff9214d0) //  1 55%    *** != 0xff828e44
// ALT: NHSTUB(kbd_pwr_on, 0xff9214fc) // 1 5/4
NHSTUB(malloc                                 ,0xffad39e8) //  1 53%
NHSTUB(taskIdListGet                          ,0xffae162c) //  1 82%
NHSTUB(localtime                              ,0xffacb13c) //  1 93%
NHSTUB(Mount_FileSystem                       ,0xff86fc64) //  1 90%
NHSTUB(MakeAFScan                             ,0xff94d318) //  1 89%

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff95e704 -> ff95e704
// Mode 0 in firmware but not in current modemap
// Strange mode 0x00010010 in firmware, found in modemap as 16 (MODE_VIDEO_STD)
// Strange mode 0x00010011 in firmware but not in current modemap
// Strange mode 0x00010012 in firmware but not in current modemap

// Values below can be overridden in 'stubs_min.S':
DEF(levent_table                            ,0xff957980) // Found @0xff957980
DEF(FlashParamsTable                        ,0xff960844) // Found @0xff960844
DEF(fileio_semaphore                        ,0x00002840) // Found @0xff86e088
DEF(exmem_alloc_table                       ,0x00001c30) // Found @0xff812140
DEF(exmem_types_table                       ,0xff811eac) // Found @0xff811eac
DEF_CONST(exmem_type_count                  ,0x0000000c)
DEF(imager_active                           ,0x000054cc) // Found @0xff8c5d1c (0x54cc + 0)
DEF_CONST(uiprop_count                      ,0x00000057) // Found @0xff962174
DEF(cameracon_state                         ,0x00007630) // Found @0xff982afc

// Values below go in 'lib.c':
//int get_flash_params_count(void) { return 0x5e; }                          // Found @0xff962f94

// Values below go in 'platform_camera.h':
//#define PARAM_CAMERA_NAME 3 // Found @0xff960118

// Misc stuff

// EXMEM types:
// EXMEM_RAMDISK   0
// EXMEM_COM       1
// EXMEM_FORMATTER 2
// EXMEM_SHADING   3
// EXMEM_FAMODE    4
// EXMEM_FIRMUP    5
// EXMEM_FILESTORE 6
// EXMEM_MOVIE_REC 7
// EXMEM_MOVIE_PLY 8
// EXMEM_WIDE      9
// EXMEM_NARROW    10
// EXMEM_PCEVF     11

// LED table init @ 0xff82e8c0
// LED #1: 0xc022008c, offset 0x4
// LED #2: 0xc0220088, offset 0x44
// LED #3: 0xc0220084, offset 0x204
// LED #4: 0xc0220080, offset 0x244


// For capt_seq.c
DEF(_nrflag,0x6b6c) // Found @ ff94f100 (0x6b6c)
//static long *nrflag = (long*)(0x6b6c);       // Found @ ff94f100

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NHSTUB(AllocateUncacheableMemory              ,0xff814d0c) //  1
NHSTUB(Close                                  ,0xff8709b0) //120
NHSTUB(CreateBinarySemaphore                  ,0xff821cc8) //115
NHSTUB(CreateTask                             ,0xff8228ac) //120
NHSTUB(DebugAssert                            ,0xff813bdc) //1100
NHSTUB(DeleteFile_Fut                         ,0xff869894) //  1
NHSTUB(DoAELock                               ,0xff949044) //120
NHSTUB(DoAFLock                               ,0xff948efc) //120
NHSTUB(ExecuteEventProcedure                  ,0xff816fac) //  1
NHSTUB(ExitTask                               ,0xff822c6c) //120
NHSTUB(Fclose_Fut                             ,0xff8699d4) //120
NHSTUB(Feof_Fut                               ,0xff869be8) //  1
NHSTUB(Fflush_Fut                             ,0xff869c20) //  1
NHSTUB(Fgets_Fut                              ,0xff869b58) //  1
NHSTUB(Fopen_Fut                              ,0xff869998) //120
NHSTUB(Fread_Fut                              ,0xff869ab8) //120
NHSTUB(FreeUncacheableMemory                  ,0xff814d40) //  1
NHSTUB(Fseek_Fut                              ,0xff869ba0) //120
NHSTUB(Fwrite_Fut                             ,0xff869b08) //120
NHSTUB(GetBatteryTemperature                  ,0xff82dec8) //102
NHSTUB(GetCCDTemperature                      ,0xff82deb4) //102
NHSTUB(GetCurrentAvValue                      ,0xffa856d0) //120
NHSTUB(GetCurrentShutterSpeed                 ,0xffa8536c) //120
NHSTUB(GetDrive_ClusterSize                   ,0xff87018c) //119
NHSTUB(GetDrive_FreeClusters                  ,0xff870204) //1103
NHSTUB(GetDrive_TotalClusters                 ,0xff8701c8) //119
NHSTUB(GetOpticalTemperature                  ,0xff82dea0) //120
NHSTUB(GetParameterData                       ,0xff962f28) //  1
NHSTUB(GetPropertyCase                        ,0xff825bb0) //  1
NHSTUB(GetZoomLensCurrentPoint                ,0xffa6bb54) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xffa6bb68) //102
NHSTUB(GiveSemaphore                          ,0xff8222b0) //120
NHSTUB(IsStrobeChargeCompleted                ,0xff8fca14) //  1
NHSTUB(LEDDrive                               ,0xff82e420) //120
NHSTUB(LocalTime                              ,0xff814264) //115
NHSTUB(LockMainPower                          ,0xff95e47c) //120
NHSTUB(MakeDirectory_Fut                      ,0xff869920) //  1
NHSTUB(MoveFocusLensToDistance                ,0xffa87a6c) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xffa6ba34) //120
NHSTUB(Open                                   ,0xff870988) //120
NHSTUB(PT_PlaySound                           ,0xff955e3c) //  1
NHSTUB(PostLogicalEventForNotPowerType        ,0xff95a570) //120
NHSTUB(PostLogicalEventToUI                   ,0xff95a5fc) //120
NHSTUB(Read                                   ,0xff870a44) //120
NHSTUB(RefreshPhysicalScreen                  ,0xff9738b4) //120
NHSTUB(RenameFile_Fut                         ,0xff869814) //  1
NHSTUB(Restart                                ,0xff824140) //  1
NHSTUB(SetAE_ShutterSpeed                     ,0xffa8ab20) //102
NHSTUB(SetAutoShutdownTime                    ,0xff95e374) //120
NHSTUB(SetCurrentCaptureModeType              ,0xff98a8c8) //120
NHSTUB(SetDate                                ,0xffa8c678) //120
NHSTUB(SetFileAttributes                      ,0xff870b9c) //  1
NHSTUB(SetLogicalEventActive                  ,0xff95c52c) //1104
NHSTUB(SetParameterData                       ,0xff962e48) //  1
NHSTUB(SetPropertyCase                        ,0xff825a94) //  1
NHSTUB(SetScriptMode                          ,0xff95c590) //120
NHSTUB(SleepTask                              ,0xff82270c) //120
NHSTUB(TakeSemaphore                          ,0xff8220c8) //1101
NHSTUB(TurnOffBackLight                       ,0xff9a04c4) //  1
NHSTUB(TurnOnBackLight                        ,0xff9a0498) //  1
NHSTUB(TurnOnDisplay                          ,0xff921384) //120
NHSTUB(TurnOffDisplay                         ,0xff921394) //120
NHSTUB(UnlockAE                               ,0xff949064) //120
NHSTUB(UnlockAF                               ,0xff948f3c) //120
NHSTUB(UnlockMainPower                        ,0xff95e530) //120
NHSTUB(VbattGet                               ,0xff82cf1c) //120
NHSTUB(Write                                  ,0xff870a50) //120
NHSTUB(_log                                   ,0xffabcf28) //121
NHSTUB(_log10                                 ,0xffabd5d0) //121
NHSTUB(_pow                                   ,0xffabdac0) //121
NHSTUB(_sqrt                                  ,0xffac1e0c) //  1
NHSTUB(apex2us                                ,0xff8abda0) //  1
NHSTUB(close                                  ,0xffad09a8) //109
NHSTUB(exmem_ualloc                           ,0xff81293c) //122
NHSTUB(exmem_ufree                            ,0xff812988) //122
NHSTUB(get_nd_value                           ,0xffa7409c) //115
NHSTUB(get_current_nd_value                   ,0xffa74020) //122
NHSTUB(get_current_deltasv                    ,0xff8acd98) //122
NHSTUB(GetCurrentDriveBaseSvValue             ,0xff8b5608) //107
NHSTUB(kbd_p1_f                               ,0xff827bec) //  1
NHSTUB(kbd_p1_f_cont                          ,0xff827bf8) //109
NHSTUB(kbd_p2_f                               ,0xff827fd0) //  1
NHSTUB(lseek                                  ,0xffad0aec) //  1
NHSTUB(memcmp                                 ,0xffaca51c) //120
NHSTUB(memcpy                                 ,0xffaca558) //120
NHSTUB(memset                                 ,0xffaca5d0) //120
NHSTUB(mkdir                                  ,0xff870bcc) //  1
NHSTUB(open                                   ,0xffad0fec) //109
NHSTUB(closedir                               ,0xffacc948) //  1
NHSTUB(qsort                                  ,0xffac9d7c) //  1
NHSTUB(rand                                   ,0xffac9da0) //  1
NHSTUB(realloc                                ,0xffab5084) //115
NHSTUB(srand                                  ,0xffac9dc4) //  1
NHSTUB(stat                                   ,0xffacca10) //  1
NHSTUB(strcat                                 ,0xffaca5f0) //  1
NHSTUB(strchr                                 ,0xffaca61c) //  1
NHSTUB(strcmp                                 ,0xffaca640) //120
NHSTUB(strcpy                                 ,0xffaca7d4) //120
NHSTUB(strftime                               ,0xffacbe5c) //  1
NHSTUB(strlen                                 ,0xffaca938) //120
NHSTUB(strncmp                                ,0xffaca99c) //  1
NHSTUB(strncpy                                ,0xffaca9e0) //  1
NHSTUB(strrchr                                ,0xffacaa64) //  1
NHSTUB(strtol                                 ,0xffaca1b8) //  1
NHSTUB(isdigit                                ,0xffac68ec) //  1
NHSTUB(isspace                                ,0xffac6964) //  1
NHSTUB(isalpha                                ,0xffac68bc) //  1
NHSTUB(isupper                                ,0xffac697c) //  1
NHSTUB(islower                                ,0xffac691c) //  1
NHSTUB(ispunct                                ,0xffac694c) //  1
NHSTUB(isxdigit                               ,0xffac6994) //  1
NHSTUB(toupper                                ,0xffac69bc) //  1
NHSTUB(tolower                                ,0xffac69ac) //  1
NHSTUB(taskLock                               ,0xffae1ce8) //  1
NHSTUB(taskUnlock                             ,0xffae1d90) //  1
NHSTUB(taskName                               ,0xffae1524) //  1
NHSTUB(errnoOfTaskGet                         ,0xffacd114) //  1
NHSTUB(readdir                                ,0xffacc914) //  1
NHSTUB(strtoul                                ,0xffaca360) //  1
NHSTUB(strpbrk                                ,0xffacaa28) //  1
NHSTUB(utime                                  ,0xffaccaa4) //  1
NHSTUB(mktime                                 ,0xffacb304) //  1
NHSTUB(opendir                                ,0xffacc97c) //  1
NHSTUB(memchr                                 ,0xffaca4e8) //  1
NHSTUB(memPartInfoGet                         ,0xffad3e08) //  1
NHSTUB(iosDrvInstall                          ,0xffad1e8c) //  1
NHSTUB(iosDevAdd                              ,0xffad1bc8) //  1
NHSTUB(iosDevDelete                           ,0xffad1ba0) //  1
NHSTUB(GetCurrentTargetDistance               ,0xffa877dc) //  1
NHSTUB(taskCreateHookAdd                      ,0xffad7068) //  1
NHSTUB(taskDeleteHookAdd                      ,0xffad6fa4) //  1
NHSTUB(Unmount_FileSystem                     ,0xff86fd6c) //  1
NHSTUB(taskSuspend                            ,0xffae1734) //  1
NHSTUB(taskResume                             ,0xffae1908) //  1
NHSTUB(time                                   ,0xffacbe88) //  1
NHSTUB(vsprintf                               ,0xfface268) //115
NHSTUB(EngDrvRead                             ,0xff881ea4) //102
NHSTUB(PTM_GetCurrentItem                     ,0xff960f30) //102
NHSTUB(CancelHPTimer                          ,0xff816094) //119
NHSTUB(SetHPTimerAfterNow                     ,0xff815c20) //119
NHSTUB(MFOn                                   ,0xff9499f0) //120
NHSTUB(MFOff                                  ,0xff949a20) //120
NHSTUB(GetAdChValue                           ,0xff82a680) //120
NHSTUB(get_ptp_buf_size                       ,0xffa2b15c) //122
NHSTUB(get_ptp_file_buf                       ,0xffa4ae3c) //121
