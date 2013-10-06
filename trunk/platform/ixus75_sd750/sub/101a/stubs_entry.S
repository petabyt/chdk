// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   "Firmware Ver GM1.01A"      // Found @ 0xff81803c
//   Firmware build timestamp: Mar 14 2007 18:38:48
//   Possible corrupt firmware dump - file size too small for start address 0xff810000
//     file size = 3.57MB, should be 7.94MB
//   Could not find Camera name - possible corrupt firmware dump

// Values for makefile.inc

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
NHSTUB(EnterToCompensationEVF                 ,0xffb0657c) //  3 96%
NHSTUB(FreeUncacheableMemory                  ,0xff81e5ec) //  1 90%
NHSTUB(GetDrive_ClusterSize                   ,0xffaa51dc) //  3 92%
NHSTUB(GetDrive_FreeClusters                  ,0xffaa5254) //  3 92%
NHSTUB(GetDrive_TotalClusters                 ,0xffaa5218) //  3 92%
NHSTUB(GetFocusLensSubjectDistance            ,0xffade99c) //  1 90%
NHSTUB(GetParameterData                       ,0xffb45910) //  1 86%
NHSTUB(GetPropertyCase                        ,0xff81bcac) //  2 89%
NHSTUB(GetSystemTime                          ,0xff813700) //  1 96%
//NHSTUB(MoveFocusLensToDistance              ,0xffa5e340) //102        *** != 0xffae01b8
NHSTUB(PutInNdFilter                          ,0xffa5bd14) //  1 92%
NHSTUB(PutOutNdFilter                         ,0xffa5bd5c) //  1 94%
NHSTUB(Restart                                ,0xff81b760) //  1 96%
NHSTUB(SetParameterData                       ,0xffb45830) //  1 86%
NHSTUB(TakeSemaphore                          ,0xffb1fbf8) //  1 61%
NHSTUB(UnsetZoomForMovie                      ,0xff8369cc) //  1 89%
//NHSTUB(WriteSDCard                          ,0xffab7bd4) //  3 74%    *** != 0xffab7d7c
// ALT: NHSTUB(WriteSDCard, 0xffab7d7c) // 3 23/8
NHSTUB(add_ptp_handler                        ,0xff9eeafc) //  1 96%
NHSTUB(exmem_alloc                            ,0xff81e2c4) //  2 93%
// ERROR: free is not found.                               //--- ---    *** != 0xff92a5b0
NHSTUB(kbd_p2_f                               ,0xffa39a7c) //  1 56%
//NHSTUB(kbd_read_keys_r2                     ,0xffa3acdc) //  3 62%    *** != 0xffa3acc0
//NHSTUB(kbd_pwr_off                          ,0xffa38984) //  1 83%    *** != 0xffa3b230
// ALT: NHSTUB(kbd_pwr_off, 0xffa389a0) // 1 5/1
// ALT: NHSTUB(kbd_pwr_off, 0xffa3b278) // 1 5/1
// ALT: NHSTUB(kbd_pwr_off, 0xffa3b294) // 1 5/1
// ALT: NHSTUB(kbd_pwr_off, 0xffa3b278) // 3 5/1
// ALT: NHSTUB(kbd_pwr_off, 0xffa3b294) // 3 5/1
//NHSTUB(kbd_pwr_on                           ,0xffa31aa8) //  1 55%    *** != 0xffa3b1f0
// ALT: NHSTUB(kbd_pwr_on, 0xffa31ad4) // 1 5/4
// ALT: NHSTUB(kbd_pwr_on, 0xffa31fd4) // 1 5/4
NHSTUB(malloc                                 ,0xff92a5a4) //  1 53%
NHSTUB(mkdir                                  ,0xffaa5c58) //  1 51%
// ALT: NHSTUB(mkdir, 0xffaa5d2c) // 1 16/15
NHSTUB(taskIdListGet                          ,0xff9346ec) //  1 82%
NHSTUB(utime                                  ,0xffb5fb94) //  1 57%
NHSTUB(localtime                              ,0xff9233bc) //  1 93%
NHSTUB(Mount_FileSystem                       ,0xffaa4d14) //  3 93%
NHSTUB(MakeAFScan                             ,0xffb0baec) //  2 79%

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NHSTUB(AllocateUncacheableMemory              ,0xff81e5b8) //  1
NHSTUB(Close                                  ,0xffaa59f0) //120
NHSTUB(CreateTask                             ,0xffb2022c) //120
NHSTUB(DeleteFile_Fut                         ,0xffaa0fc4) //  1
NHSTUB(DoAFLock                               ,0xffb061d4) //102
NHSTUB(ExecuteEventProcedure                  ,0xff814a6c) //  1
NHSTUB(ExitFromCompensationEVF                ,0xffb06600) //  3
NHSTUB(ExitTask                               ,0xffb205ec) //120
NHSTUB(Fclose_Fut                             ,0xffaa1138) //120
NHSTUB(Feof_Fut                               ,0xffaa1334) //  3
NHSTUB(Fflush_Fut                             ,0xffaa1370) //  3
NHSTUB(Fgets_Fut                              ,0xffaa129c) //  3
NHSTUB(Fopen_Fut                              ,0xffaa10f8) //120
NHSTUB(Fread_Fut                              ,0xffaa11f4) //120
NHSTUB(Fseek_Fut                              ,0xffaa12e8) //120
NHSTUB(Fwrite_Fut                             ,0xffaa1248) //120
//NHSTUB(GetBatteryTemperature                ,0xffa3fcbc) //102            == 0xffa3fcbc
NHSTUB(GetCCDTemperature                      ,0xffa3fca8) //102
NHSTUB(GetCurrentAvValue                      ,0xffa5bb30) //  2
// ALT: NHSTUB(GetCurrentAvValue, 0xffa5e100) // 1 13/0
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xffadee90) //  3
NHSTUB(GetOpticalTemperature                  ,0xffa3fc94) //102
NHSTUB(GetZoomLensCurrentPoint                ,0xffaf18cc) //102
NHSTUB(GetZoomLensCurrentPosition             ,0xffaf18e0) //102
NHSTUB(GiveSemaphore                          ,0xffb1fdf8) //120
NHSTUB(IsStrobeChargeCompleted                ,0xff9ae7d4) //  2
NHSTUB(LocalTime                              ,0xffb2ca04) //115
NHSTUB(LockMainPower                          ,0xffb42824) //120
NHSTUB(MakeDirectory_Fut                      ,0xffaa1078) //  3
NHSTUB(MoveIrisWithAv                         ,0xffae5814) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xffaf17a4) //102
NHSTUB(Open                                   ,0xffaa59c8) //120
NHSTUB(PT_MoveDigitalZoomToWide               ,0xffb17244) //120
NHSTUB(PT_MoveOpticalZoomAt                   ,0xffb17208) //120
NHSTUB(PT_PlaySound                           ,0xffb16d08) //  3
NHSTUB(PostLogicalEventForNotPowerType        ,0xffb3dfb8) //120
NHSTUB(PostLogicalEventToUI                   ,0xffb3e034) //120
NHSTUB(Read                                   ,0xffaa5a84) //120
NHSTUB(RefreshPhysicalScreen                  ,0xff915ffc) //120
NHSTUB(RenameFile_Fut                         ,0xffaa0f1c) //  3
NHSTUB(SetAE_ShutterSpeed                     ,0xffa61440) //102
NHSTUB(SetAutoShutdownTime                    ,0xffb42728) //120
NHSTUB(SetCurrentCaptureModeType              ,0xff82afd0) //120
NHSTUB(SetFileAttributes                      ,0xffaa5bd8) //  3
NHSTUB(SetLogicalEventActive                  ,0xffb401cc) //  3
NHSTUB(SetPropertyCase                        ,0xff81bb74) //  3
//NHSTUB(SetScriptMode                        ,0xffb40230) //120            == 0xffb40230
NHSTUB(SleepTask                              ,0xffb20140) //120
NHSTUB(TurnOffBackLight                       ,0xff849f2c) //  2
NHSTUB(TurnOnBackLight                        ,0xff849efc) //  2
NHSTUB(UnlockAF                               ,0xffb06254) //102
NHSTUB(UnlockMainPower                        ,0xffb428bc) //120
NHSTUB(UpdateMBROnFlash                       ,0xffaa4f10) //  1
NHSTUB(VbattGet                               ,0xffa37158) //120
NHSTUB(Write                                  ,0xffaa5a90) //120
NHSTUB(_log                                   ,0xff91d198) //  1
NHSTUB(_log10                                 ,0xff919f40) //  1
NHSTUB(_pow                                   ,0xff91a0c0) //  1
NHSTUB(_sqrt                                  ,0xff91bf80) //  1
NHSTUB(apex2us                                ,0xff93ba2c) //  1
NHSTUB(close                                  ,0xff927564) //109
NHSTUB(exmem_free                             ,0xff81e514) //102
NHSTUB(kbd_p1_f                               ,0xffa3964c) //  1
NHSTUB(kbd_p1_f_cont                          ,0xffa39658) //109
NHSTUB(lseek                                  ,0xff9276a8) //  1
NHSTUB(memcmp                                 ,0xff92279c) //120
NHSTUB(memcpy                                 ,0xff9227d8) //120
NHSTUB(memset                                 ,0xff922850) //120
NHSTUB(open                                   ,0xff927ba8) //109
NHSTUB(closedir                               ,0xffb5fa38) //  1
NHSTUB(qsort                                  ,0xff921ffc) //  1
NHSTUB(rand                                   ,0xff922020) //  1
NHSTUB(realloc                                ,0xffb2bd44) //115
NHSTUB(srand                                  ,0xff922044) //  1
NHSTUB(stat                                   ,0xffb5fb00) //  1
NHSTUB(strcat                                 ,0xff922870) //  1
NHSTUB(strchr                                 ,0xff92289c) //  1
NHSTUB(strcmp                                 ,0xff9228c0) //120
NHSTUB(strcpy                                 ,0xff922a54) //120
NHSTUB(strftime                               ,0xff9240dc) //  1
NHSTUB(strlen                                 ,0xff922bb8) //120
NHSTUB(strncmp                                ,0xff922c1c) //  1
NHSTUB(strncpy                                ,0xff922c60) //  1
NHSTUB(strrchr                                ,0xff922ce4) //  1
NHSTUB(strtol                                 ,0xff922438) //  1
NHSTUB(isdigit                                ,0xff91eb6c) //  1
NHSTUB(isspace                                ,0xff91ebe4) //  1
NHSTUB(isalpha                                ,0xff91eb3c) //  1
NHSTUB(isupper                                ,0xff91ebfc) //  1
NHSTUB(islower                                ,0xff91eb9c) //  1
NHSTUB(ispunct                                ,0xff91ebcc) //  1
NHSTUB(isxdigit                               ,0xff91ec14) //  1
NHSTUB(toupper                                ,0xff91ec3c) //  1
NHSTUB(tolower                                ,0xff91ec2c) //  1
NHSTUB(taskLock                               ,0xff934da8) //  1
NHSTUB(taskUnlock                             ,0xff934e50) //  1
NHSTUB(taskName                               ,0xff9345e4) //  1
NHSTUB(errnoOfTaskGet                         ,0xff9251b8) //  1
NHSTUB(readdir                                ,0xffb5fa04) //  1
NHSTUB(strtoul                                ,0xff9225e0) //  1
NHSTUB(strpbrk                                ,0xff922ca8) //  1
NHSTUB(mktime                                 ,0xff923584) //  1
NHSTUB(opendir                                ,0xffb5fa6c) //  1
NHSTUB(memchr                                 ,0xff922768) //  1
NHSTUB(memPartInfoGet                         ,0xff92a9c4) //  1
NHSTUB(iosDrvInstall                          ,0xff928a48) //  1
NHSTUB(iosDevAdd                              ,0xff928784) //  1
NHSTUB(iosDevDelete                           ,0xff92875c) //  1
NHSTUB(GetCurrentTargetDistance               ,0xffa5e0a8) //  1
NHSTUB(taskCreateHookAdd                      ,0xff92d204) //  1
NHSTUB(taskDeleteHookAdd                      ,0xff92d140) //  1
NHSTUB(Unmount_FileSystem                     ,0xffaa4dbc) //  1
NHSTUB(taskSuspend                            ,0xff9347f4) //  1
NHSTUB(taskResume                             ,0xff9349c8) //  1
NHSTUB(time                                   ,0xff924108) //  1
NHSTUB(vsprintf                               ,0xff92630c) //115
