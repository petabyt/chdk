// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!
#include "stubs_asm.h"

// Camera info:
//   DRYOS R50 (DRYOS version 2.3, release #0050)
//   Firmware Ver GM1.00E   // Found @ 0xff87d840, "GM1.00E" @ 0xff87d84d
//   Firmware build timestamp: Jun  4 2012 18:04:49
//   Canon PowerShot A1300

// Values for makefile.inc
//   PLATFORMOSVER = 50
//   PLATFORMID = 12862 (0x323e) // Found @ 0xfffe0040
//   MAXRAMADDR = 0x03ffffff
//   MEMISOSTART = 0x001585f0
//   KEYSYS = d4c                // Found @ 0xffff1d4c
//   NEED_ENCODED_DISKBOOT = 8   // Found @ 0xffff1d5c

// Note, ROM copied to RAM :- from 0xffc02710, to 0x003f1000, len 15733 words.
//   ARAM_HEAP_START = 0x34e000  // Found @ 0xff969cc4
//   ARAM_HEAP_SIZE  = 0x22000   // Found @ 0xff969c88

// Stubs below should be checked. Stub not matched 100%, or difference found to current 'stubs_entry_2.S'
//    Name                                     Address      Rule  %  Comp to stubs_entry_2.S
//NHSTUB(DeleteFile_Fut                       ,0xff82fa00) //  1 90%        == 0xff82fa00
//NHSTUB(GetBatteryTemperature                ,0xff85875c) //102        *** != 0x00000000
// ERROR: MakeDirectory_Fut is not found.                  //--- ---    *** != 0xff8305a4
// ERROR: rand is not found.                               //--- ---    *** != 0x00000000
// ERROR: srand is not found.                              //--- ---    *** != 0x00000000

// Check of modemap from 'platform/CAMERA/shooting.c':
// Firmware modemap table found @ffa80170 -> ffba0d78
// No problems found with modemap table.

// Values below can be overridden in 'stubs_min.S':
DEF(physw_status                            ,0x00030fd8) // Found @0xff82d96c
DEF(physw_run                               ,0x00001bf8) // Found @0xff82d51c
DEF(physw_sleep_delay                       ,0x00001c00) // Found @0xff82d51c
DEF(levent_table                            ,0xffb5cd68) // Found @0xffb5cd68
DEF(FlashParamsTable                        ,0xffba0fd4) // Found @0xffba0fd4
DEF(movie_status                            ,0x0000633c) // Found @0xff95a0f0
DEF(video_compression_rate                  ,0x0000637c) // Found @0xff95ad0c
DEF(full_screen_refresh                     ,0x00008608) // Found @0xff9d2bd4
DEF(canon_menu_active                       ,0x00002e2c) // Found @0xff87f32c
DEF(canon_shoot_menu_active                 ,0x0000778d) // Found @0xff99b5a4
DEF(playrec_mode                            ,0x00002b80) // Found @0xff8733d8
DEF(zoom_status                             ,0x0000b3e0) // Found @0xffa83908
// focus_len_table contains zoom focus lengths for use in 'get_focal_length' (main.c).
// each entry contains 2 int value(s), the first is the zoom focus length.
// there are 64 entries in the table - set NUM_FL to 64
DEF(focus_len_table                         ,0xfffeabc8) // Found @0xfffeabc8
DEF(zoom_busy                               ,0x0000621c) // Found @0xff9563fc
DEF(focus_busy                              ,0x000060f4) // Found @0xff9534d0
DEF(recreview_hold                          ,0x000033d8) // Found @0xff88cf34
// Palette colour tables  found @ 0xffb6de9c
DEF(palette_control                         ,0x00008608) // Found @0xff9d2b50
DEF(active_palette_buffer                   ,0x00008610) // Found @0xff9d2b54
DEF(palette_buffer_ptr                      ,0x00008614) // Found @0xff9d2ee8
DEF(palette_buffer                          ,0x000b42c0) // Found @0xff9d2ef8
// Offset from start of palette_buffer to color data = 4 (Found @0xffab6ae4)
DEF(viewport_buffers                        ,0xffb10fa4) // Found @0xff849058
DEF(active_viewport_buffer                  ,0x00002094) // Found @0xff848dc0
// Camera appears to have only 1 RAW buffer @ 0x420b7fc0 (Found @0xffae22a8)
DEF(fileio_semaphore                        ,0x000028f4) // Found @0xff86474c
DEF_CONST(uiprop_count                      ,0x0000008d) // Found @0xff984d3c

// Values below go in 'lib.c':
//void *vid_get_bitmap_fb()        { return (void*)0x40411000; }             // Found @0xff8521ac
//void *vid_get_viewport_fb()      { return (void*)0x40566b80; }             // Found @0xffadf4cc
DEF(viewport_fb_d                           ,0x000029a4) // Found 0x2950 (@0xff867ad4) + 0x54 (@0xff867b0c)
//void *vid_get_viewport_fb_d()    { return (void*)(*(int*)(0x2950+0x54)); } // Found @0xff867ad4 & 0xff867b0c
DEF(jpeg_count_str                          ,0x000b3b6c) // Found @0xff9c9308
//char *camera_jpeg_count_str()    { return (char*)0x000b3b6c; }             // Found @0xff9c9308
//int get_flash_params_count(void) { return 0xa6; }                          // Found @0xff985714

// Bitmap masks and physw_status index values for SD_READONLY and USB power flags (for kbd.c).
//#define SD_READONLY_FLAG    0x00020000 // Found @0xffb1150c, levent 0x20a
//#define SD_READONLY_IDX     2
//#define USB_MASK            0x00040000 // Found @0xffb11514, levent 0x202
//#define USB_IDX             2
//#define BATTCOVER_FLAG      0x00080000 // Found @0xffb1151c, levent 0x205
//#define BATTCOVER_IDX       2

// Keymap values for kbd.c. Additional keys may be present, only common values included here.
//static KeyMap keymap[] = {
//    { 0, KEY_ZOOM_OUT        ,0x00001000 }, // Found @0xffb11494, levent 0x03
//    { 0, KEY_ZOOM_IN         ,0x00002000 }, // Found @0xffb1149c, levent 0x02
//    { 1, KEY_SHOOT_FULL      ,0x00300000 }, // Found @0xffb114ac, levent 0x01
//    { 1, KEY_SHOOT_FULL_ONLY ,0x00200000 }, // Found @0xffb114ac, levent 0x01
//    { 1, KEY_SHOOT_HALF      ,0x00100000 }, // Found @0xffb114a4, levent 0x00
//    { 1, KEY_UP              ,0x00400000 }, // Found @0xffb114b4, levent 0x04
//    { 1, KEY_DOWN            ,0x00800000 }, // Found @0xffb114bc, levent 0x05
//    { 1, KEY_RIGHT           ,0x01000000 }, // Found @0xffb114c4, levent 0x07
//    { 1, KEY_LEFT            ,0x02000000 }, // Found @0xffb114cc, levent 0x06
//    { 1, KEY_MENU            ,0x04000000 }, // Found @0xffb114d4, levent 0x09
//    { 1, KEY_SET             ,0x08000000 }, // Found @0xffb114dc, levent 0x08
//    { 1, KEY_VIDEO           ,0x10000000 }, // Found @0xffb114e4, levent 0x1a
//    { 1, KEY_HELP            ,0x20000000 }, // Found @0xffb114ec, levent 0x14
//    { 1, KEY_POWER           ,0x40000000 }, // Found @0xffb114f4, levent 0x100
//    { 1, KEY_PLAYBACK        ,0x80000000 }, // Found @0xffb114fc, levent 0x101
//    { 0, 0, 0 }
//};

// Values below go in 'platform_camera.h':
//#define CAM_DRYOS         1
//#define CAM_DRYOS_2_3_R39 1 // Defined for cameras with DryOS version R39 or higher
//#define CAM_DRYOS_2_3_R47 1 // Defined for cameras with DryOS version R47 or higher
//#define CAM_RAW_ROWPIX    4704 // Found @0xff92e0a4
//#define CAM_RAW_ROWS      3504 // Found @0xff92e0b0
//#undef  CAM_UNCACHED_BIT
//#define CAM_UNCACHED_BIT  0x40000000 // Found @0xff832e74
//#define CAM_DATE_FOLDER_NAMING 0x400 // Found @0xffa47704 (pass as 3rd param to GetImageFolder)
//#define PARAM_CAMERA_NAME 4 // Found @0xffba00e0

// Misc stuff
DEF(ctypes, 0xffb108d4)

// LED table init @ 0xff90c904
// LED #1: 0xc0220120, offset 0x4
// LED #2: 0xc0220104, offset 0x44
// LED #3: 0xc0220124, offset 0x104

// For capt_seq.c
DEF(_nrflag,0x8744) // Found @ ff9df684 (0x8744) & ff9df6c0 (+0x00)
//static long *nrflag = (long*)(0x8744+0x00);  // Found @ ff9df684 & ff9df6c0
//#define NR_AUTO (0)                          // have to explictly reset value back to 0 to enable auto

// Stubs below matched 100%.
//    Name                                     Address                Comp to stubs_entry_2.S
NHSTUB(AllocateUncacheableMemory              ,0xff832e2c) //112
NHSTUB(Close                                  ,0xff830074) //120
NHSTUB(CreateBinarySemaphore                  ,0x003f74c8) //115
NHSTUB(CreateTask                             ,0x003f6824) //120
NHSTUB(DebugAssert                            ,0x003f6afc) //107
NHSTUB(DeleteDirectory_Fut                    ,0xff82fa74) //116
NHSTUB(DoAELock                               ,0xff831cf8) //120
NHSTUB(DoAFLock                               ,0xff831a04) //120
NHSTUB(EnterToCompensationEVF                 ,0xff831c60) //104
NHSTUB(ExecuteEventProcedure                  ,0xff87a800) //104
NHSTUB(ExitFromCompensationEVF                ,0xff831ca4) //104
NHSTUB(ExitTask                               ,0x003f6ab4) //120
NHSTUB(ExpCtrlTool_StartContiAE               ,0xff83ca58) //104
NHSTUB(ExpCtrlTool_StopContiAE                ,0xff83cbb4) //104
NHSTUB(Fclose_Fut                             ,0xff82fb0c) //120
NHSTUB(Feof_Fut                               ,0xff82fcf8) //  1
NHSTUB(Fflush_Fut                             ,0xff82fd34) //  1
NHSTUB(Fgets_Fut                              ,0xff82fc60) //  6
NHSTUB(Fopen_Fut                              ,0xff82facc) //120
NHSTUB(Fread_Fut                              ,0xff82fbb8) //120
NHSTUB(FreeUncacheableMemory                  ,0xff832e6c) //112
NHSTUB(Fseek_Fut                              ,0xff82fcac) //120
NHSTUB(Fwrite_Fut                             ,0xff82fc0c) //120
NHSTUB(GetCCDTemperature                      ,0xff8586e8) //102
NHSTUB(GetCurrentAvValue                      ,0xff95503c) //120
NHSTUB(GetDrive_ClusterSize                   ,0xff86653c) //122
NHSTUB(GetDrive_FreeClusters                  ,0xff866594) //119
NHSTUB(GetDrive_TotalClusters                 ,0xff86656c) //119
NHSTUB(GetFocusLensSubjectDistance            ,0xff954294) //102
NHSTUB(GetFocusLensSubjectDistanceFromLens    ,0xff9546e4) //  3
NHSTUB(GetImageFolder                         ,0xff937624) //122
NHSTUB(GetKbdState                            ,0xff856650) //109
NHSTUB(GetMemInfo                             ,0xff8150cc) //115
NHSTUB(GetOpticalTemperature                  ,0xff8587d4) //120
NHSTUB(GetParameterData                       ,0xff9856d4) //101
NHSTUB(GetPropertyCase                        ,0xff87e8cc) //102
NHSTUB(GetSystemTime                          ,0xffa72570) //120
NHSTUB(GetVRAMHPixelsSize                     ,0xff84b138) //120
NHSTUB(GetVRAMVPixelsSize                     ,0xff84b144) //120
NHSTUB(GetZoomLensCurrentPoint                ,0xff95687c) //120
NHSTUB(GetZoomLensCurrentPosition             ,0xffa64194) //102
NHSTUB(GiveSemaphore                          ,0x003f7704) //120
NHSTUB(IsStrobeChargeCompleted                ,0xff8c9b38) //102
NHSTUB(LEDDrive                               ,0xff95c2f0) //120
NHSTUB(LocalTime                              ,0x003fb1b8) //115
NHSTUB(LockMainPower                          ,0xff883170) //120
NHSTUB(MakeSDCardBootable                     ,0xff866814) //105
NHSTUB(MoveFocusLensToDistance                ,0xffadb584) //102
NHSTUB(MoveIrisWithAv                         ,0xffa6e404) //120
NHSTUB(MoveZoomLensWithPoint                  ,0xffa6eb2c) //120
NHSTUB(Open                                   ,0xff82ffac) //120
NHSTUB(PB2Rec                                 ,0xff885fe0) //104
NHSTUB(PT_MoveDigitalZoomToWide               ,0xff86c594) //120
NHSTUB(PT_MoveOpticalZoomAt                   ,0xff86c56c) //120
NHSTUB(PT_PlaySound                           ,0xff87503c) //122
NHSTUB(PostLogicalEventForNotPowerType        ,0xff882864) //120
NHSTUB(PostLogicalEventToUI                   ,0xff8828b0) //120
NHSTUB(PutInNdFilter                          ,0xffa6e904) //102
NHSTUB(PutOutNdFilter                         ,0xffa6e928) //102
NHSTUB(Read                                   ,0xff815b88) //120
NHSTUB(ReadFastDir                            ,0xffa545d8) //115
NHSTUB(Rec2PB                                 ,0xff886020) //104
NHSTUB(RefreshPhysicalScreen                  ,0xff894b14) //104
NHSTUB(RenameFile_Fut                         ,0xff82f96c) //116
NHSTUB(Restart                                ,0xff83464c) //122
NHSTUB(ScreenLock                             ,0xff895b34) //117
NHSTUB(ScreenUnlock                           ,0xff895b98) //117
NHSTUB(SetAE_ShutterSpeed                     ,0xffade6a4) //102
NHSTUB(SetAutoShutdownTime                    ,0xff8831e4) //120
NHSTUB(SetCurrentCaptureModeType              ,0xff88a1d0) //120
NHSTUB(SetFileAttributes                      ,0xff83050c) //  6
NHSTUB(SetFileTimeStamp                       ,0xff830494) //  6
NHSTUB(SetLogicalEventActive                  ,0xff882eec) //120
NHSTUB(SetParameterData                       ,0xff985644) //101
NHSTUB(SetPropertyCase                        ,0xff87e744) //102
NHSTUB(SetScriptMode                          ,0xff882f3c) //120
NHSTUB(SleepTask                              ,0x003f79b0) //120
NHSTUB(TakeSemaphore                          ,0x003f7634) //120
NHSTUB(TurnOffBackLight                       ,0xff88ff94) //104
NHSTUB(TurnOnBackLight                        ,0xff88ff7c) //104
NHSTUB(TurnOnDisplay                          ,0xff85259c) //120
NHSTUB(TurnOffDisplay                         ,0xff8525ac) //120
NHSTUB(UIFS_WriteFirmInfoToFile               ,0xff977c18) //120
NHSTUB(UnlockAE                               ,0xff831d1c) //120
NHSTUB(UnlockAF                               ,0xff831a3c) //120
NHSTUB(UnlockMainPower                        ,0xff8830c4) //120
NHSTUB(UnsetZoomForMovie                      ,0xff98be7c) //104
NHSTUB(VbattGet                               ,0xff82c274) //120
NHSTUB(Write                                  ,0xff8300c8) //120
NHSTUB(WriteSDCard                            ,0xff94748c) //108
NHSTUB(_log                                   ,0x003fcce0) //111
NHSTUB(_log10                                 ,0x003fd220) //112
NHSTUB(_pow                                   ,0x003fd398) //121
NHSTUB(_sqrt                                  ,0x003fefbc) //  6
NHSTUB(add_ptp_handler                        ,0xffa17594) //121
NHSTUB(apex2us                                ,0xff9d8e90) //121
NHSTUB(close                                  ,0xff8159e4) //109
NHSTUB(err_init_task                          ,0xff81437c) //111
NHSTUB(exmem_alloc                            ,0xff8791d4) //101
NHSTUB(exmem_free                             ,0xff87924c) //101
NHSTUB(free                                   ,0xff812f78) //112
NHSTUB(kbd_p1_f                               ,0xff82d9bc) //109
NHSTUB(kbd_p1_f_cont                          ,0xff82d9c8) //109
NHSTUB(kbd_p2_f                               ,0xff82d1b4) //109
NHSTUB(kbd_read_keys                          ,0xff82d96c) //109
NHSTUB(kbd_read_keys_r2                       ,0xff85616c) //109
NHSTUB(lseek                                  ,0xff8302f0) //120
NHSTUB(malloc                                 ,0xff812f20) //112
NHSTUB(memcmp                                 ,0xff81ae58) //120
NHSTUB(memcpy                                 ,0xff835da4) //120
NHSTUB(memset                                 ,0xff9d71e0) //120
NHSTUB(mkdir                                  ,0xff8305a4) //121
NHSTUB(mktime_ext                             ,0xff896064) //  1
NHSTUB(open                                   ,0xff815934) //109
NHSTUB(OpenFastDir                            ,0xffa54474) //115
NHSTUB(closedir                               ,0xffa54424) //121
NHSTUB(get_fstype                             ,0xff8665b4) //122
NHSTUB(qsort                                  ,0xff9d7180) //  6
NHSTUB(realloc                                ,0xff9d725c) //115
NHSTUB(reboot_fw_update                       ,0xffa59aa0) //106
NHSTUB(set_control_event                      ,0xff882bac) //111
NHSTUB(stat                                   ,0xff830338) //109
NHSTUB(strcat                                 ,0xff8966e4) //  1
NHSTUB(strchr                                 ,0xff812dec) //  1
NHSTUB(strcmp                                 ,0xff81af54) //120
NHSTUB(strcpy                                 ,0xff81ae40) //120
NHSTUB(strftime                               ,0xff8960b0) //113
NHSTUB(strlen                                 ,0xff812e38) //120
NHSTUB(strncmp                                ,0xff812da0) //  1
NHSTUB(strncpy                                ,0xff812d64) //  1
NHSTUB(strrchr                                ,0xff812e10) //  1
NHSTUB(strtol                                 ,0xff835d90) //101
NHSTUB(strtolx                                ,0xff835b94) //109
   DEF(task_CaptSeq                           ,0xff86eca8) //120
   DEF(task_DvlpSeqTask                       ,0xff961a78) //120
   DEF(task_ExpDrv                            ,0xff8ae8d4) //120
   DEF(task_FileWrite                         ,0xffa52e28) //120
   DEF(task_InitFileModules                   ,0xff88688c) //120
   DEF(task_MovieRecord                       ,0xff95b59c) //120
   DEF(task_PhySw                             ,0xff82d518) //120
NHSTUB(time                                   ,0x003fb794) //  6
NHSTUB(vsprintf                               ,0xff81acf0) //115
NHSTUB(EngDrvRead                             ,0xff82e7fc) //102
NHSTUB(PTM_GetCurrentItem                     ,0xff883994) //105
NHSTUB(CancelHPTimer                          ,0xff879ee8) //119
NHSTUB(SetHPTimerAfterNow                     ,0xff879de0) //119
NHSTUB(PT_MFOn                                ,0xff86c644) //120
NHSTUB(PT_MFOff                               ,0xff86c654) //120
NHSTUB(GetAdChValue                           ,0xff85396c) //120
