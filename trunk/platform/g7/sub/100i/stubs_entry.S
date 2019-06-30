// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   Firmware Ver GM1.00I   // Found @ 0xff81a738, "GM1.00I" @ 0xff81a745
//   Firmware build timestamp: Nov  1 2006 12:00:20
//   Canon PowerShot G7

// Values for makefile.inc
//   PLATFORMID = 12581 (0x3125) // Found @ 0xfffe0130
//   MAXRAMADDR = 0x03ffffff
//   MEMISOSTART = 0x000a7910

// Detected address ranges:
// ROM      0xff810000 - 0xffffffff (8323072 bytes)
// RAM data 0x00001900 - 0x0000ef10 copied from 0xffbb1ac0 (  54800 bytes)

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NHSTUB(EnterToCompensationEVF               ,0xff99b204) //  2 87%        == 0xff99b204
//NHSTUB(ExitFromCompensationEVF              ,0xff99f0c0) //  2 66%    *** != 0xff99b244
// ALT: NHSTUB(ExitFromCompensationEVF, 0xff99f11c) // 2 20/10
// ALT: NHSTUB(ExitFromCompensationEVF, 0xff99f1d8) // 2 20/10
NHSTUB(GetFocusLensSubjectDistance            ,0xffb3d8c4) //  1 83%
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xffb3de30) //  2 92%
NHSTUB(GetPropertyCase                        ,0xff8258d4) //  2 92%
NHSTUB(GetSystemTime                          ,0xff8150d8) //  1 96%
NHSTUB(PutInNdFilter                          ,0xffb505d8) //  1 92%
NHSTUB(PutOutNdFilter                         ,0xffb50620) //  1 94%
//NHSTUB(Remove                               ,0xff8e7ac8) //  3 52%
//NHSTUB(Restart                              ,0xff823ac0) //  1 92%    *** != 0xff823abc
NHSTUB(UnsetZoomForMovie                      ,0xff9f6c4c) //  1 89%
//NHSTUB(WriteSDCard                          ,0xff88bcd0) //  2 93%    *** != 0xff88be6c
NHSTUB(add_ptp_handler                        ,0xffaef0d4) //  1 96%
// ERROR: free is not found.                               //--- ---    *** != 0xffb9ec44
// ERROR: kbd_read_keys_r2 is not found.                   //--- ---    *** != 0xff828e70
NHSTUB(kbd_pwr_off                            ,0xff82ab3c) //  1 83%
// ALT: NHSTUB(kbd_pwr_off, 0xff82ab58) // 1 5/1
NHSTUB(kbd_pwr_on                             ,0xff96715c) //  1 55%
// ALT: NHSTUB(kbd_pwr_on, 0xff967188) // 1 5/4
NHSTUB(malloc                                 ,0xffb9ec38) //  1 53%
NHSTUB(taskIdListGet                          ,0xffbab860) //  1 82%
NHSTUB(localtime                              ,0xffb97874) //  1 93%
NHSTUB(Mount_FileSystem                       ,0xff87be74) //  1 90%
NHSTUB(MakeAFScan                             ,0xff9a0560) //  2 79%

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ff9b6358 -> ff9b6358
// Mode  8222 in firmware but not in current modemap
// Mode  8223 in firmware but not in current modemap

// Values below can be overridden in 'stubs_min.S':
DEF(levent_table                            ,0xff9ae87c) // Found @0xff9ae87c
DEF(FlashParamsTable                        ,0xff9b8db4) // Found @0xff9b8db4
DEF(fileio_semaphore                        ,0x00002984) // Found @0xff87a218
DEF(exmem_alloc_table                       ,0x00001bcc) // Found @0xff811f28
DEF(exmem_types_table                       ,0xff811d3c) // Found @0xff811d3c
DEF_CONST(exmem_type_count                  ,0x0000000e)
DEF(imager_active                           ,0x00005a60) // Found @0xff8eb40c (0x5a60 + 0)
DEF_CONST(uiprop_count                      ,0x0000005b) // Found @0xff9bac64

// Values below go in 'lib.c':
//int get_flash_params_count(void) { return 0x6e; }                          // Found @0xff9bbe74

// Values below go in 'platform_camera.h':
//#define PARAM_CAMERA_NAME 4 // Found @0xff9b8554

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

// LED table init @ 0xff82f464
// LED #1: 0xc0220068, offset 0xc4
// LED #2: 0xc022006c, offset 0x204
// LED #3: 0xc0220094, offset 0x244
// LED #4: 0xc02200b0, offset 0x384

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NHSTUB(AllocateUncacheableMemory              ,0xff814ea0) //  1
NHSTUB(Close                                  ,0xff87cb4c) //120
NHSTUB(CreateBinarySemaphore                  ,0xff821be4) //115
NHSTUB(CreateTask                             ,0xff822594) //120
NHSTUB(DebugAssert                            ,0xff813d70) //1100
NHSTUB(DeleteFile_Fut                         ,0xff875a0c) //  1
NHSTUB(DoAELock                               ,0xff99b2a4) //120
NHSTUB(DoAFLock                               ,0xff99afd0) //120
NHSTUB(ExecuteEventProcedure                  ,0xff816d3c) //  1
NHSTUB(ExitTask                               ,0xff822954) //120
NHSTUB(Fclose_Fut                             ,0xff875b80) //120
NHSTUB(Feof_Fut                               ,0xff875d7c) //  3
NHSTUB(Fflush_Fut                             ,0xff875db8) //  3
NHSTUB(Fgets_Fut                              ,0xff875ce4) //  3
NHSTUB(Fopen_Fut                              ,0xff875b40) //120
NHSTUB(Fread_Fut                              ,0xff875c3c) //120
NHSTUB(FreeUncacheableMemory                  ,0xff814ed4) //  1
NHSTUB(Fseek_Fut                              ,0xff875d30) //120
NHSTUB(Fwrite_Fut                             ,0xff875c90) //120
NHSTUB(GetBatteryTemperature                  ,0xff82eb20) //102
NHSTUB(GetCCDTemperature                      ,0xff82eb0c) //102
NHSTUB(GetCurrentAvValue                      ,0xffb50148) //120
NHSTUB(GetCurrentShutterSpeed                 ,0xffb4fd9c) //120
NHSTUB(GetUsableMaxAv                         ,0xffb50404) //120
NHSTUB(GetUsableMinAv                         ,0xffb503e0) //120
NHSTUB(GetDrive_ClusterSize                   ,0xff87c338) //119
NHSTUB(GetDrive_FreeClusters                  ,0xff87c3b0) //1103
NHSTUB(GetDrive_TotalClusters                 ,0xff87c374) //119
NHSTUB(GetOpticalTemperature                  ,0xff82eaf8) //120
NHSTUB(GetParameterData                       ,0xff9bbe08) //  2
NHSTUB(GetZoomLensCurrentPoint                ,0xffb29cc8) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xffb29cdc) //102
NHSTUB(GiveSemaphore                          ,0xff82218c) //120
NHSTUB(IsStrobeChargeCompleted                ,0xff939f98) //  2
NHSTUB(LEDDrive                               ,0xff82f078) //120
NHSTUB(LocalTime                              ,0xff8143f8) //115
NHSTUB(LockMainPower                          ,0xff9b60f8) //120
NHSTUB(MakeDirectory_Fut                      ,0xff875ac0) //  3
NHSTUB(MoveFocusLensToDistance                ,0xffb52900) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xffb29ba8) //120
NHSTUB(Open                                   ,0xff87cb24) //120
NHSTUB(PT_PlaySound                           ,0xff9aca78) //  1
NHSTUB(PostLogicalEventForNotPowerType        ,0xff9b1988) //120
NHSTUB(PostLogicalEventToUI                   ,0xff9b1a04) //120
NHSTUB(Read                                   ,0xff87cbe0) //120
NHSTUB(RefreshPhysicalScreen                  ,0xff9ce31c) //120
NHSTUB(RenameFile_Fut                         ,0xff875964) //  3
NHSTUB(SetAE_ShutterSpeed                     ,0xffb555d4) //102
NHSTUB(SetAutoShutdownTime                    ,0xff9b5ffc) //120
NHSTUB(SetCurrentCaptureModeType              ,0xff9e9e80) //120
NHSTUB(SetFileAttributes                      ,0xff87cd74) //  1
NHSTUB(SetLogicalEventActive                  ,0xff9b3924) //1104
NHSTUB(SetParameterData                       ,0xff9bbd28) //  2
NHSTUB(SetPropertyCase                        ,0xff825784) //  2
NHSTUB(SetScriptMode                          ,0xff9b398c) //120
NHSTUB(SleepTask                              ,0xff8224a8) //120
NHSTUB(TakeSemaphore                          ,0xff821fa4) //1101
NHSTUB(TurnOffBackLight                       ,0xffa12ef4) //  2
NHSTUB(TurnOnBackLight                        ,0xffa12ec4) //  2
NHSTUB(TurnOnDisplay                          ,0xff9648dc) //120
NHSTUB(TurnOffDisplay                         ,0xff9648ec) //120
NHSTUB(UnlockAE                               ,0xff99b2c4) //120
NHSTUB(UnlockAF                               ,0xff99b044) //120
NHSTUB(UnlockMainPower                        ,0xff9b6190) //120
NHSTUB(UpdateMBROnFlash                       ,0xff87c06c) //  1
NHSTUB(VbattGet                               ,0xff82d9bc) //120
NHSTUB(Write                                  ,0xff87cbec) //120
NHSTUB(_log                                   ,0xffb9103c) //121
NHSTUB(_log10                                 ,0xffb8cef8) //121
NHSTUB(_pow                                   ,0xffb8d080) //121
NHSTUB(_sqrt                                  ,0xffb8f270) //  1
NHSTUB(apex2us                                ,0xff8c8a28) //  1
NHSTUB(close                                  ,0xffb9bbf8) //109
NHSTUB(exmem_alloc                            ,0xff812834) //122
NHSTUB(exmem_free                             ,0xff812904) //122
NHSTUB(get_nd_value                           ,0xffb371d0) //122
NHSTUB(get_current_nd_value                   ,0xffb37178) //122
NHSTUB(kbd_p1_f                               ,0xff828014) //  1
NHSTUB(kbd_p1_f_cont                          ,0xff828020) //109
NHSTUB(kbd_p2_f                               ,0xff8283f0) //  1
NHSTUB(lseek                                  ,0xffb9bd3c) //  1
NHSTUB(memcmp                                 ,0xffb96c54) //120
NHSTUB(memcpy                                 ,0xffb96c90) //120
NHSTUB(memset                                 ,0xffb96d08) //120
NHSTUB(mkdir                                  ,0xff87cda4) //  1
NHSTUB(open                                   ,0xffb9c23c) //109
NHSTUB(closedir                               ,0xffb99080) //  1
NHSTUB(qsort                                  ,0xffb964b4) //  1
NHSTUB(rand                                   ,0xffb964d8) //  1
NHSTUB(realloc                                ,0xffb87038) //115
NHSTUB(srand                                  ,0xffb964fc) //  1
NHSTUB(stat                                   ,0xffb99148) //  1
NHSTUB(strcat                                 ,0xffb96d28) //  1
NHSTUB(strchr                                 ,0xffb96d54) //  1
NHSTUB(strcmp                                 ,0xffb96d78) //120
NHSTUB(strcpy                                 ,0xffb96f0c) //120
NHSTUB(strftime                               ,0xffb98594) //  1
NHSTUB(strlen                                 ,0xffb97070) //120
NHSTUB(strncmp                                ,0xffb970d4) //  1
NHSTUB(strncpy                                ,0xffb97118) //  1
NHSTUB(strrchr                                ,0xffb9719c) //  1
NHSTUB(strtol                                 ,0xffb968f0) //  1
NHSTUB(isdigit                                ,0xffb93024) //  1
NHSTUB(isspace                                ,0xffb9309c) //  1
NHSTUB(isalpha                                ,0xffb92ff4) //  1
NHSTUB(isupper                                ,0xffb930b4) //  1
NHSTUB(islower                                ,0xffb93054) //  1
NHSTUB(ispunct                                ,0xffb93084) //  1
NHSTUB(isxdigit                               ,0xffb930cc) //  1
NHSTUB(toupper                                ,0xffb930f4) //  1
NHSTUB(tolower                                ,0xffb930e4) //  1
NHSTUB(taskLock                               ,0xffbabf1c) //  1
NHSTUB(taskUnlock                             ,0xffbabfc4) //  1
NHSTUB(taskName                               ,0xffbab758) //  1
NHSTUB(errnoOfTaskGet                         ,0xffb9984c) //  1
NHSTUB(readdir                                ,0xffb9904c) //  1
NHSTUB(strtoul                                ,0xffb96a98) //  1
NHSTUB(strpbrk                                ,0xffb97160) //  1
NHSTUB(utime                                  ,0xffb991dc) //  1
NHSTUB(mktime                                 ,0xffb97a3c) //  1
NHSTUB(opendir                                ,0xffb990b4) //  1
NHSTUB(memchr                                 ,0xffb96c20) //  1
NHSTUB(memPartInfoGet                         ,0xffb9f058) //  1
NHSTUB(iosDrvInstall                          ,0xffb9d0dc) //  1
NHSTUB(iosDevAdd                              ,0xffb9ce18) //  1
NHSTUB(iosDevDelete                           ,0xffb9cdf0) //  1
NHSTUB(GetCurrentTargetDistance               ,0xffb52660) //  1
NHSTUB(taskCreateHookAdd                      ,0xffba1898) //  1
NHSTUB(taskDeleteHookAdd                      ,0xffba17d4) //  1
NHSTUB(Unmount_FileSystem                     ,0xff87bf18) //  1
NHSTUB(taskSuspend                            ,0xffbab968) //  1
NHSTUB(taskResume                             ,0xffbabb3c) //  1
NHSTUB(time                                   ,0xffb985c0) //  1
NHSTUB(vsprintf                               ,0xffb9a9a0) //115
NHSTUB(EngDrvRead                             ,0xff88e5bc) //102
NHSTUB(PTM_GetCurrentItem                     ,0xff9b936c) //102
NHSTUB(CancelHPTimer                          ,0xff815f9c) //119
NHSTUB(SetHPTimerAfterNow                     ,0xff815b28) //119
NHSTUB(MFOn                                   ,0xff99c09c) //120
NHSTUB(MFOff                                  ,0xff99c0d0) //120
NHSTUB(GetAdChValue                           ,0xff82ac74) //120
NHSTUB(get_ptp_buf_size                       ,0xffae2808) //122
NHSTUB(get_ptp_file_buf                       ,0xffaffdb4) //121
