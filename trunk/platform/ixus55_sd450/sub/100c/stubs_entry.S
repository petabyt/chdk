// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

NHSTUB(AllocateMemory, 0xff811acc)
NHSTUB(AllocateUncacheableMemory, 0xff814bb0)
NHSTUB(Close, 0xff86e2c0)
NHSTUB(CreatePhysicalVram, 0xff9241ac)
NHSTUB(CreateTask, 0xff821508)
NHSTUB(CreateTaskStrict, 0xff822670)
NHSTUB(DeleteFile_Fut, 0xff867774)
NHSTUB(DisableDispatch, 0xff82132c)
NHSTUB(DisplayImagePhysicalScreen, 0xff923574)
NHSTUB(DoAFLock, 0xff94a1d0)
NHSTUB(EnableDispatch, 0xff8213b8)
// Best match: 64%
NHSTUB(EnterToCompensationEVF, 0xff94c024)
NHSTUB(ExecuteEventProcedure, 0xff816ac8)
// Best match: 73%
//NHSTUB(ExitFromCompensationEVF, 0xff94c0f0) -- stubs_entry_2.S = 0xff94c084
NHSTUB(ExitTask, 0xff8218c8)
NHSTUB(Fclose_Fut, 0xff8678b4)
NHSTUB(Feof_Fut, 0xff867ac8)
NHSTUB(Fflush_Fut, 0xff867b00)
NHSTUB(Fgets_Fut, 0xff867a38)
NHSTUB(Fopen_Fut, 0xff867878)
NHSTUB(Fread_Fut, 0xff867998)
NHSTUB(FreeMemory, 0xff811ad8)
NHSTUB(FreeUncacheableMemory, 0xff814be4)
NHSTUB(Fseek_Fut, 0xff867a80)
NHSTUB(Fwrite_Fut, 0xff8679e8)
// Best match: 82%
NHSTUB(GetBatteryTemperature, 0xff82c6d4)
// Best match: 82%
NHSTUB(GetCCDTemperature, 0xff82c6c0)
NHSTUB(GetCurrentAvValue, 0xffa8aa84)
NHSTUB(GetCurrentTargetDistance, 0xffa8aa2c)
// Best match: 92%
NHSTUB(GetDrive_ClusterSize, 0xff86da9c)
// Best match: 92%
NHSTUB(GetDrive_FreeClusters, 0xff86db14)
// Best match: 92%
NHSTUB(GetDrive_TotalClusters, 0xff86dad8)
// Best match: 96%
NHSTUB(GetFocusLensSubjectDistance, 0xffa7ddec)
// Best match: 92%
NHSTUB(GetFocusLensSubjectDistanceFromLens, 0xffa7e38c)
// Best match: 82%
NHSTUB(GetOpticalTemperature, 0xff82c6ac)
NHSTUB(GetParameterData, 0xff964448)
NHSTUB(GetPropertyCase, 0xff82447c)
// Best match: 96%
NHSTUB(GetSystemTime, 0xff814de8)
// ALT: NHSTUB(GetSystemTime, 0xff814de8) // 26/1
// Best match: 93%
NHSTUB(GetZoomLensCurrentPoint, 0xffa6ec8c)
// ALT: NHSTUB(GetZoomLensCurrentPoint, 0xffa6ec8c) // 27/2
// Best match: 93%
NHSTUB(GetZoomLensCurrentPosition, 0xffa6eca0)
// ALT: NHSTUB(GetZoomLensCurrentPosition, 0xffa6eca0) // 27/2
NHSTUB(IsStrobeChargeCompleted, 0xff8fdd38)
// Best match: 96%
NHSTUB(LockMainPower, 0xff95f90c)
// Best match: 96%
NHSTUB(MakeAFScan, 0xff94e624)
NHSTUB(MakeDirectory, 0xff86e564)
NHSTUB(MakeDirectory_Fut, 0xff867800)
// Best match: 90%
NHSTUB(Mount_FileSystem, 0xff86d574)
// ALT: NHSTUB(Mount_FileSystem, 0xff86d574) // 27/3
// Best match: 96%
NHSTUB(MoveFocusLensToDistance, 0xffa8acbc)
NHSTUB(MoveZoomLensWithPoint, 0xffa6eb6c)
// ALT: NHSTUB(MoveZoomLensWithPoint, 0xffa6eb6c) // 25/0
NHSTUB(Open, 0xff86e298)
NHSTUB(PT_PlaySound, 0xff9571cc)
// Best match: 96%
NHSTUB(PhySw_testgpio, 0xff827800)
NHSTUB(PostLogicalEventForNotPowerType, 0xff95b954)
NHSTUB(PostLogicalEventToUI, 0xff95b9e0)
// ALT: NHSTUB(PostLogicalEventToUI, 0xff95ba78) // 25/0
NHSTUB(ProtectFile, 0xff866ee0)
// Best match: 92%
NHSTUB(PutInNdFilter, 0xffa88aa4)
// ALT: NHSTUB(PutInNdFilter, 0xffa88aa4) // 25/2
// ALT: NHSTUB(PutInNdFilter, 0xffa8a630) // 25/2
// ALT: NHSTUB(PutInNdFilter, 0xffa8a630) // 25/2
// ALT: NHSTUB(PutInNdFilter, 0xffa8a678) // 25/2
// ALT: NHSTUB(PutInNdFilter, 0xffa8a678) // 25/2
// Best match: 94%
NHSTUB(PutOutNdFilter, 0xffa88aec)
// ALT: NHSTUB(PutOutNdFilter, 0xffa88aec) // 16/1
NHSTUB(Read, 0xff86e354)
NHSTUB(RefreshPhysicalScreen, 0xff974dfc)
NHSTUB(Remove, 0xff86e2e0)
NHSTUB(RenameFile_Fut, 0xff8676f4)
NHSTUB(Restart, 0xff822ab8)
// Best match: 95%
NHSTUB(SetAE_ShutterSpeed, 0xffa8dd70)
// Best match: 96%
NHSTUB(SetAutoShutdownTime, 0xff95f804)
NHSTUB(SetCurrentCaptureModeType, 0xff98c010)
NHSTUB(SetFileAttributes, 0xff86e478)
// Best match: 87%
NHSTUB(SetLogicalEventActive, 0xff95d9b0)
NHSTUB(SetParameterData, 0xff964368)
NHSTUB(SetPropertyCase, 0xff824360)
NHSTUB(SleepTask, 0xff82141c)
NHSTUB(TakeSemaphore, 0xff820f18)
NHSTUB(TurnOffBackLight, 0xff9a23e4)
NHSTUB(TurnOnBackLight, 0xff9a23b8)
NHSTUB(UnlockAF, 0xff94a210)
// Best match: 96%
NHSTUB(UnlockMainPower, 0xff95f9c0)
NHSTUB(Unmount_FileSystem, 0xff86d67c)
// Best match: 89%
NHSTUB(UnsetZoomForMovie, 0xff996b94)
NHSTUB(UpdateMBROnFlash, 0xff86d7d4)
// ERROR: VbattGet is not found!
NHSTUB(Write, 0xff86e360)
NHSTUB(WriteSDCard, 0xff87cb8c)
NHSTUB(_log, 0xffabffd8)
// ALT: NHSTUB(_log, 0xffabffd8) // 27/0
NHSTUB(_log10, 0xffac0680)
// ALT: NHSTUB(_log10, 0xffac0680) // 27/0
NHSTUB(_pow, 0xffac0b70)
// ALT: NHSTUB(_pow, 0xffac0b70) // 25/0
NHSTUB(_sqrt, 0xffac4ebc)
// ALT: NHSTUB(_sqrt, 0xffac4ebc) // 24/0
// Best match: 96%
NHSTUB(add_ptp_handler, 0xffa3d19c)
NHSTUB(apex2us, 0xff8ab374)
NHSTUB(chdir, 0xffad4118)
// ALT: NHSTUB(chdir, 0xffad4118) // 27/0
NHSTUB(close, 0xffad3a58)
NHSTUB(closedir, 0xffacf9f8)
NHSTUB(errnoOfTaskGet, 0xffad01c4)
NHSTUB(exmem_alloc, 0xff8127e0)
// ERROR: free is not found!
NHSTUB(ints_disable, 0xff81d8a4)
NHSTUB(ints_enable, 0xff81d8b0)
NHSTUB(ioctl, 0xffad3b98)
NHSTUB(iosDevAdd, 0xffad4c78)
NHSTUB(iosDevDelete, 0xffad4c50)
NHSTUB(iosDevFind, 0xffad4c04)
NHSTUB(iosDrvInstall, 0xffad4f3c)
NHSTUB(isalpha, 0xffac996c)
NHSTUB(isdigit, 0xffac999c)
NHSTUB(islower, 0xffac99cc)
NHSTUB(ispunct, 0xffac99fc)
NHSTUB(isspace, 0xffac9a14)
NHSTUB(isupper, 0xffac9a2c)
NHSTUB(isxdigit, 0xffac9a44)
NHSTUB(kbd_p1_f, 0xff82647c)
NHSTUB(kbd_p1_f_cont, 0xff826488)
NHSTUB(kbd_p2_f, 0xff826860)
// Best match: 83%
NHSTUB(kbd_pwr_off, 0xff8277c8)
// ALT: NHSTUB(kbd_pwr_off, 0xff8277c8) // 5/1
// ALT: NHSTUB(kbd_pwr_off, 0xff8277e4) // 5/1
// ALT: NHSTUB(kbd_pwr_off, 0xff8277e4) // 5/1
// ALT: NHSTUB(kbd_pwr_off, 0xff828454) // 5/1
// ALT: NHSTUB(kbd_pwr_off, 0xff828470) // 5/1
// ALT: NHSTUB(kbd_pwr_off, 0xff82855c) // 5/1
// ALT: NHSTUB(kbd_pwr_off, 0xff828578) // 5/1
// ALT: NHSTUB(kbd_pwr_off, 0xff828648) // 5/1
// ALT: NHSTUB(kbd_pwr_off, 0xff828664) // 5/1
// ALT: NHSTUB(kbd_pwr_off, 0xff8287ac) // 5/1
// ALT: NHSTUB(kbd_pwr_off, 0xff8287c8) // 5/1
// Best match: 55%
NHSTUB(kbd_pwr_on, 0xff8276dc)
// ALT: NHSTUB(kbd_pwr_on, 0xff922694) // 5/4
// ALT: NHSTUB(kbd_pwr_on, 0xff9226c0) // 5/4
// ALT: NHSTUB(kbd_pwr_on, 0xff9227fc) // 5/4
// ALT: NHSTUB(kbd_pwr_on, 0xffa74374) // 5/4
// ALT: NHSTUB(kbd_pwr_on, 0xffa743a0) // 5/4
NHSTUB(kbd_read_keys_r2, 0xff827260)
// Best match: 93%
NHSTUB(localtime, 0xfface1ec)
NHSTUB(lseek, 0xffad3b9c)
// Best match: 53%
NHSTUB(malloc, 0xffad6a98)
// ALT: NHSTUB(malloc, 0xffad6a98) // 15/13
NHSTUB(memPartInfoGet, 0xffad6eb8)
NHSTUB(memchr, 0xffacd598)
NHSTUB(memcmp, 0xffacd5cc)
// ALT: NHSTUB(memcmp, 0xffadb9b4) // 9/0
NHSTUB(memcpy, 0xffacd608)
NHSTUB(memset, 0xffacd680)
NHSTUB(mkdir, 0xff86e4a8)
NHSTUB(mktime, 0xfface3b4)
NHSTUB(open, 0xffad409c)
NHSTUB(opendir, 0xffacfa2c)
NHSTUB(qsort, 0xffacce2c)
NHSTUB(rand, 0xffacce50)
// ALT: NHSTUB(rand, 0xffacce50) // 8/0
NHSTUB(read, 0xffad3ab8)
NHSTUB(readdir, 0xffacf9c4)
NHSTUB(rename, 0xffad40a4)
// ALT: NHSTUB(rename, 0xffad40a4) // 26/0
NHSTUB(rewinddir, 0xffacf9ec)
NHSTUB(srand, 0xffacce74)
// ALT: NHSTUB(srand, 0xffacce74) // 4/0
NHSTUB(stat, 0xffacfac0)
NHSTUB(strcat, 0xffacd6a0)
NHSTUB(strchr, 0xffacd6cc)
NHSTUB(strcmp, 0xffacd6f0)
NHSTUB(strcpy, 0xffacd884)
NHSTUB(strftime, 0xffacef0c)
NHSTUB(strlen, 0xffacd9e8)
NHSTUB(strncmp, 0xffacda4c)
NHSTUB(strncpy, 0xffacda90)
// ALT: NHSTUB(strncpy, 0xffacda90) // 24/0
NHSTUB(strpbrk, 0xffacdad8)
NHSTUB(strrchr, 0xffacdb14)
// ALT: NHSTUB(strrchr, 0xffacdb14) // 8/0
NHSTUB(strtol, 0xffacd268)
NHSTUB(strtoul, 0xffacd410)
NHSTUB(taskCreateHookAdd, 0xffada118)
NHSTUB(taskDeleteHookAdd, 0xffada054)
// Best match: 82%
NHSTUB(taskIdListGet, 0xffae46dc)
NHSTUB(taskLock, 0xffae4d98)
NHSTUB(taskName, 0xffae45d4)
NHSTUB(taskResume, 0xffae49b8)
NHSTUB(taskSuspend, 0xffae47e4)
NHSTUB(taskUnlock, 0xffae4e40)
NHSTUB(time, 0xffacef38)
// ALT: NHSTUB(time, 0xffacef38) // 25/0
NHSTUB(tolower, 0xffac9a5c)
NHSTUB(toupper, 0xffac9a6c)
NHSTUB(utime, 0xffacfb54)
// ALT: NHSTUB(utime, 0xffacfb54) // 26/0
NHSTUB(vsprintf, 0xffad1318)
NHSTUB(write, 0xffad3b28)
