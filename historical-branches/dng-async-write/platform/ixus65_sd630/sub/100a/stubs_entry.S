// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

NHSTUB(AllocateMemory, 0xff811ac4)
NHSTUB(AllocateUncacheableMemory, 0xff814cb0)
NHSTUB(Close, 0xff87056c)
NHSTUB(CreatePhysicalVram, 0xff935f78)
NHSTUB(CreateTask, 0xff82161c)
NHSTUB(CreateTaskStrict, 0xff8226bc)
NHSTUB(DeleteFile_Fut, 0xff86970c)
NHSTUB(DisableDispatch, 0xff821440)
// Best match: 96%
NHSTUB(DisplayImagePhysicalScreen, 0xff9352ac)
// Best match: 56%
//NHSTUB(DoAFLock, 0xff95cab4) -- stubs_entry_2.S = 0xff95cabc
NHSTUB(EnableDispatch, 0xff8214cc)
// ERROR: EnterToCompensationEVF is not found!
NHSTUB(ExecuteEventProcedure, 0xff816bc8)
// Best match: 70%
//NHSTUB(ExitFromCompensationEVF, 0xff95ebd0) -- stubs_entry_2.S = 0x00000000
NHSTUB(ExitTask, 0xff8219dc)
NHSTUB(Fclose_Fut, 0xff86984c)
NHSTUB(Feof_Fut, 0xff869a60)
NHSTUB(Fflush_Fut, 0xff869a98)
NHSTUB(Fgets_Fut, 0xff8699d0)
NHSTUB(Fopen_Fut, 0xff869810)
NHSTUB(Fread_Fut, 0xff869930)
NHSTUB(FreeMemory, 0xff811ad0)
NHSTUB(FreeUncacheableMemory, 0xff814ce4)
NHSTUB(Fseek_Fut, 0xff869a18)
NHSTUB(Fwrite_Fut, 0xff869980)
// Best match: 78%
NHSTUB(GetBatteryTemperature, 0xff82e220)
// Best match: 79%
NHSTUB(GetCCDTemperature, 0xff82e20c)
NHSTUB(GetCurrentAvValue, 0xffaccaa8)
NHSTUB(GetCurrentTargetDistance, 0xffacca50)
// Best match: 76%
//NHSTUB(GetDrive_ClusterSize, 0xff86fd94) -- stubs_entry_2.S = 0xff86fd58
// Best match: 80%
//NHSTUB(GetDrive_FreeClusters, 0xff86fd94) -- stubs_entry_2.S = 0xff868ad4
// Best match: 84%
//NHSTUB(GetDrive_TotalClusters, 0xff86fd58) -- stubs_entry_2.S = 0xff86fd94
// Best match: 96%
NHSTUB(GetFocusLensSubjectDistance, 0xffabed90)
// Best match: 92%
NHSTUB(GetFocusLensSubjectDistanceFromLens, 0xffabf330)
// Best match: 79%
NHSTUB(GetOpticalTemperature, 0xff82e1f8)
// Best match: 86%
NHSTUB(GetParameterData, 0xff9786ac)
NHSTUB(GetPropertyCase, 0xff8248e0)
// Best match: 96%
NHSTUB(GetSystemTime, 0xff814ee8)
// ALT: NHSTUB(GetSystemTime, 0xff814ee8) // 26/1
// Best match: 93%
NHSTUB(GetZoomLensCurrentPoint, 0xffaafa08)
// ALT: NHSTUB(GetZoomLensCurrentPoint, 0xffaafa08) // 27/2
// Best match: 93%
NHSTUB(GetZoomLensCurrentPosition, 0xffaafa1c)
// ALT: NHSTUB(GetZoomLensCurrentPosition, 0xffaafa1c) // 27/2
NHSTUB(IsStrobeChargeCompleted, 0xff9112ec)
NHSTUB(LockMainPower, 0xff973874)
// ERROR: MakeAFScan is not found!
NHSTUB(MakeDirectory, 0xff870810)
NHSTUB(MakeDirectory_Fut, 0xff869798)
// Best match: 90%
NHSTUB(Mount_FileSystem, 0xff86f89c)
// ALT: NHSTUB(Mount_FileSystem, 0xff86f89c) // 27/3
// Best match: 96%
NHSTUB(MoveFocusLensToDistance, 0xffacccf0)
NHSTUB(MoveZoomLensWithPoint, 0xffaaf8e8)
// ALT: NHSTUB(MoveZoomLensWithPoint, 0xffaaf8e8) // 25/0
NHSTUB(Open, 0xff870544)
NHSTUB(PT_PlaySound, 0xff96aa98)
// Best match: 89%
NHSTUB(PhySw_testgpio, 0xff828020)
NHSTUB(PostLogicalEventForNotPowerType, 0xff96f5c8)
NHSTUB(PostLogicalEventToUI, 0xff96f644)
// ALT: NHSTUB(PostLogicalEventToUI, 0xff96f6cc) // 21/0
NHSTUB(ProtectFile, 0xff868e78)
// Best match: 92%
NHSTUB(PutInNdFilter, 0xffacaac4)
// ALT: NHSTUB(PutInNdFilter, 0xffacaac4) // 25/2
// ALT: NHSTUB(PutInNdFilter, 0xffacc654) // 25/2
// ALT: NHSTUB(PutInNdFilter, 0xffacc654) // 25/2
// ALT: NHSTUB(PutInNdFilter, 0xffacc69c) // 25/2
// ALT: NHSTUB(PutInNdFilter, 0xffacc69c) // 25/2
// Best match: 94%
NHSTUB(PutOutNdFilter, 0xffacab0c)
// ALT: NHSTUB(PutOutNdFilter, 0xffacab0c) // 16/1
NHSTUB(Read, 0xff870600)
NHSTUB(RefreshPhysicalScreen, 0xff98a644)
NHSTUB(Remove, 0xff87058c)
NHSTUB(RenameFile_Fut, 0xff86968c)
NHSTUB(Restart, 0xff822b34)
// Best match: 95%
NHSTUB(SetAE_ShutterSpeed, 0xffad0598)
NHSTUB(SetAutoShutdownTime, 0xff973778)
NHSTUB(SetCurrentCaptureModeType, 0xff9a66a0)
NHSTUB(SetFileAttributes, 0xff870724)
// Best match: 88%
NHSTUB(SetLogicalEventActive, 0xff971544)
// Best match: 86%
NHSTUB(SetParameterData, 0xff9785cc)
NHSTUB(SetPropertyCase, 0xff8247c4)
NHSTUB(SleepTask, 0xff821530)
NHSTUB(TakeSemaphore, 0xff82102c)
NHSTUB(TurnOffBackLight, 0xff9be4e8)
NHSTUB(TurnOnBackLight, 0xff9be4b8)
// Best match: 78%
//NHSTUB(UnlockAF, 0xff904870) -- stubs_entry_2.S = 0xff95cb00
// ALT: NHSTUB(UnlockAF, 0xff95cb04) // 11/3
NHSTUB(UnlockMainPower, 0xff97390c)
NHSTUB(Unmount_FileSystem, 0xff86f940)
// Best match: 89%
NHSTUB(UnsetZoomForMovie, 0xff9b1680)
NHSTUB(UpdateMBROnFlash, 0xff86fa90)
// ERROR: VbattGet is not found!
NHSTUB(Write, 0xff87060c)
// Best match: 64%
NHSTUB(WriteSDCard, 0xff87ef94)
NHSTUB(_log, 0xffb079f8)
// ALT: NHSTUB(_log, 0xffb079f8) // 27/0
NHSTUB(_log10, 0xffb03d98)
// ALT: NHSTUB(_log10, 0xffb03d98) // 27/0
NHSTUB(_pow, 0xffb03f20)
// ALT: NHSTUB(_pow, 0xffb03f20) // 25/0
NHSTUB(_sqrt, 0xffb05df4)
// ALT: NHSTUB(_sqrt, 0xffb05df4) // 24/0
// Best match: 96%
NHSTUB(add_ptp_handler, 0xffa7e780)
NHSTUB(apex2us, 0xff8b2d78)
NHSTUB(chdir, 0xffb12b90)
// ALT: NHSTUB(chdir, 0xffb12b90) // 27/0
NHSTUB(close, 0xffb124d0)
NHSTUB(closedir, 0xffb0f958)
NHSTUB(errnoOfTaskGet, 0xffb10124)
// Best match: 93%
NHSTUB(exmem_alloc, 0xff81282c)
// ERROR: free is not found!
NHSTUB(ints_disable, 0xff81da9c)
NHSTUB(ints_enable, 0xff81daa8)
NHSTUB(ioctl, 0xffb12610)
NHSTUB(iosDevAdd, 0xffb136f0)
NHSTUB(iosDevDelete, 0xffb136c8)
NHSTUB(iosDevFind, 0xffb1367c)
NHSTUB(iosDrvInstall, 0xffb139b4)
NHSTUB(isalpha, 0xffb099fc)
NHSTUB(isdigit, 0xffb09a2c)
NHSTUB(islower, 0xffb09a5c)
NHSTUB(ispunct, 0xffb09a8c)
NHSTUB(isspace, 0xffb09aa4)
NHSTUB(isupper, 0xffb09abc)
NHSTUB(isxdigit, 0xffb09ad4)
NHSTUB(kbd_p1_f, 0xff826cec)
NHSTUB(kbd_p1_f_cont, 0xff826cf8)
NHSTUB(kbd_p2_f, 0xff8270d0)
// Best match: 83%
//NHSTUB(kbd_pwr_off, 0xff827fdc) -- stubs_entry_2.S = 0xff827ff8
// ALT: NHSTUB(kbd_pwr_off, 0xff827fdc) // 5/1
// ALT: NHSTUB(kbd_pwr_off, 0xff827ff8) // 5/1
// ALT: NHSTUB(kbd_pwr_off, 0xff827ff8) // 5/1
// ALT: NHSTUB(kbd_pwr_off, 0xff829e4c) // 5/1
// ALT: NHSTUB(kbd_pwr_off, 0xff829e68) // 5/1
// ALT: NHSTUB(kbd_pwr_off, 0xff829f54) // 5/1
// ALT: NHSTUB(kbd_pwr_off, 0xff829f70) // 5/1
// ALT: NHSTUB(kbd_pwr_off, 0xff82a040) // 5/1
// ALT: NHSTUB(kbd_pwr_off, 0xff82a05c) // 5/1
// ALT: NHSTUB(kbd_pwr_off, 0xff82a1a4) // 5/1
// ALT: NHSTUB(kbd_pwr_off, 0xff82a1c0) // 5/1
// ERROR: kbd_pwr_on is not found!
NHSTUB(kbd_read_keys_r2, 0xff827aac)
// Best match: 93%
NHSTUB(localtime, 0xffb0e14c)
NHSTUB(lseek, 0xffb12614)
// Best match: 53%
NHSTUB(malloc, 0xffb15510)
// ALT: NHSTUB(malloc, 0xffb15510) // 15/13
NHSTUB(memPartInfoGet, 0xffb15930)
NHSTUB(memchr, 0xffb0d4f8)
NHSTUB(memcmp, 0xffb0d52c)
// ALT: NHSTUB(memcmp, 0xffb1a0f0) // 9/0
NHSTUB(memcpy, 0xffb0d568)
NHSTUB(memset, 0xffb0d5e0)
NHSTUB(mkdir, 0xff870754)
NHSTUB(mktime, 0xffb0e314)
NHSTUB(open, 0xffb12b14)
NHSTUB(opendir, 0xffb0f98c)
NHSTUB(qsort, 0xffb0cd8c)
NHSTUB(rand, 0xffb0cdb0)
// ALT: NHSTUB(rand, 0xffb0cdb0) // 8/0
NHSTUB(read, 0xffb12530)
NHSTUB(readdir, 0xffb0f924)
NHSTUB(rename, 0xffb12b1c)
// ALT: NHSTUB(rename, 0xffb12b1c) // 26/0
NHSTUB(rewinddir, 0xffb0f94c)
NHSTUB(srand, 0xffb0cdd4)
// ALT: NHSTUB(srand, 0xffb0cdd4) // 4/0
NHSTUB(stat, 0xffb0fa20)
NHSTUB(strcat, 0xffb0d600)
NHSTUB(strchr, 0xffb0d62c)
NHSTUB(strcmp, 0xffb0d650)
NHSTUB(strcpy, 0xffb0d7e4)
NHSTUB(strftime, 0xffb0ee6c)
NHSTUB(strlen, 0xffb0d948)
NHSTUB(strncmp, 0xffb0d9ac)
NHSTUB(strncpy, 0xffb0d9f0)
// ALT: NHSTUB(strncpy, 0xffb0d9f0) // 24/0
NHSTUB(strpbrk, 0xffb0da38)
NHSTUB(strrchr, 0xffb0da74)
// ALT: NHSTUB(strrchr, 0xffb0da74) // 8/0
NHSTUB(strtol, 0xffb0d1c8)
NHSTUB(strtoul, 0xffb0d370)
NHSTUB(taskCreateHookAdd, 0xffb18b90)
NHSTUB(taskDeleteHookAdd, 0xffb18acc)
// Best match: 82%
NHSTUB(taskIdListGet, 0xffb22b58)
NHSTUB(taskLock, 0xffb23214)
NHSTUB(taskName, 0xffb22a50)
NHSTUB(taskResume, 0xffb22e34)
NHSTUB(taskSuspend, 0xffb22c60)
NHSTUB(taskUnlock, 0xffb232bc)
NHSTUB(time, 0xffb0ee98)
// ALT: NHSTUB(time, 0xffb0ee98) // 25/0
NHSTUB(tolower, 0xffb09aec)
NHSTUB(toupper, 0xffb09afc)
NHSTUB(utime, 0xffb0fab4)
// ALT: NHSTUB(utime, 0xffb0fab4) // 26/0
NHSTUB(vsprintf, 0xffb11278)
NHSTUB(write, 0xffb125a0)
