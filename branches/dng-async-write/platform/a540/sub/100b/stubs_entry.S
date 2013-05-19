// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

NHSTUB(AllocateMemory, 0xffc01ab0)
NHSTUB(AllocateUncacheableMemory, 0xffc048f0)
NHSTUB(Close, 0xffc5e4c4)
NHSTUB(CreatePhysicalVram, 0xffd2332c)
NHSTUB(CreateTask, 0xffc1125c)
NHSTUB(CreateTaskStrict, 0xffc122fc)
NHSTUB(DeleteFile_Fut, 0xffc57634)
NHSTUB(DisableDispatch, 0xffc11080)
// Best match: 96%
NHSTUB(DisplayImagePhysicalScreen, 0xffd22660)
// Best match: 56%
//NHSTUB(DoAFLock, 0xffd41c5c) -- stubs_entry_2.S = 0xffd41c64
NHSTUB(EnableDispatch, 0xffc1110c)
// ERROR: EnterToCompensationEVF is not found!
NHSTUB(ExecuteEventProcedure, 0xffc06808)
// Best match: 73%
//NHSTUB(ExitFromCompensationEVF, 0xffd43b60) -- stubs_entry_2.S = 0xffd43b28
NHSTUB(ExitTask, 0xffc1161c)
NHSTUB(Fclose_Fut, 0xffc57774)
NHSTUB(Feof_Fut, 0xffc57988)
NHSTUB(Fflush_Fut, 0xffc579c0)
NHSTUB(Fgets_Fut, 0xffc578f8)
NHSTUB(Fopen_Fut, 0xffc57738)
NHSTUB(Fread_Fut, 0xffc57858)
NHSTUB(FreeMemory, 0xffc01abc)
NHSTUB(FreeUncacheableMemory, 0xffc04924)
NHSTUB(Fseek_Fut, 0xffc57940)
NHSTUB(Fwrite_Fut, 0xffc578a8)
// Best match: 96%
NHSTUB(GetBatteryTemperature, 0xffc1d044)
// Best match: 96%
NHSTUB(GetCCDTemperature, 0xffc1d030)
NHSTUB(GetCurrentAvValue, 0xffe972cc)
// ALT: NHSTUB(GetCurrentAvValue, 0xffe996d4) // 13/0
NHSTUB(GetCurrentTargetDistance, 0xffe9967c)
// Best match: 80%
//NHSTUB(GetDrive_ClusterSize, 0xffc5dd14) -- stubs_entry_2.S = 0xffc5dc9c
// Best match: 80%
//NHSTUB(GetDrive_FreeClusters, 0xffc5dcd8) -- stubs_entry_2.S = 0xffc5dd14
// Best match: 84%
//NHSTUB(GetDrive_TotalClusters, 0xffc5dc9c) -- stubs_entry_2.S = 0xffc5dcd8
// Best match: 54%
NHSTUB(GetFocusLensSubjectDistance, 0xffe8b798)
// ALT: NHSTUB(GetFocusLensSubjectDistance, 0xffe8b798) // 17/14
// Best match: 92%
NHSTUB(GetFocusLensSubjectDistanceFromLens, 0xffe8bd34)
// Best match: 96%
NHSTUB(GetOpticalTemperature, 0xffc1d01c)
// Best match: 86%
NHSTUB(GetParameterData, 0xffd5d738)
NHSTUB(GetPropertyCase, 0xffc144f0)
// Best match: 96%
NHSTUB(GetSystemTime, 0xffc04b28)
// ALT: NHSTUB(GetSystemTime, 0xffc04b28) // 26/1
// Best match: 93%
NHSTUB(GetZoomLensCurrentPoint, 0xffe781a0)
// ALT: NHSTUB(GetZoomLensCurrentPoint, 0xffe781a0) // 27/2
// Best match: 93%
NHSTUB(GetZoomLensCurrentPosition, 0xffe781b4)
// ALT: NHSTUB(GetZoomLensCurrentPosition, 0xffe781b4) // 27/2
NHSTUB(IsStrobeChargeCompleted, 0xffcfe554)
NHSTUB(LockMainPower, 0xffd58674)
// ERROR: MakeAFScan is not found!
NHSTUB(MakeDirectory, 0xffc5e768)
NHSTUB(MakeDirectory_Fut, 0xffc576c0)
// Best match: 90%
NHSTUB(Mount_FileSystem, 0xffc5d768)
// ALT: NHSTUB(Mount_FileSystem, 0xffc5d768) // 27/3
// Best match: 96%
NHSTUB(MoveFocusLensToDistance, 0xffe9991c)
NHSTUB(MoveZoomLensWithPoint, 0xffe78080)
// ALT: NHSTUB(MoveZoomLensWithPoint, 0xffe78080) // 25/0
NHSTUB(Open, 0xffc5e49c)
NHSTUB(PT_PlaySound, 0xffd4fb34)
// Best match: 89%
NHSTUB(PhySw_testgpio, 0xffc17d5c)
NHSTUB(PostLogicalEventForNotPowerType, 0xffd54630)
NHSTUB(PostLogicalEventToUI, 0xffd546ac)
// ALT: NHSTUB(PostLogicalEventToUI, 0xffd54734) // 21/0
NHSTUB(ProtectFile, 0xffc56da0)
// Best match: 92%
NHSTUB(PutInNdFilter, 0xffe972e0)
// ALT: NHSTUB(PutInNdFilter, 0xffe972e0) // 25/2
// ALT: NHSTUB(PutInNdFilter, 0xffe97328) // 25/2
// ALT: NHSTUB(PutInNdFilter, 0xffe97328) // 25/2
// ALT: NHSTUB(PutInNdFilter, 0xffe976ec) // 25/2
// ALT: NHSTUB(PutInNdFilter, 0xffe976ec) // 25/2
// ALT: NHSTUB(PutInNdFilter, 0xffe9927c) // 25/2
// ALT: NHSTUB(PutInNdFilter, 0xffe9927c) // 25/2
// ALT: NHSTUB(PutInNdFilter, 0xffe992c4) // 25/2
// ALT: NHSTUB(PutInNdFilter, 0xffe992c4) // 25/2
// Best match: 94%
NHSTUB(PutOutNdFilter, 0xffe97734)
// ALT: NHSTUB(PutOutNdFilter, 0xffe97734) // 16/1
NHSTUB(Read, 0xffc5e558)
NHSTUB(RefreshPhysicalScreen, 0xffd6f828)
NHSTUB(Remove, 0xffc5e4e4)
NHSTUB(RenameFile_Fut, 0xffc575b4)
NHSTUB(Restart, 0xffc12774)
// Best match: 95%
NHSTUB(SetAE_ShutterSpeed, 0xffe9d1c4)
NHSTUB(SetAutoShutdownTime, 0xffd58578)
NHSTUB(SetCurrentCaptureModeType, 0xffd88b20)
NHSTUB(SetFileAttributes, 0xffc5e67c)
// Best match: 88%
NHSTUB(SetLogicalEventActive, 0xffd563f8)
// Best match: 86%
NHSTUB(SetParameterData, 0xffd5d658)
NHSTUB(SetPropertyCase, 0xffc143d4)
NHSTUB(SleepTask, 0xffc11170)
NHSTUB(TakeSemaphore, 0xffc10c6c)
NHSTUB(TurnOffBackLight, 0xffda486c)
NHSTUB(TurnOnBackLight, 0xffda483c)
// Best match: 78%
//NHSTUB(UnlockAF, 0xffcf16c8) -- stubs_entry_2.S = 0xffd41ca8
// ALT: NHSTUB(UnlockAF, 0xffd41cac) // 11/3
NHSTUB(UnlockMainPower, 0xffd5870c)
NHSTUB(Unmount_FileSystem, 0xffc5d880)
// Best match: 89%
NHSTUB(UnsetZoomForMovie, 0xffd93bdc)
NHSTUB(UpdateMBROnFlash, 0xffc5d9d4)
// ERROR: VbattGet is not found!
NHSTUB(Write, 0xffc5e564)
// Best match: 64%
//NHSTUB(WriteSDCard, 0xffc6cf38) -- stubs_entry_2.S = 0xffc6d0e0
NHSTUB(_log, 0xffed331c)
// ALT: NHSTUB(_log, 0xffed331c) // 27/0
NHSTUB(_log10, 0xffecf7f4)
// ALT: NHSTUB(_log10, 0xffecf7f4) // 27/0
NHSTUB(_pow, 0xffecf97c)
// ALT: NHSTUB(_pow, 0xffecf97c) // 25/0
NHSTUB(_sqrt, 0xffed1718)
// ALT: NHSTUB(_sqrt, 0xffed1718) // 24/0
// Best match: 96%
NHSTUB(add_ptp_handler, 0xffe46ddc)
NHSTUB(apex2us, 0xffc9f288)
NHSTUB(chdir, 0xffede5e4)
// ALT: NHSTUB(chdir, 0xffede5e4) // 27/0
NHSTUB(close, 0xffeddf24)
NHSTUB(closedir, 0xffedb3ac)
NHSTUB(errnoOfTaskGet, 0xffedbb78)
// Best match: 93%
NHSTUB(exmem_alloc, 0xffc02818)
// ERROR: free is not found!
NHSTUB(ints_disable, 0xffc0d6dc)
NHSTUB(ints_enable, 0xffc0d6e8)
NHSTUB(ioctl, 0xffede064)
NHSTUB(iosDevAdd, 0xffedf144)
NHSTUB(iosDevDelete, 0xffedf11c)
NHSTUB(iosDevFind, 0xffedf0d0)
NHSTUB(iosDrvInstall, 0xffedf408)
NHSTUB(isalpha, 0xffed5320)
NHSTUB(isdigit, 0xffed5350)
NHSTUB(islower, 0xffed5380)
NHSTUB(ispunct, 0xffed53b0)
NHSTUB(isspace, 0xffed53c8)
NHSTUB(isupper, 0xffed53e0)
NHSTUB(isxdigit, 0xffed53f8)
NHSTUB(kbd_p1_f, 0xffc1692c)
NHSTUB(kbd_p1_f_cont, 0xffc16938)
NHSTUB(kbd_p2_f, 0xffc16d10)
NHSTUB(kbd_pwr_off, 0xffc17ce8)
// ALT: NHSTUB(kbd_pwr_off, 0xffc17d18) // 6/0
// ALT: NHSTUB(kbd_pwr_off, 0xffc17d34) // 6/0
NHSTUB(kbd_pwr_on, 0xffc17cc0)
NHSTUB(kbd_read_keys_r2, 0xffc17730)
// Best match: 93%
NHSTUB(localtime, 0xffed9ba0)
NHSTUB(lseek, 0xffede068)
// Best match: 53%
NHSTUB(malloc, 0xffee0f64)
// ALT: NHSTUB(malloc, 0xffee0f64) // 15/13
NHSTUB(memPartInfoGet, 0xffee1384)
NHSTUB(memchr, 0xffed8f4c)
NHSTUB(memcmp, 0xffed8f80)
// ALT: NHSTUB(memcmp, 0xffee5124) // 9/0
NHSTUB(memcpy, 0xffed8fbc)
NHSTUB(memset, 0xffed9034)
NHSTUB(mkdir, 0xffc5e6ac)
NHSTUB(mktime, 0xffed9d68)
NHSTUB(open, 0xffede568)
NHSTUB(opendir, 0xffedb3e0)
NHSTUB(qsort, 0xffed87e0)
NHSTUB(rand, 0xffed8804)
// ALT: NHSTUB(rand, 0xffed8804) // 8/0
NHSTUB(read, 0xffeddf84)
NHSTUB(readdir, 0xffedb378)
NHSTUB(rename, 0xffede570)
// ALT: NHSTUB(rename, 0xffede570) // 26/0
NHSTUB(rewinddir, 0xffedb3a0)
NHSTUB(srand, 0xffed8828)
// ALT: NHSTUB(srand, 0xffed8828) // 4/0
NHSTUB(stat, 0xffedb474)
NHSTUB(strcat, 0xffed9054)
NHSTUB(strchr, 0xffed9080)
NHSTUB(strcmp, 0xffed90a4)
NHSTUB(strcpy, 0xffed9238)
NHSTUB(strftime, 0xffeda8c0)
NHSTUB(strlen, 0xffed939c)
NHSTUB(strncmp, 0xffed9400)
NHSTUB(strncpy, 0xffed9444)
// ALT: NHSTUB(strncpy, 0xffed9444) // 24/0
NHSTUB(strpbrk, 0xffed948c)
NHSTUB(strrchr, 0xffed94c8)
// ALT: NHSTUB(strrchr, 0xffed94c8) // 8/0
NHSTUB(strtol, 0xffed8c1c)
NHSTUB(strtoul, 0xffed8dc4)
NHSTUB(taskCreateHookAdd, 0xffee3bc4)
NHSTUB(taskDeleteHookAdd, 0xffee3b00)
// Best match: 82%
NHSTUB(taskIdListGet, 0xffeedb8c)
NHSTUB(taskLock, 0xffeee248)
NHSTUB(taskName, 0xffeeda84)
NHSTUB(taskResume, 0xffeede68)
NHSTUB(taskSuspend, 0xffeedc94)
NHSTUB(taskUnlock, 0xffeee2f0)
NHSTUB(time, 0xffeda8ec)
// ALT: NHSTUB(time, 0xffeda8ec) // 25/0
NHSTUB(tolower, 0xffed5410)
NHSTUB(toupper, 0xffed5420)
NHSTUB(utime, 0xffedb508)
// ALT: NHSTUB(utime, 0xffedb508) // 26/0
NHSTUB(vsprintf, 0xffedcccc)
NHSTUB(write, 0xffeddff4)
