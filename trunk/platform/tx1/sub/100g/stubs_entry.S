// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   Firmware Ver GM1.00G   // Found @ 0xff8180ac, "GM1.00G" @ 0xff8180b9
//   Firmware build timestamp: Feb  8 2007 09:02:47
//   Possible corrupt firmware dump - file size too small for start address 0xff810000
//     file size = 3.73MB, should be 7.94MB
//   Could not find Camera name - possible corrupt firmware dump

// Values for makefile.inc
//   MAXRAMADDR = 0x03ffffff
//   MEMISOSTART = 0x000b84d0

// Detected address ranges:
// ROM      0xff810000 - 0xffffffff (8323072 bytes)
// RAM data 0x00001900 - 0x0000e7a0 copied from 0xffbbe510 (  52896 bytes)

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
NHSTUB(EnterToCompensationEVF                 ,0xffb268b8) //  3 96%
NHSTUB(FreeUncacheableMemory                  ,0xff81e698) //  1 90%
//NHSTUB(GetFocusLensSubjectDistance          ,0xffaea650) //  1 74%    *** != 0xffaea654
// ERROR: GetFocusLensSubjectDistanceFromLens is not found.  //--- ---    *** != 0xffaeab54
NHSTUB(GetParameterData                       ,0xffb66b94) //  1 86%
NHSTUB(GetPropertyCase                        ,0xff81bd58) //  2 89%
NHSTUB(GetSystemTime                          ,0xff813770) //  1 96%
NHSTUB(PutInNdFilter                          ,0xffa63994) //  1 92%
NHSTUB(PutOutNdFilter                         ,0xffa639dc) //  1 94%
NHSTUB(Restart                                ,0xff81b80c) //  1 96%
NHSTUB(SetParameterData                       ,0xffb66ab4) //  1 86%
NHSTUB(add_ptp_handler                        ,0xff9f6390) //  1 96%
// ERROR: free is not found.                               //--- ---    *** != 0xff92b488
NHSTUB(kbd_p2_f                               ,0xffa43350) //  1 56%
//NHSTUB(kbd_read_keys_r2                     ,0xffa445c4) //  1 76%    *** != 0xffa444fc
NHSTUB(kbd_pwr_off                            ,0xffa421f0) //  1 83%
// ALT: NHSTUB(kbd_pwr_off, 0xffa4220c) // 1 5/1
NHSTUB(kbd_pwr_on                             ,0xffa39b2c) //  1 55%
// ALT: NHSTUB(kbd_pwr_on, 0xffa39b58) // 1 5/4
NHSTUB(malloc                                 ,0xff92b47c) //  1 53%
NHSTUB(mkdir                                  ,0xffaaeec4) //  1 51%
// ALT: NHSTUB(mkdir, 0xffaaef98) // 1 16/15
NHSTUB(taskIdListGet                          ,0xff9355c4) //  1 82%
NHSTUB(utime                                  ,0xffb7cd84) //  1 57%
NHSTUB(localtime                              ,0xff924294) //  1 93%
NHSTUB(Mount_FileSystem                       ,0xffaadf80) //  3 93%
NHSTUB(MakeAFScan                             ,0xffb2c7e4) //  2 79%

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ffb68d28 -> ffb68d28
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(levent_table                            ,0xffb5bf2c) // Found @0xffb5bf2c
DEF(FlashParamsTable                        ,0xffb6aecc) // Found @0xffb6aecc
DEF(fileio_semaphore                        ,0x0000a348) // Found @0xffab1320
DEF(exmem_alloc_table                       ,0x00001e24) // Found @0xff81da5c
DEF(exmem_types_table                       ,0xff81d87c) // Found @0xff81d87c
DEF_CONST(exmem_type_count                  ,0x00000011)
DEF(imager_active                           ,0x00006c44) // Found @0xff9be1d0 (0x6c44 + 0)
DEF_CONST(uiprop_count                      ,0x0000005d) // Found @0xffb65c94

// Values below go in 'lib.c':
//int get_flash_params_count(void) { return 0x6f; }                          // Found @0xffb66c00

// Values below go in 'platform_camera.h':
//#define PARAM_CAMERA_NAME 4 // Found @0xffb6a65c

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

// LED table init @ 0xffa42cb8

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NHSTUB(AllocateUncacheableMemory              ,0xff81e664) //  1
NHSTUB(Close                                  ,0xffaaec5c) //120
NHSTUB(CreateBinarySemaphore                  ,0xffb410b0) //115
NHSTUB(CreateTask                             ,0xffb41ac8) //120
NHSTUB(DebugAssert                            ,0xffb4d970) //1100
NHSTUB(DeleteFile_Fut                         ,0xffaaa230) //  1
NHSTUB(DoAELock                               ,0xffb26a44) //120
NHSTUB(DoAFLock                               ,0xffb26510) //120
NHSTUB(ExecuteEventProcedure                  ,0xff814adc) //  1
NHSTUB(ExitFromCompensationEVF                ,0xffb2693c) //  3
NHSTUB(ExitTask                               ,0xffb41e88) //120
NHSTUB(Fclose_Fut                             ,0xffaaa3a4) //120
NHSTUB(Feof_Fut                               ,0xffaaa5a0) //  3
NHSTUB(Fflush_Fut                             ,0xffaaa5dc) //  3
NHSTUB(Fgets_Fut                              ,0xffaaa508) //  3
NHSTUB(Fopen_Fut                              ,0xffaaa364) //120
NHSTUB(Fread_Fut                              ,0xffaaa460) //120
NHSTUB(Fseek_Fut                              ,0xffaaa554) //120
NHSTUB(Fwrite_Fut                             ,0xffaaa4b4) //120
NHSTUB(GetBatteryTemperature                  ,0xffa48d00) //102
NHSTUB(GetCCDTemperature                      ,0xffa48cec) //102
NHSTUB(GetCurrentAvValue                      ,0xffa63518) //120
NHSTUB(GetCurrentShutterSpeed                 ,0xffa6317c) //120
NHSTUB(GetUsableMaxAv                         ,0xffa637d4) //120
NHSTUB(GetUsableMinAv                         ,0xffa637b0) //120
NHSTUB(GetDrive_ClusterSize                   ,0xffaae448) //119
NHSTUB(GetDrive_FreeClusters                  ,0xffaae4c0) //1103
NHSTUB(GetDrive_TotalClusters                 ,0xffaae484) //119
NHSTUB(GetOpticalTemperature                  ,0xffa48cd8) //120
NHSTUB(GetZoomLensCurrentPoint                ,0xffaff734) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xffaff748) //102
NHSTUB(GiveSemaphore                          ,0xffb41694) //120
NHSTUB(IsStrobeChargeCompleted                ,0xff9b8f54) //  2
NHSTUB(LEDDrive                               ,0xffa42820) //120
NHSTUB(LocalTime                              ,0xffb4e23c) //115
NHSTUB(LockMainPower                          ,0xffb63880) //120
NHSTUB(MakeDirectory_Fut                      ,0xffaaa2e4) //  3
NHSTUB(MoveFocusLensToDistance                ,0xffa6624c) //102
NHSTUB(MoveIrisWithAv                         ,0xffaf2548) //120
NHSTUB(MoveZoomLensWithPoint                  ,0xffaff658) //120
NHSTUB(Open                                   ,0xffaaec34) //120
NHSTUB(PT_MoveDigitalZoomToWide               ,0xffb3883c) //120
NHSTUB(PT_MoveOpticalZoomAt                   ,0xffb38800) //120
NHSTUB(PT_PlaySound                           ,0xffb38300) //  3
NHSTUB(PostLogicalEventForNotPowerType        ,0xffb5f498) //120
NHSTUB(PostLogicalEventToUI                   ,0xffb5f514) //120
NHSTUB(Read                                   ,0xffaaecf0) //120
NHSTUB(RefreshPhysicalScreen                  ,0xff916bd8) //120
NHSTUB(RenameFile_Fut                         ,0xffaaa188) //  3
NHSTUB(SetAE_ShutterSpeed                     ,0xffa698f8) //102
NHSTUB(SetAutoShutdownTime                    ,0xffb63784) //120
NHSTUB(SetCurrentCaptureModeType              ,0xff829c58) //120
NHSTUB(SetFileAttributes                      ,0xffaaee44) //  3
NHSTUB(SetLogicalEventActive                  ,0xffb61390) //1104
NHSTUB(SetPropertyCase                        ,0xff81bc20) //  3
NHSTUB(SetScriptMode                          ,0xffb613f4) //120
NHSTUB(SleepTask                              ,0xffb419dc) //120
NHSTUB(TakeSemaphore                          ,0xffb4148c) //1101
NHSTUB(TurnOffBackLight                       ,0xff848a6c) //  2
NHSTUB(TurnOnBackLight                        ,0xff848a3c) //  2
NHSTUB(TurnOnDisplay                          ,0xffa368a4) //120
NHSTUB(TurnOffDisplay                         ,0xffa368b4) //120
NHSTUB(UnlockAE                               ,0xffb26a94) //120
NHSTUB(UnlockAF                               ,0xffb26590) //120
NHSTUB(UnlockMainPower                        ,0xffb63918) //120
NHSTUB(UpdateMBROnFlash                       ,0xffaae17c) //  1
NHSTUB(VbattGet                               ,0xffa409cc) //120
NHSTUB(Write                                  ,0xffaaecfc) //120
NHSTUB(WriteSDCard                            ,0xffac0ff8) //  3
NHSTUB(_log                                   ,0xff91e554) //121
NHSTUB(_log10                                 ,0xff91ac9c) //121
NHSTUB(_pow                                   ,0xff91ae1c) //121
NHSTUB(_sqrt                                  ,0xff91ccdc) //  1
NHSTUB(apex2us                                ,0xff93c8cc) //  1
NHSTUB(close                                  ,0xff92843c) //109
NHSTUB(exmem_alloc                            ,0xff81e540) //102
NHSTUB(exmem_free                             ,0xff81e5c0) //102
NHSTUB(kbd_p1_f                               ,0xffa42f28) //  1
NHSTUB(kbd_p1_f_cont                          ,0xffa42f34) //109
NHSTUB(lseek                                  ,0xff928580) //  1
NHSTUB(memcmp                                 ,0xff923674) //120
NHSTUB(memcpy                                 ,0xff9236b0) //120
NHSTUB(memset                                 ,0xff923728) //120
NHSTUB(open                                   ,0xff928a80) //109
NHSTUB(closedir                               ,0xffb7cc28) //  1
NHSTUB(qsort                                  ,0xff922ed4) //  1
NHSTUB(rand                                   ,0xff922ef8) //  1
NHSTUB(realloc                                ,0xffb4d57c) //115
NHSTUB(srand                                  ,0xff922f1c) //  1
NHSTUB(stat                                   ,0xffb7ccf0) //  1
NHSTUB(strcat                                 ,0xff923748) //  1
NHSTUB(strchr                                 ,0xff923774) //  1
NHSTUB(strcmp                                 ,0xff923798) //120
NHSTUB(strcpy                                 ,0xff92392c) //120
NHSTUB(strftime                               ,0xff924fb4) //  1
NHSTUB(strlen                                 ,0xff923a90) //120
NHSTUB(strncmp                                ,0xff923af4) //  1
NHSTUB(strncpy                                ,0xff923b38) //  1
NHSTUB(strrchr                                ,0xff923bbc) //  1
NHSTUB(strtol                                 ,0xff923310) //  1
NHSTUB(isdigit                                ,0xff91fa44) //  1
NHSTUB(isspace                                ,0xff91fabc) //  1
NHSTUB(isalpha                                ,0xff91fa14) //  1
NHSTUB(isupper                                ,0xff91fad4) //  1
NHSTUB(islower                                ,0xff91fa74) //  1
NHSTUB(ispunct                                ,0xff91faa4) //  1
NHSTUB(isxdigit                               ,0xff91faec) //  1
NHSTUB(toupper                                ,0xff91fb14) //  1
NHSTUB(tolower                                ,0xff91fb04) //  1
NHSTUB(taskLock                               ,0xff935c80) //  1
NHSTUB(taskUnlock                             ,0xff935d28) //  1
NHSTUB(taskName                               ,0xff9354bc) //  1
NHSTUB(errnoOfTaskGet                         ,0xff926090) //  1
NHSTUB(readdir                                ,0xffb7cbf4) //  1
NHSTUB(strtoul                                ,0xff9234b8) //  1
NHSTUB(strpbrk                                ,0xff923b80) //  1
NHSTUB(mktime                                 ,0xff92445c) //  1
NHSTUB(opendir                                ,0xffb7cc5c) //  1
NHSTUB(memchr                                 ,0xff923640) //  1
NHSTUB(memPartInfoGet                         ,0xff92b89c) //  1
NHSTUB(iosDrvInstall                          ,0xff929920) //  1
NHSTUB(iosDevAdd                              ,0xff92965c) //  1
NHSTUB(iosDevDelete                           ,0xff929634) //  1
NHSTUB(GetCurrentTargetDistance               ,0xffa65fb4) //  1
NHSTUB(taskCreateHookAdd                      ,0xff92e0dc) //  1
NHSTUB(taskDeleteHookAdd                      ,0xff92e018) //  1
NHSTUB(Unmount_FileSystem                     ,0xffaae028) //  1
NHSTUB(taskSuspend                            ,0xff9356cc) //  1
NHSTUB(taskResume                             ,0xff9358a0) //  1
NHSTUB(time                                   ,0xff924fe0) //  1
NHSTUB(vsprintf                               ,0xff9271e4) //115
NHSTUB(EngDrvRead                             ,0xffa50c64) //102
NHSTUB(PTM_GetCurrentItem                     ,0xffb64790) //102
NHSTUB(CancelHPTimer                          ,0xff8146c8) //1100
NHSTUB(SetHPTimerAfterNow                     ,0xff8141e0) //119
NHSTUB(MFOn                                   ,0xffb391e4) //120
NHSTUB(MFOff                                  ,0xffb391f4) //120
NHSTUB(GetAdChValue                           ,0xffa3d89c) //120
NHSTUB(get_ptp_buf_size                       ,0xff9eba8c) //122
NHSTUB(get_ptp_file_buf                       ,0xffa043a0) //121
