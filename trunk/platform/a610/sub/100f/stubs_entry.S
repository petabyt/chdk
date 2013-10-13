// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   Firmware Ver GM1.00F   // Found @ 0xffc0a1ac, "GM1.00F" @ 0xffc0a1b9
//   Firmware build timestamp: Dec 20 2005 10:49:50
//   Possible corrupt firmware dump - file size too small for start address 0xffc00000
//     file size = 2.88MB, should be 4.00MB
//   Could not find Camera name - possible corrupt firmware dump

// Values for makefile.inc

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xffe67118) //  3 52%
//NHSTUB(WriteSDCard                          ,0xffc6b360) //  1        *** != 0xffc6b188

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NHSTUB(AllocateUncacheableMemory              ,0xffc048d8) //  1
NHSTUB(Close                                  ,0xffc5ca94) //120
NHSTUB(CreateTask                             ,0xffc11250) //120
NHSTUB(DeleteFile_Fut                         ,0xffc55db4) //  1
NHSTUB(DoAFLock                               ,0xffd3341c) //  1
NHSTUB(EnterToCompensationEVF                 ,0xffd352c0) //  1
NHSTUB(ExecuteEventProcedure                  ,0xffc067f0) //  1
NHSTUB(ExitFromCompensationEVF                ,0xffd35320) //  1
NHSTUB(ExitTask                               ,0xffc11610) //120
NHSTUB(Fclose_Fut                             ,0xffc55ef4) //120
NHSTUB(Feof_Fut                               ,0xffc56108) //  1
NHSTUB(Fflush_Fut                             ,0xffc56140) //  1
NHSTUB(Fgets_Fut                              ,0xffc56078) //  1
NHSTUB(Fopen_Fut                              ,0xffc55eb8) //120
NHSTUB(Fread_Fut                              ,0xffc55fd8) //120
NHSTUB(FreeUncacheableMemory                  ,0xffc0490c) //  1
NHSTUB(Fseek_Fut                              ,0xffc560c0) //120
NHSTUB(Fwrite_Fut                             ,0xffc56028) //120
NHSTUB(GetBatteryTemperature                  ,0xffc1c488) //102
NHSTUB(GetCCDTemperature                      ,0xffc1c474) //102
NHSTUB(GetCurrentAvValue                      ,0xffe7169c) //  1
// ALT: NHSTUB(GetCurrentAvValue, 0xffe73a9c) // 1 13/0
NHSTUB(GetDrive_ClusterSize                   ,0xffc5c270) //  1
NHSTUB(GetDrive_FreeClusters                  ,0xffc5c2e8) //  1
NHSTUB(GetDrive_TotalClusters                 ,0xffc5c2ac) //  1
NHSTUB(GetFocusLensSubjectDistance            ,0xffe66b78) //  1
NHSTUB(GetOpticalTemperature                  ,0xffc1c460) //102
NHSTUB(GetParameterData                       ,0xffd4e684) //  1
NHSTUB(GetPropertyCase                        ,0xffc141a8) //  1
NHSTUB(GetSystemTime                          ,0xffc04b10) //  1
NHSTUB(GetZoomLensCurrentPoint                ,0xffe533e4) //102
NHSTUB(GetZoomLensCurrentPosition             ,0xffe533f8) //102
NHSTUB(GiveSemaphore                          ,0xffc10e48) //120
NHSTUB(IsStrobeChargeCompleted                ,0xffcec188) //  1
NHSTUB(LocalTime                              ,0xffc041a0) //115
NHSTUB(LockMainPower                          ,0xffd49268) //120
NHSTUB(MakeDirectory_Fut                      ,0xffc55e40) //  1
NHSTUB(MoveFocusLensToDistance                ,0xffe73cd4) //102
NHSTUB(MoveZoomLensWithPoint                  ,0xffe532c4) //102
NHSTUB(Open                                   ,0xffc5ca6c) //120
NHSTUB(PT_PlaySound                           ,0xffd40ad4) //  1
NHSTUB(PostLogicalEventForNotPowerType        ,0xffd4528c) //120
NHSTUB(PostLogicalEventToUI                   ,0xffd45318) //120
NHSTUB(PutInNdFilter                          ,0xffe71abc) //  1
NHSTUB(PutOutNdFilter                         ,0xffe71b04) //  1
NHSTUB(Read                                   ,0xffc5cb28) //120
NHSTUB(RefreshPhysicalScreen                  ,0xffd5fa48) //120
NHSTUB(RenameFile_Fut                         ,0xffc55d34) //  1
NHSTUB(Restart                                ,0xffc12800) //  1
NHSTUB(SetAE_ShutterSpeed                     ,0xffe76d88) //102
NHSTUB(SetAutoShutdownTime                    ,0xffd49160) //120
NHSTUB(SetCurrentCaptureModeType              ,0xffd771a4) //120
NHSTUB(SetFileAttributes                      ,0xffc5cc4c) //  1
NHSTUB(SetLogicalEventActive                  ,0xffd47304) //  1
NHSTUB(SetParameterData                       ,0xffd4e5a4) //  1
NHSTUB(SetPropertyCase                        ,0xffc1408c) //  1
//NHSTUB(SetScriptMode                        ,0xffd4736c) //120            == 0xffd4736c
NHSTUB(SleepTask                              ,0xffc11164) //120
NHSTUB(TakeSemaphore                          ,0xffc10c60) //  1
NHSTUB(TurnOffBackLight                       ,0xffd937dc) //  1
NHSTUB(TurnOnBackLight                        ,0xffd937b0) //  1
NHSTUB(UnlockAF                               ,0xffd3345c) //  1
NHSTUB(UnlockMainPower                        ,0xffd4931c) //120
NHSTUB(UnsetZoomForMovie                      ,0xffd81f08) //  1
NHSTUB(UpdateMBROnFlash                       ,0xffc5bfa8) //  1
NHSTUB(VbattGet                               ,0xffc1b4cc) //120
NHSTUB(Write                                  ,0xffc5cb34) //120
NHSTUB(_log                                   ,0xffea8764) //  1
NHSTUB(_log10                                 ,0xffea8e0c) //  1
NHSTUB(_pow                                   ,0xffea92fc) //  1
NHSTUB(_sqrt                                  ,0xffead648) //  1
NHSTUB(add_ptp_handler                        ,0xffe22658) //  1
NHSTUB(apex2us                                ,0xffc98b74) //  1
NHSTUB(close                                  ,0xffebc1e4) //109
NHSTUB(exmem_alloc                            ,0xffc02830) //  1
NHSTUB(free                                   ,0xffebf230) //  1
NHSTUB(kbd_p1_f                               ,0xffc16184) //  1
NHSTUB(kbd_p1_f_cont                          ,0xffc16190) //109
NHSTUB(kbd_p2_f                               ,0xffc16568) //  1
NHSTUB(kbd_read_keys_r2                       ,0xffc16fd8) //  1
NHSTUB(kbd_pwr_off                            ,0xffc1758c) //  1
// ALT: NHSTUB(kbd_pwr_off, 0xffc17620) // 1 6/0
// ALT: NHSTUB(kbd_pwr_off, 0xffc1763c) // 1 6/0
NHSTUB(kbd_pwr_on                             ,0xffc17564) //  1
NHSTUB(lseek                                  ,0xffebc328) //  1
NHSTUB(malloc                                 ,0xffebf224) //  1
NHSTUB(memcmp                                 ,0xffeb5d58) //120
NHSTUB(memcpy                                 ,0xffeb5d94) //120
NHSTUB(memset                                 ,0xffeb5e0c) //120
NHSTUB(mkdir                                  ,0xffc5cc7c) //  1
NHSTUB(open                                   ,0xffebc828) //109
NHSTUB(closedir                               ,0xffeb8184) //  1
NHSTUB(qsort                                  ,0xffeb55b8) //  1
NHSTUB(rand                                   ,0xffeb55dc) //  1
NHSTUB(realloc                                ,0xffea089c) //115
NHSTUB(srand                                  ,0xffeb5600) //  1
NHSTUB(stat                                   ,0xffeb824c) //  1
NHSTUB(strcat                                 ,0xffeb5e2c) //  1
NHSTUB(strchr                                 ,0xffeb5e58) //  1
NHSTUB(strcmp                                 ,0xffeb5e7c) //120
NHSTUB(strcpy                                 ,0xffeb6010) //120
NHSTUB(strftime                               ,0xffeb7698) //  1
NHSTUB(strlen                                 ,0xffeb6174) //120
NHSTUB(strncmp                                ,0xffeb61d8) //  1
NHSTUB(strncpy                                ,0xffeb621c) //  1
NHSTUB(strrchr                                ,0xffeb62a0) //  1
NHSTUB(strtol                                 ,0xffeb59f4) //  1
NHSTUB(isdigit                                ,0xffeb2128) //  1
NHSTUB(isspace                                ,0xffeb21a0) //  1
NHSTUB(isalpha                                ,0xffeb20f8) //  1
NHSTUB(isupper                                ,0xffeb21b8) //  1
NHSTUB(islower                                ,0xffeb2158) //  1
NHSTUB(ispunct                                ,0xffeb2188) //  1
NHSTUB(isxdigit                               ,0xffeb21d0) //  1
NHSTUB(toupper                                ,0xffeb21f8) //  1
NHSTUB(tolower                                ,0xffeb21e8) //  1
NHSTUB(taskLock                               ,0xffecd524) //  1
NHSTUB(taskUnlock                             ,0xffecd5cc) //  1
NHSTUB(taskName                               ,0xffeccd60) //  1
NHSTUB(taskIdListGet                          ,0xffecce68) //  1
NHSTUB(errnoOfTaskGet                         ,0xffeb8950) //  1
NHSTUB(readdir                                ,0xffeb8150) //  1
NHSTUB(strtoul                                ,0xffeb5b9c) //  1
NHSTUB(strpbrk                                ,0xffeb6264) //  1
NHSTUB(utime                                  ,0xffeb82e0) //  1
NHSTUB(localtime                              ,0xffeb6978) //  1
NHSTUB(mktime                                 ,0xffeb6b40) //  1
NHSTUB(opendir                                ,0xffeb81b8) //  1
NHSTUB(memchr                                 ,0xffeb5d24) //  1
NHSTUB(memPartInfoGet                         ,0xffebf644) //  1
NHSTUB(iosDrvInstall                          ,0xffebd6c8) //  1
NHSTUB(iosDevAdd                              ,0xffebd404) //  1
NHSTUB(iosDevDelete                           ,0xffebd3dc) //  1
NHSTUB(GetCurrentTargetDistance               ,0xffe73a44) //  1
NHSTUB(taskCreateHookAdd                      ,0xffec28a4) //  1
NHSTUB(taskDeleteHookAdd                      ,0xffec27e0) //  1
NHSTUB(Mount_FileSystem                       ,0xffc5bd48) //  1
NHSTUB(Unmount_FileSystem                     ,0xffc5be50) //  1
NHSTUB(MakeAFScan                             ,0xffd37b38) //  1
NHSTUB(taskSuspend                            ,0xffeccf70) //  1
NHSTUB(taskResume                             ,0xffecd144) //  1
NHSTUB(time                                   ,0xffeb76c4) //  1
NHSTUB(vsprintf                               ,0xffeb9aa4) //115
