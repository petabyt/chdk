// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

NSTUB(AllocateMemory, 0xffa9edb0)
NSTUB(AllocateUncacheableMemory, 0xff8389d8)
NSTUB(Close, 0xff835408)
NSTUB(CreateTask, 0xff81e5b4)
NSTUB(DeleteFile_Fut, 0xff834d94)
// ERROR: EnterToCompensationEVF is not found!
NSTUB(ExecuteEventProcedure, 0xff884de0)
// ERROR: ExitFromCompensationEVF is not found!
// Best match: 57%
NSTUB(ExitTask, 0xff81e844)
NSTUB(Fclose_Fut, 0xff834f10)
NSTUB(Feof_Fut, 0xff8350fc)
NSTUB(Fflush_Fut, 0xff835138)
NSTUB(Fgets_Fut, 0xff835064)
NSTUB(Fopen_Fut, 0xff834ed0)
NSTUB(Fread_Fut, 0xff834fbc)
NSTUB(FreeMemory, 0xffa9eda8)
// Best match: 91%
NSTUB(FreeUncacheableMemory, 0xff838a18)
NSTUB(Fseek_Fut, 0xff8350b0)
NSTUB(Fwrite_Fut, 0xff835010)
// Best match: 52%
NSTUB(GetBatteryTemperature, 0xff85e2ac)
// Best match: 52%
NSTUB(GetCCDTemperature, 0xff85e238)
// Best match: 85%
NSTUB(GetCurrentAvValue, 0xff9446cc)
NSTUB(GetDrive_ClusterSize, 0xff86bb04)
NSTUB(GetDrive_FreeClusters, 0xff86bb64)
NSTUB(GetDrive_TotalClusters, 0xff86bb38)
// Best match: 64%
NSTUB(GetFocusLensSubjectDistance, 0xff942ca0)
NSTUB(GetFocusLensSubjectDistanceFromLens, 0xff9430e8)
NSTUB(GetMemInfo, 0xff81a070)
NSTUB(GetOpticalTemperature, 0xff85e320)
// Best match: 96%
NSTUB(GetParameterData, 0xff979b1c)
// Best match: 72%
NSTUB(GetPropertyCase, 0xff888b48)
// Best match: 96%
NSTUB(GetSystemTime, 0xffa9ee08)
// Best match: 74%
NSTUB(GetZoomLensCurrentPoint, 0xff947174)
NSTUB(GetZoomLensCurrentPosition, 0xffa904f8)
// Best match: 77%
NSTUB(IsStrobeChargeCompleted, 0xff8c3a24)
NSTUB(LocalTime, 0xff882754)
// Best match: 93%
NSTUB(LockMainPower, 0xff8909b0)
// ERROR: Lseek is not found!
// Best match: 92%
NSTUB(MakeDirectory_Fut, 0xff834e08)
// Best match: 57%
NSTUB(MoveFocusLensToDistance, 0xffb08268)
// Best match: 58%
NSTUB(MoveZoomLensWithPoint, 0xffa9c990)
// Best match: 62%
NSTUB(NewTaskShell, 0xff8885f4)
NSTUB(Open, 0xff8353b0)
NSTUB(PB2Rec, 0xff8939dc)
// ERROR: PT_PlaySound is not found!
// Best match: 86%
NSTUB(PostLogicalEventForNotPowerType, 0xff88e7b8)
// Best match: 92%
NSTUB(PostLogicalEventToUI, 0xff88e804)
NSTUB(Read, 0xff81ab78)
NSTUB(ReadFastDir, 0xffa7e1f4)
NSTUB(Rec2PB, 0xff893a1c)
// ERROR: RefreshPhysicalScreen is not found!
// ERROR: Remove is not found!
// Best match: 53%
NSTUB(RenameFile_Fut, 0xff834ecc)
// ALT: NSTUB(RenameFile_Fut, 0xffa65680) // 8/7
// ALT: NSTUB(RenameFile_Fut, 0xffa656d0) // 8/7
NSTUB(Restart, 0xff83a130)
// Best match: 93%
NSTUB(SetAutoShutdownTime, 0xff890a24)
// Best match: 81%
NSTUB(SetCurrentCaptureModeType, 0xff897d04)
// Best match: 55%
NSTUB(SetFileTimeStamp, 0xff932af4)
// Best match: 64%
NSTUB(SetLogicalEventActive, 0xff8906fc)
// Best match: 96%
NSTUB(SetParameterData, 0xff979a8c)
// Best match: 89%
NSTUB(SetPropertyCase, 0xff888a44)
// Best match: 92%
NSTUB(SleepTask, 0xff83865c)
// Best match: 60%
NSTUB(TakeSemaphore, 0xff838324)
// ERROR: TurnOffBackLight is not found!
// Best match: 54%
NSTUB(TurnOnBackLight, 0xff89e2a0)
// ERROR: UIFS_WriteFirmInfoToFile is not found!
// Best match: 93%
NSTUB(UnlockMainPower, 0xff890904)
NSTUB(UpdateMBROnFlash, 0xff86b984)
NSTUB(VbattGet, 0xff831e04)
NSTUB(Write, 0xff835498)
NSTUB(_log, 0xffb3bc6c)
NSTUB(_log10, 0xffb3a8f8)
NSTUB(_pow, 0xffb3aa68)
NSTUB(_sqrt, 0xffb3d8f0)
NSTUB(add_ptp_handler, 0xffa3f98c)
NSTUB(close, 0xff81a990)
NSTUB(closedir, 0xffa7e07c)
// Best match: 71%
NSTUB(closefastdir, 0xffa7e390)
NSTUB(free, 0xff814138)
// Best match: 86%
NSTUB(kbd_p1_f, 0xff833624)
// Best match: 86%
NSTUB(kbd_p1_f_cont, 0xff833630)
NSTUB(kbd_p2_f, 0xff832ecc)
// Best match: 51%
NSTUB(kbd_pwr_off, 0xff85ae98)
// ERROR: kbd_pwr_on is not found!
NSTUB(kbd_read_keys, 0xff8335a8)
NSTUB(kbd_read_keys_r2, 0xff85a83c)
NSTUB(lseek, 0xff835524)
NSTUB(malloc, 0xff8140dc)
NSTUB(memcmp, 0xff8203e8)
NSTUB(memcpy, 0xff83df94)
NSTUB(memset, 0xff9fbfa0)
NSTUB(mkdir, 0xff83587c)
NSTUB(mktime_ext, 0xff8a5d68)
NSTUB(open, 0xff81a8e0)
NSTUB(opendir, 0xffa7e0c0)
// ERROR: openfastdir is not found!
NSTUB(qsort, 0xff9fc560)
// Best match: 95%
NSTUB(rand, 0xff8204f0)
NSTUB(read, 0xff81ab78)
// ERROR: readfastdir is not found!
// Best match: 82%
NSTUB(reboot_fw_update, 0xffa83704)
// ERROR: rename is not found!
// Best match: 93%
NSTUB(set_control_event, 0xff89032c)
// Best match: 95%
NSTUB(srand, 0xff8204e4)
NSTUB(stat, 0xff835560)
// ALT: NSTUB(stat, 0xff868f48) // 30/0
// Best match: 61%
NSTUB(strcat, 0xff813f38)
// Best match: 56%
NSTUB(strchr, 0xff813fc0)
NSTUB(strcmp, 0xff8203a4)
NSTUB(strcpy, 0xff82038c)
NSTUB(strftime, 0xff8a5770)
NSTUB(strlen, 0xff81400c)
NSTUB(strncmp, 0xff813f74)
// Best match: 73%
NSTUB(strncpy, 0xff813f38)
// Best match: 71%
NSTUB(strrchr, 0xff83df6c)
// ALT: NSTUB(strrchr, 0xff8a5538) // 18/8
// Best match: 96%
NSTUB(strtol, 0xff83e274)
NSTUB(strtolx, 0xff83e078)
// Best match: 86%
NSTUB(time, 0xff882ccc)
NSTUB(vsprintf, 0xff820350)
NSTUB(write, 0xff81abd8)
