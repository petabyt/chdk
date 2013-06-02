// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

NHSTUB(AllocateMemory, 0xff811acc)
NHSTUB(AllocateUncacheableMemory, 0xff814bb0)
NHSTUB(Close, 0xff86e648)
NHSTUB(CreatePhysicalVram, 0xff924534)
NHSTUB(CreateTask, 0xff821508)
NHSTUB(CreateTaskStrict, 0xff822670)
NHSTUB(DeleteFile_Fut, 0xff867afc)
NHSTUB(DisableDispatch, 0xff82132c)
NHSTUB(DisplayImagePhysicalScreen, 0xff9238fc)
NHSTUB(DoAFLock, 0xff94a558)
NHSTUB(EnableDispatch, 0xff8213b8)
// Best match: 64%
NHSTUB(EnterToCompensationEVF, 0xff94c3ac)
NHSTUB(ExecuteEventProcedure, 0xff816ac8)
// Best match: 73%
//NHSTUB(ExitFromCompensationEVF, 0xff94c478) -- stubs_entry_2.S = 0xff94c40c
NHSTUB(ExitTask, 0xff8218c8)
NHSTUB(Fclose_Fut, 0xff867c3c)
NHSTUB(Feof_Fut, 0xff867e50)
NHSTUB(Fflush_Fut, 0xff867e88)
NHSTUB(Fgets_Fut, 0xff867dc0)
NHSTUB(Fopen_Fut, 0xff867c00)
NHSTUB(Fread_Fut, 0xff867d20)
NHSTUB(FreeMemory, 0xff811ad8)
NHSTUB(FreeUncacheableMemory, 0xff814be4)
NHSTUB(Fseek_Fut, 0xff867e08)
NHSTUB(Fwrite_Fut, 0xff867d70)
// Best match: 82%
NHSTUB(GetBatteryTemperature, 0xff82c6d4)
// Best match: 82%
NHSTUB(GetCCDTemperature, 0xff82c6c0)
NHSTUB(GetCurrentAvValue, 0xffa8ae0c)
NHSTUB(GetCurrentTargetDistance, 0xffa8adb4)
// Best match: 92%
NHSTUB(GetDrive_ClusterSize, 0xff86de24)
// Best match: 92%
NHSTUB(GetDrive_FreeClusters, 0xff86de9c)
// Best match: 92%
NHSTUB(GetDrive_TotalClusters, 0xff86de60)
// Best match: 96%
NHSTUB(GetFocusLensSubjectDistance, 0xffa7e174)
// Best match: 92%
NHSTUB(GetFocusLensSubjectDistanceFromLens, 0xffa7e714)
// Best match: 82%
NHSTUB(GetOpticalTemperature, 0xff82c6ac)
NHSTUB(GetParameterData, 0xff9647d0)
NHSTUB(GetPropertyCase, 0xff82447c)
// Best match: 96%
NHSTUB(GetSystemTime, 0xff814de8)
// ALT: NHSTUB(GetSystemTime, 0xff814de8) // 26/1
// Best match: 93%
NHSTUB(GetZoomLensCurrentPoint, 0xffa6f014)
// ALT: NHSTUB(GetZoomLensCurrentPoint, 0xffa6f014) // 27/2
// Best match: 93%
NHSTUB(GetZoomLensCurrentPosition, 0xffa6f028)
// ALT: NHSTUB(GetZoomLensCurrentPosition, 0xffa6f028) // 27/2
NHSTUB(IsStrobeChargeCompleted, 0xff8fe0c0)
// Best match: 96%
NHSTUB(LockMainPower, 0xff95fc94)
// Best match: 96%
NHSTUB(MakeAFScan, 0xff94e9ac)
NHSTUB(MakeDirectory, 0xff86e8ec)
NHSTUB(MakeDirectory_Fut, 0xff867b88)
// Best match: 90%
NHSTUB(Mount_FileSystem, 0xff86d8fc)
// ALT: NHSTUB(Mount_FileSystem, 0xff86d8fc) // 27/3
// Best match: 96%
NHSTUB(MoveFocusLensToDistance, 0xffa8b044)
NHSTUB(MoveZoomLensWithPoint, 0xffa6eef4)
// ALT: NHSTUB(MoveZoomLensWithPoint, 0xffa6eef4) // 25/0
NHSTUB(Open, 0xff86e620)
NHSTUB(PT_PlaySound, 0xff957554)
// Best match: 96%
NHSTUB(PhySw_testgpio, 0xff827800)
NHSTUB(PostLogicalEventForNotPowerType, 0xff95bcdc)
NHSTUB(PostLogicalEventToUI, 0xff95bd68)
// ALT: NHSTUB(PostLogicalEventToUI, 0xff95be00) // 25/0
NHSTUB(ProtectFile, 0xff867268)
// Best match: 92%
NHSTUB(PutInNdFilter, 0xffa88e2c)
// ALT: NHSTUB(PutInNdFilter, 0xffa88e2c) // 25/2
// ALT: NHSTUB(PutInNdFilter, 0xffa8a9b8) // 25/2
// ALT: NHSTUB(PutInNdFilter, 0xffa8a9b8) // 25/2
// ALT: NHSTUB(PutInNdFilter, 0xffa8aa00) // 25/2
// ALT: NHSTUB(PutInNdFilter, 0xffa8aa00) // 25/2
// Best match: 94%
NHSTUB(PutOutNdFilter, 0xffa88e74)
// ALT: NHSTUB(PutOutNdFilter, 0xffa88e74) // 16/1
NHSTUB(Read, 0xff86e6dc)
NHSTUB(RefreshPhysicalScreen, 0xff975184)
NHSTUB(Remove, 0xff86e668)
NHSTUB(RenameFile_Fut, 0xff867a7c)
NHSTUB(Restart, 0xff822ab8)
// Best match: 95%
NHSTUB(SetAE_ShutterSpeed, 0xffa8e0f8)
// Best match: 96%
NHSTUB(SetAutoShutdownTime, 0xff95fb8c)
NHSTUB(SetCurrentCaptureModeType, 0xff98c398)
NHSTUB(SetFileAttributes, 0xff86e800)
// Best match: 87%
NHSTUB(SetLogicalEventActive, 0xff95dd38)
NHSTUB(SetParameterData, 0xff9646f0)
NHSTUB(SetPropertyCase, 0xff824360)
NHSTUB(SleepTask, 0xff82141c)
NHSTUB(TakeSemaphore, 0xff820f18)
NHSTUB(TurnOffBackLight, 0xff9a276c)
NHSTUB(TurnOnBackLight, 0xff9a2740)
NHSTUB(UnlockAF, 0xff94a598)
// Best match: 96%
NHSTUB(UnlockMainPower, 0xff95fd48)
NHSTUB(Unmount_FileSystem, 0xff86da04)
// Best match: 89%
NHSTUB(UnsetZoomForMovie, 0xff996f1c)
NHSTUB(UpdateMBROnFlash, 0xff86db5c)
// ERROR: VbattGet is not found!
NHSTUB(Write, 0xff86e6e8)
NHSTUB(WriteSDCard, 0xff87cf14)
NHSTUB(_log, 0xffac0360)
// ALT: NHSTUB(_log, 0xffac0360) // 27/0
NHSTUB(_log10, 0xffac0a08)
// ALT: NHSTUB(_log10, 0xffac0a08) // 27/0
NHSTUB(_pow, 0xffac0ef8)
// ALT: NHSTUB(_pow, 0xffac0ef8) // 25/0
NHSTUB(_sqrt, 0xffac5244)
// ALT: NHSTUB(_sqrt, 0xffac5244) // 24/0
// Best match: 96%
NHSTUB(add_ptp_handler, 0xffa3d524)
NHSTUB(apex2us, 0xff8ab6fc)
NHSTUB(chdir, 0xffad44a0)
// ALT: NHSTUB(chdir, 0xffad44a0) // 27/0
NHSTUB(close, 0xffad3de0)
NHSTUB(closedir, 0xffacfd80)
NHSTUB(errnoOfTaskGet, 0xffad054c)
NHSTUB(exmem_alloc, 0xff8127e0)
// ERROR: free is not found!
NHSTUB(ints_disable, 0xff81d8a4)
NHSTUB(ints_enable, 0xff81d8b0)
NHSTUB(ioctl, 0xffad3f20)
NHSTUB(iosDevAdd, 0xffad5000)
NHSTUB(iosDevDelete, 0xffad4fd8)
NHSTUB(iosDevFind, 0xffad4f8c)
NHSTUB(iosDrvInstall, 0xffad52c4)
NHSTUB(isalpha, 0xffac9cf4)
NHSTUB(isdigit, 0xffac9d24)
NHSTUB(islower, 0xffac9d54)
NHSTUB(ispunct, 0xffac9d84)
NHSTUB(isspace, 0xffac9d9c)
NHSTUB(isupper, 0xffac9db4)
NHSTUB(isxdigit, 0xffac9dcc)
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
// ALT: NHSTUB(kbd_pwr_on, 0xff922a1c) // 5/4
// ALT: NHSTUB(kbd_pwr_on, 0xff922a48) // 5/4
// ALT: NHSTUB(kbd_pwr_on, 0xff922b84) // 5/4
// ALT: NHSTUB(kbd_pwr_on, 0xffa746fc) // 5/4
// ALT: NHSTUB(kbd_pwr_on, 0xffa74728) // 5/4
NHSTUB(kbd_read_keys_r2, 0xff827260)
// Best match: 93%
NHSTUB(localtime, 0xfface574)
NHSTUB(lseek, 0xffad3f24)
// Best match: 53%
NHSTUB(malloc, 0xffad6e20)
// ALT: NHSTUB(malloc, 0xffad6e20) // 15/13
NHSTUB(memPartInfoGet, 0xffad7240)
NHSTUB(memchr, 0xffacd920)
NHSTUB(memcmp, 0xffacd954)
// ALT: NHSTUB(memcmp, 0xffadbd3c) // 9/0
NHSTUB(memcpy, 0xffacd990)
NHSTUB(memset, 0xffacda08)
NHSTUB(mkdir, 0xff86e830)
NHSTUB(mktime, 0xfface73c)
NHSTUB(open, 0xffad4424)
NHSTUB(opendir, 0xffacfdb4)
NHSTUB(qsort, 0xffacd1b4)
NHSTUB(rand, 0xffacd1d8)
// ALT: NHSTUB(rand, 0xffacd1d8) // 8/0
NHSTUB(read, 0xffad3e40)
NHSTUB(readdir, 0xffacfd4c)
NHSTUB(rename, 0xffad442c)
// ALT: NHSTUB(rename, 0xffad442c) // 26/0
NHSTUB(rewinddir, 0xffacfd74)
NHSTUB(srand, 0xffacd1fc)
// ALT: NHSTUB(srand, 0xffacd1fc) // 4/0
NHSTUB(stat, 0xffacfe48)
NHSTUB(strcat, 0xffacda28)
NHSTUB(strchr, 0xffacda54)
NHSTUB(strcmp, 0xffacda78)
NHSTUB(strcpy, 0xffacdc0c)
NHSTUB(strftime, 0xffacf294)
NHSTUB(strlen, 0xffacdd70)
NHSTUB(strncmp, 0xffacddd4)
NHSTUB(strncpy, 0xffacde18)
// ALT: NHSTUB(strncpy, 0xffacde18) // 24/0
NHSTUB(strpbrk, 0xffacde60)
NHSTUB(strrchr, 0xffacde9c)
// ALT: NHSTUB(strrchr, 0xffacde9c) // 8/0
NHSTUB(strtol, 0xffacd5f0)
NHSTUB(strtoul, 0xffacd798)
NHSTUB(taskCreateHookAdd, 0xffada4a0)
NHSTUB(taskDeleteHookAdd, 0xffada3dc)
// Best match: 82%
NHSTUB(taskIdListGet, 0xffae4a64)
NHSTUB(taskLock, 0xffae5120)
NHSTUB(taskName, 0xffae495c)
NHSTUB(taskResume, 0xffae4d40)
NHSTUB(taskSuspend, 0xffae4b6c)
NHSTUB(taskUnlock, 0xffae51c8)
NHSTUB(time, 0xffacf2c0)
// ALT: NHSTUB(time, 0xffacf2c0) // 25/0
NHSTUB(tolower, 0xffac9de4)
NHSTUB(toupper, 0xffac9df4)
NHSTUB(utime, 0xffacfedc)
// ALT: NHSTUB(utime, 0xffacfedc) // 26/0
NHSTUB(vsprintf, 0xffad16a0)
NHSTUB(write, 0xffad3eb0)
