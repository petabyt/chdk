// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

NSTUB(AllocateMemory, 0xff811ac4)
NSTUB(AllocateUncacheableMemory, 0xff814cb0)
NSTUB(Close, 0xff87056c)
NSTUB(CreatePhysicalVram, 0xff935f78)
NSTUB(CreateTask, 0xff82161c)
NSTUB(CreateTaskStrict, 0xff8226bc)
NSTUB(DisableDispatch, 0xff821440)
// Best match: 96%
NSTUB(DisplayImagePhysicalScreen, 0xff9352ac)
NSTUB(EnableDispatch, 0xff8214cc)
NSTUB(ExecuteEventProcedure, 0xff816bc8)
NSTUB(ExitTask, 0xff8219dc)
NSTUB(FreeMemory, 0xff811ad0)
NSTUB(FreeUncacheableMemory, 0xff814ce4)
NSTUB(GetCurrentAvValue, 0xffaccaa8)
NSTUB(GetCurrentTargetDistance, 0xffacca50)
// Best match: 96%
NSTUB(GetFocusLensSubjectDistance, 0xffabed90)
// Best match: 86%
NSTUB(GetParameterData, 0xff9786ac)
NSTUB(GetPropertyCase, 0xff8248e0)
// Best match: 96%
NSTUB(GetSystemTime, 0xff814ee8)
// ALT: NSTUB(GetSystemTime, 0xff814ee8) // 26/1
// Best match: 93%
NSTUB(GetZoomLensCurrentPoint, 0xffaafa08)
// ALT: NSTUB(GetZoomLensCurrentPoint, 0xffaafa08) // 27/2
// Best match: 93%
NSTUB(GetZoomLensCurrentPosition, 0xffaafa1c)
// ALT: NSTUB(GetZoomLensCurrentPosition, 0xffaafa1c) // 27/2
NSTUB(IsStrobeChargeCompleted, 0xff9112ec)
NSTUB(LockMainPower, 0xff973874)
NSTUB(MakeDirectory, 0xff870810)
// Best match: 90%
NSTUB(Mount_FileSystem, 0xff86f89c)
// ALT: NSTUB(Mount_FileSystem, 0xff86f89c) // 27/3
// Best match: 96%
NSTUB(MoveFocusLensToDistance, 0xffacccf0)
NSTUB(MoveZoomLensWithPoint, 0xffaaf8e8)
// ALT: NSTUB(MoveZoomLensWithPoint, 0xffaaf8e8) // 25/0
NSTUB(Open, 0xff870544)
// Best match: 89%
NSTUB(PhySw_testgpio, 0xff828020)
NSTUB(ProtectFile, 0xff868e78)
NSTUB(Read, 0xff870600)
NSTUB(RefreshPhysicalScreen, 0xff98a644)
NSTUB(Remove, 0xff87058c)
// Best match: 86%
NSTUB(SetParameterData, 0xff9785cc)
NSTUB(SetPropertyCase, 0xff8247c4)
NSTUB(SleepTask, 0xff821530)
NSTUB(TakeSemaphore, 0xff82102c)
NSTUB(UnlockMainPower, 0xff97390c)
NSTUB(Unmount_FileSystem, 0xff86f940)
NSTUB(UpdateMBROnFlash, 0xff86fa90)
// ERROR: VbattGet is not found!
NSTUB(Write, 0xff87060c)
NSTUB(_log, 0xffb079f8)
// ALT: NSTUB(_log, 0xffb079f8) // 27/0
NSTUB(_log10, 0xffb03d98)
// ALT: NSTUB(_log10, 0xffb03d98) // 27/0
NSTUB(_pow, 0xffb03f20)
// ALT: NSTUB(_pow, 0xffb03f20) // 25/0
NSTUB(_sqrt, 0xffb05df4)
// ALT: NSTUB(_sqrt, 0xffb05df4) // 24/0
NSTUB(chdir, 0xffb12b90)
// ALT: NSTUB(chdir, 0xffb12b90) // 27/0
NSTUB(close, 0xffb124d0)
NSTUB(closedir, 0xffb0f958)
// ERROR: free is not found!
NSTUB(ints_disable, 0xff81da9c)
NSTUB(ints_enable, 0xff81daa8)
NSTUB(ioctl, 0xffb12610)
NSTUB(iosDevAdd, 0xffb136f0)
NSTUB(iosDrvInstall, 0xffb139b4)
NSTUB(isalpha, 0xffb099fc)
// ALT: NSTUB(isalpha, 0xffb099fc) // 4/0
NSTUB(isdigit, 0xffb09a2c)
// ALT: NSTUB(isdigit, 0xffb09a2c) // 4/0
NSTUB(islower, 0xffb09a5c)
// ALT: NSTUB(islower, 0xffb09a5c) // 4/0
NSTUB(isspace, 0xffb09aa4)
// ALT: NSTUB(isspace, 0xffb09aa4) // 4/0
NSTUB(isupper, 0xffb09abc)
// ALT: NSTUB(isupper, 0xffb09abc) // 4/0
NSTUB(kbd_p1_f, 0xff826cec)
NSTUB(kbd_p1_f_cont, 0xff826cf8)
NSTUB(kbd_p2_f, 0xff8270d0)
// Best match: 83%
NSTUB(kbd_pwr_off, 0xff827fdc)
// ALT: NSTUB(kbd_pwr_off, 0xff827ff8) // 5/1
// ALT: NSTUB(kbd_pwr_off, 0xff82a1a4) // 5/1
// ALT: NSTUB(kbd_pwr_off, 0xff82a1c0) // 5/1
// ERROR: kbd_pwr_on is not found!
NSTUB(kbd_read_keys_r2, 0xff827aac)
// Best match: 93%
NSTUB(localtime, 0xffb0e14c)
NSTUB(lseek, 0xffb12614)
// Best match: 53%
NSTUB(malloc, 0xffb15510)
// ALT: NSTUB(malloc, 0xffb15510) // 15/13
NSTUB(memcmp, 0xffb0d52c)
// ALT: NSTUB(memcmp, 0xffb1a0f0) // 9/0
NSTUB(memcpy, 0xffb0d568)
NSTUB(memset, 0xffb0d5e0)
NSTUB(mkdir, 0xff870754)
NSTUB(open, 0xffb12b14)
NSTUB(opendir, 0xffb0f98c)
NSTUB(qsort, 0xffb0cd8c)
NSTUB(rand, 0xffb0cdb0)
// ALT: NSTUB(rand, 0xffb0cdb0) // 8/0
NSTUB(read, 0xffb12530)
NSTUB(readdir, 0xffb0f924)
NSTUB(rename, 0xffb12b1c)
// ALT: NSTUB(rename, 0xffb12b1c) // 26/0
NSTUB(rewinddir, 0xffb0f94c)
NSTUB(srand, 0xffb0cdd4)
// ALT: NSTUB(srand, 0xffb0cdd4) // 4/0
NSTUB(stat, 0xffb0fa20)
NSTUB(strcat, 0xffb0d600)
NSTUB(strchr, 0xffb0d62c)
NSTUB(strcmp, 0xffb0d650)
NSTUB(strcpy, 0xffb0d7e4)
NSTUB(strlen, 0xffb0d948)
NSTUB(strncmp, 0xffb0d9ac)
NSTUB(strncpy, 0xffb0d9f0)
// ALT: NSTUB(strncpy, 0xffb0d9f0) // 24/0
NSTUB(strpbrk, 0xffb0da38)
NSTUB(strrchr, 0xffb0da74)
// ALT: NSTUB(strrchr, 0xffb0da74) // 8/0
NSTUB(strtol, 0xffb0d1c8)
NSTUB(taskCreateHookAdd, 0xffb18b90)
NSTUB(taskDeleteHookAdd, 0xffb18acc)
// Best match: 82%
NSTUB(taskIdListGet, 0xffb22b58)
NSTUB(taskLock, 0xffb23214)
NSTUB(taskName, 0xffb22a50)
NSTUB(taskResume, 0xffb22e34)
NSTUB(taskSuspend, 0xffb22c60)
NSTUB(taskUnlock, 0xffb232bc)
NSTUB(time, 0xffb0ee98)
// ALT: NSTUB(time, 0xffb0ee98) // 25/0
NSTUB(utime, 0xffb0fab4)
// ALT: NSTUB(utime, 0xffb0fab4) // 26/0
NSTUB(vsprintf, 0xffb11278)
NSTUB(write, 0xffb125a0)
NSTUB(fclose, 0xffb09bc0)
NSTUB(fdopen, 0xffb09cac)
NSTUB(feof, 0xffb09d18)
// ALT: NSTUB(feof, 0xffb09d84) // 17/0
NSTUB(ferror, 0xffb09d18)
// ALT: NSTUB(ferror, 0xffb09d84) // 17/0
NSTUB(fflush, 0xffb09eb0)
NSTUB(fgetc, 0xffb09f24)
NSTUB(fgetpos, 0xffb09fac)
NSTUB(fgets, 0xffb0a010)
NSTUB(fileno, 0xffb0a144)
NSTUB(fopen, 0xffb0a2c8)
NSTUB(fprintf, 0xffb0a35c)
NSTUB(fputs, 0xffb0a47c)
NSTUB(fread, 0xffb0a504)
NSTUB(freopen, 0xffb0a608)
NSTUB(fscanf, 0xffb0a7f0)
NSTUB(fseek, 0xffb0a898)
NSTUB(fsetpos, 0xffb0ac3c)
NSTUB(ftell, 0xffb0ac48)
NSTUB(fwrite, 0xffb0b068)
NSTUB(fstat, 0xffb0f980)
NSTUB(fstatfs, 0xffb0fa64)
NSTUB(fdprintf, 0xffb115dc)
NSTUB(free, 0xffb1551c)
