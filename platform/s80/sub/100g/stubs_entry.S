// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

NHSTUB(AllocateMemory, 0xff811acc)
NHSTUB(AllocateUncacheableMemory, 0xff814bb0)
NHSTUB(Close, 0xff870568)
NHSTUB(CreatePhysicalVram, 0xff92a650)
NHSTUB(CreateTask, 0xff821564)
NHSTUB(CreateTaskStrict, 0xff8226cc)
NHSTUB(DeleteFile_Fut, 0xff869328)
NHSTUB(DisableDispatch, 0xff821388)
// Best match: 58%
NHSTUB(DisplayImagePhysicalScreen, 0xff929a0c)
// Best match: 91%
//NHSTUB(DoAFLock, 0xff951274) -- stubs_entry_2.S = 0xff95124c
NHSTUB(EnableDispatch, 0xff821414)
// Best match: 87%
NHSTUB(EnterToCompensationEVF, 0xff953378)
NHSTUB(ExecuteEventProcedure, 0xff816ac8)
// Best match: 90%
NHSTUB(ExitFromCompensationEVF, 0xff954c84)
NHSTUB(ExitTask, 0xff821924)
NHSTUB(Fclose_Fut, 0xff869468)
NHSTUB(Feof_Fut, 0xff86967c)
NHSTUB(Fflush_Fut, 0xff8696b4)
NHSTUB(Fgets_Fut, 0xff8695ec)
NHSTUB(Fopen_Fut, 0xff86942c)
NHSTUB(Fread_Fut, 0xff86954c)
NHSTUB(FreeMemory, 0xff811ad8)
NHSTUB(FreeUncacheableMemory, 0xff814be4)
NHSTUB(Fseek_Fut, 0xff869634)
NHSTUB(Fwrite_Fut, 0xff86959c)
// Best match: 82%
NHSTUB(GetBatteryTemperature, 0xff82d36c)
// Best match: 82%
NHSTUB(GetCCDTemperature, 0xff82d358)
NHSTUB(GetCurrentAvValue, 0xffab63a0)
// ALT: NHSTUB(GetCurrentAvValue, 0xffab87a0) // 13/0
NHSTUB(GetCurrentTargetDistance, 0xffab8748)
// ERROR: GetDrive_ClusterSize is not found!
// Best match: 52%
//NHSTUB(GetDrive_FreeClusters, 0xff86f900) -- stubs_entry_2.S = 0xff86f93c
// Best match: 64%
//NHSTUB(GetDrive_TotalClusters, 0xff86f900) -- stubs_entry_2.S = 0xff86f900
// Best match: 96%
NHSTUB(GetFocusLensSubjectDistance, 0xffaaab38)
// Best match: 52%
NHSTUB(GetFocusLensSubjectDistanceFromLens, 0xffaab0d8)
// Best match: 82%
NHSTUB(GetOpticalTemperature, 0xff82d344)
NHSTUB(GetParameterData, 0xff96dad0)
NHSTUB(GetPropertyCase, 0xff824554)
// Best match: 96%
NHSTUB(GetSystemTime, 0xff814de8)
// ALT: NHSTUB(GetSystemTime, 0xff814de8) // 26/1
// Best match: 93%
NHSTUB(GetZoomLensCurrentPoint, 0xffa973d4)
// ALT: NHSTUB(GetZoomLensCurrentPoint, 0xffa973d4) // 27/2
// Best match: 93%
NHSTUB(GetZoomLensCurrentPosition, 0xffa973e8)
// ALT: NHSTUB(GetZoomLensCurrentPosition, 0xffa973e8) // 27/2
NHSTUB(IsStrobeChargeCompleted, 0xff904154)
NHSTUB(LockMainPower, 0xff9682a0)
//NHSTUB(MakeAFScan, 0xff955dd8) -- stubs_entry_2.S = 0x00000000
NHSTUB(MakeDirectory, 0xff87080c)
NHSTUB(MakeDirectory_Fut, 0xff8693b4)
// Best match: 73%
NHSTUB(Mount_FileSystem, 0xff86f2bc)
// ALT: NHSTUB(Mount_FileSystem, 0xff86f2bc) // 22/8
// Best match: 96%
//NHSTUB(MoveFocusLensToDistance, 0xffab89d8) -- stubs_entry_2.S = 0x00000000
NHSTUB(MoveZoomLensWithPoint, 0xffa97264)
// ALT: NHSTUB(MoveZoomLensWithPoint, 0xffa97264) // 25/0
NHSTUB(Open, 0xff870540)
NHSTUB(PT_PlaySound, 0xff95f6e8)
// Best match: 89%
NHSTUB(PhySw_testgpio, 0xff827a10)
NHSTUB(PostLogicalEventForNotPowerType, 0xff963ef0)
NHSTUB(PostLogicalEventToUI, 0xff963f7c)
// ALT: NHSTUB(PostLogicalEventToUI, 0xff964014) // 25/0
NHSTUB(ProtectFile, 0xff868a94)
// Best match: 92%
//NHSTUB(PutInNdFilter, 0xffab63b4) -- stubs_entry_2.S = 0xffab67c0
// ALT: NHSTUB(PutInNdFilter, 0xffab63b4) // 25/2
// ALT: NHSTUB(PutInNdFilter, 0xffab63fc) // 25/2
// ALT: NHSTUB(PutInNdFilter, 0xffab63fc) // 25/2
// ALT: NHSTUB(PutInNdFilter, 0xffab67c0) // 25/2
// ALT: NHSTUB(PutInNdFilter, 0xffab67c0) // 25/2
// ALT: NHSTUB(PutInNdFilter, 0xffab834c) // 25/2
// ALT: NHSTUB(PutInNdFilter, 0xffab834c) // 25/2
// ALT: NHSTUB(PutInNdFilter, 0xffab8394) // 25/2
// ALT: NHSTUB(PutInNdFilter, 0xffab8394) // 25/2
// Best match: 94%
NHSTUB(PutOutNdFilter, 0xffab6808)
// ALT: NHSTUB(PutOutNdFilter, 0xffab6808) // 16/1
NHSTUB(Read, 0xff8705fc)
NHSTUB(RefreshPhysicalScreen, 0xff97eea8)
NHSTUB(Remove, 0xff870588)
NHSTUB(RenameFile_Fut, 0xff8692a8)
NHSTUB(Restart, 0xff822bac)
// Best match: 95%
NHSTUB(SetAE_ShutterSpeed, 0xffabba8c)
NHSTUB(SetAutoShutdownTime, 0xff968198)
NHSTUB(SetCurrentCaptureModeType, 0xff99855c)
NHSTUB(SetFileAttributes, 0xff870720)
// Best match: 88%
NHSTUB(SetLogicalEventActive, 0xff9660f8)
NHSTUB(SetParameterData, 0xff96d9f0)
NHSTUB(SetPropertyCase, 0xff824438)
NHSTUB(SleepTask, 0xff821478)
NHSTUB(TakeSemaphore, 0xff820f74)
NHSTUB(TurnOffBackLight, 0xff9b93a8)
NHSTUB(TurnOnBackLight, 0xff9b937c)
NHSTUB(UnlockAF, 0xff9512b4)
NHSTUB(UnlockMainPower, 0xff968354)
NHSTUB(Unmount_FileSystem, 0xff86f3d4)
// Best match: 89%
NHSTUB(UnsetZoomForMovie, 0xff9a40c0)
NHSTUB(UpdateMBROnFlash, 0xff86f580)
// ERROR: VbattGet is not found!
NHSTUB(Write, 0xff870608)
NHSTUB(WriteSDCard, 0xff87ee40)
NHSTUB(_log, 0xffaef0ac)
// ALT: NHSTUB(_log, 0xffaef0ac) // 27/0
NHSTUB(_log10, 0xffaef754)
// ALT: NHSTUB(_log10, 0xffaef754) // 27/0
NHSTUB(_pow, 0xffaefc44)
// ALT: NHSTUB(_pow, 0xffaefc44) // 25/0
NHSTUB(_sqrt, 0xffaf3f90)
// ALT: NHSTUB(_sqrt, 0xffaf3f90) // 24/0
// Best match: 96%
NHSTUB(add_ptp_handler, 0xffa610a8)
NHSTUB(apex2us, 0xff8aef88)
NHSTUB(chdir, 0xffb031ec)
// ALT: NHSTUB(chdir, 0xffb031ec) // 27/0
NHSTUB(close, 0xffb02b2c)
NHSTUB(closedir, 0xffafeacc)
NHSTUB(errnoOfTaskGet, 0xffaff298)
NHSTUB(exmem_alloc, 0xff8127e0)
// ERROR: free is not found!
NHSTUB(ints_disable, 0xff81d900)
NHSTUB(ints_enable, 0xff81d90c)
NHSTUB(ioctl, 0xffb02c6c)
NHSTUB(iosDevAdd, 0xffb03d4c)
NHSTUB(iosDevDelete, 0xffb03d24)
NHSTUB(iosDevFind, 0xffb03cd8)
NHSTUB(iosDrvInstall, 0xffb04010)
NHSTUB(isalpha, 0xffaf8a40)
NHSTUB(isdigit, 0xffaf8a70)
NHSTUB(islower, 0xffaf8aa0)
NHSTUB(ispunct, 0xffaf8ad0)
NHSTUB(isspace, 0xffaf8ae8)
NHSTUB(isupper, 0xffaf8b00)
NHSTUB(isxdigit, 0xffaf8b18)
NHSTUB(kbd_p1_f, 0xff826558)
NHSTUB(kbd_p1_f_cont, 0xff826564)
NHSTUB(kbd_p2_f, 0xff826934)
// Best match: 83%
NHSTUB(kbd_pwr_off, 0xff828fec)
// ALT: NHSTUB(kbd_pwr_off, 0xff829008) // 5/1
// ALT: NHSTUB(kbd_pwr_off, 0xff8290f4) // 5/1
// ALT: NHSTUB(kbd_pwr_off, 0xff829110) // 5/1
// ALT: NHSTUB(kbd_pwr_off, 0xff8291e0) // 5/1
// ALT: NHSTUB(kbd_pwr_off, 0xff8291fc) // 5/1
// ALT: NHSTUB(kbd_pwr_off, 0xff829344) // 5/1
// ALT: NHSTUB(kbd_pwr_off, 0xff829360) // 5/1
// Best match: 55%
NHSTUB(kbd_pwr_on, 0xff928b28)
// ALT: NHSTUB(kbd_pwr_on, 0xff928b54) // 5/4
// ALT: NHSTUB(kbd_pwr_on, 0xff928c90) // 5/4
// ALT: NHSTUB(kbd_pwr_on, 0xff92b544) // 5/4
// ALT: NHSTUB(kbd_pwr_on, 0xff92b570) // 5/4
// ERROR: kbd_read_keys_r2 is not found!
// Best match: 93%
NHSTUB(localtime, 0xffafd2c0)
NHSTUB(lseek, 0xffb02c70)
// Best match: 53%
NHSTUB(malloc, 0xffb05b6c)
// ALT: NHSTUB(malloc, 0xffb05b6c) // 15/13
NHSTUB(memPartInfoGet, 0xffb05f8c)
NHSTUB(memchr, 0xffafc66c)
NHSTUB(memcmp, 0xffafc6a0)
// ALT: NHSTUB(memcmp, 0xffb0aa88) // 9/0
NHSTUB(memcpy, 0xffafc6dc)
NHSTUB(memset, 0xffafc754)
NHSTUB(mkdir, 0xff870750)
NHSTUB(mktime, 0xffafd488)
NHSTUB(open, 0xffb03170)
NHSTUB(opendir, 0xffafeb00)
NHSTUB(qsort, 0xffafbf00)
NHSTUB(rand, 0xffafbf24)
// ALT: NHSTUB(rand, 0xffafbf24) // 8/0
NHSTUB(read, 0xffb02b8c)
NHSTUB(readdir, 0xffafea98)
NHSTUB(rename, 0xffb03178)
// ALT: NHSTUB(rename, 0xffb03178) // 26/0
NHSTUB(rewinddir, 0xffafeac0)
NHSTUB(srand, 0xffafbf48)
// ALT: NHSTUB(srand, 0xffafbf48) // 4/0
NHSTUB(stat, 0xffafeb94)
NHSTUB(strcat, 0xffafc774)
NHSTUB(strchr, 0xffafc7a0)
NHSTUB(strcmp, 0xffafc7c4)
NHSTUB(strcpy, 0xffafc958)
NHSTUB(strftime, 0xffafdfe0)
NHSTUB(strlen, 0xffafcabc)
NHSTUB(strncmp, 0xffafcb20)
NHSTUB(strncpy, 0xffafcb64)
// ALT: NHSTUB(strncpy, 0xffafcb64) // 24/0
NHSTUB(strpbrk, 0xffafcbac)
NHSTUB(strrchr, 0xffafcbe8)
// ALT: NHSTUB(strrchr, 0xffafcbe8) // 8/0
NHSTUB(strtol, 0xffafc33c)
NHSTUB(strtoul, 0xffafc4e4)
NHSTUB(taskCreateHookAdd, 0xffb091ec)
NHSTUB(taskDeleteHookAdd, 0xffb09128)
// Best match: 82%
NHSTUB(taskIdListGet, 0xffb137b0)
NHSTUB(taskLock, 0xffb13e6c)
NHSTUB(taskName, 0xffb136a8)
NHSTUB(taskResume, 0xffb13a8c)
NHSTUB(taskSuspend, 0xffb138b8)
NHSTUB(taskUnlock, 0xffb13f14)
NHSTUB(time, 0xffafe00c)
// ALT: NHSTUB(time, 0xffafe00c) // 25/0
NHSTUB(tolower, 0xffaf8b30)
NHSTUB(toupper, 0xffaf8b40)
NHSTUB(utime, 0xffafec28)
// ALT: NHSTUB(utime, 0xffafec28) // 26/0
NHSTUB(vsprintf, 0xffb003ec)
NHSTUB(write, 0xffb02bfc)
